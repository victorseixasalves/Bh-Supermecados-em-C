#include <windows.h>
#include "Interface.h"
#include <conio.h>

void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void Caixa(int x, int y, int Largura, int Altura, int Tipo)
{
    int i, j;
    unsigned char C[][6] = {{218, 196, 191, 179, 192, 217},
        {201, 205, 187, 186, 200, 188}
    };
    gotoxy(x, y);
    printf("%c", C[Tipo][0]);
    for(i = 0; i < Largura; i++) printf("%c", C[Tipo][1]);
    printf("%c", C[Tipo][2]);
    for(j = 0; j < Altura; j++)
    {
        gotoxy(x, y + j + 1);
        printf("%c", C[Tipo][3]);
        for(i = 0; i < Largura; i++) printf(" ");
        printf("%c", C[Tipo][3]);
    }
    gotoxy(x, y + j + 1);
    printf("%c", C[Tipo][4]);
    for(i = 0; i < Largura; i++) printf("%c", C[Tipo][1]);
    printf("%c", C[Tipo][5]);
}

void textcoloreback (int letras, int fundo) /*para mudar a cor de fundo mude o background*/
{
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
                             letras + (fundo << 4));
}

int Menu(int x[], int y[], char Opcoes[][100], int n)
{
    int i, Opcao = 0, Tecla;
    tipocursor(0);
    textcoloreback(BLACK, WHITE);
    for (i = 0; i < n; i++)
    {
        gotoxy(x[i], y[i]);
        printf("%s", Opcoes[i]);
    }
    do
    {
        textcoloreback(GREEN,LIGHT_GRAY);
        gotoxy(x[Opcao], y[Opcao]);
        printf("%s", Opcoes[Opcao]);
        Tecla = getTecla();
        textcoloreback(BLACK,WHITE);
        gotoxy(x[Opcao], y[Opcao]);
        printf("%s", Opcoes[Opcao]);
        if(Tecla == TEC_ESQ) Opcao--;
        if(Tecla == TEC_DIR) Opcao++;
        if(Tecla == TEC_CIMA) Opcao--;
        if(Tecla == TEC_BAIXO) Opcao++;
        if(Tecla == TEC_ENTER)
        {
            tipocursor(1);
            return Opcao;
        }
        if(Opcao < 0) Opcao = n - 1;
        if(Opcao >= n) Opcao = 0;
    }
    while(Tecla != TEC_ESC);
    tipocursor(1);
    return -1;
}

int getTecla()
{
    int ch;
    ch = getch();
    if(ch == 224)
    {
        ch = getch() + 1000;
    }
    return ch;
}

void tipocursor (int cursor)
{
    HANDLE myconsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CURSOR;
    BOOL result;
    CURSOR.dwSize = 1;
    if(cursor == 0)
        CURSOR.bVisible = FALSE;
    else
        CURSOR.bVisible = TRUE;
    result=SetConsoleCursorInfo(myconsole, &CURSOR);//second argument need pointer
}

int Selecao(int x, int y, int Largura, int Altura, char Opcoes[][100], int n)
{
    int i, Opcao = 0, Tecla, Primeiro = 0;
    tipocursor(0);
    textcoloreback(YELLOW, BLACK);
    for (i = 0; i < Altura && i < n; i++)
    {
        gotoxy(x, y + i);
        printf("%*s", -Largura, Opcoes[i + Primeiro]);
    }
    do
    {
        textcoloreback(YELLOW, BLUE);
        gotoxy(x, y + Opcao - Primeiro);
        printf("%*s", -Largura, Opcoes[Opcao]);
        Tecla = getTecla();
        textcoloreback(YELLOW, BLACK);
        gotoxy(x, y + Opcao - Primeiro);
        printf("%*s", -Largura, Opcoes[Opcao]);
        if(Tecla == TEC_ESQ) Opcao--;
        if(Tecla == TEC_DIR) Opcao++;
        if(Tecla == TEC_CIMA) Opcao--;
        if(Tecla == TEC_BAIXO) Opcao++;
        if(Tecla == TEC_ENTER)
        {
            tipocursor(1);
            return Opcao;
        }
        if(Opcao < 0) Opcao = 0;//n - 1;
        if(Opcao >= n) Opcao = n-1;//0;
        if(Opcao - Primeiro < 0 || Opcao >= Altura + Primeiro)
        {
            if(Opcao - Primeiro < 0) Primeiro--;
            else Primeiro++;
            for (i = 0; i < Altura && i < n; i++)
            {
                gotoxy(x, y + i);
                printf("%*s", -Largura, Opcoes[i + Primeiro]);
            }
        }
    }
    while(Tecla != TEC_ESC);
    tipocursor(1);
    return -1;
}

int EntradaDados(int x, int y, int Tamanho, char Texto[]){
    int Tecla, Pos;
    gotoxy(x, y);
    textcoloreback(BLACK, WHITE);
    printf("%*s", Tamanho, " ");
    gotoxy(x, y);
    printf("%s", Texto);
    Pos = strlen(Texto);
    do{
        gotoxy(Pos + x, y);
        Tecla = getTecla();
        if(Tecla == TEC_ENTER) break;
        if(Tecla == TEC_ESQ) Pos--;
        if(Tecla == TEC_DIR) Pos++;
        if(Tecla == TEC_CIMA) break;
        if(Tecla == TEC_BAIXO) break;
        if(Tecla == TEC_ESC) break;
        if(Tecla == TEC_BACKSPACE && Pos > 0){
            printf("\x08 \x08");
            Pos--;
        }
        if(Tecla >= ' ' && Tecla < 127){
            if(Pos < Tamanho){
                if(Texto[Pos] == 0) Texto[Pos+1] = 0;
                Texto[Pos++] = Tecla;
                printf("%c", Tecla);
            }
        }
        if(Pos < 0) Pos = 0;
        if(Pos > Tamanho) Pos = Tamanho;
        if(Pos > 0 && Texto[Pos-1] == 0) Pos--;
    } while(1);
    //Texto[Pos] = 0;
    textcoloreback(YELLOW, BLUE);
    return Tecla;
}

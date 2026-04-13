#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <locale.h>
#include "Produto.h"
#include "Interface.h"

FILE*fp;

int main(){
    setlocale(LC_ALL,"");
    textcoloreback(BLUE,WHITE);

    int opcao, sair, code, Tecla, scode,pag;
    Produto prod;

    do{
     fp=fopen("Arquivo.txt","rb+");
      if(fp==NULL){
       fp=fopen("Arquivo.txt","wb+");
      if(fp==NULL){
       printf("Não Abriu...");
       exit(1);
      }
     }

     textcoloreback(BLUE,WHITE);
     system ("cls");
     opcao = inicio();
     switch(opcao){
      case 0:
       Telacadastro();
       prod=DigitarProduto();
       fseek(fp,0,SEEK_END);
       fwrite(&prod,sizeof(Produto),1,fp);
       fclose(fp);
       break;

      case 1:
       Telapesquisa();
       mostrarlist();
       gotoxy(1,10);printf("Digite o Código do Produto:");
       textcoloreback(BLACK,WHITE);
       gotoxy(29,10);scanf("%d",&code);

       prod = buscar(code);

       if(prod.code==-1){
        textcoloreback(RED,WHITE);
        gotoxy(1,12);printf("[Produto não encontrado]");
       }else{
        textcoloreback(GREEN,WHITE);
        gotoxy(1,12);printf("[Produto encontrado!]");
        imprimir(prod);
       }
       textcoloreback(BLACK,WHITE);
       gotoxy(1,30);system("pause");
       fclose(fp);
       break;

      case 2:
       Telaalterar();
       mostrarlist();
       gotoxy(1,8);printf("Digite o código:");
       textcoloreback(BLACK,WHITE);
       gotoxy(18,8);scanf("%d",&code);
       alterar(code);
       textcoloreback(BLACK,WHITE);
       fclose(fp);
       break;

      case 3:
       Telaexcluir();
       mostrarlist();
       gotoxy(1,8);printf("Digite o código:");
       textcoloreback(BLACK,WHITE);
       gotoxy(18,8);scanf("%d",&code);
       excluir(code);
       textcoloreback(BLACK,WHITE);
       gotoxy(1,12);system("pause");
       fclose(fp);
       break;

      case 4:
       pag=1;
       Telalista();
       fseek(fp,0,SEEK_SET);
       while(fread(&prod,sizeof(Produto),1,fp)){
          if(prod.code!=-1){
           setlocale(LC_ALL,"");
           textcoloreback(BLUE,WHITE);
           gotoxy(1,9);printf("Página %d",pag);
           pag++;
           textcoloreback(BLACK,WHITE);
           imprimir(prod);
           gotoxy(1,34);system("pause");
          }
       }
       textcoloreback(BLACK,WHITE);
       fclose(fp);
       break;

      case 5:
        sair=confirmar();
        if(sair==1){
          system ("cls");
          break;
        }else{
          opcao++;
        }
        fclose(fp);
     }

    }while(opcao!=6);


    gotoxy(0,29);

return 0;
}

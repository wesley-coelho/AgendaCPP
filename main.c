#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<ctype.h>
#include <string.h>
#include <windows.h>
#define MAX 100


typedef struct{
    char nome[MAX][41];
    char telefone[MAX][16];
    char endereco[MAX][101];
    int fim;
}Tagenda;


void menu(){
    system("cls");
    printf("\t--> M E N U \n");
    printf("\n\t1 - Inserir");
    printf("\n\t2 - Remover");
    printf("\n\t3 - Alterar");
    printf("\n\t4 - Mostrar contatos");
    printf("\n\t5 - Mostrar estrutura");
    printf("\n\t6 - Salvar");
    printf("\n\t7 - Buscar contato");
    printf("\n\t9 - Sair\n");
}

void lerArquivoTextoAgenda( Tagenda *agenda){


    FILE *arq;
    char c;

    arq=fopen("Agenda.txt","r+");

    if(arq == NULL){
        system("cls");
        printf("\n\nError. Falha ao ler o arquivo: Agenda.txt\n\n");
        system("pause");
    }else{

       while( (c=fgetc(arq)) != EOF ){
            agenda->fim = agenda->fim + 1;

            //lendo nome
            int j = 0;
            while(j<40){
                agenda->nome[agenda->fim][j] = c;
                c=fgetc(arq);
                ++j;
            }
            agenda->nome[agenda->fim][j] = '\0';
             //lendo endereco
            j = 0;
            while(j<100){
                agenda->endereco[agenda->fim][j] = c;
                c=fgetc(arq);
                ++j;
            }
            agenda->endereco[agenda->fim][j] = '\0';
            //lendo telefone
            j = 0;
            while(j<15){
                agenda->telefone[agenda->fim][j] = c;
                c=fgetc(arq);
                ++j;
            }
            agenda->telefone[agenda->fim][j] = '\0';
       }
    }
    fclose(arq);
}

void mostraEstrutura(Tagenda *agenda){

    system("cls");
    printf("\tM E N U --> CONTATOS NA MEMORIA RAM\n\n");
    printf("\t Id    NOME                                    ENDERECO                                                                                            TELEFONE                                                       \n");
    printf("\t-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    if(agenda->fim != -1){
        for(int i = 0; i <= agenda->fim; i++){
            printf("\t%3d    ", i);
            int j = 0;
                while(agenda->nome[i][j] != '\0'){
                    printf("%c", agenda->nome[i][j]);
                    ++j;
                }
            j=0;
                while(agenda->endereco[i][j] != '\0'){
                        printf("%c", agenda->endereco[i][j]);
                        ++j;
                    }
            j=0;
                while(agenda->telefone[i][j] != '\0'){
                        printf("%c", agenda->telefone[i][j]);
                        ++j;
                    }
            printf("\n");
        }
    }
    printf("\t-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("\n\n\t");
}
int insereContato(Tagenda *agenda){
    char  ch, nome[41], endereco[101], telefone[16];
    int   cont, inserePosicao;

    if(agenda->fim < MAX-1){
        if( agenda->fim == -1){
            agenda->fim = agenda->fim +1;
            //inserindo nome na estrutura agenda
            printf("\n\tNome: ");
            cont=0;
            fflush(stdin);
            ch = getchar();
            while(ch != '\n' && cont < 40){
                agenda->nome[agenda->fim][cont] = toupper(ch);
                ch = getchar();
                cont++;
            }
            if(cont < 40){
                for(int i = cont; i < 40; i++,cont++)
                  agenda->nome[agenda->fim][i] = ' ';  //completando com espacos em branco
            }
            agenda->nome[agenda->fim][cont] = '\0';
            //inserindo endereco na estrutra agenda
            cont = 0;
            printf("\n\tEndereco: ");
            fflush(stdin);
            ch = getchar();
            while(ch != '\n' && cont < 100){
                agenda->endereco[agenda->fim][cont] = toupper(ch);
                ch = getchar();
                cont++;
            }
            if(cont < 100){
                for(int i = cont; i < 100; i++,cont++)
                  agenda->endereco[agenda->fim][i] = ' ';  //completando com espacos em branco
            }
             agenda->endereco[agenda->fim][cont] = '\0';
            //inserindo telefone na estrutra agenda
            cont = 0;
            printf("\n\tTelefone: ");
            fflush(stdin);
            ch = getchar();
            while(ch != '\n' && cont < 15){
                agenda->telefone[agenda->fim][cont] = toupper(ch);
                ch = getchar();
                cont++;
            }
            if(cont < 15){
                for(int i = cont; i < 15; i++, cont++)
                  agenda->telefone[agenda->fim][i] = ' ';  //completando com espacos em branco
            }
            agenda->telefone[agenda->fim][cont] = '\0';
            printf("\n\t");
            return 0;
        }else{
            //recebendo o nome
            printf("\n\tNome: ");
            cont=0;
            fflush(stdin);
            ch = getchar();
            while(ch != '\n' && cont < 40){
                nome[cont] = toupper(ch);
                ch = getchar();
                cont++;
            }
            if(cont < 40){
                for(int i = cont; i < 40; i++,cont++)
                  nome[i] = ' ';  //completando com espacos em branco
            }
            nome[cont] = '\0';
            //recebendo o endereco
            printf("\n\tEndereco: ");
            cont=0;
            fflush(stdin);
            ch = getchar();
            while(ch != '\n' && cont < 100){
                endereco[cont] = toupper(ch);
                ch = getchar();
                cont++;
            }
            if(cont < 100){
                for(int i = cont; i < 100; i++,cont++)
                  endereco[i] = ' ';  //completando com espacos em branco
            }
            endereco[cont] = '\0';
            //recebendo o telefone
            printf("\n\tTelefone: ");
            cont=0;
            fflush(stdin);
            ch = getchar();
            while(ch != '\n' && cont < 15){
                telefone[cont] = toupper(ch);
                ch = getchar();
                cont++;
            }
            if(cont < 15){
                for(int i = cont; i < 15; i++,cont++)
                  telefone[i] = ' ';  //completando com espacos em branco
            }
            telefone[cont] = '\0';
            //inserindo na lista ordenadamente
            for(cont = 0; cont <= agenda->fim; cont++)
                if(strcmp(agenda->nome[cont],nome) > 0)
                    break;
            inserePosicao = cont;
            //deslocando os itens da lista para inserir os novos dados
            agenda->fim = agenda->fim + 1;
            for(int i = agenda->fim; i > inserePosicao; i--){
                strcpy(agenda->nome[i], agenda->nome[i-1]);
                strcpy(agenda->endereco[i], agenda->endereco[i-1]);
                strcpy(agenda->telefone[i], agenda->telefone[i-1]);
            }
            //inserindo o novo registro na posicao ordenada alfabeticamente
            strcpy(agenda->nome[inserePosicao], nome);
            strcpy(agenda->endereco[inserePosicao], endereco);
            strcpy(agenda->telefone[inserePosicao], telefone);

        printf("\n\t");
        return 0;
        }
    }else{
        printf("\n\t");
        return -1;
    }


}

void mostraContatos(){
    FILE *arq;
    char  ch;

    arq = fopen("Agenda.txt","r+");

    if(arq != NULL){

        int index = -1;
        system("cls");
        printf("\tM E N U --> CONTATOS SALVOS EM AGENDA.txt\n\n");

    printf("\t Id    NOME                                    ENDERECO                                                                                            TELEFONE                                                       \n");
    printf("\t-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        ch = fgetc(arq);
        while(ch != EOF){
            printf("\t%3d    ", ++index);
                while(ch != '\n' && ch != EOF){
                    printf("%c", ch);
                    ch = fgetc(arq);
                }
            printf("%c", ch);
            ch = fgetc(arq);
        }
    }else{
        system("cls");
        printf("\tERRO ao abrir a arquivo Agenda.txt\n\n");
    }
    printf("\t-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("\n\n\t");
 }

 int removeContato(Tagenda *agenda){

    int index;
    if(agenda->fim >-1){
        printf("\n\n\tDigite o Id do contato que deseja remover entre %d e %d: ", 0, agenda->fim);
        do{
            scanf("%d", &index);
        }while(index < 0  && index > agenda->fim);
        //deslocando os registros da estrutura lista
        for(int i = index; i < agenda->fim; i++){
            strcpy(agenda->nome[i], agenda->nome[i+1]);
            strcpy(agenda->endereco[i], agenda->endereco[i+1]);
            strcpy(agenda->telefone[i], agenda->telefone[i+1]);
        }
        agenda->fim = agenda->fim - 1;
    printf("\n\t");
    return 0;
    }else{
        printf("\n\n\tImpossivel remover.\n\n\t");
    printf("\n\t");
    return -1;
    }
 }


 int alteraContato(Tagenda *agenda){
    int index,j;
    char  ch, auxNome[41], auxEnd[101], auxTel[16], opt;


    if(agenda->fim >-1){
        printf("\n\n\tDigite o Id do contato que deseja alterar entre %d e %d: ", 0, agenda->fim);
        do{
            scanf("%d", &index);
        }while(index < 0  && index > agenda->fim);

        printf("\n\n\tDeseja alterar o nome, sim[1] ou nao[0]: ");
        fflush(stdin);
        scanf("%c", &opt);
        if(opt == '1'){
            printf("\tNovo Nome: ");
            j = 0;
            fflush(stdin);
            ch=getchar();
            while(ch != '\n' && j < 40){
                agenda->nome[index][j] = toupper(ch);
                ch=getchar();
                j++;
            }
            while(j < 40){
                agenda->nome[index][j] = ' ';//completando com espacos em branco
                j++;
            }
            agenda->nome[index][j] = '\0';
        }

             printf("\n\n\tDeseja alterar o endereco, sim[1] ou nao[0]: ");
             fflush(stdin);
             scanf("%c", &opt);
             fflush(stdin);
        if(opt == '1'){
            printf("\tNovo Endereco: ");
            j = 0;
            ch=toupper(getchar());
            while(ch != '\n' && j < 100){
                agenda->endereco[index][j] = ch;
                ch=toupper(getchar());
                j++;
            }
            while(j < 100){
                agenda->endereco[index][j] = ' ';//completando com espacos em branco
                j++;
            }
            agenda->endereco[index][j] = '\0';
        }
        fflush(stdin);
        printf("\n\n\tDeseja alterar o telefone, sim[1] ou nao[0]: ");
        scanf("%c", &opt);
        fflush(stdin);
        if(opt == '1'){
            printf("\tNovo telefone: ");
            j = 0;
            ch=toupper(getchar());
            while( ch != '\n' && j < 15 ){
                agenda->telefone[index][j] = ch;
                ch=toupper(getchar());
                j++;
            }
            while(j < 15){
                agenda->telefone[index][j] = ' ';//completando com espacos em branco
                j++;
            }
            agenda->telefone[index][j] = '\0';
        }
        //reordenando os contatos com bublesort

        for(int i; i < agenda->fim; i++){
            for(int j = i+1; j <= agenda->fim; j++){
                if(strcmp(agenda->nome[i], agenda->nome[j]) > 0){
                    strcpy(auxNome,agenda->nome[j]);
                    strcpy(agenda->nome[j], agenda->nome[i]);
                    strcpy(agenda->nome[i],auxNome);

                    strcpy(auxEnd,agenda->endereco[j]);
                    strcpy(agenda->endereco[j], agenda->endereco[i]);
                    strcpy(agenda->endereco[i],auxEnd);

                    strcpy(auxTel,agenda->telefone[j]);
                    strcpy(agenda->telefone[j], agenda->telefone[i]);
                    strcpy(agenda->telefone[i],auxTel);
                }
            }
        }
        printf("\n\t");
        return 0;
    }else{
        printf("\n\n\tImpossivel remover.\n\n\t");

    return -1;
    }
 printf("\n\t");
 return 0;
 }


 int buscaContato(Tagenda agenda){

    char nomeProcurado[41],ch, acc=0;
    int tamNome;
    if(agenda.fim > -1){
        printf("\n\n\tDigite o nome ou parte do nome do contato que deseja buscar: ");
        fflush(stdin);
        tamNome = 0;
        ch = getchar();
        while(ch != '\n' && tamNome < 40){
            nomeProcurado[tamNome] = toupper(ch);
            ch = getchar();
            tamNome++;
        }
        nomeProcurado[tamNome]='\0';
        printf("\n\t Id    NOME                                    ENDERECO                                                                                            TELEFONE                                                       \n");
        printf("\t-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        //algoritmo de busca sequencial
        for(int i = 0; i <= agenda.fim; i++){
            if(strstr(agenda.nome[i], nomeProcurado) != NULL){
                printf("\t%3d    ", i);
                printf("%s", agenda.nome[i]);
                printf("%s", agenda.endereco[i]);
                printf("%s", agenda.telefone[i]);
                printf("\n");
                acc++;
            }
        }
    }
    printf("\t-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    if(acc > 0)
        printf("\n\t%d resultado(s) encontrado(s).\n", acc);
    else
        printf("\n\tNenhum resultado(s) encontrado(s).\n");
    printf("\n\t");
 return 0;
 }

int main()
{
   Tagenda      agenda;
   char         op;

   agenda.fim = -1;
   lerArquivoTextoAgenda(&agenda);


   do{
        menu();
        printf("\n\tDigite uma opcao valida: ");
        scanf("%c",&op);

        switch(op){
            case '1':{
                    system("cls");
                    printf("\tM E N U --> I N S E R I R \n\n");
                    insereContato(&agenda);
                    system("pause");
            }break;
            case '2':{
                    system("cls");
                    printf("\tM E N U --> R E M O V E R \n\n");
                    removeContato(&agenda);
                    system("pause");

            }break;
            case '3':{
                    system("cls");
                    printf("\tM E N U --> A L T E R A R \n\n");
                    alteraContato(&agenda);
                    system("pause");

            }break;
            case '4':{
                    system("cls");
                    printf("\tM E N U --> M O S T R A R  C O N T A T O S \n\n");
                    mostraContatos();
                    system("pause");

            }break;
            case '5':{
                    system("cls");
                    printf("\tM E N U --> M O S T R A R   E S T R U T U R A \n\n");
                    mostraEstrutura(&agenda);
                    system("pause");

            }break;
            case '6':{
                    //inserindo o registro no arquivo Agenda.txt
                    FILE *arq;
                    arq=fopen("Agenda.txt","w+");
                    int indiceLista=0;
                    //anexando o nome
                    while(indiceLista <= agenda.fim){
                        fflush(stdin);
                        fputs(agenda.nome[indiceLista],arq);
                        //anexando o endereco
                        fflush(stdin);
                        fputs(agenda.endereco[indiceLista],arq);
                        //anexando o telefone
                        fflush(stdin);
                        fputs(agenda.telefone[indiceLista],arq);
                        fputc('\n',arq);
                        indiceLista++;
                    }
                    fclose(arq);
                    printf("\n\n\tSalvo em Agenda.txt.\n\n\t");
                    system("pause");

            }break;
            case '7':{
                    system("cls");
                    printf("\tM E N U --> B U S C A R   C O N T A T O \n\n");
                    buscaContato(agenda);
                    system("pause");

            }break;
        }
   }while(op != '9');
return 0;
}

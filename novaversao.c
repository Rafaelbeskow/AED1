#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct pessoa
{
    char nome[20];
    int tel;
}typedef Pessoa;

void imprimeAgenda(void *pBuffer,int *i,int *v1,int *v2) {
   
    char *pNomeprint= pBuffer + 3*sizeof(int);
    int *pTelefone =  pBuffer + 3*sizeof(int) + 20 ;
    *v1=0;
    *v2=0;
    for(;*v1 != *i;*v1=*v1 + 1) {
        
        for(;*pNomeprint!='\0';pNomeprint++){
             printf("%c",*pNomeprint);
             *v2= *v2 + 1 ;
        }
        pNomeprint = pNomeprint + (sizeof(Pessoa)) - *v2;
            printf("\n%d\n",*pTelefone);
        pTelefone = pTelefone + (sizeof(Pessoa));
        
       
    }
    
}

void insereAgenda(void *pBuffer,int *i){
    *i=*i + 1;
    printf("%d\n",*i);
    pBuffer= realloc(pBuffer,3*sizeof(int) + (*i * sizeof(Pessoa)));
    char *pNome = (pBuffer + (3*sizeof(int)) + ((*i - 1) * sizeof(Pessoa)));
    int *pTelefone = (pBuffer + (3*sizeof(int) + 20) + ((*i - 1) * sizeof(Pessoa)));
    printf("Digite o nome da pessoa: ");
    scanf(" %[^\n]",pNome);
    printf("Digite o Telefone da pessoa: ");
    scanf("%d",pTelefone);
   
}

int main () {
	
    void *pBuffer;
    int *i;
    int *v1;
    int *v2;
    
    pBuffer= malloc(3*sizeof(int));
   
    i = (int*)pBuffer;
    *i=0;
    v1 = (int*) pBuffer + sizeof(int);
    v2 = (int*) pBuffer + 2*sizeof(int);

    insereAgenda(pBuffer,i);
    imprimeAgenda(pBuffer,i,v1,v2);
    insereAgenda(pBuffer,i);
    imprimeAgenda(pBuffer,i,v1,v2);
}
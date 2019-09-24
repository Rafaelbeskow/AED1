
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void imprimeAgenda(void *pBuffer,int *i) {
   
    char *pNomeprint=pBuffer;
    int *pTelefone =  pBuffer + 20*sizeof(char);
    for(;*i>0;*i= *(i - 1) ) {
        printf("%d\n",*i);
        for(;*pNomeprint!='\0';pNomeprint++){
             printf("%c",*pNomeprint);
        }
        pNomeprint = pBuffer + (20*sizeof(char) + sizeof (int));
            printf("\n%d\n",*pTelefone);
        pTelefone = pTelefone + (20*sizeof(char) + sizeof (int)); 
       
    }
    
}

void insereAgenda(void *pBuffer,int *i){
    *i=*i + 1;
    printf("%d\n",*i);
    pBuffer= realloc(pBuffer,*i * (20*sizeof(char) + sizeof (int)));
    char *pNome = pBuffer + ((*i - 1) * (20*sizeof(char) + sizeof (int)));
    int *pTelefone = (pBuffer+ 20*sizeof(char)) + ((*i - 1) * (20*sizeof(char) + sizeof (int))) ;
    printf("Digite o nome da pessoa: ");
    scanf(" %[^\n]",pNome);
    printf("Digite o Telefone da pessoa: ");
    scanf("%d",pTelefone);
}

int main () {
	
    void *pBuffer;
    int *i;
    *i=0;
    
    pBuffer= malloc(20*sizeof(char) + sizeof (int));
    insereAgenda(pBuffer,i);
    imprimeAgenda(pBuffer,i);
    insereAgenda(pBuffer,i);
    imprimeAgenda(pBuffer,i);
}

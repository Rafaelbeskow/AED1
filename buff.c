#include<stdio.h>
#include<stdlib.h>
#include<string.h>



void imprimeAgenda(void *pBuffer,int *i) {
    char *pNome=pBuffer;
    int *pTelefone =  (pBuffer+50);
    int   *j = i;
    printf("%d\n",*j);
    for(; *j> 0;*j--) {
        
        for(;*pNome!='\0';pNome++){
             printf("%c",*pNome);
        }
        *pNome= *pNome + 50*sizeof(char) + sizeof(int) ; 
            printf("\n%d\n",*pTelefone);
        *pTelefone= (*pTelefone+100) + sizeof(int); 
    }
    
}

void insereAgenda(void *pBuffer,int *i){
    *i=*i + 1;
    pBuffer= realloc(pBuffer,*i * (sizeof (int) + 50*sizeof(char) + sizeof (int)));
    char *pNome=pBuffer + ((*i - 1) * (50*sizeof(char) + sizeof (int)));
    int *pTelefone= (pBuffer+50) + ((*i - 1) * (50*sizeof(char) + sizeof (int))) ;
    printf("Digite o nome da pessoa: ");
    scanf("%[^\n]",pNome);
    printf("Digite o Telefone da pessoa: ");
    scanf("%d",pTelefone);
}

int main () {
    void *pBuffer;
    int *i=pBuffer;
    *i=0;
    pBuffer= malloc(50*sizeof(char) + sizeof (int));
    insereAgenda(pBuffer,i);
    imprimeAgenda(pBuffer,i);
    insereAgenda(pBuffer,i);
    imprimeAgenda(pBuffer,i);
}

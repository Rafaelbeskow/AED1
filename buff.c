#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**
    A função imprime os valores que estão no buffer passado por parâmetro.
    Os valores estão intercalados na seguinte ordem: int, float, double.
    A variável nTotal indica o total de trios (int, float e double) no buffer.
*/


void imprimeAgenda(void *pBuffer,int *i) {
    for(; *i > 0; *i--) {
        char *pNome= pBuffer + sizeof(int);
        int *pTelefone = (pBuffer+50);
        for(;*pNome!='\0';pNome++){
        printf("%c",*pNome);
        }
        
        printf("\n%d\n",*pTelefone);
    }
}

void insereAgenda(void *pBuffer,int *i){
    pBuffer= realloc(pBuffer,*i * (50*sizeof(char) + sizeof (int)));
    char *pNome=pBuffer+sizeof (int);
    void *pInicio=pBuffer+sizeof(int);
    int *pTelefone= (pBuffer+50);
    printf("Digite o nome da pessoa: ");
        scanf("%[^\n]",pNome);
    printf("Digite o Telefone da pessoa: ");
    scanf("%d",pTelefone);
    i++;
    pBuffer = pInicio;
}

int main () {
    void *pBuffer;
    int *i=pBuffer;
    *i=1;
    pBuffer= malloc(sizeof (int) + 50*sizeof(char) + sizeof (int));
    insereAgenda(pBuffer,i);
    imprimeAgenda(pBuffer,i);
    insereAgenda(pBuffer,i);
    imprimeAgenda(pBuffer,i);
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**
    A função imprime os valores que estão no buffer passado por parâmetro.
    Os valores estão intercalados na seguinte ordem: int, float, double.
    A variável nTotal indica o total de trios (int, float e double) no buffer.
*/


void imprimeAgenda(void *pBuffer,int *i) {
    for(; i > 0; i--) {
        int *pInt = pBuffer;
        char *pNome=pBuffer +sizeof(int);
        printf("%d",pInt);
        pBuffer += sizeof(char)*100 + sizeof(int);
    }
}

void insereAgenda(void *pBuffer,int *i){

    int *pTelefone;
    int *pInt = pBuffer;
    char *pNome=pBuffer + sizeof(int);
    printf("Digite o nome da pessoa: ");
        scanf("%[^\n]",pNome);
        pBuffer = *(pNome+100);
    printf("Digite o Telefone da pessoa: ");
    scanf("%d",pTelefone);
    i++;
}

int main () {
    void *pBuffer;
    int *i=1;
    pBuffer= malloc(100*sizeof(char) + sizeof (int));
    insereAgenda(pBuffer,i);
    imprimeAgenda(pBuffer,i);

}


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void imprimi(int *vetor,int d){
    for(;0<d;d--){
        scanf("%d",vetor);
        vetor=(vetor + sizeof(int));
    }
    vetor=vetor - (sizeof(int) * d);
}

int main()

{   int *vetor,d;
    printf("digite o numero de posicoes do vetor: \n");
    scanf("%d",&d);
    vetor=malloc(sizeof (int) * d);
    imprimi(vetor,d);
    for(;0<d;d--){
        printf("%d",*vetor);
        vetor=(vetor + sizeof(int));
    }
for(;0<d;d--){
        free(vetor);
        vetor=(vetor - sizeof(int));
    }
for(;0<d;d--){
        printf("%d",*vetor);
        vetor=(vetor + sizeof(int));
    }
    return 0;
}

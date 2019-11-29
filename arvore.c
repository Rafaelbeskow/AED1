#include <stdio.h>
#include <stdlib.h>

struct arvore{
    int num;
    struct arvore *esq;
    struct arvore *dir;
};

void colocaarv(struct arvore **principal,int n){
    if(*principal==NULL){
        *principal=(struct arvore*)malloc(sizeof(struct arvore));
        (*principal)->esq=NULL;
        (*principal)->dir=NULL;
        (*principal)->num=n;}
     else {if(n<(*principal)->num)
            colocaarv(&(*principal)->esq,n);
           if(n>(*principal)->num)
           colocaarv(&(*principal)->dir,n);
     }
}

void printaarvore(struct arvore **principal){
    if(*principal!=NULL){
        printf("%d\n",(*principal)->num);
        printaarvore(&(*principal)->esq);
        printaarvore(&(*principal)->dir);
    }
}

void acha(struct arvore **principal,int igual){
    if(*principal==NULL)
        printf("Arvore esta vazia\n");
    else 
    {
        if((*principal)->num!=igual){
        acha(&(*principal)->esq,igual);
        acha(&(*principal)->dir,igual);}
        else
        {
			if((*principal)->num==igual)
				printf("o numero %d esta na arvore",igual);
            else{
				
			}
        
    
    }
}
}


int main ()
{
     struct arvore *principal=NULL;
     colocaarv(&principal,15);
     colocaarv(&principal,10);
     colocaarv(&principal,20);
     colocaarv(&principal,5);
     colocaarv(&principal,7);
     printaarvore(&principal);
     acha(&principal,0);
     return 0;
}


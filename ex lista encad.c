/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next
};

void insere(struct node **cabeca,int numero){
    struct node *lista;
    lista=(struct node*) malloc(sizeof(struct node));
    
    lista->data= numero;
    lista->next = *cabeca;
    *cabeca= lista;
}
void printa(struct node *cabeca) 
{ 
    while(cabeca != NULL) 
    { 
        printf("%d->", cabeca->data); 
        cabeca = cabeca->next; 
    } 
    printf("\n");
} 


void concat(struct node *comeca,struct node *segunda){
    while(comeca!=NULL){
        if(comeca->data==5){
       comeca->next=segunda;}
       comeca=comeca->next;
       
    }
}

int main()
{
  struct node *comeca=NULL,*segunda=NULL;
  insere(&comeca,5);
  insere(&comeca,4);
  insere(&comeca,3);
  insere(&comeca,2);
  insere(&comeca,1);
  insere(&segunda,10);
  insere(&segunda,9);
  insere(&segunda,8);
  insere(&segunda,7);
  insere(&segunda,6);
  
  printa(comeca);
 concat(comeca,segunda);
 printa (comeca);
 
  
}

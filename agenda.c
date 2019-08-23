#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct data{
    int dia;
    int mes;
    int ano;
};
struct registro {
    char nome[100];
    char endereco[100];
    long int telefone;
    struct data nascimento;
};
struct celula {
    struct registro informacoes;
    struct celula *prox;
};


struct celula *cria (){
   struct celula *start;
    start= (struct celula *) malloc(sizeof(struct celula));
    start->prox = NULL;
    return start;

}

void insere (struct celula *p){
   struct celula *nova;
    nova=(struct celula*)malloc(sizeof(struct celula));
    printf("digite o nome da pessoa para a agenda\n");
    scanf(" %[^\n]s",nova->informacoes.nome);
    printf("digite o endereco da pessoa para a agenda\n");
    scanf(" %[^\n]s",nova->informacoes.endereco);
    printf("digite o telefone da pessoa para a agenda\n");
    scanf("%ld",&nova->informacoes.telefone);
    printf("escreva a data de nascimento com dia mes e ano\n");
    scanf("%d%d%d",&nova->informacoes.nascimento.dia,&nova->informacoes.nascimento.mes,&nova->informacoes.nascimento.ano);
    nova->prox=p->prox;
    p->prox = nova;
}

void imprimi(struct celula *ini,struct celula *p){
	
	for (p = ini->prox;p != NULL; p = p->prox)
    printf("Nome:%s\nendereco:%s\ntelefone:%ld\ndata de nascimento:%d/%d/%d\n",p->informacoes.nome,p->informacoes.endereco,p->informacoes.telefone,p->informacoes.nascimento.dia,p->informacoes.nascimento.mes,p->informacoes.nascimento.ano);

}

void remova(struct celula *ini){
    char k[100];
    struct celula *listaum,*listadois;
    
    printf("digite o nome da pessoa que queira excluir:\n");
    scanf(" %[^\n]s",k);
    listaum=ini;
    listadois=ini->prox;
    while(listadois!=NULL && strcmp(listadois->informacoes.nome,k)!=0){
        listaum=listadois;
        listadois=listadois->prox;}
    if (listadois!=NULL){
        listaum->prox=listadois->prox;
        free(listadois);
        printf("\nremovido com sucesso\n");
    }
}

int main (void){
struct celula *ini,*escolha;
int n=200;

   ini=cria();
for (int i=0;n!=0;i++){
    printf ("selecione o que quer fazer:\n1- adicionar na agenda\n2- remover da agenda\n3- imprimir agenda\n0-Finalizar agenda");
    scanf ("%d",&n);
    if (n==1)
        insere(ini);
    if (n==2)
      remova(ini);
    if (n==3)
        imprimi(ini,escolha);
}


}

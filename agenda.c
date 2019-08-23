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

void insere (struct celula *ini){
   struct celula *nova;
    nova=(struct celula*)malloc(sizeof(struct celula));
    printf("digite o nome da pessoa para a agenda\n");
    scanf("%s",nova->informacoes.nome);
    printf("digite o endereco da pessoa para a agenda\n");
    scanf("%s",nova->informacoes.endereco);
    printf("digite o telefone da pessoa para a agenda\n");
    scanf("%ld",&nova->informacoes.telefone);
    printf("escreva a data de nascimento com dia mes e ano\n");
    scanf("%d%d%d",&nova->informacoes.nascimento.dia,&nova->informacoes.nascimento.mes,&nova->informacoes.nascimento.ano);
    nova=ini->prox;
    ini->prox = nova;
};

void imprimi(struct celula *ini,struct celula *escolha){
	
	for (escolha=ini->prox;escolha!=NULL;escolha=escolha->prox)
    printf("Nome:%s\nendereco:%s\ntelefone:%ld\ndata de nascimento:%d/%d/%d\n",ini->informacoes.nome,ini->informacoes.endereco,ini->informacoes.telefone,ini->informacoes.nascimento.dia,ini->informacoes.nascimento.mes,ini->informacoes.nascimento.ano);

};

int main (void){
struct celula *ini,*escolha;
int n=200;

   ini=cria();
for (int i=0;n!=0;i++){
    printf ("selecione o que quer fazer:\n1- adicionar na agenda\n2- remover da agenda\n3- imprimir agenda\n0-Finalizar agenda");
    scanf ("%d",&n);
    if (n==1)
        insere(ini);
    /* (n==2)
      remova(escolha,ini);*/
    if (n==3)
        imprimi(ini,escolha);
}


}

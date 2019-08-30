#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main (){
void *pbuffer;
int *i;
char *n;
pbuffer= malloc(sizeof (int) + 10*sizeof(char));
i=pbuffer;
n=(pbuffer+sizeof(int));
n[0]='a';
n[1]='n';
n[2]='a';
}


#include <stdio.h>
#include <stdlib.h>


//questao 3
void ordena (int v[],int n){
    int i,j,menor,aux;
    for(i=0;i<n-1;i++){
        menor = i;
        for(j=i+1;j<n;j++){
         if(v[j]<v[menor])
                menor = j;
        }
        if(i!= menor){
                aux = v[i];
                v[i] = v[menor];
                v[menor] = aux;
        }
    }

}




void menu(){
    int opcao;
    int tam;
    int v[50];



    while(1){
        printf("\nBem vindo ao Sistema de... ");
        printf("\n1- Ordenar ");
        printf("\nDigite opção: ");
        scanf("%d", &opcao);

        if(opcao == 1){

   int tam;
    printf("Digite a quantidade de elementos: ");
    scanf("%d",&tam);
    int v[tam];
    printf("\nDigite os elementos: ");
    for(int i=0;i<tam;i++){
        scanf("%d",&v[i]);
    }
    ordena(v,tam);
    printf("\nElementos ordenados: ");
    for(int i=0;i<tam;i++){
    printf("%d ",v[i]);
    }
    printf("\n");
        }

        else continue;

}
}


int main(){
    menu();
}
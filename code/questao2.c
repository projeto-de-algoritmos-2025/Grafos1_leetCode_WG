#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int a;
    int b;
} Edge;

int main(){
    int N;
    int a = 0,b = 0;

    printf("Qual a quantidade de arestas: ");
    scanf("%d", &N);

    int pais[N+1];
    int filhos[N+1];

    for(int i=0; i<N+1; i++){
        pais[i] = 0;
        filhos[i] = 0;
    }

    Edge edgesRemoveCicle;
    edgesRemoveCicle.a = -1;
    edgesRemoveCicle.b = -1;
    Edge edgesRemoveTwoFathers;
    edgesRemoveTwoFathers.a = -1;
    edgesRemoveTwoFathers.b = -1;

    printf("Digite no formato [x, y]: \n");

    for(int i=0; i<N; i++){
        scanf(" [%d , %d]", &a, &b);
        if(pais[b] == 1 && filhos[a] == 1){
           // identificar ciclos
           edgesRemoveCicle.a = a;
           edgesRemoveCicle.b = b;
        }
        if(filhos[b] == 1){
            // identificar dois pais
            edgesRemoveTwoFathers.a = a;
            edgesRemoveTwoFathers.b = b;
        }
        pais[a] = 1;
        filhos[b] = 1;
    }

    printf("\nSaída:\n");

    if(edgesRemoveCicle.a == -1){
        printf("[%d,%d]\n", edgesRemoveTwoFathers.a, edgesRemoveTwoFathers.b);
    }else{
        printf("[%d,%d]\n", edgesRemoveCicle.a, edgesRemoveCicle.b);
    }

    return 0;
}
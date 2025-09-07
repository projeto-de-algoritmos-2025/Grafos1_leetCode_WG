#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct{
    int a;
    int b;
} Edge;

bool dfs(int node, int numCourses, int **matriz, int *visited) {
    // 0 nao visita - 1 visitando - 2 visitado
    if (visited[node] == 1) return true; // encontrado o ciclo
    if (visited[node] == 2) return false;

    visited[node] = 1;
    for (int i = 0; i < numCourses; i++) {
        if (matriz[node][i] == 1) {
            if (dfs(i, numCourses, matriz, visited)) return true;
        }
    }
    visited[node] = 2;
    return false;
}

int main() {
    int numCourses = 3;
    int qtdePrerequisites = 3;
    Edge prerequisites[3] = { {0,1}, {1,2},{2,0} };

    int **matriz = malloc(numCourses * sizeof(int*));
    for (int i = 0; i < numCourses; i++) {
        matriz[i] = calloc(numCourses, sizeof(int));
    }

    for(int i = 0; i < qtdePrerequisites; i++){
        int a = prerequisites[i].a;
        int b = prerequisites[i].b;
        matriz[b][a] = 1;
    }

    int *visited = calloc(numCourses, sizeof(int));

    bool ciclo = false;
    for (int i = 0; i < numCourses; i++) {
        if (visited[i] == 0) {
            if (dfs(i, numCourses, matriz, visited)) {
                ciclo = true;
                break;
            }
        }
    }

    if (ciclo){
        printf("False\n");
    }   
    else printf("True\n");

    for (int i = 0; i < numCourses; i++) free(matriz[i]);
    free(matriz);
    free(visited);

    return 0;
}

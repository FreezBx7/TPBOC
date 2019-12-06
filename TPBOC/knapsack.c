#include "knapsack.h"

/*
    DIEVART Cyriaque - CROCHON Cécile
    MASTER 1 TNSI - Groupe apprentis
*/

/* Greedy Heuristic */
void greedy(BAG b){
    int weightCounter = 0;
    int profitCounter = 0;
    for(int i = 0; i < b.n; i++) {
        if((weightCounter + b.w[i]) <= b.W) {
            b.x[i] = 1;
            profitCounter = profitCounter + b.p[i];
            printf("We select the object number %d\n", i);
        }
    }
    printf("The profit : %d $\n", profitCounter);
}

/* Initialization of the bag. We do not take any object in it */
void init_bag(BAG b) {
    for(int i = 0; i < b.n; i++) {
        b.x[i] = 0;
    }
}

/* Read file */
void get_file(char* file_name, int *n, int *W,int p[100], int w[100]) {
    FILE* fichier = NULL;
    fichier = fopen(file_name, "r+");
    if (fichier != NULL){
        int i = 0;
        fscanf(fichier, "%d %d",n,W);
        for(i = 0; i < *n ; i++){
            fscanf(fichier, "%d",&p[i]);
        }
        for(i = 0;i< *n;i++){
            fscanf(fichier, "%d",&w[i]);
        }
    }else{
        printf("Impossible to open the file %s", file_name);
    }
}

/* Memory allocation */
BAG allocation_BAG(int *n, int *W, int *w, int *p) {
    BAG bag;

    bag.n = *n;
    bag.W = *W;

    bag.p = (int *)calloc(*n, sizeof(int));
    assert(bag.p != NULL);
    bag.w = (int*)calloc(*n, sizeof(int));
    assert(bag.w != NULL);
    bag.x = (int*)calloc(*n, sizeof(int));
    assert(bag.x != NULL);

    for(int i = 0; i < bag.n; i++) {
        bag.x[i] = 0;
        bag.w[i] = w[i];
        bag.p[i] = p[i];
    }

    return bag;
}

void print_BAG(BAG b) {
    for(int i = 0; i < b.n; i++){
        printf("Objet : %d\t profit : %d\t poids : %d\n", i,b.p[i], b.w[i]);
    }
}

/* void dynamic(BAG b) {
    for(int c = 0; c <= b; c++) {

    }
} */

/* W max poids w[i] poid un objet x tout pareil p le profit */

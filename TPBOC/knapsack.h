#ifndef KNAPSACK_H_INCLUDED
#define KNAPSACK_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

/*
    DIEVART Cyriaque - CROCHON Cécile
    MASTER 1 TNSI - Groupe apprentis
*/

/* Bag's structure */
typedef struct {
    int n;      // How much object there is in the problem
    int W;      // The maximum's weight in the bag
    int *p;     // The object's profit
    int *w;     // The object's weight
    int *x;     // The object's selection (1 if true else 0)
}BAG;


/* Greedy Heuristic */
void greedy(BAG b);

/* Initialization of the bag. We do not take any object in it */
void init_bag(BAG b);

/* Read file */
void get_file(char* file_name, int *n, int *W,int p[100], int w[100]);

/* Memory allocation */
BAG allocation_BAG(int *n, int *W, int *w, int *p);

/* Print all the object */
void print_BAG(BAG b);

#endif // KNAPSACK_H_INCLUDED

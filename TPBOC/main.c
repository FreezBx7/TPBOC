#include <stdio.h>
#include <stdlib.h>
#include "knapsack.h"

int main()
{
    printf("TP Base de l optimisation combinatoire\n");

    char* file_name = "test.txt";

    int p[100];
    int w[100];
    int n = 0;
    int W = 0;

    BAG b;

    get_file(file_name, &n, &W, p, w);
    b = allocation_BAG(&n,&W,w,p);
    print_BAG(b);

    return 0;
}

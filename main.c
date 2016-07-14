/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/30/2016 01:07:21 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include "bst.h"
#include <stdlib.h>
#include <stdio.h>

/*  main.c */

#define RANGE 100
#define N 8

void print_item(link p)
{
        printf("%d", p->data);

}

int main()
{
    int i, key;
    link root = NULL;
    srand(time(NULL));
    for (i = 0; i < N; i++)
        root = insert_bst(root, rand() % RANGE);

    printf("\t\\tree");
    print_bst(root);
    printf("\n\n");
    while (root) {
        key = rand() % RANGE;
        if (search_bst(root, key)) {
            printf("delete %d in tree\n", key);
            root = delete_bst(root, key);
            printf("\t\\tree");
            print_bst(root);
            printf("\n\n");
        }
    }
    
    return 0;
}

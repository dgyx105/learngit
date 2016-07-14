/*
 * =====================================================================================
 *
 *       Filename:  bst.c
 *
 *    Description:  binary search tree api
 *
 *        Version:  1.0
 *        Created:  05/30/2016 12:03:29 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ls, 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include "bst.h"

static link creat_node(int data) {
    link p = malloc(sizeof(*p));
    if (!p)
        return NULL;

    p->data = data;
    p->l = NULL;
    p->r = NULL;

    return p;
}

static void free_node(link node) {
    free(node);
}

link search_bst(link t, int key) {
    if (!t)
        return NULL;
    if (t->data > key)
        return search_bst(t->l, key);
    if (t->data < key)
        return search_bst(t->r, key);

    return t;
}

link insert_bst(link t, int key) {
    if (!t)
        return creat_node(key);
    if (t->data > key)
        t->l = insert_bst(t->l, key);
    else 
        t->r = insert_bst(t->r, key);

    return t;
}

link delete_bst(link t, int key) {
    link p;

    if (!t)
        return NULL;

    if (t->data > key)
        t->l = delete_bst(t->l, key);
    else if (t->data < key)
        t->r = delete_bst(t->r, key);
    else {
        if (t->l == NULL && t->r == NULL) {
            free_node(t);
            t = NULL;
        } else if (t->l != NULL) {
            //replace t with the rightest node in left subtree of t
            for (p=t->l; p->r!=NULL; p=p->r)
                ;
            t->data = p->data;
            t->l = delete_bst(t->l, t->data);
        } else  {
            //replace t with the leftmost node in right subtree of t
            for (p=t->r; p->l!=NULL; p=p->l)
                ;
            t->data = p->data;
            t->r = delete_bst(t->r, t->data);
        }
    }

    return t;
}

void print_bst(link t) {
    if (t){
        printf("(");
        printf("%d", t->data);
        print_bst(t->l);
        print_bst(t->r);
        printf(")");
    } else {
        printf("(#)");
    }

}

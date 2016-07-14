/*
 * =====================================================================================
 *
 *       Filename:  bst.h
 *
 *    Description:  binary search tree INCLUDE file
 *
 *        Version:  1.0
 *        Created:  05/30/2016 11:53:39 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  ls, 
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef BST_H
#define BST_H//start

#define MAX_NODE 1000
typedef struct node *link;

struct node {
    int data;
    link l, r;
};


link search_bst(link t, int key);
link insert_bst(link t, int key);
link delete_bst(link t, int key);
void print__bst(link t);

#endif//end

//  tree.c
//  hdecode


#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

struct node *new(int x, int y){
    struct node* node = (struct node *)malloc(sizeof(struct node));
    node->value = x;
    node->position = y;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void destroy(struct node *x){
    if (x == NULL)
        return;
    destroy(x->left);
    destroy(x->right);
    free((struct node *)x);
}

struct node *insert(struct node *x, int pass, int position){
    if (x == NULL)
        return new(pass, position);        //create new node
    if ( x->value == -1 && ( position > x->position ))
        x->right = insert(x->right, pass, position);        //test if R
    else if ( x->value == -1 && ( position < x->position ))
        x->left = insert(x->left, pass, position);    //test if L
    return x;
}

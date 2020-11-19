//  tree.h
//  hdecode


#ifndef tree_h
#define tree_h

#include <stdio.h>

struct node {
    int value;
    int position;
    struct node *left;
    struct node *right;
};

struct node *new(int x, int y);

void destroy(struct node *x);

struct node *insert(struct node *x, int pass, int position);
#endif /* tree_h */

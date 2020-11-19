//  main.c
//  hdecode
//  A program to decode Huffman-coded files
//  Elliott Long


#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, const char * argv[]) {
    if ( argc != 2 ){                    //checks if right number of
        //arguements passed
        printf("Incorrect number of arguments\n");
        printf("Closing program\n");
    }
    else if(errno == EACCES){            //if no permissions
        printf("File cannot be read\n");
        printf("Ending program\n");
    }
    else{
        FILE *input = fopen( argv[1] , "rb" );
        if ( input == 0 ){        //file can't be opened
            printf("File cannot be opened\n");
            printf("Please restart program with correct\n");
            printf("file name passed\n");
        }
        else{
            struct node *root = NULL;
            int holder = 0;
            fscanf(input, "%d", &holder);   //holds numnber of nodes
            holder = holder - 1;            //used for loop
            int val = 0;
            int pos = 0;
            fscanf(input, "%d", &val);
            fscanf(input, "%d", &pos);
            root = new(val, pos);           //val and pos needed to build correct tree
            for (int i = 0; i < holder; i++){ //for length of nodes in file
                fscanf(input, "%d", &val);
                fscanf(input, "%d", &pos);
                insert(root, val, pos);        //build tree
            }
            char ch = 'A';
            struct node *move = NULL;
            move = root;
            while ( ch != 2 ){
                ch = fgetc(input);
                switch (ch){
                    case '1':
                        move = move->right;
                        if ( move->value != -1 ){
                            printf("%c", move->value);
                            move = root;
                        }
                        break;
                    case '0':
                        move = move->left;
                        if ( move->value != -1 ){
                            printf("%c", move->value);
                            move = root;
                        }
                        break;
                    case '2':
                        destroy(root);
                        //destroy(root);
                        fclose(input);
                        return 0;
                }
            }
        }
    }
    return 0;
}

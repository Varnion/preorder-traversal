/*
 * Created by Varnion on 27/06/2022.
 *
 * Program to create a tree from a digits string.
*/

#ifndef TREE_TREE_H
#define TREE_TREE_H

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* createNode(int data);
Node* insertNode(Node* node, int data);
void preorderTraversal(Node* node);

#endif

/*
 * Created by Varnion on 27/06/2022.
 *
 * Program to create a tree from a digits string
 * and perform a preorder traversal on it.
*/

// Header files.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

// Main function.
int main()
{
    // Ask the user for the number of nodes.
    int nodes;
    printf("\nNumber of Nodes:");
    scanf("%i", &nodes);

    // Ask the user for the digits string.
    char* digits = calloc(nodes + 1, sizeof(char));
    printf("\nDigits String:");
    scanf("%s", digits);

    // Create a node with the first digit.
    Node* node = createNode(digits[0] - '0');

    // Insert the other digits.
    for (int i = 1; i < strlen(digits); i++)
    {
        insertNode(node, digits[i] - '0');
    }
    free(digits);

    // Preorder Traversal.
    printf("\nPreorder Traversal: ");
    preorderTraversal(node);
    printf("\n");

    // End the program.
    return 0;
}

// Create a node.
Node* createNode(int data)
{
    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Insert a node.
Node* insertNode(Node* node, int data)
{
    if (node != NULL) // If this node exists.
    {
        if (data < node->data) // If the data is smaller than the current node.
        {
            node->left = insertNode(node->left, data); // Add it to the left subtree.
        }
        else // If the data is not smaller than the current node.
        {
            node->right = insertNode(node->right, data); // Add it to the right subtree.
        }
        return node;
    }
    else // If this node does not exist.
    {
        return createNode(data); // Create it.
    }
}

// Preorder Traversal.
void preorderTraversal(Node* node)
{
    if (node != NULL) // If this node exists.
    {
        // Print it on the screen and continue traversing.
        printf("%d ", node->data);
        preorderTraversal(node->left);
        preorderTraversal(node->right);
        if (node->left != NULL) // If left child exists.
        {
            free(node->left);
        }
        if (node->right != NULL) // If right child exists.
        {
            free(node->right);
        }
        free(node);
    }
}

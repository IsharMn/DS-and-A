#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

Node add_node(char data) 
{
    Node new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left_child = NULL;
    new_node->right_child = NULL;
    return new_node;
} /* end function add_node */

void inorder_traversal(Node root_node)
{
    if (root_node) {
        inorder_traversal(root_node->left_child);
        printf("%c ", root_node->data);
        inorder_traversal(root_node->right_child);
    }
} /* end function inorder_traversal */

void preorder_traversal(Node root_node)
{
    if (root_node) {
        printf("%c ", root_node->data);
        preorder_traversal(root_node->left_child);
        preorder_traversal(root_node->right_child);
    }
} /* end function preorder_traversal */

void postorder_traversal(Node root_node)
{
    if (root_node) {
        postorder_traversal(root_node->left_child);
        postorder_traversal(root_node->right_child);
        printf("%c ", root_node->data);
    }
} /* end function postorder_traversal */


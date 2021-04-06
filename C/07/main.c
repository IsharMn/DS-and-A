#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

int main(void)
{
    /* creating a tree */
    Node root_node = add_node('+');
    root_node->left_child = add_node('*');
    root_node->right_child = add_node('D');

    root_node->left_child->left_child = add_node('/');
    root_node->left_child->right_child = add_node('C');

    root_node->left_child->left_child->left_child = add_node('A');
    root_node->left_child->left_child->right_child = add_node('B');

    /* traversal */
    printf("Inorder traversal: ");
    inorder_traversal(root_node);
    printf("\nPreorder traversal: ");
    preorder_traversal(root_node);
    printf("\nPostorder traversal: ");
    postorder_traversal(root_node);
    printf("\n");
    return 0;
} /* end function main */

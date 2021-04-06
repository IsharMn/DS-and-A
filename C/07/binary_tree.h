#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct node {
    char data;
    struct node *left_child, *right_child;
} *Node;


Node add_node(char data);
/* traversal techniques */
void inorder_traversal(Node root_node);
void preorder_traversal(Node root_node);
void postorder_traversal(Node root_node);

#endif      /* BINARY_TREE_H */

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};
typedef struct node *NODE;

NODE create_node(int item) {
    NODE temp;
    temp = (NODE)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

NODE insertleft(NODE root, int item) {
    root->left = create_node(item);
}

NODE insertright(NODE root, int item) {
    root->right = create_node(item);
}

void display(NODE root) {
    if(root != NULL) {
        display(root->left);
        printf("%d\t", root->data);
        display(root->right);
    }
}

int count_nodes(NODE root) {
    if(root == NULL)
        return 0;
    return count_nodes(root->left) + count_nodes(root->right) + 1;
}

int height(NODE root) {
    int leftht, rightht;
    if(root == NULL)
        return -1;
    leftht = height(root->left);
    rightht = height(root->right);
    return (leftht > rightht) ? leftht + 1 : rightht + 1;
}

int leaf_nodes(NODE root) {
    if(root == NULL)
        return 0;
    else if(root->left == NULL && root->right == NULL)
        return 1;
    return leaf_nodes(root->left) + leaf_nodes(root->right);
}

int nonleaf_nodes(NODE root) {
    return count_nodes(root) - leaf_nodes(root);
}

int main() {
    NODE root = create_node(45);
    insertleft(root, 39);
    insertright(root, 78);
    insertleft(root->right, 54);
    insertright(root->right, 79);
    insertright(root->right->left, 55);
    insertright(root->right->right, 80);
    printf("The tree(inorder) is\n");
    display(root);
    printf("\n");
    printf("\nThe total number of nodes is %d", count_nodes(root)); 
    printf("\nThe height of the tree is %d", height(root)); 
    printf("\nThe total number of leaf nodes is %d", leaf_nodes(root)); 
    printf("\nThe total number of non-leaf nodes is %d", nonleaf_nodes(root)); 
    printf("\n");
}
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
}; 

int treeSize(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return treeSize(root->left) + 1 + treeSize(root->right);
}



void inorderRecursion(struct TreeNode* root, int* result, int* index) {
    if (root == NULL) {
        return;
    }

    inorderRecursion(root->left, result, index);

    result[*index] = root->val;
    (*index)++;

    inorderRecursion(root->right, result, index);
}


int* inorderTraversal(struct TreeNode* root, int* returnSize) {

    int size = treeSize(root);

    int* result = (int*)malloc(size * sizeof(int));

    int index = 0;

    inorderRecursion(root, result, &index); 

    *returnSize = size;

    return result;
}
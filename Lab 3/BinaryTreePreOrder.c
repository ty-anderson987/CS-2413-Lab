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



void preorderRecursion(struct TreeNode* root, int* result, int* index) {
    if (root == NULL) {
        return;
    }

    result[*index] = root->val;
    (*index)++;

    preorderRecursion(root->left, result, index);
    preorderRecursion(root->right, result, index);
}


int* preorderTraversal(struct TreeNode* root, int* returnSize) {

    int size = treeSize(root);

    int* result = (int*)malloc(size * sizeof(int));

    int index = 0;

    preorderRecursion(root, result, &index); 

    *returnSize = size;

    return result;
}
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//  NOTE: IN THIS QUESTION, I AM USING PRE-ORDER TRAVERSAL OF CHOICE.

typedef struct treenode{
    int data;
    struct treenode *left;
    struct treenode *right;
} node;

struct treenode *createNode(int data){
    node *newNode = (struct treenode *)malloc(sizeof(struct treenode));
    if(newNode==NULL){
        printf("Memory allocation failed");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
}


void preOrderSequence(node *root){
    if(root == NULL){
        return;
    }
    printf("%d", root->data);
    preOrderSequence(root->left);
    preOrderSequence(root->right);
}

void getLeafNodes(node *root, int *leafNodeArray, int *counter){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        leafNodeArray[*counter] = root->data;
        (*counter)++;
    }
    getLeafNodes(root->left, leafNodeArray, counter);
    getLeafNodes(root->right, leafNodeArray, counter);
    
}

bool compareLeafNodes(node *root1, node *root2){
    int leafNodes1[100], leafNodes2[100];
    int counter1 = 0, counter2 = 0;

    getLeafNodes(root1, leafNodes1, &counter1);
    getLeafNodes(root2, leafNodes2, &counter2);

    if(counter1!=counter2){
        printf("no");
        return false;
    }

    for(int i=0; i<counter1; i++){
        if(leafNodes1[i]!=leafNodes2[i]){
            return false;
        }
    }
    return true;

}

int main(){

    node *root1 = createNode(1);
    root1->left = createNode(2);
    root1->right = createNode(4);
    root1->left->right = createNode(11);
    root1->right->right = createNode(6);
    root1->right->left = createNode(8);
    root1->left->left = createNode(5);
    
    node *root2 = createNode(2);
    root2->left = createNode(3);
    root2->right = createNode(4);
    root2->left->right = createNode(11);
    root2->right->right = createNode(6);
    root2->right->left = createNode(8);
    root2->left->left = createNode(5);
    
    bool result = compareLeafNodes(root1, root2);
    if(result==1){
        printf("Yes, the leaf nodes are the same.");
    }
    else{
        printf("The leaf nodes are not the same.");
    }


    return 0;
}
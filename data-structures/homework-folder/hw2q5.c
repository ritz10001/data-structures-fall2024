#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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

    return newNode;
}

struct treenode *buildTree(node *root, int value){
    
    if(root == NULL){
        return createNode(value);
    }
    if(value < root->data){
        root->left = buildTree(root->left,value);
        //printf("Left value inserted %d\n", root->left->data);
    }
    else{
        root->right = buildTree(root->right,value);
        //printf("Right value inserted %d\n", root->right->data);
    }

    return root;

}

void deleteTree(node *root){
    if(root == NULL){
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}

bool search(node *root, int value){
    if(root==NULL){
        return false;
    }
    if(root->data==value){
        return true;
    }
    else if(value < root->data){
        search(root->left, value);
    }
    else if(value > root->data){
        search(root->right, value);
    }
}

void preOrderSequence(node *root){
    if(root == NULL){
        return;
    }
    printf("%d\n", root->data);
    preOrderSequence(root->left);
    preOrderSequence(root->right);
}

int getHeight(node *root){
    if(root == NULL){
        return -1;
    }
    int l_height = getHeight(root->left);
    int r_height = getHeight(root->right);

    if(l_height>r_height){
        return 1 + l_height;
    }
    else{
        return 1 + r_height;
    }
    

}

bool isBalanced(node *root){
    if(root == NULL){
        return true;
    }
    
    int l_height = getHeight(root->left);
    int r_height = getHeight(root->right);

    bool leftBalance = isBalanced(root->left);
    bool rightBalance = isBalanced(root->right);
    
    if(abs(l_height-r_height)<=1 && leftBalance == true && rightBalance == true){
        return true;
    }

    return false;
    

}

int main(){
    int counter;
    int nodecounter;
    int value;

    node *root = NULL;

    printf("Enter the number of nodes");
    scanf("%d", &counter);

    int nodes[counter];

    for(int i=0; i<counter; i++){
        printf("Enter Node (%d) Value", i);
        scanf("%d", &value);
        nodes[i] = value;
    }
    root = buildTree(root, nodes[0]);

    for(int i=1; i<counter; i++){
        buildTree(root, nodes[i]);
    }
     
    preOrderSequence(root);

    int val;
    printf("Enter the value you want to search: ");
    scanf("%d", &val);

    bool result = search(root, val);

    if(result==1){
        printf("The element was found!\n");
    }
    else{
        printf("This element does not exist in the tree\n");
    }

    if(isBalanced(root)){
        printf("The tree is balanced!\n");
    }
    else{
        printf("The tree is not balanced!\n");
    }

    return 0;
}
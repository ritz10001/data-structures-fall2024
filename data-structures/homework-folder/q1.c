#include<stdio.h>
#include<stdlib.h>


typedef struct listnode{
    int data;
    struct listnode *next;
} node;

struct listnode *createNode(int data){
    node *newnode = (struct listnode *)malloc(sizeof(struct listnode));
    if(newnode == NULL){
        printf("memory allocation failed!");
        exit(1);
    }
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void append(node **head, int data){
    node *newnode = createNode(data);
    
    if(*head == NULL){
        *head = newnode;
        return;
    }

    node *currentnode = *head;
    while(currentnode->next != NULL){
        currentnode = currentnode->next;
    }
    currentnode->next = newnode;

}

void printList(node* head) {
    while (head != NULL) {
        if(head->next == NULL){
            printf("%d", head->data);
            return;
        }
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int listLength(node *head){
    int counter = 0;
    while(head != NULL){
        counter++;
        head = head->next;
    }
    return counter;
}

void printMiddleNode(node *head){

    int length = listLength(head);
    int middle = (int)length/2;

    for(int i=0;i<length;i++){
        if(i<middle){
            head = head->next;
        }
        else{
            if(head->next == NULL){
                printf("%d", head->data);
                return;
            }
            printf("%d -> ", head->data);
            head = head->next;
        }
        
    }
}

int main(){
    node *headnode = NULL;

    append(&headnode, 1);
    append(&headnode, 2);
    append(&headnode, 3);
    append(&headnode, 4);
    append(&headnode, 5);
    append(&headnode, 6);

    printMiddleNode(headnode);

    return 0;
}
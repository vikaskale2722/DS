#include <stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void Traverse(struct Node* head){
    struct Node* temp = head;
    while(temp!=NULL){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct Node* InsertAtBeg(struct Node* head, int value){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = head;
    head = temp;
    return head;
}

void InsertAtEnd(struct Node* head,int value){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = NULL;
    struct Node* temp2 = head;
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp2->next = temp;
}

void InsertAtPos(struct Node* head, int value, int pos){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = value;
    struct Node* temp2 = head;
    for(int i = 1; i< pos-1; i++){
        temp2 = temp2->next;
    }
    temp->next = temp2->next;
    temp2->next = temp;
}

struct Node* DelAtBeg(struct Node* head){
    struct Node* temp = head;
    head = temp->next;
    free(temp);
    return head;
}

void DelAtEnd(struct Node* head){
    struct Node* temp = head;
    while(temp->next->next!=NULL){
        temp = temp->next;
    }
    struct Node* temp2 = temp->next;
    temp->next = NULL;
    free(temp2);
}

void DelAtPos(struct Node* head, int pos){
    struct Node* temp = head;
    for(int i = 1 ; i< pos-1 ; i++){
        temp = temp->next;
    }
    struct Node* temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2);
}

int LengthCount(struct Node* head){
    int count = 0;
    struct Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
        count++;
    }
    return count+1;
}

int main() {
    // Write C code here
    struct Node* first = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));
    
    first->data = 10;
    second->data = 20;
    third->data = 30;
    first->next = second;
    second->next = third;
    third->next = NULL;

    
    struct Node* head = first;
    
    Traverse(head);
    head = InsertAtBeg(head,100);
    Traverse(head);
    InsertAtEnd(head,200);
    Traverse(head);
    InsertAtPos(head,500,2);
    Traverse(head);
    DelAtPos(head,2);
    Traverse(head);
    printf("%d\n",LengthCount(head));
    head = InsertAtBeg(head,600);
    Traverse(head);
    printf("%d\n",LengthCount(head));    
    
    return 0;
}
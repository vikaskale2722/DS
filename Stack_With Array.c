#include<stdio.h>
#define MAX_SIZE 100

int Stack[MAX_SIZE];
int top = -1;


void Push(int x){
    if(top == MAX_SIZE-1){
        printf("STACK OVERFLOW\n");
        return;
    }
    top= top+1;
    Stack[top] = x;
}

void Pop(){
    if(top==-1){
        printf("NOTHING TO POP\n");
        return;
    }
    top = top-1;
}

int IsEmpty(){
    if(top==-1){
        return 1;
    }
    return 0;
}

int IsFull(){
    if(top==MAX_SIZE-1){
        return 1;
    }
    return 0;
}

int Top(){
    return Stack[top];
}

void Traverse(){
    for(int i = 0; i<= top;i++){
        printf("%d ",Stack[i]);
    }
    printf("\n");
}

int main(){
    Push(10);
    Push(20);
    Traverse();
    Pop();
    Traverse();
    return 0;
}
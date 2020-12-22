#include<stdio.h>
#include<stdlib.h>
struct Node {
    int value;
    Node *next;
} *head, *tail;

Node *createNode(int value) {
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->value = value;
    temp->next = NULL;
    return temp;
}

void pushTail(int value) {
    Node *temp = createNode(value);
    if(!head) {
        head = tail = temp;
    }
    else {
        tail->next = temp;
        tail = temp;
    }
    tail->next = head; //cycle
}

int checkCycle()
{
Node *curr = head;                     
while(curr) { 
    curr = curr->next;
    if(curr==head) return 1;
}
return 0;
}
int main()
{
    pushTail(1);
    pushTail(2);
    pushTail(3);
    pushTail(4);
    int x=checkCycle();
    if(x==1) printf("The Linked list has a Cycle");
    else printf("The Linked list doesnt has a Cycle");
}
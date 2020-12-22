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
}

void printLinkedList() {
  Node *curr = head;                     
  while(curr) { 
    printf("%d->", curr->value);
    curr = curr->next;
  }
  printf("NULL");
}

void Rev() {
  Node *curr= head;
  Node *prev=NULL;
  Node *next;

  while(curr) {
    next=curr->next;
    curr->next=prev;
    prev=curr;
    curr=next;
  }

  head=prev;
}

int main() {
int Nth,m,val;
  printf("Enter Linked List Size:\n");
  scanf("%d",&m);
  while(m--) {
  printf("Enter Sorted(ascending) Linked List Value:\n");
  scanf("%d",&val);
  pushTail(val);
 }
  Rev();
  printf("The sorted(descending) linked list:\n");
  printLinkedList();
  printf("\n");
}
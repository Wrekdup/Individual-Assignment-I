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

void printLinkedList(int n) {
  Node *curr = head;
  int count=0;                     
  while(curr) { 
    if(count==n) {
      printf("%d\n", curr->value);
      return;
    }
    count++; 
    curr = curr->next; 
  }
}

int checkSize() {
    int counter=0;
    Node *curr = head;                     
    while(curr) { 
        curr = curr->next;
        counter++;
}
    return counter;
}

int main() {
  int Nth,m,val;
  printf("Enter Linked List Size:\n");
  scanf("%d",&m);
  while(m--) {
  printf("Enter Linked List Value:\n");
  scanf("%d",&val);
  pushTail(val);
 }
  printf("Input Nth Node:\n");
  scanf("%d",&Nth);
  int Location=checkSize()-Nth;
  printf("The %dth Node from the end is : ",Nth);
  printLinkedList(Location);
}

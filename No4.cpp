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

void removeDup() {
    Node *curr = head;
    Node *temp;                     
    while(curr->next) { 
      if(curr->value == curr->next->value) {
        temp = curr->next->next;
        free(curr->next);
        curr->next = temp;
      }
      else
        curr = curr->next;
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

int main() {
int m,n,val;
printf("Enter Linked List Size:\n");
scanf("%d",&m);
while(m--) {
  printf("Enter Linked List Value:\n");
  scanf("%d",&val);
  pushTail(val);
 }
removeDup();
printf("Linked List Without Duplicate: ");
printLinkedList();
printf("\n");
}
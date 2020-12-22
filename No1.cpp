#include<stdio.h>
#include<stdlib.h>
struct Node {
    int value;
    Node *next;
};

Node *createNode(int value) {
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->value = value;
    temp->next = NULL;
    return temp;
}
void pushTail(Node **head,Node **tail,int value) {
    Node *temp = createNode(value);
    if( *head == NULL) {
        *head = *tail = temp;
    }
    else {
      Node *prev;
      prev = *tail;
      prev->next = temp;
      *tail = temp;
    }
}

void merge(Node **head1, Node **tail1, Node **head2, Node **headmerge, Node **tailmerge){
    Node *curr2 = *head2;
    Node *temp;
    Node *curr = *head1;
    while(curr2&&curr) {
      if(curr->value <= curr2->value) {
        pushTail(&*headmerge,&*tailmerge,curr->value);
        temp=curr;
        curr = curr->next;
        free(temp);
      }
      else {
        pushTail(&*headmerge,&*tailmerge,curr2->value);
        temp=curr2;
        curr2 = curr2->next;
        free(temp);
      }
        
    }
    while(curr2) {
      pushTail(&*headmerge,&*tailmerge,curr2->value);
        curr2 = curr2->next;
    }
    while(curr) {
      pushTail(&*headmerge,&*tailmerge,curr->value);
      curr = curr->next;
    }
}

void printLinkedList(Node *head) {
  Node *curr = head;                     
  while(curr) {
    printf("%d->", curr->value); 
    curr = curr->next; 
  }
  printf("NULL");
}

int main() {
  Node *head=NULL, *tail=NULL, *head2=NULL, *tail2=NULL, *headmerge=NULL, *tailmerge=NULL;
  int m,n,val;
  printf("Enter Linked List 1 Size:\n");
  scanf("%d",&m);
  while(m--) {
    printf("Enter Linked List 1 Value:\n");
    scanf("%d",&val);
    pushTail(&head,&tail,val);
  }
  printf("Enter Linked List 2 Size:\n");
  scanf("%d",&n);
  while(n--) {
    printf("Enter Linked List 2 Value:\n");
    scanf("%d",&val);
    pushTail(&head2,&tail2,val);
  }
  merge(&head,&tail,&head2,&headmerge,&tailmerge);
  printf("Merged Sorted Linked List:\n");
  printLinkedList(headmerge);
}
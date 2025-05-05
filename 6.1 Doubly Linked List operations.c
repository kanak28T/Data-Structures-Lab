//Write a C program to implement a menu-driven application that uses a doubly linked list to perform the following operations:
// Create, Insert, Delete, Display, Reverse, Exit

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

struct Node *head= NULL;
struct Node *tail= NULL;

void insert(int value){
	struct Node *new = (struct Node *)malloc(sizeof(struct Node));
	new->data = value;
	new->prev = NULL;
	new->next = NULL ;

	if(head == NULL){
		new->prev = NULL;
		head = tail = new;
	}
	else{
		struct Node* temp = head;
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = new;
		new->prev = temp;
		tail = new;
	}
}

void remov(int data){
	struct Node *temp = head;
	while(temp != NULL && temp->data != data){
		temp = temp->next;
	}
	if(temp == NULL){
		printf("%d not found\n",data);
		return;
	}
	if(temp == head){
		head = temp->next;
		if(head != NULL){
			head->prev = NULL;
		}
	}
	else if(temp == tail){
		tail = temp->prev;
		if(tail != NULL){
			tail->next = NULL;
		}
    else{
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
    }
    free(temp);
    return ;
    printf("%d not found\n",data);
}
        
void display(){
    struct Node *temp = head;
    if(head == NULL){
        printf("List is empty.\n");
        return;
    }
    while(temp != NULL){
        printf("%d\t",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
        
void reverse(){
    if(head == NULL || head->next == NULL){
         return;
     }
    struct Node *temp = NULL;
    struct Node *curr = head;
    while(curr != NULL){
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    if(temp != NULL){
         head = temp->prev;
    }
}
    
int main() {
     int n, ch;
     do {
        printf("Operations on doubly linked list\n");
        printf("1.Insert\n2.Remove\n3.Display\n4.Reverse\n0.Exit\n");                printf("Enter Choice 0-4: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter number: ");
                scanf("%d", &n);
                insert(n);
                break;
            case 2:
                printf("Enter number to delete: ");
                scanf("%d", &n);
                remov(n);
                break;
            case 3:
                display();
                break;
            case 4:
                reverse();
                printf("List reversed\n");
                break;
        }
        } while (ch != 0);
        return 0;
}
        
        
     
//Write a menu driven C program that implements singly linked list for the following operations:

#include<stdio.h>
#include<stdlib.h>

#include "AllOperations.c"
int main() {
    NODE list1 = NULL, list2 = NULL;
    int choice, x;

    while (1) {
        printf("1. Create SLL1\n");
        printf("2. Create SLL2\n");
        printf("3. Display SLL1\n");
        printf("4. Display SLL2\n");
        printf("5. Concatenation\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter elements for SLL1 (-1 to end): ");
                scanf("%d", &x);
                while (x != -1) {
                    list1 = addNode(list1, x);
                    scanf("%d", &x);
                }
                break;
            case 2:
                printf("Enter elements for SLL2 (-1 to end): ");
                scanf("%d", &x);
                while (x != -1) {
                    list2 = addNode(list2, x);
                    scanf("%d", &x);
                }
                break;
            case 3:
                printf("SLL1: ");
                displayList(list1);
                break;
            case 4:
                printf("SLL2: ");
                displayList(list2);
                break;
            case 5:
                list1 = concatenate(list1, list2);
                printf("Concatenated List: ");
                displayList(list1);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

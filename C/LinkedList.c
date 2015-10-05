/* LinkedList.c
 *
 * A basic linked list
 * github.com/z-ko
 */

#include<stdio.h>
#include<stdlib.h>
#include"LinkedList.h"

/* Represents a node in the list */
struct Node {
    int data;
    struct Node* next;
};

struct Node* head;

/*
 * Function: newNode
 * ------------------
 * Creates a new node
 *
 * data: The value to be inserted in the node.
 *
 * returns: A pointer to the newly created node.
 */
struct Node* newNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

/*
 * Function: insertAtHead
 * ----------------------
 * Inserts a node at the front of the list.
 *
 * data: The value to be inserted into the node.
 */
void insertAtHead(int data) {
    struct Node* node = newNode(data);

    if(head == NULL) {
        head = node;
        return;
    }

    node->next = head;
    head = node;
}

/*
 * Function insertAtTail
 * ---------------------
 * Inserts a node at the end of the list.
 *
 * data: The value to be inserted into the node.
 */
void insertAtTail(int data) {
     struct Node* temp = head;
     struct Node* node = newNode(data);

     if(head == NULL) {
         head = node;
         return;
     }

     while(temp->next != NULL) {
         temp = temp->next;
     }
     temp->next = node;
}

/*
 * Function: search
 * ----------------
 * Traverses the linked list to see if it contains an item.
 *
 * data: The item to search for.
 *
 * returns: 0(false) or 1(true)
 */
int search(int data) {
     struct Node* temp = head;

     while(temp != NULL) {
         if(temp->data == data) {
             return 1;
         }
         temp = temp->next;
     }
     return 0;
}

/*
 * Function: removeItem
 * --------------------
 * Removes a given item in the list.
 *
 * data: The item to remove from the list.
 *
 * returns: 0(false) or 1(true)
 */
int removeItem(int data) {
     struct Node* temp = head;
     struct Node* previous = (struct Node*) NULL;

     if(temp->data == data && temp->next == NULL){
         head = NULL;
         return 1;
     } else if(temp->data == data) {
         head = head->next;
         return 1;
     }

     while(temp != NULL) {
         if(temp->data == data) {
             previous->next = temp->next;
            free(temp);
             return 1;
         }
         previous = temp;
         temp = temp->next;
     }
     return 0;
}

/*
 * Function: printList
 * ------------------
 * Prints the entire list
 */
void printList() {
     struct Node* temp = head;

     while(temp != NULL) {
         printf("%d -> ",temp->data);
         temp = temp->next;
     }

     printf("NULL");
     printf("\n");
}

int main() {
     head = NULL;
     int input = 1;
     int dataInput;

     while(input != 0) {
        printf("List status: ");
        printList();
        printf("1: Insert item at head\n");
        printf("2: Insert item at tail\n");
        printf("3: Search\n");
        printf("4: Remove\n");
        printf("0: quit\n");
        printf("> ");
        scanf("%d",&input);
        switch(input) {
            case 1:
                printf("Item value: ");
                scanf("%d",&dataInput);
                insertAtHead(dataInput);
                break;
            case 2:
                printf("Item value: ");
                scanf("%d",&dataInput);
                insertAtTail(dataInput);
                break;
            case 3:
                printf("Item to search for: ");
                scanf("%d",&dataInput);

                if(search(dataInput) == 1) {
                    printf("%d IS in the list\n\n",dataInput);
                } else {
                    printf("%d IS NOT in the list\n\n",dataInput);
                }
                break;
            case 4:
                printf("Item to remove: ");
                scanf("%d",&dataInput);

                if(removeItem(dataInput) == 1) {
                    printf("REMOVE SUCCESSFUL\n");
                } else {
                    printf("ITEM NOT IN LIST\n");
                }
                break;
        }
     }
}

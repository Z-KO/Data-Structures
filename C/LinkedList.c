/* LinkedList.c
 *
 * A basic linked list
 * github.com/z-ko
 */

#include<stdio.h>
#include<stdlib.h>

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
        }
     }
}

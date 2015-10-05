/**
 * LinkedList.h
 *
 * Author: zujko
 */

//Represents a node in the list
struct Node 
{
	int data;
	struct Nose* next;
};

/**
 * newNode
 * Description: Creates a new node with a next of NULL
 *
 * @param data The data to store in the node.
 * @return Pointer to the new node.
 */
struct Node* newNode(int data);

/**
 * insertAtHead
 * Description: Inserts a node at the front of the list. 
 *
 * @param data The data to insert into the list 
 */
void insertAtHead(int data);

/**
 * insertAtTail
 * Description: Inserts a node at the end of the list. 
 *
 * @parm data The data to insert into the list.
 */
void insertAtTail(int data);

/**
 * search
 * Description: Traverses the list to see if it contains an item.
 *
 * @param data The item to search for.
 * @return Returns success or failure status code.
 */
int search(int data);

/**
 * removeItem
 * Description: Removes a given item in the list.
 *
 * @param data The data to remove.
 */
int removeItem(int data);

/**
 * printList
 * Description: Prints the entire list.
 */
void printList();



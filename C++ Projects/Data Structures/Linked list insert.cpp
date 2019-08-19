
#include <iostream> 
using namespace std; 

class Node 
{ 
	public: 
	int info; 
	Node *next; 
}; 

void push(Node** head_reference, int new_info) 
{
	Node* newNode = new Node(); 

	newNode->info = new_info; 

	newNode->next = (*head_reference); 

	(*head_reference) = newNode; 
} 

void insertAfter(Node* prev_node, int new_info) 
{
	if (prev_node == NULL) 
	{ 
		cout<<"the given previous node cannot be NULL"; 
		return; 
	} 

	Node* newNode = new Node(); 

	newNode->info = new_info; 

	newNode->next = prev_node->next;

	prev_node->next = newNode; 
} 

void append(Node** head_reference, int new_info) 
{ 
	Node* newNode = new Node(); 

	Node *last = *head_reference;

	newNode->info = new_info; 

	newNode->next = NULL; 

	if (*head_reference == NULL) 
	{ 
		*head_reference = newNode; 
		return; 
	} 

	while (last->next != NULL) 
		last = last->next; 

	last->next = newNode; 
	return; 
} 

void printList(Node *node) 
{ 
	while (node != NULL) 
	{ 
		cout<<" "<<node->info; 
		node = node->next; 
	} 
} 

/* Main Function*/
int main() 
{ 
	Node* head = NULL; 
	
	append(&head, 6); 
	
	push(&head, 7); 
	
	push(&head, 1); 
	
	append(&head, 4); 
	 
	insertAfter(head->next, 8); 
	
	cout<<"Created Linked list is: "; 
	printList(head); 
	
	return 0; 
}

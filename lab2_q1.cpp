#include <iostream>
using namespace std;

//Creat class for node
class node{
	public:
		// data
		int data;
		//pointer to the next node
		node * next;
		// construct that makes the pointer to NULL
		node(){
			next = NULL;
		}	
};

class LinkedList{
	// Head and nodes linked with each other
	public:
		// Head -> node type pointer
		node * head;
		node * tail;
		// construct that makes the head and tail to NULL
		LinkedList(){
			head = NULL;
			tail = NULL;
		}
		// Nodes inside linked with each other
		// Rules how nodes are linked
		
		//Insert
		void insert(int value){
			// If 1st Node is added
			node * temp = new node;
			//insert value in this node
			temp->data = value;
			// 1st node only
			if(head == NULL){
				head = temp;
			}
			// Any other node only
			else{
				tail->next = temp;
			}
			tail = temp;
		}
		
		void insertAt(int pos, int value){
			// Reach the place before the pos
			node * current = head;
			int i = 1;
			while(i < pos-1){
				i++;
				current = current->next;
			}
			
			// Creat a node
			node * temp = new node;
			temp->data = value;
			
			// Moving pointers
			temp->next = current->next;
			current->next=temp;
		}
		
		void delet(){
			// Store the tail in temp
			node * temp = tail;
			// before tail has to print to null
			node * current = head;
			while(current->next != tail){
				current = current->next;
			}
			current->next = NULL;
			// update tail
			tail = current;
			// delete temp
			delete temp;
		}
		void deleteAt(int pos){
			// Reach the place of pos
			node * current = head;
			node * previous;
			int i = 1;
			while(i < pos){
				i++;
				previous = current;
				current = current->next;
			}
			// Store the pos in temp
			node * temp = previous->next;
			//moving pointers
			previous->next = current->next;
			// delete temp
			delete temp;
		}
		void countItems(){
			// counting of the items
			node * current = head;
			int i = 0;
			while(current != NULL){
				i++;
				current = current->next;
			}
			cout << "Number of items in linked list: " << i <<endl;
		}
		void display(){
			node * current = head;
			while(current != NULL){
				cout << current->data << " -> ";
				current = current->next;
			}
			cout <<"NULL" << endl;
		}
		
};

int main(){
	LinkedList l1;
	l1.insert(1);
	l1.insert(2);
	l1.insert(3);
	l1.insert(4);
	l1.insert(5);
	cout << "Display after creating of linked list" << endl;
	l1.display();
	l1.insertAt(3,9);
	cout << "Display after inserting node at pos 3 (data=9)" << endl;
	l1.display();
	l1.delet();
	l1.deleteAt(4);
	cout << "Display after deleting node at the end and at pos 4" << endl;
	l1.display();
	l1.countItems();
	return 0;
}

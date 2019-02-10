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
			if(pos == 1){
				node * current = head;
				node * temp = new node;
				head = temp;
				temp->next = current;
				temp->data = value;
			}
		
			else{
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
	}
		void revDisplay(){
			revDisplay2(head);
		}
		void revDisplay2(node * current){
			// Moves to next (till available)
			if(current == NULL) return;
			else{
				revDisplay2(current->next);
				cout << current->data <<"->";
			}
			//While coming back you print
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
			if(pos==1){
				if (head == NULL){
					cout<<"Head is empty now"<<endl;
				}
				else{
					node * temp = head;
					head = head->next;
					delete temp;
				}
			}
			else{
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
		}
		int countItems(){
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
//#include<iostream>
//#include "lab2_q1.cpp"
using namespace std;

class Queues{
	public:
		node * top;
		LinkedList l1;
		Queues(){
			top = l1.head;
		}
		//Pushes on top
		void enqueue(int value){
			l1.insertAt(1,value);
			top = l1.head;
		}
			//Pops the top
		void dequeue(){
			if( top == NULL){
				cout<<endl<<"******Queue is empty!!!******"<<endl<<endl;
			}
			else{
				node * current = l1.head;
				int i = 0;
				while(current != NULL){
					i++;
					current = current->next;
				}	
			
				//void deleteAt(int pos){
				l1.deleteAt(i);
				//top = new_head
				top = l1.head;
			}
		}
			
		bool isEmpty(){
			if(top == NULL) return true;
			return false;
		}
		int size(){
			return l1.countItems();
		}
		int topDisplay(){
			
		}
		void display(){
			l1.display();
		}
};

int main(){
	Queues q1;
	for(int i = 0; i < 4; i++){
			q1.enqueue(i);
		}
		cout<<"Display after Enqueue"<<endl;
		q1.display();
		q1.dequeue();
		cout<<"Display after Dequeue"<<endl;
		q1.display();
		q1.dequeue();
		cout<<"Display after Dequeue for one more time"<<endl;
		q1.display();
		q1.isEmpty();
		q1.size();
		return 0;	
}

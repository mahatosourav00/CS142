#include <iostream>
using namespace std;

class node{
	public:
		//data
		int data;
		//pointer to the next node
		node * next;
		node * prev;
		//construct that makes the pointer to null
		node(int value){
			next = NULL;
			prev = NULL;
			data = value;
		}
};

class DLL{
	public:
		node * head;
		DLL(){
			head = NULL;
		}
		void insert (int value){
			//creat a new node
			node * temp = new node(value);
				//Ceck if empty list
				if(head == NULL){
					head = temp;
				}
				
			else{
				node * current = head;
				while(current->next != NULL){
					current = current->next;
				}
				current->next = temp;
				temp->prev = current;
			}
		}
		void display(){
			node * current = head;
			node * last;
			cout << "Print in order : ";
			while(current!=NULL){
				cout <<current->data<< "->";
				//Store the current in the last;
				last = current;
				//Move forward
				current = current -> next;
			}
			cout<<endl;
			cout<< "Print in Reverse order : ";
				while(last!=NULL){
					cout <<last->data<< "->";
					//move backwards
					last = last->prev;
				}
				cout<<endl;
		}
		void InsertAt(int value, int pos){
			//reach the place before pos
			node * current = head;
			node * later;
			int i=1;
			while(i<pos-1){
				i++;
				current = current->next;
			}
			//creat a node
			node * temp = new node(value);
			later = current->next;
			temp->next = later;
			temp->prev = current;	
			later->prev = temp;
			current->next = temp;
			
		}
		void DeleteAt (int pos){
			node * current = head;
			node * earl;
			node * later;
			int i = 1;
			while(i<pos){
				i++;
				current = current->next;
			}
			later = current->next;
			later->prev = current->prev;
			earl = current->prev;
			earl->next = later;
			delete current;
		}
		void Del(){
			node * current = head;
			node * earl;
			while(current->next!=NULL){
				earl = current;
				current = current->next;
			}
			earl->next = NULL;
			delete current;
		}
		void countItems(){
			int i = 1;
			node * current = head;
			while(current->next != NULL){
				i++;
				current = current->next;
			}
			cout << "Total items in Linked List are : " << i;
		}
};

int main(){
	DLL dl11;
	for (int i=1; i < 11; i++){
		dl11.insert(i);
	}
	dl11.display();
	dl11.InsertAt(11,3);
	dl11.display();
	dl11.DeleteAt(5);
	dl11.display();
	dl11.Del();
	dl11.display();
	dl11.countItems();
	return 0;
}


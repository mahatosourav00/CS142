#include<iostream>
using namespace std;

class node{
	public:
		//data
		int data;
		//pointer
		node * next;
		//construct that makes the pointer to NULL
		node (int value){
			next = NULL;
			data = value;
		}
};

class CSLL{
	public:
		node * head;
		CSLL(){
			head = NULL;
		}
		//inserts to the end of the linked list
		void insert(int value){
			node * temp = new node(value);
			//check if empty list
			if(head == NULL){
				head = temp;
			}
			else{
				//if not empty list
				node * current = head;
				while(current->next != head)
					current = current->next;
					current->next = temp;
				}
				temp->next = head;
		}
		//Displays the linked list
		void display(){
			node * current = head;
			if(current == NULL){
				cout << "No elements"<<endl;
				return;
			}
			while(current->next != head){
				// stopping at head
			cout << current->data<< "->";
			current = current->next;
			}
			//printing the last element
			cout << current->data;
			cout << endl;
		}
		void insertAt(int pos, int value){
			node * current = head;
			int i = 1;
			while(i < pos-1){
				i++;
				current = current->next;
			}
			node * temp = new node(value);
			temp->next = current->next;
			temp->data = value;
			current->next = temp;
		}
		void delet(){
			node * current = head;
			node * temp;
			node * prev;
			while(current->next != head){
				prev = current;
				current = current->next;
			}
			temp = current;
			prev->next = head;
			delete temp;
		}
		void deletAt(int pos){
			node * current = head;
			node * temp;
			node * prev;
			int i = 1;
			while(i < pos){
				i++;
				prev = current;
				current = current->next;
			}
			temp = current;
			prev->next = current->next;
			delete temp;
		}
		void countItems(){
			// counting of the items
			node * current = head;
			int i = 1;
			while(current->next != head){
				i++;
				current = current->next;
			}
			cout << "Number of items in linked list: " << i <<endl;
		}
};
		
		int main(){
			CSLL csll1;
			for(int i; i < 11; i++){
				csll1.insert(i); 
			}
			cout<<"After creating circula linked list : ";
			csll1.display();
			csll1.insertAt(3,17);
			cout<< "After inserting 17 at 3 rd position : ";
			csll1.display();
			csll1.delet();
			cout<< "After deleting the end part : ";
			csll1.display();
			csll1.deletAt(4);
			cout<< "After deleting at 4th position : ";
			csll1.display();
			csll1.countItems();
			return 0;
		}

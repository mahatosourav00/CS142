#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node * left;
		Node * right;
		Node(int value){
			left = NULL;
			right = NULL;
			data = value;
		}
};
class BST {
	public:
		Node * root;
		BST (){
			root = NULL;
		}
		void insertHelper(int value){
			insert(root, value);
		}
		void insert (Node * curr, int value){
			//if root is NULL, then creat a node and make it as root
			if(root == NULL) root = new Node(value);
			//else decide left or right
			else if(value < curr->data){
				//if left is already null, creat a new node and link it
				if (curr->left == NULL) curr->left = new Node(value);
				//move left and call insert there
				else insert(curr->left, value);
			}
			else{
				//if right is already null creat a new node and link it
				if(curr->right == NULL) curr->right = new Node(value);
				//move right and call insert
				else insert(curr->right, value);
			}
		}
		void displayHelper(){
			display(root);
		}
		void display(Node * curr){
			//in case for empt tree and nodes
			if (curr == NULL)return;
			//in order print
			else{
				//print left
				display(curr->left);
				//print myself
				cout<<curr->data<<", ";
				//print right
				display(curr->right);
			}
		}
		Node * searchHelper(int value){
			search(root, value);
		}
		Node * search(Node * curr, int value){
			//Are you the value? Or are you null? if yes return curr
			if (curr ==  NULL || curr->data == value) return curr;
			//left
			else if (value<curr->data) return search(curr->left, value);
			//right
			else search(curr->right, value);
		}
};

int main(){
	BST bst1;
	bst1.insertHelper(7);
	bst1.insertHelper(5);
	bst1.insertHelper(8);
	bst1.insertHelper(2);
	bst1.insertHelper(9);
	bst1.insertHelper(6);
	bst1.insertHelper(1);
	bst1.insertHelper(3);
	bst1.insertHelper(4);
	/*bst1.displayHelper();
	if(bst1.searchHelper(3) != NULL){
		cout<<endl<<bst1.searchHelper(3)->data<<endl;
	}*/
	return 0;
}

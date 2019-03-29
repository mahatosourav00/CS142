#include<iostream>
using namespace std;
class Node{
	public:
		int data;
		Node * left;
		Node * right;
		Node * P;
		Node(int value){
			left = NULL;
			right = NULL;
			data = value;
		}
};
class BST {
	public:
		Node * root;
		int i;
		BST (){
			root = NULL;
			i = 0;
		}
		void insertHelper(int value){
			insert(root, value);
			i++;
		}
		void insert (Node * curr, int value){
			//if root is NULL, then creat a node and make it as root
			if(root == NULL) root = new Node(value);
			//else decide left or right
			else if(value < curr->data){
				//if left is already null, creat a new node and link it
				if (curr->left == NULL) {
					Node * temp = new Node(value);
					temp->P = curr;
					curr->left = temp;
				}
				//move left and call insert there
				else insert(curr->left, value);
			}
			else{
				//if right is already null creat a new node and link it
				if(curr->right == NULL){
					Node * temp = new Node(value);
					temp->P = curr;
					curr->right = temp;
				}
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
		int count(){
			cout<<"Total items = "<<i<<endl;
		}
		Node * find_minHelper(){
			find_min(root);
		}
		Node * find_min(Node * curr){
			//in case for empty tree and nodes
			if (curr->left == NULL){
				cout<<"Minimum is = "<<curr->data<<endl;
			}
			//in order print
			else{
				//print left
				find_min(curr->left);
			}
		}
		void replace_At_Parent(Node * A, Node *B){
			Node *p=A->P;	
			Node *pa=B->P;		
			delete	A;
			if(p->left==A){
				p->left=B;
			}
			else{
				p->right=B;
			}
			if(pa->left==B){ 
				pa->left=NULL;
			}
			else{
				pa->right=NULL;
			}
			B->P=p;			
		}
		Node * searchP(int value){
			if(searchHelper(value)){
					searchPM(value,root);		
				}
			else{
				cout<<"\nThe element is not present\n";
			}
		}
		Node *searchPM(int value,Node* curr){
			if(curr==NULL){
				cout<<"end";
			}
			else if(curr->data==value)	
			return curr;
			if(value < curr->data){
				searchPM(value,curr->left);
			}
			else{
				searchPM(value,curr->right);
			}
		}
		void Delete(int value){
			if(searchHelper(value)){
				Node *N=searchP(value);	
				if(N->left!=NULL)
				{
					if(N->right!=NULL){	
						Node *M=find_min(N->right);
						N->data=M->data;
						if(M->P!=N)
						M->P->left=NULL;	
						delete M;
					}
				}
			}
			else{
				cout<<"\nThe element is not present\n";
			}
		}
		
		int height(){
			int M=0;		
			heightHelper(root,&M,0);	
			return M;
		}
	void heightHelper(Node *curr,int *m,int T){
		if(curr==NULL){
			if(T>*m)
			*m=T;
			return;	
		}
	heightHelper(curr->left,m,T+1);	
	heightHelper(curr->right,m,T+1);	
	}

	 int R_search(int a, int b){
		int c=0;			
		cout<<endl;
		R_searchM(a,b,&c,root);	
		if(c==0)
			cout<<"\nThere are no elements in this range\n";
		return c;				
	}
	void R_searchM(int x,int y, int * C, Node*curr)	{	
		if(curr==NULL)			
			return;	
		R_searchM(x,y,C,curr->left);	
		int V=curr->data;
		if(V>=x&&V<=y){
			(*C)++;
			cout<<V<<" ";
		}
		R_searchM(x,y,C,curr->right);	
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
	bst1.displayHelper();
	if(bst1.searchHelper(3) != NULL){
		cout<<endl<<bst1.searchHelper(3)->data<<endl;
	}
	bst1.count();
	bst1.find_minHelper();
	bst1.Delete(3);
	bst1.displayHelper();
	return 0;
}

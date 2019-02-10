#include <iostream>
using namespace std;
class StackArr{
	public:
		int top;
		int n;
		int stack[5];
		StackArr(){
			top=-1;
			n=5;
		}
		void push() {
   			if(top>=n-1)
      			cout<<"Stack Overflow"<<endl; 
   			else {
   				top++;
   				cout<<"Enter the value you want to push:"<<endl;
      			cin>>stack[top];
   			}
		}
		void pop() {
  			if(top<=-1)
   	     		cout<<"Stack Underflow"<<endl;
   			else {
      			cout<<"The popped element is "<< stack[top] <<endl;
      			top--;
   			}
		}
		void display() {
   			if(top>=0) {
      			cout<<"Stack elements are:";
      			for(int i=top; i>=0; i--)
         			cout<<stack[i]<<" ";
         		cout<<endl;
   			} 		
   			else
    		  cout<<"Stack is empty";
		}
};

int main(){
	int size;
	StackArr s1;
	for(int i = 0; i<5; i++)
		s1.push();
	s1.display();
	s1.pop();
	s1.display();
}

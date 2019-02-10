#include <iostream>
using namespace std;
class QueueArr{
	public:
		int top;
		int n;
		int stack[5];
		QueueArr(){
			top=-1;
			n=5;
		}
		void enqueue() {
   			if(top>=n-1)
      			cout<<"Stack Overflow"<<endl; 
   			else {
   				top++;
   				cout<<"Enter the value you want to push:"<<endl;
      			cin>>stack[top];
   			}
		}
		void dequeue() {
  			if(top<=-1)
   	     		cout<<"Stack Underflow"<<endl;
   			else {
      			cout<<"The popped element is "<< stack[0] <<endl;
      			stack[0]=NULL;
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
	QueueArr q1;
	for(int i = 0; i<5; i++)
		q1.enqueue();
	q1.display();
	q1.dequeue();
	q1.display();
}

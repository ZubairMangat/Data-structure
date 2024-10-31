#include<iostream>
using namespace std;
struct stack {
    int data;
    stack* next;

}*top=nullptr;
//stack* top =nullptr;
void push(int value){
    stack * p =new stack;
    p->data=value;
    p->next=nullptr;
    if (top==nullptr){
        top=p;
    }
    else
    {
        p->next=top;
        top=p;

    }
}
void peek(){
    cout<<"The peek value is : "<<top->data;
}
void pop(){  //int if you want to return
    if (top==nullptr){
        cout<<"Stack is empty!!!";
    }
    else
    {
        stack* th =top;
       // int popvalue=top->data; 
        top=top->next;
        delete th;
        //return popvalue;
    }
}

int main (){
push(231204);
push(231178);
peek();
cout<<endl;
pop();
peek();


}
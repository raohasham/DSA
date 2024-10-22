#include<iostream>

class stack{
    public:
    int stk[10];
    int top = -1;

    bool isEmpty(){
        if (top==-1)
        {
            return true;
        }
        else{
            return false;
        }
        
    }

    bool isFull(){
        if(top==9){
            return true;
        }
        else
        {
            return false;
        }
        
    }

    void push(int a){
        if (isFull())
        {
            std::cout<<"stack overflown"<<std::endl;
            return;
        }
         top++;
        stk[top] = a;
    }

    int pop(){
        if (isEmpty())
        {
            std::cout<<"stack is empty"<<std::endl;
            return 0000000;
        
        }
        else
        {
            top--;
            std::cout<<stk[top+1]<<std::endl;
            return stk[top+1];
        
        }
           
    }

    int peek(){
        if (isEmpty())
        {
            std::cout<<"stack is empty "<<std::endl;
            return 00000000;
        }
        else{
            std::cout<<stk[top]<<std::endl;
            return stk[top];
        }
        
    }

};

int main(){
    stack s;
    s.push(1);
    s.push(2);
    s.push(1);
    s.push(2);
     s.peek();
    s.push(1);
    s.push(2);
    s.push(1);
     s.peek();
    s.push(2);
    s.push(1);
    s.push(2);
    s.push(3);
    s.peek();
    s.pop();
    
    return 0;
}
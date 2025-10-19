#include<iostream>

using namespace std;

class stack{

public:
    int top;
    char *arr;
    int size;

    stack(int size){
        this->size = size;
        arr = new char[size];
        top = -1;
    }

    void push(char data){
        if(top>=size){
            cout<<"Stack overflow"<<endl;
            return;
        }
        arr[++top]=data;
    }

    void pop(bool &is_empty){
        if(top == -1){
            cout<<"Stack Underflow"<<endl;
            is_empty = true;
            return ;
        }
        cout<<"Popped: "<<arr[top--]<<endl;
        // top--;
    }

    void display(){
        for(int i=0;i<=top;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    int n;
    cout<<"Enter the size of the valid parantheses: ";
    cin>>n;
    stack st(n);
    string para;
    cout<<"Enter a valid parantheses string of types '()' , '[]' , '{}' : ";
    cin>>para;
    

}
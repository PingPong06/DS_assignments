#include<iostream>

using namespace std;
// # define n 100
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
        if(top >= size-1){
            cout<<"Stack overflow"<<endl;
            return;
        }
        arr[++top]=data;
    }

    void pop(){
        if(top == -1){
            cout<<"Stack Underflow"<<endl;
            return ;
        }
        cout<<arr[top--]<<" ";
    }
};
int main(){
    int size;
    cout<<"Enter the size of the string: ";
    cin>>size; 
    cin.ignore();
    stack obj(size);
    string reverseString;
    cout<<"Enter the string: ";
    getline(cin , reverseString);
    cout<<endl;
    for(int i=0;i<reverseString.size();i++){
        obj.push(reverseString[i]);
    }
    for(int i=0;i<reverseString.size();i++){
        obj.pop();
    }
    return 0;
}

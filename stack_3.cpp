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
        if(top == size-1){
            cout<<"Stack overflow"<<endl;
            return;
        }
        arr[++top]=data;
    }

    void pop(){
        if(top == -1){
            cout<<"Stack Underflow"<<endl;
            // is_empty = true;
            return ;
        }
        top--;
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
    // int n;
    // cout<<"Enter the size of the parantheses: ";
    // cin>>n;
    
    string para;
    cout<<"Enter a parantheses string of types '()' , '[]' , '{}' : ";
    cin>>para;

    stack st(para.size());
    int count=0;
    for(int i=0;i<para.size();i++){
        char check = para[i];
        char compare = st.arr[st.top];
        
        if(check == '(' || check == '[' || check == '{') st.push(check);
        else if(compare == '(' && check == ')' ){
            st.pop();
            count++;
        }
        else if(compare == '[' && check == ']'  ){
            st.pop();
            count++;
        }
        else if(compare == '{' && check == '}'  ){
            st.pop();
            count++;
        }
    }
    if(st.top == -1 && count == para.size()/2) cout<<"valid parentheses"<<endl;
    else cout<<"Not a valid Parentheses"<<endl;

}
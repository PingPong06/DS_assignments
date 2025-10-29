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

int main() {
    string para;
    cout << "Enter a parentheses string of types '()' , '[]' , '{}' : ";
    cin >> para;

    stack st(para.size());

    for (int i = 0; i < para.size(); i++) {
        char check = para[i];

        if (check == '(' || check == '[' || check == '{') {
            st.push(check);
        }
        else {
            if (st.top == -1) {
                cout << "Not a valid Parentheses" << endl;
                return 0;
            }
            char compare = st.arr[st.top];
            if ((compare == '(' && check == ')') ||
                (compare == '[' && check == ']') ||
                (compare == '{' && check == '}')) {
                st.pop();
            }
            else {
                cout << "Not a valid Parentheses" << endl;
                return 0;
            }
        }
    }

    if (st.top == -1)
        cout << "Valid Parentheses" << endl;
    else
        cout << "Not a valid Parentheses" << endl;
}

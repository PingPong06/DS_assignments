#include<iostream>

using namespace std;

class stack{

public:
    int top;
    int *arr;
    int size;
    stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }
    void push(int data){
        if(top>=size){
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
    cout<<"Enter the size of the stack: ";
    cin>>n;
    stack st(n);

    int store[n];
    cout<<"Enter any "<<n<<" elements: ";
    for(int i=0;i<n;i++){
        cin>>store[i];
        st.push(store[i]);
    }

    cout<<"\nYou are allowed to perform any operation in total 5 times -_-\n";
    cout<<"Available options:\n";
    cout<<"1. Insert an element to stack\n";
    cout<<"2. Remove an element from stack\n";
    cout<<"3. Display all elements of stack\n\n";

    cout<<"To avail first option enter '1'\n";
    cout<<"To avail second option enter '2'\n";
    cout<<"To avail third option enter '3'\n";

    
    int count = 0;
    while(count != 5){
        cout<<"\nEnter the number as per your choice of operation: ";
        int opt;
        cin>>opt;
        switch (opt){
            case 1:
            cout<<"Enter the element to be inserted: ";
            int ins;
            cin>>ins;
            st.push(ins);
            break;

            case 2:
            st.pop();
            break;

            case 3:
            cout<<"current stack: ";
            st.display();
            break;

            default:
            cout<<"Enter a valid option"<<endl;
            break;
        }
        count++;
    }
    cout<<"\nFinal stack looks like: ";
    st.display();
}

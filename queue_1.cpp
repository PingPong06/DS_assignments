#include <iostream>
using namespace std;

#define size 100
class queue{
    int arr[size];
    int front,rear;
    
public:
    queue(){
        front=-1;
        rear=-1;
    };
    
    void enqueue(int val){
        if(rear >= size-1){
            cout<<"Queue may be full\n";
        }
        front=0;
        arr[++rear]=val;
        cout<<"Enqueued: "<<val<<endl;
    }
    
    int dequeue(){
        if(front==-1 || front>rear){
            cout<<"Queue is empty"<<endl;
            return -100;
        }
        cout<<"dequeued: "<<arr[front++]<<endl;
        return 0;
    }
    
    void display(){
        int i=front;
        if(front!= -1 || front<=rear){
            cout<<"Current Queue is: ";
            while(i<=rear){
                cout<<arr[i++]<<" ";
            }
        }
    }
};
int main()
{
   queue bro;

    int n;
    cout<<"Enter the no of integers to be inserted in queue: ";
    cin>>n;

    cout<<"\nEnter the integers to be inserted: ";
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        bro.enqueue(arr[i]);
    }
    // for(int i=0)

   cout<<"\nYou are allowed to perform any operation in total 5 times -_-\n";
    cout<<"Available options:\n";
    cout<<"1. Insert an element to queue\n";
    cout<<"2. Remove an element from queue\n";
    cout<<"3. Display all elements of queue\n\n";

    cout<<"To avail first option enter '1'\n";
    cout<<"To avail second option enter '2'\n";
    cout<<"To avail third option enter '3'\n";

    
    int count = 0;
    while(count != 5){
        cout<<"\n\nEnter the number of your choice of operation: ";
        int opt;
        cin>>opt;
        switch (opt){
            case 1:
            cout<<"Enter the element to be inserted: ";
            int ins;
            cin>>ins;
            bro.enqueue(ins);
            break;

            case 2:
            bro.dequeue();
            break;

            case 3:
            bro.display();
            break;

            default:
            cout<<"Enter a valid option"<<endl;
            break;
        }
        count++;
    }
    cout<<"\nFinal stack looks like: ";
    bro.display();
}


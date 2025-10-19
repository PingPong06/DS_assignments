#include <bits/stdc++.h>
using namespace std;

class mydeque{
    vector <int> arr;
    int front,rear;
    int size;
public:
    mydeque(int size){
        this->size=size;
        arr.resize(size);
        front=-1;
        rear=-1;
    };
    
    void push_back(int val){
         if(front == -1 && rear == -1){
            front=0, rear=0;
        }

        if(rear == size-1){
            cout<<"Deque is full\n";
            return;
        }
        rear++;
        arr.push_back(val);
        cout<<"Enqueued: "<<val<<endl;
    }
    
   void push_front(int val) {
        if ((front == 0 && rear == size - 1) || (rear + 1 == front)) {
            cout << "Deque is full\n";
            return;
        }

        if (front == -1) { 
            front = rear = 0;
        } 
        else if (front == 0) {
            front = size - 1;
        } 
        else {
            front--;
        }
        arr[front] = val;
        cout << "Enqueued at front: " << val << endl;
    }

    void pop_front(){
        if(front == -1 && rear == -1){
            cout<<"Deque is already empty\n";
            return;
        }
         if(front == rear){
            cout<<"dequeued: "<<arr[rear]<<endl;
            front=rear=-1;
            return;
        }
        cout<<"dequeued: "<<arr[front++]<<endl;
        return ;
    }

     void pop_back(){
        if((front == -1 && rear == -1)){
            cout<<"Deque is already empty\n";
            return;
        }
        // if(front > rear){
        //     cout<<"Deque is already empty\n"<<endl;
        //     return ;
        // }
        if(front == rear){
            cout<<"dequeued: "<<arr[rear]<<endl;
            front=rear=-1;
            return;
        }
        cout<<"dequeued: "<<arr[rear--]<<endl;
        return ;
    }
    
    void display(){
        int i=front;
        if(front<=rear) cout<<"Current Queue is: ";
        while(i<=rear){
            cout<<arr[i++]<<" ";
        }
    }
};
int main()
{
    int size, n;
    cout<<"Enter the size of deque: ";
    cin>>size;
   mydeque obj(size);
   cout<<"Enter the no. of values to be enqueued: ";
   cin>>n;

   int count=1;
   while(count < n+1){
    cout<<"Input "<<count<<" :";
    int takeInput;
    cin>>takeInput;
    obj.push_front(takeInput);
    cout<<endl;
    count++;
   }

   cout<<"Any five operations will be considered: \n";
   cout<<"TO Enqueue from front: press 1"<<endl;
   cout<<"TO Enqueue from back: press 2"<<endl;
   cout<<"TO dequeue from front: press 3"<<endl;
   cout<<"TO dequeue from back: press 4"<<endl;
    int j=1;
   cout<<endl;
    while(j<5){
        int num;
        cout<<"Enter Operation number: ";
        cin>>num;
    switch (num) {
        case 1: 
            int val_1;
            cout<<"Enter the value: ";
            cin>>val_1;
            obj.push_front(val_1);
            break;
        case 2: 
            int val_2;
            cout<<"Enter the value: ";
            cin>>val_2;
            obj.push_back(val_2);
            break;
        case 3:
            obj.pop_front();
            break;
        case 4: 
            obj.pop_back();
            break;
        default: cout<<"Invalid Operation\n";
            break;
        }
        j++;
   }
   obj.display();

    return 0;
}

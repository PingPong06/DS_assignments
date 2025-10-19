#include <iostream>
#include<queue>
using namespace std;

class Myqueue{
    int front, rear;
    int *arr;
    int size;
public: 
    Myqueue(int size){
        this->size=size;
        arr= new int[size];
        front=-1;
        rear=-1;
    };
    void enqueue(int data){
        if((rear+1) % size == front){
            cout<<"Queue is full"<<endl;
        }
        else{
            if(front == -1 && rear == -1){
                front=0,rear=0;
            }
            else{
                if(rear == size-1) rear=0;
                else rear=(rear+1)%size;
            }
            arr[rear]=data;
            cout<<"Enqueued: "<<data<<endl;
        }
    }

    void dequeue(){
        if(front == -1 && rear == -1 ){
           cout<<"Queue is already empty"<<endl;
        }
        else{
            cout<<"Element pop is: "<<arr[front]<<endl;
            arr[front] = -1; // here -1 indicates that the element has been dequeued
            if(front % size ==rear) front=-1,rear=-1;
            else front++;
        }
    }

    void display(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    int size;
    cout<<"Enter the size of queue: ";
    cin>>size;
    Myqueue obj(size);
    // int n;
    // cout<<"Enter the number of elements to be enqueued: ";
    // cin>>n;
    cout<<"Enter the elements to be enqueued: ";
    for(int i=0;i<size;i++){
        int takeInput;
        cin>>takeInput;
        obj.enqueue(takeInput);
    }
obj.dequeue();
obj.dequeue();
obj.enqueue(36);

obj.display();

    return 0;
}
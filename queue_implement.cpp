#include <iostream>
using namespace std;

class Queue {
    public:
        int *arr;
        int size;
        int front;
        int rear;

    Queue(int size){
        arr = new int[size];
         this -> size = size;
         front = -1;
         rear = -1;
    }

    void push( int data)
    {
        if(rear == size -1){
            cout<<" Overflow condition"<< endl;
            return;
        }

        else if( front == -1 && rear == -1){
            front++;
            rear++;
            arr[rear] = data;    
        }

        else{
            rear++;
            arr[rear] = data; 
        }
    }

    void pop()
    {
        if( front == -1 && rear == -1){
            cout<<"Underflow condtion" <<endl;
            return;
        }

        else if( front == rear){
            arr[rear] = -1;
            front = -1;
            rear = -1;
        }

        else{
            arr[front] = -1;
            front++;
        }
    }

    bool isEmpty(){
        if( front == -1 && rear == -1){
            return true;
        }
        else{
            return false; 
        }
    }

    int getFront()
    {
        if( front == -1){
            cout << "No element in queue" << endl;
            return -1;
        }

        else{
            return arr[front];  
        }
    }

    void print(){
        for(int i = front; i<size ; i++){
            cout<< arr[i] <<" ";
        }
        cout<< endl;
    }
};

int main() 
{
    Queue q(5);

    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);  

   q.print();

   q.pop(); 

   q.print();

   cout<< " Queue is empty or not " << q.isEmpty();



    // queue <int> q;

    // q.push(10);

    // cout << "size of queue " << q.size() << endl;

    // if( q.empty() == true){
    //     cout << "queue is empty " << endl;
    // }else{
    //     cout<< "queue is not empty "<< q.size() << endl;
    // }

    // q.pop();

    // if( q.empty() == true){
    //     cout << "queue is empty " << endl;
    // }else{
    //     cout<< "queue is not empty "<< q.size() << endl;
    // }
    return 0;
}
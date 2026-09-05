#include<iostream>
using namespace std;

class Stack{
    public:

    int *arr;
    int size;
    int top;

    Stack(int size){
        arr = new int[size];
        this -> size = size;
        this -> top = -1;
    }

    void push( int data){
        if( top == size-1){
            cout<<"Stack overflow"<<endl;
        }
        else{
            top++;
            arr[top] = data;
        }
    }

    void pop( ){
        if(top == -1){
            cout<<"Stack underflow"<<endl;
        }
        else{
            top--;
        }
    }

    void print(){
        for( int i=0; i<size ; i++){
            cout<<arr[i]<<endl;
        }
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }

    void getTop(){
        if( top == -1){
            cout<<"stack is empty"<<endl;
        }
        else{
            cout<< arr[top];
        }
    }


};

int main(){

    Stack st(5);

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(20);
    st.push(30);

    st.pop();
    st.pop();

    st.getTop();
    st.print();

    if(st.isEmpty()){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Not empty"<<endl;
    }

    st.getTop();
}
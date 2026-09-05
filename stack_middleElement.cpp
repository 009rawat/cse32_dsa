#include<iostream>
#include<stack>
using namespace std;

void solve( stack<int> &st, int &pos , int &ans){
    if( pos == 1){
        ans = st.top();
        return ;
    }
    
    pos--;
    int temp = st.top();                            //store value to push after get mid
    st.pop();

    solve( st, pos, ans);                           //recusrion 

    st.push(temp);                                  //backtrack
}

int getMiddle( stack<int> &st){
    int size = st.size();
    int pos = 0;

    if(st.empty()){     
        cout<< "Stack is empty"<< endl;             //empty
        return -1;
    }
    else{

        // for odd
        if( size & 1){
            pos = size/2 + 1;                       //non emnpty
        }

        //even
        else{
            pos = size/2;
        }
    }

    int ans = -1;
    solve(st, pos , ans);
    return ans;
}

int main(){

    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    int mid = getMiddle(st);
    cout << "Middle element "<< mid ;
}
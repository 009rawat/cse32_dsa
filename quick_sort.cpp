#include<iostream>
using namespace std ;

int partition ( int a[],int l, int r){

    int p = a[r] ;
    int i = l-1;
    for ( int j = l ; j<= r-1; j++){
        if( p > a[j]){
            i++;
            swap (a[i], a[j]);
        }
    }

    swap(a[i+1], a[r]);
    return i+1;
}

void quick_sort(int a[], int l , int r){
    int p ;

    if( l< r){

       int p = partition ( a, l , r);
        quick_sort(a, l , p-1);
        quick_sort(a, p+1 , r);
    }

    
}

int main (){

    int a[] = {7,2,5,1,9,3};
    int n = sizeof(a)/ sizeof(a[0]);
    quick_sort( a, 0, n-1);
    for ( int i = 0; i<n ; i++){
        cout<<a[i];
    }

}
/*
Author:Pranav Kulkarni
Title:Write a C++ program to sort N names in alphabetical order.
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void display(string name[],int n){
    for(int i=0;i<n;i++){
        cout<<name[i]<<"\n";
    }
}

void selectionSort(string name[],int n){ 
    string temp;
    //int i,j;
    /*logic for bubble sort*/
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(name[i]>name[j]){
                temp=name[i];
                name[i]=name[j];
                name[j]=temp;
               
            }
        }
    }
    
   cout<<"\nSorted Student Data:\n";
   display(name,n);
}
int main()
{
    
    int n;
    
    cout<<"\nHow Many Students Names do you want to sort :";
    cin>>n;
    string name[n];
    
    for(int i=0;i<n;i++){
        cout<<"\nEnter student Name "<<(i+1)<< " :";
        cin>>name[i];
    }
    
   cout<<"\nUnsorted Data:\n";
   display(name,n);
    
   selectionSort(name,n);
    
    

    return 0;
}

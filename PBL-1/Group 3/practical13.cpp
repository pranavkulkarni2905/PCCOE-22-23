/*
Author:Pranav Kulkarni
Title:Write a C++ program to print all the repeated numbers with their frequency in an array in minimum time 
complexity
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int i,j,n,count;
    
    //cout<<"Enter no. of elements:";
    cin>>n;
   
    int set[n];
    //cout<<"\nEnter the elements:";
    for(i=0; i<n; i++)
    {
       cin>>set[i];
    }
    
    
    int flag[n]={0};          
   // cout<<"\nRepeated Numbers with their frequency:";
    for(i=0; i<n; i++)
    {
      count=0;
      if(flag[i]!=1)       // if element set[i] is not considered for counting the frequency of a repeated number
      {
         for(j=0; j<n; j++)
         {
            if(set[i]==set[j])
            {
              count++;        
              flag[j]=1;     // set flag[j] to 1, to avoid more than 1 entry of repeated number in the output
            }
         }
         if(count>=1)      
         {
           cout<<set[i]<<" "<<count<<" ";
         }
      }
    }
    return 0;
}


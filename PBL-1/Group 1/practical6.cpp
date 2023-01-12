/*
Author:Pranav Kulkarni (SYCOA288)
Title:Implement matrix class as ADT. Write a program to perform matrix addition, subtraction, and 
multiplication. In read matrix function, raise an exception if any attempt is made to have rows and columns 
beyond the array size. Raise an exception if any attempt is made to perform matrix operations on matrices 
which does not satisfy the matrix order criteria. Implement using C++
*/
#include<iostream>
using namespace std;
class Matrix{
    int rows, columns, a[5][5];
    public:
    void read(){
        cout<<"\nEnter the number of rows and columns: ";
        cin>>rows>>columns;
        try{
            if(rows>5||columns>5){
                throw 1;
            }
            else{
            for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                cout<<"\nEnter the element "<<i+1<<" "<<j+1<<" of the matrix: ";
                cin>>a[i][j];
            }
        }}
        }
        catch(int e){
            cout<<"\nException caught: The number of rows and columns should not be greater than 5";
            exit(0);
        }
    }
    void display(){
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    Matrix operator +(Matrix &m2){
        Matrix m3;
        m3.rows=rows;
        m3.columns=columns;
        try{
            if(rows!=m2.rows||columns!=m2.columns){
                throw 2;
            }
            else{
            for(int i=0;i<rows;i++){
                for(int j=0;j<columns;j++){
                    m3.a[i][j]=a[i][j]+m2.a[i][j];
                }
            }}
        }
        catch(int i){
            cout<<"\nException caught: The number of rows and columns should be equal for addition";
            exit(0);
        }

        return m3;
    }
    Matrix operator *(Matrix &m2){
        Matrix m4;
        m4.rows=rows;
        m4.columns=columns;
        try{
            if(columns!=m2.rows){
            throw 3;}
            for(int i=0; i<rows; i++){
                for(int j=0; j<m2.columns; j++){
                    m4.a[i][j]=0;
                    for(int k=0;k<m2.columns; k++){
                        m4.a[i][j]+=a[i][k]*m2.a[k][i];
                    }
                }
            }
        }
        catch(int y){
            cout<<"\nException caught: The number of columns of the first matrix should be equal to the number of rows of the second matrix";
            exit(0);
        }
        return m4;
    }
}; 

int main(){
    Matrix m1,m2,m3,m4;
    m1.read();
    cout<<"\nMatrix 1:"<<endl;
    m1.display();
    m2.read();
    cout<<"\nMatrix 2:"<<endl;
    m2.display();
    m3=m1+m2;
    cout<<"\nAddition of the two matrices is:"<<endl;
    m3.display();
    m4=m1*m2;
    cout<<"\nMultiplication of the two matrices is:"<<endl;
    m4.display();
    return 0;
}

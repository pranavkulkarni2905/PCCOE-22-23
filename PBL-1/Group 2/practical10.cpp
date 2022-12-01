#include<iostream>
#include<string>
using namespace std;

class Set{
	int no;
	string name[20];
	
	public:
		void accept();
		void display();
		void union1(Set b);
};

void Set::accept(){
	int i=0;
	cout<<"\nEnter number of customers:";
	cin>>no;
	for(i=0;i<no;i++){
		cout<<"\nEnter customer "<<i+1<<" Data :";
		cout<<"\nEnter customer name :";
		cin>>name[i];
	}
}

void Set::display(){
	for(int i=0;i<no;i++){
		cout<<name[i]<<"\t";
	}
	cout<<"\n";
}

void Set::union1(Set b){
	int len1=(sizeof(name)/sizeof(name[0]));
	int len2=(sizeof(b.name)/sizeof(b.name[0]));
	string temp[20];
	for(int i=0;i<len1;i++){
		temp[i]=name[i];
		cout<<"Added "<<temp[i]<<"\n";
	}
	
	cout<<"hiiii";
	for(int j=0;j<len2;j++){
		cout<<"inside 2nd for looop";
		for(int k=0;k<len1+len2;k++){
			int b1=len1;
			if(temp[k]!=b.name[j]){
				temp[b1]=b.name[j];
				cout<<temp[b1];
				b1++;
				}else{
					break;
				}
			
			}
				
		}
		cout<<"\n--------------";
		for(int i=0;i<len1+len2;i++)
		{
			cout<<"hello\n";
			cout<<temp[i];
		}
	
}
int main(){
	
	Set setu,seta,setb;
	
	cout<<"\nEnter elements in Set A ( who likes Pizza):";
	seta.accept();
	
	cout<<"\nEnter elements in Set B (who likes Burger):";
	setb.accept();
	
	cout<<"\nEnter elements in Set U (who likes Both or doesn't like any):";
	setu.accept();
	
	seta.union1(setb);
	
}

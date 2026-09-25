#include<iostream>
using namespace std;

int main()
{
	int x, start, stop;
	int sum=0;
	 cout<<"Enter X:";
	 cin>>x;
	 
	 cout<<"Enter starting value:";
	 cin>>start;
	 
	 cout<<"Enter stopping value:";
	 cin>>stop;
	 
	 for(int i=start;i<=stop;i++)
	 {
	 	sum= sum+x*x;
	 }
	 
	 cout<<"Sum="<<sum;
	 return 0;
}

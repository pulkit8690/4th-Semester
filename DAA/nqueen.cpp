#include<iostream>
#include<cstdlib>
using namespace std;
void NQueen(int,int);
bool place(int,int);
int x[10];
int count=0;
void NQueen(int k,int n)
{
	for(int i=1;i<=n;i++)
	{
		if(place(k,i))
		{
			x[k]=i;
			if(k==n)
			{
				count++;
				cout<<endl;
				for(int j=1;j<=n;j++)
				{
					cout<<x[j]<<"\t";
				}
			}
			else
			{
				NQueen(k+1,n);
			}
		}
	}
	
}
bool place(int k,int i)
{
	for(int j=1;j<=k-1;j++)
	{
		if((x[j]==i)||(abs(x[j]-i)==abs(j-k)))
		{
			return false;
		}
	}
	return true;
}
int main()
{ int n;
	cout<<"enter the number of queen"<<endl;
	cin>>n;
	int k=1;
	NQueen(k,n);
	cout<<endl<<"count=\t"<<count;
	return 0;
}
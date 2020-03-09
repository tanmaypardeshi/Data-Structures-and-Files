#include<bits/stdc++.h>
using namespace std;


int main()
{
	int t,n,m,i,j,no;
	int **a,*sum;
	
	cin>>t;
	while(t>0)
	{
		cin>>n>>m;		
		a = new int*[2];
		sum = new int[m+1];
		for(i=0;i<2;i++)
			a[i]= new int[n];
			
		for(i=0;i<n;i++)
			cin>>a[0][i];
		for(i=0;i<n;i++)
			cin>>a[1][i];
		for(i=0;i<n;i++)
		{
			no = a[0][i]%m-1;
			sum[no] = sum[no] + a[1][i];
		}
		for(j=1;j<=m;j++)
		{
			cout<<"\nValue of m:- "<<j<<endl;
			cout<<sum[j]<<" ";
			cout<<endl;
		}
		t--;
	}
	return 0;
}

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
		for(i=0;i<2;i++)
			a[i]= new int[n];
		sum = new int[m];
		cout<<m<<endl;
				
		for(i=0;i<n;i++)
			cin>>a[0][i];
		for(i=0;i<n;i++)
			cin>>a[1][i];
		for(i=0;i<n;i++)
		{
			no = (a[0][i]%m);
			sum[no] = sum[no] + a[1][i];
		}
		int mini=sum[0];
		for(j=0;j<m;j++)
		{
			if(mini<sum[j] && sum[j]!=0)
				mini = sum[j];
		}
		cout<<mini;
		t--;
	}
	return 0;
}

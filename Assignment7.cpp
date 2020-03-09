#include<iostream>
#include<string.h>

using namespace std;

class graph
{
	int n;
	char vname[10][10];
	int arr[10][10];
	int visit[10];

	public:
		graph();
		void create();
		void display();
		int position(char s[10]);
		void kruskal();
};

graph::graph()
{
	n = 0;
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
		{
			vname[i][j]=NULL;
			arr[i][j]=999;
			visit[i]=0;
		}
}

int graph::position(char s[10])
{
	for(int i=0;i<n;i++)
		if(strcmp(vname[i],s)==0)
				return i;
	return -1;
}

void graph::create()
{
	char vertex1[10],vertex2[10];
	int weight;
	char ans;
	cout<<"Enter total vertex:";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter Vertex name:";
		cin>>vname[i];
	}
	cout<<"Time to add weight";
	do
	{
		cout<<"\nEnter Vertex1: ";
		cin>>vertex1;
		cout<<"Enter Vertex2: ";
		cin>>vertex2;

		int i=position(vertex1);
		int j=position(vertex2);

		if(i!=-1&&j!=-1)
		{
			cout<<"Enter Weight between "<<vertex1<<" & "<<vertex2<<": ";
			cin>>weight;
			arr[i][j]=arr[j][i]=weight;
		}
		else
			cout<<"Vertex is not present";
		cout<<"\nDo you want to add more weight (Y/N):";
		cin>>ans;
	}while(ans=='y'||ans=='Y');
}

void graph::display()
{
	for(int i=0;i<n;i++)
	{
		cout<<"\n";
		for(int j=0;j<n;j++)
			cout<<"  "<<arr[i][j];
	}
}

void graph::kruskal()
{
	int x,y,i,j,a,count,min,sum;
	char start[10];
	i=0;
	j=0;
	sum=0;
	int flag=0;
	int grp=1;

	cout<<"\nEdge\tEdge\tWeight";
	while(flag==0)
	{
		min=arr[i][j];
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(arr[i][j]<min)
				{
					x=i;
					y=j;
					min=arr[i][j];
				}
		if(visit[x]==0 && visit[y]==0)
		{
			visit[x]=visit[y]=grp;
			grp++;
			sum=sum+arr[x][y];
			arr[x][y]=999;
			arr[y][x]=999;
			cout<<"\n"<<vname[x]<<"\t"<<vname[y]<<"\t"<<min;
		}
		else if(visit[x]!=0 && visit[y]==0)
		{
			visit[y]=visit[x];
			sum=sum+arr[x][y];
			arr[x][y]=999;
			arr[y][x]=999;
			cout<<"\n"<<vname[x]<<"\t"<<vname[y]<<"\t"<<min;
		}
		else if(visit[x]==0 && visit[y]!=0)
		{
			visit[x]=visit[y];
			sum=sum+arr[x][y];
			arr[x][y]=999;
			arr[y][x]=999;
			cout<<"\n"<<vname[x]<<"\t"<<vname[y]<<"\t"<<min;
		}
		else if(visit[x]!=visit[y])
		{
			int temp=visit[y];
			sum=sum+arr[x][y];
			arr[x][y]=999;
			arr[y][x]=999;
			cout<<"\n"<<vname[x]<<"\t"<<vname[y]<<"\t"<<min;
			for(int k=0;k<n;k++)
			{
				if(visit[k]==temp)
					visit[k]=visit[x];
			}
		}

		int d=visit[0];
		flag=1;
		for(int l=0;l<n;l++)
		{
			if(visit[l]!=d)
			{
				flag=0;
				break;
			}
			else
				continue;
		}
	}
	cout<<"\nTotal weight of kruskal graph is: "<<sum;
}

int main()
{
	graph g1;
	g1.create();
	g1.display();
	g1.kruskal();
}

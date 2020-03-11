#include<iostream>
#include<iomanip>
#include<string.h>

using namespace std;

class Graph
{
	int n;
	char vname[10][10];
	int arr[10][10];
	int visit[10];

	public:
		Graph();
		void create();
		void display();
		int position(char s[10]);
		void kruskal();
};

Graph::Graph()
{
	n = 0;
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++)
		{
			vname[i][j]='\0';
			arr[i][j]=999;
			visit[i]=0;
		}
}

void Graph::create()
{
	char vertex1[10],vertex2[10];
	int weight;
	char ans;
	cout<<"Enter total number of vertices:- ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the name of the vertex:- ";
		cin>>vname[i];
	}
	
	do
	{
		cout<<"\nEnter the name of vertex 1:- ";
		cin>>vertex1;
		cout<<"Enter the name of vertex 2:- ";
		cin>>vertex2;

		int i=position(vertex1);
		int j=position(vertex2);

		if(i!=-1&&j!=-1)
		{
			cout<<"Enter weight between "<<vertex1<<" & "<<vertex2<<":- ";
			cin>>weight;
			arr[i][j]=arr[j][i]=weight;
		}
		else
			cout<<"Vertex is not present";
		cout<<"\nDo you want to add more weight(Y/N):- ";
		cin>>ans;
	}while(ans=='y'||ans=='Y');
}

void Graph::display()
{
	for(int i=0;i<n;i++)
	{
		cout<<"\n";
		for(int j=0;j<n;j++)
			cout<<setw(5)<<arr[i][j];
	}
}

int Graph::position(char s[10])
{
	for(int i=0;i<n;i++)
		if(strcmp(vname[i],s)==0)
			return i;
	return -1;
}

void Graph::kruskal()
{
	int x,y,i,j,a,count,min,sum;
	char start[10];
	i=0;
	j=0;
	sum=0;
	int flag=0;
	int grp=1;

	cout<<"\nEdge 1\tEdge 2\tWeight";
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
	cout<<"\nTotal weight of Kruskal Graph is:- "<<sum;
}

int main()
{
	Graph g1;
	g1.create();
	g1.display();
	g1.kruskal();
}

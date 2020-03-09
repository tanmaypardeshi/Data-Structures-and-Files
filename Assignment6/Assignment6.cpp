#include <iostream>
#include <queue>
using namespace std;

struct graphedge
{
	graphedge *nextedge;
	struct graphvertex *destinationvertex;
};

struct graphvertex
{
	string name;
	int date,month,year;
	int comments;
	int friends;
	int visited;
	graphedge *nextedgepointer;
	graphvertex *nextvertexpointer;
};

struct graphhead
{
	int count;
	graphvertex *firstvertex;
};

class graphSocialnetwork
{
	graphhead *g;

public:
	graphSocialnetwork();
	void createGraph();
	int insertVertex();
	int insertEdge();
	void displayGraph();
	void MostFriends();
	void MostComments();
	void MinComments();
	void birthday();
	int DFSmax(graphvertex*,int);
	int DFSmin(graphvertex*,int);
	void BFS(int);
	void clear();
};

graphSocialnetwork::graphSocialnetwork()
{
	g=NULL;
}

void graphSocialnetwork::createGraph()
{
	g=new graphhead;
	g->count=0;
	g->firstvertex=NULL;
	cout<<"\nNEW GRAPH CREATED\n";
}

int graphSocialnetwork::insertVertex()
{
	graphvertex *newptr,*locptr;
	locptr=g->firstvertex;

	newptr=new graphvertex();
	cout<<"ENTER NAME OF THE USER : ";
	cin>>newptr->name;
	cout<<"\nENTER NUMBER OF COMMENTS MADE : ";
	cin>>newptr->comments;
	cout<<"Enter Birthday :\nDate : ";
	cin>>newptr->date;
	cout<<"\nMonth : ";
	cin>>newptr->month;
	cout<<"\nYear ";
	cin>>newptr->year;
	newptr->visited=0;

	newptr->friends=0;
	newptr->nextvertexpointer=NULL;
	newptr->nextedgepointer=NULL;

	if(g->count==0)
	{
		g->firstvertex=newptr;
	}
	else
	{
		while(locptr->nextvertexpointer!=NULL)
		{
			locptr=locptr->nextvertexpointer;
		}
		locptr->nextvertexpointer=newptr;
	}
	g->count++;

	return 1;
}

int graphSocialnetwork::insertEdge()
{
	graphvertex *from, *to;
	graphedge *temp,*temp2;
	string startVertex, endVertex;
	cout<<"ENTER NAMES OF USERS TO MAKE FRIENDS :: \n";
	cout<<"USER 1 : ";
	cin>>startVertex;
	cout<<"\nUSER 2 : ";
	cin>>endVertex;
	from=g->firstvertex;
	to=g->firstvertex;

	while(from != NULL && from->name != startVertex)
	{
		from=from->nextvertexpointer;
	}
	if(from != NULL)
	{

		while(to != NULL && to->name != endVertex)
		{
			to=to->nextvertexpointer;
		}
		if(to != NULL)
		{
			if(from != to)
			{
				temp=from->nextedgepointer;				
				if(temp == NULL)
				{
					temp=new graphedge();
					from->nextedgepointer=temp;
					temp->destinationvertex=to;
					temp->nextedge=NULL;
				}
				else
				{
					while(temp->nextedge != NULL)
					{
						temp=temp->nextedge;
					}
					temp2=new graphedge();
					temp2->destinationvertex=to;
					temp2->nextedge=NULL;
					temp->nextedge=temp2;
				}

				temp=to->nextedgepointer;				
				if(temp == NULL)
				{
					temp=new graphedge();
					to->nextedgepointer=temp;
					temp->destinationvertex=from;
					temp->nextedge=NULL;
				}
				else
				{
					while(temp->nextedge != NULL)
					{
						temp=temp->nextedge;
					}
					temp2=new graphedge();
					temp2->destinationvertex=to;
					temp2->nextedge=NULL;
					temp->nextedge=temp2;
				}
				from->friends+=1;
				to->friends+=1;
			}
			else
			{
				cout<<"Start and end cannot be same";
			}
		}
		else
		{
			cout<<endl<<endVertex<<" DOES NOT EXIST !\n";
		}
	}
	else
	{
		cout<<endl<<startVertex<<" DOES NOT EXIST !\n";
	}
	return 1;
}

void graphSocialnetwork::displayGraph()
{
	graphvertex *vertexPtr;
	graphedge *edgePtr;
	vertexPtr=g->firstvertex;
	while(vertexPtr!=NULL)
	{
		edgePtr=vertexPtr->nextedgepointer;
		cout<<endl<<vertexPtr->name;
		while(edgePtr!=NULL)
		{
			cout<<" -> "<<edgePtr->destinationvertex->name;
			edgePtr=edgePtr->nextedge;
		}
		vertexPtr=vertexPtr->nextvertexpointer;
	}
}

void graphSocialnetwork::MostFriends()
{
	graphvertex *vertex=g->firstvertex;
	int max=0;
	while(vertex!=NULL)
	{
		if(max<vertex->friends)
		{
			max=vertex->friends;
		}
		vertex=vertex->nextvertexpointer;
	}
	vertex=g->firstvertex;
	cout<<"\nTHE MAXIMUM NUMBER OF FRIENDS OF A USER ARE : "<<max;
	cout<<"\nTHE USERS WITH "<<max<<" FRIENDS ARE : \n";
	while(vertex!=NULL)
	{
		if(max==vertex->friends)
		{
			cout<<vertex->name<<endl;
		}
		vertex=vertex->nextvertexpointer;
	}
}

int graphSocialnetwork::DFSmax(graphvertex *v,int max)
{
	graphedge *e;
	v->visited=1;
	if(v->comments > max)
	{
		max = v->comments;
	}
	if(v->nextedgepointer != NULL)
	{
		e=v->nextedgepointer;
		while(e != NULL )
		{
			if(e->destinationvertex->visited==0)
			{
				max=DFSmax(e->destinationvertex,max);
			}
			e=e->nextedge;
		}
	}
	return max;
}
void graphSocialnetwork::MostComments()
{
	graphvertex *vertex=g->firstvertex;
	int max=DFSmax(vertex,0);

	vertex=g->firstvertex;
	cout<<"\nTHE MAXIMUM NUMBER OF COMMENTS OF A USER ARE : "<<max;
	cout<<"\nTHE USERS WITH "<<max<<" COMMENTS ARE : \n";
	while(vertex!=NULL)
	{
		if(max==vertex->comments)
		{
			cout<<vertex->name<<endl;
		}
		vertex=vertex->nextvertexpointer;
	}
	clear();
}

int graphSocialnetwork::DFSmin(graphvertex *v,int min)
{
	graphedge *e;
	v->visited=1;
	if(v->comments < min)
	{
		min = v->comments;
	}
	if(v->nextedgepointer != NULL)
	{
		e=v->nextedgepointer;
		while(e != NULL )
		{
			if(e->destinationvertex->visited==0)
			{
				min=DFSmin(e->destinationvertex,min);
			}
			e=e->nextedge;
		}
	}
	return min;
}
void graphSocialnetwork::MinComments()
{
	graphvertex *vertex=g->firstvertex;
	int min=DFSmin(vertex,1000000);

	vertex=g->firstvertex;
	cout<<"\nTHE MINIMUM NUMBER OF COMMENTS OF A USER ARE : "<<min;
	cout<<"\nTHE USERS WITH "<<min<<" COMMENTS ARE : \n";
	while(vertex!=NULL)
	{
		if(min==vertex->comments)
		{
			cout<<vertex->name<<endl;
		}
		vertex=vertex->nextvertexpointer;
	}
	clear();
}

void graphSocialnetwork::BFS(int mon)
{
	graphvertex *vertex=g->firstvertex;
	graphvertex *temp;
	graphedge *e;
	queue<graphvertex*> q;
	q.push(vertex);
	vertex->visited=1;
	if(vertex->month == mon)
	{
		cout<<vertex->name;
	}
	while(!q.empty())
	{
		temp=q.front();
		q.pop();
		e=temp->nextedgepointer;
		while(e!=NULL)
		{
			if(e->destinationvertex->visited==0)
			{
				q.push(e->destinationvertex);
				e->destinationvertex->visited=1;
				if(e->destinationvertex->month == mon)
				{
					cout<<" , "<<e->destinationvertex->name;
				}
			}
			e=e->nextedge;
		}
	}
	clear();
}
void graphSocialnetwork::birthday()
{
	graphvertex *vertex=g->firstvertex;
	int mon;
	cout<<"ENTER CURRENT MONTH : ";
	cin>>mon;
	cout<<"\nTHE USERS HAVING BIRTHDAY THIS MONTH ARE ::\n";
	BFS(mon);
}

void graphSocialnetwork::clear()
{
	graphvertex *vertex=g->firstvertex;
	while(vertex!=NULL)
	{
		vertex->visited=0;
		vertex=vertex->nextvertexpointer;
	}
}



int main() {
	graphSocialnetwork g1;
	int choice;
	do
	{
		cout<<"\n\n\n\tMENU::\n";
		cout<<"\n\t(1)CREATE A NEW GRAPH";
		cout<<"\n\t(2)ADD A NEW USER";
		cout<<"\n\t(3)ADD A FRIEND";
		cout<<"\n\t(4)DISPLAY FRIENDS NETWORK";
		cout<<"\n\t(5)USER WITH MOST NUMBER OF FRIENDS";
		cout<<"\n\t(6)USER WITH MOST NUMBER OF COMMENTS";
		cout<<"\n\t(7)USER WITH MINIMUM NUMBER OF COMMENTS";
		cout<<"\n\t(8)USERS HAVING BIRTHDAY THIS MONTH";
		cout<<"\n\t(9)EXIT";
		cout<<"\n\n\t\tENTER OUR CHOICE : ";
		cin>>choice;
		switch(choice)
		{
		case 1 :
			g1.createGraph();
			break;

		case 2:
			g1.insertVertex();
			break;

		case 3:
			g1.insertEdge();
			break;

		case 4:
			g1.displayGraph();
			break;

		case 5:
			g1.MostFriends();
			break;

		case 6:
			g1.MostComments();
			break;

		case 7:
			g1.MinComments();
			break;

		case 8:
			g1.birthday();
			break;

		case 9:
			return 0;

		default:
			cout<<"\n\nINVALID CHOICE !!";
			break;
		}

	}while(1);
	return 0;
}


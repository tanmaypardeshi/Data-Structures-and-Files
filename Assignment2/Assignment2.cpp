/* 
Assignment 2
Name:- Tanmay Pardeshi
Roll number:- 23260
Batch:- H10
*/

#include "Queue.cpp"
using namespace std;

struct Patient
{
	int id;
	string name;
	string disease;
	string bloodgroup;
	unsigned long mobile;
	int priority;
};

class Patientdb
{
	Patient P;
	Queue<Patient> q;

	public:
		void add();
		void serve();
		void display();

};

void Patientdb::add()
{
	int length,i;
	
	cout<<"Enter Patient id:- ";
	cin>>P.id;
	
	cout<<"Enter Patient Name:-  ";
	cin>>P.name;
	
	cout<<"Enter bloodgroup:- ";
	cin>>P.bloodgroup;

	cout<<"Enter mobile:- ";
	cin>>P.mobile;

	cout<<"\nSelect by entering one of the diseases:- "<<endl;
	cout<<"1. Cancer"<<endl;
	cout<<"2. Accident"<<endl;
	cout<<"3. Heartattack"<<endl;
	cout<<"4. Kidneystones"<<endl;
	cout<<"5. Typhoid"<<endl;
	cout<<"6. Cholera"<<endl;
	cout<<"7. Dengue"<<endl;
	cout<<"8. Malaria"<<endl;
	cout<<"9. Other"<<endl;
	cout<<"\nType a disease or type other:- ";	
	cin>>P.disease;


	if(P.disease=="Cancer" || P.disease=="Accident" || P.disease=="Heartattack")
	{
		P.priority=3;
	}
	else if(P.disease=="Kidneystones" || P.disease=="Typhoid" || P.disease=="Cholera" || P.disease=="Dengue" || P.disease=="Malaria" )
	{
		P.priority=2;
	}
	else
	{
		P.priority=1;
	}
	q.addq(P);
}

void Patientdb::serve()
{
	q.delq();
}

void Patientdb::display()
{
	q.displayq();
}

int main() 
{
	Patientdb d;
	int choice;

	while(1)
	{
		cout<<"\n\nHosptial management system"<<endl;
		cout<<"1. Add a record for patient"<<endl;
		cout<<"2. Serve a patient"<<endl;
		cout<<"3. Display the patients"<<endl;
		cout<<"4. Exit program"<<endl;
		cout<<"\nEnter your choice:- ";
		cin>>choice;

		switch(choice)
		{
			case 1:
				d.add();
				break;
			case 2:
				d.serve();
				break;
			case 3:
				d.display();
				break;
			case 4:
				return 0;
			default:
				cout<<"Error in choice, try again"<<endl;
		}
	}
	return 0;
}

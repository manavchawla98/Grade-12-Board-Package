#include <iostream>
#include <stdio.h>
#include <fstream>

using namespace std;

//This program functions as a hospital management system.
//It can be used to view, add, delete or modify a patient's record, and also to admit or discharge a patient.

//Global Structure Declaration
struct record             	//record is a structure that will hold the patient details Patient ID, Name, Ward No. and Status.
{
	int PatientID;
	char Name[50];
	int WardNo;
	char Status;          //Status holds either the character 'A' (Admitted) or 'D' (Discharged).
};


//Function prototypes
void View(record Patients[100], int size);
void Add(record Patients[100], int &size);
void Modify(record Patients[100], int size);
void Delete(record Patients[100], int &size);
void Admit(record Patients[100], int size);
void Discharge(record Patients[100], int size);


//Main function
int main()
{
  


  record Patients[100]={
									{7981,"Ashmeet Kaur",101,'D'},
									{8012,"Raniya K.P",107,'A'},
									{1123,"Rachna Mallara",109,'D'},
									{3017,"Anna Mathew",102,'A'},
									{7019,"Aishwarya Suresh",110,'A'},
									{5076,"Amritha JK",103,'D'},
									{5715,"Siona Fernandes",106,'A'},
									{4996,"Arathi Radeesh",114,'D'},
									{9917,"Aksha Sajeev",105,'D'},
									{1112,"Neela Ramesh",104,'A'},
								};
  int size=10;
  int opt;


	do
	{
			cout<<"************************************************************"<<endl;
			cout<<"*	       HOSPITAL MANAGEMENT SYSTEM                  *"<<endl;
			cout<<"************************************************************"<<endl;
			cout<<"*	                  MENU                             *"<<endl;
			cout<<"************************************************************"<<endl;
			cout<<"*	     	                                           *"<<endl;
			cout<<"* Maintenance:                                             *"<<endl;
			cout<<"*                                                          *"<<endl;
			cout<<"*	1 - View record	                                   *"<<endl;
			cout<<"*	2 - Add record	                                   *"<<endl;
			cout<<"*	3 - Modify record		                   *"<<endl;
			cout<<"*	4 - Delete record	          	     	   *"<<endl;
			cout<<"*						    	   *"<<endl;
			cout<<"* Transaction: 					           *"<<endl;
			cout<<"*				      			   *"<<endl;
			cout<<"*	5 - Admit				           *"<<endl;
			cout<<"*	6 - Discharge                                      *"<<endl;
			cout<<"*							   *"<<endl;
			cout<<"*	7 - Exit					   *"<<endl;
			cout<<"************************************************************"<<endl;
			cout<<"*	                BY MANAV CHAWLA                       *"<<endl;
			cout<<"************************************************************"<<endl;

			cout<<endl;

			cout<<"Enter choice(1-7): ";
			cin>>opt;

			cout<<endl;

			switch(opt)
			{
				case 1:View(Patients, size);
						 break;
				case 2:Add(Patients, size);
						 break;
				case 3:Modify(Patients, size);
						 break;
				case 4:Delete(Patients, size);
						 break;
				case 5:Admit(Patients, size);
						 break;
				case 6:Discharge(Patients, size);
						 break;

			}

			cout<<endl;

		}while(opt!=7);

}


void View(record Patients[100], int size)
{
	int i;
	int flag=0;
	int ID;

	cout<<"Enter Patient ID: ";
	cin>>ID;

	for(i=0;i<size;i++)
	  if(ID==Patients[i].PatientID)
	  {
		flag=1;

		cout<<endl<<"RECORD FOUND"<<endl<<endl;
		cout<<"Name    : "<<Patients[i].Name<<endl;
		cout<<"Ward No.:"<<Patients[i].WardNo<<endl;
		cout<<"Status  : "<<Patients[i].Status<<endl;
	  }


	if(flag==0)
	  cout<<endl<<"RECORD NOT FOUND"<<endl;

	cout<<endl<<"Enter any key: ";
	cin.ignore();

}


void Add(record Patients[100], int &size)
{
	cin.ignore();
	size++;

	cout<<"ENTER NEW PATIENT'S DETAILS"<<endl;
	cout<<"Patient ID          : ";
	cin>>Patients[size-1].PatientID;
	cout<<"Patient Name        : ";
	cin.ignore();
	cin.getline(Patients[size-1].Name, 20);
	cout<<"Ward No.            : ";
	cin>>Patients[size-1].WardNo;
	cout<<"Patient Status (A/D): ";
	cin>>Patients[size-1].Status;
	cout<<endl<<"RECORD ADDED"<<endl;

	cout<<endl<<"Enter any key: ";
	cin.ignore();

}


void Modify(record Patients[100], int size)
{
	int i;
	int flag=0;
	int ID;
	char choice;

	cout<<"Enter Patient ID: ";
	cin>>ID;

	for(i=0;i<size;i++)
	{
	 if(ID==Patients[i].PatientID)
	  {
		flag=1;

		cout<<endl<<"RECORD FOUND"<<endl<<endl;
		cout<<"Name:"<<Patients[i].Name<<endl;
		cout<<"Modify patient name?(Y/N): ";
		cin>>choice;

		if(choice=='Y')
		{
		 cout<<"Enter new patient name: ";
		 gets(Patients[i].Name);

		 cout<<endl;
		 cout<<endl<<"RECORD MODIFIED"<<endl<<endl;
		}
		else if (choice=='N')
		  cout<<endl<<"RECORD NOT MODIFIED"<<endl<<endl;

		cout<<"Ward no.: "<<Patients[i].WardNo<<endl;
		cout<<"Modify Ward no.?(Y/N): ";
		cin>>choice;

		if(choice=='Y')
		{
		 cout<<"Enter new ward no.: ";
		 cin>>Patients[i].WardNo;

		 cout<<endl;
		 cout<<"RECORD MODIFIED"<<endl;
		}
		else if (choice=='N')
		  cout<<endl<<"RECORD NOT MODIFIED"<<endl;

	     }
	 }

	if(flag==0)
	 cout<<endl<<"RECORD NOT FOUND"<<endl;

	cout<<endl<<"Enter any key: ";
	 cin.ignore();

}


void Delete(record Patients[100], int &size)
{
	int i, j;
	int flag=0;
	int ID;
	char choice;

	cout<<"Enter Patient ID:";
	cin>>ID;

	for(i=0;i<size;i++)
	{
	 if(ID==Patients[i].PatientID)
	 {
	  flag=1;

	  cout<<endl<<"RECORD FOUND"<<endl<<endl;

	  cout<<"Name    : "<<Patients[i].Name<<endl;
	  cout<<"Ward No.: "<<Patients[i].WardNo<<endl;
	  cout<<"Status  : "<<Patients[i].Status<<endl;

	  cout<<"Are you sure you want to delete this record?(Y/N): ";
	  cin>>choice;

	  if(choice=='Y')
	  {
		for(j=i;j<size-2;j++)
		 Patients[j]=Patients[j+1];

		size--;

		cout<<endl<<"RECORD DELETED"<<endl;
	  }

	  if(choice=='N')
		cout<<endl<<"RECORD NOT DELETED"<<endl;
	 break;
	 }
	}

	if(flag==0)
	 cout<<endl<<"RECORD NOT FOUND"<<endl;

	cout<<endl<<"Enter any key: ";
	 cin.ignore();

}


void Admit(record Patients[100], int size)
{
	int i;
	int ID;
	int flag=0;
	char choice;

	cout<<"Enter Patient ID: ";
	cin>>ID;

	for(i=0;i<size;i++)
	{
	 if(ID==Patients[i].PatientID)
	  {
		flag=1;

		cout<<endl<<"RECORD FOUND"<<endl<<endl;

		cout<<"Name    : "<<Patients[i].Name<<endl;
		cout<<"Ward No.: "<<Patients[i].WardNo<<endl;
		cout<<"Status  : "<<Patients[i].Status<<endl;

		if(Patients[i].Status=='A')
		 cout<<endl<<"ERROR: This patient has already been admitted."<<endl;

		if(Patients[i].Status=='D')
		{
		 cout<<endl<<"Admit?(Y/N): ";
		 cin>>choice;

		 if(choice=='Y')
		 {
		  Patients[i].Status='A';

		  cout<<endl<<"Patient Admitted."<<endl;
		 }
		 else if(choice=='N')
		   cout<<endl<<"Patient Not Admitted."<<endl;

	     }
	  }

	 }

	 if(flag==0)
	  cout<<endl<<"RECORD NOT FOUND"<<endl;

	 cout<<endl<<"Enter any key: ";
	  cin.ignore();

}


void Discharge(record Patients[100], int size)
{
	int i;
	int ID;
	int flag=0;
	char choice;

	cout<<"Enter Patient ID: ";
	cin>>ID;

	for(i=0;i<size;i++)
	{
	 if(ID==Patients[i].PatientID)
	 {
	  flag=1;

	  cout<<endl<<"RECORD FOUND"<<endl<<endl;

	  cout<<"Name    : "<<Patients[i].Name<<endl;
	  cout<<"Ward No.: "<<Patients[i].WardNo<<endl;
	  cout<<"Status  : "<<Patients[i].Status<<endl;

	  if(Patients[i].Status=='D')
		cout<<endl<<"ERROR: This patient has already been discharged."<<endl;

	  if(Patients[i].Status=='A')
	  {
		cout<<endl<<"Discharge?(Y/N): ";
		cin>>choice;

		if(choice=='Y')
		{
		 Patients[i].Status='D';

		 cout<<endl<<"Patient Discharged."<<endl;
		}
		else if(choice=='N')
		  cout<<endl<<"Patient Not Discharged."<<endl;

	     }
	 }

	}

	if(flag==0)
	 cout<<endl<<"RECORD NOT FOUND"<<endl;

	cout<<endl<<"Enter any key: ";
	 cin.ignore();

}

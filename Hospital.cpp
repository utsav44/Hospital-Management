#include <stdio.h>
#include <conio.h> //  getch() 
#include <ctype.h> // toupper(), tolower() 
#include <string.h> // strcmp(), strcpy() , strlen() 
#include <stdlib.h>

// Function declarations 

void Intro();
void Title();
void MainMenu();
void Print_all_records();

void Add_record();
void Search_record();
void Edit_record();
void List_record_of_patients();
void Delete_record();
void Print_outsider_patient_data();
void Maximum_and_Minimum_charge();
void Funds_Return_Data();
void Search_patient_by_Age();
void Search_patient_by_Doctor();
void View_Doctors();

/* List of all the functions
a.Title
b.Intro 
c.Main Menu
d.Print all records

1. Add a new patient record
2. Search Patient Record
3. Edit Patient Record
4. List record of patients
5. Delete Patient Records 
6. Print outsider patient data
7. Maximum and Minimum charge of Treatment
8. Funds Return Data
9. Search patients by Age 
10. Search patients by Doctor
11.View Doctors

*/

struct patient
{ 
	int ServiceType;
	int PatientNumber;
	char FirstName [20];
	char LastName [20];
	int age; 
	char gender; 
	char PhoneNumber [15];
	char ResidentialCity [15];
	char Email [30];
	char Problem [30];
	char Doctor [20];
	 
	
	struct 
		{ 
			char TotalCharge [15]; 
			char TotalDeposited [15]; 
			char TotalReturn [15]; 
		}charges; 
};

struct patient p;

int main()
{
	Intro();
	MainMenu();
	
	return 0;
}

void Title()
{
	printf("\n\n\n\t\t\t\t\t----------------------------\n\t\t\t\t\t HOSPITAL MANAGEMENT SYSTEM\n\t\t\t\t\t----------------------------");
}

void Intro()
{
	Title();
	printf("\n\n\n\t\t\tName: Gore Om Bharat\n\t\t\tEnrollment Number: BT20CSE042\n\t\t\tBatch Number: 2\n\t\t\tSubject: DSPD\n\n\n");
	printf("\t\t\tPress enter to continue....");
	getch();
	system("cls"); 
}

void MainMenu()
{	
	Title();
	printf("\n\n\t1. Add a new patient record\n\t2. Search Patient Record\n\t3. Edit Patient Record\n\t4. List record of patients\n\t5. Delete Patient Records \n\t6. Print outsider patient data\n\t7. Maximum and Minimum charge of Treatment\n\t8. Funds Return Data\n\t9. Search patients by Age \n\t10. Search patients by Doctor\n\t11.View Doctors\n\t12.Print all records\n\t13.Exit");
	
	int num;
	
	printf("\n\n\tEnter a number 1 to 13 for above commands: ");
	scanf("%d",&num);
		
	if(num==1)
	{
		Add_record();
	}
	else if(num==2)
	{
		Search_record();
	}
	else if(num==3)
	{
		Edit_record();
	}
	else if(num==4)
	{
		List_record_of_patients();
	}
	else if(num==5)
	{
		Delete_record();
	}
	else if(num==6)
	{
		Print_outsider_patient_data();
	}
	else if(num==7)
	{
		Maximum_and_Minimum_charge();
		
	}
	else if(num==8)
	{
		Funds_Return_Data();
	}
	else if(num==9)
	{
		Search_patient_by_Age();
	}
	else if(num==10)
	{
		Search_patient_by_Doctor();
	}
	else if(num==11)
	{
		View_Doctors();
	}
	else if(num==12)
	{
		Print_all_records();
	}
		
}

void Print_all_records()
{
	
	system("cls");
	Title();
	
	FILE*ptr;
	ptr=fopen("Records.txt","r");
	
	printf("\n\n# Printing All Patient Record\n\n");
			
	printf("\n=======================================================================================================================\n");
				
	while(fread(&p, sizeof(struct patient), 1, ptr) >0)
	{
		printf("\nService Type: %d \nPatient Number: %d \nFirst Name: %s \nLast Name: %s \nAge: %d \nGender: %c \nPhone Number: %s \nResidential City: %s \nEmail : %s \nProblem: %s \nDoctor: %s \nTotal Charge: %s \nTotal Deposited: %s \nTotal Return: %s",p.ServiceType,p.PatientNumber,p.FirstName,p.LastName,p.age,p.gender,p.PhoneNumber,p.ResidentialCity,p.Email,p.Problem,p.Doctor,p.charges.TotalCharge,p.charges.TotalDeposited,p.charges.TotalReturn);
		printf("\n=======================================================================================================================\n");
		
	}
	
	fclose (ptr);
	
	printf("\n\nPress Enter to continue ...");
	getch();
	system("cls");
	
	MainMenu();
}

void Add_record()
 {
	system("cls");
	Title();
	
	FILE*ptr;
	ptr=fopen("Records.txt","a+");
	
	printf("\n\n\t# Add a new patient record\n\n");
	
	printf("\tService Type (0/1) :");
	scanf(" %d",&p.ServiceType);
	
	printf("\tPatient Number : ");
	scanf(" %d",&p.PatientNumber);
	
	int valid;
	do
	{
		valid=1;
		printf("\tFirst Name: ");
		fflush(stdin);
		scanf("%s",p.FirstName);
		
		for(int k=0; k< strlen(p.FirstName) && valid==1 ; k++)
		{
			if(!isalpha(p.FirstName[k]))
			{
				valid=0;
				printf("\nEntered input is incorrect, please enter proper input.....\n\n");
			}
		}
		
	}
	while(valid==0);
	
	
	do
	{
		valid=1;
		printf("\tLast Name : ");
		fflush(stdin);
		scanf("%s",p.LastName);
		
		for(int k=0; k< strlen(p.LastName) && valid==1 ; k++)
		{
			if(!isalpha(p.LastName[k]))
			{
				valid=0;
				printf("\nEntered input is incorrect, please enter proper input.....\n\n");
			}
		}
		
	}
	while(valid==0);
	
	printf("\tAge : ");
	scanf("%d",&p.age);
	
	do
	{
		
		printf("\tGender (M/F) : ");
		fflush(stdin);
		scanf(" %c",&p.gender);
		
		if(toupper(p.gender)=='M'|| toupper(p.gender)=='F')
		{
			valid=1;
			p.gender=toupper(p.gender);
		}
		else
		{
			valid=0;
			printf("\nEntered input is incorrect, please enter proper input.....\n\n");
		}
	
	}
	while(valid==0);
	
	printf("\tPhone number: ");
	fflush(stdin);
	scanf("%s",p.PhoneNumber);
	
	do
	{
		valid=1;
		printf("\tResidential City: ");
		fflush(stdin);
		scanf("%s",p.ResidentialCity);
		
		for(int k=0; k< strlen(p.ResidentialCity) && valid==1 ; k++)
		{
			if(!isalpha(p.ResidentialCity[k]))
			{
				valid=0;
				printf("\nEntered input is incorrect, please enter proper input.....\n\n");
			}
		}
	}
	while(valid==0);
	
	printf("\tEmail address: ");
	fflush(stdin);
	scanf("%s",p.Email);
	
	
	printf("\tProblem : ");
	fflush(stdin);
	scanf("%[^\n]s",p.Problem);
	
	do
	{
		valid=1;
		printf("\tDoctor : ");
		fflush(stdin);
		scanf("%s",p.Doctor);
		
		for(int k=0; k< strlen(p.Doctor) && valid==1 ; k++)
		{
			if(!isalpha(p.Doctor[k]))
			{
				valid=0;
				printf("\nEntered input is incorrect, please enter proper input.....\n\n");
			}
		}
		
	}
	while(valid==0);
	
	printf("\tTotal charge: ");
	fflush(stdin);
	scanf("%s",p.charges.TotalCharge);
	
	printf("\tTotal deposited: ");
	fflush(stdin);
	scanf("%s",p.charges.TotalDeposited);
	
	int number=atoi(p.charges.TotalDeposited)-atoi(p.charges.TotalCharge);
	itoa(number,p.charges.TotalReturn,10);
	
	int stop=0;
	struct patient p1;
	
	while(stop==0 && fread(&p1,sizeof(p1),1,ptr)>0 )
	{
		if(p.ServiceType==1)
		{
			if(p1.ServiceType==1)
			{
				stop=1;	
			}
		}
		else
		{
			stop=1;
		}
	}
	
	long int n;
	n=ftell(ptr);
	fseek(ptr,0,n-sizeof(p));
	
	stop=0;
	
	while(stop==0 && fread(&p1,sizeof(p1),1,ptr)>0)
	{
		if(p.PatientNumber<=p1.PatientNumber || p.ServiceType!=p1.ServiceType)
		{
			stop=1;
		}
	}

	n=ftell(ptr);
	fseek(ptr,0,n-sizeof(p));
	
	fwrite(&p,sizeof(p),1,ptr);
	printf("\n\n\nInformation is recorded successfully ... ");
	fclose(ptr);
	
	printf("\n\nPress Enter to continue ...");
	getch();
	system("cls");
	
	MainMenu();
	
}

void Search_record()
{
	system("cls");
	Title();
	
	FILE*ptr;
	ptr=fopen("Records.txt","r");
	
	printf("\n\n# Search Patient Record\n\n");
	
	int choice;
	char first_name[20],last_name[20],phone_number[10];
	
	do
	{
		printf("1. Search by patient name\n2. Search by patient phone number");
		printf("\n\nEnter your choice from above options: ");
		scanf("%d",&choice);
		
		if(choice==1)
		{
			printf("\nEnter first name of patient: ");
			scanf("%s",first_name);
			
			printf("Enter last name of patient: ");
			scanf("%s",last_name);
			
		}
		else if(choice ==2)
		{
			printf("\nEnter phone number of patient: ");
			scanf("%s",phone_number);
		}
	
	}
	while(choice<1 || choice >2);
	
	
	int flag=0;
	while(fread(&p, sizeof(struct patient), 1, ptr) >0)
	{
		if(!strcmp(p.FirstName,first_name) && !strcmp(p.LastName,last_name) || !strcmp(p.PhoneNumber,phone_number) )
		{
			printf("\nService Type: %d \nPatient Number: %d \nFirst Name: %s \nLast Name: %s \nAge: %d \nGender: %c \nPhone Number: %s \nResidential City: %s \nEmail : %s \nProblem: %s \nDoctor: %s \nTotal Charge: %s \nTotal Deposited: %s \nTotal Return: %s",p.ServiceType,p.PatientNumber,p.FirstName,p.LastName,p.age,p.gender,p.PhoneNumber,p.ResidentialCity,p.Email,p.Problem,p.Doctor,p.charges.TotalCharge,p.charges.TotalDeposited,p.charges.TotalReturn);
			flag=1;
		}

	}
	
	if(flag==0)
	{
		printf("No record found ...");
	}
	
	fclose (ptr);
	
	printf("\n\nPress Enter to continue ...");
	getch();
	system("cls");
	
	MainMenu();
	
}
 
void Edit_record()
{
	system("cls");
	Title();
	
	FILE*ptr;
	FILE*ptr1;
	ptr=fopen("Records.txt","r");
	ptr1=fopen("temp.txt","w");
	
	
	printf("\n\n# Edit Patient Record\n\n");
	
	int choice;
	char first_name[20],last_name[20],phone_number[10];
	
	do
	{
		printf("1. Search by patient name\n2. Search by patient phone number");
		printf("\n\nEnter your choice from above options: ");
		scanf("%d",&choice);
		
		if(choice==1)
		{
			printf("\nEnter first name of patient: ");
			scanf("%s",first_name);
			
			printf("Enter last name of patient: ");
			scanf("%s",last_name);
			
		}
		else if(choice ==2)
		{
			printf("\nEnter phone number of patient: ");
			scanf("%s",phone_number);
		}
	
	}
	while(choice<1 || choice >2);
	
	
	int flag=0;
	while(fread(&p, sizeof(struct patient), 1, ptr) >0)
	{
		if(!strcmp(p.FirstName,first_name) && !strcmp(p.LastName,last_name) || !strcmp(p.PhoneNumber,phone_number))
		{
			flag=1;
			printf("\nService Type: %d \nPatient Number: %d \nFirst Name: %s \nLast Name: %s \nAge: %d \nGender: %c \nPhone Number: %s \nResidential City: %s \nEmail : %s \nProblem: %s \nDoctor: %s \nTotal Charge: %s \nTotal Deposited: %s \nTotal Return: %s",p.ServiceType,p.PatientNumber,p.FirstName,p.LastName,p.age,p.gender,p.PhoneNumber,p.ResidentialCity,p.Email,p.Problem,p.Doctor,p.charges.TotalCharge,p.charges.TotalDeposited,p.charges.TotalReturn);
			printf("\n=======================================================================================================================\n");
		
			int num,valid;
			
			do
			{
				printf("\n1.Service Type \n2.Patient Number \n3.First Name \n4.Last Name \n5.Age \n6.Gender \n7.Phone Number \n8.Residential City \n9.Email \n10.Problem \n11.Doctor \n12.Total Charge \n13.Total Deposited \n14.Total Return \n15.None \n\nEnter the field number you want to edit: ");
				scanf("%d",&num);
				
				
				if(num==1)
				{
					printf("\tService Type : ");
					scanf(" %d",&p.ServiceType);
				}
				else if(num==2)
				{
					printf("\tPatient Number : ");
					scanf(" %d",&p.PatientNumber);
				}
				
				else if(num==3)
				{
					do
					{
						valid=1;
						printf("\tFirst Name: ");
						fflush(stdin);
						scanf("%s",p.FirstName);
						
						for(int k=0; k< strlen(p.FirstName) && valid==1 ; k++)
						{
							if(!isalpha(p.FirstName[k]))
							{
								valid=0;
								printf("\nEntered input is incorrect, please enter proper input.....\n\n");
							}
						}
						
					}
					while(valid==0);
				}
				
				else if(num==4)
				{
					do
					{
						valid=1;
						printf("\tLast Name : ");
						fflush(stdin);
						scanf("%s",p.LastName);
						
						for(int k=0; k< strlen(p.LastName) && valid==1 ; k++)
						{
							if(!isalpha(p.LastName[k]))
							{
								valid=0;
								printf("\nEntered input is incorrect, please enter proper input.....\n\n");
							}
						}
						
					}
					while(valid==0);
				}
				
				else if(num==5)
				{
					printf("\tAge : ");
					scanf("%d",&p.age);
				}
				
				else if(num==6)
				{
					do
					{
					
						printf("\tGender (M/F) : ");
						fflush(stdin);
						scanf(" %c",&p.gender);
						
						if(toupper(p.gender)=='M'|| toupper(p.gender)=='F')
						{
							valid=1;
							p.gender=toupper(p.gender);
						}
						else
						{
							valid=0;
							printf("\nEntered input is incorrect, please enter proper input.....\n\n");
						}
					
					}
					while(valid==0);
					
				}
				
				else if(num==7)
				{
					do
					{
						valid=1;
						printf("\tPhone number: ");
						fflush(stdin);
						scanf("%s",p.PhoneNumber);
						
						for(int k=0; k< strlen(p.PhoneNumber) && valid==1 ; k++)
						{
							if(isalpha(p.PhoneNumber[k]))
							{
								valid=0;
								printf("\nEntered input is incorrect, please enter proper input.....\n\n");
							}
							if(strlen(p.PhoneNumber)!=10)
							{
								valid=0;
								printf("\nEntered input is incorrect, please enter proper input.....\n\n");
								
							}
						}
						
					}
					while(valid==0);	
				}
				
				else if(num==8)
				{
					do
					{
						valid=1;
						printf("\tResidential City: ");
						fflush(stdin);
						scanf("%s",p.ResidentialCity);
						
						for(int k=0; k< strlen(p.ResidentialCity) && valid==1 ; k++)
						{
							if(!isalpha(p.ResidentialCity[k]))
							{
								valid=0;
								printf("\nEntered input is incorrect, please enter proper input.....\n\n");
							}
						}
					}
					while(valid==0);
				}
				
				else if(num==9)
				{
					printf("\tEmail address: ");
					fflush(stdin);
					scanf("%s",p.Email);
				}
				
				else if(num==10)
				{
					printf("\tProblem : ");
					fflush(stdin);
					scanf("%s",p.Problem);	
				}
				
				
				else if(num==11)
				{
					do
					{
						valid=1;
						printf("\tDoctor : ");
						fflush(stdin);
						scanf("%s",p.Doctor);
						
						for(int k=0; k< strlen(p.Doctor) && valid==1 ; k++)
						{
							if(!isalpha(p.Doctor[k]))
							{
								valid=0;
								printf("\nEntered input is incorrect, please enter proper input.....\n\n");
							}
						}
						
					}
					while(valid==0);
					
				}
				
				else if(num==12)
				{
					printf("\tTotal charge: ");
					fflush(stdin);
					scanf("%s",p.charges.TotalCharge);
				}
				
				else if(num==13)
				{
					printf("\tTotal deposited: ");
					fflush(stdin);
					scanf("%s",p.charges.TotalDeposited);
				}
				
				else if(num==14)
				{
					printf("\tTotal return: ");
					fflush(stdin);
					scanf("%s",p.charges.TotalReturn);
				}
				
			}
			while(num!=15);	
		}
		
		fwrite(&p,sizeof(p),1,ptr1);
	}
	
	fclose(ptr);
	fclose(ptr1);
	
	if(flag==1)
	{
		ptr=fopen("Records.txt","w");
		ptr1=fopen("temp.txt","r");
		
		while(fread(&p, sizeof(p), 1, ptr1) >0)
		{
			fwrite(&p,sizeof(p),1,ptr);
		}
		printf("\nRecord has been updated ...");
		fclose(ptr);
		fclose(ptr1);
	}
	else
	{
		printf("\nNo record found ...");
	}
	

	
	printf("\n\nPress Enter to continue ...");
	getch();
	system("cls");
	
	MainMenu();
}

void List_record_of_patients()
{
	system("cls");
	Title();
	
	FILE*ptr;
	ptr=fopen("Records.txt","r");
	
	printf("\n\n# List Patient Record\n\n");
	
	int choice;
	
	do
	{

		printf("1. Records of patient in alphabetical order\n2. Records of Emergency patients\n3. Records of O.P.D. patients");
		printf("\n\nEnter your choice from above options: ");
		scanf("%d",&choice);
		
		if(choice==1)
		{
			int i=0,j=0;
   			char str[100][100],s[100];
   		
   			while(fread(&p,sizeof(p),1,ptr)>0)
   			{
   				strcpy(str[i],p.FirstName);
   				i++;
   				
			}
			
			fseek(ptr,0,SEEK_END);
			int n=ftell(ptr)/sizeof(p);
			
   			for(i=0;i<n;i++)
			   {
      				for(j=i+1;j<n;j++)
						{
		         			if(strcmp(str[i],str[j])>0)
								{
		            				strcpy(s,str[i]);
		            				strcpy(str[i],str[j]);
		            				strcpy(str[j],s);
		         				}			
	      				}
   				}
		   	
		   	i=0;
		   	while(i<n)
		   	{	
		   		int found=0;
		   		rewind(ptr);
		   		while(fread(&p,sizeof(p),1,ptr)>0 && found==0)
		   		{
		   			if(!strcmp(p.FirstName,str[i]))
		   			{
		   				printf("\nService Type: %d \nPatient Number: %d \nFirst Name: %s \nLast Name: %s \nAge: %d \nGender: %c \nPhone Number: %s \nResidential City: %s \nEmail : %s \nProblem: %s \nDoctor: %s \nTotal Charge: %s \nTotal Deposited: %s \nTotal Return: %s",p.ServiceType,p.PatientNumber,p.FirstName,p.LastName,p.age,p.gender,p.PhoneNumber,p.ResidentialCity,p.Email,p.Problem,p.Doctor,p.charges.TotalCharge,p.charges.TotalDeposited,p.charges.TotalReturn);
						printf("\n=======================================================================================================================\n");
		
		   				i++;
		   				found=1;
		   				
					}
		   			
				}
		   		
			   }	
		}
		
		else if(choice ==2)
		{
			while(fread(&p, sizeof(struct patient), 1, ptr) >0)
			{
				if(p.ServiceType==1)
				{
					printf("\nService Type: %d \nPatient Number: %d \nFirst Name: %s \nLast Name: %s \nAge: %d \nGender: %c \nPhone Number: %s \nResidential City: %s \nEmail : %s \nProblem: %s \nDoctor: %s \nTotal Charge: %s \nTotal Deposited: %s \nTotal Return: %s",p.ServiceType,p.PatientNumber,p.FirstName,p.LastName,p.age,p.gender,p.PhoneNumber,p.ResidentialCity,p.Email,p.Problem,p.Doctor,p.charges.TotalCharge,p.charges.TotalDeposited,p.charges.TotalReturn);
					printf("\n=======================================================================================================================\n");
		
				}
			}
		}
		
		else if(choice ==3)
		{
			while(fread(&p, sizeof(struct patient), 1, ptr) >0)
			{
				if(p.ServiceType==0)
				{
					printf("\nService Type: %d \nPatient Number: %d \nFirst Name: %s \nLast Name: %s \nAge: %d \nGender: %c \nPhone Number: %s \nResidential City: %s \nEmail : %s \nProblem: %s \nDoctor: %s \nTotal Charge: %s \nTotal Deposited: %s \nTotal Return: %s",p.ServiceType,p.PatientNumber,p.FirstName,p.LastName,p.age,p.gender,p.PhoneNumber,p.ResidentialCity,p.Email,p.Problem,p.Doctor,p.charges.TotalCharge,p.charges.TotalDeposited,p.charges.TotalReturn);
					printf("\n=======================================================================================================================\n");
		
				}
			}
		}
	
	}
	while(choice<1 || choice >3);
				

	fclose (ptr);
	
	printf("\n\nPress Enter to continue ...");
	getch();
	system("cls");
	
	MainMenu();
	
}

void Delete_record()
{
	system("cls");
	Title();
	
	FILE*ptr;
	FILE*ptr1;
	ptr=fopen("Records.txt","r");
	ptr1=fopen("temp.txt","w");
	
	printf("\n\n# Delete Patient Record\n\n");
	
	char phone_number[10];
	printf("\nEnter phone number of patient: ");
	fflush(stdin);
	scanf("%s",phone_number);
	
	int found=0;
	
	while(fread(&p, sizeof(p), 1, ptr) >0)
	{
		if(!strcmp(p.PhoneNumber,phone_number))
		{
			printf("stage2");
			found=1;
			printf("\nService Type: %d \nPatient Number: %d \nFirst Name: %s \nLast Name: %s \nAge: %d \nGender: %c \nPhone Number: %s \nResidential City: %s \nEmail : %s \nProblem: %s \nDoctor: %s \nTotal Charge: %s \nTotal Deposited: %s \nTotal Return: %s",p.ServiceType,p.PatientNumber,p.FirstName,p.LastName,p.age,p.gender,p.PhoneNumber,p.ResidentialCity,p.Email,p.Problem,p.Doctor,p.charges.TotalCharge,p.charges.TotalDeposited,p.charges.TotalReturn);
			printf("\n=======================================================================================================================\n");
		}
		else
		{
			printf("stage3");
			fwrite(&p,sizeof(p),1,ptr1);
		}
		printf("stage4");
		
	}
	
	printf("stage5");
	fclose(ptr);
	fclose(ptr1);
	
	if(found==1)
	{
		ptr=fopen("Records.txt","w");
		ptr1=fopen("temp.txt","r");
		
		while(fread(&p, sizeof(p), 1, ptr1) >0)
		{
			fwrite(&p,sizeof(p),1,ptr);
		}
		printf("\nRecord has been deleted ...");
		fclose(ptr);
		fclose(ptr1);
	}
	else
	{
		printf("\nNo record found ...");
	}
	

	
	printf("\n\nPress Enter to continue ...");
	getch();
	system("cls");
	
	MainMenu();
}

void Print_outsider_patient_data()
{
	system("cls");
	Title();
	
	FILE*ptr;
	ptr=fopen("Records.txt","r");
	
	printf("\n\n# Printing Outsider Patient Record\n\n");
		
	char city[15];	
			
	while(fread(&p, sizeof(struct patient), 1, ptr) >0)
		{
			
			for(int k=0; k< strlen(p.ResidentialCity); k++)
			{
				city[k]=tolower(p.ResidentialCity[k]);
			}
		
			if(strcmp(city,"nagpur"))
			{
				printf("\nService Type: %d \nPatient Number: %d \nFirst Name: %s \nLast Name: %s \nAge: %d \nGender: %c \nPhone Number: %s \nResidential City: %s \nEmail : %s \nProblem: %s \nDoctor: %s \nTotal Charge: %s \nTotal Deposited: %s \nTotal Return: %s",p.ServiceType,p.PatientNumber,p.FirstName,p.LastName,p.age,p.gender,p.PhoneNumber,p.ResidentialCity,p.Email,p.Problem,p.Doctor,p.charges.TotalCharge,p.charges.TotalDeposited,p.charges.TotalReturn);
				printf("\n=======================================================================================================================\n");
		
			}
		}
	fclose (ptr);
	
	printf("\n\nPress Enter to continue ...");
	getch();
	system("cls");
	
	MainMenu();
	
}

void Maximum_and_Minimum_charge()
{
	system("cls");
	Title();
	
	FILE*ptr;
	ptr=fopen("Records.txt","r");
	
	printf("\n\n# Maximum and Minimum charged Patients Record\n\n");
	
	int choice;
	char max[15],min[15];
	
	do
	{
		printf("1. Record of patients who are charged Highest\n2. Record of patients who are charged Lowest");
		printf("\n\nEnter your choice from above options: ");
		scanf("%d",&choice);
		
		if(choice==1)
		{
			fread(&p,sizeof(p),1,ptr);
			strcpy(max,p.charges.TotalCharge);
			
			while(fread(&p, sizeof(struct patient), 1, ptr) >0)
			{
				if(atoi(p.charges.TotalCharge)>atoi(max))
				{
					strcpy(max,p.charges.TotalCharge);
				}
			}
			
			rewind(ptr);
			
			while(fread(&p, sizeof(struct patient), 1, ptr) >0)
			{
				if(!strcmp(max,p.charges.TotalCharge))
				{
					printf("\nService Type: %d \nPatient Number: %d \nFirst Name: %s \nLast Name: %s \nAge: %d \nGender: %c \nPhone Number: %s \nResidential City: %s \nEmail : %s \nProblem: %s \nDoctor: %s \nTotal Charge: %s \nTotal Deposited: %s \nTotal Return: %s",p.ServiceType,p.PatientNumber,p.FirstName,p.LastName,p.age,p.gender,p.PhoneNumber,p.ResidentialCity,p.Email,p.Problem,p.Doctor,p.charges.TotalCharge,p.charges.TotalDeposited,p.charges.TotalReturn);
					printf("\n=======================================================================================================================\n");
		
				}
			}
			
		}
		
		else if(choice ==2)
		{
			fread(&p,sizeof(p),1,ptr);
			strcpy(min,p.charges.TotalCharge);
			
			while(fread(&p, sizeof(struct patient), 1, ptr) >0)
			{
				if(!atoi(p.charges.TotalCharge)<atoi(min))
				{
					strcpy(min,p.charges.TotalCharge);
				}
			}
			
			rewind(ptr);
			
			while(fread(&p, sizeof(struct patient), 1, ptr) >0)
			{
				if(!strcmp(min,p.charges.TotalCharge))
				{
					printf("\nService Type: %d \nPatient Number: %d \nFirst Name: %s \nLast Name: %s \nAge: %d \nGender: %c \nPhone Number: %s \nResidential City: %s \nEmail : %s \nProblem: %s \nDoctor: %s \nTotal Charge: %s \nTotal Deposited: %s \nTotal Return: %s",p.ServiceType,p.PatientNumber,p.FirstName,p.LastName,p.age,p.gender,p.PhoneNumber,p.ResidentialCity,p.Email,p.Problem,p.Doctor,p.charges.TotalCharge,p.charges.TotalDeposited,p.charges.TotalReturn);
					printf("\n=======================================================================================================================\n");
		
				}
			}
		}

	}
	while(choice<1 || choice >2);
				

	fclose (ptr);
	
	printf("\n\nPress Enter to continue ...");
	getch();
	system("cls");
	
	MainMenu();
	
}

void Funds_Return_Data()
{
	system("cls");
	Title();
	
	FILE*ptr;
	ptr=fopen("Records.txt","r");
	
	printf("\n\n# Funds Return Data\n\n");
		
	while(fread(&p, sizeof(struct patient), 1, ptr) >0)
			{
				if(atoi(p.charges.TotalReturn)>0)
				{
					printf("\nFirst Name: %s \nLast Name: %s \nTotal Return: %s",p.FirstName,p.LastName,p.charges.TotalReturn);
					printf("\n=======================================================================================================================\n");
		
				}
			}
				
	fclose (ptr);
	
	printf("\n\nPress Enter to continue ...");
	getch();
	system("cls");
	
	MainMenu();
	
}

void Search_patient_by_Age()
{
	system("cls");
	Title();
	
	FILE*ptr;
	ptr=fopen("Records.txt","r");
	
	printf("\n\n# Search patient by age who are using emergency services\n\n");
	
	int choice;
	
	do
	{
		printf("1. 25-40\n2. 40+\n");
		printf("\n\nEnter your choice from above options: ");
		scanf("%d",&choice);
		
		if(choice==1)
		{
			while(fread(&p, sizeof(struct patient), 1, ptr) >0)
			{
				if(p.ServiceType==1 && p.age>=25 && p.age<=40)
				{
					printf("\nService Type: %d \nPatient Number: %d \nFirst Name: %s \nLast Name: %s \nAge: %d \nGender: %c \nPhone Number: %s \nResidential City: %s \nEmail : %s \nProblem: %s \nDoctor: %s \nTotal Charge: %s \nTotal Deposited: %s \nTotal Return: %s",p.ServiceType,p.PatientNumber,p.FirstName,p.LastName,p.age,p.gender,p.PhoneNumber,p.ResidentialCity,p.Email,p.Problem,p.Doctor,p.charges.TotalCharge,p.charges.TotalDeposited,p.charges.TotalReturn);
					printf("\n=======================================================================================================================\n");
		
				}
			}
			
		}
		
		else if(choice ==2)
		{
			while(fread(&p, sizeof(struct patient), 1, ptr) >0)
			{
				if(p.ServiceType==1 && p.age>40)
				{
					printf("\nService Type: %d \nPatient Number: %d \nFirst Name: %s \nLast Name: %s \nAge: %d \nGender: %c \nPhone Number: %s \nResidential City: %s \nEmail : %s \nProblem: %s \nDoctor: %s \nTotal Charge: %s \nTotal Deposited: %s \nTotal Return: %s",p.ServiceType,p.PatientNumber,p.FirstName,p.LastName,p.age,p.gender,p.PhoneNumber,p.ResidentialCity,p.Email,p.Problem,p.Doctor,p.charges.TotalCharge,p.charges.TotalDeposited,p.charges.TotalReturn);
					printf("\n=======================================================================================================================\n");
		
				}
			}
		}	
	
	}
	while(choice<1 || choice >2);
				

	fclose (ptr);
	
	printf("\n\nPress Enter to continue ...");
	getch();
	system("cls");
	
	MainMenu();
	
}

void Search_patient_by_Doctor()
{
	
	system("cls");
	Title();
	
	FILE*ptr;
	ptr=fopen("Records.txt","r");
	
	printf("\n\n# Search patient by doctor\n\n");
	
	char doctor[20];
	printf("Enter the doctor name:");
	scanf("%s",doctor);
	
	while(fread(&p, sizeof(struct patient), 1, ptr) >0)
			{
				if(!strcmp(doctor,p.Doctor))
				{
					printf("\nFirst Name: %s \nLast Name: %s ",p.FirstName,p.LastName);
					printf("\n=======================================================================================\n");
		
				}
			}
	fclose (ptr);
	
	printf("\n\nPress Enter to continue ...");
	getch();
	system("cls");
	
	MainMenu();
	
}

void View_Doctors()
{
	system("cls");
	Title();
	
	FILE*ptr;
	FILE*ptr1;
	ptr=fopen("Records.txt","r");
	ptr1=fopen("temp.txt","a+");
	
	printf("\n\n# View Doctors based on services\n\n");
	
	int choice,found;
	char doctor[20];
	
	do
	{
		printf("1. Doctors treating both OPD and Emergency patients\n2. Doctors treating only Emergency patients\n");
		printf("\n\nEnter your choice from above options: ");
		scanf("%d",&choice);
		
		if(choice==1)
		{
			while(fread(&p, sizeof(struct patient), 1, ptr) >0)
			{
				found=0;
				rewind(ptr1);
				while((fread(&doctor,sizeof(doctor),1,ptr1) >0) && found ==0)
				{
					found=!strcmp(doctor,p.Doctor);	
				}
				
				if(found==0)
				{
					fwrite(p.Doctor,sizeof(p.Doctor),1,ptr1);
				}
					
			}
			
			rewind(ptr1);
			
			while(fread(&doctor,sizeof(doctor),1,ptr1) >0 )
			{
				printf("\n%s",doctor);
			}
			
		}
		
		else if(choice ==2)
		{
			while(fread(&p, sizeof(struct patient), 1, ptr) >0)
			{
				if(p.ServiceType==1)
				{	
					found=0;
					rewind(ptr1);
					while((fread(&doctor,sizeof(doctor),1,ptr1) >0) && found ==0)
					{
						found=!strcmp(doctor,p.Doctor);	
					}
					
					if(found==0)
					{
						fwrite(p.Doctor,sizeof(p.Doctor),1,ptr1);
					}
					
				}	
				
			}
			rewind(ptr1);
				
			while(fread(&doctor,sizeof(doctor),1,ptr1) >0 )
			{
				printf("\n%s",doctor);
			}
		}
	}
	while(choice<1 || choice >2);
				
	
	fclose (ptr);
	fclose(ptr1);
	
	fclose(fopen("temp.txt", "w"));
	
	printf("\n\nPress Enter to continue ...");
	getch();
	system("cls");
	
	MainMenu();
	
}

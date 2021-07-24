//-----start including header files-----
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//--------end header file-----

//---global variables-----
int i,j,main_exit,choice,flagcount;
FILE *fp, *hostel,*ptr,*view,*old,*newrec;
 
//--declaring student record functions---
void menu();
void new_student();
void modify_student();
void view_studentAll();
void delete_student();
void search_student();
void sort_studentdata();
void clearscreen();
//----End student record Functions--------

//---defining structures ---
struct date{
    int month,day,year;
};
struct {
    char name[50];
    int age;
    char sex[10];  
    char room_no[8];
    char hostelno[60];
    int year;   
    char course[50];
    char Id[10];
    struct date allotteddate;
    }add,modifyStudent,check,rem,sort;

//----End structures----------
//main function
int main()
{
  password();
  menu();
  return 0;
}


//----menu function---
void menu()
{ //clear screen
    system("CLS");
    printf("\n\n\t\t\tHOSTEL MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\t ++++++++ WELCOME TO THE MAIN MENU +++++++++++++");
    printf("\n\n\t\t1. Add new Student's Record\n\t\t2. Modify Student Record \n\t\t3. Search Student Record\n\t\t4. Delete Student Record By Id\n\t\t5. List Student Record\n\t\t6. Exit\n\n\n\t\t Enter your choice:");
    scanf("%d",&choice);

    switch(choice)
    {

	case 1:new_student();
	break;
	case 2:modify_student();
	break;
	case 3:search_student();
	break;
	case 4:delete_student();
	break;
	case 5:view_studentAll();
	break;
	case 6:clearscreen();
	break;
	default:menu();
    }
}

//------------------------------------------------------------------------------------------------------------------
//function to display all students of a hostel
void sort_studentdata()
{
	system("CLS");
    flagcount=0; 
	hostel=fopen("studentRecord","a+");

    while(fscanf(hostel,"%s\n",check.Id)!=EOF)
    {
	    fp=fopen("studentRecord.txt","r");
	while(fscanf(fp,"%s %s %d/%d/%d %d %s %s %d %s %s\n",sort.Id, sort.name, &sort.allotteddate.month, &sort.allotteddate.day, &sort.allotteddate.year, &sort.age, sort.sex,  sort.hostelno, &sort.year, sort.room_no, sort.course)!=EOF)
	{
		if(strcmp(check.Id,sort.Id)==0)
		{
			if(flagcount==0)
			{
				printf("\t\tFollowing is the list of requested students:");
			    printf("\n\tROLL NO.\tNAME\tROOM NO.\n");
			}
			printf("\n\t%8s\t %8s\t %s", sort.Id, sort.room_no, sort.name);
			flagcount++;
		}
	}
    }

    fclose(fp);
    if (flagcount==0)
	printf("\nNO RECORDS!!\n");

    sort_list_invalid:
    printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);

    if (main_exit==1)
	menu();
    else if(main_exit==0)
	clearscreen();
    else
    {
	printf("\nInvalid!\a");
	goto sort_list_invalid;
    }

}

//------------------------------------------------------------------------------------------------------------------
//new entry function
void new_student()
{
	system("CLS");
    ptr=fopen("studentRecord.txt","a+");
    Id:
    printf("\n\t\t\t\--> ADD STUDENTS DATA *********");
    printf("\nEnter your roll number:");
    scanf("%s",check.Id);
    while(fscanf(ptr,"%s %s %d/%d/%d %d %s %s %d %s %s\n",add.Id, add.name, &add.allotteddate.month, &add.allotteddate.day, &add.allotteddate.year, &add.age, add.sex,  add.hostelno, &add.year, add.room_no, add.course)!=EOF)
    {
	if (strcmp(check.Id,add.Id)==0)
	    {printf("Students roll no. already in use!");
	     goto Id;
	}
    }

    strcpy(add.Id,check.Id);
    printf("\nEnter the name:");
    scanf("%s",&add.name);
    printf("\nEnter Alloted Date Till(mm/dd/yyyy):");
    scanf("%d/%d/%d",&add.allotteddate.month,&add.allotteddate.day,&add.allotteddate.year);
    printf("\nEnter the age:");
    scanf("%d",&add.age);
    printf("\nEnter the sex:");
    scanf("%s",&add.sex);
    printf("\n Enter hostel no :");
    scanf("%s",&add.hostelno);
    printf("\n Enter session Year:");
    scanf("%d",&add.year);
    printf("\n Enter your room no.:");
    scanf("%s",&add.room_no);
    printf("\n Enter your coure:");
    scanf("%s",&add.course);
    fprintf(ptr,"%s %s %d/%d/%d %d %s %s %d %s %s\n",add.Id, add.name, add.allotteddate.month, add.allotteddate.day, add.allotteddate.year, add.age, add.sex,  add.hostelno, add.year, add.room_no, add.course);

	

    fclose(ptr);
    printf("\nStudent added successfully!");
    add_invalid:
    printf("\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);

    if (main_exit==1)

	menu();
    else if(main_exit==0)
	    clearscreen();
    else
	{
	    printf("\nInvalid!\a");
	    goto add_invalid;
	}
}

//------------------------------------------------------------------------------------------------------------------
//nsbfunction to view all students
void view_studentAll()
{
	system("CLS");

    view=fopen("studentRecord.txt","r");
 flagcount=0;

    printf("Hostel Student Record List\n");
    printf("=================================\n");
    printf("ID  NAME	 Sex   Age   HostelNo	RoomNo	Course	Year	AllottedDate \n");
    printf("------------------------------------------------------------------------------\n");
    while(fscanf(view,"%s %s %d/%d/%d %d %s %s %d %s %s\n",add.Id, add.name, &add.allotteddate.month, &add.allotteddate.day, &add.allotteddate.year, &add.age, add.sex,  add.hostelno, &add.year, add.room_no, add.course)!=EOF)
       {
    printf("%s  %s\t%s\t%d\t%s\t%s\t%s\t%d\t%d/%d/%d\n",add.Id,add.name,add.sex,add.age,add.hostelno,add.room_no, add.course,add.year,add.allotteddate);
	   flagcount++;
       }
    fclose(view);

    if (flagcount==0)
	{
	    printf("\nNO RECORDS!!\n");}

    view_studentAll_invalid:
     printf("\n\nEnter 1 to go to the main menu and 0 to exit:");
	scanf("%d",&main_exit);

	if (main_exit==1)
	    menu();
	else if(main_exit==0)
	    clearscreen();
	else
	{
	    printf("\nInvalid!\a");
	    goto view_studentAll_invalid;
	}
}

//------------------------------------------------------------------------------------------------------------------
//function to view all data of 1 student
void search_student()
{
	system("CLS");

      flagcount=0;

    ptr=fopen("studentRecord.txt","r");
    printf("Do you want to search By\n1.Roll no\n2.Name\nEnter your choice:");
    scanf("%d",&choice);
    if (choice==1)
    {
		printf("\n\nEnter the roll number:");
		scanf("%s",check.Id);

	while (fscanf(ptr,"%s %s %d/%d/%d %d %s %s %d %s %s\n",add.Id, add.name, &add.allotteddate.month, &add.allotteddate.day, &add.allotteddate.year, &add.age, add.sex,  add.hostelno, &add.year, add.room_no, add.course)!=EOF)
	{
	    if(strcmp(add.Id,check.Id)==0)
	    {
		flagcount=1;

		printf("\nROLL NO.:%s\nName:%s \nallotteddate:%d/%d/%d \nAge:%d \nsex:%s  \nHostelno:%s \n Year:%d \nRoom No:%s \nCourse:%s \n",add.Id, add.name, add.allotteddate.month, add.allotteddate.day, add.allotteddate.year, add.age, add.sex,  add.hostelno, add.year, add.room_no, add.course);
	    }
	}
    }
    else if (choice==2)
    {
	printf("\n\nEnter the name:");
	scanf("%s",check.name);
	while (fscanf(ptr,"%s %s %d/%d/%d %d %s %s %d %s %s\n",add.Id, add.name, &add.allotteddate.month, &add.allotteddate.day, &add.allotteddate.year, &add.age, add.sex,  add.hostelno, &add.year, add.room_no, add.course)!=EOF)
	{
	    if(strcmp(add.name,check.name)==0)
	    {
		flagcount=1;
		printf("\nROLL NO.:%s\nName:%s \nallotteddate:%d/%d/%d \nAge:%d \nsex:%s  \nHostelno:%s \n Year.:%d \nRoom No:%s \nCourse:%s \n",add.Id, add.name, add.allotteddate.month, add.allotteddate.day, add.allotteddate.year, add.age, add.sex,  add.hostelno, add.year, add.room_no, add.course);
	    }
	}
    }

    fclose(ptr);
    if(flagcount!=1)
	printf("\nRecord not found!!\a\a\a");
    search_student_invalid:
	printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
	scanf("%d",&main_exit);
	if (main_exit==1)
	    menu();
	else if (main_exit==2)
	    clearscreen();
	else if(main_exit==0)
	    delete_student();
	else
	{
		printf("\nInvalid!\a");
	    goto search_student_invalid;
	}
}

//------------------------------------------------------------------------------------------------------------------
//function to modifyStudentate student info
void modify_student()
{
     system("CLS");
     flagcount=0;

    old=fopen("studentRrecord.txt","r");
    newrec=fopen("new.txt","w");

    printf("\nEnter the roll no. of the student whose info you want to change:");
    scanf("%s",modifyStudent.Id);
    while(fscanf(old,"%s %s %d/%d/%d %d %s %s %d %s %s\n",add.Id, add.name, &add.allotteddate.month, &add.allotteddate.day, &add.allotteddate.year, &add.age, add.sex, add.hostelno, &add.year, add.room_no, add.course)!=EOF)

    {
	if (strcmp(add.Id,modifyStudent.Id)==0)
	{
		flagcount=1;
    printf("\nEnter the name:");
    scanf("%s",&modifyStudent.name);
    printf("\nEnter the age:");
    scanf("%d",&modifyStudent.age);
    printf("\nEnter the sex:");
    scanf("%s",&modifyStudent.sex);
    printf("\nEnter the new room no.:");
    scanf("%s",modifyStudent.room_no);
    printf("\nEnter the new Hostelno number:");
    scanf("%s",&modifyStudent.hostelno);

    printf("\n Enter session Year:");
    scanf("%d",&modifyStudent.year);
    printf("\n Enter your Course:");
    scanf("%s",&modifyStudent.course);


		fprintf(newrec,"%s %s %d/%d/%d %d %s %s %d %s %s\n",add.Id, modifyStudent.name, add.allotteddate.month, add.allotteddate.day, add.allotteddate.year, modifyStudent.age, modifyStudent.sex,modifyStudent.hostelno,modifyStudent.year,modifyStudent.room_no,modifyStudent.course);
		printf("Changes saved!");


	}
	else
	    fprintf(newrec,"%s %s %d/%d/%d %d %s %s %d %s %s\n",add.Id, add.name, add.allotteddate.month, add.allotteddate.day, add.allotteddate.year, add.age, add.sex, add.hostelno, add.year, add.room_no, add.course);
    }
    fclose(old);
    fclose(newrec);
    remove("studentRecord.txt");
    rename("new.txt","studentRecord.txt");

	if(flagcount!=1)
	printf("\nRecord not found!!\a\a\a");

    modify_student_invalid:
		printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
	scanf("%d",&main_exit);
	if (main_exit==1)
			menu();
	else if (main_exit==2)
	    clearscreen();
	else if(main_exit==0)
	    modify_student();
	else
	{
		printf("\nInvalid!\a");
	    goto modify_student_invalid;
	}

}

//------------------------------------------------------------------------------------------------------------------
//function to delete records
void delete_student()
{
	system("CLS");

    flagcount=0;
    old=fopen("studentRecord.txt","r");
    newrec=fopen("new.txt","w");
    printf("Enter the roll np. of student whose data you want to delete:");
    scanf("%s",rem.Id);
    while (fscanf(old,"%s %s %d/%d/%d %d %s %s %d %s %s\n",add.Id, add.name, &add.allotteddate.month, &add.allotteddate.day, &add.allotteddate.year, &add.age, add.sex,  add.hostelno, &add.year, add.room_no, add.course)!=EOF)
   {
	if(strcmp(add.Id,rem.Id)!=0)
	{
	    printf("\n%s %s",&add.Id,rem.Id);
	    fprintf(newrec,"%s %s %d/%d/%d %d %s %s %d %s %s\n",add.Id, add.name, add.allotteddate.month, add.allotteddate.day, add.allotteddate.year, add.age, add.sex,  add.hostelno, add.year, add.room_no, add.course);
	 }
	else
	    {
	    flagcount++;
	    printf("\nRecord deleted successfully!\n");
	    }
    }
    fclose(old);
    fclose(newrec);
    remove("studentRecord.txt");
    rename("new.txt","studentRecord.txt");
    if(flagcount==0)
	    printf("\nRecord not found!!\a\a\a");
    delete_student_invalid:
	printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
	scanf("%d",&main_exit);
	if (main_exit==1)
	    menu();
	else if (main_exit==2)
	    clearscreen();
	else if(main_exit==0)
	    delete_student();
	else
	{
		printf("\nInvalid!\a");
	    goto delete_student_invalid;
		}
}

//------------------------------------------------------------------------------------------------------------------
//function clear the output screen
void clearscreen()
{
	system("CLS");
    printf("\n\n\n\nThanks\n\n\n");
}

int password(void)
{
   int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="pass";
    char pass[10]="pass";
    do
{
	system("cls");

    printf("\n  **************************  LOGIN FORM  **************************  ");
    printf(" \n                       ENTER USERNAME:-");
	scanf("%s", &uname);
	printf(" \n                       ENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	//char code=pword;
	i=0;
	//scanf("%s",&pword);
		if(strcmp(uname,user)==0 && strcmp(pword,pass)==0)
	{
	printf("  \n\n\n       WELCOME !!!! LOGIN IS SUCCESSFUL\n");
	system("PAUSE");
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL\n");
		system("PAUSE");
		a++;

		getch();

	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");

		getch();

		}
		system("cls");
		return 0;
}


/*
		HOSPITAL MANAGEMENT CONSOLE
	     ------------------------------------------------
		PALAK JADWANI & MEGHA GOYAL

*/

#include<fstream.h>
#include<math.h>
#include<process.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<dos.h>
#include<iomanip.h>
//////////////////////////////////////////////

void Pmenu();
void emenu();
struct date1
{
int dd,mm,yy;
};
void date()
{
 int d1, m1, y1 ;
 struct date d;
 getdate(&d);          //Inbuilt function to display current
 d1 = d.da_day ;       //date of the system
 m1 = d.da_mon ;
 y1 = d.da_year ;
 gotoxy(52,2) ;
 cout <<"System Date : "<<d1<<"/" <<m1 <<"/" <<y1 ;
}
//function for loading the software
void loader()
{
 clrscr();
 gotoxy(15,20);cout<<"<<< HOSPITAL MANAGEMENT SYSTEM >>>";
 gotoxy(22,11);cout<<"loading your software";
 gotoxy(29,13);
 for(int loop=1;loop<=4;loop++)
 {
  textcolor(YELLOW);
  sleep(1);
  cout<<"*";
  ;
 }
}
void MAIN();
//for welcome screen showing wssential details of the software
void DETAILS()
{
 char ch;
 clrscr();
 date();
 gotoxy(20,2);
 textcolor(GREEN);
 cout<<"***** HOSPITAL MANAGENT SYSTEM ***** ";
 textcolor(LIGHTGRAY);
 gotoxy(27,3);
 cout<<"Important Information";
 textcolor(YELLOW);
 gotoxy(3,5);
 cout<<"#1";
 textcolor(WHITE+BLINK);
 gotoxy(7,5);
 cout<<"you cab add/create,edit/update,delete/remove or simply view";
 gotoxy(7,6);
 cout<<"records of patients and doctors in a easy way .";
 textcolor(YELLOW);
 gotoxy(3,8);
 cout<<"#2";
 textcolor(WHITE);
 gotoxy(7,8);
 cout<<"this application is password protected to guarantee parental";
 gotoxy(7,9);
 cout<<"controls to the user.if password is lost, please contact";
 gotoxy(7,10);
 cout<<"system administrator for default password.";
 gotoxy(19,21);
 cout<<"copyright 2014 | all rights reserved";
 textcolor(CYAN);
 gotoxy(22,22);
 cout<<"PALAK JADWANI & MEGHA GOEL";
 gotoxy(25,23);
 cout<<"SALWAN PUBLIC SCHOOL ";
 textcolor(YELLOW);
 gotoxy(16,17);
 cout<<"PRESS E AND ENTER TO TRANSIT TO THE MAIN MENU";
 gotoxy(18
 ,18);
 cout<<"PRESS Q AND ENTER TO QUIT \n";
 cout<<" ";
 cin>>ch;
 if(ch=='Q'||ch=='q')
  exit(0);
 if(ch=='E'||ch=='e')
 MAIN();
 loader();
}

/******************************************************
*
*  Class PERSON to modulate a person's
*  characteristics and behaviors.
*
*******************************************************/
class person
{
 char fname[100];
 char add[200];
 char city[5];
 char state[50];
 char country[50];
 long double number;

 public:
 int age;
 char gender[10];
 char name[100];
 void in();
 void out();
};

/******************************************************
*
*  Class PATIENT to modulate a patient's
*  characteristics and behaviors.
*
*******************************************************/
class patient:public person
{
 char rtype[15]; // luxory/deluxe/general
 char bg[5];   //blood group
 int pstay;    // Number of days stayed
 date1 doa;      //date of admission
 date1 dod;      //date of discharge
 float prc;           // 24 hr Room Charge
 float amt;     //total bill
 float voice;  // To store payable amount

 public:
 int pid; //unique patient's ID
 int rno; //room no.
 void enterp();
 void showp();
 void paybill();
 void discharge();
 void pmod();
 void setpstay()
 {
  pstay=dod.dd-doa.dd;
 }
 void setprc()
 {
   if(rtype=="luxory")
    prc=5000;
   else if(rtype=="deluxe")
    prc=3000;
   else
    prc=1000;
 }
}p;

/******************************************************
*
*  Class EMPLOYEE to modulate a employee's
*  characteristics and behaviors.
*
*******************************************************/
class employee:public person
{
 float expe;
 float sal;
 date1 doa;      //date of admission
 date1 dod;      //date of discharge
 char dept[20];
 char category[10]; //'d' for doctor and 'e' for employee
 float esal;          // Monthly Salary

 public:
 int eid;
 char erno[10];       // Room number
 void entere();
 void showe();
 void paysal();
 void remove();
 void emod();

}e;

/******************************************************
*
*  Function in() to enter a PERSON record
*
*******************************************************/
void person::in()
{
 cout<<"\n Name :";
 gets(name);
 cout<<" Age :";
 cin>>age;
 cout<<" Gender :";
 gets(gender);
 cout<<" Father's Name :";
 gets(fname);
 cout<<" Address :";
 gets(add);
 cout<<" City :";
 gets(city);
 cout<<" State :";
 gets(state);
 cout<<" country :";
 gets(country);
 cout<<" Contact number :";
 cin>>number;
}

/******************************************************
*
*  Function out() to print an invoked record on the
*  screen
*
*******************************************************/
void person::out()
{
 cout<<"\n Name :";
 puts(name);
 cout<<" Age: ";
 cout<<age;
 cout<<"\n Gender :";
 puts(gender);
 cout<<" Father's Name :";
 puts(fname);
 cout<<" Address :";
 puts(add);
 cout<<" City :";
 puts(city);
 cout<<" State :";
 puts(state);
 cout<<" country :";
 puts(country);
 cout<<" Contact Number :";
 cout<<number;
}

/******************************************************
*
*  Function enterp() to enter a patient record
*  and write to PATIENT.DAT
*
*******************************************************/
void patient::enterp()
{
 clrscr();
 patient p;
 date();
 struct date d;
 getdate(&d);
 doa.dd=d.da_day;
 doa.mm=d.da_mon;
 doa.yy=d.da_year;
 dod.dd=0;
 dod.mm=0;
 dod.yy=0;
 ifstream f;
 f.open("PATIENT", ios::binary|ios::in);
 if(!f)
 {
  pid=1;
 }
 else
 {
  while(!f.eof())
  {
   f.read((char*)&p,sizeof(p));
  }
  pid=p.pid+1;
 }
 cout<<"\n Patient ID :"<<pid;
 cout<<"\n Enter details of the PATIENT";
 in();
 cout<<" Room No. :";
 cin>>rno;
 cout<<"Room type[ luxory/deluxe/general] *** All AC Rooms ***:";
 gets(rtype);
 cout<<"Bloodgroup :";
 cin>>bg;
}

/******************************************************
*
*  Function entere() to enter a EMPLOYEE record
*  and write to EMPLOYEE.DAT
*
*******************************************************/
void employee::entere()
{
 clrscr();
 date();
 employee e;
 struct date d;
 getdate(&d);
 doa.dd=d.da_day;
 doa.mm=d.da_mon;
 doa.yy=d.da_year;
 dod.dd=0;
 dod.mm=0;
 dod.yy=0;
 ifstream f1;
 f1.open("EMPLOYEE.DAT",ios::binary);
 if(!f1)
 {
  eid=1;
 }
 else
 {
  while(!f1.eof())
  {
   f1.read((char*)&e,sizeof(e));
  }
  eid=e.eid+1;
 }
 f1.close();
 cout<<"\n Employee ID :"<<eid;
 cout<<"\n Enter details of the EMPLOYEE";
 in();
 cout<<" Category ( (d)doctor / (s)staff) :";
 cin>>category;
 cout<<"Department of work :";
 gets(dept);
 cout<<"Work Experience :";
 cin>>expe;
 cout<<"Room number :";
 cin>>erno;
 cout<<"Monthly salary :";
 cin>>esal;
}

/******************************************************
*
*  Function searchp() to search a patient's record
*  through patient ID of type long.
*
*******************************************************/
void searchp()
{
 clrscr();
 patient p;
 date();
 int pid;
 int flag=0;
 char ans;
 do
 {
 cout<<"\n Enter patient ID to be searched for :";
 cin>>pid;
 ifstream f1;
 f1.open("PATIENT",ios::binary);
 while(!f1.eof())
 {
  f1.read((char*)&p,sizeof(p));
  if(pid==p.pid)
  {
   p.showp();
   flag=1;
   break;
  }
 }
 f1.close();
 if(flag==0)
 {
  cout<<"\n The patient with patient ID "<<pid<<" is not found";
 }
 cout<<"\n  Do you want to enter again(y/n) ?";
 cin>>ans;
 }while(ans=='y'||ans=='Y');
}

/******************************************************
*
*  Function searche() to search a employee's record
*  through emloyee ID of type long.
*
*******************************************************/
void searche()
{
 clrscr();
 date();
 employee e;
 int eid;
 int flag=0;
 char ans;
 do
 {
 cout<<" \n Enter employee ID to be searched for :";
 cin>>eid;
 ifstream f1;
 f1.open("EMPLOYEE.DAT",ios::binary);
 while(!f1.eof())
 {
  f1.read((char*)&e,sizeof(e));
  if(eid==e.eid)
  {
   e.showe();
   flag=1;
  }
 }
 f1.close();
 if(flag==0)
 {
  cout<<"\n The employee with employee ID "<<eid<<" is not  found";
 }
 cout<<"\n Do you want to enter again(y\n) ?";
 cin>>ans;
 }while(ans=='y'||ans=='Y');
}

/******************************************************
*
*  Function showallp() to view captions of all records
*  and view details of selected records
*
*******************************************************/
void showallp()
{
   clrscr();
   patient p1;
   date();
   int ID;
   gotoxy(3,6);
   textcolor(WHITE);
   cputs("ALL PATIENT'S RECORD (SORTED BY ENTRY)");
   gotoxy(3,7);
   textcolor(WHITE);
   cputs("============================================================");
   gotoxy(3,8);  cout<<"PID";
   gotoxy(12,8);  cout<<"   <Patient's Name>-<Age>-<Gender>";
   gotoxy(50,8); cout<<"    Room Number";
   gotoxy(3,9);
   cputs("============================================================");
   ifstream f1;
   f1.open("PATIENT", ios::in|ios::binary);
   int y=11;
   while(!f1.eof())
   {
      f1.read((char*)&p,sizeof(p));
      gotoxy(3,y); cout<<p.pid;
      gotoxy(12,y); cout<<"    "<<p.name<<"-"<<p.age<<"-"<<p.gender;
      gotoxy(50,y); cout<<"    "<<p.rno;
      getch();
      y+=2;
   }
   f1.close();
   Pmenu();
}

/******************************************************
*
*  Function showalle() to view captions of all records
*  and view details of selected records
*
*******************************************************/
void showalle()
{
   clrscr();
   employee e;
   date();
   int ID;
   gotoxy(3,6);
   textcolor(WHITE);
   cputs("ALL EMPLOYEE'S RECORD (SORTED BY ENTRY)");
   gotoxy(3,7);
   textcolor(WHITE);
   cputs("============================================================");
   gotoxy(3,8);  cout<<"EID";
   gotoxy(12,8);  cout<<"   <Employee's Name>-<Age>-<Gender>";
   gotoxy(50,8); cout<<"    Room Number";
   gotoxy(3,9);
   cputs("============================================================");
   ifstream f1;
   f1.open("EMPLOYEE.DAT", ios::in|ios::binary);
   int y=11;
   while(!f1.eof())
   {
      f1.read((char*)&e,sizeof(e));
      gotoxy(3,y); cout<<e.eid;
      gotoxy(12,y); cout<<"    "<<e.name<<"-"<<e.age<<"-"<<e.gender;
      gotoxy(50,y); cout<<"    "<<e.erno;
      getch();
      y+=2;
   }
   f1.close();
   emenu();
}

/******************************************************
*
*  Function showp() to print an invoked record on the
*  screen
*
*******************************************************/
void patient::showp()
 {
  clrscr();
  date();
  cout<<"\n The details of the patient are :";
  cout<<"\n\n Date of admission : ";
  cout<<doa.dd<<"/"<<doa.mm<<"/"<<doa.yy;
  out();
  cout<<"\n Room Number : ";
  cout<<rno;
  cout<<"\n Blood Group :";
  cout<<bg;
 }
/******************************************************
*
*  Function showe() to print an invoked record on the
*  screen
*
*******************************************************/
void employee::showe()
 {
  clrscr();
  date();
  cout<<"The details of the employee are ";
  cout<<"\n\n Date of recruitment : ";
  cout<<doa.dd<<"/"<<doa.mm<<"/"<<doa.yy;
  out();
  cout<<"\n  Category :";
  puts(category);
  cout<<"\n  Department :";
  puts(dept);
  cout<<"\n  Work Experience :";
  cout<<expe;
  cout<<"\n  Employee salary :";
  cout<<sal;
 }

void patient::discharge()
 {
  struct date d;
  getdate(&d);
  dod.dd=d.da_day;
  dod.mm=d.da_mon;
  dod.yy=d.da_year;
  cout<<"\n No. of days stay(ed): ";
  cout<<pstay;
  cout<<"\n Total Bill Amount :";
  cout<<amt;
 }

void employee::remove()
 {
  struct date d;
  getdate(&d);
  dod.dd=d.da_day;
  dod.mm=d.da_mon;
  dod.yy=d.da_year;
  cout<<" \n Date of resignation :";
  cout<<dod.dd<<"/"<<dod.mm<<"/"<<dod.yy;
  cout<<" \n Total Salary :";
  cout<<esal;
 }

 /******************************************************
*
*  Function deletep() to delete a patient's record
*  accessable through patient's ID
*
*******************************************************/
void deletep()
 {
  int flag=0;
  clrscr();
  date();
  char ch,ans;
  int found;
  int pid;
  cout<<" \n Enter the patient ID to be discharged:";
  cin>>pid;
  ifstream f1;
  ofstream f2;
  ofstream f3;
  f1.open("PATIENT",ios::in|ios::binary);
  f2.open("temp",ios::binary|ios::out);
  f3.open("discharge",ios::binary|ios::app);
  while(!f1.eof())
  {
  f1.read((char*)&p,sizeof(p));
  if(pid==p.pid)
  {
    p.showp();
    p.discharge();
    found='t';
    cout<<" \n Are you sure the patient is allowed to be discharged  ?";
    cin>>ans;
    if(ans=='y')
    {
     f3.write((char*)&p,sizeof(p));
     cout<<" \n Patient record saved in another file !";
    }
    else
     f2.write((char*)&p,sizeof(p));
  }
  else
   f2.write((char*)&p,sizeof(p));
  }
  f1.close();
  f2.close();
  f3.close();
  if(found=='f')
   cout<<"Patient not found ";
   remove("PATIENT");
  rename("temp","PATIENT");
  getch();
  MAIN();
}

/******************************************************
*
*  Function edelete() to delete an employee's record
*  accessable through employee's ID
*
*******************************************************/
void edelete()
 {
  int flag=0;
  clrscr();
  date();
  char ch,ans;
  int found;
  int eid;
  cout<<" \n Enter the employee ID to be discharged:";
  cin>>eid;
  ifstream f1;
  ofstream f2;
  ofstream f3;
  f1.open("EMPLOYEE.DAT",ios::in|ios::binary);
  f2.open("temp",ios::binary|ios::out);
  f3.open("remove",ios::binary|ios::app);
  while(!f1.eof())
  {
  f1.read((char*)&e,sizeof(e));
  if(eid==e.eid)
  {
    e.showe();
    e.remove();
    found='t';
    cout<<" \n Are you sure you want to resign ?";
    cin>>ans;
    if(ans=='y')
    {
     f3.write((char*)&e,sizeof(e));
     cout<<" \n Employee record saved in another file !";
    }
    else  f2.write((char*)&e,sizeof(e));
  }
  else   f2.write((char*)&e,sizeof(e));
  }
  f1.close();
  f2.close();
  f3.close();
  if(found=='f')
   cout<<"employee not found ";
  remove("EMPLOYEE.DAT");
  rename("temp","EMPLOYEE.DAT");
  getch();
  MAIN();
}

void pwrite()
 {
 patient p;
 p.enterp();
 ofstream f1;
 f1.open("PATIENT",ios::app|ios::binary);
 f1.write((char*)&p,sizeof(p));
 f1.close();
 textcolor(LIGHTGRAY);
 gotoxy(3,29);
 cout<<" \n RECORD WAS SUCCESSFULLY SAVED";
 gotoxy(3,29);
 cout<<" \n Press ANY key to continue ";
 getch();
}

void ewrite()
{
 employee e;
 e.entere();
 ofstream f;
 f.open("EMPLOYEE.DAT",ios::app|ios::binary);
 f.write((char*)&e,sizeof(e));
 f.close();
 textcolor(LIGHTGRAY);
 gotoxy(3,29);
 cout<<" \n RECORD WAS SUCCESSFULLY SAVED";
 gotoxy(3,29);
 cout<<" \n Press ANY key to continue ";
 getch();
}

/******************************************************
*
*  Function PMODIFY() to modify the records
*  in the PATIENT field
*
*******************************************************/
/*void pmodify()
{
 clrscr();
 date();
 int ID;
 long pos;
 char found='f';
 cout<<"\n Enter the patient ID to be modified :";
 cin>>ID;
 fstream f1;
 f1.open("PATIENT",ios::in|ios::out|ios::binary);
 while(!f1.eof())
 {
  pos=f1.tellg();
  f1.read((char*)&p,sizeof(p));
  if(ID==p.pid)
  {
   p.pmod();
   f1.seekg(pos);
   f1.write((char*)&p,sizeof(p));
   found='t';
   break;
  }
 }
 if(found=='f')
  cout<<"\n Patient not found !";
 f1.seekg(0);
 cout<<"\n Now the patient data contains :\n";
 while(!f1.eof())
 {
  f1.read((char*)&p,sizeof(p));
  p.showp();
 }
 f1.close();
}

/******************************************************
*
*  Function EMODIFY() to modify the records
*  in the EMPLOYEE field
*
*******************************************************/
/*void emodify()
{
 clrscr();
 date();
 int ID;
 long pos;
 char found='f';
 cout<<"\n Enter the employee ID to be modified :";
 cin>>ID;
 fstream f1;
 f1.open("EMPLOYEE.DAT",ios::in|ios::out|ios::binary);
 while(!f1.eof())
 {
  pos=f1.tellg();
  f1.read((char*)&e,sizeof(e));
  if(ID==e.eid)
  {
   e.emod();
   f1.seekg(pos);
   f1.write((char*)&e,sizeof(e));
   found='t';
   break;
  }
 }
 if(found=='f')
  cout<<"\n Employee not found !";
 f1.seekg(0);
 cout<<"\n Now the employee data contains :\n";
 while(!f1.eof())
 {
  f1.read((char*)&e,sizeof(e));
  e.showe();
 }
 f1.close();
}

void patient::pmod()
{

 clrscr();
 date();
 char ch;
 cout<<"Enter the field you want to modify:";
 cout<<"1.Name"
     <<"2.Address"
     <<"3.Contact Number";
 cin>>ch;
 switch(ch)
 {
  case '1': clrscr();
	    cout<<"enter new name :";
	    gets(name);
	    break;

  case '2': clrscr();
	    cout<<"Enter new address :";
	    gets(add);
	    break;

  case '3': clrscr();
	    cout<<"Enter new contact number :";
	    cin>>number;
	    break;
 }
}

void employee::emod()
{

 clrscr();
 date();
 char ch;
 cout<<"Enter the field you want to modify:";
 cout<<"1.Name"
     <<"2.Address"
     <<"3.Contact Number";
 cin>>ch;
 switch(ch)
 {
  case '1': clrscr();
	    cout<<"enter new name :";
	    gets(p.name);
	    break;

  case '2': clrscr();
	    cout<<"Enter new address :";
	    gets(add);
	    break;

  case '3': clrscr();
	    cout<<"Enter new contact number :";
	    cin>>number;
	    break;
 }
}
/******************************************************
*
*  Function PMENU() to manage the flow of control
*  in the Patient field
*
*******************************************************/
void Pmenu()
{
 clrscr();
 char ch;
 char pass[20];
 date();
 gotoxy(3,2);
 textcolor(LIGHTGRAY);
 cout<<"PATIENT DATABASE SIMULATION";
 gotoxy(2,4);
 textcolor(BLUE);
 cout<<"========================================================";
 gotoxy(3,7);
 textcolor(LIGHTGRAY);
 cout<<"1. Admit a PATIENT ";
 gotoxy(3,9);
 cout<<"2. Display all PATIENTS ";
 gotoxy(3,11);
 cout<<"3. Search and display a PATIENT record ";
 gotoxy(3,13);
 cout<<"4. Search and discharge a PATIENT";
 gotoxy(3,15);
 cout<<"5. Bill calculator";
 gotoxy(3,17);
 cout<<"6. Modify or change the data of PATIENT";
 gotoxy(3,19);
 cout<<"7. go back to main menu ";
 gotoxy(3,21);
 cout<<"D. FORMAT records | disk clean-up";
 gotoxy(3,23);
 cout<<"E. press E to exit from the program";
 gotoxy(3,26);
 textcolor(WHITE);
 cprintf("please select any one of the above option  ");
 gotoxy(44,24);
 cin>>ch;
 switch(ch)
 {
  case '1': clrscr();
	    pwrite();
	    break;

  case '2': clrscr();
	    showallp();
	    break;

  case '3': clrscr();
	    searchp();
	    break;

  case '4': clrscr();
	    deletep();
	    break;

  case '5': clrscr();
	    p.paybill();
	    break;

  case '6': clrscr();
	    pmodify();
	    break;

  case '7': clrscr();
	    MAIN();
	    break;

  case 'E': clrscr();
	    {
	     char c;
	     gotoxy(10,20);
	     cout<<"\N sure want to EXIT [y\n] : ";
	     cin>>c;
	     if(c=='y'||c=='Y')
	     {
	      clrscr();
	      gotoxy(17,20);
	      textcolor(RED);
	      cputs(" exitting in      seconds");
	      gotoxy(29,20);
	      cout<<" 3 ";
	       sleep(1);
	      gotoxy(29,20);
	      cout<<" 2 ";
	       sleep(1);
	      gotoxy(29,20);
	      cout<<" 1 ";
	       sleep(1);
	       cout<<" 0 ";
	       exit(0);
	     }
	     break;
	    }

  case 'e':  clrscr();
	    {
	     char c;
	     gotoxy(10,20);
	     cout<<" \n sure want to EXIT [y\n] : ";
	     cin>>c;
	     if(c=='y'||c=='Y')
	     {
	      clrscr();
	      gotoxy(17,20);
	      textcolor(RED);
	      cputs(" exitting in      seconds");
	      gotoxy(29,20);
	      cout<<" 3 ";
	       sleep(1);
	      gotoxy(29,20);
	      cout<<" 2 ";
	       sleep(1);
	      gotoxy(29,20);
	      cout<<" 1 ";
	       sleep(1);
	       cout<<" 0 ";
	       exit(0);
	     }
	     break;
	    }

  case 'D': clrscr();
	    textcolor(WHITE);
	    gotoxy(5,10);
	    cout<<"enter administrator password :";
	    cin>>pass;
	    if(strcmp(pass,"2015palakmegha")==0)
	    {
	     cout<<"\n\n   you entered correct pass word :) ";
	     cout<<"\n   --> press enter to delete all contents ";
	     getch();
	     ofstream out;
	     out.open("PATIENT",ios::out);
	    }
	    else
	    {
	     textcolor(WHITE);
	     cout<<"\n\n    WRONG PASSWORD . Press any key to continue ";
	     getch();
	     Pmenu();
	    }

  case 'd':  clrscr();
	    textcolor(WHITE);
	    gotoxy(5,10);
	    cout<<"enter administrator password :";
	    cin>>pass;
	    if(strcmp(pass,"2015palakmegha")==0)
	    {
	     cout<<"\n\n   you entered correct pass word :) ";
	     cout<<"\n   --> press enter to delete all contents ";
	     getch();
	     ofstream out;
	     out.open("PATIENT",ios::out);
	    }
	    else
	    {
	     textcolor(WHITE);
	     cputs("\n\n    WRONG PASSWORD . Press any key to continue ");
	     getch();
	     Pmenu();
	    }

 default : cout<<"\n enter a valid choice !!";
    }
}

/******************************************************
*
*  Function EMENU() to manage the flow of control
*  in the Employee field
*
*******************************************************/
void emenu()
{
 clrscr();
 char ch;
 char pass[20];
 date();
 gotoxy(3,2);
 textcolor(WHITE);
 cprintf("EMPLOYEE DATABASE SIMULATION");
 gotoxy(2,4);
 cout<<"========================================================";
 gotoxy(3,7);
 cout<<"1. Recruit an EMPLOYEE ";
 gotoxy(3,9);
 cout<<"2. Display all EMPLOYEES ";
 gotoxy(3,11);
 cout<<"3. Search and display an EMPLOYEE record ";
 gotoxy(3,13);
 cout<<"4. Search and remove an EMPLOYEE";
 gotoxy(3,15);
 cout<<"5. salary calculator";
 gotoxy(3,17);
 cout<<"6. go back to main menu ";
 gotoxy(3,19);
 cout<<"D. delete all records | disk clean-up";
 gotoxy(3,21);
 cout<<"E. press E to exit from the program";
 gotoxy(3,24);
 textcolor(WHITE);
 cout<<"please select any one of the above option :";
 gotoxy(44,24);
 cin>>ch;
 switch(ch)
 {
  case '1': clrscr();
	    ewrite();
	    break;

  case '2': clrscr();
	    showalle ();
	    break;

  case '3': clrscr();
	    searche();
	    break;

  case '4': clrscr();
	    edelete();
	    break;

  case '5': clrscr();
	    e.paysal();
	    break;

  case '6': clrscr();
	    MAIN();
	    break;

  case 'E': clrscr();
	    {
	     char c;
	     gotoxy(10,20);
	     cout<<"\n sure you want to EXIT [y\n] : ";
	     cin>>c;
	     if(c=='y'||c=='Y')
	     {
	      clrscr();
	      gotoxy(17,20);
	      textcolor(RED);
	      cputs(" exiting in     seconds");
	      gotoxy(29,20);
	      cout<<" 3 ";
	       sleep(1);
	      gotoxy(29,20);
	      cout<<" 2 ";
	       sleep(1);
	      gotoxy(29,20);
	      cout<<" 1 ";
	       sleep(1);
	       cout<<" 0 ";
	       exit(0);
	     }
	     break;
	    }

  case 'e':  clrscr();
	    {
	     char c;
	     gotoxy(10,20);
	     cout<<"sure you want to EXIT [y\n] : ";
	     cin>>c;
	     if(c=='y'||c=='Y')
	     {
	      clrscr();
	      gotoxy(17,20);
	      textcolor(RED);
	      cputs(" exiting in     seconds");
	      gotoxy(29,20);
	      cout<<" 3 ";
	       sleep(1);
	      gotoxy(29,20);
	      cout<<" 2 ";
	       sleep(1);
	      gotoxy(29,20);
	      cout<<" 1 ";
	       sleep(1);
	      gotoxy(29,20);
	      cout<<" 0 ";
	       exit(0);
	     }
	     break;
	    }

  case 'D': clrscr();
	    textcolor(WHITE);
	    gotoxy(5,10);
	    cout<<"enter administrator password :";
	    cin>>pass;
	    if(strcmp(pass,"2015palakmegha")==0)
	    {
	     cout<<"\n\n   you entered correct pass word :) ";
	     cout<<"\n   --> press enter to delete all contents ";
	     getch();
	     ofstream out;
	     out.open("EMPLOYEE.DAT",ios::out);
	    }
	    else
	    {
	     textcolor(WHITE);
	     cputs("\n\n    WRONG PASSWORD . Press any key to continue ");
	     getch();
	     emenu();
	    }

  case 'd':  clrscr();
	    textcolor(WHITE);
	    gotoxy(5,10);
	    cout<<"enter administrator password :";
	    cin>>pass;
	    if(strcmp(pass,"2015palakmegha")==0)
	    {
	     cout<<"\n\n   you entered correct pass word :) ";
	     cout<<"\n   --> press enter to delete all contents ";
	     getch();
	     ofstream out;
	     out.open("EMPLOYEE.DAT",ios::out);
	    }
	    else
	    {
	     textcolor(WHITE);
	     cputs("\n\n    WRONG PASSWORD . Press any key to continue ");
	     getch();
	     emenu();
	    }

  default : cout<<"\n enter a valid choice !!";
 }
}

/******************************************************
*
*  Function 222
PAYSAL() to pay monthly salary to any
*  employee and save this information in a file.
*
*******************************************************/
void employee::paysal()
{
 int ID;
 clrscr();
 date();
 gotoxy(3,2);
 textcolor(LIGHTGRAY);
 cputs("SAVE SALARY RECORD");
 gotoxy(2,4);
 cout<<"==================================================================";
 gotoxy(3,6);
 textcolor(LIGHTGRAY);
 cout<<"NOTE : You will be sent back to previous menu is record is NOT found.";
 cout<<"\n\n  Enter the provided employee ID : ";
 cin>> ID;
 ifstream f1;
 f1.open("EMPLOYEE.DAT",ios::in|ios::binary);
 while(!f1.eof())
 {
    f1.read((char*)&e,sizeof(e));
    if(f1.eof())
     break;
    if(ID==eid)
     {
       cout<<"\n\n Employee Name    : "<<name;
       cout<<"\n Category    : "<<category;
       float months=0;
       cout<<"\n\n Monthly Salary : "<< esal;
       cout<<"\n\n Enter number of months to calculate salary : ";
       cin>> months;
       float amount=months*esal;
       cout<<"\n  Current payable amount for "<<months<<" months";
       cout<<" is Rs. "<< amount;
       getch();
       ofstream f2;
       f2.open("SALARY.DAT",ios::app|ios::binary);
       int d1, m1, y1 ;
       struct date d;
       getdate(&d); //Inbuilt function to display current date of the system
       d1 = d.da_day ;
       m1 = d.da_mon ;
       y1 = d.da_year ;
       f2<<name<<" was paid with Rs. "<<amount<<" on ";
       f2<<d1<<"/"<<m1 <<"/" <<y1<<" for "<<months<<" month(s)\n" ;
       f2.close();
       cout<<endl<<name<<" was paid with Rs. "<<amount<<" on ";
       cout<<d1<<"/"<<m1 <<"/" <<y1<<" for "<<months<<" month(s)\n" ;
     }
    else
     {
       cout<<"\n\n Employee ID does not exists. \n Press any key to proceed ";
       getch();
       MAIN();
     }
 }
 f1.close();
 emenu();
}

/******************************************************
*
*  Function PAYBILL() to save bill information
*  for one or more PATIENT
*
*******************************************************/
void patient::paybill()
{
   clrscr();
   date();
   long ID;
   int flag=0;
   gotoxy(3,2);
   textcolor(WHITE);
   cout<<"PATIENT'S INVOICE";
   gotoxy(2,4);
   cout<<"============================================================";
   char choice;
   clrscr();
   gotoxy(3,6);
   cout<<"Enter the Patient ID  : ";
   cin>> ID;
   ifstream f2;
   f2.open("PATIENT",ios::in|ios::binary);
   while(!f2.eof())
   {
      f2.read((char*)&p,sizeof(p));
      if(ID==pid)
      {
	cout<<endl<<endl;
	char choice1, choice2;
	cout<<" The no. of days stay(ed) are :"<<pstay;
	voice=prc*pstay;     // Calculating Payable amount
	cout<<"\n "<<name<<" is currently billed with : Rs.";
	cout<< setprecision(2)<< voice;
	getch();
	cout<<"\n\n  Would you like to see full record of this patient [Y or N] : ";
	cin>>choice1;
	if(choice1=='Y'||choice1=='y')
	 {
	   showp();
	 }
	cout<<" \n Would you like to save this bill? [Y/N] : ";
	cin>>choice2;
	if(choice2=='Y'||choice2=='y')
	{
	 ofstream f1;
	 f1.open("BILL.DAT",ios::app|ios::binary);
	 f1<<"Registered Bill for "<<name<< " PID ["<< pid << "] is Rs. "<<setprecision(2);
	 f1<< voice <<endl<<endl;
	 f1.close();
	 cout<<"BILL is saved. Press any key to proceed !";
	 getch();
	}
	flag++;
      }
      if(flag==0)
      {
	cout<<"\n\n  No such record was found!";
	cout<<"\n  Press ANY key to Proceed ";
	getch();
      }

   }
 f2.close();
 Pmenu();
}
// MAIN function of thw software program
void MAIN()
{
  clrscr();
  gotoxy(3,2);
  textcolor(LIGHTBLUE);
  cprintf("MAIN MENU FOR HOSPITAL MANAGEMENT CONSOLE");
  gotoxy(3,3);
  cprintf("Select a field to work upon");
  gotoxy(2,5);
  cputs("============================================================");
  gotoxy(3,7);
  cout<< "1. Patient Database Simulation";
  gotoxy(3,8);
  cout<< "2. Employee Database Management";
  gotoxy(3,9);
  cout<< "E. Exit from the Console";
  char ch;
  cout<<"\n\n\n  Enter your choice : ";
  cin>>ch;
  switch(ch)
  {
    case '1': Pmenu();
	      break;

    case '2': emenu();
	      break;

    case 'e': exit(0);

    case 'E': exit(0);

    default : MAIN();
  }
  MAIN();
}

void main()
{
 clrscr();
 loader();
 DETAILS();
 MAIN();
}

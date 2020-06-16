#include<conio.h>
#include<iostream.h>
#include<stdio.h>
#include<string.h>
//Database Modelling

struct airstat
{
 char serno[5];
 char time1[6];
 char cit1[39];
 char time2[6];
 char cit2[39];
};

struct day
{
 airstat a[3];
};
day A[2];

void getdata(day &A)
{
 for(int o=0;o<3;o++)
{
 cout<<"\t"<<"Flight status entry"<<o+1<<"\n";
 cout<<"serno"<<"\t";gets(A.a[o].serno);
 cout<<"time1"<<"\t";gets(A.a[o].time1);
 cout<<"cit1"<<"\t";gets(A.a[o].cit1);
 cout<<"time2"<<"\t"; gets(A.a[o].time2);
 cout<<"cit2"<<"\t"; gets(A.a[o].cit2);
}
}

struct ticket
{
 char dtu[6];
 int dayu;
 int n;
 char email[89];
 char plac1[39];
 char plac2[39];
 char sernou[5];
 int availseats;
 int m;
};
ticket t[200];


void getticket(int ctr)
{
 cout<<"Enter Booking day&date";cin>>t[ctr].dayu;
 cin>>t[ctr].dtu;
 cout<<"Enter from Where to where";cin>>t[ctr].plac1;
 cin>>t[ctr].plac2;
 int i=0;
 do
 {
  if ((strcmp(t[ctr].plac1,A[t[ctr].dayu].a[i].cit1)==0)&&(strcmp(t[ctr].plac2,A[t[ctr].dayu].a[i].cit2)==0))
  {
    cout<<"Expected fligths are:";
    cout<<"serno"<<"\t";puts(A[t[ctr].dayu].a[i].serno);
    cout<<"time1"<<"\t";puts(A[t[ctr].dayu].a[i].time1);
    cout<<"time2"<<"\t"; puts(A[t[ctr].dayu].a[i].time2);
  }
  i++;
  }while(i<3);
cout<<"if you want to select flight press 4";cin>>t[ctr].m;
if(t[ctr].m==4)
 {
  cout<<"Please enter flight serial no.";
  cin >>t[ctr].sernou;
  char email[87];
  cout<<"Enter No.of Passengers<10 &email address";cin>>t[ctr].n;
  gets(email);
 }
}

void main()
{
 clrscr();
 for(int days=0;days<2;days++)
 {
  cout<<"day="<<days;
  getdata(A[days]);
 }

 clrscr();

 int choice,i=0;
do
 {
  int j;
   clrscr();
  cout<<"Welcome to ARS Press 1 to book:";
  cout<<"2 for booking history";
  cout<<"4 to exit";
  cin>>j;
  //program start
  if (j==1)
   {
    getticket (i);
    //limiter program activation
   if(t[i].m==4)
   {
 if (i!=0)
{

if((strcmp(t[i-1].dtu,t[i].dtu)==0)&&(strcmp(t[i-1].sernou,t[i].sernou)==0))
{
if (i-1==0)
{
cout<<"available seats"<<10-t[0].n<<"\n";
}
if(i-1!=0)
cout<<"available seats"<<t[i-1].availseats<<"\n";
}


int count=1;int limit=0;int s;int re;
 for(int m=0;m<=i-1;m++)
{
 if((strcmp(t[m].dtu,t[i].dtu)==0)&&(strcmp(t[m].sernou,t[i].sernou)==0))
{

 if(count==1)
{
 s=t[m].n+t[i].n;
}
if(count>1)
{
 re=t[m].n+s;
 limit=limit+re;
}
count++;
}
}


if((limit>10)||(s>10))
{
 i=i-1;
 cout<<"Sorry req plane is full:";
 }
else
 {
  cout<<"Thanks for booking";
  if(count==2)
t[i].availseats=10-s;
 else
t[i].availseats=10-limit;
if(count==1)
t[i].availseats=10-t[i].n;
}

}//termination of (i!=j)
i++;}
}//termination of(j==1)
//limiter program termination

if(j==2)
{char sernouu[5];char dtuu[6];char place1[39];
char place2[39];int dayuu;int s=0;
int choice2;
cout<<"enter day of searching history"<<"\t";;cin>>dayuu;
cout<<"enter source  for which data needed"<<"\t";;gets(place1);
cout<<"enter destination  for which data needed"<<"\t";;gets(place2);

do
 {
  if ((strcmp(place1,A[dayuu].a[s].cit1)==0)&&(strcmp(place2,A[dayuu].a[s].cit2)==0))
  {
    cout<<"Expected fligths are:";
    cout<<"serno"<<"\t";puts(A[dayuu].a[s].serno);
  }
  s++;
  }while(s<3);
do{int sum=0;int o=0;
cout<<"enter serno";gets(sernouu);
cout<<"enter dt";gets(dtuu);
  do{
  if((strcmp(sernouu,t[o].sernou)==0)&&(strcmp(dtuu,t[o].dtu)==0))
   {
    sum=sum+t[o].n;
   }
   o++;
   }while(o<i);
cout<<"serno of queried plane"<<"\t";puts(sernouu);
cout<<"search date of queried plane"<<"\t";puts(dtuu);
cout<<"booked tickets"<<"\t"<<sum<<"\n";
cout<<"enter 5 for searching history for other flight";cin>>choice2;
}while(choice2==5);
}

cout<<"To return to main menu press 3 press integer to exit";
cin>>choice;
}while(choice==3);
	getch();
}











































































































































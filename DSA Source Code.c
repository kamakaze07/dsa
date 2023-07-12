#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<math.h>
#include<time.h>
#include<stdbool.h>
#define MAX 80

struct details
{
	char Name[MAX];
	char Gender[MAX];
	int Age;
	char Phone[MAX];
	struct details *link;
};
typedef struct details *NODE;
struct user
{
	char name[MAX];
	char dob[10];
	char phno[10];
	char pass[MAX];
	struct user *link;
};
typedef struct user* USER_NODE;
struct ticket
{
	int pnr;
	char trn_name[MAX];
	char trn_no[MAX];
	char tr_date[10];
	int np;
	struct ticket *link;
};
typedef struct ticket* TICKET_NODE; 

#define MALLOC(p,s,t)\
	p=(t)malloc(s);\
	if(p==NULL)\
	{\
		printf("Insufficient Memory.\n");\
		exit;\
	}

char name[MAX];
char gen[MAX];
int age;
char ph[MAX];
int SL,Third,Second,First;
char source[MAX],dest[MAX],tname[MAX],tno[MAX],cla[MAX],dur[MAX],date[12];
char berth[5];
int sno[MAX];
int amount,n,PNR;
float arr,depart;
char uname[MAX],dob[10],uph[10],upass[MAX],h;

TICKET_NODE ban(TICKET_NODE);

TICKET_NODE ban_hyd(TICKET_NODE);

void ReadData();
NODE InsFront(NODE,int);
void ticket(NODE,int);
NODE passdata(int,NODE);
int calc(int,int,int,int,int);
void seat(int);
void coach();
void starting_display(void);
void payment(void);
USER_NODE user(USER_NODE);
USER_NODE create(USER_NODE);
bool login(USER_NODE);
TICKET_NODE cancel(TICKET_NODE);
TICKET_NODE disp(TICKET_NODE);
TICKET_NODE trn_ticket(TICKET_NODE,int);
TICKET_NODE book(TICKET_NODE);

void main()
{
	USER_NODE First=NULL;
	TICKET_NODE ti=NULL;
	char g,u;
	int choice,done=0;
	starting_display();
	g:First=user(First);
	printf("\n\n\n");
	getchar();
	while(!done)
	{
		printf("1.Book Ticket\t2.Cancel Ticket\t\t3.Display Ticket\t4.Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:system("cls");
			ti=book(ti);
			break;
			case 2:ti=cancel(ti);
			break;
			case 3:ti=disp(ti);
			break;
			case 4:done=1;
			break;
			default:printf("Invalid choice.\n");
			break;
		}
	}
	return;
}
TICKET_NODE book(TICKET_NODE ti)
{
	char q;
	getchar();
	q:printf("Source:");
	gets(source);
	if(strcmp(strlwr(source),"bengaluru")==0)
	{
		ti=ban(ti);
		return ti;
	}
	else
	{
		printf("Enter Valid Station.\n");
		goto q;
	}
}
void starting_display(void)
{
	printf("\n\n\n\n\n\n\t\t\t\t\t");
	int i=0;
	while(i++<70)
		putchar('-');
	printf("\n\t\t\t\t\t|");
	i=0;while(i++<68)printf(" ");
	putchar('|');
	printf("\n\t\t\t\t\t|");
	printf("\tWELCOME TO IRCTC RAILWAY RESERVATION SYSTEM SIMULATION");
	clock_t start1=clock();
			while(clock()<start1+1000);//this is a clock() function which halts program for 1000ms
	i=0;
	while(i++<6)printf(" ");printf(" |");
	printf("\n\t\t\t\t\t|");
	i=0;while(i++<68)printf(" ");
	printf("|");
	printf("\n\t\t\t\t\t|\t\t----------MADE BY-----------");
	i=0;while(i++<25)printf(" ");printf("|");
	const char* array[]={
		"MUSTHAFFA","SOHAN JAGTAP","RAJA SAGAR","SATYAM","RUMAN","SUDHANSHU","HARSH","SHASHANK"
	};
	i=0;
	while(i<8)
	{
			clock_t start=clock();
			while(clock()<start+700);
				printf("\n\t\t\t\t\t|");
				printf("\t\t\t%s",array[i]);
				int a=0;while(a++<(45-strlen(array[i])))printf(" ");putchar('|');
			i++;
	}
	printf("\n\t\t\t\t\t");
	 i=0;
	while(i++<70)
		putchar('-');
	printf("\n\n\t\t\t\tPlease type the project password:\t");
	int k;
	while(scanf("%d",&k)==1)
	{
		if(k==786)
			break;
		printf("\n\t\t\t\tWrong password!! Type again:\t");
	}
	system("cls");//clears the display screen
	
}
USER_NODE user(USER_NODE First)
{
	char c;
	bool find;
	c:printf("\nChoose any one of the following:\t");
	printf("\n\n1.New user\t2.login\t\t3.exit\n");
	int n;scanf("%d",&n);
	switch(n)
	{
		case 1:First=create(First);find=true;break;
		case 2:find=login(First);break;
		case 3:exit(0);
		default:("Please choose the right option\n");goto c;
	}
	if(find==false)
		goto c;
	return First;
}
USER_NODE create(USER_NODE first)
{
	USER_NODE curr=first;
	if(first==NULL)
	{
		first=(USER_NODE)malloc(sizeof(struct user));
		printf("this is the first user\n");
		printf("\nType the username:\t");
		scanf("%s",first->name);
		printf("\nType the phone number:\t");
		scanf("%s",first->phno);
		printf("\nType the the date of birth:\t");
		scanf("%s",first->dob);
		printf("\nType the password:\t");
		scanf("%s",first->pass);
		first->link=NULL;
		printf("\n\n\t\tWElCOME\t%s",first->name);
		return first;
	}
	while((curr->link)!=NULL){
		printf("HELLO");
		curr=curr->link;}//this searches till the last of the linked list
		USER_NODE temp=NULL;
		MALLOC(temp,sizeof(struct user),USER_NODE);
		printf("\nType the username:\t");
		scanf("%s",temp->name);
		printf("\nType the phone number:\t");
		scanf("%s",temp->phno);
		printf("\nType the the date of birth:\t");
		scanf("%s",temp->dob);
		printf("\nType the password:\t");
		scanf("%s",temp->pass);
		temp->link=NULL;
		curr->link=temp;
		printf("\n\n\t\tWelcome!!\t%s \n",temp->name);
		getchar();
	return first;
}
bool login(USER_NODE first)//this function can return true or false based on the fact that user was found or not
{
	if(first==NULL)
	{
		printf("\n\tThere is no existing user present\n");
		return false;//NO user was find;
	}
	printf("\nType the username:\t");
	char username[30];scanf("%s",username);
	USER_NODE curr=first;
	while(curr!=NULL&&strcmp(curr->name,username))
		curr=curr->link;
	if(curr==NULL)
	{
		printf("\n There is no person with this name in our list\n");
		return false;
	}
	printf("\nType your password");
	char password[MAX];scanf("%s",password);
	while(strcmp(password,curr->pass))
	{
		printf("\n\tTry again\n");
		scanf("%s",password);
	}
	return true;
}
TICKET_NODE ban(TICKET_NODE ti)
{
	char q;
	q:printf("Destination:");
	gets(dest);
	if(strcmp(strlwr(dest),"hyderabad")==0)
	{
		printf("Date:");
		gets(date);
		ti=ban_hyd(ti);
		return ti;
	}
	else
	{
		printf("Enter Valid Station.\n");
		goto q;
	}
}
//Bangalore to Hyderabad
TICKET_NODE ban_hyd(TICKET_NODE ti)
{
	int z,y;
	char q;
	NODE fi=NULL;
	time_t t;
	srand((unsigned) time(&t));
	q:printf("\nTrain Number\tSource\t\t Destination\t\t Train Name\t Departure\t Arrival\tDuration\n");
	printf("17604\t\tYelahanka(YNK)\t Kacheguda(KCG)\t\t YNK KCG EXP\t 16.20\t\t 5.00\t\t12hr40min\n");
	printf("12786\t\tBengaluru(SBC)\t Kacheguda(KCG)\t\t Kacheguda EXP\t 18.20\t\t 5.40\t\t11hr20min\n");
	printf("22691\t\tBengaluru(SBC))\t Secundrabad Jn(SC)\t RAJDHANI EXP\t 20.00\t\t 7.05\t\t11hr5min\n");
	printf("\nEnter train number:");
	scanf("%d",&z);//enter train number
	switch(z)
	{
		case 17604:printf("\nFare Chart:\n");
					printf("SL:365/-\t3A:990/-\t2A:1410/-\t1A:2360\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Yelahanka Jn(YNK)");
					strcpy(dest,"Kacheguda(KCG)");
					strcpy(tname,"YNK KCG EXP");
					strcpy(tno,"17604");
					strcpy(dur,"12hr40min");
					depart=16.20;
					arr=5.00;
					fi=passdata(n,fi);
					SL=365;
					Third=990;
					Second=1410;
					First=2360;
					PNR=(rand()%89999)+10000;
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
					ti=trn_ticket(ti,n);
				   break;
		case 12786:printf("\nFare Chart:\n");
					printf("SL:385/-\t3A:1005/-\t2A:1415/-\t1A:2360\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Krantivira Sangoli Rayanna(SBC)");
					strcpy(dest,"Kacheguda(KCG)");
					strcpy(tname,"KACHEGUDA EXP");
					strcpy(tno,"12786");
					strcpy(dur,"11hr20min");
					depart=18.20;
					arr=5.40;
					fi=passdata(n,fi);
					SL=385;
					Third=1005;
					Second=1415;
					First=2360;
					PNR=(rand()%89999)+10000;
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
					ti=trn_ticket(ti,n);
			       break;
		case 22691:printf("\nFare Chart:\n");
					printf("3A:1790/-\t2A:2100/-\t1A:3190\n");
					printf("To select another train, press 1\n");
					printf("To continue with booking, press 2\n");
					scanf("%d",&y);
					if(y==1)
						goto q;
					printf("\nEnter number of passengers:");
					scanf("%d",&n);
					strcpy(source,"Krantivira Sangoli Rayanna(SBC)");
					strcpy(dest,"Secundrabad Jn(SC)");
					strcpy(tname,"RAJDHANI EXP");
					strcpy(tno,"22691");
					strcpy(dur,"11hr5min");
					depart=20.00;
					arr=7.05;
					fi=passdata(n,fi);
					SL=0;//No SL Class Coach
					Third=1790;
					Second=2100;
					First=3190;
					PNR=(rand()%89999)+10000;
					amount=calc(SL,Third,Second,First,n);
					ticket(fi,n);
					ti=trn_ticket(ti,n);
			       break;
		default:printf("Enter valid Train Number.\n");
		goto q;
		break;
	}
	return ti;	
}
TICKET_NODE trn_ticket(TICKET_NODE ti,int p)
{
	TICKET_NODE temp=NULL;
	MALLOC(temp,sizeof(struct ticket),TICKET_NODE);
	temp->link=NULL;
	temp->pnr=PNR;
	strcpy(temp->trn_no,tno);
	strcpy(temp->trn_name,tname);
	strcpy(temp->tr_date,date);
	temp->np=p;
	if(ti==NULL)
		return temp;
	else
	{
		temp->link=ti;
		return temp;
	}
	
}
TICKET_NODE cancel(TICKET_NODE ti)
{
	int t;
	TICKET_NODE cur,prev;
	cur=prev=NULL;
	if(ti==NULL)
	{
		printf("No ticket booked yet.\n");
		return ti;
	}
	else
	{
		printf("Enter PNR number:");
		scanf("%d",&t);
		cur=ti;
		if(cur->link==NULL && cur->pnr==t)
		{
			free(cur);
			printf("Ticket has been canceled.\n");
			return NULL;
		}
		while(cur && cur->pnr!=t)
		{
			prev=cur;
			cur=prev->link;
		}
		if(cur==NULL)
		{
			printf("No ticket found with the PNR number.\n");
			return ti;
		}
		else
		{
			prev->link=cur->link;
			free(cur);
			printf("Your ticket has been canceled.\n");
			return ti;
		}
	}
}
TICKET_NODE disp(TICKET_NODE ti)
{
	int i=1;
	TICKET_NODE cur=NULL;
	if(ti==NULL)
	{
		printf("No upcoming ticktes.\n");
		return ti;
	}
	else
	{
		cur=ti;
		printf("Upcoming tickets are:\n");
		while(cur)
		{
			printf("\nTicket %d\n",i);
			printf("\nPNR:%d\nTrain Name:%s\nTrain Number:%s\nTravel Date:%s\nNumber of passengers:%d\n\n\n",cur->pnr,cur->trn_name,cur->trn_no,cur->tr_date,cur->np);
			cur=cur->link;
			i++;
		}
	}
	return ti;
}
NODE passdata(int m,NODE t)
{
	int i;
	for(i=1;i<=m;i++)
		{
	   		printf("\nEnter Passenger %d details:\n",i);
	   		ReadData();
	   		t=InsFront(t,m);
	   }
	   return t;
}
//Reading Passenger Details
void ReadData()
{
	printf("Enter Name:\n");
	getchar();
	gets(name);
	printf("Enter Gender:\n");
	scanf("%s",gen);
	printf("Enter Age:\n");
	scanf("%d",&age);
	printf("Enter Phone Number:\n");
	scanf("%s",ph);
}
NODE InsFront(NODE first,int y)
{
	NODE q=NULL;
	MALLOC(q,sizeof(struct details),NODE);
	strcpy(q->Name,name);
	strcpy(q->Gender,gen);
	q->Age=age;
	strcpy(q->Phone,ph);
	q->link=first;
	return q;
}
//Train Fare Calculation
int calc(int x1,int x2,int x3,int x4,int y)
{
	int d,h;
	printf("Select Class:\n");
	printf("1.SL\t2.3A\t3.2A\t4.1A\n");
	scanf("%d",&d);
	switch(d)
	{
		case 1:strcpy(cla,"SL");
				h=x1*y;
				payment();
				return h;
				
		case 2:strcpy(cla,"3A");
				h=x2*y;
				payment();
				return h;
				
		case 3:strcpy(cla,"2A");
				h=x3*y;
				payment();
				return h;
				
		case 4:strcpy(cla,"1A");
				h=x4*y;
				payment();
				return h;
			
		default:printf("Select valid Class.\n");
		break;
	}
}
//Seat Allotment
void seat(int p)
{
	time_t t;
	int i,x[MAX];
	srand((unsigned) time(&t));
	if(p<6)
	{
		for(i=0;i<p;i++)
			sno[i]=(rand()%25)+32;
	}	
	else
	{
		for(i=0;i<p;i++)
		sno[i]=(rand()%72)+1;
	}	
	for(i=0;i<p;i++)
		x[i]=sno[i]%8;
		printf("\nBerth:\t");
	for(i=0;i<n;i++)
	{
		if(x[i]==1||x[i]==4)
			printf("LB\t");//Lower Berth
		else if(x[i]==2||x[i]==5)
			printf("MB\t");//Middle Berth
		else if(x[i]==3||x[i]==6)
			printf("UB\t");//Upper Berth
		else if(x[i]==7)
			printf("SLB\t");//Side lower Berth
		else
			printf("SUB\t");//Side Upper Berth
	}
	printf("\n");
	printf("Seat No.:");
	for(i=0;i<n;i++)
	{
		printf("%d\t",sno[i]);
	}
	printf("\n");
	return;
}
//Ticket Payment
void payment(void)
{
	time_t t;
	srand((unsigned) time(&t));
	while(1){
	printf("\n\n\t\tPlease type the otp received on your mobile number:(wait 5 seconds)\t");
	int k=(rand()%8999)+1000;//rand() function with ranges to generate random otp
	clock_t start=clock();
			while(clock()<start+5000);//will receive otp in five seconds
	printf("\t\t\t\t\t\t|OTP--%d|\n",k);
	int y;
	printf("Enter OTP:");
	scanf("%d",&y);
	if(y==k){
		printf("\nYour payment is being processed\n");
		start=clock();
			while(clock()<start+2000);
		printf("\nYour payment was successful.\n");
		start=clock();
			while(clock()<start+2000);
		break;
	}
	printf("\nType again");
	continue;
	}
	return;
}
//Coach Allotment
void coach()
{
	int x;
	time_t t;
	srand((unsigned) time(&t));
	x=1+(rand()%12);
	printf("\nCoach:S%d\n",x);
}
//Final Ticket PrintOut
void ticket(NODE q,int p)
{
	int i;
	printf("\n**************************************************TICKET**************************************************\n");
	printf("\nSource\t\tDestination\t\tTrain Name\tTrain No.\tClass\n");
	printf("%s\t%s\t%s\t%s\t\t%s\n",source,dest,tname,tno,cla);
	printf("PNR:%d\n",PNR);
	printf("\nDate:%s\n",date);
	printf("\nDeparture\tArrival\t\tDuration\n");
	printf("%.2f\t\t%.2f\t\t%s\n",depart,arr,dur);
	printf("\nFare:%d\n",amount);
	clock_t start=clock();
			while(clock()<start+500);//it takes a little time to print the further ticket
	coach();
	seat(p);
	printf("\n");
	printf("\nPassenger Details:\n");
	start=clock();
			while(clock()<start+300);
	while(q)
	{
		printf("\nName:%s\nGender:%s\nAge:%d\nPhone Number:%s\n",q->Name,q->Gender,q->Age,q->Phone);
		q=q->link;
	}
	printf("\n\n*********************************************HAPPY JOURNEY*********************************************\n\n");
	printf("\n\n\n");
}

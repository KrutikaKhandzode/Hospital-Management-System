#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<fstream.h>
#include<iomanip.h>
#include<stdio.h>

int Count=0;
class PATIENT
{
	int Pno,Bno;
	char PName[10],Category[5];
	public:
	int flag;//1 if Admitted, 0 if Discharged
	int RPno()
	{	return Pno;	}
	char* RPName()
	{	return PName;	}
	void Input();
	void Output();
};

void PATIENT::Input()
{
	cout<<"Name: ";gets(PName);
	cout<<"Patient Number: ";cin>>Pno;
	cout<<"Bed Number: ";cin>>Bno;
	cout<<"Category:(IN/OUT) ";gets(Category);
	char ch;
	cout<<"Does the Patient have to be admitted?(y/n)";
	cin>>ch;
	if(ch=='y')
	flag=1;
	else
	flag=0;
	cout<<"Registered";
}

void PATIENT::Output()
{
	cout<<"NAME: "<<PName<<endl;
	cout<<"Patient No.: "<<Pno<<endl;
	cout<<"Bed No.: "<<Bno<<endl;
	cout<<"Category: "<<Category<<endl;
	cout<<"Status: ";
	if(flag==1)
	cout<<"Admitted"<<endl;
	else if(flag==0)
	cout<<"Discharged"<<endl;
}


const int Max=5;
const char VL=179,HL=196,TL=218,TR=191,BL=192,BR=217;
const char DVL=186,DHL=205,DTL=201,DTR=187,DBL=200,DBR=188;

void Color(int TC,int BC)//For Changing Text Color and Text Background
{
	textcolor(TC);
	textbackground(BC);
}

void ShowXY(int X,int Y,char CH)//Displays a character at X,Y position
{
	gotoxy(X,Y);
	cprintf("%c",CH);  //cout<<CH;
}

void ShowXY(int X,int Y,char CH[])//Displays a string at X,Y position
{
	gotoxy(X,Y);
	cprintf("%s",CH);  //cout<<CH;
}

void Vline(int X,int Y,int L)//To vertical line by joining vert. characters
{
	for (int i=Y;i<=Y+L;i++)
		ShowXY(X,i,VL);
}
void Hline(int X,int Y,int L)//To horizontal line by joining hor.characters
{
	for (int i=X;i<=X+L;i++)
		ShowXY(i,Y,HL);
}
void Recta(int C1,int R1,int C2,int R2)
{
	ShowXY(C1,R1,TL);             //
	ShowXY(C1,R2,BL);             //Placing corner characters
	ShowXY(C2,R1,TR);             //
	ShowXY(C2,R2,BR);             //
	Vline(C1,R1+1,R2-R1-2);       //
	Vline(C2,R1+1,R2-R1-2);       //Joining Corners by Vertical lines
	Hline(C1+1,R1,C2-C1-2);       //
	Hline(C1+1,R2,C2-C1-2);       //Joining Corners by Horizontal lines
}
void DVline(int X,int Y,int L)
{
	for (int i=Y;i<=Y+L;i++)
		ShowXY(X,i,DVL);
}
void DHline(int X,int Y,int L)
{
	for (int i=X;i<=X+L;i++)
		ShowXY(i,Y,DHL);
}
void DRecta(int C1,int R1,int C2,int R2)
{
	ShowXY(C1,R1,DTL);
	ShowXY(C1,R2,DBL);
	ShowXY(C2,R1,DTR);
	ShowXY(C2,R2,DBR);
	DVline(C1,R1+1,R2-R1-2);
	DVline(C2,R1+1,R2-R1-2);
	DHline(C1+1,R1,C2-C1-2);
	DHline(C1+1,R2,C2-C1-2);
}

//X,Y are coordinates for displaying menu
//Mnu all choices which required to be displayed as Menu Choices
//Noc no. of choices
int Vmenu(int X,int Y,char Mnu[][20],int Noc)
{
	Color(WHITE,BLUE);
	Recta(X,Y,X+strlen(Mnu[0])+1,Y+Noc+1);
	for (int i=0;i<Noc;i++)
		ShowXY(X+1,Y+i+1,Mnu[i]);

	int Sel=0,Exit=0;//Sel - Current Selected Option
				//Exit- Control Variable for loop
	do
	{
		int Tsel=Sel;    //To store the current selection in Tsel
		Color(BLUE,WHITE);
		ShowXY(X+1,Y+Sel+1,Mnu[Sel]);
		Color(WHITE,BLUE);
		char Cho=getch();
		//71:Home  72:Up   73:Pup   75:Left   77:Right  79:End  80:Dn 81:PD
		switch(Cho)
		{
		 case 71:Sel=0;break;
		 case 79:Sel=Noc-1;break;
		 case 72:if (Sel==0)
				 Sel=Noc-1;
			 else
				 Sel--;
			 break;
		 case 80:if (Sel==Noc-1)
				 Sel=0;
			 else
				 Sel++;
			 break;
		 case 13:Exit=1; //Enter Key
			 break;
		 case 27:Sel=-1; //Escape
			 Exit=1;
			 break;
		}
		ShowXY(X+1,Y+Tsel+1,Mnu[Tsel]);
	}
	while (!Exit);
	return Sel;
}

int Hmenu(int X,int Y,char Mnu[][20],int Noc)
{
	Color(WHITE,BLUE);
	for (int i=0;i<Noc;i++)
		ShowXY(X+15*i+1,Y,Mnu[i]);
	int Sel=0,Exit=0;
	do
	{
		int Tsel=Sel;    //To store the current selection in Tsel
		Color(BLUE,WHITE);
		ShowXY(X+15*Sel+1,Y,Mnu[Sel]);
		Color(WHITE,BLUE);
		char Cho=getch();
		//71:Home  72:Up   73:Pup   75:Left   77:Right  79:End  80:Dn 81:PD
		switch(Cho)
		{
		 case 71:Sel=0;break;
		 case 79:Sel=Noc-1;break;
		 case 75:if (Sel==0)
				 Sel=Noc-1;
			 else
				 Sel--;
			 break;
		 case 77:if (Sel==Noc-1)
				 Sel=0;
			 else
				 Sel++;
			 break;
		 case 13:Exit=1;
			 break;
		 case 27:Sel=-1;
			 Exit=1;
			 break;
		}
		ShowXY(X+15*Tsel+1,Y,Mnu[Tsel]);
	}
	while (!Exit);
	return Sel;
}

void ClearArea(int C1,int R1,int C2,int R2)
{
	window(C1,R1,C2,R2);
	clrscr();
	window(1,1,80,25);
}


void Home();
void Create();
void DisplayAll();
void Discharge();
void Register();
void Search();
void SearchPName();
void SearchPNumber();
void BillGeneration();
void Exit();

void main()
{
	clrscr();
	PATIENT P[50];
	char MainMenu[][20] = {
					"HOME     ",
					"REGISTER  ",
					"SEARCH   ",
					"DISCHARGE   ",
					"EXIT     "
				};

	int Ch;

      do
	{
		Color(WHITE,BLUE);
		clrscr();

		Ch = Hmenu(1,1,MainMenu,5);

		switch(Ch)
		{
			case 0:Home(); break;
			case 1:Register(); break;
			case 2:Search(); break;
			case 3:Discharge();
		}
	}while(Ch!=4);
}

void DisplayAll()
{
	fstream file;
	PATIENT P;
	file.open("Patient.dat",ios::binary|ios::in);
	while(file.read((char*)&P,sizeof(P)))
	{
		P.Output();
	}
	file.close();
}
void SearchPName()
{
	fstream file;
	PATIENT P;
	char Name[20];
	int Found=0;
	file.open("Patient.dat",ios::binary|ios::in);
	gotoxy(0,10);
	cout<<"Enter the Name of the Patient: ";
	gets(Name);
	while(file.read((char*)&P,sizeof(P)))
	{
		if(strcmpi(P.RPName(),Name)==0)
		{
			P.Output();
			Found++;
		}
	}
	if(Found==0)
	cout<<"Patient record not found"<<endl;
	file.close();
	getch();
}

void SearchPNumber()
{
	fstream file;
	PATIENT P;
	int Number;
	int Found=0;
	file.open("Patient.dat",ios::binary|ios::in);
	gotoxy(0,10);
	cout<<"Enter the Patient Number: ";
	cin>>Number;
	while(file.read((char*)&P,sizeof(P)))
	{
		if(P.RPno()==Number)
		{
			P.Output();
			Found++;
		}
	}
	if(Found==0)
	cout<<"Patient record not found"<<endl;
	file.close();
	getch();
}

void Discharge()
{
	fstream file;
	PATIENT P;
	int Number;
	file.open("Patient.dat",ios::binary|ios::in|ios::out);
	gotoxy(10,10);
	cout<<"Enter the Patient Number: ";
	cin>>Number;
	while(file.read((char*)&P,sizeof(P)))
	{
		if(P.RPno()==Number)
		P.flag=0;
	}
	file.close();
	Count--;
	BillGeneration();
}
void Home()
{
       ShowXY(5,5,"WELCOME TO CITY HOSPITAL");
       ShowXY(5,10,"Total Beds: 50");
       ShowXY(5,11,"Beds Occupied: ");
       cout<<Count;
       ShowXY(5,12,"Beds Available: ");
       cout<<(50-Count);
       cout<<"\nVIEW ALL PATIENT RECORDS?(Y/N)";
       char ch;
       cin>>ch;
       if (ch=='y'||ch=='Y')
       DisplayAll();
       getch();
}


void Register()
{
	fstream file;
	PATIENT P;
	gotoxy(10,10);
	file.open("Patient.dat",ios::binary|ios::app);
	P.Input();
	file.write((char*)&P,sizeof(P));
	if(P.flag==1)
	Count++;
	file.close();
	getch();
}

void Search()
{

  char SMenu[][20] = {
		      "By Patient's Name  " ,
		      "By Registration No." ,
		      };
	int Ch;
	Ch = Vmenu(32,3,SMenu,2);
	switch(Ch)
	{
		case 0: gotoxy(5,10);
			SearchPName(); break;
		case 1: gotoxy(5,10);
			SearchPNumber();
	}
}

void BillGeneration()
{
	int Days;
	gotoxy(0,10);
	cout<<"Enter the Duration of Stay(Days): ";
	cin>>Days;
	int RoomCharge=2500+(Days*500);
	cout<<"ROOM CHARGE [2500 + DAYS(PER DAY COST:Rs. 500)] = "<<RoomCharge<<endl;
	cout<<"DOCTORS FEES = 2000"<<endl;
	cout<<"NURSING FEES = 500"<<endl;
	cout<<"MEDICATION FEES = 1000"<<endl;
	cout<<"Tax = 13%"<<endl;
	cout<<"TOTAL BILL AMOUNT = "<<(RoomCharge+2000+500+1000)*1.13<<endl;
	getch();

}

void Exit()
{

}

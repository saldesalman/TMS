//whenver you have to select a choice on runtime enter capital choice to procced... 
// Libraries to be used
#include <iostream>
#include <stdlib.h>
#include<iomanip>
#include <fstream>
#include <conio.h>
#include <time.h>
#include <cstring>
using namespace std;


//User defined functions
void index();
void load();
void sign_up();
void signoff();
void sign_in();
void contactno();
void seats();
void morning();
void night();
void index2();
int booking(int[][10],int,int);
void account();
char temp1[20];
//Pessenger class
class pessenger{
	
	protected:
		
	char name[20];
	string pass;
	string cnic;
	string contact;
	
	public:
		pessenger()
		{
			name[20] = '\0';
			pass = "\0";
			cnic = "\0";
			contact = "\0";
		}
		fstream fp,mp;
		//function for getting data
		
		void getdata()
		{
			system("cls");
			system("Color 72");
			cout<<"\n\n\t\t\t\t\t....Welcome To Pakistan Railways...."<<endl;
			cout<<"\n\n\t\t\t\t---Fill Sign Up form to register and Move with us---"<<endl;
			cout<<"\nName:  ";
			cin>>name;
			
			cout<<"\nPassword:  ";
			cin>>pass;
			
			
			cout<<"\nCnic:  ";
			cin>>cnic;
			
			cout<<"\nContact:  ";
			cin>>contact;
		}
	
	//function for writing to file
		void write()
		{
			//in this method we are creating files at runtime with username.
			char fname[20];
			strcpy(fname,name);
			strcat(fname,".txt");
			int len=strlen(fname);
			fname[len+1]='\0';
			fp.open(fname,ios::app);
			fp<<name;
			fp<<endl;
			fp<<pass;
			fp<<endl;
			fp<<cnic;
			fp<<endl;
			fp<<contact;
			fp<<endl;
		}
};


//class train

class train{
	private:
		string *tname;
		string *typ;
		string *tclass;
		float *time;
	public:
	
		int tseats[2][10];
		train()
		{
			//information about trains we are storing information for two trains only.
			tname = new string[2];
			tclass = new string[2];
			typ = new string[2];
			
			
			tname[0] = "Morning Ride";
			tname[1] = "Night Coach";
			
			typ[0] = "Government";
			typ[1] = "Private";
			
			tclass[0] = "Bussiness and Economy";
			tclass[1] = "Ac sleeper and Economy";
			int j=0;
				for(j=0;j<10;j++)
				{
					tseats[0][j] = 1;
					tseats[1][j] = 1;
				}
			
			}
		ifstream t1,t2;
		ofstream seatstore;
		void view()
		{
			system("cls");
			system("color 70");
			cout<<"\n\n\n\t\t\t\t..TRAIN INFORMATION.."<<endl<<endl<<endl;
			t1.open("Morning.txt");
			t2.open("Night.txt");
			cout<<"Name\t\tType\t\tclass\t\t\t\tSeats"<<endl;
			int j=0;
			while(j<10)
			{
				t1 >> tseats[0][j];
				t2 >> tseats[1][j];
				j++;
			}
			
			j=0;
			int s1=0,s2=0;
			
				t1>>s1;
				t2>>s2;
				t1.close();
				t2.close();
				s1=0,s2=0;
			
				ifstream ta1,ta2;
				ta1.open("Morning.txt");
				ta2.open("Night.txt");
			j=0;	
			while(j<11)
			{
				ta1>>s1;
				ta2>>s2;
				if(j==10)
				{
					ta1 >>s1;
					break;
				}
				j++;
			}
				
			cout<<tname[0]<<"\t"<<typ[0]<<"\t"<<tclass[0]<<"\t\t"<<s1<<endl<<endl;
			cout<<tname[1]<<"\t"<<typ[1]<<"\t\t"<<tclass[1]<<"\t\t"<<s2<<endl;
			
			
			cout<<"\n\nPress Y to book ticket"<<endl;
			char c;
			
			c = getche();
			if(c=='Y')
			{
			ofstream fin;
			fin.open(temp1,ios::app); //to store seat number in file;
			int u = booking(tseats,s1,s2);
			system("pause");
			index2();
			}
			else
			{
				index2();
			}
		}
		void timings()
		{
			label1:
			system("cls");
			system("color 70");
			cout<<"\n\n\n\n\t\t\t\t..TIMINGS.."<<endl;
			char ch;
			cout<<"Press..\nA-Morning ride\nB-Night Coach"<<endl;
			ch = getche();
			
			switch(ch)
			{
				case 'A':
					morning();
					break;
				case 'B':
					night();
					break;
				default:
					goto label1;
			}
		}
		virtual void cancel(); //concept of abstract func implemented.
};

		
//inheritance
class home: public pessenger,public train{
	public:
		
		void welcome()
		{
			label2:
			system("cls");
			cout<<"\n\n\t\t\t\t\t....Welcome To Pakistan Railways...."<<endl;
			cout<<endl<<endl<<endl;
			cout<<"\t\t\tA-My Account \t\t V-View seats & Book\t T-View time \n"<<endl;
			cout<<"\t\t\tX-Cancel Ticket          L-Sign off\tC-Contact us\n"<<endl;
			
			char ch;
			
			cout<<"Press your choice"<<endl;
			ch = getche();
			
			switch(ch)
			{
				case 'A':
					account();
					break;
				case 'X':
					cancel();
					break;
				case 'L':
					signoff();
					break;
				case 'V':
					view();
					break;
				case 'T':
					timings();
				case 'C':
						contactno();
					break;
				default:
					goto label2;
			}
		}
		
		
};
void train::cancel() // concept of inline function implementd.
{
	label5:
	system("cls");
	system("color 70");
	cout<<"\n\n\t\t\t\t\t....Welcome To Pakistan Railways...."<<endl;
	int snum,a[11],i=0;
	char tnum;
	
	cout<<"Enter train initial"<<endl;
	cout<<"M- Morning Ride"<<endl;
	cout<<"N- Night coach"<<endl;
	tnum = getche();
	
	cout<<"\nEnter seat number to cancel"<<endl;
	cin>>snum;
	snum--; //to get equal to the positon in file.
	if(tnum == 'M')
	{
		ifstream in;
		in.open("Morning.txt");
		while(i<10)
		{
			in>>a[i];
			i++;
		}
		i=0;
		while(i<10)
		{
			if(i==snum)
			{
				if(a[i]==1)
				{
					cout<<"Seat not booked "<<endl;
					
		
				}
				else
				{
					a[i] = 1;
					int j=0,c=0;
		ofstream f;
		f.open("Morning.txt");
		while(j<10)
		{
			if(a[j]==1)
			{
				c++;
			}
			f<<a[j];
			f<<endl;
			j++;
		}
		a[j+1] = c;
		f<<a[j+1];			
		cout<<"Seat is vacant for now"<<endl;
				}
			}
			i++;
		}
	}
	else if(tnum=='N') {
		ifstream in;
		in.open("Night.txt");
		while(i<10)
		{
			in>>a[i];
			i++;
		}
		i=0;
		while(i<10)
		{
			if(i==snum)
			{
				if(a[i]==1)
				{
					cout<<"Seat not booked "<<endl;
					i=0;
				}
				else
				{
					a[i] = 1;
					cout<<"Seat is vacant for now"<<endl;
					ofstream f;
		f.open("Night.txt");
		int j=0,c=0;
		while(j<10)
		{
			if(a[j]==1)
		{
		c++;
		}
			f<<a[j];
			f<<endl;
			j++;
		}
		a[j+1] = c;
		f<<a[j+1];
				}
			}
		i++;
		}
		
	}
	else
	{
		goto label5;
	}
	system("pause");
	index2();
}
//main 
int main()
{
	index();
}



//home page
void index()
{
	label:
	system("color 72");
	cout<<"\n\n\t\t\t\t\t....Welcome To Pakistan Railways...."<<endl;
	
	cout<<"\n\n\t\tA-Sign in"<<endl;
	cout<<"\n\n\t\tB-Sign up"<<endl;
	char ch;
	cout<<"\n\nPress choice"<<endl;
	ch=getche();
	
	//checking for choice
	switch(ch)
	{
		case 'A':
			sign_in();
			break;
		case 'B':
			sign_up();
			break;
		default:
			system("cls");
		goto label;	
	}
}


void load(){
    int row,col,r,c,q;
    system("color 70");
    cout<<"\n\t\t\t\t\tA little Patience Please...."<<endl;
    cout<<"\n\n\n\t\t\t\t\t";
	cout<<"loading...";
    for(r=1;r<=20;r++){
    	
    for(q=0;q<=10000000;q++);
	{
	//to display the character slowly
	}
	cout<<(char)177;
    }
}
void index2()
{
	home h1;
	h1.welcome();
}
void sign_in()
{
	system("cls");
	system("color 72");
	cout<<"\n\n\t\t\t\t\t....Welcome To Pakistan Railways...."<<endl;
	cout<<endl<<endl<<endl;
	string name,pass,hold;
	ifstream fin;
	cout<<"Username: ";
	cin>>name;
	cout<<endl<<"Password: ";
	cin>>pass;
	int i=0;
	while(name[i]!='\0')
	{
		temp1[i] = name[i];
		i++;
	}
	
	strcat(temp1,".txt");
	temp1[strlen(temp1)] = '\0';
	fin.open(temp1);
	
	if(fin==NULL)
{
	cout<<"Kindly Check Your User name and pass again you are not registered "<<endl;
}
else
{
	int off,c=0;
	while(!fin.eof())
	{
		getline(fin,hold);
		if((off = hold.find(name,0))!= string::npos)
		{
			c++;
		}
		
		getline(fin,hold);
		if((off = hold.find(pass,0))!= string::npos)
		{
			c++;
		}
	}
	if(c==2)
	{
		system("cls");
		cout<<"\n\n\n\t\t\tHave a breath until we Connect You!..."<<endl;
		load();
		index2();
	}
	else
	{
		system("cls");
		cout<<"\n\n\n\t\t\tHave a breath until we Connect You!..."<<endl;
		cout<<"\n\n\t\t\tSorry You are not register with Us"<<endl;
	}
}

}

void sign_up()
{
	system("cls");
	load();
	home h1;
	h1.getdata();
	h1.write();
	        system("cls");
			cout<<"\n\n\n\n\t\t\t...THANK YOU!!! for Choosing to travel with us..."<<endl<<endl;
			cout<<"\t\t\tHave a breath until we register You!..."<<endl;
	sign_in();
}

void signoff()
		{
			system("cls");
			system("color 70");
			cout<<"\n\n\n\n\t\t\t.....Have a good day....."<<endl;
			cout<<"\n\t\t\t\t..Thankyou!!!"<<endl;
			cout<<"\n\t\t\t\tUnofficial Work of Pakistan Railways"<<endl;
		}
		
		void contactno()
		{
			label3:
			system("cls");
			system("color 70");
			cout<<"\n\n\n\t\t\tContact us"<<endl;
			cout<<"\nPhone Number : 117"<<endl;
			cout<<"\nEmail at www.pakrail.com"<<endl;
			char ch;
			cout<<"\n\nPress E to exit"<<endl;
			ch=getche();
			
			if(ch=='E' || ch=='e')
			{
				system("cls");
				load();
				home h1;
				h1.welcome();
			}
			else
			{
				goto label3;
			}
		}
		
void morning()
{
	system("cls");
	system("color 07");
	cout<<"\n\n\n\n\t\t\t\t..TIMINGS.."<<endl;
	cout<<"\t\t\tUP"<<endl;
	cout<<"\n\n\t\tStation 1 - 7:00AM Start"<<endl;
	cout<<"\n\n\t\tStation 2 - 11:00AM Stop"<<endl;
	cout<<"\n\n\t\tStation 3 - 3:00PM Destination"<<endl;		
	
	cout<<"\t\t\tDown"<<endl;
	cout<<"\n\n\t\tStation 3 - 5:50PM Start"<<endl;
	cout<<"\n\n\t\tStation 2 - 9:00PM Stop"<<endl;
	cout<<"\n\n\t\tStation 1 - 12:30AM Destination"<<endl;		
	
	cout<<"\n\n\nPress Y from checking seats\n";
	char c = getche();
	if(c=='Y')
	{
		train t1;
		t1.view();
	}
	else
	{
		home h1;
		h1.welcome();
	}
}


void night()
{
	system("cls");
	system("color 07");
	cout<<"\n\n\n\n\t\t\t\t..TIMINGS.."<<endl;
	cout<<"\t\t\tUP"<<endl;
	cout<<"\n\n\t\tStation 1 - 11:55PM Start"<<endl;
	cout<<"\n\n\t\tStation 2 - 4:00AM Stop"<<endl;
	cout<<"\n\n\t\tStation 3 - 9:00AM Destination"<<endl;		
	
	cout<<"\t\t\tDown"<<endl;
	cout<<"\n\n\t\tStation 3 - 11:00AM Start"<<endl;
	cout<<"\n\n\t\tStation 2 - 3:00PM Stop"<<endl;
	cout<<"\n\n\t\tStation 1 - 7:30AM Destination"<<endl;		
	
	cout<<"\n\n\nPress Y from checking seats\n";
	char c = getche();
	if(c=='Y')
	{
		train t1;
		t1.view();
	}
	else
	{
		home h1;
		h1.welcome();
	}
}

int booking(int tseats[][10],int s1,int s2)
{
	system("cls");
	system("color 70");
	cout<<"\n\n\n\n\t\t\t\t..BOOKING.."<<endl;
	cout<<"\n\n\nM-Morning Ride\nN-Night Coach"<<endl<<endl;
	int seatno;
	char c;
	int y=0;
	c = getche();
	if(c=='M')
	{
	label2:
	cout<<"\n\nAvailable seats\n"<<endl;
	int i=0;
	int ava[11];
				i=0,c=0;
				for(i=0;i<10;i++)
				{
					if(tseats[0][i]==0)
					{
						c++;
					}
				}
				
				if(c==10)
				{
					cout<<"\n\nNo Seats Available in train"<<endl;
					return 0;
				}
		
	for(i=0;i<10;i++)
	{
		ava[i] = tseats[0][i];
	}
	ava[11] = s1;
	i=0;
	while(i<10)
	{
		if(ava[i]==1)
		{
		cout<<"Seat "<<i+1<<" is Empty"<<endl;
		}
		i++;
	}
	cout<<"Enter Your Desired Seat Number"<<endl;
	cin>>y;
	 //getting matched in file 
	if(ava[y-1]==1 && y>0  && y<11)
	{
		seatno = ava[y-1];
		cout<<"Seat "<<y<<" Is reserved for You"<<endl;
		ofstream of;
		of.open("Morning.txt");
		i=0;
		ava[y-1]=0;
		ava[11] = --s1;
		while(i<10)
		{	
				of<<ava[i];
				of<<endl;
				i++;
		}
		of<<s1;
		of.close();
	}
	else
{
	system("cls");
	cout<<"\n\nSeat "<<y<<" is already Reserved"<<endl;
	cout<<"Kindly Select Another Seat"<<endl;
	goto label2;
	
}
	}
	else if(c=='N')
{
	int i=0,c=0;
				for(i=0;i<10;i++)
				{
					if(tseats[1][i]==0)
					{
						c++;
					}
				}
				
				if(c==10)
				{
					cout<<"\n\nNo Seats Available in train "<<endl;
					return 0;
				}
		
	
	label3:
	cout<<"\n\nAvailable seats\n"<<endl;
	 i=0;
	 int ava[11];
	for(i=0;i<10;i++)
	{
		ava[i] = tseats[1][i];
	}
	ava[11] = s2;
	i=0;
	while(i<10)
	{
		if(ava[i]==1)
		{
		cout<<"Seat "<<i+1<<" is Empty"<<endl;
		}
		i++;
	}
	 
	cout<<"Enter Your Desired Seat Number"<<endl;
	cin>>y;
	 //getting matched in file 
	if(ava[y-1]==1 && y>0  && y<11)
	{
		seatno = ava[y-1];
		cout<<"Seat "<<y<<" Is reserved for You"<<endl;
		ofstream of1;
		of1.open("Night.txt");
		i=0;
		ava[y-1]=0;
		ava[11] = --s2;
		while(i<10)
		{	
				of1<<ava[i];
				of1<<endl;
				i++;
		}
		of1<<s2;
		of1.close();
	}
	else
{
	system("cls");
	cout<<"\n\nSeat "<<y<<" is already Reserved"<<endl;
	cout<<"Kindly Select Another Seat"<<endl;
	goto label3;
}

}
return y;
}
//underconstrcution
void account()
{
		system("cls");
		system("color 70");
		cout<<"\n\n\n\t\t\tYour account "<<endl;
		ifstream f;
		f.open(temp1); //opening current logined file;
		string s;
			f>>s;
			cout<<"Name : "<<s<<endl;
			f>>s;
			cout<<"Password : "<<s<<endl;
			f>>s;
			cout<<"Cnic : "<<s<<endl;
			f>>s;
			cout<<"Contact : "<<s<<endl;
}

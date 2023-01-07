//HOTEL MANAGEMENT PROJECT

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//STARTING BOOK ROOM FUNCTION
char book_room(int a)
{
		system("cls"); //CLEARING SCREEN
		
		int ch,confirm,second_confirm,third_confirm,floor,room_no;
		char first_name[7],last_name[7];
		int last_confirm;
		int age;
		int price,total_dues;
		char gen;
		long long phone;
		long long cnic;
		char address[100];
		fstream file;		
		file.open("Record.txt" ,ios::in | ios::out | ios::app);  //OPENING FILE IN Write and append mode
		cout<<"\n\t\t\tEnter Your First Name : ";
		cin.getline(first_name,7)>>first_name; 
		
		cout<<"\n\t\t\tEnter Your Last Name : ";
		cin.getline(last_name,7)>>last_name;
		file<<"\nCustomer Name : "; //WRITING CUSTOMER NAME TO FILE
		system("cls");
		for(int i=0 ; i<=7 ; i++)
		{
			file<<first_name[i]; //Writing customer name from array to file
		}
		file<<" "; //providing spaces in file
		for(int i=0 ; i<=7 ; i++)
		{
			file<<last_name[i]; //writing customer last name from array to a file
		}
		file<<"\n         {"; //writing { bracket to file
		system("cls");
		cout<<"\n\n";
		cout<<"\n\t\t\tChoose which class of Room you Want"<<endl; //Asking user room class
		cout<<"\n\t\t\t1. Vip "<<endl; //option
		cout<<"\n\t\t\t2. Non-vip"<<endl; //option
		cout<<"\n\t\t\tPlease Enter a choice to begin booking room : "; //confirmation
		cin>>ch; 
		file<<"\n\t  Booking Class : "; //writing to file
		if(ch==1)
		{
			file<<" Vip"; //Writing to file
			cout<<"\n\t\t\tPrice of Vip Room is RS.17000 or 100$ per month"<<endl; //displaying output
			price=100; //storing in variable
		}
		if(ch==2)
		{	
			
			file<<" Non-Vip";
			cout<<"\n\t\t\tPrice of Non-vip Room is RS.8800 or 50$ per month"<<endl; //displaying output
			price=50; //storing in variable
		}
		cout<<"\n\t\t\tPress again 1 or 2 to re-confirm your room choice : "; //again confirm
		cin>>second_confirm;
		if(second_confirm==1)
		{
			system("cls");
			file<<"\n\t  Floor Number : "; //writing to file floor number
			cout<<"\n\t\t\tPlease Enter the Floor number at which you want to book room (0 to 10) : ";
			cin>>floor;
			file<<" "<<floor; //writing floor entered by user to file
			while(floor>10)
			{
				
				cout<<"\n\t\t\tPlease again Enter the Floor number between (0 to 10) : ";
				cin>>floor;
				file<<" "<<floor; //writing floor entered by user to file
			}
			file<<"\n\t  Room Number : "; //writing room nymber to file
			cout<<"\n\t\t\tPlease Enter Room no (1 to 20): "; 	
			cin>>room_no;
			if(room_no<=20){
				file<<room_no; // writing room no to file
			}
			else
			{
				while(room_no>20)
			{
				cout<<"\n\t\t\tPlease Re enter Room no (1 to 20) : "; //Again Confirming room if room is greater than 20 
				cin>>room_no;
				file<<room_no; // writing room no to file
			}}
			//Asking user for Hotel Food
			file<<"\n\t  Hotel Food : ";
			cout<<"\n\t\t\tDear Customer! Do you want Hotel Food. Monthly Food Charges is 30$"<<endl;
			cout<<"\n\t\t\t1. Yes"<<endl;
			cout<<"\n\t\t\t2. No"<<endl;
			cout<<"\n\t\t\t";cin>>third_confirm;
			
			if(third_confirm==1)
			{
				system("cls");
				file<<"Yes";
				total_dues=price+30;
				//Showing total dues with food of vip room
				cout<<"\n\t\t\tThe total monthly room price is "<<total_dues<<endl;
				file<<"\n\t  Price of Room : "; //room price
				file<<total_dues;
				cout<<"\n\t\t\tPlease Enter your age : "; //asking age from user
				cin>>age;
				file<<"\n\t  Age : "; //storing in file
				file<<age;
				cout<<"\n\t\t\tPlease Enter your gender (M or F) : "; //asking user for gender
				cin>>gen;
				file<<"\n\t  Gender : "; // storing gender in file
				if(gen!='M' || gen!='F' || gen!='m' || gen!='f')
				{
					cout<<"\n\t\t\tPlease Again Enter your gender (M or F) : "; //Storing gender in file
					cin>>gen; 
					file<<gen;
				}
				cout<<"\n\t\t\tEnter Your Address (End address with . dot): "; //asking user for their address
				cin.getline(address,100,'.'); 
				file<<"\n\t  Address : "; //storing address in file
				file<<address; //address
				cout<<"\n\t\t\tEnter Your Phone Number : "; //asking user for phone number
				cin>>phone; 
				
				file<<"\n\t  Phone Number : "; //storing phone number in file
				file<<phone; //storing phone number in file
				cout<<"\n\t\t\tEnter Your CNIC (without dashes): "; 
				cin>>cnic;
				file<<"\n\t  CNIC : ";
				file<<cnic;
				cout<<"\n\t\t\tPress 1 to Confirm your Room Book\n";
				cout<<"\n\t\t\tPress 0 to Cancel Confirming Your Room\n\t\t\t\t";
				cin>>last_confirm;
				if(last_confirm==1)
				{
					file<<"\n\t  Room is Booked";
					cout<<"\n\n\t\t\tCONGRAGULATIONS!"<<first_name<<" "<<last_name<<" YOUR ROOM IS BOOKED.";
					
				}
				if(last_confirm==0)
				{
					file<<"\n\t  Room not Confirm or Canceled by User";
				}
				file<<"\n         }";
				file.close();
			}}
			if(third_confirm==2)
			{
				total_dues=price;
				system("cls");
				cout<<"\n\t\t\tThe total monthly room price is "<<total_dues<<endl;
				file<<"\n\t  Price of Room : "; //room price
				file<<total_dues;
				cout<<"\n\t\t\tPlease Enter your age : "; //asking age from user
				cin>>age;
				file<<"\n\t  Age : "; //storing in file
				file<<age;
				cout<<"\n\t\t\tPlease Enter your gender (M or F) : "; //asking user for gender
				cin>>gen;
				file<<"\n\t  Gender : "; // storing gender in file
				if(gen!='M' || gen!='F' || gen!='m' || gen!='f')
				{
					cout<<"\n\t\t\tPlease Again Enter your gender (M or F) : "; //Storing gender in file
					cin>>gen; 
					file<<gen;
				}
				cout<<"\n\t\t\tEnter Your Address (End address with . dot): "; //asking user for their address
				cin.getline(address,100,'.'); 
				file<<"\n\t  Address : "; //storing address in file
				file<<address; //address
				cout<<"\n\t\t\tEnter Your Phone Number : "; //asking user for phone number
				cin>>phone; 
				
				file<<"\n\t  Phone Number : "; //storing phone number in file
				file<<phone; //storing phone number in file
				cout<<"\n\t\t\tEnter Your CNIC (without dashes): "; 
				cin>>cnic;
				file<<"\n\t  CNIC : ";
				file<<cnic;
				cout<<"\n\t\t\tPress 1 to Confirm your Room Book\n";
				cout<<"\n\t\t\tPress 0 to Cancel Confirming Your Room\n\t\t\t\t";
				cin>>last_confirm;
				if(last_confirm==1)
				{
					file<<"\n\t  Room is Booked";
					cout<<"\n\n\t\t\tCONGRAGULATIONS!"<<first_name<<" "<<last_name<<" YOUR ROOM IS BOOKED.";
					
				}
				if(last_confirm==0)
				{
					file<<"\n\t  Room not Confirm or Canceled by User";
				}
				file<<"\n         }";
				file.close();
			}
		if(second_confirm==2)
		{
				system("cls");
			cout<<"\n\t\t\tThe total monthly room price is"<<total_dues<<endl;
				file<<"\n\t  Price of Room : "; //room price
				file<<total_dues;
				cout<<"\n\t\t\tPlease Enter your age : "; //asking age from user
				cin>>age;
				file<<"\n\t  Age : "; //storing in file
				file<<age;
				cout<<"\n\t\t\tPlease Enter your gender (M or F) : "; //asking user for gender
				cin>>gen;
				file<<"\n\t  Gender : "; // storing gender in file
				if(gen!='M' || gen!='F' || gen!='m' || gen!='f')
				{
					cout<<"\n\t\t\tPlease Again Enter your gender (M or F) : "; //Storing gender in file
					cin>>gen; 
					file<<gen;
				}
				cout<<"Enter Your Address (End address with . dot): "; //asking user for their address
				cin.getline(address,100,'.'); 
				file<<"\n\t  Address : "; //storing address in file
				file<<address; //address
				cout<<"\n\t\t\tEnter Your Phone Number : "; //asking user for phone number
				cin>>phone; 
				
				file<<"\n\t  Phone Number : "; //storing phone number in file
				file<<phone; //storing phone number in file
				cout<<"\n\t\t\tEnter Your CNIC (without dashes): "; 
				cin>>cnic;
				file<<"\n\t  CNIC : ";
				file<<cnic;
				cout<<"\n\t\t\tPress 1 to Confirm your Room Book\n";
				cout<<"\n\t\t\tPress 0 to Cancel Confirming Your Room\n\t\t\t";
				cin>>last_confirm;
				if(last_confirm==1)
				{
					file<<"\n\t  Room is Booked";
					cout<<"\n\n\t\tCONGRAGULATIONS!"<<first_name<<" "<<last_name<<" YOUR ROOM IS BOOKED.";
					
				}
				if(last_confirm==0)
				{
					file<<"\n\t  Room not Confirm or Canceled by User";
				}
				file<<"\n         }";
				file.close();
			}}

void customer_record(int a)
{
	string line; 
	int customer_name;
	int booking_class;
	ifstream record;
	record.open("Record.txt" , ios::in); //Opening File
	while(getline(record,line)) //Reading record from File
	cout<<line<<endl; //Printing all record on screenj
	record.close(); //Closing file
}
void rooms_alloted(int a)
{
	int room;
	int line;
	ifstream file;
	file.open("Record.txt", ios::in);
}
//Starting of Main Function
int main()
{
	int choice;
  	system("cls"); // Clearing Screen
  	//Showing outputs
	cout<<"\n\t\t\t\t\t\t****************************";
	cout<<"\n\t\t\t\t\t\t* HOTEL MANAGEMENT PROJECT *";
	cout<<"\n\t\t\t\t\t\t****************************";
	cout<<"\n\n\t\t\t\t\t\t   Welcome to Your Hotel";
	cout<<"\n\n\n\n\t\t\t\t\t\t       Developed By";
	cout<<"\n\t\t\t\tMuhammad Hassan , Asim Ijaz, Wasi Ahamd, Ammar Hamza,";
	cout<<"\n\n\n\n\n\n\n\t\t\t\t\t      Press 1 key to continue....!!\n\t\t\t";
	cin>>choice; //getting input
	if(choice=1) //if choice entered by user is 1 then it will execute below lines
	{
		int choice;
	system("cls");
	cout<<"\n\t\t\t\t**************************";
	cout<<"\n\t\t\t\t HOTEL MANAGEMENT Project";
	cout<<"\n\t\t\t\t      * MAIN MENU *";
	cout<<"\n\t\t\t\t**************************";
	cout<<"\n\n\n\t\t\t1.Book A Room";
	cout<<"\n\t\t\t2.Customer Records";
	cout<<"\n\t\t\t3.Rooms Allotted";
	cout<<"\n\t\t\t4.Exit";
	cout<<"\n\n\t\t\tEnter Your Choice: ";
	cin>>choice;
	if(choice==1)
	{
		book_room(choice);
	}	
	if(choice==2)
	{
		customer_record(choice);
	}
	if(choice==3)
	{
		rooms_alloted(choice);
	}
	if(choice==4)
	{
		int exit;
		cout<<"\t\t\tPress 1 to exit : ";
		cin>>exit;
		if(exit=1)
		{
			
		}
	}
	}
	else
	{
		cout<<"WRONG INPUT !!!!!!!!!";
		cout<<"Again Press 1 to Continue";
		cin>>choice;
		book_room(choice);
	}
}

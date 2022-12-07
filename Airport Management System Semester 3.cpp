#include <iostream>
#include <string.h>
using namespace std;
class node
{
public:
    node *left;
    node *right;
    string firstName;
    string lastName;
    string id;
    string phNumber;
    string departure;
    string destination;
    string vege;
    string novege;
    string nomeal;
    string day;
    int seatnmbr;
    int date1, date2;
    int reservationnmbr;

    node()
    {
        firstName = ' ';
        lastName = ' ';
        id = ' ';
        phNumber = ' ';
        vege = "No";
        novege = "No";
        nomeal = "No";
        reservationnmbr = 0;
        departure = ' ';
        destination = ' ';
        day = " ";
        date1 = date2 = 0;
    }
};
class airport
{
private:
    string id = "admin";
    string password = "admin";
    string ide, pass2;
    int choice;
    node *root = NULL, *newnode;
    int confirm;
    bool flaggy;

public:
    void mainmenu()
    {
        system("cls");
        cout << "1 : Seat Booking" << endl;
        cout << "2 : Cancel Seat" << endl;
        cout << "3 : Check Ticket" << endl;
        cout << "4 : Search Any Passeger Details (For Admin Only)" << endl;
        cout << "5 : Exit" << endl;
        cout << "* : Enter Your Choice : ";
        cin >> choice;
        if (choice == 1)
        {
            seatbookingmenu();
        }
        else if (choice == 2)
        {
            cancelseat();
        }
        else if (choice == 3)
        {
            checkticket();
        }
        else if (choice == 4)
        {
            displaydata();
        }
        else if (choice == 5)
        {
            abort();
        }
    }
    void seatbookingmenu()
    {
        system("cls");
        int departure, destination;
        string day;
        int date1, date2;
        while (confirm != 2)
        {
            do
            {
                system("cls");
                cout << "Choose Departure Country" << endl;
                cout << "01 : Russia   02 : Germany      03 : United Kingdom   04 : France       05 : Italy" << endl;
                cout << "06 : Spain    07 : Ukraine      08 : Poland           09 : Romainia     10 : Netharlands" << endl;
                cout << "11 : Swedan   12 : India        13 : Ireland          14 : Australia    15 : United States" << endl;
                cout << "16 : Norway   17 : Afganistan   18 : Saudia Arabia    19 : Srilanka     20 : Newzeland" << endl;
                cout << "Enter Choice Here : ";
                cin >> departure;
                for (int i = 0; i < 10000; i++)
                {
                    for (int j = 0; j < 100000; j++)
                    {
                    }
                }
                system("cls");
                cout << "Choose Destination Country" << endl;
                cout << "01 : Russia   02 : Germany      03 : United Kingdom   04 : France       05 : Italy" << endl;
                cout << "06 : Spain    07 : Ukraine      08 : Poland           09 : Romainia     10 : Netharlands" << endl;
                cout << "11 : Swedan   12 : India        13 : Ireland          14 : Australia    15 : United States" << endl;
                cout << "16 : Norway   17 : Afganistan   18 : Saudia Arabia    19 : Srilanka     20 : Newzeland" << endl;
                cout << "Enter Choice Here : ";
                cin >> destination;
                for (int i = 0; i < 10000; i++)
                {
                    for (int j = 0; j < 100000; j++)
                    {
                    }
                }
                if (destination == departure)
                {
                    cout << "Departure and Destination Country is Same. Please Choose Different" << endl;
                    system("cls");
                    continue;
                }
                cout << "Enter Day (Only First Three Charcters) : ";
                cin >> day;
                cout << "Enter Date in the format (HH/MM) : ";
                cin >> date1 >> date2;
                if (departure != destination)
                {
                    break;
                }
            } while (departure != destination);

            if (root == NULL)
            {
                root = insert(root, departure, destination, day, date1, date2);
            }
            else
            {
                insert(root, departure, destination, day, date1, date2);
            }
            system("cls");
            cout << "Do You Want to Purchase More Ticket(1 : Yes | 2 : No) : ";
            cin >> confirm;
            if (confirm == 1)
            {
                continue;
            }
            else if (confirm == 2)
            {
                break;
            }
            else if (confirm != 1 || confirm != 2 || confirm > 2)
            {
                cout << "Invalid Value. Please Enter Again Value";
                do
                {
                    if (confirm == 1)
                    {
                        continue;
                    }
                    else if (confirm == 2)
                    {
                        mainmenu();
                    }
                } while (confirm != 1 || confirm != 2);
            }
        }
        mainmenu();
    }
    node *insert(node *nnode, int dep, int des, string day, int date1, int date2)
    {
        if (nnode == NULL)
        {
            system("cls");
            newnode = new node;
            cout << "Enter Your First Name : ";
            cin >> newnode->firstName;
            cout << "Enter Your Last Name : ";
            cin >> newnode->lastName;
            cout << "Enter ID of Passenger (Without Dashes) : ";
            cin >> newnode->id;
            cout << "Enter Phone Number : ";
            cin >> newnode->phNumber;
            int seatno;
            do
            {
                cout << "Choose Seat Number Between (1 <-> 850) : ";
                cin >> seatno;
                flaggy = seat(seatno);
                if (flaggy == false)
                {
                    newnode->seatnmbr = seatno;
                    break;
                }
                else if (flaggy == true)
                {
                    cout << "Seat Already Registered to Another Passenger." << endl;
                    continue;
                }
            } while (flaggy != 0);
            system("cls");
            cout << "Choose Type of Food Which You Want to Served in Flight" << endl;
            cout << "1 : Vegetarian" << endl;
            cout << "2 : Non-Vegetarian" << endl;
            cout << "3 : No Meal" << endl;
            cout << "* : Enter Your Choice Here : ";
            cin >> confirm;
            if (confirm == 1)
            {
                newnode->vege = "Yes";
                newnode->novege = "No";
                newnode->nomeal = "No";
            }
            if (confirm == 2)
            {
                newnode->vege = "No";
                newnode->novege = "Yes";
                newnode->nomeal = "No";
            }
            if (confirm == 3)
            {
                newnode->vege = "No";
                newnode->novege = "No";
                newnode->nomeal = "Yes";
            }
            if (dep == 1)
            {
                newnode->departure = "Russia";
            }
            if (dep == 2)
            {
                newnode->departure = "Germany";
            }
            if (dep == 3)
            {
                newnode->departure = "United Kingdom";
            }
            if (dep == 4)
            {
                newnode->departure = "France";
            }
            if (dep == 5)
            {
                newnode->departure = "Italy";
            }
            if (dep == 6)
            {
                newnode->departure = "Spain";
            }
            if (dep == 7)
            {
                newnode->departure = "Ukraine";
            }
            if (dep == 8)
            {
                newnode->departure = "Poland";
            }
            if (dep == 9)
            {
                newnode->departure = "Romainia";
            }
            if (dep == 10)
            {
                newnode->departure = "Netharlands";
            }
            if (dep == 11)
            {
                newnode->departure = "Swedan";
            }
            if (dep == 12)
            {
                newnode->departure = "India";
            }
            if (dep == 13)
            {
                newnode->departure = "Ireland";
            }
            if (dep == 14)
            {
                newnode->departure = "Australia";
            }
            if (dep == 15)
            {
                newnode->departure = "United States";
            }
            if (dep == 16)
            {
                newnode->departure = "Norway";
            }
            if (dep == 17)
            {
                newnode->departure = "Afganistan";
            }
            if (dep == 18)
            {
                newnode->departure = "Saudia Arabia";
            }
            if (dep == 19)
            {
                newnode->departure = "Srilanka";
            }
            if (dep == 20)
            {
                newnode->departure = "NewZeland";
            }

            if (des == 1)
            {
                newnode->destination = "Russia";
            }
            if (des == 2)
            {
                newnode->destination = "Germany";
            }
            if (des == 3)
            {
                newnode->destination = "United Kingdom";
            }
            if (des == 4)
            {
                newnode->destination = "France";
            }
            if (des == 5)
            {
                newnode->destination = "Italy";
            }
            if (des == 6)
            {
                newnode->destination = "Spain";
            }
            if (des == 7)
            {
                newnode->destination = "Ukraine";
            }
            if (des == 8)
            {
                newnode->destination = "Poland";
            }
            if (des == 9)
            {
                newnode->destination = "Romainia";
            }
            if (des == 10)
            {
                newnode->destination = "United States";
            }
            if (des == 11)
            {
                newnode->destination = "Swedan";
            }
            if (des == 12)
            {
                newnode->destination = "India";
            }
            if (des == 13)
            {
                newnode->destination = "Ireland";
            }
            if (des == 14)
            {
                newnode->destination = "Australia";
            }
            if (des == 15)
            {
                newnode->destination = "United States";
            }
            if (des == 16)
            {
                newnode->destination = "Norway";
            }
            if (des == 17)
            {
                newnode->destination = "Afganistan";
            }
            if (des == 18)
            {
                newnode->destination = "Saudia Arabia";
            }
            if (des == 19)
            {
                newnode->destination = "Srilanka";
            }
            if (des == 20)
            {
                newnode->destination = "Newzeland";
            }
            if (day == "mon" || day == "Mon")
            {
                newnode->day = "Monday";
            }
            if (day == "tue" || day == "Tue")
            {
                newnode->day = "Tuesday";
            }
            if (day == "wed" || day == "Wed")
            {
                newnode->day = "Tueday";
            }
            if (day == "thu" || day == "Thu")
            {
                newnode->day = "Thurday";
            }
            if (day == "fri" || day == "Fri")
            {
                newnode->day = "Friday";
            }
            if (day == "sat" || day == "Sat")
            {
                newnode->day = "Satday";
            }
            if (day == "sun" || day == "Sun")
            {
                newnode->day = "Sunday";
            }
            newnode->date1 = date1;
            newnode->date2 = date2;
            newnode->reservationnmbr = rand() % 10000;
            for (int i = 0; i < 10000; i++)
            {
                for (int j = 0; j < 10000; j++)
                {
                }
            }
            int a;
            system("cls");
            cout << "Seat Registered Successfully. Happy Jouney " << endl;
            cout << "Your Reservation Number is " << newnode->reservationnmbr << endl;
            cout << "Press 1 to Continue" << endl;
            cin >> a;
            if (a == 1)
            {
            }
            return newnode;
        }
        if (nnode->seatnmbr < root->seatnmbr)
        {
            nnode->left = insert(nnode->left, dep, des, day, date1, date2);
        }
        if (nnode->seatnmbr > root->seatnmbr)
        {
            nnode->right = insert(nnode->right, dep, des, day, date1, date2);
        }
        return nnode;
    }
    void cancelseat()
    {
        int del;
        cout<<"Enter Your Reservation Number : ";
        cin>>del;
        
        root = NULL;
        cout<<"The Data has been Cleared Successfully."<<endl;
        
    }
    bool seat(int con)
    {
        int flag = 0;
        flag = isSeatReserved(root, con);
        if (flag == 0)
        {
            return false;
        }
        else if (flag == 1)
        {
            return true;
        }
    }
    int isSeatReserved(node *nnode, int seatnmbr)
    {
        if (nnode == NULL)
        {
            return 0;
        }
        if (nnode->seatnmbr == seatnmbr)
        {
            return 1;
        }
        if (nnode->seatnmbr > seatnmbr)
        {
            isSeatReserved(nnode->left, seatnmbr);
        }
        if (nnode->seatnmbr < seatnmbr)
        {
            isSeatReserved(nnode->right, seatnmbr);
        }
        return 0;
    }
    void displaydata()
    {
        int search;
        cout << "Are You Admin? (1 : Yes , 2 : No) : ";
        cin >> search;
        if (search == 1)
        {
            cout << "Enter Login Id : ";
            cin >> id;
            cout << "Enter Password : ";
            cin >> password;
            if (id == "admin" && password == "admin")
            {
                node *temp = NULL;
                cout << "Enter Seat Number to Check Passenger Details : ";
                cin >> search;
                temp = display(root, search);
                system("cls");
                if (temp != NULL)
                {
                    cout << "First Name              : " << temp->firstName << endl;
                    cout << "Last Name               : " << temp->lastName << endl;
                    cout << "Identification Number   : " << temp->id << endl;
                    cout << "Phone Number            : " << temp->phNumber << endl;
                    cout << "Seat Number             : " << temp->seatnmbr << endl;
                    cout << "Registeration Number    : " << temp->reservationnmbr << endl;
                    cout << "Departure Country       : " << temp->departure << endl;
                    cout << "Destination Country     : " << temp->destination << endl;
                    cout << "Vegetarian              : " << temp->vege << endl;
                    cout << "Non Vegetarian          : " << temp->novege << endl;
                    cout << "No Meal                 : " << temp->nomeal << endl;
                    cout << "Last Flight Day         : " << temp->day;
                    cout << "Late Flight Date        : " << temp->date1 << " " << temp->date2 << endl;
                }
                else
                {
                    cout << "No One is Registered with This Reservation Number." << endl;
                }
            }
        }
        else if (search == 2)
        {
            cout << "I Think You are not a Admin. Go Back To Main Menu (1 : Yes , 2 : No) : " << endl;
            cin >> confirm;
            if (confirm == 1)
            {
                mainmenu();
            }
            else if (confirm == 2)
            {
                abort();
            }
        }
    }
    node *display(node *nnode, int seatnmr)
    {
        if (nnode->seatnmbr == seatnmr)
        {
            cout<<"1"<<endl;
            return nnode;
        }
        if (nnode->seatnmbr > seatnmr)
        {
            cout<<"2"<<endl;
            display(nnode->left, seatnmr);
        }
        if (nnode->seatnmbr < seatnmr)
        {
            cout<<"3"<<endl;
            display(nnode->right, seatnmr);
        }
        return nnode;
    }

    void checkticket()
    {
        system("cls");
        cout << "Enter Reservation Number : ";
        cin >> confirm;
        node *temp = NULL;
        temp = display2(root, confirm);
        system("cls");
        if (temp != NULL)
        {
            cout << "The Flight Details of "<<temp->reservationnmbr<<" Reservation Number are"<<endl;
            cout << "Passenger Full Name : "<<temp->firstName<<" "<<temp->lastName<<endl;
            cout << "Flight Day          : "<<temp->day<<endl;
            cout << "Flight Date         : "<<temp->date1<<":"<<temp->date2<<endl;
        }
        else
        {
            cout << "No One is Registered with This Reservation Number." << endl;
        }
        cout<<"Do You Want to Go Back To Main Menu (1 : Yes , 2 : No ) : ";
        cin>>confirm;
        if(confirm == 1)
        {
            mainmenu();
        }
        else if(confirm == 2)
        {
            abort();
        }
    }
    node *display2(node *nnode, int rsn)
    {
        if (nnode->reservationnmbr == rsn)
        {
            return nnode;
        }
        if (nnode->reservationnmbr > rsn)
        {
            display2(nnode->left, rsn);
        }
        if (nnode->seatnmbr < rsn)
        {
            display2(nnode->right, rsn);
        }
        return nnode;
    }
};
int main()
{
    airport Pak;
    Pak.mainmenu();
}

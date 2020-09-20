/*

	Name : Ahmad Azam (100698308), Ryan Maku ()

	Date : September 19, 2020

	Description : Lab One Review of Classes and Objects. Creating a programe that stores detial about work ticket. first it stores the input but before storing eac data the program will
	 runs it throgh validation and than stored into correct variable.


*/


#include<iostream>
#include <stdexcept>
#include<string>

using namespace std;

class WorkTicket							// main class name
{
public:

	//default constructor
	WorkTicket()
	{
		WorkTicketNumber = 0;
		Day = 1;
		Month = 1;
		Year = 2000;
		ClientID = "";
		IssueInformation = "";
	}

	//parameterized constructor
	WorkTicket(int ticket, string clientID, int day, int month, int year, string desc)
	{
		WorkTicketNumber = ticket;
		ClientID = clientID;
		Day = day;
		Month = month;
		Year = year;
		IssueInformation = desc;
	}
	// function for getting input from user and validating all the integer inout for work ticket Info.
	void SetWorkTicket()
	{

		cout << endl << "Please enter the ticket number:";
		cin >> WorkTicketNumber;
		Validating_Work_Ticket_Number(WorkTicketNumber);

		cout << endl << "Please enter the client ID: ";
		getchar(); 		// for clearing the buffer 
		getline(cin, ClientID);

		cout << endl << "Enter the day for date: ";
		cin >> Day;
		int Validating_Day_for_date(Day);

		cout << endl << "Enter the month for the date: ";
		cin >> Month;
		Validating_Month_for_date(Month);

		cout << endl << "Enter the year for date: ";
		cin >> Year;
		Validating_Year_for_date(Year);

		cout << endl << "Enter your issue description:";
		getchar();
		getline(cin, IssueInformation);

	}

	//function for getting the output print on display
	void ShowWorkTicket()
	{
		cout << "\nYour ticket number is : "
			<< WorkTicketNumber << " \Your client ID is : "
			<< ClientID << " \t the is date was : "
			<< Day << "-" << Month << "-" << Year << " \t & the issue was : "
			<< IssueInformation;
	}

private:
	// variable to store ticket number		
	int WorkTicketNumber;
	//variable to store Day for date
	int Day;
	//variable to store Month for date
	int Month;
	//variable to store year for date
	int Year;
	// variable to store client ID		
	string ClientID;
	//  variable to store Issue 
	string IssueInformation;

	//Function to do validation of all integer input
	int Validating_Work_Ticket_Number(int ticket_no);
	int Validating_Day_for_date(int day);
	int Validating_Month_for_date(int month);
	int Validating_Year_for_date(int year);
};

int main()
{
	cout << "-----------------------------------------------------\n"
		<< "\t Lab One Review of Classes and Objects \n\t\t\tWorkTicket\n"
		<< "-------------------------------------------------------\n\n";
	//making array's of 4 
	WorkTicket tickets[4];

	//using for loop to keep the programme running until 4 times (collect data in 4 boxes of an array)
	for (int round = 0;round < 4;round++)
	{
		//exception handling
		try
		{
			//calling the function to get the ticket information
			tickets[round].SetWorkTicket();
			cout << "\n---------------------------------";
		}
		catch (invalid_argument& ex)
		{
			cin.clear();
			cin.sync();
			cout << endl
				<< ex.what();
			//displaying exceptions accordingly
			cerr << ex.what() << endl;
		}
	}

	//second for loop showing the info ass many times as we cteate array size

	cout << "\n---------------------\n\tOutPut\n";
	for (int output = 0;output < 4;output++)
	{
		tickets[output].ShowWorkTicket();
	}

	return 0;

}
#include<iostream>
#include<fstream>
using namespace std;

class shopping
{
	private:
		int ProductCode;
		float price;
		float dis;
		string ProductName;
	
	public:
	    void menu();
		void administrator();
		void buyer();
		void add();
		void edit();
		void remove();
		void receipt();
					
};

void shopping:: menu()
{
	m:
	int choice;
	string email;
	string password;
	
	cout<<"\t\t\t\t-----------------------------------------------\n";
	cout<<"\t\t\t\t                                               \n";
	cout<<"\t\t\t\t                  Main Menu                    \n";
	cout<<"\t\t\t\t                                               \n";
	cout<<"\t\t\t\t-----------------------------------------------\n";
	cout<<"\t\t\t\t                                               \n";
	cout<<"\t\t\t\t\|       1)Administrator         |\n";
	cout<<"\t\t\t\t\|                               |\n;
	cout<<"\t\t\t\t\|       2)Buyer                 |\n";
	cout<<"\t\t\t\t\|                               |\n;
	cout<<"\t\t\t\t\|       3)Exit                  |\n;
	cout<<"\t\t\t\t\|                               |\n;
	
	cout<<"\n\t\t\t Please select from above";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			{
			cout<<"\t\t\t Please Login \n";
			cout<<"\t\t\t Enter Email  \n";
			cin>>email;
			cout<<"\t\t\t Enter Password \n";
			cin>>password;
			
			if(email=="abc@gmail.com" && password==abc@123)
			{
				administrator();
			}
			else
			{
				cout<<"Invalid Password/Email \n";
			}
			break;
			
		
	
     	case 2;
		    {
		    	buyer();
			}
    	case 3:
			{
				exit(0);
			}
			
	    default:
		{
			cout<<"Please select from given options";
	
		}
	
	
}
goto m;
}

void shopping::administrator()
{
	m:
	int choice;
	
	cout<<"\n\n\t\t\t       Administrator Menu    ";
	cout<<"\n\t\t\t|_________1) Add the product_________ |";
	cout<<"\n\t\t\t|                                     |";
	cout<<"\n\t\t\t|_________2) Edit the product_________|";
	cout<<"\n\t\t\t|                                     |";
	cout<<"\n\t\t\t|_________3) Delele the product_______|";
	cout<<"\n\t\t\t|                                     |";
	cout<<"\n\t\t\t|_________4) Back to main menu_______ |";
	
	cout<<"\n\n\tPlease enter your choice";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			add();
			break;
		
		case 2:
			edit();
			break;
			
		case 3:
			remove();
			break;
			
		case 4:
			menu();
			break;
			
		default:
			cout<<"Select from given options\n";
			
	}
	goto m;
}

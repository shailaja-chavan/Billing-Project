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
	cout<<"\t\t\t\t|       1)Administrator         |\n";
	cout<<"\t\t\t\t|                               |\n";
	cout<<"\t\t\t\t|      2)Buyer                  |\n";
	cout<<"\t\t\t\t|                               |\n";
	cout<<"\t\t\t\t|      3)Exit                   |\n";
	cout<<"\t\t\t\t|                               |\n";
	
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
			
			if(email=="abc@gmail.com" && password=="abc@123")
			{
				administrator();
			}
			else
			{
				cout<<"Invalid Password/Email \n";
			}
			break;
			
		
	
     	case 2:
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
void shopping:: administrator()
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
void shopping::buyer()
{
	m:
	int choice;
	cout<<"\t\t\t   Buyer   \n";
	cout<<"\t\t\t_________________\n";
	cout<<"      |                 |\n";
	cout<<"\t\t\t|   1)Buy Product |\n";
	cout<<"      |                 |\n";
	cout<<"\t\t\t|   2) Go back    |\n";
	
	cout<<"enter your choice";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			receipt();
			break;
		case 2:
			menu();
		
		default:
		   cout<<"Invalid Choice";
		   
		   	
			
	}
	
	goto m;
}

void shopping::add()
{
	m:
	fstream data;
	int c;
	int token=0;
	float p;
	float d;
	string n;
	cout<<"\n\n\t\t\t Add new product";
	cout<<"\n\n\t product code of the product ";
	cin>>ProductCode;
	cout<<"/n/n\t Name of the product ";
	cin>>ProductName;
	cout<<"Price of the product ";
	cin>>price;
	cout"\n\n\t Discount on the product ";
	cin>>dis;
	
	data.open("database.txt",ios::in);
	
	if(!data)
	{
		data.open("data.txt", ios::app|ios::out);
		data<<" "<<ProductCode<<" "<<ProductName<<" "<<price<<" "<<dis<<"\n";
		data.clode();
	}
	else
	{
		data>>c>>n>>p>>d;
		
		while(!data.eof())
		{
			if(c==ProductCode)
			{
				token++;
			}
			data.close();
		}
	
	if(token==1)
	{
		goto m;
	}
	else
	{
		data.open("data.txt", ios::app|ios::out);
		data<<" "<<ProductCode<<" "<<ProductName<<" "<<price<<" "<<dis<<"\n";
		data.clode();
	}
    }
    cout<<"\n\n\t\t Record Inserted ";
}

void shopping::edit()
{
	fstream data,data1;
	int pkey;
	int token=0;
	int c;
	float p;
	float d;
	string n;
	
	cout<<"\n\n\t\t Modify the record ";
	cout<<"\n\t\t\t Product code: ";
	cin>>pkey;
	
	data.open("database.txt",ios::in);
	if(!data)
	{
		cout<<"\n\n File doens't Exist ";
	}
	else
	{
		data1.open("database1.txt", ios::app|ios::out);
		data>>ProductCode>>ProductName>>price>>dis;
		
		while(!data.eof())
		{
			if(pkey==ProductCode)
			{
				cout<<"\n\n\t\t Product new code: ";
				cin>>c;
				cout<<"\n\t\t Name of the product: ";
				cin>>n;
				cout<<"\n\t\t Price: ";
				cin>>p;
				cout<<"\n\t\t Discount: ";
				cin>>d;
				data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
				cout<<"Record Edited";
				token++;
			}
			else
			{
				data1<<" "<<ProductCode<<" "<<ProductName<<" "<<price<<dis<<"\n";
			}
			data>>ProductCode>>ProductName>>price>>dis;
			
		}
		data.close();
		data1.close();
		
		remove("database.txt");
		rename("database1.txt","database.txt");		
		
		if(token==0)
		{
			cout<<"\n\n Record not found Sorry! ";
		}
		
	}
	
	
	
	
}

void shopping::remove()
{
	fstream data,data1;
	int pkey;
	int token=0;
	cout<<"\n\n\t Delete Product ";
	cout<<"\n\n\t Product code: ";
	cin>>pkey;
	data.open("database.txt", ios::in);
	if(!data)
	{
		cout<<"File doesn't exist ";
	}
	else
	{
		data1.open("database1.txt",ios::app|ios::out);
		data>>ProductCode>>ProductName>>price>>dis;
		
		while(!data.eof())
		{
			if(ProductCode==pkey)
			{
				cout<<"\n\n\t Product deleted successfully ";
				token++;
			}
			else
			{
				data1<<ProductCode<<" "<<ProductName<<" "<<price<<" "<<dis<<"\n";
			}
			data>>ProductCode>>ProductName>>price>>dis;
		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt","database1.txt");
		
		if(token==0)
		{
			cout<<"\n\t\t Record not found ";
		}
		
	}
}
void shopping::list()
{
	fstream data;
	data.open("database.txt",ios::in);
	cout<<"\n\n-------------------------------------------\n";
	cout<<"ProNo\t\tName\t\tPrice\n";
	cout<<"\n\n-------------------------------------------\n";
	data>>ProductCode>>ProductName>>price>>dis;
	while(!data.eof())
	{
		cout<<ProductCode<<"\t\t"<<ProductName<<"\t\t"<<price<<"\n";
		data>>ProductCode>>ProductName>>price>>dis;
	}
	data.close();
	
}
void shopping::receipt()
{
	fstream data;
	int arrc[100];
	int arrq[100];
	char choice;
	int c=0;
	float amount=0;
	float dis=0;
	float total=0;
	
	cout<<"\n\n\t\t\t\t RECEIPT ";
	data.open("database.txt",ios::in);
	if(!data)
	{
		cout<<"\n\n Empty Database";
	}
	else
	{
		data.close();
		list();
		
		cout<<"\n_________________________________________\n";
		cout<<"\n                                         \n";
		cout<<"            Please place the order         \n";
		cout<<"\n                                         \n";
		cout<<"\n_________________________________________\n";
		
		do
		{
			m:
			cout<<"\n\n Enter Product code : ";
			cin>>arrc[c];
			cout<<"\n\n Enter product quantity : ";
			cin>>arrq[c];
			for(int i=0;i<c;i++)
			{
				if(arrc[c]==arrc[i])
				{
					cout<<"\n\n Duplicate product code. Please try again ";
					goto m;
				}
			}
			c++;
			cout<<"\n\n Do you want to buy another product? if yes then press y else no ";
			cin>>choice;
		}
		while(choice=="y");
	
	    cout<<"\n\n\t\t\t________________________RECEIPT__________________________\n";
	    cout<<"\nProduct No\t Product Name\t Product quantity\t Price\t Amount\t Amount with discount\n";
	    
	    for(int i=0;i<c;i++)
	    {
	    	data.open("database.txt",ios::in);
	    	data>>ProductCode>>ProductName>>price>>dis;
	    	while(!data.eof())
			{
				if(ProductCode==arrc[i])
				{
					amount=price*arrq[i];
					dis=amount-(amount*dis/100);
					total=total+dis;
					cout<<"\n"<<ProductCode<<"\t\t"<<ProductName<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<dis;
				}
				data>>ProductCode>>ProductName>>price>>dis;
			}		
		}
		data.close();
	    
	}
	cout<<"\n\n___________________________________________________";
	cout<<"\n Total Amount: "<<total;
}

int main()
{
    shopping s;
	s.menu();
}
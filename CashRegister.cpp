#include <iostream>
#include <array>
#include <ostream>
#include <string>
#include <sstream>

using namespace std;

class Store {
public:

	Store() {};
	Store(string name, string address, string id) {
		this->storeName = name;
		this->address = address;
		this->storeID = id;
	};

	string storeName;
	string address;
	string storeID;

};

class Receipt
{
public:	

	float totalValue;
	int numberOfItems;
	float cashIn;
	float change;
};

class SaleItem
{
public:

	SaleItem() {};
	SaleItem(string id, float price) {
		this->ID = id;
		this->price = price;
	}
	string ID;
	float price;
	
	void ChangePrice(float newPrice) {
		this->price = newPrice;
	}

};

SaleItem inventory[] =
{
	*new SaleItem("aaaaaaaaaa",10.00f),
	*new SaleItem("bbbbbbbbbb",10.11f),
	*new SaleItem("cccccccccc",10.12f),
	*new SaleItem("111111111c",10.13f),
	*new SaleItem("222222222b",10.14f),
	*new SaleItem("555555555c",10.15f),
	*new SaleItem("666666666d",10.16f),
	*new SaleItem("777777777e",10.17f),
	*new SaleItem("888888888f",10.18f),
	*new SaleItem("999999999g",10.19f)
};

void MainMenu(Receipt &currReceipt);
bool CheckInventory(string ItemID);
void PriceChange(string itemID, float newPrice);
void AddItemTopUrchase(Receipt &currReceipt, string itemID);


int main() {

	Store myStore = Store("CandyShop","Somewhere in the middle of nowhere", "12345678");
	Receipt currReceipt = Receipt();
	currReceipt.totalValue = 20.00;
	currReceipt.numberOfItems = 5;

    //cout << inventory[2].ID << endl;
	MainMenu(currReceipt);

	string userInput;
    getline(cin, userInput);
	
	while (userInput != "END")
	{
		cout << "you entered "<<userInput << endl;

		if (userInput.length() == 10)
		{
			if (CheckInventory(userInput))
			{
				AddItemTopUrchase(currReceipt, userInput);				
				system("pause");
			}							
		}

		if (userInput == "C")
		{
			currReceipt.totalValue = 0;
			currReceipt.numberOfItems = 0;
			system("pause");
		}

		if (userInput == "T")
		{
			cout << "Your current purchase total is: ";
			cout << currReceipt.totalValue << " leva." << endl;
			system("pause");			
		}

		if (userInput == "G")
		{
			cout << "Enter cash given by customer: ";
			cin >> currReceipt.cashIn;
			currReceipt.change = currReceipt.cashIn - currReceipt.totalValue;
			cout << "The change is " << currReceipt.change << " leva" << endl;
			system("pause");			
		}


		if (userInput == "P")
		{
            string itemId;
            string price;
			float newPrice;
			stringstream stream;

			cout << "Which item do you want me to change the price of? ";
			
			getline(cin, itemId);			

			if (CheckInventory(itemId))
			{
				cout << "Enter new price for that item: ";	

				getline(cin, price);			
				stream << price;
				stream >> newPrice;

				void PriceChange(string itemID, float newPrice);
				system("pause");
			}	
			
		}

		if (userInput == "I")
		{
			//message “CandyShop\nBIC:12345678\nAddress : Somewhere in the middle of nowhere\nPurchases : <xx.xx> leva\nGiven : <xx.xx>\nChange : <xx.xx>\n”
			cout << myStore.storeName << endl;
			cout << "BIC:" << myStore.storeID << endl;
			cout << "Address" << myStore.address << endl;
			cout << "Purchases :" << currReceipt.totalValue << endl;
			cout << "Given :" << currReceipt.cashIn << endl;
			cout << "Change :" << currReceipt.change << endl;

			system("pause");			
		}

		else
		{
			cout << "invalid selection" << endl;
			system("pause");	
		}

		MainMenu(currReceipt);
		getline(cin, userInput);
	}

	cout << "goodbye!"<<endl;
	
	return 0;
}


void MainMenu(Receipt &currReceipt)
{
	system("cls");
	cout << " Welcome to our store" << endl;
	cout << " +++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << " Enter a 10 character item id to add to the purchase" << endl;
	cout << " +++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << " other commands you can use :" << endl;
	cout << " C - clear purchase" << endl;
	cout << " T - display current purchase total" << endl;
	cout << " G - enter customer moneys given" << endl;
	cout << " P - change the price of an item in the inventory" << endl;
	cout << " I - print recepit" << endl;
	cout << endl;
	cout << " +++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << " Current receipt has " << currReceipt.numberOfItems << " items, for a total of " << currReceipt.totalValue << " leva" << endl;
	cout << " +++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << endl;

	cout << " What is your wish, master?" << endl;
	// userInput;
	//getline(cin, userInput);
	//cin >> userInput;
	//return userInput;
}
	


bool CheckInventory(string itemID)
{
	for each (SaleItem item in inventory)
	{
		if (item.ID == itemID)
		{
			cout << " I found your item and it costs " << item.price << " leva" << endl;
			system("pause");
			return true;
		}

		else {
			cout << "Item cannot be found" << endl;
			system("pause");
			return false;
		}
	}
}	

void PriceChange(string itemID, float newPrice)
{
	for each (SaleItem &item in inventory)
	{
		if (item.ID == itemID)
		{
			cout << "I am now fetching yout item so you can change its price. curent price is " << item.price << " leva" << endl;	
			item.price = newPrice;
			//item.ChangePrice(newPrice);
			cout << "Price changed, now it is " << item.price << " leva" << endl;			
			//system("pause");			
		}
	}
}

void AddItemTopUrchase(Receipt &currReceipt, string itemID)
{
	for each (SaleItem item in inventory)
	{
		if (item.ID == itemID)
		{
			currReceipt.totalValue += item.price; // to be done with an operator override laters.
			currReceipt.numberOfItems++;
			cout << "I found your item and i added it to the purchase!" << endl;
			cout << "Now your total is: " << currReceipt.totalValue << endl;
			
			//system("pause");
			
		}		
	}
}


// really need a SaleItem GetItem(SaleItem* inventory[], string itemId) fuction.. 
//but i cant figure out how to write it to return a pointer to the object,
//or the object itself for that matter.
//this looping thru the array everywhere needs to stop.
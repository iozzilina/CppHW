#include <iostream>
#include <array>
#include <ostream>
#include <string>
#include <sstream>

using namespace std;

// TODO: Array of SaleItems as a field for Receipt
// related: operator override
// find a spot for the copy constructor?



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

	void CalculateChange() {
		this->change = this->cashIn - this->totalValue;
	};
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

	//PurchaseItems arrays for quantity, Total price += foreach(item)quant.price
	
	void ChangePrice(float newPrice) {
		this->price = newPrice;
	}

};

SaleItem* inventory[] =
{
	new SaleItem("aaaaaaaaaa",10.00f),
	new SaleItem("bbbbbbbbbb",10.11f),
	new SaleItem("cccccccccc",10.12f),
	new SaleItem("111111111c",10.13f),
	new SaleItem("222222222b",10.14f),
	new SaleItem("555555555c",10.15f),
	new SaleItem("666666666d",10.16f),
	new SaleItem("777777777e",10.17f),
	new SaleItem("888888888f",10.18f),
    new SaleItem("999999999g",10.19f)
};

void MainMenu(Receipt &currReceipt);
bool CheckInventory(string ItemID);
void PriceChange(SaleItem* currSaleItem, float newPrice);
void AddItemToPurchase(Receipt &currReceipt, SaleItem* currSaleItem);
SaleItem* GetItemByID(string itemId);


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
		//cout << "you entered "<<userInput << endl;

		if (userInput.length() == 10)
		{
			cout << "You entered "<<userInput<<". Let me check if we have that."<< endl;
			if (CheckInventory(userInput))
			{
				SaleItem* currObject = GetItemByID(userInput);
				//cout << "pointing to " <<currObject << endl;
				AddItemToPurchase(currReceipt, currObject);		
				currReceipt.CalculateChange();
				system("pause");
			}							
		}

		if (userInput == "C")
		{
			currReceipt.totalValue = 0;
			currReceipt.numberOfItems = 0;
			cout << "Zeroing the current order"<<endl;
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
			currReceipt.CalculateChange();
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
			
			cout << "You entered "<< itemId <<". Let me check if we have that. "<< endl;

			if (CheckInventory(itemId))
			{
				cout << "Enter new price for that item: ";	

				getline(cin, price);			
				stream << price;
				stream >> newPrice;

				SaleItem* currObject = GetItemByID(itemId);

				PriceChange(currObject,newPrice);
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

		/*else
		{
			cout << "invalid selection" << endl;
			system("pause");	
		}*/

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
	cout << " C - clear purchase" << endl;
	cout << " T - display current purchase total" << endl;
	cout << " G - enter customer moneys given" << endl;
	cout << " P - change the price of an item in the inventory" << endl;
	cout << " I - print recepit" << endl;
	cout << " END - to exit" << endl;
	cout << " +++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << " Current purchase " << currReceipt.numberOfItems << " items, total of " << currReceipt.totalValue << " leva . Cash Given is "<<currReceipt.cashIn<<". Change due is "<< currReceipt.change << endl;
	cout << " +++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << " Inventory: " << endl;	

	for each (SaleItem* item in inventory)
	{
		cout << item->ID << " - " << item->price<<endl;
	}

    cout << " Enter a 10 character item id to add to the purchase, or select from the menu above"<<endl;
	cout << " What is your wish, master?" << endl;
	// userInput;
	//getline(cin, userInput);
	//cin >> userInput;
	//return userInput;
}
	
bool CheckInventory(string itemID)
{	
	for each (SaleItem* itemPointer in inventory)
	{
		//cout << "checking if " <<itemPointer->ID<< " is in inventory" << endl;

		if (itemPointer->ID == itemID)
		{
			cout << " I found your item and it costs " << itemPointer->price << " leva" << endl;
			//system("pause");
			return true;
		}
	}

	cout << "Item cannot be found" << endl;
	system("pause");
	return false;
}	


void PriceChange(SaleItem* currSaleItem, float newPrice)
{			
	//cout << "I am now fetching yout item so you can change its price. Current price is " << currSaleItem->price << " leva" << endl;	
	currSaleItem->price = newPrice;
	//item.ChangePrice(newPrice);
	cout << "Price changed, now it is " << currSaleItem->price << " leva" << endl;
	//system("pause");				
}

void AddItemToPurchase(Receipt &currReceipt, SaleItem* currSaleItem)
{	
	currReceipt.totalValue += currSaleItem->price; 
	// to be done with an operator override laters.
	//maybe add to the receipt array, not just the total value?

	currReceipt.numberOfItems++;
	cout << "I have added item "<< currSaleItem->ID<<" to the purchase!" << endl;
	cout << "Now your total is: " << currReceipt.totalValue << endl;			
	//system("pause");
}

SaleItem* GetItemByID(string itemId)
{
	for each (SaleItem* itemPointer in inventory)
	{
		if (itemPointer ->ID == itemId)
		{
			return itemPointer;
		}
	}
}

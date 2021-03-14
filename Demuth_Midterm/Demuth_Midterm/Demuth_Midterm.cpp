//Demuth ITDEV-185-900

#include <iostream>
#include <vector>
#include "Item.h"
#include <iomanip>
#include <cstdlib>
using namespace std;

MeasuredProduct m;//declared outside main to allow access by all functions within the .cpp
FreshProduce f;
Item it;

double Item::delivery = 0;
double Item::tip = 0;

void menuSelection();
int  selectService();
void printMenu(vector<string>&);
void checkout();
void printVector(vector<string>&, vector<double>&);
void printVectorsLBS(vector<string>&, vector<double>&);

vector<Item*>cart;
vector<string> serviceType = { "Pick Up", "Delivery" ,"Exit" };
vector<string> mainMenu = { "Fresh Produce","Meat and Seafood","Frozen Foods"};
vector<string> produceNames = { "Gala apples","Bananas","Grapes"};
vector<double> producePrices = { 3.99, .48, 2.99 };
vector<string> meatNames = { "Whole Chicken", "Ground Beef", "Salmon" };
vector<double> meatPrices = { 6.99, 4.99, 9.99 };
vector<string> frozenNames = { "Waffles", "Pizza", "Popsicle" };
vector<double> frozenPrices = { 6.99, 4.99, 2.99 };

int main()
{
	switch (selectService())
	{
		//clear screen
	case 1:	
		menuSelection();
		break;

	case 2:
		it.setDelivery(20.00);//setting delivery to 20
		it.setTip(5.00);//setting tip to 5
		menuSelection();
		break;

	case 3:
		exit(0);

	}
}

int selectService() // function to take user input and determine the service they would like
{
	system("CLS");
	cout << "****************************************" << endl;
	int selection = 3;

	cout << "(1) Pick Up\n" << "(2) Delivery\n" << "\n(3) Exit" << endl;;
	cout << "****************************************" << endl;
	cin >> selection;

	if (selection == 1 || selection == 2)
	{
		return selection;
	}
	else
	{
		exit(0);
	}


}

void menuSelection()
{
	system("CLS");
	int selection = 0;
	int i = 0;
	double lbs;
	int quantity;
	printMenu(mainMenu);
	cin >> selection;
	do {
		switch (selection)
		{
		case 1: // case used for selection of fresh produce
			printVectorsLBS(produceNames, producePrices);
			cout << "\n(4) Return to Menu" << endl;
			cout << "****************************************" << endl;
			cin >> (i);
			
				if (i == 1 || i == 2 || i == 3)
				{
					f.setName(produceNames[i - 1]); //setting frozen product name
					f.setPrice(producePrices[i - 1]);//setting frozen product price
					cout << "Wieght in pounds?" << endl;
					cin >> lbs;
					f.setPounds(lbs); //setting the weight chosen
					cart.push_back(new Item(f.getName(), f.calcPrice())); //loading vector with an item object containing the freshproduct name and price
				
				}
				else if (i == 4)
				{
					menuSelection();
				}
				else
				{
					cout << "Error";
				}
			break;

		case 2: // case used for selection of meat
			printVectorsLBS(meatNames, meatPrices);
			cout << "\n(4) Return to Menu" << endl;
			cout << "****************************************" << endl;
			cin >> (i);
			
				if (i == 1 || i == 2 || i == 3)
				{
					f.setName(meatNames[i - 1]);
					f.setPrice(meatPrices[i - 1]);
					cout << "Weight in pounds?" << endl;
					cin >> lbs;
					f.setPounds(lbs);
					cart.push_back(new Item(f.getName(), f.calcPrice()));
				}
				else if (i == 4)
				{
					menuSelection();
				}
				else
				{
					cout << "Error";
				}
			break;

		case 3: // case used for selection of frozen product
			printVector(frozenNames, frozenPrices);
			cout << "\n(4) Return to Menu" << endl;
			cout << "****************************************" << endl;
			cin >> i;
			
				if (i == 1 || i == 2 || i == 3)
				{
					m.setName(frozenNames[i-1]); // setting measured product name equal to the point within the vector selected by the user.
					m.setPrice(frozenPrices[i-1]); //setting measured product price equal to the point withing the vector selected by the user.
					cout << "Total quantity desired?" << endl;
					cin >> quantity;
					m.setQuantity(quantity);
					cart.push_back(new Item(m.getName(), m.getPrice()));// loading cart vector with an item objoect containing name and price
				}
				else if (i == 4)
				{
					menuSelection();
				}
				else
				{
					cout << "Error";
				}
			break;

		case 4:
			checkout();
			break;

		default:
			cout << "Error";
			break;
		}
	} while (selection != 4);
	exit(0);

}


void printMenu(vector<string>& n) //passing in vector and looping through to display the menu
{
	cout << "****************************************" << endl;
	for (int i = 0; i < n.size(); i++)
	{
		cout << "(" << i + 1 << ") " << n[i] << "\t" << endl;
	}
	cout << "\n(4) Checkout" << endl;
	cout << "****************************************" << endl;

}

void printVectorsLBS(vector<string>& n, vector<double>& m )// passing in vectors and looping through to create the menu
{
	system("CLS");
	cout << "****************************************" << endl;
	for (int i = 0; i < n.size(); i++)
	{
		cout << "(" << i + 1 << ") "  << left << setw(15) << n[i]  << right << setw(6)<< "$  "  << m[i] << "/lb" << endl;
	}

}

void printVector(vector<string>& n, vector<double>& m) // passing in vectors and looping through to create the menu
{
	system("CLS");//clearing screen to keep selection clean
	cout << "****************************************" << endl;
	for (int i = 0; i < n.size(); i++)
	{
		cout << "(" << i + 1 << ") " << left << setw(15) << n[i] << right << setw(6) << "$  " << m[i] << endl;

	}
}

void checkout()
{
	system("CLS");
	cout << "***************************************" << endl;
	double total = 0;
	for (int i = 0; i < cart.size(); i++)//looping through cart vector to display name and price of each object
	{
		cout << setw(17) << cart[i]->getName()<<"   " << right << "$  " << right << setw(5) << cart[i]->getPrice() << endl;
		total += cart[i]->getPrice(); // adding the price of each object to determine the total
	}
	total += it.getDelivery() + it.getTip(); //adding tip and delivery charge to the total.. will be 0 if pickup is selected
	
	cout << endl;
	cout << setw(20) << "Tip   " << right << "$  " << setw(5) << fixed << setprecision(2) << it.getTip() << endl;
	cout << setw(20) << "Delivery   " << right << "$  " << setw(5) << fixed << setprecision(2) << it.getDelivery() << endl;
	cout << setw(20) << "" << right << "___________" << setw(5) << endl;
	cout << setw(20) << "Total   " << right << "$  " << setw(5) << total << endl;
	cout << endl;
	cout << endl;
	cout << "****************************************" << endl;
	cout << "****************************************" << endl;
	cout << "Thanks for your order, Application closing" << endl;
}

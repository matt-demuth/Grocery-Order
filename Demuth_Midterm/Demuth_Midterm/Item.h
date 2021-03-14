#pragma once
#include <iostream>
using namespace std;
class Item
{
	friend class FreshProduce;
	friend class MeasuredProduct;
private:
	string name;
	double price;
	static double delivery;
	static double tip;

public:
	Item(void);
	Item(string, double);
	static double getDelivery();
	const string getName();
	double getPrice();
	static double getTip();
	void setDelivery(double);
	void setName(string);
	void setPrice(double);
	void setTip(double);

};

class FreshProduce : public Item // declaring child of item
{
	friend class Item;
private:
	double pounds;

public:
	FreshProduce(void);
	double calcPrice();
	double getPounds();
	void setPounds(double);
};

class MeasuredProduct : public Item // declaring child of item
{
private:
	int quantity;

public:
	MeasuredProduct(void);
	double calcPrice();
	int getQuantity();
	void setQuantity(double);
};


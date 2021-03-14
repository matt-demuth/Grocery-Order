#include "Item.h"
Item::Item(void)
{

}

Item::Item(string name, double price)
{
	this->name = name;
	this->price = price;
}

double Item::getDelivery() 
{
	return delivery;
}

void Item::setDelivery(double delivery)
{
	this->delivery = delivery;
}


void Item::setName(string name)
{
	this->name = name;
}

const string Item::getName()
{
	return name;
}


double Item::getPrice()
{
	return price;
}

void Item::setPrice(double price)
{
	this->price = price;
}

double Item::getTip()
{
	return tip;
}

void Item::setTip(double tip)
{
	this->tip = tip;
}

FreshProduce::FreshProduce(void)
{
	calcPrice();
}


double FreshProduce::calcPrice() 
{
	price = getPrice()* getPounds();
	return price;
}

double FreshProduce::getPounds()
{
	return pounds;

}

void FreshProduce::setPounds(double pounds)
{
	this->pounds = pounds;
}

MeasuredProduct::MeasuredProduct(void)
{

	calcPrice();
}

double MeasuredProduct::calcPrice()
{
	price = getPrice() * getQuantity();
	return price;
}

int MeasuredProduct::getQuantity()
{
	return quantity;
}

void MeasuredProduct::setQuantity(double quantity)
{
	this->quantity = quantity;
}
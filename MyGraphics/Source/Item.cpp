#include "Item.h"


CItem::CItem(void)
{
	name = "undefined";
	price = 0.0f;
}


CItem::~CItem(void)
{
}


void CItem::SetData(string a, float b)
{
	name = a;
	
	price = b;
}

string CItem::getName(void)
{
	return name;
}

float CItem::getPrice(void)
{
	return price;
}
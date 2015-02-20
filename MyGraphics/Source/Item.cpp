#include "Item.h"


CItem::CItem(void)
{
	name = "undefined";
	price = 0.0f;
	isRender = true;
	meshPtr = (NULL);
}


CItem::~CItem(void)
{
}


void CItem::SetData(string a, float b, bool d, Mesh* e)
{
	name = a;
	
	price = b;
	
	
	isRender = d;

	meshPtr = e;
}

string CItem::getName(void)
{
	return name;
}

float CItem::getPrice(void)
{
	return price;
}

bool CItem::getRender(void)
{
	return isRender;
}

Mesh* CItem::getMesh(void)
{
	return meshPtr;
}

void CItem::setRender(bool a)
{
	isRender = a;
}
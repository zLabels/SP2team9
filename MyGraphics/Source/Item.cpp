#include "Item.h"


CItem::CItem(void)
{
	name = "undefined";
	price = 0.0f;
	isRender = true;
	meshPtr = (NULL);
	objType = 0;
}

CItem::~CItem(void)
{
}

void CItem::SetData(string a, float b, bool d, Mesh* e,int f)
{
	name = a;
	
	price = b;
	
	isRender = d;

	meshPtr = e;

	objType = f;
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

int CItem::getobjType(void)
{
	return objType;
}

void CItem::setRender(bool a)
{
	isRender = a;
}

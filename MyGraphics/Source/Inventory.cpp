#include "Inventory.h"

CInventory::CInventory(void)
{
	NoOfItems = -1;
}


CInventory::~CInventory(void)
{
}

void CInventory::AddItem(CItem temp)
{
	if(NoOfItems + 1 < 10)
	{
		Container.push_back(temp);
		NoOfItems++;
	}
}

void CInventory::RemoveItem(int pos)
{
	pos = pos - 1;
	if(NoOfItems > 0)
	{
		Container.erase(Container.begin() + pos);
	}
}

CItem CInventory::getInventory(void)
{
	return Container[10];
}
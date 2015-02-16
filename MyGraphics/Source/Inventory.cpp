#include "Inventory.h"

CInventory::CInventory(void)
{
	Container[10];
	NoOfItems = -1;
}


CInventory::~CInventory(void)
{
}

void CInventory::AddItem(CItem temp)
{
	if(NoOfItems + 1 < 10)
	{
		Container[NoOfItems + 1] = temp;
		NoOfItems++;
	}
}

CItem CInventory::getInventory(void)
{
	return Container[10];
}
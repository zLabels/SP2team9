#include "Inventory.h"

CInventory::CInventory(void)
{
	NoOfItems = 0;
	ptr = (NULL);
}


CInventory::~CInventory(void)
{
}

void CInventory::AddItem(CItem temp)
{
	if(NoOfItems < 10)
	{
		Container.push_back(temp);
		NoOfItems++;
	}
}

CItem CInventory::getItem(int pos)
{
	return Container[pos];
}

void CInventory::removeItem(int pos)
{

}

void CInventory::DeleteAll(void)
{
	Container.clear();
}

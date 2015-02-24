#include "Inventory.h"

CInventory::CInventory(void)
{
	NoOfItems = 0;
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
	if( pos <= NoOfItems)
	{
		Container.erase(Container.begin()+pos);
		NoOfItems--;
	}
}

void CInventory::removeItem(CItem temp)
{
	for(int i = 0; i < Container.size(); ++i)
	{
		if(Container[i].getobjType() == temp.getobjType())
		{
			Container.erase(Container.begin()+i);
			NoOfItems--;
		}
	}
}

void CInventory::DeleteAll(void)
{
	Container.clear();
}
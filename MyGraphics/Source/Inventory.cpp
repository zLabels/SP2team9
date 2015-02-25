#include "Inventory.h"

CInventory::CInventory(void)
{
}


CInventory::~CInventory(void)
{
}

void CInventory::AddItem(CItem temp)
{
	if(Container.size() < 10)
	{
		Container.push_back(temp);
	}
}

CItem CInventory::getItem(int pos)
{
	pos = pos - 1;
	if(pos < Container.size())
	{
		return Container[pos];
	}
}

int CInventory::getNoOfItems(void)
{
	return Container.size();
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
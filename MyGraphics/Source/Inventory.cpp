#include "Inventory.h"

CInventory::CInventory(void)
{
}


CInventory::~CInventory(void)
{
}

bool CInventory::AddItem(CItem temp)
{
	if(Inventory.size() < 10)
	{
		Inventory.push_back(temp);
		return true;
	}
	else
	{
		return false;
	}
}

CItem CInventory::getItem(int pos)
{
	pos = pos - 1;
	if(pos < Inventory.size())
	{
		return Inventory[pos];
	}
}

int CInventory::getNoOfItems(void)
{
	return Inventory.size();
}

void CInventory::removeItem(int pos)
{
	pos = pos - 1;
	if( pos <= Inventory.size())
	{
		Inventory.erase(Inventory.begin()+pos);
	}
}

bool CInventory::removeItem(CItem temp)
{
	for(int i = 0; i < Inventory.size(); ++i)
	{
		if(Inventory[i].getobjType() == temp.getobjType() && Inventory[i].getPaid() == temp.getPaid())
		{
			Inventory.erase(Inventory.begin()+i);
			return true;
		}
	}
	return false;
}

void CInventory::DeleteAll(void)
{
	Inventory.clear();
}
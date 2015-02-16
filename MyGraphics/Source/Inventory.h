#pragma once
#include <string>
#include "Item.h"

using std::string;

class CInventory
{
public:
	CInventory(void);
	~CInventory(void);

	CItem getInventory(void);

	void AddItem(CItem temp);

private:
	CItem Container[10];
	int NoOfItems;
};


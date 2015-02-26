#pragma once
#include <string>
#include <vector>
#include "Item.h"
#include <iostream>

using std::string;
using std::vector;

class CInventory
{
public:
	CInventory(void);
	~CInventory(void);

	bool AddItem(CItem temp);
	CItem getItem(int pos);
	int getNoOfItems(void);
	void DeleteAll(void);
	void removeItem(int pos);
	void removeItem(CItem temp);

private:
	vector<CItem> Inventory;
};


#pragma once
#include <string>
#include <vector>
#include "Item.h"

using std::string;
using std::vector;

class CInventory
{
public:
	CInventory(void);
	~CInventory(void);

	void AddItem(CItem temp);
	CItem getItem(int pos);
	void DeleteAll(void);
	void removeItem(int pos);
	void removeItem(CItem temp);

private:
	vector<CItem> Container;
	int NoOfItems;
};


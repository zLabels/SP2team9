#pragma once
#include <string>
#include "Item.h"
#include <vector>

using std::string;
using std::vector;


class CInventory
{
public:
	CInventory(void);
	~CInventory(void);

	CItem getInventory(void);

	void AddItem(CItem temp);
	void RemoveItem(int pos);

private:
	vector<CItem> Container;
	int NoOfItems;
};


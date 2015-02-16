#pragma once
#include <string>
#include "Item.h"

using std::string;

class CInventory
{
public:
	CInventory(void);
	~CInventory(void);

private:
	string Invent[10];
	CItem Item;
};


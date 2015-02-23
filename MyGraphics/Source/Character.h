#pragma once
#include "Inventory.h"
#include "Vector3.h"

class CCharacter
{
public:
	CCharacter(void);
	~CCharacter(void);
	CInventory getInventory(void);
	float getMoney(void);

private:
	CInventory Inventory;
	float Money;
	
};


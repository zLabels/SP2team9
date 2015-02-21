#pragma once
#include "Inventory.h"
#include "Vector3.h"

class CCharacter
{
public:
	CCharacter(void);
	~CCharacter(void);

private:
	CInventory Inventory;
	float Money;
	Vector3 Position;

	
};


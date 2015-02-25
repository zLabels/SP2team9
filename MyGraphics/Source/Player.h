#pragma once
#include "Character.h"
#include "Inventory.h"

class CPlayer : public CCharacter
{
public:
	CPlayer(void);
	~CPlayer(void);
	float getMoney(void);
	CInventory getInventory(void);

private:
	CInventory Invent;
	float Money;
};


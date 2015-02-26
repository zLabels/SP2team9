#pragma once
#include "Character.h"
#include "Inventory.h"

class CPlayer : public CCharacter
{
public:
	CPlayer(void);
	~CPlayer(void);
	void setMoney(float a);
	float getMoney(void);
	CInventory& getInventory(void);

private:
	CInventory Invent;
	float Money;
};


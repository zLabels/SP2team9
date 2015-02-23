#include "Character.h"

CCharacter::CCharacter(void)
{
	Money = 100.0f;
}

CCharacter::~CCharacter(void)
{
}

CInventory CCharacter::getInventory(void)
{
	return Inventory;
}

float CCharacter::getMoney(void)
{
	return Money;
}
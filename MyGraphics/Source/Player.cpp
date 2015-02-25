#include "Player.h"

CPlayer::CPlayer(void)
{
	Money = 100.f;
}

CPlayer::~CPlayer(void)
{
}

float CPlayer::getMoney(void)
{
	return Money;
}

CInventory CPlayer::getInventory(void)
{
	return Invent;
}

#include "Player.h"

CPlayer::CPlayer(void)
{
	Money = 0.f;
}

CPlayer::~CPlayer(void)
{
}

void CPlayer::setMoney(float a)
{
	Money = a;
}

float CPlayer::getMoney(void)
{
	return Money;
}

CInventory& CPlayer::getInventory(void)
{
	return Invent;
}


#include "MenuClass.h"


Menu::Menu(void)
{
	StartGameTrue =
	StartGameFalse =
	EndGameTrue =
	EndGameFalse =
	Arrow =
	MenuBackground =
	GameOver = 0;

	pointToGame = true;
	pointToExit = false;
	showMenu = true;
	GameOverState = false;
}

Menu::~Menu(void)
{
}

void Menu::SetBackground(int newObj)
{
	MenuBackground = newObj;
}

int Menu::getBackgroundMesh()
{
	return MenuBackground;
}

void Menu::SetArrow(int newObj)
{
	Arrow = newObj;
}
int Menu::getArrowMesh()
{
	return Arrow;
}

//=========================SET GAME TRUE================================//
void Menu::SetStartGameTrue(int newObj)
{
	StartGameTrue = newObj;
}
int Menu::getStartGameTrueMesh()
{
	return StartGameTrue;
}

//=========================SET GAME FALSE================================//
void Menu::SetStartGameFalse(int newObj)
{
	StartGameFalse = newObj;
}
int Menu::getStartGameFalseMesh()
{
	return StartGameFalse;
}

//=========================END GAME TRUE================================//
void Menu::SetEndGameTrue(int newObj)
{
	EndGameTrue = newObj;
}

int Menu::getEndGameTrueMesh()
{
	return EndGameTrue;
}
//=========================END GAME FALSE================================//
void Menu::SetEndGameFalse(int newObj)
{
	EndGameFalse = newObj;
}

int Menu::getEndGameFalseMesh()
{
	return EndGameFalse;
}

bool Menu::getPointToGame()
{
	return pointToGame;
}

bool Menu::getPointToExit()
{
	return pointToExit;
}

bool Menu::getShowMenuStatus()
{
	return showMenu;
}

void Menu::SetGameOverMesh(int newObj)
{
	GameOver = newObj;
}

int Menu::getGameOverMesh()
{
	return GameOver;
}

void Menu::update(double dt)
{
	static float elapsedTime1 = 0, elapsedTime2 = 0;
	elapsedTime1 = fmod(Timer.getElapsedTime(), 1);

	if (elapsedTime2 <= 0.5)
	{
		elapsedTime2 += elapsedTime1;
	}
	else
	{
		elapsedTime2 += 0;
	}

	if(Application::IsKeyPressed(VK_UP) && elapsedTime2 >= 0.5 ||
		Application::IsKeyPressed(VK_DOWN) && elapsedTime2 >= 0.5)
	{

		//=======================Pointing to start game====================//
		if (pointToGame == true && pointToExit == false ||
			pointToGame == true && pointToExit == false)
		{
			pointToGame = false;
			pointToExit = true;
		}//=======================Pointing to End game====================//
		else if (pointToGame == false && pointToExit == true ||
				pointToGame == false && pointToExit == true)
		{
			pointToGame = true;
			pointToExit = false;
		}
		elapsedTime2 -= 0.5;
	}

	if (pointToGame == true && pointToExit == false) //Start Game
	{
		if(Application::IsKeyPressed(VK_RETURN))
		{
			showMenu = false;
		}
	}
	if (pointToGame == false && pointToExit == true) // End Game
	{
		if (Application::IsKeyPressed(VK_RETURN))
		{
			exit (NULL);
		}
	}

	if (Application::IsKeyPressed('R') == true && showMenu == false)
	{
		showMenu = true;
		pointToGame = true;
		pointToExit = false;
	}
}

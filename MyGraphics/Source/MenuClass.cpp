/******************************************************************************/
/*!
\file	Ai.cpp
\author Ong Swee Seng
\par	email: 142128G@mymail.nyp.edu.sg
\brief
Ai Class
*/
/******************************************************************************/

#include "MenuClass.h"

/******************************************************************************/
/*!
\brief
Default constructor for class
*/
/******************************************************************************/
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
/******************************************************************************/
/*!
\brief
Set background enum position

\param newObj - enum position
*/
/******************************************************************************/
void Menu::SetBackground(int newObj)
{
	MenuBackground = newObj;
}

/******************************************************************************/
/*!
\brief
get background enum position
*/
/******************************************************************************/
int Menu::getBackgroundMesh()
{
	return MenuBackground;
}

/******************************************************************************/
/*!
\brief
Set arrow enum position

\param newObj - enum position
*/
/******************************************************************************/
void Menu::SetArrow(int newObj)
{
	Arrow = newObj;
}
/******************************************************************************/
/*!
\brief
get arrow enum position
*/
/******************************************************************************/
int Menu::getArrowMesh()
{
	return Arrow;
}

//=========================SET GAME TRUE================================//
/******************************************************************************/
/*!
\brief
Set StartGametrue enum position

\param newObj - enum position
*/
/******************************************************************************/
void Menu::SetStartGameTrue(int newObj)
{
	StartGameTrue = newObj;
}
/******************************************************************************/
/*!
\brief
get StartGametrue enum position
*/
/******************************************************************************/
int Menu::getStartGameTrueMesh()
{
	return StartGameTrue;
}

//=========================SET GAME FALSE================================//
/******************************************************************************/
/*!
\brief
Set StartGameFalse enum position

\param newObj - enum position
*/
/******************************************************************************/
void Menu::SetStartGameFalse(int newObj)
{
	StartGameFalse = newObj;
}
/******************************************************************************/
/*!
\brief
get StartGameFalse enum position
*/
/******************************************************************************/
int Menu::getStartGameFalseMesh()
{
	return StartGameFalse;
}

//=========================END GAME TRUE================================//
/******************************************************************************/
/*!
\brief
Set EndGameTrue enum position

\param newObj - enum position
*/
/******************************************************************************/
void Menu::SetEndGameTrue(int newObj)
{
	EndGameTrue = newObj;
}
/******************************************************************************/
/*!
\brief
get EndGameTrue enum position
*/
/******************************************************************************/
int Menu::getEndGameTrueMesh()
{
	return EndGameTrue;
}
//=========================END GAME FALSE================================//
/******************************************************************************/
/*!
\brief
Set EndGameFalse enum position

\param newObj - enum position
*/
/******************************************************************************/
void Menu::SetEndGameFalse(int newObj)
{
	EndGameFalse = newObj;
}
/******************************************************************************/
/*!
\brief
get EndGameFalse enum position
*/
/******************************************************************************/
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

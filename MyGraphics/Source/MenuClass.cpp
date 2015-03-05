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
	pointToControl = false;
	showControl = false;
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

void Menu::SetControlMesh(int newObj)
{
	Control = newObj;
}

int Menu::getControlMesh()
{
	return Control;
}

void Menu::SetPointControlTrue(int newObj)
{
	PointToControlTrue = newObj;
}

int Menu::getControlTrueMesh()
{
	return PointToControlTrue;
}

void Menu::SetPointControlFalse(int newObj)
{
	PointToControlFalse = newObj;
}

int Menu::getControlFalseMesh()
{
	return PointToControlFalse;
}

bool Menu::getShowContorlStatus()
{
	return showControl;
}

bool Menu::getPointToContorl()
{
	return pointToControl;
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

	//======================UP ARROW KEY==================//
	if(Application::IsKeyPressed(VK_UP) && elapsedTime2 >= 0.5)
	{
		//=======================Pointing to start game====================//
		if (pointToGame == true && pointToExit == false && pointToControl == false)
		{
			pointToGame = false;
			pointToExit = true;
			pointToControl = false;
		}//=======================Pointing to Controls====================//
		else if (pointToGame == false && pointToExit == false && pointToControl == true)
		{
			pointToGame = true;
			pointToExit = false;
			pointToControl = false;
		}//=======================Pointing to End game====================//
		else if (pointToGame == false && pointToExit == true && pointToControl == false)
		{
			pointToGame = false;
			pointToExit = false;
			pointToControl = true;
		}
		elapsedTime2 -= 0.5;
	}

	//======================DOWN ARROW KEY==================//
	if(Application::IsKeyPressed(VK_DOWN) && elapsedTime2 >= 0.5)
	{
		//=======================Pointing to start game====================//
		if (pointToGame == true && pointToExit == false && pointToControl == false)
		{
			pointToGame = false;
			pointToExit = false;
			pointToControl = true;
		}//=======================Pointing to Controls====================//
		else if (pointToGame == false && pointToExit == false && pointToControl == true)
		{
			pointToGame = false;
			pointToExit = true;
			pointToControl = false;
		}//=======================Pointing to End game====================//
		else if (pointToGame == false && pointToExit == true && pointToControl == false)
		{
			pointToGame = true;
			pointToExit = false;
			pointToControl = false;
		}
		elapsedTime2 -= 0.5;
	}

	if (pointToGame == true && pointToExit == false && pointToControl == false) //Start Game
	{
		if(Application::IsKeyPressed(VK_RETURN))
		{
			showMenu = false;
		}
	}
	if (pointToGame == false && pointToExit == false && pointToControl == true) //Show Control
	{
		if(Application::IsKeyPressed(VK_RETURN))
		{
			showControl = true;
		}
	}
	if (pointToGame == false && pointToExit == true && pointToControl == false) // End Game
	{
		if (Application::IsKeyPressed(VK_RETURN))
		{
			exit (NULL);
		}
	}

	if (Application::IsKeyPressed('R') && showMenu == false ||
		Application::IsKeyPressed('R') && showControl == true)
	{
		showMenu = true;
		pointToGame = true;
		pointToExit = false;
		pointToControl = false;
		showControl = false;
	}
}

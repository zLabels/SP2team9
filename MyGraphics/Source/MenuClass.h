#pragma once
#include <string>
#include "Vector3.h"
#include "Mesh.h"
#include "Mtx44.h"
#include "Player.h"
#include "MatrixStack.h"
#include "Application.h"
#include "timer.h"

using std::string;
using std::cout;
using std::endl;

class Menu
{
public:
	Menu(void);
	~Menu(void);

	void SetBackground(int newObj);
	void SetArrow(int newObj);
	void SetStartGameTrue(int newObj);
	void SetStartGameFalse(int newObj);
	void SetEndGameTrue(int newObj);
	void SetEndGameFalse(int newObj);
	void SetGameOverMesh(int newObj);

	void update(double dt);

	int getBackgroundMesh();
	int getArrowMesh();
	int getStartGameTrueMesh();
	int getStartGameFalseMesh();
	int getEndGameTrueMesh();
	int getEndGameFalseMesh();
	int getGameOverMesh();
	bool getPointToGame();
	bool getPointToExit();
	bool getShowMenuStatus();

private:
	int StartGameTrue,
		StartGameFalse,
		EndGameTrue,
		EndGameFalse,
		Arrow,
		MenuBackground,
		GameOver;

	bool pointToGame,
		pointToExit,
		showMenu,
		GameOverState;

	StopWatch Timer;
};


#pragma once
#include "Character.h"
#include "timer.h"
#include "Application.h"
#include "Mtx44.h"

class CGuard : public CCharacter
{
public:
	CGuard(void);
	~CGuard(void);
	void SetData(Vector3 pos, Vector3 targ);
	Vector3 getGuardPosition();
	void getDifference(Vector3 camerapos);
	float getDerivedAngle();
	int getState();
	void guardUpdate(float dt,Vector3 camerapos);
	void setState(int a);

private:
	Vector3 guardPos;
	Vector3 guardTarget;
	Vector3 guardView;
	Vector3 guardDifference;
	Vector3 initialPos;

	float derivedAngle;
	int state;

	enum States
	{
		S_IDLE,
		S_ALERT,
		S_MAX,
	};

	StopWatch Timer;
};


#ifndef AI_H
#define AI_H

#include "Camera.h"
#include <iostream>
#include <vector>
#include "Vector3.h"
#include "timer.h"

class Ai : public Camera
{
public:
	Ai();
	~Ai();

	void passInPositionAndTarget(Vector3, Vector3);
	void update(float, Vector3);
	void FindPlayerDistanceDifference(Vector3);
	void FindPlayerDistanceDifferencePasserby(Vector3);

	void SetPasserby(Vector3);

	float getDerivedAngle();
	float getPasserbyAngle();
	Vector3 getGuardPosition();
	Vector3 getPasserbyPosition();

private:
	Vector3 guardPos;
	Vector3 guardTarget;
	Vector3 guardView;
	Vector3 guardDifference;

	Vector3 PasserbyPos;
	Vector3 PasserbyDifference;

	float derivedAngle;
	float PasserbyAngle;
	bool guardAlertState;

	bool Passerby1Phase1, Passerby1Phase2, Passerby1Phase3, Passerby1Phase4;

	StopWatch Timer;
};

#endif
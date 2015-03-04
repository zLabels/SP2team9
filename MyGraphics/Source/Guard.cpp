#include "Guard.h"


CGuard::CGuard(void)
{
	guardPos.SetZero();
	guardTarget.SetZero();
	guardView.SetZero();
	guardDifference.SetZero();
	initialPos.SetZero();

	derivedAngle = 0.f;
	state = 0;
}


CGuard::~CGuard(void)
{
}

void CGuard::SetData(Vector3 pos, Vector3 targ)
{
	guardPos = pos;
	initialPos = pos;
	guardTarget = targ;
	guardView = (guardTarget - guardPos).Normalized();
}
void CGuard::guardUpdate(float dt, Vector3 camerapos)
{
	//==================================GUARD=====================//
	//Rotation following player
	derivedAngle = Math::RadianToDegree(acos(guardView.Dot(guardDifference) / (guardView.Length() * guardDifference.Length())));
	if(guardView.Cross(guardDifference).y > 1)
	{
		derivedAngle *= 1;
	}
	else
	{
		derivedAngle *= -1;
	}
	//std::cout << derivedAngle << std::endl;

	if(state == S_ALERT)
	{
		//Movement of guard to player
		guardPos += (guardDifference.Normalized()) * 10 * dt;
	}
	if(state == S_IDLE)
	{
		if(guardPos != initialPos)
		{
			Vector3 diffinitialPos = initialPos - guardPos;
			guardPos += (diffinitialPos.Normalized()) * 10 * dt;
		}
	}
}

void CGuard::getDifference(Vector3 camerapos)
{
	guardDifference = camerapos - guardPos;
}
Vector3 CGuard::getGuardPosition()
{
	return guardPos;
}

float CGuard::getDerivedAngle()
{
	return derivedAngle;
}

int CGuard::getState()
{
	return state;
}

void CGuard::setState(int a)
{
	state = a;
}
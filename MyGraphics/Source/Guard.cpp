#include "Guard.h"


CGuard::CGuard(void)
{
	guardPos.SetZero();
	guardTarget.SetZero();
	guardView.SetZero();
	guardDifference.SetZero();

	derivedAngle = 0.f;
	state = 0;
}


CGuard::~CGuard(void)
{
}

void CGuard::SetData(Vector3 pos, Vector3 targ)
{
	guardPos = pos;
	guardTarget = targ;
	guardView = (guardTarget - guardPos).Normalized();
}
void CGuard::guardUpdate(float dt, Vector3 camerapos)
{
	//==================================GUARD=====================//
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
	static float elapsedTime1 = 0, elapsedTime2 = 0;
	elapsedTime1 = fmod(Timer.getElapsedTime(), 1);
	if (elapsedTime2 <= 1)
	{
		elapsedTime2 += elapsedTime1;
	}
	else
	{
		elapsedTime2 += 0;
	}
	if (Application::IsKeyPressed('0') && elapsedTime2 >= 1)
	{
		state = S_ALERT;
	}
	if (state == S_ALERT)
	{
		guardPos += (guardDifference.Normalized()) * 10 * dt;
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

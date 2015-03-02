#include "Ai.h"
#include "Application.h"
#include "Mtx44.h"

Ai::Ai()
{
	derivedAngle = 0;
	guardAlertState = false;
	PasserbyAngle = 180;
	Passerby1Phase1 = Passerby1Phase2 = Passerby1Phase3 = Passerby1Phase4 = false;
}

Ai::~Ai()
{
}

void Ai::passInPositionAndTarget(Vector3 pos, Vector3 target)
{
	guardPos = pos;
	guardTarget = target;
	guardView = (guardTarget - guardPos).Normalized();
}

void Ai::update(float dt, Vector3 camera)
{
	//==================================GUARD=====================//
	derivedAngle = Math::RadianToDegree(acos(guardView.Dot(guardDifference) / (guardView.Length() * guardDifference.Length())));
	if (camera.z <= 0)
	{
		derivedAngle  = derivedAngle + 270;
	}
	else
	{
		derivedAngle = -(derivedAngle + 90);
	}
	
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
		if (guardAlertState == false)
		{
			guardAlertState = true;
		}
		else if (guardAlertState == true)
		{
			guardAlertState = false;
		}
		elapsedTime2 -= 1;
	}

	if (guardAlertState == true)
	{
		if (Application::IsKeyPressed('8'))
		{
			if (guardPos.x > guardDifference.x)
			{
				guardPos.x -= sin(Math::DegreeToRadian(derivedAngle)) * 10 * dt;
			}
			else if (guardPos.x <= guardDifference.x)
			{
				guardPos.x += sin(Math::DegreeToRadian(derivedAngle)) * 10 * dt;
			}

			if (guardPos.z > guardDifference.z)
			{
				guardPos.z += cos(Math::DegreeToRadian(derivedAngle)) * 10 * dt;
			}
			else if (guardPos.z <= guardDifference.z)
			{
				guardPos.z -= cos(Math::DegreeToRadian(derivedAngle)) * 10 * dt;
			}
		}
	}

	//========================PASSERBY 1==========================//
	if (PasserbyDifference.Length() > 6)
	{
		if (PasserbyPos.z < 31.5 && PasserbyPos.x == 0 && PasserbyAngle ==180)
		{
			PasserbyPos.z += 10 * dt;
			if (PasserbyPos.z >= 31.5)
			{
				PasserbyPos.z = 31.5;
			}

		}
		if (PasserbyPos.z == 31.5 && PasserbyAngle < 270 && PasserbyPos.x == 0)
		{
			PasserbyAngle += 100 * dt;
			if (PasserbyAngle >= 270)
			{
				PasserbyAngle = 270;
			}
		}

		if (PasserbyAngle == 270 && PasserbyPos.z == 31.5 && PasserbyPos.x < 48.5)
		{
			PasserbyPos.x += 10 * dt;
			if (PasserbyPos.x >= 48.5)
			{
				PasserbyPos.x = 48.5;
			}
		}

		if (PasserbyPos.x == 48.5 && PasserbyPos.z == 31.5 && PasserbyAngle > 180)
		{
			PasserbyAngle -= 100 * dt;
			if (PasserbyAngle < 180)
			{
				PasserbyAngle = 180;
			}
		}
	
		if (PasserbyAngle == 180 && PasserbyPos.z  < 55 && PasserbyPos.x == 48.5)
		{
			PasserbyPos.z += 10 * dt;
			if (PasserbyPos.z > 55)
			{
				PasserbyPos.z = 55;
			}
		}

		if (PasserbyAngle > 90 && PasserbyPos.z == 55 && PasserbyPos.x == 48.5)
		{
			PasserbyAngle -= 100 * dt;
			if (PasserbyAngle <= 90)
			{
				PasserbyAngle = 90;
			}
		}

		if (PasserbyAngle == 90 && PasserbyPos.x > -33 && PasserbyPos.z == 55)
		{
			PasserbyPos.x -= 10 * dt;
			if (PasserbyPos.x < -33)
			{
				PasserbyPos.x = -33;
			}
		}

		if (PasserbyAngle < 360 && PasserbyPos.x == -33 && PasserbyPos.z == 55)
		{
			PasserbyAngle += 100 * dt;
			if (PasserbyAngle > 360)
			{
				PasserbyAngle = 360;
			}
		}

		if (PasserbyAngle == 360 && PasserbyPos.x == -33 && PasserbyPos.z > 31.5)
		{
			PasserbyPos.z -= 10 * dt;
			if (PasserbyPos.z < 31.5)
			{
				PasserbyPos.z = 31.5;
			}
		}

		if (PasserbyAngle > 270 && PasserbyPos.x == -33 && PasserbyPos.z == 31.5)
		{
			PasserbyAngle -= 100 * dt;
			if (PasserbyAngle < 270)
			{
				PasserbyAngle = 270;
			}
		}
	}
	std::cout << PasserbyDifference.Length() << std::endl;
}

void Ai::FindPlayerDistanceDifference(Vector3 cameraPosition)
{
	guardDifference = cameraPosition - guardPos;
	
}

void Ai::FindPlayerDistanceDifferencePasserby(Vector3 cameraPosition)
{
	PasserbyDifference = cameraPosition - PasserbyPos;
}

void Ai::SetPasserby(Vector3 PasserbyPassIn)
{
	PasserbyPos = PasserbyPassIn;
}

float Ai::getDerivedAngle()
{
	return derivedAngle;
}

Vector3 Ai::getGuardPosition()
{
	return guardPos;
}

float Ai::getPasserbyAngle()
{
	return PasserbyAngle;
}

Vector3 Ai::getPasserbyPosition()
{
	return PasserbyPos;
}
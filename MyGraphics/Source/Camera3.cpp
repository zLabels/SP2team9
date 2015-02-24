#include "Camera3.h"
#include "Application.h"
#include "Mtx44.h"

Camera3::Camera3()
{
}

Camera3::~Camera3()
{
}

void Camera3::Init(const Vector3& pos, const Vector3& target, const Vector3& up)
{
	escal = false;
	escaldown = false;
	this->position = defaultPosition = pos;
	this->target = defaultTarget = target;
	Vector3 view = (target - position).Normalized();
	Vector3 right = view.Cross(up);
	right.y = 0;
	right.Normalize();
	this->up = defaultUp = right.Cross(view).Normalized();
	temp = 0;
	isCrouching = false;
	Crouching = false;
	Jumping = false;
	isJumping = false;
	isFalling = false;
	tempJumpY = 0.f;
	CAMERA_SPEED = 15.f;
	JUMP_SPEED = 12.f;
	//=======Collision=========//
	//Middle shelf
	maxPos.Set(13.4, 10, 15.2);
	minPos.Set(8.3, -10, -9.3);
	maximum.push_back(maxPos);
	minimum.push_back(minPos);

	//Left shelf (closer to cashier)
	maxPos.Set(18.3,10,-33.5);
	minPos.Set(-30.6,-10,-37.5);
	maximum.push_back(maxPos);
	minimum.push_back(minPos);

	//Extreme left shelf
	maxPos.Set(21.5,10,-55.7);
	minPos.Set(-33.1,-10,-60.7);
	maximum.push_back(maxPos);
	minimum.push_back(minPos);

	//Left frozen food shelf
	maxPos.Set(36.1,10,-88.2);
	minPos.Set(-35.5,-10,-94);
	maximum.push_back(maxPos);
	minimum.push_back(minPos);

	//Back frozen food shelf
	maxPos.Set(54.8,10,63.4);
	minPos.Set(48.9,-10,-77.5);
	maximum.push_back(maxPos);
	minimum.push_back(minPos);

	//Right wooden shelf
	maxPos.Set(18.6,10,36.8);
	minPos.Set(-30.3,-10,32.4);
	maximum.push_back(maxPos);
	minimum.push_back(minPos);

	//extreme Right Metal shelf
	maxPos.Set(21.4,10,60.3);
	minPos.Set(-33.2,-10,55.3);
	maximum.push_back(maxPos);
	minimum.push_back(minPos);

	//Right metal fence
	maxPos.Set(-18.7,6,27.2);
	minPos.Set(-30.6,-5,24.9);
	maximum.push_back(maxPos);
	minimum.push_back(minPos);

	//Middle metal fence
	maxPos.Set(-19.6,6,8.7);
	minPos.Set(-29.3,-5,7.2);
	maximum.push_back(maxPos);
	minimum.push_back(minPos);

	//Left metal fence
	maxPos.Set(-18.9,6,-9.1);
	minPos.Set(-29.6,-5,-11.4);
	maximum.push_back(maxPos);
	minimum.push_back(minPos);

	//Right cashier
	maxPos.Set(-18,6,22);
	minPos.Set(-30,-5,17.6);
	maximum.push_back(maxPos);
	minimum.push_back(minPos);

	//Right cashier (cash register)
	maxPos.Set(-26.6,6,19);
	minPos.Set(-29.9,-5,14);
	maximum.push_back(maxPos);
	minimum.push_back(minPos);

	//Middle cashier
	maxPos.Set(-18.1,6,4.6);
	minPos.Set(-30.1,-5,0.84);
	maximum.push_back(maxPos);
	minimum.push_back(minPos);

	//Middle cashier(Cash Register)
	maxPos.Set(-26,6,2.1);
	minPos.Set(-30.1,-5,-2.1);
	maximum.push_back(maxPos);
	minimum.push_back(minPos);

	//Left Cashier
	maxPos.Set(-18,6,-13);
	minPos.Set(-30.4,-5,-17.1);
	maximum.push_back(maxPos);
	minimum.push_back(minPos);

	//Left Cashier(Cash Register)
	maxPos.Set(-26,6,-17);
	minPos.Set(-30.5,-5,-20.4);
	maximum.push_back(maxPos);
	minimum.push_back(minPos);

	//Right entrance (wall)
	maxPos.Set(-53.8,40,96.2);
	minPos.Set(-57,-5,19.4);
	maximum.push_back(maxPos);
	minimum.push_back(minPos);

	//Left entrance (wall)
	maxPos.Set(-54.3,40,-19.2);
	minPos.Set(-57,-5,-96.2);
	maximum.push_back(maxPos);
	minimum.push_back(minPos);

	//Left side (wall)
	maxPos.Set(56.8,40,-93.5);
	minPos.Set(-57,-5,-96.4);
	maximum.push_back(maxPos);
	minimum.push_back(minPos);

	//Back (wall)
	maxPos.Set(57.5,40,96.2);
	minPos.Set(54.5,-5,-96);
	maximum.push_back(maxPos);
	minimum.push_back(minPos);

	//Right side (wall)
	maxPos.Set(95,40,96.4);
	minPos.Set(-57.5,-5,93.2);
	maximum.push_back(maxPos);
	minimum.push_back(minPos);

	//Escalator bottom
	maxPos.Set(-6.9,10,91);
	minPos.Set(-28.4,-6,63.4);
	maximum.push_back(maxPos);
	minimum.push_back(minPos);
	
}

void Camera3::BoundsCheck()
{
	if(position.y >= 5)
	{
		position.y = tempPos.y;
		target.y = tempTarg.y;
	}
	if(position.y <= 5)
	{
		position.y = tempPos.y;
		target.y = tempTarg.y;
	}
}



void Camera3::bound(Vector3 maximum, Vector3 minimum)
{
	//===Collision==//

	if((position.x <= maximum.x) && (position.y <= maximum.y) &&(position.z <= maximum.z) && (position.x >= minimum.x) && (position.y >= minimum.y)&& (position.z >= minimum.z) )
	{
		position.x = tempPos.x;
		position.y = tempPos.y;
		position.z = tempPos.z;

		target.x = tempTarg.x;
		target.y = tempTarg.y;
		target.z = tempTarg.z;
	}
}

void Camera3::Update(double dt)
{
	static const float TURN_SPEED = 100.f;
	bool walk = true;
	/*===========================================================
							MOVING AROUND
	==============================================================*/
	//==========STRAFE LEFT===========//
	//Sprint
	
	if(Application::IsKeyPressed(VK_SHIFT) && Application::IsKeyPressed('A') && escal == false)
	{
		if(CAMERA_SPEED <= 30)
		{
			CAMERA_SPEED += (float)(10*dt);
		}

		tempPos = position;
		tempTarg = target;

		Vector3 view = (target - position).Normalized();
		Vector3 right = view.Cross(up);
		right.y = 0;
		right.Normalize();
		position -= right * CAMERA_SPEED * dt;
		target -= right * CAMERA_SPEED * dt;

		tempView = view;
		//===Collision Check==//
		BoundsCheck();

		for(int i = 0; i < maximum.size();i++)
		{
			bound(maximum[i], minimum[i]);
		}

	}
	//Walk
	else if(Application::IsKeyPressed('A'))
	{
		if(CAMERA_SPEED >15.f)
		{
			CAMERA_SPEED -= (float)(10*dt);
		}
		tempPos = position;
		tempTarg = target;

		Vector3 view = (target - position).Normalized();
		Vector3 right = view.Cross(up);
		right.y = 0;
		right.Normalize();
		position -= right * CAMERA_SPEED * dt;
		target -= right * CAMERA_SPEED * dt;

		tempView = view;
		//===Collision Check==//
		BoundsCheck();

		for(int i = 0; i < maximum.size();i++)
		{
			bound(maximum[i], minimum[i]);
		}
	}
	//=========MOVE BACKWARDS==========//
	//Sprint
	else if(Application::IsKeyPressed(VK_SHIFT) && Application::IsKeyPressed('S'))
	{
		if(CAMERA_SPEED <= 30)
		{
			CAMERA_SPEED += (float)(10*dt);
		}
		tempPos = position;
		tempTarg = target;

		Vector3 view = (target - position).Normalized();
		target -= view * CAMERA_SPEED * dt;
		position -= view * CAMERA_SPEED * dt;

		tempView = view;

		//===Collision Check==//

		BoundsCheck();

		for(int i = 0; i < maximum.size();i++)
		{
			bound(maximum[i], minimum[i]);
		}
	}
	//Walk
	else if(Application::IsKeyPressed('S'))
	{
		if(CAMERA_SPEED >15.f)
		{
			CAMERA_SPEED -= (float)(10*dt);
		}
		tempPos = position;
		tempTarg = target;

		Vector3 view = (target - position).Normalized();
		target -= view * CAMERA_SPEED * dt;
		position -= view * CAMERA_SPEED * dt;

		tempView = view;

		//===Collision Check==//

		BoundsCheck();

		for(int i = 0; i < maximum.size();i++)
		{
			bound(maximum[i], minimum[i]);
		}
	}

	//=============STRAFE RIGHT================//
	//Sprint
	else if(Application::IsKeyPressed(VK_SHIFT) && Application::IsKeyPressed('D'))
	{
		if(CAMERA_SPEED <= 30)
		{
			CAMERA_SPEED += (float)(10*dt);
		}
		tempPos = position;
		tempTarg = target;

		Vector3 view = (target - position).Normalized();
		Vector3 right = view.Cross(up);
		right.y = 0;
		right.Normalize();
		position += right * CAMERA_SPEED * dt;
		target += right * CAMERA_SPEED * dt;

		tempView = view;

		//===Collision Check==//
		BoundsCheck();

		for(int i = 0; i < maximum.size();i++)
		{
			bound(maximum[i], minimum[i]);
		}
	}
	//Walk
	else if(Application::IsKeyPressed('D'))
	{
		if(CAMERA_SPEED >15.f)
		{
			CAMERA_SPEED -= (float)(10*dt);
		}
		tempPos = position;
		tempTarg = target;

		Vector3 view = (target - position).Normalized();
		Vector3 right = view.Cross(up);
		right.y = 0;
		right.Normalize();
		position += right * CAMERA_SPEED * dt;
		target += right * CAMERA_SPEED * dt;

		tempView = view;

		//===Collision Check==//
		BoundsCheck();

		for(int i = 0; i < maximum.size();i++)
		{
			bound(maximum[i], minimum[i]);
		}
	}

	//===============MOVE FORWARD==========//
	//Sprint
	else if(Application::IsKeyPressed(VK_SHIFT) && Application::IsKeyPressed('W'))
	{
		if(CAMERA_SPEED <= 30)
		{
			CAMERA_SPEED += (float)(10*dt);
		}
		tempPos = position;
		tempTarg = target;

		Vector3 view = (target - position).Normalized();
		target += view * CAMERA_SPEED * dt;
		position += view * CAMERA_SPEED * dt;

		tempView = view;

		//===Collision Check==//
		BoundsCheck();

		for(int i = 0; i < maximum.size();i++)
		{
			bound(maximum[i], minimum[i]);
		}
	}
	//Walk
	else if(Application::IsKeyPressed('W'))
	{
		if(CAMERA_SPEED >15.f)
		{
			CAMERA_SPEED -= (float)(10*dt);
		}
		tempPos = position;
		tempTarg = target;

		Vector3 view = (target - position).Normalized();
		target += view * CAMERA_SPEED * dt;
		position += view * CAMERA_SPEED * dt;

		tempView = view;

		//===Collision Check==//
		BoundsCheck();

		for(int i = 0; i < maximum.size();i++)
		{
			bound(maximum[i], minimum[i]);
		}
	}
	//Return to normal Speed
	else
	{
		if(CAMERA_SPEED >15.f)
		{
			CAMERA_SPEED -= (float)(10*dt);
		}
	}
	/*===================================================
					LOOKING AROUND
	=====================================================*/
	//==Look Right==//
	if(Application::IsKeyPressed(VK_RIGHT))
	{
		float pitch = (float)(-TURN_SPEED * dt);
		Vector3 view = (target - position).Normalized();
		Vector3 right = view.Cross(up);
		right.y = 0;
		right.Normalize();
		up = right.Cross(view).Normalized();
		Mtx44 rotation;
		rotation.SetToRotation(pitch, up.x, up.y, up.z);
		view = rotation * view;
		target = (rotation * (target - position)) + position;
	}
	//==Look Left==//
	if(Application::IsKeyPressed(VK_LEFT))
	{
		float pitch = (float)(TURN_SPEED * dt);
		Vector3 view = (target - position).Normalized();
		Vector3 right = view.Cross(up);
		right.y = 0;
		right.Normalize();
		up = right.Cross(view).Normalized();
		Mtx44 rotation;
		rotation.SetToRotation(pitch, up.x, up.y, up.z);
		view = rotation * view;
		target = (rotation * (target - position)) + position;
	}
	//==Look Down==//
	if(temp > -60)
	{
		if(Application::IsKeyPressed(VK_DOWN))
		{
			float pitch = (float)(-TURN_SPEED * dt);
			Vector3 view = (target - position).Normalized();
			Vector3 right = view.Cross(up);
			right.y = 0;
			right.Normalize();
			up = right.Cross(view).Normalized();
			Mtx44 rotation;
			rotation.SetToRotation(pitch, right.x, right.y, right.z);
			view = rotation * view;
			target = (rotation * (target - position)) + position;

			tempView = view;

			//==View Limiter==//
			temp--;
		}
	}
	//==Look Up==//
	if(temp < 80)
	{
		if(Application::IsKeyPressed(VK_UP))
		{
			float pitch = (float)(TURN_SPEED * dt);
			Vector3 view = (target - position).Normalized();
			Vector3 right = view.Cross(up);
			right.y = 0;
			right.Normalize();
			up = right.Cross(view).Normalized();
			Mtx44 rotation;
			rotation.SetToRotation(pitch, right.x, right.y, right.z);
			view = rotation * view;
			target = (rotation * (target - position)) + position;

			tempView = view;

			//==View Limiter==//
			temp++;
		}
	}
	

	//=====================================Escalator===============================================

	float y = 30-position.x; //Length across
	float x = 24.6-position.y; //Length Height
	float z = (pow(y ,2)+pow(x,2)); 
	float hyp = sqrt(z);
	std::cout << escal << std::endl;
	
	if (escal == true)
	{
		position.x +=(float)(hyp*dt);
		position.y +=(float)(x*dt);
		target.x +=(float)(14*dt);
		target.y +=(float)(4.5*dt);
		
	}

	if (escaldown == true)
	{
		position.x -=(float)(14*dt);
		position.y -=(float)(4.5*dt);
		target.x -=(float)(14*dt);
		target.y -=(float)(4.5*dt);
		
	}

	if(position.x >= -40 && position.x <=-30 && position.y >= 3 && position.y <=6 && position.z >= 64.9 && position.z <= 75) //Going up
	{	
		escal = true;
		walk = false;


	}
	if(position.x <=29.9 && position.y >= 20 && position.y <=30 && position.z >= 80 && position.z <=90) // going down
	{
		escaldown = true;
	}
	else if(position.x >= 28)
	{
		escal = false;
		
	}
	else if (position.y <= 5)
	{
		escaldown = false;
	}
	

	//==================================== end of escalator ============================= //
	/*====================================================================================
										JUMPING
	=======================================================================================*/
 	if(Application::IsKeyPressed(VK_SPACE) && isJumping == false && isFalling == false && Crouching == false && isCrouching == false)
	{
		Jumping = true;
		tempJumpY = position.y;
	}

	if(Jumping == true)
	{
		isJumping = true;
		
		if(position.y <= (tempJumpY + 3))
		{
			position.y += (float)(JUMP_SPEED * dt);
			target.y += (float)(JUMP_SPEED * dt);
			JUMP_SPEED -= (float)(20 * dt);
		}
		else
		{
			isJumping = false;
			Jumping = false;
			isFalling = true;
		}
	}
	if(isFalling == true)
	{
		if(position.y >= tempJumpY)
		{
			position.y -= (float)(JUMP_SPEED * dt);
			target.y -= (float)(JUMP_SPEED * dt);
			JUMP_SPEED += (float)(40 * dt);
		}
		if(position.y <= tempJumpY)
		{
			isFalling = false;
			JUMP_SPEED = 12.f;
		}
	}

	/*=======================================================================================
										CROUCHING
	======================================================================================*/
	if(Application::IsKeyPressed(VK_LCONTROL) && isCrouching == false && Crouching == false)
	{
		Crouching = true;
	}
	else if(Application::IsKeyPressed(VK_LCONTROL) && isCrouching == false && Crouching == true)
	{
		Crouching = false;
	}
	if(Crouching == true)
	{
		isCrouching = true;
		if(position.y >= 2.5)
		{
			position.y -= (float)(CAMERA_SPEED * dt);
			target.y  -= (float)(CAMERA_SPEED * dt);
		}
		else
		{
			isCrouching = false;
		}
	}
	else if(Crouching == false)
	{
		isCrouching = true;
		if(position.y < 5)
		{
			position.y += (float)(CAMERA_SPEED * dt);
			target.y  += (float)(CAMERA_SPEED * dt);
		}
		else
		{
			isCrouching = false;
		}
	}
	if(Application::IsKeyPressed('R'))
	{
		Reset();
	}
}


void Camera3::Reset()
{
	position = defaultPosition;
	target = defaultTarget;
	up = defaultUp;
}
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
	
	//=======Collision=========//

	//maxPos.Set(125, 140, -80);
	//minPos.Set(-25, -10, -125);
	//maximum.push_back(maxPos);
	//minimum.push_back(minPos);

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

void Camera3::escalator()
{
	/*if(position.x >= -40 && position.x <=-30 && position.y == 5 && position.z >= 64.9 && position.z <= 75)
	{	
		if(position.x < 28 && position.y <28)
		{
			position.x +=(float)(100*dt);
			position.y +=(float)(100*dt);
		}	
	}
	else
	{
		std::cout << "Mr Sim is awesome" << std::endl;
	}
	*/
}

void Camera3::bound(Vector3 maximum, Vector3 minimum)
{
	//===Collision==//

	/*if((position.x <= maximum.x) && (position.y <= maximum.y) &&(position.z <= maximum.z) && (position.x >= minimum.x) && (position.y >= minimum.y)&& (position.z >= minimum.z) )
	{
		position.x = tempPos.x;
		position.y = tempPos.y;
		position.z = tempPos.z;
		
		target.x = tempTarg.x;
		target.y = tempTarg.y;
		target.z = tempTarg.z;
	}*/
}

void Camera3::Update(double dt)
{
	static const float CAMERA_SPEED = 15.f;
	static const float TURN_SPEED = 60.f;

	if(Application::IsKeyPressed('A'))
	{
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
		/*
		for(int i = 0; i < maximum.size();i++)
		{
			bound(maximum[i], minimum[i]);
		}*/
	}
	
	/*if(Application::IsKeyPressed(VK_RIGHT))
	{
		Vector3 view = (target - position).Normalized();
		float yaw = (float)(-CAMERA_SPEED * dt);
		Mtx44 rotation;
		rotation.SetToRotation(yaw, 0, 1, 0);
		view = rotation * view;
		up = rotation * up;
		target = view + position;

		tempView = view;
	}*/
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
	if(Application::IsKeyPressed('D'))
	{
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
		/*
		for(int i = 0; i < maximum.size();i++)
		{
			bound(maximum[i], minimum[i]);
		}*/
	}
		
	/*if(Application::IsKeyPressed(VK_LEFT))
	{
		Vector3 view = (target - position).Normalized();
		float yaw = (float)(CAMERA_SPEED * dt);
		Mtx44 rotation;
		rotation.SetToRotation(yaw, 0, 1, 0);
		view = rotation * view;
		target = view + position;
		up = rotation * up;

		tempView = view;
	}*/
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

	if(Application::IsKeyPressed('W'))
	{
		tempPos = position;
		tempTarg = target;

		Vector3 view = (target - position).Normalized();
		target += view * CAMERA_SPEED * dt;
		position += view * CAMERA_SPEED * dt;

		tempView = view;

		//===Collision Check==//
		BoundsCheck();
		/*
		for(int i = 0; i < maximum.size();i++)
		{
			bound(maximum[i], minimum[i]);
		}*/
	}
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
	
	if(Application::IsKeyPressed('S'))
	{
		tempPos = position;
		tempTarg = target;

		Vector3 view = (target - position).Normalized();
		target -= view * CAMERA_SPEED * dt;
		position -= view * CAMERA_SPEED * dt;

		tempView = view;

		//===Collision Check==//

		BoundsCheck();
		/*
		for(int i = 0; i < maximum.size();i++)
		{
			bound(maximum[i], minimum[i]);
		}*/
	}
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
	
	//if (escal == true)
	//{
	//	position.x +=(float)(14*dt);
	//	position.y +=(float)(4.5*dt);
	//	target.x +=(float)(14*dt);
	//	target.y +=(float)(4.5*dt);
	//	
	//}

	//if (escaldown == true)
	//{
	//	position.x -=(float)(14*dt);
	//	position.y -=(float)(4.5*dt);
	//	target.x -=(float)(14*dt);
	//	target.y -=(float)(4.5*dt);
	//	
	//}

	//if(position.x >= -40 && position.x <=-30 && position.y <= 5 && position.z >= 64.9 && position.z <= 75) //Going up
	//{	
	//	escal = true;
	//	std::cout << "haha" << std::endl;

	//}
	//if(position.x <=29.9 && position.y >= 20 && position.y <=30 && position.z >= 80 && position.z <=90) // going down
	//{
	//	escaldown = true;
	//}
	//else if(position.x >= 28)
	//{
	//	escal = false;
	//	
	//}
	//else if (position.y <= 5)
	//{
	//	escaldown = false;
	//}
	//
	//else
	//{
	//	std::cout << "Mr Sim is awesome" << std::endl;
	//}
	if (position.x >= -31)
	{
		position.x +=(float)(14*dt);
		position.y +=(float)(4.5*dt);
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

	if(position.x >= -40 && position.x <=-30 && position.y <= 5 && position.z >= 64.9 && position.z <= 75) //Going up
	{	
		escal = true;
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
		if (position.y == 5)
		{
			std::cout << "Escalator detected" << std::endl;
		}
	//==================================== end of escalator ============================= //
	
	if(Application::IsKeyPressed('F'))
	{
		position.y += (float)(CAMERA_SPEED * dt);
		target.y  += (float)(CAMERA_SPEED * dt);
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
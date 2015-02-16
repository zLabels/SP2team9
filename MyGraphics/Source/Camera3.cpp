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
	static const float CAMERA_SPEED = 50.f;
	

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

		//===Collision Check==//
		/*BoundsCheck();
		
		for(int i = 0; i < maximum.size();i++)
		{
			bound(maximum[i], minimum[i]);
		}*/
	}
	
	if(Application::IsKeyPressed(VK_RIGHT))
	{
		Vector3 view = (target - position).Normalized();
		float yaw = (float)(-CAMERA_SPEED * dt);
		Mtx44 rotation;
		rotation.SetToRotation(yaw, 0, 1, 0);
		view = rotation * view;
		up = rotation * up;
		target = view + position;
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

		//===Collision Check==//
		/*BoundsCheck();

		for(int i = 0; i < maximum.size();i++)
		{
			bound(maximum[i], minimum[i]);
		}*/
	}
		
	if(Application::IsKeyPressed(VK_LEFT))
	{
		Vector3 view = (target - position).Normalized();
		float yaw = (float)(CAMERA_SPEED * dt);
		Mtx44 rotation;
		rotation.SetToRotation(yaw, 0, 1, 0);
		view = rotation * view;
		target = view + position;
		up = rotation * up;
	}
	if(Application::IsKeyPressed('W'))
	{
		tempPos = position;
		tempTarg = target;

		Vector3 view = (target - position).Normalized();
		target += view * CAMERA_SPEED * dt;
		position += view * CAMERA_SPEED * dt;

		//===Collision Check==//
		/*BoundsCheck();

		for(int i = 0; i < maximum.size();i++)
		{
			bound(maximum[i], minimum[i]);
		}*/
	}
	if(temp > -60)
	{
		if(Application::IsKeyPressed(VK_DOWN))
		{
			float pitch = (float)(-CAMERA_SPEED * dt);
			Vector3 view = (target - position).Normalized();
			Vector3 right = view.Cross(up);
			right.y = 0;
			right.Normalize();
			up = right.Cross(view).Normalized();
			Mtx44 rotation;
			rotation.SetToRotation(pitch, right.x, right.y, right.z);
			view = rotation * view;
			target = view + position;

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

		//===Collision Check==//

		/*BoundsCheck();

		for(int i = 0; i < maximum.size();i++)
		{
			bound(maximum[i], minimum[i]);
		}*/
	}
	if(temp < 80)
	{
		if(Application::IsKeyPressed(VK_UP))
		{
			float pitch = (float)(CAMERA_SPEED * dt);
			Vector3 view = (target - position).Normalized();
			Vector3 right = view.Cross(up);
			right.y = 0;
			right.Normalize();
			up = right.Cross(view).Normalized();
			Mtx44 rotation;
			rotation.SetToRotation(pitch, right.x, right.y, right.z);
			view = rotation * view;
			target = view + position;

			//==View Limiter==//
			temp++;
		}
	}
	
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
#ifndef CAMERA_3_H
#define CAMERA_3_H

#include "Camera.h"
#include <vector>

class Camera3 : public Camera
{
public:
	//Vector3 position;
	//Vector3 target;
	//Vector3 up;

	Vector3 defaultPosition;
	Vector3 defaultTarget;
	Vector3 defaultUp;

	Camera3();
	~Camera3();
	virtual void Init(const Vector3& pos, const Vector3& target, const Vector3& up);
	virtual void Update(double dt);
	virtual void Reset(void);
	void BoundsCheck(void);
	void bound(Vector3 maximum, Vector3 minimum);
	void setCheckingOut(bool a);
	std::vector<Vector3> maximum;
	std::vector<Vector3> minimum;
	Vector3 maxPos;
	Vector3 minPos;
	Vector3 tempPos;
	Vector3 tempTarg;

	bool escal;
	bool escaldown;
	bool isCrouching;
	bool Crouching;
	bool Jumping;
	bool isJumping;
	bool isFalling;
	bool walk;
	bool checkingOut;
	float tempJumpY;
	float tempJumpTargY;
	float tempCrouchY;
	float tempCrouchTargY;
	int temp;
	float CAMERA_SPEED;
	float JUMP_SPEED;
	bool CollisionWithAi;
};

#endif
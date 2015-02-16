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
	std::vector<Vector3> maximum;
	std::vector<Vector3> minimum;
	Vector3 maxPos;
	Vector3 minPos;
	Vector3 tempPos;
	Vector3 tempTarg;

	int temp;

};

#endif
#pragma once
#include "Vector3.h"
#include "Mesh.h"

class CCharacter
{
public:
	CCharacter(void);
	~CCharacter(void);

	void setCharacter(Mesh* head, Mesh* torso, Mesh* Lhand, Mesh* Rhand, Mesh* Lleg, Mesh* Rleg,Vector3 pos);
	void setPosition(float x, float y, float z);

	Mesh* getHead(void);
	Mesh* getTorso(void);
	Mesh* getLHand(void);
	Mesh* getRHand(void);
	Mesh* getLLeg(void);
	Mesh* getRLeg(void);
	Vector3 getPosition(void);

	Mesh* HeadPtr;
	Mesh* TorsoPtr;
	Mesh* leftHandPtr;
	Mesh* rightHandPtr;
	Mesh* leftLegPtr;
	Mesh* rightLegPtr;

	Vector3 position;
};


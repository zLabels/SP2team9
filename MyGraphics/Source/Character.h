#pragma once
#include "Vector3.h"
#include "Mesh.h"

class CCharacter
{
public:
	CCharacter(void);
	~CCharacter(void);

	void setCharacter(Mesh* head, Mesh* torso, Mesh* Lhand, Mesh* Rhand, Mesh* Lleg, Mesh* Rleg);

	Mesh* getHead(void);
	Mesh* getTorso(void);
	Mesh* getLHand(void);
	Mesh* getRHand(void);
	Mesh* getLLeg(void);
	Mesh* getRLeg(void);

	Mesh* HeadPtr;
	Mesh* TorsoPtr;
	Mesh* leftHandPtr;
	Mesh* rightHandPtr;
	Mesh* leftLegPtr;
	Mesh* rightLegPtr;
};


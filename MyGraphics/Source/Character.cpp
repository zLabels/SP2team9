#include "Character.h"

CCharacter::CCharacter(void)
{
	HeadPtr = (NULL);
	TorsoPtr = (NULL);
	leftHandPtr = (NULL);
	rightHandPtr = (NULL);
	leftLegPtr = (NULL);
	rightLegPtr = (NULL);

	position.Set(0.0f,0.0f,0.0f);
}

CCharacter::~CCharacter(void)
{
}

void CCharacter::setCharacter(Mesh* head, Mesh* torso, Mesh* Lhand, Mesh* Rhand, Mesh* Lleg, Mesh* Rleg,Vector3 pos)
{
	HeadPtr = head;
	TorsoPtr = torso;
	leftHandPtr = Lhand;
	rightHandPtr = Rhand;
	leftLegPtr = Lleg;
	rightLegPtr = Rleg;
	position = pos;
}

void CCharacter::setPosition(float x,float y,float z)
{
	position.x = x;
	position.y = y;
	position.z = z;
}

Mesh* CCharacter::getHead(void)
{
	return HeadPtr;
}
Mesh* CCharacter::getTorso(void)
{
	return TorsoPtr;
}
Mesh* CCharacter::getLHand(void)
{
	return leftHandPtr;
}
Mesh* CCharacter::getRHand(void)
{
	return rightHandPtr;
}
Mesh* CCharacter::getLLeg(void)
{
	return leftLegPtr;
}
Mesh* CCharacter::getRLeg(void)
{
	return rightLegPtr;
}

Vector3 CCharacter::getPosition(void)
{
	return position;
}
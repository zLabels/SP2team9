#pragma once
#include <string>
#include "Vector3.h"
#include "Mesh.h"
#include "Mtx44.h"

using std::string;

class CItem
{
public:
	CItem(void);
	~CItem(void);

	void SetData(string a, float b, bool d, Mesh* e,int f,Mtx44 g);
	
	void setRender(bool a);
	string getName(void);
	float getPrice(void);
	bool getRender(void);
	Mesh* getMesh(void);
	int getobjType(void);
	Mtx44 getTRS(void);

private:
	Mesh* meshPtr;
	string name;
	float price;
	bool isRender;
	int objType;
	Mtx44 TRS;
};


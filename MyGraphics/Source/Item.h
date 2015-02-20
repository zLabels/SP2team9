#pragma once
#include <string>
#include "Vector3.h"
#include "Mesh.h" 

using std::string;

class CItem
{
public:
	CItem(void);
	~CItem(void);

	void SetData(string a, float b, bool d, Mesh* e);
	
	void setRender(bool a);
	string getName(void);
	float getPrice(void);
	bool getRender(void);
	Mesh* getMesh(void);

private:
	Mesh* meshPtr;
	string name;
	float price;
	bool isRender;

};


#pragma once
#include <string>
#include "Mesh.h"

using std::string;

class CItem
{
public:
	CItem(void);
	~CItem(void);

	void SetData(string a, float b);
	
	string getName(void);
	float getPrice(void);

private:
	string name;
	float price;

};


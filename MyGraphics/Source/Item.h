#pragma once
#include <string>
#include "Mesh.h"

using std::string;

class CItem
{
public:
	CItem(void);
	~CItem(void);

private:
	string name;
	float price;
};


#pragma once
#include <string>

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
	CItem* itemPtr;
	string name;
	float price;

};


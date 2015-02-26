#include "CItemInventory.h"


CItemInventory::CItemInventory(void)
{	
	//Initalize all int to 0
	backgroundObj = 
	sardineObj = 
	PncObj = 
	BakedBeanObj = 
	PizzaboxObj = 
	Cereal1Obj = 
	Cereal2Obj =
	PotatoChipObj =
	CokeObj =
	PepsiObj =
	CokeZeroObj =
	MiloObj = 0;

	background =
	sardine =
	Pnc =
	BakedBean =
	Pizzabox =
	CerealBox1 =
	CerealBox2 =
	PototoChip =
	Coke =
	Pepsi =
	CokeZero = 
	Milo = "";

	for (int a = 0; a < 12; a++)
	{
		ItemsTaken[a] = false;
	}
}

CItemInventory::~CItemInventory(void)
{
}

void CItemInventory::SetBackground(string newName, int newObj)
{
	backgroundObj = newObj;
	background = newName;
}

int CItemInventory::getBackgroundMesh()
{
	return backgroundObj;
}

void CItemInventory::SetSardine(string newName, int newObj)
{
	sardineObj = newObj;
	sardine = newName;
}
int CItemInventory::getSardineMesh()
{
	return sardineObj;
}
string CItemInventory::getSardineName()
{
	return sardine;
}

void CItemInventory::SetPnc(string newName, int newObj)
{
	PncObj = newObj;
	Pnc = newName;
}
int CItemInventory::getPncMesh()
{
	return PncObj;
}
string CItemInventory::getPncName()
{
	return Pnc;
}

void CItemInventory::setBakedBean(string newName, int newObj)
{
	BakedBeanObj = newObj;
	BakedBean = newName;
}
int CItemInventory::getBakedBeanMesh()
{
	return BakedBeanObj;
}
string CItemInventory::getBakedBeanName()
{
	return BakedBean;
}

void CItemInventory::setPizzabox(string newName, int newObj)
{
	PizzaboxObj = newObj;
	Pizzabox = newName;
}
int CItemInventory::getPizzaboxMesh()
{
	return PizzaboxObj;
}
string CItemInventory::getPizzaboxName()
{
	return Pizzabox;
}

void CItemInventory::setCerealbox1(string newName, int newObj)
{
	Cereal1Obj = newObj;
	CerealBox1 = newName;
}
int CItemInventory::getCerealbox1Mesh()
{
	return Cereal1Obj;
}
string CItemInventory::getCerealbox1Name()
{
	return CerealBox1;
}

void CItemInventory::setCerealbox2(string newName, int newObj)
{
	Cereal2Obj = newObj;
	CerealBox2 = newName;
}
int CItemInventory::getCerealbox2Mesh()
{
	return Cereal2Obj;
}
string CItemInventory::getCerealbox2Name()
{
	return CerealBox2;
}

void CItemInventory::setPotatoChip(string newName, int newObj)
{
	PotatoChipObj = newObj;
	PototoChip = newName;
}
int CItemInventory::getPotatoChipMesh()
{
	return PotatoChipObj;
}
string CItemInventory::getPotatoChipName()
{
	return PototoChip;
}

void CItemInventory::setCoke(string newName, int newObj)
{
	CokeObj = newObj;
	Coke = newName;
}
int CItemInventory::getCokeMesh()
{
	return CokeObj;
}
string CItemInventory::getCokeName()
{
	return Coke;
}

void CItemInventory::setCokeZero(string newName, int newObj)
{
	CokeZeroObj = newObj;
	CokeZero = newName;
}
int CItemInventory::getCokeZeroMesh()
{
	return CokeZeroObj;
}
string CItemInventory::getCokeZeroName()
{
	return CokeZero;
}

void CItemInventory::setPepsi(string newName, int newObj)
{
	PepsiObj = newObj;
	Pepsi = newName;
}
int CItemInventory::getPepsiMesh()
{
	return PepsiObj;
}
string CItemInventory::getPepsiName()
{
	return Pepsi;
}

void CItemInventory::setMilo(string newName, int newObj)
{
	MiloObj = newObj;
	Milo = newName;
}
int CItemInventory::getMiloMesh()
{
	return MiloObj;
}
string CItemInventory::getMiloName()
{
	return Milo;
}

void CItemInventory::setCPlayer(CPlayer player)
{
	if (player.getInventory().getNoOfItems() == 1)
	{
		ItemsTaken[1] = true;
	}
	else if (player.getInventory().getNoOfItems() < 1)
	{
		ItemsTaken[1] = false;
	}

	if (player.getInventory().getNoOfItems() == 2)
	{
		ItemsTaken[2] = true;
	}
	else if (player.getInventory().getNoOfItems() < 2)
	{
		ItemsTaken[2] = false;
	}

	if (player.getInventory().getNoOfItems() == 3)
	{
		ItemsTaken[3] = true;
	}
	else if (player.getInventory().getNoOfItems() < 3)
	{
		ItemsTaken[3] = false;
	}

	if (player.getInventory().getNoOfItems() == 4)
	{
		ItemsTaken[4] = true;
	}
	else if (player.getInventory().getNoOfItems() < 4)
	{
		ItemsTaken[4] = false;
	}

	if (player.getInventory().getNoOfItems() == 5)
	{
		ItemsTaken[5] = true;
	}
	else if (player.getInventory().getNoOfItems() < 5)
	{
		ItemsTaken[5] = false;
	}

	if (player.getInventory().getNoOfItems() == 6)
	{
		ItemsTaken[6] = true;
	}
	else if (player.getInventory().getNoOfItems() < 6)
	{
		ItemsTaken[6] = false;
	}

	if (player.getInventory().getNoOfItems() == 7)
	{
		ItemsTaken[7] = true;
	}
	else if (player.getInventory().getNoOfItems() < 7)
	{
		ItemsTaken[7] = false;
	}

	if (player.getInventory().getNoOfItems() == 8)
	{
		ItemsTaken[8] = true;
	}
	else if (player.getInventory().getNoOfItems() < 8)
	{
		ItemsTaken[8] = false;
	}

	if (player.getInventory().getNoOfItems() == 9)
	{
		ItemsTaken[9] = true;
	}
	else if (player.getInventory().getNoOfItems() < 9)
	{
		ItemsTaken[9] = false;
	}

	if (player.getInventory().getNoOfItems() == 10)
	{
		ItemsTaken[10] = true;
	}
	else if (player.getInventory().getNoOfItems() < 10 )
	{
		ItemsTaken[10] = false;
	}
}
bool CItemInventory::getItemsTaken1()
{
	return ItemsTaken[1];
}

bool CItemInventory::getItemsTaken2()
{
	return ItemsTaken[2];
}

bool CItemInventory::getItemsTaken3()
{
	return ItemsTaken[3];
}

bool CItemInventory::getItemsTaken4()
{
	return ItemsTaken[4];
}

bool CItemInventory::getItemsTaken5()
{
	return ItemsTaken[5];
}

bool CItemInventory::getItemsTaken6()
{
	return ItemsTaken[6];
}

bool CItemInventory::getItemsTaken7()
{
	return ItemsTaken[7];
}

bool CItemInventory::getItemsTaken8()
{
	return ItemsTaken[8];
}

bool CItemInventory::getItemsTaken9()
{
	return ItemsTaken[9];
}

bool CItemInventory::getItemsTaken10()
{
	return ItemsTaken[10];
}
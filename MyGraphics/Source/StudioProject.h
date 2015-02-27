#ifndef _StudioProject_H
#define _StudioProject_H

#include "Scene.h"
#include "Mtx44.h"
#include "Mesh.h"
#include "MatrixStack.h"
#include "Light.h"
#include "Utility.h"
#include "Camera3.h"
#include <string>
#include <sstream>
#include "timer.h"

#include "Item.h"
#include "Inventory.h"
#include "Character.h"
#include "Guard.h"
#include "Player.h"
#include "Customer.h"
#include "Cashier.h"
#include "CItemInventory.h"
//#include "Security.h"

using std::string;

struct hitBox
{
	Vector3 max;
	Vector3 min;

	void SetBox(Vector3 a, Vector3 b)
	{
		max = a; 
		min = b;
	}
};

class StudioProject: public Scene
{
private:
	enum UNIFORM_TYPE
	{
		U_MVP = 0,
		U_MODELVIEW,
		U_MODELVIEW_INVERSE_TRANSPOSE,
		U_MATERIAL_AMBIENT,
		U_MATERIAL_DIFFUSE,
		U_MATERIAL_SPECULAR,
		U_MATERIAL_SHININESS,
		U_LIGHTENABLED,
		U_NUMLIGHTS,

		//Light 1
		U_LIGHT0_POSITION,
		U_LIGHT0_COLOR,
		U_LIGHT0_POWER,
		U_LIGHT0_KC,
		U_LIGHT0_KL,
		U_LIGHT0_KQ,
		U_LIGHT0_TYPE,
		U_LIGHT0_SPOTDIRECTION,
		U_LIGHT0_COSCUTOFF,
		U_LIGHT0_COSINNER,
		U_LIGHT0_EXPONENT,

		//Light2
		U_LIGHT1_POSITION,
		U_LIGHT1_COLOR,
		U_LIGHT1_POWER,
		U_LIGHT1_KC,
		U_LIGHT1_KL,
		U_LIGHT1_KQ,
		U_LIGHT1_TYPE,
		U_LIGHT1_SPOTDIRECTION,
		U_LIGHT1_COSCUTOFF,
		U_LIGHT1_COSINNER,
		U_LIGHT1_EXPONENT,

		//Light 3
		U_LIGHT2_POSITION,
		U_LIGHT2_COLOR,
		U_LIGHT2_POWER,
		U_LIGHT2_KC,
		U_LIGHT2_KL,
		U_LIGHT2_KQ,
		U_LIGHT2_TYPE,
		U_LIGHT2_SPOTDIRECTION,
		U_LIGHT2_COSCUTOFF,
		U_LIGHT2_COSINNER,
		U_LIGHT2_EXPONENT,

		//Light 4
		U_LIGHT3_POSITION,
		U_LIGHT3_COLOR,
		U_LIGHT3_POWER,
		U_LIGHT3_KC,
		U_LIGHT3_KL,
		U_LIGHT3_KQ,
		U_LIGHT3_TYPE,
		U_LIGHT3_SPOTDIRECTION,
		U_LIGHT3_COSCUTOFF,
		U_LIGHT3_COSINNER,
		U_LIGHT3_EXPONENT,

		//Light 5
		U_LIGHT4_POSITION,
		U_LIGHT4_COLOR,
		U_LIGHT4_POWER,
		U_LIGHT4_KC,
		U_LIGHT4_KL,
		U_LIGHT4_KQ,
		U_LIGHT4_TYPE,
		U_LIGHT4_SPOTDIRECTION,
		U_LIGHT4_COSCUTOFF,
		U_LIGHT4_COSINNER,
		U_LIGHT4_EXPONENT,

		//Light 6
		U_LIGHT5_POSITION,
		U_LIGHT5_COLOR,
		U_LIGHT5_POWER,
		U_LIGHT5_KC,
		U_LIGHT5_KL,
		U_LIGHT5_KQ,
		U_LIGHT5_TYPE,
		U_LIGHT5_SPOTDIRECTION,
		U_LIGHT5_COSCUTOFF,
		U_LIGHT5_COSINNER,
		U_LIGHT5_EXPONENT,

		//add these enum in UNIFORM_TYPE before U_TOTAL
		U_COLOR_TEXTURE_ENABLED,
		U_COLOR_TEXTURE,

		//Text
		U_TEXT_ENABLED,
		U_TEXT_COLOR,
		U_TOTAL,
	};


	enum GEOMETRY_TYPE
	{
		GEO_AXES,
		GEO_QUAD,
		GEO_LIGHTBALL,
		GEO_LIGHTBALL2,
		GEO_LIGHTBALL3,
		GEO_LIGHTBALL4,
		GEO_LIGHTBALL5,
		GEO_LIGHTBALL6,
		GEO_CUBE,
		GEO_CYLINDER,
		GEO_LEFT,
		GEO_RIGHT,
		GEO_TOP,
		GEO_BOTTOM,
		GEO_FRONT,
		GEO_BACK,
		GEO_FLOOR,
		//==Place New Geometry variable names here==//
		GEO_TEXT,
		GEO_FRONTSKY,	//Front skybox
		GEO_LEFTSKY,	//Left skybox
		GEO_RIGHTSKY,	//Right skybox
		GEO_BACKSKY,	//Back skybox
		GEO_SKY,        //Top of skybox
		GEO_BOTTOMSKY,  //bottom of skybox
		GEO_MARKET,
		GEO_CASHIER,
		GEO_CASHREG,
		GEO_COLDFOODSHELF,
		GEO_SHELF,
		GEO_SHELF2,
		GEO_RAIL,
		GEO_DOORLEFT,
		GEO_DOORRIGHT,

		GEO_SARDINE_CAN, //food items
		GEO_PEA_N_CARROTS,
		GEO_BAKED_BEANS_CAN,
		GEO_COKE_CAN,
		GEO_DRINKCAN2,
		GEO_PEPSI_CAN,
		GEO_MILOCAN,
		GEO_CEREALBOX1,
		GEO_CEREALBOX2,
		GEO_PIZZABOX,
		GEO_POTATOCHIPS,

		modelHead,			//Model Head
		modelTorso,			//Model Torso
		modelRightHand,		//Model Right Hand
		modelLeftHand,		//Model Left Hand
		modelLeftLeg,		//Model Left Leg
		modelRightLeg,		//Model Right Leg
		cashierHead,		//Cashier Head
		cashierTorso,		//Cashier Torso
		cashierRightHand,	//Cashier Right Hand
		cashierLeftHand,	//Cashier Left Hand
		cashierLeftLeg,		//Cashier Left Leg
		cashierRightLeg,	//Cashier Right Leg
		guardHead,			//Guard Head
		guardTorso,			//Guard Torso
		guardRightHand,		//Guard Right Hand
		guardLeftHand,		//Guard Left Hand
		guardLeftLeg,		//Guard Left Leg
		guardRightLeg,		//Guard Right Leg
		customerHead,		//Customer Head
		customerTorso,		//Customer Torso
		customerRightHand,	//Customer Right Hand
		customerLeftHand,	//Customer Left Hand
		customerLeftLeg,	//Customer Left Leg
		customerRightLeg,	//Customer Right Leg

		itemInventory,		//Item Inventory page
		cart,
		SC,					//Security Camera
		UI_SARDINE_CAN,
		UI_PEA_N_CARROTS,
		UI_BAKED_BEANS_CAN,
		UI_COKE_CAN,
		UI_COKE_ZERO_CAN,
		UI_PEPSI_CAN,
		UI_MILOCAN,
		UI_CEREALBOX1,
		UI_CEREALBOX2,
		UI_PIZZABOX,
		UI_POTATOCHIPS,
		NUM_GEOMETRY,
	};

	void RenderSkybox();
	void RenderSupermarket();
	void RenderModel();
	void RenderCashier();
	void RenderGuard();
	void RenderCustomer();
	void RenderItems();
	void RenderPlayerInfo();
	void RenderingSecurityCamera();
	void RenderItemsInfo();

public:
	StudioProject();
	~StudioProject();

	virtual void Init();
	virtual void Update(double dt);
	virtual void Render();
	virtual void Exit();
	void InitMesh();
	void InitVariables();
	void InitShaders();
	void InitCharacters();
	void InitSecurity();

private:
	unsigned m_vertexArrayID;
	Mesh* meshList[NUM_GEOMETRY];
	unsigned m_programID;
	unsigned m_parameters[U_TOTAL];

	double fps;
	string Framerate;
	string camerax;
	string cameray;
	string cameraz;
	string viewx;
	string viewy;
	string viewz;
	float worldsize;
	float roomsize;
	float roomheight;
	float moving;
	bool showInventory;
	StopWatch Timer;

	//=========Character=========//
	bool movingModel;
	float rotateRightArms, rotateLeftArms, rotateLeftLeg, rotateRightLeg;
	float movingCharacterX, movingCharacterZ;
	Vector3 charPosition;
	float playerAngle;
	float angle;
	//========Booleans for objs ======//
	bool Pizza;
	bool Peas;
	bool Milo;
	bool Cereal1;
	bool Cereal2;
	bool Sardine;
	bool Beans;
	bool Lays;
	bool Coke;
	bool Pepsi;
	string Cash;

	CPlayer player;
	CGuard Guard1;
	CGuard Guard2;

	CCashier Cashier1;
	CCashier Cashier2;
	CCashier Cashier3;

	CCustomer Customer;

	//Security CameraOBJ[3];
	CItemInventory Page;

	//=========Items=========//
	CItem sardineCan,
		PnCCan, 
		BBCan,
		MiloCan, 
		CokeCan,
		PizzaBox,
		CokeZeroCan,
		PepsiCan,
		cerealBox1,
		cerealBox2,
		PotatoChip;

	vector<CItem> Container,
				Container2, 
				Container3,
				Container4, 
				Container5,
				Container6,
				Container7,
				Container8, 
				Container9,
				Container10,
				Container11,
				Container12;

	vector<hitBox> boxContainer, 
				boxContainer2,
				boxContainer3,
				boxContainer4,
				boxContainer5, 
				boxContainer6,
				boxContainer7,
				boxContainer8,
				boxContainer9,
				boxContainer10,
				boxContainer11,
				boxContainer12,
				CashierBox;

	Camera3 camera;

	MS modelStack, viewStack, projectionStack;

	Light lights[7];
	CInventory in;
	void RenderMesh(Mesh *mesh, bool enableLight);


	//Text
	void RenderText(Mesh* mesh, std::string text, Color color);
	void RenderTextOnScreen(Mesh* mesh, std::string text, Color color, float size, float x, float y);
	void RenderImageOnScreen(Mesh* mesh, std::string text, Color color, float size, float x, float y);

};


#endif
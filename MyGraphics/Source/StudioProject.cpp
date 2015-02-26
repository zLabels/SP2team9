#include "StudioProject.h"
#include "GL\glew.h"

#include "shader.hpp"
#include "Mtx44.h"

#include "Application.h"
#include "MeshBuilder.h"

#include "Vertex.h"
#include "LoadTGA.h"

using std::cout;
using std::cin;
using std::endl;

StudioProject::StudioProject()
{
}

StudioProject::~StudioProject()
{
}
void StudioProject::InitMesh()
{
	//Initialize all meshes to NULL
	for(int i = 0; i < NUM_GEOMETRY; ++i)
	{
		meshList[i] = NULL;
	}
	meshList[GEO_AXES] = MeshBuilder::GenerateAxes("reference",Color(1,1,1),1000, 1000, 1000);
	meshList[GEO_CUBE] = MeshBuilder::GenerateCube("cube",Color(1,1,1), 1);

	/*
	========================Sky Box=====================================
	========================Sky Box=====================================
	========================Sky Box=====================================
	*/
	meshList[GEO_FRONTSKY] = MeshBuilder::GenerateQuad("Back", Color(1, 1, 1), 1.f , 1.f);
	meshList[GEO_FRONTSKY]->textureID = LoadTGA("Image//stormydays_ft.tga");

	meshList[GEO_BACKSKY] = MeshBuilder::GenerateQuad("Front", Color(1, 1, 1), 1.f , 1.f);
	meshList[GEO_BACKSKY]->textureID = LoadTGA("Image//stormydays_bk.tga");

	meshList[GEO_SKY] = MeshBuilder::GenerateQuad("top", Color(1, 1, 1), 1.f, 1.f);
	meshList[GEO_SKY]->textureID = LoadTGA("Image//stormydays_up.tga");

	meshList[GEO_LEFTSKY] = MeshBuilder::GenerateQuad("left", Color(1, 1, 1), 1.f,1.f);
	meshList[GEO_LEFTSKY]->textureID = LoadTGA("Image//stormydays_rt.tga");

	meshList[GEO_RIGHTSKY] = MeshBuilder::GenerateQuad("right", Color(1, 1, 1), 1.f, 1.f);
	meshList[GEO_RIGHTSKY]->textureID = LoadTGA("Image//stormydays_lf.tga");

	meshList[GEO_BOTTOMSKY] = MeshBuilder::GenerateQuad("bottom", Color(1, 1, 1), 1.f, 1.f);
	meshList[GEO_BOTTOMSKY]->textureID = LoadTGA("Image//stormydays_dn.tga");

	//===============SUPERMARKET RELATED OBJs==========================//

	meshList[GEO_MARKET] = MeshBuilder::GenerateOBJ("Market", "OBJ//market2.obj");
	meshList[GEO_MARKET]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_MARKET]->material.kDiffuse.Set(1.5f, 1.5f,1.5f);
	meshList[GEO_MARKET]->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_MARKET]->material.kShininess = 8.f;
	meshList[GEO_MARKET] ->textureID = LoadTGA("Image//Supermarket.tga");

	meshList[GEO_CASHIER] = MeshBuilder::GenerateOBJ("Market", "OBJ//Cashier_Counter.obj");
	meshList[GEO_CASHIER]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_CASHIER]->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	meshList[GEO_CASHIER]->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_CASHIER]->material.kShininess = 8.f;
	meshList[GEO_CASHIER] ->textureID = LoadTGA("Image//cashier_counter.tga");

	meshList[GEO_CASHREG] = MeshBuilder::GenerateOBJ("Market", "OBJ//cash-register.obj");
	meshList[GEO_CASHREG]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_CASHREG]->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	meshList[GEO_CASHREG]->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_CASHREG]->material.kShininess = 8.f;
	meshList[GEO_CASHREG] ->textureID = LoadTGA("Image//cashRegisterTexture.tga");

	meshList[GEO_COLDFOODSHELF] = MeshBuilder::GenerateOBJ("Market" , "OBJ//Cold-food-shelf.obj");
	meshList[GEO_COLDFOODSHELF]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_COLDFOODSHELF]->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	meshList[GEO_COLDFOODSHELF]->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_COLDFOODSHELF]->material.kShininess = 8.f;
	meshList[GEO_COLDFOODSHELF] ->textureID = LoadTGA("Image//Shelf_Texture.tga");

	meshList[GEO_SHELF] = MeshBuilder::GenerateOBJ("Market" , "OBJ//shelf1.obj");
	meshList[GEO_SHELF]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_SHELF]->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	meshList[GEO_SHELF]->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_SHELF]->material.kShininess = 8.f;
	meshList[GEO_SHELF] ->textureID = LoadTGA("Image//Shelf.tga");

	meshList[GEO_SHELF2] = MeshBuilder::GenerateOBJ("Market" , "OBJ//Shelf2.obj");
	meshList[GEO_SHELF2]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_SHELF2]->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	meshList[GEO_SHELF2]->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_SHELF2]->material.kShininess = 8.f;
	meshList[GEO_SHELF2] ->textureID = LoadTGA("Image//Shelf_Texture2.tga");

	meshList[GEO_RAIL] = MeshBuilder::GenerateOBJ("Railing" , "OBJ//Railing.obj");
	meshList[GEO_RAIL]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_RAIL]->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	meshList[GEO_RAIL]->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_RAIL]->material.kShininess = 8.f;
	meshList[GEO_RAIL] ->textureID = LoadTGA("Image//Railing.tga");

	//meshList[GEO_SARDINE_CAN] = MeshBuilder::GenerateOBJ("Railing" , "OBJ//canned-food1.obj");
	//meshList[GEO_SARDINE_CAN]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	//meshList[GEO_SARDINE_CAN]->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	//meshList[GEO_SARDINE_CAN]->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	//meshList[GEO_SARDINE_CAN]->material.kShininess = 8.f;
	//meshList[GEO_SARDINE_CAN] ->textureID = LoadTGA("Image//canned_food_1.tga");

	/*meshList[GEO_CANFOOD2] = MeshBuilder::GenerateOBJ("Railing" , "OBJ//canned-food2.obj");
	meshList[GEO_CANFOOD2]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_CANFOOD2]->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	meshList[GEO_CANFOOD2]->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_CANFOOD2]->material.kShininess = 8.f;
	meshList[GEO_CANFOOD2] ->textureID = LoadTGA("Image//canned_food_2.tga");*/

	/*meshList[GEO_CANFOOD3] = MeshBuilder::GenerateOBJ("Railing" , "OBJ//canned-food3.obj");
	meshList[GEO_CANFOOD3]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_CANFOOD3]->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	meshList[GEO_CANFOOD3]->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_CANFOOD3]->material.kShininess = 8.f;
	meshList[GEO_CANFOOD3] ->textureID = LoadTGA("Image//canned_food_3.tga");*/

	/*meshList[GEO_MILOCAN] = MeshBuilder::GenerateOBJ("Railing" , "OBJ//milocan.obj");
	meshList[GEO_MILOCAN]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_MILOCAN]->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	meshList[GEO_MILOCAN]->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_MILOCAN]->material.kShininess = 8.f;
	meshList[GEO_MILOCAN] ->textureID = LoadTGA("Image//milocan.tga");*/

	/*meshList[GEO_COKE_CAN] = MeshBuilder::GenerateOBJ("Coke" , "OBJ//drink-can1.obj");
	meshList[GEO_COKE_CAN]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_COKE_CAN]->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	meshList[GEO_COKE_CAN]->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_COKE_CAN]->material.kShininess = 8.f;
	meshList[GEO_COKE_CAN] ->textureID = LoadTGA("Image//drink_can1.tga");*/

	meshList[GEO_DRINKCAN2] = MeshBuilder::GenerateOBJ("Railing" , "OBJ//drink-can2.obj");
	meshList[GEO_DRINKCAN2]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_DRINKCAN2]->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	meshList[GEO_DRINKCAN2]->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_DRINKCAN2]->material.kShininess = 8.f;
	meshList[GEO_DRINKCAN2] ->textureID = LoadTGA("Image//drink_can2.tga");

	meshList[GEO_PEPSI_CAN] = MeshBuilder::GenerateOBJ("Railing" , "OBJ//drink-can3.obj");
	meshList[GEO_PEPSI_CAN]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_PEPSI_CAN]->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	meshList[GEO_PEPSI_CAN]->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_PEPSI_CAN]->material.kShininess = 8.f;
	meshList[GEO_PEPSI_CAN] ->textureID = LoadTGA("Image//drink_can3.tga");

	meshList[GEO_CEREALBOX1] = MeshBuilder::GenerateOBJ("Railing" , "OBJ//cereal-box1.obj");
	meshList[GEO_CEREALBOX1]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_CEREALBOX1]->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	meshList[GEO_CEREALBOX1]->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_CEREALBOX1]->material.kShininess = 8.f;
	meshList[GEO_CEREALBOX1] ->textureID = LoadTGA("Image//Cereal-box1.tga");

	meshList[GEO_CEREALBOX2] = MeshBuilder::GenerateOBJ("Railing" , "OBJ//cereal-box2.obj");
	meshList[GEO_CEREALBOX2]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_CEREALBOX2]->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	meshList[GEO_CEREALBOX2]->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_CEREALBOX2]->material.kShininess = 8.f;
	meshList[GEO_CEREALBOX2] ->textureID = LoadTGA("Image//cereal_box2.tga");

	meshList[GEO_PIZZABOX] = MeshBuilder::GenerateOBJ("Railing" , "OBJ//frozenpizza.obj");
	meshList[GEO_PIZZABOX]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_PIZZABOX]->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	meshList[GEO_PIZZABOX]->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_PIZZABOX]->material.kShininess = 8.f;
	meshList[GEO_PIZZABOX] ->textureID = LoadTGA("Image//frozen_pizza.tga");

	meshList[GEO_POTATOCHIPS] = MeshBuilder::GenerateOBJ("Railing" , "OBJ//potato-chips.obj");
	meshList[GEO_POTATOCHIPS]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_POTATOCHIPS]->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	meshList[GEO_POTATOCHIPS]->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_POTATOCHIPS]->material.kShininess = 8.f;
	meshList[GEO_POTATOCHIPS] ->textureID = LoadTGA("Image//potato_chips.tga");

	meshList[GEO_DOORLEFT] = MeshBuilder::GenerateOBJ("Market door left", "OBJ//MarketDoorLeft.obj");
	meshList[GEO_DOORLEFT]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_DOORLEFT]->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	meshList[GEO_DOORLEFT]->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_DOORLEFT]->material.kShininess = 8.f;
	meshList[GEO_DOORLEFT]->textureID = LoadTGA("Image//MarketDoor.tga");

	meshList[GEO_DOORRIGHT] = MeshBuilder::GenerateOBJ("Market Door Right", "OBJ/MarketDoorRight.obj");
	meshList[GEO_DOORRIGHT]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_DOORRIGHT]->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	meshList[GEO_DOORRIGHT]->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_DOORRIGHT]->material.kShininess = 8.f;
	meshList[GEO_DOORRIGHT]->textureID = LoadTGA("Image//MarketDoor.tga");



	//meshList[GEO_CANTEST] = MeshBuilder::GenerateQuad("CANTEST", Color(1, 1, 1), 1.f, 1.f);
	//meshList[GEO_CANTEST] ->textureID = LoadTGA("UI sprites//UI-canned_food_1.tga");


	//===============MODEL OBJs==========================//
	meshList[modelHead] = MeshBuilder::GenerateOBJ("Character Head", "OBJ//modelHead.obj");
	meshList[modelHead]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[modelHead]->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	meshList[modelHead]->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	meshList[modelHead]->material.kShininess = 8.f;
	meshList[modelHead]->textureID = LoadTGA("Image//modelHead.tga");

	meshList[modelTorso] = MeshBuilder::GenerateOBJ("Character Torso", "OBJ//modelTorso.obj");
	meshList[modelTorso]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[modelTorso]->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	meshList[modelTorso]->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	meshList[modelTorso]->material.kShininess = 8.f;
	meshList[modelTorso]->textureID = LoadTGA("Image//modelTorso.tga");

	meshList[modelRightHand] = MeshBuilder::GenerateOBJ("Character Right Hand", "OBJ//modelArm.obj");
	meshList[modelRightHand]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[modelRightHand]->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	meshList[modelRightHand]->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	meshList[modelRightHand]->material.kShininess = 8.f;
	meshList[modelRightHand]->textureID = LoadTGA("Image//modelHand.tga");

	meshList[modelLeftHand] = MeshBuilder::GenerateOBJ("Character Left Hand", "OBJ//modelArm.obj");
	meshList[modelLeftHand]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[modelLeftHand]->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	meshList[modelLeftHand]->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	meshList[modelLeftHand]->material.kShininess = 8.f;
	meshList[modelLeftHand]->textureID = LoadTGA("Image//modelHand.tga");

	meshList[modelLeftLeg] = MeshBuilder::GenerateOBJ("Character Left Leg", "OBJ//modelLeg.obj");
	meshList[modelLeftLeg]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[modelLeftLeg]->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	meshList[modelLeftLeg]->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	meshList[modelLeftLeg]->material.kShininess = 8.f;
	meshList[modelLeftLeg]->textureID = LoadTGA("Image//modelLeg.tga");

	meshList[modelRightLeg] = MeshBuilder::GenerateOBJ("Character Right Leg", "OBJ//modelLeg.obj");
	meshList[modelRightLeg]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[modelRightLeg]->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	meshList[modelRightLeg]->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	meshList[modelRightLeg]->material.kShininess = 8.f;
	meshList[modelRightLeg]->textureID = LoadTGA("Image//modelLeg.tga");

	//===============CASHIER OBJs==========================//
	meshList[cashierHead] = MeshBuilder::GenerateOBJ("Cashier Head", "OBJ//cashierHead.obj");
	meshList[cashierHead]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[cashierHead]->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	meshList[cashierHead]->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	meshList[cashierHead]->material.kShininess = 8.f;
	meshList[cashierHead]->textureID = LoadTGA("Image//cashierHead.tga");

	meshList[cashierTorso] = MeshBuilder::GenerateOBJ("Cashier Torso", "OBJ//cashierTorso.obj");
	meshList[cashierTorso]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[cashierTorso]->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	meshList[cashierTorso]->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	meshList[cashierTorso]->material.kShininess = 8.f;
	meshList[cashierTorso]->textureID = LoadTGA("Image//cashierTorso.tga");

	meshList[cashierRightHand] = MeshBuilder::GenerateOBJ("Cashier Right Hand", "OBJ//cashierHand.obj");
	meshList[cashierRightHand]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[cashierRightHand]->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	meshList[cashierRightHand]->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	meshList[cashierRightHand]->material.kShininess = 8.f;
	meshList[cashierRightHand]->textureID = LoadTGA("Image//cashierHand.tga");

	meshList[cashierLeftHand] = MeshBuilder::GenerateOBJ("Cashier Left Hand", "OBJ//cashierHand.obj");
	meshList[cashierLeftHand]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[cashierLeftHand]->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	meshList[cashierLeftHand]->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	meshList[cashierLeftHand]->material.kShininess = 8.f;
	meshList[cashierLeftHand]->textureID = LoadTGA("Image//cashierHand.tga");

	meshList[cashierLeftLeg] = MeshBuilder::GenerateOBJ("Cashier Left Leg", "OBJ//cashierLeg.obj");
	meshList[cashierLeftLeg]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[cashierLeftLeg]->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	meshList[cashierLeftLeg]->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	meshList[cashierLeftLeg]->material.kShininess = 8.f;
	meshList[cashierLeftLeg]->textureID = LoadTGA("Image//cashierLeg.tga");

	meshList[cashierRightLeg] = MeshBuilder::GenerateOBJ("Cashier Right Leg", "OBJ//cashierLeg.obj");
	meshList[cashierRightLeg]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[cashierRightLeg]->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	meshList[cashierRightLeg]->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	meshList[cashierRightLeg]->material.kShininess = 8.f;
	meshList[cashierRightLeg]->textureID = LoadTGA("Image//cashierLeg.tga");

	//===============CUSTOMER OBJs==========================//
	meshList[customerHead] = MeshBuilder::GenerateOBJ("customer Head", "OBJ//cashierHead.obj");
	meshList[customerHead]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[customerHead]->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	meshList[customerHead]->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	meshList[customerHead]->material.kShininess = 8.f;
	meshList[customerHead]->textureID = LoadTGA("Image//customerHead.tga");

	meshList[customerTorso] = MeshBuilder::GenerateOBJ("customer Torso", "OBJ//cashierTorso.obj");
	meshList[customerTorso]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[customerTorso]->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	meshList[customerTorso]->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	meshList[customerTorso]->material.kShininess = 8.f;
	meshList[customerTorso]->textureID = LoadTGA("Image//customerTorso.tga");

	meshList[customerRightHand] = MeshBuilder::GenerateOBJ("customer Right Hand", "OBJ//cashierHand.obj");
	meshList[customerRightHand]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[customerRightHand]->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	meshList[customerRightHand]->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	meshList[customerRightHand]->material.kShininess = 8.f;
	meshList[customerRightHand]->textureID = LoadTGA("Image//customerHand.tga");

	meshList[customerLeftHand] = MeshBuilder::GenerateOBJ("customer Left Hand", "OBJ//cashierHand.obj");
	meshList[customerLeftHand]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[customerLeftHand]->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	meshList[customerLeftHand]->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	meshList[customerLeftHand]->material.kShininess = 8.f;
	meshList[customerLeftHand]->textureID = LoadTGA("Image//customerHand.tga");

	meshList[customerLeftLeg] = MeshBuilder::GenerateOBJ("customer Left Leg", "OBJ//cashierLeg.obj");
	meshList[customerLeftLeg]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[customerLeftLeg]->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	meshList[customerLeftLeg]->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	meshList[customerLeftLeg]->material.kShininess = 8.f;
	meshList[customerLeftLeg]->textureID = LoadTGA("Image//customerLeg.tga");

	meshList[customerRightLeg] = MeshBuilder::GenerateOBJ("customer Right Leg", "OBJ//cashierLeg.obj");
	meshList[customerRightLeg]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[customerRightLeg]->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	meshList[customerRightLeg]->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	meshList[customerRightLeg]->material.kShininess = 8.f;
	meshList[customerRightLeg]->textureID = LoadTGA("Image//customerLeg.tga");

	//=======================Item Inventory Page================//
	meshList[itemInventory] = MeshBuilder::GenerateQuad("item Inventory", Color(1, 1, 1), 1.f , 1.f);
	meshList[itemInventory]->textureID = LoadTGA("Image//Item.tga");

	meshList[UI_SARDINE_CAN] = MeshBuilder::GenerateQuad("sardine can", Color(1, 1, 1), 1.f , 1.f);
	meshList[UI_SARDINE_CAN]->textureID = LoadTGA("UI sprites//UI-canned_food_1.tga");

	meshList[UI_PEA_N_CARROTS] = MeshBuilder::GenerateQuad("peas n carrots can", Color(1, 1, 1), 1.f , 1.f);
	meshList[UI_PEA_N_CARROTS]->textureID = LoadTGA("UI sprites//UI-canned_food_2.tga");

	meshList[UI_BAKED_BEANS_CAN] = MeshBuilder::GenerateQuad("bakes beans can", Color(1, 1, 1), 1.f , 1.f);
	meshList[UI_BAKED_BEANS_CAN]->textureID = LoadTGA("UI sprites/UI-canned_food_3.tga");

	meshList[UI_PIZZABOX] = MeshBuilder::GenerateQuad("pizza box", Color(1, 1, 1), 1.f , 1.f);
	meshList[UI_PIZZABOX]->textureID = LoadTGA("UI sprites/UI-frozen_pizza.tga");

	meshList[UI_POTATOCHIPS] = MeshBuilder::GenerateQuad("pizza box", Color(1, 1, 1), 1.f , 1.f);
	meshList[UI_POTATOCHIPS]->textureID = LoadTGA("UI sprites/UI-potato_chips.tga");

	meshList[UI_COKE_CAN] = MeshBuilder::GenerateQuad("pizza box", Color(1, 1, 1), 1.f , 1.f);
	meshList[UI_COKE_CAN]->textureID = LoadTGA("UI sprites/UI-drink_can1.tga");

	meshList[UI_PEPSI_CAN] = MeshBuilder::GenerateQuad("pizza box", Color(1, 1, 1), 1.f , 1.f);
	meshList[UI_PEPSI_CAN]->textureID = LoadTGA("UI sprites/UI-drink_can3.tga");

	meshList[UI_CEREALBOX1] = MeshBuilder::GenerateQuad("pizza box", Color(1, 1, 1), 1.f , 1.f);
	meshList[UI_CEREALBOX1]->textureID = LoadTGA("UI sprites/UI-Cereal-box1.tga");

	meshList[UI_CEREALBOX2] = MeshBuilder::GenerateQuad("pizza box", Color(1, 1, 1), 1.f , 1.f);
	meshList[UI_CEREALBOX2]->textureID = LoadTGA("UI sprites/UI-cereal_box2.tga");

	meshList[UI_MILOCAN] = MeshBuilder::GenerateQuad("pizza box", Color(1, 1, 1), 1.f , 1.f);
	meshList[UI_MILOCAN]->textureID = LoadTGA("UI sprites/UI-milocan.tga");

	//meshList[GEO_TOP] = MeshBuilder::GenerateQuad("top", Color(1, 1, 1), 1.f, 1.f);
	//meshList[GEO_TOP]->textureID = LoadTGA("Image//hills_up.tga");

	//meshList[GEO_BOTTOM] = MeshBuilder::GenerateQuad("bottom", Color(1, 1, 1), 1.f, 1.f);
	//meshList[GEO_BOTTOM]->textureID = LoadTGA("Image//road-texture.tga");

	meshList[GEO_FLOOR] = MeshBuilder::GenerateQuad("bottom", Color(1, 1, 1), 1.f, 1.f);
	meshList[GEO_FLOOR]->textureID = LoadTGA("Image//road-texture.tga");

	//Light ball
	meshList[GEO_LIGHTBALL] = MeshBuilder::GenerateCube("lightball", Color(1, 1, 1), 5);
	meshList[GEO_LIGHTBALL2] = MeshBuilder::GenerateCube("lightball2", Color(1, 1, 1), 5);
	meshList[GEO_LIGHTBALL3] = MeshBuilder::GenerateCube("lightball3", Color(1, 1, 1), 5);
	meshList[GEO_LIGHTBALL4] = MeshBuilder::GenerateCube("lightball4", Color(1, 1, 1), 5);
	meshList[GEO_LIGHTBALL5] = MeshBuilder::GenerateCube("lightball5", Color(1, 1, 1), 5);
	meshList[GEO_LIGHTBALL6] = MeshBuilder::GenerateCube("lightball6", Color(1, 1, 1), 5);
	//Quad texture
	meshList[GEO_QUAD] = MeshBuilder::GenerateQuad("quad", Color(1, 1, 1), 1.f,1.f);
	meshList[GEO_QUAD]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_QUAD]->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	meshList[GEO_QUAD]->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_QUAD]->material.kShininess = 8.f;
	meshList[GEO_QUAD]->textureID = LoadTGA("Image//color2.tga");

	//Text Related
	meshList[GEO_TEXT] = MeshBuilder::GenerateText("text", 16, 16);
	meshList[GEO_TEXT]->textureID = LoadTGA("Image//CourierNew.tga");

}
void StudioProject::InitVariables()
{
	//variable to rotate geometry
	worldsize = 1000.0f;
	roomsize = 250.0f;
	roomheight = 150.0f;
	fps = 0.0f;
	angle = 3600;
	playerAngle = 0;
	moving = 0;
	showInventory = false;
	int a = 0;

	//variable to animate model
	rotateRightArms = rotateLeftArms = rotateRightLeg = rotateLeftLeg = 360;
	charPosition.Set(0.f, 0.f,0.f);
	movingModel = false;
	movingCharacterX = movingCharacterZ = 0;

	Framerate = "FPS: ";

	Cash = "";
	//=========Cashier box===============//
	hitBox checkOut;
	Vector3 cashierMax, cashierMin;
	//First Cashier
	cashierMax.Set(-19.2f,8.f,-11.6f);
	cashierMin.Set(-26.f,4.f,-13.f);
	checkOut.SetBox(cashierMax,cashierMin);
	CashierBox.push_back(checkOut);
	//Middle Cashier
	cashierMax.Set(-19.2f,8.f,7.1f);
	cashierMin.Set(-26.f,4.f,4.8f);
	checkOut.SetBox(cashierMax,cashierMin);
	CashierBox.push_back(checkOut);
	//Last Cashier
	cashierMax.Set(-19.2f,8.f,25.f);
	cashierMin.Set(-26.f,4.f,22.2f);
	checkOut.SetBox(cashierMax,cashierMin);
	CashierBox.push_back(checkOut);

	//===============Sardine Can Variables============//
	Mesh* newMesh;
	newMesh = MeshBuilder::GenerateOBJ("SardineCan" , "OBJ//canned-food1.obj");
	newMesh->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	newMesh->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	newMesh->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	newMesh->material.kShininess = 8.f;
	newMesh->textureID = LoadTGA("Image//canned_food_1.tga");
	hitBox sardineBox;
	for(int i = 0; i < 20;i++)
	{
		Mtx44 newTRS;
		if(i % 5 == 0 && i > 0) //When i mod 5 == 0, it will create a spacing 
		{
			a += 1;
		}
		newTRS.SetToTranslation(10,6.2,-8+i + a);
		sardineCan.SetData("Sardine", 3.5f, true, newMesh,GEO_SARDINE_CAN,newTRS);
		Container.push_back(sardineCan);
		Vector3 Min, Max;
		Max.Set(newTRS.a[12] + 0.59, newTRS.a[13]+0.7, newTRS.a[14]+0.35);
		Min.Set(-0.59 + newTRS.a[12], -0.7+newTRS.a[13], -0.35+newTRS.a[14]);
		sardineBox.SetBox(Max, Min);
		boxContainer.push_back(sardineBox);
	}
	a = 0; //reset a t 0

	//BACK MIDDLE SHELF Back row
	for(int i = 0; i < 20;i++)
	{
		Mtx44 newTRS;
		if(i % 5 == 0 && i > 0)
		{
			a += 1;
		}
		newTRS.SetToTranslation(12,6.2,-8+i + a);
		sardineCan.SetData("Sardine", 3.5f, true, newMesh,GEO_SARDINE_CAN,newTRS);
		Container2.push_back(sardineCan);
		Vector3 Min, Max;
		Max.Set(newTRS.a[12] + 0.59, newTRS.a[13]+0.7, newTRS.a[14]+0.35);
		Min.Set(-0.59 + newTRS.a[12], -0.7+newTRS.a[13], -0.35+newTRS.a[14]);
		sardineBox.SetBox(Max, Min);
		boxContainer2.push_back(sardineBox);
	}
	a = 0;


	//===============Pea and Carrots Variables============//
	newMesh = MeshBuilder::GenerateOBJ("Peas and Carrots can" , "OBJ//canned-food2.obj");
	newMesh->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	newMesh->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	newMesh->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	newMesh->material.kShininess = 8.f;
	newMesh->textureID = LoadTGA("Image//canned_food_2.tga");
	hitBox PnC;
	for(int i = 0; i < 20;i++) //first middle shelf
	{
		Mtx44 newTRS;
		if(i % 5 == 0 && i > 0)
		{
			a += 1;
		}
		newTRS.SetToTranslation(10,4.3,-8+i + a);
		PnCCan.SetData("PeasAndCarrots", 3.5f, true, newMesh,GEO_PEA_N_CARROTS,newTRS);
		Container.push_back(PnCCan);
		Vector3 Min, Max;
		Max.Set(newTRS.a[12]+0.59,newTRS.a[13]+0.7,newTRS.a[14]+0.35);
		Min.Set(-0.59+newTRS.a[12],-0.1+newTRS.a[13],-0.35+newTRS.a[14]);
		PnC.SetBox(Max, Min);
		boxContainer.push_back(PnC);
	}
	a = 0;

	for(int i = 0; i < 20;i++) //BACK MIDDLE SHELF Back row
	{
		Mtx44 newTRS;
		if(i % 5 == 0 && i > 0)
		{
			a += 1;
		}
		newTRS.SetToTranslation(12,4.3,-8+i + a);
		PnCCan.SetData("PeasAndCarrots", 3.5f, true, newMesh,GEO_PEA_N_CARROTS,newTRS);
		Container2.push_back(PnCCan);
		Vector3 Min, Max;
		Max.Set(newTRS.a[12]+0.59,newTRS.a[13]+0.7,newTRS.a[14]+0.35);
		Min.Set(-0.59+newTRS.a[12],-0.7+newTRS.a[13],-0.35+newTRS.a[14]);
		PnC.SetBox(Max, Min);
		boxContainer2.push_back(PnC);
	}
	a = 0;

	//===============Baked Beans Variables============//
	newMesh = MeshBuilder::GenerateOBJ("Baked Beans Can" , "OBJ//canned-food3.obj");
	newMesh->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	newMesh->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	newMesh->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	newMesh->material.kShininess = 8.f;
	newMesh->textureID = LoadTGA("Image//canned_food_3.tga");
	hitBox BB;
	for(int i = 0; i < 20;i++)
	{
		Mtx44 newTRS;
		if(i % 5 == 0 && i > 0)
		{
			a += 1;
		}
		newTRS.SetToTranslation(10,2.3,-8+i + a);
		BBCan.SetData("BakedBeanCan", 3.5f, true, newMesh,GEO_BAKED_BEANS_CAN,newTRS);
		Container.push_back(BBCan);
		Vector3 Min, Max;
		Max.Set(newTRS.a[12]+0.59,newTRS.a[13]+0.7,newTRS.a[14]+0.35);
		Min.Set(-0.59+newTRS.a[12],-0.7+newTRS.a[13],-0.35+newTRS.a[14]);
		BB.SetBox(Max, Min);
		boxContainer.push_back(BB);
	}
	a = 0;

	for(int i = 0; i < 20;i++)
	{
		Mtx44 newTRS;
		if(i % 5 == 0 && i > 0)
		{
			a += 1;
		}
		newTRS.SetToTranslation(12,2.3,-8+i + a);
		BBCan.SetData("BakedBeanCan", 3.5f, true, newMesh,GEO_BAKED_BEANS_CAN,newTRS);
		Container2.push_back(BBCan);
		Vector3 Min, Max;
		Max.Set(newTRS.a[12]+0.59,newTRS.a[13]+0.7,newTRS.a[14]+0.35);
		Min.Set(-0.59+newTRS.a[12],-0.7+newTRS.a[13],-0.35+newTRS.a[14]);
		BB.SetBox(Max, Min);
		boxContainer2.push_back(BB);
	}
	a = 0;
	
	//===============Coke Can Variables============//
	newMesh = MeshBuilder::GenerateOBJ("Coke" , "OBJ//drink-can1.obj");
	newMesh->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	newMesh->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	newMesh->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	newMesh->material.kShininess = 8.f;
	newMesh ->textureID = LoadTGA("Image//drink_can1.tga");
	hitBox Coke;
	for(int i = 0; i < 100;i++)
	{
		Mtx44 newTRS;
		if(i % 10 == 0 && i > 0)
		{
			a += 4;
		}
		newTRS.SetToTranslation(51.3, 4.7,-74+i + a);
		CokeCan.SetData("CokeCan", 3.5f, true, newMesh, GEO_COKE_CAN,newTRS);
		Container3.push_back(CokeCan);
		Vector3 Min, Max;
		Max.Set(newTRS.a[12]+0.59,newTRS.a[13]+0.7,newTRS.a[14]+0.5);
		Min.Set(-0.59+newTRS.a[12],-0.7+newTRS.a[13],-0.35+newTRS.a[14]);
		Coke.SetBox(Max, Min);
		boxContainer3.push_back(Coke);
	}
	a = 0;

	//===============Frozen Pizza Variables============//
	newMesh = MeshBuilder::GenerateOBJ("Pizza" , "OBJ//frozenpizza.obj");
	newMesh->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	newMesh->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	newMesh->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	newMesh->material.kShininess = 8.f;
	newMesh ->textureID = LoadTGA("Image//frozen_pizza.tga");
	hitBox Pizza;
	for(int i = 0; i < 120; i += 3)
	{
		Mtx44 newTRS;
		if(i % 12 == 0 && i > 0)
		{
			a += 2;
		}
		newTRS.SetToTranslation(51.3, 2.7,-75+i + a);
		PizzaBox.SetData("PizzaBox", 3.5f, true, newMesh, GEO_PIZZABOX,newTRS);
		Container3.push_back(PizzaBox);
		Vector3 Min, Max;
		Max.Set(newTRS.a[12],newTRS.a[13]+0.8,newTRS.a[14]+1);
		Min.Set(-3+newTRS.a[12],-0.5+newTRS.a[13],-2+newTRS.a[14]);
		Pizza.SetBox(Max, Min);
		boxContainer3.push_back(Pizza);
	}
	a = 0;

	//===============Coke Zero Can Variables============//
	newMesh = MeshBuilder::GenerateOBJ("Coke" , "OBJ//drink-can2.obj");
	newMesh->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	newMesh->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	newMesh->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	newMesh->material.kShininess = 8.f;
	newMesh ->textureID = LoadTGA("Image//drink_can2.tga");
	hitBox CokeZero;
	for(int i = 0; i < 50;i++)
	{
		Mtx44 newTRS;
		if(i % 10 == 0 && i > 0)
		{
			a += 4;
		}
		newTRS.SetToTranslation(-33 +i + a, 4.7,-90);
		CokeZeroCan.SetData("CokeZeroCan", 3.5f, true, newMesh, GEO_DRINKCAN2,newTRS);
		Container4.push_back(CokeZeroCan);
		Vector3 Min, Max;
		Max.Set(newTRS.a[12]+0.59,newTRS.a[13]+0.7,newTRS.a[14]+0.35);
		Min.Set(-0.59+newTRS.a[12],-0.7+newTRS.a[13],-0.35+newTRS.a[14]);
		CokeZero.SetBox(Max, Min);
		boxContainer4.push_back(CokeZero);
	}
	a = 0;

	newMesh = MeshBuilder::GenerateOBJ("Coke" , "OBJ//drink-can3.obj");
	newMesh->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	newMesh->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	newMesh->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	newMesh->material.kShininess = 8.f;
	newMesh ->textureID = LoadTGA("Image//drink_can3.tga");
	hitBox Pepsi;
	for(int i = 0; i < 50;i++)
	{
		Mtx44 newTRS;
		if(i % 10 == 0 && i > 0)
		{
			a += 4;
		}
		newTRS.SetToTranslation(-33 +i + a, 2.9,-90);
		PepsiCan.SetData("PepsiCan", 3.5f, true, newMesh, GEO_PEPSI_CAN,newTRS);
		Container4.push_back(PepsiCan);
		Vector3 Min, Max;
		Max.Set(newTRS.a[12]+0.59,newTRS.a[13]+0.7,newTRS.a[14]+0.35);
		Min.Set(-0.59+newTRS.a[12],-0.7+newTRS.a[13],-0.35+newTRS.a[14]);
		Pepsi.SetBox(Max, Min);
		boxContainer4.push_back(Pepsi);
	}
	a = 0;

	//===============Cereal Box 1 Variables============//
	newMesh = MeshBuilder::GenerateOBJ("Cereal Box 1" , "OBJ//cereal-box1.obj");
	newMesh->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	newMesh->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	newMesh->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	newMesh->material.kShininess = 8.f;
	newMesh ->textureID = LoadTGA("Image//Cereal-box1.tga");
	hitBox cereal1;
	for(int i = 0; i < 45;i++)
	{
		Mtx44 newTRS;
		if(i % 5 == 0 && i > 0)
		{
			a += 1;
		}
		newTRS.SetToTranslation(-32 +i + a, 4.3,-56.7);
		cerealBox1.SetData("CerealBox1", 3.5f, true, newMesh, GEO_CEREALBOX1,newTRS);
		Container5.push_back(cerealBox1);
		Vector3 Min, Max;
		Max.Set(newTRS.a[12]+0.59, newTRS.a[13]+2,newTRS.a[14]+0.35);
		Min.Set(-0.59+newTRS.a[12],-1+newTRS.a[13],-0.35+newTRS.a[14]);
		cereal1.SetBox(Max, Min);
		boxContainer5.push_back(cereal1);
	}
	a = 0;

	for(int i = 0; i < 45;i++) // Left shelf Back Row
	{
		Mtx44 newTRS;
		if(i % 5 == 0 && i > 0)
		{
			a += 1;
		}
		newTRS.SetToTranslation(-32 +i + a, 4.3,-59.5);
		cerealBox1.SetData("CerealBox1", 3.5f, true, newMesh, GEO_CEREALBOX1,newTRS);
		Container6.push_back(cerealBox1);
		Vector3 Min, Max;
		Max.Set(newTRS.a[12]+0.59,newTRS.a[13]+2,newTRS.a[14]+0.35);
		Min.Set(-0.59+newTRS.a[12],-1+newTRS.a[13],-0.35+newTRS.a[14]);
		cereal1.SetBox(Max, Min);
		boxContainer6.push_back(cereal1);
	}
	a = 0;

	for(int i = 0; i < 45;i++) // Right shelf Front Row
	{
		Mtx44 newTRS;
		if(i % 5 == 0 && i > 0)
		{
			a += 1;
		}
		newTRS.SetToTranslation(-32 +i + a, 4.3,56.5);
		cerealBox1.SetData("CerealBox1", 3.5f, true, newMesh, GEO_CEREALBOX1,newTRS);
		Container7.push_back(cerealBox1);
		Vector3 Min, Max;
		Max.Set(newTRS.a[12]+0.59,newTRS.a[13]+2,newTRS.a[14]+0.35);
		Min.Set(-0.59+newTRS.a[12],-1+newTRS.a[13],-0.35+newTRS.a[14]);
		cereal1.SetBox(Max, Min);
		boxContainer7.push_back(cereal1);
	}
	a = 0;

	for(int i = 0; i < 45;i++) // Right shelf Back Row
	{
		Mtx44 newTRS;
		if(i % 5 == 0 && i > 0)
		{
			a += 1;
		}
		newTRS.SetToTranslation(-32 +i + a, 4.3,59.5);
		cerealBox1.SetData("CerealBox1", 3.5f, true, newMesh, GEO_CEREALBOX1,newTRS);
		Container8.push_back(cerealBox1);
		Vector3 Min, Max;
		Max.Set(newTRS.a[12]+0.59,newTRS.a[13]+2,newTRS.a[14]+0.35);
		Min.Set(-0.59+newTRS.a[12],-1+newTRS.a[13],-0.35+newTRS.a[14]);
		cereal1.SetBox(Max, Min);
		boxContainer8.push_back(cereal1);
	}
	a = 0;

	//===============Cereal Box 2 Variables============//
	newMesh = MeshBuilder::GenerateOBJ("Cereal Box 2" , "OBJ//cereal-box2.obj");
	newMesh->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	newMesh->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	newMesh->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	newMesh->material.kShininess = 8.f;
	newMesh ->textureID = LoadTGA("Image//cereal_box2.tga");
	hitBox cereal2;
	for(int i = 0; i < 45;i++)
	{
		Mtx44 newTRS;
		if(i % 5 == 0 && i > 0)
		{
			a += 1;
		}
		newTRS.SetToTranslation(-32 +i + a, 2.3,-56.7);
		cerealBox2.SetData("CerealBox2", 3.5f, true, newMesh, GEO_CEREALBOX2,newTRS);
		Container5.push_back(cerealBox2);
		Vector3 Min, Max;
		Max.Set(newTRS.a[12]+0.59,newTRS.a[13]+2,newTRS.a[14]+0.35);
		Min.Set(-0.59+newTRS.a[12],-1+newTRS.a[13],-0.35+newTRS.a[14]);
		cereal2.SetBox(Max, Min);
		boxContainer5.push_back(cereal2);
	}
	a = 0;



	for(int i = 0; i < 45;i++)//Left Shwlf Back Row
	{
		Mtx44 newTRS;
		if(i % 5 == 0 && i > 0)
		{
			a += 1;
		}
		newTRS.SetToTranslation(-32 +i + a, 2.3,-59.5);
		cerealBox2.SetData("CerealBox2", 3.5f, true, newMesh, GEO_CEREALBOX2,newTRS);
		Container6.push_back(cerealBox2);
		Vector3 Min, Max;
		Max.Set(newTRS.a[12]+0.59,newTRS.a[13]+2,newTRS.a[14]+0.35);
		Min.Set(-0.59+newTRS.a[12],-1+newTRS.a[13],-0.35+newTRS.a[14]);
		cereal2.SetBox(Max, Min);
		boxContainer6.push_back(cereal2);
	}
	a = 0;

	for(int i = 0; i < 45;i++)//Right Shwlf Back Row
	{
		Mtx44 newTRS;
		if(i % 5 == 0 && i > 0)
		{
			a += 1;
		}
		newTRS.SetToTranslation(-32 +i + a, 2.3,59.5);
		cerealBox2.SetData("CerealBox2", 3.5f, true, newMesh, GEO_CEREALBOX2,newTRS);
		Container8.push_back(cerealBox2);
		Vector3 Min, Max;
		Max.Set(newTRS.a[12]+0.59,newTRS.a[13]+2,newTRS.a[14]+0.35);
		Min.Set(-0.59+newTRS.a[12],-1+newTRS.a[13],-0.35+newTRS.a[14]);
		cereal2.SetBox(Max, Min);
		boxContainer8.push_back(cereal2);
	}
	a = 0;

	for(int i = 0; i < 45;i++)//Right Shwlf Front Row
	{
		Mtx44 newTRS;
		if(i % 5 == 0 && i > 0)
		{
			a += 1;
		}
		newTRS.SetToTranslation(-32 +i + a, 2.3,56.5);
		cerealBox2.SetData("CerealBox2", 3.5f, true, newMesh, GEO_CEREALBOX2,newTRS);
		Container7.push_back(cerealBox2);
		Vector3 Min, Max;
		Max.Set(newTRS.a[12]+0.59,newTRS.a[13]+0.7,newTRS.a[14]+0.35);
		Min.Set(-0.59+newTRS.a[12],-0.7+newTRS.a[13],-0.35+newTRS.a[14]);
		cereal2.SetBox(Max, Min);
		boxContainer7.push_back(cereal2);
	}
	a = 0;

	//===============Potato CHip Variables============//
	newMesh = MeshBuilder::GenerateOBJ("Potato Chip" , "OBJ//potato-chips.obj");
	newMesh->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	newMesh->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	newMesh->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	newMesh->material.kShininess = 8.f;
	newMesh->textureID = LoadTGA("Image//potato_chips.tga");
	hitBox PC;
	for(int i = 0; i < 40;i++) //Potato Top Shelves Left
	{
		Mtx44 newTRS;
		if(i % 10 == 0 && i > 0)
		{
			a += 2;
		}
		newTRS.SetToTranslation(-28.5 +i + a, 5,-35);
		PotatoChip.SetData("PotatoChips", 3.5f, true, newMesh, GEO_POTATOCHIPS,newTRS);
		Container9.push_back(PotatoChip);
		Vector3 Min, Max;
		Max.Set(newTRS.a[12]+0.59,newTRS.a[13]+2,newTRS.a[14]+0.35);
		Min.Set(-0.59+newTRS.a[12],+newTRS.a[13],-0.35+newTRS.a[14]);
		PC.SetBox(Max, Min);
		boxContainer9.push_back(PC);
	}
	a = 0;
	for(int i = 0; i < 40;i++)
	{
		Mtx44 newTRS;
		if(i % 10 == 0 && i > 0) //Potato Bottom Shelves Left
		{
			a += 2;
		}
		newTRS.SetToTranslation(-28.5 +i + a, 2.,-35);
		PotatoChip.SetData("PotatoChips", 3.5f, true, newMesh, GEO_POTATOCHIPS,newTRS);
		Container9.push_back(PotatoChip);
		Vector3 Min, Max;
		Max.Set(newTRS.a[12]+0.59,newTRS.a[13]+2,newTRS.a[14]+0.35);
		Min.Set(-0.59+newTRS.a[12],+newTRS.a[13],-0.35+newTRS.a[14]);
		PC.SetBox(Max, Min);
		boxContainer9.push_back(PC);
	}
	a = 0;

	for(int i = 0; i < 40;i++) //Potato Top Shelves Right
	{
		Mtx44 newTRS;
		if(i % 10 == 0 && i > 0)
		{
			a += 2;
		}
		newTRS.SetToTranslation(-28.5 +i + a, 5,33);
		PotatoChip.SetData("PotatoChips", 3.5f, true, newMesh, GEO_POTATOCHIPS,newTRS);
		Container10.push_back(PotatoChip);
		Vector3 Min, Max;
		Max.Set(newTRS.a[12]+0.59,newTRS.a[13]+2,newTRS.a[14]+0.35);
		Min.Set(-0.59+newTRS.a[12],+newTRS.a[13],-0.35+newTRS.a[14]);
		PC.SetBox(Max, Min);
		boxContainer10.push_back(PC);
	}
	a = 0;

	for(int i = 0; i < 40;i++) //Potato bottom  Shelves Right
	{
		Mtx44 newTRS;
		if(i % 10 == 0 && i > 0)
		{
			a += 2;
		}
		newTRS.SetToTranslation(-28.5 +i + a, 2,33);
		PotatoChip.SetData("PotatoChips", 3.5f, true, newMesh, GEO_POTATOCHIPS,newTRS);
		Container10.push_back(PotatoChip);
		Vector3 Min, Max;
		Max.Set(newTRS.a[12]+0.59,newTRS.a[13]+2,newTRS.a[14]+0.35);
		Min.Set(-0.59+newTRS.a[12],+newTRS.a[13],-0.35+newTRS.a[14]);
		PC.SetBox(Max, Min);
		boxContainer10.push_back(PC);
	}
	a = 0;

	//===============Milo Cam Variables============//
	newMesh = MeshBuilder::GenerateOBJ("Milo Can" , "OBJ//milocan.obj");
	newMesh->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	newMesh->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	newMesh->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	newMesh->material.kShininess = 8.f;
	newMesh->textureID = LoadTGA("Image//milocan.tga");
	hitBox MC;
	for(int i = 0; i < 54; i += 2) //Milo front Shelves Left
	{
		Mtx44 newTRS;
		if(i % 3 == 0 && i > 0)
		{
			a += 0.5;
		}
		newTRS.SetToTranslation(-32 +i + a, 6.3,-57);
		MiloCan.SetData("MiloCan", 3.5f, true, newMesh, GEO_MILOCAN,newTRS);
		Container11.push_back(MiloCan);
		Vector3 Min, Max;
		Max.Set(newTRS.a[12]+0.59,newTRS.a[13]+2,newTRS.a[14]+0.35);
		Min.Set(-0.59+newTRS.a[12],+newTRS.a[13],-0.35+newTRS.a[14]);
		MC.SetBox(Max, Min);
		boxContainer11.push_back(MC);
	}
	a = 0;

	for(int i = 0; i < 54; i += 2) //Milo back Shelves Right
	{
		Mtx44 newTRS;
		if(i % 3 == 0 && i > 0)
		{
			a += 0.5;
		}
		newTRS.SetToTranslation(-32 +i + a, 6.3, 59);
		MiloCan.SetData("MiloCan", 3.5f, true, newMesh, GEO_MILOCAN,newTRS);
		Container11.push_back(MiloCan);
		Vector3 Min, Max;
		Max.Set(newTRS.a[12]+0.59,newTRS.a[13]+2,newTRS.a[14]+0.35);
		Min.Set(-0.59+newTRS.a[12],+newTRS.a[13],-0.35+newTRS.a[14]);
		MC.SetBox(Max, Min);
		boxContainer11.push_back(MC);
	}
	a = 0;

	for(int i = 0; i < 54; i += 2) //Milo back Shelves Left
	{
		Mtx44 newTRS;
		if(i % 3 == 0 && i > 0)
		{
			a += 0.5;
		}
		newTRS.SetToTranslation(-32 +i + a, 6.3,-59.3);
		MiloCan.SetData("MiloCan", 3.5f, true, newMesh, GEO_MILOCAN,newTRS);
		Container12.push_back(MiloCan);
		Vector3 Min, Max;
		Max.Set(newTRS.a[12]+0.59,newTRS.a[13]+2,newTRS.a[14]+0.35);
		Min.Set(-0.59+newTRS.a[12],+newTRS.a[13],-0.35+newTRS.a[14]);
		MC.SetBox(Max, Min);
		boxContainer12.push_back(MC);
	}
	a = 0;

	for(int i = 0; i < 54; i += 2) //Milo back Shelves Left
	{
		Mtx44 newTRS;
		if(i % 3 == 0 && i > 0)
		{
			a += 0.5;
		}
		newTRS.SetToTranslation(-32 +i + a, 6.3,57);
		MiloCan.SetData("MiloCan", 3.5f, true, newMesh, GEO_MILOCAN,newTRS);
		Container12.push_back(MiloCan);
		Vector3 Min, Max;
		Max.Set(newTRS.a[12]+0.59,newTRS.a[13]+2,newTRS.a[14]+0.35);
		Min.Set(-0.59+newTRS.a[12],+newTRS.a[13],-0.35+newTRS.a[14]);
		MC.SetBox(Max, Min);
		boxContainer12.push_back(MC);
	}
	a = 0;

	/*meshList[GEO_MILOCAN] = MeshBuilder::GenerateOBJ("Railing" , "OBJ//milocan.obj");
	meshList[GEO_MILOCAN]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_MILOCAN]->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	meshList[GEO_MILOCAN]->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_MILOCAN]->material.kShininess = 8.f;
	meshList[GEO_MILOCAN] ->textureID = LoadTGA("Image//milocan.tga");*/

	//variable to animate model
	rotateRightArms = rotateLeftArms = rotateRightLeg = rotateLeftLeg = 360;
	movingModel = false;
	movingCharacterX = movingCharacterZ = 0;

	Framerate = "FPS: ";
}
void StudioProject::InitShaders()
{
	m_programID = LoadShaders( "Shader//Texture.vertexshader", "Shader//MultiLight.fragmentshader");
	m_parameters[U_COLOR_TEXTURE_ENABLED] = glGetUniformLocation(m_programID, "colorTextureEnabled");
	m_parameters[U_COLOR_TEXTURE] = glGetUniformLocation(m_programID, "colorTexture");
	m_parameters[U_MVP] = glGetUniformLocation(m_programID, "MVP");
	m_parameters[U_MODELVIEW] = glGetUniformLocation(m_programID, "MV");
	m_parameters[U_MODELVIEW_INVERSE_TRANSPOSE] = glGetUniformLocation(m_programID, "MV_inverse_transpose");
	m_parameters[U_MATERIAL_AMBIENT] = glGetUniformLocation(m_programID, "material.kAmbient");
	m_parameters[U_MATERIAL_DIFFUSE] = glGetUniformLocation(m_programID, "material.kDiffuse");
	m_parameters[U_MATERIAL_SPECULAR] = glGetUniformLocation(m_programID, "material.kSpecular");
	m_parameters[U_MATERIAL_SHININESS] = glGetUniformLocation(m_programID, "material.kShininess");
	m_parameters[U_LIGHTENABLED] = glGetUniformLocation(m_programID, "lightEnabled");
	m_parameters[U_NUMLIGHTS] = glGetUniformLocation(m_programID, "numLights");

	// Light 1
	m_parameters[U_LIGHT0_POSITION] = glGetUniformLocation(m_programID, "lights[0].position_cameraspace");
	m_parameters[U_LIGHT0_COLOR] = glGetUniformLocation(m_programID, "lights[0].color");
	m_parameters[U_LIGHT0_POWER] = glGetUniformLocation(m_programID, "lights[0].power");
	m_parameters[U_LIGHT0_KC] = glGetUniformLocation(m_programID, "lights[0].kC");
	m_parameters[U_LIGHT0_KL] = glGetUniformLocation(m_programID, "lights[0].kL");
	m_parameters[U_LIGHT0_KQ] = glGetUniformLocation(m_programID, "lights[0].kQ");
	m_parameters[U_LIGHT0_TYPE] = glGetUniformLocation(m_programID, "lights[0].type");
	m_parameters[U_LIGHT0_SPOTDIRECTION] = glGetUniformLocation(m_programID, "lights[0].spotDirection");
	m_parameters[U_LIGHT0_COSCUTOFF] = glGetUniformLocation(m_programID, "lights[0].cosCutoff");
	m_parameters[U_LIGHT0_COSINNER] = glGetUniformLocation(m_programID, "lights[0].cosInner");
	m_parameters[U_LIGHT0_EXPONENT] = glGetUniformLocation(m_programID, "lights[0].exponent");
	m_parameters[U_NUMLIGHTS] = glGetUniformLocation(m_programID, "numLights");

	// Light2
	m_parameters[U_LIGHT1_POSITION] = glGetUniformLocation(m_programID, "lights[1].position_cameraspace");
	m_parameters[U_LIGHT1_COLOR] = glGetUniformLocation(m_programID, "lights[1].color");
	m_parameters[U_LIGHT1_POWER] = glGetUniformLocation(m_programID, "lights[1].power");
	m_parameters[U_LIGHT1_KC] = glGetUniformLocation(m_programID, "lights[1].kC");
	m_parameters[U_LIGHT1_KL] = glGetUniformLocation(m_programID, "lights[1].kL");
	m_parameters[U_LIGHT1_KQ] = glGetUniformLocation(m_programID, "lights[1].kQ");
	m_parameters[U_LIGHT1_TYPE] = glGetUniformLocation(m_programID, "lights[1].type");
	m_parameters[U_LIGHT1_SPOTDIRECTION] = glGetUniformLocation(m_programID, "lights[1].spotDirection");
	m_parameters[U_LIGHT1_COSCUTOFF] = glGetUniformLocation(m_programID, "lights[1].cosCutoff");
	m_parameters[U_LIGHT1_COSINNER] = glGetUniformLocation(m_programID, "lights[1].cosInner");
	m_parameters[U_LIGHT1_EXPONENT] = glGetUniformLocation(m_programID, "lights[1].exponent");
	m_parameters[U_NUMLIGHTS] = glGetUniformLocation(m_programID, "numLights");

	// Light3
	m_parameters[U_LIGHT2_POSITION] = glGetUniformLocation(m_programID, "lights[2].position_cameraspace");
	m_parameters[U_LIGHT2_COLOR] = glGetUniformLocation(m_programID, "lights[2].color");
	m_parameters[U_LIGHT2_POWER] = glGetUniformLocation(m_programID, "lights[2].power");
	m_parameters[U_LIGHT2_KC] = glGetUniformLocation(m_programID, "lights[2].kC");
	m_parameters[U_LIGHT2_KL] = glGetUniformLocation(m_programID, "lights[2].kL");
	m_parameters[U_LIGHT2_KQ] = glGetUniformLocation(m_programID, "lights[2].kQ");
	m_parameters[U_LIGHT2_TYPE] = glGetUniformLocation(m_programID, "lights[2].type");
	m_parameters[U_LIGHT2_SPOTDIRECTION] = glGetUniformLocation(m_programID, "lights[2].spotDirection");
	m_parameters[U_LIGHT2_COSCUTOFF] = glGetUniformLocation(m_programID, "lights[2].cosCutoff");
	m_parameters[U_LIGHT2_COSINNER] = glGetUniformLocation(m_programID, "lights[2].cosInner");
	m_parameters[U_LIGHT2_EXPONENT] = glGetUniformLocation(m_programID, "lights[2].exponent");
	m_parameters[U_NUMLIGHTS] = glGetUniformLocation(m_programID, "numLights");

	// Light4
	m_parameters[U_LIGHT3_POSITION] = glGetUniformLocation(m_programID, "lights[3].position_cameraspace");
	m_parameters[U_LIGHT3_COLOR] = glGetUniformLocation(m_programID, "lights[3].color");
	m_parameters[U_LIGHT3_POWER] = glGetUniformLocation(m_programID, "lights[3].power");
	m_parameters[U_LIGHT3_KC] = glGetUniformLocation(m_programID, "lights[3].kC");
	m_parameters[U_LIGHT3_KL] = glGetUniformLocation(m_programID, "lights[3].kL");
	m_parameters[U_LIGHT3_KQ] = glGetUniformLocation(m_programID, "lights[3].kQ");
	m_parameters[U_LIGHT3_TYPE] = glGetUniformLocation(m_programID, "lights[3].type");
	m_parameters[U_LIGHT3_SPOTDIRECTION] = glGetUniformLocation(m_programID, "lights[3].spotDirection");
	m_parameters[U_LIGHT3_COSCUTOFF] = glGetUniformLocation(m_programID, "lights[3].cosCutoff");
	m_parameters[U_LIGHT3_COSINNER] = glGetUniformLocation(m_programID, "lights[3].cosInner");
	m_parameters[U_LIGHT3_EXPONENT] = glGetUniformLocation(m_programID, "lights[3].exponent");
	m_parameters[U_NUMLIGHTS] = glGetUniformLocation(m_programID, "numLights");

	// Light5
	m_parameters[U_LIGHT4_POSITION] = glGetUniformLocation(m_programID, "lights[4].position_cameraspace");
	m_parameters[U_LIGHT4_COLOR] = glGetUniformLocation(m_programID, "lights[4].color");
	m_parameters[U_LIGHT4_POWER] = glGetUniformLocation(m_programID, "lights[4].power");
	m_parameters[U_LIGHT4_KC] = glGetUniformLocation(m_programID, "lights[4].kC");
	m_parameters[U_LIGHT4_KL] = glGetUniformLocation(m_programID, "lights[4].kL");
	m_parameters[U_LIGHT4_KQ] = glGetUniformLocation(m_programID, "lights[4].kQ");
	m_parameters[U_LIGHT4_TYPE] = glGetUniformLocation(m_programID, "lights[4].type");
	m_parameters[U_LIGHT4_SPOTDIRECTION] = glGetUniformLocation(m_programID, "lights[4].spotDirection");
	m_parameters[U_LIGHT4_COSCUTOFF] = glGetUniformLocation(m_programID, "lights[4].cosCutoff");
	m_parameters[U_LIGHT4_COSINNER] = glGetUniformLocation(m_programID, "lights[4].cosInner");
	m_parameters[U_LIGHT4_EXPONENT] = glGetUniformLocation(m_programID, "lights[4].exponent");
	m_parameters[U_NUMLIGHTS] = glGetUniformLocation(m_programID, "numLights");

	// Light6
	m_parameters[U_LIGHT5_POSITION] = glGetUniformLocation(m_programID, "lights[5].position_cameraspace");
	m_parameters[U_LIGHT5_COLOR] = glGetUniformLocation(m_programID, "lights[5].color");
	m_parameters[U_LIGHT5_POWER] = glGetUniformLocation(m_programID, "lights[5].power");
	m_parameters[U_LIGHT5_KC] = glGetUniformLocation(m_programID, "lights[5].kC");
	m_parameters[U_LIGHT5_KL] = glGetUniformLocation(m_programID, "lights[5].kL");
	m_parameters[U_LIGHT5_KQ] = glGetUniformLocation(m_programID, "lights[5].kQ");
	m_parameters[U_LIGHT5_TYPE] = glGetUniformLocation(m_programID, "lights[5].type");
	m_parameters[U_LIGHT5_SPOTDIRECTION] = glGetUniformLocation(m_programID, "lights[5].spotDirection");
	m_parameters[U_LIGHT5_COSCUTOFF] = glGetUniformLocation(m_programID, "lights[5].cosCutoff");
	m_parameters[U_LIGHT5_COSINNER] = glGetUniformLocation(m_programID, "lights[5].cosInner");
	m_parameters[U_LIGHT5_EXPONENT] = glGetUniformLocation(m_programID, "lights[5].exponent");
	m_parameters[U_NUMLIGHTS] = glGetUniformLocation(m_programID, "numLights");

	//Text Related
	// Get a handle for our "textColor" uniform
	m_parameters[U_TEXT_ENABLED] = glGetUniformLocation(m_programID, "textEnabled");
	m_parameters[U_TEXT_COLOR] = glGetUniformLocation(m_programID, "textColor");

	glUseProgram(m_programID);

	//Light 1 (BOTTOM CENTER BACK LIGHT )
	lights[0].type = Light::LIGHT_POINT;
	lights[0].position.Set(25,19.5, 0);
	lights[0].color.Set(1, 1, 1);
	lights[0].power = 1;
	lights[0].kC = 1.f;
	lights[0].kL = 0.01f;
	lights[0].kQ = 0.001f;
	lights[0].cosCutoff = cos(Math::DegreeToRadian(45));
	lights[0].cosInner = cos(Math::DegreeToRadian(30));
	lights[0].exponent = 3.f;
	lights[0].spotDirection.Set(0.f, 1.f, 0.f);

	//Light 2 (BOTTOM RIGHT BACK LIGHT)
	lights[1].type = Light::LIGHT_POINT;
	lights[1].position.Set(25,19.5,45);
	lights[1].color.Set(1, 1, 1);
	lights[1].power = 1;
	lights[1].kC = 1.f;
	lights[1].kL = 0.01f;
	lights[1].kQ = 0.001f;
	lights[1].cosCutoff = cos(Math::DegreeToRadian(45));
	lights[1].cosInner = cos(Math::DegreeToRadian(30));
	lights[1].exponent = 3.f;
	lights[1].spotDirection.Set(0.f, 5.f, 0.f);

	//Lights3 (BOTTOM LEFT BACK LIGHT)
	lights[2].type = Light::LIGHT_POINT;
	lights[2].position.Set(25,19.5,-60);
	lights[2].color.Set(1, 1, 1);
	lights[2].power = 1;
	lights[2].kC = 1.f;
	lights[2].kL = 0.01;
	lights[2].kQ = 0.001f;
	lights[2].cosCutoff = cos(Math::DegreeToRadian(45));
	lights[2].cosInner = cos(Math::DegreeToRadian(30));
	lights[2].exponent = 3.f;
	lights[2].spotDirection.Set(1.f, 1.f, 0.f);

	//Lights4 (BOTTOM LEFT FRONT LIGHT)
	lights[3].type = Light::LIGHT_POINT;
	lights[3].position.Set(-25,19.5,-60);
	lights[3].color.Set(1, 1, 1);
	lights[3].power = 1;
	lights[3].kC = 1.f;
	lights[3].kL = 0.01;
	lights[3].kQ = 0.001f;
	lights[3].cosCutoff = cos(Math::DegreeToRadian(45));
	lights[3].cosInner = cos(Math::DegreeToRadian(30));
	lights[3].exponent = 3.f;
	lights[3].spotDirection.Set(1.f, 1.f, 0.f);

	
	//Lights5 (BOTTOM RIGHT FRONT LIGHT)
	lights[4].type = Light::LIGHT_POINT;
	lights[4].position.Set(-25,19.5,45);
	lights[4].color.Set(1, 1, 1);
	lights[4].power = 1;
	lights[4].kC = 1.f;
	lights[4].kL = 0.01;
	lights[4].kQ = 0.001f;
	lights[4].cosCutoff = cos(Math::DegreeToRadian(45));
	lights[4].cosInner = cos(Math::DegreeToRadian(30));
	lights[4].exponent = 3.f;
	lights[4].spotDirection.Set(1.f, 1.f, 0.f);

	//Lights6 (BOTTOM CENTER FRONT LIGHT)
	lights[5].type = Light::LIGHT_POINT;
	lights[5].position.Set(-25,19.5, 0);
	lights[5].color.Set(1, 1, 1);
	lights[5].power = 1;
	lights[5].kC = 1.f;
	lights[5].kL = 0.01;
	lights[5].kQ = 0.001f;
	lights[5].cosCutoff = cos(Math::DegreeToRadian(45));
	lights[5].cosInner = cos(Math::DegreeToRadian(30));
	lights[5].exponent = 3.f;
	lights[5].spotDirection.Set(1.f, 1.f, 0.f);

	// Make sure you pass uniform parameters after glUseProgram()
	glUniform1i(m_parameters[U_NUMLIGHTS], 7);

	//Light 1
	glUniform1i(m_parameters[U_LIGHT0_TYPE], lights[0].type);
	glUniform3fv(m_parameters[U_LIGHT0_COLOR], 1, &lights[0].color.r);
	glUniform1f(m_parameters[U_LIGHT0_POWER], lights[0].power);
	glUniform1f(m_parameters[U_LIGHT0_KC], lights[0].kC);
	glUniform1f(m_parameters[U_LIGHT0_KL], lights[0].kL);
	glUniform1f(m_parameters[U_LIGHT0_KQ], lights[0].kQ);
	glUniform1f(m_parameters[U_LIGHT0_COSCUTOFF], lights[0].cosCutoff);
	glUniform1f(m_parameters[U_LIGHT0_COSINNER], lights[0].cosInner);
	glUniform1f(m_parameters[U_LIGHT0_EXPONENT], lights[0].exponent);

	//Light 2
	glUniform1i(m_parameters[U_LIGHT1_TYPE], lights[1].type);
	glUniform3fv(m_parameters[U_LIGHT1_COLOR], 1, &lights[1].color.r);
	glUniform1f(m_parameters[U_LIGHT1_POWER], lights[1].power);
	glUniform1f(m_parameters[U_LIGHT1_KC], lights[1].kC);
	glUniform1f(m_parameters[U_LIGHT1_KL], lights[1].kL);
	glUniform1f(m_parameters[U_LIGHT1_KQ], lights[1].kQ);
	glUniform1f(m_parameters[U_LIGHT1_COSCUTOFF], lights[1].cosCutoff);
	glUniform1f(m_parameters[U_LIGHT1_COSINNER], lights[1].cosInner);
	glUniform1f(m_parameters[U_LIGHT1_EXPONENT], lights[1].exponent);

	//Light 3
	glUniform1i(m_parameters[U_LIGHT2_TYPE], lights[2].type);
	glUniform3fv(m_parameters[U_LIGHT2_COLOR], 1, &lights[2].color.r);
	glUniform1f(m_parameters[U_LIGHT2_POWER], lights[2].power);
	glUniform1f(m_parameters[U_LIGHT2_KC], lights[2].kC);
	glUniform1f(m_parameters[U_LIGHT2_KL], lights[2].kL);
	glUniform1f(m_parameters[U_LIGHT2_KQ], lights[2].kQ);
	glUniform1f(m_parameters[U_LIGHT2_COSCUTOFF], lights[2].cosCutoff);
	glUniform1f(m_parameters[U_LIGHT2_COSINNER], lights[2].cosInner);
	glUniform1f(m_parameters[U_LIGHT2_EXPONENT], lights[2].exponent);

	//Light 4
	glUniform1i(m_parameters[U_LIGHT3_TYPE], lights[3].type);
	glUniform3fv(m_parameters[U_LIGHT3_COLOR], 1, &lights[3].color.r);
	glUniform1f(m_parameters[U_LIGHT3_POWER], lights[3].power);
	glUniform1f(m_parameters[U_LIGHT3_KC], lights[3].kC);
	glUniform1f(m_parameters[U_LIGHT3_KL], lights[3].kL);
	glUniform1f(m_parameters[U_LIGHT3_KQ], lights[3].kQ);
	glUniform1f(m_parameters[U_LIGHT3_COSCUTOFF], lights[3].cosCutoff);
	glUniform1f(m_parameters[U_LIGHT3_COSINNER], lights[3].cosInner);
	glUniform1f(m_parameters[U_LIGHT3_EXPONENT], lights[3].exponent);

	//Light 5
	glUniform1i(m_parameters[U_LIGHT4_TYPE], lights[4].type);
	glUniform3fv(m_parameters[U_LIGHT4_COLOR], 1, &lights[4].color.r);
	glUniform1f(m_parameters[U_LIGHT4_POWER], lights[4].power);
	glUniform1f(m_parameters[U_LIGHT4_KC], lights[4].kC);
	glUniform1f(m_parameters[U_LIGHT4_KL], lights[4].kL);
	glUniform1f(m_parameters[U_LIGHT4_KQ], lights[4].kQ);
	glUniform1f(m_parameters[U_LIGHT4_COSCUTOFF], lights[4].cosCutoff);
	glUniform1f(m_parameters[U_LIGHT4_COSINNER], lights[4].cosInner);
	glUniform1f(m_parameters[U_LIGHT4_EXPONENT], lights[4].exponent);

	//Light 6
	glUniform1i(m_parameters[U_LIGHT5_TYPE], lights[5].type);
	glUniform3fv(m_parameters[U_LIGHT5_COLOR], 1, &lights[5].color.r);
	glUniform1f(m_parameters[U_LIGHT5_POWER], lights[5].power);
	glUniform1f(m_parameters[U_LIGHT5_KC], lights[5].kC);
	glUniform1f(m_parameters[U_LIGHT5_KL], lights[5].kL);
	glUniform1f(m_parameters[U_LIGHT5_KQ], lights[5].kQ);
	glUniform1f(m_parameters[U_LIGHT5_COSCUTOFF], lights[5].cosCutoff);
	glUniform1f(m_parameters[U_LIGHT5_COSINNER], lights[5].cosInner);
	glUniform1f(m_parameters[U_LIGHT5_EXPONENT], lights[5].exponent);


}
void StudioProject::InitCharacters()
{
	Mesh* newHead;
	Mesh* newTorso;
	Mesh* newLHand;
	Mesh* newRHand;
	Mesh* newLLeg;
	Mesh* newRLeg;
	Vector3 newPosition;
	newPosition.Set(0.0f,0.0f,0.0f);

	/*========================================================================
									PLAYER
	===========================================================================*/

	newHead = MeshBuilder::GenerateOBJ("Character Head", "OBJ//modelHead.obj");
	newHead->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	newHead->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	newHead->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	newHead->material.kShininess = 8.f;
	newHead->textureID = LoadTGA("Image//modelHead.tga");

	newTorso = MeshBuilder::GenerateOBJ("Character Torso", "OBJ//modelTorso.obj");
	newTorso->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	newTorso->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	newTorso->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	newTorso->material.kShininess = 8.f;
	newTorso->textureID = LoadTGA("Image//modelTorso.tga");

	newLHand = MeshBuilder::GenerateOBJ("Character Left Hand", "OBJ//modelArm.obj");
	newLHand->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	newLHand->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	newLHand->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	newLHand->material.kShininess = 8.f;
	newLHand->textureID = LoadTGA("Image//modelHand.tga");
	
	newRHand = MeshBuilder::GenerateOBJ("Character Right Hand ", "OBJ//modelArm.obj");
	newRHand->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	newRHand->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	newRHand->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	newRHand->material.kShininess = 8.f;
	newRHand->textureID = LoadTGA("Image//modelHand.tga");

	newLLeg = MeshBuilder::GenerateOBJ("Character Left Leg", "OBJ//modelLeg.obj");
	newLLeg->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	newLLeg->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	newLLeg->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	newLLeg->material.kShininess = 8.f;
	newLLeg->textureID = LoadTGA("Image//modelLeg.tga");

	newRLeg = MeshBuilder::GenerateOBJ("Character Right Leg", "OBJ//modelLeg.obj");
	newRLeg->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	newRLeg->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	newRLeg->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	newRLeg->material.kShininess = 8.f;
	newRLeg->textureID = LoadTGA("Image//modelLeg.tga");

	player.setCharacter(newHead,newTorso,newLHand,newRHand,newLLeg,newRLeg,newPosition);

	/*========================================================================
									Guard
	===========================================================================*/

	newHead = MeshBuilder::GenerateOBJ("Guard Head", "OBJ//cashierHead.obj");
	newHead->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	newHead->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	newHead->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	newHead->material.kShininess = 8.f;
	newHead->textureID = LoadTGA("Image//guardHead.tga");

	newTorso = MeshBuilder::GenerateOBJ("Guard Torso", "OBJ//cashierTorso.obj");
	newTorso->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	newTorso->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	newTorso->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	newTorso->material.kShininess = 8.f;
	newTorso->textureID = LoadTGA("Image//guardTorso.tga");

	newLHand = MeshBuilder::GenerateOBJ("guard Left Hand", "OBJ//cashierHand.obj");
	newLHand->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	newLHand->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	newLHand->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	newLHand->material.kShininess = 8.f;
	newLHand->textureID = LoadTGA("Image//guardHand.tga");
	
	newRHand = MeshBuilder::GenerateOBJ("guard Right Hand ", "OBJ//cashierHand.obj");
	newRHand->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	newRHand->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	newRHand->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	newRHand->material.kShininess = 8.f;
	newRHand->textureID = LoadTGA("Image//guardHand.tga");

	newLLeg = MeshBuilder::GenerateOBJ("guard Left Leg", "OBJ//cashierLeg.obj");
	newLLeg->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	newLLeg->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	newLLeg->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	newLLeg->material.kShininess = 8.f;
	newLLeg->textureID = LoadTGA("Image//guardLeg.tga");

	newRLeg = MeshBuilder::GenerateOBJ("guard Right Leg", "OBJ//cashierLeg.obj");
	newRLeg->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	newRLeg->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	newRLeg->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	newRLeg->material.kShininess = 8.f;
	newRLeg->textureID = LoadTGA("Image//guardLeg.tga");

	Guard1.setCharacter(newHead,newTorso,newLHand,newRHand,newLLeg,newRLeg,newPosition);
	////===============GUARD OBJs==========================//
	//meshList[guardHead] = MeshBuilder::GenerateOBJ("Guard Head", "OBJ//cashierHead.obj");
	//meshList[guardHead]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	//meshList[guardHead]->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	//meshList[guardHead]->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	//meshList[guardHead]->material.kShininess = 8.f;
	//meshList[guardHead]->textureID = LoadTGA("Image//guardHead.tga");

	//meshList[guardTorso] = MeshBuilder::GenerateOBJ("Guard Torso", "OBJ//cashierTorso.obj");
	//meshList[guardTorso]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	//meshList[guardTorso]->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	//meshList[guardTorso]->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	//meshList[guardTorso]->material.kShininess = 8.f;
	//meshList[guardTorso]->textureID = LoadTGA("Image//guardTorso.tga");

	//meshList[guardRightHand] = MeshBuilder::GenerateOBJ("guard Right Hand", "OBJ//cashierHand.obj");
	//meshList[guardRightHand]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	//meshList[guardRightHand]->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	//meshList[guardRightHand]->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	//meshList[guardRightHand]->material.kShininess = 8.f;
	//meshList[guardRightHand]->textureID = LoadTGA("Image//guardHand.tga");

	//meshList[guardLeftHand] = MeshBuilder::GenerateOBJ("guard Left Hand", "OBJ//cashierHand.obj");
	//meshList[guardLeftHand]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	//meshList[guardLeftHand]->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	//meshList[guardLeftHand]->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	//meshList[guardLeftHand]->material.kShininess = 8.f;
	//meshList[guardLeftHand]->textureID = LoadTGA("Image//guardHand.tga");

	//meshList[guardLeftLeg] = MeshBuilder::GenerateOBJ("guard Left Leg", "OBJ//cashierLeg.obj");
	//meshList[guardLeftLeg]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	//meshList[guardLeftLeg]->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	//meshList[guardLeftLeg]->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	//meshList[guardLeftLeg]->material.kShininess = 8.f;
	//meshList[guardLeftLeg]->textureID = LoadTGA("Image//guardLeg.tga");

	//meshList[guardRightLeg] = MeshBuilder::GenerateOBJ("guard Right Leg", "OBJ//cashierLeg.obj");
	//meshList[guardRightLeg]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	//meshList[guardRightLeg]->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	//meshList[guardRightLeg]->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	//meshList[guardRightLeg]->material.kShininess = 8.f;
	//meshList[guardRightLeg]->textureID = LoadTGA("Image//guardLeg.tga");
}

void StudioProject::InitSecurity()
{
	Mesh* CameraObj;
	Vector3 newPosition1;
	newPosition1.Set(53.3, 18, -92.5);

	/*newRLeg = MeshBuilder::GenerateOBJ("guard Right Leg", "OBJ//cashierLeg.obj");
	newRLeg->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	newRLeg->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	newRLeg->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	newRLeg->material.kShininess = 8.f;
	newRLeg->textureID = LoadTGA("Image//guardLeg.tga");*/
	/*
	meshList[SC] = MeshBuilder::GenerateOBJ("SC" , "OBJ//SC.obj");
	meshList[SC]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[SC]->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	meshList[SC]->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	meshList[SC]->material.kShininess = 8.f;
	meshList[SC]->textureID = LoadTGA("Image//SC.tga");*/

	CameraObj = MeshBuilder::GenerateOBJ("Security Camera", "OBJ//SC.obj");
	CameraObj->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	CameraObj->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	CameraObj->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	CameraObj->material.kShininess = 8.f;
	CameraObj->textureID = LoadTGA("Image//SC.tga");

	CameraOBJ[0].setCharacter(CameraObj, newPosition1);
	CameraOBJ[1].setCharacter(CameraObj, newPosition1);
}
void StudioProject::Init()
{
	// Set background color to black
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	//Enable depth buffer and depth testing
	glEnable(GL_DEPTH_TEST);
	//Enable back face culling
	glDisable(GL_CULL_FACE);
	// Enable blending
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//Default to fill mode
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	// Generate a default VAO for now
	glGenVertexArrays(1, &m_vertexArrayID);
	glBindVertexArray(m_vertexArrayID);

	//Initialize camera settings
	camera.Init(Vector3(0, 5, 15), Vector3(0, 5, 13), Vector3(0, 1, 0));

	Mtx44 projection;
	projection.SetToPerspective(45.f, 4.f / 3.f, 0.1f, 10000.f);
	projectionStack.LoadMatrix(projection);

	InitVariables();

	InitCharacters();

	InitSecurity();

	InitShaders();

	InitMesh();

}

//========Variables for use in update====//
bool Closed = true;
bool Opened = false;
bool doorMoving = false;
bool doorStop = true;
bool B_Light = true;
static float ROT_LIMIT = 45.f;
static float SCALE_LIMIT = 5.f;
string result;

float doorTranslate = 0;
//Show Controls
bool isShown = true;

//=====variables to animate model arms===//
int rotatingRightArm = 1;
int rotatingLeftArm = 1;
int rotatingRightLeg = 1;
int rotatingLeftLeg = 1;

//========variables used for debugging purposes==========//
bool collide = false;
bool checking = false;

void StudioProject::Update(double dt)
{
	for (int a = 0; a < 3; a++)
	{
		CameraOBJ[a].PassinDt(dt);
	}
	float LSPEED = 10.f;

	if(Application::IsKeyPressed('1')) //enable back face culling
		glEnable(GL_CULL_FACE);
	if(Application::IsKeyPressed('2')) //disable back face culling
		glDisable(GL_CULL_FACE);
	if(Application::IsKeyPressed('3'))
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); //default fill mode
	if(Application::IsKeyPressed('4'))
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); //wireframe mode

	if(Application::IsKeyPressed('5'))
	{
		B_Light = true;
	}
	if(Application::IsKeyPressed('6'))
	{
		B_Light = false;
	}

	//===Controls===//

	if(Application::IsKeyPressed('I'))
	{
		isShown = true;
	}

	if(Application::IsKeyPressed('O'))
	{
		isShown = false;
	}

	//===Character Control===//
	static float ROTATE_SPEED = 50.f;
	static int count = 0;

	if (Application::IsKeyPressed('8') || Application::IsKeyPressed('9')) //currently i set it to press 9 to animate character
	{
		movingModel = true;
	}
	else
	{
		movingModel = false;
	}

	if (movingModel == true)
	{
		rotateRightArms += (float)(rotatingRightArm * dt * ROTATE_SPEED);
		rotateLeftLeg += (float)(rotatingLeftLeg * dt * ROTATE_SPEED);
		rotateRightLeg -= (float)(rotatingRightLeg * dt * ROTATE_SPEED);

		if (rotateRightArms >= 405)//rotating right arm
		{
			rotatingRightArm = -1;
			count++;
		}
		if(rotateRightArms <= 330)
		{
			rotatingRightArm = 1;
		}

		if (rotateLeftArms >= 405)//rotatin left arm
		{
			rotatingLeftArm = -1;
		}
		if(rotateLeftArms <= 330)
		{
			rotatingLeftArm = 1;
		}

		if (rotateLeftLeg >= 405)//rotatin left leg
		{
			rotatingLeftLeg = -1;
		}
		if(rotateLeftLeg <= 315)
		{
			rotatingLeftLeg = 1;
		}

		if (rotateRightLeg >= 405)//rotatin right leg
		{
			rotatingRightLeg = 1;
		}
		if(rotateRightLeg <= 315)
		{
			rotatingRightLeg = -1;
		}

		if (count >= 1)
		{
			rotateLeftArms += (float)(rotatingLeftArm * dt * ROTATE_SPEED);
		}
	}

	else if (movingModel == false)
	{
		count = 0;
		rotatingRightArm = 1;
		rotatingLeftArm = 1;
		rotatingRightLeg = 1;
		rotatingLeftLeg = 1;
		if (rotateRightArms > 360)//moving back right arm
		{
			rotateRightArms -= (float)(rotatingRightArm * dt * ROTATE_SPEED);
			if (rotateRightArms <= 360)
			{
				rotateRightArms = 360;
			}
		}
		else if (rotateRightArms < 360)
		{
			rotateRightArms += (float)(rotatingRightArm * dt * ROTATE_SPEED);
			if (rotateRightArms >= 360)
			{
				rotateRightArms = 360;
			}
		}

		if (rotateLeftArms > 360)//moving back left arm
		{
			rotateLeftArms -= (float)(rotatingLeftArm * dt * ROTATE_SPEED);
			if (rotateLeftArms <= 360)
			{
				rotateLeftArms = 360;
			}
		}
		else if (rotateLeftArms < 360)
		{
			rotateLeftArms += (float)(rotatingLeftArm * dt * ROTATE_SPEED);
			if (rotateLeftArms >= 360)
			{
				rotateLeftArms = 360;
			}
		}

		if (rotateRightLeg > 360)//moving back right leg
		{
			rotateRightLeg -= (float)(rotatingRightLeg * dt * ROTATE_SPEED);
			if (rotateRightLeg <= 360)
			{
				rotateRightLeg = 360;
			}
		}
		else if (rotateRightLeg < 360)
		{
			rotateRightLeg += (float)(rotatingRightLeg * dt * ROTATE_SPEED);
			if (rotateRightLeg >= 360)
			{
				rotateRightLeg = 360;
			}
		}

		if (rotateLeftLeg > 360)//moving back left arm
		{
			rotateLeftLeg -= (float)(rotatingRightLeg * dt * ROTATE_SPEED);
			if (rotateLeftLeg <= 360)
			{
				rotateLeftLeg = 360;
			}
		}
		else if (rotateLeftLeg < 360)
		{
			rotateLeftLeg += (float)(rotatingLeftLeg * dt * ROTATE_SPEED);
			if (rotateLeftLeg >= 360)
			{
				rotateLeftLeg = 360;
			}
		}
	}

	/*if (Application::IsKeyPressed('8'))
	{
		charPosition.z += cos(Math::DegreeToRadian(angle)) * 10 * dt;
		charPosition.x += sin(Math::DegreeToRadian(angle)) * 10 * dt;
	}
	if (Application::IsKeyPressed('9'))
	{
		charPosition.z -= cos(Math::DegreeToRadian(angle)) * 10 * dt;
		charPosition.x -= sin(Math::DegreeToRadian(angle)) * 10 * dt;
	}*/
	if (Application::IsKeyPressed('I'))
	{
		angle += 100 * dt;
	}
	if (Application::IsKeyPressed('O'))
	{
		angle -= 100 * dt;
	}

	/*========================================================
							Player
	=========================================================*/
	player.setPosition(camera.position.x,camera.position.y,camera.position.z);

	/*=======================================================
						Interactions
	==========================================================*/
	//============================DOOR===========================//

	//This part is code for door opening
	if (camera.position.z <20.1 && camera.position.z >=-19.7 && camera.position.y >=5 && camera.position.y <= 10 && camera.position.x <=-41.5 && camera.position.x >= -76.3)
	{
		if(Opened == false &&  Closed == true && doorStop == true)
		{
			Closed = false;
			doorMoving = true;
		}

		if(Closed == false && doorMoving == true)
		{
			doorTranslate -=(float)(35*dt);
			if(doorTranslate < -20)
			{
				doorMoving = false;
				Opened = true;
				doorStop = true;
			}	

		}
	}
	//This part is for closing of the door
	else
	{
		Opened = false;
		if(Opened == false && Closed == false )
		{
			doorTranslate +=(float)(35*dt);
			if(doorTranslate > 0)
			{
				Closed = true;
			}

		}
	}
//==============================END OF DOOR ==========================//
	if(checking == false)
	{
		if(Application::IsKeyPressed('E'))
		{
			for(int i = 0; i < boxContainer.size(); ++i) //Container 1
			{
				checking = true;
				//==========Taking Items from shelf=============//
				if(Container[i].getRender() == true)
				{
					if((camera.target.x <= boxContainer[i].max.x) &&
						(camera.target.y <= boxContainer[i].max.y) && 
						(camera.target.z <= boxContainer[i].max.z) &&
						(camera.target.x >= boxContainer[i].min.x) && 
						(camera.target.y >= boxContainer[i].min.y) && 
						(camera.target.z >= boxContainer[i].min.z))
					{
						if(player.getInventory().AddItem(Container[i]) == true)
						{
							Container[i].setRender(false);
							break;
						}
					}
				}
			}

			for(int i = 0; i < boxContainer2.size(); ++i)//Container 2
			{
				checking = true;
				//==========Taking Items from shelf=============//
				if(Container2[i].getRender() == true)
				{
					if((camera.target.x <= boxContainer2[i].max.x) && 
						(camera.target.y <= boxContainer2[i].max.y) && 
						(camera.target.z <= boxContainer2[i].max.z) && 
						(camera.target.x >= boxContainer2[i].min.x) && 
						(camera.target.y >= boxContainer2[i].min.y) && 
						(camera.target.z >= boxContainer2[i].min.z))
					{
						if(player.getInventory().AddItem(Container2[i]) == true)
						{
							Container2[i].setRender(false);
							break;
						}
					}
				}
			}

			for(int i = 0; i < boxContainer3.size(); ++i) //Container 3
			{
				checking = true;
				//==========Taking Items from shelf=============//
				if(Container3[i].getRender() == true)
				{
					if((camera.target.x <= boxContainer3[i].max.x) && 
						(camera.target.y <= boxContainer3[i].max.y) && 
						(camera.target.z <= boxContainer3[i].max.z) && 
						(camera.target.x >= boxContainer3[i].min.x) && 
						(camera.target.y >= boxContainer3[i].min.y) && 
						(camera.target.z >= boxContainer3[i].min.z))
					{
						if(player.getInventory().AddItem(Container3[i]) == true)
						{
							Container3[i].setRender(false);
							break;
						}
					}
				}
			}

			for(int i = 0; i < boxContainer4.size(); ++i) //Container 4
			{
				checking = true;
				//==========Taking Items from shelf=============//
				if(Container4[i].getRender() == true)
				{
					if((camera.target.x <= boxContainer4[i].max.x) && 
						(camera.target.y <= boxContainer4[i].max.y) && 
						(camera.target.z <= boxContainer4[i].max.z) && 
						(camera.target.x >= boxContainer4[i].min.x) && 
						(camera.target.y >= boxContainer4[i].min.y) && 
						(camera.target.z >= boxContainer4[i].min.z))
					{
						if(player.getInventory().AddItem(Container4[i]) == true)
						{
							Container4[i].setRender(false);
							break;
						}
					}
				}
			}

			for(int i = 0; i < boxContainer5.size(); ++i) //Container 5
			{
				checking = true;
				//==========Taking Items from shelf=============//
				if(Container5[i].getRender() == true)
				{
					if((camera.target.x <= boxContainer5[i].max.x) && 
						(camera.target.y <= boxContainer5[i].max.y) && 
						(camera.target.z <= boxContainer5[i].max.z) && 
						(camera.target.x >= boxContainer5[i].min.x) && 
						(camera.target.y >= boxContainer5[i].min.y) && 
						(camera.target.z >= boxContainer5[i].min.z))
					{
						if(player.getInventory().AddItem(Container5[i]) == true)
						{
							Container5[i].setRender(false);
							break;
						}
					}
				}
			}

			for(int i = 0; i < boxContainer6.size(); ++i) //Container 6
			{
				checking = true;
				//==========Taking Items from shelf=============//
				if(Container6[i].getRender() == true)
				{
					if((camera.target.x <= boxContainer6[i].max.x) && 
						(camera.target.y <= boxContainer6[i].max.y) && 
						(camera.target.z <= boxContainer6[i].max.z) && 
						(camera.target.x >= boxContainer6[i].min.x) && 
						(camera.target.y >= boxContainer6[i].min.y) && 
						(camera.target.z >= boxContainer6[i].min.z))
					{
						if(player.getInventory().AddItem(Container6[i]) == true)
						{
							Container6[i].setRender(false);
							break;
						}
					}
				}
			}

			for(int i = 0; i < boxContainer7.size(); ++i) //Container 7
			{
				checking = true;
				//==========Taking Items from shelf=============//
				if(Container7[i].getRender() == true)
				{
					if((camera.target.x <= boxContainer7[i].max.x) && 
						(camera.target.y <= boxContainer7[i].max.y) && 
						(camera.target.z <= boxContainer7[i].max.z) && 
						(camera.target.x >= boxContainer7[i].min.x) && 
						(camera.target.y >= boxContainer7[i].min.y) && 
						(camera.target.z >= boxContainer7[i].min.z))
					{
						if(player.getInventory().AddItem(Container7[i]) == true)
						{
							Container7[i].setRender(false);
							break;
						}
					}
				}
			}

			for(int i = 0; i < boxContainer8.size(); ++i) //Container 8
			{
				checking = true;
				//==========Taking Items from shelf=============//
				if(Container8[i].getRender() == true)
				{
					if((camera.target.x <= boxContainer8[i].max.x) && 
						(camera.target.y <= boxContainer8[i].max.y) && 
						(camera.target.z <= boxContainer8[i].max.z) && 
						(camera.target.x >= boxContainer8[i].min.x) && 
						(camera.target.y >= boxContainer8[i].min.y) && 
						(camera.target.z >= boxContainer8[i].min.z))
					{
						if(player.getInventory().AddItem(Container8[i]) == true)
						{
							Container8[i].setRender(false);
							break;
						}
					}
				}
			}
			for(int i = 0; i < boxContainer9.size(); ++i) //Container 9
			{
				checking = true;
				//==========Taking Items from shelf=============//
				if(Container9[i].getRender() == true)
				{
					if((camera.target.x <= boxContainer9[i].max.x) && 
						(camera.target.y <= boxContainer9[i].max.y) && 
						(camera.target.z <= boxContainer9[i].max.z) && 
						(camera.target.x >= boxContainer9[i].min.x) && 
						(camera.target.y >= boxContainer9[i].min.y) && 
						(camera.target.z >= boxContainer9[i].min.z))
					{
						if(player.getInventory().AddItem(Container9[i]) == true)
						{
							Container9[i].setRender(false);
							break;
						}
					}
				}
			}
			for(int i = 0; i < boxContainer10.size(); ++i) //Container 10
			{
				checking = true;
				//==========Taking Items from shelf=============//
				if(Container10[i].getRender() == true)
				{
					if((camera.target.x <= boxContainer10[i].max.x) && 
						(camera.target.y <= boxContainer10[i].max.y) && 
						(camera.target.z <= boxContainer10[i].max.z) && 
						(camera.target.x >= boxContainer10[i].min.x) && 
						(camera.target.y >= boxContainer10[i].min.y) && 
						(camera.target.z >= boxContainer10[i].min.z))
					{
						if(player.getInventory().AddItem(Container10[i]) == true)
						{
							Container10[i].setRender(false);
							break;
						}
					}
				}
			}

			for(int i = 0; i < boxContainer11.size(); ++i) //Container 11
			{
				checking = true;
				//==========Taking Items from shelf=============//
				if(Container11[i].getRender() == true)
				{
					if((camera.target.x <= boxContainer11[i].max.x) && 
						(camera.target.y <= boxContainer11[i].max.y) && 
						(camera.target.z <= boxContainer11[i].max.z) && 
						(camera.target.x >= boxContainer11[i].min.x) && 
						(camera.target.y >= boxContainer11[i].min.y) && 
						(camera.target.z >= boxContainer11[i].min.z))
					{
						if(player.getInventory().AddItem(Container11[i]) == true)
						{
							Container11[i].setRender(false);
							break;
						}
					}
				}
			}
			for(int i = 0; i < boxContainer12.size(); ++i) //Container 12
			{
				checking = true;
				//==========Taking Items from shelf=============//
				if(Container12[i].getRender() == true)
				{
					if((camera.target.x <= boxContainer12[i].max.x) && 
						(camera.target.y <= boxContainer12[i].max.y) && 
						(camera.target.z <= boxContainer12[i].max.z) && 
						(camera.target.x >= boxContainer12[i].min.x) && 
						(camera.target.y >= boxContainer12[i].min.y) && 
						(camera.target.z >= boxContainer12[i].min.z))
					{
						if(player.getInventory().AddItem(Container12[i]) == true)
						{
							Container12[i].setRender(false);
							break;
						}
					}
				}
			}
			checking = false;
		}
	}
	/*===============================================================
								CHECKING OUT
	==================================================================*/
	if(Application::IsKeyPressed('E') && (player.getInventory().getNoOfItems() != 0))
	{
		for(int i = 0;i < CashierBox.size();i++)
		{
			if((camera.position.x <= CashierBox[i].max.x) && 
				(camera.position.y <= CashierBox[i].max.y) && 
				(camera.position.z <= CashierBox[i].max.z) &&
				(camera.position.x >= CashierBox[i].min.x) && 
				(camera.position.y >= CashierBox[i].min.y) && 
				(camera.position.z >= CashierBox[i].min.z))
			{
				float cost = 0.f;
				//Calculating Cost of items taken by player
				for(int i = 1; i < (player.getInventory().getNoOfItems() + 1); i++)
				{
					cost += player.getInventory().getItem(i).getPrice();
					cout << player.getInventory().getItem(i).getName() << endl;
				}
				//Only if cost is lesser or equal player will be successfully checked out and items removed from invent
				if(cost < player.getMoney())
				{
					for(int i = 1; i < (player.getInventory().getNoOfItems() + 1); i++)
					{
						player.getInventory().removeItem(i);
					}
					player.setMoney(player.getMoney() - cost);
				}
			}
		}
	}

	if(Application::IsKeyPressed('Q'))
	{
		for(int i = 0; i < boxContainer.size(); ++i)
		{
		//==========Putting items back to shelf=============//
			if(Container[i].getRender() == false)//Container 1
			{
				if((camera.target.x <= boxContainer[i].max.x) && 
					(camera.target.y <= boxContainer[i].max.y) && 
					(camera.target.z <= boxContainer[i].max.z) &&
					(camera.target.x >= boxContainer[i].min.x) && 
					(camera.target.y >= boxContainer[i].min.y) && 
					(camera.target.z >= boxContainer[i].min.z))
				{
					if(player.getInventory().removeItem(Container[i]) == true)
					{
						Container[i].setRender(true);
						break;
					}
				}
			}
		}
		for(int i = 0; i < boxContainer2.size(); ++i)//Container 2
		{
			if(Container2[i].getRender() == false)
			{
				if((camera.target.x <= boxContainer2[i].max.x) && 
					(camera.target.y <= boxContainer2[i].max.y) && 
					(camera.target.z <= boxContainer2[i].max.z) &&
					(camera.target.x >= boxContainer2[i].min.x) && 
					(camera.target.y >= boxContainer2[i].min.y) &&
					(camera.target.z >= boxContainer2[i].min.z))
				{
					if(player.getInventory().removeItem(Container2[i]) == true)
					{
						Container2[i].setRender(true);
						break;
					}
				}
			}
		}

		for(int i = 0; i < boxContainer3.size(); ++i)//Container 3
		{
			if(Container3[i].getRender() == false)
			{
				if((camera.target.x <= boxContainer3[i].max.x) && 
					(camera.target.y <= boxContainer3[i].max.y) && 
					(camera.target.z <= boxContainer3[i].max.z) &&
					(camera.target.x >= boxContainer3[i].min.x) && 
					(camera.target.y >= boxContainer3[i].min.y) &&
					(camera.target.z >= boxContainer3[i].min.z))
				{
					if(player.getInventory().removeItem(Container3[i]) == true)
					{
						Container3[i].setRender(true);
						break;
					}
				}
			}
		}

		for(int i = 0; i < boxContainer4.size(); ++i)
		{
		//==========Putting items back to shelf=============//
			if(Container4[i].getRender() == false)//Container 4
			{
				if((camera.target.x <= boxContainer4[i].max.x) && 
					(camera.target.y <= boxContainer4[i].max.y) && 
					(camera.target.z <= boxContainer4[i].max.z) &&
					(camera.target.x >= boxContainer4[i].min.x) && 
					(camera.target.y >= boxContainer4[i].min.y) && 
					(camera.target.z >= boxContainer4[i].min.z))
				{
					if(player.getInventory().removeItem(Container4[i]) == true)
					{
						Container4[i].setRender(true);
						break;
					}
				}
			}
		}
		for(int i = 0; i < boxContainer5.size(); ++i)//Container 5
		{
			if(Container5[i].getRender() == false)
			{
				if((camera.target.x <= boxContainer5[i].max.x) && 
					(camera.target.y <= boxContainer5[i].max.y) && 
					(camera.target.z <= boxContainer5[i].max.z) &&
					(camera.target.x >= boxContainer5[i].min.x) && 
					(camera.target.y >= boxContainer5[i].min.y) &&
					(camera.target.z >= boxContainer5[i].min.z))
				{
					if(player.getInventory().removeItem(Container5[i]) == true)
					{
						Container5[i].setRender(true);
						break;
					}
				}
			}
		}

		for(int i = 0; i < boxContainer6.size(); ++i)//Container 6
		{
			if(Container6[i].getRender() == false)
			{
				if((camera.target.x <= boxContainer6[i].max.x) && 
					(camera.target.y <= boxContainer6[i].max.y) && 
					(camera.target.z <= boxContainer6[i].max.z) &&
					(camera.target.x >= boxContainer6[i].min.x) && 
					(camera.target.y >= boxContainer6[i].min.y) &&
					(camera.target.z >= boxContainer6[i].min.z))
				{
					if(player.getInventory().removeItem(Container6[i]) == true)
					{
						Container6[i].setRender(true);
						break;
					}
				}
			}
		}
		for(int i = 0; i < boxContainer7.size(); ++i)//Container 7
		{
			if(Container7[i].getRender() == false)
			{
				if((camera.target.x <= boxContainer7[i].max.x) && 
					(camera.target.y <= boxContainer7[i].max.y) && 
					(camera.target.z <= boxContainer7[i].max.z) &&
					(camera.target.x >= boxContainer7[i].min.x) && 
					(camera.target.y >= boxContainer7[i].min.y) &&
					(camera.target.z >= boxContainer7[i].min.z))
				{
					if(player.getInventory().removeItem(Container7[i]) == true)
					{
						Container7[i].setRender(true);
						break;
					}
				}
			}
		}

		for(int i = 0; i < boxContainer8.size(); ++i)//Container 8
		{
			if(Container8[i].getRender() == false)
			{
				if((camera.target.x <= boxContainer8[i].max.x) && 
					(camera.target.y <= boxContainer8[i].max.y) && 
					(camera.target.z <= boxContainer8[i].max.z) &&
					(camera.target.x >= boxContainer8[i].min.x) && 
					(camera.target.y >= boxContainer8[i].min.y) &&
					(camera.target.z >= boxContainer8[i].min.z))
				{
					if(player.getInventory().removeItem(Container8[i]) == true)
					{
						Container8[i].setRender(true);
						break;
					}
				}
			}
		}
		for(int i = 0; i < boxContainer9.size(); ++i)//Container 9
		{
			if(Container9[i].getRender() == false)
			{
				if((camera.target.x <= boxContainer9[i].max.x) && 
					(camera.target.y <= boxContainer9[i].max.y) && 
					(camera.target.z <= boxContainer9[i].max.z) &&
					(camera.target.x >= boxContainer9[i].min.x) && 
					(camera.target.y >= boxContainer9[i].min.y) &&
					(camera.target.z >= boxContainer9[i].min.z))
				{
					if(player.getInventory().removeItem(Container9[i]) == true)
					{
						Container9[i].setRender(true);
						break;
					}
				}
			}
		}
		for(int i = 0; i < boxContainer10.size(); ++i)//Container 10
		{
			if(Container10[i].getRender() == false)
			{
				if((camera.target.x <= boxContainer10[i].max.x) && 
					(camera.target.y <= boxContainer10[i].max.y) && 
					(camera.target.z <= boxContainer10[i].max.z) &&
					(camera.target.x >= boxContainer10[i].min.x) && 
					(camera.target.y >= boxContainer10[i].min.y) &&
					(camera.target.z >= boxContainer10[i].min.z))
				{
					if(player.getInventory().removeItem(Container10[i]) == true)
					{
						Container10[i].setRender(true);
						break;
					}
				}
			}
		}
		for(int i = 0; i < boxContainer11.size(); ++i)//Container 11
		{
			if(Container11[i].getRender() == false)
			{
				if((camera.target.x <= boxContainer11[i].max.x) && 
					(camera.target.y <= boxContainer11[i].max.y) && 
					(camera.target.z <= boxContainer11[i].max.z) &&
					(camera.target.x >= boxContainer11[i].min.x) && 
					(camera.target.y >= boxContainer11[i].min.y) &&
					(camera.target.z >= boxContainer11[i].min.z))
				{
					if(player.getInventory().removeItem(Container11[i]) == true)
					{
						Container11[i].setRender(true);
						break;
					}
				}
			}
		}
		for(int i = 0; i < boxContainer12.size(); ++i)//Container 12
		{
			if(Container12[i].getRender() == false)
			{
				if((camera.target.x <= boxContainer12[i].max.x) && 
					(camera.target.y <= boxContainer12[i].max.y) && 
					(camera.target.z <= boxContainer12[i].max.z) &&
					(camera.target.x >= boxContainer12[i].min.x) && 
					(camera.target.y >= boxContainer12[i].min.y) &&
					(camera.target.z >= boxContainer12[i].min.z))
				{
					if(player.getInventory().removeItem(Container12[i]) == true)
					{
						Container12[i].setRender(true);
						break;
					}
				}
			}
		}
	}

	if((camera.target.x <= boxContainer[0].max.x) && 
		(camera.target.y <= boxContainer[0].max.y) && 
		(camera.target.z <= boxContainer[0].max.z) &&
		(camera.target.x >= boxContainer[0].min.x) &&
		(camera.target.y >= boxContainer[0].min.y) &&
		(camera.target.z >= boxContainer[0].min.z))
	{
		collide = true;
	}
	else
	{
		collide = false;
	}


	//if(player.getInventory().getNoOfItems() > 0)
	//{
	//	cout << player.getInventory().getItem(1).getName() << endl;
	//}

	//====Camera coordinates===//
	std::ostringstream ss;
	fps = 1/dt;
	ss << fps;
	result = ss.str();

	std::ostringstream ss2;
	ss2 << camera.position.x;
	camerax = ss2.str();

	std::ostringstream ss3;
	ss3 << camera.position.y;
	cameray = ss3.str();

	std::ostringstream ss4;
	ss4 << camera.position.z;
	cameraz = ss4.str();

	//====Camera Target======//
	std::ostringstream ss5;
	ss5 << camera.target.x;
	viewx = ss5.str();

	std::ostringstream ss6;
	ss6 << camera.target.y;
	viewy = ss6.str();

	std::ostringstream ss7;
	ss7 <<  camera.target.z;
	viewz = ss7.str();

	//====Player Money===//
	std::ostringstream ss8;
	ss8 <<  player.getMoney();
	Cash = ss8.str();

	//================Item Inventory Image=================//
	static float elapsedTime1 = 0, elapsedTime2 = 0;
	elapsedTime1 = fmod(Timer.getElapsedTime(), 1);

	if (elapsedTime2 <= 0.15)
	{
		elapsedTime2 += elapsedTime1;
	}
	else
	{
		elapsedTime2 += 0;
	}

	if (Application::IsKeyPressed(VK_TAB) && elapsedTime2 >= 0.15)
	{
		if (showInventory == false)
		{
			showInventory = true;
		}
		else if (showInventory == true)
		{
			showInventory = false;
		}
		elapsedTime2 -= 0.15;
	}
	//std::cout << elapsedTime2 << endl;

	//================Testing =================//
	//cout << Container.size() << endl;
	if (Application::IsKeyPressed('M'))
		moving += (float) (10 * dt);
	if (Application::IsKeyPressed('N'))
		moving -= (float) (10 * dt);

	camera.Update(dt);
}

//=========Rendering of Skybox to be done here=========//
void StudioProject::RenderSkybox()
{
	//Back
	modelStack.PushMatrix();
	modelStack.Translate(0.f, 0.f, (worldsize/2) - 1);
	modelStack.Rotate(180, 0, 1, 0);
	modelStack.Scale(worldsize, worldsize, worldsize);
	RenderMesh(meshList[GEO_BACKSKY], false);
	modelStack.PopMatrix();

	//Front
	modelStack.PushMatrix();
	modelStack.Translate(0.f, 0.f, (-worldsize/2) + 1);
	modelStack.Rotate(180, 0, 1, 0);
	modelStack.PushMatrix();
	modelStack.Rotate(-180, 1, 0, 0);
	modelStack.PushMatrix();
	modelStack.Rotate(-180, 0, 0, 1);
	modelStack.Scale(worldsize, worldsize, worldsize);
	RenderMesh(meshList[GEO_FRONTSKY], false);
	modelStack.PopMatrix();
	modelStack.PopMatrix();
	modelStack.PopMatrix();

	//Top
	modelStack.PushMatrix();
	modelStack.Rotate(360,0,1,0);
	modelStack.Translate(0.f, (worldsize/2) - 1, 0.f);
	modelStack.Rotate(90, 1, 0, 0);
	modelStack.PushMatrix();
	modelStack.Rotate(270, 0, 0, 1);
	modelStack.Scale(worldsize, worldsize, worldsize);
	RenderMesh(meshList[GEO_SKY], false);
	modelStack.PopMatrix();
	modelStack.PopMatrix();

	//modelStack.PushMatrix();
	//modelStack.Translate(0.f, 0.f, (worldsize/2) - 1);
	//modelStack.Rotate(180, 0, 1, 0);
	//modelStack.Scale(worldsize, worldsize, worldsize);
	//RenderMesh(meshList[GEO_BACK], false);
	//modelStack.PopMatrix();

	////Front
	//modelStack.PushMatrix();
	//modelStack.Translate(0.f, 0.f, (-worldsize/2) + 1);
	//modelStack.Rotate(180, 0, 1, 0);
	//modelStack.PushMatrix();
	//modelStack.Rotate(-180, 1, 0, 0);
	//modelStack.PushMatrix();
	//modelStack.Rotate(-180, 0, 0, 1);
	//modelStack.Scale(worldsize, worldsize, worldsize);
	//RenderMesh(meshList[GEO_FRONT], false);
	//modelStack.PopMatrix();
	//modelStack.PopMatrix();
	//modelStack.PopMatrix();

	////Top
	//modelStack.PushMatrix();
	//modelStack.Translate(0.f, (worldsize/2) - 1, 0.f);
	//modelStack.Rotate(90, 1, 0, 0);
	//modelStack.PushMatrix();
	//modelStack.Rotate(270, 0, 0, 1);
	//modelStack.Scale(worldsize, worldsize, worldsize);
	//RenderMesh(meshList[GEO_TOP], false);
	//modelStack.PopMatrix();
	//modelStack.PopMatrix();


	//Bottom
	//modelStack.PushMatrix();
	//modelStack.Translate(0.f, (-worldsize/2) + 1, 0.f);
	//modelStack.Rotate(90,1,0,0);
	//modelStack.Scale(worldsize, worldsize, worldsize);
	//RenderMesh(meshList[GEO_BOTTOM], false);
	//modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0.f, (-worldsize/2) + 1, 0.f);
	modelStack.Rotate(90,1,0,0);
	modelStack.Scale(worldsize, worldsize, worldsize);
	RenderMesh(meshList[GEO_BOTTOMSKY], false);
	modelStack.PopMatrix();

	//RIGHT
	modelStack.PushMatrix();
	modelStack.Rotate(90,1,0,0);
	modelStack.Translate((worldsize/2) - 1, 0.f, 0.f);
	modelStack.Rotate(90, 0, 1, 0);
	modelStack.PushMatrix();
	modelStack.Rotate(270, 0, 0, 1);
	modelStack.Scale(worldsize, worldsize, worldsize);
	RenderMesh(meshList[GEO_RIGHTSKY], false);
	modelStack.PopMatrix();
	modelStack.PopMatrix();

	//LEFT
	modelStack.PushMatrix();
	modelStack.Rotate(-90,1,0,0);
	modelStack.PushMatrix();
	modelStack.Translate((-worldsize/2) + 1, 0.f, 0.f);
	modelStack.Rotate(90, 0, 1, 0);
	modelStack.PushMatrix();
	modelStack.Rotate(90, 0, 0, 1);
	modelStack.Scale(worldsize, worldsize, worldsize);
	RenderMesh(meshList[GEO_LEFTSKY], false);
	modelStack.PopMatrix();

	modelStack.PopMatrix();
	RenderMesh(meshList[GEO_FLOOR], false);
	modelStack.PopMatrix();

	//RIGHT
	//modelStack.PushMatrix();
	//modelStack.Translate((worldsize/2) - 1, 0.f, 0.f);
	//modelStack.Rotate(90, 0, 1, 0);
	//modelStack.PushMatrix();
	//modelStack.Rotate(-180, 0, 1, 0);
	//modelStack.Scale(worldsize, worldsize, worldsize);
	//RenderMesh(meshList[GEO_RIGHT], false);
	//modelStack.PopMatrix();
	//modelStack.PopMatrix();

	////LEFT
	//modelStack.PushMatrix();
	//modelStack.Translate((-worldsize/2) + 1, 0.f, 0.f);
	//modelStack.Rotate(-90, 0, 1, 0);
	//modelStack.PushMatrix();
	//modelStack.Rotate(180, 0, 1, 0);
	//modelStack.Scale(worldsize, worldsize, worldsize);
	//RenderMesh(meshList[GEO_LEFT], false);
	//modelStack.PopMatrix();
	//modelStack.PopMatrix();
}

void StudioProject::RenderSupermarket()
{
	/*===============================================================
	Level 1 Of Supermarket
	================================================================*/
	modelStack.PushMatrix();
	//modelStack.Rotate(180, 0, 1, 0);
	modelStack.Scale(5,5,5);
	RenderMesh(meshList[GEO_MARKET],B_Light);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(-28, -1, -15);
	modelStack.Rotate(180, 0, 1, 0);
	RenderMesh(meshList[GEO_CASHIER],B_Light);

	modelStack.PushMatrix();
	modelStack.Translate(0.5, 3.7, 3.5);
	modelStack.Rotate(-90, 0, 1, 0);
	modelStack.Scale(0.8, 0.8, 0.8);
	RenderMesh(meshList[GEO_CASHREG],B_Light);
	modelStack.PopMatrix();
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(-28, -1, 3);
	modelStack.Rotate(180, 0, 1, 0);
	RenderMesh(meshList[GEO_CASHIER],B_Light);

	modelStack.PushMatrix();
	modelStack.Translate(0.5, 3.7, 3.5);
	modelStack.Rotate(-90, 0, 1, 0);
	modelStack.Scale(0.8, 0.8, 0.8);
	RenderMesh(meshList[GEO_CASHREG],B_Light);
	modelStack.PopMatrix();
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(-28, -1, 20);
	modelStack.Rotate(180, 0, 1, 0);
	RenderMesh(meshList[GEO_CASHIER],B_Light);

	modelStack.PushMatrix();
	modelStack.Translate(0.5, 3.7, 3.5);
	modelStack.Rotate(-90, 0, 1, 0);
	modelStack.Scale(0.8, 0.8, 0.8);
	RenderMesh(meshList[GEO_CASHREG],B_Light);
	modelStack.PopMatrix();
	modelStack.PopMatrix();

	//Extreme left cold food shelf
	for(int i = -2; i < 3; ++i)
	{
		modelStack.PushMatrix();
		modelStack.Translate(i*14,-1,-91);
		modelStack.Rotate(90,0,-1,0);
		RenderMesh(meshList[GEO_COLDFOODSHELF],B_Light);
		modelStack.PopMatrix();
	}
	//Back of market (Cold food shelf)
	for(int i = -5; i < 5; ++i)
	{
		modelStack.PushMatrix();
		modelStack.Translate(51.5,-1,i*14);
		modelStack.Rotate(180,0,-1,0);
		RenderMesh(meshList[GEO_COLDFOODSHELF],B_Light);
		modelStack.PopMatrix();
	}

	//Left side (metal Shelf 2)
	for(int i = -5; i <4; ++i)
	{
		modelStack.PushMatrix();
		modelStack.Translate(i*6, -1, -58);
		modelStack.Rotate(90,0,1,0);
		RenderMesh(meshList[GEO_SHELF2],B_Light);
		modelStack.PopMatrix();
	}

	//Left side wooden shelf
	for(int i = -2; i <2; ++i)
	{
		modelStack.PushMatrix();
		modelStack.Translate(i*12, -1 , -35);
		RenderMesh(meshList[GEO_SHELF],B_Light);
		modelStack.PopMatrix();
	}


	//Right side (metal Shelf 2)
	for(int i = -5; i <4; ++i)
	{
		modelStack.PushMatrix();
		modelStack.Translate(i*6, -1, 58);
		modelStack.Rotate(90,0,1,0);
		RenderMesh(meshList[GEO_SHELF2],B_Light);
		modelStack.PopMatrix();
	}

	//Right side wooden shelf
	for(int i = -2; i <2; ++i)
	{
		modelStack.PushMatrix();
		modelStack.Translate(i*12, -1 , 35);
		RenderMesh(meshList[GEO_SHELF],B_Light);
		modelStack.PopMatrix();
	}

	//Middle metal shelf
	for(int i = -1; i<3; ++i)
	{
		modelStack.PushMatrix();
		modelStack.Translate(11, -1, i*6);
		RenderMesh(meshList[GEO_SHELF2],B_Light);
		modelStack.PopMatrix();
	}
	//Right most railing (POV from the entrance)
	modelStack.PushMatrix();
	modelStack.Translate(-21,-1,26);
	RenderMesh(meshList[GEO_RAIL],B_Light);
	modelStack.PopMatrix();

	//middle most railing (POV from the entrance)
	modelStack.PushMatrix();
	modelStack.Translate(-21,-1,8);
	RenderMesh(meshList[GEO_RAIL],B_Light);
	modelStack.PopMatrix();

	//left most railing (POV from the entrance)
	modelStack.PushMatrix();
	modelStack.Translate(-21,-1,1-11);
	RenderMesh(meshList[GEO_RAIL],B_Light);
	modelStack.PopMatrix();

	
}

void StudioProject::RenderItems()
{
	for(int i = 0; i < Container.size(); ++i) //Container 1
	{
		if(Container[i].getRender() == true)
		{
			//========MIDDLE ROW FRONT=========//
			modelStack.PushMatrix();
			modelStack.LoadMatrix(Container[i].getTRS());
			modelStack.Rotate(90,0,1,0);
			RenderMesh(Container[i].getMesh(),B_Light);
			modelStack.PopMatrix(); //pop back to origin
		}
	}
	for(int i = 0; i < Container2.size(); ++i) //Container 2
	{
		if(Container2[i].getRender() == true)
		{
			//========MIDDLE ROW BACK=========//
			modelStack.PushMatrix();
			modelStack.LoadMatrix(Container2[i].getTRS());
			modelStack.Rotate(270,0,1,0);
			RenderMesh(Container2[i].getMesh(),B_Light);
			modelStack.PopMatrix(); //pop back to origin
		}
	}
	for(int i = 0; i < Container2.size(); ++i) //Container 3
	{
		if(Container2[i].getRender() == true)
		{
			//========MIDDLE ROW BACK=========//
			modelStack.PushMatrix();
			modelStack.LoadMatrix(Container2[i].getTRS());
			modelStack.Rotate(270,0,1,0);
			RenderMesh(Container2[i].getMesh(),B_Light);
			modelStack.PopMatrix(); //pop back to origin
		}
	}
	for(int i = 0; i < Container3.size(); ++i) //Container 3
	{
		if(Container3[i].getRender() == true)
		{
			//========MIDDLE ROW BACK=========//
			modelStack.PushMatrix();
			modelStack.LoadMatrix(Container3[i].getTRS());
			modelStack.Rotate(270,0,1,0);
			RenderMesh(Container3[i].getMesh(),B_Light);
			modelStack.PopMatrix(); //pop back to origin
		}
	}
	for(int i = 0; i < Container4.size(); ++i) //Container 4
	{
		if(Container4[i].getRender() == true)
		{
			//========MIDDLE ROW BACK=========//
			modelStack.PushMatrix();
			modelStack.LoadMatrix(Container4[i].getTRS());
			modelStack.Rotate(270,0,1,0);
			RenderMesh(Container4[i].getMesh(),B_Light);
			modelStack.PopMatrix(); //pop back to origin
		}
	}
	for(int i = 0; i < Container5.size(); ++i) //Container 5
	{
		if(Container5[i].getRender() == true)
		{
			//========MIDDLE ROW BACK=========//
			modelStack.PushMatrix();
			modelStack.LoadMatrix(Container5[i].getTRS());
			modelStack.Rotate(180,0,1,0);
			RenderMesh(Container5[i].getMesh(),B_Light);
			modelStack.PopMatrix(); //pop back to origin
		}
	}
	for(int i = 0; i < Container6.size(); ++i) //Container 6
	{
		if(Container6[i].getRender() == true)
		{
			//========MIDDLE ROW BACK=========//
			modelStack.PushMatrix();
			modelStack.LoadMatrix(Container6[i].getTRS());
			//modelStack.Rotate(270,0,1,0);
			RenderMesh(Container6[i].getMesh(),B_Light);
			modelStack.PopMatrix(); //pop back to origin
		}
	}

	for(int i = 0; i < Container7.size(); ++i) //Container 7
	{
		if(Container7[i].getRender() == true)
		{
			//========MIDDLE ROW BACK=========//
			modelStack.PushMatrix();
			modelStack.LoadMatrix(Container7[i].getTRS());
			//modelStack.Rotate(270,0,1,0);
			RenderMesh(Container7[i].getMesh(),B_Light);
			modelStack.PopMatrix(); //pop back to origin
		}
	}

	for(int i = 0; i < Container8.size(); ++i) //Container 8
	{
		if(Container8[i].getRender() == true)
		{
			//========MIDDLE ROW BACK=========//
			modelStack.PushMatrix();
			modelStack.LoadMatrix(Container8[i].getTRS());
			modelStack.Rotate(180,0,1,0);
			RenderMesh(Container8[i].getMesh(),B_Light);
			modelStack.PopMatrix(); //pop back to origin
		}
	}
	for(int i = 0; i < Container9.size(); ++i) //Container 9
	{
		if(Container9[i].getRender() == true)
		{
			//========MIDDLE ROW BACK=========//
			modelStack.PushMatrix();
			modelStack.LoadMatrix(Container9[i].getTRS());
			modelStack.Rotate(180,0,1,0);
			RenderMesh(Container9[i].getMesh(),B_Light);
			modelStack.PopMatrix(); //pop back to origin
		}
	}
	for(int i = 0; i < Container10.size(); ++i) //Container 10
	{
		if(Container10[i].getRender() == true)
		{
			//========MIDDLE ROW BACK=========//
			modelStack.PushMatrix();
			modelStack.LoadMatrix(Container10[i].getTRS());
			modelStack.Rotate(180,0,1,0);
			RenderMesh(Container10[i].getMesh(),B_Light);
			modelStack.PopMatrix(); //pop back to origin
		}
	}
	for(int i = 0; i < Container11.size(); ++i) //Container 11
	{
		if(Container11[i].getRender() == true)
		{
			//========MIDDLE ROW BACK=========//
			modelStack.PushMatrix();
			modelStack.LoadMatrix(Container11[i].getTRS());
			modelStack.Rotate(180,0,1,0);
			RenderMesh(Container11[i].getMesh(),B_Light);
			modelStack.PopMatrix(); //pop back to origin
		}
	}
	for(int i = 0; i < Container12.size(); ++i) //Container 12
	{
		if(Container12[i].getRender() == true)
		{
			//========MIDDLE ROW BACK=========//
			modelStack.PushMatrix();
			modelStack.LoadMatrix(Container12[i].getTRS());
			//modelStack.Rotate(180,0,1,0);
			RenderMesh(Container12[i].getMesh(),B_Light);
			modelStack.PopMatrix(); //pop back to origin
		}
	}
	modelStack.PushMatrix();
	modelStack.Translate(camera.target.x,camera.target.y, camera.target.z);
	modelStack.Rotate(90,0,1,0);
	modelStack.Scale(0.5,0.5,0.5);
	RenderMesh(meshList[GEO_AXES],false);
	modelStack.PopMatrix();
	
	/*modelStack.PushMatrix();
	modelStack.Translate(4, 0, 0);
	RenderMesh(meshList[GEO_CANFOOD2],B_Light);
	modelStack.PopMatrix();*/

	/*modelStack.PushMatrix();
	modelStack.Translate(6, 0, 0);
	modelStack.Scale(0.5, 0.5, 0.5);
	RenderMesh(meshList[GEO_CANFOOD3],B_Light);
	modelStack.PopMatrix();*/

	//modelStack.PushMatrix();
	//modelStack.Translate(0, 0, 6);
	//modelStack.Scale(2, 2, 2);
	//RenderMesh(meshList[GEO_COKE_CAN],B_Light);// Coke
	//modelStack.PopMatrix();

	//modelStack.PushMatrix();
	//modelStack.Translate(0, 0, 5);
	//RenderMesh(meshList[GEO_DRINKCAN2],B_Light); 
	//modelStack.PopMatrix();

	//modelStack.PushMatrix();
	////modelStack.Translate(8, 0, 0);
	//modelStack.Translate(0, 0, 6);
	//modelStack.Scale(2, 2, 2);
	//RenderMesh(meshList[GEO_PEPSI_CAN],B_Light); // Pepsi
	//modelStack.PopMatrix();

	//modelStack.PushMatrix();
	//modelStack.Translate(0, 0, 4);
	//modelStack.Rotate(90,0,1,0);
	//modelStack.Scale(2, 2, 2);
	//RenderMesh(meshList[GEO_CEREALBOX1],B_Light);
	//modelStack.PopMatrix();

	//modelStack.PushMatrix();
	//modelStack.Translate(0, 0, 10);
	//modelStack.Rotate(-90,0,1,0);
	//modelStack.Scale(1.2, 1.2, 1.2);
	//RenderMesh(meshList[GEO_CEREALBOX2],B_Light);
	//modelStack.PopMatrix();

	//modelStack.PushMatrix();
	//modelStack.Translate(0, 0, -2);
	//modelStack.Rotate(-90,0,1,0);
	//RenderMesh(meshList[GEO_PIZZABOX],B_Light);
	//modelStack.PopMatrix();

	//modelStack.PushMatrix();
	//modelStack.Translate(0, 0, -4);
	//modelStack.Rotate(-90,0,1,0);
	//RenderMesh(meshList[GEO_POTATOCHIPS],B_Light);
	//modelStack.PopMatrix();

}

void StudioProject::RenderModel()
{
	modelStack.PushMatrix();
	modelStack.Translate(0.f,0.f,0.f);
	modelStack.Rotate(playerAngle, 0, 1, 0);

	modelStack.PushMatrix();
	modelStack.Translate(0, 3.6, 0);
	RenderMesh(player.getTorso(), B_Light);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 1.5, 0);
	RenderMesh(player.getTorso(), B_Light);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 3 + 0.2, 0);
	modelStack.Rotate(1+ rotateRightArms, 1+rotateRightArms, 0, 0);
	modelStack.Translate(-0.8, -1.5 + 0.2, 0);
	RenderMesh(player.getRHand(), B_Light);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 3 + 0.2, 0);
	modelStack.Rotate(1 + rotateLeftArms, 1 + rotateLeftArms, 0, 0);
	modelStack.Translate(0.8, -1.5 + 0.2, 0);
	RenderMesh(player.getLHand(), B_Light);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 0.4, 0);
	modelStack.PushMatrix();
	modelStack.Translate(0.3, 1, 0);
	modelStack.Rotate(1+ rotateLeftLeg, 1+ rotateLeftLeg, 0, 0);
	modelStack.Translate(0, -1.4, 0);
	RenderMesh(player.getLLeg(), B_Light);
	modelStack.PopMatrix();
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 0.4, 0);
	modelStack.PushMatrix();
	modelStack.Translate(-0.3, 1, 0);
	modelStack.Rotate(1+ rotateRightLeg, 1+rotateRightLeg, 0, 0);
	modelStack.Translate(0, -1.4, 0);
	RenderMesh(player.getRLeg(), B_Light);
	modelStack.PopMatrix();
	modelStack.PopMatrix();


	modelStack.PopMatrix();
	//modelStack.PushMatrix(); //Here lies hierachy modelling

	//modelStack.PushMatrix();
	////modelStack.Scale(0.05, 0.05, 0.05);
	//RenderMesh(meshList[modelButt], false);
	//modelStack.PopMatrix();

	//modelStack.PushMatrix();
	////modelStack.Scale(2, 2, 2);
	//modelStack.Translate(-0.3, 1, 0);
	//modelStack.Rotate(1+ rotateRightArms, 1+rotateRightArms, 0, 0);
	//modelStack.Translate(0, -1.2, 0);
	//RenderMesh(meshList[modelRightLeg], false);
	//modelStack.PopMatrix();

	//modelStack.PopMatrix();
}

void StudioProject::RenderCashier()
{
	modelStack.PushMatrix();
	modelStack.Translate(charPosition.x, 0, charPosition.z);
	modelStack.Rotate(angle, 0, angle, 1);

	modelStack.PushMatrix();
	modelStack.Translate(0, -2.285, 0);
	RenderMesh(meshList[cashierHead], B_Light);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 1.5, 0);
	RenderMesh(meshList[cashierTorso], B_Light);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 3 + 0.2, 0);
	modelStack.Rotate(1+ rotateRightArms, 1+rotateRightArms, 0, 0);
	modelStack.Translate(-0.8, -1.5 + 0.2, 0);
	RenderMesh(meshList[cashierRightHand], B_Light);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 3 + 0.2, 0);
	modelStack.Rotate(1 + rotateLeftArms, 1 + rotateLeftArms, 0, 0);
	modelStack.Translate(0.8, -1.5 + 0.2, 0);
	RenderMesh(meshList[cashierLeftHand], B_Light);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 0.4, 0);
	modelStack.PushMatrix();
	modelStack.Translate(0.3, 1, 0);
	modelStack.Rotate(1+ rotateLeftLeg, 1+ rotateLeftLeg, 0, 0);
	modelStack.Translate(0, -1.4, 0);
	RenderMesh(meshList[cashierLeftLeg], B_Light);
	modelStack.PopMatrix();
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 0.4, 0);
	modelStack.PushMatrix();
	modelStack.Translate(-0.3, 1, 0);
	modelStack.Rotate(1+ rotateRightLeg, 1+rotateRightLeg, 0, 0);
	modelStack.Translate(0, -1.4, 0);
	RenderMesh(meshList[cashierRightLeg], B_Light);
	modelStack.PopMatrix();
	modelStack.PopMatrix();

	modelStack.PushMatrix(); //Notation
	modelStack.Scale(0.5, 0.5, 0.5);
	modelStack.Rotate(180, 0, 180, 0);
	modelStack.Translate(-3, 10, 0);
	RenderText(meshList[GEO_TEXT], "Cashier", Color(0, 0, 1));
	modelStack.PopMatrix();

	modelStack.PopMatrix();
}

void StudioProject::RenderGuard()
{
	modelStack.PushMatrix();
	modelStack.Translate(charPosition.x, 0, charPosition.z);
	modelStack.Rotate(angle, 0, angle, 1);


	modelStack.PushMatrix();
	modelStack.Translate(0, -2.285, 0);
	RenderMesh(Guard1.getHead(), B_Light);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 1.5, 0);
	RenderMesh(Guard1.getTorso(), B_Light);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 3 + 0.2, 0);
	modelStack.Rotate(1+ rotateRightArms, 1+rotateRightArms, 0, 0);
	modelStack.Translate(-0.8, -1.5 + 0.2, 0);
	RenderMesh(Guard1.getRHand(), B_Light);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 3 + 0.2, 0);
	modelStack.Rotate(1 + rotateLeftArms, 1 + rotateLeftArms, 0, 0);
	modelStack.Translate(0.8, -1.5 + 0.2, 0);
	RenderMesh(Guard1.getLHand(), B_Light);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 0.4, 0);
	modelStack.PushMatrix();
	modelStack.Translate(0.3, 1, 0);
	modelStack.Rotate(1+ rotateLeftLeg, 1+ rotateLeftLeg, 0, 0);
	modelStack.Translate(0, -1.4, 0);
	RenderMesh(Guard1.getLLeg(), B_Light);
	modelStack.PopMatrix();
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 0.4, 0);
	modelStack.PushMatrix();
	modelStack.Translate(-0.3, 1, 0);
	modelStack.Rotate(1+ rotateRightLeg, 1+rotateRightLeg, 0, 0);
	modelStack.Translate(0, -1.4, 0);
	RenderMesh(Guard1.getRLeg(), B_Light);
	modelStack.PopMatrix();
	modelStack.PopMatrix();

	modelStack.PushMatrix(); //Notation
	modelStack.Scale(0.5, 0.5, 0.5);
	modelStack.Rotate(180, 0, 180, 0);
	modelStack.Translate(-2, 10, 0);
	RenderText(meshList[GEO_TEXT], "Guard", Color(0, 0, 1));
	modelStack.PopMatrix();

	modelStack.PopMatrix();
}

void StudioProject::RenderCustomer()
{
	modelStack.PushMatrix();
	modelStack.Translate(charPosition.x, 0, charPosition.z);
	modelStack.Rotate(angle, 0, angle, 1);

	modelStack.PushMatrix();
	modelStack.Translate(0, -2.285, 0);
	RenderMesh(meshList[customerHead], B_Light);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 1.5, 0);
	RenderMesh(meshList[customerTorso], B_Light);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 3 + 0.2, 0);
	modelStack.Rotate(1+ rotateRightArms, 1+rotateRightArms, 0, 0);
	modelStack.Translate(-0.8, -1.5 + 0.2, 0);
	RenderMesh(meshList[customerRightHand], B_Light);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 3 + 0.2, 0);
	modelStack.Rotate(1 + rotateLeftArms, 1 + rotateLeftArms, 0, 0);
	modelStack.Translate(0.8, -1.5 + 0.2, 0);
	RenderMesh(meshList[customerLeftHand], B_Light);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 0.4, 0);
	modelStack.PushMatrix();
	modelStack.Translate(0.3, 1, 0);
	modelStack.Rotate(1+ rotateLeftLeg, 1+ rotateLeftLeg, 0, 0);
	modelStack.Translate(0, -1.4, 0);
	RenderMesh(meshList[customerLeftLeg], B_Light);
	modelStack.PopMatrix();
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 0.4, 0);
	modelStack.PushMatrix();
	modelStack.Translate(-0.3, 1, 0);
	modelStack.Rotate(1+ rotateRightLeg, 1+rotateRightLeg, 0, 0);
	modelStack.Translate(0, -1.4, 0);
	RenderMesh(meshList[customerRightLeg], B_Light);
	modelStack.PopMatrix();
	modelStack.PopMatrix();

	modelStack.PushMatrix(); //Notation
	modelStack.Scale(0.5, 0.5, 0.5);
	modelStack.Rotate(180, 0, 180, 0);
	modelStack.Translate(-3, 10, 0);
	RenderText(meshList[GEO_TEXT], "Customer", Color(0, 0, 1));
	modelStack.PopMatrix();

	modelStack.PopMatrix();
}

void StudioProject::RenderPlayerInfo()
{
	RenderTextOnScreen(meshList[GEO_TEXT],"Money: " + Cash, Color(0, 0, 1), 3, 1, 18);
}

void StudioProject::RenderingSecurityCamera()
{
	//=========================Camera 1=======================//
	modelStack.PushMatrix(); //Rotating Camera;
	modelStack.Rotate(180, 0, 1, 0);
	modelStack.PushMatrix();//Moving Camera
	modelStack.Translate(CameraOBJ[0].getPosition().x, CameraOBJ[0].getPosition().y, CameraOBJ[0].getPosition().z);
	modelStack.Rotate(20, 1, 0, 0);
	modelStack.PushMatrix();//Fixing rotatin angle
	modelStack.Translate(0, 0, -0.2);
	modelStack.Rotate(CameraOBJ[0].getCameraRotation(), 0, 1, 0);
	modelStack.Translate(0, 0, +0.3);
	RenderMesh(CameraOBJ[0].getCamera(), B_Light);
	modelStack.PopMatrix();
	modelStack.PopMatrix(); //Moving camera
	modelStack.PopMatrix();//rotating Camera

	//=========================Camera 2=======================//
	modelStack.PushMatrix();//Moving Camera
	modelStack.Translate(0, 18, 0);
	modelStack.Rotate(20, 1, 0, 0);
	modelStack.PushMatrix();//Fixing rotatin angle
	modelStack.Translate(0, 0, -0.2);
	modelStack.Rotate(CameraOBJ[1].getCameraRotation(), 0, 1, 0);
	modelStack.Translate(0, 0, +0.3);
	RenderMesh(CameraOBJ[1].getCamera(), B_Light);
	modelStack.PopMatrix();
	modelStack.PopMatrix(); //Moving camera
}

void StudioProject::Render()
{
	//clear depth and color buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Temp variables
	Mtx44 MVP;

	viewStack.LoadIdentity();
	viewStack.LookAt(camera.position.x, camera.position.y, camera.position.z, camera.target.x, camera.target.y, camera.target.z, camera.up.x, camera.up.y, camera.up.z);
	modelStack.LoadIdentity();


	if(lights[0].type == Light::LIGHT_DIRECTIONAL)
	{
		Vector3 lightDir(lights[0].position.x, lights[0].position.y, lights[0].position.z);
		Vector3 lightDirection_cameraspace = viewStack.Top() * lightDir;
		glUniform3fv(m_parameters[U_LIGHT0_POSITION], 1, &lightDirection_cameraspace.x);
	}
	else if(lights[0].type == Light::LIGHT_SPOT)
	{
		Position lightPosition_cameraspace = viewStack.Top() * lights[0].position;
		glUniform3fv(m_parameters[U_LIGHT0_POSITION], 1, &lightPosition_cameraspace.x);
		Vector3 spotDirection_cameraspace = viewStack.Top() * lights[0].spotDirection;
		glUniform3fv(m_parameters[U_LIGHT0_SPOTDIRECTION], 1, &spotDirection_cameraspace.x);
	}
	else
	{
		Position lightPosition_cameraspace = viewStack.Top() * lights[0].position;
		glUniform3fv(m_parameters[U_LIGHT0_POSITION], 1, &lightPosition_cameraspace.x);
	}

	//Light2
	if(lights[1].type == Light::LIGHT_DIRECTIONAL)
	{
		Vector3 lightDir(lights[1].position.x, lights[1].position.y, lights[1].position.z);
		Vector3 lightDirection_cameraspace = viewStack.Top() * lightDir;
		glUniform3fv(m_parameters[U_LIGHT1_POSITION], 1, &lightDirection_cameraspace.x);
	}
	else if(lights[1].type == Light::LIGHT_SPOT)
	{
		Position lightPosition_cameraspace = viewStack.Top() * lights[1].position;
		glUniform3fv(m_parameters[U_LIGHT1_POSITION], 1, &lightPosition_cameraspace.x);
		Vector3 spotDirection_cameraspace = viewStack.Top() * lights[1].spotDirection;
		glUniform3fv(m_parameters[U_LIGHT1_SPOTDIRECTION], 1, &spotDirection_cameraspace.x);
	}
	else
	{
		Position lightPosition_cameraspace = viewStack.Top() * lights[1].position;
		glUniform3fv(m_parameters[U_LIGHT1_POSITION], 1, &lightPosition_cameraspace.x);
	}

	//Light 3
	if(lights[2].type == Light::LIGHT_DIRECTIONAL)
	{
		Vector3 lightDir(lights[2].position.x, lights[2].position.y, lights[2].position.z);
		Vector3 lightDirection_cameraspace = viewStack.Top() * lightDir;
		glUniform3fv(m_parameters[U_LIGHT2_POSITION], 1, &lightDirection_cameraspace.x);
	}
	else if(lights[2].type == Light::LIGHT_SPOT)
	{
		Position lightPosition_cameraspace = viewStack.Top() * lights[2].position;
		glUniform3fv(m_parameters[U_LIGHT2_POSITION], 1, &lightPosition_cameraspace.x);
		Vector3 spotDirection_cameraspace = viewStack.Top() * lights[2].spotDirection;
		glUniform3fv(m_parameters[U_LIGHT2_SPOTDIRECTION], 1, &spotDirection_cameraspace.x);
	}
	else
	{
		Position lightPosition_cameraspace = viewStack.Top() * lights[2].position;
		glUniform3fv(m_parameters[U_LIGHT2_POSITION], 1, &lightPosition_cameraspace.x);
	}

	//Light 4
	if(lights[3].type == Light::LIGHT_DIRECTIONAL)
	{
		Vector3 lightDir(lights[3].position.x, lights[3].position.y, lights[3].position.z);
		Vector3 lightDirection_cameraspace = viewStack.Top() * lightDir;
		glUniform3fv(m_parameters[U_LIGHT3_POSITION], 1, &lightDirection_cameraspace.x);
	}
	else if(lights[3].type == Light::LIGHT_SPOT)
	{
		Position lightPosition_cameraspace = viewStack.Top() * lights[3].position;
		glUniform3fv(m_parameters[U_LIGHT3_POSITION], 1, &lightPosition_cameraspace.x);
		Vector3 spotDirection_cameraspace = viewStack.Top() * lights[3].spotDirection;
		glUniform3fv(m_parameters[U_LIGHT3_SPOTDIRECTION], 1, &spotDirection_cameraspace.x);
	}
	else
	{
		Position lightPosition_cameraspace = viewStack.Top() * lights[3].position;
		glUniform3fv(m_parameters[U_LIGHT3_POSITION], 1, &lightPosition_cameraspace.x);
	}

	//Light 5
	if(lights[4].type == Light::LIGHT_DIRECTIONAL)
	{
		Vector3 lightDir(lights[4].position.x, lights[4].position.y, lights[4].position.z);
		Vector3 lightDirection_cameraspace = viewStack.Top() * lightDir;
		glUniform3fv(m_parameters[U_LIGHT4_POSITION], 1, &lightDirection_cameraspace.x);
	}
	else if(lights[4].type == Light::LIGHT_SPOT)
	{
		Position lightPosition_cameraspace = viewStack.Top() * lights[4].position;
		glUniform3fv(m_parameters[U_LIGHT4_POSITION], 1, &lightPosition_cameraspace.x);
		Vector3 spotDirection_cameraspace = viewStack.Top() * lights[4].spotDirection;
		glUniform3fv(m_parameters[U_LIGHT4_SPOTDIRECTION], 1, &spotDirection_cameraspace.x);
	}
	else
	{
		Position lightPosition_cameraspace = viewStack.Top() * lights[4].position;
		glUniform3fv(m_parameters[U_LIGHT4_POSITION], 1, &lightPosition_cameraspace.x);
	}

	//Light 6 (Middle front (Bottom))
	if(lights[5].type == Light::LIGHT_DIRECTIONAL)
	{
		Vector3 lightDir(lights[5].position.x, lights[5].position.y, lights[5].position.z);
		Vector3 lightDirection_cameraspace = viewStack.Top() * lightDir;
		glUniform3fv(m_parameters[U_LIGHT5_POSITION], 1, &lightDirection_cameraspace.x);
	}
	else if(lights[5].type == Light::LIGHT_SPOT)
	{
		Position lightPosition_cameraspace = viewStack.Top() * lights[5].position;
		glUniform3fv(m_parameters[U_LIGHT4_POSITION], 1, &lightPosition_cameraspace.x);
		Vector3 spotDirection_cameraspace = viewStack.Top() * lights[5].spotDirection;
		glUniform3fv(m_parameters[U_LIGHT5_SPOTDIRECTION], 1, &spotDirection_cameraspace.x);
	}
	else
	{
		Position lightPosition_cameraspace = viewStack.Top() * lights[5].position;
		glUniform3fv(m_parameters[U_LIGHT5_POSITION], 1, &lightPosition_cameraspace.x);
	}


	//====Rendering of light ball====//


	//=====Lights for first floor====//

	//Right back Lightball
	modelStack.PushMatrix();
	modelStack.Translate(lights[1].position.x, lights[1].position.y, lights[1].position.z);
	modelStack.Scale(3,0.5,8);
	RenderMesh(meshList[GEO_LIGHTBALL2], false);
	modelStack.PopMatrix();

	//Center back Lightball
	modelStack.PushMatrix();
	modelStack.Translate(lights[0].position.x, lights[0].position.y, lights[0].position.z);
	modelStack.Scale(3,0.5,8);
	RenderMesh(meshList[GEO_LIGHTBALL], false);
	modelStack.PopMatrix();

	//Left back Lightball
	modelStack.PushMatrix();
	modelStack.Translate(lights[2].position.x, lights[2].position.y, lights[2].position.z);
	modelStack.Scale(3,0.5,8);
	RenderMesh(meshList[GEO_LIGHTBALL3], false);
	modelStack.PopMatrix();

	//Left back Lightball
	modelStack.PushMatrix();
	modelStack.Translate(lights[3].position.x, lights[3].position.y, lights[3].position.z);
	modelStack.Scale(3,0.5,8);
	RenderMesh(meshList[GEO_LIGHTBALL4], false);
	modelStack.PopMatrix();

	//Left back Lightball
	modelStack.PushMatrix();
	modelStack.Translate(lights[4].position.x, lights[4].position.y, lights[4].position.z);
	modelStack.Scale(3,0.5,8);
	RenderMesh(meshList[GEO_LIGHTBALL5], false);
	modelStack.PopMatrix();

	//Left back Lightball
	modelStack.PushMatrix();
	modelStack.Translate(lights[5].position.x, lights[5].position.y, lights[5].position.z);
	modelStack.Scale(3,0.5,8);
	RenderMesh(meshList[GEO_LIGHTBALL6], false);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(-20.f, 0.f, -20.f);
	modelStack.Scale(10.f, 10.f, 10.f);
	modelStack.PopMatrix();

	MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top();
	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);
	RenderMesh(meshList[GEO_AXES], false);

	//Rendering skybox
	modelStack.PushMatrix();
	modelStack.Translate(camera.position.x, camera.position.y, camera.position.z);
	RenderSkybox();
	modelStack.PopMatrix();

	//Rendering of supermarket scene
	modelStack.PushMatrix();
	RenderSupermarket();
	RenderItems();
	modelStack.PopMatrix();


	//Rendering of CharacterModel
	modelStack.PushMatrix();
	//modelStack.Scale(1.2, 1.2, 1.2);
	//RenderModel();
	modelStack.PopMatrix();

	//Rendering of CashierModel
	modelStack.PushMatrix(); //Moving of cashier
	modelStack.Translate(-24, 0, 17);
	modelStack.Rotate(90,0,1,0);
	modelStack.PushMatrix();
	modelStack.Scale(1.2, 1.2, 1.2);
	modelStack.Rotate(90, 0, 90, 0);
	RenderCashier();
	modelStack.PopMatrix();
	modelStack.PopMatrix();

	//Rendering of CashierModel
	modelStack.PushMatrix(); //Moving of cashier
	modelStack.Translate(-24, 0, 0);
	modelStack.Rotate(90,0,1,0);
	modelStack.PushMatrix();
	modelStack.Scale(1.2, 1.2, 1.2);
	modelStack.Rotate(90, 0, 90, 0);
	RenderCashier();
	modelStack.PopMatrix();
	modelStack.PopMatrix();

	//Rendering of CashierModel
	modelStack.PushMatrix(); //Moving of cashier
	modelStack.Translate(-24, 0, -18);
	modelStack.Rotate(90,0,1,0);
	modelStack.PushMatrix();
	modelStack.Scale(1.2, 1.2, 1.2);
	modelStack.Rotate(90, 0, 90, 0);
	RenderCashier();
	modelStack.PopMatrix();
	modelStack.PopMatrix();

	//Rendering of GuardModel
	modelStack.PushMatrix(); //Moving of guard
	modelStack.Translate(0, 0, 5);

	modelStack.PushMatrix();
	modelStack.Scale(1.2, 1.2, 1.2);
	modelStack.Rotate(90, 0, 90, 0);
	RenderGuard();
	modelStack.PopMatrix();
	modelStack.PopMatrix();

	//Rendering of CustomerModel
	modelStack.PushMatrix(); //Moving of customer
	modelStack.Translate(0, 0, 10);

	modelStack.PushMatrix();
	modelStack.Scale(1.2, 1.2, 1.2);
	modelStack.Rotate(90, 0, 90, 0);
	RenderCustomer();
	modelStack.PopMatrix();
	modelStack.PopMatrix();

	//=======DOORS=====//
	//LEFTDOOR
	modelStack.PushMatrix();
	modelStack.Translate(-55.75,0.15,doorTranslate);
	modelStack.Scale(5,5,5);
	RenderMesh(meshList[GEO_DOORLEFT],B_Light);
	modelStack.PopMatrix();
	

	//RIGHTDOOR
	modelStack.PushMatrix();
	modelStack.Translate(-56,0,-doorTranslate);
	modelStack.Scale(5,5,5);
	RenderMesh(meshList[GEO_DOORRIGHT],B_Light);
	modelStack.PopMatrix();

	//Rendering of itempage
	if (showInventory == true)
	{
		RenderImageOnScreen(meshList[itemInventory], "Item Inventory", Color(1, 1, 1), 100, 1, 1);
	}

	RenderPlayerInfo();
	

	RenderingSecurityCamera();
	//============DEBUGGING PURPOSES====================//
	RenderTextOnScreen(meshList[GEO_TEXT], Framerate + result, Color(0, 1, 0), 3, 1, 2);
	RenderTextOnScreen(meshList[GEO_TEXT],"x: " + camerax, Color(0, 1, 0), 3, 1, 3);
	RenderTextOnScreen(meshList[GEO_TEXT],"y: " + cameray, Color(0, 1, 0), 3, 1, 4);
	RenderTextOnScreen(meshList[GEO_TEXT],"z: " + cameraz, Color(0, 1, 0), 3, 1, 5);

	RenderTextOnScreen(meshList[GEO_TEXT],"targetX: " + viewx, Color(0, 1, 0), 3, 10, 3);
	RenderTextOnScreen(meshList[GEO_TEXT],"targetY: " + viewy, Color(0, 1, 0), 3, 10, 4);
	RenderTextOnScreen(meshList[GEO_TEXT],"targetZ: " + viewz, Color(0, 1, 0), 3, 10, 5);

	RenderTextOnScreen(meshList[GEO_TEXT],"+", Color(1, 0, 0), 3, 13.55, 10);

	//==Controls==//
	if(isShown == true)
	{
		RenderTextOnScreen(meshList[GEO_TEXT], "WASD to Move", Color(0, 0 ,0), 2, 1, 29);
		RenderTextOnScreen(meshList[GEO_TEXT], "Arrow Keys to turn", Color(0, 0, 0), 2, 1, 28);
		RenderTextOnScreen(meshList[GEO_TEXT], "Press E to interact", Color(0,0,0), 2, 1, 27);
	}
	



}

void StudioProject::RenderMesh(Mesh *mesh, bool enableLight)
{
	Mtx44 MVP, modelView, modelView_inverse_transpose;

	MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top();
	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);

	if(mesh->textureID > 0)
	{
		glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 1);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, mesh->textureID);
		glUniform1i(m_parameters[U_COLOR_TEXTURE], 0);
	}
	else
	{
		glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 0);
	}
	if(enableLight)
	{
		glUniform1i(m_parameters[U_LIGHTENABLED], 1);
		modelView = viewStack.Top() * modelStack.Top();
		glUniformMatrix4fv(m_parameters[U_MODELVIEW], 1, GL_FALSE, &modelView.a[0]);
		modelView_inverse_transpose = modelView.GetInverse().GetTranspose();
		glUniformMatrix4fv(m_parameters[U_MODELVIEW_INVERSE_TRANSPOSE], 1, GL_FALSE, &modelView_inverse_transpose.a[0]);

		//load material
		glUniform3fv(m_parameters[U_MATERIAL_AMBIENT], 1, &mesh->material.kAmbient.r);
		glUniform3fv(m_parameters[U_MATERIAL_DIFFUSE], 1, &mesh->material.kDiffuse.r);
		glUniform3fv(m_parameters[U_MATERIAL_SPECULAR], 1, &mesh->material.kSpecular.r);
		glUniform1f(m_parameters[U_MATERIAL_SHININESS], mesh->material.kShininess);
	}
	else
	{	
		glUniform1i(m_parameters[U_LIGHTENABLED], 0);
	}

	mesh->Render(); //this line should only be called once 
	if(mesh->textureID > 0)
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}
}

void StudioProject::RenderText(Mesh* mesh, std::string text, Color color)
{
	if(!mesh || mesh->textureID <= 0) //Proper error check
		return;

	glDisable(GL_DEPTH_TEST);
	glUniform1i(m_parameters[U_TEXT_ENABLED], 1);
	glUniform3fv(m_parameters[U_TEXT_COLOR], 1, &color.r);
	glUniform1i(m_parameters[U_LIGHTENABLED], 0);
	glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 1);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, mesh->textureID);
	glUniform1i(m_parameters[U_COLOR_TEXTURE], 0);
	for(unsigned i = 0; i < text.length(); ++i)
	{
		Mtx44 characterSpacing;
		characterSpacing.SetToTranslation(i * 1.0f, 0, 0); //1.0f is the spacing of each character, you may change this value
		Mtx44 MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top() * characterSpacing;
		glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);

		mesh->Render((unsigned)text[i] * 6, 6);
	}
	glBindTexture(GL_TEXTURE_2D, 0);
	glUniform1i(m_parameters[U_TEXT_ENABLED], 0);
	glEnable(GL_DEPTH_TEST);
}

void StudioProject::RenderImageOnScreen(Mesh* mesh, std::string text, Color color, float size, float x, float y)
{
	if(!mesh || mesh->textureID <= 0) //Proper error check
		return;

	glDisable(GL_DEPTH_TEST);
	//Add these code just after glDisable(GL_DEPTH_TEST);
	Mtx44 ortho;
	ortho.SetToOrtho(0, 80, 0, 60, -10, 10); //size of screen UI
	projectionStack.PushMatrix();
	projectionStack.LoadMatrix(ortho);
	viewStack.PushMatrix();
	viewStack.LoadIdentity(); //No need camera for ortho mode
	modelStack.PushMatrix();
	modelStack.LoadIdentity(); //Reset modelStack
	modelStack.Scale(size, size, size);
	modelStack.Translate(x, y, 0);

	glUniform1i(m_parameters[U_TEXT_ENABLED], 1);
	glUniform3fv(m_parameters[U_TEXT_COLOR], 1, &color.r);
	glUniform1i(m_parameters[U_LIGHTENABLED], 0);
	glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 1);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, mesh->textureID);
	glUniform1i(m_parameters[U_COLOR_TEXTURE], 0);

	//for(unsigned i = 0; i < text.length(); ++i)
	//{
	//	Mtx44 characterSpacing;
	//	characterSpacing.SetToTranslation(i * 1.0f, 0, 0); //1.0f is the spacing of each character, you may change this value
	//	Mtx44 MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top();
	//	glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);

	//	mesh->Render((unsigned)text[i] * 6, 6);
	//}
	modelStack.PushMatrix();
	modelStack.Scale(0.5, 0.5, 0.5);
	modelStack.Translate(-1.43656 + -0.065, -1.43656 + 0.15, 0);
	RenderMesh(meshList[itemInventory], false);
	modelStack.PopMatrix();
	
	modelStack.PushMatrix();
	modelStack.Scale(0.1, 0.1, 0.1);
	modelStack.Translate(-7.5, -7.48149, 0);
	RenderMesh(meshList[UI_SARDINE_CAN], false);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Scale(0.1, 0.1, 0.1);
	modelStack.Translate(-6.5, -7.48149, 0);
	RenderMesh(meshList[UI_PEA_N_CARROTS], false);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Scale(0.1, 0.1, 0.1);
	modelStack.Translate(-5.5, -7.48149, 0);
	RenderMesh(meshList[UI_BAKED_BEANS_CAN], false);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Scale(0.1, 0.1, 0.1);
	modelStack.Translate(-8.5, -7.48149, 0);
	RenderMesh(meshList[UI_PIZZABOX], false);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Scale(0.1, 0.1, 0.1);
	modelStack.Translate(-9.5, -7.48149, 0);
	RenderMesh(meshList[UI_POTATOCHIPS], false);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Scale(0.1, 0.1, 0.1);
	modelStack.Translate(-9.5, -5.8, 0);
	RenderMesh(meshList[UI_COKE_CAN], false);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Scale(0.1, 0.1, 0.1);
	modelStack.Translate(-8.5, -5.8, 0);
	RenderMesh(meshList[UI_PEPSI_CAN], false);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Scale(0.1, 0.1, 0.1);
	modelStack.Translate(-7.5, -5.8, 0);
	RenderMesh(meshList[UI_CEREALBOX1], false);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Scale(0.1, 0.1, 0.1);
	modelStack.Translate(-6.5, -5.8, 0);
	RenderMesh(meshList[UI_CEREALBOX2], false);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Scale(0.1, 0.1, 0.1);
	modelStack.Translate(-5.5, -5.8, 0);
	RenderMesh(meshList[UI_MILOCAN], false);
	modelStack.PopMatrix();

	glBindTexture(GL_TEXTURE_2D, 0);
	glUniform1i(m_parameters[U_TEXT_ENABLED], 0);
	projectionStack.PopMatrix();
	viewStack.PopMatrix();
	modelStack.PopMatrix();
	glEnable(GL_DEPTH_TEST);
}

void StudioProject::RenderTextOnScreen(Mesh* mesh, std::string text, Color color, float size, float x, float y)
{
	if(!mesh || mesh->textureID <= 0) //Proper error check
		return;

	glDisable(GL_DEPTH_TEST);
	//Add these code just after glDisable(GL_DEPTH_TEST);
	Mtx44 ortho;
	ortho.SetToOrtho(0, 80, 0, 60, -10, 10); //size of screen UI
	projectionStack.PushMatrix();
	projectionStack.LoadMatrix(ortho);
	viewStack.PushMatrix();
	viewStack.LoadIdentity(); //No need camera for ortho mode
	modelStack.PushMatrix();
	modelStack.LoadIdentity(); //Reset modelStack
	modelStack.Scale(size, size, size);
	modelStack.Translate(x, y, 0);

	glUniform1i(m_parameters[U_TEXT_ENABLED], 1);
	glUniform3fv(m_parameters[U_TEXT_COLOR], 1, &color.r);
	glUniform1i(m_parameters[U_LIGHTENABLED], 0);
	glUniform1i(m_parameters[U_COLOR_TEXTURE_ENABLED], 1);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, mesh->textureID);
	glUniform1i(m_parameters[U_COLOR_TEXTURE], 0);

	for(unsigned i = 0; i < text.length(); ++i)
	{
		Mtx44 characterSpacing;
		characterSpacing.SetToTranslation(i * 1.0f, 0, 0); //1.0f is the spacing of each character, you may change this value
		Mtx44 MVP = projectionStack.Top() * viewStack.Top() * modelStack.Top() * characterSpacing;
		glUniformMatrix4fv(m_parameters[U_MVP], 1, GL_FALSE, &MVP.a[0]);

		mesh->Render((unsigned)text[i] * 6, 6);
	}
	glBindTexture(GL_TEXTURE_2D, 0);
	glUniform1i(m_parameters[U_TEXT_ENABLED], 0);
	projectionStack.PopMatrix();
	viewStack.PopMatrix();
	modelStack.PopMatrix();
	glEnable(GL_DEPTH_TEST);
}

void StudioProject::Exit()
{
	// Cleanup here
	for(int i = 0; i < NUM_GEOMETRY; ++i)
	{
		if(meshList[i] != NULL)
			delete meshList[i];
	}
	glDeleteVertexArrays(1, &m_vertexArrayID);
	glDeleteProgram(m_programID);
}

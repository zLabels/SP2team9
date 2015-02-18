#include "StudioProject.h"
#include "GL\glew.h"

#include "shader.hpp"
#include "Mtx44.h"

#include "Application.h"
#include "MeshBuilder.h"

#include "Vertex.h"
#include "LoadTGA.h"

#include "Item.h"
#include "Inventory.h"
#include "Character.h"

using std::cout;
using std::cin;
using std::endl;

StudioProject::StudioProject()
{
}

StudioProject::~StudioProject()
{
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

	//Load vertex and fragment shaders
	//m_programID = LoadShaders( "Shader//TransformVertexShader.vertexshader", "Shader//SimpleFragmentShader.fragmentshader" );
	//m_programID = LoadShaders( "Shader//Texture.vertexshader", "Shader//Texture.fragmentshader" );
	//m_programID = LoadShaders( "Shader//Texture.vertexshader", "Shader//Blending.fragmentshader" );
	// Use our shader

	//variable to rotate geometry
	rotateAngle = 0;
	worldsize = 1000.0f;
	roomsize = 250.0f;
	roomheight = 150.0f;
	fps = 0.0f;

	//variable to animate model
	rotateRightArms = rotateLeftArms = rotateRightLeg = rotateLeftLeg = 360;
	movingModel = false;
	movingCharacterX = movingCharacterZ = 0;
	

	//variable to animate metaknight
	rotateAngle = 0;

	Framerate = "FPS: ";
	//Initialize camera settings
	camera.Init(Vector3(0, 5, 60), Vector3(0, 0, 0), Vector3(0, 1, 0));

	//Initialize all meshes to NULL
	for(int i = 0; i < NUM_GEOMETRY; ++i)
	{
		meshList[i] = NULL;
	}
	meshList[GEO_AXES] = MeshBuilder::GenerateAxes("reference",Color(1,1,1),1000, 1000, 1000);

	Mtx44 projection;
	projection.SetToPerspective(45.f, 4.f / 3.f, 0.1f, 10000.f);
	projectionStack.LoadMatrix(projection);

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

	//Text Related
	// Get a handle for our "textColor" uniform
	m_parameters[U_TEXT_ENABLED] = glGetUniformLocation(m_programID, "textEnabled");
	m_parameters[U_TEXT_COLOR] = glGetUniformLocation(m_programID, "textColor");

	glUseProgram(m_programID);

	//Light 1
	lights[0].type = Light::LIGHT_POINT;
	lights[0].position.Set(0, 20, 0);
	lights[0].color.Set(1, 1, 1);
	lights[0].power = 2;
	lights[0].kC = 1.f;
	lights[0].kL = 0.01f;
	lights[0].kQ = 0.001f;
	lights[0].cosCutoff = cos(Math::DegreeToRadian(45));
	lights[0].cosInner = cos(Math::DegreeToRadian(30));
	lights[0].exponent = 3.f;
	lights[0].spotDirection.Set(0.f, 1.f, 0.f);

	//Light 2
	lights[1].type = Light::LIGHT_DIRECTIONAL;
	lights[1].position.Set(-450, 200, 120);
	lights[1].color.Set(1, 1, 1);
	lights[1].power = 0.5f;
	lights[1].kC = 1.f;
	lights[1].kL = 0.01f;
	lights[1].kQ = 0.001f;
	lights[1].cosCutoff = cos(Math::DegreeToRadian(45));
	lights[1].cosInner = cos(Math::DegreeToRadian(30));
	lights[1].exponent = 3.f;
	lights[1].spotDirection.Set(0.f, 1.f, 0.f);

	// Make sure you pass uniform parameters after glUseProgram()
	glUniform1i(m_parameters[U_NUMLIGHTS], 2);

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

	meshList[GEO_MARKET] = MeshBuilder::GenerateOBJ("Market" , "OBJ//Market.obj");
	meshList[GEO_MARKET]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_MARKET]->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	meshList[GEO_MARKET]->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_MARKET]->material.kShininess = 8.f;
	meshList[GEO_MARKET] ->textureID = LoadTGA("Image//WallTextures.tga");

	meshList[GEO_CASHIER] = MeshBuilder::GenerateOBJ("Market" , "OBJ//Cashier_Counter.obj");
	meshList[GEO_CASHIER]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_CASHIER]->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	meshList[GEO_CASHIER]->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_CASHIER]->material.kShininess = 8.f;
	meshList[GEO_CASHIER] ->textureID = LoadTGA("Image//cashier_counter.tga");

	meshList[GEO_CASHREG] = MeshBuilder::GenerateOBJ("Market" , "OBJ//cash-register.obj");
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

	meshList[GEO_CANFOOD1] = MeshBuilder::GenerateOBJ("Railing" , "OBJ//canned-food1.obj");
	meshList[GEO_CANFOOD1]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_CANFOOD1]->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	meshList[GEO_CANFOOD1]->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_CANFOOD1]->material.kShininess = 8.f;
	meshList[GEO_CANFOOD1] ->textureID = LoadTGA("Image//canned_food_1.tga");

	meshList[GEO_CANFOOD2] = MeshBuilder::GenerateOBJ("Railing" , "OBJ//canned-food2.obj");
	meshList[GEO_CANFOOD2]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_CANFOOD2]->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	meshList[GEO_CANFOOD2]->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_CANFOOD2]->material.kShininess = 8.f;
	meshList[GEO_CANFOOD2] ->textureID = LoadTGA("Image//canned_food_2.tga");

	meshList[GEO_CANFOOD3] = MeshBuilder::GenerateOBJ("Railing" , "OBJ//canned-food3.obj");
	meshList[GEO_CANFOOD3]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_CANFOOD3]->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	meshList[GEO_CANFOOD3]->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_CANFOOD3]->material.kShininess = 8.f;
	meshList[GEO_CANFOOD3] ->textureID = LoadTGA("Image//canned_food_3.tga");

	meshList[GEO_MILOCAN] = MeshBuilder::GenerateOBJ("Railing" , "OBJ//milocan.obj");
	meshList[GEO_MILOCAN]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_MILOCAN]->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	meshList[GEO_MILOCAN]->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_MILOCAN]->material.kShininess = 8.f;
	meshList[GEO_MILOCAN] ->textureID = LoadTGA("Image//milocan.tga");

	meshList[GEO_COKE_CAN] = MeshBuilder::GenerateOBJ("Railing" , "OBJ//drink-can1.obj");
	meshList[GEO_COKE_CAN]->material.kAmbient.Set(0.1f, 0.1f, 0.1f);
	meshList[GEO_COKE_CAN]->material.kDiffuse.Set(0.9f, 0.9f, 0.9f);
	meshList[GEO_COKE_CAN]->material.kSpecular.Set(0.5f, 0.5f, 0.5f);
	meshList[GEO_COKE_CAN]->material.kShininess = 8.f;
	meshList[GEO_COKE_CAN] ->textureID = LoadTGA("Image//drink_can1.tga");

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
	//meshList[GEO_TOP] = MeshBuilder::GenerateQuad("top", Color(1, 1, 1), 1.f, 1.f);
	//meshList[GEO_TOP]->textureID = LoadTGA("Image//hills_up.tga");

	//meshList[GEO_BOTTOM] = MeshBuilder::GenerateQuad("bottom", Color(1, 1, 1), 1.f, 1.f);
	//meshList[GEO_BOTTOM]->textureID = LoadTGA("Image//road-texture.tga");

	meshList[GEO_FLOOR] = MeshBuilder::GenerateQuad("bottom", Color(1, 1, 1), 1.f, 1.f);
	meshList[GEO_FLOOR]->textureID = LoadTGA("Image//road-texture.tga");


	//Light ball
	meshList[GEO_LIGHTBALL] = MeshBuilder::GenerateSphere("lightball", Color(1, 1, 1), 10, 10, 1);
	meshList[GEO_LIGHTBALL2] = MeshBuilder::GenerateSphere("lightball2", Color(1, 1, 1), 10, 10, 1);

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

//========Variables for use in update====//
bool B_Light = true;
static float ROT_LIMIT = 45.f;
static float SCALE_LIMIT = 5.f;
string result;

//Show Controls
bool isShown = true;

//=====variables to animate model arms===//
int rotatingRightArm = 1;
int rotatingLeftArm = 1;
int rotatingRightLeg = 1;
int rotatingLeftLeg = 1;

void StudioProject::Update(double dt)
{
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

	rotateAngle += (float)(10 * dt);

	//===Controls===//

	if(Application::IsKeyPressed('I'))
	{
		isShown = true;
	}

	if(Application::IsKeyPressed('O'))
	{
		isShown = false;
	}

	//===Character Contorl===//
	int ROTATE_SPEED = 50;
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

	if (Application::IsKeyPressed('8'))
		movingCharacterX += 10 * dt;
	if (Application::IsKeyPressed('9'))
		movingCharacterX -= 10 * dt;
	if (Application::IsKeyPressed('I'))
		movingCharacterZ += 10 * dt;
	if (Application::IsKeyPressed('O'))
		movingCharacterZ -= 10 * dt;
	
	//====Camera===//
	std::ostringstream ss;
	fps = 1/dt;
	ss << fps;
	result = ss.str();

	std::ostringstream ss2;
	ss2 <<camera.position.x;
	camerax = ss2.str();

	std::ostringstream ss3;
	ss3 << camera.position.y;
	cameray = ss3.str();

	std::ostringstream ss4;
	ss4 << camera.position.z;
	cameraz = ss4.str();
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
		modelStack.Translate(i*14,-1,-83.5);
		modelStack.Rotate(90,0,-1,0);
		RenderMesh(meshList[GEO_COLDFOODSHELF],B_Light);
		modelStack.PopMatrix();
	}
	//Back of market (Cold food shelf)
	for(int i = -5; i < 5; ++i)
	{
		modelStack.PushMatrix();
		modelStack.Translate(47,-1,i*14);
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
	modelStack.PushMatrix();
	modelStack.Translate(10, 4.3, 0);
	modelStack.Rotate(90,0,1,0);
	RenderMesh(meshList[GEO_CANFOOD1],B_Light);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(4, 0, 0);
	RenderMesh(meshList[GEO_CANFOOD2],B_Light);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(6, 0, 0);
	modelStack.Scale(0.5, 0.5, 0.5);
	RenderMesh(meshList[GEO_CANFOOD3],B_Light);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 0, 6);
	modelStack.Scale(2, 2, 2);
	RenderMesh(meshList[GEO_COKE_CAN],B_Light);// Coke
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 0, 5);
	RenderMesh(meshList[GEO_DRINKCAN2],B_Light); 
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	//modelStack.Translate(8, 0, 0);
	modelStack.Translate(0, 0, 6);
	modelStack.Scale(2, 2, 2);
	RenderMesh(meshList[GEO_PEPSI_CAN],B_Light); // Pepsi
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 0, 2);
	RenderMesh(meshList[GEO_MILOCAN],B_Light);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 0, 4);
	modelStack.Rotate(90,0,1,0);
	modelStack.Scale(2, 2, 2);
	RenderMesh(meshList[GEO_CEREALBOX1],B_Light);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 0, 10);
	modelStack.Rotate(-90,0,1,0);
	modelStack.Scale(1.2, 1.2, 1.2);
	RenderMesh(meshList[GEO_CEREALBOX2],B_Light);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 0, -2);
	modelStack.Rotate(-90,0,1,0);
	RenderMesh(meshList[GEO_PIZZABOX],B_Light);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 0, -4);
	modelStack.Rotate(-90,0,1,0);
	RenderMesh(meshList[GEO_POTATOCHIPS],B_Light);
	modelStack.PopMatrix();

}

void StudioProject::RenderModel()
{
	modelStack.PushMatrix();
	modelStack.Translate(0, 3.6, 0);
	RenderMesh(meshList[modelHead], B_Light);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 1.5, 0);
	RenderMesh(meshList[modelTorso], B_Light);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 3 + 0.2, 0);
	modelStack.Rotate(1+ rotateRightArms, 1+rotateRightArms, 0, 0);
	modelStack.Translate(-0.8, -1.5 + 0.2, 0);
	RenderMesh(meshList[modelRightHand], B_Light);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 3 + 0.2, 0);
	modelStack.Rotate(1 + rotateLeftArms, 1 + rotateLeftArms, 0, 0);
	modelStack.Translate(0.8, -1.5 + 0.2, 0);
	RenderMesh(meshList[modelLeftHand], B_Light);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 0.4, 0);
	modelStack.PushMatrix();
	modelStack.Translate(0.3, 1, 0);
	modelStack.Rotate(1+ rotateLeftLeg, 1+ rotateLeftLeg, 0, 0);
	modelStack.Translate(0, -1.4, 0);
	RenderMesh(meshList[modelLeftLeg], B_Light);
	modelStack.PopMatrix();
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(0, 0.4, 0);
	modelStack.PushMatrix();
	modelStack.Translate(-0.3, 1, 0);
	modelStack.Rotate(1+ rotateRightLeg, 1+rotateRightLeg, 0, 0);
	modelStack.Translate(0, -1.4, 0);
	RenderMesh(meshList[modelRightLeg], B_Light);
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
	//Texture

	modelStack.PushMatrix();
	modelStack.Translate(lights[1].position.x, lights[1].position.y, lights[1].position.z);
	RenderMesh(meshList[GEO_LIGHTBALL2], false);
	modelStack.PopMatrix();

	modelStack.PushMatrix();
	modelStack.Translate(lights[0].position.x, lights[0].position.y, lights[0].position.z);
	RenderMesh(meshList[GEO_LIGHTBALL], false);
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
	modelStack.PushMatrix(); //Moving of character
	modelStack.Translate(movingCharacterX, 0, movingCharacterZ);

	modelStack.PushMatrix();
	modelStack.Scale(1.2, 1.2, 1.2);
	modelStack.Rotate(90, 0, 90, 0);
	RenderModel();
	modelStack.PopMatrix();
	modelStack.PopMatrix();

	//Rendering of CashierModel
	modelStack.PushMatrix(); //Moving of cashier
	modelStack.Translate(movingCharacterX, 0, -5 + movingCharacterZ);

	modelStack.PushMatrix();
	modelStack.Scale(1.2, 1.2, 1.2);
	modelStack.Rotate(90, 0, 90, 0);
	RenderCashier();
	modelStack.PopMatrix();
	modelStack.PopMatrix();


	//============DEBUGGING PURPOSES====================//
	RenderTextOnScreen(meshList[GEO_TEXT], Framerate + result, Color(0, 1, 0), 3, 1, 2);
	RenderTextOnScreen(meshList[GEO_TEXT],"x: " + camerax, Color(0, 1, 0), 3, 1, 3);
	RenderTextOnScreen(meshList[GEO_TEXT],"y: " + cameray, Color(0, 1, 0), 3, 1, 4);
	RenderTextOnScreen(meshList[GEO_TEXT],"z: " + cameraz, Color(0, 1, 0), 3, 1, 5);

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

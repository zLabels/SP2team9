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

using std::string;

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
		GEO_COLDFOODSHELF,
		GEO_SHELF,
		GEO_SHELF2,

		modelHead,		//Model Head
		modelTorso,		//Model Torso
		modelRightHand,	//Model Right Hand
		modelLeftHand,	//Model Left Hand
		modelLeftLeg,	//Model Left Leg
		modelRightLeg,	//Model Right Leg
		modelButt,
		NUM_GEOMETRY,
	};

	void RenderSkybox();
	void RenderSupermarket();
	void RenderModel();

public:
	StudioProject();
	~StudioProject();

	virtual void Init();
	virtual void Update(double dt);
	virtual void Render();
	virtual void Exit();

private:
	unsigned m_vertexArrayID;
	Mesh* meshList[NUM_GEOMETRY];
	unsigned m_programID;
	unsigned m_parameters[U_TOTAL];

	float rotateAngle;
	double fps;
	string Framerate;
	string camerax;
	string cameray;
	string cameraz;
	float worldsize;
	float roomsize;
	float roomheight;
	bool movingModel;
	float rotateRightArms, rotateLeftArms, rotateLeftLeg, rotateRightLeg;

	Camera3 camera;

	MS modelStack, viewStack, projectionStack;

	Light lights[2];

	void RenderMesh(Mesh *mesh, bool enableLight);

	//Text
	void RenderText(Mesh* mesh, std::string text, Color color);
	void RenderTextOnScreen(Mesh* mesh, std::string text, Color color, float size, float x, float y);

};

#endif
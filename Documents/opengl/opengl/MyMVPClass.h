#pragma once
#include <glad/glad.h>
#include <glm/glm.hpp>

class MyMVP 
{
//create and store the three matrices

	//need to expose model movement,scale and rotation xyz,
	//need to expose the same for camera  

public:

	MyMVP():
		model(glm::mat4(1.0f)),
		modelScale(glm::mat4(1.0f)),
		modelRotX(glm::mat4(1.0f)),
		modelRotY(glm::mat4(1.0f)),
		modelRotZ(glm::mat4(1.0f)),
		modelTranslate(glm::mat4(1.0f)),
		view(glm::mat4(1.0f)),
		projection(glm::mat4(1.0f)),
		mvp(glm::mat4(1.0f))
	{}//construct initial 




	void setModel(glm::mat4 sc,glm::mat4 rx,glm::mat4 ry,glm::mat4 rz,glm::mat4 tr) 
	{
		modelScale = sc;
		modelRotX = rx;
		modelRotY = ry;
		modelRotZ = rz;
		modelTranslate = tr;
	
		model = modelTranslate * modelRotZ * modelRotY * modelRotX * modelScale;
	
	}

	glm::mat4 getModel() 
	{
		return model;
	}

private:

	glm::mat4 model;

	glm::mat4 modelScale;
	glm::mat4 modelRotX;
	glm::mat4 modelRotY;
	glm::mat4 modelRotZ;
	glm::mat4 modelTranslate;

	glm::mat4 view;
	glm::mat4 projection;
	glm::mat4 mvp;
	/*
	glm::mat4 lookAtFunc(glm::vec3 camPosition, glm::vec3 target,glm::vec3 wUp)
	{
		//get basis vectors for camera
		glm::vec3 camZ = glm::normalize(camPosition - target);
		glm::vec3 camX = glm::normalize(glm::cross(normalize(wUp), camZ));
		glm::vec3 camY = glm::normalize(glm::cross(camZ, camX));

		glm::mat4 translation =
		{
			1.0f,0.0f,0.0f,0.0f,
			0.0f,1.0f,0.0f,0.0f,
			0.0f,0.0f,1.0f,0.0f,
			camPosition.x,camPosition.y,camPosition.z,1.0f
		};

		glm::mat4 rotation =
		{
			camX.x,camX.y,camX.z,0.0f,
			camY.x,camY.y,camY.z,0.0f,
			camZ.x,camZ.y,camZ.z,0.0f,
			0.0f,0.0f,0.0f,1.0f
		};

		return glm::inverse(rotation) * glm::inverse(translation);

	}
	glm::mat4 projectionFunc(float fovAngle, float scrnW, float scrnH, float near, float far )
	{
		float f = 1.0f / (glm::tan(fovAngle / 2.0f));
		float a = scrnW / scrnH;
		float rangeInv = 1.0f/(near - far);


		glm::mat4 projection =
		{
			f/a,0.0f,0.0f,0.0f,
			0.0f,f,0.0f,0.0f,
			0.0f, 0.0f, far* rangeInv, -1.0f,
			0.0f, 0.0f, near* far* rangeInv, 0.0f
		};

		return projection;
	}

	*/
};
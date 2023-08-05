/*
 * gFireworksParticles.cpp
 *
 *  Created on: 26 Tem 2023
 *      Author: Batuhan Yigit
 */

#include "gFireworksParticles.h"

gFireworksParticles::gFireworksParticles() {
	// TODO Auto-generated constructor stub

}

gFireworksParticles::~gFireworksParticles() {
	// TODO Auto-generated destructor stub
}

void gFireworksParticles::init(int particleNum) {
	tex = gImage(507, 492, GL_RGBA);
	tex.setImageData((unsigned char*)gDecodeBase64(getFireworkImageData()).c_str());
	setTexture(&tex);
	int randomcolorno = (int)(gRandom(6.5f));
	setInitialColor(rainbowcolors[randomcolorno][0], rainbowcolors[randomcolorno][1], rainbowcolors[randomcolorno][2], 1.0f);
	burstsize = particleNum;
	gp.scale(0.04);
	gBaseParticles::init(particleNum);
}

void gFireworksParticles::resetParticle(int particleNo) {
	if(particleNo == 0) {
		resetedparticles.clear();
		int randomcolorno = (int)(gRandom(6.5f));
		setInitialColor(rainbowcolors[randomcolorno][0], rainbowcolors[randomcolorno][1], rainbowcolors[randomcolorno][2], 1.0f);
	}
	for(int i = 0; i < resetedparticles.size(); i++){
			if(particleNo == resetedparticles[i])
				return;
	}
	float fRand = (float)(gRandom(2.0)) / 10;
	resetedparticles.push_back(particleNo);
	setCurrentColor(particleNo, m_clrParticleColor.r - fRand, m_clrParticleColor.g - fRand, m_clrParticleColor.b - fRand, m_clrParticleColor.a);

	fRand = (float)(gRandom(2.0));
	float life = 1.5 + fRand;
	if(particleNo != 0){
		setLife(particleNo, (float)(gRandom(1.5)));
	}
	else{
		setLife(particleNo, life);
	}


	setFadeColor(particleNo, 0.0032f, 0.0032f,  0.0032f, -life / 150);
	setFadeLife(particleNo, -0.02f);

	float particleTheta = PI * (1.0 + sqrt(5.0)) * particleNo ;
	float particlePhi = acos(1.0 - (2.0 * particleNo) / (burstsize - 1));

	fRand = (float)(gRandom(5.0)) * 10.0;
	setDirection(particleNo, sin(particleTheta) * sin(particlePhi) / (80 + fRand), cos(particlePhi) /  (80 + fRand),
			cos(particleTheta) * sin(particlePhi) / (80 + fRand));


	fRand = (float)(gRandom(90) + 470);
	fRand = fRand / 200000;
	setGravity(particleNo, 0, -fRand, 0);

	fRand= (float)(gRandom(80));
	fRand = fRand / 1600;
	setLR(particleNo, fRand - 0.5f, -1, 0);
	setUL(particleNo, pos.x - 0.2f + fRand, pos.y, pos.z + (particleNo - particlenum) * 0.0001f);

	setAge(particleNo, 0);
	setFrame(particleNo, 0);
}

void gFireworksParticles::setPosition(float x, float y, float z) {
	pos.x = x;
	pos.y = y;
	pos.z = z;
}

std::string gFireworksParticles::getFireworkImageData() {
}
#pragma once
#include <vector>
#include "Particle.h"

class ParticleSystem
{
private:
	std::vector<Particle> particleContainer;
	sf::Shader shader;
	sf::RenderStates renderStates;
public:
	void update(float delta);
	void render(sf::RenderWindow &window);
	void spawnParticle(float positionX, float positionY,int mass, sf::Vector2f velocity);
	int particleCount();
	void reset();
	ParticleSystem();
	~ParticleSystem();
};


#include "Particle.h"



sf::Vector2f Particle::getPosition()
{
	return particleShape.getPosition();
}

void Particle::setPosition(sf::Vector2f &position)
{
	sphereOI.setPosition(position);
	particleShape.setPosition(position);
}

void Particle::changeMass(int mass)
{
	float radius = mass / 2;
	this->mass = mass;
	sphereOfInfluence = radius * radius * 2;
	particleShape.setRadius(radius);
	sphereOI.setRadius(sphereOfInfluence);
	sphereOI.setOrigin(sphereOfInfluence, sphereOfInfluence);
	particleShape.setOrigin(radius, radius);


}

void Particle::draw(sf::RenderWindow & window, sf::RenderStates &renderStates)
{
	window.draw(sphereOI);
	window.draw(particleShape,renderStates);
}

Particle::Particle(float positionX, float positionY, int mass,sf::Vector2f velocity)
{
	float radius = mass / 2;
	sphereOfInfluence = radius * radius;
	particleShape.setPosition(positionX, positionY);
	this->mass = mass;
	particleShape.setRadius(radius);
	particleShape.setOrigin(radius, radius);
	particleShape.setPointCount(200);
	sphereOI.setFillColor(sf::Color(0, 0, 150, 100));
	sphereOI.setRadius(sphereOfInfluence);
	sphereOI.setOrigin(sphereOfInfluence, sphereOfInfluence);
	destroyed = false;
	this->velocity = velocity;
}


Particle::~Particle()
{
}

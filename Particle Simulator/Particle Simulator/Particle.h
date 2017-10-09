#pragma once
#include "SFML\Graphics.hpp"

class Particle
{
public:
	sf::CircleShape sphereOI;
	sf::CircleShape particleShape;
	bool destroyed;
	float sphereOfInfluence;
	int mass;
	sf::Vector2f getPosition();
	void draw(sf::RenderWindow &window,sf::RenderStates &renderStates);
	sf::Vector2f velocity;
	void Particle::setPosition(sf::Vector2f &position);
	void changeMass(int mass);
	Particle(float positionX, float positionY, int mass, sf::Vector2f velocity);
	~Particle();
};


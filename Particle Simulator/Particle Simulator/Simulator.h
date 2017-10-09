#pragma once

#include "SFML\Window.hpp"
#include "SFML\Graphics.hpp"
#include "Particle.h"
#include "ParticleSystem.h"
#include "Console.h"

class Simulator
{
private:

	ParticleSystem particleSystem;
	sf::RenderWindow mainWindow;
	void handleEvents(sf::Event &event);
	Console console;

public:

	struct config {
		bool showConsole;
		int mass;
		sf::Vector2f velocity;
		std::string toString() {
			std::string returnString;
			returnString.append("MASS: ");
			returnString.append(std::to_string(mass));
			returnString.append("\n");
			returnString.append("VEL X ");
			returnString.append(std::to_string(velocity.x));
			returnString.append("\n");
			returnString.append("VEL Y ");
			returnString.append(std::to_string(velocity.y));
			return returnString;
		}
	};
	config conf;
	void run();
	Simulator();
	~Simulator();
};


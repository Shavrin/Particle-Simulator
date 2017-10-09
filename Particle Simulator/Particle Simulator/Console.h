#pragma once
#include "SFML\Graphics.hpp"

class Console
{
private:
	sf::Font consoleFont;
	sf::Text consoleText;
public:
	void render(sf::RenderWindow &window);
	void update(std::string &string);
	Console();
	~Console();
};


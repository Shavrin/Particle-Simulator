#include "Console.h"



void Console::render(sf::RenderWindow & window)
{
	window.draw(consoleText);
}

void Console::update(std::string &string)
{
	consoleText.setString(string);
}

Console::Console()
{
	if (!consoleFont.loadFromFile("consoleFont.ttf")) {
		exit(1);
	}
	consoleText.setFont(consoleFont);
	consoleText.setFillColor(sf::Color::White);
	consoleText.setPosition(0, 0);
	consoleText.setCharacterSize(25);
}


Console::~Console()
{
}

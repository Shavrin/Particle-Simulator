#include "Simulator.h"



void Simulator::handleEvents(sf::Event &event)
{
	while (mainWindow.pollEvent(event))
	{
		switch (event.type) {
		case sf::Event::Closed:
			mainWindow.close();
		case sf::Event::KeyPressed:

			switch (event.key.code) {
			case sf::Keyboard::S:
				particleSystem.spawnParticle((float)sf::Mouse::getPosition(mainWindow).x,
					(float)sf::Mouse::getPosition(mainWindow).y,conf.mass,conf.velocity);
				break;

			case sf::Keyboard::Comma:
				conf.mass--;
				break;
			case sf::Keyboard::Period:
				conf.mass++;
				break;
			case sf::Keyboard::O:
				conf.velocity.x -= 0.05;
				break;
			case sf::Keyboard::P:
				conf.velocity.x += 0.05;
				break;
			case sf::Keyboard::L:
				conf.velocity.y -= 1;
				break;
			case sf::Keyboard::SemiColon:
				conf.velocity.y += 1;
				break;
			case sf::Keyboard::R:
				particleSystem.reset();
				break;
			case sf::Keyboard::Tilde:
				conf.showConsole = !conf.showConsole;
				break;
			}
		}
	}
}

void Simulator::run()
{
	sf::Clock gameClock;
	sf::Time elapsed = gameClock.restart();

	const sf::Time physicsTick = sf::seconds(1.f / 30.f);

	while (mainWindow.isOpen())
	{
		sf::Event event;
		handleEvents(event);

		elapsed += gameClock.restart();

		while (elapsed >= physicsTick) {
			const auto delta = physicsTick.asSeconds();

			particleSystem.update(delta);

			std::string consoleText("Particle Count: ");
			consoleText.append(std::to_string(particleSystem.particleCount()));
			consoleText.append("\n");
			consoleText.append(conf.toString());
			console.update(consoleText);
			elapsed -= physicsTick;

		}


		mainWindow.clear(sf::Color::Black);
		particleSystem.render(mainWindow);
		if (conf.showConsole) console.render(mainWindow);
		mainWindow.display();

	}
}
Simulator::Simulator()
{
	mainWindow.create(sf::VideoMode(750, 750), "Particle Simulator", sf::Style::None);
	//mainWindow.setFramerateLimit(30);
	//mainWindow.setKeyRepeatEnabled(false);
	conf.mass = 10;
	conf.showConsole = true;
}


Simulator::~Simulator()
{
}

#include "ParticleSystem.h"
#include <iostream>
void ParticleSystem::update(float delta)
{
	if(!particleContainer.empty()){

		for (Particle &particle : particleContainer) {
			if(!particle.destroyed){
				for (Particle &otherParticle : particleContainer) {
					bool collision = false;
					bool moved = false;
					
					float distanceX = particle.getPosition().x - otherParticle.getPosition().x;
					float distanceY = particle.getPosition().y - otherParticle.getPosition().y;
					float distance = sqrt((distanceX*distanceX) + (distanceY*distanceY));

					if (distance < particle.mass / 2 && particle.getPosition() != otherParticle.getPosition()) {
						if (particle.mass >= otherParticle.mass) {
							otherParticle.destroyed = true;
							particle.changeMass(particle.mass + otherParticle.mass);
							collision = true;
						}
						else {
							particle.destroyed = true;
							otherParticle.changeMass(particle.mass + otherParticle.mass);
							collision = true;
						}
					}

					if (!collision) {

						if (distance < particle.sphereOfInfluence && distance != 0) {
							float gravity = 0.0667 * otherParticle.mass * particle.mass / distance*distance;
							float gravityX = gravity*distanceX / distance;
							float gravityY = gravity*distanceY / distance;

							otherParticle.velocity.x += gravityX / otherParticle.mass;
							otherParticle.velocity.y += gravityY / otherParticle.mass;

							otherParticle.setPosition(sf::Vector2f(otherParticle.getPosition().x + otherParticle.velocity.x * delta,
								otherParticle.getPosition().y + otherParticle.velocity.y * delta));
							moved = true;
						}
					}
					if (!moved) {
							particle.setPosition(sf::Vector2f(particle.getPosition().x + particle.velocity.x * delta,
														particle.getPosition().y + particle.velocity.y * delta));
					}
				}
			}
		}
		
			auto i = particleContainer.begin();
			while (i != particleContainer.end()) {
				if (i->destroyed) {
					i = particleContainer.erase(i);
				}
				else {
					++i;
				}
		}
	}

}

void ParticleSystem::render(sf::RenderWindow &window)
{
	for (Particle &particle : particleContainer) {
		particle.draw(window,renderStates);
	}
}

void ParticleSystem::spawnParticle(float positionX, float positionY,int mass, sf::Vector2f velocity)
{
	particleContainer.push_back(Particle(positionX,positionY,mass,velocity));
}

int ParticleSystem::particleCount()
{
	return particleContainer.size();
}

void ParticleSystem::reset()
{
	particleContainer.clear();
}

ParticleSystem::ParticleSystem()
{
	shader.loadFromFile("shader.vert","shader.frag");
	renderStates.shader = &shader;
}


ParticleSystem::~ParticleSystem()
{
}

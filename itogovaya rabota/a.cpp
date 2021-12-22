#include "a.h"

using namespace a;

Amain::Amain(RenderWindow* window)
{
	circle.setRadius(20.f);
	circle.setPosition(window->getSize().x / 2, window->getSize().y / 2);
}

void a::Amain::draw(RenderWindow* window)
{
	window->draw(circle);
}

void a::Amain::move(RenderWindow* window, Bmain* rect)
{
	if (!gameIsOver) {
		circle.move(speed * dx, speed * dy);
		if (circle.getPosition().x <= 0) {
			dx *= -1;
			circle.setPosition(0, circle.getPosition().y);
		}
		if (circle.getPosition().x + circle.getRadius() * 2 >= window->getSize().x) {
			dx *= -1;
			circle.setPosition(window->getSize().x - circle.getRadius() * 2, circle.getPosition().y);
		}

		if (circle.getPosition().y <= 0) {
			dy *= -1;
			circle.setPosition(circle.getPosition().x, 0);
		}
		if (circle.getPosition().y + circle.getRadius() * 2 >= rect->getPosition().y) {
			if (circle.getPosition().x >= rect->getPosition().x - circle.getRadius() * 1.5 &&
				circle.getPosition().x <= rect->getPosition().x + rect->getSize().x + circle.getRadius() * 1.5) {
				dy *= -1;
				circle.setPosition(circle.getPosition().x, rect->getPosition().y - circle.getRadius() * 2);
			}
			else
				if (circle.getPosition().y + circle.getRadius() * 2 >= window->getSize().y)gameIsOver = true;
		}
	}
}

void a::Amain::reset(RenderWindow* window)
{
	circle.setPosition(window->getSize().x / 2, window->getSize().y / 2);
	gameIsOver = false;
}

a::Bmain::Bmain(RenderWindow* window)
{
	rect.setSize(Vector2f(120, 20));
	rect.setPosition(window->getSize().x / 2 - rect.getSize().x / 2, window->getSize().y - rect.getSize().y);
}

void a::Bmain::draw(RenderWindow* window)
{
	window->draw(rect);
}

void a::Bmain::move(int dx)
{
	rect.move(speed*dx,0);
}

#include"a.h"
#include <cstdlib>

using namespace a;

int main()
{
	RenderWindow window(VideoMode(720, 960), "AAA!");
	Amain circle(&window);
	Bmain rect(&window);
	Clock clock;
	float timer = 0, delay = 0.01, time;

	Font font;
	font.loadFromFile("font.ttf");

	Text text;
	text.setFont(font);
	text.setCharacterSize(70);
	text.setString("Game Over");
	text.setPosition(window.getSize().x / 2 - text.getCharacterSize()*2, window.getSize().y / 2);
	text.setScale(0, 0);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();

			if(event.type == Event::KeyReleased){ 
				if (event.key.code == Keyboard::R)
					circle.reset(&window);
			}

			if (event.type == Event::KeyPressed)
				if (event.key.code == Keyboard::Left)
					rect.move(-1);
				else
					if (event.key.code == Keyboard::Right)
					rect.move(1);
		}

		time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;

		if (timer > delay)
		{
			circle.move(&window,&rect);
			timer = 0;
		}

		if (circle.gameIsOver) text.setScale(1, 1);
		else
			text.setScale(0, 0);

		window.clear();
		circle.draw(&window);
		rect.draw(&window);
		window.draw(text);
		window.display();
	}

	return 0;
}
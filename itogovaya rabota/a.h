#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

namespace a {

	class Bmain {
	public:
		Bmain(RenderWindow* window);
		void draw(RenderWindow* window);
		void move(int dx);
		Vector2f getPosition() { return rect.getPosition(); }
		Vector2f getSize() { return rect.getSize(); }
		float speed = 30;
	private:
		RectangleShape rect;
	};
	
	class Amain {
	public:
		Amain(RenderWindow* window);
		void draw(RenderWindow* window);
		void move(RenderWindow* window, Bmain* rect);
		void reset(RenderWindow* window);
		bool gameIsOver = false;
		float speed = 5;
		int dx = 1, dy = 1;
		Vector2f getPosition() { return circle.getPosition();};
		

	private:
		CircleShape circle;
	};
}
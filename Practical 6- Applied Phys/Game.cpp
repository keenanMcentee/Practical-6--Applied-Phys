#include "Game.h"



Game::Game() : m_window(VideoMode(800,600), "Practical 6")
{

}
void Game::initialise()
{
	initialPosX = 60;
	initialPosY = 490;
	xPlane.setFillColor(Color::Red);
	xPlane.setPosition(Vector2f(50, 500));
	xPlane.setSize(Vector2f(650, 10));

	yPlane.setFillColor(Color::Red);
	yPlane.setPosition(Vector2f(50, 50));
	yPlane.setSize(Vector2f(10, 450));

	gravity = Vector2f(0, 9.81f);
	initialForce = Vector2f(30, -50);
	position = Vector2f(initialPosX, initialPosY);
	jumped = false;
	
	ball.setFillColor(Color::Color(180, 180, 180, 255));
	ball.setRadius(5);
	ball.setPosition(position);
	force = 0;
	angle = 0;
	font.loadFromFile("arial.ttf");
	angleText.setFont(font);
	initialSpeed.setFont(font);
	initialSpeed.setPosition(0, 50);
	distanceText.setFont(font);
	distanceText.setPosition(300, 0);
	maxHeight = 0;
}
void Game::run()
{
	Clock clock;
	float timer = 0;
	float timeSinceLastFrame = 0;
	initialise();
	while (true)
	{
		timer += clock.getElapsedTime().asSeconds();
		clock.restart();
		timer -= timeSinceLastFrame;
		timeSinceLastFrame = timer;

		update(timeSinceLastFrame);
		
		draw();
		
		timeSinceLastFrame = 0;
	}

}

void Game::update(double dt)
{
	float angleInRads = angle * 3.14 / 180;
	if (Keyboard::isKeyPressed(Keyboard::Space) && !jumped)
	{
		velocity = Vector2f(cosf(angleInRads)* force,sinf(angleInRads)* force);
		jumped = true;
	}
	if (Keyboard::isKeyPressed(Keyboard::Y))
	{
		if (angle < 90)
		{
			angle += 0.5f;
		}
		else if (angle > 90)
		{
			angle = 90;
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::U))
	{
		if (angle > 0)
		{
			angle -= 0.5f;
		}
		else if (angle < 0)
		{
			angle = 0;
		}
	}
	if (Keyboard::isKeyPressed(Keyboard::B))
	{
		if (force < 50)
		{
			force += 0.5f;
		}
		else if (force > 50)
		{
			force = 50;
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::V))
	{
		if (force > 0)
		{
			force -= 0.5f;
		}
		else if (force < 0)
		{
			force = 0;
		}
	}
	
	if (Keyboard::isKeyPressed(Keyboard::R))
	{
		initialise();
	}
    position += (Vector2f(velocity.x * dt, velocity.y * dt) + Vector2f(0.5*gravity.x * (dt * dt), 0.5*gravity.y * (dt * dt)));

	if (position.y < 490)
	{
		velocity += Vector2f(gravity.x * dt, gravity.y * dt);
	}
	else
	{
		//velocity = Vector2f(0, 0);
		position.y = 490;
		velocity.y = (E * velocity.y * -1);
	}
	distanceX = (position.x - initialPosX) * CONVERT_TO_METERS;
	if (initialPosY - position.y > maxHeight)
	{
		maxHeight = initialPosY - position.y;
	}
	ball.setPosition(position);
	distanceText.setString("X travelled: " + std::to_string(distanceX) + "\n" + "Max Height: " + std::to_string(maxHeight * -1 * CONVERT_TO_METERS));
	angleText.setString("angle: " + std::to_string(angle));
	initialSpeed.setString("Force :" + std::to_string(force * 10) + "N");
}
void Game::draw()
{
	m_window.clear(Color::Black);
	m_window.draw(xPlane);
	m_window.draw(yPlane);
	m_window.draw(ball);
	m_window.draw(angleText);
	m_window.draw(initialSpeed);
	m_window.draw(distanceText);
	m_window.display();
}
Game::~Game()
{
}

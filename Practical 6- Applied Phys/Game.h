#pragma once
//////////////////////////////////////////////////////////// 
// Headers for SFML projects
// include correct library file for release and debug versions
// include opengl library files
// include iostream for console window output
////////////////////////////////////////////////////////////
#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib") 
#include "SFML/Graphics.hpp" 
#include "SFML/OpenGL.hpp" 
#include <iostream>
using namespace sf;
class Game
{
public:
	Game();
	~Game();
	void run();
private:
	RenderWindow m_window;
	void update(double dt);
	void draw();
	void initialise();
	bool jumped;
	double timeSinceLastFrame;
	RectangleShape xPlane, yPlane;
	CircleShape ball;
	Vector2f position;
	Vector2f velocity;
	Vector2f gravity;
	Vector2f initialForce;
	float initialPosX;
	float initialPosY;
	float angle;
	float force;
	const int CONVERT_TO_METERS = 20;
	const float E = 1;
	Font font;
	Text angleText;
	Text initialSpeed;
	Text distanceText;
	float distanceX;
	float maxHeight;
};


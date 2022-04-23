#pragma once
// Including all necessary libraries
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <random>
#include <windows.h>

class game
{

private:
	// Set width and height of window
	const int window_w = 1545;
	const int window_h = 810;
	sf::RenderWindow* window; // window object
	sf::Cursor cursor; // cursor object
	sf::Image icon; // icon


	sf::Event sfmlEvent;

	// Initial backgrounds sprite and texture
	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;

	// Initial games clock
	sf::Clock clock;
	sf::Time elapsed;
	int timeCount = 1;

	//Initial buttons for the game menu
	sf::RectangleShape button1;
	sf::RectangleShape button2;
	sf::RectangleShape button3;
	sf::RectangleShape button4;

	void init_window();
	void initPLayer();

	bool ready = 0;

public:

	game(); // Constructor for initializing different values
	~game(); // Deconstructor for deleting values

	void pollEvents(); // Function for getting events
	bool running(); // Function to check whether game is running
	void start(); // Function to start game
	void menu(); // Setting the game menu
	void customCursor(); // Setting the custom cursor
	void setTheIcon(); // Icon for the window
	void setReady(); // Config everything before the start of the game
	void posWindow(); // Window for getting the mouse pos
	bool getMousePos(float x, float y, int a); // Getting the mouse position
	void update(); // Main function to change values every iteration
	void render(); // Main function to render objects every iteration
	void setBackground(); // Function to display background
	int randomNum(int n); // Function for returning random value
};

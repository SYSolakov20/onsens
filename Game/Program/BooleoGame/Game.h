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
	const int window_w = 1030;
	const int window_h = 540;
	sf::RenderWindow* window; // window object

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

	void init_window();
	void initPLayer();

	bool ready = 0;

public:

	game(); // Constructor for initializing different values
	~game(); // Deconstructor for deleting values

	void pollEvents(); // Function to close window
	bool running(); // Function to check whether game is running
	void Start(); // Function to start game
	void menu(); // Setting the game menu
	bool getMousePos(float x, float y, int a); // Getting the mouse position
	void update(); // Main function to change values every iteration
	void render(); // Main function to render objects every iteration
	void setBackground(); // Function to display background
	int randomNum(int n); // Function for returning random value
};

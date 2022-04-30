#pragma once
// Including all necessary libraries
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <random>
#include <windows.h>

class Game
{

private:
	// Set width and height of window
	const int window_w = 1545;
	const int window_h = 810;
	sf::RenderWindow* window; // window object
	sf::Cursor cursor; // cursor object
	sf::Image icon; // image for custom icon


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


	// Some more game realeted stuff :P
	bool ready = 0;
	bool gameMode = 0;
	int gamemodeNum = 0;
	int counter = 0;
	int tableNum = 0;
	bool pressed = false;
	sf::Texture player1TextTexture;
	sf::Sprite player1Text;
	sf::Texture player2TextTexture;
	sf::Sprite player2Text;
	sf::RectangleShape buttonTable;
	sf::Texture TruthTableTexture;
	sf::Sprite TruthTable;
	sf::Texture TableHeaderTexture;
	sf::Sprite TableHeader;
	sf::Texture TableHoverTexture;
	sf::Sprite TableHover;


public:

	Game(); // Constructor for initializing different values
	~Game(); // Deconstructor for deleting values

	void pollEvents(); // Function for getting events
	bool running(); // Function to check whether game is running
	void start(); // Function to start game
	void menu(sf::Window& newWindow); // Setting the game menu
	void modes(sf::Window& newWindow); // Modes menu function
	void menuButtons(); // Setting the buttons
	void modesButtons(); // Setting the buttons
	void customCursor(); // Setting the custom cursor
	void setTheIcon(); // Icon for the window
	void setReady(); // Config everything before the start of the game
	void setPlay(); // Config the game before playing
	bool getMousePos(float x, float y, int a, sf::Window& newWindow); // Getting the mouse position
	void update(sf::Window& newWindow); // Main function to change values every iteration
	void render(); // Main function to render objects every iteration
	void setBackground(); // Function to display background
};

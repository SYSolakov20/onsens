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
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <string>
#include <iomanip>


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
	sf::Font font;
	sf::Text timer;
	int sec;
	int min;
	int hour;
	int timeCount = 1;
	int intSecondsCounted;

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
	bool pressed0 = false;
	bool pressed1 = false;
	bool pressed2 = false;
	bool pressed3 = false;
	bool pressed4 = false;
	bool pressed20 = false;
	bool pressed21 = false;
	bool pressed22 = false;
	bool pressed23 = false;
	bool pressed24 = false;
	std::stringstream ss;
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
	sf::Texture transitionTexture;
	sf::Sprite transitionImg;

	// Base Cards
	struct baseCard
	{
		bool value = 0;

		// image of the base card
		sf::Texture BaseCardImgTexture;
		sf::Sprite BaseCardImg;
	};
	
	baseCard baseCards[6];  // Base cards for player 1
	baseCard baseCards2[6]; // Base cards for player 2

	// Cards struct
	struct card
	{
		int num = 0; // Pos
		int value = 0; // 0 or 1
		char type = 0; // and / or / xor

		// some properties
		bool display1 = 0;
		bool display2 = 0;
		int player = 0; // 1 or 2
		int secondNum = 0;;
		bool player1pos = 0;
		bool player2pos = 0;
		bool x = 0;
		bool y = 0;
		bool drag = 0;
		bool placed = 0;

		// image of the card
		sf::Texture imgTexture; 
		sf::Sprite img; 
	};

	// Field Positions struct
	struct fieldPos
	{
		int cardNum = 0; // The number of the card that's on this pos
		int cardValue = 0; // The value of the card that's on this pos


		// some properties
		bool showPos = 0;
		bool cardOnIt = 0;
		int pos = 0; // 1 to 15
		int x = 0;
		int y = 0;


		// image
		sf::Texture imgTexture;
		sf::Sprite img;
	};


	fieldPos fPositions[40];
	fieldPos fPositions2[40];

	card startDeck[100];
	int temp;
	int randNum;
	int deckI = 1;
	card deck[150];
	bool canPlace1 = 0;
	int cardGet = 1;
	int counterCards = 1;
	int counterCards2 = 49;
	int counterCards3 = 48;
	int player1Cards = 0;
	int player2Cards = 0;
	int win = 0;
	bool showA = 0;
	bool showA2 = 0;
	bool cardAgain = 0;
	bool roundPlayed = 0;
	bool card1Dragging = 0;
	bool card2Dragging = 0;
	bool card3Dragging = 0;
	bool card4Dragging = 0;
	bool card5Dragging = 0;

	int player1Pos1 = 0;
	int player1Pos2 = 0;
	int player1Pos3 = 0;
	int player1Pos4 = 0;
	int player1Pos5 = 0;

	int player2Pos1 = 0;
	int player2Pos2 = 0;
	int player2Pos3 = 0;
	int player2Pos4 = 0;
	int player2Pos5 = 0;


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
	void setTimer(); // Setting a timer in game
	void setBaseCards(); // Setting the positions and the type of the base cards
	void transition(); // animations / transition for the game
	void setDeck(); // Setting a deck and cards
	void sortDeck(); // Radomising the Deck cards
	void cardsInHand(); // Sets the cards that the player has
	void tableOfTruth(); // Helps table display
	void placingCardsPos(); // Sets the possible positions
	void setCardImages(sf::Vector2i cursorpos); // Loads cards images
	bool checkPlacedCards(int jj); // Checks if the operation is possible
	bool getMousePos(float x, float y, int a, sf::Window& newWindow); // Getting the mouse position
	void update(sf::Window& newWindow); // Main function to change values every iteration
	void render(); // Main function to render objects every iteration
	void setBackground(); // Function to display background
};

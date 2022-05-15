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


	// Some more game realeted stuff 
	bool ready = 0;
	bool gameMode = 0;
	bool firstGamemode1 = 1;
	bool firstGamemode2 = 1;
	bool firstGamemode3 = 1;
	bool firstGamemode4 = 1;
	bool rules = 0;
	bool options = 0;
	bool pause = 0;
	bool resume = 0;
	bool breakResume = 0;
	bool breakPause = 0;
	int gamemodeNum = 0;
	int counter = 0;
	int tableNum = 0;
	int specialButtonC = 0;
	bool pressed = false;
	bool pressed0 = false;
	bool pressed1 = false;
	bool pressed2 = false;
	bool pressed3 = false;
	bool pressed4 = false;
	bool pressed5 = false;
	bool pressed6 = false;
	bool pressed7 = false;
	bool pressed8 = false;
	bool pressed9 = false;
	bool pressed10 = false;
	bool pressed11 = false;
	bool pressed12 = false;
	bool pressed20 = false;
	bool pressed21 = false;
	bool pressed22 = false;
	bool pressed23 = false;
	bool pressed24 = false;
	bool pressed25 = false;
	std::stringstream ss;

	// in-game images
	sf::Texture player1TextTexture;
	sf::Sprite player1Text;
	sf::Texture player2TextTexture;
	sf::Sprite player2Text;
	sf::RectangleShape buttonTable;
	sf::Texture truthTableTexture;
	sf::Sprite truthTable;
	sf::Texture tableHeaderTexture;
	sf::Sprite tableHeader;
	sf::Texture tableHoverTexture;
	sf::Sprite tableHover;
	sf::Texture transitionTexture;
	sf::Sprite transitionImg;
	sf::Texture pyramid1Texture;
	sf::Sprite pyramid1Img;
	sf::Texture pyramid2Texture;
	sf::Sprite pyramid2Img;
	sf::Texture resumeTexture;
	sf::Sprite resumeImg;
	sf::Texture pauseTexture;
	sf::Sprite pauseImg;
	sf::Texture specialButtonTexture;
	sf::Sprite specialButtonImg;
	sf::Texture changeTexture;
	sf::Texture notCardPopTexture;
	sf::Sprite notCardPop;

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
		int secondNum = 0;
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


	fieldPos fPositions[40]; // Positions for Player 1
	fieldPos fPositions2[40]; // Positions for Player 2
	fieldPos notCardPos[6]; // Positions for the not-card 
	card startDeck[100]; // The starting deck
	card deck[150]; // The ready deck
	int temp;
	int randNum;
	int deckI = 1;
	int nextPage = -1;
	int cardGet = 1;
	int counterCards = 1;
	int counterCards2 = 49;
	int counterCards3 = 48;
	int counterNotCards3 = 56;
	int player1Cards = 0;
	int player2Cards = 0;
	int win = 0;
	bool showA = 0;
	bool showA2 = 0;
	bool showNotA = 0;
	bool otherNot = 0;
	bool roundPlayed = 0;
	bool card1Dragging = 0;
	bool card2Dragging = 0;
	bool card3Dragging = 0;
	bool card4Dragging = 0;
	bool card5Dragging = 0;
	bool card1Dragging2 = 0;
	bool card2Dragging2 = 0;
	bool card3Dragging2 = 0;
	bool card4Dragging2 = 0;
	bool card5Dragging2 = 0;

	// Cards in hand pos
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
	void rulestab(sf::Window& newWindow); // Rules
	void optionsMenu(sf::Window& newWindow); // Options
	void firstGamemode(sf::Window& newWindow); // Contains the first mode
	void secondGamemode(sf::Window& newWindow); // Contains the second mode
	void thirdGamemode(sf::Window& newWindow); // Contains the third mode
	void fourthGamemode(sf::Window& newWindow); // Contains the fourth mode
	void menuButtons(); // Setting the buttons
	void modesButtons(); // Setting the buttons
	void winScreen(sf::Window& newWindow); // Displays the victory window
	void customCursor(); // Setting the custom cursor
	void setTheIcon(); // Icon for the window
	void setReady(); // Config everything before the start of the game
	void setPlay(); // Config the game before playing
	void setTimer(); // Setting a timer in game
	void setBaseCards(); // Setting the positions and the type of the base cards
	void setDeck(); // Setting a deck and cards
	void sortDeck(); // Radomising the Deck cards
	void setNotDeck(); // Setting a deck and cards for not-gamemode
	void sortNotDeck(); // Radomising the Deck cards for not-gamemode
	void cardsInHand(); // Sets the cards that the player has
	void tableOfTruth(); // Helps table display
	void setPlacingCards(); // Sets the default positions of the cards
	void placingCardsPos(); // Sets the possible positions
	void placingNotCardsPos(); // Sets the possible positions for the not-card
	void notCardLogic(int j); // Checks if not-cards were placed and can handle them
	void setCardImages(sf::Vector2i cursorpos); // Loads cards images
	void setCardImages2(sf::Vector2i cursorpos); // The same function but modified for the second gamemode
	void setNotCardImages(sf::Vector2i cursorpos); // Loads cards images for the not gamemode
	void setNotCardImages2(sf::Vector2i cursorpos); // The same function but modified for the fourth gamemode
	bool checkPlacedCards(int jj); // Checks if the operation is possible
	bool getMousePos(float x, float y, int a, sf::Window& newWindow); // Getting the mouse position
	void update(sf::Window& newWindow); // Main function to change values every iteration
	void render(); // Main function to render objects every iteration
	void setBackground(); // Function to display background
};

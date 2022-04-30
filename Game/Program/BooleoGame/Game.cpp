#include "game.h"


void Game::init_window()
{
	this->window = new sf::RenderWindow(sf::VideoMode(window_w, window_h), "Booleo", sf::Style::Close);
	this->window->setFramerateLimit(80);
}

bool Game::running()
{
	return this->window->isOpen();
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->sfmlEvent))
	{
		switch (this->sfmlEvent.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;

		case sf::Event::KeyPressed:
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				if (ready)
				{
					ready = 0;
				}
				else if (gameMode)
				{
					gameMode = 0;
				}
				else
				{
					this->window->close();
				}
			}
			break;
		}
	}
}

void Game::setBackground()
{
	this->backgroundTexture.loadFromFile("assets/menu.png");
	backgroundTexture.setSmooth(true);
	this->backgroundSprite.setTexture(backgroundTexture);
}


void Game::render()
{
	this->window->clear();
	this->window->draw(this->backgroundSprite);
	this->window->display();
}

void Game::update(sf::Window& newWindow)
{
	if (getMousePos(1394, 191, 3, newWindow)) // Table Button:
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (!pressed) 
			{
				tableNum++;
				if (tableNum == 3)
				{
						tableNum = 0;
				}
				pressed = true;
			}
		}
		else 
		{
				pressed = false;
		}
	}
	pollEvents();
}


bool Game::getMousePos(float x, float y, int a, sf::Window &newWindow)
{
	sf::Vector2i mousepos = sf::Mouse::getPosition(newWindow);
	switch (a)
	{
	case 1: // checking for hovering buttons
		if ((mousepos.x + 8 >= x && mousepos.x + 8 <= x + 295) && (mousepos.y + 8 >= y && mousepos.y + 8 <= y + 75))
		{
			return 1;
		}
		break;
	case 2:
		if ((mousepos.x + 8 >= x && mousepos.x + 8 <= x + 310) && (mousepos.y + 8 >= y && mousepos.y + 8 <= y + 470))
		{
			return 1;
		}
		break;
	case 3:
		if ((mousepos.x + 8 >= x && mousepos.x + 8 <= x + 114) && (mousepos.y + 8 >= y && mousepos.y + 8 <= y + 37))
		{
			return 1;
		}
		break;
	case 4:
		if ((mousepos.x + 8 >= x && mousepos.x + 8 <= x + 172) && (mousepos.y + 8 >= y && mousepos.y + 8 <= y + 120))
		{
			return 1;
		}
		break;
	}
	return 0;
}

void Game::menuButtons()
{
	this->button1.setSize(sf::Vector2f(295, 75));
	this->button1.setPosition(625, 307);
	this->button1.setFillColor(sf::Color(0, 255, 0));
	this->button2.setSize(sf::Vector2f(295, 75));
	this->button2.setPosition(625, 412);
	this->button2.setFillColor(sf::Color(30, 255, 0));
	this->button3.setSize(sf::Vector2f(295, 75));
	this->button3.setPosition(625, 516);
	this->button3.setFillColor(sf::Color(80, 255, 0));
	this->button4.setSize(sf::Vector2f(295, 75));
	this->button4.setPosition(625, 620);
	this->button4.setFillColor(sf::Color(80, 255, 0));
}

void Game::menu(sf::Window &newWindow)
{
	if (getMousePos(625, 307, 1, newWindow)) // Button Play:
	{
		this->backgroundTexture.loadFromFile("assets/HoverPlay.png");
		this->backgroundSprite.setTexture(backgroundTexture);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (!pressed)
			{
				gameMode = 1;
				modesButtons();
				pressed = true;
			}
		}
		else
		{
			pressed = false;
		}
	}
	else if (getMousePos(625, 412, 1, newWindow)) // Button Options
	{
		this->backgroundTexture.loadFromFile("assets/HoverOptions.png");
		this->backgroundSprite.setTexture(backgroundTexture);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->backgroundTexture.loadFromFile("assets/Options.png");
			this->backgroundSprite.setTexture(backgroundTexture);
		}
	}
	else if (getMousePos(625, 516, 1, newWindow)) // Button Rules
	{
		this->backgroundTexture.loadFromFile("assets/HoverRules.png");
		this->backgroundSprite.setTexture(backgroundTexture);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->backgroundTexture.loadFromFile("assets/Rules.png");
			this->backgroundSprite.setTexture(backgroundTexture);
		}
	}
	else if (getMousePos(625, 620, 1, newWindow)) // Button Quit
	{
		this->backgroundTexture.loadFromFile("assets/HoverQuit.png");
		this->backgroundSprite.setTexture(backgroundTexture);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			window->close();
		}
	}
	else
	{
		setBackground();
	}
	this->window->draw(this->backgroundSprite);
	this->window->display();
}


void Game::modesButtons()
{
	this->button1.setSize(sf::Vector2f(310, 470));
	this->button1.setPosition(95, 170);
	this->button1.setFillColor(sf::Color(0, 255, 0));
	this->button2.setSize(sf::Vector2f(310, 470));
	this->button2.setPosition(445, 170);
	this->button2.setFillColor(sf::Color(30, 255, 0));
	this->button3.setSize(sf::Vector2f(310, 470));
	this->button3.setPosition(795, 170);
	this->button3.setFillColor(sf::Color(80, 255, 0));
	this->button4.setSize(sf::Vector2f(310, 470));
	this->button4.setPosition(1145, 170);
	this->button4.setFillColor(sf::Color(80, 255, 0));
}

void Game::modes(sf::Window& newWindow)
{
	if (getMousePos(95, 170, 2, newWindow)) // First mode:
	{
		this->backgroundTexture.loadFromFile("assets/HoverMode1.png");
		this->backgroundSprite.setTexture(backgroundTexture);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (!pressed)
			{
				ready = 1;
				gamemodeNum = 1;
				setPlay();
				pressed = true;
			}
		}
		else
		{
			pressed = false;
		}
	}
	else if (getMousePos(445, 170, 2, newWindow)) // Second mode:
	{
		this->backgroundTexture.loadFromFile("assets/HoverMode2.png");
		this->backgroundSprite.setTexture(backgroundTexture);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (!pressed)
			{
				ready = 1;
				gamemodeNum = 2;
				pressed = true;
			}
		}
		else
		{
			pressed = false;
		}
	}
	else if (getMousePos(795, 170, 2, newWindow)) // Third mode:
	{
		this->backgroundTexture.loadFromFile("assets/HoverMode3.png");
		this->backgroundSprite.setTexture(backgroundTexture);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (!pressed)
			{
				ready = 1;
				gamemodeNum = 3;
				pressed = true;
			}
		}
		else
		{
			pressed = false;
		}
	}
	else if (getMousePos(1145, 170, 2, newWindow)) // Fourth mode:
	{
		this->backgroundTexture.loadFromFile("assets/HoverMode4.png");
		this->backgroundSprite.setTexture(backgroundTexture);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (!pressed)
			{
				ready = 1;
				gamemodeNum = 4;
				pressed = true;
			}
		}
		else
		{
			pressed = false;
		}
	}
	else
	{
		this->backgroundTexture.loadFromFile("assets/GameMode.png");
		this->backgroundSprite.setTexture(backgroundTexture);
	}


	this->window->draw(this->backgroundSprite);
	this->window->display();
}

void Game::setDeck()
{
	int numCounter = 1;

	startDeck[0].num = 0;
	for (int i = 1; i < 49; i++)
	{
		if (i <= 16)
		{
			startDeck[i].type = 'a';
			startDeck[i].num = numCounter;
			if (i <= 8)
			{
				startDeck[i].value = 0;
				startDeck->imgTexture.loadFromFile("assets/AndCard0.png");
				this->startDeck[i].imgTexture.setSmooth(true);
				startDeck[i].img.setTexture(startDeck[i].imgTexture);
			}
			else
			{
				startDeck[i].value = 1;
			}
		}
		else if (i <= 32)
		{
			startDeck[i].type = 'o';
			startDeck[i].num = numCounter;
			if (i <= 24)
			{
				startDeck[i].value = 1;
			}
			else
			{
				startDeck[i].value = 0;
			}
		}
		else if (i <= 48)
		{
			startDeck[i].type = 'x';
			startDeck[i].num = numCounter;
			if (i <= 40)
			{
				startDeck[i].value = 0;
			}
			else
			{
				startDeck[i].value = 1;
			}
		}
		numCounter++;
	}
}

void Game::sortDeck()
{
	srand((unsigned)time(0));

	while (deckI < 49)
	{
		temp = rand() % 48 + 1;
		if (startDeck[temp].num != 0)
		{
			deck[deckI].type = startDeck[temp].type;
			deck[deckI].num = deckI;
			deck[deckI].value = startDeck[temp].value;
			startDeck[temp].num = 0;
			deckI++;
		}
	}
}
void Game::setCardImages()
{
	int numCounter = 1;

	for (int i = 1; i < 49; i++)
	{
		if (deck[i].display1 == 1 && counter == 1)
		{
			if (deck[i].player1pos == 1)
			{
				if (player1Pos1 == i)
				{
					if (getMousePos(0, 110, 4, *this->window))
					{
						deck[player1Pos1].img.setPosition(183, 110);
					}
					else
					{
						deck[player1Pos1].img.setPosition(170, 110);
					}	
				}
				else if (player1Pos2 == i)
				{
					if (getMousePos(0, 245, 4, *this->window))
					{
						deck[player1Pos2].img.setPosition(183, 245);
					}
					else
					{
						deck[player1Pos2].img.setPosition(170, 245);
					}
				}
				else if (player1Pos3 == i)
				{
					if (getMousePos(0, 380, 4, *this->window))
					{
						deck[player1Pos3].img.setPosition(183, 380);
					}
					else
					{
						deck[player1Pos3].img.setPosition(170, 380);
					}
				}
				else if (player1Pos4 == i)
				{
					if (getMousePos(0, 515, 4, *this->window))
					{
						deck[player1Pos4].img.setPosition(183, 515);
					}
					else
					{
						deck[player1Pos4].img.setPosition(170, 515);
					}
				}
				else if (player1Pos5 == i)
				{
					if (getMousePos(0, 650, 4, *this->window))
					{
						deck[player1Pos5].img.setPosition(183, 650);
					}
					else
					{
						deck[player1Pos5].img.setPosition(170, 650);
					}
				}
			}
			if (deck[i].value == 0)
			{
				if (deck[i].type == 'a')
				{
					deck[i].imgTexture.loadFromFile("assets/AndCard0.png");
					this->deck[i].imgTexture.setSmooth(true);
					deck[i].img.setTexture(deck[i].imgTexture);
					this->window->draw(deck[i].img);
				}
				else if (deck[i].type == 'o')
				{
					deck[i].imgTexture.loadFromFile("assets/OrCard0.png");
					this->deck[i].imgTexture.setSmooth(true);
					deck[i].img.setTexture(deck[i].imgTexture);
					this->window->draw(deck[i].img);
				}
				else if (deck[i].type == 'x')
				{
					deck[i].imgTexture.loadFromFile("assets/XorCard0.png");
					this->deck[i].imgTexture.setSmooth(true);
					deck[i].img.setTexture(deck[i].imgTexture);
					this->window->draw(deck[i].img);
				}
			}
			else if (deck[i].value == 1)
			{

				if (deck[i].type == 'a')
				{
					deck[i].imgTexture.loadFromFile("assets/AndCard1.png");
					this->deck[i].imgTexture.setSmooth(true);
					deck[i].img.setTexture(deck[i].imgTexture);
					this->window->draw(deck[i].img);
				}
				else if (deck[i].type == 'o')
				{
					deck[i].imgTexture.loadFromFile("assets/OrCard1.png");
					this->deck[i].imgTexture.setSmooth(true);
					deck[i].img.setTexture(deck[i].imgTexture);
					this->window->draw(deck[i].img);
				}
				else if (deck[i].type == 'x')
				{
					deck[i].imgTexture.loadFromFile("assets/XorCard1.png");
					this->deck[i].imgTexture.setSmooth(true);
					deck[i].img.setTexture(deck[i].imgTexture);
					this->window->draw(deck[i].img);
				}
			}
			this->window->draw(baseCards[0].BaseCardImg);
			this->window->draw(baseCards[1].BaseCardImg);
			this->window->draw(baseCards[2].BaseCardImg);
			this->window->draw(baseCards[3].BaseCardImg);
			this->window->draw(baseCards[4].BaseCardImg);
			this->window->draw(baseCards[5].BaseCardImg);
		}
	}
}

void Game::setTheIcon()
{
	this->icon.loadFromFile("assets/Icon.png");
	this->window->setIcon(69, 69, icon.getPixelsPtr());
}

void Game::customCursor()
{
	sf::Image cursorImg;
	cursorImg.loadFromFile("assets/Cursor.png");
	this->cursor.loadFromPixels(cursorImg.getPixelsPtr(), cursorImg.getSize(), sf::Vector2u(0, 0));
	this->window->setMouseCursor(cursor);
}

void Game::setBaseCards()
{
	srand((unsigned)time(0));
	for (int i = 0; i < 6; i++)
	{
		randNum = rand() % 2 + 1;
		if (randNum == 1)
		{
			baseCards[i].value = 0;
			baseCards[i].BaseCardImgTexture.loadFromFile("assets/BaseCard0.png");
			baseCards[i].BaseCardImgTexture.setSmooth(true);
			baseCards[i].BaseCardImg.setTexture(baseCards[i].BaseCardImgTexture);
		}
		else
		{
			baseCards[i].value = 1;
			baseCards[i].BaseCardImgTexture.loadFromFile("assets/BaseCard1.png");
			baseCards[i].BaseCardImgTexture.setSmooth(true);
			baseCards[i].BaseCardImg.setTexture(baseCards[i].BaseCardImgTexture);
		}
	}
	baseCards[0].BaseCardImg.setPosition(334, -98);
	baseCards[1].BaseCardImg.setPosition(497, -98);
	baseCards[2].BaseCardImg.setPosition(660, -98);
	baseCards[3].BaseCardImg.setPosition(823, -98);
	baseCards[4].BaseCardImg.setPosition(986, -98);
	baseCards[5].BaseCardImg.setPosition(1149, -98);
}

void Game::cardsInHand()
{
	for (int i = 0; i < 49; i++)
	{
		if (deck[i].player == 1 && deck[i].player1pos == 0)
		{
			if (player1Pos1 == 0)
			{
				player1Pos1 = deck[i].num;
				deck[i].player1pos = 1;
				deck[i].img.setRotation(90.f);
				deck[i].display1 = true;
			}
			else if (player1Pos2 == 0)
			{
				player1Pos2 = deck[i].num;
				deck[i].player1pos = 1;
				deck[i].img.setRotation(90.f);
				deck[i].display1 = true;
			}
			else if (player1Pos3 == 0)
			{
				player1Pos3 = deck[i].num;
				deck[i].player1pos = 1;
				deck[i].img.setRotation(90.f);
				deck[i].display1 = true;
			}
			else if (player1Pos4 == 0)
			{
				player1Pos4 = deck[i].num;
				deck[i].player1pos = 1;
				deck[i].img.setRotation(90.f);
				deck[i].display1 = true;
			}
			else if (player1Pos5 == 0)
			{
				player1Pos5 = deck[i].num;
				deck[i].player1pos = 1;
				deck[i].img.setRotation(90.f);
				deck[i].display1 = true;
			}
		}
	}
}

void Game::setPlay()
{
	this->backgroundTexture.loadFromFile("assets/GameField.png");
	this->backgroundSprite.setTexture(backgroundTexture);
	player1TextTexture.loadFromFile("assets/Player1Text.png");
	this->player1TextTexture.setSmooth(true);
	player1Text.setTexture(player1TextTexture);
	player1Text.setPosition(15, 12);
	player2TextTexture.loadFromFile("assets/Player2Text.png");
	this->player2TextTexture.setSmooth(true);
	player2Text.setTexture(player2TextTexture);
	player2Text.setPosition(15, 12);
	this->buttonTable.setSize(sf::Vector2f(114, 37));
	this->buttonTable.setPosition(1394, 191);
	this->buttonTable.setFillColor(sf::Color(80, 255, 0));
	TableHeaderTexture.loadFromFile("assets/AndTableHover.png");
	this->TableHeaderTexture.setSmooth(true);
	TableHeader.setTexture(TableHeaderTexture);
	TableHeader.setPosition(1394, 188);
	TableHoverTexture.loadFromFile("assets/AndTableHeader.png");
	this->TableHoverTexture.setSmooth(true);
	TableHover.setTexture(TableHoverTexture);
	TableHover.setPosition(1394, 190);

	if (gamemodeNum == 1)
	{
		setBaseCards();
	}

	setDeck();
	sortDeck();
	setCardImages();
	clock.restart();
}

void Game::setReady()
{
	this->window->setPosition(sf::Vector2i(190, 80));
	setTheIcon();
	customCursor();
}

Game::Game()
{
	init_window();
	setBackground();
	setReady();
	this->backgroundSprite.setScale(window_w / backgroundSprite.getGlobalBounds().width, window_h / backgroundSprite.getGlobalBounds().height);

}

Game::~Game()
{
	delete this->window;
}
	
void Game::start()
{
	while (running())
	{
		sf::Vector2i cursorpos = sf::Mouse::getPosition(*this->window);

		if (ready) // Play
		{
			if (gamemodeNum == 1)
			{
				sf::Time elapsed1 = clock.getElapsedTime();
				if (counter == 0)
				{
					counter++;
				}
				else if (counter == 1) // Player1 round
				{
					//std::cout << elapsed1.asSeconds() << std::endl;
					for (cardGet; player1Cards <= 5; player1Cards++, cardGet++)
					{
						deck[cardGet].player = 1;
					}
					cardsInHand();




					this->window->clear();
					this->window->draw(this->backgroundSprite);
					this->window->draw(this->player1Text);
					setCardImages();
					if (tableNum == 0)
					{
						if (!(getMousePos(1394, 188, 3, *this->window)))
						{
							TableHeaderTexture.loadFromFile("assets/AndTableHover.png");
							this->window->draw(this->TableHeader);
						}
						else
						{
							TableHoverTexture.loadFromFile("assets/AndTableHeader.png");
							this->window->draw(this->TableHover);
						}
						TruthTableTexture.loadFromFile("assets/AndTable.png");
						this->TruthTableTexture.setSmooth(true);
						TruthTable.setTexture(TruthTableTexture);
						TruthTable.setPosition(1390, 240);
						this->window->draw(this->TruthTable);
						//counter++;
					}
					else if (tableNum == 1)
					{
						if (!(getMousePos(1394, 188, 3, *this->window)))
						{
							TableHeaderTexture.loadFromFile("assets/OrTableHover.png");
							this->window->draw(this->TableHeader);
						}
						else
						{
							TableHoverTexture.loadFromFile("assets/OrTableHeader.png");
							this->window->draw(this->TableHover);
						}
						TruthTableTexture.loadFromFile("assets/OrTable.png");
						this->TruthTableTexture.setSmooth(true);
						TruthTable.setTexture(TruthTableTexture);
						TruthTable.setPosition(1390, 240);
						this->window->draw(this->TruthTable);
					}
					else if (tableNum == 2)
					{
						if (!(getMousePos(1394, 188, 3, *this->window)))
						{
							TableHeaderTexture.loadFromFile("assets/XorTableHover.png");
							this->window->draw(this->TableHeader);
						}
						else
						{
							TableHoverTexture.loadFromFile("assets/XorTableHeader.png");
							this->window->draw(this->TableHover);
						}
						TruthTableTexture.loadFromFile("assets/XorTable.png");
						this->TruthTableTexture.setSmooth(true);
						TruthTable.setTexture(TruthTableTexture);
						TruthTable.setPosition(1390, 240);
						this->window->draw(this->TruthTable);
					}
					this->window->display();
					update(*this->window);
				}
				else if (counter == 2) // Player 2 round
				{




					counter++;
					update(*this->window);
					render();
				}
				else
				{
					counter = 1;
				}
			}
			else if (gamemodeNum == 2)
			{
				this->backgroundTexture.loadFromFile("assets/Play.png");
				this->backgroundSprite.setTexture(backgroundTexture);
				update(*this->window);
				render();
			}
			else if (gamemodeNum == 3)
			{
				this->backgroundTexture.loadFromFile("assets/Play.png");
				this->backgroundSprite.setTexture(backgroundTexture);
				update(*this->window);
				render();
			}
			else if (gamemodeNum == 4)
			{
				this->backgroundTexture.loadFromFile("assets/Play.png");
				this->backgroundSprite.setTexture(backgroundTexture);
				update(*this->window);
				render();
			}
			
		}
		else if (gameMode) // Modes menu
		{
			pollEvents();
			modes(*this->window);
			clock.restart();
		}
		else // Game Menu
		{ 
			pollEvents();
			menuButtons();
			menu(*this->window);
			clock.restart();
		}
	}
};
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
				else if (rules)
				{
					rules = 0;
					nextPage = 0;
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
			if (!pressed0)
			{
				tableNum++;
				if (tableNum == 3)
				{
					tableNum = 0;
				}
				pressed0 = true;
			}
		}
		else
		{
			pressed0 = false;
		}
	}
	pollEvents();
}


bool Game::getMousePos(float x, float y, int a, sf::Window& newWindow)
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
	case 5:
		if ((mousepos.x + 8 >= x && mousepos.x + 8 <= x + 300) && (mousepos.y + 8 >= y && mousepos.y + 8 <= y + 600))
		{
			return 1;
		}
		break;
	case 6:
		if ((mousepos.x + 8 >= x && mousepos.x + 8 <= x + 1300) && (mousepos.y + 8 >= y && mousepos.y + 8 <= y + 1000))
		{
			return 1;
		}
		break;
	case 7:
		if ((mousepos.x + 8 >= x && mousepos.x + 8 <= x + 120) && (mousepos.y + 8 >= y && mousepos.y + 8 <= y + 194))
		{
			return 1;
		}
		break;
	case 8:
		if ((mousepos.x + 8 >= x && mousepos.x + 8 <= x + 80) && (mousepos.y + 8 >= y && mousepos.y + 8 <= y + 80))
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

void Game::menu(sf::Window& newWindow)
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
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				rules = 1;
				pressed = true;
			}
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


void Game::rulestab(sf::Window& newWindow)
{
	this->window->clear();
	if (nextPage == -1)
	{
		this->backgroundTexture.loadFromFile("assets/RulesPage1.png");
		this->backgroundSprite.setTexture(backgroundTexture);
		if (getMousePos(1419, 371, 8, *this->window))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (!pressed5)
				{
					this->backgroundTexture.loadFromFile("assets/RulesPage2.png");
					this->backgroundSprite.setTexture(backgroundTexture);
					nextPage++;
					pressed5 = true;
				}
			}
			else
			{
				pressed5 = false;
			}
		}
	}
	if (nextPage == 0)
	{
		if (getMousePos(1419, 371, 8, *this->window))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (!pressed5)
				{
					this->backgroundTexture.loadFromFile("assets/RulesPage3.png");
					this->backgroundSprite.setTexture(backgroundTexture);
					nextPage++;
					pressed5 = true;
				}
			}
			else
			{
				pressed5 = false;
			}
		}
		else if (getMousePos(48, 371, 8, *this->window))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (!pressed6)
				{
					this->backgroundTexture.loadFromFile("assets/RulesPage1.png");
					this->backgroundSprite.setTexture(backgroundTexture);
					nextPage--;
					pressed6 = true;
				}
			}
			else
			{
				pressed6 = false;
			}
		}
	}
	else if (nextPage == 1)
	{
		if (getMousePos(1419, 371, 8, *this->window))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (!pressed5)
				{
					this->backgroundTexture.loadFromFile("assets/RulesPage4.png");
					this->backgroundSprite.setTexture(backgroundTexture);
					nextPage++;
					pressed5 = true;
				}
			}
			else
			{
				pressed5 = false;
			}
		}
		else if (getMousePos(48, 371, 8, *this->window))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (!pressed6)
				{
					this->backgroundTexture.loadFromFile("assets/RulesPage2.png");
					this->backgroundSprite.setTexture(backgroundTexture);
					nextPage--;
					pressed6 = true;
				}
			}
			else
			{
				pressed6 = false;
			}
		}
	}
	else if (nextPage == 2)
	{
		if (getMousePos(1419, 371, 8, *this->window))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (!pressed5)
				{
					this->backgroundTexture.loadFromFile("assets/RulesPage5.png");
					this->backgroundSprite.setTexture(backgroundTexture);
					nextPage++;
					pressed5 = true;
				}
			}
			else
			{
				pressed5 = false;
			}
		}
		else if (getMousePos(48, 371, 8, *this->window))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (!pressed6)
				{
					this->backgroundTexture.loadFromFile("assets/RulesPage3.png");
					this->backgroundSprite.setTexture(backgroundTexture);
					nextPage--;
					pressed6 = true;
				}
			}
			else
			{
				pressed6 = false;
			}
		}
	}
	else if (nextPage == 3)
	{
		if (getMousePos(1419, 371, 8, *this->window))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (!pressed5)
				{
					this->backgroundTexture.loadFromFile("assets/RulesPage6.png");
					this->backgroundSprite.setTexture(backgroundTexture);
					nextPage++;
					pressed5 = true;
				}
			}
			else
			{
				pressed5 = false;
			}
		}
		else if (getMousePos(48, 371, 8, *this->window))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (!pressed6)
				{
					this->backgroundTexture.loadFromFile("assets/RulesPage4.png");
					this->backgroundSprite.setTexture(backgroundTexture);
					nextPage--;
					pressed6 = true;
				}
			}
			else
			{
				pressed6 = false;
			}
		}
	}
	else if (nextPage == 4)
	{
		if (getMousePos(1419, 371, 8, *this->window))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (!pressed5)
				{
					this->backgroundTexture.loadFromFile("assets/RulesPage7.png");
					this->backgroundSprite.setTexture(backgroundTexture);
					nextPage++;
					pressed5 = true;
				}
			}
			else
			{
				pressed5 = false;
			}
		}
		else if (getMousePos(48, 371, 8, *this->window))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (!pressed6)
				{
					this->backgroundTexture.loadFromFile("assets/RulesPage5.png");
					this->backgroundSprite.setTexture(backgroundTexture);
					nextPage--;
					pressed6 = true;
				}
			}
			else
			{
				pressed6 = false;
			}
		}
	}
	else if (nextPage == 5)
	{
		if (getMousePos(1419, 41, 8, *this->window))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (!pressed5)
				{
					rules = 0;
					nextPage = -1;
					pressed5 = true;
				}
			}
			else
			{
				pressed5 = false;
			}
		}
		else if (getMousePos(48, 371, 8, *this->window))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (!pressed6)
				{
					this->backgroundTexture.loadFromFile("assets/RulesPage6.png");
					this->backgroundSprite.setTexture(backgroundTexture);
					nextPage--;
					pressed6 = true;
				}
			}
			else
			{
				pressed6 = false;
			}
		}
	}
	else
	{
		this->backgroundTexture.loadFromFile("assets/RulesPage1.png");
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
void Game::setCardImages(sf::Vector2i cursorpos)
{
	int numCounter = 1;

	for (int i = 1; i <= counterCards3; i++)
	{
		if (deck[i].display1 == 1 && counter == 1)
		{
			if (deck[i].player1pos == 1)
			{
				if (player1Pos1 == i && !(card2Dragging || card3Dragging || card4Dragging || card5Dragging))  // Display and drag The first card
				{
					if (getMousePos(0, 110, 4, *this->window))
					{
						deck[player1Pos1].img.setPosition(183, 110);
						if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !(card2Dragging || card3Dragging || card4Dragging || card5Dragging))
						{
							if (deck[i].drag && !pressed)
							{
								deck[i].drag = 0;
								card1Dragging = 0;
								pressed = true;
							}
							else if (!pressed)
							{
								card1Dragging = 1;
								deck[i].drag = 1;
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
						deck[player1Pos1].img.setPosition(170, 110);
					}
					if (deck[i].drag)
					{
						int x = cursorpos.x + 50;
						int y = cursorpos.y - 52;
						card1Dragging = 1;
						showA = 1;

						if (getMousePos(300, 0, 6, *this->window))
						{
							x = cursorpos.x + 69;
							y = cursorpos.y + 50;
							deck[i].img.setRotation(180.f);
							for (int j = 1; j < 17; j++)
							{
								if (getMousePos(fPositions[j].x, fPositions[j].y, 7, *this->window) && fPositions[j].showPos == 1)
								{
									if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
									{
										if (!pressed)
										{
											if (j == 16)
											{
												deck[i].drag = 0;
												deck[i].placed = 1;
												deck[i].num = 0;
												deck[counterCards3].type = deck[i].type;
												deck[counterCards3].value = deck[i].value;
												deck[counterCards3].num = counterCards3;
												deck[i].player1pos = 0;
												deck[i].display1 = 0;
												deck[i].display2 = 0;
												counterCards3++;
												card1Dragging = 0;
												player1Pos1 = 0;
												player1Cards--;
												pressed = true;
												roundPlayed = 1;
											}
											else
											{
												if (checkPlacedCards(j))
												{

													deck[i].drag = 0;
													deck[i].placed = 1;
													fPositions[j].cardOnIt = 1;
													fPositions[j].cardNum = deck[i].num;
													fPositions[j].cardValue = deck[i].value;
													deck[i].num = 0;
													deck[i].x = fPositions[j].x;
													deck[i].y = fPositions[j].y;
													deck[i].img.setPosition(fPositions[j].x, fPositions[j].y);
													card1Dragging = 0;
													player1Pos1 = 0;
													player1Cards--;
													pressed = true;
													roundPlayed = 1;
												}
												else
												{
													deck[i].drag = 0;
													deck[i].placed = 1;
													deck[i].num = 0;
													deck[counterCards3].type = deck[i].type;
													deck[counterCards3].value = deck[i].value;
													deck[counterCards3].num = counterCards3;
													deck[i].player1pos = 0;
													deck[i].display1 = 0;
													deck[i].display2 = 0;
													counterCards3++;
													card1Dragging = 0;
													player1Pos1 = 0;
													player1Cards--;
													pressed = true;
													roundPlayed = 1;
												}
											}
										}
									}
									else
									{
										pressed = false;
									}
								}
							}
						}
						else
						{

							deck[i].img.setRotation(90.f);
						}
						deck[i].img.setPosition(float(x), float(y));
						if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
						{
							if (!pressed)
							{
								deck[i].drag = 0;
								card1Dragging = 0;
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
						showA = 0;
						deck[i].img.setRotation(90.f);
					}
				}
				else if (player1Pos2 == i && !(card1Dragging || card3Dragging || card4Dragging || card5Dragging)) // Display and drag The second card
				{
					if (getMousePos(0, 245, 4, *this->window))
					{
						deck[player1Pos2].img.setPosition(183, 245);
						if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !(card1Dragging || card3Dragging || card4Dragging || card5Dragging))
						{
							if (deck[i].drag && !pressed1)
							{
								deck[i].drag = 0;
								card2Dragging = 0;
								pressed1 = true;
							}
							else if (!pressed1)
							{
								card2Dragging = 1;
								deck[i].drag = 1;
								pressed1 = true;
							}

						}
						else
						{
							pressed1 = false;
						}
					}
					else
					{
						deck[player1Pos2].img.setPosition(170, 245);
					}
					if (deck[i].drag)
					{
						int x = cursorpos.x + 50;
						int y = cursorpos.y - 52;
						showA = 1;

						if (getMousePos(300, 0, 6, *this->window))
						{
							x = cursorpos.x + 69;
							y = cursorpos.y + 50;
							deck[i].img.setRotation(180.f);
							for (int j = 1; j < 17; j++)
							{
								if (getMousePos(fPositions[j].x, fPositions[j].y, 7, *this->window) && fPositions[j].showPos == 1)
								{
									if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
									{
										if (!pressed1)
										{
											if (j == 16)
											{
												deck[i].drag = 0;
												deck[i].placed = 1;
												deck[i].num = 0;
												deck[counterCards3].type = deck[i].type;
												deck[counterCards3].value = deck[i].value;
												deck[counterCards3].num = counterCards3;
												deck[i].player1pos = 0;
												deck[i].display1 = 0;
												deck[i].display2 = 0;
												counterCards3++;
												card2Dragging = 0;
												player1Pos2 = 0;
												player1Cards--;
												pressed1 = true;
												roundPlayed = 1;
											}
											else
											{
												if (checkPlacedCards(j))
												{

													deck[i].drag = 0;
													deck[i].placed = 1;
													fPositions[j].cardOnIt = 1;
													fPositions[j].cardNum = deck[i].num;
													fPositions[j].cardValue = deck[i].value;
													deck[i].num = 0;
													deck[i].x = fPositions[j].x;
													deck[i].y = fPositions[j].y;
													deck[i].img.setPosition(fPositions[j].x, fPositions[j].y);
													card2Dragging = 0;
													player1Pos2 = 0;
													player1Cards--;
													pressed1 = true;
													roundPlayed = 1;
												}
												else
												{
													deck[i].drag = 0;
													deck[i].placed = 1;
													deck[i].num = 0;
													deck[counterCards3].type = deck[i].type;
													deck[counterCards3].value = deck[i].value;
													deck[counterCards3].num = counterCards3;
													deck[i].player1pos = 0;
													deck[i].display1 = 0;
													deck[i].display2 = 0;
													counterCards3++;
													card2Dragging = 0;
													player1Pos2 = 0;
													player1Cards--;
													pressed1 = true;
													roundPlayed = 1;
												}
											}
										}
									}
									else
									{
										pressed1 = false;
									}
								}
							}
						}
						else
						{

							deck[i].img.setRotation(90.f);
						}
						deck[i].img.setPosition(float(x), float(y));
					}
					else
					{
						showA = 0;
						deck[i].img.setRotation(90.f);
					}
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						if (!pressed1)
						{
							deck[i].drag = 0;
							card2Dragging = 0;
							pressed1 = true;
						}
					}
					else
					{
						pressed1 = false;
					}
				}
				else if (player1Pos3 == i && !(card1Dragging || card2Dragging || card4Dragging || card5Dragging)) // Display and drag The third card
				{
					if (getMousePos(0, 380, 4, *this->window))
					{
						deck[player1Pos3].img.setPosition(183, 380);
						if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !(card1Dragging || card2Dragging || card4Dragging || card5Dragging))
						{
							if (deck[i].drag && !pressed2)
							{
								deck[i].drag = 0;
								card3Dragging = 0;
								pressed2 = true;
							}
							else if (!pressed2)
							{
								card3Dragging = 1;
								deck[i].drag = 1;
								pressed2 = true;
							}
						}
						else
						{
							pressed2 = false;
						}
					}
					else
					{
						deck[player1Pos3].img.setPosition(170, 380);
					}
					if (deck[i].drag)
					{
						int x = cursorpos.x + 50;
						int y = cursorpos.y - 52;
						showA = 1;

						if (getMousePos(300, 0, 6, *this->window))
						{
							x = cursorpos.x + 69;
							y = cursorpos.y + 50;
							deck[i].img.setRotation(180.f);
							for (int j = 1; j < 17; j++)
							{
								if (getMousePos(fPositions[j].x, fPositions[j].y, 7, *this->window) && fPositions[j].showPos == 1)
								{
									if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
									{
										if (!pressed2)
										{
											if (j == 16)
											{
												deck[i].drag = 0;
												deck[i].placed = 1;
												deck[i].num = 0;
												deck[counterCards3].type = deck[i].type;
												deck[counterCards3].value = deck[i].value;
												deck[counterCards3].num = counterCards3;
												deck[i].player1pos = 0;
												deck[i].display1 = 0;
												deck[i].display2 = 0;
												counterCards3++;
												card3Dragging = 0;
												player1Pos3 = 0;
												player1Cards--;
												pressed2 = true;
												roundPlayed = 1;
											}
											else
											{
												if (checkPlacedCards(j))
												{

													deck[i].drag = 0;
													deck[i].placed = 1;
													fPositions[j].cardOnIt = 1;
													fPositions[j].cardNum = deck[i].num;
													fPositions[j].cardValue = deck[i].value;
													deck[i].num = 0;
													deck[i].x = fPositions[j].x;
													deck[i].y = fPositions[j].y;
													deck[i].img.setPosition(fPositions[j].x, fPositions[j].y);
													card3Dragging = 0;
													player1Pos3 = 0;
													player1Cards--;
													pressed2 = true;
													roundPlayed = 1;
												}
												else
												{
													deck[i].drag = 0;
													deck[i].placed = 1;
													deck[i].num = 0;
													deck[counterCards3].type = deck[i].type;
													deck[counterCards3].value = deck[i].value;
													deck[counterCards3].num = counterCards3;
													deck[i].player1pos = 0;
													deck[i].display1 = 0;
													deck[i].display2 = 0;
													counterCards3++;
													card3Dragging = 0;
													player1Pos3 = 0;
													player1Cards--;
													pressed2 = true;
													roundPlayed = 1;
												}
											}
										}
									}
									else
									{
										pressed2 = false;
									}
								}
							}
						}
						else
						{

							deck[i].img.setRotation(90.f);
						}
						deck[i].img.setPosition(float(x), float(y));
					}
					else
					{
						showA = 0;
						deck[i].img.setRotation(90.f);
					}
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						if (!pressed2)
						{
							deck[i].drag = 0;
							card3Dragging = 0;
							pressed2 = true;
						}
					}
					else
					{
						pressed2 = false;
					}
				}
				else if (player1Pos4 == i && !(card1Dragging || card2Dragging || card3Dragging || card5Dragging)) // Display and drag The fourth card
				{
					if (getMousePos(0, 515, 4, *this->window))
					{
						deck[player1Pos4].img.setPosition(183, 515);
						if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !(card1Dragging || card2Dragging || card3Dragging || card5Dragging))
						{
							if (deck[i].drag && !pressed3)
							{
								deck[i].drag = 0;
								card4Dragging = 0;
								pressed3 = true;
							}
							else if (!pressed3)
							{
								card4Dragging = 1;
								deck[i].drag = 1;
								pressed3 = true;
							}
						}
						else
						{
							pressed3 = false;
						}
					}
					else
					{
						deck[player1Pos4].img.setPosition(170, 515);
					}
					if (deck[i].drag)
					{
						int x = cursorpos.x + 50;
						int y = cursorpos.y - 52;
						showA = 1;

						if (getMousePos(300, 0, 6, *this->window))
						{
							x = cursorpos.x + 69;
							y = cursorpos.y + 50;
							deck[i].img.setRotation(180.f);
							for (int j = 1; j < 17; j++)
							{
								if (getMousePos(fPositions[j].x, fPositions[j].y, 7, *this->window) && fPositions[j].showPos == 1)
								{
									if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
									{
										if (!pressed3)
										{
											if (j == 16)
											{
												deck[i].drag = 0;
												deck[i].placed = 1;
												deck[i].num = 0;
												deck[counterCards3].type = deck[i].type;
												deck[counterCards3].value = deck[i].value;
												deck[counterCards3].num = counterCards3;
												deck[i].player1pos = 0;
												deck[i].display1 = 0;
												deck[i].display2 = 0;
												counterCards3++;
												card4Dragging = 0;
												player1Pos4 = 0;
												player1Cards--;
												pressed3 = true;
												roundPlayed = 1;
											}
											else
											{
												if (checkPlacedCards(j))
												{

													deck[i].drag = 0;
													deck[i].placed = 1;
													fPositions[j].cardOnIt = 1;
													fPositions[j].cardNum = deck[i].num;
													fPositions[j].cardValue = deck[i].value;
													deck[i].num = 0;
													deck[i].x = fPositions[j].x;
													deck[i].y = fPositions[j].y;
													deck[i].img.setPosition(fPositions[j].x, fPositions[j].y);
													card4Dragging = 0;
													player1Pos4 = 0;
													player1Cards--;
													pressed3 = true;
													roundPlayed = 1;
												}
												else
												{
													deck[i].drag = 0;
													deck[i].placed = 1;
													deck[i].num = 0;
													deck[counterCards3].type = deck[i].type;
													deck[counterCards3].value = deck[i].value;
													deck[counterCards3].num = counterCards3;
													deck[i].player1pos = 0;
													deck[i].display1 = 0;
													deck[i].display2 = 0;
													counterCards3++;
													card4Dragging = 0;
													player1Pos4 = 0;
													player1Cards--;
													pressed3 = true;
													roundPlayed = 1;
												}
											}
										}
									}
									else
									{
										pressed3 = false;
									}
								}
							}
						}
						else
						{

							deck[i].img.setRotation(90.f);
						}
						deck[i].img.setPosition(float(x), float(y));
					}
					else
					{
						showA = 0;
						deck[i].img.setRotation(90.f);
					}
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						if (!pressed3)
						{
							deck[i].drag = 0;
							card4Dragging = 0;
							pressed3 = true;
						}
					}
					else
					{
						pressed3 = false;
					}
				}
				else if (player1Pos5 == i && !(card1Dragging || card2Dragging || card3Dragging || card4Dragging)) // Display and drag The fifth card
				{
					if (getMousePos(0, 650, 4, *this->window))
					{
						deck[player1Pos5].img.setPosition(183, 650);
						if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !(card1Dragging || card2Dragging || card3Dragging || card4Dragging))
						{
							if (deck[i].drag && !pressed4)
							{
								deck[i].drag = 0;
								card5Dragging = 0;
								pressed4 = true;
							}
							else if (!pressed4)
							{
								card5Dragging = 1;
								deck[i].drag = 1;
								pressed4 = true;
							}
						}
						else
						{
							pressed4 = false;
						}
					}
					else
					{
						deck[player1Pos5].img.setPosition(170, 650);
					}
					if (deck[i].drag)
					{
						int x = cursorpos.x + 50;
						int y = cursorpos.y - 52;
						showA = 1;

						if (getMousePos(300, 0, 6, *this->window))
						{
							x = cursorpos.x + 69;
							y = cursorpos.y + 50;
							deck[i].img.setRotation(180.f);
							for (int j = 1; j < 17; j++)
							{
								if (getMousePos(fPositions[j].x, fPositions[j].y, 7, *this->window) && fPositions[j].showPos == 1)
								{
									if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
									{
										if (!pressed4)
										{
											if (j == 16)
											{
												deck[i].drag = 0;
												deck[i].placed = 1;
												deck[i].num = 0;
												deck[counterCards3].type = deck[i].type;
												deck[counterCards3].value = deck[i].value;
												deck[counterCards3].num = counterCards3;
												deck[i].player1pos = 0;
												deck[i].display1 = 0;
												deck[i].display2 = 0;
												counterCards3++;
												card5Dragging = 0;
												player1Pos5 = 0;
												player1Cards--;
												pressed4 = true;
												roundPlayed = 1;
											}
											else
											{
												if (checkPlacedCards(j))
												{

													deck[i].drag = 0;
													deck[i].placed = 1;
													fPositions[j].cardOnIt = 1;
													fPositions[j].cardNum = deck[i].num;
													fPositions[j].cardValue = deck[i].value;
													deck[i].num = 0;
													deck[i].x = fPositions[j].x;
													deck[i].y = fPositions[j].y;
													deck[i].img.setPosition(fPositions[j].x, fPositions[j].y);
													card5Dragging = 0;
													player1Pos5 = 0;
													player1Cards--;
													pressed4 = true;
													roundPlayed = 1;
												}
												else
												{
													deck[i].drag = 0;
													deck[i].placed = 1;
													deck[i].num = 0;
													deck[counterCards3].type = deck[i].type;
													deck[counterCards3].value = deck[i].value;
													deck[counterCards3].num = counterCards3;
													deck[i].player1pos = 0;
													deck[i].display1 = 0;
													deck[i].display2 = 0;
													counterCards3++;
													card5Dragging = 0;
													player1Pos5 = 0;
													player1Cards--;
													pressed4 = true;
													roundPlayed = 1;
												}
											}
										}
									}
									else
									{
										pressed4 = false;
									}
								}
							}
						}
						else
						{

							deck[i].img.setRotation(90.f);
						}
						deck[i].img.setPosition(float(x), float(y));
					}
					else
					{
						showA = 0;
						deck[i].img.setRotation(90.f);
					}
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						if (!pressed4)
						{
							deck[i].drag = 0;
							card5Dragging = 0;
							pressed4 = true;
						}
					}
					else
					{
						pressed4 = false;
					}
				}
				// Displaying by type
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
		}
		else if (deck[i].display2 == 1 && counter == 2)
		{
			if (deck[i].player2pos == 1)
			{
				if (player2Pos1 == i && !(card2Dragging2 || card3Dragging2 || card4Dragging2 || card5Dragging2))  // Display and drag The first card P2
				{
					if (getMousePos(0, 110, 4, *this->window))
					{
						deck[player2Pos1].img.setPosition(183, 110);
						if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !(card2Dragging2 || card3Dragging2 || card4Dragging2 || card5Dragging2))
						{
							if (deck[i].drag && !pressed20)
							{
								deck[i].drag = 0;
								card1Dragging2 = 0;
								pressed20 = true;
							}
							else if (!pressed20)
							{
								card1Dragging2 = 1;
								deck[i].drag = 1;
								pressed20 = true;
							}
						}
						else
						{
							pressed20 = false;
						}
					}
					else
					{
						deck[player2Pos1].img.setPosition(170, 110);
					}
					if (deck[i].drag)
					{
						float x = float(cursorpos.x + 50);
						float y = float(cursorpos.y - 52);
						showA2 = 1;

						if (getMousePos(300, 0, 6, *this->window))
						{
							x = float(cursorpos.x + 69);
							y = float(cursorpos.y + 50);
							deck[i].img.setRotation(180.f);
							for (int j = 1; j < 17; j++)
							{
								if (getMousePos(fPositions2[j].x, fPositions2[j].y, 7, *this->window) && fPositions2[j].showPos == 1)
								{
									if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
									{
										if (!pressed20)
										{
											if (j == 16)
											{
												deck[i].drag = 0;
												deck[i].placed = 1;
												deck[i].num = 0;
												deck[counterCards3].type = deck[i].type;
												deck[counterCards3].value = deck[i].value;
												deck[counterCards3].num = counterCards3;
												deck[i].player2pos = 0;
												deck[i].display1 = 0;
												deck[i].display2 = 0;
												counterCards3++;
												card1Dragging2 = 0;
												player2Pos1 = 0;
												player2Cards--;
												pressed20 = true;
												roundPlayed = 1;
											}
											else
											{
												if (checkPlacedCards(j))
												{

													deck[i].drag = 0;
													deck[i].placed = 1;
													fPositions2[j].cardOnIt = 1;
													fPositions2[j].cardNum = deck[i].num;
													fPositions2[j].cardValue = deck[i].value;
													deck[i].num = 0;
													deck[i].x = fPositions2[j].x;
													deck[i].y = fPositions2[j].y;
													deck[i].img.setPosition(fPositions2[j].x, fPositions2[j].y);
													card1Dragging2 = 0;
													player2Pos1 = 0;
													player2Cards--;
													pressed20 = true;
													roundPlayed = 1;
												}
												else
												{
													deck[i].drag = 0;
													deck[i].placed = 1;
													deck[i].num = 0;
													deck[counterCards3].type = deck[i].type;
													deck[counterCards3].value = deck[i].value;
													deck[counterCards3].num = counterCards3;
													deck[i].player2pos = 0;
													deck[i].display1 = 0;
													deck[i].display2 = 0;
													counterCards3++;
													card1Dragging2 = 0;
													player2Pos1 = 0;
													player2Cards--;
													pressed20 = true;
													roundPlayed = 1;
												}
											}
										}
									}
									else
									{
										pressed20 = false;
									}
								}
							}
						}
						else
						{

							deck[i].img.setRotation(90.f);
						}
						deck[i].img.setPosition(x, y);
					}
					else
					{
						showA2 = 0;
						deck[i].img.setRotation(90.f);
					}
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						if (!pressed20)
						{
							deck[i].drag = 0;
							card1Dragging2 = 0;
							pressed20 = true;
						}
					}
					else
					{
						pressed20 = false;
					}
				}
				else if (player2Pos2 == i && !(card1Dragging2 || card3Dragging2 || card4Dragging2 || card5Dragging2)) // Display and drag The second card P2
				{
					if (getMousePos(0, 245, 4, *this->window))
					{
						deck[player2Pos2].img.setPosition(183, 245);
						if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !(card1Dragging2 || card3Dragging2 || card4Dragging2 || card5Dragging2))
						{
							if (deck[i].drag && !pressed21)
							{
								deck[i].drag = 0;
								card2Dragging2 = 0;
								pressed21 = true;
							}
							else if (!pressed21)
							{
								card2Dragging2 = 1;
								deck[i].drag = 1;
								pressed21 = true;
							}

						}
						else
						{
							pressed21 = false;
						}
					}
					else
					{
						deck[player2Pos2].img.setPosition(170, 245);
					}
					if (deck[i].drag)
					{
						float x = float(cursorpos.x + 50);
						float y = float(cursorpos.y - 52);
						showA2 = 1;

						if (getMousePos(300, 0, 6, *this->window))
						{
							x = float(cursorpos.x + 69);
							y = float(cursorpos.y + 50);
							deck[i].img.setRotation(180.f);
							for (int j = 1; j < 17; j++)
							{
								if (getMousePos(fPositions2[j].x, fPositions2[j].y, 7, *this->window) && fPositions2[j].showPos == 1)
								{
									if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
									{
										if (!pressed21)
										{
											if (j == 16)
											{
												deck[i].drag = 0;
												deck[i].placed = 1;
												deck[i].num = 0;
												deck[counterCards3].type = deck[i].type;
												deck[counterCards3].value = deck[i].value;
												deck[counterCards3].num = counterCards3;
												deck[i].player2pos = 0;
												deck[i].display1 = 0;
												deck[i].display2 = 0;
												counterCards3++;
												card2Dragging2 = 0;
												player2Pos2 = 0;
												player2Cards--;
												pressed21 = true;
												roundPlayed = 1;
											}
											else
											{
												if (checkPlacedCards(j))
												{

													deck[i].drag = 0;
													deck[i].placed = 1;
													fPositions2[j].cardOnIt = 1;
													fPositions2[j].cardNum = deck[i].num;
													fPositions2[j].cardValue = deck[i].value;
													deck[i].num = 0;
													deck[i].x = fPositions2[j].x;
													deck[i].y = fPositions2[j].y;
													deck[i].img.setPosition(fPositions2[j].x, fPositions2[j].y);
													card2Dragging2 = 0;
													player2Pos2 = 0;
													player2Cards--;
													pressed21 = true;
													roundPlayed = 1;
												}
												else
												{
													deck[i].drag = 0;
													deck[i].placed = 1;
													deck[i].num = 0;
													deck[counterCards3].type = deck[i].type;
													deck[counterCards3].value = deck[i].value;
													deck[counterCards3].num = counterCards3;
													deck[i].player2pos = 0;
													deck[i].display1 = 0;
													deck[i].display2 = 0;
													counterCards3++;
													card2Dragging2 = 0;
													player2Pos2 = 0;
													player2Cards--;
													pressed21 = true;
													roundPlayed = 1;
												}
											}
										}
									}
									else
									{
										pressed21 = false;
									}
								}
							}
						}
						else
						{

							deck[i].img.setRotation(90.f);
						}
						deck[i].img.setPosition(x, y);
					}
					else
					{
						showA2 = 0;
						deck[i].img.setRotation(90.f);
					}
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						if (!pressed21)
						{
							deck[i].drag = 0;
							card2Dragging2 = 0;
							pressed21 = true;
						}
					}
					else
					{
						pressed21 = false;
					}
				}
				else if (player2Pos3 == i && !(card1Dragging2 || card2Dragging2 || card4Dragging2 || card5Dragging2)) // Display and drag The third card P2
				{
					if (getMousePos(0, 380, 4, *this->window))
					{
						deck[player2Pos3].img.setPosition(183, 380);
						if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !(card1Dragging2 || card2Dragging2 || card4Dragging2 || card5Dragging2))
						{
							if (deck[i].drag && !pressed22)
							{
								deck[i].drag = 0;
								card3Dragging2 = 0;
								pressed22 = true;
							}
							else if (!pressed22)
							{
								card3Dragging2 = 1;
								deck[i].drag = 1;
								pressed22 = true;
							}
						}
						else
						{
							pressed22 = false;
						}
					}
					else
					{
						deck[player2Pos3].img.setPosition(170, 380);
					}
					if (deck[i].drag)
					{
						float x = float(cursorpos.x + 50);
						float y = float(cursorpos.y - 52);
						showA2 = 1;

						if (getMousePos(300, 0, 6, *this->window))
						{
							x = float(cursorpos.x + 69);
							y = float(cursorpos.y + 50);
							deck[i].img.setRotation(180.f);
							for (int j = 1; j < 17; j++)
							{
								if (getMousePos(fPositions2[j].x, fPositions2[j].y, 7, *this->window) && fPositions2[j].showPos == 1)
								{
									if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
									{
										if (!pressed22)
										{
											if (j == 16)
											{
												deck[i].drag = 0;
												deck[i].placed = 1;
												deck[i].num = 0;
												deck[counterCards3].type = deck[i].type;
												deck[counterCards3].value = deck[i].value;
												deck[counterCards3].num = counterCards3;
												deck[i].player2pos = 0;
												deck[i].display1 = 0;
												deck[i].display2 = 0;
												counterCards3++;
												card3Dragging2 = 0;
												player2Pos3 = 0;
												player2Cards--;
												pressed22 = true;
												roundPlayed = 1;
											}
											else
											{
												if (checkPlacedCards(j))
												{

													deck[i].drag = 0;
													deck[i].placed = 1;
													fPositions2[j].cardOnIt = 1;
													fPositions2[j].cardNum = deck[i].num;
													fPositions2[j].cardValue = deck[i].value;
													deck[i].num = 0;
													deck[i].x = fPositions2[j].x;
													deck[i].y = fPositions2[j].y;
													deck[i].img.setPosition(fPositions2[j].x, fPositions2[j].y);
													card3Dragging2 = 0;
													player2Pos3 = 0;
													player2Cards--;
													pressed22 = true;
													roundPlayed = 1;
												}
												else
												{
													deck[i].drag = 0;
													deck[i].placed = 1;
													deck[i].num = 0;
													deck[counterCards3].type = deck[i].type;
													deck[counterCards3].value = deck[i].value;
													deck[counterCards3].num = counterCards3;
													deck[i].player2pos = 0;
													deck[i].display1 = 0;
													deck[i].display2 = 0;
													counterCards3++;
													card3Dragging2 = 0;
													player2Pos3 = 0;
													player2Cards--;
													pressed22 = true;
													roundPlayed = 1;
												}
											}
										}
									}
									else
									{
										pressed22 = false;
									}
								}
							}
						}
						else
						{

							deck[i].img.setRotation(90.f);
						}
						deck[i].img.setPosition(x, y);
					}
					else
					{
						showA2 = 0;
						deck[i].img.setRotation(90.f);
					}
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						if (!pressed22)
						{
							deck[i].drag = 0;
							card3Dragging2 = 0;
							pressed22 = true;
						}
					}
					else
					{
						pressed22 = false;
					}
				}
				else if (player2Pos4 == i && !(card1Dragging2 || card2Dragging2 || card3Dragging2 || card5Dragging2)) // Display and drag The fourth card P2
				{
					if (getMousePos(0, 515, 4, *this->window))
					{
						deck[player2Pos4].img.setPosition(183, 515);
						if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !(card1Dragging2 || card2Dragging2 || card3Dragging2 || card5Dragging2))
						{
							if (deck[i].drag && !pressed23)
							{
								deck[i].drag = 0;
								card4Dragging2 = 0;
								pressed23 = true;
							}
							else if (!pressed23)
							{
								card4Dragging2 = 1;
								deck[i].drag = 1;
								pressed23 = true;
							}
						}
						else
						{
							pressed23 = false;
						}
					}
					else
					{
						deck[player2Pos4].img.setPosition(170, 515);
					}
					if (deck[i].drag)
					{
						float x = float(cursorpos.x + 50);
						float y = float(cursorpos.y - 52);
						showA2 = 1;

						if (getMousePos(300, 0, 6, *this->window))
						{
							x = float(cursorpos.x + 69);
							y = float(cursorpos.y + 50);
							deck[i].img.setRotation(180.f);
							for (int j = 1; j < 17; j++)
							{
								if (getMousePos(fPositions2[j].x, fPositions2[j].y, 7, *this->window) && fPositions2[j].showPos == 1)
								{
									if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
									{
										if (!pressed23)
										{
											if (j == 16)
											{
												deck[i].drag = 0;
												deck[i].placed = 1;
												deck[i].num = 0;
												deck[counterCards3].type = deck[i].type;
												deck[counterCards3].value = deck[i].value;
												deck[counterCards3].num = counterCards3;
												deck[i].player2pos = 0;
												deck[i].display1 = 0;
												deck[i].display2 = 0;
												counterCards3++;
												card4Dragging2 = 0;
												player2Pos4 = 0;
												player2Cards--;
												pressed23 = true;
												roundPlayed = 1;
											}
											else
											{
												if (checkPlacedCards(j))
												{

													deck[i].drag = 0;
													deck[i].placed = 1;
													fPositions2[j].cardOnIt = 1;
													fPositions2[j].cardNum = deck[i].num;
													fPositions2[j].cardValue = deck[i].value;
													deck[i].num = 0;
													deck[i].x = fPositions2[j].x;
													deck[i].y = fPositions2[j].y;
													deck[i].img.setPosition(fPositions2[j].x, fPositions2[j].y);
													card4Dragging2 = 0;
													player2Pos4 = 0;
													player2Cards--;
													pressed23 = true;
													roundPlayed = 1;
												}
												else
												{
													deck[i].drag = 0;
													deck[i].placed = 1;
													deck[i].num = 0;
													deck[counterCards3].type = deck[i].type;
													deck[counterCards3].value = deck[i].value;
													deck[counterCards3].num = counterCards3;
													deck[i].player2pos = 0;
													deck[i].display1 = 0;
													deck[i].display2 = 0;
													counterCards3++;
													card4Dragging2 = 0;
													player2Pos4 = 0;
													player2Cards--;
													pressed23 = true;
													roundPlayed = 1;
												}
											}
										}
									}
									else
									{
										pressed23 = false;
									}
								}
							}
						}
						else
						{

							deck[i].img.setRotation(90.f);
						}
						deck[i].img.setPosition(x, y);
					}
					else
					{
						showA2 = 0;
						deck[i].img.setRotation(90.f);
					}
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						if (!pressed23)
						{
							deck[i].drag = 0;
							card4Dragging2 = 0;
							pressed23 = true;
						}
					}
					else
					{
						pressed23 = false;
					}
				}
				else if (player2Pos5 == i && !(card1Dragging2 || card2Dragging2 || card3Dragging2 || card4Dragging2)) // Display and drag The fifth card P2
				{
					if (getMousePos(0, 650, 4, *this->window))
					{
						deck[player2Pos5].img.setPosition(183, 650);
						if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !(card1Dragging2 || card2Dragging2 || card3Dragging2 || card4Dragging2))
						{
							if (deck[i].drag && !pressed24)
							{
								deck[i].drag = 0;
								card5Dragging2 = 0;
								pressed24 = true;
							}
							else if (!pressed24)
							{
								card5Dragging2 = 1;
								deck[i].drag = 1;
								pressed24 = true;
							}
						}
						else
						{
							pressed24 = false;
						}
					}
					else
					{
						deck[player2Pos5].img.setPosition(170, 650);
					}
					if (deck[i].drag)
					{
						int x = cursorpos.x + 50;
						int y = cursorpos.y - 52;
						showA2 = 1;

						if (getMousePos(300, 0, 6, *this->window))
						{
							x = cursorpos.x + 69;
							y = cursorpos.y + 50;
							deck[i].img.setRotation(180.f);
							for (int j = 1; j < 17; j++)
							{
								if (getMousePos(fPositions2[j].x, fPositions2[j].y, 7, *this->window) && fPositions2[j].showPos == 1)
								{
									if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
									{
										if (!pressed24)
										{
											if (j == 16)
											{
												deck[i].drag = 0;
												deck[i].placed = 1;
												deck[i].num = 0;
												deck[counterCards3].type = deck[i].type;
												deck[counterCards3].value = deck[i].value;
												deck[counterCards3].num = counterCards3;
												deck[i].player2pos = 0;
												deck[i].display1 = 0;
												deck[i].display2 = 0;
												counterCards3++;
												card5Dragging2 = 0;
												player2Pos5 = 0;
												player2Cards--;
												pressed24 = true;
												roundPlayed = 1;
											}
											else
											{
												if (checkPlacedCards(j))
												{

													deck[i].drag = 0;
													deck[i].placed = 1;
													fPositions2[j].cardOnIt = 1;
													fPositions2[j].cardNum = deck[i].num;
													fPositions2[j].cardValue = deck[i].value;
													deck[i].num = 0;
													deck[i].x = fPositions2[j].x;
													deck[i].y = fPositions2[j].y;
													deck[i].img.setPosition(fPositions2[j].x, fPositions2[j].y);
													card5Dragging2 = 0;
													player2Pos5 = 0;
													player2Cards--;
													pressed24 = true;
													roundPlayed = 1;
												}
												else
												{
													deck[i].drag = 0;
													deck[i].placed = 1;
													deck[i].num = 0;
													deck[counterCards3].type = deck[i].type;
													deck[counterCards3].value = deck[i].value;
													deck[counterCards3].num = counterCards3;
													deck[i].player2pos = 0;
													deck[i].display1 = 0;
													deck[i].display2 = 0;
													counterCards3++;
													card5Dragging2 = 0;
													player2Pos5 = 0;
													player2Cards--;
													pressed24 = true;
													roundPlayed = 1;
												}
											}
										}
									}
									else
									{
										pressed24 = false;
									}
								}
							}
						}
						else
						{

							deck[i].img.setRotation(90.f);
						}
						deck[i].img.setPosition(float(x), float(y));
					}
					else
					{
						showA2 = 0;
						deck[i].img.setRotation(90.f);
					}
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						if (!pressed24)
						{
							deck[i].drag = 0;
							card5Dragging2 = 0;
							pressed24 = true;
						}
					}
					else
					{
						pressed24 = false;
					}
				}
				// Displaying by type P2
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
		}
	}
}

bool Game::checkPlacedCards(int jj)
{
	for (int i = 0; i < counterCards3; i++)
	{
		if (counter == 1)
		{
			if (deck[i].drag == 1)
			{
				switch (jj)
				{
				case 1:
					if (deck[i].type == 'a')
					{
						if ((baseCards[0].value && baseCards[1].value) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'o')
					{
						if ((baseCards[0].value || baseCards[1].value) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'x')
					{
						if ((baseCards[0].value ^ baseCards[1].value) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					break;
				case 2:
					if (deck[i].type == 'a')
					{
						if ((baseCards[1].value && baseCards[2].value) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'o')
					{
						if ((baseCards[1].value || baseCards[2].value) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'x')
					{
						if ((baseCards[1].value ^ baseCards[2].value) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					break;
				case 3:
					if (deck[i].type == 'a')
					{
						if ((baseCards[2].value && baseCards[3].value) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'o')
					{
						if ((baseCards[2].value || baseCards[3].value) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'x')
					{
						if ((baseCards[2].value ^ baseCards[3].value) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					break;
				case 4:
					if (deck[i].type == 'a')
					{
						if ((baseCards[3].value && baseCards[4].value) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'o')
					{
						if ((baseCards[3].value || baseCards[4].value) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'x')
					{
						if ((baseCards[3].value ^ baseCards[4].value) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					break;
				case 5:
					if (deck[i].type == 'a')
					{
						if ((baseCards[4].value && baseCards[5].value) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'o')
					{
						if ((baseCards[4].value || baseCards[5].value) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'x')
					{
						if ((baseCards[4].value ^ baseCards[5].value) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					break;
				case 6:
					if (deck[i].type == 'a')
					{
						if ((fPositions[1].cardValue && fPositions[2].cardValue) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'o')
					{
						if ((fPositions[1].cardValue || fPositions[2].cardValue) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'x')
					{
						if ((fPositions[1].cardValue ^ fPositions[2].cardValue) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					break;
				case 7:
					if (deck[i].type == 'a')
					{
						if ((fPositions[2].cardValue && fPositions[3].cardValue) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'o')
					{
						if ((fPositions[2].cardValue || fPositions[3].cardValue) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'x')
					{
						if ((fPositions[2].cardValue ^ fPositions[3].cardValue) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					break;
				case 8:
					if (deck[i].type == 'a')
					{
						if ((fPositions[3].cardValue && fPositions[4].cardValue) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'o')
					{
						if ((fPositions[3].cardValue || fPositions[4].cardValue) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'x')
					{
						if ((fPositions[3].cardValue ^ fPositions[4].cardValue) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					break;
				case 9:
					if (deck[i].type == 'a')
					{
						if ((fPositions[4].cardValue && fPositions[5].cardValue) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'o')
					{
						if ((fPositions[4].cardValue || fPositions[5].cardValue) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'x')
					{
						if ((fPositions[4].cardValue ^ fPositions[5].cardValue) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					break;
				case 10:
					if (deck[i].type == 'a')
					{
						if ((fPositions[6].cardValue && fPositions[7].cardValue) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'o')
					{
						if ((fPositions[6].cardValue || fPositions[7].cardValue) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'x')
					{
						if ((fPositions[6].cardValue ^ fPositions[7].cardValue) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					break;
				case 11:
					if (deck[i].type == 'a')
					{
						if ((fPositions[7].cardValue && fPositions[8].cardValue) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'o')
					{
						if ((fPositions[7].cardValue || fPositions[8].cardValue) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'x')
					{
						if ((fPositions[7].cardValue ^ fPositions[8].cardValue) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					break;
				case 12:
					if (deck[i].type == 'a')
					{
						if ((fPositions[8].cardValue && fPositions[9].cardValue) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'o')
					{
						if ((fPositions[8].cardValue || fPositions[9].cardValue) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'x')
					{
						if ((fPositions[8].cardValue ^ fPositions[9].cardValue) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					break;
				case 13:
					if (deck[i].type == 'a')
					{
						if ((fPositions[10].cardValue && fPositions[11].cardValue) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'o')
					{
						if ((fPositions[10].cardValue || fPositions[11].cardValue) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'x')
					{
						if ((fPositions[10].cardValue ^ fPositions[11].cardValue) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					break;
				case 14:
					if (deck[i].type == 'a')
					{
						if ((fPositions[11].cardValue && fPositions[12].cardValue) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'o')
					{
						if ((fPositions[11].cardValue || fPositions[12].cardValue) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'x')
					{
						if ((fPositions[11].cardValue ^ fPositions[12].cardValue) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					break;
				case 15:
					if (deck[i].type == 'a')
					{
						if ((fPositions[13].cardValue && fPositions[14].cardValue) == deck[i].value)
						{
							win = 1;
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'o')
					{
						if ((fPositions[13].cardValue || fPositions[14].cardValue) == deck[i].value)
						{
							win = 1;
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'x')
					{
						if ((fPositions[13].cardValue ^ fPositions[14].cardValue) == deck[i].value)
						{
							win = 1;
							return 1;
						}
						return 0;
					}
					break;
				default:
					return 0;
					break;
				}
			}
		}
		else if (counter == 2)
		{
			if (deck[i].drag == 1)
			{
				switch (jj)
				{
				case 1:
					if (deck[i].type == 'a')
					{
						if ((baseCards2[0].value && baseCards2[1].value) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'o')
					{
						if ((baseCards2[0].value || baseCards2[1].value) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'x')
					{
						if ((baseCards2[0].value ^ baseCards2[1].value) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					break;
				case 2:
					if (deck[i].type == 'a')
					{
						if ((baseCards2[1].value && baseCards2[2].value) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'o')
					{
						if ((baseCards2[1].value || baseCards2[2].value) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'x')
					{
						if ((baseCards2[1].value ^ baseCards2[2].value) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					break;
				case 3:
					if (deck[i].type == 'a')
					{
						if ((baseCards2[2].value && baseCards2[3].value) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'o')
					{
						if ((baseCards2[2].value || baseCards2[3].value) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'x')
					{
						if ((baseCards2[2].value ^ baseCards2[3].value) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					break;
				case 4:
					if (deck[i].type == 'a')
					{
						if ((baseCards2[3].value && baseCards2[4].value) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'o')
					{
						if ((baseCards2[3].value || baseCards2[4].value) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'x')
					{
						if ((baseCards2[3].value ^ baseCards2[4].value) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					break;
				case 5:
					if (deck[i].type == 'a')
					{
						if ((baseCards2[4].value && baseCards2[5].value) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'o')
					{
						if ((baseCards2[4].value || baseCards2[5].value) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'x')
					{
						if ((baseCards2[4].value ^ baseCards2[5].value) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					break;
				case 6:
					if (deck[i].type == 'a')
					{
						if ((fPositions2[1].cardValue && fPositions2[2].cardValue) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'o')
					{
						if ((fPositions2[1].cardValue || fPositions2[2].cardValue) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'x')
					{
						if ((fPositions2[1].cardValue ^ fPositions2[2].cardValue) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					break;
				case 7:
					if (deck[i].type == 'a')
					{
						if ((fPositions2[2].cardValue && fPositions2[3].cardValue) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'o')
					{
						if ((fPositions2[2].cardValue || fPositions2[3].cardValue) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'x')
					{
						if ((fPositions2[2].cardValue ^ fPositions2[3].cardValue) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					break;
				case 8:
					if (deck[i].type == 'a')
					{
						if ((fPositions2[3].cardValue && fPositions2[4].cardValue) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'o')
					{
						if ((fPositions2[3].cardValue || fPositions2[4].cardValue) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'x')
					{
						if ((fPositions2[3].cardValue ^ fPositions2[4].cardValue) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					break;
				case 9:
					if (deck[i].type == 'a')
					{
						if ((fPositions2[4].cardValue && fPositions2[5].cardValue) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'o')
					{
						if ((fPositions2[4].cardValue || fPositions2[5].cardValue) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'x')
					{
						if ((fPositions2[4].cardValue ^ fPositions2[5].cardValue) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					break;
				case 10:
					if (deck[i].type == 'a')
					{
						if ((fPositions2[6].cardValue && fPositions2[7].cardValue) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'o')
					{
						if ((fPositions2[6].cardValue || fPositions2[7].cardValue) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'x')
					{
						if ((fPositions2[6].cardValue ^ fPositions2[7].cardValue) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					break;
				case 11:
					if (deck[i].type == 'a')
					{
						if ((fPositions2[7].cardValue && fPositions2[8].cardValue) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'o')
					{
						if ((fPositions2[7].cardValue || fPositions2[8].cardValue) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'x')
					{
						if ((fPositions2[7].cardValue ^ fPositions2[8].cardValue) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					break;
				case 12:
					if (deck[i].type == 'a')
					{
						if ((fPositions2[8].cardValue && fPositions2[9].cardValue) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'o')
					{
						if ((fPositions2[8].cardValue || fPositions2[9].cardValue) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'x')
					{
						if ((fPositions2[8].cardValue ^ fPositions2[9].cardValue) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					break;
				case 13:
					if (deck[i].type == 'a')
					{
						if ((fPositions2[10].cardValue && fPositions2[11].cardValue) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'o')
					{
						if ((fPositions2[10].cardValue || fPositions2[11].cardValue) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'x')
					{
						if ((fPositions2[10].cardValue ^ fPositions2[11].cardValue) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					break;
				case 14:
					if (deck[i].type == 'a')
					{
						if ((fPositions2[11].cardValue && fPositions2[12].cardValue) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'o')
					{
						if ((fPositions2[11].cardValue || fPositions2[12].cardValue) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'x')
					{
						if ((fPositions2[11].cardValue ^ fPositions2[12].cardValue) == deck[i].value)
						{
							return 1;
						}
						return 0;
					}
					break;
				case 15:
					if (deck[i].type == 'a')
					{
						if ((fPositions2[13].cardValue && fPositions2[14].cardValue) == deck[i].value)
						{
							win = 2;
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'o')
					{
						if ((fPositions2[13].cardValue || fPositions2[14].cardValue) == deck[i].value)
						{
							win = 2;
							return 1;
						}
						return 0;
					}
					else if (deck[i].type == 'x')
					{
						if ((fPositions2[13].cardValue ^ fPositions2[14].cardValue) == deck[i].value)
						{
							win = 2;
							return 1;
						}
						return 0;
					}
					break;
				default:
					return 0;
					break;
				}
			}
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
			baseCards2[i].value = 1;
			baseCards2[i].BaseCardImgTexture.loadFromFile("assets/BaseCard1.png");
			baseCards2[i].BaseCardImgTexture.setSmooth(true);
			baseCards2[i].BaseCardImg.setTexture(baseCards2[i].BaseCardImgTexture);
		}
		else
		{
			baseCards[i].value = 1;
			baseCards[i].BaseCardImgTexture.loadFromFile("assets/BaseCard1.png");
			baseCards[i].BaseCardImgTexture.setSmooth(true);
			baseCards[i].BaseCardImg.setTexture(baseCards[i].BaseCardImgTexture);
			baseCards2[i].value = 0;
			baseCards2[i].BaseCardImgTexture.loadFromFile("assets/BaseCard0.png");
			baseCards2[i].BaseCardImgTexture.setSmooth(true);
			baseCards2[i].BaseCardImg.setTexture(baseCards2[i].BaseCardImgTexture);
		}
	}
	baseCards[0].BaseCardImg.setPosition(334, -98);
	baseCards[1].BaseCardImg.setPosition(497, -98);
	baseCards[2].BaseCardImg.setPosition(660, -98);
	baseCards[3].BaseCardImg.setPosition(823, -98);
	baseCards[4].BaseCardImg.setPosition(986, -98);
	baseCards[5].BaseCardImg.setPosition(1149, -98);
	baseCards2[0].BaseCardImg.setPosition(334, -98);
	baseCards2[1].BaseCardImg.setPosition(497, -98);
	baseCards2[2].BaseCardImg.setPosition(660, -98);
	baseCards2[3].BaseCardImg.setPosition(823, -98);
	baseCards2[4].BaseCardImg.setPosition(986, -98);
	baseCards2[5].BaseCardImg.setPosition(1149, -98);
}

void Game::cardsInHand()
{
	for (int i = counterCards; i < counterCards2; i++)
	{
		if (counter == 1)
		{
			if (deck[i].player == 1 && deck[i].player1pos == 0)
			{
				if (player1Pos1 == 0)
				{
					player1Pos1 = deck[i].num;
					deck[i].player1pos = 1;
					deck[i].img.setRotation(90.f);
					deck[i].display1 = true;
					counterCards++;
					counterCards2++;
				}
				else if (player1Pos2 == 0)
				{
					player1Pos2 = deck[i].num;
					deck[i].player1pos = 1;
					deck[i].img.setRotation(90.f);
					deck[i].display1 = true;
					counterCards++;
					counterCards2++;
				}
				else if (player1Pos3 == 0)
				{
					player1Pos3 = deck[i].num;
					deck[i].player1pos = 1;
					deck[i].img.setRotation(90.f);
					deck[i].display1 = true;
					counterCards++;
					counterCards2++;
				}
				else if (player1Pos4 == 0)
				{
					player1Pos4 = deck[i].num;
					deck[i].player1pos = 1;
					deck[i].img.setRotation(90.f);
					deck[i].display1 = true;
					counterCards++;
					counterCards2++;
				}
				else if (player1Pos5 == 0)
				{
					player1Pos5 = deck[i].num;
					deck[i].player1pos = 1;
					deck[i].img.setRotation(90.f);
					deck[i].display1 = true;
					counterCards++;
					counterCards2++;
				}
			}
		}
		else if (counter == 2)
		{
			if (deck[i].player == 2 && deck[i].player2pos == 0)
			{
				if (player2Pos1 == 0)
				{
					player2Pos1 = deck[i].num;
					deck[i].player2pos = 1;
					deck[i].img.setRotation(90.f);
					deck[i].display2 = true;
					counterCards++;
					counterCards2++;
				}
				else if (player2Pos2 == 0)
				{
					player2Pos2 = deck[i].num;
					deck[i].player2pos = 1;
					deck[i].img.setRotation(90.f);
					deck[i].display2 = true;
					counterCards++;
					counterCards2++;
				}
				else if (player2Pos3 == 0)
				{
					player2Pos3 = deck[i].num;
					deck[i].player2pos = 1;
					deck[i].img.setRotation(90.f);
					deck[i].display2 = true;
					counterCards++;
					counterCards2++;
				}
				else if (player2Pos4 == 0)
				{
					player2Pos4 = deck[i].num;
					deck[i].player2pos = 1;
					deck[i].img.setRotation(90.f);
					deck[i].display2 = true;
					counterCards++;
					counterCards2++;
				}
				else if (player2Pos5 == 0)
				{
					player2Pos5 = deck[i].num;
					deck[i].player2pos = 1;
					deck[i].img.setRotation(90.f);
					deck[i].display2 = true;
					counterCards++;
					counterCards2++;
				}
			}
		}
	}
}

void Game::placingCardsPos()
{
	if (counter == 1)
	{
		for (int i = 1; i < 17; i++)
		{
			if (fPositions[i].showPos == 1)
			{
				this->window->draw(fPositions[i].img);
			}
		}
		for (int i = 1; i < 17; i++)
		{
			switch (fPositions[i].pos)
			{
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
				if (fPositions[i].cardOnIt == 0)
				{
					fPositions[i].showPos = 1;
				}
				else
				{
					fPositions[i].showPos = 0;
				}
				break;
			case 6:
				if (fPositions[i].cardOnIt == 0 && fPositions[1].cardOnIt == 1 && fPositions[2].cardOnIt == 1)
				{
					fPositions[i].showPos = 1;
				}
				else
				{
					fPositions[i].showPos = 0;
				}
				break;
			case 7:
				if (fPositions[i].cardOnIt == 0 && fPositions[2].cardOnIt == 1 && fPositions[3].cardOnIt == 1)
				{
					fPositions[i].showPos = 1;
				}
				else
				{
					fPositions[i].showPos = 0;
				}
				break;
			case 8:
				if (fPositions[i].cardOnIt == 0 && fPositions[3].cardOnIt == 1 && fPositions[4].cardOnIt == 1)
				{
					fPositions[i].showPos = 1;
				}
				else
				{
					fPositions[i].showPos = 0;
				}
				break;
			case 9:
				if (fPositions[i].cardOnIt == 0 && fPositions[4].cardOnIt == 1 && fPositions[5].cardOnIt == 1)
				{
					fPositions[i].showPos = 1;
				}
				else
				{
					fPositions[i].showPos = 0;
				}
				break;
			case 10:
				if (fPositions[i].cardOnIt == 0 && fPositions[6].cardOnIt == 1 && fPositions[7].cardOnIt == 1)
				{
					fPositions[i].showPos = 1;
				}
				else
				{
					fPositions[i].showPos = 0;
				}
				break;
			case 11:
				if (fPositions[i].cardOnIt == 0 && fPositions[7].cardOnIt == 1 && fPositions[8].cardOnIt == 1)
				{
					fPositions[i].showPos = 1;
				}
				else
				{
					fPositions[i].showPos = 0;
				}
				break;
			case 12:
				if (fPositions[i].cardOnIt == 0 && fPositions[8].cardOnIt == 1 && fPositions[9].cardOnIt == 1)
				{
					fPositions[i].showPos = 1;
				}
				else
				{
					fPositions[i].showPos = 0;
				}
				break;
			case 13:
				if (fPositions[i].cardOnIt == 0 && fPositions[10].cardOnIt == 1 && fPositions[11].cardOnIt == 1)
				{
					fPositions[i].showPos = 1;
				}
				else
				{
					fPositions[i].showPos = 0;
				}
				break;
			case 14:
				if (fPositions[i].cardOnIt == 0 && fPositions[11].cardOnIt == 1 && fPositions[12].cardOnIt == 1)
				{
					fPositions[i].showPos = 1;
				}
				else
				{
					fPositions[i].showPos = 0;
				}
				break;
			case 15:
				if (fPositions[i].cardOnIt == 0 && fPositions[13].cardOnIt == 1 && fPositions[14].cardOnIt == 1)
				{
					fPositions[i].showPos = 1;
				}
				else
				{
					fPositions[i].showPos = 0;
				}
				break;
			case 16:
				fPositions[i].showPos = 1;
				break;
			}
		}
	}
	else if (counter == 2)
	{
		for (int i = 1; i < 17; i++)
		{
			if (fPositions2[i].showPos == 1)
			{
				this->window->draw(fPositions2[i].img);
			}
		}
		for (int i = 1; i < 17; i++)
		{
			switch (fPositions2[i].pos)
			{
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
				if (fPositions2[i].cardOnIt == 0)
				{
					fPositions2[i].showPos = 1;
				}
				else
				{
					fPositions2[i].showPos = 0;
				}
				break;
			case 6:
				if (fPositions2[i].cardOnIt == 0 && fPositions2[1].cardOnIt == 1 && fPositions2[2].cardOnIt == 1)
				{
					fPositions2[i].showPos = 1;
				}
				else
				{
					fPositions2[i].showPos = 0;
				}
				break;
			case 7:
				if (fPositions2[i].cardOnIt == 0 && fPositions2[2].cardOnIt == 1 && fPositions2[3].cardOnIt == 1)
				{
					fPositions2[i].showPos = 1;
				}
				else
				{
					fPositions2[i].showPos = 0;
				}
				break;
			case 8:
				if (fPositions2[i].cardOnIt == 0 && fPositions2[3].cardOnIt == 1 && fPositions2[4].cardOnIt == 1)
				{
					fPositions2[i].showPos = 1;
				}
				else
				{
					fPositions2[i].showPos = 0;
				}
				break;
			case 9:
				if (fPositions2[i].cardOnIt == 0 && fPositions2[4].cardOnIt == 1 && fPositions2[5].cardOnIt == 1)
				{
					fPositions2[i].showPos = 1;
				}
				else
				{
					fPositions2[i].showPos = 0;
				}
				break;
			case 10:
				if (fPositions2[i].cardOnIt == 0 && fPositions2[6].cardOnIt == 1 && fPositions2[7].cardOnIt == 1)
				{
					fPositions2[i].showPos = 1;
				}
				else
				{
					fPositions2[i].showPos = 0;
				}
				break;
			case 11:
				if (fPositions2[i].cardOnIt == 0 && fPositions2[7].cardOnIt == 1 && fPositions2[8].cardOnIt == 1)
				{
					fPositions2[i].showPos = 1;
				}
				else
				{
					fPositions2[i].showPos = 0;
				}
				break;
			case 12:
				if (fPositions2[i].cardOnIt == 0 && fPositions2[8].cardOnIt == 1 && fPositions2[9].cardOnIt == 1)
				{
					fPositions2[i].showPos = 1;
				}
				else
				{
					fPositions2[i].showPos = 0;
				}
				break;
			case 13:
				if (fPositions2[i].cardOnIt == 0 && fPositions2[10].cardOnIt == 1 && fPositions2[11].cardOnIt == 1)
				{
					fPositions2[i].showPos = 1;
				}
				else
				{
					fPositions2[i].showPos = 0;
				}
				break;
			case 14:
				if (fPositions2[i].cardOnIt == 0 && fPositions2[11].cardOnIt == 1 && fPositions2[12].cardOnIt == 1)
				{
					fPositions2[i].showPos = 1;
				}
				else
				{
					fPositions2[i].showPos = 0;
				}
				break;
			case 15:
				if (fPositions2[i].cardOnIt == 0 && fPositions2[13].cardOnIt == 1 && fPositions2[14].cardOnIt == 1)
				{
					fPositions2[i].showPos = 1;
				}
				else
				{
					fPositions2[i].showPos = 0;
				}
				break;
			case 16:
				fPositions2[i].showPos = 1;
				break;
			}
		}
	}
}

void Game::tableOfTruth()
{
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
}

void Game::setTimer()
{
	sf::Time elapsed1 = clock.getElapsedTime();
	ss.str("");
	sec = int(elapsed1.asSeconds());
	hour = sec / 3600;
	min = (sec - (hour * 3600)) / 60;
	sec = sec - (hour * 3600 + min * 60);

	if (min < 10)
	{
		ss << "0" << min;
	}
	else
	{
		ss << ":" << min;
	}
	if (sec < 10)
	{
		ss << ":" << "0" << sec;
	}
	else
	{
		ss << ":" << sec;
	}
	timer.setString(ss.str());
}

void Game::transition()
{
	// A tramsition
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
	transitionTexture.loadFromFile("assets/Play.png");
	this->transitionTexture.setSmooth(true);
	transitionImg.setTexture(transitionTexture);
	timer.setFont(font);
	timer.setPosition(1386, 12);
	timer.setCharacterSize(51);
	timer.setFillColor(sf::Color(87, 87, 87));

	if (gamemodeNum == 1)
	{
		setBaseCards();
		for (int i = 1; i < 17; i++)
		{
			fPositions[i].pos = i;
			fPositions2[i].pos = i;
			if (i == 16)
			{
				fPositions[i].imgTexture.loadFromFile("assets/UnderTheDeck.png");
				fPositions[i].imgTexture.setSmooth(true);
				fPositions[i].img.setTexture(fPositions[i].imgTexture);
				fPositions2[i].imgTexture.loadFromFile("assets/UnderTheDeck.png");
				fPositions2[i].imgTexture.setSmooth(true);
				fPositions2[i].img.setTexture(fPositions[i].imgTexture);

			}
			else
			{
				fPositions[i].imgTexture.loadFromFile("assets/PositionsA.png");
				fPositions[i].imgTexture.setSmooth(true);
				fPositions[i].img.setTexture(fPositions[i].imgTexture);
				fPositions2[i].imgTexture.loadFromFile("assets/PositionsA.png");
				fPositions2[i].imgTexture.setSmooth(true);
				fPositions2[i].img.setTexture(fPositions[i].imgTexture);
			}
			switch (fPositions[i].pos)
			{
			case 1:
				fPositions[i].img.setPosition(414, 60);
				fPositions[i].x = 414;
				fPositions[i].y = 60;
				fPositions2[i].img.setPosition(414, 60);
				fPositions2[i].x = 414;
				fPositions2[i].y = 60;
				break;
			case 2:
				fPositions[i].img.setPosition(576, 60);
				fPositions[i].x = 576;
				fPositions[i].y = 60;
				fPositions2[i].img.setPosition(576, 60);
				fPositions2[i].x = 576;
				fPositions2[i].y = 60;
				break;
			case 3:
				fPositions[i].img.setPosition(738, 60);
				fPositions[i].x = 738;
				fPositions[i].y = 60;
				fPositions2[i].img.setPosition(738, 60);
				fPositions2[i].x = 738;
				fPositions2[i].y = 60;
				break;
			case 4:
				fPositions[i].img.setPosition(906, 60);
				fPositions[i].x = 906;
				fPositions[i].y = 60;
				fPositions2[i].img.setPosition(906, 60);
				fPositions2[i].x = 906;
				fPositions2[i].y = 60;
				break;
			case 5:
				fPositions[i].img.setPosition(1068, 60);
				fPositions[i].x = 1068;
				fPositions[i].y = 60;
				fPositions2[i].img.setPosition(1068, 60);
				fPositions2[i].x = 1068;
				fPositions2[i].y = 60;
				break;
			case 6:
				fPositions[i].img.setPosition(496, 207);
				fPositions[i].x = 496;
				fPositions[i].y = 207;
				fPositions2[i].img.setPosition(496, 207);
				fPositions2[i].x = 496;
				fPositions2[i].y = 207;
				break;
			case 7:
				fPositions[i].img.setPosition(659, 207);
				fPositions[i].x = 659;
				fPositions[i].y = 207;
				fPositions2[i].img.setPosition(659, 207);
				fPositions2[i].x = 659;
				fPositions2[i].y = 207;
				break;
			case 8:
				fPositions[i].img.setPosition(822, 207);
				fPositions[i].x = 822;
				fPositions[i].y = 207;
				fPositions2[i].img.setPosition(822, 207);
				fPositions2[i].x = 822;
				fPositions2[i].y = 207;
				break;
			case 9:
				fPositions[i].img.setPosition(985, 207);
				fPositions[i].x = 985;
				fPositions[i].y = 207;
				fPositions2[i].img.setPosition(985, 207);
				fPositions2[i].x = 985;
				fPositions2[i].y = 207;
				break;
			case 10:
				fPositions[i].img.setPosition(576, 355);
				fPositions[i].x = 576;
				fPositions[i].y = 355;
				fPositions2[i].img.setPosition(576, 355);
				fPositions2[i].x = 576;
				fPositions2[i].y = 355;
				break;
			case 11:
				fPositions[i].img.setPosition(738, 355);
				fPositions[i].x = 738;
				fPositions[i].y = 355;
				fPositions2[i].img.setPosition(738, 355);
				fPositions2[i].x = 738;
				fPositions2[i].y = 355;
				break;
			case 12:
				fPositions[i].img.setPosition(907, 355);
				fPositions[i].x = 907;
				fPositions[i].y = 355;
				fPositions2[i].img.setPosition(907, 355);
				fPositions2[i].x = 907;
				fPositions2[i].y = 355;
				break;
			case 13:
				fPositions[i].img.setPosition(660, 511);
				fPositions[i].x = 660;
				fPositions[i].y = 511;
				fPositions2[i].img.setPosition(660, 511);
				fPositions2[i].x = 660;
				fPositions2[i].y = 511;
				break;
			case 14:
				fPositions[i].img.setPosition(822, 511);
				fPositions[i].x = 822;
				fPositions[i].y = 511;
				fPositions2[i].img.setPosition(822, 511);
				fPositions2[i].x = 822;
				fPositions2[i].y = 511;
				break;
			case 15:
				fPositions[i].img.setPosition(738, 608);
				fPositions[i].x = 738;
				fPositions[i].y = 608;
				fPositions2[i].img.setPosition(738, 608);
				fPositions2[i].x = 738;
				fPositions2[i].y = 608;
				break;
			case 16:
				fPositions[i].img.setPosition(1313, 576);
				fPositions[i].x = 1313;
				fPositions[i].y = 576;
				fPositions2[i].img.setPosition(1313, 576);
				fPositions2[i].x = 1313;
				fPositions2[i].y = 576;
				break;
			}
		}
	}

	setDeck();
	sortDeck();
	clock.restart();
}

void Game::setReady()
{
	this->window->setPosition(sf::Vector2i(190, 80));
	font.loadFromFile("assets/tex-gyre-adventor.bold.otf");
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
				setTimer();
				if (win != 0)
				{
					std::cout << "Player " << win << " won!" << std::endl;
					ready = 0;
					gameMode = 1;
				}
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
					this->window->draw(timer);
					this->window->draw(this->player1Text);
					this->window->draw(baseCards[0].BaseCardImg);
					this->window->draw(baseCards[1].BaseCardImg);
					this->window->draw(baseCards[2].BaseCardImg);
					this->window->draw(baseCards[3].BaseCardImg);
					this->window->draw(baseCards[4].BaseCardImg);
					this->window->draw(baseCards[5].BaseCardImg);
					tableOfTruth();
					setCardImages(cursorpos);
					if (showA == 1)
					{
						placingCardsPos();
					}
					for (int i = 1; i < counterCards2; i++)
					{
						if (deck[i].drag == 1)
						{
							this->window->draw(deck[i].img);
						}
					}
					this->window->display();
					update(*this->window);
					if (roundPlayed)
					{
						roundPlayed = 0;
						counter++;
						// transition();
					}
				}
				else if (counter == 2) // Player 2 round
				{
					for (cardGet; player2Cards <= 5; player2Cards++, cardGet++)
					{
						deck[cardGet].player = 2;
					}
					cardsInHand();




					this->window->clear();
					this->window->draw(this->backgroundSprite);
					this->window->draw(timer);
					this->window->draw(this->player2Text);
					this->window->draw(baseCards2[0].BaseCardImg);
					this->window->draw(baseCards2[1].BaseCardImg);
					this->window->draw(baseCards2[2].BaseCardImg);
					this->window->draw(baseCards2[3].BaseCardImg);
					this->window->draw(baseCards2[4].BaseCardImg);
					this->window->draw(baseCards2[5].BaseCardImg);
					tableOfTruth();
					setCardImages(cursorpos);
					if (showA2 == 1)
					{
						placingCardsPos();
					}
					for (int i = 1; i < counterCards2; i++)
					{
						if (deck[i].drag == 1)
						{
							this->window->draw(deck[i].img);
						}
					}
					this->window->display();
					update(*this->window);
					if (roundPlayed)
					{
						roundPlayed = 0;
						counter++;
					}
				}
				else
				{
					counter = 1;
					// transition();
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
		else if (rules) // Rules
		{
			pollEvents();
			rulestab(*this->window);
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
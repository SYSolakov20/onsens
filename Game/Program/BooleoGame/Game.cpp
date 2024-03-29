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
			localOut();
			this->window->close();
			break;

		case sf::Event::KeyPressed:
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				if (ready && !(resume))
				{
					while (true)
					{
						sf::Vector2i cursorpos = sf::Mouse::getPosition(*this->window);
						while (this->window->pollEvent(this->sfmlEvent))
						{
							switch (this->sfmlEvent.type)
							{
							case sf::Event::Closed:
								localOut();
								this->window->close();
								break;

							case sf::Event::KeyPressed:
								if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
								{
									breakPause = 1;
								}
							}
						}
						if (breakPause)
						{
							breakPause = 0;
							break;
						}
						pause = 1;
						pollEvents();
						this->window->clear();
						if (counter == 1)
						{
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
							for (int i = 0; i < 6; i++)
							{
								if (notCardPos[i].cardOnIt == 1)
								{
									notCardPos[i].imgTexture.loadFromFile("assets/PlacedNotCard.png");
									notCardPos[i].img.setTexture(notCardPos[i].imgTexture);
									this->window->draw(notCardPos[i].img);
								}
							}
							setNotCardImages(cursorpos);
							for (int i = 1; i < 16; i++)
							{
								if (fPositions[i].cardOnIt == 1)
								{
									this->window->draw(deck[fPositions[i].cardNum].img);
								}
							}
						}
						else if (counter == 2)
						{
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
							for (int i = 0; i < 6; i++)
							{
								if (notCardPos[i].cardOnIt == 1)
								{
									notCardPos[i].imgTexture.loadFromFile("assets/PlacedNotCard.png");
									notCardPos[i].img.setTexture(notCardPos[i].imgTexture);
									this->window->draw(notCardPos[i].img);
								}
							}
							tableOfTruth();
							setNotCardImages(cursorpos);
							for (int i = 1; i < 16; i++)
							{
								if (fPositions2[i].cardOnIt == 1)
								{
									this->window->draw(deck[fPositions2[i].cardNum].img);
								}
							}
						}
						if (getMousePos(567, 210, 13, *this->window))
						{
							pauseTexture.loadFromFile("assets/PauseHover1.png");
							pauseImg.setTexture(pauseTexture);
							if (cosmosTheme)
							{
								pauseTexture.loadFromFile("assets/cosmos/PauseHover1.png");
								pauseImg.setTexture(pauseTexture);
							}
							if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
							{
								if (!pressed0)
								{
									if (soundOn) clickSound.play();
									pressed0 = true;
									pause = 0;
									break;
								}
							}
							else
							{
								pressed0 = false;
							}
						}
						else if (getMousePos(567, 352, 13, *this->window))
						{
							pauseTexture.loadFromFile("assets/PauseHover2.png");
							pauseImg.setTexture(pauseTexture);
							if (cosmosTheme)
							{
								pauseTexture.loadFromFile("assets/cosmos/PauseHover2.png");
								pauseImg.setTexture(pauseTexture);
							}
							if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
							{
								if (!pressed3)
								{
									if (soundOn) clickSound.play();
									ready = 0;
									gameMode = 0;
									rules = 0;
									pressed3 = true;
									pause = 0;
									break;
								}
							}
							else
							{
								pressed3 = false;
							}
						}
						else if (getMousePos(567, 496, 13, *this->window))
						{
							pauseTexture.loadFromFile("assets/PauseHover3.png");
							pauseImg.setTexture(pauseTexture);
							if (cosmosTheme)
							{
								pauseTexture.loadFromFile("assets/cosmos/PauseHover3.png");
								pauseImg.setTexture(pauseTexture);
							}
							if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
							{
								if (!pressed0)
								{
									if (soundOn) clickSound.play();
									if (gamemodeNum == 1 || gamemodeNum == 2)
									{
										pressed0 = true;
										counter = 1;
										pause = 0;
										deckI = 1;
										cardGet = 1;
										counterCards = 1;
										counterCards2 = 49;
										counterCards3 = 48;
										player1Cards = 0;
										player2Cards = 0;
										win = 0;
										showA = 0;
										showA2 = 0;
										roundPlayed = 0;
										card1Dragging = 0;
										card2Dragging = 0;
										card3Dragging = 0;
										card4Dragging = 0;
										card5Dragging = 0;
										card1Dragging2 = 0;
										card2Dragging2 = 0;
										card3Dragging2 = 0;
										card4Dragging2 = 0;
										card5Dragging2 = 0;
										player1Pos1 = 0;
										player1Pos2 = 0;
										player1Pos3 = 0;
										player1Pos4 = 0;
										player1Pos5 = 0;
										player2Pos1 = 0;
										player2Pos2 = 0;
										player2Pos3 = 0;
										player2Pos4 = 0;
										player2Pos5 = 0;
										for (int i = 0; i < 100; i++)
										{
											startDeck[i].num = 0;
											startDeck[i].value = 0;
											startDeck[i].type = 0;
											startDeck[i].display1 = 0;
											startDeck[i].display2 = 0;
											startDeck[i].player = 0;
											startDeck[i].secondNum = 0;
											startDeck[i].player1pos = 0;
											startDeck[i].player2pos = 0;
											startDeck[i].x = 0;
											startDeck[i].y = 0;
											startDeck[i].drag = 0;
											startDeck[i].placed = 0;
										}
										for (int i = 0; i < 150; i++)
										{
											deck[i].num = 0;
											deck[i].value = 0;
											deck[i].type = 0;
											deck[i].display1 = 0;
											deck[i].display2 = 0;
											deck[i].player = 0;
											deck[i].secondNum = 0;
											deck[i].player1pos = 0;
											deck[i].player2pos = 0;
											deck[i].x = 0;
											deck[i].y = 0;
											deck[i].drag = 0;
											deck[i].placed = 0;
										}
										for (int i = 0; i < 16; i++)
										{
											fPositions[i].cardNum = 0;
											fPositions[i].cardValue = 0;
											fPositions[i].showPos = 0;
											fPositions[i].cardOnIt = 0;
											fPositions[i].pos = 0;
											fPositions2[i].cardNum = 0;
											fPositions2[i].cardValue = 0;
											fPositions2[i].showPos = 0;
											fPositions2[i].cardOnIt = 0;
											fPositions2[i].pos = 0;
										}
										if (gamemodeNum == 1)
										{
											firstGamemode2 = 1;
										}
										else
										{
											firstGamemode1 = 1;
										}
										firstGamemode3 = 1;
										firstGamemode4 = 1;
										setPlacingCards();
										setDeck();
										setBaseCards();
										sortDeck();
										clock.restart();
										break;
									}
									else if (gamemodeNum == 3 || gamemodeNum == 4)
									{
										pressed0 = true;
										counter = 1;
										pause = 0;
										deckI = 1;
										cardGet = 1;
										counterCards = 1;
										counterCards2 = 49;
										counterCards3 = 48;
										player1Cards = 0;
										player2Cards = 0;
										win = 0;
										showA = 0;
										showA2 = 0;
										roundPlayed = 0;
										card1Dragging = 0;
										card2Dragging = 0;
										card3Dragging = 0;
										card4Dragging = 0;
										card5Dragging = 0;
										card1Dragging2 = 0;
										card2Dragging2 = 0;
										card3Dragging2 = 0;
										card4Dragging2 = 0;
										card5Dragging2 = 0;
										player1Pos1 = 0;
										player1Pos2 = 0;
										player1Pos3 = 0;
										player1Pos4 = 0;
										player1Pos5 = 0;
										player2Pos1 = 0;
										player2Pos2 = 0;
										player2Pos3 = 0;
										player2Pos4 = 0;
										player2Pos5 = 0;
										for (int i = 0; i < 100; i++)
										{
											startDeck[i].num = 0;
											startDeck[i].value = 0;
											startDeck[i].type = 0;
											startDeck[i].display1 = 0;
											startDeck[i].display2 = 0;
											startDeck[i].player = 0;
											startDeck[i].secondNum = 0;
											startDeck[i].player1pos = 0;
											startDeck[i].player2pos = 0;
											startDeck[i].x = 0;
											startDeck[i].y = 0;
											startDeck[i].drag = 0;
											startDeck[i].placed = 0;
										}
										for (int i = 0; i < 150; i++)
										{
											deck[i].num = 0;
											deck[i].value = 0;
											deck[i].type = 0;
											deck[i].display1 = 0;
											deck[i].display2 = 0;
											deck[i].player = 0;
											deck[i].secondNum = 0;
											deck[i].player1pos = 0;
											deck[i].player2pos = 0;
											deck[i].x = 0;
											deck[i].y = 0;
											deck[i].drag = 0;
											deck[i].placed = 0;
										}
										for (int i = 0; i < 16; i++)
										{
											fPositions[i].cardNum = 0;
											fPositions[i].cardValue = 0;
											fPositions[i].showPos = 0;
											fPositions[i].cardOnIt = 0;
											fPositions[i].pos = 0;
											fPositions2[i].cardNum = 0;
											fPositions2[i].cardValue = 0;
											fPositions2[i].showPos = 0;
											fPositions2[i].cardOnIt = 0;
											fPositions2[i].pos = 0;
										}
										for (int i = 0; i < 6; i++)
										{
											notCardPos[i].cardNum = 0;
											notCardPos[i].cardValue = 0;
											notCardPos[i].showPos = 0;
											notCardPos[i].cardOnIt = 0;
										}
										if (gamemodeNum == 3)
										{
											firstGamemode4 = 1;
										}
										else
										{
											firstGamemode3 = 1;
										}
										firstGamemode1 = 1;
										firstGamemode2 = 1;
										setPlacingCards();
										setNotDeck();
										setBaseCards();
										sortNotDeck();
										for (int i = 0; i < 6; i++)
										{
											notCardPos[i].imgTexture.loadFromFile("assets/NotCardPos.png");
											notCardPos[i].imgTexture.setSmooth(true);
											notCardPos[i].img.setTexture(notCardPos[i].imgTexture);
											switch (notCardPos[i].pos)
											{
											case 0:
												notCardPos[i].img.setPosition(322, -13);
												notCardPos[i].x = 322;
												notCardPos[i].y = -13;
												break;
											case 1:
												notCardPos[i].img.setPosition(485, -13);
												notCardPos[i].x = 485;
												notCardPos[i].y = -13;
												break;
											case 2:
												notCardPos[i].img.setPosition(648, -13);
												notCardPos[i].x = 648;
												notCardPos[i].y = -13;
												break;
											case 3:
												notCardPos[i].img.setPosition(811, -13);
												notCardPos[i].x = 811;
												notCardPos[i].y = -13;
												break;
											case 4:
												notCardPos[i].img.setPosition(974, -13);
												notCardPos[i].x = 974;
												notCardPos[i].y = -13;
												break;
											case 5:
												notCardPos[i].img.setPosition(1135, -13);
												notCardPos[i].x = 1135;
												notCardPos[i].y = -13;
												break;
											}
										}
										clock.restart();
										break;
									}
								}
							}
							else
							{
								pressed0 = false;
							}
						}
						else
						{
							pauseTexture.loadFromFile("assets/PauseScreen.png");
							pauseImg.setTexture(pauseTexture);
							if (cosmosTheme)
							{
								pauseTexture.loadFromFile("assets/cosmos/PauseScreen.png");
								pauseImg.setTexture(pauseTexture);
							}
						}
						this->window->draw(pauseImg);
						this->window->display();
					}
				}
				else if (resume)
				{
				breakResume = 1;
				resume = 0;
				ready = 0;
				gameMode = 1;
				}
				else if (gameMode)
				{
					gameMode = 0;
				}
				else if (options)
				{
					options = 0;
				}
				else if (rules)
				{
					rules = 0;
					nextPage = -1;
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
	if (cosmosTheme)
	{
		this->backgroundTexture.loadFromFile("assets/cosmos/Menu.png");
		this->backgroundSprite.setTexture(backgroundTexture);
	}
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


bool Game::getMousePos(int x, int y, int a, sf::Window& newWindow)
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
	case 9: 
		if ((mousepos.x + 8 >= x && mousepos.x + 8 <= x + 348) && (mousepos.y + 8 >= y && mousepos.y + 8 <= y + 92))
		{
			return 1;
		}
		break;
	case 10:
		if ((mousepos.x + 8 >= x && mousepos.x + 8 <= x + 1400) && (mousepos.y + 8 >= y && mousepos.y + 8 <= y + 1000))
		{
			return 1;
		}
		break;
	case 11:
		if ((mousepos.x + 8 >= x && mousepos.x + 8 <= x + 114) && (mousepos.y + 8 >= y && mousepos.y + 8 <= y + 82))
		{
			return 1;
		}
		break;
	case 12:
		if ((mousepos.x + 8 >= x && mousepos.x + 8 <= x + 364) && (mousepos.y + 8 >= y && mousepos.y + 8 <= y + 96))
		{
			return 1;
		}
		break;
	case 13:
		if ((mousepos.x + 8 >= x && mousepos.x + 8 <= x + 412) && (mousepos.y + 8 >= y && mousepos.y + 8 <= y + 109))
		{
			return 1;
		}
		break;
	case 14:
		if ((mousepos.x + 8 >= x && mousepos.x + 8 <= x + 427) && (mousepos.y + 8 >= y && mousepos.y + 8 <= y + 87))
		{
			return 1;
		}
		break;
	case 15:
		if ((mousepos.x + 8 >= x && mousepos.x + 8 <= x + 620) && (mousepos.y + 8 >= y && mousepos.y + 8 <= y + 104))
		{
			return 1;
		}
		break;
	case 16:
		if ((mousepos.x + 8 >= x && mousepos.x + 8 <= x + 150) && (mousepos.y + 8 >= y && mousepos.y + 8 <= y + 82))
		{
			return 1;
		}
		break;
	case 17:
		if ((mousepos.x + 8 >= x && mousepos.x + 8 <= x + 160) && (mousepos.y + 8 >= y && mousepos.y + 8 <= y + 47))
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
		if (cosmosTheme)
		{
			this->backgroundTexture.loadFromFile("assets/cosmos/HoverPlay.png");
			this->backgroundSprite.setTexture(backgroundTexture);
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (!pressed)
			{
				if(soundOn) clickSound.play();
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
		if (cosmosTheme)
		{
			this->backgroundTexture.loadFromFile("assets/cosmos/HoverOptions.png");
			this->backgroundSprite.setTexture(backgroundTexture);
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (!pressed3)
			{
				if (soundOn) clickSound.play();
				options = 1;
				pressed3 = true;
			}
		}
		else
		{
			pressed3 = false;
		}
	}
	else if (getMousePos(625, 516, 1, newWindow)) // Button Rules
	{
		this->backgroundTexture.loadFromFile("assets/HoverRules.png");
		this->backgroundSprite.setTexture(backgroundTexture);
		if (cosmosTheme)
		{
			this->backgroundTexture.loadFromFile("assets/cosmos/HoverRules.png");
			this->backgroundSprite.setTexture(backgroundTexture);
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (!pressed24)
			{
				if (soundOn) clickSound.play();
				rules = 1;
				pressed24 = true;
			}
		}
		else
		{
			pressed24 = false;
		}
	}
	else if (getMousePos(625, 620, 1, newWindow)) // Button Quit
	{
		this->backgroundTexture.loadFromFile("assets/HoverQuit.png");
		this->backgroundSprite.setTexture(backgroundTexture);
		if (cosmosTheme)
		{
			this->backgroundTexture.loadFromFile("assets/cosmos/HoverQuit.png");
			this->backgroundSprite.setTexture(backgroundTexture);
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (soundOn) clickSound.play();
			localOut();
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
		if (cosmosTheme)
		{
			this->backgroundTexture.loadFromFile("assets/cosmos/HoverMode1.png");
			this->backgroundSprite.setTexture(backgroundTexture);
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (!pressed)
			{
				if (soundOn) clickSound.play();
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
		if (cosmosTheme)
		{
			this->backgroundTexture.loadFromFile("assets/cosmos/HoverMode2.png");
			this->backgroundSprite.setTexture(backgroundTexture);
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (!pressed)
			{
				if (soundOn) clickSound.play();
				ready = 1;
				gamemodeNum = 2;
				setPlay();
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
		if (cosmosTheme)
		{
			this->backgroundTexture.loadFromFile("assets/cosmos/HoverMode3.png");
			this->backgroundSprite.setTexture(backgroundTexture);
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (!pressed)
			{
				if (soundOn) clickSound.play();
				ready = 1;
				gamemodeNum = 3;
				setPlay();
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
		if (cosmosTheme)
		{
			this->backgroundTexture.loadFromFile("assets/cosmos/HoverMode4.png");
			this->backgroundSprite.setTexture(backgroundTexture);
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (!pressed)
			{
				if (soundOn) clickSound.play();
				ready = 1;
				gamemodeNum = 4;
				setPlay();
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
		if (cosmosTheme)
		{
			this->backgroundTexture.loadFromFile("assets/cosmos/GameMode.png");
			this->backgroundSprite.setTexture(backgroundTexture);
		}
	}


	this->window->draw(this->backgroundSprite);
	this->window->display();
}

void Game::optionsMenu(sf::Window& newWindow)
{
	std::string web = "start https://sysolakov20.github.io/onsens/";
	pollEvents();
	this->window->clear();
	this->backgroundTexture.loadFromFile("assets/OptionsBackground.png");
	this->backgroundSprite.setTexture(backgroundTexture);
	if (cosmosTheme)
	{
		this->backgroundTexture.loadFromFile("assets/cosmos/OptionsBackground.png");
		this->backgroundSprite.setTexture(backgroundTexture);
	}

	if (getMousePos(557, 765, 14, *this->window))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (!pressed5)
			{
				if (soundOn) clickSound.play();
				system(web.c_str()); 
				pressed5 = true;
			}
		}
		else
		{
			pressed5 = false;
		}
	}
	if (getMousePos(1405, 42, 8, *this->window))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (!pressed5)
			{
				if (soundOn) clickSound.play();
				options = 0;
				pressed5 = true;
			}
		}
		else
		{
			pressed5 = false;
		}
	}
	if (getMousePos(463, 239, 15, *this->window))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (!pressed5)
			{
				pressed5 = true;
				if (soundOn == 1) clickSound.play();
				musicOn = !musicOn;
				if (musicOn == 1)
				{
					musicTexture.loadFromFile("assets/MusicIcon1.png");
					musicImg.setTexture(musicTexture);
				}
				else
				{
					musicTexture.loadFromFile("assets/MusicIcon2.png");
					musicImg.setTexture(musicTexture);
				}
			}
		}
		else
		{
			pressed5 = false;
		}
	}
	if (getMousePos(463, 394, 15, *this->window))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (!pressed3)
			{
				pressed3 = true;
				soundOn = !soundOn;
				if (soundOn == 1)
				{
					clickSound.play();
					soundTexture.loadFromFile("assets/SoundIcon1.png");
					soundImg.setTexture(soundTexture);
				}
				else
				{
					soundTexture.loadFromFile("assets/SoundIcon2.png");
					soundImg.setTexture(soundTexture);
				}	
			}
		}
		else
		{
			pressed3 = false;
		}
	}
	if (getMousePos(463, 549, 15, *this->window))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (!pressed5)
			{
				if (soundOn) clickSound.play();
				specialCounter++;
				pressed5 = true;
				if (specialCounter == 6)
				{
					specialCounter = 0;
				}
			}
		}
		else
		{
			pressed5 = false;
		}
	}
	switch (specialCounter)
	{
	case 0:
		cosmosTheme = 0;
		specialButtonC = 0;
		specialButtonTexture.loadFromFile("assets/SpecialButton1.png");
		specialButtonImg.setTexture(specialButtonTexture);
		break;
	case 1:
		cosmosTheme = 0;
		if (winGamemode1 != 0)
		{
			specialButtonC = 1;
			specialButtonTexture.loadFromFile("assets/SpecialButton2.png");
			specialButtonImg.setTexture(specialButtonTexture);
		}
		else
		{

			specialButtonC = 0;
			specialButtonTexture.loadFromFile("assets/SpecialButtonN1.png");
			specialButtonImg.setTexture(specialButtonTexture);
		}
		break;
	case 2:
		cosmosTheme = 0;
		if (winGamemode2 != 0)
		{
			specialButtonC = 2;
			specialButtonTexture.loadFromFile("assets/SpecialButton3.png");
			specialButtonImg.setTexture(specialButtonTexture);
		}
		else
		{

			specialButtonC = 0;
			specialButtonTexture.loadFromFile("assets/SpecialButtonN2.png");
			specialButtonImg.setTexture(specialButtonTexture);
		}
		break;
	case 3:
		cosmosTheme = 0;
		if (winGamemode3 != 0)
		{
			specialButtonC = 3;
			specialButtonTexture.loadFromFile("assets/SpecialButton4.png");
			specialButtonImg.setTexture(specialButtonTexture);
		}
		else
		{

			specialButtonC = 0;
			specialButtonTexture.loadFromFile("assets/SpecialButtonN3.png");
			specialButtonImg.setTexture(specialButtonTexture);
		}
		break;
	case 4:
		cosmosTheme = 0;
		if (winGamemode4 != 0)
		{
			specialButtonC = 4;
			specialButtonTexture.loadFromFile("assets/SpecialButton5.png");
			specialButtonImg.setTexture(specialButtonTexture);
		}
		else
		{

			specialButtonC = 0;
			specialButtonTexture.loadFromFile("assets/SpecialButtonN4.png");
			specialButtonImg.setTexture(specialButtonTexture);
		}
		break;
	case 5:
		if (winGamemode1 != 0 && winGamemode2 != 0 && winGamemode3 != 0 && winGamemode4 != 0)
		{
			specialButtonC = 5;
			cosmosTheme = 1;
			specialButtonTexture.loadFromFile("assets/SpecialButton6.png");
			specialButtonImg.setTexture(specialButtonTexture);
		}
		else
		{
			cosmosTheme = 0;
			specialButtonC = 0;
			specialButtonTexture.loadFromFile("assets/SpecialButtonN5.png");
			specialButtonImg.setTexture(specialButtonTexture);
		}
		break;
	}
	this->window->draw(this->backgroundSprite);
	this->window->draw(specialButtonImg);
	this->window->draw(musicImg);
	this->window->draw(soundImg);
	this->window->display();
}

void Game::rulestab(sf::Window& newWindow)
{
	this->window->clear();
	if (nextPage == -1)
	{
		this->backgroundTexture.loadFromFile("assets/RulesPage1.png");
		this->backgroundSprite.setTexture(backgroundTexture);
		if (cosmosTheme)
		{
			this->backgroundTexture.loadFromFile("assets/cosmos/RulesPage1.png");
			this->backgroundSprite.setTexture(backgroundTexture);
		}
		if (getMousePos(1419, 371, 8, *this->window))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (!pressed5)
				{
					if (soundOn) clickSound.play();
					this->backgroundTexture.loadFromFile("assets/RulesPage2.png");
					this->backgroundSprite.setTexture(backgroundTexture);
					if (cosmosTheme)
					{
						this->backgroundTexture.loadFromFile("assets/cosmos/RulesPage2.png");
						this->backgroundSprite.setTexture(backgroundTexture);
					}
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
					if (soundOn) clickSound.play();
					this->backgroundTexture.loadFromFile("assets/RulesPage3.png");
					this->backgroundSprite.setTexture(backgroundTexture);
					if (cosmosTheme)
					{
						this->backgroundTexture.loadFromFile("assets/cosmos/RulesPage3.png");
						this->backgroundSprite.setTexture(backgroundTexture);
					}
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
					if (soundOn) clickSound.play();
					this->backgroundTexture.loadFromFile("assets/RulesPage1.png");
					this->backgroundSprite.setTexture(backgroundTexture);
					if (cosmosTheme)
					{
						this->backgroundTexture.loadFromFile("assets/cosmos/RulesPage1.png");
						this->backgroundSprite.setTexture(backgroundTexture);
					}
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
					if (soundOn) clickSound.play();
					this->backgroundTexture.loadFromFile("assets/RulesPage4.png");
					this->backgroundSprite.setTexture(backgroundTexture);
					if (cosmosTheme)
					{
						this->backgroundTexture.loadFromFile("assets/cosmos/RulesPage4.png");
						this->backgroundSprite.setTexture(backgroundTexture);
					}
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
					if (soundOn) clickSound.play();
					this->backgroundTexture.loadFromFile("assets/RulesPage2.png");
					this->backgroundSprite.setTexture(backgroundTexture);
					if (cosmosTheme)
					{
						this->backgroundTexture.loadFromFile("assets/cosmos/RulesPage2.png");
						this->backgroundSprite.setTexture(backgroundTexture);
					}
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
					if (soundOn) clickSound.play();
					this->backgroundTexture.loadFromFile("assets/RulesPage5.png");
					this->backgroundSprite.setTexture(backgroundTexture);
					if (cosmosTheme)
					{
						this->backgroundTexture.loadFromFile("assets/cosmos/RulesPage5.png");
						this->backgroundSprite.setTexture(backgroundTexture);
					}
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
					if (soundOn) clickSound.play();
					this->backgroundTexture.loadFromFile("assets/RulesPage3.png");
					this->backgroundSprite.setTexture(backgroundTexture);
					if (cosmosTheme)
					{
						this->backgroundTexture.loadFromFile("assets/cosmos/RulesPage3.png");
						this->backgroundSprite.setTexture(backgroundTexture);
					}
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
					if (soundOn) clickSound.play();
					this->backgroundTexture.loadFromFile("assets/RulesPage6.png");
					this->backgroundSprite.setTexture(backgroundTexture);
					if (cosmosTheme)
					{
						this->backgroundTexture.loadFromFile("assets/cosmos/RulesPage6.png");
						this->backgroundSprite.setTexture(backgroundTexture);
					}
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
					if (soundOn) clickSound.play();
					this->backgroundTexture.loadFromFile("assets/RulesPage4.png");
					this->backgroundSprite.setTexture(backgroundTexture);
					if (cosmosTheme)
					{
						this->backgroundTexture.loadFromFile("assets/cosmos/RulesPage4.png");
						this->backgroundSprite.setTexture(backgroundTexture);
					}
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
					if (soundOn) clickSound.play();
					this->backgroundTexture.loadFromFile("assets/RulesPage7.png");
					this->backgroundSprite.setTexture(backgroundTexture);
					if (cosmosTheme)
					{
						this->backgroundTexture.loadFromFile("assets/cosmos/RulesPage7.png");
						this->backgroundSprite.setTexture(backgroundTexture);
					}
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
					if (soundOn) clickSound.play();
					this->backgroundTexture.loadFromFile("assets/RulesPage5.png");
					this->backgroundSprite.setTexture(backgroundTexture);
					if (cosmosTheme)
					{
						this->backgroundTexture.loadFromFile("assets/cosmos/RulesPage5.png");
						this->backgroundSprite.setTexture(backgroundTexture);
					}
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
					if (soundOn) clickSound.play();
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
					if (soundOn) clickSound.play();
					this->backgroundTexture.loadFromFile("assets/RulesPage6.png");
					this->backgroundSprite.setTexture(backgroundTexture);
					if (cosmosTheme)
					{
						this->backgroundTexture.loadFromFile("assets/cosmos/RulesPage6.png");
						this->backgroundSprite.setTexture(backgroundTexture);
					}
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
		if (cosmosTheme)
		{
			this->backgroundTexture.loadFromFile("assets/cosmos/RulesPage1.png");
			this->backgroundSprite.setTexture(backgroundTexture);
		}
	}
	this->window->draw(this->backgroundSprite);
	this->window->display();
}


void Game::winScreen(sf::Window& newWindow)
{
	if (win == 1)
	{
		this->backgroundTexture.loadFromFile("assets/Player1WinScreen.png");
		this->backgroundSprite.setTexture(backgroundTexture);
		if (cosmosTheme)
		{
			this->backgroundTexture.loadFromFile("assets/cosmos/Player1WinScreen.png");
			this->backgroundSprite.setTexture(backgroundTexture);
		}
		if (getMousePos(598, 506, 9, *this->window))
		{
			if (cosmosTheme)
			{
				this->backgroundTexture.loadFromFile("assets/cosmos/Player1WinScreenHover.png");
				this->backgroundSprite.setTexture(backgroundTexture);
			}
			this->backgroundTexture.loadFromFile("assets/Player1WinScreenHover.png");
			this->backgroundSprite.setTexture(backgroundTexture);
		}
	}
	else
	{
		this->backgroundTexture.loadFromFile("assets/Player2WinScreen.png");
		this->backgroundSprite.setTexture(backgroundTexture);
		if (cosmosTheme)
		{
			this->backgroundTexture.loadFromFile("assets/cosmos/Player2WinScreen.png");
			this->backgroundSprite.setTexture(backgroundTexture);
		}
		if (getMousePos(598, 506, 9, *this->window))
		{
			this->backgroundTexture.loadFromFile("assets/Player2WinScreenHover.png");
			this->backgroundSprite.setTexture(backgroundTexture);
			if (cosmosTheme)
			{
				this->backgroundTexture.loadFromFile("assets/cosmos/Player2WinScreenHover.png");
				this->backgroundSprite.setTexture(backgroundTexture);
			}
		}
	}
	if (getMousePos(598, 506, 9, *this->window))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (!pressed24)
			{
				if (soundOn) clickSound.play();
				win = 0;
				gameMode = 0;
				rules = 0;
				pressed24 = true;
			}
		}
		else
		{
			pressed24 = false;
		}
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

void Game::setNotDeck()
{
	int numCounter = 1;

	startDeck[0].num = 0;
	for (int i = 1; i < 57; i++)
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
		else if (i <= 56)
		{
			startDeck[i].type = 'n';
			startDeck[i].value = 3;
			startDeck[i].num = numCounter;
		}
		numCounter++;
	}
}

void Game::sortNotDeck()
{
	srand((unsigned)time(0));

	while (deckI < 57)
	{
		temp = rand() % 56 + 1;
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
				if (player1Pos1 == i && !(card2Dragging || card3Dragging || card4Dragging || card5Dragging) && !(roundPlayed))  // Display and drag The first card
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
												deck[i].type = 0;
												deck[i].value = 0;
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
													deck[i].type = 0;
													deck[i].value = 0;
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
					}
					else
					{
						showA = 0;
						deck[i].img.setRotation(90.f);
					}
					if (getMousePos(200, 0, 10, *this->window))
					{
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
				}
				else if (player1Pos2 == i && !(card1Dragging || card3Dragging || card4Dragging || card5Dragging) && !(roundPlayed)) // Display and drag The second card
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
												deck[i].type = 0;
												deck[i].value = 0;
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
													deck[i].type = 0;
													deck[i].value = 0;
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
					if (getMousePos(200, 0, 10, *this->window))
					{
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
				}
				else if (player1Pos3 == i && !(card1Dragging || card2Dragging || card4Dragging || card5Dragging) && !(roundPlayed)) // Display and drag The third card
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
												deck[i].type = 0;
												deck[i].value = 0;
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
													deck[i].type = 0;
													deck[i].value = 0;
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
					if (getMousePos(200, 0, 10, *this->window))
					{
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
				}
				else if (player1Pos4 == i && !(card1Dragging || card2Dragging || card3Dragging || card5Dragging) && !(roundPlayed)) // Display and drag The fourth card
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
												deck[i].type = 0;
												deck[i].value = 0;
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
													deck[i].type = 0;
													deck[i].value = 0;
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
					if (getMousePos(200, 0, 10, *this->window))
					{
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
				}
				else if (player1Pos5 == i && !(card1Dragging || card2Dragging || card3Dragging || card4Dragging) && !(roundPlayed)) // Display and drag The fifth card
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
												deck[i].type = 0;
												deck[i].value = 0;
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
													deck[i].type = 0;
													deck[i].value = 0;
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
					if (getMousePos(200, 0, 10, *this->window))
					{
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
				}
				// Displaying by type
			}
			if (deck[i].value == 0 && !(deck[i].num == fPositions[i].cardNum))
			{
				switch (specialButtonC)
				{
				case 0:
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
					break;
				case 1:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				case 2:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				case 3:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				case 4:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				case 5:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				}
			}
			else if (deck[i].value == 0 && (deck[i].num == fPositions[i].cardNum))
			{
				switch (specialButtonC)
				{
				case 0:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 1:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 2:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 3:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 4:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 5:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				}
			}
			else if (deck[i].value == 1 && !(deck[i].num == fPositions[i].cardNum))
			{

				switch (specialButtonC)
				{
				case 0:
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
					break;
				case 1:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				case 2:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				case 3:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				case 4:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				case 5:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				}
			}
			else if (deck[i].value == 1 && (deck[i].num == fPositions[i].cardNum))
			{

				switch (specialButtonC)
				{
				case 0:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 1:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 2:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 3:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 4:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 5:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				}
			}
		}
		else if (deck[i].display2 == 1 && counter == 2)
		{
			if (deck[i].player2pos == 1)
			{
				if (player2Pos1 == i && !(card2Dragging2 || card3Dragging2 || card4Dragging2 || card5Dragging2) && !(roundPlayed))  // Display and drag The first card P2
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
					if (getMousePos(200, 0, 10, *this->window))
					{
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
				}
				else if (player2Pos2 == i && !(card1Dragging2 || card3Dragging2 || card4Dragging2 || card5Dragging2) && !(roundPlayed)) // Display and drag The second card P2
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
					if (getMousePos(200, 0, 10, *this->window))
					{
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
				}
				else if (player2Pos3 == i && !(card1Dragging2 || card2Dragging2 || card4Dragging2 || card5Dragging2) && !(roundPlayed)) // Display and drag The third card P2
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
					if (getMousePos(200, 0, 10, *this->window))
					{
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
				}
				else if (player2Pos4 == i && !(card1Dragging2 || card2Dragging2 || card3Dragging2 || card5Dragging2) && !(roundPlayed)) // Display and drag The fourth card P2
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
					if (getMousePos(200, 0, 10, *this->window))
					{
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
				}
				else if (player2Pos5 == i && !(card1Dragging2 || card2Dragging2 || card3Dragging2 || card4Dragging2) && !(roundPlayed)) // Display and drag The fifth card P2
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
					if (getMousePos(200, 0, 10, *this->window))
					{
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
				}
				// Displaying by type P2
			}
			if (deck[i].value == 0 && !(deck[i].num == fPositions[i].cardNum))
			{
				switch (specialButtonC)
				{
				case 0:
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
					break;
				case 1:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				case 2:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				case 3:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				case 4:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				case 5:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				}
			}
			else if (deck[i].value == 0 && (deck[i].num == fPositions[i].cardNum))
			{
				switch (specialButtonC)
				{
				case 0:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 1:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 2:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 3:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 4:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 5:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				}
			}
			else if (deck[i].value == 1 && !(deck[i].num == fPositions[i].cardNum))
			{

				switch (specialButtonC)
				{
				case 0:
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
					break;
				case 1:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				case 2:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				case 3:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				case 4:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				case 5:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				}
			}
			else if (deck[i].value == 1 && (deck[i].num == fPositions[i].cardNum))
			{

				switch (specialButtonC)
				{
				case 0:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 1:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 2:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 3:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 4:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 5:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				}
			}
		}
	}
}

void Game::setCardImages2(sf::Vector2i cursorpos)
{
	int numCounter = 1;

	for (int i = 1; i <= counterCards3; i++)
	{
		if (deck[i].display2 == 1 && counter == 2)
		{
			
				// Displaying by type P2
			if (deck[i].value == 0 && !(deck[i].num == fPositions[i].cardNum))
			{
				switch (specialButtonC)
				{
				case 0:
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
					break;
				case 1:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				case 2:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				case 3:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				case 4:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				case 5:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				}
			}
			else if (deck[i].value == 0 && (deck[i].num == fPositions[i].cardNum))
			{
				switch (specialButtonC)
				{
				case 0:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 1:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 2:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 3:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 4:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 5:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				}
			}
			else if (deck[i].value == 1 && !(deck[i].num == fPositions[i].cardNum))
			{

				switch (specialButtonC)
				{
				case 0:
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
					break;
				case 1:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				case 2:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				case 3:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				case 4:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				case 5:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				}
			}
			else if (deck[i].value == 1 && (deck[i].num == fPositions[i].cardNum))
			{

				switch (specialButtonC)
				{
				case 0:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 1:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 2:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 3:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 4:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 5:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				}
			}
		}
	}
}

void Game::notCardLogic(int j)
{
	int collapse = 0;
	int collapse2 = 0;
	switch (j)
	{
	case 0:
		if (fPositions[1].cardOnIt == 1)
		{
			if (deck[fPositions[1].cardNum].type == 'a')
			{
				if ((baseCards[0].value && baseCards[1].value) == fPositions[1].cardValue)
				{
					collapse = 0;
				}
				else
				{
					collapse = 1;
				}
			}
			else if (deck[fPositions[1].cardNum].type == 'o')
			{
				if ((baseCards[0].value || baseCards[1].value) == fPositions[1].cardValue)
				{
					collapse = 0;
				}
				else
				{
					collapse = 1;
				}
			}
			else if (deck[fPositions[1].cardNum].type == 'x')
			{
				if ((baseCards[0].value ^ baseCards[1].value) == fPositions[1].cardValue)
				{
					collapse = 0;
				}
				else
				{
					collapse = 1;
				}
			}
			if (collapse == 1)
			{
				collapse = 0;
				deck[counterNotCards3].type = deck[fPositions[1].cardNum].type;
				deck[counterNotCards3].value = deck[fPositions[1].cardNum].value;
				deck[counterNotCards3].num = counterNotCards3;
				deck[fPositions[1].cardNum].placed = 1;
				deck[fPositions[1].cardNum].display1 = 0;
				deck[fPositions[1].cardNum].display2 = 0;
				deck[fPositions[1].cardNum].type = 0;
				deck[fPositions[1].cardNum].value = 0;
				deck[fPositions[1].cardNum].num = 0;
				counterNotCards3++;
				fPositions[1].cardOnIt = 0;
				fPositions[1].cardValue = 0;
				fPositions[1].cardNum = 0;

				if (fPositions[6].cardOnIt == 1)
				{
					deck[counterNotCards3].type = deck[fPositions[6].cardNum].type;
					deck[counterNotCards3].value = deck[fPositions[6].cardNum].value;
					deck[counterNotCards3].num = counterNotCards3;
					deck[fPositions[6].cardNum].placed = 1;
					deck[fPositions[6].cardNum].display1 = 0;
					deck[fPositions[6].cardNum].display2 = 0;
					deck[fPositions[6].cardNum].type = 0;
					deck[fPositions[6].cardNum].value = 0;
					deck[fPositions[6].cardNum].num = 0;
					counterNotCards3++;
					fPositions[6].cardOnIt = 0;
					fPositions[6].cardValue = 0;
					fPositions[6].cardNum = 0;

					if (fPositions[10].cardOnIt == 1)
					{
						deck[counterNotCards3].type = deck[fPositions[10].cardNum].type;
						deck[counterNotCards3].value = deck[fPositions[10].cardNum].value;
						deck[counterNotCards3].num = counterNotCards3;
						deck[fPositions[10].cardNum].placed = 1;
						deck[fPositions[10].cardNum].display1 = 0;
						deck[fPositions[10].cardNum].display2 = 0;
						deck[fPositions[10].cardNum].type = 0;
						deck[fPositions[10].cardNum].value = 0;
						deck[fPositions[10].cardNum].num = 0;
						counterNotCards3++;
						fPositions[10].cardOnIt = 0;
						fPositions[10].cardValue = 0;
						fPositions[10].cardNum = 0;

						if (fPositions[13].cardOnIt == 1)
						{
							deck[counterNotCards3].type = deck[fPositions[13].cardNum].type;
							deck[counterNotCards3].value = deck[fPositions[13].cardNum].value;
							deck[counterNotCards3].num = counterNotCards3;
							deck[fPositions[13].cardNum].placed = 1;
							deck[fPositions[13].cardNum].display1 = 0;
							deck[fPositions[13].cardNum].display2 = 0;
							deck[fPositions[13].cardNum].type = 0;
							deck[fPositions[13].cardNum].value = 0;
							deck[fPositions[13].cardNum].num = 0;
							counterNotCards3++;
							fPositions[13].cardOnIt = 0;
							fPositions[13].cardValue = 0;
							fPositions[13].cardNum = 0;

						}
					}
				}
			}
		}
		if (fPositions2[1].cardOnIt == 1)
		{
			if (deck[fPositions2[1].cardNum].type == 'a')
			{
				if ((baseCards2[0].value && baseCards2[1].value) == fPositions2[1].cardValue)
				{
					collapse2 = 0;
				}
				else
				{
					collapse2 = 1;
				}
			}
			else if (deck[fPositions2[1].cardNum].type == 'o')
			{
				if ((baseCards2[0].value || baseCards2[1].value) == fPositions2[1].cardValue)
				{
					collapse2 = 0;
				}
				else
				{
					collapse2 = 1;
				}
			}
			else if (deck[fPositions2[1].cardNum].type == 'x')
			{
				if ((baseCards2[0].value ^ baseCards2[1].value) == fPositions2[1].cardValue)
				{
					collapse2 = 0;
				}
				else
				{
					collapse2 = 1;
				}
			}
			if (collapse2 == 1)
			{
				collapse2 = 0;
				deck[counterNotCards3].type = deck[fPositions2[1].cardNum].type;
				deck[counterNotCards3].value = deck[fPositions2[1].cardNum].value;
				deck[counterNotCards3].num = counterNotCards3;
				deck[fPositions2[1].cardNum].placed = 1;
				deck[fPositions2[1].cardNum].display1 = 0;
				deck[fPositions2[1].cardNum].display2 = 0;
				deck[fPositions2[1].cardNum].type = 0;
				deck[fPositions2[1].cardNum].value = 0;
				deck[fPositions2[1].cardNum].num = 0;
				counterNotCards3++;
				fPositions2[1].cardOnIt = 0;
				fPositions2[1].cardValue = 0;
				fPositions2[1].cardNum = 0;

				if (fPositions2[6].cardOnIt == 1)
				{
					deck[counterNotCards3].type = deck[fPositions2[6].cardNum].type;
					deck[counterNotCards3].value = deck[fPositions2[6].cardNum].value;
					deck[counterNotCards3].num = counterNotCards3;
					deck[fPositions2[6].cardNum].placed = 1;
					deck[fPositions2[6].cardNum].display1 = 0;
					deck[fPositions2[6].cardNum].display2 = 0;
					deck[fPositions2[6].cardNum].type = 0;
					deck[fPositions2[6].cardNum].value = 0;
					deck[fPositions2[6].cardNum].num = 0;
					counterNotCards3++;
					fPositions2[6].cardOnIt = 0;
					fPositions2[6].cardValue = 0;
					fPositions2[6].cardNum = 0;

					if (fPositions2[10].cardOnIt == 1)
					{
						deck[counterNotCards3].type = deck[fPositions2[10].cardNum].type;
						deck[counterNotCards3].value = deck[fPositions2[10].cardNum].value;
						deck[counterNotCards3].num = counterNotCards3;
						deck[fPositions2[10].cardNum].placed = 1;
						deck[fPositions2[10].cardNum].display1 = 0;
						deck[fPositions2[10].cardNum].display2 = 0;
						deck[fPositions2[10].cardNum].type = 0;
						deck[fPositions2[10].cardNum].value = 0;
						deck[fPositions2[10].cardNum].num = 0;
						counterNotCards3++;
						fPositions2[10].cardOnIt = 0;
						fPositions2[10].cardValue = 0;
						fPositions2[10].cardNum = 0;

						if (fPositions2[13].cardOnIt == 1)
						{
							deck[counterNotCards3].type = deck[fPositions2[13].cardNum].type;
							deck[counterNotCards3].value = deck[fPositions2[13].cardNum].value;
							deck[counterNotCards3].num = counterNotCards3;
							deck[fPositions2[13].cardNum].placed = 1;
							deck[fPositions2[13].cardNum].display1 = 0;
							deck[fPositions2[13].cardNum].display2 = 0;
							deck[fPositions2[13].cardNum].type = 0;
							deck[fPositions2[13].cardNum].value = 0;
							deck[fPositions2[13].cardNum].num = 0;
							counterNotCards3++;
							fPositions2[13].cardOnIt = 0;
							fPositions2[13].cardValue = 0;
							fPositions2[13].cardNum = 0;

						}
					}
				}
			}
		}
		break;
	case 1:
		if (fPositions[1].cardOnIt == 1)
		{
			if (deck[fPositions[1].cardNum].type == 'a')
			{
				if ((baseCards[0].value && baseCards[1].value) == fPositions[1].cardValue)
				{
					collapse = 0;
				}
				else
				{
					collapse = 1;
				}
			}
			else if (deck[fPositions[1].cardNum].type == 'o')
			{
				if ((baseCards[0].value || baseCards[1].value) == fPositions[1].cardValue)
				{
					collapse = 0;
				}
				else
				{
					collapse = 1;
				}
			}
			else if (deck[fPositions[1].cardNum].type == 'x')
			{
				if ((baseCards[0].value ^ baseCards[1].value) == fPositions[1].cardValue)
				{
					collapse = 0;
				}
				else
				{
					collapse = 1;
				}
			}
			if (collapse == 1)
			{
				collapse = 0;
				deck[counterNotCards3].type = deck[fPositions[1].cardNum].type;
				deck[counterNotCards3].value = deck[fPositions[1].cardNum].value;
				deck[counterNotCards3].num = counterNotCards3;
				deck[fPositions[1].cardNum].placed = 1;
				deck[fPositions[1].cardNum].display1 = 0;
				deck[fPositions[1].cardNum].display2 = 0;
				deck[fPositions[1].cardNum].type = 0;
				deck[fPositions[1].cardNum].value = 0;
				deck[fPositions[1].cardNum].num = 0;
				counterNotCards3++;
				fPositions[1].cardOnIt = 0;
				fPositions[1].cardValue = 0;
				fPositions[1].cardNum = 0;

				if (fPositions[6].cardOnIt == 1)
				{
					deck[counterNotCards3].type = deck[fPositions[6].cardNum].type;
					deck[counterNotCards3].value = deck[fPositions[6].cardNum].value;
					deck[counterNotCards3].num = counterNotCards3;
					deck[fPositions[6].cardNum].placed = 1;
					deck[fPositions[6].cardNum].display1 = 0;
					deck[fPositions[6].cardNum].display2 = 0;
					deck[fPositions[6].cardNum].type = 0;
					deck[fPositions[6].cardNum].value = 0;
					deck[fPositions[6].cardNum].num = 0;
					counterNotCards3++;
					fPositions[6].cardOnIt = 0;
					fPositions[6].cardValue = 0;
					fPositions[6].cardNum = 0;

					if (fPositions[10].cardOnIt == 1)
					{
						deck[counterNotCards3].type = deck[fPositions[10].cardNum].type;
						deck[counterNotCards3].value = deck[fPositions[10].cardNum].value;
						deck[counterNotCards3].num = counterNotCards3;
						deck[fPositions[10].cardNum].placed = 1;
						deck[fPositions[10].cardNum].display1 = 0;
						deck[fPositions[10].cardNum].display2 = 0;
						deck[fPositions[10].cardNum].type = 0;
						deck[fPositions[10].cardNum].value = 0;
						deck[fPositions[10].cardNum].num = 0;
						counterNotCards3++;
						fPositions[10].cardOnIt = 0;
						fPositions[10].cardValue = 0;
						fPositions[10].cardNum = 0;

						if (fPositions[13].cardOnIt == 1)
						{
							deck[counterNotCards3].type = deck[fPositions[13].cardNum].type;
							deck[counterNotCards3].value = deck[fPositions[13].cardNum].value;
							deck[counterNotCards3].num = counterNotCards3;
							deck[fPositions[13].cardNum].placed = 1;
							deck[fPositions[13].cardNum].display1 = 0;
							deck[fPositions[13].cardNum].display2 = 0;
							deck[fPositions[13].cardNum].type = 0;
							deck[fPositions[13].cardNum].value = 0;
							deck[fPositions[13].cardNum].num = 0;
							counterNotCards3++;
							fPositions[13].cardOnIt = 0;
							fPositions[13].cardValue = 0;
							fPositions[13].cardNum = 0;

						}
					}
				}
			}
		}

		if (fPositions[2].cardOnIt == 1)
		{
			if (deck[fPositions[2].cardNum].type == 'a')
			{
				if ((baseCards[1].value && baseCards[2].value) == fPositions[2].cardValue)
				{
					collapse = 0;
				}
				else
				{
					collapse = 1;
				}
			}
			else if (deck[fPositions[2].cardNum].type == 'o')
			{
				if ((baseCards[1].value || baseCards[2].value) == fPositions[2].cardValue)
				{
					collapse = 0;
				}
				else
				{
					collapse = 1;
				}
			}
			else if (deck[fPositions[2].cardNum].type == 'x')
			{
				if ((baseCards[1].value ^ baseCards[2].value) == fPositions[2].cardValue)
				{
					collapse = 0;
				}
				else
				{
					collapse = 1;
				}
			}
			if (collapse == 1)
			{
				collapse = 0;
				deck[counterNotCards3].type = deck[fPositions[2].cardNum].type;
				deck[counterNotCards3].value = deck[fPositions[2].cardNum].value;
				deck[counterNotCards3].num = counterNotCards3;
				deck[fPositions[2].cardNum].placed = 1;
				deck[fPositions[2].cardNum].display1 = 0;
				deck[fPositions[2].cardNum].display2 = 0;
				deck[fPositions[2].cardNum].type = 0;
				deck[fPositions[2].cardNum].value = 0;
				deck[fPositions[2].cardNum].num = 0;
				counterNotCards3++;
				fPositions[2].cardOnIt = 0;
				fPositions[2].cardValue = 0;
				fPositions[2].cardNum = 0;

				if (fPositions[6].cardOnIt == 1)
				{
					deck[counterNotCards3].type = deck[fPositions[6].cardNum].type;
					deck[counterNotCards3].value = deck[fPositions[6].cardNum].value;
					deck[counterNotCards3].num = counterNotCards3;
					deck[fPositions[6].cardNum].placed = 1;
					deck[fPositions[6].cardNum].display1 = 0;
					deck[fPositions[6].cardNum].display2 = 0;
					deck[fPositions[6].cardNum].type = 0;
					deck[fPositions[6].cardNum].value = 0;
					deck[fPositions[6].cardNum].num = 0;
					counterNotCards3++;
					fPositions[6].cardOnIt = 0;
					fPositions[6].cardValue = 0;
					fPositions[6].cardNum = 0;

					if (fPositions[10].cardOnIt == 1)
					{
						deck[counterNotCards3].type = deck[fPositions[10].cardNum].type;
						deck[counterNotCards3].value = deck[fPositions[10].cardNum].value;
						deck[counterNotCards3].num = counterNotCards3;
						deck[fPositions[10].cardNum].placed = 1;
						deck[fPositions[10].cardNum].display1 = 0;
						deck[fPositions[10].cardNum].display2 = 0;
						deck[fPositions[10].cardNum].type = 0;
						deck[fPositions[10].cardNum].value = 0;
						deck[fPositions[10].cardNum].num = 0;
						counterNotCards3++;
						fPositions[10].cardOnIt = 0;
						fPositions[10].cardValue = 0;
						fPositions[10].cardNum = 0;

						if (fPositions[13].cardOnIt == 1)
						{
							deck[counterNotCards3].type = deck[fPositions[13].cardNum].type;
							deck[counterNotCards3].value = deck[fPositions[13].cardNum].value;
							deck[counterNotCards3].num = counterNotCards3;
							deck[fPositions[13].cardNum].placed = 1;
							deck[fPositions[13].cardNum].display1 = 0;
							deck[fPositions[13].cardNum].display2 = 0;
							deck[fPositions[13].cardNum].type = 0;
							deck[fPositions[13].cardNum].value = 0;
							deck[fPositions[13].cardNum].num = 0;
							counterNotCards3++;
							fPositions[13].cardOnIt = 0;
							fPositions[13].cardValue = 0;
							fPositions[13].cardNum = 0;

						}
					}
				}
				if (fPositions[7].cardOnIt == 1)
				{
					deck[counterNotCards3].type = deck[fPositions[7].cardNum].type;
					deck[counterNotCards3].value = deck[fPositions[7].cardNum].value;
					deck[counterNotCards3].num = counterNotCards3;
					deck[fPositions[7].cardNum].placed = 1;
					deck[fPositions[7].cardNum].display1 = 0;
					deck[fPositions[7].cardNum].display2 = 0;
					deck[fPositions[7].cardNum].type = 0;
					deck[fPositions[7].cardNum].value = 0;
					deck[fPositions[7].cardNum].num = 0;
					counterNotCards3++;
					fPositions[7].cardOnIt = 0;
					fPositions[7].cardValue = 0;
					fPositions[7].cardNum = 0;

					if (fPositions[11].cardOnIt == 1)
					{
						deck[counterNotCards3].type = deck[fPositions[11].cardNum].type;
						deck[counterNotCards3].value = deck[fPositions[11].cardNum].value;
						deck[counterNotCards3].num = counterNotCards3;
						deck[fPositions[11].cardNum].placed = 1;
						deck[fPositions[11].cardNum].display1 = 0;
						deck[fPositions[11].cardNum].display2 = 0;
						deck[fPositions[11].cardNum].type = 0;
						deck[fPositions[11].cardNum].value = 0;
						deck[fPositions[11].cardNum].num = 0;
						counterNotCards3++;
						fPositions[11].cardOnIt = 0;
						fPositions[11].cardValue = 0;
						fPositions[11].cardNum = 0;

						if (fPositions[14].cardOnIt == 1)
						{
							deck[counterNotCards3].type = deck[fPositions[14].cardNum].type;
							deck[counterNotCards3].value = deck[fPositions[14].cardNum].value;
							deck[counterNotCards3].num = counterNotCards3;
							deck[fPositions[14].cardNum].placed = 1;
							deck[fPositions[14].cardNum].display1 = 0;
							deck[fPositions[14].cardNum].display2 = 0;
							deck[fPositions[14].cardNum].type = 0;
							deck[fPositions[14].cardNum].value = 0;
							deck[fPositions[14].cardNum].num = 0;
							counterNotCards3++;
							fPositions[14].cardOnIt = 0;
							fPositions[14].cardValue = 0;
							fPositions[14].cardNum = 0;

						}
					}
				}
			}
		}
		
		if (fPositions2[1].cardOnIt == 1)
		{
			if (deck[fPositions2[1].cardNum].type == 'a')
			{
				if ((baseCards2[0].value && baseCards2[1].value) == fPositions2[1].cardValue)
				{
					collapse2 = 0;
				}
				else
				{
					collapse2 = 1;
				}
			}
			else if (deck[fPositions2[1].cardNum].type == 'o')
			{
				if ((baseCards2[0].value || baseCards2[1].value) == fPositions2[1].cardValue)
				{
					collapse2 = 0;
				}
				else
				{
					collapse2 = 1;
				}
			}
			else if (deck[fPositions2[1].cardNum].type == 'x')
			{
				if ((baseCards2[0].value ^ baseCards2[1].value) == fPositions2[1].cardValue)
				{
					collapse2 = 0;
				}
				else
				{
					collapse2 = 1;
				}
			}
			if (collapse2 == 1)
			{
				collapse2 = 0;
				deck[counterNotCards3].type = deck[fPositions2[1].cardNum].type;
				deck[counterNotCards3].value = deck[fPositions2[1].cardNum].value;
				deck[counterNotCards3].num = counterNotCards3;
				deck[fPositions2[1].cardNum].placed = 1;
				deck[fPositions2[1].cardNum].display1 = 0;
				deck[fPositions2[1].cardNum].display2 = 0;
				deck[fPositions2[1].cardNum].type = 0;
				deck[fPositions2[1].cardNum].value = 0;
				deck[fPositions2[1].cardNum].num = 0;
				counterNotCards3++;
				fPositions2[1].cardOnIt = 0;
				fPositions2[1].cardValue = 0;
				fPositions2[1].cardNum = 0;

				if (fPositions2[6].cardOnIt == 1)
				{
					deck[counterNotCards3].type = deck[fPositions2[6].cardNum].type;
					deck[counterNotCards3].value = deck[fPositions2[6].cardNum].value;
					deck[counterNotCards3].num = counterNotCards3;
					deck[fPositions2[6].cardNum].placed = 1;
					deck[fPositions2[6].cardNum].display1 = 0;
					deck[fPositions2[6].cardNum].display2 = 0;
					deck[fPositions2[6].cardNum].type = 0;
					deck[fPositions2[6].cardNum].value = 0;
					deck[fPositions2[6].cardNum].num = 0;
					counterNotCards3++;
					fPositions2[6].cardOnIt = 0;
					fPositions2[6].cardValue = 0;
					fPositions2[6].cardNum = 0;

					if (fPositions2[10].cardOnIt == 1)
					{
						deck[counterNotCards3].type = deck[fPositions2[10].cardNum].type;
						deck[counterNotCards3].value = deck[fPositions2[10].cardNum].value;
						deck[counterNotCards3].num = counterNotCards3;
						deck[fPositions2[10].cardNum].placed = 1;
						deck[fPositions2[10].cardNum].display1 = 0;
						deck[fPositions2[10].cardNum].display2 = 0;
						deck[fPositions2[10].cardNum].type = 0;
						deck[fPositions2[10].cardNum].value = 0;
						deck[fPositions2[10].cardNum].num = 0;
						counterNotCards3++;
						fPositions2[10].cardOnIt = 0;
						fPositions2[10].cardValue = 0;
						fPositions2[10].cardNum = 0;

						if (fPositions2[13].cardOnIt == 1)
						{
							deck[counterNotCards3].type = deck[fPositions2[13].cardNum].type;
							deck[counterNotCards3].value = deck[fPositions2[13].cardNum].value;
							deck[counterNotCards3].num = counterNotCards3;
							deck[fPositions2[13].cardNum].placed = 1;
							deck[fPositions2[13].cardNum].display1 = 0;
							deck[fPositions2[13].cardNum].display2 = 0;
							deck[fPositions2[13].cardNum].type = 0;
							deck[fPositions2[13].cardNum].value = 0;
							deck[fPositions2[13].cardNum].num = 0;
							counterNotCards3++;
							fPositions2[13].cardOnIt = 0;
							fPositions2[13].cardValue = 0;
							fPositions2[13].cardNum = 0;

						}
					}
				}
			}
		}

		if (fPositions2[2].cardOnIt == 1)
		{
			if (deck[fPositions2[2].cardNum].type == 'a')
			{
				if ((baseCards2[1].value && baseCards2[2].value) == fPositions2[2].cardValue)
				{
					collapse2 = 0;
				}
				else
				{
					collapse2 = 1;
				}
			}
			else if (deck[fPositions2[2].cardNum].type == 'o')
			{
				if ((baseCards2[1].value || baseCards2[2].value) == fPositions2[2].cardValue)
				{
					collapse2 = 0;
				}
				else
				{
					collapse2 = 1;
				}
			}
			else if (deck[fPositions2[2].cardNum].type == 'x')
			{
				if ((baseCards2[1].value ^ baseCards2[2].value) == fPositions2[2].cardValue)
				{
					collapse2 = 0;
				}
				else
				{
					collapse2 = 1;
				}
			}
			if (collapse2 == 1)
			{
				collapse2 = 0;
				deck[counterNotCards3].type = deck[fPositions2[2].cardNum].type;
				deck[counterNotCards3].value = deck[fPositions2[2].cardNum].value;
				deck[counterNotCards3].num = counterNotCards3;
				deck[fPositions2[2].cardNum].placed = 1;
				deck[fPositions2[2].cardNum].display1 = 0;
				deck[fPositions2[2].cardNum].display2 = 0;
				deck[fPositions2[2].cardNum].type = 0;
				deck[fPositions2[2].cardNum].value = 0;
				deck[fPositions2[2].cardNum].num = 0;
				counterNotCards3++;
				fPositions2[2].cardOnIt = 0;
				fPositions2[2].cardValue = 0;
				fPositions2[2].cardNum = 0;

				if (fPositions2[6].cardOnIt == 1)
				{
					deck[counterNotCards3].type = deck[fPositions2[6].cardNum].type;
					deck[counterNotCards3].value = deck[fPositions2[6].cardNum].value;
					deck[counterNotCards3].num = counterNotCards3;
					deck[fPositions2[6].cardNum].placed = 1;
					deck[fPositions2[6].cardNum].display1 = 0;
					deck[fPositions2[6].cardNum].display2 = 0;
					deck[fPositions2[6].cardNum].type = 0;
					deck[fPositions2[6].cardNum].value = 0;
					deck[fPositions2[6].cardNum].num = 0;
					counterNotCards3++;
					fPositions2[6].cardOnIt = 0;
					fPositions2[6].cardValue = 0;
					fPositions2[6].cardNum = 0;

					if (fPositions2[10].cardOnIt == 1)
					{
						deck[counterNotCards3].type = deck[fPositions2[10].cardNum].type;
						deck[counterNotCards3].value = deck[fPositions2[10].cardNum].value;
						deck[counterNotCards3].num = counterNotCards3;
						deck[fPositions2[10].cardNum].placed = 1;
						deck[fPositions2[10].cardNum].display1 = 0;
						deck[fPositions2[10].cardNum].display2 = 0;
						deck[fPositions2[10].cardNum].type = 0;
						deck[fPositions2[10].cardNum].value = 0;
						deck[fPositions2[10].cardNum].num = 0;
						counterNotCards3++;
						fPositions2[10].cardOnIt = 0;
						fPositions2[10].cardValue = 0;
						fPositions2[10].cardNum = 0;

						if (fPositions2[13].cardOnIt == 1)
						{
							deck[counterNotCards3].type = deck[fPositions2[13].cardNum].type;
							deck[counterNotCards3].value = deck[fPositions2[13].cardNum].value;
							deck[counterNotCards3].num = counterNotCards3;
							deck[fPositions2[13].cardNum].placed = 1;
							deck[fPositions2[13].cardNum].display1 = 0;
							deck[fPositions2[13].cardNum].display2 = 0;
							deck[fPositions2[13].cardNum].type = 0;
							deck[fPositions2[13].cardNum].value = 0;
							deck[fPositions2[13].cardNum].num = 0;
							counterNotCards3++;
							fPositions2[13].cardOnIt = 0;
							fPositions2[13].cardValue = 0;
							fPositions2[13].cardNum = 0;

						}
					}
				}
				if (fPositions2[7].cardOnIt == 1)
				{
					deck[counterNotCards3].type = deck[fPositions2[7].cardNum].type;
					deck[counterNotCards3].value = deck[fPositions2[7].cardNum].value;
					deck[counterNotCards3].num = counterNotCards3;
					deck[fPositions2[7].cardNum].placed = 1;
					deck[fPositions2[7].cardNum].display1 = 0;
					deck[fPositions2[7].cardNum].display2 = 0;
					deck[fPositions2[7].cardNum].type = 0;
					deck[fPositions2[7].cardNum].value = 0;
					deck[fPositions2[7].cardNum].num = 0;
					counterNotCards3++;
					fPositions2[7].cardOnIt = 0;
					fPositions2[7].cardValue = 0;
					fPositions2[7].cardNum = 0;

					if (fPositions2[11].cardOnIt == 1)
					{
						deck[counterNotCards3].type = deck[fPositions2[11].cardNum].type;
						deck[counterNotCards3].value = deck[fPositions2[11].cardNum].value;
						deck[counterNotCards3].num = counterNotCards3;
						deck[fPositions2[11].cardNum].placed = 1;
						deck[fPositions2[11].cardNum].display1 = 0;
						deck[fPositions2[11].cardNum].display2 = 0;
						deck[fPositions2[11].cardNum].type = 0;
						deck[fPositions2[11].cardNum].value = 0;
						deck[fPositions2[11].cardNum].num = 0;
						counterNotCards3++;
						fPositions2[11].cardOnIt = 0;
						fPositions2[11].cardValue = 0;
						fPositions2[11].cardNum = 0;

						if (fPositions2[14].cardOnIt == 1)
						{
							deck[counterNotCards3].type = deck[fPositions2[14].cardNum].type;
							deck[counterNotCards3].value = deck[fPositions2[14].cardNum].value;
							deck[counterNotCards3].num = counterNotCards3;
							deck[fPositions2[14].cardNum].placed = 1;
							deck[fPositions2[14].cardNum].display1 = 0;
							deck[fPositions2[14].cardNum].display2 = 0;
							deck[fPositions2[14].cardNum].type = 0;
							deck[fPositions2[14].cardNum].value = 0;
							deck[fPositions2[14].cardNum].num = 0;
							counterNotCards3++;
							fPositions2[14].cardOnIt = 0;
							fPositions2[14].cardValue = 0;
							fPositions2[14].cardNum = 0;

						}
					}
				}
			}
		}
		break;
	case 2:

		if (fPositions[2].cardOnIt == 1)
		{
			if (deck[fPositions[2].cardNum].type == 'a')
			{
				if ((baseCards[1].value && baseCards[2].value) == fPositions[2].cardValue)
				{
					collapse = 0;
				}
				else
				{
					collapse = 1;
				}
			}
			else if (deck[fPositions[2].cardNum].type == 'o')
			{
				if ((baseCards[1].value || baseCards[2].value) == fPositions[2].cardValue)
				{
					collapse = 0;
				}
				else
				{
					collapse = 1;
				}
			}
			else if (deck[fPositions[2].cardNum].type == 'x')
			{
				if ((baseCards[1].value ^ baseCards[2].value) == fPositions[2].cardValue)
				{
					collapse = 0;
				}
				else
				{
					collapse = 1;
				}
			}
			if (collapse == 1)
			{
				collapse = 0;
				deck[counterNotCards3].type = deck[fPositions[2].cardNum].type;
				deck[counterNotCards3].value = deck[fPositions[2].cardNum].value;
				deck[counterNotCards3].num = counterNotCards3;
				deck[fPositions[2].cardNum].placed = 1;
				deck[fPositions[2].cardNum].display1 = 0;
				deck[fPositions[2].cardNum].display2 = 0;
				deck[fPositions[2].cardNum].type = 0;
				deck[fPositions[2].cardNum].value = 0;
				deck[fPositions[2].cardNum].num = 0;
				counterNotCards3++;
				fPositions[2].cardOnIt = 0;
				fPositions[2].cardValue = 0;
				fPositions[2].cardNum = 0;

				if (fPositions[7].cardOnIt == 1)
				{
					deck[counterNotCards3].type = deck[fPositions[7].cardNum].type;
					deck[counterNotCards3].value = deck[fPositions[7].cardNum].value;
					deck[counterNotCards3].num = counterNotCards3;
					deck[fPositions[7].cardNum].placed = 1;
					deck[fPositions[7].cardNum].display1 = 0;
					deck[fPositions[7].cardNum].display2 = 0;
					deck[fPositions[7].cardNum].type = 0;
					deck[fPositions[7].cardNum].value = 0;
					deck[fPositions[7].cardNum].num = 0;
					counterNotCards3++;
					fPositions[7].cardOnIt = 0;
					fPositions[7].cardValue = 0;
					fPositions[7].cardNum = 0;

					if (fPositions[11].cardOnIt == 1)
					{
						deck[counterNotCards3].type = deck[fPositions[11].cardNum].type;
						deck[counterNotCards3].value = deck[fPositions[11].cardNum].value;
						deck[counterNotCards3].num = counterNotCards3;
						deck[fPositions[11].cardNum].placed = 1;
						deck[fPositions[11].cardNum].display1 = 0;
						deck[fPositions[11].cardNum].display2 = 0;
						deck[fPositions[11].cardNum].type = 0;
						deck[fPositions[11].cardNum].value = 0;
						deck[fPositions[11].cardNum].num = 0;
						counterNotCards3++;
						fPositions[11].cardOnIt = 0;
						fPositions[11].cardValue = 0;
						fPositions[11].cardNum = 0;

						if (fPositions[14].cardOnIt == 1)
						{
							deck[counterNotCards3].type = deck[fPositions[14].cardNum].type;
							deck[counterNotCards3].value = deck[fPositions[14].cardNum].value;
							deck[counterNotCards3].num = counterNotCards3;
							deck[fPositions[14].cardNum].placed = 1;
							deck[fPositions[14].cardNum].display1 = 0;
							deck[fPositions[14].cardNum].display2 = 0;
							deck[fPositions[14].cardNum].type = 0;
							deck[fPositions[14].cardNum].value = 0;
							deck[fPositions[14].cardNum].num = 0;
							counterNotCards3++;
							fPositions[14].cardOnIt = 0;
							fPositions[14].cardValue = 0;
							fPositions[14].cardNum = 0;

						}
					}
				}

				if (fPositions[6].cardOnIt == 1)
				{
					deck[counterNotCards3].type = deck[fPositions[6].cardNum].type;
					deck[counterNotCards3].value = deck[fPositions[6].cardNum].value;
					deck[counterNotCards3].num = counterNotCards3;
					deck[fPositions[6].cardNum].placed = 1;
					deck[fPositions[6].cardNum].display1 = 0;
					deck[fPositions[6].cardNum].display2 = 0;
					deck[fPositions[6].cardNum].type = 0;
					deck[fPositions[6].cardNum].value = 0;
					deck[fPositions[6].cardNum].num = 0;
					counterNotCards3++;
					fPositions[6].cardOnIt = 0;
					fPositions[6].cardValue = 0;
					fPositions[6].cardNum = 0;

					if (fPositions[10].cardOnIt == 1)
					{
						deck[counterNotCards3].type = deck[fPositions[10].cardNum].type;
						deck[counterNotCards3].value = deck[fPositions[10].cardNum].value;
						deck[counterNotCards3].num = counterNotCards3;
						deck[fPositions[10].cardNum].placed = 1;
						deck[fPositions[10].cardNum].display1 = 0;
						deck[fPositions[10].cardNum].display2 = 0;
						deck[fPositions[10].cardNum].type = 0;
						deck[fPositions[10].cardNum].value = 0;
						deck[fPositions[10].cardNum].num = 0;
						counterNotCards3++;
						fPositions[10].cardOnIt = 0;
						fPositions[10].cardValue = 0;
						fPositions[10].cardNum = 0;

						if (fPositions[13].cardOnIt == 1)
						{
							deck[counterNotCards3].type = deck[fPositions[13].cardNum].type;
							deck[counterNotCards3].value = deck[fPositions[13].cardNum].value;
							deck[counterNotCards3].num = counterNotCards3;
							deck[fPositions[13].cardNum].placed = 1;
							deck[fPositions[13].cardNum].display1 = 0;
							deck[fPositions[13].cardNum].display2 = 0;
							deck[fPositions[13].cardNum].type = 0;
							deck[fPositions[13].cardNum].value = 0;
							deck[fPositions[13].cardNum].num = 0;
							counterNotCards3++;
							fPositions[13].cardOnIt = 0;
							fPositions[13].cardValue = 0;
							fPositions[13].cardNum = 0;

						}
					}
				}
			}
		}

		if (fPositions[3].cardOnIt == 1)
		{
			if (deck[fPositions[3].cardNum].type == 'a')
			{
				if ((baseCards[2].value && baseCards[3].value) == fPositions[3].cardValue)
				{
					collapse = 0;
				}
				else
				{
					collapse = 1;
				}
			}
			else if (deck[fPositions[3].cardNum].type == 'o')
			{
				if ((baseCards[2].value || baseCards[3].value) == fPositions[3].cardValue)
				{
					collapse = 0;
				}
				else
				{
					collapse = 1;
				}
			}
			else if (deck[fPositions[3].cardNum].type == 'x')
			{
				if ((baseCards[2].value ^ baseCards[3].value) == fPositions[3].cardValue)
				{
					collapse = 0;
				}
				else
				{
					collapse = 1;
				}
			}
			if (collapse == 1)
			{
				collapse = 0;
				deck[counterNotCards3].type = deck[fPositions[3].cardNum].type;
				deck[counterNotCards3].value = deck[fPositions[3].cardNum].value;
				deck[counterNotCards3].num = counterNotCards3;
				deck[fPositions[3].cardNum].placed = 1;
				deck[fPositions[3].cardNum].display1 = 0;
				deck[fPositions[3].cardNum].display2 = 0;
				deck[fPositions[3].cardNum].type = 0;
				deck[fPositions[3].cardNum].value = 0;
				deck[fPositions[3].cardNum].num = 0;
				counterNotCards3++;
				fPositions[3].cardOnIt = 0;
				fPositions[3].cardValue = 0;
				fPositions[3].cardNum = 0;

				if (fPositions[8].cardOnIt == 1)
				{
					deck[counterNotCards3].type = deck[fPositions[8].cardNum].type;
					deck[counterNotCards3].value = deck[fPositions[8].cardNum].value;
					deck[counterNotCards3].num = counterNotCards3;
					deck[fPositions[8].cardNum].placed = 1;
					deck[fPositions[8].cardNum].display1 = 0;
					deck[fPositions[8].cardNum].display2 = 0;
					deck[fPositions[8].cardNum].type = 0;
					deck[fPositions[8].cardNum].value = 0;
					deck[fPositions[8].cardNum].num = 0;
					counterNotCards3++;
					fPositions[8].cardOnIt = 0;
					fPositions[8].cardValue = 0;
					fPositions[8].cardNum = 0;

					if (fPositions[12].cardOnIt == 1)
					{
						deck[counterNotCards3].type = deck[fPositions[12].cardNum].type;
						deck[counterNotCards3].value = deck[fPositions[12].cardNum].value;
						deck[counterNotCards3].num = counterNotCards3;
						deck[fPositions[12].cardNum].placed = 1;
						deck[fPositions[12].cardNum].display1 = 0;
						deck[fPositions[12].cardNum].display2 = 0;
						deck[fPositions[12].cardNum].type = 0;
						deck[fPositions[12].cardNum].value = 0;
						deck[fPositions[12].cardNum].num = 0;
						counterNotCards3++;
						fPositions[12].cardOnIt = 0;
						fPositions[12].cardValue = 0;
						fPositions[12].cardNum = 0;
					}
				}
				if (fPositions[7].cardOnIt == 1)
				{
					deck[counterNotCards3].type = deck[fPositions[7].cardNum].type;
					deck[counterNotCards3].value = deck[fPositions[7].cardNum].value;
					deck[counterNotCards3].num = counterNotCards3;
					deck[fPositions[7].cardNum].placed = 1;
					deck[fPositions[7].cardNum].display1 = 0;
					deck[fPositions[7].cardNum].display2 = 0;
					deck[fPositions[7].cardNum].type = 0;
					deck[fPositions[7].cardNum].value = 0;
					deck[fPositions[7].cardNum].num = 0;
					counterNotCards3++;
					fPositions[7].cardOnIt = 0;
					fPositions[7].cardValue = 0;
					fPositions[7].cardNum = 0;

					if (fPositions[10].cardOnIt == 1)
					{
						deck[counterNotCards3].type = deck[fPositions[10].cardNum].type;
						deck[counterNotCards3].value = deck[fPositions[10].cardNum].value;
						deck[counterNotCards3].num = counterNotCards3;
						deck[fPositions[10].cardNum].placed = 1;
						deck[fPositions[10].cardNum].display1 = 0;
						deck[fPositions[10].cardNum].display2 = 0;
						deck[fPositions[10].cardNum].type = 0;
						deck[fPositions[10].cardNum].value = 0;
						deck[fPositions[10].cardNum].num = 0;
						counterNotCards3++;
						fPositions[10].cardOnIt = 0;
						fPositions[10].cardValue = 0;
						fPositions[10].cardNum = 0;
					}
					if (fPositions[11].cardOnIt == 1)
					{
						deck[counterNotCards3].type = deck[fPositions[11].cardNum].type;
						deck[counterNotCards3].value = deck[fPositions[11].cardNum].value;
						deck[counterNotCards3].num = counterNotCards3;
						deck[fPositions[11].cardNum].placed = 1;
						deck[fPositions[11].cardNum].display1 = 0;
						deck[fPositions[11].cardNum].display2 = 0;
						deck[fPositions[11].cardNum].type = 0;
						deck[fPositions[11].cardNum].value = 0;
						deck[fPositions[11].cardNum].num = 0;
						counterNotCards3++;
						fPositions[11].cardOnIt = 0;
						fPositions[11].cardValue = 0;
						fPositions[11].cardNum = 0;
						if (fPositions[13].cardOnIt == 1)
						{
							deck[counterNotCards3].type = deck[fPositions[13].cardNum].type;
							deck[counterNotCards3].value = deck[fPositions[13].cardNum].value;
							deck[counterNotCards3].num = counterNotCards3;
							deck[fPositions[13].cardNum].placed = 1;
							deck[fPositions[13].cardNum].display1 = 0;
							deck[fPositions[13].cardNum].display2 = 0;
							deck[fPositions[13].cardNum].type = 0;
							deck[fPositions[13].cardNum].value = 0;
							deck[fPositions[13].cardNum].num = 0;
							counterNotCards3++;
							fPositions[13].cardOnIt = 0;
							fPositions[13].cardValue = 0;
							fPositions[13].cardNum = 0;
						}
						if (fPositions[14].cardOnIt == 1)
						{
							deck[counterNotCards3].type = deck[fPositions[14].cardNum].type;
							deck[counterNotCards3].value = deck[fPositions[14].cardNum].value;
							deck[counterNotCards3].num = counterNotCards3;
							deck[fPositions[14].cardNum].placed = 1;
							deck[fPositions[14].cardNum].display1 = 0;
							deck[fPositions[14].cardNum].display2 = 0;
							deck[fPositions[14].cardNum].type = 0;
							deck[fPositions[14].cardNum].value = 0;
							deck[fPositions[14].cardNum].num = 0;
							counterNotCards3++;
							fPositions[14].cardOnIt = 0;
							fPositions[14].cardValue = 0;
							fPositions[14].cardNum = 0;
						}
					}
				}
			}
		}
		
		if (fPositions2[2].cardOnIt == 1)
		{
			if (deck[fPositions2[2].cardNum].type == 'a')
			{
				if ((baseCards2[1].value && baseCards2[2].value) == fPositions2[2].cardValue)
				{
					collapse2 = 0;
				}
				else
				{
					collapse2 = 1;
				}
			}
			else if (deck[fPositions2[2].cardNum].type == 'o')
			{
				if ((baseCards2[1].value || baseCards2[2].value) == fPositions2[2].cardValue)
				{
					collapse2 = 0;
				}
				else
				{
					collapse2 = 1;
				}
			}
			else if (deck[fPositions2[2].cardNum].type == 'x')
			{
				if ((baseCards2[1].value ^ baseCards2[2].value) == fPositions2[2].cardValue)
				{
					collapse2 = 0;
				}
				else
				{
					collapse2 = 1;
				}
			}
			if (collapse2 == 1)
			{
				collapse2 = 0;
				deck[counterNotCards3].type = deck[fPositions2[2].cardNum].type;
				deck[counterNotCards3].value = deck[fPositions2[2].cardNum].value;
				deck[counterNotCards3].num = counterNotCards3;
				deck[fPositions2[2].cardNum].placed = 1;
				deck[fPositions2[2].cardNum].display1 = 0;
				deck[fPositions2[2].cardNum].display2 = 0;
				deck[fPositions2[2].cardNum].type = 0;
				deck[fPositions2[2].cardNum].value = 0;
				deck[fPositions2[2].cardNum].num = 0;
				counterNotCards3++;
				fPositions2[2].cardOnIt = 0;
				fPositions2[2].cardValue = 0;
				fPositions2[2].cardNum = 0;

				if (fPositions2[7].cardOnIt == 1)
				{
					deck[counterNotCards3].type = deck[fPositions2[7].cardNum].type;
					deck[counterNotCards3].value = deck[fPositions2[7].cardNum].value;
					deck[counterNotCards3].num = counterNotCards3;
					deck[fPositions2[7].cardNum].placed = 1;
					deck[fPositions2[7].cardNum].display1 = 0;
					deck[fPositions2[7].cardNum].display2 = 0;
					deck[fPositions2[7].cardNum].type = 0;
					deck[fPositions2[7].cardNum].value = 0;
					deck[fPositions2[7].cardNum].num = 0;
					counterNotCards3++;
					fPositions2[7].cardOnIt = 0;
					fPositions2[7].cardValue = 0;
					fPositions2[7].cardNum = 0;

					if (fPositions2[11].cardOnIt == 1)
					{
						deck[counterNotCards3].type = deck[fPositions2[11].cardNum].type;
						deck[counterNotCards3].value = deck[fPositions2[11].cardNum].value;
						deck[counterNotCards3].num = counterNotCards3;
						deck[fPositions2[11].cardNum].placed = 1;
						deck[fPositions2[11].cardNum].display1 = 0;
						deck[fPositions2[11].cardNum].display2 = 0;
						deck[fPositions2[11].cardNum].type = 0;
						deck[fPositions2[11].cardNum].value = 0;
						deck[fPositions2[11].cardNum].num = 0;
						counterNotCards3++;
						fPositions2[11].cardOnIt = 0;
						fPositions2[11].cardValue = 0;
						fPositions2[11].cardNum = 0;

						if (fPositions2[14].cardOnIt == 1)
						{
							deck[counterNotCards3].type = deck[fPositions2[14].cardNum].type;
							deck[counterNotCards3].value = deck[fPositions2[14].cardNum].value;
							deck[counterNotCards3].num = counterNotCards3;
							deck[fPositions2[14].cardNum].placed = 1;
							deck[fPositions2[14].cardNum].display1 = 0;
							deck[fPositions2[14].cardNum].display2 = 0;
							deck[fPositions2[14].cardNum].type = 0;
							deck[fPositions2[14].cardNum].value = 0;
							deck[fPositions2[14].cardNum].num = 0;
							counterNotCards3++;
							fPositions2[14].cardOnIt = 0;
							fPositions2[14].cardValue = 0;
							fPositions2[14].cardNum = 0;

						}
					}
				}

				if (fPositions2[6].cardOnIt == 1)
				{
					deck[counterNotCards3].type = deck[fPositions2[6].cardNum].type;
					deck[counterNotCards3].value = deck[fPositions2[6].cardNum].value;
					deck[counterNotCards3].num = counterNotCards3;
					deck[fPositions2[6].cardNum].placed = 1;
					deck[fPositions2[6].cardNum].display1 = 0;
					deck[fPositions2[6].cardNum].display2 = 0;
					deck[fPositions2[6].cardNum].type = 0;
					deck[fPositions2[6].cardNum].value = 0;
					deck[fPositions2[6].cardNum].num = 0;
					counterNotCards3++;
					fPositions2[6].cardOnIt = 0;
					fPositions2[6].cardValue = 0;
					fPositions2[6].cardNum = 0;

					if (fPositions2[10].cardOnIt == 1)
					{
						deck[counterNotCards3].type = deck[fPositions2[10].cardNum].type;
						deck[counterNotCards3].value = deck[fPositions2[10].cardNum].value;
						deck[counterNotCards3].num = counterNotCards3;
						deck[fPositions2[10].cardNum].placed = 1;
						deck[fPositions2[10].cardNum].display1 = 0;
						deck[fPositions2[10].cardNum].display2 = 0;
						deck[fPositions2[10].cardNum].type = 0;
						deck[fPositions2[10].cardNum].value = 0;
						deck[fPositions2[10].cardNum].num = 0;
						counterNotCards3++;
						fPositions2[10].cardOnIt = 0;
						fPositions2[10].cardValue = 0;
						fPositions2[10].cardNum = 0;

						if (fPositions2[13].cardOnIt == 1)
						{
							deck[counterNotCards3].type = deck[fPositions2[13].cardNum].type;
							deck[counterNotCards3].value = deck[fPositions2[13].cardNum].value;
							deck[counterNotCards3].num = counterNotCards3;
							deck[fPositions2[13].cardNum].placed = 1;
							deck[fPositions2[13].cardNum].display1 = 0;
							deck[fPositions2[13].cardNum].display2 = 0;
							deck[fPositions2[13].cardNum].type = 0;
							deck[fPositions2[13].cardNum].value = 0;
							deck[fPositions2[13].cardNum].num = 0;
							counterNotCards3++;
							fPositions2[13].cardOnIt = 0;
							fPositions2[13].cardValue = 0;
							fPositions2[13].cardNum = 0;

						}
					}
				}
			}
		}

		if (fPositions2[3].cardOnIt == 1)
		{
			if (deck[fPositions2[3].cardNum].type == 'a')
			{
				if ((baseCards2[2].value && baseCards2[3].value) == fPositions2[3].cardValue)
				{
					collapse2 = 0;
				}
				else
				{
					collapse2 = 1;
				}
			}
			else if (deck[fPositions2[3].cardNum].type == 'o')
			{
				if ((baseCards2[2].value || baseCards2[3].value) == fPositions2[3].cardValue)
				{
					collapse2 = 0;
				}
				else
				{
					collapse2 = 1;
				}
			}
			else if (deck[fPositions2[3].cardNum].type == 'x')
			{
				if ((baseCards2[2].value ^ baseCards2[3].value) == fPositions2[3].cardValue)
				{
					collapse2 = 0;
				}
				else
				{
					collapse2 = 1;
				}
			}
			if (collapse2 == 1)
			{
				collapse2 = 0;
				deck[counterNotCards3].type = deck[fPositions2[3].cardNum].type;
				deck[counterNotCards3].value = deck[fPositions2[3].cardNum].value;
				deck[counterNotCards3].num = counterNotCards3;
				deck[fPositions2[3].cardNum].placed = 1;
				deck[fPositions2[3].cardNum].display1 = 0;
				deck[fPositions2[3].cardNum].display2 = 0;
				deck[fPositions2[3].cardNum].type = 0;
				deck[fPositions2[3].cardNum].value = 0;
				deck[fPositions2[3].cardNum].num = 0;
				counterNotCards3++;
				fPositions2[3].cardOnIt = 0;
				fPositions2[3].cardValue = 0;
				fPositions2[3].cardNum = 0;

				if (fPositions2[8].cardOnIt == 1)
				{
					deck[counterNotCards3].type = deck[fPositions2[8].cardNum].type;
					deck[counterNotCards3].value = deck[fPositions2[8].cardNum].value;
					deck[counterNotCards3].num = counterNotCards3;
					deck[fPositions2[8].cardNum].placed = 1;
					deck[fPositions2[8].cardNum].display1 = 0;
					deck[fPositions2[8].cardNum].display2 = 0;
					deck[fPositions2[8].cardNum].type = 0;
					deck[fPositions2[8].cardNum].value = 0;
					deck[fPositions2[8].cardNum].num = 0;
					counterNotCards3++;
					fPositions2[8].cardOnIt = 0;
					fPositions2[8].cardValue = 0;
					fPositions2[8].cardNum = 0;

					if (fPositions2[12].cardOnIt == 1)
					{
						deck[counterNotCards3].type = deck[fPositions2[12].cardNum].type;
						deck[counterNotCards3].value = deck[fPositions2[12].cardNum].value;
						deck[counterNotCards3].num = counterNotCards3;
						deck[fPositions2[12].cardNum].placed = 1;
						deck[fPositions2[12].cardNum].display1 = 0;
						deck[fPositions2[12].cardNum].display2 = 0;
						deck[fPositions2[12].cardNum].type = 0;
						deck[fPositions2[12].cardNum].value = 0;
						deck[fPositions2[12].cardNum].num = 0;
						counterNotCards3++;
						fPositions2[12].cardOnIt = 0;
						fPositions2[12].cardValue = 0;
						fPositions2[12].cardNum = 0;
					}
				}
				if (fPositions2[7].cardOnIt == 1)
				{
					deck[counterNotCards3].type = deck[fPositions2[7].cardNum].type;
					deck[counterNotCards3].value = deck[fPositions2[7].cardNum].value;
					deck[counterNotCards3].num = counterNotCards3;
					deck[fPositions2[7].cardNum].placed = 1;
					deck[fPositions2[7].cardNum].display1 = 0;
					deck[fPositions2[7].cardNum].display2 = 0;
					deck[fPositions2[7].cardNum].type = 0;
					deck[fPositions2[7].cardNum].value = 0;
					deck[fPositions2[7].cardNum].num = 0;
					counterNotCards3++;
					fPositions2[7].cardOnIt = 0;
					fPositions2[7].cardValue = 0;
					fPositions2[7].cardNum = 0;

					if (fPositions2[10].cardOnIt == 1)
					{
						deck[counterNotCards3].type = deck[fPositions2[10].cardNum].type;
						deck[counterNotCards3].value = deck[fPositions2[10].cardNum].value;
						deck[counterNotCards3].num = counterNotCards3;
						deck[fPositions2[10].cardNum].placed = 1;
						deck[fPositions2[10].cardNum].display1 = 0;
						deck[fPositions2[10].cardNum].display2 = 0;
						deck[fPositions2[10].cardNum].type = 0;
						deck[fPositions2[10].cardNum].value = 0;
						deck[fPositions2[10].cardNum].num = 0;
						counterNotCards3++;
						fPositions2[10].cardOnIt = 0;
						fPositions2[10].cardValue = 0;
						fPositions2[10].cardNum = 0;
					}
					if (fPositions2[11].cardOnIt == 1)
					{
						deck[counterNotCards3].type = deck[fPositions2[11].cardNum].type;
						deck[counterNotCards3].value = deck[fPositions2[11].cardNum].value;
						deck[counterNotCards3].num = counterNotCards3;
						deck[fPositions2[11].cardNum].placed = 1;
						deck[fPositions2[11].cardNum].display1 = 0;
						deck[fPositions2[11].cardNum].display2 = 0;
						deck[fPositions2[11].cardNum].type = 0;
						deck[fPositions2[11].cardNum].value = 0;
						deck[fPositions2[11].cardNum].num = 0;
						counterNotCards3++;
						fPositions2[11].cardOnIt = 0;
						fPositions2[11].cardValue = 0;
						fPositions2[11].cardNum = 0;
						if (fPositions2[13].cardOnIt == 1)
						{
							deck[counterNotCards3].type = deck[fPositions2[13].cardNum].type;
							deck[counterNotCards3].value = deck[fPositions2[13].cardNum].value;
							deck[counterNotCards3].num = counterNotCards3;
							deck[fPositions2[13].cardNum].placed = 1;
							deck[fPositions2[13].cardNum].display1 = 0;
							deck[fPositions2[13].cardNum].display2 = 0;
							deck[fPositions2[13].cardNum].type = 0;
							deck[fPositions2[13].cardNum].value = 0;
							deck[fPositions2[13].cardNum].num = 0;
							counterNotCards3++;
							fPositions2[13].cardOnIt = 0;
							fPositions2[13].cardValue = 0;
							fPositions2[13].cardNum = 0;
						}
						if (fPositions2[14].cardOnIt == 1)
						{
							deck[counterNotCards3].type = deck[fPositions2[14].cardNum].type;
							deck[counterNotCards3].value = deck[fPositions2[14].cardNum].value;
							deck[counterNotCards3].num = counterNotCards3;
							deck[fPositions2[14].cardNum].placed = 1;
							deck[fPositions2[14].cardNum].display1 = 0;
							deck[fPositions2[14].cardNum].display2 = 0;
							deck[fPositions2[14].cardNum].type = 0;
							deck[fPositions2[14].cardNum].value = 0;
							deck[fPositions2[14].cardNum].num = 0;
							counterNotCards3++;
							fPositions2[14].cardOnIt = 0;
							fPositions2[14].cardValue = 0;
							fPositions2[14].cardNum = 0;
						}
					}
				}
			}
		}
		break;
	case 3:
		if (fPositions[3].cardOnIt == 1)
		{
			if (deck[fPositions[3].cardNum].type == 'a')
			{
				if ((baseCards[2].value && baseCards[3].value) == fPositions[3].cardValue)
				{
					collapse = 0;
				}
				else
				{
					collapse = 1;
				}
			}
			else if (deck[fPositions[3].cardNum].type == 'o')
			{
				if ((baseCards[2].value || baseCards[3].value) == fPositions[3].cardValue)
				{
					collapse = 0;
				}
				else
				{
					collapse = 1;
				}
			}
			else if (deck[fPositions[3].cardNum].type == 'x')
			{
				if ((baseCards[2].value ^ baseCards[3].value) == fPositions[3].cardValue)
				{
					collapse = 0;
				}
				else
				{
					collapse = 1;
				}
			}
			if (collapse == 1)
			{
				collapse = 0;
				deck[counterNotCards3].type = deck[fPositions[3].cardNum].type;
				deck[counterNotCards3].value = deck[fPositions[3].cardNum].value;
				deck[counterNotCards3].num = counterNotCards3;
				deck[fPositions[3].cardNum].placed = 1;
				deck[fPositions[3].cardNum].display1 = 0;
				deck[fPositions[3].cardNum].display2 = 0;
				deck[fPositions[3].cardNum].type = 0;
				deck[fPositions[3].cardNum].value = 0;
				deck[fPositions[3].cardNum].num = 0;
				counterNotCards3++;
				fPositions[3].cardOnIt = 0;
				fPositions[3].cardValue = 0;
				fPositions[3].cardNum = 0;

				if (fPositions[8].cardOnIt == 1)
				{
					deck[counterNotCards3].type = deck[fPositions[8].cardNum].type;
					deck[counterNotCards3].value = deck[fPositions[8].cardNum].value;
					deck[counterNotCards3].num = counterNotCards3;
					deck[fPositions[8].cardNum].placed = 1;
					deck[fPositions[8].cardNum].display1 = 0;
					deck[fPositions[8].cardNum].display2 = 0;
					deck[fPositions[8].cardNum].type = 0;
					deck[fPositions[8].cardNum].value = 0;
					deck[fPositions[8].cardNum].num = 0;
					counterNotCards3++;
					fPositions[8].cardOnIt = 0;
					fPositions[8].cardValue = 0;
					fPositions[8].cardNum = 0;

					if (fPositions[12].cardOnIt == 1)
					{
						deck[counterNotCards3].type = deck[fPositions[12].cardNum].type;
						deck[counterNotCards3].value = deck[fPositions[12].cardNum].value;
						deck[counterNotCards3].num = counterNotCards3;
						deck[fPositions[12].cardNum].placed = 1;
						deck[fPositions[12].cardNum].display1 = 0;
						deck[fPositions[12].cardNum].display2 = 0;
						deck[fPositions[12].cardNum].type = 0;
						deck[fPositions[12].cardNum].value = 0;
						deck[fPositions[12].cardNum].num = 0;
						counterNotCards3++;
						fPositions[12].cardOnIt = 0;
						fPositions[12].cardValue = 0;
						fPositions[12].cardNum = 0;
					}
				}
				if (fPositions[7].cardOnIt == 1)
				{
					deck[counterNotCards3].type = deck[fPositions[7].cardNum].type;
					deck[counterNotCards3].value = deck[fPositions[7].cardNum].value;
					deck[counterNotCards3].num = counterNotCards3;
					deck[fPositions[7].cardNum].placed = 1;
					deck[fPositions[7].cardNum].display1 = 0;
					deck[fPositions[7].cardNum].display2 = 0;
					deck[fPositions[7].cardNum].type = 0;
					deck[fPositions[7].cardNum].value = 0;
					deck[fPositions[7].cardNum].num = 0;
					counterNotCards3++;
					fPositions[7].cardOnIt = 0;
					fPositions[7].cardValue = 0;
					fPositions[7].cardNum = 0;

					if (fPositions[10].cardOnIt == 1)
					{
						deck[counterNotCards3].type = deck[fPositions[10].cardNum].type;
						deck[counterNotCards3].value = deck[fPositions[10].cardNum].value;
						deck[counterNotCards3].num = counterNotCards3;
						deck[fPositions[10].cardNum].placed = 1;
						deck[fPositions[10].cardNum].display1 = 0;
						deck[fPositions[10].cardNum].display2 = 0;
						deck[fPositions[10].cardNum].type = 0;
						deck[fPositions[10].cardNum].value = 0;
						deck[fPositions[10].cardNum].num = 0;
						counterNotCards3++;
						fPositions[10].cardOnIt = 0;
						fPositions[10].cardValue = 0;
						fPositions[10].cardNum = 0;
					}
					if (fPositions[11].cardOnIt == 1)
					{
						deck[counterNotCards3].type = deck[fPositions[11].cardNum].type;
						deck[counterNotCards3].value = deck[fPositions[11].cardNum].value;
						deck[counterNotCards3].num = counterNotCards3;
						deck[fPositions[11].cardNum].placed = 1;
						deck[fPositions[11].cardNum].display1 = 0;
						deck[fPositions[11].cardNum].display2 = 0;
						deck[fPositions[11].cardNum].type = 0;
						deck[fPositions[11].cardNum].value = 0;
						deck[fPositions[11].cardNum].num = 0;
						counterNotCards3++;
						fPositions[11].cardOnIt = 0;
						fPositions[11].cardValue = 0;
						fPositions[11].cardNum = 0;
						if (fPositions[13].cardOnIt == 1)
						{
							deck[counterNotCards3].type = deck[fPositions[13].cardNum].type;
							deck[counterNotCards3].value = deck[fPositions[13].cardNum].value;
							deck[counterNotCards3].num = counterNotCards3;
							deck[fPositions[13].cardNum].placed = 1;
							deck[fPositions[13].cardNum].display1 = 0;
							deck[fPositions[13].cardNum].display2 = 0;
							deck[fPositions[13].cardNum].type = 0;
							deck[fPositions[13].cardNum].value = 0;
							deck[fPositions[13].cardNum].num = 0;
							counterNotCards3++;
							fPositions[13].cardOnIt = 0;
							fPositions[13].cardValue = 0;
							fPositions[13].cardNum = 0;
						}
						if (fPositions[14].cardOnIt == 1)
						{
							deck[counterNotCards3].type = deck[fPositions[14].cardNum].type;
							deck[counterNotCards3].value = deck[fPositions[14].cardNum].value;
							deck[counterNotCards3].num = counterNotCards3;
							deck[fPositions[14].cardNum].placed = 1;
							deck[fPositions[14].cardNum].display1 = 0;
							deck[fPositions[14].cardNum].display2 = 0;
							deck[fPositions[14].cardNum].type = 0;
							deck[fPositions[14].cardNum].value = 0;
							deck[fPositions[14].cardNum].num = 0;
							counterNotCards3++;
							fPositions[14].cardOnIt = 0;
							fPositions[14].cardValue = 0;
							fPositions[14].cardNum = 0;
						}
					}
				}
			}
		}
		if (fPositions[4].cardOnIt == 1)
		{
			if (deck[fPositions[4].cardNum].type == 'a')
			{
				if ((baseCards[3].value && baseCards[4].value) == fPositions[4].cardValue)
				{
					collapse = 0;
				}
				else
				{
					collapse = 1;
				}
			}
			else if (deck[fPositions[4].cardNum].type == 'o')
			{
				if ((baseCards[3].value || baseCards[4].value) == fPositions[4].cardValue)
				{
					collapse = 0;
				}
				else
				{
					collapse = 1;
				}
			}
			else if (deck[fPositions[4].cardNum].type == 'x')
			{
				if ((baseCards[3].value ^ baseCards[4].value) == fPositions[4].cardValue)
				{
					collapse = 0;
				}
				else
				{
					collapse = 1;
				}
			}
			if (collapse == 1)
			{
				collapse = 0;
				deck[counterNotCards3].type = deck[fPositions[4].cardNum].type;
				deck[counterNotCards3].value = deck[fPositions[4].cardNum].value;
				deck[counterNotCards3].num = counterNotCards3;
				deck[fPositions[4].cardNum].placed = 1;
				deck[fPositions[4].cardNum].display1 = 0;
				deck[fPositions[4].cardNum].display2 = 0;
				deck[fPositions[4].cardNum].type = 0;
				deck[fPositions[4].cardNum].value = 0;
				deck[fPositions[4].cardNum].num = 0;
				counterNotCards3++;
				fPositions[4].cardOnIt = 0;
				fPositions[4].cardValue = 0;
				fPositions[4].cardNum = 0;

				if (fPositions[9].cardOnIt == 1)
				{
					deck[counterNotCards3].type = deck[fPositions[9].cardNum].type;
					deck[counterNotCards3].value = deck[fPositions[9].cardNum].value;
					deck[counterNotCards3].num = counterNotCards3;
					deck[fPositions[9].cardNum].placed = 1;
					deck[fPositions[9].cardNum].display1 = 0;
					deck[fPositions[9].cardNum].display2 = 0;
					deck[fPositions[9].cardNum].type = 0;
					deck[fPositions[9].cardNum].value = 0;
					deck[fPositions[9].cardNum].num = 0;
					counterNotCards3++;
					fPositions[9].cardOnIt = 0;
					fPositions[9].cardValue = 0;
					fPositions[9].cardNum = 0;

					if (fPositions[12].cardOnIt == 1)
					{
						deck[counterNotCards3].type = deck[fPositions[12].cardNum].type;
						deck[counterNotCards3].value = deck[fPositions[12].cardNum].value;
						deck[counterNotCards3].num = counterNotCards3;
						deck[fPositions[12].cardNum].placed = 1;
						deck[fPositions[12].cardNum].display1 = 0;
						deck[fPositions[12].cardNum].display2 = 0;
						deck[fPositions[12].cardNum].type = 0;
						deck[fPositions[12].cardNum].value = 0;
						deck[fPositions[12].cardNum].num = 0;
						counterNotCards3++;
						fPositions[12].cardOnIt = 0;
						fPositions[12].cardValue = 0;
						fPositions[12].cardNum = 0;

						if (fPositions[14].cardOnIt == 1)
						{
							deck[counterNotCards3].type = deck[fPositions[14].cardNum].type;
							deck[counterNotCards3].value = deck[fPositions[14].cardNum].value;
							deck[counterNotCards3].num = counterNotCards3;
							deck[fPositions[14].cardNum].placed = 1;
							deck[fPositions[14].cardNum].display1 = 0;
							deck[fPositions[14].cardNum].display2 = 0;
							deck[fPositions[14].cardNum].type = 0;
							deck[fPositions[14].cardNum].value = 0;
							deck[fPositions[14].cardNum].num = 0;
							counterNotCards3++;
							fPositions[14].cardOnIt = 0;
							fPositions[14].cardValue = 0;
							fPositions[14].cardNum = 0;

						}
					}
				}

				if (fPositions[8].cardOnIt == 1)
				{
					deck[counterNotCards3].type = deck[fPositions[8].cardNum].type;
					deck[counterNotCards3].value = deck[fPositions[8].cardNum].value;
					deck[counterNotCards3].num = counterNotCards3;
					deck[fPositions[8].cardNum].placed = 1;
					deck[fPositions[8].cardNum].display1 = 0;
					deck[fPositions[8].cardNum].display2 = 0;
					deck[fPositions[8].cardNum].type = 0;
					deck[fPositions[8].cardNum].value = 0;
					deck[fPositions[8].cardNum].num = 0;
					counterNotCards3++;
					fPositions[8].cardOnIt = 0;
					fPositions[8].cardValue = 0;
					fPositions[8].cardNum = 0;

					if (fPositions[11].cardOnIt == 1)
					{
						deck[counterNotCards3].type = deck[fPositions[11].cardNum].type;
						deck[counterNotCards3].value = deck[fPositions[11].cardNum].value;
						deck[counterNotCards3].num = counterNotCards3;
						deck[fPositions[11].cardNum].placed = 1;
						deck[fPositions[11].cardNum].display1 = 0;
						deck[fPositions[11].cardNum].display2 = 0;
						deck[fPositions[11].cardNum].type = 0;
						deck[fPositions[11].cardNum].value = 0;
						deck[fPositions[11].cardNum].num = 0;
						counterNotCards3++;
						fPositions[11].cardOnIt = 0;
						fPositions[11].cardValue = 0;
						fPositions[11].cardNum = 0;

						if (fPositions[13].cardOnIt == 1)
						{
							deck[counterNotCards3].type = deck[fPositions[13].cardNum].type;
							deck[counterNotCards3].value = deck[fPositions[13].cardNum].value;
							deck[counterNotCards3].num = counterNotCards3;
							deck[fPositions[13].cardNum].placed = 1;
							deck[fPositions[13].cardNum].display1 = 0;
							deck[fPositions[13].cardNum].display2 = 0;
							deck[fPositions[13].cardNum].type = 0;
							deck[fPositions[13].cardNum].value = 0;
							deck[fPositions[13].cardNum].num = 0;
							counterNotCards3++;
							fPositions[13].cardOnIt = 0;
							fPositions[13].cardValue = 0;
							fPositions[13].cardNum = 0;

						}
					}
				}
			}
		}


		if (fPositions2[3].cardOnIt == 1)
		{
			if (deck[fPositions2[3].cardNum].type == 'a')
			{
				if ((baseCards2[2].value && baseCards2[3].value) == fPositions2[3].cardValue)
				{
					collapse2 = 0;
				}
				else
				{
					collapse2 = 1;
				}
			}
			else if (deck[fPositions2[3].cardNum].type == 'o')
			{
				if ((baseCards2[2].value || baseCards2[3].value) == fPositions2[3].cardValue)
				{
					collapse2 = 0;
				}
				else
				{
					collapse2 = 1;
				}
			}
			else if (deck[fPositions2[3].cardNum].type == 'x')
			{
				if ((baseCards2[2].value ^ baseCards2[3].value) == fPositions2[3].cardValue)
				{
					collapse2 = 0;
				}
				else
				{
					collapse2 = 1;
				}
			}
			if (collapse2 == 1)
			{
				collapse2 = 0;
				deck[counterNotCards3].type = deck[fPositions2[3].cardNum].type;
				deck[counterNotCards3].value = deck[fPositions2[3].cardNum].value;
				deck[counterNotCards3].num = counterNotCards3;
				deck[fPositions2[3].cardNum].placed = 1;
				deck[fPositions2[3].cardNum].display1 = 0;
				deck[fPositions2[3].cardNum].display2 = 0;
				deck[fPositions2[3].cardNum].type = 0;
				deck[fPositions2[3].cardNum].value = 0;
				deck[fPositions2[3].cardNum].num = 0;
				counterNotCards3++;
				fPositions2[3].cardOnIt = 0;
				fPositions2[3].cardValue = 0;
				fPositions2[3].cardNum = 0;

				if (fPositions2[8].cardOnIt == 1)
				{
					deck[counterNotCards3].type = deck[fPositions2[8].cardNum].type;
					deck[counterNotCards3].value = deck[fPositions2[8].cardNum].value;
					deck[counterNotCards3].num = counterNotCards3;
					deck[fPositions2[8].cardNum].placed = 1;
					deck[fPositions2[8].cardNum].display1 = 0;
					deck[fPositions2[8].cardNum].display2 = 0;
					deck[fPositions2[8].cardNum].type = 0;
					deck[fPositions2[8].cardNum].value = 0;
					deck[fPositions2[8].cardNum].num = 0;
					counterNotCards3++;
					fPositions2[8].cardOnIt = 0;
					fPositions2[8].cardValue = 0;
					fPositions2[8].cardNum = 0;

					if (fPositions2[12].cardOnIt == 1)
					{
						deck[counterNotCards3].type = deck[fPositions2[12].cardNum].type;
						deck[counterNotCards3].value = deck[fPositions2[12].cardNum].value;
						deck[counterNotCards3].num = counterNotCards3;
						deck[fPositions2[12].cardNum].placed = 1;
						deck[fPositions2[12].cardNum].display1 = 0;
						deck[fPositions2[12].cardNum].display2 = 0;
						deck[fPositions2[12].cardNum].type = 0;
						deck[fPositions2[12].cardNum].value = 0;
						deck[fPositions2[12].cardNum].num = 0;
						counterNotCards3++;
						fPositions2[12].cardOnIt = 0;
						fPositions2[12].cardValue = 0;
						fPositions2[12].cardNum = 0;
					}
				}
				if (fPositions2[7].cardOnIt == 1)
				{
					deck[counterNotCards3].type = deck[fPositions2[7].cardNum].type;
					deck[counterNotCards3].value = deck[fPositions2[7].cardNum].value;
					deck[counterNotCards3].num = counterNotCards3;
					deck[fPositions2[7].cardNum].placed = 1;
					deck[fPositions2[7].cardNum].display1 = 0;
					deck[fPositions2[7].cardNum].display2 = 0;
					deck[fPositions2[7].cardNum].type = 0;
					deck[fPositions2[7].cardNum].value = 0;
					deck[fPositions2[7].cardNum].num = 0;
					counterNotCards3++;
					fPositions2[7].cardOnIt = 0;
					fPositions2[7].cardValue = 0;
					fPositions2[7].cardNum = 0;

					if (fPositions2[10].cardOnIt == 1)
					{
						deck[counterNotCards3].type = deck[fPositions2[10].cardNum].type;
						deck[counterNotCards3].value = deck[fPositions2[10].cardNum].value;
						deck[counterNotCards3].num = counterNotCards3;
						deck[fPositions2[10].cardNum].placed = 1;
						deck[fPositions2[10].cardNum].display1 = 0;
						deck[fPositions2[10].cardNum].display2 = 0;
						deck[fPositions2[10].cardNum].type = 0;
						deck[fPositions2[10].cardNum].value = 0;
						deck[fPositions2[10].cardNum].num = 0;
						counterNotCards3++;
						fPositions2[10].cardOnIt = 0;
						fPositions2[10].cardValue = 0;
						fPositions2[10].cardNum = 0;
					}
					if (fPositions2[11].cardOnIt == 1)
					{
						deck[counterNotCards3].type = deck[fPositions2[11].cardNum].type;
						deck[counterNotCards3].value = deck[fPositions2[11].cardNum].value;
						deck[counterNotCards3].num = counterNotCards3;
						deck[fPositions2[11].cardNum].placed = 1;
						deck[fPositions2[11].cardNum].display1 = 0;
						deck[fPositions2[11].cardNum].display2 = 0;
						deck[fPositions2[11].cardNum].type = 0;
						deck[fPositions2[11].cardNum].value = 0;
						deck[fPositions2[11].cardNum].num = 0;
						counterNotCards3++;
						fPositions2[11].cardOnIt = 0;
						fPositions2[11].cardValue = 0;
						fPositions2[11].cardNum = 0;
						if (fPositions2[13].cardOnIt == 1)
						{
							deck[counterNotCards3].type = deck[fPositions2[13].cardNum].type;
							deck[counterNotCards3].value = deck[fPositions2[13].cardNum].value;
							deck[counterNotCards3].num = counterNotCards3;
							deck[fPositions2[13].cardNum].placed = 1;
							deck[fPositions2[13].cardNum].display1 = 0;
							deck[fPositions2[13].cardNum].display2 = 0;
							deck[fPositions2[13].cardNum].type = 0;
							deck[fPositions2[13].cardNum].value = 0;
							deck[fPositions2[13].cardNum].num = 0;
							counterNotCards3++;
							fPositions2[13].cardOnIt = 0;
							fPositions2[13].cardValue = 0;
							fPositions2[13].cardNum = 0;
						}
						if (fPositions2[14].cardOnIt == 1)
						{
							deck[counterNotCards3].type = deck[fPositions2[14].cardNum].type;
							deck[counterNotCards3].value = deck[fPositions2[14].cardNum].value;
							deck[counterNotCards3].num = counterNotCards3;
							deck[fPositions2[14].cardNum].placed = 1;
							deck[fPositions2[14].cardNum].display1 = 0;
							deck[fPositions2[14].cardNum].display2 = 0;
							deck[fPositions2[14].cardNum].type = 0;
							deck[fPositions2[14].cardNum].value = 0;
							deck[fPositions2[14].cardNum].num = 0;
							counterNotCards3++;
							fPositions2[14].cardOnIt = 0;
							fPositions2[14].cardValue = 0;
							fPositions2[14].cardNum = 0;
						}
					}
				}
			}
		}
		if (fPositions2[4].cardOnIt == 1)
		{
			if (deck[fPositions2[4].cardNum].type == 'a')
			{
				if ((baseCards2[3].value && baseCards2[4].value) == fPositions2[4].cardValue)
				{
					collapse2 = 0;
				}
				else
				{
					collapse2 = 1;
				}
			}
			else if (deck[fPositions2[4].cardNum].type == 'o')
			{
				if ((baseCards2[3].value || baseCards2[4].value) == fPositions2[4].cardValue)
				{
					collapse2 = 0;
				}
				else
				{
					collapse2 = 1;
				}
			}
			else if (deck[fPositions2[4].cardNum].type == 'x')
			{
				if ((baseCards2[3].value ^ baseCards2[4].value) == fPositions2[4].cardValue)
				{
					collapse2 = 0;
				}
				else
				{
					collapse2 = 1;
				}
			}
			if (collapse2 == 1)
			{
				collapse2 = 0;
				deck[counterNotCards3].type = deck[fPositions2[4].cardNum].type;
				deck[counterNotCards3].value = deck[fPositions2[4].cardNum].value;
				deck[counterNotCards3].num = counterNotCards3;
				deck[fPositions2[4].cardNum].placed = 1;
				deck[fPositions2[4].cardNum].display1 = 0;
				deck[fPositions2[4].cardNum].display2 = 0;
				deck[fPositions2[4].cardNum].type = 0;
				deck[fPositions2[4].cardNum].value = 0;
				deck[fPositions2[4].cardNum].num = 0;
				counterNotCards3++;
				fPositions2[4].cardOnIt = 0;
				fPositions2[4].cardValue = 0;
				fPositions2[4].cardNum = 0;

				if (fPositions2[9].cardOnIt == 1)
				{
					deck[counterNotCards3].type = deck[fPositions2[9].cardNum].type;
					deck[counterNotCards3].value = deck[fPositions2[9].cardNum].value;
					deck[counterNotCards3].num = counterNotCards3;
					deck[fPositions2[9].cardNum].placed = 1;
					deck[fPositions2[9].cardNum].display1 = 0;
					deck[fPositions2[9].cardNum].display2 = 0;
					deck[fPositions2[9].cardNum].type = 0;
					deck[fPositions2[9].cardNum].value = 0;
					deck[fPositions2[9].cardNum].num = 0;
					counterNotCards3++;
					fPositions2[9].cardOnIt = 0;
					fPositions2[9].cardValue = 0;
					fPositions2[9].cardNum = 0;

					if (fPositions2[12].cardOnIt == 1)
					{
						deck[counterNotCards3].type = deck[fPositions2[12].cardNum].type;
						deck[counterNotCards3].value = deck[fPositions2[12].cardNum].value;
						deck[counterNotCards3].num = counterNotCards3;
						deck[fPositions2[12].cardNum].placed = 1;
						deck[fPositions2[12].cardNum].display1 = 0;
						deck[fPositions2[12].cardNum].display2 = 0;
						deck[fPositions2[12].cardNum].type = 0;
						deck[fPositions2[12].cardNum].value = 0;
						deck[fPositions2[12].cardNum].num = 0;
						counterNotCards3++;
						fPositions2[12].cardOnIt = 0;
						fPositions2[12].cardValue = 0;
						fPositions2[12].cardNum = 0;

						if (fPositions2[14].cardOnIt == 1)
						{
							deck[counterNotCards3].type = deck[fPositions2[14].cardNum].type;
							deck[counterNotCards3].value = deck[fPositions2[14].cardNum].value;
							deck[counterNotCards3].num = counterNotCards3;
							deck[fPositions2[14].cardNum].placed = 1;
							deck[fPositions2[14].cardNum].display1 = 0;
							deck[fPositions2[14].cardNum].display2 = 0;
							deck[fPositions2[14].cardNum].type = 0;
							deck[fPositions2[14].cardNum].value = 0;
							deck[fPositions2[14].cardNum].num = 0;
							counterNotCards3++;
							fPositions2[14].cardOnIt = 0;
							fPositions2[14].cardValue = 0;
							fPositions2[14].cardNum = 0;

						}
					}
				}

				if (fPositions2[8].cardOnIt == 1)
				{
					deck[counterNotCards3].type = deck[fPositions2[8].cardNum].type;
					deck[counterNotCards3].value = deck[fPositions2[8].cardNum].value;
					deck[counterNotCards3].num = counterNotCards3;
					deck[fPositions2[8].cardNum].placed = 1;
					deck[fPositions2[8].cardNum].display1 = 0;
					deck[fPositions2[8].cardNum].display2 = 0;
					deck[fPositions2[8].cardNum].type = 0;
					deck[fPositions2[8].cardNum].value = 0;
					deck[fPositions2[8].cardNum].num = 0;
					counterNotCards3++;
					fPositions2[8].cardOnIt = 0;
					fPositions2[8].cardValue = 0;
					fPositions2[8].cardNum = 0;

					if (fPositions2[11].cardOnIt == 1)
					{
						deck[counterNotCards3].type = deck[fPositions2[11].cardNum].type;
						deck[counterNotCards3].value = deck[fPositions2[11].cardNum].value;
						deck[counterNotCards3].num = counterNotCards3;
						deck[fPositions2[11].cardNum].placed = 1;
						deck[fPositions2[11].cardNum].display1 = 0;
						deck[fPositions2[11].cardNum].display2 = 0;
						deck[fPositions2[11].cardNum].type = 0;
						deck[fPositions2[11].cardNum].value = 0;
						deck[fPositions2[11].cardNum].num = 0;
						counterNotCards3++;
						fPositions2[11].cardOnIt = 0;
						fPositions2[11].cardValue = 0;
						fPositions2[11].cardNum = 0;

						if (fPositions2[13].cardOnIt == 1)
						{
							deck[counterNotCards3].type = deck[fPositions2[13].cardNum].type;
							deck[counterNotCards3].value = deck[fPositions2[13].cardNum].value;
							deck[counterNotCards3].num = counterNotCards3;
							deck[fPositions2[13].cardNum].placed = 1;
							deck[fPositions2[13].cardNum].display1 = 0;
							deck[fPositions2[13].cardNum].display2 = 0;
							deck[fPositions2[13].cardNum].type = 0;
							deck[fPositions2[13].cardNum].value = 0;
							deck[fPositions2[13].cardNum].num = 0;
							counterNotCards3++;
							fPositions2[13].cardOnIt = 0;
							fPositions2[13].cardValue = 0;
							fPositions2[13].cardNum = 0;

						}
					}
				}
			}
		}
		break;
	case 4:
		if (fPositions[4].cardOnIt == 1)
		{
			if (deck[fPositions[4].cardNum].type == 'a')
			{
				if ((baseCards[3].value && baseCards[4].value) == fPositions[4].cardValue)
				{
					collapse = 0;
				}
				else
				{
					collapse = 1;
				}
			}
			else if (deck[fPositions[4].cardNum].type == 'o')
			{
				if ((baseCards[3].value || baseCards[4].value) == fPositions[4].cardValue)
				{
					collapse = 0;
				}
				else
				{
					collapse = 1;
				}
			}
			else if (deck[fPositions[4].cardNum].type == 'x')
			{
				if ((baseCards[3].value ^ baseCards[4].value) == fPositions[4].cardValue)
				{
					collapse = 0;
				}
				else
				{
					collapse = 1;
				}
			}
			if (collapse == 1)
			{
				collapse = 0;
				deck[counterNotCards3].type = deck[fPositions[4].cardNum].type;
				deck[counterNotCards3].value = deck[fPositions[4].cardNum].value;
				deck[counterNotCards3].num = counterNotCards3;
				deck[fPositions[4].cardNum].placed = 1;
				deck[fPositions[4].cardNum].display1 = 0;
				deck[fPositions[4].cardNum].display2 = 0;
				deck[fPositions[4].cardNum].type = 0;
				deck[fPositions[4].cardNum].value = 0;
				deck[fPositions[4].cardNum].num = 0;
				counterNotCards3++;
				fPositions[4].cardOnIt = 0;
				fPositions[4].cardValue = 0;
				fPositions[4].cardNum = 0;

				if (fPositions[8].cardOnIt == 1)
				{
					deck[counterNotCards3].type = deck[fPositions[8].cardNum].type;
					deck[counterNotCards3].value = deck[fPositions[8].cardNum].value;
					deck[counterNotCards3].num = counterNotCards3;
					deck[fPositions[8].cardNum].placed = 1;
					deck[fPositions[8].cardNum].display1 = 0;
					deck[fPositions[8].cardNum].display2 = 0;
					deck[fPositions[8].cardNum].type = 0;
					deck[fPositions[8].cardNum].value = 0;
					deck[fPositions[8].cardNum].num = 0;
					counterNotCards3++;
					fPositions[8].cardOnIt = 0;
					fPositions[8].cardValue = 0;
					fPositions[8].cardNum = 0;

					if (fPositions[11].cardOnIt == 1)
					{
						deck[counterNotCards3].type = deck[fPositions[11].cardNum].type;
						deck[counterNotCards3].value = deck[fPositions[11].cardNum].value;
						deck[counterNotCards3].num = counterNotCards3;
						deck[fPositions[11].cardNum].placed = 1;
						deck[fPositions[11].cardNum].display1 = 0;
						deck[fPositions[11].cardNum].display2 = 0;
						deck[fPositions[11].cardNum].type = 0;
						deck[fPositions[11].cardNum].value = 0;
						deck[fPositions[11].cardNum].num = 0;
						counterNotCards3++;
						fPositions[11].cardOnIt = 0;
						fPositions[11].cardValue = 0;
						fPositions[11].cardNum = 0;

						if (fPositions[13].cardOnIt == 1)
						{
							deck[counterNotCards3].type = deck[fPositions[13].cardNum].type;
							deck[counterNotCards3].value = deck[fPositions[13].cardNum].value;
							deck[counterNotCards3].num = counterNotCards3;
							deck[fPositions[13].cardNum].placed = 1;
							deck[fPositions[13].cardNum].display1 = 0;
							deck[fPositions[13].cardNum].display2 = 0;
							deck[fPositions[13].cardNum].type = 0;
							deck[fPositions[13].cardNum].value = 0;
							deck[fPositions[13].cardNum].num = 0;
							counterNotCards3++;
							fPositions[13].cardOnIt = 0;
							fPositions[13].cardValue = 0;
							fPositions[13].cardNum = 0;

						}
					}
				}
				if (fPositions[9].cardOnIt == 1)
				{
					deck[counterNotCards3].type = deck[fPositions[9].cardNum].type;
					deck[counterNotCards3].value = deck[fPositions[9].cardNum].value;
					deck[counterNotCards3].num = counterNotCards3;
					deck[fPositions[9].cardNum].placed = 1;
					deck[fPositions[9].cardNum].display1 = 0;
					deck[fPositions[9].cardNum].display2 = 0;
					deck[fPositions[9].cardNum].type = 0;
					deck[fPositions[9].cardNum].value = 0;
					deck[fPositions[9].cardNum].num = 0;
					counterNotCards3++;
					fPositions[9].cardOnIt = 0;
					fPositions[9].cardValue = 0;
					fPositions[9].cardNum = 0;

					if (fPositions[12].cardOnIt == 1)
					{
						deck[counterNotCards3].type = deck[fPositions[12].cardNum].type;
						deck[counterNotCards3].value = deck[fPositions[12].cardNum].value;
						deck[counterNotCards3].num = counterNotCards3;
						deck[fPositions[12].cardNum].placed = 1;
						deck[fPositions[12].cardNum].display1 = 0;
						deck[fPositions[12].cardNum].display2 = 0;
						deck[fPositions[12].cardNum].type = 0;
						deck[fPositions[12].cardNum].value = 0;
						deck[fPositions[12].cardNum].num = 0;
						counterNotCards3++;
						fPositions[12].cardOnIt = 0;
						fPositions[12].cardValue = 0;
						fPositions[12].cardNum = 0;

						if (fPositions[14].cardOnIt == 1)
						{
							deck[counterNotCards3].type = deck[fPositions[14].cardNum].type;
							deck[counterNotCards3].value = deck[fPositions[14].cardNum].value;
							deck[counterNotCards3].num = counterNotCards3;
							deck[fPositions[14].cardNum].placed = 1;
							deck[fPositions[14].cardNum].display1 = 0;
							deck[fPositions[14].cardNum].display2 = 0;
							deck[fPositions[14].cardNum].type = 0;
							deck[fPositions[14].cardNum].value = 0;
							deck[fPositions[14].cardNum].num = 0;
							counterNotCards3++;
							fPositions[14].cardOnIt = 0;
							fPositions[14].cardValue = 0;
							fPositions[14].cardNum = 0;

						}
					}
				}
			}
		}
		
		if (fPositions[5].cardOnIt == 1)
		{
			if (deck[fPositions[5].cardNum].type == 'a')
			{
				if ((baseCards[4].value && baseCards[5].value) == fPositions[5].cardValue)
				{
					collapse = 0;
				}
				else
				{
					collapse = 1;
				}
			}
			else if (deck[fPositions[5].cardNum].type == 'o')
			{
				if ((baseCards[4].value || baseCards[5].value) == fPositions[5].cardValue)
				{
					collapse = 0;
				}
				else
				{
					collapse = 1;
				}
			}
			else if (deck[fPositions[5].cardNum].type == 'x')
			{
				if ((baseCards[4].value ^ baseCards[5].value) == fPositions[5].cardValue)
				{
					collapse = 0;
				}
				else
				{
					collapse = 1;
				}
			}
			if (collapse == 1)
			{
				collapse = 0;
				deck[counterNotCards3].type = deck[fPositions[5].cardNum].type;
				deck[counterNotCards3].value = deck[fPositions[5].cardNum].value;
				deck[counterNotCards3].num = counterNotCards3;
				deck[fPositions[5].cardNum].placed = 1;
				deck[fPositions[5].cardNum].display1 = 0;
				deck[fPositions[5].cardNum].display2 = 0;
				deck[fPositions[5].cardNum].type = 0;
				deck[fPositions[5].cardNum].value = 0;
				deck[fPositions[5].cardNum].num = 0;
				counterNotCards3++;
				fPositions[5].cardOnIt = 0;
				fPositions[5].cardValue = 0;
				fPositions[5].cardNum = 0;

				if (fPositions[9].cardOnIt == 1)
				{
					deck[counterNotCards3].type = deck[fPositions[9].cardNum].type;
					deck[counterNotCards3].value = deck[fPositions[9].cardNum].value;
					deck[counterNotCards3].num = counterNotCards3;
					deck[fPositions[9].cardNum].placed = 1;
					deck[fPositions[9].cardNum].display1 = 0;
					deck[fPositions[9].cardNum].display2 = 0;
					deck[fPositions[9].cardNum].type = 0;
					deck[fPositions[9].cardNum].value = 0;
					deck[fPositions[9].cardNum].num = 0;
					counterNotCards3++;
					fPositions[9].cardOnIt = 0;
					fPositions[9].cardValue = 0;
					fPositions[9].cardNum = 0;

					if (fPositions[12].cardOnIt == 1)
					{
						deck[counterNotCards3].type = deck[fPositions[12].cardNum].type;
						deck[counterNotCards3].value = deck[fPositions[12].cardNum].value;
						deck[counterNotCards3].num = counterNotCards3;
						deck[fPositions[12].cardNum].placed = 1;
						deck[fPositions[12].cardNum].display1 = 0;
						deck[fPositions[12].cardNum].display2 = 0;
						deck[fPositions[12].cardNum].type = 0;
						deck[fPositions[12].cardNum].value = 0;
						deck[fPositions[12].cardNum].num = 0;
						counterNotCards3++;
						fPositions[12].cardOnIt = 0;
						fPositions[12].cardValue = 0;
						fPositions[12].cardNum = 0;

						if (fPositions[14].cardOnIt == 1)
						{
							deck[counterNotCards3].type = deck[fPositions[14].cardNum].type;
							deck[counterNotCards3].value = deck[fPositions[14].cardNum].value;
							deck[counterNotCards3].num = counterNotCards3;
							deck[fPositions[14].cardNum].placed = 1;
							deck[fPositions[14].cardNum].display1 = 0;
							deck[fPositions[14].cardNum].display2 = 0;
							deck[fPositions[14].cardNum].type = 0;
							deck[fPositions[14].cardNum].value = 0;
							deck[fPositions[14].cardNum].num = 0;
							counterNotCards3++;
							fPositions[14].cardOnIt = 0;
							fPositions[14].cardValue = 0;
							fPositions[14].cardNum = 0;

						}
					}
				}
			}
		}

		if (fPositions2[4].cardOnIt == 1)
		{
			if (deck[fPositions2[4].cardNum].type == 'a')
			{
				if ((baseCards2[3].value && baseCards2[4].value) == fPositions2[4].cardValue)
				{
					collapse2 = 0;
				}
				else
				{
					collapse2 = 1;
				}
			}
			else if (deck[fPositions2[4].cardNum].type == 'o')
			{
				if ((baseCards2[3].value || baseCards2[4].value) == fPositions2[4].cardValue)
				{
					collapse2 = 0;
				}
				else
				{
					collapse2 = 1;
				}
			}
			else if (deck[fPositions2[4].cardNum].type == 'x')
			{
				if ((baseCards2[3].value ^ baseCards2[4].value) == fPositions2[4].cardValue)
				{
					collapse2 = 0;
				}
				else
				{
					collapse2 = 1;
				}
			}
			if (collapse2 == 1)
			{
				collapse2 = 0;
				deck[counterNotCards3].type = deck[fPositions2[4].cardNum].type;
				deck[counterNotCards3].value = deck[fPositions2[4].cardNum].value;
				deck[counterNotCards3].num = counterNotCards3;
				deck[fPositions2[4].cardNum].placed = 1;
				deck[fPositions2[4].cardNum].display1 = 0;
				deck[fPositions2[4].cardNum].display2 = 0;
				deck[fPositions2[4].cardNum].type = 0;
				deck[fPositions2[4].cardNum].value = 0;
				deck[fPositions2[4].cardNum].num = 0;
				counterNotCards3++;
				fPositions2[4].cardOnIt = 0;
				fPositions2[4].cardValue = 0;
				fPositions2[4].cardNum = 0;

				if (fPositions2[8].cardOnIt == 1)
				{
					deck[counterNotCards3].type = deck[fPositions2[8].cardNum].type;
					deck[counterNotCards3].value = deck[fPositions2[8].cardNum].value;
					deck[counterNotCards3].num = counterNotCards3;
					deck[fPositions2[8].cardNum].placed = 1;
					deck[fPositions2[8].cardNum].display1 = 0;
					deck[fPositions2[8].cardNum].display2 = 0;
					deck[fPositions2[8].cardNum].type = 0;
					deck[fPositions2[8].cardNum].value = 0;
					deck[fPositions2[8].cardNum].num = 0;
					counterNotCards3++;
					fPositions2[8].cardOnIt = 0;
					fPositions2[8].cardValue = 0;
					fPositions2[8].cardNum = 0;

					if (fPositions2[11].cardOnIt == 1)
					{
						deck[counterNotCards3].type = deck[fPositions2[11].cardNum].type;
						deck[counterNotCards3].value = deck[fPositions2[11].cardNum].value;
						deck[counterNotCards3].num = counterNotCards3;
						deck[fPositions2[11].cardNum].placed = 1;
						deck[fPositions2[11].cardNum].display1 = 0;
						deck[fPositions2[11].cardNum].display2 = 0;
						deck[fPositions2[11].cardNum].type = 0;
						deck[fPositions2[11].cardNum].value = 0;
						deck[fPositions2[11].cardNum].num = 0;
						counterNotCards3++;
						fPositions2[11].cardOnIt = 0;
						fPositions2[11].cardValue = 0;
						fPositions2[11].cardNum = 0;

						if (fPositions2[13].cardOnIt == 1)
						{
							deck[counterNotCards3].type = deck[fPositions2[13].cardNum].type;
							deck[counterNotCards3].value = deck[fPositions2[13].cardNum].value;
							deck[counterNotCards3].num = counterNotCards3;
							deck[fPositions2[13].cardNum].placed = 1;
							deck[fPositions2[13].cardNum].display1 = 0;
							deck[fPositions2[13].cardNum].display2 = 0;
							deck[fPositions2[13].cardNum].type = 0;
							deck[fPositions2[13].cardNum].value = 0;
							deck[fPositions2[13].cardNum].num = 0;
							counterNotCards3++;
							fPositions2[13].cardOnIt = 0;
							fPositions2[13].cardValue = 0;
							fPositions2[13].cardNum = 0;

						}
					}
				}
				if (fPositions2[9].cardOnIt == 1)
				{
					deck[counterNotCards3].type = deck[fPositions2[9].cardNum].type;
					deck[counterNotCards3].value = deck[fPositions2[9].cardNum].value;
					deck[counterNotCards3].num = counterNotCards3;
					deck[fPositions2[9].cardNum].placed = 1;
					deck[fPositions2[9].cardNum].display1 = 0;
					deck[fPositions2[9].cardNum].display2 = 0;
					deck[fPositions2[9].cardNum].type = 0;
					deck[fPositions2[9].cardNum].value = 0;
					deck[fPositions2[9].cardNum].num = 0;
					counterNotCards3++;
					fPositions2[9].cardOnIt = 0;
					fPositions2[9].cardValue = 0;
					fPositions2[9].cardNum = 0;

					if (fPositions2[12].cardOnIt == 1)
					{
						deck[counterNotCards3].type = deck[fPositions2[12].cardNum].type;
						deck[counterNotCards3].value = deck[fPositions2[12].cardNum].value;
						deck[counterNotCards3].num = counterNotCards3;
						deck[fPositions2[12].cardNum].placed = 1;
						deck[fPositions2[12].cardNum].display1 = 0;
						deck[fPositions2[12].cardNum].display2 = 0;
						deck[fPositions2[12].cardNum].type = 0;
						deck[fPositions2[12].cardNum].value = 0;
						deck[fPositions2[12].cardNum].num = 0;
						counterNotCards3++;
						fPositions2[12].cardOnIt = 0;
						fPositions2[12].cardValue = 0;
						fPositions2[12].cardNum = 0;

						if (fPositions2[14].cardOnIt == 1)
						{
							deck[counterNotCards3].type = deck[fPositions2[14].cardNum].type;
							deck[counterNotCards3].value = deck[fPositions2[14].cardNum].value;
							deck[counterNotCards3].num = counterNotCards3;
							deck[fPositions2[14].cardNum].placed = 1;
							deck[fPositions2[14].cardNum].display1 = 0;
							deck[fPositions2[14].cardNum].display2 = 0;
							deck[fPositions2[14].cardNum].type = 0;
							deck[fPositions2[14].cardNum].value = 0;
							deck[fPositions2[14].cardNum].num = 0;
							counterNotCards3++;
							fPositions2[14].cardOnIt = 0;
							fPositions2[14].cardValue = 0;
							fPositions2[14].cardNum = 0;

						}
					}
				}
			}
		}

		if (fPositions2[5].cardOnIt == 1)
		{
			if (deck[fPositions2[5].cardNum].type == 'a')
			{
				if ((baseCards2[4].value && baseCards2[5].value) == fPositions2[5].cardValue)
				{
					collapse2 = 0;
				}
				else
				{
					collapse2 = 1;
				}
			}
			else if (deck[fPositions2[5].cardNum].type == 'o')
			{
				if ((baseCards2[4].value || baseCards2[5].value) == fPositions2[5].cardValue)
				{
					collapse2 = 0;
				}
				else
				{
					collapse2 = 1;
				}
			}
			else if (deck[fPositions2[5].cardNum].type == 'x')
			{
				if ((baseCards2[4].value ^ baseCards2[5].value) == fPositions2[5].cardValue)
				{
					collapse2 = 0;
				}
				else
				{
					collapse2 = 1;
				}
			}
			if (collapse2 == 1)
			{
				collapse2 = 0;
				deck[counterNotCards3].type = deck[fPositions2[5].cardNum].type;
				deck[counterNotCards3].value = deck[fPositions2[5].cardNum].value;
				deck[counterNotCards3].num = counterNotCards3;
				deck[fPositions2[5].cardNum].placed = 1;
				deck[fPositions2[5].cardNum].display1 = 0;
				deck[fPositions2[5].cardNum].display2 = 0;
				deck[fPositions2[5].cardNum].type = 0;
				deck[fPositions2[5].cardNum].value = 0;
				deck[fPositions2[5].cardNum].num = 0;
				counterNotCards3++;
				fPositions2[5].cardOnIt = 0;
				fPositions2[5].cardValue = 0;
				fPositions2[5].cardNum = 0;

				if (fPositions2[9].cardOnIt == 1)
				{
					deck[counterNotCards3].type = deck[fPositions2[9].cardNum].type;
					deck[counterNotCards3].value = deck[fPositions2[9].cardNum].value;
					deck[counterNotCards3].num = counterNotCards3;
					deck[fPositions2[9].cardNum].placed = 1;
					deck[fPositions2[9].cardNum].display1 = 0;
					deck[fPositions2[9].cardNum].display2 = 0;
					deck[fPositions2[9].cardNum].type = 0;
					deck[fPositions2[9].cardNum].value = 0;
					deck[fPositions2[9].cardNum].num = 0;
					counterNotCards3++;
					fPositions2[9].cardOnIt = 0;
					fPositions2[9].cardValue = 0;
					fPositions2[9].cardNum = 0;

					if (fPositions2[12].cardOnIt == 1)
					{
						deck[counterNotCards3].type = deck[fPositions2[12].cardNum].type;
						deck[counterNotCards3].value = deck[fPositions2[12].cardNum].value;
						deck[counterNotCards3].num = counterNotCards3;
						deck[fPositions2[12].cardNum].placed = 1;
						deck[fPositions2[12].cardNum].display1 = 0;
						deck[fPositions2[12].cardNum].display2 = 0;
						deck[fPositions2[12].cardNum].type = 0;
						deck[fPositions2[12].cardNum].value = 0;
						deck[fPositions2[12].cardNum].num = 0;
						counterNotCards3++;
						fPositions2[12].cardOnIt = 0;
						fPositions2[12].cardValue = 0;
						fPositions2[12].cardNum = 0;

						if (fPositions2[14].cardOnIt == 1)
						{
							deck[counterNotCards3].type = deck[fPositions2[14].cardNum].type;
							deck[counterNotCards3].value = deck[fPositions2[14].cardNum].value;
							deck[counterNotCards3].num = counterNotCards3;
							deck[fPositions2[14].cardNum].placed = 1;
							deck[fPositions2[14].cardNum].display1 = 0;
							deck[fPositions2[14].cardNum].display2 = 0;
							deck[fPositions2[14].cardNum].type = 0;
							deck[fPositions2[14].cardNum].value = 0;
							deck[fPositions2[14].cardNum].num = 0;
							counterNotCards3++;
							fPositions2[14].cardOnIt = 0;
							fPositions2[14].cardValue = 0;
							fPositions2[14].cardNum = 0;

						}
					}
				}
			}
		}
		break;
	case 5:
		if (fPositions[5].cardOnIt == 1)
		{
			if (deck[fPositions[5].cardNum].type == 'a')
			{
				if ((baseCards[4].value && baseCards[5].value) == fPositions[5].cardValue)
				{
					collapse = 0;
				}
				else
				{
					collapse = 1;
				}
			}
			else if (deck[fPositions[5].cardNum].type == 'o')
			{
				if ((baseCards[4].value || baseCards[5].value) == fPositions[5].cardValue)
				{
					collapse = 0;
				}
				else
				{
					collapse = 1;
				}
			}
			else if (deck[fPositions[5].cardNum].type == 'x')
			{
				if ((baseCards[4].value ^ baseCards[5].value) == fPositions[5].cardValue)
				{
					collapse = 0;
				}
				else
				{
					collapse = 1;
				}
			}
			if (collapse == 1)
			{
				collapse = 0;
				deck[counterNotCards3].type = deck[fPositions[5].cardNum].type;
				deck[counterNotCards3].value = deck[fPositions[5].cardNum].value;
				deck[counterNotCards3].num = counterNotCards3;
				deck[fPositions[5].cardNum].placed = 1;
				deck[fPositions[5].cardNum].display1 = 0;
				deck[fPositions[5].cardNum].display2 = 0;
				deck[fPositions[5].cardNum].type = 0;
				deck[fPositions[5].cardNum].value = 0;
				deck[fPositions[5].cardNum].num = 0;
				counterNotCards3++;
				fPositions[5].cardOnIt = 0;
				fPositions[5].cardValue = 0;
				fPositions[5].cardNum = 0;

				if (fPositions[9].cardOnIt == 1)
				{
					deck[counterNotCards3].type = deck[fPositions[9].cardNum].type;
					deck[counterNotCards3].value = deck[fPositions[9].cardNum].value;
					deck[counterNotCards3].num = counterNotCards3;
					deck[fPositions[9].cardNum].placed = 1;
					deck[fPositions[9].cardNum].display1 = 0;
					deck[fPositions[9].cardNum].display2 = 0;
					deck[fPositions[9].cardNum].type = 0;
					deck[fPositions[9].cardNum].value = 0;
					deck[fPositions[9].cardNum].num = 0;
					counterNotCards3++;
					fPositions[9].cardOnIt = 0;
					fPositions[9].cardValue = 0;
					fPositions[9].cardNum = 0;

					if (fPositions[12].cardOnIt == 1)
					{
						deck[counterNotCards3].type = deck[fPositions[12].cardNum].type;
						deck[counterNotCards3].value = deck[fPositions[12].cardNum].value;
						deck[counterNotCards3].num = counterNotCards3;
						deck[fPositions[12].cardNum].placed = 1;
						deck[fPositions[12].cardNum].display1 = 0;
						deck[fPositions[12].cardNum].display2 = 0;
						deck[fPositions[12].cardNum].type = 0;
						deck[fPositions[12].cardNum].value = 0;
						deck[fPositions[12].cardNum].num = 0;
						counterNotCards3++;
						fPositions[12].cardOnIt = 0;
						fPositions[12].cardValue = 0;
						fPositions[12].cardNum = 0;

						if (fPositions[14].cardOnIt == 1)
						{
							deck[counterNotCards3].type = deck[fPositions[14].cardNum].type;
							deck[counterNotCards3].value = deck[fPositions[14].cardNum].value;
							deck[counterNotCards3].num = counterNotCards3;
							deck[fPositions[14].cardNum].placed = 1;
							deck[fPositions[14].cardNum].display1 = 0;
							deck[fPositions[14].cardNum].display2 = 0;
							deck[fPositions[14].cardNum].type = 0;
							deck[fPositions[14].cardNum].value = 0;
							deck[fPositions[14].cardNum].num = 0;
							counterNotCards3++;
							fPositions[14].cardOnIt = 0;
							fPositions[14].cardValue = 0;
							fPositions[14].cardNum = 0;

						}
					}
				}
			}
		}
		if (fPositions2[5].cardOnIt == 1)
		{
			if (deck[fPositions2[5].cardNum].type == 'a')
			{
				if ((baseCards2[4].value && baseCards2[5].value) == fPositions2[5].cardValue)
				{
					collapse2 = 0;
				}
				else
				{
					collapse2 = 1;
				}
			}
			else if (deck[fPositions2[5].cardNum].type == 'o')
			{
				if ((baseCards2[4].value || baseCards2[5].value) == fPositions2[5].cardValue)
				{
					collapse2 = 0;
				}
				else
				{
					collapse2 = 1;
				}
			}
			else if (deck[fPositions2[5].cardNum].type == 'x')
			{
				if ((baseCards2[4].value ^ baseCards2[5].value) == fPositions2[5].cardValue)
				{
					collapse2 = 0;
				}
				else
				{
					collapse2 = 1;
				}
			}
			if (collapse2 == 1)
			{
				collapse2 = 0;
				deck[counterNotCards3].type = deck[fPositions2[5].cardNum].type;
				deck[counterNotCards3].value = deck[fPositions2[5].cardNum].value;
				deck[counterNotCards3].num = counterNotCards3;
				deck[fPositions2[5].cardNum].placed = 1;
				deck[fPositions2[5].cardNum].display1 = 0;
				deck[fPositions2[5].cardNum].display2 = 0;
				deck[fPositions2[5].cardNum].type = 0;
				deck[fPositions2[5].cardNum].value = 0;
				deck[fPositions2[5].cardNum].num = 0;
				counterNotCards3++;
				fPositions2[5].cardOnIt = 0;
				fPositions2[5].cardValue = 0;
				fPositions2[5].cardNum = 0;

				if (fPositions2[9].cardOnIt == 1)
				{
					deck[counterNotCards3].type = deck[fPositions2[9].cardNum].type;
					deck[counterNotCards3].value = deck[fPositions2[9].cardNum].value;
					deck[counterNotCards3].num = counterNotCards3;
					deck[fPositions2[9].cardNum].placed = 1;
					deck[fPositions2[9].cardNum].display1 = 0;
					deck[fPositions2[9].cardNum].display2 = 0;
					deck[fPositions2[9].cardNum].type = 0;
					deck[fPositions2[9].cardNum].value = 0;
					deck[fPositions2[9].cardNum].num = 0;
					counterNotCards3++;
					fPositions2[9].cardOnIt = 0;
					fPositions2[9].cardValue = 0;
					fPositions2[9].cardNum = 0;

					if (fPositions2[12].cardOnIt == 1)
					{
						deck[counterNotCards3].type = deck[fPositions2[12].cardNum].type;
						deck[counterNotCards3].value = deck[fPositions2[12].cardNum].value;
						deck[counterNotCards3].num = counterNotCards3;
						deck[fPositions2[12].cardNum].placed = 1;
						deck[fPositions2[12].cardNum].display1 = 0;
						deck[fPositions2[12].cardNum].display2 = 0;
						deck[fPositions2[12].cardNum].type = 0;
						deck[fPositions2[12].cardNum].value = 0;
						deck[fPositions2[12].cardNum].num = 0;
						counterNotCards3++;
						fPositions2[12].cardOnIt = 0;
						fPositions2[12].cardValue = 0;
						fPositions2[12].cardNum = 0;

						if (fPositions2[14].cardOnIt == 1)
						{
							deck[counterNotCards3].type = deck[fPositions2[14].cardNum].type;
							deck[counterNotCards3].value = deck[fPositions2[14].cardNum].value;
							deck[counterNotCards3].num = counterNotCards3;
							deck[fPositions2[14].cardNum].placed = 1;
							deck[fPositions2[14].cardNum].display1 = 0;
							deck[fPositions2[14].cardNum].display2 = 0;
							deck[fPositions2[14].cardNum].type = 0;
							deck[fPositions2[14].cardNum].value = 0;
							deck[fPositions2[14].cardNum].num = 0;
							counterNotCards3++;
							fPositions2[14].cardOnIt = 0;
							fPositions2[14].cardValue = 0;
							fPositions2[14].cardNum = 0;

						}
					}
				}
			}
		}
		break;
	}
}

void Game::setNotCardImages(sf::Vector2i cursorpos)
{
	int numCounter = 1;

	for (int i = 1; i <= counterNotCards3; i++)
	{
		if (deck[i].display1 == 1 && counter == 1)
		{
			if (deck[i].player1pos == 1)
			{
				if (player1Pos1 == i && !(card2Dragging || card3Dragging || card4Dragging || card5Dragging) && !(roundPlayed))  // Display and drag The first card
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
					if (deck[i].type == 'n')
					{
						if (deck[i].drag && deck[i].type == 'n')
						{
							int x = cursorpos.x + 50;
							int y = cursorpos.y - 52;
							card1Dragging = 1;
							showNotA = 1;

							if (getMousePos(300, 0, 6, *this->window))
							{
								x = cursorpos.x - 52;
								y = cursorpos.y - 30;
								deck[i].img.setRotation(360.f);
								for (int j = 0; j < 6; j++)
								{
									if (getMousePos(notCardPos[j].x, notCardPos[j].y, 16, *this->window) && notCardPos[j].cardOnIt == 0)
									{
										if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
										{
											if (!pressed)
											{
												pressed = true;

												if (deck[player2Pos1].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player2Pos2].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player2Pos3].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player2Pos4].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player2Pos5].type == 'n')
												{
													otherNot = 1;
												}
												
												if (otherNot)
												{
													deck[i].drag = 0;
													otherNot = 0;
													while (true)
													{
														setTimer();
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
														for (int i = 0; i < 6; i++)
														{
															if (notCardPos[i].cardOnIt == 1)
															{
																notCardPos[i].imgTexture.loadFromFile("assets/PlacedNotCard.png");
																notCardPos[i].img.setTexture(notCardPos[i].imgTexture);
																this->window->draw(notCardPos[i].img);
															}
														}
														tableOfTruth();
														setNotCardImages(cursorpos);
														for (int i = 1; i < 16; i++)
														{
															if (fPositions[i].cardOnIt == 1)
															{
																this->window->draw(deck[fPositions[i].cardNum].img);
															}
														}
														if (getMousePos(639, 530, 17, *this->window))
														{
															notCardPopTexture.loadFromFile("assets/NotCardPopUp1.png");
															notCardPop.setTexture(notCardPopTexture);
															if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
															{
																if (deck[player2Pos1].type == 'n')
																{
																	deck[player2Pos1].drag = 0;
																	deck[player2Pos1].placed = 1;
																	deck[player2Pos1].num = 0;
																	deck[player2Pos1].type = 0;
																	deck[player2Pos1].value = 0;
																	deck[player2Pos1].player2pos = 0;
																	deck[player2Pos1].display1 = 0;
																	deck[player2Pos1].display2 = 0;
																	player2Pos1 = 0;
																}
																else if (deck[player2Pos2].type == 'n')
																{
																	deck[player2Pos2].drag = 0;
																	deck[player2Pos2].placed = 1;
																	deck[player2Pos2].num = 0;
																	deck[player2Pos2].type = 0;
																	deck[player2Pos2].value = 0;
																	deck[player2Pos2].player2pos = 0;
																	deck[player2Pos2].display1 = 0;
																	deck[player2Pos2].display2 = 0;
																	player2Pos2 = 0;
																}
																else if (deck[player2Pos3].type == 'n')
																{
																	deck[player2Pos3].drag = 0;
																	deck[player2Pos3].placed = 1;
																	deck[player2Pos3].num = 0;
																	deck[player2Pos3].type = 0;
																	deck[player2Pos3].value = 0;
																	deck[player2Pos3].player2pos = 0;
																	deck[player2Pos3].display1 = 0;
																	deck[player2Pos3].display2 = 0;
																	player2Pos3 = 0;
																}
																else if (deck[player2Pos4].type == 'n')
																{
																	deck[player2Pos4].drag = 0;
																	deck[player2Pos4].placed = 1;
																	deck[player2Pos4].num = 0;
																	deck[player2Pos4].type = 0;
																	deck[player2Pos4].value = 0;
																	deck[player2Pos4].player2pos = 0;
																	deck[player2Pos4].display1 = 0;
																	deck[player2Pos4].display2 = 0;
																	player2Pos4 = 0;
																}
																else if (deck[player2Pos5].type == 'n')
																{
																	deck[player2Pos5].drag = 0;
																	deck[player2Pos5].placed = 1;
																	deck[player2Pos5].num = 0;
																	deck[player2Pos5].type = 0;
																	deck[player2Pos5].value = 0;
																	deck[player2Pos5].player2pos = 0;
																	deck[player2Pos5].display1 = 0;
																	deck[player2Pos5].display2 = 0;
																	player2Pos5 = 0;
																}
																roundPlayed = 1;
																deck[i].drag = 0;
																deck[i].placed = 1;
																notCardPos[j].cardOnIt = 0;
																deck[i].num = 0;
																deck[i].type = 0;
																deck[i].value = 0;
																deck[i].player1pos = 0;
																deck[i].display1 = 0;
																deck[i].display2 = 0;
																card1Dragging = 0;
																player1Pos1 = 0;
																showNotA = 0;
																player1Cards--;
																player2Cards--;
																pressed = true;
																break;
															}
														}
														else if (getMousePos(823, 530, 17, *this->window))
														{
															notCardPopTexture.loadFromFile("assets/NotCardPopUp2.png");
															notCardPop.setTexture(notCardPopTexture);
															if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
															{
																baseCards[j].value = !(baseCards[j].value);
																baseCards2[j].value = !(baseCards2[j].value);
																baseCards[j].BaseCardImg.setTexture(baseCards2[j].BaseCardImgTexture);
																baseCards2[j].BaseCardImg.setTexture(baseCards[j].BaseCardImgTexture);
																roundPlayed = 1;

																deck[i].drag = 0;
																deck[i].placed = 1;
																notCardPos[j].cardOnIt = 1;
																deck[i].num = 0;
																deck[i].type = 0;
																deck[i].value = 0;
																deck[i].player1pos = 0;
																deck[i].display1 = 0;
																deck[i].display2 = 0;
																card1Dragging = 0;
																player1Pos1 = 0;
																showNotA = 0;
																player1Cards--;
																pressed = true;
																notCardLogic(j);
																break;
															}
														}
														else
														{
														notCardPopTexture.loadFromFile("assets/NotCardPopUp.png");
														notCardPop.setTexture(notCardPopTexture);
														}
														this->window->draw(notCardPop);
														this->window->display();
													}
												}
												else
												{
													baseCards[j].value = !(baseCards[j].value);
													baseCards2[j].value = !(baseCards2[j].value);
													baseCards[j].BaseCardImg.setTexture(baseCards2[j].BaseCardImgTexture);
													baseCards2[j].BaseCardImg.setTexture(baseCards[j].BaseCardImgTexture);
													roundPlayed = 1;

													deck[i].drag = 0;
													deck[i].placed = 1;
													notCardPos[j].cardOnIt = 1;
													deck[i].num = 0;
													deck[i].type = 0;
													deck[i].value = 0;
													deck[i].player1pos = 0;
													deck[i].display1 = 0;
													deck[i].display2 = 0;
													card1Dragging = 0;
													player1Pos1 = 0;
													showNotA = 0;
													player1Cards--;
													pressed = true;
													notCardLogic(j);
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
						}
						else
						{
							showNotA = 0;
							deck[i].img.setRotation(90.f);
						}
					}
					else
					{
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
													deck[counterNotCards3].type = deck[i].type;
													deck[counterNotCards3].value = deck[i].value;
													deck[counterNotCards3].num = counterNotCards3;
													deck[i].type = 0;
													deck[i].value = 0;
													deck[i].player1pos = 0;
													deck[i].display1 = 0;
													deck[i].display2 = 0;
													counterNotCards3++;
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
														deck[counterNotCards3].type = deck[i].type;
														deck[counterNotCards3].value = deck[i].value;
														deck[counterNotCards3].num = counterNotCards3;
														deck[i].type = 0;
														deck[i].value = 0;
														deck[i].player1pos = 0;
														deck[i].display1 = 0;
														deck[i].display2 = 0;
														counterNotCards3++;
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
						}
						else
						{
							showA = 0;
							deck[i].img.setRotation(90.f);
						}
					}
					if (getMousePos(200, 0, 10, *this->window))
					{
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
				}
				else if (player1Pos2 == i && !(card1Dragging || card3Dragging || card4Dragging || card5Dragging) && !(roundPlayed)) // Display and drag The second card
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
					if (deck[i].type == 'n')
					{
						if (deck[i].drag && deck[i].type == 'n')
						{
							int x = cursorpos.x + 50;
							int y = cursorpos.y - 52;
							card2Dragging = 1;
							showNotA = 1;

							if (getMousePos(300, 0, 6, *this->window))
							{
								x = cursorpos.x - 52;
								y = cursorpos.y - 30;
								deck[i].img.setRotation(360.f);
								for (int j = 0; j < 6; j++)
								{
									if (getMousePos(notCardPos[j].x, notCardPos[j].y, 16, *this->window) && notCardPos[j].cardOnIt == 0)
									{
										if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
										{
											if (!pressed)
											{
												pressed = true;

												if (deck[player2Pos1].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player2Pos2].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player2Pos3].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player2Pos4].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player2Pos5].type == 'n')
												{
													otherNot = 1;
												}

												if (otherNot)
												{
													deck[i].drag = 0;
													otherNot = 0;
													while (true)
													{
														setTimer();
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
														for (int i = 0; i < 6; i++)
														{
															if (notCardPos[i].cardOnIt == 1)
															{
																notCardPos[i].imgTexture.loadFromFile("assets/PlacedNotCard.png");
																notCardPos[i].img.setTexture(notCardPos[i].imgTexture);
																this->window->draw(notCardPos[i].img);
															}
														}
														tableOfTruth();
														setNotCardImages(cursorpos);
														for (int i = 1; i < 16; i++)
														{
															if (fPositions[i].cardOnIt == 1)
															{
																this->window->draw(deck[fPositions[i].cardNum].img);
															}
														}
														if (getMousePos(639, 530, 17, *this->window))
														{
															notCardPopTexture.loadFromFile("assets/NotCardPopUp1.png");
															notCardPop.setTexture(notCardPopTexture);
															if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
															{
																if (deck[player2Pos1].type == 'n')
																{
																	deck[player2Pos1].drag = 0;
																	deck[player2Pos1].placed = 1;
																	deck[player2Pos1].num = 0;
																	deck[player2Pos1].type = 0;
																	deck[player2Pos1].value = 0;
																	deck[player2Pos1].player2pos = 0;
																	deck[player2Pos1].display1 = 0;
																	deck[player2Pos1].display2 = 0;
																	player2Pos1 = 0;
																}
																else if (deck[player2Pos2].type == 'n')
																{
																	deck[player2Pos2].drag = 0;
																	deck[player2Pos2].placed = 1;
																	deck[player2Pos2].num = 0;
																	deck[player2Pos2].type = 0;
																	deck[player2Pos2].value = 0;
																	deck[player2Pos2].player2pos = 0;
																	deck[player2Pos2].display1 = 0;
																	deck[player2Pos2].display2 = 0;
																	player2Pos2 = 0;
																}
																else if (deck[player2Pos3].type == 'n')
																{
																	deck[player2Pos3].drag = 0;
																	deck[player2Pos3].placed = 1;
																	deck[player2Pos3].num = 0;
																	deck[player2Pos3].type = 0;
																	deck[player2Pos3].value = 0;
																	deck[player2Pos3].player2pos = 0;
																	deck[player2Pos3].display1 = 0;
																	deck[player2Pos3].display2 = 0;
																	player2Pos3 = 0;
																}
																else if (deck[player2Pos4].type == 'n')
																{
																	deck[player2Pos4].drag = 0;
																	deck[player2Pos4].placed = 1;
																	deck[player2Pos4].num = 0;
																	deck[player2Pos4].type = 0;
																	deck[player2Pos4].value = 0;
																	deck[player2Pos4].player2pos = 0;
																	deck[player2Pos4].display1 = 0;
																	deck[player2Pos4].display2 = 0;
																	player2Pos4 = 0;
																}
																else if (deck[player2Pos5].type == 'n')
																{
																	deck[player2Pos5].drag = 0;
																	deck[player2Pos5].placed = 1;
																	deck[player2Pos5].num = 0;
																	deck[player2Pos5].type = 0;
																	deck[player2Pos5].value = 0;
																	deck[player2Pos5].player2pos = 0;
																	deck[player2Pos5].display1 = 0;
																	deck[player2Pos5].display2 = 0;
																	player2Pos5 = 0;
																}
																roundPlayed = 1;
																deck[i].drag = 0;
																deck[i].placed = 1;
																notCardPos[j].cardOnIt = 0;
																deck[i].num = 0;
																deck[i].type = 0;
																deck[i].value = 0;
																deck[i].player1pos = 0;
																deck[i].display1 = 0;
																deck[i].display2 = 0;
																card2Dragging = 0;
																player1Pos2 = 0;
																showNotA = 0;
																player1Cards--;
																player2Cards--;
																pressed = true;
																break;
															}
														}
														else if (getMousePos(823, 530, 17, *this->window))
														{
															notCardPopTexture.loadFromFile("assets/NotCardPopUp2.png");
															notCardPop.setTexture(notCardPopTexture);
															if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
															{
																baseCards[j].value = !(baseCards[j].value);
																baseCards2[j].value = !(baseCards2[j].value);
																baseCards[j].BaseCardImg.setTexture(baseCards2[j].BaseCardImgTexture);
																baseCards2[j].BaseCardImg.setTexture(baseCards[j].BaseCardImgTexture);
																roundPlayed = 1;

																deck[i].drag = 0;
																deck[i].placed = 1;
																notCardPos[j].cardOnIt = 1;
																deck[i].num = 0;
																deck[i].type = 0;
																deck[i].value = 0;
																deck[i].player1pos = 0;
																deck[i].display1 = 0;
																deck[i].display2 = 0;
																card2Dragging = 0;
																player1Pos2 = 0;
																showNotA = 0;
																player1Cards--;
																pressed = true;
																notCardLogic(j);
																break;
															}
														}
														else
														{
															notCardPopTexture.loadFromFile("assets/NotCardPopUp.png");
															notCardPop.setTexture(notCardPopTexture);
														}
														this->window->draw(notCardPop);
														this->window->display();
													}
												}
												else
												{
													baseCards[j].value = !(baseCards[j].value);
													baseCards2[j].value = !(baseCards2[j].value);
													baseCards[j].BaseCardImg.setTexture(baseCards2[j].BaseCardImgTexture);
													baseCards2[j].BaseCardImg.setTexture(baseCards[j].BaseCardImgTexture);
													roundPlayed = 1;

													deck[i].drag = 0;
													deck[i].placed = 1;
													notCardPos[j].cardOnIt = 1;
													deck[i].num = 0;
													deck[i].type = 0;
													deck[i].value = 0;
													deck[i].player1pos = 0;
													deck[i].display1 = 0;
													deck[i].display2 = 0;
													card2Dragging = 0;
													player1Pos2 = 0;
													showNotA = 0;
													player1Cards--;
													pressed = true;
													notCardLogic(j);
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
						}
						else
						{
							showNotA = 0;
							deck[i].img.setRotation(90.f);
						}
					}
					else
					{
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
													deck[counterNotCards3].type = deck[i].type;
													deck[counterNotCards3].value = deck[i].value;
													deck[counterNotCards3].num = counterNotCards3;
													deck[i].type = 0;
													deck[i].value = 0;
													deck[i].player1pos = 0;
													deck[i].display1 = 0;
													deck[i].display2 = 0;
													counterNotCards3++;
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
														deck[counterNotCards3].type = deck[i].type;
														deck[counterNotCards3].value = deck[i].value;
														deck[counterNotCards3].num = counterNotCards3;
														deck[i].type = 0;
														deck[i].value = 0;
														deck[i].player1pos = 0;
														deck[i].display1 = 0;
														deck[i].display2 = 0;
														counterNotCards3++;
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
					}
					if (getMousePos(200, 0, 10, *this->window))
					{
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
				}
				else if (player1Pos3 == i && !(card1Dragging || card2Dragging || card4Dragging || card5Dragging) && !(roundPlayed)) // Display and drag The third card
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
					if (deck[i].type == 'n')
					{
						if (deck[i].drag && deck[i].type == 'n')
						{
							int x = cursorpos.x + 50;
							int y = cursorpos.y - 52;
							card3Dragging = 1;
							showNotA = 1;

							if (getMousePos(300, 0, 6, *this->window))
							{
								x = cursorpos.x - 52;
								y = cursorpos.y - 30;
								deck[i].img.setRotation(360.f);
								for (int j = 0; j < 6; j++)
								{
									if (getMousePos(notCardPos[j].x, notCardPos[j].y, 16, *this->window) && notCardPos[j].cardOnIt == 0)
									{
										if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
										{
											if (!pressed)
											{
												pressed = true;

												if (deck[player2Pos1].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player2Pos2].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player2Pos3].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player2Pos4].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player2Pos5].type == 'n')
												{
													otherNot = 1;
												}

												if (otherNot)
												{
													deck[i].drag = 0;
													otherNot = 0;
													while (true)
													{
														setTimer();
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
														for (int i = 0; i < 6; i++)
														{
															if (notCardPos[i].cardOnIt == 1)
															{
																notCardPos[i].imgTexture.loadFromFile("assets/PlacedNotCard.png");
																notCardPos[i].img.setTexture(notCardPos[i].imgTexture);
																this->window->draw(notCardPos[i].img);
															}
														}
														tableOfTruth();
														setNotCardImages(cursorpos);
														for (int i = 1; i < 16; i++)
														{
															if (fPositions[i].cardOnIt == 1)
															{
																this->window->draw(deck[fPositions[i].cardNum].img);
															}
														}
														if (getMousePos(639, 530, 17, *this->window))
														{
															notCardPopTexture.loadFromFile("assets/NotCardPopUp1.png");
															notCardPop.setTexture(notCardPopTexture);
															if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
															{
																if (deck[player2Pos1].type == 'n')
																{
																	deck[player2Pos1].drag = 0;
																	deck[player2Pos1].placed = 1;
																	deck[player2Pos1].num = 0;
																	deck[player2Pos1].type = 0;
																	deck[player2Pos1].value = 0;
																	deck[player2Pos1].player2pos = 0;
																	deck[player2Pos1].display1 = 0;
																	deck[player2Pos1].display2 = 0;
																	player2Pos1 = 0;
																}
																else if (deck[player2Pos2].type == 'n')
																{
																	deck[player2Pos2].drag = 0;
																	deck[player2Pos2].placed = 1;
																	deck[player2Pos2].num = 0;
																	deck[player2Pos2].type = 0;
																	deck[player2Pos2].value = 0;
																	deck[player2Pos2].player2pos = 0;
																	deck[player2Pos2].display1 = 0;
																	deck[player2Pos2].display2 = 0;
																	player2Pos2 = 0;
																}
																else if (deck[player2Pos3].type == 'n')
																{
																	deck[player2Pos3].drag = 0;
																	deck[player2Pos3].placed = 1;
																	deck[player2Pos3].num = 0;
																	deck[player2Pos3].type = 0;
																	deck[player2Pos3].value = 0;
																	deck[player2Pos3].player2pos = 0;
																	deck[player2Pos3].display1 = 0;
																	deck[player2Pos3].display2 = 0;
																	player2Pos3 = 0;
																}
																else if (deck[player2Pos4].type == 'n')
																{
																	deck[player2Pos4].drag = 0;
																	deck[player2Pos4].placed = 1;
																	deck[player2Pos4].num = 0;
																	deck[player2Pos4].type = 0;
																	deck[player2Pos4].value = 0;
																	deck[player2Pos4].player2pos = 0;
																	deck[player2Pos4].display1 = 0;
																	deck[player2Pos4].display2 = 0;
																	player2Pos4 = 0;
																}
																else if (deck[player2Pos5].type == 'n')
																{
																	deck[player2Pos5].drag = 0;
																	deck[player2Pos5].placed = 1;
																	deck[player2Pos5].num = 0;
																	deck[player2Pos5].type = 0;
																	deck[player2Pos5].value = 0;
																	deck[player2Pos5].player2pos = 0;
																	deck[player2Pos5].display1 = 0;
																	deck[player2Pos5].display2 = 0;
																	player2Pos5 = 0;
																}
																roundPlayed = 1;
																deck[i].drag = 0;
																deck[i].placed = 1;
																notCardPos[j].cardOnIt = 0;
																deck[i].num = 0;
																deck[i].type = 0;
																deck[i].value = 0;
																deck[i].player1pos = 0;
																deck[i].display1 = 0;
																deck[i].display2 = 0;
																card3Dragging = 0;
																player1Pos3 = 0;
																showNotA = 0;
																player1Cards--;
																player2Cards--;
																pressed = true;
																break;
															}
														}
														else if (getMousePos(823, 530, 17, *this->window))
														{
															notCardPopTexture.loadFromFile("assets/NotCardPopUp2.png");
															notCardPop.setTexture(notCardPopTexture);
															if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
															{
																baseCards[j].value = !(baseCards[j].value);
																baseCards2[j].value = !(baseCards2[j].value);
																baseCards[j].BaseCardImg.setTexture(baseCards2[j].BaseCardImgTexture);
																baseCards2[j].BaseCardImg.setTexture(baseCards[j].BaseCardImgTexture);
																roundPlayed = 1;

																deck[i].drag = 0;
																deck[i].placed = 1;
																notCardPos[j].cardOnIt = 1;
																deck[i].num = 0;
																deck[i].type = 0;
																deck[i].value = 0;
																deck[i].player1pos = 0;
																deck[i].display1 = 0;
																deck[i].display2 = 0;
																card3Dragging = 0;
																player1Pos3 = 0;
																showNotA = 0;
																player1Cards--;
																pressed = true;
																notCardLogic(j);
																break;
															}
														}
														else
														{
															notCardPopTexture.loadFromFile("assets/NotCardPopUp.png");
															notCardPop.setTexture(notCardPopTexture);
														}
														this->window->draw(notCardPop);
														this->window->display();
													}
												}
												else
												{
													baseCards[j].value = !(baseCards[j].value);
													baseCards2[j].value = !(baseCards2[j].value);
													baseCards[j].BaseCardImg.setTexture(baseCards2[j].BaseCardImgTexture);
													baseCards2[j].BaseCardImg.setTexture(baseCards[j].BaseCardImgTexture);
													roundPlayed = 1;

													deck[i].drag = 0;
													deck[i].placed = 1;
													notCardPos[j].cardOnIt = 1;
													deck[i].num = 0;
													deck[i].type = 0;
													deck[i].value = 0;
													deck[i].player1pos = 0;
													deck[i].display1 = 0;
													deck[i].display2 = 0;
													card3Dragging = 0;
													player1Pos3 = 0;
													showNotA = 0;
													player1Cards--;
													pressed = true;
													notCardLogic(j);
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
						}
						else
						{
							showNotA = 0;
							deck[i].img.setRotation(90.f);
						}
					}
					else
					{
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
													deck[counterNotCards3].type = deck[i].type;
													deck[counterNotCards3].value = deck[i].value;
													deck[counterNotCards3].num = counterNotCards3;
													deck[i].type = 0;
													deck[i].value = 0;
													deck[i].player1pos = 0;
													deck[i].display1 = 0;
													deck[i].display2 = 0;
													counterNotCards3++;
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
														deck[counterNotCards3].type = deck[i].type;
														deck[counterNotCards3].value = deck[i].value;
														deck[counterNotCards3].num = counterNotCards3;
														deck[i].type = 0;
														deck[i].value = 0;
														deck[i].player1pos = 0;
														deck[i].display1 = 0;
														deck[i].display2 = 0;
														counterNotCards3++;
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
					}
					if (getMousePos(200, 0, 10, *this->window))
					{
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
				}
				else if (player1Pos4 == i && !(card1Dragging || card2Dragging || card3Dragging || card5Dragging) && !(roundPlayed)) // Display and drag The fourth card
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
					if (deck[i].type == 'n')
					{
						if (deck[i].drag && deck[i].type == 'n')
						{
							int x = cursorpos.x + 50;
							int y = cursorpos.y - 52;
							card4Dragging = 1;
							showNotA = 1;

							if (getMousePos(300, 0, 6, *this->window))
							{
								x = cursorpos.x - 52;
								y = cursorpos.y - 30;
								deck[i].img.setRotation(360.f);
								for (int j = 0; j < 6; j++)
								{
									if (getMousePos(notCardPos[j].x, notCardPos[j].y, 16, *this->window) && notCardPos[j].cardOnIt == 0)
									{
										if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
										{
											if (!pressed)
											{
												pressed = true;

												if (deck[player2Pos1].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player2Pos2].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player2Pos3].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player2Pos4].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player2Pos5].type == 'n')
												{
													otherNot = 1;
												}

												if (otherNot)
												{
													deck[i].drag = 0;
													otherNot = 0;
													while (true)
													{
														setTimer();
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
														for (int i = 0; i < 6; i++)
														{
															if (notCardPos[i].cardOnIt == 1)
															{
																notCardPos[i].imgTexture.loadFromFile("assets/PlacedNotCard.png");
																notCardPos[i].img.setTexture(notCardPos[i].imgTexture);
																this->window->draw(notCardPos[i].img);
															}
														}
														tableOfTruth();
														setNotCardImages(cursorpos);
														for (int i = 1; i < 16; i++)
														{
															if (fPositions[i].cardOnIt == 1)
															{
																this->window->draw(deck[fPositions[i].cardNum].img);
															}
														}
														if (getMousePos(639, 530, 17, *this->window))
														{
															notCardPopTexture.loadFromFile("assets/NotCardPopUp1.png");
															notCardPop.setTexture(notCardPopTexture);
															if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
															{
																if (deck[player2Pos1].type == 'n')
																{
																	deck[player2Pos1].drag = 0;
																	deck[player2Pos1].placed = 1;
																	deck[player2Pos1].num = 0;
																	deck[player2Pos1].type = 0;
																	deck[player2Pos1].value = 0;
																	deck[player2Pos1].player2pos = 0;
																	deck[player2Pos1].display1 = 0;
																	deck[player2Pos1].display2 = 0;
																	player2Pos1 = 0;
																}
																else if (deck[player2Pos2].type == 'n')
																{
																	deck[player2Pos2].drag = 0;
																	deck[player2Pos2].placed = 1;
																	deck[player2Pos2].num = 0;
																	deck[player2Pos2].type = 0;
																	deck[player2Pos2].value = 0;
																	deck[player2Pos2].player2pos = 0;
																	deck[player2Pos2].display1 = 0;
																	deck[player2Pos2].display2 = 0;
																	player2Pos2 = 0;
																}
																else if (deck[player2Pos3].type == 'n')
																{
																	deck[player2Pos3].drag = 0;
																	deck[player2Pos3].placed = 1;
																	deck[player2Pos3].num = 0;
																	deck[player2Pos3].type = 0;
																	deck[player2Pos3].value = 0;
																	deck[player2Pos3].player2pos = 0;
																	deck[player2Pos3].display1 = 0;
																	deck[player2Pos3].display2 = 0;
																	player2Pos3 = 0;
																}
																else if (deck[player2Pos4].type == 'n')
																{
																	deck[player2Pos4].drag = 0;
																	deck[player2Pos4].placed = 1;
																	deck[player2Pos4].num = 0;
																	deck[player2Pos4].type = 0;
																	deck[player2Pos4].value = 0;
																	deck[player2Pos4].player2pos = 0;
																	deck[player2Pos4].display1 = 0;
																	deck[player2Pos4].display2 = 0;
																	player2Pos4 = 0;
																}
																else if (deck[player2Pos5].type == 'n')
																{
																	deck[player2Pos5].drag = 0;
																	deck[player2Pos5].placed = 1;
																	deck[player2Pos5].num = 0;
																	deck[player2Pos5].type = 0;
																	deck[player2Pos5].value = 0;
																	deck[player2Pos5].player2pos = 0;
																	deck[player2Pos5].display1 = 0;
																	deck[player2Pos5].display2 = 0;
																	player2Pos5 = 0;
																}
																roundPlayed = 1;
																deck[i].drag = 0;
																deck[i].placed = 1;
																notCardPos[j].cardOnIt = 0;
																deck[i].num = 0;
																deck[i].type = 0;
																deck[i].value = 0;
																deck[i].player1pos = 0;
																deck[i].display1 = 0;
																deck[i].display2 = 0;
																card4Dragging = 0;
																player1Pos4 = 0;
																showNotA = 0;
																player1Cards--;
																player2Cards--;
																pressed = true;
																break;
															}
														}
														else if (getMousePos(823, 530, 17, *this->window))
														{
															notCardPopTexture.loadFromFile("assets/NotCardPopUp2.png");
															notCardPop.setTexture(notCardPopTexture);
															if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
															{
																baseCards[j].value = !(baseCards[j].value);
																baseCards2[j].value = !(baseCards2[j].value);
																baseCards[j].BaseCardImg.setTexture(baseCards2[j].BaseCardImgTexture);
																baseCards2[j].BaseCardImg.setTexture(baseCards[j].BaseCardImgTexture);
																roundPlayed = 1;

																deck[i].drag = 0;
																deck[i].placed = 1;
																notCardPos[j].cardOnIt = 1;
																deck[i].num = 0;
																deck[i].type = 0;
																deck[i].value = 0;
																deck[i].player1pos = 0;
																deck[i].display1 = 0;
																deck[i].display2 = 0;
																card4Dragging = 0;
																player1Pos4 = 0;
																showNotA = 0;
																player1Cards--;
																pressed = true;
																notCardLogic(j);
																break;
															}
														}
														else
														{
															notCardPopTexture.loadFromFile("assets/NotCardPopUp.png");
															notCardPop.setTexture(notCardPopTexture);
														}
														this->window->draw(notCardPop);
														this->window->display();
													}
												}
												else
												{
													baseCards[j].value = !(baseCards[j].value);
													baseCards2[j].value = !(baseCards2[j].value);
													baseCards[j].BaseCardImg.setTexture(baseCards2[j].BaseCardImgTexture);
													baseCards2[j].BaseCardImg.setTexture(baseCards[j].BaseCardImgTexture);
													roundPlayed = 1;

													deck[i].drag = 0;
													deck[i].placed = 1;
													notCardPos[j].cardOnIt = 1;
													deck[i].num = 0;
													deck[i].type = 0;
													deck[i].value = 0;
													deck[i].player1pos = 0;
													deck[i].display1 = 0;
													deck[i].display2 = 0;
													card4Dragging = 0;
													player1Pos4 = 0;
													showNotA = 0;
													player1Cards--;
													pressed = true;
													notCardLogic(j);
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
						}
						else
						{
							showNotA = 0;
							deck[i].img.setRotation(90.f);
						}
					}
					else
					{
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
													deck[counterNotCards3].type = deck[i].type;
													deck[counterNotCards3].value = deck[i].value;
													deck[counterNotCards3].num = counterNotCards3;
													deck[i].type = 0;
													deck[i].value = 0;
													deck[i].player1pos = 0;
													deck[i].display1 = 0;
													deck[i].display2 = 0;
													counterNotCards3++;
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
														deck[counterNotCards3].type = deck[i].type;
														deck[counterNotCards3].value = deck[i].value;
														deck[counterNotCards3].num = counterNotCards3;
														deck[i].type = 0;
														deck[i].value = 0;
														deck[i].player1pos = 0;
														deck[i].display1 = 0;
														deck[i].display2 = 0;
														counterNotCards3++;
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
					}
					if (getMousePos(200, 0, 10, *this->window))
					{
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
				}
				else if (player1Pos5 == i && !(card1Dragging || card2Dragging || card3Dragging || card4Dragging) && !(roundPlayed)) // Display and drag The fifth card
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
					if (deck[i].type == 'n')
					{
						if (deck[i].drag && deck[i].type == 'n')
						{
							int x = cursorpos.x + 50;
							int y = cursorpos.y - 52;
							card5Dragging = 1;
							showNotA = 1;

							if (getMousePos(300, 0, 6, *this->window))
							{
								x = cursorpos.x - 52;
								y = cursorpos.y - 30;
								deck[i].img.setRotation(360.f);
								for (int j = 0; j < 6; j++)
								{
									if (getMousePos(notCardPos[j].x, notCardPos[j].y, 16, *this->window) && notCardPos[j].cardOnIt == 0)
									{
										if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
										{
											if (!pressed)
											{
												pressed = true;

												if (deck[player2Pos1].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player2Pos2].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player2Pos3].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player2Pos4].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player2Pos5].type == 'n')
												{
													otherNot = 1;
												}

												if (otherNot)
												{
													deck[i].drag = 0;
													otherNot = 0;
													while (true)
													{
														setTimer();
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
														for (int i = 0; i < 6; i++)
														{
															if (notCardPos[i].cardOnIt == 1)
															{
																notCardPos[i].imgTexture.loadFromFile("assets/PlacedNotCard.png");
																notCardPos[i].img.setTexture(notCardPos[i].imgTexture);
																this->window->draw(notCardPos[i].img);
															}
														}
														tableOfTruth();
														setNotCardImages(cursorpos);
														for (int i = 1; i < 16; i++)
														{
															if (fPositions[i].cardOnIt == 1)
															{
																this->window->draw(deck[fPositions[i].cardNum].img);
															}
														}
														if (getMousePos(639, 530, 17, *this->window))
														{
															notCardPopTexture.loadFromFile("assets/NotCardPopUp1.png");
															notCardPop.setTexture(notCardPopTexture);
															if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
															{
																if (deck[player2Pos1].type == 'n')
																{
																	deck[player2Pos1].drag = 0;
																	deck[player2Pos1].placed = 1;
																	deck[player2Pos1].num = 0;
																	deck[player2Pos1].type = 0;
																	deck[player2Pos1].value = 0;
																	deck[player2Pos1].player2pos = 0;
																	deck[player2Pos1].display1 = 0;
																	deck[player2Pos1].display2 = 0;
																	player2Pos1 = 0;
																}
																else if (deck[player2Pos2].type == 'n')
																{
																	deck[player2Pos2].drag = 0;
																	deck[player2Pos2].placed = 1;
																	deck[player2Pos2].num = 0;
																	deck[player2Pos2].type = 0;
																	deck[player2Pos2].value = 0;
																	deck[player2Pos2].player2pos = 0;
																	deck[player2Pos2].display1 = 0;
																	deck[player2Pos2].display2 = 0;
																	player2Pos2 = 0;
																}
																else if (deck[player2Pos3].type == 'n')
																{
																	deck[player2Pos3].drag = 0;
																	deck[player2Pos3].placed = 1;
																	deck[player2Pos3].num = 0;
																	deck[player2Pos3].type = 0;
																	deck[player2Pos3].value = 0;
																	deck[player2Pos3].player2pos = 0;
																	deck[player2Pos3].display1 = 0;
																	deck[player2Pos3].display2 = 0;
																	player2Pos3 = 0;
																}
																else if (deck[player2Pos4].type == 'n')
																{
																	deck[player2Pos4].drag = 0;
																	deck[player2Pos4].placed = 1;
																	deck[player2Pos4].num = 0;
																	deck[player2Pos4].type = 0;
																	deck[player2Pos4].value = 0;
																	deck[player2Pos4].player2pos = 0;
																	deck[player2Pos4].display1 = 0;
																	deck[player2Pos4].display2 = 0;
																	player2Pos4 = 0;
																}
																else if (deck[player2Pos5].type == 'n')
																{
																	deck[player2Pos5].drag = 0;
																	deck[player2Pos5].placed = 1;
																	deck[player2Pos5].num = 0;
																	deck[player2Pos5].type = 0;
																	deck[player2Pos5].value = 0;
																	deck[player2Pos5].player2pos = 0;
																	deck[player2Pos5].display1 = 0;
																	deck[player2Pos5].display2 = 0;
																	player2Pos5 = 0;
																}
																roundPlayed = 1;
																deck[i].drag = 0;
																deck[i].placed = 1;
																notCardPos[j].cardOnIt = 0;
																deck[i].num = 0;
																deck[i].type = 0;
																deck[i].value = 0;
																deck[i].player1pos = 0;
																deck[i].display1 = 0;
																deck[i].display2 = 0;
																card5Dragging = 0;
																player1Pos5 = 0;
																showNotA = 0;
																player1Cards--;
																player2Cards--;
																pressed = true;
																break;
															}
														}
														else if (getMousePos(823, 530, 17, *this->window))
														{
															notCardPopTexture.loadFromFile("assets/NotCardPopUp2.png");
															notCardPop.setTexture(notCardPopTexture);
															if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
															{
																baseCards[j].value = !(baseCards[j].value);
																baseCards2[j].value = !(baseCards2[j].value);
																baseCards[j].BaseCardImg.setTexture(baseCards2[j].BaseCardImgTexture);
																baseCards2[j].BaseCardImg.setTexture(baseCards[j].BaseCardImgTexture);
																roundPlayed = 1;

																deck[i].drag = 0;
																deck[i].placed = 1;
																notCardPos[j].cardOnIt = 1;
																deck[i].num = 0;
																deck[i].type = 0;
																deck[i].value = 0;
																deck[i].player1pos = 0;
																deck[i].display1 = 0;
																deck[i].display2 = 0;
																card5Dragging = 0;
																player1Pos5 = 0;
																showNotA = 0;
																player1Cards--;
																pressed = true;
																notCardLogic(j);
																break;
															}
														}
														else
														{
															notCardPopTexture.loadFromFile("assets/NotCardPopUp.png");
															notCardPop.setTexture(notCardPopTexture);
														}
														this->window->draw(notCardPop);
														this->window->display();
													}
												}
												else
												{
													baseCards[j].value = !(baseCards[j].value);
													baseCards2[j].value = !(baseCards2[j].value);
													baseCards[j].BaseCardImg.setTexture(baseCards2[j].BaseCardImgTexture);
													baseCards2[j].BaseCardImg.setTexture(baseCards[j].BaseCardImgTexture);
													roundPlayed = 1;

													deck[i].drag = 0;
													deck[i].placed = 1;
													notCardPos[j].cardOnIt = 1;
													deck[i].num = 0;
													deck[i].type = 0;
													deck[i].value = 0;
													deck[i].player1pos = 0;
													deck[i].display1 = 0;
													deck[i].display2 = 0;
													card5Dragging = 0;
													player1Pos5 = 0;
													showNotA = 0;
													player1Cards--;
													pressed = true;
													notCardLogic(j);
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
						}
						else
						{
							showNotA = 0;
							deck[i].img.setRotation(90.f);
						}
					}
					else
					{
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
													deck[counterNotCards3].type = deck[i].type;
													deck[counterNotCards3].value = deck[i].value;
													deck[counterNotCards3].num = counterNotCards3;
													deck[i].type = 0;
													deck[i].value = 0;
													deck[i].player1pos = 0;
													deck[i].display1 = 0;
													deck[i].display2 = 0;
													counterNotCards3++;
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
														deck[counterNotCards3].type = deck[i].type;
														deck[counterNotCards3].value = deck[i].value;
														deck[counterNotCards3].num = counterNotCards3;
														deck[i].type = 0;
														deck[i].value = 0;
														deck[i].player1pos = 0;
														deck[i].display1 = 0;
														deck[i].display2 = 0;
														counterNotCards3++;
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
					}
					if (getMousePos(200, 0, 10, *this->window))
					{
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
				}
				// Displaying by type
			}
			if (deck[i].value == 0 && !(deck[i].num == fPositions[i].cardNum))
			{
				switch (specialButtonC)
				{
				case 0:
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
					break;
				case 1:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				case 2:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				case 3:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				case 4:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				case 5:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				}
			}
			else if (deck[i].value == 0 && (deck[i].num == fPositions[i].cardNum))
			{
				switch (specialButtonC)
				{
				case 0:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 1:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 2:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 3:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 4:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 5:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				}
			}
			else if (deck[i].value == 1 && !(deck[i].num == fPositions[i].cardNum))
			{

				switch (specialButtonC)
				{
				case 0:
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
					break;
				case 1:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				case 2:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				case 3:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				case 4:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				case 5:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				}
			}
			else if (deck[i].value == 1 && (deck[i].num == fPositions[i].cardNum))
			{

				switch (specialButtonC)
				{
				case 0:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 1:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 2:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 3:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 4:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 5:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				}
			}
			else if (deck[i].type == 'n' && !(deck[i].num == fPositions[i].cardNum))
			{
			switch (specialButtonC)
			{
			case 0:
				deck[i].imgTexture.loadFromFile("assets/NotCard.png");
				this->deck[i].imgTexture.setSmooth(true);
				deck[i].img.setTexture(deck[i].imgTexture);
				this->window->draw(deck[i].img);
				break;
			case 1:
				deck[i].imgTexture.loadFromFile("assets/NavyBundle/NotCard.png");
				this->deck[i].imgTexture.setSmooth(true);
				deck[i].img.setTexture(deck[i].imgTexture);
				this->window->draw(deck[i].img);
				break;
			case 2:
				deck[i].imgTexture.loadFromFile("assets/SunsetBundle/NotCard.png");
				this->deck[i].imgTexture.setSmooth(true);
				deck[i].img.setTexture(deck[i].imgTexture);
				this->window->draw(deck[i].img);
				break;
			case 3:
				deck[i].imgTexture.loadFromFile("assets/SeaBundle/NotCard.png");
				this->deck[i].imgTexture.setSmooth(true);
				deck[i].img.setTexture(deck[i].imgTexture);
				this->window->draw(deck[i].img);
				break;
			case 4:
				deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/NotCard.png");
				this->deck[i].imgTexture.setSmooth(true);
				deck[i].img.setTexture(deck[i].imgTexture);
				this->window->draw(deck[i].img);
				break;
			case 5:
				deck[i].imgTexture.loadFromFile("assets/CosmosBundle/NotCard.png");
				this->deck[i].imgTexture.setSmooth(true);
				deck[i].img.setTexture(deck[i].imgTexture);
				this->window->draw(deck[i].img);
				break;
			}
			}
			else if (deck[i].type == 'n' && (deck[i].num == fPositions[i].cardNum))
			{
			switch (specialButtonC)
			{
			case 0:
				deck[i].imgTexture.loadFromFile("assets/NotCard.png");
				this->deck[i].imgTexture.setSmooth(true);
				deck[i].img.setTexture(deck[i].imgTexture);
				break;
			case 1:
				deck[i].imgTexture.loadFromFile("assets/NavyBundle/NotCard.png");
				this->deck[i].imgTexture.setSmooth(true);
				deck[i].img.setTexture(deck[i].imgTexture);
				break;
			case 2:
				deck[i].imgTexture.loadFromFile("assets/SunsetBundle/NotCard.png");
				this->deck[i].imgTexture.setSmooth(true);
				deck[i].img.setTexture(deck[i].imgTexture);
				break;
			case 3:
				deck[i].imgTexture.loadFromFile("assets/SeaBundle/NotCard.png");
				this->deck[i].imgTexture.setSmooth(true);
				deck[i].img.setTexture(deck[i].imgTexture);
				break;
			case 4:
				deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/NotCard.png");
				this->deck[i].imgTexture.setSmooth(true);
				deck[i].img.setTexture(deck[i].imgTexture);
				break;
			case 5:
				deck[i].imgTexture.loadFromFile("assets/CosmosBundle/NotCard.png");
				this->deck[i].imgTexture.setSmooth(true);
				deck[i].img.setTexture(deck[i].imgTexture);
				break;
			}
			}
		}
		else if (deck[i].display2 == 1 && counter == 2)
		{
			if (deck[i].player2pos == 1)
			{
				if (player2Pos1 == i && !(card2Dragging2 || card3Dragging2 || card4Dragging2 || card5Dragging2) && !(roundPlayed))  // Display and drag The first card P2
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
					if (deck[i].type == 'n')
					{
						if (deck[i].drag && deck[i].type == 'n')
						{
							int x = cursorpos.x + 50;
							int y = cursorpos.y - 52;
							card1Dragging2 = 1;
							showNotA = 1;

							if (getMousePos(300, 0, 6, *this->window))
							{
								x = cursorpos.x - 52;
								y = cursorpos.y - 30;
								deck[i].img.setRotation(360.f);
								for (int j = 0; j < 6; j++)
								{
									if (getMousePos(notCardPos[j].x, notCardPos[j].y, 16, *this->window) && notCardPos[j].cardOnIt == 0)
									{
										if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
										{
											if (!pressed)
											{
												pressed = true;

												if (deck[player1Pos1].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player1Pos2].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player1Pos3].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player1Pos4].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player1Pos5].type == 'n')
												{
													otherNot = 1;
												}

												if (otherNot)
												{
													deck[i].drag = 0;
													otherNot = 0;
													while (true)
													{
														setTimer();
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
														for (int i = 0; i < 6; i++)
														{
															if (notCardPos[i].cardOnIt == 1)
															{
																notCardPos[i].imgTexture.loadFromFile("assets/PlacedNotCard.png");
																notCardPos[i].img.setTexture(notCardPos[i].imgTexture);
																this->window->draw(notCardPos[i].img);
															}
														}
														tableOfTruth();
														setNotCardImages(cursorpos);
														for (int i = 1; i < 16; i++)
														{
															if (fPositions2[i].cardOnIt == 1)
															{
																this->window->draw(deck[fPositions2[i].cardNum].img);
															}
														}
														if (getMousePos(639, 530, 17, *this->window))
														{
															notCardPopTexture.loadFromFile("assets/NotCard2PopUp1.png");
															notCardPop.setTexture(notCardPopTexture);
															if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
															{
																if (deck[player1Pos1].type == 'n')
																{
																	deck[player1Pos1].drag = 0;
																	deck[player1Pos1].placed = 1;
																	deck[player1Pos1].num = 0;
																	deck[player1Pos1].type = 0;
																	deck[player1Pos1].value = 0;
																	deck[player1Pos1].player1pos = 0;
																	deck[player1Pos1].display1 = 0;
																	deck[player1Pos1].display2 = 0;
																	player1Pos1 = 0;
																}
																else if (deck[player1Pos2].type == 'n')
																{
																	deck[player1Pos2].drag = 0;
																	deck[player1Pos2].placed = 1;
																	deck[player1Pos2].num = 0;
																	deck[player1Pos2].type = 0;
																	deck[player1Pos2].value = 0;
																	deck[player1Pos2].player1pos = 0;
																	deck[player1Pos2].display1 = 0;
																	deck[player1Pos2].display2 = 0;
																	player1Pos2 = 0;
																}
																else if (deck[player1Pos3].type == 'n')
																{
																	deck[player1Pos3].drag = 0;
																	deck[player1Pos3].placed = 1;
																	deck[player1Pos3].num = 0;
																	deck[player1Pos3].type = 0;
																	deck[player1Pos3].value = 0;
																	deck[player1Pos3].player1pos = 0;
																	deck[player1Pos3].display1 = 0;
																	deck[player1Pos3].display2 = 0;
																	player1Pos3 = 0;
																}
																else if (deck[player1Pos4].type == 'n')
																{
																	deck[player1Pos4].drag = 0;
																	deck[player1Pos4].placed = 1;
																	deck[player1Pos4].num = 0;
																	deck[player1Pos4].type = 0;
																	deck[player1Pos4].value = 0;
																	deck[player1Pos4].player1pos = 0;
																	deck[player1Pos4].display1 = 0;
																	deck[player1Pos4].display2 = 0;
																	player1Pos4 = 0;
																}
																else if (deck[player1Pos5].type == 'n')
																{
																	deck[player1Pos5].drag = 0;
																	deck[player1Pos5].placed = 1;
																	deck[player1Pos5].num = 0;
																	deck[player1Pos5].type = 0;
																	deck[player1Pos5].value = 0;
																	deck[player1Pos5].player1pos = 0;
																	deck[player1Pos5].display1 = 0;
																	deck[player1Pos5].display2 = 0;
																	player1Pos5 = 0;
																}
																roundPlayed = 1;
																deck[i].drag = 0;
																deck[i].placed = 1;
																notCardPos[j].cardOnIt = 0;
																deck[i].num = 0;
																deck[i].type = 0;
																deck[i].value = 0;
																deck[i].player2pos = 0;
																deck[i].display1 = 0;
																deck[i].display2 = 0;
																card1Dragging2 = 0;
																player2Pos1 = 0;
																showNotA = 0;
																player1Cards--;
																player2Cards--;
																pressed = true;
																break;
															}
														}
														else if (getMousePos(823, 530, 17, *this->window))
														{
															notCardPopTexture.loadFromFile("assets/NotCard2PopUp2.png");
															notCardPop.setTexture(notCardPopTexture);
															if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
															{
																baseCards[j].value = !(baseCards[j].value);
																baseCards2[j].value = !(baseCards2[j].value);
																baseCards[j].BaseCardImg.setTexture(baseCards2[j].BaseCardImgTexture);
																baseCards2[j].BaseCardImg.setTexture(baseCards[j].BaseCardImgTexture);
																roundPlayed = 1;

																deck[i].drag = 0;
																deck[i].placed = 1;
																notCardPos[j].cardOnIt = 1;
																deck[i].num = 0;
																deck[i].type = 0;
																deck[i].value = 0;
																deck[i].player2pos = 0;
																deck[i].display1 = 0;
																deck[i].display2 = 0;
																card1Dragging2 = 0;
																player2Pos1 = 0;
																showNotA = 0;
																player2Cards--;
																pressed = true;
																notCardLogic(j);
																break;
															}
														}
														else
														{
															notCardPopTexture.loadFromFile("assets/NotCard2PopUp.png");
															notCardPop.setTexture(notCardPopTexture);
														}
														this->window->draw(notCardPop);
														this->window->display();
													}
												}
												else
												{
													baseCards[j].value = !(baseCards[j].value);
													baseCards2[j].value = !(baseCards2[j].value);
													baseCards[j].BaseCardImg.setTexture(baseCards2[j].BaseCardImgTexture);
													baseCards2[j].BaseCardImg.setTexture(baseCards[j].BaseCardImgTexture);
													roundPlayed = 1;

													deck[i].drag = 0;
													deck[i].placed = 1;
													notCardPos[j].cardOnIt = 1;
													deck[i].num = 0;
													deck[i].type = 0;
													deck[i].value = 0;
													deck[i].player2pos = 0;
													deck[i].display1 = 0;
													deck[i].display2 = 0;
													card1Dragging2 = 0;
													player2Pos1 = 0;
													showNotA = 0;
													player2Cards--;
													pressed = true;
													notCardLogic(j);
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
						}
						else
						{
							showNotA = 0;
							deck[i].img.setRotation(90.f);
						}
					}
					else
					{
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
													deck[counterNotCards3].type = deck[i].type;
													deck[counterNotCards3].value = deck[i].value;
													deck[counterNotCards3].num = counterNotCards3;
													deck[i].player2pos = 0;
													deck[i].display1 = 0;
													deck[i].display2 = 0;
													counterNotCards3++;
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
														deck[counterNotCards3].type = deck[i].type;
														deck[counterNotCards3].value = deck[i].value;
														deck[counterNotCards3].num = counterNotCards3;
														deck[i].player2pos = 0;
														deck[i].display1 = 0;
														deck[i].display2 = 0;
														counterNotCards3++;
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
					}
					if (getMousePos(200, 0, 10, *this->window))
					{
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
				}
				else if (player2Pos2 == i && !(card1Dragging2 || card3Dragging2 || card4Dragging2 || card5Dragging2) && !(roundPlayed)) // Display and drag The second card P2
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
					if (deck[i].type == 'n')
					{
						if (deck[i].drag && deck[i].type == 'n')
						{
							int x = cursorpos.x + 50;
							int y = cursorpos.y - 52;
							card2Dragging2 = 1;
							showNotA = 1;

							if (getMousePos(300, 0, 6, *this->window))
							{
								x = cursorpos.x - 52;
								y = cursorpos.y - 30;
								deck[i].img.setRotation(360.f);
								for (int j = 0; j < 6; j++)
								{
									if (getMousePos(notCardPos[j].x, notCardPos[j].y, 16, *this->window) && notCardPos[j].cardOnIt == 0)
									{
										if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
										{
											if (!pressed)
											{
												pressed = true;

												if (deck[player1Pos1].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player1Pos2].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player1Pos3].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player1Pos4].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player1Pos5].type == 'n')
												{
													otherNot = 1;
												}

												if (otherNot)
												{
													deck[i].drag = 0;
													otherNot = 0;
													while (true)
													{
														setTimer();
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
														for (int i = 0; i < 6; i++)
														{
															if (notCardPos[i].cardOnIt == 1)
															{
																notCardPos[i].imgTexture.loadFromFile("assets/PlacedNotCard.png");
																notCardPos[i].img.setTexture(notCardPos[i].imgTexture);
																this->window->draw(notCardPos[i].img);
															}
														}
														tableOfTruth();
														setNotCardImages(cursorpos);
														for (int i = 1; i < 16; i++)
														{
															if (fPositions2[i].cardOnIt == 1)
															{
																this->window->draw(deck[fPositions2[i].cardNum].img);
															}
														}
														if (getMousePos(639, 530, 17, *this->window))
														{
															notCardPopTexture.loadFromFile("assets/NotCard2PopUp1.png");
															notCardPop.setTexture(notCardPopTexture);
															if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
															{
																if (deck[player1Pos1].type == 'n')
																{
																	deck[player1Pos1].drag = 0;
																	deck[player1Pos1].placed = 1;
																	deck[player1Pos1].num = 0;
																	deck[player1Pos1].type = 0;
																	deck[player1Pos1].value = 0;
																	deck[player1Pos1].player1pos = 0;
																	deck[player1Pos1].display1 = 0;
																	deck[player1Pos1].display2 = 0;
																	player1Pos1 = 0;
																}
																else if (deck[player1Pos2].type == 'n')
																{
																	deck[player1Pos2].drag = 0;
																	deck[player1Pos2].placed = 1;
																	deck[player1Pos2].num = 0;
																	deck[player1Pos2].type = 0;
																	deck[player1Pos2].value = 0;
																	deck[player1Pos2].player1pos = 0;
																	deck[player1Pos2].display1 = 0;
																	deck[player1Pos2].display2 = 0;
																	player1Pos2 = 0;
																}
																else if (deck[player1Pos3].type == 'n')
																{
																	deck[player1Pos3].drag = 0;
																	deck[player1Pos3].placed = 1;
																	deck[player1Pos3].num = 0;
																	deck[player1Pos3].type = 0;
																	deck[player1Pos3].value = 0;
																	deck[player1Pos3].player1pos = 0;
																	deck[player1Pos3].display1 = 0;
																	deck[player1Pos3].display2 = 0;
																	player1Pos3 = 0;
																}
																else if (deck[player1Pos4].type == 'n')
																{
																	deck[player1Pos4].drag = 0;
																	deck[player1Pos4].placed = 1;
																	deck[player1Pos4].num = 0;
																	deck[player1Pos4].type = 0;
																	deck[player1Pos4].value = 0;
																	deck[player1Pos4].player1pos = 0;
																	deck[player1Pos4].display1 = 0;
																	deck[player1Pos4].display2 = 0;
																	player1Pos4 = 0;
																}
																else if (deck[player1Pos5].type == 'n')
																{
																	deck[player1Pos5].drag = 0;
																	deck[player1Pos5].placed = 1;
																	deck[player1Pos5].num = 0;
																	deck[player1Pos5].type = 0;
																	deck[player1Pos5].value = 0;
																	deck[player1Pos5].player1pos = 0;
																	deck[player1Pos5].display1 = 0;
																	deck[player1Pos5].display2 = 0;
																	player1Pos5 = 0;
																}
																roundPlayed = 1;
																deck[i].drag = 0;
																deck[i].placed = 1;
																notCardPos[j].cardOnIt = 0;
																deck[i].num = 0;
																deck[i].type = 0;
																deck[i].value = 0;
																deck[i].player2pos = 0;
																deck[i].display1 = 0;
																deck[i].display2 = 0;
																card2Dragging2 = 0;
																player2Pos2 = 0;
																showNotA = 0;
																player1Cards--;
																player2Cards--;
																pressed = true;
																break;
															}
														}
														else if (getMousePos(823, 530, 17, *this->window))
														{
															notCardPopTexture.loadFromFile("assets/NotCard2PopUp2.png");
															notCardPop.setTexture(notCardPopTexture);
															if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
															{
																baseCards[j].value = !(baseCards[j].value);
																baseCards2[j].value = !(baseCards2[j].value);
																baseCards[j].BaseCardImg.setTexture(baseCards2[j].BaseCardImgTexture);
																baseCards2[j].BaseCardImg.setTexture(baseCards[j].BaseCardImgTexture);
																roundPlayed = 1;

																deck[i].drag = 0;
																deck[i].placed = 1;
																notCardPos[j].cardOnIt = 1;
																deck[i].num = 0;
																deck[i].type = 0;
																deck[i].value = 0;
																deck[i].player2pos = 0;
																deck[i].display1 = 0;
																deck[i].display2 = 0;
																card2Dragging2 = 0;
																player2Pos2 = 0;
																showNotA = 0;
																player2Cards--;
																pressed = true;
																notCardLogic(j);
																break;
															}
														}
														else
														{
															notCardPopTexture.loadFromFile("assets/NotCard2PopUp.png");
															notCardPop.setTexture(notCardPopTexture);
														}
														this->window->draw(notCardPop);
														this->window->display();
													}
												}
												else
												{
													baseCards[j].value = !(baseCards[j].value);
													baseCards2[j].value = !(baseCards2[j].value);
													baseCards[j].BaseCardImg.setTexture(baseCards2[j].BaseCardImgTexture);
													baseCards2[j].BaseCardImg.setTexture(baseCards[j].BaseCardImgTexture);
													roundPlayed = 1;

													deck[i].drag = 0;
													deck[i].placed = 1;
													notCardPos[j].cardOnIt = 1;
													deck[i].num = 0;
													deck[i].type = 0;
													deck[i].value = 0;
													deck[i].player1pos = 0;
													deck[i].display1 = 0;
													deck[i].display2 = 0;
													card2Dragging2 = 0;
													player2Pos2 = 0;
													showNotA = 0;
													player2Cards--;
													pressed = true;
													notCardLogic(j);
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
						}
						else
						{
							showNotA = 0;
							deck[i].img.setRotation(90.f);
						}
					}
					else
					{
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
													deck[counterNotCards3].type = deck[i].type;
													deck[counterNotCards3].value = deck[i].value;
													deck[counterNotCards3].num = counterNotCards3;
													deck[i].player2pos = 0;
													deck[i].display1 = 0;
													deck[i].display2 = 0;
													counterNotCards3++;
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
														deck[counterNotCards3].type = deck[i].type;
														deck[counterNotCards3].value = deck[i].value;
														deck[counterNotCards3].num = counterNotCards3;
														deck[i].player2pos = 0;
														deck[i].display1 = 0;
														deck[i].display2 = 0;
														counterNotCards3++;
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
					}
					if (getMousePos(200, 0, 10, *this->window))
					{
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
				}
				else if (player2Pos3 == i && !(card1Dragging2 || card2Dragging2 || card4Dragging2 || card5Dragging2) && !(roundPlayed)) // Display and drag The third card P2
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
					if (deck[i].type == 'n')
					{
						if (deck[i].drag && deck[i].type == 'n')
						{
							int x = cursorpos.x + 50;
							int y = cursorpos.y - 52;
							card3Dragging2 = 1;
							showNotA = 1;

							if (getMousePos(300, 0, 6, *this->window))
							{
								x = cursorpos.x - 52;
								y = cursorpos.y - 30;
								deck[i].img.setRotation(360.f);
								for (int j = 0; j < 6; j++)
								{
									if (getMousePos(notCardPos[j].x, notCardPos[j].y, 16, *this->window) && notCardPos[j].cardOnIt == 0)
									{
										if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
										{
											if (!pressed)
											{
												pressed = true;

												if (deck[player1Pos1].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player1Pos2].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player1Pos3].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player1Pos4].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player1Pos5].type == 'n')
												{
													otherNot = 1;
												}

												if (otherNot)
												{
													deck[i].drag = 0;
													otherNot = 0;
													while (true)
													{
														setTimer();
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
														for (int i = 0; i < 6; i++)
														{
															if (notCardPos[i].cardOnIt == 1)
															{
																notCardPos[i].imgTexture.loadFromFile("assets/PlacedNotCard.png");
																notCardPos[i].img.setTexture(notCardPos[i].imgTexture);
																this->window->draw(notCardPos[i].img);
															}
														}
														tableOfTruth();
														setNotCardImages(cursorpos);
														for (int i = 1; i < 16; i++)
														{
															if (fPositions2[i].cardOnIt == 1)
															{
																this->window->draw(deck[fPositions2[i].cardNum].img);
															}
														}
														if (getMousePos(639, 530, 17, *this->window))
														{
															notCardPopTexture.loadFromFile("assets/NotCard2PopUp1.png");
															notCardPop.setTexture(notCardPopTexture);
															if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
															{
																if (deck[player1Pos1].type == 'n')
																{
																	deck[player1Pos1].drag = 0;
																	deck[player1Pos1].placed = 1;
																	deck[player1Pos1].num = 0;
																	deck[player1Pos1].type = 0;
																	deck[player1Pos1].value = 0;
																	deck[player1Pos1].player1pos = 0;
																	deck[player1Pos1].display1 = 0;
																	deck[player1Pos1].display2 = 0;
																	player1Pos1 = 0;
																}
																else if (deck[player1Pos2].type == 'n')
																{
																	deck[player1Pos2].drag = 0;
																	deck[player1Pos2].placed = 1;
																	deck[player1Pos2].num = 0;
																	deck[player1Pos2].type = 0;
																	deck[player1Pos2].value = 0;
																	deck[player1Pos2].player1pos = 0;
																	deck[player1Pos2].display1 = 0;
																	deck[player1Pos2].display2 = 0;
																	player1Pos2 = 0;
																}
																else if (deck[player1Pos3].type == 'n')
																{
																	deck[player1Pos3].drag = 0;
																	deck[player1Pos3].placed = 1;
																	deck[player1Pos3].num = 0;
																	deck[player1Pos3].type = 0;
																	deck[player1Pos3].value = 0;
																	deck[player1Pos3].player1pos = 0;
																	deck[player1Pos3].display1 = 0;
																	deck[player1Pos3].display2 = 0;
																	player1Pos3 = 0;
																}
																else if (deck[player1Pos4].type == 'n')
																{
																	deck[player1Pos4].drag = 0;
																	deck[player1Pos4].placed = 1;
																	deck[player1Pos4].num = 0;
																	deck[player1Pos4].type = 0;
																	deck[player1Pos4].value = 0;
																	deck[player1Pos4].player1pos = 0;
																	deck[player1Pos4].display1 = 0;
																	deck[player1Pos4].display2 = 0;
																	player1Pos4 = 0;
																}
																else if (deck[player1Pos5].type == 'n')
																{
																	deck[player1Pos5].drag = 0;
																	deck[player1Pos5].placed = 1;
																	deck[player1Pos5].num = 0;
																	deck[player1Pos5].type = 0;
																	deck[player1Pos5].value = 0;
																	deck[player1Pos5].player1pos = 0;
																	deck[player1Pos5].display1 = 0;
																	deck[player1Pos5].display2 = 0;
																	player1Pos5 = 0;
																}
																roundPlayed = 1;
																deck[i].drag = 0;
																deck[i].placed = 1;
																notCardPos[j].cardOnIt = 0;
																deck[i].num = 0;
																deck[i].type = 0;
																deck[i].value = 0;
																deck[i].player2pos = 0;
																deck[i].display1 = 0;
																deck[i].display2 = 0;
																card3Dragging2 = 0;
																player2Pos3 = 0;
																showNotA = 0;
																player1Cards--;
																player2Cards--;
																pressed = true;
																break;
															}
														}
														else if (getMousePos(823, 530, 17, *this->window))
														{
															notCardPopTexture.loadFromFile("assets/NotCard2PopUp2.png");
															notCardPop.setTexture(notCardPopTexture);
															if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
															{
																baseCards[j].value = !(baseCards[j].value);
																baseCards2[j].value = !(baseCards2[j].value);
																baseCards[j].BaseCardImg.setTexture(baseCards2[j].BaseCardImgTexture);
																baseCards2[j].BaseCardImg.setTexture(baseCards[j].BaseCardImgTexture);
																roundPlayed = 1;

																deck[i].drag = 0;
																deck[i].placed = 1;
																notCardPos[j].cardOnIt = 1;
																deck[i].num = 0;
																deck[i].type = 0;
																deck[i].value = 0;
																deck[i].player2pos = 0;
																deck[i].display1 = 0;
																deck[i].display2 = 0;
																card3Dragging2 = 0;
																player2Pos3 = 0;
																showNotA = 0;
																player2Cards--;
																pressed = true;
																notCardLogic(j);
																break;
															}
														}
														else
														{
															notCardPopTexture.loadFromFile("assets/NotCard2PopUp.png");
															notCardPop.setTexture(notCardPopTexture);
														}
														this->window->draw(notCardPop);
														this->window->display();
													}
												}
												else
												{
													baseCards[j].value = !(baseCards[j].value);
													baseCards2[j].value = !(baseCards2[j].value);
													baseCards[j].BaseCardImg.setTexture(baseCards2[j].BaseCardImgTexture);
													baseCards2[j].BaseCardImg.setTexture(baseCards[j].BaseCardImgTexture);
													roundPlayed = 1;

													deck[i].drag = 0;
													deck[i].placed = 1;
													notCardPos[j].cardOnIt = 1;
													deck[i].num = 0;
													deck[i].type = 0;
													deck[i].value = 0;
													deck[i].player1pos = 0;
													deck[i].display1 = 0;
													deck[i].display2 = 0;
													card3Dragging2 = 0;
													player2Pos3 = 0;
													showNotA = 0;
													player2Cards--;
													pressed = true;
													notCardLogic(j);
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
						}
						else
						{
							showNotA = 0;
							deck[i].img.setRotation(90.f);
						}
					}
					else
					{
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
													deck[counterNotCards3].type = deck[i].type;
													deck[counterNotCards3].value = deck[i].value;
													deck[counterNotCards3].num = counterNotCards3;
													deck[i].player2pos = 0;
													deck[i].display1 = 0;
													deck[i].display2 = 0;
													counterNotCards3++;
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
														deck[counterNotCards3].type = deck[i].type;
														deck[counterNotCards3].value = deck[i].value;
														deck[counterNotCards3].num = counterNotCards3;
														deck[i].player2pos = 0;
														deck[i].display1 = 0;
														deck[i].display2 = 0;
														counterNotCards3++;
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
					}
					if (getMousePos(200, 0, 10, *this->window))
					{
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
				}
				else if (player2Pos4 == i && !(card1Dragging2 || card2Dragging2 || card3Dragging2 || card5Dragging2) && !(roundPlayed)) // Display and drag The fourth card P2
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
					if (deck[i].type == 'n')
					{
						if (deck[i].drag && deck[i].type == 'n')
						{
							int x = cursorpos.x + 50;
							int y = cursorpos.y - 52;
							card4Dragging2 = 1;
							showNotA = 1;

							if (getMousePos(300, 0, 6, *this->window))
							{
								x = cursorpos.x - 52;
								y = cursorpos.y - 30;
								deck[i].img.setRotation(360.f);
								for (int j = 0; j < 6; j++)
								{
									if (getMousePos(notCardPos[j].x, notCardPos[j].y, 16, *this->window) && notCardPos[j].cardOnIt == 0)
									{
										if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
										{
											if (!pressed)
											{
												pressed = true;

												if (deck[player1Pos1].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player1Pos2].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player1Pos3].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player1Pos4].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player1Pos5].type == 'n')
												{
													otherNot = 1;
												}

												if (otherNot)
												{
													deck[i].drag = 0;
													otherNot = 0;
													while (true)
													{
														setTimer();
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
														for (int i = 0; i < 6; i++)
														{
															if (notCardPos[i].cardOnIt == 1)
															{
																notCardPos[i].imgTexture.loadFromFile("assets/PlacedNotCard.png");
																notCardPos[i].img.setTexture(notCardPos[i].imgTexture);
																this->window->draw(notCardPos[i].img);
															}
														}
														tableOfTruth();
														setNotCardImages(cursorpos);
														for (int i = 1; i < 16; i++)
														{
															if (fPositions2[i].cardOnIt == 1)
															{
																this->window->draw(deck[fPositions2[i].cardNum].img);
															}
														}
														if (getMousePos(639, 530, 17, *this->window))
														{
															notCardPopTexture.loadFromFile("assets/NotCard2PopUp1.png");
															notCardPop.setTexture(notCardPopTexture);
															if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
															{
																if (deck[player1Pos1].type == 'n')
																{
																	deck[player1Pos1].drag = 0;
																	deck[player1Pos1].placed = 1;
																	deck[player1Pos1].num = 0;
																	deck[player1Pos1].type = 0;
																	deck[player1Pos1].value = 0;
																	deck[player1Pos1].player1pos = 0;
																	deck[player1Pos1].display1 = 0;
																	deck[player1Pos1].display2 = 0;
																	player1Pos1 = 0;
																}
																else if (deck[player1Pos2].type == 'n')
																{
																	deck[player1Pos2].drag = 0;
																	deck[player1Pos2].placed = 1;
																	deck[player1Pos2].num = 0;
																	deck[player1Pos2].type = 0;
																	deck[player1Pos2].value = 0;
																	deck[player1Pos2].player1pos = 0;
																	deck[player1Pos2].display1 = 0;
																	deck[player1Pos2].display2 = 0;
																	player1Pos2 = 0;
																}
																else if (deck[player1Pos3].type == 'n')
																{
																	deck[player1Pos3].drag = 0;
																	deck[player1Pos3].placed = 1;
																	deck[player1Pos3].num = 0;
																	deck[player1Pos3].type = 0;
																	deck[player1Pos3].value = 0;
																	deck[player1Pos3].player1pos = 0;
																	deck[player1Pos3].display1 = 0;
																	deck[player1Pos3].display2 = 0;
																	player1Pos3 = 0;
																}
																else if (deck[player1Pos4].type == 'n')
																{
																	deck[player1Pos4].drag = 0;
																	deck[player1Pos4].placed = 1;
																	deck[player1Pos4].num = 0;
																	deck[player1Pos4].type = 0;
																	deck[player1Pos4].value = 0;
																	deck[player1Pos4].player1pos = 0;
																	deck[player1Pos4].display1 = 0;
																	deck[player1Pos4].display2 = 0;
																	player1Pos4 = 0;
																}
																else if (deck[player1Pos5].type == 'n')
																{
																	deck[player1Pos5].drag = 0;
																	deck[player1Pos5].placed = 1;
																	deck[player1Pos5].num = 0;
																	deck[player1Pos5].type = 0;
																	deck[player1Pos5].value = 0;
																	deck[player1Pos5].player1pos = 0;
																	deck[player1Pos5].display1 = 0;
																	deck[player1Pos5].display2 = 0;
																	player1Pos5 = 0;
																}
																roundPlayed = 1;
																deck[i].drag = 0;
																deck[i].placed = 1;
																notCardPos[j].cardOnIt = 0;
																deck[i].num = 0;
																deck[i].type = 0;
																deck[i].value = 0;
																deck[i].player2pos = 0;
																deck[i].display1 = 0;
																deck[i].display2 = 0;
																card4Dragging2 = 0;
																player2Pos4 = 0;
																showNotA = 0;
																player1Cards--;
																player2Cards--;
																pressed = true;
																break;
															}
														}
														else if (getMousePos(823, 530, 17, *this->window))
														{
															notCardPopTexture.loadFromFile("assets/NotCard2PopUp2.png");
															notCardPop.setTexture(notCardPopTexture);
															if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
															{
																baseCards[j].value = !(baseCards[j].value);
																baseCards2[j].value = !(baseCards2[j].value);
																baseCards[j].BaseCardImg.setTexture(baseCards2[j].BaseCardImgTexture);
																baseCards2[j].BaseCardImg.setTexture(baseCards[j].BaseCardImgTexture);
																roundPlayed = 1;

																deck[i].drag = 0;
																deck[i].placed = 1;
																notCardPos[j].cardOnIt = 1;
																deck[i].num = 0;
																deck[i].type = 0;
																deck[i].value = 0;
																deck[i].player2pos = 0;
																deck[i].display1 = 0;
																deck[i].display2 = 0;
																card4Dragging2 = 0;
																player2Pos4 = 0;
																showNotA = 0;
																player2Cards--;
																pressed = true;
																notCardLogic(j);
																break;
															}
														}
														else
														{
															notCardPopTexture.loadFromFile("assets/NotCard2PopUp.png");
															notCardPop.setTexture(notCardPopTexture);
														}
														this->window->draw(notCardPop);
														this->window->display();
													}
												}
												else
												{
													baseCards[j].value = !(baseCards[j].value);
													baseCards2[j].value = !(baseCards2[j].value);
													baseCards[j].BaseCardImg.setTexture(baseCards2[j].BaseCardImgTexture);
													baseCards2[j].BaseCardImg.setTexture(baseCards[j].BaseCardImgTexture);
													roundPlayed = 1;

													deck[i].drag = 0;
													deck[i].placed = 1;
													notCardPos[j].cardOnIt = 1;
													deck[i].num = 0;
													deck[i].type = 0;
													deck[i].value = 0;
													deck[i].player1pos = 0;
													deck[i].display1 = 0;
													deck[i].display2 = 0;
													card4Dragging2 = 0;
													player2Pos4 = 0;
													showNotA = 0;
													player2Cards--;
													pressed = true;
													notCardLogic(j);
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
						}
						else
						{
							showNotA = 0;
							deck[i].img.setRotation(90.f);
						}
					}
					else
					{
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
													deck[counterNotCards3].type = deck[i].type;
													deck[counterNotCards3].value = deck[i].value;
													deck[counterNotCards3].num = counterNotCards3;
													deck[i].player2pos = 0;
													deck[i].display1 = 0;
													deck[i].display2 = 0;
													counterNotCards3++;
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
														deck[counterNotCards3].type = deck[i].type;
														deck[counterNotCards3].value = deck[i].value;
														deck[counterNotCards3].num = counterNotCards3;
														deck[i].player2pos = 0;
														deck[i].display1 = 0;
														deck[i].display2 = 0;
														counterNotCards3++;
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
					}
					if (getMousePos(200, 0, 10, *this->window))
					{
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
				}
				else if (player2Pos5 == i && !(card1Dragging2 || card2Dragging2 || card3Dragging2 || card4Dragging2) && !(roundPlayed)) // Display and drag The fifth card P2
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
					if (deck[i].type == 'n')
					{
						if (deck[i].drag && deck[i].type == 'n')
						{
							int x = cursorpos.x + 50;
							int y = cursorpos.y - 52;
							card5Dragging2 = 1;
							showNotA = 1;

							if (getMousePos(300, 0, 6, *this->window))
							{
								x = cursorpos.x - 52;
								y = cursorpos.y - 30;
								deck[i].img.setRotation(360.f);
								for (int j = 0; j < 6; j++)
								{
									if (getMousePos(notCardPos[j].x, notCardPos[j].y, 16, *this->window) && notCardPos[j].cardOnIt == 0)
									{
										if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
										{
											if (!pressed)
											{
												pressed = true;

												if (deck[player1Pos1].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player1Pos2].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player1Pos3].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player1Pos4].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player1Pos5].type == 'n')
												{
													otherNot = 1;
												}

												if (otherNot)
												{
													deck[i].drag = 0;
													otherNot = 0;
													while (true)
													{
														setTimer();
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
														for (int i = 0; i < 6; i++)
														{
															if (notCardPos[i].cardOnIt == 1)
															{
																notCardPos[i].imgTexture.loadFromFile("assets/PlacedNotCard.png");
																notCardPos[i].img.setTexture(notCardPos[i].imgTexture);
																this->window->draw(notCardPos[i].img);
															}
														}
														tableOfTruth();
														setNotCardImages(cursorpos);
														for (int i = 1; i < 16; i++)
														{
															if (fPositions2[i].cardOnIt == 1)
															{
																this->window->draw(deck[fPositions2[i].cardNum].img);
															}
														}
														if (getMousePos(639, 530, 17, *this->window))
														{
															notCardPopTexture.loadFromFile("assets/NotCard2PopUp1.png");
															notCardPop.setTexture(notCardPopTexture);
															if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
															{
																if (deck[player1Pos1].type == 'n')
																{
																	deck[player1Pos1].drag = 0;
																	deck[player1Pos1].placed = 1;
																	deck[player1Pos1].num = 0;
																	deck[player1Pos1].type = 0;
																	deck[player1Pos1].value = 0;
																	deck[player1Pos1].player1pos = 0;
																	deck[player1Pos1].display1 = 0;
																	deck[player1Pos1].display2 = 0;
																	player1Pos1 = 0;
																}
																else if (deck[player1Pos2].type == 'n')
																{
																	deck[player1Pos2].drag = 0;
																	deck[player1Pos2].placed = 1;
																	deck[player1Pos2].num = 0;
																	deck[player1Pos2].type = 0;
																	deck[player1Pos2].value = 0;
																	deck[player1Pos2].player1pos = 0;
																	deck[player1Pos2].display1 = 0;
																	deck[player1Pos2].display2 = 0;
																	player1Pos2 = 0;
																}
																else if (deck[player1Pos3].type == 'n')
																{
																	deck[player1Pos3].drag = 0;
																	deck[player1Pos3].placed = 1;
																	deck[player1Pos3].num = 0;
																	deck[player1Pos3].type = 0;
																	deck[player1Pos3].value = 0;
																	deck[player1Pos3].player1pos = 0;
																	deck[player1Pos3].display1 = 0;
																	deck[player1Pos3].display2 = 0;
																	player1Pos3 = 0;
																}
																else if (deck[player1Pos4].type == 'n')
																{
																	deck[player1Pos4].drag = 0;
																	deck[player1Pos4].placed = 1;
																	deck[player1Pos4].num = 0;
																	deck[player1Pos4].type = 0;
																	deck[player1Pos4].value = 0;
																	deck[player1Pos4].player1pos = 0;
																	deck[player1Pos4].display1 = 0;
																	deck[player1Pos4].display2 = 0;
																	player1Pos4 = 0;
																}
																else if (deck[player1Pos5].type == 'n')
																{
																	deck[player1Pos5].drag = 0;
																	deck[player1Pos5].placed = 1;
																	deck[player1Pos5].num = 0;
																	deck[player1Pos5].type = 0;
																	deck[player1Pos5].value = 0;
																	deck[player1Pos5].player1pos = 0;
																	deck[player1Pos5].display1 = 0;
																	deck[player1Pos5].display2 = 0;
																	player1Pos5 = 0;
																}
																roundPlayed = 1;
																deck[i].drag = 0;
																deck[i].placed = 1;
																notCardPos[j].cardOnIt = 0;
																deck[i].num = 0;
																deck[i].type = 0;
																deck[i].value = 0;
																deck[i].player2pos = 0;
																deck[i].display1 = 0;
																deck[i].display2 = 0;
																card5Dragging2 = 0;
																player2Pos5 = 0;
																showNotA = 0;
																player1Cards--;
																player2Cards--;
																pressed = true;
																break;
															}
														}
														else if (getMousePos(823, 530, 17, *this->window))
														{
															notCardPopTexture.loadFromFile("assets/NotCard2PopUp2.png");
															notCardPop.setTexture(notCardPopTexture);
															if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
															{
																baseCards[j].value = !(baseCards[j].value);
																baseCards2[j].value = !(baseCards2[j].value);
																baseCards[j].BaseCardImg.setTexture(baseCards2[j].BaseCardImgTexture);
																baseCards2[j].BaseCardImg.setTexture(baseCards[j].BaseCardImgTexture);
																roundPlayed = 1;

																deck[i].drag = 0;
																deck[i].placed = 1;
																notCardPos[j].cardOnIt = 1;
																deck[i].num = 0;
																deck[i].type = 0;
																deck[i].value = 0;
																deck[i].player2pos = 0;
																deck[i].display1 = 0;
																deck[i].display2 = 0;
																card5Dragging2 = 0;
																player2Pos5 = 0;
																showNotA = 0;
																player2Cards--;
																pressed = true;
																notCardLogic(j);
																break;
															}
														}
														else
														{
															notCardPopTexture.loadFromFile("assets/NotCard2PopUp.png");
															notCardPop.setTexture(notCardPopTexture);
														}
														this->window->draw(notCardPop);
														this->window->display();
													}
												}
												else
												{
													baseCards[j].value = !(baseCards[j].value);
													baseCards2[j].value = !(baseCards2[j].value);
													baseCards[j].BaseCardImg.setTexture(baseCards2[j].BaseCardImgTexture);
													baseCards2[j].BaseCardImg.setTexture(baseCards[j].BaseCardImgTexture);
													roundPlayed = 1;

													deck[i].drag = 0;
													deck[i].placed = 1;
													notCardPos[j].cardOnIt = 1;
													deck[i].num = 0;
													deck[i].type = 0;
													deck[i].value = 0;
													deck[i].player1pos = 0;
													deck[i].display1 = 0;
													deck[i].display2 = 0;
													card5Dragging2 = 0;
													player2Pos5 = 0;
													showNotA = 0;
													player2Cards--;
													pressed = true;
													notCardLogic(j);
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
						}
						else
						{
							showNotA = 0;
							deck[i].img.setRotation(90.f);
						}
					}
					else
					{
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
													deck[counterNotCards3].type = deck[i].type;
													deck[counterNotCards3].value = deck[i].value;
													deck[counterNotCards3].num = counterNotCards3;
													deck[i].player2pos = 0;
													deck[i].display1 = 0;
													deck[i].display2 = 0;
													counterNotCards3++;
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
														deck[counterNotCards3].type = deck[i].type;
														deck[counterNotCards3].value = deck[i].value;
														deck[counterNotCards3].num = counterNotCards3;
														deck[i].player2pos = 0;
														deck[i].display1 = 0;
														deck[i].display2 = 0;
														counterNotCards3++;
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
					}
					if (getMousePos(200, 0, 10, *this->window))
					{
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
				}
				// Displaying by type P2
			}
			if (deck[i].value == 0 && !(deck[i].num == fPositions[i].cardNum))
			{
				switch (specialButtonC)
				{
				case 0:
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
					break;
				case 1:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				case 2:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				case 3:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				case 4:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				case 5:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				}
			}
			else if (deck[i].value == 0 && (deck[i].num == fPositions[i].cardNum))
			{
				switch (specialButtonC)
				{
				case 0:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 1:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 2:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 3:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 4:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 5:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				}
			}
			else if (deck[i].value == 1 && !(deck[i].num == fPositions[i].cardNum))
			{

				switch (specialButtonC)
				{
				case 0:
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
					break;
				case 1:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				case 2:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				case 3:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				case 4:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				case 5:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				}
			}
			else if (deck[i].value == 1 && (deck[i].num == fPositions[i].cardNum))
			{

				switch (specialButtonC)
				{
				case 0:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 1:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 2:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 3:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 4:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 5:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				}
			}
			else if (deck[i].type == 'n' && !(deck[i].num == fPositions[i].cardNum))
			{
			switch (specialButtonC)
			{
			case 0:
				deck[i].imgTexture.loadFromFile("assets/NotCard.png");
				this->deck[i].imgTexture.setSmooth(true);
				deck[i].img.setTexture(deck[i].imgTexture);
				this->window->draw(deck[i].img);
				break;
			case 1:
				deck[i].imgTexture.loadFromFile("assets/NavyBundle/NotCard.png");
				this->deck[i].imgTexture.setSmooth(true);
				deck[i].img.setTexture(deck[i].imgTexture);
				this->window->draw(deck[i].img);
				break;
			case 2:
				deck[i].imgTexture.loadFromFile("assets/SunsetBundle/NotCard.png");
				this->deck[i].imgTexture.setSmooth(true);
				deck[i].img.setTexture(deck[i].imgTexture);
				this->window->draw(deck[i].img);
				break;
			case 3:
				deck[i].imgTexture.loadFromFile("assets/SeaBundle/NotCard.png");
				this->deck[i].imgTexture.setSmooth(true);
				deck[i].img.setTexture(deck[i].imgTexture);
				this->window->draw(deck[i].img);
				break;
			case 4:
				deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/NotCard.png");
				this->deck[i].imgTexture.setSmooth(true);
				deck[i].img.setTexture(deck[i].imgTexture);
				this->window->draw(deck[i].img);
				break;
			case 5:
				deck[i].imgTexture.loadFromFile("assets/CosmosBundle/NotCard.png");
				this->deck[i].imgTexture.setSmooth(true);
				deck[i].img.setTexture(deck[i].imgTexture);
				this->window->draw(deck[i].img);
				break;
			}
			}
			else if (deck[i].type == 'n' && (deck[i].num == fPositions[i].cardNum))
			{
			switch (specialButtonC)
			{
			case 0:
				deck[i].imgTexture.loadFromFile("assets/NotCard.png");
				this->deck[i].imgTexture.setSmooth(true);
				deck[i].img.setTexture(deck[i].imgTexture);
				break;
			case 1:
				deck[i].imgTexture.loadFromFile("assets/NavyBundle/NotCard.png");
				this->deck[i].imgTexture.setSmooth(true);
				deck[i].img.setTexture(deck[i].imgTexture);
				break;
			case 2:
				deck[i].imgTexture.loadFromFile("assets/SunsetBundle/NotCard.png");
				this->deck[i].imgTexture.setSmooth(true);
				deck[i].img.setTexture(deck[i].imgTexture);
				break;
			case 3:
				deck[i].imgTexture.loadFromFile("assets/SeaBundle/NotCard.png");
				this->deck[i].imgTexture.setSmooth(true);
				deck[i].img.setTexture(deck[i].imgTexture);
				break;
			case 4:
				deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/NotCard.png");
				this->deck[i].imgTexture.setSmooth(true);
				deck[i].img.setTexture(deck[i].imgTexture);
				break;
			case 5:
				deck[i].imgTexture.loadFromFile("assets/CosmosBundle/NotCard.png");
				this->deck[i].imgTexture.setSmooth(true);
				deck[i].img.setTexture(deck[i].imgTexture);
				break;
			}
			}
		}
	}
}

void Game::setNotCardImages2(sf::Vector2i cursorpos)
{
	int numCounter = 1;

	for (int i = 1; i <= counterNotCards3; i++)
	{
		if (deck[i].display1 == 1 && counter == 1)
		{
			if (deck[i].player1pos == 1)
			{
				if (player1Pos1 == i && !(card2Dragging || card3Dragging || card4Dragging || card5Dragging) && !(roundPlayed))  // Display and drag The first card
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
					if (deck[i].type == 'n')
					{
						if (deck[i].drag && deck[i].type == 'n')
						{
							int x = cursorpos.x + 50;
							int y = cursorpos.y - 52;
							card1Dragging = 1;
							showNotA = 1;

							if (getMousePos(300, 0, 6, *this->window))
							{
								x = cursorpos.x - 52;
								y = cursorpos.y - 30;
								deck[i].img.setRotation(360.f);
								for (int j = 0; j < 6; j++)
								{
									if (getMousePos(notCardPos[j].x, notCardPos[j].y, 16, *this->window) && notCardPos[j].cardOnIt == 0)
									{
										if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
										{
											if (!pressed)
											{
												pressed = true;

												if (deck[player2Pos1].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player2Pos2].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player2Pos3].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player2Pos4].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player2Pos5].type == 'n')
												{
													otherNot = 1;
												}

												if (otherNot)
												{
													srand((unsigned)time(0));
													int shouldPlayNot = rand() % 10 + 1;
													deck[i].drag = 0;
													otherNot = 0;

													if (shouldPlayNot <= 6)
													{
														if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
														{
															if (deck[player2Pos1].type == 'n')
															{
																deck[player2Pos1].drag = 0;
																deck[player2Pos1].placed = 1;
																deck[player2Pos1].num = 0;
																deck[player2Pos1].type = 0;
																deck[player2Pos1].value = 0;
																deck[player2Pos1].player2pos = 0;
																deck[player2Pos1].display1 = 0;
																deck[player2Pos1].display2 = 0;
																player2Pos1 = 0;
															}
															else if (deck[player2Pos2].type == 'n')
															{
																deck[player2Pos2].drag = 0;
																deck[player2Pos2].placed = 1;
																deck[player2Pos2].num = 0;
																deck[player2Pos2].type = 0;
																deck[player2Pos2].value = 0;
																deck[player2Pos2].player2pos = 0;
																deck[player2Pos2].display1 = 0;
																deck[player2Pos2].display2 = 0;
																player2Pos2 = 0;
															}
															else if (deck[player2Pos3].type == 'n')
															{
																deck[player2Pos3].drag = 0;
																deck[player2Pos3].placed = 1;
																deck[player2Pos3].num = 0;
																deck[player2Pos3].type = 0;
																deck[player2Pos3].value = 0;
																deck[player2Pos3].player2pos = 0;
																deck[player2Pos3].display1 = 0;
																deck[player2Pos3].display2 = 0;
																player2Pos3 = 0;
															}
															else if (deck[player2Pos4].type == 'n')
															{
																deck[player2Pos4].drag = 0;
																deck[player2Pos4].placed = 1;
																deck[player2Pos4].num = 0;
																deck[player2Pos4].type = 0;
																deck[player2Pos4].value = 0;
																deck[player2Pos4].player2pos = 0;
																deck[player2Pos4].display1 = 0;
																deck[player2Pos4].display2 = 0;
																player2Pos4 = 0;
															}
															else if (deck[player2Pos5].type == 'n')
															{
																deck[player2Pos5].drag = 0;
																deck[player2Pos5].placed = 1;
																deck[player2Pos5].num = 0;
																deck[player2Pos5].type = 0;
																deck[player2Pos5].value = 0;
																deck[player2Pos5].player2pos = 0;
																deck[player2Pos5].display1 = 0;
																deck[player2Pos5].display2 = 0;
																player2Pos5 = 0;
															}
															roundPlayed = 1;
															deck[i].drag = 0;
															deck[i].placed = 1;
															notCardPos[j].cardOnIt = 0;
															deck[i].num = 0;
															deck[i].type = 0;
															deck[i].value = 0;
															deck[i].player1pos = 0;
															deck[i].display1 = 0;
															deck[i].display2 = 0;
															card1Dragging = 0;
															player1Pos1 = 0;
															showNotA = 0;
															player1Cards--;
															player2Cards--;
															pressed = true;
															break;
														}
													}
												else if (shouldPlayNot >= 7)
												{
													if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
													{
													baseCards[j].value = !(baseCards[j].value);
													baseCards2[j].value = !(baseCards2[j].value);
													baseCards[j].BaseCardImg.setTexture(baseCards2[j].BaseCardImgTexture);
													baseCards2[j].BaseCardImg.setTexture(baseCards[j].BaseCardImgTexture);
													roundPlayed = 1;
													deck[i].drag = 0;
													deck[i].placed = 1;
													notCardPos[j].cardOnIt = 1;
													deck[i].num = 0;
													deck[i].type = 0;
													deck[i].value = 0;
													deck[i].player1pos = 0;
													deck[i].display1 = 0;
													deck[i].display2 = 0;
													card1Dragging = 0;
													player1Pos1 = 0;
													showNotA = 0;
													player1Cards--;
													pressed = true;
													notCardLogic(j);
													break;
													}
												}		
												}
												else
												{
													baseCards[j].value = !(baseCards[j].value);
													baseCards2[j].value = !(baseCards2[j].value);
													baseCards[j].BaseCardImg.setTexture(baseCards2[j].BaseCardImgTexture);
													baseCards2[j].BaseCardImg.setTexture(baseCards[j].BaseCardImgTexture);
													roundPlayed = 1;

													deck[i].drag = 0;
													deck[i].placed = 1;
													notCardPos[j].cardOnIt = 1;
													deck[i].num = 0;
													deck[i].type = 0;
													deck[i].value = 0;
													deck[i].player1pos = 0;
													deck[i].display1 = 0;
													deck[i].display2 = 0;
													card1Dragging = 0;
													player1Pos1 = 0;
													showNotA = 0;
													player1Cards--;
													pressed = true;
													notCardLogic(j);
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
						}
						else
						{
							showNotA = 0;
							deck[i].img.setRotation(90.f);
						}
					}
					else
					{
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
													deck[counterNotCards3].type = deck[i].type;
													deck[counterNotCards3].value = deck[i].value;
													deck[counterNotCards3].num = counterNotCards3;
													deck[i].type = 0;
													deck[i].value = 0;
													deck[i].player1pos = 0;
													deck[i].display1 = 0;
													deck[i].display2 = 0;
													counterNotCards3++;
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
														deck[counterNotCards3].type = deck[i].type;
														deck[counterNotCards3].value = deck[i].value;
														deck[counterNotCards3].num = counterNotCards3;
														deck[i].type = 0;
														deck[i].value = 0;
														deck[i].player1pos = 0;
														deck[i].display1 = 0;
														deck[i].display2 = 0;
														counterNotCards3++;
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
						}
						else
						{
							showA = 0;
							deck[i].img.setRotation(90.f);
						}
					}
					if (getMousePos(200, 0, 10, *this->window))
					{
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
				}
				else if (player1Pos2 == i && !(card1Dragging || card3Dragging || card4Dragging || card5Dragging) && !(roundPlayed)) // Display and drag The second card
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
					if (deck[i].type == 'n')
					{
						if (deck[i].drag && deck[i].type == 'n')
						{
							int x = cursorpos.x + 50;
							int y = cursorpos.y - 52;
							card2Dragging = 1;
							showNotA = 1;

							if (getMousePos(300, 0, 6, *this->window))
							{
								x = cursorpos.x - 52;
								y = cursorpos.y - 30;
								deck[i].img.setRotation(360.f);
								for (int j = 0; j < 6; j++)
								{
									if (getMousePos(notCardPos[j].x, notCardPos[j].y, 16, *this->window) && notCardPos[j].cardOnIt == 0)
									{
										if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
										{
											if (!pressed)
											{
												pressed = true;

												if (deck[player2Pos1].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player2Pos2].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player2Pos3].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player2Pos4].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player2Pos5].type == 'n')
												{
													otherNot = 1;
												}

												if (otherNot)
												{
													srand((unsigned)time(0));
													int shouldPlayNot = rand() % 10 + 1;
													deck[i].drag = 0;
													otherNot = 0;

													if (shouldPlayNot <= 6)
													{
														if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
														{
															if (deck[player2Pos1].type == 'n')
															{
																deck[player2Pos1].drag = 0;
																deck[player2Pos1].placed = 1;
																deck[player2Pos1].num = 0;
																deck[player2Pos1].type = 0;
																deck[player2Pos1].value = 0;
																deck[player2Pos1].player2pos = 0;
																deck[player2Pos1].display1 = 0;
																deck[player2Pos1].display2 = 0;
																player2Pos1 = 0;
															}
															else if (deck[player2Pos2].type == 'n')
															{
																deck[player2Pos2].drag = 0;
																deck[player2Pos2].placed = 1;
																deck[player2Pos2].num = 0;
																deck[player2Pos2].type = 0;
																deck[player2Pos2].value = 0;
																deck[player2Pos2].player2pos = 0;
																deck[player2Pos2].display1 = 0;
																deck[player2Pos2].display2 = 0;
																player2Pos2 = 0;
															}
															else if (deck[player2Pos3].type == 'n')
															{
																deck[player2Pos3].drag = 0;
																deck[player2Pos3].placed = 1;
																deck[player2Pos3].num = 0;
																deck[player2Pos3].type = 0;
																deck[player2Pos3].value = 0;
																deck[player2Pos3].player2pos = 0;
																deck[player2Pos3].display1 = 0;
																deck[player2Pos3].display2 = 0;
																player2Pos3 = 0;
															}
															else if (deck[player2Pos4].type == 'n')
															{
																deck[player2Pos4].drag = 0;
																deck[player2Pos4].placed = 1;
																deck[player2Pos4].num = 0;
																deck[player2Pos4].type = 0;
																deck[player2Pos4].value = 0;
																deck[player2Pos4].player2pos = 0;
																deck[player2Pos4].display1 = 0;
																deck[player2Pos4].display2 = 0;
																player2Pos4 = 0;
															}
															else if (deck[player2Pos5].type == 'n')
															{
																deck[player2Pos5].drag = 0;
																deck[player2Pos5].placed = 1;
																deck[player2Pos5].num = 0;
																deck[player2Pos5].type = 0;
																deck[player2Pos5].value = 0;
																deck[player2Pos5].player2pos = 0;
																deck[player2Pos5].display1 = 0;
																deck[player2Pos5].display2 = 0;
																player2Pos5 = 0;
															}
															roundPlayed = 1;
															deck[i].drag = 0;
															deck[i].placed = 1;
															notCardPos[j].cardOnIt = 0;
															deck[i].num = 0;
															deck[i].type = 0;
															deck[i].value = 0;
															deck[i].player1pos = 0;
															deck[i].display1 = 0;
															deck[i].display2 = 0;
															card2Dragging = 0;
															player1Pos2 = 0;
															showNotA = 0;
															player1Cards--;
															player2Cards--;
															pressed = true;
															break;
														}
													}
													else if (shouldPlayNot >= 7)
													{
														if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
														{
															baseCards[j].value = !(baseCards[j].value);
															baseCards2[j].value = !(baseCards2[j].value);
															baseCards[j].BaseCardImg.setTexture(baseCards2[j].BaseCardImgTexture);
															baseCards2[j].BaseCardImg.setTexture(baseCards[j].BaseCardImgTexture);
															roundPlayed = 1;
															deck[i].drag = 0;
															deck[i].placed = 1;
															notCardPos[j].cardOnIt = 1;
															deck[i].num = 0;
															deck[i].type = 0;
															deck[i].value = 0;
															deck[i].player1pos = 0;
															deck[i].display1 = 0;
															deck[i].display2 = 0;
															card2Dragging = 0;
															player1Pos2 = 0;
															showNotA = 0;
															player1Cards--;
															pressed = true;
															notCardLogic(j);
															break;
														}
													}
												}
												else
												{
													baseCards[j].value = !(baseCards[j].value);
													baseCards2[j].value = !(baseCards2[j].value);
													baseCards[j].BaseCardImg.setTexture(baseCards2[j].BaseCardImgTexture);
													baseCards2[j].BaseCardImg.setTexture(baseCards[j].BaseCardImgTexture);
													roundPlayed = 1;

													deck[i].drag = 0;
													deck[i].placed = 1;
													notCardPos[j].cardOnIt = 1;
													deck[i].num = 0;
													deck[i].type = 0;
													deck[i].value = 0;
													deck[i].player1pos = 0;
													deck[i].display1 = 0;
													deck[i].display2 = 0;
													card2Dragging = 0;
													player1Pos2 = 0;
													showNotA = 0;
													player1Cards--;
													pressed = true;
													notCardLogic(j);
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
						}
						else
						{
							showNotA = 0;
							deck[i].img.setRotation(90.f);
						}
					}
					else
					{
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
													deck[counterNotCards3].type = deck[i].type;
													deck[counterNotCards3].value = deck[i].value;
													deck[counterNotCards3].num = counterNotCards3;
													deck[i].type = 0;
													deck[i].value = 0;
													deck[i].player1pos = 0;
													deck[i].display1 = 0;
													deck[i].display2 = 0;
													counterNotCards3++;
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
														deck[counterNotCards3].type = deck[i].type;
														deck[counterNotCards3].value = deck[i].value;
														deck[counterNotCards3].num = counterNotCards3;
														deck[i].type = 0;
														deck[i].value = 0;
														deck[i].player1pos = 0;
														deck[i].display1 = 0;
														deck[i].display2 = 0;
														counterNotCards3++;
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
					}
					if (getMousePos(200, 0, 10, *this->window))
					{
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
				}
				else if (player1Pos3 == i && !(card1Dragging || card2Dragging || card4Dragging || card5Dragging) && !(roundPlayed)) // Display and drag The third card
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
					if (deck[i].type == 'n')
					{
						if (deck[i].drag && deck[i].type == 'n')
						{
							int x = cursorpos.x + 50;
							int y = cursorpos.y - 52;
							card3Dragging = 1;
							showNotA = 1;

							if (getMousePos(300, 0, 6, *this->window))
							{
								x = cursorpos.x - 52;
								y = cursorpos.y - 30;
								deck[i].img.setRotation(360.f);
								for (int j = 0; j < 6; j++)
								{
									if (getMousePos(notCardPos[j].x, notCardPos[j].y, 16, *this->window) && notCardPos[j].cardOnIt == 0)
									{
										if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
										{
											if (!pressed)
											{
												pressed = true;

												if (deck[player2Pos1].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player2Pos2].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player2Pos3].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player2Pos4].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player2Pos5].type == 'n')
												{
													otherNot = 1;
												}

												if (otherNot)
												{
													srand((unsigned)time(0));
													int shouldPlayNot = rand() % 10 + 1;
													deck[i].drag = 0;
													otherNot = 0;

													if (shouldPlayNot <= 6)
													{
														if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
														{
															if (deck[player2Pos1].type == 'n')
															{
																deck[player2Pos1].drag = 0;
																deck[player2Pos1].placed = 1;
																deck[player2Pos1].num = 0;
																deck[player2Pos1].type = 0;
																deck[player2Pos1].value = 0;
																deck[player2Pos1].player2pos = 0;
																deck[player2Pos1].display1 = 0;
																deck[player2Pos1].display2 = 0;
																player2Pos1 = 0;
															}
															else if (deck[player2Pos2].type == 'n')
															{
																deck[player2Pos2].drag = 0;
																deck[player2Pos2].placed = 1;
																deck[player2Pos2].num = 0;
																deck[player2Pos2].type = 0;
																deck[player2Pos2].value = 0;
																deck[player2Pos2].player2pos = 0;
																deck[player2Pos2].display1 = 0;
																deck[player2Pos2].display2 = 0;
																player2Pos2 = 0;
															}
															else if (deck[player2Pos3].type == 'n')
															{
																deck[player2Pos3].drag = 0;
																deck[player2Pos3].placed = 1;
																deck[player2Pos3].num = 0;
																deck[player2Pos3].type = 0;
																deck[player2Pos3].value = 0;
																deck[player2Pos3].player2pos = 0;
																deck[player2Pos3].display1 = 0;
																deck[player2Pos3].display2 = 0;
																player2Pos3 = 0;
															}
															else if (deck[player2Pos4].type == 'n')
															{
																deck[player2Pos4].drag = 0;
																deck[player2Pos4].placed = 1;
																deck[player2Pos4].num = 0;
																deck[player2Pos4].type = 0;
																deck[player2Pos4].value = 0;
																deck[player2Pos4].player2pos = 0;
																deck[player2Pos4].display1 = 0;
																deck[player2Pos4].display2 = 0;
																player2Pos4 = 0;
															}
															else if (deck[player2Pos5].type == 'n')
															{
																deck[player2Pos5].drag = 0;
																deck[player2Pos5].placed = 1;
																deck[player2Pos5].num = 0;
																deck[player2Pos5].type = 0;
																deck[player2Pos5].value = 0;
																deck[player2Pos5].player2pos = 0;
																deck[player2Pos5].display1 = 0;
																deck[player2Pos5].display2 = 0;
																player2Pos5 = 0;
															}
															roundPlayed = 1;
															deck[i].drag = 0;
															deck[i].placed = 1;
															notCardPos[j].cardOnIt = 0;
															deck[i].num = 0;
															deck[i].type = 0;
															deck[i].value = 0;
															deck[i].player1pos = 0;
															deck[i].display1 = 0;
															deck[i].display2 = 0;
															card3Dragging = 0;
															player1Pos3 = 0;
															showNotA = 0;
															player1Cards--;
															player2Cards--;
															pressed = true;
															break;
														}
													}
													else if (shouldPlayNot >= 7)
													{
														if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
														{
															baseCards[j].value = !(baseCards[j].value);
															baseCards2[j].value = !(baseCards2[j].value);
															baseCards[j].BaseCardImg.setTexture(baseCards2[j].BaseCardImgTexture);
															baseCards2[j].BaseCardImg.setTexture(baseCards[j].BaseCardImgTexture);
															roundPlayed = 1;
															deck[i].drag = 0;
															deck[i].placed = 1;
															notCardPos[j].cardOnIt = 1;
															deck[i].num = 0;
															deck[i].type = 0;
															deck[i].value = 0;
															deck[i].player1pos = 0;
															deck[i].display1 = 0;
															deck[i].display2 = 0;
															card3Dragging = 0;
															player1Pos3 = 0;
															showNotA = 0;
															player1Cards--;
															pressed = true;
															notCardLogic(j);
															break;
														}
													}
												}
												else
												{
													baseCards[j].value = !(baseCards[j].value);
													baseCards2[j].value = !(baseCards2[j].value);
													baseCards[j].BaseCardImg.setTexture(baseCards2[j].BaseCardImgTexture);
													baseCards2[j].BaseCardImg.setTexture(baseCards[j].BaseCardImgTexture);
													roundPlayed = 1;

													deck[i].drag = 0;
													deck[i].placed = 1;
													notCardPos[j].cardOnIt = 1;
													deck[i].num = 0;
													deck[i].type = 0;
													deck[i].value = 0;
													deck[i].player1pos = 0;
													deck[i].display1 = 0;
													deck[i].display2 = 0;
													card3Dragging = 0;
													player1Pos3 = 0;
													showNotA = 0;
													player1Cards--;
													pressed = true;
													notCardLogic(j);
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
						}
						else
						{
							showNotA = 0;
							deck[i].img.setRotation(90.f);
						}
					}
					else
					{
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
													deck[counterNotCards3].type = deck[i].type;
													deck[counterNotCards3].value = deck[i].value;
													deck[counterNotCards3].num = counterNotCards3;
													deck[i].type = 0;
													deck[i].value = 0;
													deck[i].player1pos = 0;
													deck[i].display1 = 0;
													deck[i].display2 = 0;
													counterNotCards3++;
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
														deck[counterNotCards3].type = deck[i].type;
														deck[counterNotCards3].value = deck[i].value;
														deck[counterNotCards3].num = counterNotCards3;
														deck[i].type = 0;
														deck[i].value = 0;
														deck[i].player1pos = 0;
														deck[i].display1 = 0;
														deck[i].display2 = 0;
														counterNotCards3++;
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
					}
					if (getMousePos(200, 0, 10, *this->window))
					{
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
				}
				else if (player1Pos4 == i && !(card1Dragging || card2Dragging || card3Dragging || card5Dragging) && !(roundPlayed)) // Display and drag The fourth card
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
					if (deck[i].type == 'n')
					{
						if (deck[i].drag && deck[i].type == 'n')
						{
							int x = cursorpos.x + 50;
							int y = cursorpos.y - 52;
							card4Dragging = 1;
							showNotA = 1;

							if (getMousePos(300, 0, 6, *this->window))
							{
								x = cursorpos.x - 52;
								y = cursorpos.y - 30;
								deck[i].img.setRotation(360.f);
								for (int j = 0; j < 6; j++)
								{
									if (getMousePos(notCardPos[j].x, notCardPos[j].y, 16, *this->window) && notCardPos[j].cardOnIt == 0)
									{
										if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
										{
											if (!pressed)
											{
												pressed = true;

												if (deck[player2Pos1].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player2Pos2].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player2Pos3].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player2Pos4].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player2Pos5].type == 'n')
												{
													otherNot = 1;
												}

												if (otherNot)
												{
													srand((unsigned)time(0));
													int shouldPlayNot = rand() % 10 + 1;
													deck[i].drag = 0;
													otherNot = 0;

													if (shouldPlayNot <= 6)
													{
														if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
														{
															if (deck[player2Pos1].type == 'n')
															{
																deck[player2Pos1].drag = 0;
																deck[player2Pos1].placed = 1;
																deck[player2Pos1].num = 0;
																deck[player2Pos1].type = 0;
																deck[player2Pos1].value = 0;
																deck[player2Pos1].player2pos = 0;
																deck[player2Pos1].display1 = 0;
																deck[player2Pos1].display2 = 0;
																player2Pos1 = 0;
															}
															else if (deck[player2Pos2].type == 'n')
															{
																deck[player2Pos2].drag = 0;
																deck[player2Pos2].placed = 1;
																deck[player2Pos2].num = 0;
																deck[player2Pos2].type = 0;
																deck[player2Pos2].value = 0;
																deck[player2Pos2].player2pos = 0;
																deck[player2Pos2].display1 = 0;
																deck[player2Pos2].display2 = 0;
																player2Pos2 = 0;
															}
															else if (deck[player2Pos3].type == 'n')
															{
																deck[player2Pos3].drag = 0;
																deck[player2Pos3].placed = 1;
																deck[player2Pos3].num = 0;
																deck[player2Pos3].type = 0;
																deck[player2Pos3].value = 0;
																deck[player2Pos3].player2pos = 0;
																deck[player2Pos3].display1 = 0;
																deck[player2Pos3].display2 = 0;
																player2Pos3 = 0;
															}
															else if (deck[player2Pos4].type == 'n')
															{
																deck[player2Pos4].drag = 0;
																deck[player2Pos4].placed = 1;
																deck[player2Pos4].num = 0;
																deck[player2Pos4].type = 0;
																deck[player2Pos4].value = 0;
																deck[player2Pos4].player2pos = 0;
																deck[player2Pos4].display1 = 0;
																deck[player2Pos4].display2 = 0;
																player2Pos4 = 0;
															}
															else if (deck[player2Pos5].type == 'n')
															{
																deck[player2Pos5].drag = 0;
																deck[player2Pos5].placed = 1;
																deck[player2Pos5].num = 0;
																deck[player2Pos5].type = 0;
																deck[player2Pos5].value = 0;
																deck[player2Pos5].player2pos = 0;
																deck[player2Pos5].display1 = 0;
																deck[player2Pos5].display2 = 0;
																player2Pos5 = 0;
															}
															roundPlayed = 1;
															deck[i].drag = 0;
															deck[i].placed = 1;
															notCardPos[j].cardOnIt = 0;
															deck[i].num = 0;
															deck[i].type = 0;
															deck[i].value = 0;
															deck[i].player1pos = 0;
															deck[i].display1 = 0;
															deck[i].display2 = 0;
															card4Dragging = 0;
															player1Pos4 = 0;
															showNotA = 0;
															player1Cards--;
															player2Cards--;
															pressed = true;
															break;
														}
													}
													else if (shouldPlayNot >= 7)
													{
														if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
														{
															baseCards[j].value = !(baseCards[j].value);
															baseCards2[j].value = !(baseCards2[j].value);
															baseCards[j].BaseCardImg.setTexture(baseCards2[j].BaseCardImgTexture);
															baseCards2[j].BaseCardImg.setTexture(baseCards[j].BaseCardImgTexture);
															roundPlayed = 1;
															deck[i].drag = 0;
															deck[i].placed = 1;
															notCardPos[j].cardOnIt = 1;
															deck[i].num = 0;
															deck[i].type = 0;
															deck[i].value = 0;
															deck[i].player1pos = 0;
															deck[i].display1 = 0;
															deck[i].display2 = 0;
															card4Dragging = 0;
															player1Pos4 = 0;
															showNotA = 0;
															player1Cards--;
															pressed = true;
															notCardLogic(j);
															break;
														}
													}
												}
												else
												{
													baseCards[j].value = !(baseCards[j].value);
													baseCards2[j].value = !(baseCards2[j].value);
													baseCards[j].BaseCardImg.setTexture(baseCards2[j].BaseCardImgTexture);
													baseCards2[j].BaseCardImg.setTexture(baseCards[j].BaseCardImgTexture);
													roundPlayed = 1;

													deck[i].drag = 0;
													deck[i].placed = 1;
													notCardPos[j].cardOnIt = 1;
													deck[i].num = 0;
													deck[i].type = 0;
													deck[i].value = 0;
													deck[i].player1pos = 0;
													deck[i].display1 = 0;
													deck[i].display2 = 0;
													card4Dragging = 0;
													player1Pos4 = 0;
													showNotA = 0;
													player1Cards--;
													pressed = true;
													notCardLogic(j);
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
						}
						else
						{
							showNotA = 0;
							deck[i].img.setRotation(90.f);
						}
					}
					else
					{
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
													deck[counterNotCards3].type = deck[i].type;
													deck[counterNotCards3].value = deck[i].value;
													deck[counterNotCards3].num = counterNotCards3;
													deck[i].type = 0;
													deck[i].value = 0;
													deck[i].player1pos = 0;
													deck[i].display1 = 0;
													deck[i].display2 = 0;
													counterNotCards3++;
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
														deck[counterNotCards3].type = deck[i].type;
														deck[counterNotCards3].value = deck[i].value;
														deck[counterNotCards3].num = counterNotCards3;
														deck[i].type = 0;
														deck[i].value = 0;
														deck[i].player1pos = 0;
														deck[i].display1 = 0;
														deck[i].display2 = 0;
														counterNotCards3++;
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
					}
					if (getMousePos(200, 0, 10, *this->window))
					{
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
				}
				else if (player1Pos5 == i && !(card1Dragging || card2Dragging || card3Dragging || card4Dragging) && !(roundPlayed)) // Display and drag The fifth card
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
					if (deck[i].type == 'n')
					{
						if (deck[i].drag && deck[i].type == 'n')
						{
							int x = cursorpos.x + 50;
							int y = cursorpos.y - 52;
							card5Dragging = 1;
							showNotA = 1;

							if (getMousePos(300, 0, 6, *this->window))
							{
								x = cursorpos.x - 52;
								y = cursorpos.y - 30;
								deck[i].img.setRotation(360.f);
								for (int j = 0; j < 6; j++)
								{
									if (getMousePos(notCardPos[j].x, notCardPos[j].y, 16, *this->window) && notCardPos[j].cardOnIt == 0)
									{
										if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
										{
											if (!pressed)
											{
												pressed = true;

												if (deck[player2Pos1].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player2Pos2].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player2Pos3].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player2Pos4].type == 'n')
												{
													otherNot = 1;
												}
												else if (deck[player2Pos5].type == 'n')
												{
													otherNot = 1;
												}

												if (otherNot)
												{
													srand((unsigned)time(0));
													int shouldPlayNot = rand() % 10 + 1;
													deck[i].drag = 0;
													otherNot = 0;

													if (shouldPlayNot <= 6)
													{
														if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
														{
															if (deck[player2Pos1].type == 'n')
															{
																deck[player2Pos1].drag = 0;
																deck[player2Pos1].placed = 1;
																deck[player2Pos1].num = 0;
																deck[player2Pos1].type = 0;
																deck[player2Pos1].value = 0;
																deck[player2Pos1].player2pos = 0;
																deck[player2Pos1].display1 = 0;
																deck[player2Pos1].display2 = 0;
																player2Pos1 = 0;
															}
															else if (deck[player2Pos2].type == 'n')
															{
																deck[player2Pos2].drag = 0;
																deck[player2Pos2].placed = 1;
																deck[player2Pos2].num = 0;
																deck[player2Pos2].type = 0;
																deck[player2Pos2].value = 0;
																deck[player2Pos2].player2pos = 0;
																deck[player2Pos2].display1 = 0;
																deck[player2Pos2].display2 = 0;
																player2Pos2 = 0;
															}
															else if (deck[player2Pos3].type == 'n')
															{
																deck[player2Pos3].drag = 0;
																deck[player2Pos3].placed = 1;
																deck[player2Pos3].num = 0;
																deck[player2Pos3].type = 0;
																deck[player2Pos3].value = 0;
																deck[player2Pos3].player2pos = 0;
																deck[player2Pos3].display1 = 0;
																deck[player2Pos3].display2 = 0;
																player2Pos3 = 0;
															}
															else if (deck[player2Pos4].type == 'n')
															{
																deck[player2Pos4].drag = 0;
																deck[player2Pos4].placed = 1;
																deck[player2Pos4].num = 0;
																deck[player2Pos4].type = 0;
																deck[player2Pos4].value = 0;
																deck[player2Pos4].player2pos = 0;
																deck[player2Pos4].display1 = 0;
																deck[player2Pos4].display2 = 0;
																player2Pos4 = 0;
															}
															else if (deck[player2Pos5].type == 'n')
															{
																deck[player2Pos5].drag = 0;
																deck[player2Pos5].placed = 1;
																deck[player2Pos5].num = 0;
																deck[player2Pos5].type = 0;
																deck[player2Pos5].value = 0;
																deck[player2Pos5].player2pos = 0;
																deck[player2Pos5].display1 = 0;
																deck[player2Pos5].display2 = 0;
																player2Pos5 = 0;
															}
															roundPlayed = 1;
															deck[i].drag = 0;
															deck[i].placed = 1;
															notCardPos[j].cardOnIt = 0;
															deck[i].num = 0;
															deck[i].type = 0;
															deck[i].value = 0;
															deck[i].player1pos = 0;
															deck[i].display1 = 0;
															deck[i].display2 = 0;
															card5Dragging = 0;
															player1Pos5 = 0;
															showNotA = 0;
															player1Cards--;
															player2Cards--;
															pressed = true;
															break;
														}
													}
													else if (shouldPlayNot >= 7)
													{
														if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
														{
															baseCards[j].value = !(baseCards[j].value);
															baseCards2[j].value = !(baseCards2[j].value);
															baseCards[j].BaseCardImg.setTexture(baseCards2[j].BaseCardImgTexture);
															baseCards2[j].BaseCardImg.setTexture(baseCards[j].BaseCardImgTexture);
															roundPlayed = 1;
															deck[i].drag = 0;
															deck[i].placed = 1;
															notCardPos[j].cardOnIt = 1;
															deck[i].num = 0;
															deck[i].type = 0;
															deck[i].value = 0;
															deck[i].player1pos = 0;
															deck[i].display1 = 0;
															deck[i].display2 = 0;
															card5Dragging = 0;
															player1Pos5 = 0;
															showNotA = 0;
															player1Cards--;
															pressed = true;
															notCardLogic(j);
															break;
														}
													}
												}
												else
												{
													baseCards[j].value = !(baseCards[j].value);
													baseCards2[j].value = !(baseCards2[j].value);
													baseCards[j].BaseCardImg.setTexture(baseCards2[j].BaseCardImgTexture);
													baseCards2[j].BaseCardImg.setTexture(baseCards[j].BaseCardImgTexture);
													roundPlayed = 1;

													deck[i].drag = 0;
													deck[i].placed = 1;
													notCardPos[j].cardOnIt = 1;
													deck[i].num = 0;
													deck[i].type = 0;
													deck[i].value = 0;
													deck[i].player1pos = 0;
													deck[i].display1 = 0;
													deck[i].display2 = 0;
													card5Dragging = 0;
													player1Pos5 = 0;
													showNotA = 0;
													player1Cards--;
													pressed = true;
													notCardLogic(j);
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
						}
						else
						{
							showNotA = 0;
							deck[i].img.setRotation(90.f);
						}
					}
					else
					{
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
													deck[counterNotCards3].type = deck[i].type;
													deck[counterNotCards3].value = deck[i].value;
													deck[counterNotCards3].num = counterNotCards3;
													deck[i].type = 0;
													deck[i].value = 0;
													deck[i].player1pos = 0;
													deck[i].display1 = 0;
													deck[i].display2 = 0;
													counterNotCards3++;
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
														deck[counterNotCards3].type = deck[i].type;
														deck[counterNotCards3].value = deck[i].value;
														deck[counterNotCards3].num = counterNotCards3;
														deck[i].type = 0;
														deck[i].value = 0;
														deck[i].player1pos = 0;
														deck[i].display1 = 0;
														deck[i].display2 = 0;
														counterNotCards3++;
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
					}
					if (getMousePos(200, 0, 10, *this->window))
					{
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
				}
				// Displaying by type
			}
			if (deck[i].value == 0 && !(deck[i].num == fPositions[i].cardNum))
			{
				switch (specialButtonC)
				{
				case 0:
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
					break;
				case 1:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				case 2:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				case 3:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				case 4:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				case 5:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				}
			}
			else if (deck[i].value == 0 && (deck[i].num == fPositions[i].cardNum))
			{
				switch (specialButtonC)
				{
				case 0:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 1:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 2:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 3:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 4:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 5:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				}
			}
			else if (deck[i].value == 1 && !(deck[i].num == fPositions[i].cardNum))
			{

				switch (specialButtonC)
				{
				case 0:
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
					break;
				case 1:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				case 2:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				case 3:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				case 4:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				case 5:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				}
			}
			else if (deck[i].value == 1 && (deck[i].num == fPositions[i].cardNum))
			{

				switch (specialButtonC)
				{
				case 0:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 1:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 2:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 3:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 4:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 5:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				}
			}
			else if (deck[i].type == 'n' && !(deck[i].num == fPositions[i].cardNum))
			{
				switch (specialButtonC)
				{
				case 0:
					deck[i].imgTexture.loadFromFile("assets/NotCard.png");
					this->deck[i].imgTexture.setSmooth(true);
					deck[i].img.setTexture(deck[i].imgTexture);
					this->window->draw(deck[i].img);
					break;
				case 1:
					deck[i].imgTexture.loadFromFile("assets/NavyBundle/NotCard.png");
					this->deck[i].imgTexture.setSmooth(true);
					deck[i].img.setTexture(deck[i].imgTexture);
					this->window->draw(deck[i].img);
					break;
				case 2:
					deck[i].imgTexture.loadFromFile("assets/SunsetBundle/NotCard.png");
					this->deck[i].imgTexture.setSmooth(true);
					deck[i].img.setTexture(deck[i].imgTexture);
					this->window->draw(deck[i].img);
					break;
				case 3:
					deck[i].imgTexture.loadFromFile("assets/SeaBundle/NotCard.png");
					this->deck[i].imgTexture.setSmooth(true);
					deck[i].img.setTexture(deck[i].imgTexture);
					this->window->draw(deck[i].img);
					break;
				case 4:
					deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/NotCard.png");
					this->deck[i].imgTexture.setSmooth(true);
					deck[i].img.setTexture(deck[i].imgTexture);
					this->window->draw(deck[i].img);
					break;
				case 5:
					deck[i].imgTexture.loadFromFile("assets/CosmosBundle/NotCard.png");
					this->deck[i].imgTexture.setSmooth(true);
					deck[i].img.setTexture(deck[i].imgTexture);
					this->window->draw(deck[i].img);
					break;
				}
			}
			else if (deck[i].type == 'n' && (deck[i].num == fPositions[i].cardNum))
			{
				switch (specialButtonC)
				{
				case 0:
					deck[i].imgTexture.loadFromFile("assets/NotCard.png");
					this->deck[i].imgTexture.setSmooth(true);
					deck[i].img.setTexture(deck[i].imgTexture);
					break;
				case 1:
					deck[i].imgTexture.loadFromFile("assets/NavyBundle/NotCard.png");
					this->deck[i].imgTexture.setSmooth(true);
					deck[i].img.setTexture(deck[i].imgTexture);
					break;
				case 2:
					deck[i].imgTexture.loadFromFile("assets/SunsetBundle/NotCard.png");
					this->deck[i].imgTexture.setSmooth(true);
					deck[i].img.setTexture(deck[i].imgTexture);
					break;
				case 3:
					deck[i].imgTexture.loadFromFile("assets/SeaBundle/NotCard.png");
					this->deck[i].imgTexture.setSmooth(true);
					deck[i].img.setTexture(deck[i].imgTexture);
					break;
				case 4:
					deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/NotCard.png");
					this->deck[i].imgTexture.setSmooth(true);
					deck[i].img.setTexture(deck[i].imgTexture);
					break;
				case 5:
					deck[i].imgTexture.loadFromFile("assets/CosmosBundle/NotCard.png");
					this->deck[i].imgTexture.setSmooth(true);
					deck[i].img.setTexture(deck[i].imgTexture);
					break;
				}
			}
		}
		else if (deck[i].display2 == 1 && counter == 2)
		{
			if (deck[i].value == 0 && !(deck[i].num == fPositions[i].cardNum))
			{
				switch (specialButtonC)
				{
				case 0:
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
					break;
				case 1:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				case 2:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				case 3:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				case 4:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				case 5:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				}
			}
			else if (deck[i].value == 0 && (deck[i].num == fPositions[i].cardNum))
			{
				switch (specialButtonC)
				{
				case 0:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 1:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 2:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 3:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 4:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 5:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/AndCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/OrCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/XorCard0.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				}
			}
			else if (deck[i].value == 1 && !(deck[i].num == fPositions[i].cardNum))
			{

				switch (specialButtonC)
				{
				case 0:
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
					break;
				case 1:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				case 2:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				case 3:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				case 4:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				case 5:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
						this->window->draw(deck[i].img);
					}
					break;
				}
			}
			else if (deck[i].value == 1 && (deck[i].num == fPositions[i].cardNum))
			{

				switch (specialButtonC)
				{
				case 0:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 1:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/NavyBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 2:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/SunsetBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 3:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/SeaBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 4:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				case 5:
					if (deck[i].type == 'a')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/AndCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'o')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/OrCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					else if (deck[i].type == 'x')
					{
						deck[i].imgTexture.loadFromFile("assets/CosmosBundle/XorCard1.png");
						this->deck[i].imgTexture.setSmooth(true);
						deck[i].img.setTexture(deck[i].imgTexture);
					}
					break;
				}
			}
			else if (deck[i].type == 'n' && !(deck[i].num == fPositions[i].cardNum))
			{
				switch (specialButtonC)
				{
				case 0:
					deck[i].imgTexture.loadFromFile("assets/NotCard.png");
					this->deck[i].imgTexture.setSmooth(true);
					deck[i].img.setTexture(deck[i].imgTexture);
					this->window->draw(deck[i].img);
					break;
				case 1:
					deck[i].imgTexture.loadFromFile("assets/NavyBundle/NotCard.png");
					this->deck[i].imgTexture.setSmooth(true);
					deck[i].img.setTexture(deck[i].imgTexture);
					this->window->draw(deck[i].img);
					break;
				case 2:
					deck[i].imgTexture.loadFromFile("assets/SunsetBundle/NotCard.png");
					this->deck[i].imgTexture.setSmooth(true);
					deck[i].img.setTexture(deck[i].imgTexture);
					this->window->draw(deck[i].img);
					break;
				case 3:
					deck[i].imgTexture.loadFromFile("assets/SeaBundle/NotCard.png");
					this->deck[i].imgTexture.setSmooth(true);
					deck[i].img.setTexture(deck[i].imgTexture);
					this->window->draw(deck[i].img);
					break;
				case 4:
					deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/NotCard.png");
					this->deck[i].imgTexture.setSmooth(true);
					deck[i].img.setTexture(deck[i].imgTexture);
					this->window->draw(deck[i].img);
					break;
				case 5:
					deck[i].imgTexture.loadFromFile("assets/CosmosBundle/NotCard.png");
					this->deck[i].imgTexture.setSmooth(true);
					deck[i].img.setTexture(deck[i].imgTexture);
					this->window->draw(deck[i].img);
					break;
				}
			}
			else if (deck[i].type == 'n' && (deck[i].num == fPositions[i].cardNum))
			{
				switch (specialButtonC)
				{
				case 0:
					deck[i].imgTexture.loadFromFile("assets/NotCard.png");
					this->deck[i].imgTexture.setSmooth(true);
					deck[i].img.setTexture(deck[i].imgTexture);
					break;
				case 1:
					deck[i].imgTexture.loadFromFile("assets/NavyBundle/NotCard.png");
					this->deck[i].imgTexture.setSmooth(true);
					deck[i].img.setTexture(deck[i].imgTexture);
					break;
				case 2:
					deck[i].imgTexture.loadFromFile("assets/SunsetBundle/NotCard.png");
					this->deck[i].imgTexture.setSmooth(true);
					deck[i].img.setTexture(deck[i].imgTexture);
					break;
				case 3:
					deck[i].imgTexture.loadFromFile("assets/SeaBundle/NotCard.png");
					this->deck[i].imgTexture.setSmooth(true);
					deck[i].img.setTexture(deck[i].imgTexture);
					break;
				case 4:
					deck[i].imgTexture.loadFromFile("assets/DeluxeBundle/NotCard.png");
					this->deck[i].imgTexture.setSmooth(true);
					deck[i].img.setTexture(deck[i].imgTexture);
					break;
				case 5:
					deck[i].imgTexture.loadFromFile("assets/CosmosBundle/NotCard.png");
					this->deck[i].imgTexture.setSmooth(true);
					deck[i].img.setTexture(deck[i].imgTexture);
					break;
				}
			}
		}
	}
}

void Game::setPlacingCards()
{
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

bool Game::checkPlacedCards(int jj)
{
	for (int i = 0; i < counterCards3; i++)
	{
		if (counter == 1)
		{
			if (deck[i].drag)
			{
				switch (jj)
				{
				case 1:
				case 2:
				case 3:
				case 4:
				case 5:
					if (deck[i].type == 'a') {
						if ((baseCards[jj - 1].value & baseCards[jj].value) == deck[i].value)	return 1;
					}
					else if (deck[i].type == 'o') {
						if ((baseCards[jj - 1].value | baseCards[jj].value) == deck[i].value)	return 1;
					}
					else if (deck[i].type == 'x') {
						if ((baseCards[jj - 1].value ^ baseCards[jj].value) == deck[i].value)	return 1;
					}
					break;
				case 6:
				case 7:
				case 8:
				case 9:
					if (deck[i].type == 'a') {
						if ((fPositions[jj - 5].cardValue & fPositions[jj - 4].cardValue) == deck[i].value)	return 1;
					}
					else if (deck[i].type == 'o') {
						if ((fPositions[jj - 5].cardValue | fPositions[jj - 4].cardValue) == deck[i].value)	return 1;
					}
					else if (deck[i].type == 'x') {
						if ((fPositions[jj - 5].cardValue ^ fPositions[jj - 4].cardValue) == deck[i].value)	return 1;
					}
					break;
				case 10:
				case 11:
				case 12:
					if (deck[i].type == 'a') {
						if ((fPositions[jj - 4].cardValue & fPositions[jj - 3].cardValue) == deck[i].value)	return 1;
					}
					else if (deck[i].type == 'o') {
						if ((fPositions[jj - 4].cardValue | fPositions[jj - 3].cardValue) == deck[i].value)	return 1;
					}
					else if (deck[i].type == 'x') {
						if ((fPositions[jj - 4].cardValue ^ fPositions[jj - 3].cardValue) == deck[i].value)	return 1;
					}
					break;
				case 13:
				case 14:
					if (deck[i].type == 'a') {
						if ((fPositions[jj - 3].cardValue & fPositions[jj - 2].cardValue) == deck[i].value)	return 1;
					}
					else if (deck[i].type == 'o') {
						if ((fPositions[jj - 3].cardValue | fPositions[jj - 2].cardValue) == deck[i].value)	return 1;
					}
					else if (deck[i].type == 'x') {
						if ((fPositions[jj - 3].cardValue ^ fPositions[jj - 2].cardValue) == deck[i].value)	return 1;
					}
					break;
				case 15:
					if (deck[i].type == 'a') {
						if ((fPositions[jj - 2].cardValue & fPositions[jj - 1].cardValue) == deck[i].value) {
							win = 2;
							return 1;
						}
					}
					else if (deck[i].type == 'o') {
						if ((fPositions[jj - 2].cardValue | fPositions[jj - 1].cardValue) == deck[i].value) {
							win = 2;
							return 1;
						}
					}
					else if (deck[i].type == 'x') {
						if ((fPositions[jj - 2].cardValue ^ fPositions[jj - 1].cardValue) == deck[i].value) {
							win = 2;
							return 1;
						}
					}
					break;
				}
				return 0;
			}
		}
		else if (counter == 2)
		{
			if (deck[i].drag)
			{
				switch (jj)
				{
				case 1:
				case 2:
				case 3:
				case 4:
				case 5:
					if (deck[i].type == 'a') {
						if ((baseCards2[jj - 1].value & baseCards2[jj].value) == deck[i].value)	return 1;
					}
					else if (deck[i].type == 'o') {
						if ((baseCards2[jj - 1].value | baseCards2[jj].value) == deck[i].value)	return 1;
					}
					else if (deck[i].type == 'x') {
						if ((baseCards2[jj - 1].value ^ baseCards2[jj].value) == deck[i].value)	return 1;
					}
					break;
				case 6:
				case 7:
				case 8:
				case 9:
					if (deck[i].type == 'a'){
						if ((fPositions2[jj - 5].cardValue & fPositions2[jj - 4].cardValue) == deck[i].value)	return 1;
					}
					else if (deck[i].type == 'o'){
						if ((fPositions2[jj - 5].cardValue | fPositions2[jj - 4].cardValue) == deck[i].value)	return 1;
					}
					else if (deck[i].type == 'x'){
						if ((fPositions2[jj - 5].cardValue ^ fPositions2[jj - 4].cardValue) == deck[i].value)	return 1;
					}
					break;
				case 10:
				case 11:
				case 12:
					if (deck[i].type == 'a'){
						if ((fPositions2[jj - 4].cardValue & fPositions2[jj - 3].cardValue) == deck[i].value)	return 1;
					}
					else if (deck[i].type == 'o'){
						if ((fPositions2[jj - 4].cardValue | fPositions2[jj - 3].cardValue) == deck[i].value)	return 1;
					}
					else if (deck[i].type == 'x'){
						if ((fPositions2[jj - 4].cardValue ^ fPositions2[jj - 3].cardValue) == deck[i].value)	return 1;
					}
					break;
				case 13:
				case 14:
					if (deck[i].type == 'a'){
						if ((fPositions2[jj - 3].cardValue & fPositions2[jj - 2].cardValue) == deck[i].value)	return 1;
					}
					else if (deck[i].type == 'o'){
						if ((fPositions2[jj - 3].cardValue | fPositions2[jj - 2].cardValue) == deck[i].value)	return 1;
					}
					else if (deck[i].type == 'x'){
						if ((fPositions2[jj - 3].cardValue ^ fPositions2[jj - 2].cardValue) == deck[i].value)	return 1;
					}
					break;
				case 15:
					if (deck[i].type == 'a'){
						if ((fPositions2[jj - 2].cardValue & fPositions2[jj - 1].cardValue) == deck[i].value){
							win = 2;
							return 1;
						}
					}
					else if (deck[i].type == 'o'){
						if ((fPositions2[jj - 2].cardValue | fPositions2[jj - 1].cardValue) == deck[i].value){
							win = 2;
							return 1;
						}
					}
					else if (deck[i].type == 'x'){
						if ((fPositions2[jj - 2].cardValue ^ fPositions2[jj - 1].cardValue) == deck[i].value){
							win = 2;
							return 1;
						}
					}
					break;
				}
				return 0;
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

void Game::placingNotCardsPos()
{

		for (int i = 0; i < 6; i++)
		{
			if (notCardPos[i].cardOnIt != 1)
			{
				this->window->draw(notCardPos[i].img);
			}
		}
	
}

void Game::tableOfTruth()
{
	if (tableNum == 0)
	{
		if (!(getMousePos(1394, 188, 3, *this->window)))
		{
			tableHeaderTexture.loadFromFile("assets/AndtableHover.png");
			this->window->draw(this->tableHeader);
		}
		else
		{
			tableHoverTexture.loadFromFile("assets/AndtableHeader.png");
			this->window->draw(this->tableHover);
		}
		truthTableTexture.loadFromFile("assets/AndTable.png");
		this->truthTableTexture.setSmooth(true);
		truthTable.setTexture(truthTableTexture);
		truthTable.setPosition(1390, 240);
		this->window->draw(this->truthTable);
		//counter++;
	}
	else if (tableNum == 1)
	{
		if (!(getMousePos(1394, 188, 3, *this->window)))
		{
			tableHeaderTexture.loadFromFile("assets/OrtableHover.png");
			this->window->draw(this->tableHeader);
		}
		else
		{
			tableHoverTexture.loadFromFile("assets/OrtableHeader.png");
			this->window->draw(this->tableHover);
		}
		truthTableTexture.loadFromFile("assets/OrTable.png");
		this->truthTableTexture.setSmooth(true);
		truthTable.setTexture(truthTableTexture);
		truthTable.setPosition(1390, 240);
		this->window->draw(this->truthTable);
	}
	else if (tableNum == 2)
	{
		if (!(getMousePos(1394, 188, 3, *this->window)))
		{
			tableHeaderTexture.loadFromFile("assets/XortableHover.png");
			this->window->draw(this->tableHeader);
		}
		else
		{
			tableHoverTexture.loadFromFile("assets/XortableHeader.png");
			this->window->draw(this->tableHover);
		}
		truthTableTexture.loadFromFile("assets/XorTable.png");
		this->truthTableTexture.setSmooth(true);
		truthTable.setTexture(truthTableTexture);
		truthTable.setPosition(1390, 240);
		this->window->draw(this->truthTable);
	}
}

void Game::firstGamemode(sf::Window& newWindow)
{
	sf::Vector2i cursorpos = sf::Mouse::getPosition(*this->window);
	setTimer();
	if (win != 0)
	{
		winGamemode1++;
		deckI = 1;
		cardGet = 1;
		counter = 0;
		counterCards = 1;
		counterCards2 = 49;
		counterCards3 = 48;
		player1Cards = 0;
		player2Cards = 0;
		showA = 0;
		showA2 = 0;
		roundPlayed = 0;
		card1Dragging = 0;
		card2Dragging = 0;
		card3Dragging = 0;
		card4Dragging = 0;
		card5Dragging = 0;
		card1Dragging2 = 0;
		card2Dragging2 = 0;
		card3Dragging2 = 0;
		card4Dragging2 = 0;
		card5Dragging2 = 0;
		player1Pos1 = 0;
		player1Pos2 = 0;
		player1Pos3 = 0;
		player1Pos4 = 0;
		player1Pos5 = 0;
		player2Pos1 = 0;
		player2Pos2 = 0;
		player2Pos3 = 0;
		player2Pos4 = 0;
		player2Pos5 = 0;
		for (int i = 0; i < 100; i++)
		{
			startDeck[i].num = 0;
			startDeck[i].value = 0;
			startDeck[i].type = 0;
			startDeck[i].display1 = 0;
			startDeck[i].display2 = 0;
			startDeck[i].player = 0;
			startDeck[i].secondNum = 0;
			startDeck[i].player1pos = 0;
			startDeck[i].player2pos = 0;
			startDeck[i].x = 0;
			startDeck[i].y = 0;
			startDeck[i].drag = 0;
			startDeck[i].placed = 0;
		}
		for (int i = 0; i < 150; i++)
		{
			deck[i].num = 0;
			deck[i].value = 0;
			deck[i].type = 0;
			deck[i].display1 = 0;
			deck[i].display2 = 0;
			deck[i].player = 0;
			deck[i].secondNum = 0;
			deck[i].player1pos = 0;
			deck[i].player2pos = 0;
			deck[i].x = 0;
			deck[i].y = 0;
			deck[i].drag = 0;
			deck[i].placed = 0;
		}
		for (int i = 0; i < 16; i++)
		{
			fPositions[i].cardNum = 0;
			fPositions[i].cardValue = 0;
			fPositions[i].showPos = 0;
			fPositions[i].cardOnIt = 0;
			fPositions[i].pos = 0;
			fPositions[i].x = 0;
			fPositions[i].y = 0;
			fPositions2[i].cardNum = 0;
			fPositions2[i].cardValue = 0;
			fPositions2[i].showPos = 0;
			fPositions2[i].cardOnIt = 0;
			fPositions2[i].pos = 0;
			fPositions2[i].x = 0;
			fPositions2[i].y = 0;
		}
		ready = 0;
		firstGamemode1 = 1;
		gameMode = 0;
	}
	if (counter == 0)
	{
		counter++;
	}
	else if (counter == 1) // Player1 round
	{
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
		for (int i = 1; i < 16; i++)
		{
			if (fPositions[i].cardOnIt == 1)
			{
				deck[fPositions[i].cardNum].img.setPosition(fPositions[i].x + 120, fPositions[i].y + 195);
				this->window->draw(deck[fPositions[i].cardNum].img);
			}
		}
		for (int i = 1; i < counterCards2; i++)
		{
			if (deck[i].drag == 1)
			{
				this->window->draw(deck[i].img);
			}
		}
		if (getMousePos(1381, 82, 11, *this->window))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				this->window->clear();
				this->window->draw(pyramid1Img);
				this->window->draw(timer);
				this->window->draw(baseCards2[0].BaseCardImg);
				this->window->draw(baseCards2[1].BaseCardImg);
				this->window->draw(baseCards2[2].BaseCardImg);
				this->window->draw(baseCards2[3].BaseCardImg);
				this->window->draw(baseCards2[4].BaseCardImg);
				this->window->draw(baseCards2[5].BaseCardImg);
				for (int i = 1; i < 16; i++)
				{
					if (fPositions2[i].cardOnIt == 1)
					{
						this->window->draw(deck[fPositions2[i].cardNum].img);
					}
				}
			}
		}
		this->window->display();
		update(*this->window);
		if (win == 0)
		{
			if (roundPlayed)
			{
				transitionImg.setPosition(-2200, 0);
				sf::Time elapsed1 = clock.getElapsedTime();
				int timeCheck = int(elapsed1.asSeconds());
				int now = int(elapsed1.asSeconds());
				int x = -2200;

				while (now - timeCheck <= 1)
				{
					sf::Time elapsed1 = clock.getElapsedTime();
					now = int(elapsed1.asSeconds());
					setTimer();
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
					for (int i = 1; i < 16; i++)
					{
						if (fPositions[i].cardOnIt == 1)
						{
							this->window->draw(deck[fPositions[i].cardNum].img);
						}
					}
					this->window->display();
				}
				while (true) // Transitions
				{
					this->window->clear();
					setTimer();
					if (x <= -315)
					{
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
						for (int i = 1; i < 16; i++)
						{
							if (fPositions[i].cardOnIt == 1)
							{
								this->window->draw(deck[fPositions[i].cardNum].img);
							}
						}
					}
					else
					{
						for (cardGet; player2Cards <= 5; player2Cards++, cardGet++)
						{
							deck[cardGet].player = 2;
						}
						cardsInHand();
						roundPlayed = 0;
						counter = 2;
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
						for (int i = 1; i < 16; i++)
						{
							if (fPositions2[i].cardOnIt == 1)
							{
								this->window->draw(deck[fPositions2[i].cardNum].img);
							}
						}
					}
					if (x >= 1545)
					{
						break;
					}
					this->window->draw(transitionImg);
					transitionImg.setPosition(x, 0);
					x += 45;
					this->window->display();
				}
			}
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
		for (int i = 1; i < 16; i++)
		{
			if (fPositions2[i].cardOnIt == 1)
			{
				deck[fPositions2[i].cardNum].img.setPosition(fPositions2[i].x + 120, fPositions2[i].y + 195);
				this->window->draw(deck[fPositions2[i].cardNum].img);
			}
		}
		for (int i = 1; i < counterCards2; i++)
		{
			if (deck[i].drag == 1)
			{
				this->window->draw(deck[i].img);
			}
		}
		if (getMousePos(1381, 82, 11, *this->window))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				this->window->clear();
				this->window->draw(pyramid2Img);
				this->window->draw(timer);
				this->window->draw(baseCards[0].BaseCardImg);
				this->window->draw(baseCards[1].BaseCardImg);
				this->window->draw(baseCards[2].BaseCardImg);
				this->window->draw(baseCards[3].BaseCardImg);
				this->window->draw(baseCards[4].BaseCardImg);
				this->window->draw(baseCards[5].BaseCardImg);
				for (int i = 1; i < 16; i++)
				{
					if (fPositions[i].cardOnIt == 1)
					{
						this->window->draw(deck[fPositions[i].cardNum].img);
					}
				}
			}
		}

		this->window->display();
		update(*this->window);
		if (win == 0)
		{
			if (roundPlayed)
			{
				transitionImg.setPosition(-2200, 0);
				sf::Time elapsed1 = clock.getElapsedTime();
				int timeCheck = int(elapsed1.asSeconds());
				int now = int(elapsed1.asSeconds());
				int x = -2200;

				while (now - timeCheck <= 1)
				{
					sf::Time elapsed1 = clock.getElapsedTime();
					now = int(elapsed1.asSeconds());
					setTimer();
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
					for (int i = 1; i < 16; i++)
					{
						if (fPositions2[i].cardOnIt == 1)
						{
							this->window->draw(deck[fPositions2[i].cardNum].img);
						}
					}
					this->window->display();
				}
				while (true) // Transitions
				{
					this->window->clear();
					setTimer();
					if (x <= -315)
					{
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
						for (int i = 1; i < 16; i++)
						{
							if (fPositions2[i].cardOnIt == 1)
							{
								this->window->draw(deck[fPositions2[i].cardNum].img);
							}
						}
					}
					else
					{
						for (cardGet; player1Cards <= 5; player1Cards++, cardGet++)
						{
							deck[cardGet].player = 1;
						}
						cardsInHand();
						roundPlayed = 0;
						counter = 1;
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
						for (int i = 1; i < 16; i++)
						{
							if (fPositions[i].cardOnIt == 1)
							{
								this->window->draw(deck[fPositions[i].cardNum].img);
							}
						}
					}
					if (x >= 1545)
					{
						break;
					}
					this->window->draw(transitionImg);
					transitionImg.setPosition(x, 0);
					x += 45;
					this->window->display();
				}
			}
		}
	}
	else
	{
		counter = 1;
	}
}

void Game::secondGamemode(sf::Window& newWindow)
{
	sf::Vector2i cursorpos = sf::Mouse::getPosition(*this->window);
	setTimer();
	if (win != 0)
	{
		if (win == 1)
		{
			winGamemode2++;
		}
		deckI = 1;
		cardGet = 1;
		counter = 0;
		counterCards = 1;
		counterCards2 = 49;
		counterCards3 = 48;
		player1Cards = 0;
		player2Cards = 0;
		showA = 0;
		showA2 = 0;
		roundPlayed = 0;
		card1Dragging = 0;
		card2Dragging = 0;
		card3Dragging = 0;
		card4Dragging = 0;
		card5Dragging = 0;
		card1Dragging2 = 0;
		card2Dragging2 = 0;
		card3Dragging2 = 0;
		card4Dragging2 = 0;
		card5Dragging2 = 0;
		player1Pos1 = 0;
		player1Pos2 = 0;
		player1Pos3 = 0;
		player1Pos4 = 0;
		player1Pos5 = 0;
		player2Pos1 = 0;
		player2Pos2 = 0;
		player2Pos3 = 0;
		player2Pos4 = 0;
		player2Pos5 = 0;
		for (int i = 0; i < 100; i++)
		{
			startDeck[i].num = 0;
			startDeck[i].value = 0;
			startDeck[i].type = 0;
			startDeck[i].display1 = 0;
			startDeck[i].display2 = 0;
			startDeck[i].player = 0;
			startDeck[i].secondNum = 0;
			startDeck[i].player1pos = 0;
			startDeck[i].player2pos = 0;
			startDeck[i].x = 0;
			startDeck[i].y = 0;
			startDeck[i].drag = 0;
			startDeck[i].placed = 0;
		}
		for (int i = 0; i < 150; i++)
		{
			deck[i].num = 0;
			deck[i].value = 0;
			deck[i].type = 0;
			deck[i].display1 = 0;
			deck[i].display2 = 0;
			deck[i].player = 0;
			deck[i].secondNum = 0;
			deck[i].player1pos = 0;
			deck[i].player2pos = 0;
			deck[i].x = 0;
			deck[i].y = 0;
			deck[i].drag = 0;
			deck[i].placed = 0;
		}
		for (int i = 0; i < 16; i++)
		{
			fPositions[i].cardNum = 0;
			fPositions[i].cardValue = 0;
			fPositions[i].showPos = 0;
			fPositions[i].cardOnIt = 0;
			fPositions[i].pos = 0;
			fPositions[i].x = 0;
			fPositions[i].y = 0;
			fPositions2[i].cardNum = 0;
			fPositions2[i].cardValue = 0;
			fPositions2[i].showPos = 0;
			fPositions2[i].cardOnIt = 0;
			fPositions2[i].pos = 0;
			fPositions2[i].x = 0;
			fPositions2[i].y = 0;
		}
		ready = 0;
		firstGamemode2 = 1;
		gameMode = 0;
	}
	if (counter == 0)
	{
		counter++;
	}
	else if (counter == 1) // Player1 round
	{
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
		for (int i = 1; i < 16; i++)
		{
			if (fPositions[i].cardOnIt == 1)
			{
				deck[fPositions[i].cardNum].img.setPosition(fPositions[i].x + 120, fPositions[i].y + 195);
				this->window->draw(deck[fPositions[i].cardNum].img);
			}
		}
		for (int i = 1; i < counterCards2; i++)
		{
			if (deck[i].drag == 1)
			{
				this->window->draw(deck[i].img);
			}
		}
		if (getMousePos(1381, 82, 11, *this->window))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				this->window->clear();
				this->window->draw(pyramid1Img);
				this->window->draw(timer);
				this->window->draw(baseCards2[0].BaseCardImg);
				this->window->draw(baseCards2[1].BaseCardImg);
				this->window->draw(baseCards2[2].BaseCardImg);
				this->window->draw(baseCards2[3].BaseCardImg);
				this->window->draw(baseCards2[4].BaseCardImg);
				this->window->draw(baseCards2[5].BaseCardImg);
				for (int i = 1; i < 16; i++)
				{
					if (fPositions2[i].cardOnIt == 1)
					{
						this->window->draw(deck[fPositions2[i].cardNum].img);
					}
				}
			}
		}
		this->window->display();
		update(*this->window);
		if (win == 0)
		{
			if (roundPlayed)
			{
				transitionImg.setPosition(-2200, 0);
				sf::Time elapsed1 = clock.getElapsedTime();
				int timeCheck = int(elapsed1.asSeconds());
				int now = int(elapsed1.asSeconds());
				int x = -2200;

				while (now - timeCheck <= 1)
				{
					sf::Time elapsed1 = clock.getElapsedTime();
					now = int(elapsed1.asSeconds());
					setTimer();
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
					for (int i = 1; i < 16; i++)
					{
						if (fPositions[i].cardOnIt == 1)
						{
							this->window->draw(deck[fPositions[i].cardNum].img);
						}
					}
					this->window->display();
				}
				while (true) // Transitions
				{
					this->window->clear();
					setTimer();
					if (x <= -315)
					{
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
						for (int i = 1; i < 16; i++)
						{
							if (fPositions[i].cardOnIt == 1)
							{
								this->window->draw(deck[fPositions[i].cardNum].img);
							}
						}
					}
					else
					{
						for (cardGet; player2Cards <= 5; player2Cards++, cardGet++)
						{
							deck[cardGet].player = 2;
						}
						cardsInHand();
						roundPlayed = 0;
						counter = 2;
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
						for (int i = 1; i < 16; i++)
						{
							if (fPositions2[i].cardOnIt == 1)
							{
								this->window->draw(deck[fPositions2[i].cardNum].img);
							}
						}
					}
					if (x >= 1545)
					{
						break;
					}
					this->window->draw(transitionImg);
					transitionImg.setPosition(x, 0);
					x += 45;
					this->window->display();
				}
			}
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
		placingCardsPos();
		sf::Time elapsed1 = clock.getElapsedTime();
		int timeCheck = int(elapsed1.asSeconds());
		int now = int(elapsed1.asSeconds());

		while (double(now) - double(timeCheck) <= 0.5)
		{
			sf::Time elapsed1 = clock.getElapsedTime();
			now = int(elapsed1.asSeconds());
			setTimer();
			this->window->clear();
			cardsInHand();
			this->window->draw(this->backgroundSprite);
			this->window->draw(timer);
			this->window->draw(this->player2Text);
			this->window->draw(baseCards2[0].BaseCardImg);
			this->window->draw(baseCards2[1].BaseCardImg);
			this->window->draw(baseCards2[2].BaseCardImg);
			this->window->draw(baseCards2[3].BaseCardImg);
			this->window->draw(baseCards2[4].BaseCardImg);
			this->window->draw(baseCards2[5].BaseCardImg);
			setCardImages2(cursorpos);
			for (int i = 1; i < 16; i++)
			{
				if (fPositions2[i].cardOnIt == 1)
				{
					this->window->draw(deck[fPositions2[i].cardNum].img);
				}
			}
			tableOfTruth();
			placingCardsPos();
			this->window->display();
		}
		srand((unsigned)time(0));
		bool succesful = 0;
		int randomNum = rand() % 10 + 1;
		if (randomNum != 7 && randomNum != 2)
		{
			for (int i = 1; i < 6; i++)
			{
				switch (i)
				{
				case 1:
					succesful = 0;
					deck[player2Pos1].drag = 1;
					deck[player2Pos1].img.setRotation(180.f);
					for (int j = 0; j < 16; j++)
					{
						if (fPositions2[j].showPos == 1)
						{
							if (checkPlacedCards(j))
							{
								succesful = 1;
								deck[player2Pos1].drag = 0;
								deck[player2Pos1].img.setRotation(180.f);
								deck[player2Pos1].placed = 1;
								fPositions2[j].cardOnIt = 1;
								fPositions2[j].cardNum = deck[player2Pos1].num;
								fPositions2[j].cardValue = deck[player2Pos1].value;
								deck[player2Pos1].num = 0;
								deck[player2Pos1].x = fPositions2[j].x;
								deck[player2Pos1].y = fPositions2[j].y;
								deck[player2Pos1].img.setPosition(fPositions2[j].x, fPositions2[j].y);
								player2Pos1 = 0;
								player2Cards--;
								roundPlayed = 1;
								break;
							}
						}
					}
					if (!(succesful))
					{
						deck[player2Pos1].drag = 0;
						deck[player2Pos1].img.setRotation(90.f);
					}
					break;
				case 2:
					succesful = 0;
					deck[player2Pos2].drag = 1;
					deck[player2Pos2].img.setRotation(180.f);
					for (int j = 0; j < 16; j++)
					{
						if (fPositions2[j].showPos == 1)
						{
							if (checkPlacedCards(j))
							{
								succesful = 1;
								deck[player2Pos2].drag = 0;
								deck[player2Pos2].img.setRotation(180.f);
								deck[player2Pos2].placed = 1;
								fPositions2[j].cardOnIt = 1;
								fPositions2[j].cardNum = deck[player2Pos2].num;
								fPositions2[j].cardValue = deck[player2Pos2].value;
								deck[player2Pos2].num = 0;
								deck[player2Pos2].x = fPositions2[j].x;
								deck[player2Pos2].y = fPositions2[j].y;
								deck[player2Pos2].img.setPosition(fPositions2[j].x, fPositions2[j].y);
								player2Pos2 = 0;
								player2Cards--;
								roundPlayed = 1;
								break;
							}
						}
					}
					if (!(succesful))
					{
						deck[player2Pos2].drag = 0;
						deck[player2Pos2].img.setRotation(90.f);
					}
					break;
				case 3:
					succesful = 0;
					deck[player2Pos3].drag = 1;
					deck[player2Pos3].img.setRotation(180.f);
					for (int j = 0; j < 16; j++)
					{
						if (fPositions2[j].showPos == 1)
						{
							if (checkPlacedCards(j))
							{
								succesful = 1;
								deck[player2Pos3].drag = 0;
								deck[player2Pos3].img.setRotation(180.f);
								deck[player2Pos3].placed = 1;
								fPositions2[j].cardOnIt = 1;
								fPositions2[j].cardNum = deck[player2Pos3].num;
								fPositions2[j].cardValue = deck[player2Pos3].value;
								deck[player2Pos3].num = 0;
								deck[player2Pos3].x = fPositions2[j].x;
								deck[player2Pos3].y = fPositions2[j].y;
								deck[player2Pos3].img.setPosition(fPositions2[j].x, fPositions2[j].y);
								player2Pos3 = 0;
								player2Cards--;
								roundPlayed = 1;
								break;
							}
						}
					}
					if (!(succesful))
					{
						deck[player2Pos3].drag = 0;
						deck[player2Pos3].img.setRotation(90.f);
					}
					break;
				case 4:
					succesful = 0;
					deck[player2Pos4].drag = 1;
					deck[player2Pos4].img.setRotation(180.f);
					for (int j = 0; j < 16; j++)
					{
						if (fPositions2[j].showPos == 1)
						{
							if (checkPlacedCards(j))
							{
								succesful = 1;
								deck[player2Pos4].drag = 0;
								deck[player2Pos4].img.setRotation(180.f);
								deck[player2Pos4].placed = 1;
								fPositions2[j].cardOnIt = 1;
								fPositions2[j].cardNum = deck[player2Pos4].num;
								fPositions2[j].cardValue = deck[player2Pos4].value;
								deck[player2Pos4].num = 0;
								deck[player2Pos4].x = fPositions2[j].x;
								deck[player2Pos4].y = fPositions2[j].y;
								deck[player2Pos4].img.setPosition(fPositions2[j].x, fPositions2[j].y);
								player2Pos4 = 0;
								player2Cards--;
								roundPlayed = 1;
								break;
							}
						}
					}
					if (!(succesful))
					{
						deck[player2Pos4].drag = 0;
						deck[player2Pos4].img.setRotation(90.f);
					}
					break;
				case 5:
					succesful = 0;
					deck[player2Pos5].drag = 1;
					deck[player2Pos5].img.setRotation(180.f);
					for (int j = 0; j < 16; j++)
					{
						if (fPositions2[j].showPos == 1)
						{
							if (checkPlacedCards(j))
							{
								succesful = 1;
								deck[player2Pos5].drag = 0;
								deck[player2Pos5].img.setRotation(180.f);
								deck[player2Pos5].placed = 1;
								fPositions2[j].cardOnIt = 1;
								fPositions2[j].cardNum = deck[player2Pos5].num;
								fPositions2[j].cardValue = deck[player2Pos5].value;
								deck[player2Pos5].num = 0;
								deck[player2Pos5].x = fPositions2[j].x;
								deck[player2Pos5].y = fPositions2[j].y;
								deck[player2Pos5].img.setPosition(fPositions2[j].x, fPositions2[j].y);
								player2Pos5 = 0;
								player2Cards--;
								roundPlayed = 1;
								break;
							}
						}
					}
					if (!(succesful))
					{
						deck[player2Pos5].drag = 0;
						deck[player2Pos5].img.setRotation(90.f);
					}
					break;
				}
				if (roundPlayed)
				{
					break;
				}
			}
			if (roundPlayed == 0)
			{
				deck[player2Pos1].drag = 0;
				deck[player2Pos1].img.setRotation(90.f);
				deck[player2Pos1].placed = 1;
				deck[player2Pos1].num = 0;
				deck[counterCards3].type = deck[player2Pos1].type;
				deck[counterCards3].value = deck[player2Pos1].value;
				deck[counterCards3].num = counterCards3;
				deck[player2Pos1].type = 0;
				deck[player2Pos1].value = 0;
				deck[player2Pos1].player1pos = 0;
				deck[player2Pos1].display1 = 0;
				deck[player2Pos1].display2 = 0;
				counterCards3++;
				player2Pos1 = 0;
				player2Cards--;
				roundPlayed = 1;
			}
		}
		else
		{
		int randomCard = rand() % 5 + 1;
			switch (randomCard)
			{
			case 1:
				deck[player2Pos1].drag = 0;
				deck[player2Pos1].img.setRotation(90.f);
				deck[player2Pos1].placed = 1;
				deck[player2Pos1].num = 0;
				deck[counterCards3].type = deck[player2Pos1].type;
				deck[counterCards3].value = deck[player2Pos1].value;
				deck[counterCards3].num = counterCards3;
				deck[player2Pos1].type = 0;
				deck[player2Pos1].value = 0;
				deck[player2Pos1].player1pos = 0;
				deck[player2Pos1].display1 = 0;
				deck[player2Pos1].display2 = 0;
				counterCards3++;
				player2Pos1 = 0;
				player2Cards--;
				roundPlayed = 1;
				break;
			case 2:
				deck[player2Pos2].drag = 0;
				deck[player2Pos2].img.setRotation(90.f);
				deck[player2Pos2].placed = 1;
				deck[player2Pos2].num = 0;
				deck[counterCards3].type = deck[player2Pos2].type;
				deck[counterCards3].value = deck[player2Pos2].value;
				deck[counterCards3].num = counterCards3;
				deck[player2Pos2].type = 0;
				deck[player2Pos2].value = 0;
				deck[player2Pos2].player1pos = 0;
				deck[player2Pos2].display1 = 0;
				deck[player2Pos2].display2 = 0;
				counterCards3++;
				player2Pos2 = 0;
				player2Cards--;
				roundPlayed = 1;
				break;
			case 3:
				deck[player2Pos3].drag = 0;
				deck[player2Pos3].img.setRotation(90.f);
				deck[player2Pos3].placed = 1;
				deck[player2Pos3].num = 0;
				deck[counterCards3].type = deck[player2Pos3].type;
				deck[counterCards3].value = deck[player2Pos3].value;
				deck[counterCards3].num = counterCards3;
				deck[player2Pos3].type = 0;
				deck[player2Pos3].value = 0;
				deck[player2Pos3].player1pos = 0;
				deck[player2Pos3].display1 = 0;
				deck[player2Pos3].display2 = 0;
				counterCards3++;
				player2Pos3 = 0;
				player2Cards--;
				roundPlayed = 1;
				break;
			case 4:
				deck[player2Pos4].drag = 0;
				deck[player2Pos4].img.setRotation(90.f);
				deck[player2Pos4].placed = 1;
				deck[player2Pos4].num = 0;
				deck[counterCards3].type = deck[player2Pos4].type;
				deck[counterCards3].value = deck[player2Pos4].value;
				deck[counterCards3].num = counterCards3;
				deck[player2Pos4].type = 0;
				deck[player2Pos4].value = 0;
				deck[player2Pos4].player1pos = 0;
				deck[player2Pos4].display1 = 0;
				deck[player2Pos4].display2 = 0;
				counterCards3++;
				player2Pos4 = 0;
				player2Cards--;
				roundPlayed = 1;
				break;
			case 5:
				deck[player2Pos5].drag = 0;
				deck[player2Pos5].img.setRotation(90.f);
				deck[player2Pos5].placed = 1;
				deck[player2Pos5].num = 0;
				deck[counterCards3].type = deck[player2Pos5].type;
				deck[counterCards3].value = deck[player2Pos5].value;
				deck[counterCards3].num = counterCards3;
				deck[player2Pos5].type = 0;
				deck[player2Pos5].value = 0;
				deck[player2Pos5].player1pos = 0;
				deck[player2Pos5].display1 = 0;
				deck[player2Pos5].display2 = 0;
				counterCards3++;
				player2Pos5 = 0;
				player2Cards--;
				roundPlayed = 1;
				break;
			}
		}

		setCardImages2(cursorpos);
			for (int i = 1; i < 16; i++)
			{
				if (fPositions2[i].cardOnIt == 1)
				{
					deck[fPositions2[i].cardNum].img.setPosition(fPositions2[i].x + 120, fPositions2[i].y + 195);
					this->window->draw(deck[fPositions2[i].cardNum].img);
				}
			}
			this->window->display();
			update(*this->window);

			if (win == 0)
			{
				if (roundPlayed)
				{
					transitionImg.setPosition(-2200, 0);
					sf::Time elapsed1 = clock.getElapsedTime();
					int timeCheck = int(elapsed1.asSeconds());
					int now = int(elapsed1.asSeconds());
					int x = -2200;

					while (now - timeCheck <= 2)
					{
						sf::Time elapsed1 = clock.getElapsedTime();
						now = int(elapsed1.asSeconds());
						setTimer();
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
						for (int i = 1; i < 16; i++)
						{
							if (fPositions2[i].cardOnIt == 1)
							{
								this->window->draw(deck[fPositions2[i].cardNum].img);
							}
						}
						this->window->display();
					}
					while (true) // Transitions
					{
						this->window->clear();
						setTimer();
						if (x <= -315)
						{
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
							for (int i = 1; i < 16; i++)
							{
								if (fPositions2[i].cardOnIt == 1)
								{
									this->window->draw(deck[fPositions2[i].cardNum].img);
								}
							}
						}
						else
						{
							for (cardGet; player1Cards <= 5; player1Cards++, cardGet++)
							{
								deck[cardGet].player = 1;
							}
							cardsInHand();
							roundPlayed = 0;
							counter = 1;
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
							for (int i = 1; i < 16; i++)
							{
								if (fPositions[i].cardOnIt == 1)
								{
									this->window->draw(deck[fPositions[i].cardNum].img);
								}
							}
						}
						if (x >= 1545)
						{
							break;
						}
						this->window->draw(transitionImg);
						transitionImg.setPosition(x, 0);
						x += 45;
						this->window->display();
					}
				}
			}
	}
	else
	{
		counter = 1;
	}
}

void Game::thirdGamemode(sf::Window& newWindow)
{
	sf::Vector2i cursorpos = sf::Mouse::getPosition(*this->window);
	setTimer();
	if (win != 0)
	{
		winGamemode3++;
		deckI = 1;
		cardGet = 1;
		counter = 0;
		counterCards = 1;
		counterCards2 = 49;
		counterCards3 = 48;
		player1Cards = 0;
		player2Cards = 0;
		showA = 0;
		showA2 = 0;
		roundPlayed = 0;
		card1Dragging = 0;
		card2Dragging = 0;
		card3Dragging = 0;
		card4Dragging = 0;
		card5Dragging = 0;
		card1Dragging2 = 0;
		card2Dragging2 = 0;
		card3Dragging2 = 0;
		card4Dragging2 = 0;
		card5Dragging2 = 0;
		player1Pos1 = 0;
		player1Pos2 = 0;
		player1Pos3 = 0;
		player1Pos4 = 0;
		player1Pos5 = 0;
		player2Pos1 = 0;
		player2Pos2 = 0;
		player2Pos3 = 0;
		player2Pos4 = 0;
		player2Pos5 = 0;
		for (int i = 0; i < 100; i++)
		{
			startDeck[i].num = 0;
			startDeck[i].value = 0;
			startDeck[i].type = 0;
			startDeck[i].display1 = 0;
			startDeck[i].display2 = 0;
			startDeck[i].player = 0;
			startDeck[i].secondNum = 0;
			startDeck[i].player1pos = 0;
			startDeck[i].player2pos = 0;
			startDeck[i].x = 0;
			startDeck[i].y = 0;
			startDeck[i].drag = 0;
			startDeck[i].placed = 0;
		}
		for (int i = 0; i < 150; i++)
		{
			deck[i].num = 0;
			deck[i].value = 0;
			deck[i].type = 0;
			deck[i].display1 = 0;
			deck[i].display2 = 0;
			deck[i].player = 0;
			deck[i].secondNum = 0;
			deck[i].player1pos = 0;
			deck[i].player2pos = 0;
			deck[i].x = 0;
			deck[i].y = 0;
			deck[i].drag = 0;
			deck[i].placed = 0;
		}
		for (int i = 0; i < 16; i++)
		{
			fPositions[i].cardNum = 0;
			fPositions[i].cardValue = 0;
			fPositions[i].showPos = 0;
			fPositions[i].cardOnIt = 0;
			fPositions[i].pos = 0;
			fPositions[i].x = 0;
			fPositions[i].y = 0;
			fPositions2[i].cardNum = 0;
			fPositions2[i].cardValue = 0;
			fPositions2[i].showPos = 0;
			fPositions2[i].cardOnIt = 0;
			fPositions2[i].pos = 0;
			fPositions2[i].x = 0;
			fPositions2[i].y = 0;
		}
		for (int i = 0; i < 6; i++)
		{
			notCardPos[i].cardNum = 0;
			notCardPos[i].cardValue = 0;
			notCardPos[i].showPos = 0;
			notCardPos[i].cardOnIt = 0;
		}
		ready = 0;
		firstGamemode3 = 1;
		gameMode = 0;
	}
	if (counter == 0)
	{
		counter++;
	}
	else if (counter == 1) // Player1 round
	{
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
		setNotCardImages(cursorpos);
		if (showA)
		{
			placingCardsPos();
		}
		if (showNotA)
		{
			placingNotCardsPos();
		}
		for (int i = 0; i < 6; i++)
		{
			if (notCardPos[i].cardOnIt == 1)
			{
				notCardPos[i].imgTexture.loadFromFile("assets/PlacedNotCard.png");
				notCardPos[i].img.setTexture(notCardPos[i].imgTexture);
				this->window->draw(notCardPos[i].img);
			}
		}
		for (int i = 1; i < 16; i++)
		{
			if (fPositions[i].cardOnIt == 1)
			{
				deck[fPositions[i].cardNum].img.setPosition(fPositions[i].x + 120, fPositions[i].y + 195);
				this->window->draw(deck[fPositions[i].cardNum].img);
			}
		}
		for (int i = 1; i < counterCards2; i++)
		{
			if (deck[i].drag == 1)
			{
				this->window->draw(deck[i].img);
			}
		}
		if (getMousePos(1381, 82, 11, *this->window))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				this->window->clear();
				this->window->draw(pyramid1Img);
				this->window->draw(timer);
				this->window->draw(baseCards2[0].BaseCardImg);
				this->window->draw(baseCards2[1].BaseCardImg);
				this->window->draw(baseCards2[2].BaseCardImg);
				this->window->draw(baseCards2[3].BaseCardImg);
				this->window->draw(baseCards2[4].BaseCardImg);
				this->window->draw(baseCards2[5].BaseCardImg);
				for (int i = 0; i < 6; i++)
				{
					if (notCardPos[i].cardOnIt == 1)
					{
						notCardPos[i].imgTexture.loadFromFile("assets/PlacedNotCard.png");
						notCardPos[i].img.setTexture(notCardPos[i].imgTexture);
						this->window->draw(notCardPos[i].img);
					}
				}
				for (int i = 1; i < 16; i++)
				{
					if (fPositions2[i].cardOnIt == 1)
					{
						this->window->draw(deck[fPositions2[i].cardNum].img);
					}
				}
			}
		}
		this->window->display();
		update(*this->window);


		if (win == 0)
		{
			if (roundPlayed)
			{
				transitionImg.setPosition(-2200, 0);
				sf::Time elapsed1 = clock.getElapsedTime();
				int timeCheck = int(elapsed1.asSeconds());
				int now = int(elapsed1.asSeconds());
				int x = -2200;

				while (now - timeCheck <= 1)
				{
					sf::Time elapsed1 = clock.getElapsedTime();
					now = int(elapsed1.asSeconds());
					setTimer();
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
					for (int i = 0; i < 6; i++)
					{
						if (notCardPos[i].cardOnIt == 1)
						{
							notCardPos[i].imgTexture.loadFromFile("assets/PlacedNotCard.png");
							notCardPos[i].img.setTexture(notCardPos[i].imgTexture);
							this->window->draw(notCardPos[i].img);
						}
					}
					tableOfTruth();
					setNotCardImages(cursorpos);
					for (int i = 1; i < 16; i++)
					{
						if (fPositions[i].cardOnIt == 1)
						{
							this->window->draw(deck[fPositions[i].cardNum].img);
						}
					}
					this->window->display();
				}
				while (true) // Transitions
				{
					this->window->clear();
					setTimer();
					if (x <= -315)
					{
						this->window->draw(this->backgroundSprite);
						this->window->draw(timer);
						this->window->draw(this->player1Text);
						this->window->draw(baseCards[0].BaseCardImg);
						this->window->draw(baseCards[1].BaseCardImg);
						this->window->draw(baseCards[2].BaseCardImg);
						this->window->draw(baseCards[3].BaseCardImg);
						this->window->draw(baseCards[4].BaseCardImg);
						this->window->draw(baseCards[5].BaseCardImg);
						for (int i = 0; i < 6; i++)
						{
							if (notCardPos[i].cardOnIt == 1)
							{
								notCardPos[i].imgTexture.loadFromFile("assets/PlacedNotCard.png");
								notCardPos[i].img.setTexture(notCardPos[i].imgTexture);
								this->window->draw(notCardPos[i].img);
							}
						}
						tableOfTruth();
						setNotCardImages(cursorpos);
						for (int i = 1; i < 16; i++)
						{
							if (fPositions[i].cardOnIt == 1)
							{
								this->window->draw(deck[fPositions[i].cardNum].img);
							}
						}
					}
					else
					{
						for (cardGet; player2Cards <= 5; player2Cards++, cardGet++)
						{
							deck[cardGet].player = 2;
						}
						cardsInHand();
						roundPlayed = 0;
						counter = 2;
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
						for (int i = 0; i < 6; i++)
						{
							if (notCardPos[i].cardOnIt == 1)
							{
								notCardPos[i].imgTexture.loadFromFile("assets/PlacedNotCard.png");
								notCardPos[i].img.setTexture(notCardPos[i].imgTexture);
								this->window->draw(notCardPos[i].img);
							}
						}
						tableOfTruth();
						setNotCardImages(cursorpos);
						for (int i = 1; i < 16; i++)
						{
							if (fPositions2[i].cardOnIt == 1)
							{
								this->window->draw(deck[fPositions2[i].cardNum].img);
							}
						}
					}
					if (x >= 1545)
					{
						break;
					}
					this->window->draw(transitionImg);
					transitionImg.setPosition(x, 0);
					x += 45;
					this->window->display();
				}
			}
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
		setNotCardImages(cursorpos);
		if (showA2 == 1)
		{
			placingCardsPos();
		}
		if (showNotA)
		{
			placingNotCardsPos();
		}
		for (int i = 0; i < 6; i++)
		{
			if (notCardPos[i].cardOnIt == 1)
			{
				notCardPos[i].imgTexture.loadFromFile("assets/PlacedNotCard.png");
				notCardPos[i].img.setTexture(notCardPos[i].imgTexture);
				this->window->draw(notCardPos[i].img);
			}
		}
		for (int i = 1; i < 16; i++)
		{
			if (fPositions2[i].cardOnIt == 1)
			{
				deck[fPositions2[i].cardNum].img.setPosition(fPositions2[i].x + 120, fPositions2[i].y + 195);
				this->window->draw(deck[fPositions2[i].cardNum].img);
			}
		}
		for (int i = 1; i < counterCards2; i++)
		{
			if (deck[i].drag == 1)
			{
				this->window->draw(deck[i].img);
			}
		}
		if (getMousePos(1381, 82, 11, *this->window))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				this->window->clear();
				this->window->draw(pyramid2Img);
				this->window->draw(timer);
				this->window->draw(baseCards[0].BaseCardImg);
				this->window->draw(baseCards[1].BaseCardImg);
				this->window->draw(baseCards[2].BaseCardImg);
				this->window->draw(baseCards[3].BaseCardImg);
				this->window->draw(baseCards[4].BaseCardImg);
				this->window->draw(baseCards[5].BaseCardImg);
				for (int i = 0; i < 6; i++)
				{
					if (notCardPos[i].cardOnIt == 1)
					{
						notCardPos[i].imgTexture.loadFromFile("assets/PlacedNotCard.png");
						notCardPos[i].img.setTexture(notCardPos[i].imgTexture);
						this->window->draw(notCardPos[i].img);
					}
				}
				for (int i = 1; i < 16; i++)
				{
					if (fPositions[i].cardOnIt == 1)
					{
						this->window->draw(deck[fPositions[i].cardNum].img);
					}
				}
			}
		}

		this->window->display();
		update(*this->window);
		if (win == 0)
		{
			if (roundPlayed)
			{
				transitionImg.setPosition(-2200, 0);
				sf::Time elapsed1 = clock.getElapsedTime();
				int timeCheck = int(elapsed1.asSeconds());
				int now = int(elapsed1.asSeconds());
				int x = -2200;

				while (now - timeCheck <= 1)
				{
					sf::Time elapsed1 = clock.getElapsedTime();
					now = int(elapsed1.asSeconds());
					setTimer();
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
					for (int i = 0; i < 6; i++)
					{
						if (notCardPos[i].cardOnIt == 1)
						{
							notCardPos[i].imgTexture.loadFromFile("assets/PlacedNotCard.png");
							notCardPos[i].img.setTexture(notCardPos[i].imgTexture);
							this->window->draw(notCardPos[i].img);
						}
					}
					tableOfTruth();
					setNotCardImages(cursorpos);
					for (int i = 1; i < 16; i++)
					{
						if (fPositions2[i].cardOnIt == 1)
						{
							this->window->draw(deck[fPositions2[i].cardNum].img);
						}
					}
					this->window->display();
				}
				while (true) // Transitions
				{
					this->window->clear();
					setTimer();
					if (x <= -315)
					{
						this->window->draw(this->backgroundSprite);
						this->window->draw(timer);
						this->window->draw(this->player2Text);
						this->window->draw(baseCards2[0].BaseCardImg);
						this->window->draw(baseCards2[1].BaseCardImg);
						this->window->draw(baseCards2[2].BaseCardImg);
						this->window->draw(baseCards2[3].BaseCardImg);
						this->window->draw(baseCards2[4].BaseCardImg);
						this->window->draw(baseCards2[5].BaseCardImg);
						for (int i = 0; i < 6; i++)
						{
							if (notCardPos[i].cardOnIt == 1)
							{
								notCardPos[i].imgTexture.loadFromFile("assets/PlacedNotCard.png");
								notCardPos[i].img.setTexture(notCardPos[i].imgTexture);
								this->window->draw(notCardPos[i].img);
							}
						}
						tableOfTruth();
						setNotCardImages(cursorpos);
						for (int i = 1; i < 16; i++)
						{
							if (fPositions2[i].cardOnIt == 1)
							{
								this->window->draw(deck[fPositions2[i].cardNum].img);
							}
						}
					}
					else
					{
						for (cardGet; player1Cards <= 5; player1Cards++, cardGet++)
						{
							deck[cardGet].player = 1;
						}
						cardsInHand();
						roundPlayed = 0;
						counter = 1;
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
						for (int i = 0; i < 6; i++)
						{
							if (notCardPos[i].cardOnIt == 1)
							{
								notCardPos[i].imgTexture.loadFromFile("assets/PlacedNotCard.png");
								notCardPos[i].img.setTexture(notCardPos[i].imgTexture);
								this->window->draw(notCardPos[i].img);
							}
						}
						tableOfTruth();
						setNotCardImages(cursorpos);
						for (int i = 1; i < 16; i++)
						{
							if (fPositions[i].cardOnIt == 1)
							{
								this->window->draw(deck[fPositions[i].cardNum].img);
							}
						}
					}
					if (x >= 1545)
					{
						break;
					}
					this->window->draw(transitionImg);
					transitionImg.setPosition(x, 0);
					x += 45;
					this->window->display();
				}
			}
		}
	}
	else
	{
		counter = 1;
	}
}

void Game::fourthGamemode(sf::Window& newWindow)
{
	sf::Vector2i cursorpos = sf::Mouse::getPosition(*this->window);
	setTimer();
	if (win != 0)
	{
		if (win == 1)
		{
			winGamemode4++;
		}
		deckI = 1;
		cardGet = 1;
		counter = 0;
		counterCards = 1;
		counterCards2 = 49;
		counterCards3 = 48;
		player1Cards = 0;
		player2Cards = 0;
		showA = 0;
		showA2 = 0;
		roundPlayed = 0;
		card1Dragging = 0;
		card2Dragging = 0;
		card3Dragging = 0;
		card4Dragging = 0;
		card5Dragging = 0;
		card1Dragging2 = 0;
		card2Dragging2 = 0;
		card3Dragging2 = 0;
		card4Dragging2 = 0;
		card5Dragging2 = 0;
		player1Pos1 = 0;
		player1Pos2 = 0;
		player1Pos3 = 0;
		player1Pos4 = 0;
		player1Pos5 = 0;
		player2Pos1 = 0;
		player2Pos2 = 0;
		player2Pos3 = 0;
		player2Pos4 = 0;
		player2Pos5 = 0;
		for (int i = 0; i < 100; i++)
		{
			startDeck[i].num = 0;
			startDeck[i].value = 0;
			startDeck[i].type = 0;
			startDeck[i].display1 = 0;
			startDeck[i].display2 = 0;
			startDeck[i].player = 0;
			startDeck[i].secondNum = 0;
			startDeck[i].player1pos = 0;
			startDeck[i].player2pos = 0;
			startDeck[i].x = 0;
			startDeck[i].y = 0;
			startDeck[i].drag = 0;
			startDeck[i].placed = 0;
		}
		for (int i = 0; i < 150; i++)
		{
			deck[i].num = 0;
			deck[i].value = 0;
			deck[i].type = 0;
			deck[i].display1 = 0;
			deck[i].display2 = 0;
			deck[i].player = 0;
			deck[i].secondNum = 0;
			deck[i].player1pos = 0;
			deck[i].player2pos = 0;
			deck[i].x = 0;
			deck[i].y = 0;
			deck[i].drag = 0;
			deck[i].placed = 0;
		}
		for (int i = 0; i < 16; i++)
		{
			fPositions[i].cardNum = 0;
			fPositions[i].cardValue = 0;
			fPositions[i].showPos = 0;
			fPositions[i].cardOnIt = 0;
			fPositions[i].pos = 0;
			fPositions[i].x = 0;
			fPositions[i].y = 0;
			fPositions2[i].cardNum = 0;
			fPositions2[i].cardValue = 0;
			fPositions2[i].showPos = 0;
			fPositions2[i].cardOnIt = 0;
			fPositions2[i].pos = 0;
			fPositions2[i].x = 0;
			fPositions2[i].y = 0;
		}
		for (int i = 0; i < 6; i++)
		{
			notCardPos[i].cardNum = 0;
			notCardPos[i].cardValue = 0;
			notCardPos[i].showPos = 0;
			notCardPos[i].cardOnIt = 0;
		}
		ready = 0;
		firstGamemode4 = 1;
		gameMode = 0;
	}
	if (counter == 0)
	{
		counter++;
	}
	else if (counter == 1) // Player1 round
	{
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
		setNotCardImages2(cursorpos);
		if (showA)
		{
			placingCardsPos();
		}
		if (showNotA)
		{
			placingNotCardsPos();
		}
		for (int i = 0; i < 6; i++)
		{
			if (notCardPos[i].cardOnIt == 1)
			{
				notCardPos[i].imgTexture.loadFromFile("assets/PlacedNotCard.png");
				notCardPos[i].img.setTexture(notCardPos[i].imgTexture);
				this->window->draw(notCardPos[i].img);
			}
		}
		for (int i = 1; i < 16; i++)
		{
			if (fPositions[i].cardOnIt == 1)
			{
				deck[fPositions[i].cardNum].img.setPosition(fPositions[i].x + 120, fPositions[i].y + 195);
				this->window->draw(deck[fPositions[i].cardNum].img);
			}
		}
		for (int i = 1; i < counterCards2; i++)
		{
			if (deck[i].drag == 1)
			{
				this->window->draw(deck[i].img);
			}
		}
		if (getMousePos(1381, 82, 11, *this->window))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				this->window->clear();
				this->window->draw(pyramid1Img);
				this->window->draw(timer);
				this->window->draw(baseCards2[0].BaseCardImg);
				this->window->draw(baseCards2[1].BaseCardImg);
				this->window->draw(baseCards2[2].BaseCardImg);
				this->window->draw(baseCards2[3].BaseCardImg);
				this->window->draw(baseCards2[4].BaseCardImg);
				this->window->draw(baseCards2[5].BaseCardImg);
				for (int i = 0; i < 6; i++)
				{
					if (notCardPos[i].cardOnIt == 1)
					{
						notCardPos[i].imgTexture.loadFromFile("assets/PlacedNotCard.png");
						notCardPos[i].img.setTexture(notCardPos[i].imgTexture);
						this->window->draw(notCardPos[i].img);
					}
				}
				for (int i = 1; i < 16; i++)
				{
					if (fPositions2[i].cardOnIt == 1)
					{
						this->window->draw(deck[fPositions2[i].cardNum].img);
					}
				}
			}
		}
		this->window->display();
		update(*this->window);


		if (win == 0)
		{
			if (roundPlayed)
			{
				transitionImg.setPosition(-2200, 0);
				sf::Time elapsed1 = clock.getElapsedTime();
				int timeCheck = int(elapsed1.asSeconds());
				int now = int(elapsed1.asSeconds());
				int x = -2200;

				while (now - timeCheck <= 1)
				{
					sf::Time elapsed1 = clock.getElapsedTime();
					now = int(elapsed1.asSeconds());
					setTimer();
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
					for (int i = 0; i < 6; i++)
					{
						if (notCardPos[i].cardOnIt == 1)
						{
							notCardPos[i].imgTexture.loadFromFile("assets/PlacedNotCard.png");
							notCardPos[i].img.setTexture(notCardPos[i].imgTexture);
							this->window->draw(notCardPos[i].img);
						}
					}
					tableOfTruth();
					setNotCardImages(cursorpos);
					for (int i = 1; i < 16; i++)
					{
						if (fPositions[i].cardOnIt == 1)
						{
							this->window->draw(deck[fPositions[i].cardNum].img);
						}
					}
					this->window->display();
				}
				while (true) // Transitions
				{
					this->window->clear();
					setTimer();
					if (x <= -315)
					{
						this->window->draw(this->backgroundSprite);
						this->window->draw(timer);
						this->window->draw(this->player1Text);
						this->window->draw(baseCards[0].BaseCardImg);
						this->window->draw(baseCards[1].BaseCardImg);
						this->window->draw(baseCards[2].BaseCardImg);
						this->window->draw(baseCards[3].BaseCardImg);
						this->window->draw(baseCards[4].BaseCardImg);
						this->window->draw(baseCards[5].BaseCardImg);
						for (int i = 0; i < 6; i++)
						{
							if (notCardPos[i].cardOnIt == 1)
							{
								notCardPos[i].imgTexture.loadFromFile("assets/PlacedNotCard.png");
								notCardPos[i].img.setTexture(notCardPos[i].imgTexture);
								this->window->draw(notCardPos[i].img);
							}
						}
						tableOfTruth();
						setNotCardImages(cursorpos);
						for (int i = 1; i < 16; i++)
						{
							if (fPositions[i].cardOnIt == 1)
							{
								this->window->draw(deck[fPositions[i].cardNum].img);
							}
						}
					}
					else
					{
						for (cardGet; player2Cards <= 5; player2Cards++, cardGet++)
						{
							deck[cardGet].player = 2;
						}
						cardsInHand();
						roundPlayed = 0;
						counter = 2;
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
						for (int i = 0; i < 6; i++)
						{
							if (notCardPos[i].cardOnIt == 1)
							{
								notCardPos[i].imgTexture.loadFromFile("assets/PlacedNotCard.png");
								notCardPos[i].img.setTexture(notCardPos[i].imgTexture);
								this->window->draw(notCardPos[i].img);
							}
						}
						tableOfTruth();
						setNotCardImages(cursorpos);
						for (int i = 1; i < 16; i++)
						{
							if (fPositions2[i].cardOnIt == 1)
							{
								this->window->draw(deck[fPositions2[i].cardNum].img);
							}
						}
					}
					if (x >= 1545)
					{
						break;
					}
					this->window->draw(transitionImg);
					transitionImg.setPosition(x, 0);
					x += 45;
					this->window->display();
				}
			}
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
		for (int i = 0; i < 6; i++)
		{
			if (notCardPos[i].cardOnIt == 1)
			{
				notCardPos[i].imgTexture.loadFromFile("assets/PlacedNotCard.png");
				notCardPos[i].img.setTexture(notCardPos[i].imgTexture);
				this->window->draw(notCardPos[i].img);
			}
		}
		sf::Time elapsed1 = clock.getElapsedTime();
		int timeCheck = int(elapsed1.asSeconds());
		int now = int(elapsed1.asSeconds());
		while (double(now) - double(timeCheck) <= 0.5)
		{
			sf::Time elapsed1 = clock.getElapsedTime();
			now = int(elapsed1.asSeconds());
			setTimer();
			this->window->clear();
			cardsInHand();
			this->window->draw(this->backgroundSprite);
			this->window->draw(timer);
			this->window->draw(this->player2Text);
			this->window->draw(baseCards2[0].BaseCardImg);
			this->window->draw(baseCards2[1].BaseCardImg);
			this->window->draw(baseCards2[2].BaseCardImg);
			this->window->draw(baseCards2[3].BaseCardImg);
			this->window->draw(baseCards2[4].BaseCardImg);
			this->window->draw(baseCards2[5].BaseCardImg);
			setNotCardImages2(cursorpos);
			for (int i = 1; i < 16; i++)
			{
				if (fPositions2[i].cardOnIt == 1)
				{
					this->window->draw(deck[fPositions2[i].cardNum].img);
				}
			}
			for (int i = 0; i < 6; i++)
			{
				if (notCardPos[i].cardOnIt == 1)
				{
					notCardPos[i].imgTexture.loadFromFile("assets/PlacedNotCard.png");
					notCardPos[i].img.setTexture(notCardPos[i].imgTexture);
					this->window->draw(notCardPos[i].img);
				}
			}
			tableOfTruth();
			placingCardsPos();
			this->window->display();
		}
		int notCardsNum = 0;
		int notCard;
		if (deck[player2Pos1].type == 'n')
		{
			otherNot = 1;
		}
		else if (deck[player2Pos2].type == 'n')
		{
			otherNot = 1;
		}
		else if (deck[player2Pos3].type == 'n')
		{
			otherNot = 1;
		}
		else if (deck[player2Pos4].type == 'n')
		{
			otherNot = 1;
		}
		else if (deck[player2Pos5].type == 'n')
		{
			otherNot = 1;
		}
		else
		{
			notCard = 0;
			notCardsNum = 0;
		}

		if (otherNot == 1)
		{
			if (deck[player2Pos1].type == 'n')
			{
				notCardsNum++;
				notCard = 1;
			}
			if (deck[player2Pos2].type == 'n')
			{
				notCardsNum++;
				notCard = 2;
			}
			if (deck[player2Pos3].type == 'n')
			{
				notCardsNum++;
				notCard = 3;
			}
			if (deck[player2Pos4].type == 'n')
			{
				notCardsNum++;
				notCard = 4;
			}
			if (deck[player2Pos5].type == 'n')
			{
				notCardsNum++;
				notCard = 5;
			}
			srand((unsigned)time(0));
			int shouldPlayNot = rand() % 10 + 1;
			if (shouldPlayNot <= 3 || notCardsNum >= 2)
			{
				notCardsNum = 0;
				int randomNotUse = rand() % 6;
				otherNot = 0;
				switch (notCard)
				{
				case 1:
					if (deck[player1Pos1].type == 'n')
					{
						otherNot = 1;
					}
					else if (deck[player1Pos2].type == 'n')
					{
						otherNot = 1;
					}
					else if (deck[player1Pos3].type == 'n')
					{
						otherNot = 1;
					}
					else if (deck[player1Pos4].type == 'n')
					{
						otherNot = 1;
					}
					else if (deck[player1Pos5].type == 'n')
					{
						otherNot = 1;
					}

					if (otherNot)
					{
						otherNot = 0;
						while (true)
						{
							setTimer();
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
							for (int i = 0; i < 6; i++)
							{
								if (notCardPos[i].cardOnIt == 1)
								{
									notCardPos[i].imgTexture.loadFromFile("assets/PlacedNotCard.png");
									notCardPos[i].img.setTexture(notCardPos[i].imgTexture);
									this->window->draw(notCardPos[i].img);
								}
							}
							tableOfTruth();
							setNotCardImages(cursorpos);
							for (int i = 1; i < 16; i++)
							{
								if (fPositions2[i].cardOnIt == 1)
								{
									this->window->draw(deck[fPositions2[i].cardNum].img);
								}
							}
							if (getMousePos(639, 530, 17, *this->window))
							{
								notCardPopTexture.loadFromFile("assets/NotCard2PopUp1.png");
								notCardPop.setTexture(notCardPopTexture);
								if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
								{
									if (deck[player1Pos1].type == 'n')
									{
										deck[player1Pos1].drag = 0;
										deck[player1Pos1].placed = 1;
										deck[player1Pos1].num = 0;
										deck[player1Pos1].type = 0;
										deck[player1Pos1].value = 0;
										deck[player1Pos1].player1pos = 0;
										deck[player1Pos1].display1 = 0;
										deck[player1Pos1].display2 = 0;
										player1Pos1 = 0;
									}
									else if (deck[player1Pos2].type == 'n')
									{
										deck[player1Pos2].drag = 0;
										deck[player1Pos2].placed = 1;
										deck[player1Pos2].num = 0;
										deck[player1Pos2].type = 0;
										deck[player1Pos2].value = 0;
										deck[player1Pos2].player1pos = 0;
										deck[player1Pos2].display1 = 0;
										deck[player1Pos2].display2 = 0;
										player1Pos2 = 0;
									}
									else if (deck[player1Pos3].type == 'n')
									{
										deck[player1Pos3].drag = 0;
										deck[player1Pos3].placed = 1;
										deck[player1Pos3].num = 0;
										deck[player1Pos3].type = 0;
										deck[player1Pos3].value = 0;
										deck[player1Pos3].player1pos = 0;
										deck[player1Pos3].display1 = 0;
										deck[player1Pos3].display2 = 0;
										player1Pos3 = 0;
									}
									else if (deck[player1Pos4].type == 'n')
									{
										deck[player1Pos4].drag = 0;
										deck[player1Pos4].placed = 1;
										deck[player1Pos4].num = 0;
										deck[player1Pos4].type = 0;
										deck[player1Pos4].value = 0;
										deck[player1Pos4].player1pos = 0;
										deck[player1Pos4].display1 = 0;
										deck[player1Pos4].display2 = 0;
										player1Pos4 = 0;
									}
									else if (deck[player1Pos5].type == 'n')
									{
										deck[player1Pos5].drag = 0;
										deck[player1Pos5].placed = 1;
										deck[player1Pos5].num = 0;
										deck[player1Pos5].type = 0;
										deck[player1Pos5].value = 0;
										deck[player1Pos5].player1pos = 0;
										deck[player1Pos5].display1 = 0;
										deck[player1Pos5].display2 = 0;
										player1Pos5 = 0;
									}
									roundPlayed = 1;
									deck[player2Pos1].drag = 0;
									deck[player2Pos1].placed = 1;
									notCardPos[randomNotUse].cardOnIt = 0;
									deck[player2Pos1].num = 0;
									deck[player2Pos1].type = 0;
									deck[player2Pos1].value = 0;
									deck[player2Pos1].player2pos = 0;
									deck[player2Pos1].display1 = 0;
									deck[player2Pos1].display2 = 0;
									player2Pos1 = 0;
									showNotA = 0;
									player1Cards--;
									player2Cards--;
									pressed = true;
									break;
								}
							}
							else if (getMousePos(823, 530, 17, *this->window))
							{
								notCardPopTexture.loadFromFile("assets/NotCard2PopUp2.png");
								notCardPop.setTexture(notCardPopTexture);
								if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
								{
									baseCards[randomNotUse].value = !(baseCards[randomNotUse].value);
									baseCards2[randomNotUse].value = !(baseCards2[randomNotUse].value);
									baseCards[randomNotUse].BaseCardImg.setTexture(baseCards2[randomNotUse].BaseCardImgTexture);
									baseCards2[randomNotUse].BaseCardImg.setTexture(baseCards[randomNotUse].BaseCardImgTexture);
									roundPlayed = 1;

									deck[player2Pos1].drag = 0;
									deck[player2Pos1].placed = 1;
									notCardPos[randomNotUse].cardOnIt = 1;
									deck[player2Pos1].num = 0;
									deck[player2Pos1].type = 0;
									deck[player2Pos1].value = 0;
									deck[player2Pos1].player2pos = 0;
									deck[player2Pos1].display1 = 0;
									deck[player2Pos1].display2 = 0;
									player2Pos1 = 0;
									showNotA = 0;
									player2Cards--;
									pressed = true;
									notCardLogic(randomNotUse);
									break;
								}
							}
							else
							{
								notCardPopTexture.loadFromFile("assets/NotCard2PopUp.png");
								notCardPop.setTexture(notCardPopTexture);
							}
							this->window->draw(notCardPop);
							this->window->display();
						}
					}
					else
					{
						baseCards[randomNotUse].value = !(baseCards[randomNotUse].value);
						baseCards2[randomNotUse].value = !(baseCards2[randomNotUse].value);
						baseCards[randomNotUse].BaseCardImg.setTexture(baseCards2[randomNotUse].BaseCardImgTexture);
						baseCards2[randomNotUse].BaseCardImg.setTexture(baseCards[randomNotUse].BaseCardImgTexture);
						roundPlayed = 1;

						deck[player2Pos1].drag = 0;
						deck[player2Pos1].placed = 1;
						notCardPos[randomNotUse].cardOnIt = 1;
						deck[player2Pos1].num = 0;
						deck[player2Pos1].type = 0;
						deck[player2Pos1].value = 0;
						deck[player2Pos1].player2pos = 0;
						deck[player2Pos1].display1 = 0;
						deck[player2Pos1].display2 = 0;
						card1Dragging2 = 0;
						player2Pos1 = 0;
						showNotA = 0;
						player2Cards--;
						pressed = true;
						notCardLogic(randomNotUse);
					}
					break;
				case 2:
					if (deck[player1Pos1].type == 'n')
					{
						otherNot = 1;
					}
					else if (deck[player1Pos2].type == 'n')
					{
						otherNot = 1;
					}
					else if (deck[player1Pos3].type == 'n')
					{
						otherNot = 1;
					}
					else if (deck[player1Pos4].type == 'n')
					{
						otherNot = 1;
					}
					else if (deck[player1Pos5].type == 'n')
					{
						otherNot = 1;
					}

					if (otherNot)
					{
						otherNot = 0;
						while (true)
						{
							setTimer();
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
							for (int i = 0; i < 6; i++)
							{
								if (notCardPos[i].cardOnIt == 1)
								{
									notCardPos[i].imgTexture.loadFromFile("assets/PlacedNotCard.png");
									notCardPos[i].img.setTexture(notCardPos[i].imgTexture);
									this->window->draw(notCardPos[i].img);
								}
							}
							tableOfTruth();
							setNotCardImages(cursorpos);
							for (int i = 1; i < 16; i++)
							{
								if (fPositions2[i].cardOnIt == 1)
								{
									this->window->draw(deck[fPositions2[i].cardNum].img);
								}
							}
							if (getMousePos(639, 530, 17, *this->window))
							{
								notCardPopTexture.loadFromFile("assets/NotCard2PopUp1.png");
								notCardPop.setTexture(notCardPopTexture);
								if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
								{
									if (deck[player1Pos1].type == 'n')
									{
										deck[player1Pos1].drag = 0;
										deck[player1Pos1].placed = 1;
										deck[player1Pos1].num = 0;
										deck[player1Pos1].type = 0;
										deck[player1Pos1].value = 0;
										deck[player1Pos1].player1pos = 0;
										deck[player1Pos1].display1 = 0;
										deck[player1Pos1].display2 = 0;
										player1Pos1 = 0;
									}
									else if (deck[player1Pos2].type == 'n')
									{
										deck[player1Pos2].drag = 0;
										deck[player1Pos2].placed = 1;
										deck[player1Pos2].num = 0;
										deck[player1Pos2].type = 0;
										deck[player1Pos2].value = 0;
										deck[player1Pos2].player1pos = 0;
										deck[player1Pos2].display1 = 0;
										deck[player1Pos2].display2 = 0;
										player1Pos2 = 0;
									}
									else if (deck[player1Pos3].type == 'n')
									{
										deck[player1Pos3].drag = 0;
										deck[player1Pos3].placed = 1;
										deck[player1Pos3].num = 0;
										deck[player1Pos3].type = 0;
										deck[player1Pos3].value = 0;
										deck[player1Pos3].player1pos = 0;
										deck[player1Pos3].display1 = 0;
										deck[player1Pos3].display2 = 0;
										player1Pos3 = 0;
									}
									else if (deck[player1Pos4].type == 'n')
									{
										deck[player1Pos4].drag = 0;
										deck[player1Pos4].placed = 1;
										deck[player1Pos4].num = 0;
										deck[player1Pos4].type = 0;
										deck[player1Pos4].value = 0;
										deck[player1Pos4].player1pos = 0;
										deck[player1Pos4].display1 = 0;
										deck[player1Pos4].display2 = 0;
										player1Pos4 = 0;
									}
									else if (deck[player1Pos5].type == 'n')
									{
										deck[player1Pos5].drag = 0;
										deck[player1Pos5].placed = 1;
										deck[player1Pos5].num = 0;
										deck[player1Pos5].type = 0;
										deck[player1Pos5].value = 0;
										deck[player1Pos5].player1pos = 0;
										deck[player1Pos5].display1 = 0;
										deck[player1Pos5].display2 = 0;
										player1Pos5 = 0;
									}
									roundPlayed = 1;
									deck[player2Pos2].drag = 0;
									deck[player2Pos2].placed = 1;
									notCardPos[randomNotUse].cardOnIt = 0;
									deck[player2Pos2].num = 0;
									deck[player2Pos2].type = 0;
									deck[player2Pos2].value = 0;
									deck[player2Pos2].player2pos = 0;
									deck[player2Pos2].display1 = 0;
									deck[player2Pos2].display2 = 0;
									player2Pos2 = 0;
									showNotA = 0;
									player1Cards--;
									player2Cards--;
									pressed = true;
									break;
								}
							}
							else if (getMousePos(823, 530, 17, *this->window))
							{
								notCardPopTexture.loadFromFile("assets/NotCard2PopUp2.png");
								notCardPop.setTexture(notCardPopTexture);
								if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
								{
									baseCards[randomNotUse].value = !(baseCards[randomNotUse].value);
									baseCards2[randomNotUse].value = !(baseCards2[randomNotUse].value);
									baseCards[randomNotUse].BaseCardImg.setTexture(baseCards2[randomNotUse].BaseCardImgTexture);
									baseCards2[randomNotUse].BaseCardImg.setTexture(baseCards[randomNotUse].BaseCardImgTexture);
									roundPlayed = 1;

									deck[player2Pos2].drag = 0;
									deck[player2Pos2].placed = 1;
									notCardPos[randomNotUse].cardOnIt = 1;
									deck[player2Pos2].num = 0;
									deck[player2Pos2].type = 0;
									deck[player2Pos2].value = 0;
									deck[player2Pos2].player2pos = 0;
									deck[player2Pos2].display1 = 0;
									deck[player2Pos2].display2 = 0;
									player2Pos2 = 0;
									showNotA = 0;
									player2Cards--;
									pressed = true;
									notCardLogic(randomNotUse);
									break;
								}
							}
							else
							{
								notCardPopTexture.loadFromFile("assets/NotCard2PopUp.png");
								notCardPop.setTexture(notCardPopTexture);
							}
							this->window->draw(notCardPop);
							this->window->display();
						}
					}
					else
					{
						baseCards[randomNotUse].value = !(baseCards[randomNotUse].value);
						baseCards2[randomNotUse].value = !(baseCards2[randomNotUse].value);
						baseCards[randomNotUse].BaseCardImg.setTexture(baseCards2[randomNotUse].BaseCardImgTexture);
						baseCards2[randomNotUse].BaseCardImg.setTexture(baseCards[randomNotUse].BaseCardImgTexture);
						roundPlayed = 1;

						deck[player2Pos2].drag = 0;
						deck[player2Pos2].placed = 1;
						notCardPos[randomNotUse].cardOnIt = 1;
						deck[player2Pos2].num = 0;
						deck[player2Pos2].type = 0;
						deck[player2Pos2].value = 0;
						deck[player2Pos2].player2pos = 0;
						deck[player2Pos2].display1 = 0;
						deck[player2Pos2].display2 = 0;
						player2Pos2 = 0;
						showNotA = 0;
						player2Cards--;
						pressed = true;
						notCardLogic(randomNotUse);
					}
					break;
				case 3:
					if (deck[player1Pos1].type == 'n')
					{
						otherNot = 1;
					}
					else if (deck[player1Pos2].type == 'n')
					{
						otherNot = 1;
					}
					else if (deck[player1Pos3].type == 'n')
					{
						otherNot = 1;
					}
					else if (deck[player1Pos4].type == 'n')
					{
						otherNot = 1;
					}
					else if (deck[player1Pos5].type == 'n')
					{
						otherNot = 1;
					}

					if (otherNot)
					{
						otherNot = 0;
						while (true)
						{
							setTimer();
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
							for (int i = 0; i < 6; i++)
							{
								if (notCardPos[i].cardOnIt == 1)
								{
									notCardPos[i].imgTexture.loadFromFile("assets/PlacedNotCard.png");
									notCardPos[i].img.setTexture(notCardPos[i].imgTexture);
									this->window->draw(notCardPos[i].img);
								}
							}
							tableOfTruth();
							setNotCardImages(cursorpos);
							for (int i = 1; i < 16; i++)
							{
								if (fPositions2[i].cardOnIt == 1)
								{
									this->window->draw(deck[fPositions2[i].cardNum].img);
								}
							}
							if (getMousePos(639, 530, 17, *this->window))
							{
								notCardPopTexture.loadFromFile("assets/NotCard2PopUp1.png");
								notCardPop.setTexture(notCardPopTexture);
								if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
								{
									if (deck[player1Pos1].type == 'n')
									{
										deck[player1Pos1].drag = 0;
										deck[player1Pos1].placed = 1;
										deck[player1Pos1].num = 0;
										deck[player1Pos1].type = 0;
										deck[player1Pos1].value = 0;
										deck[player1Pos1].player1pos = 0;
										deck[player1Pos1].display1 = 0;
										deck[player1Pos1].display2 = 0;
										player1Pos1 = 0;
									}
									else if (deck[player1Pos2].type == 'n')
									{
										deck[player1Pos2].drag = 0;
										deck[player1Pos2].placed = 1;
										deck[player1Pos2].num = 0;
										deck[player1Pos2].type = 0;
										deck[player1Pos2].value = 0;
										deck[player1Pos2].player1pos = 0;
										deck[player1Pos2].display1 = 0;
										deck[player1Pos2].display2 = 0;
										player1Pos2 = 0;
									}
									else if (deck[player1Pos3].type == 'n')
									{
										deck[player1Pos3].drag = 0;
										deck[player1Pos3].placed = 1;
										deck[player1Pos3].num = 0;
										deck[player1Pos3].type = 0;
										deck[player1Pos3].value = 0;
										deck[player1Pos3].player1pos = 0;
										deck[player1Pos3].display1 = 0;
										deck[player1Pos3].display2 = 0;
										player1Pos3 = 0;
									}
									else if (deck[player1Pos4].type == 'n')
									{
										deck[player1Pos4].drag = 0;
										deck[player1Pos4].placed = 1;
										deck[player1Pos4].num = 0;
										deck[player1Pos4].type = 0;
										deck[player1Pos4].value = 0;
										deck[player1Pos4].player1pos = 0;
										deck[player1Pos4].display1 = 0;
										deck[player1Pos4].display2 = 0;
										player1Pos4 = 0;
									}
									else if (deck[player1Pos5].type == 'n')
									{
										deck[player1Pos5].drag = 0;
										deck[player1Pos5].placed = 1;
										deck[player1Pos5].num = 0;
										deck[player1Pos5].type = 0;
										deck[player1Pos5].value = 0;
										deck[player1Pos5].player1pos = 0;
										deck[player1Pos5].display1 = 0;
										deck[player1Pos5].display2 = 0;
										player1Pos5 = 0;
									}
									roundPlayed = 1;
									deck[player2Pos3].drag = 0;
									deck[player2Pos3].placed = 1;
									notCardPos[randomNotUse].cardOnIt = 0;
									deck[player2Pos3].num = 0;
									deck[player2Pos3].type = 0;
									deck[player2Pos3].value = 0;
									deck[player2Pos3].player2pos = 0;
									deck[player2Pos3].display1 = 0;
									deck[player2Pos3].display2 = 0;
									player2Pos3 = 0;
									showNotA = 0;
									player1Cards--;
									player2Cards--;
									pressed = true;
									break;
								}
							}
							else if (getMousePos(823, 530, 17, *this->window))
							{
								notCardPopTexture.loadFromFile("assets/NotCard2PopUp2.png");
								notCardPop.setTexture(notCardPopTexture);
								if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
								{
									baseCards[randomNotUse].value = !(baseCards[randomNotUse].value);
									baseCards2[randomNotUse].value = !(baseCards2[randomNotUse].value);
									baseCards[randomNotUse].BaseCardImg.setTexture(baseCards2[randomNotUse].BaseCardImgTexture);
									baseCards2[randomNotUse].BaseCardImg.setTexture(baseCards[randomNotUse].BaseCardImgTexture);
									roundPlayed = 1;

									deck[player2Pos3].drag = 0;
									deck[player2Pos3].placed = 1;
									notCardPos[randomNotUse].cardOnIt = 1;
									deck[player2Pos3].num = 0;
									deck[player2Pos3].type = 0;
									deck[player2Pos3].value = 0;
									deck[player2Pos3].player2pos = 0;
									deck[player2Pos3].display1 = 0;
									deck[player2Pos3].display2 = 0;
									player2Pos3 = 0;
									showNotA = 0;
									player2Cards--;
									pressed = true;
									notCardLogic(randomNotUse);
									break;
								}
							}
							else
							{
								notCardPopTexture.loadFromFile("assets/NotCard2PopUp.png");
								notCardPop.setTexture(notCardPopTexture);
							}
							this->window->draw(notCardPop);
							this->window->display();
						}
					}
					else
					{
						baseCards[randomNotUse].value = !(baseCards[randomNotUse].value);
						baseCards2[randomNotUse].value = !(baseCards2[randomNotUse].value);
						baseCards[randomNotUse].BaseCardImg.setTexture(baseCards2[randomNotUse].BaseCardImgTexture);
						baseCards2[randomNotUse].BaseCardImg.setTexture(baseCards[randomNotUse].BaseCardImgTexture);
						roundPlayed = 1;

						deck[player2Pos3].drag = 0;
						deck[player2Pos3].placed = 1;
						notCardPos[randomNotUse].cardOnIt = 1;
						deck[player2Pos3].num = 0;
						deck[player2Pos3].type = 0;
						deck[player2Pos3].value = 0;
						deck[player2Pos3].player2pos = 0;
						deck[player2Pos3].display1 = 0;
						deck[player2Pos3].display2 = 0;
						player2Pos3 = 0;
						showNotA = 0;
						player2Cards--;
						pressed = true;
						notCardLogic(randomNotUse);
					}
					break;
				case 4:
					if (deck[player1Pos1].type == 'n')
					{
						otherNot = 1;
					}
					else if (deck[player1Pos2].type == 'n')
					{
						otherNot = 1;
					}
					else if (deck[player1Pos3].type == 'n')
					{
						otherNot = 1;
					}
					else if (deck[player1Pos4].type == 'n')
					{
						otherNot = 1;
					}
					else if (deck[player1Pos5].type == 'n')
					{
						otherNot = 1;
					}

					if (otherNot)
					{
						otherNot = 0;
						while (true)
						{
							setTimer();
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
							for (int i = 0; i < 6; i++)
							{
								if (notCardPos[i].cardOnIt == 1)
								{
									notCardPos[i].imgTexture.loadFromFile("assets/PlacedNotCard.png");
									notCardPos[i].img.setTexture(notCardPos[i].imgTexture);
									this->window->draw(notCardPos[i].img);
								}
							}
							tableOfTruth();
							setNotCardImages(cursorpos);
							for (int i = 1; i < 16; i++)
							{
								if (fPositions2[i].cardOnIt == 1)
								{
									this->window->draw(deck[fPositions2[i].cardNum].img);
								}
							}
							if (getMousePos(639, 530, 17, *this->window))
							{
								notCardPopTexture.loadFromFile("assets/NotCard2PopUp1.png");
								notCardPop.setTexture(notCardPopTexture);
								if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
								{
									if (deck[player1Pos1].type == 'n')
									{
										deck[player1Pos1].drag = 0;
										deck[player1Pos1].placed = 1;
										deck[player1Pos1].num = 0;
										deck[player1Pos1].type = 0;
										deck[player1Pos1].value = 0;
										deck[player1Pos1].player1pos = 0;
										deck[player1Pos1].display1 = 0;
										deck[player1Pos1].display2 = 0;
										player1Pos1 = 0;
									}
									else if (deck[player1Pos2].type == 'n')
									{
										deck[player1Pos2].drag = 0;
										deck[player1Pos2].placed = 1;
										deck[player1Pos2].num = 0;
										deck[player1Pos2].type = 0;
										deck[player1Pos2].value = 0;
										deck[player1Pos2].player1pos = 0;
										deck[player1Pos2].display1 = 0;
										deck[player1Pos2].display2 = 0;
										player1Pos2 = 0;
									}
									else if (deck[player1Pos3].type == 'n')
									{
										deck[player1Pos3].drag = 0;
										deck[player1Pos3].placed = 1;
										deck[player1Pos3].num = 0;
										deck[player1Pos3].type = 0;
										deck[player1Pos3].value = 0;
										deck[player1Pos3].player1pos = 0;
										deck[player1Pos3].display1 = 0;
										deck[player1Pos3].display2 = 0;
										player1Pos3 = 0;
									}
									else if (deck[player1Pos4].type == 'n')
									{
										deck[player1Pos4].drag = 0;
										deck[player1Pos4].placed = 1;
										deck[player1Pos4].num = 0;
										deck[player1Pos4].type = 0;
										deck[player1Pos4].value = 0;
										deck[player1Pos4].player1pos = 0;
										deck[player1Pos4].display1 = 0;
										deck[player1Pos4].display2 = 0;
										player1Pos4 = 0;
									}
									else if (deck[player1Pos5].type == 'n')
									{
										deck[player1Pos5].drag = 0;
										deck[player1Pos5].placed = 1;
										deck[player1Pos5].num = 0;
										deck[player1Pos5].type = 0;
										deck[player1Pos5].value = 0;
										deck[player1Pos5].player1pos = 0;
										deck[player1Pos5].display1 = 0;
										deck[player1Pos5].display2 = 0;
										player1Pos5 = 0;
									}
									roundPlayed = 1;
									deck[player2Pos4].drag = 0;
									deck[player2Pos4].placed = 1;
									notCardPos[randomNotUse].cardOnIt = 0;
									deck[player2Pos4].num = 0;
									deck[player2Pos4].type = 0;
									deck[player2Pos4].value = 0;
									deck[player2Pos4].player2pos = 0;
									deck[player2Pos4].display1 = 0;
									deck[player2Pos4].display2 = 0;
									player2Pos4 = 0;
									showNotA = 0;
									player1Cards--;
									player2Cards--;
									pressed = true;
									break;
								}
							}
							else if (getMousePos(823, 530, 17, *this->window))
							{
								notCardPopTexture.loadFromFile("assets/NotCard2PopUp2.png");
								notCardPop.setTexture(notCardPopTexture);
								if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
								{
									baseCards[randomNotUse].value = !(baseCards[randomNotUse].value);
									baseCards2[randomNotUse].value = !(baseCards2[randomNotUse].value);
									baseCards[randomNotUse].BaseCardImg.setTexture(baseCards2[randomNotUse].BaseCardImgTexture);
									baseCards2[randomNotUse].BaseCardImg.setTexture(baseCards[randomNotUse].BaseCardImgTexture);
									roundPlayed = 1;

									deck[player2Pos4].drag = 0;
									deck[player2Pos4].placed = 1;
									notCardPos[randomNotUse].cardOnIt = 1;
									deck[player2Pos4].num = 0;
									deck[player2Pos4].type = 0;
									deck[player2Pos4].value = 0;
									deck[player2Pos4].player2pos = 0;
									deck[player2Pos4].display1 = 0;
									deck[player2Pos4].display2 = 0;
									player2Pos4 = 0;
									showNotA = 0;
									player2Cards--;
									pressed = true;
									notCardLogic(randomNotUse);
									break;
								}
							}
							else
							{
								notCardPopTexture.loadFromFile("assets/NotCard2PopUp.png");
								notCardPop.setTexture(notCardPopTexture);
							}
							this->window->draw(notCardPop);
							this->window->display();
						}
					}
					else
					{
						baseCards[randomNotUse].value = !(baseCards[randomNotUse].value);
						baseCards2[randomNotUse].value = !(baseCards2[randomNotUse].value);
						baseCards[randomNotUse].BaseCardImg.setTexture(baseCards2[randomNotUse].BaseCardImgTexture);
						baseCards2[randomNotUse].BaseCardImg.setTexture(baseCards[randomNotUse].BaseCardImgTexture);
						roundPlayed = 1;

						deck[player2Pos4].drag = 0;
						deck[player2Pos4].placed = 1;
						notCardPos[randomNotUse].cardOnIt = 1;
						deck[player2Pos4].num = 0;
						deck[player2Pos4].type = 0;
						deck[player2Pos4].value = 0;
						deck[player2Pos4].player2pos = 0;
						deck[player2Pos4].display1 = 0;
						deck[player2Pos4].display2 = 0;
						player2Pos4 = 0;
						showNotA = 0;
						player2Cards--;
						pressed = true;
						notCardLogic(randomNotUse);
					}
					break;
				case 5:
					if (deck[player1Pos1].type == 'n')
					{
						otherNot = 1;
					}
					else if (deck[player1Pos2].type == 'n')
					{
						otherNot = 1;
					}
					else if (deck[player1Pos3].type == 'n')
					{
						otherNot = 1;
					}
					else if (deck[player1Pos4].type == 'n')
					{
						otherNot = 1;
					}
					else if (deck[player1Pos5].type == 'n')
					{
						otherNot = 1;
					}

					if (otherNot)
					{
						otherNot = 0;
						while (true)
						{
							setTimer();
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
							for (int i = 0; i < 6; i++)
							{
								if (notCardPos[i].cardOnIt == 1)
								{
									notCardPos[i].imgTexture.loadFromFile("assets/PlacedNotCard.png");
									notCardPos[i].img.setTexture(notCardPos[i].imgTexture);
									this->window->draw(notCardPos[i].img);
								}
							}
							tableOfTruth();
							setNotCardImages(cursorpos);
							for (int i = 1; i < 16; i++)
							{
								if (fPositions2[i].cardOnIt == 1)
								{
									this->window->draw(deck[fPositions2[i].cardNum].img);
								}
							}
							if (getMousePos(639, 530, 17, *this->window))
							{
								notCardPopTexture.loadFromFile("assets/NotCard2PopUp1.png");
								notCardPop.setTexture(notCardPopTexture);
								if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
								{
									if (deck[player1Pos1].type == 'n')
									{
										deck[player1Pos1].drag = 0;
										deck[player1Pos1].placed = 1;
										deck[player1Pos1].num = 0;
										deck[player1Pos1].type = 0;
										deck[player1Pos1].value = 0;
										deck[player1Pos1].player1pos = 0;
										deck[player1Pos1].display1 = 0;
										deck[player1Pos1].display2 = 0;
										player1Pos1 = 0;
									}
									else if (deck[player1Pos2].type == 'n')
									{
										deck[player1Pos2].drag = 0;
										deck[player1Pos2].placed = 1;
										deck[player1Pos2].num = 0;
										deck[player1Pos2].type = 0;
										deck[player1Pos2].value = 0;
										deck[player1Pos2].player1pos = 0;
										deck[player1Pos2].display1 = 0;
										deck[player1Pos2].display2 = 0;
										player1Pos2 = 0;
									}
									else if (deck[player1Pos3].type == 'n')
									{
										deck[player1Pos3].drag = 0;
										deck[player1Pos3].placed = 1;
										deck[player1Pos3].num = 0;
										deck[player1Pos3].type = 0;
										deck[player1Pos3].value = 0;
										deck[player1Pos3].player1pos = 0;
										deck[player1Pos3].display1 = 0;
										deck[player1Pos3].display2 = 0;
										player1Pos3 = 0;
									}
									else if (deck[player1Pos4].type == 'n')
									{
										deck[player1Pos4].drag = 0;
										deck[player1Pos4].placed = 1;
										deck[player1Pos4].num = 0;
										deck[player1Pos4].type = 0;
										deck[player1Pos4].value = 0;
										deck[player1Pos4].player1pos = 0;
										deck[player1Pos4].display1 = 0;
										deck[player1Pos4].display2 = 0;
										player1Pos4 = 0;
									}
									else if (deck[player1Pos5].type == 'n')
									{
										deck[player1Pos5].drag = 0;
										deck[player1Pos5].placed = 1;
										deck[player1Pos5].num = 0;
										deck[player1Pos5].type = 0;
										deck[player1Pos5].value = 0;
										deck[player1Pos5].player1pos = 0;
										deck[player1Pos5].display1 = 0;
										deck[player1Pos5].display2 = 0;
										player1Pos5 = 0;
									}
									roundPlayed = 1;
									deck[player2Pos5].drag = 0;
									deck[player2Pos5].placed = 1;
									notCardPos[randomNotUse].cardOnIt = 0;
									deck[player2Pos5].num = 0;
									deck[player2Pos5].type = 0;
									deck[player2Pos5].value = 0;
									deck[player2Pos5].player2pos = 0;
									deck[player2Pos5].display1 = 0;
									deck[player2Pos5].display2 = 0;
									player2Pos5 = 0;
									showNotA = 0;
									player1Cards--;
									player2Cards--;
									pressed = true;
									break;
								}
							}
							else if (getMousePos(823, 530, 17, *this->window))
							{
								notCardPopTexture.loadFromFile("assets/NotCard2PopUp2.png");
								notCardPop.setTexture(notCardPopTexture);
								if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
								{
									baseCards[randomNotUse].value = !(baseCards[randomNotUse].value);
									baseCards2[randomNotUse].value = !(baseCards2[randomNotUse].value);
									baseCards[randomNotUse].BaseCardImg.setTexture(baseCards2[randomNotUse].BaseCardImgTexture);
									baseCards2[randomNotUse].BaseCardImg.setTexture(baseCards[randomNotUse].BaseCardImgTexture);
									roundPlayed = 1;

									deck[player2Pos5].drag = 0;
									deck[player2Pos5].placed = 1;
									notCardPos[randomNotUse].cardOnIt = 1;
									deck[player2Pos5].num = 0;
									deck[player2Pos5].type = 0;
									deck[player2Pos5].value = 0;
									deck[player2Pos5].player2pos = 0;
									deck[player2Pos5].display1 = 0;
									deck[player2Pos5].display2 = 0;
									player2Pos5 = 0;
									showNotA = 0;
									player2Cards--;
									pressed = true;
									notCardLogic(randomNotUse);
									break;
								}
							}
							else
							{
								notCardPopTexture.loadFromFile("assets/NotCard2PopUp.png");
								notCardPop.setTexture(notCardPopTexture);
							}
							this->window->draw(notCardPop);
							this->window->display();
						}
					}
					else
					{
						baseCards[randomNotUse].value = !(baseCards[randomNotUse].value);
						baseCards2[randomNotUse].value = !(baseCards2[randomNotUse].value);
						baseCards[randomNotUse].BaseCardImg.setTexture(baseCards2[randomNotUse].BaseCardImgTexture);
						baseCards2[randomNotUse].BaseCardImg.setTexture(baseCards[randomNotUse].BaseCardImgTexture);
						roundPlayed = 1;

						deck[player2Pos5].drag = 0;
						deck[player2Pos5].placed = 1;
						notCardPos[randomNotUse].cardOnIt = 1;
						deck[player2Pos5].num = 0;
						deck[player2Pos5].type = 0;
						deck[player2Pos5].value = 0;
						deck[player2Pos5].player2pos = 0;
						deck[player2Pos5].display1 = 0;
						deck[player2Pos5].display2 = 0;
						player2Pos5 = 0;
						showNotA = 0;
						player2Cards--;
						pressed = true;
						notCardLogic(randomNotUse);
					}
					break;
				}
			}
			else
			{
				otherNot = 0;
				goto notPlayingNotCard;
			}
		}
		else
		{
			notPlayingNotCard:
			srand((unsigned)time(0));
			bool succesful = 0;
			int randomNum = rand() % 10 + 1;
			if (randomNum != 7 && randomNum != 2)
			{
				for (int i = 1; i < 6; i++)
				{
					if (i != notCard)
					{
						switch (i)
						{
						case 1:
							succesful = 0;
							deck[player2Pos1].drag = 1;
							deck[player2Pos1].img.setRotation(180.f);
							for (int j = 0; j < 16; j++)
							{
								if (fPositions2[j].showPos == 1)
								{
									if (checkPlacedCards(j))
									{
										succesful = 1;
										deck[player2Pos1].drag = 0;
										deck[player2Pos1].img.setRotation(180.f);
										deck[player2Pos1].placed = 1;
										fPositions2[j].cardOnIt = 1;
										fPositions2[j].cardNum = deck[player2Pos1].num;
										fPositions2[j].cardValue = deck[player2Pos1].value;
										deck[player2Pos1].num = 0;
										deck[player2Pos1].x = fPositions2[j].x;
										deck[player2Pos1].y = fPositions2[j].y;
										deck[player2Pos1].img.setPosition(fPositions2[j].x, fPositions2[j].y);
										player2Pos1 = 0;
										player2Cards--;
										roundPlayed = 1;
										break;
									}
								}
							}
							if (!(succesful))
							{
								deck[player2Pos1].drag = 0;
								deck[player2Pos1].img.setRotation(90.f);
							}
							break;
						case 2:
							succesful = 0;
							deck[player2Pos2].drag = 1;
							deck[player2Pos2].img.setRotation(180.f);
							for (int j = 0; j < 16; j++)
							{
								if (fPositions2[j].showPos == 1)
								{
									if (checkPlacedCards(j))
									{
										succesful = 1;
										deck[player2Pos2].drag = 0;
										deck[player2Pos2].img.setRotation(180.f);
										deck[player2Pos2].placed = 1;
										fPositions2[j].cardOnIt = 1;
										fPositions2[j].cardNum = deck[player2Pos2].num;
										fPositions2[j].cardValue = deck[player2Pos2].value;
										deck[player2Pos2].num = 0;
										deck[player2Pos2].x = fPositions2[j].x;
										deck[player2Pos2].y = fPositions2[j].y;
										deck[player2Pos2].img.setPosition(fPositions2[j].x, fPositions2[j].y);
										player2Pos2 = 0;
										player2Cards--;
										roundPlayed = 1;
										break;
									}
								}
							}
							if (!(succesful))
							{
								deck[player2Pos2].drag = 0;
								deck[player2Pos2].img.setRotation(90.f);
							}
							break;
						case 3:
							succesful = 0;
							deck[player2Pos3].drag = 1;
							deck[player2Pos3].img.setRotation(180.f);
							for (int j = 0; j < 16; j++)
							{
								if (fPositions2[j].showPos == 1)
								{
									if (checkPlacedCards(j))
									{
										succesful = 1;
										deck[player2Pos3].drag = 0;
										deck[player2Pos3].img.setRotation(180.f);
										deck[player2Pos3].placed = 1;
										fPositions2[j].cardOnIt = 1;
										fPositions2[j].cardNum = deck[player2Pos3].num;
										fPositions2[j].cardValue = deck[player2Pos3].value;
										deck[player2Pos3].num = 0;
										deck[player2Pos3].x = fPositions2[j].x;
										deck[player2Pos3].y = fPositions2[j].y;
										deck[player2Pos3].img.setPosition(fPositions2[j].x, fPositions2[j].y);
										player2Pos3 = 0;
										player2Cards--;
										roundPlayed = 1;
										break;
									}
								}
							}
							if (!(succesful))
							{
								deck[player2Pos3].drag = 0;
								deck[player2Pos3].img.setRotation(90.f);
							}
							break;
						case 4:
							succesful = 0;
							deck[player2Pos4].drag = 1;
							deck[player2Pos4].img.setRotation(180.f);
							for (int j = 0; j < 16; j++)
							{
								if (fPositions2[j].showPos == 1)
								{
									if (checkPlacedCards(j))
									{
										succesful = 1;
										deck[player2Pos4].drag = 0;
										deck[player2Pos4].img.setRotation(180.f);
										deck[player2Pos4].placed = 1;
										fPositions2[j].cardOnIt = 1;
										fPositions2[j].cardNum = deck[player2Pos4].num;
										fPositions2[j].cardValue = deck[player2Pos4].value;
										deck[player2Pos4].num = 0;
										deck[player2Pos4].x = fPositions2[j].x;
										deck[player2Pos4].y = fPositions2[j].y;
										deck[player2Pos4].img.setPosition(fPositions2[j].x, fPositions2[j].y);
										player2Pos4 = 0;
										player2Cards--;
										roundPlayed = 1;
										break;
									}
								}
							}
							if (!(succesful))
							{
								deck[player2Pos4].drag = 0;
								deck[player2Pos4].img.setRotation(90.f);
							}
							break;
						case 5:
							succesful = 0;
							deck[player2Pos5].drag = 1;
							deck[player2Pos5].img.setRotation(180.f);
							for (int j = 0; j < 16; j++)
							{
								if (fPositions2[j].showPos == 1)
								{
									if (checkPlacedCards(j))
									{
										succesful = 1;
										deck[player2Pos5].drag = 0;
										deck[player2Pos5].img.setRotation(180.f);
										deck[player2Pos5].placed = 1;
										fPositions2[j].cardOnIt = 1;
										fPositions2[j].cardNum = deck[player2Pos5].num;
										fPositions2[j].cardValue = deck[player2Pos5].value;
										deck[player2Pos5].num = 0;
										deck[player2Pos5].x = fPositions2[j].x;
										deck[player2Pos5].y = fPositions2[j].y;
										deck[player2Pos5].img.setPosition(fPositions2[j].x, fPositions2[j].y);
										player2Pos5 = 0;
										player2Cards--;
										roundPlayed = 1;
										break;
									}
								}
							}
							if (!(succesful))
							{
								deck[player2Pos5].drag = 0;
								deck[player2Pos5].img.setRotation(90.f);
							}
							break;
						}
						if (roundPlayed)
						{
							break;
						}
					}
				}
				if (roundPlayed == 0)
				{
					deck[player2Pos1].drag = 0;
					deck[player2Pos1].img.setRotation(90.f);
					deck[player2Pos1].placed = 1;
					deck[player2Pos1].num = 0;
					deck[counterCards3].type = deck[player2Pos1].type;
					deck[counterCards3].value = deck[player2Pos1].value;
					deck[counterCards3].num = counterCards3;
					deck[player2Pos1].type = 0;
					deck[player2Pos1].value = 0;
					deck[player2Pos1].player1pos = 0;
					deck[player2Pos1].display1 = 0;
					deck[player2Pos1].display2 = 0;
					counterCards3++;
					player2Pos1 = 0;
					player2Cards--;
					roundPlayed = 1;
				}
			}
			else
			{
				int randomCard = rand() % 5 + 1;
				switch (randomCard)
				{
				case 1:
					deck[player2Pos1].drag = 0;
					deck[player2Pos1].img.setRotation(90.f);
					deck[player2Pos1].placed = 1;
					deck[player2Pos1].num = 0;
					deck[counterCards3].type = deck[player2Pos1].type;
					deck[counterCards3].value = deck[player2Pos1].value;
					deck[counterCards3].num = counterCards3;
					deck[player2Pos1].type = 0;
					deck[player2Pos1].value = 0;
					deck[player2Pos1].player1pos = 0;
					deck[player2Pos1].display1 = 0;
					deck[player2Pos1].display2 = 0;
					counterCards3++;
					player2Pos1 = 0;
					player2Cards--;
					roundPlayed = 1;
					break;
				case 2:
					deck[player2Pos2].drag = 0;
					deck[player2Pos2].img.setRotation(90.f);
					deck[player2Pos2].placed = 1;
					deck[player2Pos2].num = 0;
					deck[counterCards3].type = deck[player2Pos2].type;
					deck[counterCards3].value = deck[player2Pos2].value;
					deck[counterCards3].num = counterCards3;
					deck[player2Pos2].type = 0;
					deck[player2Pos2].value = 0;
					deck[player2Pos2].player1pos = 0;
					deck[player2Pos2].display1 = 0;
					deck[player2Pos2].display2 = 0;
					counterCards3++;
					player2Pos2 = 0;
					player2Cards--;
					roundPlayed = 1;
					break;
				case 3:
					deck[player2Pos3].drag = 0;
					deck[player2Pos3].img.setRotation(90.f);
					deck[player2Pos3].placed = 1;
					deck[player2Pos3].num = 0;
					deck[counterCards3].type = deck[player2Pos3].type;
					deck[counterCards3].value = deck[player2Pos3].value;
					deck[counterCards3].num = counterCards3;
					deck[player2Pos3].type = 0;
					deck[player2Pos3].value = 0;
					deck[player2Pos3].player1pos = 0;
					deck[player2Pos3].display1 = 0;
					deck[player2Pos3].display2 = 0;
					counterCards3++;
					player2Pos3 = 0;
					player2Cards--;
					roundPlayed = 1;
					break;
				case 4:
					deck[player2Pos4].drag = 0;
					deck[player2Pos4].img.setRotation(90.f);
					deck[player2Pos4].placed = 1;
					deck[player2Pos4].num = 0;
					deck[counterCards3].type = deck[player2Pos4].type;
					deck[counterCards3].value = deck[player2Pos4].value;
					deck[counterCards3].num = counterCards3;
					deck[player2Pos4].type = 0;
					deck[player2Pos4].value = 0;
					deck[player2Pos4].player1pos = 0;
					deck[player2Pos4].display1 = 0;
					deck[player2Pos4].display2 = 0;
					counterCards3++;
					player2Pos4 = 0;
					player2Cards--;
					roundPlayed = 1;
					break;
				case 5:
					deck[player2Pos5].drag = 0;
					deck[player2Pos5].img.setRotation(90.f);
					deck[player2Pos5].placed = 1;
					deck[player2Pos5].num = 0;
					deck[counterCards3].type = deck[player2Pos5].type;
					deck[counterCards3].value = deck[player2Pos5].value;
					deck[counterCards3].num = counterCards3;
					deck[player2Pos5].type = 0;
					deck[player2Pos5].value = 0;
					deck[player2Pos5].player1pos = 0;
					deck[player2Pos5].display1 = 0;
					deck[player2Pos5].display2 = 0;
					counterCards3++;
					player2Pos5 = 0;
					player2Cards--;
					roundPlayed = 1;
					break;
				}
			}
		}
		for (int i = 1; i < 16; i++)
		{
			if (fPositions2[i].cardOnIt == 1)
			{
				deck[fPositions2[i].cardNum].img.setPosition(fPositions2[i].x + 120, fPositions2[i].y + 195);
				this->window->draw(deck[fPositions2[i].cardNum].img);
			}
		}
		setNotCardImages2(cursorpos);
		this->window->display();
		update(*this->window);
		if (win == 0)
		{
			if (roundPlayed)
			{
				transitionImg.setPosition(-2200, 0);
				sf::Time elapsed1 = clock.getElapsedTime();
				int timeCheck = int(elapsed1.asSeconds());
				int now = int(elapsed1.asSeconds());
				int x = -2200;

				while (now - timeCheck <= 1)
				{
					sf::Time elapsed1 = clock.getElapsedTime();
					now = int(elapsed1.asSeconds());
					setTimer();
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
					for (int i = 0; i < 6; i++)
					{
						if (notCardPos[i].cardOnIt == 1)
						{
							notCardPos[i].imgTexture.loadFromFile("assets/PlacedNotCard.png");
							notCardPos[i].img.setTexture(notCardPos[i].imgTexture);
							this->window->draw(notCardPos[i].img);
						}
					}
					tableOfTruth();
					setNotCardImages(cursorpos);
					for (int i = 1; i < 16; i++)
					{
						if (fPositions2[i].cardOnIt == 1)
						{
							this->window->draw(deck[fPositions2[i].cardNum].img);
						}
					}
					this->window->display();
				}
				while (true) // Transitions
				{
					this->window->clear();
					setTimer();
					if (x <= -315)
					{
						this->window->draw(this->backgroundSprite);
						this->window->draw(timer);
						this->window->draw(this->player2Text);
						this->window->draw(baseCards2[0].BaseCardImg);
						this->window->draw(baseCards2[1].BaseCardImg);
						this->window->draw(baseCards2[2].BaseCardImg);
						this->window->draw(baseCards2[3].BaseCardImg);
						this->window->draw(baseCards2[4].BaseCardImg);
						this->window->draw(baseCards2[5].BaseCardImg);
						for (int i = 0; i < 6; i++)
						{
							if (notCardPos[i].cardOnIt == 1)
							{
								notCardPos[i].imgTexture.loadFromFile("assets/PlacedNotCard.png");
								notCardPos[i].img.setTexture(notCardPos[i].imgTexture);
								this->window->draw(notCardPos[i].img);
							}
						}
						tableOfTruth();
						setNotCardImages(cursorpos);
						for (int i = 1; i < 16; i++)
						{
							if (fPositions2[i].cardOnIt == 1)
							{
								this->window->draw(deck[fPositions2[i].cardNum].img);
							}
						}
					}
					else
					{
						for (cardGet; player1Cards <= 5; player1Cards++, cardGet++)
						{
							deck[cardGet].player = 1;
						}
						cardsInHand();
						roundPlayed = 0;
						counter = 1;
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
						for (int i = 0; i < 6; i++)
						{
							if (notCardPos[i].cardOnIt == 1)
							{
								notCardPos[i].imgTexture.loadFromFile("assets/PlacedNotCard.png");
								notCardPos[i].img.setTexture(notCardPos[i].imgTexture);
								this->window->draw(notCardPos[i].img);
							}
						}
						tableOfTruth();
						setNotCardImages(cursorpos);
						for (int i = 1; i < 16; i++)
						{
							if (fPositions[i].cardOnIt == 1)
							{
								this->window->draw(deck[fPositions[i].cardNum].img);
							}
						}
					}
					if (x >= 1545)
					{
						break;
					}
					this->window->draw(transitionImg);
					transitionImg.setPosition(x, 0);
					x += 45;
					this->window->display();
				}
			}
		}
	}
	else
	{
		counter = 1;
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
		ss << min;
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

void Game::setPlay()
{
	// Loading and setting all the images
	this->backgroundTexture.loadFromFile("assets/GameField.png");
	this->backgroundSprite.setTexture(backgroundTexture);
	if (cosmosTheme)
	{
		this->backgroundTexture.loadFromFile("assets/cosmos/GameField.png");
		this->backgroundSprite.setTexture(backgroundTexture);
	}
	player1TextTexture.loadFromFile("assets/Player1Text.png");
	this->player1TextTexture.setSmooth(true);
	player1Text.setTexture(player1TextTexture);
	player1Text.setPosition(15, 12);
	if (cosmosTheme)
	{
		player1TextTexture.loadFromFile("assets/cosmos/Player1Text.png");
		player1Text.setTexture(player1TextTexture);
	}
	player2TextTexture.loadFromFile("assets/Player2Text.png");
	this->player2TextTexture.setSmooth(true);
	player2Text.setTexture(player2TextTexture);
	player2Text.setPosition(15, 12);
	if (cosmosTheme)
	{
		player2TextTexture.loadFromFile("assets/cosmos/Player2Text.png");
		player2Text.setTexture(player2TextTexture);
	}
	this->buttonTable.setSize(sf::Vector2f(114, 37));
	this->buttonTable.setPosition(1394, 191);
	this->buttonTable.setFillColor(sf::Color(80, 255, 0));
	tableHeaderTexture.loadFromFile("assets/AndtableHover.png");
	this->tableHeaderTexture.setSmooth(true);
	tableHeader.setTexture(tableHeaderTexture);
	tableHeader.setPosition(1394, 188);
	if (cosmosTheme)
	{
		tableHeaderTexture.loadFromFile("assets/cosmos/AndtableHover.png");
		tableHeader.setTexture(tableHeaderTexture);
	}
	tableHoverTexture.loadFromFile("assets/AndtableHeader.png");
	this->tableHoverTexture.setSmooth(true);
	tableHover.setTexture(tableHoverTexture);
	tableHover.setPosition(1394, 190);
	if (cosmosTheme)
	{
		tableHoverTexture.loadFromFile("assets/cosmos/AndtableHeader.png");
		tableHover.setTexture(tableHoverTexture);
	}
	transitionTexture.loadFromFile("assets/Transition.png");
	this->transitionTexture.setSmooth(true);
	transitionImg.setTexture(transitionTexture);
	transitionImg.setPosition(-2200, 0);
	if (cosmosTheme)
	{
		transitionTexture.loadFromFile("assets/cosmos/Transition.png");
		transitionImg.setTexture(transitionTexture);
	}
	timer.setFont(font);
	timer.setPosition(1386, 12);
	timer.setCharacterSize(51);
	timer.setFillColor(sf::Color(87, 87, 87));
	if (cosmosTheme)
	{
		timer.setFillColor(sf::Color(255, 255, 255));
	}
	pyramid1Texture.loadFromFile("assets/PyramidGround.png");
	this->pyramid1Texture.setSmooth(true);
	pyramid1Img.setTexture(pyramid1Texture);
	pyramid1Img.setPosition(0, 0);
	if (cosmosTheme)
	{
		pyramid1Texture.loadFromFile("assets/cosmos/PyramidGround.png");
		pyramid1Img.setTexture(pyramid1Texture);
	}
	pyramid2Texture.loadFromFile("assets/PyramidGround2.png");
	this->pyramid2Texture.setSmooth(true);
	pyramid2Img.setTexture(pyramid2Texture);
	pyramid2Img.setPosition(0, 0);
	if (cosmosTheme)
	{
		pyramid2Texture.loadFromFile("assets/cosmos/PyramidGround2.png");
		pyramid2Img.setTexture(pyramid2Texture);
	}
	resumeTexture.loadFromFile("assets/ResumeScreen.png");
	this->resumeTexture.setSmooth(true);
	resumeImg.setTexture(resumeTexture);
	resumeImg.setPosition(0, 0);
	pauseTexture.loadFromFile("assets/PauseScreen.png");
	this->pauseTexture.setSmooth(true);
	pauseImg.setTexture(pauseTexture);
	pauseImg.setPosition(0, 0);
	notCardPopTexture.loadFromFile("assets/NotCardPopUp.png");
	this->notCardPopTexture.setSmooth(true);
	notCardPop.setTexture(notCardPopTexture);
	notCardPop.setPosition(601, 311);


	if (gamemodeNum == 1) // Setting up the first gamemode
	{
		if (!(firstGamemode1))
		{
			while (true)
			{
				resume = 1;
				sf::Vector2i cursorpos = sf::Mouse::getPosition(*this->window);
				pollEvents();
				this->window->clear();
				if (counter == 1)
				{
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
					for (int i = 1; i < 16; i++)
					{
						if (fPositions[i].cardOnIt == 1)
						{
							this->window->draw(deck[fPositions[i].cardNum].img);
						}
					}
				}
				else if (counter == 2)
				{
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
					for (int i = 1; i < 16; i++)
					{
						if (fPositions2[i].cardOnIt == 1)
						{
							this->window->draw(deck[fPositions2[i].cardNum].img);
						}
					}
				}
				if (getMousePos(394, 403, 12, *this->window))
				{
					resumeTexture.loadFromFile("assets/ResumeHover1.png");
					resumeImg.setTexture(resumeTexture);
					if (cosmosTheme)
					{
						resumeTexture.loadFromFile("assets/cosmos/ResumeHover1.png");
						resumeImg.setTexture(resumeTexture);
					}
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						if (soundOn) clickSound.play();
						resume = 0;
						break;
					}
				}
				else if (getMousePos(804, 403, 12, *this->window))
				{
					resumeTexture.loadFromFile("assets/ResumeHover2.png");
					resumeImg.setTexture(resumeTexture);
					if (cosmosTheme)
					{
						resumeTexture.loadFromFile("assets/cosmos/ResumeHover2.png");
						resumeImg.setTexture(resumeTexture);
					}
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						if (soundOn) clickSound.play();
						resume = 0;
						deckI = 1;
						counter = 1;
						cardGet = 1;
						counterCards = 1;
						counterCards2 = 49;
						counterCards3 = 48;
						player1Cards = 0;
						player2Cards = 0;
						win = 0;
						showA = 0;
						showA2 = 0;
						roundPlayed = 0;
						card1Dragging = 0;
						card2Dragging = 0;
						card3Dragging = 0;
						card4Dragging = 0;
						card5Dragging = 0;
						card1Dragging2 = 0;
						card2Dragging2 = 0;
						card3Dragging2 = 0;
						card4Dragging2 = 0;
						card5Dragging2 = 0;
						player1Pos1 = 0;
						player1Pos2 = 0;
						player1Pos3 = 0;
						player1Pos4 = 0;
						player1Pos5 = 0;
						player2Pos1 = 0;
						player2Pos2 = 0;
						player2Pos3 = 0;
						player2Pos4 = 0;
						player2Pos5 = 0;
						for (int i = 0; i < 100; i++)
						{
							startDeck[i].num = 0;
							startDeck[i].value = 0;
							startDeck[i].type = 0;
							startDeck[i].display1 = 0;
							startDeck[i].display2 = 0;
							startDeck[i].player = 0;
							startDeck[i].secondNum = 0;
							startDeck[i].player1pos = 0;
							startDeck[i].player2pos = 0;
							startDeck[i].x = 0;
							startDeck[i].y = 0;
							startDeck[i].drag = 0;
							startDeck[i].placed = 0;
						}
						for (int i = 0; i < 150; i++)
						{
							deck[i].num = 0;
							deck[i].value = 0;
							deck[i].type = 0;
							deck[i].display1 = 0;
							deck[i].display2 = 0;
							deck[i].player = 0;
							deck[i].secondNum = 0;
							deck[i].player1pos = 0;
							deck[i].player2pos = 0;
							deck[i].x = 0;
							deck[i].y = 0;
							deck[i].drag = 0;
							deck[i].placed = 0;
						}
						for (int i = 0; i < 16; i++)
						{
							fPositions[i].cardNum = 0;
							fPositions[i].cardValue = 0;
							fPositions[i].showPos = 0;
							fPositions[i].cardOnIt = 0;
							fPositions[i].pos = 0;
							fPositions2[i].cardNum = 0;
							fPositions2[i].cardValue = 0;
							fPositions2[i].showPos = 0;
							fPositions2[i].cardOnIt = 0;
							fPositions2[i].pos = 0;
						}
						setDeck();
						setBaseCards();
						sortDeck();
						clock.restart();
						firstGamemode2 = 1;
						firstGamemode3 = 1;
						firstGamemode4 = 1;
						break;
					}
				}
				else
				{
					resumeTexture.loadFromFile("assets/ResumeScreen.png");
					resumeImg.setTexture(resumeTexture);
					if (cosmosTheme)
					{
						resumeTexture.loadFromFile("assets/cosmos/ResumeScreen.png");
						resumeImg.setTexture(resumeTexture);
					}
				}
				this->window->draw(resumeImg);
				this->window->display();
				if (breakResume)
				{
					breakResume = 0;
					break;
				}
			}
		}
		if (firstGamemode1)
		{
			resume = 0;
			counter = 1;
			deckI = 1;
			cardGet = 1;
			counterCards = 1;
			counterCards2 = 49;
			counterCards3 = 48;
			player1Cards = 0;
			player2Cards = 0;
			win = 0;
			showA = 0;
			showA2 = 0;
			roundPlayed = 0;
			card1Dragging = 0;
			card2Dragging = 0;
			card3Dragging = 0;
			card4Dragging = 0;
			card5Dragging = 0;
			card1Dragging2 = 0;
			card2Dragging2 = 0;
			card3Dragging2 = 0;
			card4Dragging2 = 0;
			card5Dragging2 = 0;
			player1Pos1 = 0;
			player1Pos2 = 0;
			player1Pos3 = 0;
			player1Pos4 = 0;
			player1Pos5 = 0;
			player2Pos1 = 0;
			player2Pos2 = 0;
			player2Pos3 = 0;
			player2Pos4 = 0;
			player2Pos5 = 0;
			for (int i = 0; i < 100; i++)
			{
				startDeck[i].num = 0;
				startDeck[i].value = 0;
				startDeck[i].type = 0;
				startDeck[i].display1 = 0;
				startDeck[i].display2 = 0;
				startDeck[i].player = 0;
				startDeck[i].secondNum = 0;
				startDeck[i].player1pos = 0;
				startDeck[i].player2pos = 0;
				startDeck[i].x = 0;
				startDeck[i].y = 0;
				startDeck[i].drag = 0;
				startDeck[i].placed = 0;
			}
			for (int i = 0; i < 150; i++)
			{
				deck[i].num = 0;
				deck[i].value = 0;
				deck[i].type = 0;
				deck[i].display1 = 0;
				deck[i].display2 = 0;
				deck[i].player = 0;
				deck[i].secondNum = 0;
				deck[i].player1pos = 0;
				deck[i].player2pos = 0;
				deck[i].x = 0;
				deck[i].y = 0;
				deck[i].drag = 0;
				deck[i].placed = 0;
			}
			for (int i = 0; i < 16; i++)
			{
				fPositions[i].cardNum = 0;
				fPositions[i].cardValue = 0;
				fPositions[i].showPos = 0;
				fPositions[i].cardOnIt = 0;
				fPositions[i].pos = 0;
				fPositions[i].x = 0;
				fPositions[i].y = 0;
				fPositions2[i].cardNum = 0;
				fPositions2[i].cardValue = 0;
				fPositions2[i].showPos = 0;
				fPositions2[i].cardOnIt = 0;
				fPositions2[i].pos = 0;
				fPositions2[i].x = 0;
				fPositions2[i].y = 0;
			}
			setDeck();
			setBaseCards();
			sortDeck();
			clock.restart();
			firstGamemode1 = 0;
			firstGamemode2 = 1;
			firstGamemode3 = 1;
			firstGamemode4 = 1;
		}
		setPlacingCards();
	}
	else if (gamemodeNum == 2) // Setting up the second gamemode
	{
		if (!(firstGamemode2))
		{
			while (true)
			{
				resume = 1;
				sf::Vector2i cursorpos = sf::Mouse::getPosition(*this->window);
				pollEvents();
				this->window->clear();
				if (counter == 1)
				{
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
					for (int i = 1; i < 16; i++)
					{
						if (fPositions[i].cardOnIt == 1)
						{
							this->window->draw(deck[fPositions[i].cardNum].img);
						}
					}
				}
				else if (counter == 2)
				{
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
					for (int i = 1; i < 16; i++)
					{
						if (fPositions2[i].cardOnIt == 1)
						{
							this->window->draw(deck[fPositions2[i].cardNum].img);
						}
					}
				}
				if (getMousePos(394, 403, 12, *this->window))
				{
					resumeTexture.loadFromFile("assets/ResumeHover1.png");
					resumeImg.setTexture(resumeTexture);
					if (cosmosTheme)
					{
						resumeTexture.loadFromFile("assets/cosmos/ResumeHover1.png");
						resumeImg.setTexture(resumeTexture);
					}
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						if (soundOn) clickSound.play();
						resume = 0;
						break;
					}
				}
				else if (getMousePos(804, 403, 12, *this->window))
				{
					resumeTexture.loadFromFile("assets/ResumeHover2.png");
					resumeImg.setTexture(resumeTexture);
					if (cosmosTheme)
					{
						pauseTexture.loadFromFile("assets/cosmos/ResumeHover2.png");
						pauseImg.setTexture(pauseTexture);
					}
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						if (soundOn) clickSound.play();
						resume = 0;
						deckI = 1;
						counter = 1;
						cardGet = 1;
						counterCards = 1;
						counterCards2 = 49;
						counterCards3 = 48;
						player1Cards = 0;
						player2Cards = 0;
						win = 0;
						showA = 0;
						showA2 = 0;
						roundPlayed = 0;
						card1Dragging = 0;
						card2Dragging = 0;
						card3Dragging = 0;
						card4Dragging = 0;
						card5Dragging = 0;
						card1Dragging2 = 0;
						card2Dragging2 = 0;
						card3Dragging2 = 0;
						card4Dragging2 = 0;
						card5Dragging2 = 0;
						player1Pos1 = 0;
						player1Pos2 = 0;
						player1Pos3 = 0;
						player1Pos4 = 0;
						player1Pos5 = 0;
						player2Pos1 = 0;
						player2Pos2 = 0;
						player2Pos3 = 0;
						player2Pos4 = 0;
						player2Pos5 = 0;
						for (int i = 0; i < 100; i++)
						{
							startDeck[i].num = 0;
							startDeck[i].value = 0;
							startDeck[i].type = 0;
							startDeck[i].display1 = 0;
							startDeck[i].display2 = 0;
							startDeck[i].player = 0;
							startDeck[i].secondNum = 0;
							startDeck[i].player1pos = 0;
							startDeck[i].player2pos = 0;
							startDeck[i].x = 0;
							startDeck[i].y = 0;
							startDeck[i].drag = 0;
							startDeck[i].placed = 0;
						}
						for (int i = 0; i < 150; i++)
						{
							deck[i].num = 0;
							deck[i].value = 0;
							deck[i].type = 0;
							deck[i].display1 = 0;
							deck[i].display2 = 0;
							deck[i].player = 0;
							deck[i].secondNum = 0;
							deck[i].player1pos = 0;
							deck[i].player2pos = 0;
							deck[i].x = 0;
							deck[i].y = 0;
							deck[i].drag = 0;
							deck[i].placed = 0;
						}
						for (int i = 0; i < 16; i++)
						{
							fPositions[i].cardNum = 0;
							fPositions[i].cardValue = 0;
							fPositions[i].showPos = 0;
							fPositions[i].cardOnIt = 0;
							fPositions[i].pos = 0;
							fPositions2[i].cardNum = 0;
							fPositions2[i].cardValue = 0;
							fPositions2[i].showPos = 0;
							fPositions2[i].cardOnIt = 0;
							fPositions2[i].pos = 0;
						}
						setDeck();
						setBaseCards();
						sortDeck();
						clock.restart();
						firstGamemode1 = 1;
						firstGamemode3 = 1;
						firstGamemode4 = 1;
						break;
					}
				}
				else
				{
					resumeTexture.loadFromFile("assets/ResumeScreen.png");
					resumeImg.setTexture(resumeTexture);
					if (cosmosTheme)
					{
						resumeTexture.loadFromFile("assets/cosmos/ResumeScreen.png");
						resumeImg.setTexture(resumeTexture);
					}
				}
				this->window->draw(resumeImg);
				this->window->display();
				if (breakResume)
				{
					breakResume = 0;
					break;
				}
			}
		}
		if (firstGamemode2)
		{
			resume = 0;
			counter = 1;
			deckI = 1;
			cardGet = 1;
			counterCards = 1;
			counterCards2 = 49;
			counterCards3 = 48;
			player1Cards = 0;
			player2Cards = 0;
			win = 0;
			showA = 0;
			showA2 = 0;
			roundPlayed = 0;
			card1Dragging = 0;
			card2Dragging = 0;
			card3Dragging = 0;
			card4Dragging = 0;
			card5Dragging = 0;
			card1Dragging2 = 0;
			card2Dragging2 = 0;
			card3Dragging2 = 0;
			card4Dragging2 = 0;
			card5Dragging2 = 0;
			player1Pos1 = 0;
			player1Pos2 = 0;
			player1Pos3 = 0;
			player1Pos4 = 0;
			player1Pos5 = 0;
			player2Pos1 = 0;
			player2Pos2 = 0;
			player2Pos3 = 0;
			player2Pos4 = 0;
			player2Pos5 = 0;
			for (int i = 0; i < 100; i++)
			{
				startDeck[i].num = 0;
				startDeck[i].value = 0;
				startDeck[i].type = 0;
				startDeck[i].display1 = 0;
				startDeck[i].display2 = 0;
				startDeck[i].player = 0;
				startDeck[i].secondNum = 0;
				startDeck[i].player1pos = 0;
				startDeck[i].player2pos = 0;
				startDeck[i].x = 0;
				startDeck[i].y = 0;
				startDeck[i].drag = 0;
				startDeck[i].placed = 0;
			}
			for (int i = 0; i < 150; i++)
			{
				deck[i].num = 0;
				deck[i].value = 0;
				deck[i].type = 0;
				deck[i].display1 = 0;
				deck[i].display2 = 0;
				deck[i].player = 0;
				deck[i].secondNum = 0;
				deck[i].player1pos = 0;
				deck[i].player2pos = 0;
				deck[i].x = 0;
				deck[i].y = 0;
				deck[i].drag = 0;
				deck[i].placed = 0;
			}
			for (int i = 0; i < 16; i++)
			{
				fPositions[i].cardNum = 0;
				fPositions[i].cardValue = 0;
				fPositions[i].showPos = 0;
				fPositions[i].cardOnIt = 0;
				fPositions[i].pos = 0;
				fPositions[i].x = 0;
				fPositions[i].y = 0;
				fPositions2[i].cardNum = 0;
				fPositions2[i].cardValue = 0;
				fPositions2[i].showPos = 0;
				fPositions2[i].cardOnIt = 0;
				fPositions2[i].pos = 0;
				fPositions2[i].x = 0;
				fPositions2[i].y = 0;
			}
			setDeck();
			setBaseCards();
			sortDeck();
			clock.restart();
			firstGamemode2 = 0;
			firstGamemode1 = 1;
			firstGamemode3 = 1;
			firstGamemode4 = 1;
		}
		setPlacingCards();
	}
	else if (gamemodeNum == 3) // Setting up the third gamemode
	{
		if (!(firstGamemode3))
		{
			while (true)
			{
				resume = 1;
				sf::Vector2i cursorpos = sf::Mouse::getPosition(*this->window);
				pollEvents();
				this->window->clear();
				if (counter == 1)
				{
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
					for (int i = 1; i < 16; i++)
					{
						if (fPositions[i].cardOnIt == 1)
						{
							this->window->draw(deck[fPositions[i].cardNum].img);
						}
					}
				}
				else if (counter == 2)
				{
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
					for (int i = 1; i < 16; i++)
					{
						if (fPositions2[i].cardOnIt == 1)
						{
							this->window->draw(deck[fPositions2[i].cardNum].img);
						}
					}
				}
				if (getMousePos(394, 403, 12, *this->window))
				{
					resumeTexture.loadFromFile("assets/ResumeHover1.png");
					resumeImg.setTexture(resumeTexture);
					if (cosmosTheme)
					{
						resumeTexture.loadFromFile("assets/cosmos/ResumeHover1.png");
						resumeImg.setTexture(resumeTexture);
					}
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						if (soundOn) clickSound.play();
						resume = 0;
						break;
					}
				}
				else if (getMousePos(804, 403, 12, *this->window))
				{
					resumeTexture.loadFromFile("assets/ResumeHover2.png");
					resumeImg.setTexture(resumeTexture);
					if (cosmosTheme)
					{
						resumeTexture.loadFromFile("assets/cosmos/ResumeHover2.png");
						resumeImg.setTexture(resumeTexture);
					}
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						if (soundOn) clickSound.play();
						resume = 0;
						deckI = 1;
						counter = 1;
						cardGet = 1;
						counterCards = 1;
						counterCards2 = 49;
						counterCards3 = 48;
						player1Cards = 0;
						player2Cards = 0;
						win = 0;
						showA = 0;
						showA2 = 0;
						roundPlayed = 0;
						card1Dragging = 0;
						card2Dragging = 0;
						card3Dragging = 0;
						card4Dragging = 0;
						card5Dragging = 0;
						card1Dragging2 = 0;
						card2Dragging2 = 0;
						card3Dragging2 = 0;
						card4Dragging2 = 0;
						card5Dragging2 = 0;
						player1Pos1 = 0;
						player1Pos2 = 0;
						player1Pos3 = 0;
						player1Pos4 = 0;
						player1Pos5 = 0;
						player2Pos1 = 0;
						player2Pos2 = 0;
						player2Pos3 = 0;
						player2Pos4 = 0;
						player2Pos5 = 0;
						for (int i = 0; i < 100; i++)
						{
							startDeck[i].num = 0;
							startDeck[i].value = 0;
							startDeck[i].type = 0;
							startDeck[i].display1 = 0;
							startDeck[i].display2 = 0;
							startDeck[i].player = 0;
							startDeck[i].secondNum = 0;
							startDeck[i].player1pos = 0;
							startDeck[i].player2pos = 0;
							startDeck[i].x = 0;
							startDeck[i].y = 0;
							startDeck[i].drag = 0;
							startDeck[i].placed = 0;
						}
						for (int i = 0; i < 150; i++)
						{
							deck[i].num = 0;
							deck[i].value = 0;
							deck[i].type = 0;
							deck[i].display1 = 0;
							deck[i].display2 = 0;
							deck[i].player = 0;
							deck[i].secondNum = 0;
							deck[i].player1pos = 0;
							deck[i].player2pos = 0;
							deck[i].x = 0;
							deck[i].y = 0;
							deck[i].drag = 0;
							deck[i].placed = 0;
						}
						for (int i = 0; i < 16; i++)
						{
							fPositions[i].cardNum = 0;
							fPositions[i].cardValue = 0;
							fPositions[i].showPos = 0;
							fPositions[i].cardOnIt = 0;
							fPositions[i].pos = 0;
							fPositions2[i].cardNum = 0;
							fPositions2[i].cardValue = 0;
							fPositions2[i].showPos = 0;
							fPositions2[i].cardOnIt = 0;
							fPositions2[i].pos = 0;
						}
						for (int i = 0; i < 6; i++)
						{
							notCardPos[i].cardNum = 0;
							notCardPos[i].cardValue = 0;
							notCardPos[i].showPos = 0;
							notCardPos[i].cardOnIt = 0;
							notCardPos[i].pos = 0;

						}
						setNotDeck();
						setBaseCards();
						sortNotDeck();
						clock.restart();
						firstGamemode1 = 1;
						firstGamemode2 = 1;
						firstGamemode4 = 1;
						break;
					}
				}
				else
				{
					resumeTexture.loadFromFile("assets/ResumeScreen.png");
					resumeImg.setTexture(resumeTexture);
					if (cosmosTheme)
					{
						resumeTexture.loadFromFile("assets/cosmos/ResumeScreen.png");
						resumeImg.setTexture(resumeTexture);
					}
				}
				this->window->draw(resumeImg);
				this->window->display();
				if (breakResume)
				{
					breakResume = 0;
					break;
				}
			}
		}
		if (firstGamemode3)
		{
			resume = 0;
			counter = 1;
			deckI = 1;
			cardGet = 1;
			counterCards = 1;
			counterCards2 = 49;
			counterCards3 = 48;
			player1Cards = 0;
			player2Cards = 0;
			win = 0;
			showA = 0;
			showA2 = 0;
			roundPlayed = 0;
			card1Dragging = 0;
			card2Dragging = 0;
			card3Dragging = 0;
			card4Dragging = 0;
			card5Dragging = 0;
			card1Dragging2 = 0;
			card2Dragging2 = 0;
			card3Dragging2 = 0;
			card4Dragging2 = 0;
			card5Dragging2 = 0;
			player1Pos1 = 0;
			player1Pos2 = 0;
			player1Pos3 = 0;
			player1Pos4 = 0;
			player1Pos5 = 0;
			player2Pos1 = 0;
			player2Pos2 = 0;
			player2Pos3 = 0;
			player2Pos4 = 0;
			player2Pos5 = 0;
			for (int i = 0; i < 100; i++)
			{
				startDeck[i].num = 0;
				startDeck[i].value = 0;
				startDeck[i].type = 0;
				startDeck[i].display1 = 0;
				startDeck[i].display2 = 0;
				startDeck[i].player = 0;
				startDeck[i].secondNum = 0;
				startDeck[i].player1pos = 0;
				startDeck[i].player2pos = 0;
				startDeck[i].x = 0;
				startDeck[i].y = 0;
				startDeck[i].drag = 0;
				startDeck[i].placed = 0;
			}
			for (int i = 0; i < 150; i++)
			{
				deck[i].num = 0;
				deck[i].value = 0;
				deck[i].type = 0;
				deck[i].display1 = 0;
				deck[i].display2 = 0;
				deck[i].player = 0;
				deck[i].secondNum = 0;
				deck[i].player1pos = 0;
				deck[i].player2pos = 0;
				deck[i].x = 0;
				deck[i].y = 0;
				deck[i].drag = 0;
				deck[i].placed = 0;
			}
			for (int i = 0; i < 16; i++)
			{
				fPositions[i].cardNum = 0;
				fPositions[i].cardValue = 0;
				fPositions[i].showPos = 0;
				fPositions[i].cardOnIt = 0;
				fPositions[i].pos = 0;
				fPositions[i].x = 0;
				fPositions[i].y = 0;
				fPositions2[i].cardNum = 0;
				fPositions2[i].cardValue = 0;
				fPositions2[i].showPos = 0;
				fPositions2[i].cardOnIt = 0;
				fPositions2[i].pos = 0;
				fPositions2[i].x = 0;
				fPositions2[i].y = 0;
			}
			for (int i = 0; i < 6; i++)
			{
				notCardPos[i].cardNum = 0;
				notCardPos[i].cardValue = 0;
				notCardPos[i].showPos = 0;
				notCardPos[i].cardOnIt = 0;
				notCardPos[i].pos = 0;
			}
			setBaseCards();
			setNotDeck();
			sortNotDeck();
			clock.restart();
			firstGamemode1 = 1;
			firstGamemode2 = 1;
			firstGamemode3 = 0;
			firstGamemode4 = 1;
		}
		setPlacingCards();
		for (int i = 0; i < 6; i++)
		{
			notCardPos[i].pos = i;
		}
		for (int i = 0; i < 6; i++)
		{
			notCardPos[i].imgTexture.loadFromFile("assets/NotCardPos.png");
			notCardPos[i].imgTexture.setSmooth(true);
			notCardPos[i].img.setTexture(notCardPos[i].imgTexture);
			switch (notCardPos[i].pos)
			{
			case 0:
				notCardPos[i].img.setPosition(322, -13);
				notCardPos[i].x = 322;
				notCardPos[i].y = -13;
				break;
			case 1:
				notCardPos[i].img.setPosition(485, -13);
				notCardPos[i].x = 485;
				notCardPos[i].y = -13;
				break;
			case 2:
				notCardPos[i].img.setPosition(648, -13);
				notCardPos[i].x = 648;
				notCardPos[i].y = -13;
				break;
			case 3:
				notCardPos[i].img.setPosition(811, -13);
				notCardPos[i].x = 811;
				notCardPos[i].y = -13;
				break;
			case 4:
				notCardPos[i].img.setPosition(974, -13);
				notCardPos[i].x = 974;
				notCardPos[i].y = -13;
				break;
			case 5:
				notCardPos[i].img.setPosition(1135, -13);
				notCardPos[i].x = 1135;
				notCardPos[i].y = -13;
				break;
			}
		}
	}
	else if (gamemodeNum == 4) // Setting up the fourth gamemode
	{
	if (!(firstGamemode4))
	{
		while (true)
		{
			resume = 1;
			sf::Vector2i cursorpos = sf::Mouse::getPosition(*this->window);
			pollEvents();
			this->window->clear();
			if (counter == 1)
			{
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
				for (int i = 1; i < 16; i++)
				{
					if (fPositions[i].cardOnIt == 1)
					{
						this->window->draw(deck[fPositions[i].cardNum].img);
					}
				}
			}
			if (getMousePos(394, 403, 12, *this->window))
			{
				resumeTexture.loadFromFile("assets/ResumeHover1.png");
				resumeImg.setTexture(resumeTexture);
				if (cosmosTheme)
				{
					resumeTexture.loadFromFile("assets/cosmos/ResumeHover1.png");
					resumeImg.setTexture(resumeTexture);
				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					if (soundOn) clickSound.play();
					resume = 0;
					break;
				}
			}
			else if (getMousePos(804, 403, 12, *this->window))
			{
				resumeTexture.loadFromFile("assets/ResumeHover2.png");
				resumeImg.setTexture(resumeTexture);
				if (cosmosTheme)
				{
					resumeTexture.loadFromFile("assets/cosmos/ResumeHover2.png");
					resumeImg.setTexture(resumeTexture);
				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					if (soundOn) clickSound.play();
					resume = 0;
					deckI = 1;
					counter = 1;
					cardGet = 1;
					counterCards = 1;
					counterCards2 = 49;
					counterCards3 = 48;
					player1Cards = 0;
					player2Cards = 0;
					win = 0;
					showA = 0;
					showA2 = 0;
					roundPlayed = 0;
					card1Dragging = 0;
					card2Dragging = 0;
					card3Dragging = 0;
					card4Dragging = 0;
					card5Dragging = 0;
					card1Dragging2 = 0;
					card2Dragging2 = 0;
					card3Dragging2 = 0;
					card4Dragging2 = 0;
					card5Dragging2 = 0;
					player1Pos1 = 0;
					player1Pos2 = 0;
					player1Pos3 = 0;
					player1Pos4 = 0;
					player1Pos5 = 0;
					player2Pos1 = 0;
					player2Pos2 = 0;
					player2Pos3 = 0;
					player2Pos4 = 0;
					player2Pos5 = 0;
					for (int i = 0; i < 100; i++)
					{
						startDeck[i].num = 0;
						startDeck[i].value = 0;
						startDeck[i].type = 0;
						startDeck[i].display1 = 0;
						startDeck[i].display2 = 0;
						startDeck[i].player = 0;
						startDeck[i].secondNum = 0;
						startDeck[i].player1pos = 0;
						startDeck[i].player2pos = 0;
						startDeck[i].x = 0;
						startDeck[i].y = 0;
						startDeck[i].drag = 0;
						startDeck[i].placed = 0;
					}
					for (int i = 0; i < 150; i++)
					{
						deck[i].num = 0;
						deck[i].value = 0;
						deck[i].type = 0;
						deck[i].display1 = 0;
						deck[i].display2 = 0;
						deck[i].player = 0;
						deck[i].secondNum = 0;
						deck[i].player1pos = 0;
						deck[i].player2pos = 0;
						deck[i].x = 0;
						deck[i].y = 0;
						deck[i].drag = 0;
						deck[i].placed = 0;
					}
					for (int i = 0; i < 16; i++)
					{
						fPositions[i].cardNum = 0;
						fPositions[i].cardValue = 0;
						fPositions[i].showPos = 0;
						fPositions[i].cardOnIt = 0;
						fPositions[i].pos = 0;
						fPositions2[i].cardNum = 0;
						fPositions2[i].cardValue = 0;
						fPositions2[i].showPos = 0;
						fPositions2[i].cardOnIt = 0;
						fPositions2[i].pos = 0;
					}
					for (int i = 0; i < 6; i++)
					{
						notCardPos[i].cardNum = 0;
						notCardPos[i].cardValue = 0;
						notCardPos[i].showPos = 0;
						notCardPos[i].cardOnIt = 0;
						notCardPos[i].pos = 0;
					}
					setNotDeck();
					setBaseCards();
					sortNotDeck();
					clock.restart();
					firstGamemode1 = 1;
					firstGamemode2 = 1;
					firstGamemode3 = 1;
					break;
				}
			}
			else
			{
				resumeTexture.loadFromFile("assets/ResumeScreen.png");
				resumeImg.setTexture(resumeTexture);
				if (cosmosTheme)
				{
					resumeTexture.loadFromFile("assets/cosmos/ResumeScreen.png");
					resumeImg.setTexture(resumeTexture);
				}
			}
			this->window->draw(resumeImg);
			this->window->display();
			if (breakResume)
			{
				breakResume = 0;
				break;
			}
		}
	}
	if (firstGamemode4)
	{
		resume = 0;
		counter = 1;
		deckI = 1;
		cardGet = 1;
		counterCards = 1;
		counterCards2 = 49;
		counterCards3 = 48;
		player1Cards = 0;
		player2Cards = 0;
		win = 0;
		showA = 0;
		showA2 = 0;
		roundPlayed = 0;
		card1Dragging = 0;
		card2Dragging = 0;
		card3Dragging = 0;
		card4Dragging = 0;
		card5Dragging = 0;
		card1Dragging2 = 0;
		card2Dragging2 = 0;
		card3Dragging2 = 0;
		card4Dragging2 = 0;
		card5Dragging2 = 0;
		player1Pos1 = 0;
		player1Pos2 = 0;
		player1Pos3 = 0;
		player1Pos4 = 0;
		player1Pos5 = 0;
		player2Pos1 = 0;
		player2Pos2 = 0;
		player2Pos3 = 0;
		player2Pos4 = 0;
		player2Pos5 = 0;
		for (int i = 0; i < 100; i++)
		{
			startDeck[i].num = 0;
			startDeck[i].value = 0;
			startDeck[i].type = 0;
			startDeck[i].display1 = 0;
			startDeck[i].display2 = 0;
			startDeck[i].player = 0;
			startDeck[i].secondNum = 0;
			startDeck[i].player1pos = 0;
			startDeck[i].player2pos = 0;
			startDeck[i].x = 0;
			startDeck[i].y = 0;
			startDeck[i].drag = 0;
			startDeck[i].placed = 0;
		}
		for (int i = 0; i < 150; i++)
		{
			deck[i].num = 0;
			deck[i].value = 0;
			deck[i].type = 0;
			deck[i].display1 = 0;
			deck[i].display2 = 0;
			deck[i].player = 0;
			deck[i].secondNum = 0;
			deck[i].player1pos = 0;
			deck[i].player2pos = 0;
			deck[i].x = 0;
			deck[i].y = 0;
			deck[i].drag = 0;
			deck[i].placed = 0;
		}
		for (int i = 0; i < 16; i++)
		{
			fPositions[i].cardNum = 0;
			fPositions[i].cardValue = 0;
			fPositions[i].showPos = 0;
			fPositions[i].cardOnIt = 0;
			fPositions[i].pos = 0;
			fPositions[i].x = 0;
			fPositions[i].y = 0;
			fPositions2[i].cardNum = 0;
			fPositions2[i].cardValue = 0;
			fPositions2[i].showPos = 0;
			fPositions2[i].cardOnIt = 0;
			fPositions2[i].pos = 0;
			fPositions2[i].x = 0;
			fPositions2[i].y = 0;
		}
		for (int i = 0; i < 6; i++)
		{
			notCardPos[i].cardNum = 0;
			notCardPos[i].cardValue = 0;
			notCardPos[i].showPos = 0;
			notCardPos[i].cardOnIt = 0;
			notCardPos[i].pos = 0;
		}
		setBaseCards();
		setNotDeck();
		sortNotDeck();
		clock.restart();
		firstGamemode1 = 1;
		firstGamemode2 = 1;
		firstGamemode3 = 1;
		firstGamemode4 = 0;
	}
	setPlacingCards();
	for (int i = 0; i < 6; i++)
	{
		notCardPos[i].pos = i;
	}
	for (int i = 0; i < 6; i++)
	{
		notCardPos[i].imgTexture.loadFromFile("assets/NotCardPos.png");
		notCardPos[i].imgTexture.setSmooth(true);
		notCardPos[i].img.setTexture(notCardPos[i].imgTexture);
		switch (notCardPos[i].pos)
		{
		case 0:
			notCardPos[i].img.setPosition(322, -13);
			notCardPos[i].x = 322;
			notCardPos[i].y = -13;
			break;
		case 1:
			notCardPos[i].img.setPosition(485, -13);
			notCardPos[i].x = 485;
			notCardPos[i].y = -13;
			break;
		case 2:
			notCardPos[i].img.setPosition(648, -13);
			notCardPos[i].x = 648;
			notCardPos[i].y = -13;
			break;
		case 3:
			notCardPos[i].img.setPosition(811, -13);
			notCardPos[i].x = 811;
			notCardPos[i].y = -13;
			break;
		case 4:
			notCardPos[i].img.setPosition(974, -13);
			notCardPos[i].x = 974;
			notCardPos[i].y = -13;
			break;
		case 5:
			notCardPos[i].img.setPosition(1135, -13);
			notCardPos[i].x = 1135;
			notCardPos[i].y = -13;
			break;
		}
	}
	}


	for (int i = 0; i < 6; i++)
	{
		if (baseCards[i].value == 0)
		{
			baseCards[i].BaseCardImgTexture.loadFromFile("assets/BaseCard0.png");
			baseCards[i].BaseCardImgTexture.setSmooth(true);
			baseCards[i].BaseCardImg.setTexture(baseCards[i].BaseCardImgTexture);
			if (cosmosTheme)
			{
				baseCards[i].BaseCardImgTexture.loadFromFile("assets/cosmos/BaseCard0.png");
				baseCards[i].BaseCardImg.setTexture(baseCards[i].BaseCardImgTexture);
			}
			baseCards2[i].BaseCardImgTexture.loadFromFile("assets/BaseCard1.png");
			baseCards2[i].BaseCardImgTexture.setSmooth(true);
			baseCards2[i].BaseCardImg.setTexture(baseCards2[i].BaseCardImgTexture);
			if (cosmosTheme)
			{
				baseCards2[i].BaseCardImgTexture.loadFromFile("assets/cosmos/BaseCard1.png");
				baseCards2[i].BaseCardImg.setTexture(baseCards2[i].BaseCardImgTexture);
			}
		}
		else
		{
			baseCards[i].BaseCardImgTexture.loadFromFile("assets/BaseCard1.png");
			baseCards[i].BaseCardImgTexture.setSmooth(true);
			baseCards[i].BaseCardImg.setTexture(baseCards[i].BaseCardImgTexture);
			if (cosmosTheme)
			{
				baseCards[i].BaseCardImgTexture.loadFromFile("assets/cosmos/BaseCard1.png");
				baseCards[i].BaseCardImg.setTexture(baseCards[i].BaseCardImgTexture);
			}
			baseCards2[i].BaseCardImgTexture.loadFromFile("assets/BaseCard0.png");
			baseCards2[i].BaseCardImgTexture.setSmooth(true);
			baseCards2[i].BaseCardImg.setTexture(baseCards2[i].BaseCardImgTexture);
			if (cosmosTheme)
			{
				baseCards2[i].BaseCardImgTexture.loadFromFile("assets/cosmos/BaseCard0.png");
				baseCards2[i].BaseCardImg.setTexture(baseCards2[i].BaseCardImgTexture);
			}
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

void Game::setReady()
{
	this->window->setPosition(sf::Vector2i(190, 80));
	specialButtonTexture.loadFromFile("assets/SpecialButton1.png");
	specialButtonTexture.setSmooth(true);
	specialButtonImg.setTexture(specialButtonTexture);
	specialButtonImg.setPosition(463, 549);
	font.loadFromFile("assets/tex-gyre-adventor.bold.otf");
	if (!buffer.loadFromFile("assets/ClickSoundEffect.wav"))
	{
	}
	clickSound.setBuffer(buffer);
	soundTexture.loadFromFile("assets/SoundIcon1.png");
	soundTexture.setSmooth(true);
	soundImg.setTexture(soundTexture);
	soundImg.setPosition(487, 404);
	musicTexture.loadFromFile("assets/MusicIcon1.png");
	musicTexture.setSmooth(true);
	musicImg.setTexture(musicTexture);
	musicImg.setPosition(487, 251);
	setTheIcon();
	customCursor();
}

void Game::localIn()
{
	// Local storage reading:
	std::string text;
	int scounter = 0;

	std::ifstream storageFileIn;
	storageFileIn.open("localStorage.txt");
	while (getline(storageFileIn, text))
	{
		switch (scounter)
		{
		case 0:
			std::istringstream(text) >> soundOn;
			break;
		case 1:
			std::istringstream(text) >> musicOn;
			break;
		case 2:
			specialButtonC = stoi(text);
			break;
		case 3:
			specialCounter = stoi(text);
			break;
		case 4:
			tableNum = stoi(text);
			break;
		case 5:
			std::istringstream(text) >> cosmosTheme;
			break;
		case 6:
			winGamemode1 = stoi(text);
			break;
		case 7:
			winGamemode2 = stoi(text);
			break;
		case 8:
			winGamemode3 = stoi(text);
			break;
		case 9:
			winGamemode4 = stoi(text);
			break;
		}
		scounter++;
	}

	storageFileIn.close();

	if (soundOn)
	{
		soundTexture.loadFromFile("assets/SoundIcon1.png");
		soundImg.setTexture(soundTexture);
	}
	else
	{
		soundTexture.loadFromFile("assets/SoundIcon2.png");
		soundImg.setTexture(soundTexture);
	}
	if (musicOn)
	{
		musicTexture.loadFromFile("assets/MusicIcon1.png");
		musicImg.setTexture(musicTexture);
	}
	else
	{
		musicTexture.loadFromFile("assets/MusicIcon2.png");
		musicImg.setTexture(musicTexture);
	}
}

void Game::localOut()
{
	std::ofstream storageFileOut;
	storageFileOut.open("localStorage.txt");

	storageFileOut << soundOn << std::endl;
	storageFileOut << musicOn << std::endl;
	storageFileOut << specialButtonC << std::endl;
	storageFileOut << specialCounter << std::endl;
	storageFileOut << tableNum << std::endl;
	storageFileOut << cosmosTheme << std::endl;
	storageFileOut << winGamemode1 << std::endl;
	storageFileOut << winGamemode2 << std::endl;
	storageFileOut << winGamemode3 << std::endl;
	storageFileOut << winGamemode4 << std::endl;

	storageFileOut.close();
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
	localIn();

	while (running())
	{
		sf::Vector2i cursorpos = sf::Mouse::getPosition(*this->window);

		if (ready) // Play
		{
			if (gamemodeNum == 1)
			{
				firstGamemode(*this->window);
			}
			else if (gamemodeNum == 2)
			{
				secondGamemode(*this->window);
			}
			else if (gamemodeNum == 3)
			{
				thirdGamemode(*this->window);
			}
			else if (gamemodeNum == 4)
			{
				fourthGamemode(*this->window);
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
		else if (options) // Options
		{
			optionsMenu(*this->window);
		}
		else if (win != 0)
		{
			pollEvents();
			winScreen(*this->window);
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
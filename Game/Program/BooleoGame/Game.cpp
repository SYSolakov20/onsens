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

void Game::update()
{
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
			gameMode = 1;
			modesButtons();
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
			ready = 1;
			gamemodeNum = 1;
			this->backgroundTexture.loadFromFile("assets/GameField.png");
			this->backgroundSprite.setTexture(backgroundTexture);
		}
	}
	else if (getMousePos(445, 170, 2, newWindow)) // Second mode:
	{
		this->backgroundTexture.loadFromFile("assets/HoverMode2.png");
		this->backgroundSprite.setTexture(backgroundTexture);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			ready = 1;
			gamemodeNum = 2;
		}
	}
	else if (getMousePos(795, 170, 2, newWindow)) // Third mode:
	{
		this->backgroundTexture.loadFromFile("assets/HoverMode3.png");
		this->backgroundSprite.setTexture(backgroundTexture);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			ready = 1;
			gamemodeNum = 3;
		}
	}
	else if (getMousePos(1145, 170, 2, newWindow)) // Fourth mode:
	{
		this->backgroundTexture.loadFromFile("assets/HoverMode4.png");
		this->backgroundSprite.setTexture(backgroundTexture);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			ready = 1;
			gamemodeNum = 4;
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

void Game::setTheIcon()
{
	this->icon.loadFromFile("assets/Icon.png");
	this->window->setIcon(77, 77, icon.getPixelsPtr());
}

void Game::customCursor()
{
	sf::Image cursorImg;
	cursorImg.loadFromFile("assets/Cursor.png");
	this->cursor.loadFromPixels(cursorImg.getPixelsPtr(), cursorImg.getSize(), sf::Vector2u(0, 0));
	this->window->setMouseCursor(cursor);
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










				update();
				render();
			}
			else if (gamemodeNum == 2)
			{
				this->backgroundTexture.loadFromFile("assets/Play.png");
				this->backgroundSprite.setTexture(backgroundTexture);
				update();
				render();
			}
			else if (gamemodeNum == 3)
			{
				this->backgroundTexture.loadFromFile("assets/Play.png");
				this->backgroundSprite.setTexture(backgroundTexture);
				update();
				render();
			}
			else if (gamemodeNum == 4)
			{
				this->backgroundTexture.loadFromFile("assets/Play.png");
				this->backgroundSprite.setTexture(backgroundTexture);
				update();
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
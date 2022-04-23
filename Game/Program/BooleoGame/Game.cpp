#include "game.h"


void game::init_window()
{
	this->window = new sf::RenderWindow(sf::VideoMode(window_w, window_h), "Booleo", sf::Style::Close);
	this->window->setFramerateLimit(80);
}

int game::randomNum(int n)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(0, n);
	return dis(gen);
}

bool game::running()
{
	return this->window->isOpen();
}

void game::pollEvents()
{
	while (this->window->pollEvent(this->sfmlEvent))
	{
		switch (this->sfmlEvent.type)
		{
		case sf::Event::Closed:
			this->window->close();

		case sf::Event::KeyPressed:
			if (this->sfmlEvent.key.code == sf::Keyboard::Escape)
			{
				this->window->close();
			}
			break;
		}
	}
}

void game::setBackground()
{
	sf::Image backgroundImg;
	backgroundImg.loadFromFile("assets/menu.png");
	this->backgroundTexture.loadFromFile("assets/menu.png");
	this->backgroundSprite.setTexture(backgroundTexture);
}


void game::render()
{
	this->window->clear();
	this->window->draw(this->backgroundSprite);
	this->window->display();
}

void game::update()
{
	pollEvents();
}

sf::Window newWindow(sf::VideoMode(1545, 810), "", sf::Style::Close);

bool game::getMousePos(float x, float y, int a)
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
	}
	return 0;
}

void game::posWindow()
{
	newWindow.setVisible(false);
	newWindow.setPosition(sf::Vector2i(190, 80));
}

void game::menu()
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

void game::setTheIcon()
{
	this->icon.loadFromFile("assets/Icon.png");
	this->window->setIcon(77, 77, icon.getPixelsPtr());
}

void game::customCursor()
{
	sf::Image cursorImg;
	cursorImg.loadFromFile("assets/Cursor.png");
	this->cursor.loadFromPixels(cursorImg.getPixelsPtr(), cursorImg.getSize(), sf::Vector2u(0, 0));
	this->window->setMouseCursor(cursor);
}

void game::setReady()
{
	posWindow();
	setTheIcon();
	customCursor();
}

game::game()
{
	init_window();
	setBackground();
	setReady();
	this->backgroundSprite.setScale(window_w / backgroundSprite.getGlobalBounds().width, window_h / backgroundSprite.getGlobalBounds().height);

}

game::~game()
{
	delete this->window;
}
	
void game::start()
{
	
	while (running())
	{
		sf::Vector2i cursorpos = sf::Mouse::getPosition(newWindow);

		if (ready) // Play
		{
			this->backgroundTexture.loadFromFile("assets/Play.png");
			this->backgroundSprite.setTexture(backgroundTexture);
			update();
			render();
		}
		else { // Game Menu
			pollEvents();
			if (getMousePos(625, 307, 1)) // Button Play:
			{
				this->backgroundTexture.loadFromFile("assets/HoverPlay.png");
				this->backgroundSprite.setTexture(backgroundTexture);
				if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{ 
					ready = 1;
				}
			}
			else if (getMousePos(625, 412, 1)) // Button Options
			{
				this->backgroundTexture.loadFromFile("assets/HoverOptions.png");
				this->backgroundSprite.setTexture(backgroundTexture);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					this->backgroundTexture.loadFromFile("assets/Options.png");
					this->backgroundSprite.setTexture(backgroundTexture);
				}
			}
			else if (getMousePos(625, 516, 1)) // Button Rules
			{
				this->backgroundTexture.loadFromFile("assets/HoverRules.png");
				this->backgroundSprite.setTexture(backgroundTexture);
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					this->backgroundTexture.loadFromFile("assets/Rules.png");
					this->backgroundSprite.setTexture(backgroundTexture);
				}
			}
			else if (getMousePos(625, 620, 1)) // Button Quit
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
			menu();
			this->window->setPosition(sf::Vector2i(190, 80));
			this->window->draw(this->backgroundSprite);
			this->window->display();
			clock.restart();
		}

	}

};
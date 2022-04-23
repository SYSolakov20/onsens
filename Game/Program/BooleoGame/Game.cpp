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

sf::Window newWindow(sf::VideoMode(1030, 540), "Booleo", sf::Style::Close);
bool game::getMousePos(float x, float y, int a)
{
	sf::Vector2i mousepos = sf::Mouse::getPosition(newWindow);
	switch (a)
	{
	case 1: // checking for hovering buttons
		if ((mousepos.x >= x && mousepos.x <= x + 280) && (mousepos.y >= y && mousepos.y <= y + 70))
		{
			return 1;
		}
		break;
	}
	return 0;
}

void game::menu()
{
	this->button1.setSize(sf::Vector2f(280, 70));
	this->button1.setPosition(375, 225);
	this->button1.setFillColor(sf::Color(0, 255, 0, 0));
	this->button2.setSize(sf::Vector2f(280, 70));
	this->button2.setPosition(375, 315);
	this->button2.setFillColor(sf::Color(30, 255, 0, 0));
	this->button3.setSize(sf::Vector2f(280, 70));
	this->button3.setPosition(375, 410);
	this->button3.setFillColor(sf::Color(80, 255, 0, 0));
}

game::game()
{
	init_window();
	setBackground();
	this->backgroundSprite.setScale(window_w / backgroundSprite.getGlobalBounds().width, window_h / backgroundSprite.getGlobalBounds().height);

}

game::~game()
{
	delete this->window;
}
	
void game::Start()
{
	newWindow.setVisible(false);

	while (running())
	{
		if (ready) // Play
		{
			this->backgroundTexture.loadFromFile("assets/white.png");
			this->backgroundSprite.setTexture(backgroundTexture);
			update();
			render();
		}
		else { // Game Menu
			pollEvents();
			if (game::getMousePos(375, 225, 1))
			{
				this->backgroundTexture.loadFromFile("assets/HoverPlay.png");
				this->backgroundSprite.setTexture(backgroundTexture);
				if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{ 
					ready = 1;
				}
			}
			else if (game::getMousePos(375, 315, 1))
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					this->backgroundTexture.loadFromFile("assets/Options.png");
					this->backgroundSprite.setTexture(backgroundTexture);
				}
			}
			else if (game::getMousePos(375, 410, 1))
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					this->backgroundTexture.loadFromFile("assets/Rules.png");
					this->backgroundSprite.setTexture(backgroundTexture);
				}
			}
			else
			{
				game::setBackground();
			}
			menu();
			this->window->draw(this->backgroundSprite);
			this->window->draw(this->button2);
			this->window->draw(this->button3);
			this->window->display();
			clock.restart();
		}

	}

};
#include "windows.h"
#include <SFML/Graphics.hpp>
#include <cstdio>
#include <iostream>
//#define SLEEPTIME 500

int wysokosc = 12; //ile jest wierszy wierzchołków
int szerokosc = 22; //ile jest kolumn wiezchołków

bool* odwiedzone;
sf::RenderWindow okno(sf::VideoMode((szerokosc * 40) + 20, (wysokosc * 40) + 20), "moje okienko"); //(szerokość, wysokość)

//DFS
int labiryntdfs(int pozycja);
int labiryntdfs(int pozycja)
{
	int l_sasiadow = 0; //liczba sąsiadów
	odwiedzone[pozycja] = true;
	std::cout << pozycja << ", "; //wypisane odwiedzone wierzcholki

	//sprawdzamy ile mamy sąsiadów
	if (odwiedzone[pozycja - 1] == false)
	{
		l_sasiadow += 1;
	}
	if (odwiedzone[pozycja + 1] == false)
	{
		l_sasiadow += 1;
	}
	if (odwiedzone[pozycja - (szerokosc + 2)] == false)
	{
		l_sasiadow += 1;
	}
	if (odwiedzone[pozycja + (szerokosc + 2)] == false)
	{
		l_sasiadow += 1;
	}

	for (int i = 0; i < l_sasiadow;)
	{

		int losowy = rand() % l_sasiadow;

		if (odwiedzone[pozycja - 1] == false)
		{
			if (losowy == 0)
			{
				sf::RectangleShape rec_l; //w lewo
				rec_l.setSize(sf::Vector2f(20, 20));
				rec_l.setPosition(sf::Vector2f(((((pozycja % (szerokosc + 2)) + 1) * 40) - 60) - 20, (((pozycja / (szerokosc + 2)) + 1) * 40) - 60));
				rec_l.setFillColor(sf::Color(255, 255, 255));
				okno.draw(rec_l);
				labiryntdfs(pozycja - 1);
			}
			else
			{
				losowy = losowy - 1;
			}
		}

		if (odwiedzone[pozycja + 1] == false)
		{
			if (losowy == 0)
			{
				sf::RectangleShape rec_p; //w prawo
				rec_p.setSize(sf::Vector2f(20, 20));
				rec_p.setPosition(sf::Vector2f(((((pozycja % (szerokosc + 2)) + 1) * 40) - 60) + 20, (((pozycja / (szerokosc + 2)) + 1) * 40) - 60));
				rec_p.setFillColor(sf::Color(255, 255, 255));
				okno.draw(rec_p);
				labiryntdfs(pozycja + 1);
			}
			else
			{
				losowy = losowy - 1;
			}
		}

		if (odwiedzone[pozycja - (szerokosc + 2)] == false)
		{
			if (losowy == 0)
			{
				sf::RectangleShape rec_d; //w dół
				rec_d.setSize(sf::Vector2f(20, 20));
				rec_d.setPosition(sf::Vector2f(((((pozycja % (szerokosc + 2)) + 1) * 40) - 60), ((((pozycja / (szerokosc + 2)) + 1) * 40) - 60) - 20));
				rec_d.setFillColor(sf::Color(255, 255, 255));
				okno.draw(rec_d);
				labiryntdfs(pozycja - (szerokosc + 2));
			}
			else
			{
				losowy = losowy - 1;
			}
		}

		if (odwiedzone[pozycja + (szerokosc + 2)] == false)
		{
			if (losowy == 0)
			{
				sf::RectangleShape rec_g; // w górę
				rec_g.setSize(sf::Vector2f(20, 20));
				rec_g.setPosition(sf::Vector2f(((((pozycja % (szerokosc + 2)) + 1) * 40) - 60), ((((pozycja / (szerokosc + 2)) + 1) * 40) - 60) + 20));
				rec_g.setFillColor(sf::Color(255, 255, 255));
				okno.draw(rec_g);
				labiryntdfs(pozycja + (szerokosc + 2));
			}
			else
			{
				losowy = losowy - 1;
			}
		}

		l_sasiadow = 0;

		if (odwiedzone[pozycja - 1] == false)
		{
			l_sasiadow += 1;
		}
		if (odwiedzone[pozycja + 1] == false)
		{
			l_sasiadow += 1;
		}
		if (odwiedzone[pozycja - (szerokosc + 2)] == false)
		{
			l_sasiadow += 1;
		}
		if (odwiedzone[pozycja + (szerokosc + 2)] == false)
		{
			l_sasiadow += 1;
		}
	}
	return 0;
}

int main()
{
	sf::RectangleShape* rect = new sf::RectangleShape[wysokosc * szerokosc];
	odwiedzone = new bool[(wysokosc + 2) * (szerokosc + 2)];

	for (int i = 0; i < (wysokosc + 2) * (szerokosc + 2); i++)
	{
		odwiedzone[i] = false;
	}

	for (int i = 0; i < szerokosc + 2; i++)
	{
		odwiedzone[i] = true;
	}
	for (int i = 0; i <= (wysokosc + 2 - 1) * (szerokosc + 2); i += szerokosc + 2)
	{
		odwiedzone[i] = true;
	}
	for (int i = szerokosc + 2 - 1; i <= (wysokosc + 2) * (szerokosc + 2) - 1; i += szerokosc + 2)
	{
		odwiedzone[i] = true;
	}
	for (int i = (wysokosc + 2 - 1) * (szerokosc + 2); i <= (wysokosc + 2) * (szerokosc + 2) - 1; i++)
	{
		odwiedzone[i] = true;
	}

	okno.clear(sf::Color(0, 0, 0));
	for (int i = 0; i < (wysokosc) * (szerokosc); i++)
	{
		for (int h = 20; h <= (wysokosc * 40) + 20; h = h + 40)
		{
			for (int w = 20; w <= (szerokosc * 40) + 20; w = w + 40)
			{
				rect[i].setSize(sf::Vector2f(20, 20));
				rect[i].setPosition(w, h);
				rect[i].setFillColor(sf::Color(255, 255, 255));
				okno.draw(rect[i]);
			}
		}
	}

	/// wybrany punkt startowy to lewy gorny rog
	labiryntdfs(szerokosc + 3);
	okno.display();

	//chcemy by program działał tak długo jak okno jest otwarte
	while (okno.isOpen())
	{
		//sprawdź wszystkie wydarzenia okna, które zostały wywołane od ostatniej iteracji
		sf::Event event;
		while (okno.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				okno.close();
			}
		}
	}

	delete rect;
	delete odwiedzone;
	return 0;
}
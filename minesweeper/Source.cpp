#include <SFML/Graphics.hpp>
#include <time.h>
using namespace sf;

int main()
{
	srand(time(0));

	RenderWindow app(VideoMode(700, 700), "Minesweeper!");

	int size = 32;
	int gf[22][22];
	int show[22][22]; 

	Texture a;
	a.loadFromFile("images/minesweeper.jpg");
	Sprite f(a);

	for (int i = 1; i <= 20; i++)
		for (int j = 1; j <= 20; j++)
		{
			show[i][j] = 10;
			if (rand() % 5 == 0)  gf[i][j] = 9;
			else gf[i][j] = 0;
		}

	for (int i = 1; i <= 20; i++)
		for (int j = 1; j <= 20; j++)
		{
			int n = 0;
			if (gf[i][j] == 9) continue;
			if (gf[i + 1][j] == 9) n++;
			if (gf[i][j + 1] == 9) n++;
			if (gf[i - 1][j] == 9) n++;
			if (gf[i][j - 1] == 9) n++;
			if (gf[i + 1][j + 1] == 9) n++;
			if (gf[i - 1][j - 1] == 9) n++;
			if (gf[i - 1][j + 1] == 9) n++;
			if (gf[i + 1][j - 1] == 9) n++;
			gf[i][j] = n;
		}

	while (app.isOpen())
	{
		Vector2i pos = Mouse::getPosition(app);
		int x = pos.x / size;
		int y = pos.y / size;

		Event e;
		while (app.pollEvent(e))
		{
			if (e.type == Event::Closed)
				app.close();

			if (e.type == Event::MouseButtonPressed) {
				if (e.key.code == Mouse::Left) show[x][y] = gf[x][y];
				else if (e.key.code == Mouse::Right) show[x][y] = 11;

			}
		}

		app.clear(Color::Black);
					aa:
				int count = 0;
				for (int i = 1; i <= 20; i++)
					for (int j = 1; j <= 20; j++)
					{
						if (i == 1 && j == 1 && show[i][j] == 0) {
							if (gf[i][j + 1] == 0 && show[i][j + 1] != 0) { show[i][j + 1] = gf[i][j + 1]; count++; }
							if (gf[i + 1][j] == 0 && show[i + 1][j] != 0) { show[i + 1][j] = gf[i + 1][j]; count++; }
						}

						if (i == 1 && j == 20 && show[i][j] == 0) {
							if (gf[i][j - 1] == 0 && show[i][j - 1] != 0) { show[i][j - 1] = gf[i][j - 1]; count++; }
							if (gf[i + 1][j] == 0 && show[i + 1][j] != 0) { show[i + 1][j] = gf[i + 1][j]; count++; }
						}

						if (i == 20 && j == 1 && show[i][j] == 0) {
							if (gf[i][j + 1] == 0 && show[i][j + 1] != 0) { show[i][j + 1] = gf[i][j + 1]; count++; }
							if (gf[i - 1][j] == 0 && show[i - 1][j] != 0) { show[i - 1][j] = gf[i - 1][j]; count++; }
						}

						if (i == 20 && j == 20 && show[i][j] == 0) {
							if (gf[i][j - 1] == 0 && show[i][j - 1] != 0) { show[i][j - 1] = gf[i][j - 1]; count++; }
							if (gf[i - 1][j] == 0 && show[i - 1][j] != 0) { show[i - 1][j] = gf[i - 1][j]; count++; }
						}

						if ((i == 1) && (j != 1 && j != 20) && show[i][j] == 0) {
							if (gf[i][j + 1] == 0 && show[i][j + 1] != 0) { show[i][j + 1] = gf[i][j + 1]; count++; }
							if (gf[i][j - 1] == 0 && show[i][j - 1] != 0) { show[i][j - 1] = gf[i][j - 1]; count++; }
							if (gf[i + 1][j] == 0 && show[i + 1][j] != 0) { show[i + 1][j] = gf[i + 1][j]; count++; }
						}

						if ((i == 20) && (j != 1 && j != 20) && show[i][j] == 0) {
							if (gf[i][j + 1] == 0 && show[i][j + 1] != 0) { show[i][j + 1] = gf[i][j + 1]; count++; }
							if (gf[i][j - 1] == 0 && show[i][j - 1] != 0) { show[i][j - 1] = gf[i][j - 1]; count++; }
							if (gf[i - 1][j] == 0 && show[i - 1][j] != 0) { show[i - 1][j] = gf[i - 1][j]; count++; }
						}

						if ((j == 1) && ( i != 1 &&  i != 20) && show[i][j] ==0) {
							if (gf[i + 1][j] == 0 && show[i + 1][j] != 0) { show[i + 1][j] = gf[i + 1][j]; count++; }
							if (gf[i - 1][j] == 0 && show[i - 1][j] != 0) { show[i - 1][j] = gf[i - 1][j]; count++; }
							if (gf[i][j + 1] == 0 && show[i][j + 1] != 0) { show[i][j + 1] = gf[i][j + 1]; count++; }
						}

						if ((j == 20) && (i != 1 && i != 20) && show[i][j] == 0) {
							if (gf[i + 1][j] == 0 && show[i + 1][j] != 0) { show[i + 1][j] = gf[i + 1][j]; count++; }
							if (gf[i - 1][j] == 0 && show[i - 1][j] != 0) { show[i - 1][j] = gf[i - 1][j]; count++; }
							if (gf[i][j - 1] == 0 && show[i][j - 1] != 0) { show[i][j - 1] = gf[i][j - 1]; count++; }
						}

						if (i != 1 && i != 20 && j != 1 && j != 20 && show[i][j] == 0) {
							if (gf[i][j + 1] == 0 && show[i][j + 1] != 0) { show[i][j + 1] = gf[i][j + 1]; count++; }
							if (gf[i][j - 1] == 0 && show[i][j - 1] != 0) { show[i][j - 1] = gf[i][j - 1]; count++; }
							if (gf[i + 1][j] == 0 && show[i + 1][j] != 0) { show[i + 1][j] = gf[i + 1][j]; count++; }
							if (gf[i - 1][j] == 0 && show[i - 1][j] != 0) { show[i - 1][j] = gf[i - 1][j]; count++; }
						}
					}
				if (count != 0) goto aa;

				for (int i = 1; i <= 20; i++)
					for (int j = 1; j <= 20; j++)
					{
						if (i == 1 && j == 1 && show[i][j] == 0) {
							show[i][j + 1] = gf[i][j + 1];
							show[i + 1][j] = gf[i + 1][j]; 
						}

						if (i == 1 && j == 20 && show[i][j] == 0) {
							show[i][j - 1] = gf[i][j - 1]; 
							show[i + 1][j] = gf[i + 1][j]; 
						}

						if (i == 20 && j == 1 && show[i][j] == 0) {
							show[i][j + 1] = gf[i][j + 1]; 
							show[i - 1][j] = gf[i - 1][j];
						}

						if (i == 20 && j == 20 && show[i][j] == 0) {
							show[i][j - 1] = gf[i][j - 1]; 
							show[i - 1][j] = gf[i - 1][j]; 
						}

						if ((i == 1) && (j != 1 && j != 20) && show[i][j] == 0) {
							show[i][j + 1] = gf[i][j + 1];
							show[i][j - 1] = gf[i][j - 1];
							show[i + 1][j] = gf[i + 1][j];
						}

						if ((i == 20) && (j != 1 && j != 20) && show[i][j] == 0) {
							show[i][j + 1] = gf[i][j + 1];
							show[i][j - 1] = gf[i][j - 1];
							show[i - 1][j] = gf[i - 1][j];
						}

						if ((j == 1) && (i != 1 && i != 20) && show[i][j] == 0) {
							show[i + 1][j] = gf[i + 1][j];
							show[i - 1][j] = gf[i - 1][j];
							show[i][j + 1] = gf[i][j + 1];
						}

						if ((j == 20) && (i != 1 && i != 20) && show[i][j] == 0) {
							show[i + 1][j] = gf[i + 1][j];
							show[i - 1][j] = gf[i - 1][j];
							show[i][j - 1] = gf[i][j - 1];
						}

						if (i != 1 && i != 20 && j != 1 && j != 20 && show[i][j] == 0) {
							show[i][j + 1] = gf[i][j + 1];
							show[i][j - 1] = gf[i][j - 1];
							show[i + 1][j] = gf[i + 1][j];
							show[i - 1][j] = gf[i - 1][j];
						}
					}


		for (int i = 1; i <= 20; i++)
			for (int j = 1; j <= 20; j++)
			{
				if (show[x][y] == 9) show[i][j] = gf[i][j];
				f.setTextureRect(IntRect(show[i][j] * size, 0, size, size));
				f.setPosition(i * size, j * size);
				app.draw(f);
			}

		app.display();
	}

	return 0;
}

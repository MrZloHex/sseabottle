#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
	// making window	
	RenderWindow window(VideoMode(575, 300), "sseabottle");

	int common_offset = 25, my_offset = 300, enemy_offset = 25;
	int my_grid[10][10];
	int enemy_grid[10][10];

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			my_grid[i][j] = 0;
			enemy_grid[i][j] = 0;
		}
	}

 
	// life cycle
	while (window.isOpen())
	{
		// getting mouse position
		//Vector2i pos = Mouse::getPosition(window) - Vector2i(offset);

		Vector2i pos = Mouse::getPosition(window);
        int x = pos.x/common_offset;
        int y = pos.y/common_offset;


		// polling events
        Event event;
        while (window.pollEvent(event))
        {
			// button *close* was pressed manual closing window
            if (event.type == Event::Closed) 
			{
				window.close();
			}

			if (event.type == Event::MouseButtonPressed)
              if (event.key.code == Mouse::Left) my_grid[x][y]=1;
        }
		
        for (int k = 0; k < 2; k++)
        {
        	for (int i = 0; i < 10; i++)
        	{
        		for (int j = 0; j < 10; j++)
        		{
        			RectangleShape square(Vector2f(23.0f, 23.0f));
        			if (my_grid[i+1][j+1] == 0)
        			{
						square.setFillColor(Color(0x00, 0xFF, 0xFF));
					} else {
						square.setFillColor(Color(0xFF, 0x00, 0x00));
					}


					if (k == 0)
					{
        				square.setPosition(i*common_offset+enemy_offset, j*common_offset+common_offset);
        			}
        			else
   					{
   						square.setPosition(i*common_offset+my_offset, j*common_offset+common_offset);
   					}
        			window.draw(square);
        		}
        	}
        }

		// refresh part
       	//window.clear(Color::White);
		window.display();
	}

	return 0;
}


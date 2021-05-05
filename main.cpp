#include <SFML/Graphics.hpp>


using namespace sf;

int main()
{
	// making window	
	RenderWindow window(VideoMode(1920, 1080), "sseabottle");

	Texture ship;
	ship.loadFromFile("./img/ship.png");

	Sprite sh(ship);


	// life cycle
	while (window.isOpen())
	{
		// getting mouse position
		//Vector2i pos = Mouse::getPosition(window) - Vector2i(offset);

		// polling events
        	Event event;

        	while (window.pollEvent(event))
        	{
			// button *close* was pressed manual closing window
            		if (event.type == Event::Closed) 
			{
                		window.close();
			}
        	}
		
		// refresh part
        	window.clear(Color::White);
		window.draw(sh);
        	window.display();
    	}

    	return 0;
}


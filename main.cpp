#include <SFML/Graphics.hpp>


using namespace sf;

int main()
{
	// making window	
	RenderWindow window(VideoMode(900, 400), "sseabottle");
	CircleShape shape(100.f);
	shape.setFillColor(Color::Green);

	// life cycle
	while (window.isOpen())
	{
		// polling events
        	Event event;

        	while (window.pollEvent(event))
        	{
			// button *close* was pressed manual closing window
            		if (event.type == Event::Closed)
                		window.close();
        	}
		
		// refresh part
        	window.clear();
        	window.draw(shape);
        	window.display();
    	}

    	return 0;
}


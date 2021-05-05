#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

int main() {
	// making window	
	RenderWindow window(VideoMode(575, 300), "sseabottle");

	int common_offset = 25, my_offset = 300, enemy_offset = 25;

	int my_grid[0xA][0xA];				// k = 1
	int enemy_grid[0xA][0xA];			// 
	int my_enemy_grid[0xA][0xA];		// k = 0

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if ((rand()%4) == 0) {
				enemy_grid[i][j] = 2;
			} 
			else {
				enemy_grid[i][j] = 0;
			}
			my_grid[i][j] = 0;
			my_enemy_grid[i][j] = 0;

		}
	}

 
	// life cycle
	while (window.isOpen()) {
		Vector2i pos = Mouse::getPosition(window);
        int x = pos.x/common_offset -1;
        int y = pos.y/common_offset -1;


		// polling events
        Event event;
        while (window.pollEvent(event)) {
			// button *close* was pressed manual closing window
            if (event.type == Event::Closed) {
				window.close();
			}

			if (event.type == Event::MouseButtonPressed) {
            	if (event.key.code == Mouse::Left) {
              		cout << "x " << x << endl;
              		cout << "y " << y << endl;
              		//my_grid[x][y]=1;
              	}
			}
        }
		
        for (int k = 0; k < 2; k++) {
        	for (int i = 0; i < 10; i++) {
        		for (int j = 0; j < 10; j++) {
        			RectangleShape square(Vector2f(23.0f, 23.0f));


        			if (k == 0) {
        				// drawing enemy grid go me

        				/* 
        				   0 - water						0x00, 0xFF, 0xFF
        				   1 - water, which was shooted		0x00, 0xF0, 0xF0
        				   2 - ship							0xF0, 0xF0, 0xF0
        				   3 - ship, which was shooted		0xFF, 0xF0, 0x00
        				   . - nothing or trouble			0x00, 0xFF, 0x00
        				*/
        				// set colour
        				if (enemy_grid[i][j] == 0) {
        					square.setFillColor(Color(0x00, 0xFF, 0xFF));
        				}
        				else if (enemy_grid[i][j] == 1){
        					square.setFillColor(Color(0x00, 0xF0, 0xF0));
        				}
        				else if (enemy_grid[i][j] == 2){
        					square.setFillColor(Color(0xF0, 0xF0, 0xF0));
        				}
        				else if (enemy_grid[i][j] == 3){
        					square.setFillColor(Color(0xFF, 0xF0, 0x00));
        				}
        				else {
        					square.setFillColor(Color(0x00, 0xFF, 0x00));
        				}


        				// placing them and drawing
        				square.setPosition((i * common_offset) + enemy_offset, (j * common_offset) + common_offset);
        			}
        			else {
        				// set colour
        				if (my_grid[i][j] == 0) {
        					square.setFillColor(Color(0x00, 0xFF, 0xFF));
        				}
        				else if (my_grid[i][j] == 1){
        					square.setFillColor(Color(0x00, 0xF0, 0xF0));
        				}
        				else if (my_grid[i][j] == 2){
        					square.setFillColor(Color(0xF0, 0xF0, 0xF0));
        				}
        				else if (my_grid[i][j] == 3){
        					square.setFillColor(Color(0xFF, 0xF0, 0x00));
        				}
        				else {
        					square.setFillColor(Color(0x00, 0xFF, 0x00));
        				}


        				// placing them and drawing
        				square.setPosition((i * common_offset) + my_offset, (j * common_offset) + common_offset);
        			}
        			window.draw(square);
        		}
        	}
        }

		// refresh part
		window.display();
	}

	return 0;
}


#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;


const bool dev = false;  // 0 - for normal mode; 1 - for dev mode


int * drawing_squares(int type, int x, int y, int my_grid[10][10], int enemy_grid[10][10], int my_enemy_grid[10][10]) {
	// drawing enemy grid go me

        /* 									 R     G     B
        0 - water							0x00, 0xFF, 0xFF
        1 - water, which was shooted		0x00, 0x80, 0x80
        2 - ship							0x3F, 0x3F, 0x3F
        3 - ship, which was shooted			0xFF, 0x80, 0x00
    	. - nothing or trouble				0x00, 0xFF, 0x00
    */
    // set colour
	static int colour[3];
    if (type == 0) {
    	if (!dev) {
    		if (my_enemy_grid[x][y] == 0) {
        		colour[0] = 0x00;
        		colour[1] = 0xFF;
        		colour[2] = 0xFF;

        	}
        	else if (my_enemy_grid[x][y] == 1){
       			colour[0] = 0x00;
        		colour[1] = 0x80;
        		colour[2] = 0x80;
        	}
      		else if (my_enemy_grid[x][y] == 2){
       			colour[0] = 0x3F;
        		colour[1] = 0x3F;
        		colour[2] = 0x3F;
       		}
        	else if (my_enemy_grid[x][y] == 3){
        		colour[0] = 0xFF;
        		colour[1] = 0x80;
        		colour[2] = 0x00;
        	}
        	else {
        		colour[0] = 0x00;
        		colour[1] = 0xFF;
        		colour[2] = 0x00;
        	}
    	}
    	else if (dev) {
    		if (enemy_grid[x][y] == 0) {
        		colour[0] = 0x00;
        		colour[1] = 0xFF;
        		colour[2] = 0xFF;

        	}
        	else if (enemy_grid[x][y] == 1){
       			colour[0] = 0x00;
        		colour[1] = 0x80;
        		colour[2] = 0x80;
        	}
      		else if (enemy_grid[x][y] == 2){
       			colour[0] = 0x3F;
        		colour[1] = 0x3F;
        		colour[2] = 0x3F;
       		}
        	else if (enemy_grid[x][y] == 3){
        		colour[0] = 0xFF;
        		colour[1] = 0x80;
        		colour[2] = 0x00;
        	}
        	else {
        		colour[0] = 0x00;
        		colour[1] = 0xFF;
        		colour[2] = 0x00;
        	}
    	}
    }
    else {
    	if (my_grid[x][y] == 0) {
        	colour[0] = 0x00;
        	colour[1] = 0xFF;
       		colour[2] = 0xFF;
        }
        else if (my_grid[x][y] == 1){
       		colour[0] = 0x00;
        	colour[1] = 0x80;
        	colour[2] = 0x80;
       	}
      	else if (my_grid[x][y] == 2){
      		colour[0] = 0x3F;
       		colour[1] = 0x3F;
        	colour[2] = 0x3F;
       	}
        else if (my_grid[x][y] == 3){
        	colour[0] = 0xFF;
        	colour[1] = 0x80;
        	colour[2] = 0x00;
        }
        else {
        	colour[0] = 0x00;
        	colour[1] = 0xFF;
        	colour[2] = 0x00;
        }
    }
    return colour;
}


void generate_enemy_field(int field[0xA][0xA]) {
	/*int amount = 10;
	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 10; y++) {
			if ((rand()%3) == 2) {

				if (x == 0) {
					if (y == 0) {
						field[x][y] = 2;
						amount--;
					}
					else {
						if (field[x][y-1] == 0) {
							field[x][y] = 2;
							amount--;
						}
					}
				}
				else {
					if (y == 0) {
						if ((field[x-1][y] == 0) && (field[x-1][y+1] == 0)) {
							field[x][y] = 2;
							amount--;
						}
					}
					else if ((y < 9) && (y != 0)) {
						if ((field[x][y-1] == 0) && (field[x-1][y-1] == 0) && (field[x-1][y] == 0) && (field[x-1][y+1] == 0)) {
							field[x][y] = 2;
							amount--;
						}
					}
					else {
						if ((field[x][y-1] == 0) && (field[x-1][y-1] == 0) && (field[x-1][y] == 0)) {
							field[x][y] = 2;
							amount--;
						}
					}
				}

			} 
			if (amount == 0) {
				return;
			}
		}
	}*/
	int enemy_full_grid[0xA][0xA];
	for (int x = 0; x < 10; x++) {
		for (int y = 0; y < 10; y++) {
			enemy_full_grid[x][y] = field[x][y];
		}
	}

	for (int length = 4; length > 0; length--) {
		for (int amount = 5 - length; amount > 0; amount--) {
			if (length == 1) {
				continue;
			}
			cout << length << endl;

			lets_try:
				//cout << "wqe" << endl;
				int x_start = rand()%10;
				int y_start = rand()%10;
				int direction = rand()%2;		// 0 - horizontal; 1 - vertical


				if (direction == 0) {
					if ((x_start + length) > 10) {
						goto lets_try;
					}
					for (int y_check = y_start - 1; y_check < y_start + 2; y_check++) {
						for (int x_check = x_start - 1; x_check < x_start + length + 1; x_check++) {
							if ((x_check < 0) || (x_check > 10) || (y_check < 0) || (y_check > 10)) {
								continue;
							}
							if (enemy_full_grid[x_check][y_check] == 2) {
								goto lets_try;
							}
						}
					}

					// drawing
					for (int draw = 0; draw < length; draw++) {
						field[x_start + draw][y_start] = 2;
					} 
					for (int y_draw = y_start - 1; y_draw < y_start + 2; y_draw++) {
						for (int x_draw = x_start - 1; x_draw < x_start + length + 1; x_draw++) {
							if ((x_draw < 0) || (x_draw > 10) || (y_draw < 0) || (y_draw > 10)) {
								continue;
							}
							enemy_full_grid[x_draw][y_draw] = 2;
						}
					}
				}


				else if (direction == 1) {
					if ((y_start + length) > 10) {
						goto lets_try;
					}
					for (int x_check = x_start - 1; x_check < x_start + 2; x_check++) {
						for (int y_check = y_start - 1; y_check < y_start + length + 1; y_check++) {
							if ((x_check < 0) || (x_check > 10) || (y_check < 0) || (y_check > 10)) {
								continue;
							}
							if (enemy_full_grid[x_check][y_check] == 2) {
								goto lets_try;
							}
						}
					}

					// drawing
					for (int draw = 0; draw < length; draw++) {
						field[x_start][y_start + draw] = 2;
					} 
					for (int x_draw = x_start - 1; x_draw < x_start + 2; x_draw++) {
						for (int y_draw = y_start - 1; y_draw < y_start + length + 1; y_draw++) {
							if ((x_draw < 0) || (x_draw > 10) || (y_draw < 0) || (y_draw > 10)) {
								continue;
							}
							enemy_full_grid[x_draw][y_draw] = 2;
						}
					}

				}
		}
	}
}

void make_field(int field[10][10]) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			field[i][j] = 0;
		}
	}
}


int main() {
	// making window	
	RenderWindow window(VideoMode(575, 300), "sseabottle");

	int common_offset = 25, my_offset = 300, enemy_offset = 25;

	int my_grid[0xA][0xA];				// k = 1
	int enemy_grid[0xA][0xA];			// 
	int my_enemy_grid[0xA][0xA];		// k = 0

	make_field(my_grid);
	make_field(enemy_grid);
	make_field(my_enemy_grid);

	generate_enemy_field(enemy_grid);

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
              		/*cout << "x " << x << endl;
              		cout << "y " << y << endl;
              		cout << endl;*/

              		if (((x <= 9) && (x >= 0)) && ((y <= 9) && (y >= 0))) {
              			if (enemy_grid[x][y] == 0) {
              				my_enemy_grid[x][y] = 1;
              				//cout << "x " << x << "y " << y << my_enemy_grid[x][y] << endl;
              			}
              			else if (enemy_grid[x][y] == 2) {
              				my_enemy_grid[x][y] = 3;
              				//cout << "x " << x << " y " << y << " " << my_enemy_grid[x][y] << endl;
              			}
              		}
              	}
			}
        }
		
        //window.clear();

        for (int type = 0; type < 2; type++) {
        	for (int x = 0; x < 10; x++) {
        		for (int y = 0; y < 10; y++) {
        			RectangleShape square(Vector2f(23.0f, 23.0f));


        			if (type == 0) {
        				// drawing enemy grid go me
        				int *colour = drawing_squares(type, x, y, my_grid, enemy_grid, my_enemy_grid);
        				square.setFillColor(Color(colour[0], colour[1], colour[2]));
        				// placing them and drawing
        				square.setPosition((x * common_offset) + enemy_offset, (y * common_offset) + common_offset);
        			}
        			else {
        				// set colour
        				int *colour = drawing_squares(type, x, y, my_grid, enemy_grid, my_enemy_grid);
        				square.setFillColor(Color(colour[0], colour[1], colour[2]));
        				// placing them and drawing
        				square.setPosition((x * common_offset) + my_offset, (y * common_offset) + common_offset);
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


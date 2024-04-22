#include <vector>
#include <iostream>
#include <fstream>
#include <string>

#include "raylib.h"
#include "level.h"

const int vertical_tiles = 100;
const int horizontal_tiles = 150;
const int tile_size = 6;


void Level::initialize(void) {

	std::vector<char> empty_vec;

	for (int i = 0; i < vertical_tiles; i++)
		empty_vec.push_back('A');
	
	for (int i = 0; i < horizontal_tiles; i++)
		this->terrain.push_back(empty_vec);
}


void Level::update(void) {

	int i = 0;
	int j = 0;
	std::fstream terrain_file("terrain.txt");
	std::string line;

	while (!terrain_file.eof()) {
		
		std::getline(terrain_file, line);
		
		for (char c : line) {
			this->terrain[i][j] = c;
			i++;
			//std::cout << c;
		}

		//std::cout << std::endl;
		j++;
		i = 0;

	}

	//for (int i = 0; i < horizontal_tiles; i++) {
	//	for (int j = 0; j < vertical_tiles; j++) {
	//		std::cout << this->terrain[j][i];
	//	}
	//	std::cout << std::endl;
	//}

	terrain_file.close();

}


void Level::draw(void) {
	Color color = RAYWHITE;
	int i = 0;
	int j = -1;

	for (std::vector<char> vec : this->terrain) {

		j++;
		i = 0;

		for (char tile : vec) {

			switch (tile) {
				case '0':
					color = RAYWHITE;
					break;
				case 'G':
					color = YELLOW;
					break;
				case 'S':
					color = RED;
					break;
				default:
					color = RAYWHITE;
			}

			
			DrawRectangle(j * tile_size, i * tile_size, tile_size, tile_size, color);
			DrawRectangleLinesEx(
				{ (float) (j * tile_size),  (float) (i * tile_size), tile_size, tile_size},
				0.1f,
				LIGHTGRAY
			);

			i++;


		}
	}
}

char Level::get_tile(int x, int y) {
	return this->terrain[x][y];
}


extern Level terrain;
#pragma once

#include <vector>

extern const int vertical_tiles;
extern const int horizontal_tiles;
extern const int tile_size;

class Level {
private:
	std::vector<std::vector<char>> terrain;

public:

	void draw(void);
	void update(void);
	void initialize(void);
	char get_tile(int x, int y);

};

extern Level terrain;


#pragma once

#include "raylib.h"
#include "level.h"

class Player {
private:
	Vector2 pos = { 0, 0 };
	Vector2 speed = {1.0f, 2};

	bool jumping = false;
	float rotation = 0;


public:

	Player(float x, float y);
	Player(Vector2 spawn);

	void move(void);
	void jump(void);
	void draw(void);
	bool check_death(void);
	Rectangle get_future_rectangle(void);
	Rectangle get_rectangle(void);
	Vector2 get_pos(void);
	void handle_player_collisions(void);

	bool is_jumping();

};
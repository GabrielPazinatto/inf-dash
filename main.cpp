#include <iostream>
#include "raylib.h"

#include "player.h"

int timer = 0;
char timer_ascii[5] = {'0'};
int timer_count = 0;

const int screen_height = 600;
const int screen_width = 900;

const Vector2 spawn = { 0, screen_height - (tile_size * 5) +3 };
//const Vector2 spawn = { 0, screen_height - (tile_size * 16) };

Player player(spawn);

Camera2D camera = {
	player.get_pos(),
	{-10, -10},
	0,
	5
};

int main(void) {

	SetTargetFPS(60);
	InitWindow(screen_width, screen_height, "Test");

	terrain.initialize();
	terrain.update();

	while (!WindowShouldClose()) {

		camera.offset = { 60,360 };
		camera.target = player.get_pos();

		BeginDrawing();
		ClearBackground(RAYWHITE);
		BeginMode2D(camera);

		terrain.draw();
		player.draw();
		player.move();
		player.handle_player_collisions();

		//DrawText(timer_ascii, player.get_pos().x, player.get_pos().y - 15, 5, BLACK);
		//DrawFPS(player.get_pos().x, player.get_pos().y- 50);

		EndMode2D();
		EndDrawing();
	}

	timer_count++;

	if (timer_count == 60) {
		timer_count = 0;
		timer++;

		_itoa_s(timer, timer_ascii, 10);
	}

	return 0;
}
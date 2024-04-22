#include "player.h"
#include <iostream>

Level terrain;

Player::Player(float x, float y) {
	this->pos = { x, y };
}

Rectangle Player::get_rectangle(void) {

	return {
		this->pos.x,
		this->pos.y,
		6,
		6
	};
}

Rectangle Player::get_future_rectangle(void) {

	return {
		this->pos.x + this->speed.x,
		this->pos.y + this->speed.y,
		6,
		6
	};
}


Player::Player(Vector2 spawn) {
	this->pos = spawn;
}

Vector2 Player::get_pos(void) {
	return this->pos;
}

void Player::draw(void) {
	
	Rectangle player = this->get_rectangle();
	player.x += 3;
	player.y += 3;

	DrawRectanglePro
	(player,
		{3, 3},
		this->rotation,
		PURPLE);

	//DrawRectangleRec(
	//	this->get_future_rectangle(),
	//	PURPLE
	//);

}

void Player::jump(void) {

	if (this->jumping) {

		this->rotation += 10;
		this->speed.y += 0.22f;
		return;
	}

	if (!IsKeyDown(KEY_UP) and !this->jumping) return;

	if (IsKeyDown(KEY_UP) and !this->jumping) {
		this->speed.y = -3;
		this->jumping = true;
		return;
	}

	return;

}

void Player::move(void) {
	this->pos.x += this->speed.x;
	this->pos.y += this->speed.y;
	this->jump();
}



bool Player::check_death(void) {
	return false;
}

bool Player::is_jumping() {
	return this->jumping;
}

void Player::handle_player_collisions(void) {

	if(!this->jumping)this->speed.y = 2;

	Rectangle player = this->get_rectangle();
	Rectangle future_player = this->get_future_rectangle();

	Rectangle tile;
	char tile_char = '\0';

	for (int i = 0; i < horizontal_tiles; i++) {
		for (int j = 0; j < vertical_tiles; j++) {

			tile_char = terrain.get_tile(i, j);
			tile = {(float) i * tile_size, (float) j * tile_size, (float) tile_size, (float) tile_size };

			if (CheckCollisionRecs(future_player, tile) && tile_char == 'G') {
				this->speed.y = 0;
				this->jumping = false;
				this->rotation = 0;
				this->pos.y = tile.y - tile.height;
				return;
			}

			if (CheckCollisionRecs(player, tile) && tile_char == 'S') {
				this->speed.y = 0;
				this->rotation = 0;
				this->jumping = false;
				this->pos = { 0, 600.0f - (tile_size * 5) + 4 };
				return;
			}

			if (CheckCollisionRecs(player, tile) && tile_char != '0') {
				if (tile.x > player.x + player.width) {
					this->speed.y = 0;
					this->rotation = 0;
					this->jumping = false;
					this->pos = { 0, 600.0f - (tile_size * 5) + 4 };
					return;
				}
			}


		}

	}




}
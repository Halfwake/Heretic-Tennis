#include <stdbool.h>

#include "SDL/SDL.h"

#include "paddle.h"
#include "config.h"

static const int default_paddle_width = 64;
static const int default_paddle_height = 128;

Paddle *create_paddle(int x, int y, int speed, bool player) {
		Paddle *p = (Paddle*) malloc(sizeof(Paddle));
		
		SDL_Rect *pad_rect = (SDL_Rect*) malloc(sizeof(SDL_Rect));
		pad_rect->x = x;
		pad_rect->y = y;
		pad_rect->w = default_paddle_width;
		pad_rect->h = default_paddle_height;
		p->rect = pad_rect;
		
		p->player = player;
		p->speed = speed;
		return p;
}

void draw_paddle(Paddle *paddle, SDL_Surface *surface) {
	SDL_FillRect(surface, paddle->rect, 128); //colour is hard coded
}

void paddle_move(Paddle *paddle, int dx, int dy) {
	Sint16 *paddle_x = &(paddle->rect->x);
	Sint16 *paddle_y = &(paddle->rect->y);
	Uint16 width = paddle->rect->w;
	Uint16 height = paddle->rect->h;
	
	*paddle_x += dx;
	//Keep in bounds for x
	if(*paddle_x + width > screen_width) {
		*paddle_x = screen_width - width;
	}
	else if(*paddle_x < 0) {
		*paddle_x = 0;
	}
	
	*paddle_y += dy;
	//Keep in bounds for y
	if(*paddle_y + height > screen_height) {
		*paddle_y = screen_height - height;
	}
	else if(*paddle_y < 0) {
		*paddle_y = 0;
	}
	
}
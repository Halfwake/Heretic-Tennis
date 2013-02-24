#include <stdbool.h>

#include "SDL/SDL.h"

#include "paddle.h"

static const int default_paddle_width = 64;
static const int default_paddle_height = 128;

Paddle *create_paddle(int x, int y, bool player) {
		Paddle *p = (Paddle*) malloc(sizeof(Paddle));
		
		SDL_Rect *pad_rect = (SDL_Rect*) malloc(sizeof(SDL_Rect));
		(*pad_rect).x = x;
		(*pad_rect).y = y;
		(*pad_rect).w = default_paddle_width;
		(*pad_rect).h = default_paddle_height;
		(*p).rect = pad_rect;
		
		(*p).player = player;
		return p;
}

void draw_paddle(Paddle paddle, SDL_Surface *surface) {
	SDL_FillRect(surface, paddle.rect, 128); //colour is hard coded
}
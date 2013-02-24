#include <stdbool.h>

#include "SDL\SDL.h"

#ifndef PADDLE
#define PADDLE

typedef struct {
	SDL_Rect *rect;
	bool player;
} Paddle;

Paddle *create_paddle(int x, int y, bool player);
void draw_paddle(Paddle paddle, SDL_Surface *surface);

#endif
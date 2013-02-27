#include "SDL/SDL.h"

#include "ball.h"
#include "config.h"

static const int default_ball_radius = 10;

Ball *create_ball(int x, int y, int dx, int dy) {
	Ball *ball = (Ball*) malloc(sizeof(Ball));
	ball->x = x;
	ball->y = y;
	ball->dx = dy;
	ball->dy = dx;
	ball->radius = default_ball_radius;
	return ball;
}

void draw_ball(Ball *ball, SDL_Surface *surface) {
	SDL_Rect temp_rect = {ball->x, ball->y, ball->radius, ball->radius};
	SDL_FillRect(surface, &temp_rect, 128); //Colour hardcoded
}

void move_ball(Ball *ball) {
	ball->x += ball->dx/* *dt */;
	
	ball->y += ball->dy/* *dt */;
	if(ball->y < 0) {
		ball->dy = -(ball->dy);
	}
	else if(ball->y > screen_height) {
		ball->dy = -(ball->dy);
	}
}
#include "SDL/SDL.h"

#include "ball.h"

static const int default_ball_radius = 5;

Ball *create_ball(int x, int y) {
	Ball *ball = (Ball*) malloc(sizeof(Ball));
	ball->x = x;
	ball->y = y;
	ball->radius = default_ball_radius;
	return ball;
}
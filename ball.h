#ifndef BALL
#define BALL

typedef struct {
	int x;
	int y;
	int dx;
	int dy;
	int radius;
} Ball;

Ball *create_ball(int x, int y, int dx, int dy);
void draw_ball(Ball *ball, SDL_Surface *surface);
void move_ball(Ball *ball);

#endif
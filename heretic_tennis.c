#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "SDL/SDL.h"

#include "config.h"
#include "paddle.h"
#include "ball.h"
#include "heretic_tennis.h"

static const int screen_depth = 8;
static const int paddle_distance = 100;
static const char *caption_title = "Heretic Tennis";
static const int player_paddle_index = 0;
static const int opponent_paddle_index = 1;
static const int player_start_speed = 3;
static const int opponent_start_speed = 1;

int main(int argc, char *argv[]) {
	SDL_Surface *screen;
	SDL_Surface *test_image;
	SDL_Rect test_area;
	Paddle *paddles[2];
	Ball *ball;
	int i;
	
	srand(time(NULL));
	
	//Initialize SDL
	SDL_Init(SDL_INIT_VIDEO);
	
	//Set Caption
	SDL_WM_SetCaption(caption_title, NULL); 
	
	//Initialize window
	screen = SDL_SetVideoMode(screen_width, screen_height, screen_depth, SDL_SWSURFACE);
	
	paddles[player_paddle_index] = create_paddle(paddle_distance, screen_height / 2, player_start_speed, true);
	paddles[opponent_paddle_index] = create_paddle(screen_width - paddle_distance, screen_height / 2, opponent_start_speed, false);
	
	ball = create_ball(screen_width / 2, screen_height / 2, rand() % 2 ? -1 : 1, rand() % 2 ? -1 : 1); //Randomly set the balls original dx and dy to some value with an abs of 1
	
	//Update the screen
	for(;;) {
		for(i = 0; i < 2; i++) {
			draw_paddle(paddles[i], screen);
		}
		draw_ball(ball, screen);
		SDL_Flip(screen);
		SDL_FillRect(SDL_GetVideoSurface(), NULL, 0);
		event_loop(paddles, ball);
	}
	
	return EXIT_FAILURE;
}	

void event_loop(Paddle **paddles, Ball *ball) {
	SDL_Event event;
	Paddle *player_paddle = paddles[player_paddle_index];
	int player_speed = player_paddle->speed;
	Uint8 *keystate = SDL_GetKeyState(NULL);
	
	move_ball(ball);
	
	if(keystate[SDLK_UP]) {
			paddle_move(player_paddle, 0, -player_speed);
	}
	else if(keystate[SDLK_DOWN]) {
			paddle_move(player_paddle, 0, player_speed);
	}
	
	while(SDL_PollEvent(&event)) {
		switch(event.type) {
			case SDL_QUIT:
				quit(0);
				break;
		}
	}
}

void quit(int success) {
	SDL_Quit();
	exit(success);
}
	
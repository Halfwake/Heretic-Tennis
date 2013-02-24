#include <stdio.h>
#include <stdbool.h>

#include "SDL/SDL.h"

#include "heretic_tennis.h"
#include "paddle.h"

static const int screen_width = 800;
static const int screen_height = 600;
static const int screen_depth = 8;
static const int paddle_distance = 100;
static const char *caption_title = "Staring Contest";

int main(int argc, char *argv[]) {
	SDL_Surface *screen;
	SDL_Surface *test_image;
	SDL_Rect test_area;
	
	//Initialize SDL
	SDL_Init(SDL_INIT_VIDEO);
	
	//Set Caption
	SDL_WM_SetCaption(caption_title, NULL); 
	
	//Initialize window
	screen = SDL_SetVideoMode(screen_width, screen_height, screen_depth, SDL_SWSURFACE);
	
	Paddle *player_paddle = create_paddle(paddle_distance, screen_height / 2, true);
	Paddle *opponent_paddle = create_paddle(screen_width - paddle_distance, screen_height / 2 ,false);
	
	//Update the screen
	for(;;) {
		draw_paddle(*player_paddle, screen);
		draw_paddle(*opponent_paddle, screen);
		SDL_Flip(screen);
		
		event_loop();
	}
	
	return EXIT_FAILURE;
}	

void event_loop() {
	SDL_Event event;
	
	while(SDL_PollEvent(&event)) {
		switch(event.type) {
			case SDL_QUIT:
				quit(0);
				break;
			case SDL_KEYDOWN
				react_key(event);
				break;
		}
	}
}

void react_key(SDL_Event event) {
	switch(event.key.keysym.sym) {
		case SDLK_UP:
			paddle_move()
			break;
	}
}

void quit(int success) {
	SDL_Quit();
	exit(success);
}
	
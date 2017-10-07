#include <vector>
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>

#include "utils.h"

#ifndef MAIN_H
#define MAIN_H

#define SCREEN_HEIGHT   480
#define SCREEN_WIDTH    640

int initialize_game(GameState* game);
void run_event_loop(GameState* game);

#endif /* MAIN_H */
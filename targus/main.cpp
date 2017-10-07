
#include "main.h"

int main(int argc, char **argv)
{
    GameState game;
    initialize_game(&game);
    run_event_loop(&game);
    
    //Destroy window
    SDL_DestroyWindow( game.window );
    SDL_Quit();
	printf("hello world\n");
	return 0;
}

int initialize_game(GameState* game)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        printf("Unable to initialize game. SDL_Error: %s\n", SDL_GetError() );
        return -1;
    }
    game->window = SDL_CreateWindow( "Targus", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if (game->window == NULL) {
        printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        return -1;
    }
    game->renderer = SDL_CreateRenderer(game->window, -1, 0);

    // Load images
    game->objects = std::vector<GameObject>();
    load_texture(game, "ego.png");
    
    // Paint the window black
    SDL_SetRenderDrawColor(game->renderer, 0, 0, 0, 255);
    SDL_RenderClear(game->renderer);
    SDL_RenderPresent(game->renderer);


    /*for (int i=0; i<100; i++) {
        //move_object_by(game->imageCache.ego, 1, 2);
        SDL_Rect dest;
        dest.x = i;
        dest.y = i;
        SDL_QueryTexture(game->imageCache.ego, NULL, NULL, &dest.w, &dest.h);
        
        //Clear screen
        SDL_RenderClear( game->renderer );

        //Render texture to screen
        SDL_RenderCopy( game->renderer, game->imageCache.ego, NULL, &dest );

        //Update screen
        SDL_RenderPresent( game->renderer );
    }
    //Wait two seconds
    SDL_Delay( 2000 );
    */
    return 0;
}

void run_event_loop(GameState* game)
{
    bool quit = false;
    SDL_Event event;
    while (!quit) {
        while( SDL_PollEvent( &event ) != 0 ) {
            switch(event.type) {
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_KEYDOWN:
                    printf("down %d\n", event.key.keysym.sym);
                    if (event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_KP_4) {
                        move_object_by(&game->objects.at(0), -3, 0);
                    } else if (event.key.keysym.sym == SDLK_RIGHT || event.key.keysym.sym == SDLK_KP_6) {
                        move_object_by(&game->objects.at(0), 3, 0);
                    } else if (event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_KP_8) {
                        move_object_by(&game->objects.at(0), 0, -3);
                    } else if (event.key.keysym.sym == SDLK_DOWN || event.key.keysym.sym == SDLK_KP_2) {
                        move_object_by(&game->objects.at(0), 0, 3);
                    } else if (event.key.keysym.sym == SDLK_KP_7) {
                        move_object_by(&game->objects.at(0), -3, -3);
                    } else if (event.key.keysym.sym == SDLK_KP_9) {
                        move_object_by(&game->objects.at(0), 3, -3);
                    } else if (event.key.keysym.sym == SDLK_KP_1) {
                        move_object_by(&game->objects.at(0), -3, 3);
                    } else if (event.key.keysym.sym == SDLK_KP_3) {
                        move_object_by(&game->objects.at(0), 3, 3);
                    }
                    break;
                case SDL_KEYUP:
                    printf("up %d\n", event.key.keysym.sym);
                    break;
                default:
                    break;
            }
        }

        //Clear screen
        SDL_RenderClear( game->renderer );

        // Render all objects
        for (GameObject object: game->objects) {
            SDL_Rect dest;
            dest.x = object.x;
            dest.y = object.y;
            dest.w = object.w;
            dest.h = object.h;
            SDL_RenderCopy(game->renderer, object.object, NULL, &dest);
            printf("%s", "2");
        }

        //Update screen
        SDL_RenderPresent( game->renderer );
        printf("%s", "1");
    }
}


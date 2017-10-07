#include "utils.h"

/**
 * @brief Load a texture from disk into the game state
 * @param game
 * @param path
 * @return A pointer to the newly loaded object.
 */
GameObject* load_texture(GameState* game, const char* path)
{
    SDL_Texture* newTexture = NULL;
    SDL_Surface* loadedSurface = IMG_Load(path);
    if (loadedSurface == NULL) {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path, IMG_GetError() );
    } else {
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( game->renderer, loadedSurface );
        if(newTexture == NULL) {
            printf( "Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError() );
        }
        GameObject* new_game_object = (GameObject*)malloc(1 * sizeof(GameObject));
        SDL_QueryTexture(newTexture, NULL, NULL, &new_game_object->w, &new_game_object->h);
        new_game_object->x = 0;
        new_game_object->y = 0;
        new_game_object->object = newTexture;
        game->objects.push_back(*new_game_object);
        
        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
        return new_game_object;
    }
    return NULL;
}

void move_object_by(GameObject* object, int dx, int dy)
{
    if (object == NULL) {
        return;
    }
    object->x += dx;
    object->y += dy;
}

void move_object_to(GameObject* object, int x, int y)
{
    if (object == NULL) {
        return;
    }
    object->x = x;
    object->y = y;
}
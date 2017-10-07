#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include <vector>

#ifndef UTILS_H
#define UTILS_H

typedef struct {
    int x;
    int y;
} ObjectLocation;

typedef struct {
    SDL_Texture* ego;
} ImageCache;


typedef struct {
    SDL_Texture* object;
    int h;
    int w;
    int x;
    int y;
} GameObject;

typedef struct {
    int score;
    SDL_Window* window;
    SDL_Renderer* renderer;
    ImageCache imageCache;

    std::vector<GameObject> objects;
} GameState;


GameObject* load_texture(GameState* game, const char* path);
void move_object_by(GameObject* object, int dx, int dy);
void move_object_to(GameObject* object, int x, int y);

#endif 
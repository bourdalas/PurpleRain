//
// Created by Jerry Kougianos on 05/05/2018.
//

#pragma once

#include <vector>
#include <string>
#include "main.h"
#include "Rect.h"
#include "TextBox.h"

class GameLoop;

class Scene {
public:
    Scene(SDL_Renderer *renderer, TTF_Font *font, int sceneId, int alternate = 0, int numItems = 0);

    Scene(SDL_Renderer *renderer, TTF_Font *font, const std::string &filepath);

    ~Scene();

    void setNarrative(const std::string &str);

    void process(GameLoop *gameLoop, int mx, int my);

    void mousePressed(GameLoop *gameLoop, int mx, int my);

    void render(SDL_Renderer *renderer);

    void setOpacity(float op);

private:
    void init(int sceneId, int alternate, int numItems);

    void loadScn(const std::string &filepath);

    struct Link {
        int mouseCursor;
        Rect region;
        std::string scnFile;
    };

    std::vector<Link> links;

    SDL_Renderer *renderer;
    SDL_Texture *image = nullptr;
    float opacity = 1.0f;

    std::shared_ptr<TextBox> textBox;
    std::string narrative;
    TTF_Font *font = nullptr;
};
//
// Created by Jerry Kougianos on 05/05/2018.
//

#pragma once

#include <memory>
#include "main.h"
#include "Scene.h"

class GameLoop {
public:
    GameLoop();

    ~GameLoop();

    ///Game loop high-level control methods
    int processEvents();

    void updateLogic();

    void doRender();

    ///Runs the game loop, doesn't return until quitting entire game
    void run();

    void loadScene(const std::string &scn);

    static const int CursorBack = 0, CursorDown = 1, CursorFwd = 2, CursorItem = 3,
            CursorLeft = 4, CursorNormal = 5, CursorRight = 6, CursorUp = 7;

    void setCursor(int cursor);

    void transitionScene(const std::string &scn);


private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    bool done = false;

    //scene//////////////////////////////
    std::shared_ptr<Scene> scene, incomingScene;
    float transitionfade = 0;

    //mouse cursor///////////////////////
    SDL_Texture *mouseCursor = nullptr;
    SDL_Texture *mouseCursors[8];

    //font///////////////////////
    TTF_Font *font = nullptr;

};
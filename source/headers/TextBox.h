//
// Created by Jerry Kougianos on 06/05/2018.
//

#pragma once

#include <string>
#include <vector>
#include "main.h"
#include "Rect.h"

class TextBox {
public:
    TextBox(const std::string &text, TTF_Font *font);

    void update();
    void render(SDL_Renderer *renderer);
private:
    void buildLines();

    Rect rect;
    std::string text;
    std::vector<std::string> lines;
    int textPosition = 0;
    int time = 0;
    TTF_Font *font;
};

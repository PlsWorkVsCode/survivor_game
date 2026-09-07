#include <iostream>
#include "raylib.h"
#include <iostream>

#pragma once

using namespace std;

class button{
    public:
        float x_position;
        float y_position;
        float width;
        float height;
        Color color;
        string text = "";
        float text_width;
        button(float x_position, float y_position, float width, float height, Color color, string text, 
            float text_width);
        bool update(Vector2 mouse_position);
        void draw();
};
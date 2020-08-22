#include "graphics.hpp"
#include "SDL2/SDL.h"

#include <iostream>
#include <cmath>

int main(int argc, char* argv[]) {
    Graphics * gfx = new Graphics("textGraphics", "./assets/tilesets/Vintl01.png", 16, 16, 0, "./assets/fonts/Monaco.ttf", 1280, 960, 30, 80);

    SDL_Event event;
    for (int i = 0; i < 1; ++i) {
        for (int j = 0; j < 100; ++j) {
            while (SDL_PollEvent(&event) != 0) {
                if (event.type == SDL_QUIT) {
                    return 0;
                }
            }
            int x = 0, y = 0;
            SDL_GetMouseState(&x, &y);
            x = gfx->getPosCol(x);
            y = gfx->getPosRow(y);
            SDL_Delay(50);
            gfx->clear();
            for (int k = 0; k < 9; ++k) {
                for (int l = 0; l < 20; ++l) {
                    gfx->setCh('@', j-k-l, 16-k);
                    gfx->setForeColor(round(255.0 * (j-20) / 50.0), 
                                      int(round(500.0 - 500.0 * (j-20) / 50.0)) % 255, 
                                      255 - int(round(500.0 - 500.0 * (j-20) / 50.0)) % 255, 
                                      int(round(255.0 - 255.0 * double(l) / 20.0)), 
                                      j-k-l, 16-k);
                    gfx->setBackColor(round(255.0 * (j-20) / 50.0), 
                                      int(round(500.0 - 500.0 * (j-20) / 50.0)) % 255, 
                                      255 - int(round(500.0 - 500.0 * (j-20) / 50.0)) % 255, 
                                      int(round(255.0 - 255.0 * double(l) / 20.0)), 
                                      j-k-l, 16-k);
                }
            }
            gfx->write("x: " + std::to_string(x), 0, gfx->getScreenRows() - 2);
            gfx->write("y: " + std::to_string(y), 0, gfx->getScreenRows() - 1);
            gfx->importTxt("./assets/txt/test.txt", true);
            gfx->render();
        }
    }
    gfx->clear();
    gfx->importTxt("./assets/txt/test2.txt", true);
    int x = 0, y = 0;
    for (unsigned int i = 0; i < 16 * 16; ++i) {
        if (i > 0 && i % 16 == 0) {
            x = 0;
            ++y;
        }
        gfx->setCh(i, x, y);
        gfx->setBackColor(0, 200, 200, 255, x, y);
        ++x;
    }
    gfx->render();
    SDL_Delay(1000);

    delete gfx;
    return 0;
}
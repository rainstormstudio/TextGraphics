#include "graphics.hpp"

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
            gfx->clear('0');
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
            gfx->render();
        }
    }
    gfx->clear();
    Texture* texture = new Texture("./assets/txt/pistol.txt");
    SDL_Rect srcRect;
    srcRect = {5, 23, 18, 6};
    gfx->drawTexture(texture, &srcRect, 25, 0);
    gfx->drawTexture(texture, &srcRect, 25, 8);
    delete texture;
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
    SDL_Delay(2000);

    delete gfx;
    return 0;
}
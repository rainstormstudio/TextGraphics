/**
 * @file graphics.hpp
 * @author Daneil Hongyu Ding
 * @brief This is a simple graphical port using SDL2
 * @version 0.5
 * @date 2020-08-18
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#ifdef __linux__
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"
#elif _WIN32
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#endif

#include "ctexture.hpp"
#include "texture.hpp"
#include <vector>
#include <string>
#include <fstream>
#include <memory>

class Graphics {
    std::string title;
    SDL_Window* window;
    SDL_Renderer* renderer;
    TTF_Font* font;

    SDL_Texture* tileset;
    unsigned int numSrcRows;
    unsigned int numSrcCols;
    unsigned int tileWidth;
    unsigned int tileHeight;

    Uint32 fullscreen;
    unsigned int screenWidth;
    unsigned int screenHeight;

    unsigned int numRows;
    unsigned int numCols;
    std::vector<std::vector<std::shared_ptr<CTexture>>> textDisplay;

public:
    /**
     * @brief Construct a new Graphics object
     * 
     * @param title the title of the window
     * @param tilesetFilename the file path to the tileset image
     * @param numSrcRows number of rows in the tileset
     * @param numSrcCols number of columns in the tileset
     * @param fullscreenFlag SDL flag for fullscreen. Use 0 for none
     * @param fontPath the file path to the ttf font
     * @param screenWidth the width of the window
     * @param screenHeight the height of the window
     * @param numRows number of rows will be shown on the screen
     * @param numCols number of columns will be shown on the screen
     */
    Graphics(std::string title, std::string tilesetFilename, 
             unsigned int numSrcRows, unsigned int numSrcCols,
             Uint32 fullscreenFlag, std::string fontPath,
             unsigned int screenWidth, unsigned int screenHeight,
             unsigned int numRows, unsigned int numCols);

    /**
     * @brief Destroy the Graphics object
     * 
     */
    ~Graphics();

    /**
     * @brief Set the character at the y-th row and the x-th column
     * 
     * @param index the character you want to put on screen
     * @param x the column number
     * @param y the row number
     */
    void setCh(Uint8 index, int x, int y);

    /**
     * @brief Set the Fore Color to be (r, b, g, a) at 
     * the y-th row and the x-th column
     * 
     * @param r red
     * @param g green
     * @param b blue
     * @param a alpha
     * @param x the column number
     * @param y the row number
     */
    void setForeColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a, int x, int y);

    /**
     * @brief Set the Back Color to be (r, b, g, a) at
     * the y-th row and the x-th column
     * 
     * @param r red
     * @param g green
     * @param b blue
     * @param a alpha
     * @param x the column number
     * @param y the row number
     */
    void setBackColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a, int x, int y);

    /**
     * @brief draws src region of a Texture to screen 
     * at the y-th row and the x-th column
     * 
     * @param texture the txt texture
     * @param src source rectangle region
     * @param x the column number
     * @param y the row number
     */
    void drawTexture(Texture* texture, SDL_Rect* src, int x, int y);

    /**
     * @brief write content starting at the y-th row and the x-th column
     * 
     * @param content the content to be written
     * @param x the column number
     * @param y the row number
     */
    void write(std::string content, int x, int y);

    /**
     * @brief write content with foreColor starting at
     * the y-th row and the x-th column
     * 
     * @param content the content to be written
     * @param x the column number
     * @param y the row number
     * @param r red for foreColor
     * @param g green for foreColor
     * @param b blue for foreColor
     * @param a alpha for foreColor
     */
    void write(std::string content, int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

    /**
     * @brief write content with foreColor and backColor starting 
     * at the y-th row and the x-th column
     * 
     * @param content the content to be written
     * @param x the content number
     * @param y the row number
     * @param r red for foreColor
     * @param g green for foreColor
     * @param b blue for foreColor
     * @param a alpha for foreColor
     * @param br red for backColor
     * @param bg green for backColor
     * @param bb blue for backColor
     * @param ba alpha for backColor
     */
    void write(std::string content, int x, int y, Uint8 r, Uint8 g, Uint8 b, Uint8 a, Uint8 br, Uint8 bg, Uint8 bb, Uint8 ba);

    /**
     * @brief write content starting at the y-th row and the x-th column
     * it creates new line every time the length reaches width
     * 
     * @param content the content to be written
     * @param x the column number
     * @param y the row number
     * @param width the width of every line
     */
    void writeln(std::string content, int x, int y, int width);

    /**
     * @brief write content with foreColor starting at
     * the y-th row and the x-th column;
     * it creates new line every time the length reaches width
     * 
     * @param content content to be written
     * @param x the column number
     * @param y the row number
     * @param width the width of every line
     * @param r red for foreColor
     * @param g green for foreColor
     * @param b blue for foreColor
     * @param a alpha for foreColor
     */
    void writeln(std::string content, int x, int y, int width, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

    /**
     * @brief write content with foreColor and backColor starting at
     * the y-th row and the x-th column;
     * it creates new line every time the length reaches width
     * 
     * @param content content to be written
     * @param x the column number
     * @param y the row number
     * @param width the width of every line
     * @param r red for foreColor
     * @param g green for foreColor
     * @param b blue for foreColor
     * @param a alpha for foreColor
     * @param br red for backColor
     * @param bg green for backColor
     * @param bb blue for backColor
     * @param ba alpha for backColor
     */
    void writeln(std::string content, int x, int y, int width, Uint8 r, Uint8 g, Uint8 b, Uint8 a, Uint8 br, Uint8 bg, Uint8 bb, Uint8 ba);

    /**
     * @brief clear the screen buffer and textDisplay
     * 
     */
    void clear();

    /**
     * @brief clear the screen buffer and textDisplay with ch
     * 
     * @param ch the character filling the screen
     * 
     */
    void clear(Uint8 ch);

    /**
     * @brief render the buffer(textDisplay) to the screen
     * 
     */
    void render();

    /**
     * @brief Get the Screen Rows
     * 
     * @return unsigned int 
     */
    unsigned int getScreenRows() const;

    /**
     * @brief Get the Screen Cols
     * 
     * @return unsigned int 
     */
    unsigned int getScreenCols() const;

    /**
     * @brief Get the index of column number given the x-coordinate
     * of the screen
     * 
     * @param x the x-coordinate of the screen
     * @return unsigned int 
     */
    unsigned int getPosCol(int x) const;

    /**
     * @brief Get the index of row number given the y-coordinate
     * of the screen
     * 
     * @param y the y-coordinate of the screen
     * @return unsigned int 
     */
    unsigned int getPosRow(int y) const;
};

#endif

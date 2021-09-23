#include "TextManager.h"

void TextManager::LoadFontAndPrint(const char* fontFile, int fontSize, const char* text, SDL_Color color, int x, int y, int w, int h, SDL_Renderer* rend) {
    TTF_Font* font = TTF_OpenFont(fontFile, fontSize);
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(font, text, color);
    SDL_Texture* message = SDL_CreateTextureFromSurface(rend, surfaceMessage);

    SDL_Rect rect {x, y, w, h};

    SDL_RenderCopy(rend, message, NULL, &rect);

    TTF_CloseFont(font);
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(message);
}
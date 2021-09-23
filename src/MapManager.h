#ifndef SRC_MAPMANAGER_H_
#define SRC_MAPMANAGER_H_

#include "Map.h"
#include "MapLoader.h"

class MapManager {
    public:
        MapManager(int size);
        void LoadMapFromFile(const char* file);
        void Render(SDL_Renderer* rend, int xOffset, int yOffset, int vpWidth, int vpHeight, int camX, int camY);

    private:
        Map* map;
        MapLoader* mapLoader;
        int tileSize;
};

#endif /* SRC_MAPMANAGER_H_ */
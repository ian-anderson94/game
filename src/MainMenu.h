#ifndef SRC_MAINMENU_H_
#define SRC_MAINMENU_H_

#include "AnimationManager.h"
#include "MainMenuButton.h"
#include "Enums.h"
#include "InputManager.h"
#include "Mouse.h"
#include "Position.h"
#include "Scene.h"
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"
#include "Selector.h"
#include "TextManager.h"
#include "TextureManager.h"

#include <unordered_set>
#include <vector>

class MainMenu : public Scene {
    public:
        MainMenu(int resX, int resY, int tileSize);

        void Update(double dt);
        void Render(SDL_Renderer* rend);
        Enums::Scene HandleEvents(SDL_Event event);

    private:
        vector<string> menuSelections = { "New Game", "Continue", "Options", "Exit" };
        vector<Enums::Scene> sceneVals = { Enums::SCN_HubMenu, Enums::SCN_HubMenu, Enums::SCN_HubMenu, Enums::SCN_HubMenu };

        Selector<Enums::Scene>* selector;
        SDL_Texture* selectionsTexture;
        SDL_Texture* selectorTexture;

        vector<Button*> buttons;

        int screenCenterX;
        int screenCenterY;
        int currSelection;
        int selectorVerticalOffset;
        int mainMenuTextSize;

        int xMenuAnchor, yMenuAnchor;

        Position RenderMenuSelections(SDL_Renderer* rend);
        void renderMenu(SDL_Renderer* rend);
        void renderSelector(SDL_Renderer* rend);
        Enums::Scene MapMainMenuSelectionToScene();

        int boundCurrSelection();
};

#endif /* SRC_MAINMENU_H_ */

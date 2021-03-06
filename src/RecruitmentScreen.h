#ifndef SRC_RECRUITMENTSCREEN_H_
#define SRC_RECRUITMENTSCREEN_H_

#include "ActionMenu.h"
#include "Frame.h"
#include "InputManager.h"
#include "PlayerAccount.h"
#include "Position.h"
#include "RecruitGenerator.h"
#include "Scene.h"
#include "TextManager.h"
#include "Utils.h"

#include <iostream>
#include <math.h>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class RecruitmentScreen : public Scene {
    public:
        RecruitmentScreen(int resX, int resY, int tileSize);
        void Render(SDL_Renderer* rend);
        void Update(double dt);
        Enums::Scene HandleEvents(SDL_Event event);

    private:
        int recruitsAvailable, maxRecruits, currSelection;

        const vector<string> menuOptions = { "Recruit", "Cancel" };
        vector<Actor*> recruits;
        vector<Frame*> frames;

        ActionMenu* actionMenu;
        RecruitGenerator* recruitGenerator;

        void SetAndBoundCurrSelection(int delta);
        void RefreshRecruits(int count);
        void CreateFrames();
        void CreateAndRenderRecruitFrame(SDL_Renderer* rend, Actor* recruit, int frameX, int frameY);
        void Recruit();
};

#endif /* SRC_RECRUITMENTSCREEN_H_ */
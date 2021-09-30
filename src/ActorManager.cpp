#include "ActorManager.h"

ActorManager::ActorManager(int resolutionX, int resolutionY, int tileSize) {
    resX = resolutionX;
    resY = resolutionY;
    this->tileSize = tileSize;
}

void ActorManager::Render(SDL_Renderer* rend, int xOffset, int yOffset, int wTiles, int hTiles, int camX, int camY) {
    vector<Actor*> actorsInViewport = GetActorsInViewport(xOffset, yOffset, wTiles, hTiles, camX, camY);

    for (auto const& actor : actorsInViewport) {
        actor->RenderRelativeToViewport(rend, xOffset, yOffset, camX, camY, wTiles, hTiles);
    }
}

void ActorManager::Update(double dt, Map* map) {
    for (auto const& actor : actors) {
        actor->Update(dt, map);
    }
}

Actor* ActorManager::GetActor(int xPos, int yPos) {
    for (auto const& actor : actors) {
        Actor::Position pos = actor->GetPosition();

        if (pos.x == xPos && pos.y == yPos) {
            return actor;
        }
    }

    return nullptr;
}

vector<Actor*> ActorManager::GetActorsInViewport(int xOffset, int yOffset, int wTiles, int hTiles, int camX, int camY) {
    vector<Actor*> actorsInViewport;
    
    for (auto const& actor : actors) {
        Actor::Position actorPos = actor->GetPosition();

        if (actorPos.x >= camX && actorPos.x < camX + wTiles) {
            if (actorPos.y >= camY && actorPos.y < camY + hTiles) {
                actorsInViewport.push_back(actor);
            }
        }
    }

    return actorsInViewport;
}
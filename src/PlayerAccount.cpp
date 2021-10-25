#include "PlayerAccount.h"

PlayerAccount* PlayerAccount::instance = nullptr;

PlayerAccount::PlayerAccount() {
    activeQuest = nullptr;
    maxPartySize = 4;
}

PlayerAccount* PlayerAccount::GetInstance() {
    if (!instance)
		instance = new PlayerAccount();

	return instance;
}
#pragma once
#include "DMAMemoryManagement/includes.h";
#include "ArmaString.h"

namespace DayZ {
	struct ScoreboardIdentity : public DMAMem::MemoryObject {
		uint32_t NetworkID;
		std::shared_ptr<ArmaString> PlayerName;
		std::shared_ptr<ArmaString> SteamID; // new member

		ScoreboardIdentity() {
			this->registerOffset(0x30, &NetworkID, sizeof(uint32_t));

			PlayerName = std::shared_ptr<ArmaString>(new ArmaString());
			this->registerPointer(0xF8, PlayerName.get());

			// register new member
			SteamID = std::shared_ptr<ArmaString>(new ArmaString());
			this->registerPointer(0xA0, SteamID.get());
		}
	};
}
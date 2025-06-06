// dma-dayz-cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "DMAMemoryManagement/includes.h"
#include "DayZ/DayZMem/DayZMem.h"
#include "DayZ/Structs/NetworkManager.h";
#include "DayZ/Structs/WorldPointer.h";
#include "DayZ/DayZMem/MemoryUpdater/MemoryUpdater.h"
#include "DayZ/DayZMem/OverlayAdapter/OverlayAdapter.h"
#include "DayZ/DayZMem/RadarAdapter/RadarAdapter.h"
#include "DMARender/includes.h"
#include "DayZ/Maps/ChernarusPlus.h"
#include "DayZ/Maps/Namalsk.h"
#include "DayZ/Maps/Livonia.h"
#include "DayZ/Maps/DeadFall.h"
#include "DayZ/Maps/Alteria.h"
#include "DayZ/Maps/Lux.h"
#include "DayZ/Maps/Esseker.h"
#include "DayZ/Maps/Deerisle.h"
#include "DayZ/Maps/Sakhal.h"
#include "DayZ/Maps/Takistan.h"
#include "DayZ/Maps/Banov.h"


int main()
{


    auto vmm = new DMAMem::VmmManager();
    auto game = new DayZ::Mem(vmm);

    auto memUpdater = std::shared_ptr<DayZ::MemoryUpdater>(new DayZ::MemoryUpdater(game));
    memUpdater->beginUpdateLoop();

    DMARender::RenderWindow cmd = DMARender::RenderWindow();

    cmd.getBridge()->setOverlay(std::make_shared<DayZ::OverlayAdapter>(memUpdater, cmd.getBridge()));
    cmd.getBridge()->addMap(std::shared_ptr<DayZ::ChernarusPlus>(new DayZ::ChernarusPlus()));
    cmd.getBridge()->addMap(std::shared_ptr<DayZ::Namalsk>(new DayZ::Namalsk()));
    cmd.getBridge()->addMap(std::shared_ptr<DayZ::Livonia>(new DayZ::Livonia()));
    cmd.getBridge()->addMap(std::shared_ptr<DayZ::DeadFall>(new DayZ::DeadFall()));
    cmd.getBridge()->addMap(std::shared_ptr<DayZ::Alteria>(new DayZ::Alteria()));
    cmd.getBridge()->addMap(std::shared_ptr<DayZ::Lux>(new DayZ::Lux()));
    cmd.getBridge()->addMap(std::shared_ptr<DayZ::Esseker>(new DayZ::Esseker()));
    cmd.getBridge()->addMap(std::shared_ptr<DayZ::Deerisle>(new DayZ::Deerisle()));
    cmd.getBridge()->addMap(std::shared_ptr<DayZ::Sakhal>(new DayZ::Sakhal()));
    cmd.getBridge()->addMap(std::shared_ptr<DayZ::Takistan>(new DayZ::Takistan()));
    cmd.getBridge()->addMap(std::shared_ptr<DayZ::Banov>(new DayZ::Banov()));


    cmd.getBridge()->setRadar(std::make_shared<DayZ::RadarAdapter>(memUpdater, cmd.getBridge()));

    std::thread gfxThread(&DMARender::RenderWindow::initializeWindow, &cmd);




    gfxThread.join();



    memUpdater->endUpdateLoop();

    return 1;
}

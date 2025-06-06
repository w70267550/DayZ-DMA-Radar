#pragma once

#include <vector>
#include <string>

//CASESENSITIVE!!!!!!!!
namespace DayZ {
	const std::vector<std::string> InventoryItemWhitelist{ "inventoryItem", "itemoptics", "carwheel", "ItemBook", "ItemSuppressor" };   
	const std::vector<std::string> itemBlacklist { "AreaDamageTriggerBase", "item", "Bonfire", "TrapTrigger", "TripWireTrigger", "ClutterCutter6x6", "GardenPlotPolytunnel", "GardenPlot", "GardenPlotGreenhouse", "ContaminatedTrigger_Dynamic", "ContaminatedArea_Dynamic", "ContaminatedArea_Static", "ContaminatedTrigger", "AreaDamageTriggerBase", "SteakKnife", "PoliceCap", "SmallStone", "BBP_Bwall", "BBP_Swall", "BBP_BDoor", "BBP_SDoor", "BBP_Bfloor", "BBP_BWindow", "TreeEffecter", "FreeDebugCamera", "NoBuildZone", "SnapPoint", "TerritoryTrigger", "vbldr_misc_haybale", "bldr_prop_Pitchfork", "StaticObj_Furniture_school_map", "RA_Coat_Hook", "bldr_prop_PipeWrench", "Underground_Prop_ToolTrolley" };
}
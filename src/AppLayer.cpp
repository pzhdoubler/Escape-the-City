//
// Created by 8luke on 10/25/2019.
//

#include "AppLayer.h"

AppLayer::AppLayer() {

    //load map
    loader.loadMap("level_prototype.txt");

    //receive level
    level = loader.createLevelState();

}

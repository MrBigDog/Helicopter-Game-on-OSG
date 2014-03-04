//
//  Game.h
//  testOsg
//
//  Created by Fares Alotaibi on 2014-03-03.
//  Copyright (c) 2014 Fares Alotaibi. All rights reserved.
//

#ifndef testOsg_Game_h
#define testOsg_Game_h
#include <osgViewer/Viewer>
#include <osg/Node>
#include <osgDB/ReadFile>
#include <osgGA/NodeTrackerManipulator>
#include "Helicopter.h"
#include "Terrain.h"
#include "Sky.h"
#include "ModelFactory.h"
#include "Obstacle.h"
#include "TimeHandler.h"
#include "Controller.h"
// game class created

class Game  {
public:
    void initialize();
    
    osgViewer::Viewer viewer;
};


#endif

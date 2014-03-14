//
//  Observer.h
//
//  Created by Fares Alotaibi on 2014-03-03.
//  SID: 200288569
// pure abstract class Observer . This class mostly will be used as an abstract class to observe events from other class. Thedesign we had decided to choose is observer design.

#ifndef __HelicopterProject__Observer_h__
#define __HelicopterProject__Observer_h__

#include "Event.h"


class Observer {
public:
    virtual void Update(Event event) = 0;
};


#endif

//
//  Observer.h
//  testOsg
//
//  Created by Fares Alotaibi on 2014-03-03.
//  SID: 200288569
//

#ifndef testOsg_Observer_h
#define testOsg_Observer_h

#include "Event.h"


class Observer {
public:
    virtual void Update(Event event) = 0;
};


#endif

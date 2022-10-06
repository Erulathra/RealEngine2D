//
// Created by erulathra on 06.10.22.
//

#ifndef REALISTICENGINE_SINUSMOVINGACTOR_H
#define REALISTICENGINE_SINUSMOVINGACTOR_H


#include "Actor.h"

class SinusMovingActor : Actor {
    virtual void Update(double DeltaSeconds, double Seconds) override;
    virtual void Start() override;
};


#endif //REALISTICENGINE_SINUSMOVINGACTOR_H

#include "Engine/SinusMovingActor.h"
#include "Eigen/Core"

void SinusMovingActor::Start() {

}

void SinusMovingActor::Update(double DeltaSeconds, double Seconds) {
    Position[1] += Position[1] + static_cast<float>(std::sin(Seconds));
}

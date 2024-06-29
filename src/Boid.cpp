#include "Boid.hpp"
#include <cmath>
#include <vector>


//Dist threshold constant
//maximum velocity, acceleration constants

Boid::Boid(float x, float y, float mass) {
    pos = CVector(x, y);
    vel = CVector(0, 0);
    acc = CVector(0, 0);
    mass = 1.0;
}

float Boid::calc_distance(Boid& other) {
    return pos.distance(other.pos);
}

CVector Boid::alignment(std::vector<Boid>& boids) {
    CVector align_vel = CVector(0, 0);

    int count = 0;
    float total_mass = 0;

    for (Boid& b: boids) {
        float dist = calc_distance(b);
        if (dist > 0 && dist <= DIST_THRESHOLD) {
            count += 1;
            total_mass += b.mass; 
            align_vel += b.vel;
        }
    }

    if (count == 0) {
        return align_vel;
    }

    align_vel /=  
}



void update() {
}


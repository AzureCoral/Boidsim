#ifndef BOID_HPP
#define BOID_HPP

#include <vector>
#include "cvector.hpp"

class Boid {
    public:
        CVector pos;
        CVector vel;
        CVector acc;
        float mass;

        Boid(float x, float y, float mass);
        float calc_distance(Boid& other);
        void update();

    private:
        CVector alignment(std::vector<Boid>& boids);
        CVector separation(std::vector<Boid>& boids);
        CVector cohesion(std::vector<Boid>& boids);
};

#endif // BOID_HPP

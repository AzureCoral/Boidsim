#ifndef BOID_HPP
#define BOID_HPP

#include <vector>
#include "cvector.hpp"

class Boid {
    public:
        CVector pos;
        CVector vel;
        float mass;

        Boid(CVector pos, CVector vel, float mass = 1.0);
        float calc_distance(Boid& other);
        void update(std::vector<Boid>& boids);

    private:
        CVector alignment(std::vector<Boid>& boids);
        CVector separation(std::vector<Boid>& boids);
        CVector cohesion(std::vector<Boid>& boids);

        bool in_bounds(CVector& v);
};

#endif // BOID_HPP

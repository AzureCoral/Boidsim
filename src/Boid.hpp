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

        static constexpr float DIST_THRESHOLD = 50.0;
        static constexpr float MAX_VEL = 1000.0;
        static constexpr float ALIGN_FACTOR = 1.0;
        static constexpr float SEPARATION_FACTOR = 1.5;
        static constexpr float COHESION_FACTOR = 1.0;

};

#endif // BOID_HPP

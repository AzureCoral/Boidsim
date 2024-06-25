#ifndef BOID_HPP
#define BOID_HPP

#include <vector>
#include "vector2.hpp"

class Boid {
    public:
        Vector2 pos;
        Vector2 vel;
        Vector2 acc;

        Boid(float x, float y);
        void update_pos(const std::vector<Boid>& boids);

    private:
        Vector2 alignment(const std::vector<Boid>& boids);
        Vector2 cohesion(const std::vector<Boid>& boids);
        Vector2 separation(const std::vector<Boid>& boids);
};

#endif // BOID_HPP

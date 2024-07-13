#include "Boid.hpp"
#include "Config.hpp"
#include <algorithm>
#include <cmath>

Boid::Boid(CVector p, CVector v, float mass) : pos(p), vel(v), mass(mass) {}

float Boid::calc_distance(Boid& other) {
    return pos.tor_distance(other.pos);
}

void Boid::update(std::vector<Boid>& boids) {
    CVector alignment_force = alignment(boids);
    CVector separation_force = separation(boids);
    CVector cohesion_force = cohesion(boids);

    vel += alignment_force + separation_force + cohesion_force;
    vel = vel.cap(Config::MAX_VEL);

    pos += vel;
    rebound_handling();
}

void Boid::rebound_handling() {
    float boid_radius = Config::BOID_SIZE / 2;
    float wall_threshold = 50;
    float repulsion_strength = 100;

    if (pos.x - boid_radius < wall_threshold) {
        float distance = pos.x - boid_radius;
        float acceleration = repulsion_strength / distance;
        vel.x += acceleration;
    } else if (pos.x + boid_radius > Config::WINDOW_WIDTH - wall_threshold) {
        float distance = Config::WINDOW_WIDTH - (pos.x + boid_radius);
        float acceleration = repulsion_strength / distance;
        vel.x -= acceleration;
    }

    if (pos.y - boid_radius < wall_threshold) {
        float distance = pos.y - boid_radius;
        float acceleration = repulsion_strength / distance;
        vel.y += acceleration;
    } else if (pos.y + boid_radius > Config::WINDOW_HEIGHT - wall_threshold) {
        float distance = Config::WINDOW_HEIGHT - (pos.y + boid_radius);
        float acceleration = repulsion_strength / distance;
        vel.y -= acceleration;
    }

    if (pos.x - boid_radius < 0 || pos.x + boid_radius > Config::WINDOW_WIDTH) {
        vel.x *= -1;
    }
    if (pos.y - boid_radius < 0 || pos.y + boid_radius > Config::WINDOW_HEIGHT) {
        vel.y *= -1;
    }
}

CVector Boid::alignment(std::vector<Boid>& boids) {
    CVector align_vel(0, 0);
    int num_boids = 0;

    for (Boid& b : boids) {
        float dist = calc_distance(b);
        if (dist > 0 && dist <= Config::DIST_THRESHOLD) {
            num_boids++;
            align_vel += b.vel;
        }
    }

    if (num_boids == 0) {
        return CVector(0, 0);
    }

    align_vel /= num_boids;
    align_vel = align_vel.normalized() * Config::ALIGN_FACTOR;
    align_vel = align_vel.cap(Config::MAX_VEL);

    return align_vel;
}

CVector Boid::separation(std::vector<Boid>& boids) {
    CVector sep_vel(0, 0);
    int num_boids = 0;

    for (Boid& b : boids) {
        float dist = calc_distance(b);
        if (dist > 0 && dist <= Config::DIST_THRESHOLD) {
            num_boids++;
            CVector diff = pos - b.pos;
            if (dist < Config::MIN_DISTANCE) {
                diff = diff.normalized() * (Config::MIN_DISTANCE - dist);
                sep_vel += diff;
            }
        }
    }

    if (num_boids == 0) {
        return CVector(0, 0);
    }

    sep_vel /= num_boids;
    sep_vel = sep_vel.cap(Config::MAX_VEL) * Config::SEPARATION_FACTOR;

    return sep_vel;
}

CVector Boid::cohesion(std::vector<Boid>& boids) {
    CVector coh_vel(0, 0);
    int num_boids = 0;

    for (Boid& b : boids) {
        float dist = calc_distance(b);
        if (dist > 0 && dist <= Config::DIST_THRESHOLD) {
            num_boids++;
            coh_vel += b.pos;
        }
    }

    if (num_boids == 0) {
        return CVector(0, 0);
    }

    coh_vel /= num_boids;
    coh_vel -= pos;
    coh_vel = coh_vel.normalized() * Config::COHESION_FACTOR;
    coh_vel = coh_vel.cap(Config::MAX_VEL);

    return coh_vel;
}

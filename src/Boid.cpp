#include "Boid.hpp"
#include "cvector.hpp"
#include <vector>
#include "Config.hpp"

Boid::Boid(CVector p, CVector v, float mass) {
    pos = p;
    vel = v;
}

float Boid::calc_distance(Boid& other) {
    return pos.distance(other.pos);
}

void Boid::update(std::vector<Boid>& boids) {
    vel += alignment(boids) + separation(boids) + cohesion(boids);
    vel = vel.cap(Config::MAX_VEL);

    if (!in_bounds()) {
        vel *= -1;
    }

    pos += vel;
}

bool Boid::in_bounds() {
    return pos.x >= 0 && pos.x < Config::WINDOW_WIDTH && pos.y >= 0 && pos.y < Config::WINDOW_HEIGHT;
}

CVector Boid::alignment(std::vector<Boid>& boids) {
    CVector align_vel = CVector(0, 0);

    int num_boids = 0;
    float total_mass = 0;

    for (Boid& b: boids) {
        float dist = calc_distance(b);
        if (dist > 0 && dist <= Config::DIST_THRESHOLD) {
            num_boids++;
            total_mass += b.mass; 
            align_vel += b.vel;
        }
    }

    if (num_boids == 0) {
        return align_vel;
    }

    align_vel /= total_mass;
    align_vel = align_vel.normalized();
    align_vel *= Config::ALIGN_FACTOR;
    align_vel = align_vel.cap(Config::MAX_VEL);

    return align_vel;
}

CVector Boid::separation(std::vector<Boid>& boids) {
    CVector sep_vel = CVector(0, 0);
    int num_boids = 0;
    float total_mass = 0;

    for (Boid& b: boids) {
        float dist = calc_distance(b);
        if (dist > 0 && dist <= Config::DIST_THRESHOLD) {
            num_boids++;
            total_mass += b.mass;
            CVector diff = pos - b.pos;
            diff /= dist;
            sep_vel += diff;
        }
    }

    if (num_boids == 0) {
        return sep_vel;
    }

    sep_vel /= total_mass;
    sep_vel = sep_vel.normalized();
    sep_vel *= Config::SEPARATION_FACTOR;
    sep_vel = sep_vel.cap(Config::MAX_VEL);

    return sep_vel;
}

CVector Boid::cohesion(std::vector<Boid>& boids) {
    CVector coh_vel = CVector(0, 0);
    int num_boids = 0;
    float total_mass = 0;

    for (Boid& b: boids) {
        float dist = calc_distance(b);
        if (dist > 0 && dist <= Config::DIST_THRESHOLD) {
            num_boids++;
            total_mass += b.mass;
            coh_vel += b.pos;
        }
    }

    if (num_boids == 0) {
        return coh_vel;
    }

    coh_vel /= total_mass;
    coh_vel = coh_vel - pos;
    coh_vel = coh_vel.normalized();
    coh_vel *= Config::COHESION_FACTOR;
    coh_vel = coh_vel.cap(Config::MAX_VEL);

    return coh_vel;
}


#include "Boid.hpp"
#include "Config.hpp"

Boid::Boid(CVector p, CVector v, float mass) {
    pos = p;
    vel = v;
    mass = mass;
}

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
    if (pos.x < Config::DIST_THRESHOLD) {
        vel.x += Config::BOUNDARY_REPULSION_FACTOR;
    }
    if (pos.x > Config::WINDOW_WIDTH - Config::DIST_THRESHOLD) {
        vel.x -= Config::BOUNDARY_REPULSION_FACTOR;
    }
    if (pos.y < Config::DIST_THRESHOLD) {
        vel.y += Config::BOUNDARY_REPULSION_FACTOR;
    }
    if (pos.y > Config::WINDOW_HEIGHT - Config::DIST_THRESHOLD) {
        vel.y -= Config::BOUNDARY_REPULSION_FACTOR;
    }
}

CVector Boid::alignment(std::vector<Boid>& boids) {
    CVector align_vel(0, 0);
    int num_boids = 0;

    for (Boid& b : boids) {
        align_vel += b.vel;
    }

    align_vel /= Config::NUM_BOIDS;
    align_vel -= vel;
    align_vel = align_vel.cap(Config::MAX_VEL);

    return align_vel / 8;
}

CVector Boid::separation(std::vector<Boid>& boids) {
    CVector sep_vel(0, 0);
    int num_boids = 0;

    for (Boid& b : boids) {
        float dist = calc_distance(b);
        if (dist < Config::DIST_THRESHOLD) {
            num_boids++;
            sep_vel -= b.pos - pos;
        }
    }

    sep_vel = sep_vel.cap(Config::MAX_VEL);

    return sep_vel;
}

CVector Boid::cohesion(std::vector<Boid>& boids) {
    CVector coh_vel(0, 0);
    int num_boids = 0;

    for (Boid& b : boids) {
        coh_vel += b.pos;
    }

    coh_vel /= Config::NUM_BOIDS;
    coh_vel -= pos;
    coh_vel = coh_vel.cap(Config::MAX_VEL);

    return coh_vel / 100;
}

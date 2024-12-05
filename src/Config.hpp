#ifndef CONFIG_HPP
#define CONFIG_HPP

namespace Config {
    static constexpr float DIST_THRESHOLD = 20.0;
    static constexpr float MAX_VEL = 1.0;
    static constexpr int NUM_BOIDS = 100;
    static constexpr float ALIGN_FACTOR = 1.0;
    static constexpr float SEPARATION_FACTOR = 5.0;
    static constexpr float COHESION_FACTOR = 1.0;
    static constexpr int WINDOW_WIDTH = 800;
    static constexpr int WINDOW_HEIGHT = 800;
    static constexpr float BOID_SIZE = 5.0;
    static constexpr float BOUNDARY_REPULSION_FACTOR = 100.0;
}

#endif // !CONFIG_HPP

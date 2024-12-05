#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Boid.hpp"
#include "cvector.hpp"
#include <vector>
#include "Config.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(Config::WINDOW_WIDTH, Config::WINDOW_HEIGHT), "Boid Simulation");

    std::vector<Boid> boids;
    for (int i = 0; i < Config::NUM_BOIDS; i++) {
        float init_pos_x = (rand() % Config::WINDOW_WIDTH);
        float init_pos_y = (rand() % Config::WINDOW_HEIGHT);

        float init_vel_x = ((rand() % 5) - 2);
        float init_vel_y = ((rand() % 5) - 2);

        boids.emplace_back(CVector(init_pos_x, init_pos_y), CVector(init_vel_x, init_vel_y), 1.0);
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::White);

        for (auto& b: boids) {
            b.update(boids);
            sf::CircleShape shape(Config::BOID_SIZE);
            shape.setPosition(b.pos.x, b.pos.y);
            shape.setFillColor(sf::Color::Red);
            window.draw(shape);
        }

        window.display();
    }

    return 0;
}

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "Boid.hpp"
#include "cvector.hpp"
#include <vector>

int main() {
    int windowWidth = 800;
    int windowHeight = 800;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Boid Simulation");

    std::vector<Boid> boids;
    for (int i = 0; i < 100; i++) {
        float init_pos_x = static_cast<float>(rand() % windowWidth);
        float init_pos_y = static_cast<float>(rand() % windowHeight);

        float init_vel_x = static_cast<float>((rand() % 5) - 2);
        float init_vel_y = static_cast<float>((rand() % 5) - 2);

        boids.emplace_back(CVector(init_pos_x, init_pos_y), CVector(init_vel_x, init_vel_y), 1.0);
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            window.clear(sf::Color::White);

            for (auto& b: boids) {
                b.update(boids);
                sf::CircleShape shape(5.f);
                shape.setPosition(b.pos.y, b.pos.x);
                shape.setFillColor(sf::Color::Black);
                window.draw(shape);
            }

            window.display();
        }
    }

    return 0;
}



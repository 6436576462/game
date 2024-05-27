#include "glfw3.h"
#include <vector>

#include "player.h"
#include "enemy.h"
#include "bullet.h"
#include "audio.h"

double previousTime = glfwGetTime();

extern std::vector<Bullet> bullets;
std::vector<Zombie> zombies;
const float collisionRadius = 0.15f;


void spawnZombie() {
    
    double currentTime = glfwGetTime();
    double interval = 1.5;
    
    int randnum = rand() % 9;
    if (currentTime - previousTime >= interval) {
        if (randnum == 0) {
            zombies.emplace_back(-1.0f, 1.0f, 0);
        }
        if (randnum == 1) {
            zombies.emplace_back(1.0f, -1.0f, 0);
        }
        if (randnum == 2) {
            zombies.emplace_back(-1.0f, -1.0f, 0);
        }
        if (randnum == 3) {
            zombies.emplace_back(1.0f, 1.0f, 0);
        }
        if (randnum == 4) {
            zombies.emplace_back(1.0f, 0, 0);
        }
        if (randnum == 5) {
            zombies.emplace_back(-1.0f, 0, 0);
        }
        if (randnum == 6) {
            zombies.emplace_back(-1.0f, 1.0f, 0);
            zombies.emplace_back(1.0f, 1.0f, 0);
        }
        if (randnum == 7) {
            zombies.emplace_back(-1.0f, -1.0f, 0);
            zombies.emplace_back(1.0f, -1.0f, 0);
        }
        if (randnum == 8) {
            zombies.emplace_back(1.0f, 0, 0);
            zombies.emplace_back(-1.0f, -1.0f, 0);
        }
        previousTime = currentTime; 
    }
}

void checkZombieCollisions() {
    for (int i = 0; i < zombies.size(); ++i) {
        for (int j = i + 1; j < zombies.size(); ++j) {
            float deltaX = zombies[j].pos_x - zombies[i].pos_x;
            float deltaY = zombies[j].pos_y - zombies[i].pos_y;
            float distance = sqrt(deltaX * deltaX + deltaY * deltaY);

            if (distance < collisionRadius) {
                float overlap = collisionRadius - distance;
                float adjustmentX = (deltaX / distance) * (overlap / 2.0f); 
                float adjustmentY = (deltaY / distance) * (overlap / 2.0f);

                zombies[i].pos_x -= adjustmentX;
                zombies[i].pos_y -= adjustmentY;

                zombies[j].pos_x += adjustmentX;
                zombies[j].pos_y += adjustmentY;
            }
        }
    }
}




void drawZombies() {
    for (std::vector<Zombie>::iterator it = zombies.begin(); it != zombies.end(); ++it) {
        it->drawEnemy();
    }
    checkZombieCollisions();
}

void moveZombies() {
    for (std::vector<Zombie>::iterator it = zombies.begin(); it != zombies.end(); ++it) {
        it->moveEnemy();
    }
}

void deleteZombiesAndBullet() {
    for (std::vector<Bullet>::iterator ib = bullets.begin(); ib != bullets.end();) {
        bool bulletHit = false;
        for (std::vector<Zombie>::iterator it = zombies.begin(); it != zombies.end();) {
            const Zombie& zombie = *it;
            const Bullet& bullet = *ib;
            float deltaX = zombie.pos_x - bullet.pos_x;
            float deltaY = zombie.pos_y - bullet.pos_y;
            float distance = sqrt(deltaX * deltaX + deltaY * deltaY);

            if (distance < zombie.radius) {
                it = zombies.erase(it);
                zombieDeathAudio();
                bulletHit = true; 
            }
            else {
                it++;
            }
        }
        if (bulletHit) {
            ib = bullets.erase(ib); 
        }
        else {
            ib++; 
        }
    }
}

void deleteAll(){
    if (player.died) {
        zombies.clear();
        player.pos_x = 0.0f;
        player.pos_y = 0.0f;
    }
}


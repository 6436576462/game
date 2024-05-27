#include "glfw3.h"
#include <iostream>
#include <vector>

#include"player.h"
#include "bullet.h"
#include "audio.h"

double reloadStartTime = 0.0;
std::vector<Bullet> bullets;

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
        double cursorPosX, cursorPosY;
        glfwGetCursorPos(window, &cursorPosX, &cursorPosY);
        if (!player.died && player.ammo > 0) {
            double cursorDirectionX = 2.0 * cursorPosX / 1620 - 1.0;
            double cursorDirectionY = 1.0 - 2.0 * cursorPosY / 1320;

            double bulletDirectionX = cursorDirectionX - player.pos_x;
            double bulletDirectionY = cursorDirectionY - player.pos_y;

            double length = sqrt(bulletDirectionX * bulletDirectionX + bulletDirectionY * bulletDirectionY);
            bulletDirectionX /= length;
            bulletDirectionY /= length;

            Bullet newBullet(player.pos_x, player.pos_y, player.rotation, bulletDirectionX, bulletDirectionY);
            bullets.push_back(newBullet);

            gunAudio();
            player.ammo -= 1;
        }
        if (player.died && (cursorPosX >= 770 && cursorPosX <= 850) && (cursorPosY >= 500 && cursorPosY <= 555)) {
            player.health = 10;
            player.ammo = 20;
            player.died = false;
        }
        reloadGun();
    }
}

void drawBullets() {
    for (std::vector<Bullet>::iterator it = bullets.begin(); it != bullets.end(); ++it) {
        it->draw();
    }
}

void updateBullets() {
    for (std::vector<Bullet>::iterator it = bullets.begin(); it != bullets.end();) {
        it->update();
        if (!it->alive) {
            it = bullets.erase(it);
        }
        else {
            ++it;
        }
    }
}


void reloadGun() {
    double currentTime = glfwGetTime();
   
    if (player.ammo <= 0 && !player.isReloading) {
        player.isReloading = true;
        reloadStartTime = currentTime; 
     
        reloadGunAudio();
    }

    if (player.isReloading && (currentTime - reloadStartTime >= 2.3)) {
        player.ammo = 20;
        player.isReloading = false; 
    }
}















#include "glfw3.h"
#include "GL/freeglut.h"
#include <cmath>
#include <iostream>
#include "Player.h"
#include <vector>
struct Bullet {
    Bullet(float x, float y, float rotation) : pos_x(x), pos_y(y), rotation(rotation) {}
    

    float pos_x;
    float pos_y;
    float rotation;

    void draw() {
        glPushMatrix();
        glTranslatef(pos_x, pos_y, 0);
        glRotatef(rotation, 0.0f, 0.0f, 1.0f);
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(250, 0, 0);
        for (float t = 0; t < 2 * 3.14; t += 0.01f) {
            float x = (0.291f + sin(t) / 115);
            float y = (cos(t) / 115 - 0.0005f);
            glVertex2f(x, y);
        }
        glEnd();
        glPopMatrix();
    }
    
    void update(GLFWwindow* window) {
        double cursorPosX, cursorPosY;
        glfwGetCursorPos(window, &cursorPosX, &cursorPosY);

        // –ассчитываем вектор направлени€ курсора
        double cursorDirectionX = 2.0 * cursorPosX / 1620 - 1.0;
        double cursorDirectionY = 1.0 - 2.0 * cursorPosY / 1320;

        // –ассчитываем вектор движени€ пули в направлении курсора
        double bulletDirectionX = cursorDirectionX - pos_x;
        double bulletDirectionY = cursorDirectionY - pos_y;

        // Ќормализуем вектор движени€ пули (чтобы его длина была равна 1)
        double length = sqrt(bulletDirectionX * bulletDirectionX + bulletDirectionY * bulletDirectionY);
        bulletDirectionX /= length;
        bulletDirectionY /= length;

        // ”станавливаем скорость пули (можете настроить по своему усмотрению)
        double bulletSpeed = 0.03;

        // ќбновл€ем позицию пули в направлении курсора
        pos_x += bulletDirectionX * bulletSpeed;
        pos_y += bulletDirectionY * bulletSpeed;

        if (pos_x == cursorDirectionX) {

        }
    }

    void _delete() {
        
        if (pos_x == this->pos_x) {

        }
    }


};

std::vector<Bullet> bullets;

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {

        /*double xPos, yPos;
        glfwGetCursorPos(window, &xPos, &yPos);
        std::cout << "Left mouse button pressed at position: (" << xPos << ", " << yPos << ")" << std::endl;
        */
        
        Bullet newBullet(player.pos_x, player.pos_y, player.rotation);
        bullets.push_back(newBullet);
        // «десь можно вызвать вашу функцию или выполнить другие действи€
    }
}

void drawBullets() {
    for (std::vector<Bullet>::iterator it = bullets.begin(); it != bullets.end(); ++it) {
        it->draw();
    }
}

void updateBullets(GLFWwindow* window) {
    for (std::vector<Bullet>::iterator it = bullets.begin(); it != bullets.end(); ++it) {
        it->update(window);
    }
}


void deleteBullets() {
    for (std::vector<Bullet>::iterator it = bullets.begin(); it != bullets.end(); ++it) {
        
    }
}










#include "glfw3.h"
#include <vector>

#include "player.h"
#include "audio.h"
#include "enemy.h"

Player player;

float step = 0.008f;
extern std::vector<Zombie> zombies;
double previousTimee = glfwGetTime();
const float collisionRadius = 0.11f;

void processKeys(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_W) {
        player.moveUp = (action == GLFW_PRESS || action == GLFW_REPEAT);
    }
    else if (key == GLFW_KEY_S) {
        player.moveDown = (action == GLFW_PRESS || action == GLFW_REPEAT);
    }
    else if (key == GLFW_KEY_A) {
        player.moveLeft = (action == GLFW_PRESS || action == GLFW_REPEAT);
    }
    else if (key == GLFW_KEY_D) {
        player.moveRight = (action == GLFW_PRESS || action == GLFW_REPEAT);
    }
}



bool checkCollision(float new_x, float new_y) {
    for (std::vector<Zombie>::iterator it = zombies.begin(); it != zombies.end(); ++it) {
        const Zombie& zombie = *it;
        float deltaX = new_x - zombie.pos_x;
        float deltaY = new_y - zombie.pos_y;
        float distance = sqrt(deltaX * deltaX + deltaY * deltaY);
        if (distance < collisionRadius) {
            return true;
        }
    }
    return false;
}

void updatePosition() {
    float new_x = player.pos_x;
    float new_y = player.pos_y;

    if (player.moveUp) {
        new_y += step;
    }
    if (player.moveDown) {
        new_y -= step;
    }
    if (player.moveLeft) {
        new_x -= step;
    }
    if (player.moveRight) {
        new_x += step;
    }

    if (new_x > 0.9f) 
        new_x = 0.9f;
    if (new_x < -0.9f) 
        new_x = -0.9f;
    if (new_y > 0.9f) 
        new_y = 0.9f;
    if (new_y < -0.9f) 
        new_y = -0.9f;

    if (!checkCollision(new_x, new_y)) {
        player.pos_x = new_x;
        player.pos_y = new_y;
    }
    
}

void cursorPositionCallback(GLFWwindow* window, double xPos, double yPos) {
    double angleX = 2.0 * xPos / 1620 - 1.0;
    double angleY = 1.0 - 2.0 * yPos / 1320;
    player.rotation = atan2(angleY - player.pos_y, angleX - player.pos_x) * 180 / 3.14f;
    //std::cout << "angleX: " << xPos << "\t" << "angleY " << yPos << "\t" << std::endl;
}

void takeDamage() {
    double currentTime = glfwGetTime(); 
    if ((currentTime - previousTimee) >= 1){
        previousTimee = currentTime;
        player.health -= 1;
        heroDamageAudio();
    }
    if (player.health <= 0) {
        player.died = true;
    }
}

void character(Player &player) {
    glPushMatrix();
    glTranslatef(player.pos_x, player.pos_y, 0);
    glRotatef(player.rotation, 0.0f, 0.0f, 1.0f);
   
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(213, 172, 129);
    
    for (float t = 0; t < 2 * 3.14; t += 0.01f) {
        float x = sin(t)/10;
        float y = cos(t)/10;
        glVertex2f(x, y);
    }
    glEnd();


    glTranslatef(0.06f, 0.0, 0);

    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0); 

    glVertex2f(0.025f, -0.021f);
    glVertex2f(0.075f, -0.021f);
    glVertex2f(0.075f, 0.021f);
    glVertex2f(0.025f, 0.021f);

    glVertex2f(0.075f, -0.007f);
    glVertex2f(0.125f, -0.007f);
    glVertex2f(0.125f, 0.007f);
    glVertex2f(0.075f, 0.007f);

    glVertex2f(0.125f, -0.003f);
    glVertex2f(0.175f, -0.003f);
    glVertex2f(0.175f, 0.003f);
    glVertex2f(0.125f, 0.003f);

    glVertex2f(0.175f, -0.009f);
    glVertex2f(0.225f, -0.009f);
    glVertex2f(0.225f, 0.009f);
    glVertex2f(0.175f, 0.009f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(213, 172, 129);

    for (float t = 0; t < 2 * 3.14; t += 0.01f) {
        float x = (0.05f + sin(t) / 44);
        float y = (cos(t) / 44 - 0.02f);
        glVertex2f(x, y);
    }
    glEnd();

    glLineWidth(3.0f);
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0); 
    for (float t = 0; t < 2 * 3.14; t += 0.01f) {
        float x = (0.05f + sin(t) / 44);
        float y = (cos(t) / 44 - 0.02f);
        glVertex2f(x, y);
    }
    glEnd();
    glPopMatrix();
}

void drawHealthBar() {
    
    glPushMatrix();
    glTranslatef(0.833f, 0.975f, 0);
    glBegin(GL_QUADS);
    glColor3ub(200, 0, 10);

    glVertex2f(0.05f * (player.health/ 3), 0.03f);
    glVertex2f(0.05f * (player.health / 3), -0.03f);
    glVertex2f(-0.05f * (player.health / 3), -0.03f);
    glVertex2f(-0.05f * (player.health / 3), 0.03f);

    glEnd();
    glPopMatrix();
}

void drawAmmoBar() {

    glPushMatrix();
    glTranslatef(0.833f, 0.915f, 0);
    glBegin(GL_QUADS);
    glColor3ub(60, 60, 60);

    glVertex2f(0.05f * (player.ammo / 6), 0.03f);
    glVertex2f(0.05f * (player.ammo / 6), -0.03f);
    glVertex2f(-0.05f * (player.ammo / 6), -0.03f);
    glVertex2f(-0.05f * (player.ammo / 6), 0.03f);

    glEnd();
    glPopMatrix();
}





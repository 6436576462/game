
#include "glfw3.h"
//#include "GL/freeglut.h"
#include <cmath>
#include <iostream>
#include "Player.h"



Player player;
float step = 0.008f;

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
void updatePosition() {
    if (player.moveUp) {
        player.pos_y += step;
    }
    if (player.moveDown) {
        player.pos_y -= step;
    }
    if (player.moveLeft) {
        player.pos_x -= step;
    }
    if (player.moveRight) {
        player.pos_x += step;
    }

    if (player.pos_x > 0.9) {
        player.pos_x = 0.9f;
    }
    else if (player.pos_x < -0.9) {
        player.pos_x = -0.9f;
    }

    if (player.pos_y > 0.9) {
        player.pos_y = 0.9f;
    }
    else if (player.pos_y < -0.9) {
        player.pos_y = -0.9f;
    }
}



void cursorPositionCallback(GLFWwindow* window, double xPos, double yPos) {
    //cout << "x: " << xPos  << "\t" <<  "y: " << yPos  << endl;
    double angleX = 2.0 * xPos / 1620 - 1.0;
    double angleY = 1.0 - 2.0 * yPos / 1320;
    std::cout << "x: " << angleX  << "\t" <<  "y: " << angleY  << std::endl;
    player.rotation = atan2(angleY - player.pos_y, angleX - player.pos_x) * 180 / 3.14f;
   

}


void circle(Player &player) {
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

    // Рукоятка
    glVertex2f(0.025f, -0.021f);
    glVertex2f(0.075f, -0.021f);
    glVertex2f(0.075f, 0.021f);
    glVertex2f(0.025f, 0.021f);

    // Приклад
    glVertex2f(0.075f, -0.007f);
    glVertex2f(0.125f, -0.007f);
    glVertex2f(0.125f, 0.007f);
    glVertex2f(0.075f, 0.007f);

    // Канал ствола
    glVertex2f(0.125f, -0.003f);
    glVertex2f(0.175f, -0.003f);
    glVertex2f(0.175f, 0.003f);
    glVertex2f(0.125f, 0.003f);

    // Задняя часть ствола
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



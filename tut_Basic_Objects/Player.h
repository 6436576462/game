#pragma once



struct Player {
    float pos_x = 0.0f;
    float pos_y = 0.0f;
    float rotation = 0.0f;

    bool moveUp = false;
    bool moveDown = false;
    bool moveLeft = false;
    bool moveRight = false;


} extern player;


void processKeys(GLFWwindow* window, int key, int scancode, int action, int mods);
void circle(Player& player);
void updatePosition();
void cursorPositionCallback(GLFWwindow* window, double xPos, double yPos);
void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
void drawBullets();
void updateBullets(GLFWwindow* window);





#pragma once

struct Player {
    float pos_x = 0.0f;
    float pos_y = 0.0f;
    float rotation = 0.0f;
    float position = 0.0f;
    float radius = 0.01f;

    float health = 10.0;
    float ammo = 20.0;

    bool died = false;
    bool isReloading;
    
    bool moveUp = false;
    bool moveDown = false;
    bool moveLeft = false;
    bool moveRight = false;


} extern player;


void processKeys(GLFWwindow* window, int key, int scancode, int action, int mods);
void character(Player& player);
void updatePosition();
void cursorPositionCallback(GLFWwindow* window, double xPos, double yPos);
void drawHealthBar();
void drawAmmoBar();








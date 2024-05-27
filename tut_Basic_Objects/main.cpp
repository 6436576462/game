
#include "glfw3.h"
#include <iostream>

#include"endgame.h"
#include "player.h"
#include "bullet.h"
#include "enemy.h"

int main() {
    if (!glfwInit()) {
        std::cout << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(1620, 1320, "game", nullptr, nullptr);
    if (!window) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    
    glfwMakeContextCurrent(window);
   
    glfwSetCursorPosCallback(window, cursorPositionCallback);
    glfwSetMouseButtonCallback(window, mouseButtonCallback);
    glfwSetKeyCallback(window, processKeys);

    srand(glfwGetTime());

    glClearColor(0.4f, 0.7f, 0.4f, 0);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glfwPollEvents();
  
        if (!player.died) {
            glClearColor(0.4f, 0.7f, 0.4f, 0);
            character(player);
            drawHealthBar();
            drawAmmoBar();
            updatePosition();
            drawBullets();
            updateBullets();
            spawnZombie();
            drawZombies();
            moveZombies();
            deleteZombiesAndBullet();
        }
        if (player.died) {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            glClearColor(0.0, 0.0, 0.0, 0);
            drawYouDied();
            loopButton();
            deleteAll();

        }
        glfwSwapBuffers(window);    
    
    }

    glfwTerminate();
    return 0;
}








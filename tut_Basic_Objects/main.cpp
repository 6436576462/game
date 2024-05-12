
#include "glfw3.h"
//#include "GL/freeglut.h"
#include <cmath>
#include <iostream>
#include"Player.h"
#include <vector>





int main() {
    
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(1620, 1320, "game", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    
    glfwMakeContextCurrent(window);

    glfwSetCursorPosCallback(window, cursorPositionCallback);
    glfwSetMouseButtonCallback(window, mouseButtonCallback);

    glfwSetKeyCallback(window, processKeys);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
        
        glClearColor(0.5, 0.7, 0.4, 0);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwPollEvents();
  

        circle(player);
        updatePosition();
        drawBullets();
        updateBullets(window);
    
        glfwSwapBuffers(window);    
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}








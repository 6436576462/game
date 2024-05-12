#include "glfw3.h"
#include "GL/freeglut.h"
#include <cmath>
#include <iostream>
/*
float pos_x = 0, pos_y = 0;
float xx = 0, yy = 0;
void renderScene(void);
void circle(float x, float y);
void processKeys(unsigned char key, int x, int y);
void lines();



int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(850, 850);
    glutCreateWindow("opneGl");
    glutDisplayFunc(renderScene);
    glutKeyboardFunc(processKeys);
    

    glutMainLoop();
    return 0;
}

void renderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glClearColor(0.5, 0.7, 0.4, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    circle(pos_x, pos_y);
    lines();
    void kvadrat();

    glutSwapBuffers();
}

void circle(float x, float y) {
    glPushMatrix();
    glTranslatef(x, y, 0);
    glRotatef(90, 0, 0, 1);
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(100, 2, 160);
    for (float t = 0; t < 2 * 3.14; t += 0.01) {
        float x = sin(t) / 10;
        float y = cos(t) / 10;
        glVertex2f(x, y);
    }

    glEnd();
    glPopMatrix();
}

void lines() {
    glBegin(GL_LINE_LOOP);
    glColor3ub(255, 0, 0);
    glVertex2f(1, 1);
    glVertex2f(-1, 1);
    glVertex2f(-1, -1);
    glVertex2f(1, -1);
    glEnd();
}

void kvadrat() {
    glBegin(GL_QUADS);
    glColor3ub(0, 255, 0);
    glVertex2f(1, 1);
    glVertex2f(-1, 1);
    glVertex2f(-1, -1);
    glVertex2f(1, -1);
    glEnd();
}   


void processKeys(unsigned char key, int x, int y) {
    const float step = 0.03;

    if ((key == 'd' || key == 'D') && pos_x < 0.9) { // d or D
        pos_x = pos_x + step;
    }
    if ((key == 'a' || key == 'A') && pos_x > -0.9) {
        pos_x = pos_x - step;
    }
    if ((key == 'w' || key == 'W') && pos_y < 0.9) {
        pos_y = pos_y + step;
    }
    if ((key == 's' || key == 'S') && pos_y > -0.9) {
        pos_y = pos_y - step;
    }

    if ((key == 'w' && glutGetModifiers() == GLUT_ACTIVE_SHIFT)) {
        if (pos_y < 1 && pos_x < 1) {
            pos_y += step / 2;
            pos_x += step / 2;
        }
    }
    else if ((key == 's' && glutGetModifiers() == GLUT_ACTIVE_SHIFT)) {
        if (pos_y > -1 && pos_x > -1) {
            pos_y -= step / 2;
            pos_x -= step / 2;
        }
    }
    else if ((key == 'a' && glutGetModifiers() == GLUT_ACTIVE_SHIFT)) {
        if (pos_x > -1 && pos_y < 1) {
            pos_x -= step / 2;
            pos_y += step / 2;
        }
    }
    else if ((key == 'd' && glutGetModifiers() == GLUT_ACTIVE_SHIFT)) {
        if (pos_x < 1 && pos_y > -1) {
            pos_x += step / 2;
            pos_y -= step / 2;
        }
    }


    if (key == 13)
        exit(0); // close app
    glutPostRedisplay(); // ���� ��� �������� animateScene
}
*/
/*
#include "glfw3.h"
#include "GL/freeglut.h"
#include <iostream>

float objectX = 0.0f;
float objectY = 0.0f;
float objectRotation = 0.0f; // ���������� ��� �������� ���� �������� �������

void cursorPositionCallback(GLFWwindow* window, double xPos, double yPos) {
    // �������� ������� ����
    int width, height;
    glfwGetWindowSize(window, &width, &height);

    // ����������� ���������� ������� ������������ ���� GLFW � ���������� OpenGL
    double oglX = 2.0 * xPos / width - 1.0;
    double oglY = 1.0 - 2.0 * yPos / height;

    // ������������ ���� ����� �������� � ��������
    float angle = atan2(oglY - objectY, oglX - objectX) * 180 / 3.14;

    // ������������� ���� �������� �������
    objectRotation = angle;
}

void drawObject() {
    glPushMatrix();
    // ���������� ������ � ��� ������� ����������
    glTranslatef(objectX, objectY, 0.0f);

    // ������������ ������ �� ���� objectRotation
    glRotatef(objectRotation, 0.0f, 0.0f, 1.0f);

    // ������������ ������ (��������, �������������)
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f); // ������� ����
    glVertex2f(-0.1f, -0.1f);
    glVertex2f(0.1f, -0.1f);
    glVertex2f(0.1f, 0.1f);
    glVertex2f(-0.1f, 0.1f);
    glEnd();

    glPopMatrix();
}

int main() {
    // ������������� GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // �������� ���� GLFW
    GLFWwindow* window = glfwCreateWindow(800, 600, "Object Facing Cursor", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // ��������� ��������� OpenGL
    glfwMakeContextCurrent(window);

    // ��������� ������� ��������� ������ ��� ������������ �������� �������
    glfwSetCursorPosCallback(window, cursorPositionCallback);

    // ������� ���� ���������
    while (!glfwWindowShouldClose(window)) {
        // ������� ������ ������
        glClear(GL_COLOR_BUFFER_BIT);

        // ��������� �������
        drawObject();

        // ���������� ������ � ��������� �������
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // ������������ �������� GLFW
    glfwTerminate();
    return 0;
}



*/
/*
#include "glfw3.h"
#include "GL/freeglut.h"
#include <iostream>

float objectX = 0.0f;
float objectY = 0.0f;
float objectRotation = 0.0f;

void cursorPositionCallback(GLFWwindow* window, double xPos, double yPos) {
    // ����������� ���������� ������� ������������ ���� GLFW � ���������� OpenGL
    double oglX = 2.0 * xPos / 800 - 1.0; // ������ ���� 800
    double oglY = 1.0 - 2.0 * yPos / 600; // ������ ���� 600

    // ������������ ���� ����� �������� � ��������
    objectRotation = atan2(oglY - objectY, oglX - objectX) * 180 / 3.14;
}

void processKeys(GLFWwindow* window, int key, int scancode, int action, int mods) {

    const float step = 0.03f;

    if (key == GLFW_KEY_W) {
        if (objectY < 0.9)
            objectY += step;

    }
    else if (key == GLFW_KEY_S) {
        if (objectY > -0.9)
            objectY -= step;

    }
    else if (key == GLFW_KEY_A) {
        if (objectX > -0.9)
            objectX -= step;

    }
    else if (key == GLFW_KEY_D) {
        if (objectX < 0.9)
            objectX += step;

    }
}

void drawObject() {
    glPushMatrix();
    // ���������� ������ � ��� ������� ����������
    glTranslatef(objectX, objectY, 0.0f);

    // ������������ ������ �� ���� objectRotation
    glRotatef(objectRotation, 0.0f, 0.0f, 1.0f);

    // ������������ ������ (��������, �������������)
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f); // ������� ����
    glVertex2f(-0.1f, -0.1f);
    glVertex2f(0.1f, -0.1f);
    glVertex2f(0.1f, 0.1f);
    glVertex2f(-0.1f, 0.1f);
    glEnd();

    glPopMatrix();
}

int main() {
    // ������������� GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // �������� ���� GLFW
    GLFWwindow* window = glfwCreateWindow(800, 600, "Object Facing Cursor", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // ��������� ��������� OpenGL
    glfwMakeContextCurrent(window);

    // ��������� ������� ��������� ������ ��� ������������ �������� ������� � ������� ������
    glfwSetCursorPosCallback(window, cursorPositionCallback);
    glfwSetKeyCallback(window, processKeys);

    // ������� ���� ���������
    while (!glfwWindowShouldClose(window)) {
        // ������� ������ ������
        glClear(GL_COLOR_BUFFER_BIT);

        // ��������� �������
        drawObject();

        // ���������� ������ � ��������� �������
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // ������������ �������� GLFW
    glfwTerminate();
    return 0;
}

*/
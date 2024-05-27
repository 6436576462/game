#include "freglut/include/freeglut.h"
//#include"glfw3.h"

void drawYouDied() {
    glColor3ub(255, 0, 0);

    glBegin(GL_LINES);

    glVertex2f(-0.4f, 0.5f); glVertex2f(-0.35f, 0.4f);
    glVertex2f(-0.35f, 0.4f); glVertex2f(-0.3f, 0.5f);
    glVertex2f(-0.35f, 0.4f); glVertex2f(-0.35f, 0.3f);

    glVertex2f(-0.25f, 0.4f); glVertex2f(-0.2f, 0.5f);
    glVertex2f(-0.2f, 0.5f); glVertex2f(-0.15f, 0.4f);
    glVertex2f(-0.15f, 0.4f); glVertex2f(-0.2f, 0.3f);
    glVertex2f(-0.2f, 0.3f); glVertex2f(-0.25f, 0.4f);

    glVertex2f(-0.1f, 0.5f); glVertex2f(-0.1f, 0.3f);
    glVertex2f(-0.1f, 0.3f); glVertex2f(-0.05f, 0.2f);
    glVertex2f(-0.05f, 0.2f); glVertex2f(0.0f, 0.3f);
    glVertex2f(0.0f, 0.3f); glVertex2f(0.0f, 0.5f);

    glVertex2f(0.1f, 0.5f); glVertex2f(0.1f, 0.3f);
    glVertex2f(0.1f, 0.5f); glVertex2f(0.15f, 0.45f);
    glVertex2f(0.15f, 0.45f); glVertex2f(0.15f, 0.35f);
    glVertex2f(0.15f, 0.35f); glVertex2f(0.1f, 0.3f);

    glVertex2f(0.2f, 0.5f); glVertex2f(0.2f, 0.45f);
    glVertex2f(0.2f, 0.4f); glVertex2f(0.2f, 0.3f);

    glVertex2f(0.25f, 0.5f); glVertex2f(0.3f, 0.5f);
    glVertex2f(0.25f, 0.5f); glVertex2f(0.25f, 0.4f);
    glVertex2f(0.25f, 0.4f); glVertex2f(0.3f, 0.4f);
    glVertex2f(0.25f, 0.4f); glVertex2f(0.25f, 0.3f);
    glVertex2f(0.25f, 0.3f); glVertex2f(0.3f, 0.3f);

    glVertex2f(0.35f, 0.5f); glVertex2f(0.35f, 0.3f);
    glVertex2f(0.35f, 0.5f); glVertex2f(0.4f, 0.45f);
    glVertex2f(0.4f, 0.45f); glVertex2f(0.4f, 0.35f);
    glVertex2f(0.4f, 0.35f); glVertex2f(0.35f, 0.3f);

    glEnd();
}

void loopButton() {
    glBegin(GL_QUADS);
    glColor3ub(50, 100, 230);

    glVertex2f(0.05f, 0.05f);
    glVertex2f(0.05f, -0.05f);
    glVertex2f(-0.05f, -0.05f);
    glVertex2f(-0.05f, 0.05f);

    glEnd();
}
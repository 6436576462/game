#pragma once


struct Bullet {
    Bullet(float x, float y, float rotation, float dirX, float dirY) : pos_x(x), pos_y(y), rotation(rotation), dir_x(dirX), dir_y(dirY) {}

    float pos_x;
    float pos_y;
    float rotation;
    float dir_x;
    float dir_y;
    bool alive = true;

    void draw() {
        glPushMatrix();
        glTranslatef(pos_x, pos_y, 0);
        glRotatef(rotation, 0.0f, 0.0f, 1.0f);
        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(0, 0, 0);
        for (float t = 0; t < 2 * 3.14; t += 0.01f) {
            float x = (0.291f + sin(t) / 115);
            float y = (cos(t) / 115 - 0.0005f);
            glVertex2f(x, y);
        }
        glEnd();
        glPopMatrix();
    }

    void update() {
        float bulletSpeed = 0.03;
        pos_x += dir_x * bulletSpeed;
        pos_y += dir_y * bulletSpeed;

        double epsilon = 0.01;
        if (pos_x < -1.0 || pos_x > 1.0 || pos_y < -1.0 || pos_y > 1.0) {
            alive = false;
            
        }
    }
};

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
void drawBullets();
void updateBullets();
void reloadGun();

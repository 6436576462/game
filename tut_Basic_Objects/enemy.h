#pragma once
#include<vector>

void takeDamage();

struct Zombie {
    Zombie(float x, float y, float rotation) : pos_x(x), pos_y(y), rotation(rotation)  {}
    float pos_x = 0.0f;
    float pos_y = 0.0f;
    float rotation = 0.0f;
    float radius = 0.1f;


    void moveEnemy() {
        float deltaX = player.pos_x - pos_x;
        float deltaY = player.pos_y - pos_y;

        rotation = atan2(deltaY, deltaX) * 180 / 3.14f;
        float distance = sqrt(deltaX * deltaX + deltaY * deltaY);
        if (distance < radius * 1.7) {
            takeDamage();
            return;
        }

        deltaX /= distance;
        deltaY /= distance;
  
        float speed = 0.01f;
       
        pos_x += deltaX * speed;
        pos_y += deltaY * speed;
        
    }

    void drawEnemy() {
        glPushMatrix();
        glTranslatef(pos_x, pos_y, 0);
        glRotatef(rotation, 0.0, 0.0f, 1.0f);

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(76, 0, 153);

        for (float t = 0; t < 2 * 3.14; t += 0.01f) {
            float x = sin(t) / 12;
            float y = cos(t) / 12;
            glVertex2f(x, y);
        }
        glEnd();

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(180, 0, 0);

        for (float t = 0; t < 2 * 3.14; t += 0.01f) {
            float x = (0.07f + sin(t) / 47);
            float y = (cos(t) / 47 - 0.05f);
            glVertex2f(x, y);
        }
        glEnd();
        glLineWidth(3.0f);

        glBegin(GL_LINE_LOOP);
        glColor3ub(0, 0, 0);
        for (float t = 0; t < 2 * 3.14; t += 0.01f) {
            float x = (0.07f + sin(t) / 47);
            float y = (cos(t) / 47 - 0.05f);
            glVertex2f(x, y);
        }
        glEnd();

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(180, 0, 0);

        for (float t = 0; t < 2 * 3.14; t += 0.01f) {
            float x = (0.07f + sin(t) / 47);
            float y = (cos(t) / 47 + 0.05f);
            glVertex2f(x, y);
        }
        glEnd();

        glBegin(GL_LINE_LOOP);
        glColor3ub(0, 0, 0);
        for (float t = 0; t < 2 * 3.14; t += 0.01f) {
            float x = (0.07f + sin(t) / 47);
            float y = (cos(t) / 47 + 0.05f);
            glVertex2f(x, y);
        }
        glEnd();

        glPopMatrix();
    }

};

void spawnZombie();
void drawZombies();
void moveZombies();
void deleteZombiesAndBullet();
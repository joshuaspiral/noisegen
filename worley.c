#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

double grid[SCREEN_HEIGHT * SCREEN_WIDTH];

int distance(x1, y1, x2, y2) { return sqrt((double) pow(x2 - x1, 2) + pow(y2 - y1, 2)); }
int main() {
    srand(time(0));

    const int featurePointLength = 100;
    Vector2 featurePoints[featurePointLength];
    for (int i = 0; i < featurePointLength; i++) {
        featurePoints[i].x = rand() % SCREEN_WIDTH;
        featurePoints[i].y = rand() % SCREEN_HEIGHT;
    }

    for (int i = 0; i < SCREEN_HEIGHT * SCREEN_WIDTH; i++) {
        int lowestDistance = distance(i % SCREEN_WIDTH, i / SCREEN_HEIGHT, featurePoints[0].y, featurePoints[0].x);
        for (int j = 0; j < featurePointLength; j++) {
            if (distance(i % SCREEN_WIDTH, i / SCREEN_HEIGHT, featurePoints[j].y, featurePoints[j].x) < lowestDistance)
                lowestDistance = distance(i % SCREEN_WIDTH, i / SCREEN_HEIGHT, featurePoints[j].y, featurePoints[j].x);
        }
        grid[i] = lowestDistance;
    }

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Worley Noise Generator");
    while (!WindowShouldClose()) {

        BeginDrawing();
        ClearBackground(WHITE);
        for (int i = 0; i < SCREEN_HEIGHT * SCREEN_WIDTH; i++) {
            Color color = {grid[i], grid[i], grid[i], 255};
            DrawPixel(i / SCREEN_WIDTH, i % SCREEN_WIDTH, color);
        }
        EndDrawing();
    }

    return 0;
}

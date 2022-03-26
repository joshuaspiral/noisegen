#include <math.h>
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

double grid[SCREEN_HEIGHT * SCREEN_WIDTH];

// euclidean distance
int distance(int x1, int y1, int z1, int x2, int y2, int z2) {
    return sqrt((double)pow(x1 - x2, 2) + pow(y1 - y2, 2) + pow(z1 - z2, 2));
}

Vector3 featurePoints[100];
const int featurePointCount = 100;

void updateGrid(int layer) {
    for (int i = 0; i < SCREEN_HEIGHT * SCREEN_WIDTH; i++) {
        int lowestDistance =
            distance(i % SCREEN_WIDTH, i / SCREEN_WIDTH, layer, featurePoints[0].y,
                    featurePoints[0].x, featurePoints[0].z);
        for (int j = 0; j < featurePointCount; j++) {
            if (distance(i / SCREEN_WIDTH, i % SCREEN_WIDTH, layer,
                        featurePoints[j].x, featurePoints[j].y,
                        featurePoints[j].z) < lowestDistance)
                lowestDistance = distance(i / SCREEN_WIDTH, i % SCREEN_WIDTH, layer,
                        featurePoints[j].x, featurePoints[j].y,
                        featurePoints[j].z);
        }
        grid[i] = lowestDistance;
    }
}

int main() {
    int layer = SCREEN_WIDTH / 2;
    for (int i = 0; i < featurePointCount; i++) {
        featurePoints[i].x = rand() % SCREEN_WIDTH;
        featurePoints[i].y = rand() % SCREEN_HEIGHT;
        featurePoints[i].z = rand() % SCREEN_WIDTH;
    }

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Worley Noise Generator");
    while (!WindowShouldClose()) {
        layer+=5;
        BeginDrawing();
        ClearBackground(WHITE);
        updateGrid(layer);
        for (int i = 0; i < SCREEN_HEIGHT * SCREEN_WIDTH; i++) {
            Color color = {grid[i], grid[i], grid[i], 255};
            DrawPixel(i / SCREEN_WIDTH, i % SCREEN_WIDTH, color);
        }
        EndDrawing();
    }

    return 0;
}

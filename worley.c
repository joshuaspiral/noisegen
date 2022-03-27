#include <math.h>
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 800

double grid[SCREEN_HEIGHT * SCREEN_WIDTH];

// euclidean distance
int distance(int x1, int y1, int x2, int y2) {
    return sqrt((double)pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

Vector2 featurePoints[100];
const int featurePointCount = 100;

void updateGrid() {
    for (int i = 0; i < SCREEN_HEIGHT * SCREEN_WIDTH; i++) {
        int lowestDistance =
            distance(i % SCREEN_WIDTH, i / SCREEN_WIDTH, featurePoints[0].y,
                    featurePoints[0].x);
        for (int j = 0; j < featurePointCount; j++) {
            if (distance(i / SCREEN_WIDTH, i % SCREEN_WIDTH,
                        featurePoints[j].x, featurePoints[j].y) < lowestDistance)
                lowestDistance = distance(i / SCREEN_WIDTH, i % SCREEN_WIDTH,
                        featurePoints[j].x, featurePoints[j].y
                        );
        }
        grid[i] = lowestDistance;
    }
}

int main() {
    srand(time(0));
    for (int i = 0; i < featurePointCount; i++) {
        featurePoints[i].x = rand() % SCREEN_WIDTH;
        featurePoints[i].y = rand() % SCREEN_HEIGHT;
    }

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Worley Noise Generator");
    updateGrid();
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        for (int i = 0; i < SCREEN_HEIGHT * SCREEN_WIDTH; i++) {
            Color color = {grid[i] , grid[i], grid[i], 255};
            DrawPixel(i / SCREEN_WIDTH, i % SCREEN_WIDTH, color);
        }
        EndDrawing();
    }

    return 0;
}

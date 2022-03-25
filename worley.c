#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define WIDTH 50
#define HEIGHT 50
#define SCREEN_WIDTH 500
#define SCREEN_HEIGHT 500

double grid[SCREEN_HEIGHT * SCREEN_WIDTH];

int distance(x1, x2, y1, y2) { return (abs(x1 - x2) + abs(y1 - y2)); }
int main() {
    srand(time(0));
    rand();
    rand();
    rand();
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Worley Noise Generator");
    for (int i = 0; i < SCREEN_HEIGHT * SCREEN_WIDTH; i++) {
        grid[i] = rand();
    }

    for (int i = 0; i < 8; i++) {
        grid[rand() % SCREEN_WIDTH] = 1;
        grid[rand() % SCREEN_HEIGHT] = 1;
    }

    for (int i = 0; i < SCREEN_HEIGHT * SCREEN_WIDTH; i++) {
        printf("%d\n", rand() % 1);
    }

    while (!WindowShouldClose()) {

        for (int i = 0; i < SCREEN_HEIGHT * SCREEN_WIDTH; i++) {
            Color color = {grid[i] * 255, grid[i] * 255, grid[i] * 255, 255};
            DrawPixel(i % SCREEN_WIDTH, i / SCREEN_WIDTH, color);
        }
        BeginDrawing();
        ClearBackground(WHITE);
        EndDrawing();
    }

    return 0;
}

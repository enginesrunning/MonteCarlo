#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Simularea pentru mers aleator 1D
int random_walk_1D(int steps) {
    int position = 0;
    for (int i = 0; i < steps; i++) {
        if (rand() % 2 == 0) {
            position++; // Move forward
        } else {
            position--; // Move backward
        }
    }
    return abs(position);
}

double simulate_random_walk_1D(int num_simulations, int steps) {
    int total_distance = 0;
    for (int i = 0; i < num_simulations; i++) {
        total_distance += random_walk_1D(steps);
    }
    return (double)total_distance / num_simulations;
}

// Simularea pentru mers aleator 2D (rețea dreptunghiulară)
void random_walk_2D(int steps, int* x, int* y) {
    for (int i = 0; i < steps; i++) {
        int direction = rand() % 4;
        switch (direction) {
            case 0: (*x)++; break; // North
            case 1: (*y)++; break; // East
            case 2: (*x)--; break; // South
            case 3: (*y)--; break; // West
        }
    }
}

double simulate_random_walk_2D(int num_simulations, int steps) {
    int total_distance = 0;
    for (int i = 0; i < num_simulations; i++) {
        int x = 0, y = 0;
        random_walk_2D(steps, &x, &y);
        total_distance += abs(x) + abs(y);
    }
    return (double)total_distance / num_simulations;
}

int main() {
    srand(time(NULL));

    // Problema 1: Mers aleator (1-dim.)
    int num_simulations_1D = 100000;
    int steps_1D = 100;
    double expected_distance_1D = simulate_random_walk_1D(num_simulations_1D, steps_1D);
    printf("Distanța medie după %d pași în 1D: %f\n", steps_1D, expected_distance_1D);

    // Problema 2: Mers aleator (2-dim.)
    int num_simulations_2D = 100000;
    int steps_2D = 50;
    double expected_distance_2D = simulate_random_walk_2D(num_simulations_2D, steps_2D);
    printf("Distanța medie după %d pași în 2D: %f\n", steps_2D, expected_distance_2D);

    return 0;
}

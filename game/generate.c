#include "game.h"

int *generateQuestions(unsigned int lower_bound, unsigned int upper_bound) {
    int size = 5, current_size = 0;
    bool *visited = (bool *) calloc(upper_bound + 1, sizeof(false));
    int *result = (int *) malloc(size * sizeof(int));
    while (current_size < size) {
        int unique = getRandomQuestion(lower_bound, upper_bound);
        if (!visited[unique]) {
            result[current_size++] = unique;
            visited[unique] = true;
        }
    }
    return result;
}
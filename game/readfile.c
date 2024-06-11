#include "game.h"

char *read_file(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == nullptr) {
        perror("Failed to open file");
        return nullptr;
    }
    fseek(file, 0, SEEK_END);
    long len = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *content = (char *) malloc(len + 1);
    if (content) {
        fread(content, 1, len, file);
        content[len] = '\0';
    }
    fclose(file);
    return content;
}

void read_questions(cJSON *json_array, Question **questions, int *questions_count) {
    int count = cJSON_GetArraySize(json_array);
    *questions = (Question *) malloc(count * sizeof(Question));
    *questions_count = count;
    printf("count = %d\n", count);
    for (int i = 0; i < count; ++i) {
        cJSON *json_question = cJSON_GetArrayItem(json_array, i);
        cJSON *content = cJSON_GetObjectItemCaseSensitive(json_question, "content");
        cJSON *answers = cJSON_GetObjectItemCaseSensitive(json_question, "answers");
        cJSON *correct_answer = cJSON_GetObjectItemCaseSensitive(json_question, "correct_answer");

        (*questions)[i].content = content ? strdup(content->valuestring) : nullptr;
        (*questions)[i].answers[0] = answers ? strdup(cJSON_GetObjectItemCaseSensitive(answers, "A")->valuestring) : nullptr;
        (*questions)[i].answers[1] = answers ? strdup(cJSON_GetObjectItemCaseSensitive(answers, "B")->valuestring) : nullptr;
        (*questions)[i].answers[2] = answers ? strdup(cJSON_GetObjectItemCaseSensitive(answers, "C")->valuestring) : nullptr;
        (*questions)[i].answers[3] = answers ? strdup(cJSON_GetObjectItemCaseSensitive(answers, "D")->valuestring) : nullptr;
        (*questions)[i].correct_answer = correct_answer ? strdup(correct_answer->valuestring) : "\0";
    }
}

void saveData(Question **db, int *data_count) {
    const char *filename = "D:/code/Repositories/raylib_project/test.json";
    char *file_content = read_file(filename);
    if (!file_content) {
        return;
    }
    cJSON *json = cJSON_Parse(file_content);
    free(file_content);
    if (!json) {
        printf("Error parsing JSON\n");
        return;
    }
    read_questions(cJSON_GetObjectItemCaseSensitive(json, "1-5"), db, data_count);
    cJSON_Delete(json);
}
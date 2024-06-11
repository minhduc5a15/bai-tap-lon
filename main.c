#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cjson/cJSON.h>

// Hàm đọc nội dung của tệp JSON
char *read_file(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *content = (char *) malloc(length + 1);
    if (content) {
        fread(content, 1, length, file);
        content[length] = '\0';
    }

    fclose(file);
    return content;
}

// Hàm tạo cấu trúc câu hỏi
typedef struct {
    char *content;
    char *answers[4];
    char *correct_answer;
} Question;

// Hàm đọc các câu hỏi từ JSON
void read_questions(cJSON *json_array, Question **questions, int *question_count) {
    int count = cJSON_GetArraySize(json_array);
    *questions = (Question *) malloc(count * sizeof(Question));
    *question_count = count;

    for (int i = 0; i < count; ++i) {
        cJSON *json_question = cJSON_GetArrayItem(json_array, i);
        cJSON *content = cJSON_GetObjectItemCaseSensitive(json_question, "content");
        cJSON *answers = cJSON_GetObjectItemCaseSensitive(json_question, "answers");
        cJSON *correct_answer = cJSON_GetObjectItemCaseSensitive(json_question, "correct_answer");

        (*questions)[i].content = content ? strdup(content->valuestring) : NULL;
        (*questions)[i].answers[0] = answers ? strdup(cJSON_GetObjectItemCaseSensitive(answers, "A")->valuestring) : NULL;
        (*questions)[i].answers[1] = answers ? strdup(cJSON_GetObjectItemCaseSensitive(answers, "B")->valuestring) : NULL;
        (*questions)[i].answers[2] = answers ? strdup(cJSON_GetObjectItemCaseSensitive(answers, "C")->valuestring) : NULL;
        (*questions)[i].answers[3] = answers ? strdup(cJSON_GetObjectItemCaseSensitive(answers, "D")->valuestring) : NULL;
        (*questions)[i].correct_answer = correct_answer ? strdup(correct_answer->valuestring) : NULL;
    }
}

int main() {
    // Đọc nội dung của tệp JSON
    const char *filename = "D:/code/Repositories/raylib_project/test.json";
    char *file_content = read_file(filename);
    if (!file_content) {
        return 1;
    }

    // Phân tích cú pháp JSON
    cJSON *json = cJSON_Parse(file_content);
    free(file_content);  // Giải phóng bộ nhớ cho nội dung tệp đã đọc
    if (!json) {
        printf("Error parsing JSON\n");
        return 1;
    }

    // Tạo mảng câu hỏi cho các nhóm 1-5, 5-10, và 11-15
    Question *questions_1_5 = nullptr;
    int question_count_1_5 = 0;
    Question *questions_5_10 = nullptr;
    int question_count_5_10 = 0;
    Question *questions_11_15 = nullptr;
    int question_count_11_15 = 0;

    // Đọc các câu hỏi từ JSON
    read_questions(cJSON_GetObjectItemCaseSensitive(json, "1-5"), &questions_1_5, &question_count_1_5);
    read_questions(cJSON_GetObjectItemCaseSensitive(json, "5-10"), &questions_5_10, &question_count_5_10);
    read_questions(cJSON_GetObjectItemCaseSensitive(json, "11-15"), &questions_11_15, &question_count_11_15);

    // In ra các câu hỏi để kiểm tra
    printf("Questions 1-5:\n");
    for (int i = 0; i < question_count_1_5; ++i) {
        printf("Question %d: %s\n", i + 1, questions_1_5[i].content);
        printf("A: %s\n", questions_1_5[i].answers[0]);
        printf("B: %s\n", questions_1_5[i].answers[1]);
        printf("C: %s\n", questions_1_5[i].answers[2]);
        printf("D: %s\n", questions_1_5[i].answers[3]);
        printf("Correct Answer: %s\n", questions_1_5[i].correct_answer);
    }

    // Giải phóng bộ nhớ
    cJSON_Delete(json);
    free(questions_1_5);
    free(questions_5_10);
    free(questions_11_15);

    return 0;
}

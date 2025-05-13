#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int N;

    printf("Введіть розмір вхідного масиву: ");
    scanf("%i", &N);

    int *input_arr = (int *)malloc(N * sizeof(int));
    if (input_arr == NULL) {
        printf("Помилка виділення пам'яті");
        return 1;
    }

    // Заповнення масиву випадковими значеннями
    srand(time(NULL));
    printf("Вхідний масив з випадкових чисел:\n");
    for (int i = 0; i < N; i++) {
        input_arr[i] = rand() % 200 - 100;
        printf("%i ", input_arr[i]);
    }
    printf("\n");

    // Пошук послідовності позитивних чисел з максимальною сумою
    int max_sum = 0, current_sum = 0;
    int max_start = -1, max_length = 0;
    int current_start = 0;

    for (int i = 0; i < N; i++) {
        if (input_arr[i] > 0) {
            if (current_sum == 0) {
                current_start = i;
            }
            current_sum += input_arr[i];
        } else {
            if (current_sum > max_sum) {
                max_sum = current_sum;
                max_start = current_start;
                max_length = i - current_start;
            }
            current_sum = 0;
        }
    }

    // Перевірка останньої послідовності
    if (current_sum > max_sum) {
        max_sum = current_sum;
        max_start = current_start;
        max_length = N - current_start;
    }

    if (max_length == 0) {
        printf("Немає позитивної підпослідовності.\n");
    } else {
        int *output_arr = (int *)malloc(max_length * sizeof(int));
        if (output_arr == NULL) {
            printf("Помилка виділення пам'яті для вихідного масиву\n");
            free(input_arr);
            return 1;
        }

        for (int i = 0; i < max_length; i++) {
            output_arr[i] = input_arr[max_start + i];
        }

        printf("Максимальна безперервна послідовність позитивних чисел із сумою %d:\n", max_sum);
        for (int i = 0; i < max_length; i++) {
            printf("%d ", output_arr[i]);
        }
        printf("\n");

        free(output_arr);
    }

    free(input_arr);
    return 0;
}

#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Qwert";
    int len = strlen(str);
    char* ptr_arr[len]; // масив вказівників

    for (int i = 0; i < len; i++) {
        ptr_arr[i] = &str[i];
    }

    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (*ptr_arr[i] > *ptr_arr[j]) {
                char* temp = ptr_arr[i];
                ptr_arr[i] = ptr_arr[j];
                ptr_arr[j] = temp;
            }
        }
    }

    printf("Відсортовані літери:\n");
    for (int i = 0; i < len; i++) {
        printf("%c ", *ptr_arr[i]);
    }
    printf("\n");

    return 0;
}

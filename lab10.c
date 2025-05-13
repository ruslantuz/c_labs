#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int is_punctuation(char c) {
    return (c >= 33 && c <= 47) || (c >= 58 && c <= 64) ||
           (c >= 91 && c <= 96) || (c >= 123 && c <= 126);
}

int is_symmetric(const char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++)
        if (*(str + i) != *(str + len - 1 - i))
            return 0;
    return 1;
}

int count_words(const char* str) {
    int count = 0, in_word = 0;
    while (*str) {
        if (isspace(*str)) {
            in_word = 0;
        } else if (!in_word) {
            count++;
            in_word = 1;
        }
        str++;
    }
    return count;
}

int main() {
    char *str;
    str = (char *)malloc(100 * sizeof(char));

    if (str == NULL) {
        printf("Помилка виділення пам'яті\n");
        return 1;
    }
    printf("Введіть рядок: ");
    scanf(" %[^\n]", str); 
    
    // 1. Підрахунок нулів і одиниць
    int zeros = 0, ones = 0;
    for (char *p = str; *p; p++) {
        if (*p == '0') zeros++;
        if (*p == '1') ones++;
    }
    printf("\n1. Кількість нулів: %d, одиниць: %d\n", zeros, ones);
    
    // 2. Літери 'R' та 'S'
    int r_count = 0, s_count = 0;
    for (char *p = str; *p; p++) {
        if (*p == 'R') r_count++;
        if (*p == 'S') s_count++;
    }
    printf("2. 'R': %d, 'S': %d\n", r_count, s_count);
    
    // 3. Баланс дужок
    int balance = 0, balanced = 1;
    for (char *p = str; *p; p++) {
        if (*p == '(') balance++;
        if (*p == ')') balance--;
        if (balance < 0) balanced = 0;
    }
    if (balance != 0) balanced = 0;
    printf("3. Баланс дужок: %s\n", balanced ? "так" : "ні");
    
    // 4. Симетричність
    int sym = is_symmetric(str);
    printf("4. Симетричний: %s\n", sym ? "так" : "ні");
    
    // 5. Цифри 5 і 7
    int has_5 = 0, has_7 = 0;
    for (char *p = str; *p; p++) {
        if (*p == '5') has_5 = 1;
        if (*p == '7') has_7 = 1;
    }
    printf("5. Містить '5': %s, '7': %s\n", has_5 ? "так" : "ні", has_7 ? "так" : "ні");
    
    // 6. Кількість слів
    int word_count = count_words(str);
    printf("6. Кількість слів: %d\n", word_count);
    
    // 7. Подвоєння літер
    int doubled = 0;
    for (char *p = str; *(p + 1); p++) {
        if (isalpha(*p) && *p == *(p + 1)) {
            doubled = 1;
            break;
        }
    }
    printf("7. Подвоєння літер: %s\n", doubled ? "так" : "ні");
    
    // 8. Знаки пунктуації
    int punctuation = 0;
    for (char *p = str; *p; p++) {
        if (is_punctuation(*p)) punctuation++;
    }
    printf("8. Знаків пунктуації: %d\n", punctuation);
    
    // 9. Сполучення "ED" або "ed"
    int ed_count = 0;
    for (char *p = str; *(p + 1); p++) {
        if ((p[0] == 'E' && p[1] == 'D') || (p[0] == 'e' && p[1] == 'd')) ed_count++;
    }
    printf("9. 'ED'/'ed' входить: %d раз(ів)\n", ed_count);
    
    // 10. Слова, що починаються з 'a'
    int a_start = 0, in_word = 0;
    for (char *p = str; *p; p++) {
        if (isspace(*p)) in_word = 0;
        else if (!in_word) {
            if (*p == 'a') a_start++;
            in_word = 1;
        }
    }
    printf("10. Слів з 'a': %d\n", a_start);
    
    // 11. Кількість '\' після '#'
    int found_hash = 0, slash_after_hash = 0;
    for (char *p = str; *p; p++) {
        if (*p == '#') found_hash = 1;
        else if (found_hash && *p == '\\') slash_after_hash++;
    }
    printf("11. '\\' після '#': %d\n", slash_after_hash);
    
    // 12. Сьома з кінця - 'S' чи 'W'
    int s_or_w = 0;
    int length = strlen(str);
    if (length >= 7 && (str[length - 7] == 'S' || str[length - 7] == 'W')) s_or_w = 1;
    printf("12. 7-а з кінця — 'S' чи 'W': %s\n", s_or_w ? "так" : "ні");
    
    // 13. 'S' через один перед '1'
    int s_1_pattern = 0;
    for (char *p = str; *(p + 2); p++) {
        if (*p == 'S' && *(p + 2) == '1') {
            s_1_pattern = 1;
            break;
        }
    }
    printf("13. 'S' через один перед '1': %s\n", s_1_pattern ? "так" : "ні");
    
    // 14. Слова з 'a' на початку та 's' у кінці
    int a_s_words = 0;
    char word[100];
    int idx = 0;
    for (char *p = str; ; p++) {
        if (*p && !isspace(*p)) {
            word[idx++] = *p;
        } else {
            if (idx > 0) {
                word[idx] = '\0';
                if (word[0] == 'a' && word[idx - 1] == 's') a_s_words++;
            }
            idx = 0;
        }
        if (!*p) break;
    }
    printf("14. Слів з 'a' на початку і 's' у кінці: %d\n", a_s_words);
    
    // 15. Кількість 'S' у першій половині
    int s_half = 0;
    int half_len = length / 2;
    for (int i = 0; i < half_len; i++) {
        if (*(str + i) == 'S') s_half++;
    }
    printf("15. 'S' у першій половині: %d\n", s_half);
    
    // 16. Слова нових речень з великої літери
    int new_sentence_cap = 1, all_upper = 1;
    for (char *p = str; *p; p++) {
        if (*p == '.' || *p == '!' || *p == '?') {
            new_sentence_cap = 1;
        } else if (new_sentence_cap && isalpha(*p)) {
            if (!isupper(*p)) {
                all_upper = 0;
                break;
            }
            new_sentence_cap = 0;
        }
    }
    printf("16. Речення починаються з великої: %s\n", all_upper ? "так" : "ні");
    
    free(str);
    return 0;
}

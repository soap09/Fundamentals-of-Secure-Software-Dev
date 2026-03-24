#include <stdio.h>
#include <string.h>

#define MAX_ATTEMPTS 3
#define MAX_LEN 50

int res(void);  
int pec(void);
int ctr(void);

int main() {
    char login[MAX_LEN];
    char password[MAX_LEN];
    
    char CORRECT_LOGIN[MAX_LEN];
    char CORRECT_PASSWORD[MAX_LEN];
    int attempts = 0;
    int login_success = 0;
    const char* filename = "./text.txt";

    FILE* fp = fopen(filename, "r");
    if (!fp) {
        printf("Ошибка чтения файла\n");
        return 1;
    }

    if (fgets(CORRECT_LOGIN, MAX_LEN, fp) == NULL) {
        printf("Ошибка чтения файла\n");
        fclose(fp);
        return 1;
    }

    CORRECT_LOGIN[strcspn(CORRECT_LOGIN, "\n")] = '\0';

    if (fgets(CORRECT_PASSWORD, MAX_LEN, fp) == NULL) {
        printf("Ошибка чтения файла\n");
        fclose(fp);
        return 1;
    }

    CORRECT_PASSWORD[strcspn(CORRECT_PASSWORD, "\n")] = '\0';

    fclose(fp);

    printf("Добро пожаловать! Пожалуйста, авторизируйтесь.\n");

    while (attempts < MAX_ATTEMPTS) {
        attempts++;
        printf("\nПопытка %d из %d:\n", attempts, MAX_ATTEMPTS);

        printf("Введите логин: ");
        scanf("%49s", login);

        printf("Введите пароль: ");
        scanf("%49s", password);

        if (strcmp(login, CORRECT_LOGIN) == 0 && strcmp(password, CORRECT_PASSWORD) == 0) {
            login_success = 1;
            break;
        } else {
            printf("Неверный логин или пароль\n");
        }
    }

    if (login_success) {
        printf("\nВход выполнен! Добро пожаловать в систему!\n");
        
        int choice;
        while (1) {
            printf("\nВыберите программу для запуска:\n");
            printf("1 — Программа №1 (пересечение треугольника с кругом)\n");
            printf("2 — Программа №2 (системы счисления)\n");
            printf("3 — Программа №3 (римские числа)\n");
            printf("0 — Выход\n");
            printf("Введите номер программы: ");

            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    res();
                    break;
                case 2:
                    pec();
                    break;
                case 3:
                    ctr();
                    break;
                case 0:
                    printf("Выход из программы.\n");
                    return 0;
                default:
                    printf("Неверный выбор!\n");
            }
        }
    } else {
        printf("\nПревышено количество попыток. Программа завершается.\n");
    }

    return 0;
}
#include <stdio.h>
#include <windows.h>
#define MOD 12345

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n;
    printf("Введіть довжину послідовності n: ");
    scanf("%d", &n);

    if (n <= 1 || n >= 10000) {
        printf("Довжина послідовності повинна бути між 1 та 10000.\n");
        return 1;
    }

    // Масиви для зберігання кількості послідовностей для кожної довжини
    int dp0[n + 1];
    int dp1[n + 1];
    int dp2[n + 1];

    // Ініціалізація базових випадків
    dp0[1] = 1; // 0
    dp1[1] = 1; // 1
    dp2[1] = 0; // недопустимий випадок для n=1

    for (int i = 2; i <= n; i++) {
        dp0[i] = (dp0[i - 1] + dp1[i - 1] + dp2[i - 1]) % MOD;
        dp1[i] = dp0[i - 1] % MOD;
        dp2[i] = dp1[i - 1] % MOD;
    }

    // Результат - сума всіх допустимих кінцевих станів
    int result = (dp0[n] + dp1[n] + dp2[n]) % MOD;
    printf("Кількість допустимих послідовностей: %d\n", result);

    return 0;
}

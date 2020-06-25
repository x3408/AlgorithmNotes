//
// Created by x3408 on 2020/6/25.
//
#include <cstdio>
#include <cstring>
const int maxn = 200;
int main() {
    char str[maxn];

    while (gets(str)) {
        for (int i = 0; i < strlen(str); ++i) {
            for (int j = 0; j < strlen(str)-1; ++j) {
                if (strcmp(&str[j],&str[j+1]) > 0) {
                    char temp = str[j];
                    str[j] = str[j + 1];
                    str[j+1] = temp;
                }
            }
        }

        for (int i = 0; i < strlen(str); ++i) {
            printf("%c", str[i]);
        }
        printf("\n");
    }
}

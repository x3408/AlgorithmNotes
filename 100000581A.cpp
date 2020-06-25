//
// Created by x3408 on 2020/6/24.
// scanf是读取空格就停下来
//
#include <iostream>
const int maxn = 10010;
int main() {
    int count;
    int num[maxn] = {0};

    while (scanf("%d", &count) != EOF) {
        for (int i = 0; i < count; ++i) {
            scanf("%d", &num[i]);
        }

        int temp;
        for (int i = 0; i < count-1; i++) {
            for (int j = 0; j < count-1; ++j) {
                if (num[j] > num [j+1]) {
                    temp = num[j];
                    num[j] = num[j+1];
                    num[j+1] = temp;
                }
            }
        }

        for (int i = 0; i < count; ++i) {
            printf("%d ", num[i]);
        }
        printf("\n");
    }
}
//
// Created by x3408 on 2020/6/24.
// scanf�Ƕ�ȡ�ո��ͣ����
//
#include <iostream>
const int maxn = 10010;
int main() {
    int count;
    int num[maxn] = {0};
    scanf("%d", &count);

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
}
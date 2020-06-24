//
// Created by x3408 on 2020/6/24.
// 这里演示了对数的存储，但对于字符串改怎么办
// 就可以使用除留余数法
//
#include <cstdio>
const int maxn = 10010;
bool hashTable1[maxn] = {false};
int hashTable2[maxn] = {0};
int main() {
    int A,B;
    int temp;

//判断一个集合中的数有没有在另一个集合中出现过
    scanf("%d %d",&A, &B);
    //输入A个数据，将table的对应位置置为true
    for (int i = 0; i < A; ++i) {
        scanf("%d", &temp);
        hashTable1[temp] = true;
    }
    for (int j = 0; j < B; ++j) {
        scanf("%d", &temp);
        if (hashTable1[temp] == true) {
            printf("已经存在");
        } else {
            printf("不存在");
        }
    }

//升级版 判断在另一个集合中出现了几次
    scanf("%d %d",&A, &B);
    //输入A个数据，将table的对应位置置为true
    for (int i = 0; i < A; ++i) {
        scanf("%d", &temp);
        hashTable2[temp]++;
    }
    for (int j = 0; j < B; ++j) {
        scanf("%d", &temp);
        if (hashTable2[temp] != 0) {
            printf("出现过%d次",hashTable2[temp]++);
        } else {
            printf("未出现过");
        }
    }
}



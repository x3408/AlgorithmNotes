//
// Created by x3408 on 2020/6/24.
// ������ʾ�˶����Ĵ洢���������ַ�������ô��
// �Ϳ���ʹ�ó���������
//
#include <cstdio>
const int maxn = 10010;
bool hashTable1[maxn] = {false};
int hashTable2[maxn] = {0};
int main() {
    int A,B;
    int temp;

//�ж�һ�������е�����û������һ�������г��ֹ�
    scanf("%d %d",&A, &B);
    //����A�����ݣ���table�Ķ�Ӧλ����Ϊtrue
    for (int i = 0; i < A; ++i) {
        scanf("%d", &temp);
        hashTable1[temp] = true;
    }
    for (int j = 0; j < B; ++j) {
        scanf("%d", &temp);
        if (hashTable1[temp] == true) {
            printf("�Ѿ�����");
        } else {
            printf("������");
        }
    }

//������ �ж�����һ�������г����˼���
    scanf("%d %d",&A, &B);
    //����A�����ݣ���table�Ķ�Ӧλ����Ϊtrue
    for (int i = 0; i < A; ++i) {
        scanf("%d", &temp);
        hashTable2[temp]++;
    }
    for (int j = 0; j < B; ++j) {
        scanf("%d", &temp);
        if (hashTable2[temp] != 0) {
            printf("���ֹ�%d��",hashTable2[temp]++);
        } else {
            printf("δ���ֹ�");
        }
    }
}



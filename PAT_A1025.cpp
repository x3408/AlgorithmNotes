#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
//
// Created by x3408 on 2020/6/22.
// ���뿼������ ��һ�������� �����źͷ��� �ڶ��������������š�����
// ��������� ������ �������������а༶�� ������ ��������
//
typedef struct Student {
    char id[10];
    int score;
    int locationNumber;
    int locationRange;
}stu;

stu finalList[100];

bool cmp(stu a, stu b) {
    if (a.score != b.score) {
        return a.score>b.score;
    } else {
        return strcmp(a.id,b.id)<0; //������ͬ����������С�ķ���ǰ��
    }
}

int main() {
    int local,localNum=0,totalNum=0;        //��������������������������
    scanf("%d", &local);
    for (int i = 0; i < local; ++i) {
        //���һ������������
        scanf("%d", &localNum);
        for (int j = 0; j < localNum; ++j) {
            scanf("%s %d",finalList[totalNum].id,&finalList[totalNum].score);
            finalList[totalNum].locationNumber = i+1;
            totalNum++;
        }

        //��ʼ����
        sort(finalList+totalNum-localNum, finalList+totalNum, cmp);
        //���ÿ�����һλ������Ϊһ ���ʱ�Ϳ���ֱ�ӱȽ����
        finalList[totalNum-localNum].locationRange = 1;
        for (int k = totalNum-localNum+1; k < totalNum; ++k) {
            if (finalList[k].score != finalList[k-1].score) finalList[k].locationRange = k+1-(totalNum-localNum);
            else finalList[k].locationRange = finalList[k-1].locationRange;
        }
    }
    sort(finalList,finalList+totalNum,cmp);
    int r = 1;
    printf("%s %d %d %d\n",finalList[0].id,r,finalList->locationNumber,finalList->locationRange);
    for (int l = 1; l < totalNum; ++l) {
        if (finalList[l].score != finalList[l-1].score) {
            //������ͬ�������+1������
            printf("%s %d %d %d\n",finalList[l].id,l+1,finalList[l].locationNumber,finalList[l].locationRange);
            r=l+1;
        }
        else
            printf("%s %d %d %d\n",finalList[l].id,r,finalList[l].locationNumber,finalList[l].locationRange);
    }
    return 0;
}
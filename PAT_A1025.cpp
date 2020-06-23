#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
//
// Created by x3408 on 2020/6/22.
// 输入考场个数 第一考场人数 考生号和分数 第二考场人数考生号。。。
// 输出总人数 考生号 最终排名（所有班级） 考场号 考场排名
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
        return strcmp(a.id,b.id)<0; //分数相同，将考生号小的放在前面
    }
}

int main() {
    int local,localNum=0,totalNum=0;        //考场数、单考场人数、总人数
    scanf("%d", &local);
    for (int i = 0; i < local; ++i) {
        //获得一个考场的数据
        scanf("%d", &localNum);
        for (int j = 0; j < localNum; ++j) {
            scanf("%s %d",finalList[totalNum].id,&finalList[totalNum].score);
            finalList[totalNum].locationNumber = i+1;
            totalNum++;
        }

        //开始排名
        sort(finalList+totalNum-localNum, finalList+totalNum, cmp);
        //将该考场第一位排名作为一 输出时就可以直接比较输出
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
            //分数不同输出人数+1总排名
            printf("%s %d %d %d\n",finalList[l].id,l+1,finalList[l].locationNumber,finalList[l].locationRange);
            r=l+1;
        }
        else
            printf("%s %d %d %d\n",finalList[l].id,r,finalList[l].locationNumber,finalList[l].locationRange);
    }
    return 0;
}
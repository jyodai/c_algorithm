// 自然数nまでの素数をすべて求める

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int getNum()
{
    int a;
    printf("数値を入力してください\n");
    scanf("%d",&a);
    return a;
}

void validation(int num)
{
    if (num <= 0) {
        printf("自然数を入力してください\n");
        exit(0);
    }
}

void algorithm(int num, int *primeNumber)
{
    int data[num + 1];
    for (int i=0; i<num+1; i++) {
        data[i] = 1;
    }

    for (int i=0; i<num+1; i++) {
        if (i == 0 || i == 1) {
            data[i] = 0;
            continue;
        }
        if (data[i] == 0) {
            continue;
        }

        int multiple = 2;
        while (multiple * i <= num) {
            data[multiple * i] = 0;
            multiple++;
        }
    }

    for (int i=0; i<num+1; i++) {
        if (data[i] == 1) {
            *primeNumber = i;
        } else {
            *primeNumber = 0;
        }
        ++primeNumber;
    }

}

void test()
{
    printf("testを開始します\n");
    printf("testが終了しました\n");
    exit(0);
}

void run()
{
    int num = getNum();
    validation(num);

    int primeNumber[num+1];
    algorithm(num, primeNumber);

    printf("素数は以下です\n");
    for (int i = 0;i < num+1;i++) {
        if(primeNumber[i] == 0) {
            continue;
        }
        printf("%d\n", primeNumber[i]);
    }
}

void main(int argc, char *argv[])
{
    int i;
    for(i = 0; i < argc; ++i){
        if(*argv[i] == '-')
        switch(*(argv[i] + 1)){
            case 't':
                test();
                break;
        }
    }

    run();
}

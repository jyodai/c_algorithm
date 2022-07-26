// 2つの自然数の最大公約数を求める

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void getNum(int array[2])
{
    int a, b;
    printf("数値 空白 数値 の形式で入力してください\n");
    printf("例 : 12 16\n");
    scanf("%d %d",&a,&b);

    if (a > b)
    {
        array[0] = a;
        array[1] = b;
    }
    else
    {
        array[0] = b;
        array[1] = a;
    }
}

void validation(int num)
{
    if (num <= 0) {
        printf("自然数を入力してください\n");
        exit(0);
    }
}

int algorithm(int m, int n)
{
    int remainder;
    remainder = m % n;
    if (remainder == 0) {
        return n;
    }
    algorithm(n, remainder);
}

void test()
{
    printf("testを開始します\n");
    assert(algorithm(1, 2) == 1);
    assert(algorithm(1, 50) == 1);
    assert(algorithm(12, 16) == 4);
    assert(algorithm(12, 18) == 6);
    assert(algorithm(84, 42) == 42);
    assert(algorithm(1071, 1029) == 21);
    printf("testが終了しました\n");
    exit(0);
}

void run()
{
    int array[2];
    getNum(array);
    for (int i = 0; i < 2; i += 1) {
        validation(array[i]);
    }

    int result = algorithm(array[0], array[1]);
    printf("最大公約数は %d です\n", result);

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

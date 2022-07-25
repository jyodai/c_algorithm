// 2つの自然数の最大公約数を求める

#include <stdio.h>
#include <stdlib.h>

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

void algorithm(int m, int n)
{
    int remainder;
    remainder = m % n;
    if (remainder == 0) {
        printf("最大公約数は %d です\n", n);
        exit(0);
    }
    algorithm(n, remainder);
}

void main()
{
    int array[2];
    getNum(array);
    for (int i = 0; i < 2; i += 1) {
        validation(array[i]);
    }

    algorithm(array[0], array[1]);
}

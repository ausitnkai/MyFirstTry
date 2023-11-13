#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Please input two intger: ");
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", a&b);
    printf("%d\n", a|b);
    printf("%d\n", a^b);
    printf("%d\n", ~a | b);
    printf("%d\n", ~b | a );
}

// 當 "a 比 b" 小，且 b 是 2 的 N 次方的時候
    //兩者做 XOR(^)其結果會是兩者 "相加"
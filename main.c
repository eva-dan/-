#include <stdio.h>
#include <windows.h>
#define lmax 200
void input(int *n, int a[lmax]){
    int n1, k;
    do{
        printf("Введите размер массива:\n");
        k = scanf("%d", &n1);
        while (getchar() != '\n');
    } while (k != 1 || n1<0 || n1 >= lmax);
    *n = n1;
    printf("Введите массив с %d элементами\n", n1);
    for (int i=0; i<n1; i++) scanf("%d", &a[i]);
}
int fun(int n, int a[lmax], int b[lmax]){
    int k = 0;
    for(int i; i<n; i++){
        int e = *(a+i);
        int j = 0;
        char c = 0;
        while(j<k && c == 0) {
            if(*(b+j) == e) c=1;
            j++;
        }
        if(c==0) {
            int count = 0;
            for(int v = 0; v < n; v++){
                if(*(a + v) == e) count++;
            }
            if(count > 1) {
                *(b + k) == e;
                k++;
            }
        }
    }
    return k;
}
void repeat(int a[lmax], int n, int b[lmax], int k){
    for(int i = 0; i < k; i++){
        int count = 0;
        for(int j = 0; j < n; j++) {
            if (*(b + i) == *(a + j)) count++;
        }
        printf("Элемент массива A = %d повторяется %d раз\n", *(b + i), count);
    }
    if(k==0)
        printf("Нет повторений\n");
}
void output(int b[lmax], int k){
    printf("Массив B из %d элементов", k);
    for(int i = 0; i < k; i++) printf("%d", *(b+i));
}
int main(){
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    int n, a[lmax], k;
    printf("Лабораторная работа №3\n");
    printf("Задача №3\n");
    input(&n, a);
    int b[lmax];
    k = fun(n, a, b);
    repeat(a, n, b, k);
    output(b, k);
    return 0;
}
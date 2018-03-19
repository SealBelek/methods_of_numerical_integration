//
//  main.c
//  lab1
//
//  Created by barry on 16.01.18.
//  Copyright © 2018 barry. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#define L 3
#define R 8
#define acc 500


void method_right_rectangle(double a, double b, int n);
void method_left_rectangle(double a, double b, int n);
void method_middle_rectangle(double a, double b, int n);
void method_trapeze(double a, double b, int n);
void method_simpson(double a, double b, int n);
double f(double);
int main(void) {
    FILE *file;
    file = fopen("file.txt", "w");
    fprintf(file, "кол-во разбиений\tшаг\tзначение интеграла\n");
    fclose(file);
    method_right_rectangle(L, R, acc);
    method_left_rectangle(L, R, acc);
    method_middle_rectangle(L, R, acc);
    method_trapeze(L, R, acc);
    method_simpson(L, R, acc);
    return 0; }
void method_right_rectangle(double a, double b, int n){
    FILE *file;
    file = fopen("file.txt", "a");
    double h = (b - a) / n;
    int i;
    double result = 0, t = b;
    
    for (i = 0; i < n; i ++) {
        result += f(t);
        t -= h;
    }
    result *= h;
    fprintf(file,"%d%25f%20f\n",n, h, result);
    fclose(file);
}
void method_left_rectangle(double a, double b, int n){
    FILE *file;
    file = fopen("file.txt", "a");
    double h = (b - a) / n;
    int i;
    double result = 0, t = a;
    
    for (i = 0; i < n; i ++) {
        result += f(t);
        t += h;
    }
    result *= h;
    fprintf(file,"%d%25f%20f\n",n, h, result);
    fclose(file);
}
void method_middle_rectangle(double a, double b, int n){
    FILE *file;
    file = fopen("file.txt", "a");
    int i;
    double result, h;
    result = 0;
    h = (b - a) / n;
    for(i = 0; i < n; i++)
    {
        result += f(a + h * (i + 0.5)); //Вычисляем в средней точке и добавляем в сумму
    }
    
    result *= h;
    fprintf(file,"%d%25f%20f\n",n, h, result);
    fclose(file);
}
void method_trapeze(double a, double b, int n){
    FILE *file;
    file = fopen("file.txt", "a");
    int i;
    double result, h, t;
    result = (f(a) + f(b)) / 2;
    h = (b - a) / n;
    t = a + h;
    for(i = 1; i < n; i++){
        result += f(t);
        t += h;
    }
    result *= h;
    fprintf(file,"%d%25f%20f\n",n, h, result);
    fclose(file);
}
void method_simpson(double a, double b, int n){
    FILE *file;
    file = fopen("file.txt", "a");
    int i;
    double result, h, t;
    h = (b - a) / n;
    result = f(a) + f(b);
    t = a + h;
    for(i = 1; i < n; i++){
        result += (i % 2)? f(t) * 4 : f(t) * 2;
        t += h;
    }
    result *= h/3;
    fprintf(file,"%d%25f%20f\n",n, h, result);
    fclose(file);
}
double f(double x){
    return (pow(x, 2)/(pow(x, 3) - 7));
}

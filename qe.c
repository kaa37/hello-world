#include <stdio.h>
#include <math.h>
/* нахождение корней квадратного уровнения */

double discrim(double a, double b, double c)
/* вычисление дискриминанта */
{
    return b*b - 4*a*c;
}

int main()
{
    double p, q, r, d;
    int n;
    printf("Введите коэффициэнты а, в и с:\n");
    n = scanf("%lf %lf %lf", &p, &q, &r);
    if(n != 3) {   /* задано неверное количество коэффициентов уравнения */
        printf("Error: wrong input.\n");
        return 1;
    }
    if(p == 0) {   /* это не квадратное уравнение */
        printf("Error: Not a quadratic equation!\n");
        return 2;
    }
    d = discrim(p, q, r);
    if(d < 0) {    /* дискриминант <0, уравнение не имеет решения */
        printf("No roots\n");
        return 0;
    }
    d = sqrt(d);
    printf("Корни уравнения:\n  %.5lf\n  %.5lf\n", (-q-d)/(2*p), (-q+d)/(2*p));
    return 0;
}

#include <stdio.h>
#include <math.h>
#include <locale.h>
int fac (int n)
{
    if(n == 0) return 1;
    else return n * fac(n - 1);
}
int rekurs(double eps, double s, int n, double elem, double x, double sum)
{

    double pr;
    elem=(pow( (-1) ,(n - 1) ) * pow(x,(2 * n) - 1));
    for(int i = 1;i <= (2 * n)- 1;i++)
        elem /= i;
    sum += elem;
    printf("\n %d%lf, %lf %lf",n,sum, s, elem);
    pr = fabs(s - sum);
    if (pr <= eps)
        return n;
    else
        return rekurs(eps, s, n+1, elem, x, sum);
}

int main()
{
    printf("Enter x and eps\n");
    double x, eps;
    scanf("%lf%lf",&x, &eps);
    if (eps <= 0)
    {
        printf("Wrong epsilon");
        return 0;
    }
    double s = sin(x);
    printf("sinx=%lf", s);
    int n = 1;
    int l;
    printf("By 1)rekursion or 2)iterasion?");
    scanf("%d",&l);
    if(l==1)
    {n = rekurs(eps, s, n, 0, x, 0);
        n++;
    }

    else if(l == 2)
        for(double pr = eps + 1,sum = 0., elem;pr > eps;n++)
        {
            elem = (pow( (-1) ,(n - 1) ) * pow(x,(2 * n) - 1));
            for(int i = 1;i <= (2 * n)- 1;i++)
                elem /= i;
            sum += elem;
            printf("\n %d %lf, %lf %lf",n,sum, s, elem);
            pr=fabs(s - sum);
        }
    else
    {
        printf("Wrong input");
        return 0;
    }

    n--;
    printf("\n%d",n);
    return 0;
}

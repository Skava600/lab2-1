#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void menu (int entr, int lvl, double heigth, double width, double dist);
int con (int a);
double dob (double b);
void dob2 (double *a,double *b);
double len (int entr, int lvl, double heigth, double width, double dist);
double csprgf (int entr, int lvl, double heigth, double width, double dist);
double csstf (int entr, int lvl, double heigth, double width, double dist);
double csprf (int entr, int lvl, double heigth, double width, double dist);
void info (void);
void proverka (int entr, int lvl, double heigth, double width, double dist);
int main ()
{
    int entr = 0, lvl = 0;
    double heigth = 0., width = 0., dist = 0.;
    menu(entr, lvl, heigth, width, dist);
    return 0;
}
void menu(int entr, int lvl, double heigth, double width, double dist)
{
    double csprg, lencab, csst, cspr;
    printf ("\t\tMenu\n"
           "1.Enter Amount of connectors.\n"
           "2.Enter Amount of Levels.\n"
           "3.Enter high of ceiling height and width.\n"
           "4.Enter average distance between connector and distribution board.\n"
           "5.Calculate cost of proecting.\n"
           "6.Calculate length of cabel.\n"
           "7.Calculate cost of staff.\n"
           "8.Calculate cost of proect.\n"
           "9.Information about firm and contacts.\n"
           "10.Exit.\n\n"
           "Choose action:");
    int ch;
    scanf ( "%d", &ch );
    switch( ch )
    {
        case 1 : entr = con (entr) ; break;
        case 2 : lvl = con (lvl) ; break;
        case 3 : dob2 (&heigth, &width) ; break;
        case 4 : dist = dob (dist) ; break;
        case 5 : csprg = csprgf (entr, lvl, heigth, width, dist) ; break;
        case 6 : lencab = len (entr, lvl, heigth, width, dist) ; break;
        case 7 : csst = csstf (entr, lvl, heigth, width, dist) ; break;
        case 8 : cspr = csprf (entr, lvl, heigth, width, dist) ; break;
        case 9 : info(); break;
        default : return ;
    }
    menu (entr, lvl, heigth, width, dist);
}
int con (int a)
{
    printf("Enter:");
    scanf("%d", &a);
    if(a <= 0)
    {
        printf("Wrong input");
        getch();
        system("cls");
        return 0;
    }
    else return a;
}
double dob (double b)
{
    printf("Enter average distance:");
    scanf("%le", &b);
    if(b <= 0.)
    {
        printf("Wrong input");
        getch();
        system("cls");
        return 0.;
    }
    else return b;
}

void dob2(double *a, double *b)
{
    printf("Enter high of ceiling height:");
    scanf("%le", &*a);
    if(*a <= 0.)
    {
        printf("Wrong input");
        *a = 0.;

    }
    printf("Enter width :");
    scanf("%le", &*b);
    if(*b <= 0.)
    {
        printf("Wrong input");
        *b = 0.;
        getch();
        system("cls");
        return;
    }
    else return;
}

double len (int entr, int lvl, double heigth, double width, double dist)
{
    proverka(entr, lvl, heigth, width, dist);
    double length;
    printf("\n %d %le %le %le %d",lvl, heigth, width, dist, entr);
    length = (lvl * heigth) + ( (lvl - 1) * width) + (dist * lvl * entr);
     printf ("\nLength of cabel is %le", length);
     getch();
     system("cls");
    return length;
}

double csstf(int entr, int lvl, double heigth, double width, double dist)
{
    proverka(entr, lvl, heigth, width, dist);
    double csst;
    csst = len(entr, lvl, heigth, width, dist) * 1.5 + 110 * lvl;
    printf ("\nCost of staff is %le", csst);
    getch();
    system("cls");
    return csst;
}

double csprgf (int entr, int lvl, double heigth, double width, double dist)
{
   double csprg;
   csprg = 0.3 * (csstf (entr, lvl, heigth, width, dist) + 33*lvl + lvl*entr*3 + 20*lvl);
   printf ("\nCost of proecting of network is %le", csprg);
   getch();
   system("cls");
   return csprg;
}

double csprf (int entr, int lvl, double heigth, double width, double dist)
{
    proverka(entr, lvl, heigth, width, dist);
    double cspr;
    cspr = csprgf (entr, lvl, heigth, width, dist) + csstf(entr, lvl, heigth, width, dist) + 33*lvl + lvl*entr*3 + 20*lvl;
    printf ("\nCost of proect is %le\n", cspr);
    getch();
    system("cls");
    return cspr;
}

void info()
{
    printf (" Installation company AMP\n"
            "Director: Stanislav Zabrodski\n"
            "Deputy Director: Nikolay Popov\n"
            "Secretary: Anastasya Tolova\n\n"
            "Contacts: st. Nezalezhnosti 34\n"
            "Tel.80336785672");
    getch();
    system("cls");
    return;
}
void proverka (int entr, int lvl, double heigth, double width, double dist)
{
    if(entr==0||lvl==0||heigth==0.||width==0.||dist==0.)
    {
        printf("Not enough of data");
        getch();
        system("cls");
        menu(entr, lvl, heigth, width, dist);
    }
    else return;
}

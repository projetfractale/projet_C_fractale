#include "math.h"

#include <vector>
using std::vector;

vector<vector<int> > Mandelbrot(int iteration_max, int a[], int c[]) //renvoie les points a colorier entre a et c
{
double a0=a[0]/300-2;
double a1=-a[1]/300+2;
double c0=c[0]/300-2;
double c1=-c[1]/300+2; //conversion en cartesienne
double r=fmax(c0-a0,a1-c1);
double q=double(r)/1200;// valeur d'un pixel en cartesienne
int imax=((c0-a0)/q); //prendre la partie entiere
int jmax=((a1-c1)/q);
int n=(imax+1)*(jmax+1);

vector<vector<int> > table(n);
int p=0;
    for (int i=0;i<=imax;i++)  //on commence par un carré
    {
        for (int j=0;j<=jmax;j++)
        {
            double a=0;
            double x=0; //x et y en coordonnees cartesiennes
            double y=0;
            double z0=a0+((double)i)*q;
            double z1=a1-((double)j)*q;
            int h=0;
            vector<vector<int> > liste(100);
            while (h<iteration_max && x*x+y*y<4)
            {
                a=x;
                x=x*x-y*y+z0;
                y=2*a*y+z1;
                h++;
            }
            table[p] = vector<int>(3);
         table [p][0]=i;
         table [p][1]=j;
         table [p][2]=h;
         p=p+1;
        }
    }
return table;
}

vector<vector<int> > Julia(int iteration_max,int a[], int c[], int b[])
 {
    double a0=a[0]/300-2;
    double a1=-a[1]/300+2;
    double c0=c[0]/300-2;
    double c1=-c[1]/300+2; //conversion en cartesienne
    double r=fmax(c0-a0,a1-c1);
    double q=double(r)/1200;// valeur d'un pixel en cartesienne
    int imax=((c0-a0)/q); //prendre la partie entiere
    int jmax=((a1-c1)/q);
    int n=(imax+1)*(jmax+1);
    double x_julia = b[0]/300-2;
    double y_julia = -b[1]/300+2;
    vector<vector<int> > table(n);
    int p=0;
    for (int i=0; i<=imax; i++)
     {
         for (int j=0; j<=jmax; j++)
         {
             double x = a0+((double)i)*q;
             double y = a1-((double)j)*q;
             double d=0;
             int h=0;
             while (h<iteration_max && x*x+y*y<4)
                 {
                     d=x;
                     x=x*x -y*y + x_julia;
                     y=2*d*y + y_julia;
                     h=h+1;
                 }
             table [p] = vector<int>(3);
             table [p][0]=i;
             table [p][1]=j;
             table [p][2]=h;
             p=p+1;
         }
      }
return table;
}

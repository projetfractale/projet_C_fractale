#ifndef MATH_H
#define MATH_H

#include <vector>
using std::vector;

vector<vector<int> > Mandelbrot(int iteration_max, int a[], int c[]);
vector<vector<int> > Julia(int iteration_max,int a[], int c[], int b[]);

#endif // MATH_H

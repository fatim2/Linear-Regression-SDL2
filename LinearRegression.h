#ifndef LINEAREGRESSION_LINEARREGRESSION_H
#define LINEAREGRESSION_LINEARREGRESSION_H
#endif //LINEAREGRESSION_LINEARREGRESSION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


#define SCALE 500
#define learning_rate 0.01

typedef struct Point
{
    double x;
    double y;
    struct Point *next;
} Point;
typedef struct TrainigList
{
    Point *first;
    Point *last;
    int size;
} TrainigList;
typedef struct Model
{
    double alpha; //learning rate
    double a;
    double b;
} Model;

Point* createPt(double , double );
void addPt(TrainigList *, double , double );
void displayPt(Point* );
TrainigList* createTrainigList();
void displayTrainigList(TrainigList* );
void deleteTrainigList(TrainigList* );
Model* createModel(double , double );
void displayModel(Model* );
double scalingValues(double) ;
void minimizeError(Model *m,TrainigList* L);


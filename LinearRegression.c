#include "LinearRegression.h"

Point* createPt(double x, double y){
    Point *p = (Point *)malloc(sizeof(Point));
    p->y = y;
    p->x = x;
    p->next = NULL;
    return p;
}
void addPt(TrainigList *L, double x, double y){
    Point *p=createPt(x,y);
    L->size++;
    if(L->first==NULL){
        L->first=p;
        L->last=p;
        return;
    }
    L->last->next=p;
    L->last=p;
}
void displayPt(Point* p){
    printf("x=%lf, y=%lf\n", p->x, p->y);
}
TrainigList* createTrainigList(){
    TrainigList* L=(TrainigList*)malloc(sizeof(TrainigList));
    L->size=0;
    L->first=NULL;
    L->last=NULL;
    return L;
}
void displayTrainigList(TrainigList* L){
    Point* p=L->first;
    while(p!=NULL){
        displayPt(p);
        p=p->next;
    }
}
void deleteTrainigList(TrainigList *L){
    Point* p=L->first;
    while(p!=NULL){
        Point* temp=p;
        p=p->next;
        free(temp);
    }
}
Model* createModel(double a, double b){
    Model* m=(Model*)malloc(sizeof(Model));
    m->alpha=learning_rate;
    m->a=a;
    m->b=b;
    return m;
}
void displayModel(Model* m){
    printf("y = %lfx + %lf\n", m->a, m->b);
}
double scalingValues(double x){
    return x/SCALE;
}
void minimizeError(Model *m,TrainigList* L){
    double a = m->a;
    double b = m->b;
    double alpha = m->alpha;
    for(Point* p=L->first;p!=NULL;p=p->next)
    {
        double x = scalingValues(p->x);
        double real_y = scalingValues(p->y);
        double predicted_y = a*x+b;
        double error = real_y - predicted_y;
        //Simultenaously updating prameters
        a += (alpha * error * x);
        b += (alpha * error );
    }
    m->a=a;
    m->b=b;

}

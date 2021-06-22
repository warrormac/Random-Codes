#include <iostream>
using namespace std;

template <typename T>
class Point1 {
    T x,y;
    public:
    Point1();
    Point1(T,T);
    Point1(Point1 &o);
    void offset(T,T);
    void set_x(T);
    void set_y(T);
    void print();
    T get_x();
    T get_y();
};


template<typename T>
Point1<T>::Point1():x(0),y(0){}
template<typename T>
Point1<T>::Point1(T x1,T y1):x(x1),y(y1){}
template<typename T>
Point1<T>::Point1(Point1 &o):x(o.x),y(o.y){}
template<typename T>
void Point1<T>::offset(T offset_x,T offset_y){
    this->x=offset_x;
    this->y=offset_y;
}
template<typename T>
void Point1<T>::set_x(T x){
    this->x=x;
}
template<typename T>
void Point1<T>::set_y(T y){
    this->y=y;
}
template<typename T>
void Point1<T>::print(){
    std::cout<<"("<<x<<","<<y<<")"<<std::endl;
}
template<typename T>
T Point1<T>::get_x(){
    return x;
}
template<typename T>
T Point1<T>::get_y(){
    return y;
}



template<typename TP>
class PointArray
{
    public:
        PointArray();
        PointArray(const Point1<TP> pts[],const int size);
        PointArray(PointArray &o);
        ~PointArray();
        void print();
        void clear();
        void push_back(const Point1<TP> &p);
        void insert(const int,const Point1<TP> &p);
        void remove(const int);
        int getSize();
    private:
        int size;
        Point1<TP> *points;
        void resize(int);
};



template<typename TP>
PointArray<TP>::PointArray(){
    this->size=0;
    points=new Point1<TP>[size];
}
template<typename TP>
PointArray<TP>::PointArray(const Point1<TP> pts[],const int size){
    this->size=size;
    points=new Point1<TP>[size];
    for(int y=0;y<size;y++)
        points[y]=pts[y];
}
template<typename TP>
PointArray<TP>::PointArray(PointArray &o){
    this->size=o.size;
    points=new Point1<TP>[size];
    for(int y=0;y<size;y++)
        points[y]=o.points[y];
}
template<typename TP>
PointArray<TP>::~PointArray(){
    delete[] points;
}
template<typename TP>
void PointArray<TP>::resize(int newsize){
    Point1<TP> *ptr=new Point1<TP>[newsize];
    int minsize=(newsize>size)?size:newsize;
    for(int y=0;y<minsize;y++)
        ptr[y]=points[y];
    delete[] points;
    size=newsize;
    points=ptr;
}
template<typename TP>
void PointArray<TP>::print(){
    for(int y=0;y<size;y++)
        points[y].print();
}
template<typename TP>
void PointArray<TP>::clear(){
    resize(0);
}
template<typename TP>
void PointArray<TP>::push_back(const Point1<TP> &p){
    resize(size+1);
    points[size-1]=p;
}
template<typename TP>
void PointArray<TP>::insert(const int pos,const Point1<TP> &p){
    resize(size+1);
    for(int y=(size-1);pos-1<y;y--)
        points[y]=points[y-1];
    points[pos-1]=p;
}
template<typename TP>
void PointArray<TP>::remove(const int pos){
    for(int y=pos-1;y<size-1;y++)
        points[y]=points[y+1];
    size--;
    resize(size);
}
template<typename TP>
int PointArray<TP>::getSize(){
    return size;
}


int main()
{
    Point1<double> a(1.1,2.2);
    Point1<int> p(1,10);
    Point1<int> q(2,20);
    Point1<int> r(3,30);

    Point1<char> s('a','b');
    Point1<char> s1('c','d');
    Point1<char> s2('e','f');


    Point1<int> arr[]={p,q,r};
    int size=sizeof(arr)/sizeof(arr[0]);
    PointArray<int> pa2(arr,size);
    PointArray<int> pa=pa2;
    pa.push_back(p);
    pa.print();//p,q,r

    cout<<"\n";


    Point1<char> arr1[]={s,s1,s2};
    int size1=sizeof(arr1)/sizeof(arr1[0]);
    PointArray<char> cha(arr1,size);
    PointArray<char> cha1=cha;
    cha1.print();
    cout<<"\n";
    cha1.clear();
    cha1.insert(1,s1);
    cha1.print();


    return 0;
}

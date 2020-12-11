#ifndef _PROTOTYPE_H
#define _PROTOTYPE_H
#include <iostream>
#include <unordered_map>
#include "Prototype_Pattern.h"

using namespace std;

//创建原型实体类
class Rectangle : public Shape
{
    public:
        Rectangle()
        {
            m_type = "Rectangle";
        }

        virtual void draw()
        {
            cout << "Inside Rectangle::draw() method." << endl;
        }

        virtual Rectangle * clone()
        {
            //调用复制构造函数，根据实际情况重写
            Rectangle * p = new Rectangle(*this);

            //或调用赋值运算符
            //*p = *this;

            return p;
        }
};

class Square : public Shape
{
    public:
        Square()
        {
            m_type = "Square";
        }

        virtual void draw()
        {
            cout << "Inside Square::draw() method." << endl;
        }

        virtual Square * clone()
        {
            //调用复制构造函数，根据实际情况重写
            Square * p = new Square(*this);

            //或调用赋值运算符
            //*p = *this;

            return p;
        }
};

class Circle : public Shape
{
    public:
        Circle()
        {
            m_type = "Circle";
        }

        virtual void draw()
        {
            cout << "Inside Circle::draw() method." << endl;
        }

        virtual Circle * clone()
        {
            //调用复制构造函数，根据实际情况重写
            Circle * p = new Circle(*this);

            //或调用赋值运算符
            //*p = *this;

            return p;
        }
};


//创建一个原始实体对象的管理类
class ShapeCache 
{
    private:
         unordered_map<string, Shape *> shapeMap;
    
    public:
         Shape * getShape(string Id)
        {
            Shape *cachedShape = shapeMap[Id];
            return cachedShape->clone();
        }

        void loadCache()
        {
            //把原型实例对象缓存下来
            Rectangle *rectangle = new Rectangle();
            rectangle->setId("1");
            shapeMap["1"] = rectangle;

            Square *square = new Square();
            square->setId("2");
            shapeMap["2"] = square;

            Circle *circle = new Circle();
            circle->setId("3");
            shapeMap["3"] = circle;
        }
};
#endif
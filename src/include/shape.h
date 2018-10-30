#pragma once

#include "stdafx.h"


enum Shapes{
    CIRCLE,
    SQUARE,
    ELLIPSE,
};


class Shape {
protected:
    uint32_t _id;
    static uint32_t _total;

public:
    Shape() {
        _id = _total++;
    }

    uint32_t getId(){
        return _id;
    }
    virtual void draw() = 0;
    virtual std::string serialize() {return "";};
    virtual void deserialize(const std::string &) {};
    virtual ~Shape() = default;
};
uint32_t Shape::_total = 0;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct EnumClassHash
{
    template <typename T>
    std::size_t operator()(T t) const
    {
        return static_cast<std::size_t>(t);
    }
};

class ShapeFactory {
public:
    using registry_map = std::unordered_map<Shapes, void*, EnumClassHash>;

    static registry_map & registry(){
        static registry_map impl;
        return impl;
    }

    template<typename ...T>
    static std::shared_ptr<Shape> instantiate(Shapes s, T&&...args)
    {
        auto it = registry().find( s );
        if ( it == registry().end() ){
            throw new std::invalid_argument("unknown shape" );
        }

        typedef std::shared_ptr<Shape> (*create_type)(T...);
        auto create_fun = reinterpret_cast<create_type>(it->second);
        return create_fun(args...);
    }

};

struct ShapeFactoryRegister
{
    template <typename T>
    ShapeFactoryRegister(Shapes shape, T foo )
    {
        ShapeFactory::registry()[shape] = reinterpret_cast<void*>(foo);
    }
};

//------------------

class Circle : public Shape {
public:
    Circle(uint32_t x, uint32_t y, uint32_t r){}

    void draw() {
        std::cout << "drawing a circle " << std::endl;
    }

    static std::shared_ptr<Shape> create(uint32_t x, uint32_t y, uint32_t r) { return std::shared_ptr<Shape>(new Circle(x, y, r)); }

private:
    static ShapeFactoryRegister _addToFactory;
};

ShapeFactoryRegister Circle::_addToFactory(Shapes::CIRCLE,  Circle::create);


//------------------

class Square : public Shape {
public:
    Square(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2) {}

    void draw() {
        std::cout << "drawing a square " << std::endl;
    }

    static std::shared_ptr<Shape> create(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2) {
        return std::shared_ptr<Shape>(new Square(x1, y1, x2, y2));
    }


private:
    static ShapeFactoryRegister _addToFactory;
};

ShapeFactoryRegister Square::_addToFactory(Shapes::SQUARE,  Square::create);


//------------------


class Ellipse : public Shape {
public:
    Ellipse(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, uint32_t r) {}

    void draw() {
        std::cout << "drawing an ellipse " << std::endl;
    }

    static std::shared_ptr<Shape> create(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2, uint32_t r) {
        return std::shared_ptr<Shape>(new Ellipse(x1, y1, x2, y2, r));
    }

private:
    static ShapeFactoryRegister _addToFactory;
};

ShapeFactoryRegister Ellipse::_addToFactory(Shapes::ELLIPSE,  Ellipse::create);

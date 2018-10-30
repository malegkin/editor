#pragma once

#include <stdafx.h>
#include "observer.h"
#include "shape.h"

using shapes_t = std::unordered_map<uint32_t, std::shared_ptr<Shape>>;
class Model : public Observable
{
public:

    void addShape(std::shared_ptr<Shape> s){
        _shapes[s->getId()] = s;
        notifyUpdate();
    }

    void removeShape(uint32_t id){
        _shapes.erase(id);
        notifyUpdate();
    }

    const shapes_t & getShapes(){
        return _shapes;
    }


private:
    shapes_t _shapes;
};

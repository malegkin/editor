#pragma once

#include "model.h"
#include "view.h"

// Controller combines Model and View
class Controller {
public:
    Controller(std::shared_ptr<View> view, std::shared_ptr<Model> model)
    : _view(view)
    , _model(model)
    {
        _model->addObserver(_view);
    }


    void saveAs(std::string file_name){
        for (auto a: _model->getShapes()){
            a.second->serialize();
        }
    }

    void save(){

    }

    void close(){
        _model->clear();
    }

    void loadFile(std::string file_name){

    }


    void addShape(std::shared_ptr<Shape> s){
        _model->addShape(s);
    }

    void removeShape(uint32_t id){
        _model->removeShape(id);
    }


private:
    std::shared_ptr<View>   _view;
    std::shared_ptr<Model>  _model;
};

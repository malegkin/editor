#pragma once

#include "model.h"


class View: public IObserver {
public:
    View()
    { }

    View(std::shared_ptr<Model> model)
    : _model(model)
    { }

    void setModel(std::shared_ptr<Model> model)
    {
        _model = model;
    }

    void update() {
        std::cout << "View: render image at " << _model->getShapes().size() << " shapes." << std::endl;
    }

private:
    std::shared_ptr<Model> _model;
};
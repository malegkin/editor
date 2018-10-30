#pragma once

#include "model.h"
#include "view.h"
/*
// Controller combines Model and View
class Controller {
public:
    Controller(const Model &model, const View &view)
    : _model(model)
    , _view(view)
    {}

    void SetModel(const Model &model) {
        _model = model;
    }
    void SetView(const View &view) {
        _view = view;
    }

    // when application starts
    void onLoad() {
        _view.render();
    }
private:
    Model   _model;
    View    _view;
};
*/
/*
class Controller
{
public:
    Controller(TemperatureModel *model)
    {
        _model = model;
    }
    void start()
    {
        _model->setC(0);

        float temp;
        do
        {
            scanf("%f", &temp);
            _model->setC(temp);
        }
        while (temp != 0);
    }
private:
    TemperatureModel *_model;
};*/
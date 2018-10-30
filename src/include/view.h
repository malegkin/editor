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
        std::cout << "View: render at " << _model->getShapes().size() << " shapes." << std::endl;
    }

private:
    std::shared_ptr<Model> _model;
};




/*
class ConsoleView: public IObserver
{
public:
    ConsoleView(TemperatureModel *model)
    {
        _model = model;
        _model->addObserver(this);
    }
    virtual void update()
    {
        system("cls");
        printf("Temperature in Celsius: %.2f\n", _model->getC());
        printf("Temperature in Farenheit: %.2f\n", _model->getF());
        printf("Input temperature in Celsius: ");
    }
private:
    TemperatureModel *_model;
};
 */
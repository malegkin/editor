#include "stdafx.h"
#include "view.h"
#include "model.h"
#include "controller.h"
#include "shape.h"


void DataChange(std::string data) {
   std::cout << "Data Changes: " << data << std::endl;
}


struct editor {

private:


};


int main()
{
    try {

        auto m = std::shared_ptr<Model>( new Model());
        auto v = std::shared_ptr<View>( new View(m));


        m->addShape( ShapeFactory::instantiate(Shapes::CIRCLE, 1, 2, 3) );
        m->addShape( ShapeFactory::instantiate(Shapes::SQUARE, 1, 2, 3, 4) );
        m->addShape( ShapeFactory::instantiate(Shapes::ELLIPSE, 1, 2, 3, 4, 5) );



        for (auto a: m->getShapes()){
            a.second->draw();
        }

        v->update();


        //std::cout << typeid( ShapeFactory::instantiate(Shapes::CIRCLE, 1, 2, 3).get()).name() << std::endl;
        //std::cout << typeid( std::shared_ptr<Circle>).name() << std::endl;
        return -1;




        return -1;

/*
        TemperatureModel model;
        ConsoleView view(&model);
        Controller controller(&model);
        controller.start();
*/
        /*

        std::shared_ptr<ModelHandler> modelHandler(new ModelHandler());

        Model model("Model");
        View  view(model);
        model.registerDataChangeHandler(&DataChange);


        Controller controller(model, view);
        controller.onLoad();

        model.setData("Changes"); // this should trigger View to render
        */
    }
    catch (std::exception& ex) {
        std::cerr << ex.what() << std::endl;
        return -1;
    }
    catch (...) {
        std::cerr << "Caught unknown exception." << std::endl;
        return -1;
    }

    return 0;
}

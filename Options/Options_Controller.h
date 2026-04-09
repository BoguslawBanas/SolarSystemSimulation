#ifndef OPTIONS_CONTROLLER_H
#define OPTIONS_CONTROLLER_H

#include "Options_Model.h"
#include "Options_View.h"

class Options_Controller{
    private:
    Options_Model *model;
    Options_View *view;

    public:
    Options_Controller();

    ~Options_Controller();

    void requestDrawing();
};

#endif
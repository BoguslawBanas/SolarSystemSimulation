#ifndef FILE_SAVER_CONTROLLER_H
#define FILE_SAVER_CONTROLLER_H

#include "../Universe/Universe_Controller.h"
#include "../header_files/solar_system_consts.h"
#include <stdio.h>

class File_Saver_Controller{
    private:
    void addPlanetToFile(FILE*, Planet_Model const * const);

    bool save(Universe_Model const * const, const char*);

    public:
    File_Saver_Controller();

    ~File_Saver_Controller();

    bool saveSnapshot(Universe_Model const * const);

    bool saveUniverse(Universe_Model const * const, const char*);
};

#endif
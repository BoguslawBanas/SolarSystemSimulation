#ifndef FILE_READER_CONTROLLER_H
#define FILE_READER_CONTROLLER_H

#include "../Universe/Universe_Controller.h"
#include "../header_files/solar_system_consts.h"
#include <stdio.h>

class File_Reader_Controller{
    private:
    Planet_Model* getPlanetFromFile(FILE*);

    Universe_Model* read(const char*);

    public:
    File_Reader_Controller();

    ~File_Reader_Controller();

    Universe_Model* readSnapshot();

    Universe_Model* readUniverse(const char*);
};

#endif
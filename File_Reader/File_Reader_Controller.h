#ifndef FILE_READER_CONTROLLER_H
#define FILE_READER_CONTROLLER_H

#include "../Universe/Universe_Controller.h"
#include "../header_files/solar_system_consts.h"
#include <stdio.h>
#include <vector>

class File_Reader_Controller{
    private:
    Planet_Model* getPlanetFromFile(FILE*, long long int&);

    bool read(Universe_Model* const , const char*);

    public:
    File_Reader_Controller();

    ~File_Reader_Controller();

    bool readSnapshot(Universe_Model* const);

    bool readUniverse(Universe_Model* const, const char*);
};

#endif
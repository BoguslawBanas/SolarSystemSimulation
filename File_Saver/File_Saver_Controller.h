#ifndef FILE_SAVER_CONTROLLER_H
#define FILE_SAVER_CONTROLLER_H

#include "../Universe/Universe_Controller.h"
#include <stdio.h>

#define SNAPSHOT_FILE_PATH "snapshot_file.sss"

class File_Saver_Controller{
    private:
    void addPlanetToFile(FILE*, Planet_Model const * const, long long int&);

    bool save(Universe_Model const * const, const char*);

    public:
    File_Saver_Controller();

    ~File_Saver_Controller();

    bool saveSnapshot(Universe_Model const * const);

    bool saveUniverse(Universe_Model const * const, const char*);
};

#endif
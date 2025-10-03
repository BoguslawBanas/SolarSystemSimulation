#ifndef FILE_SAVER_H
#define FILE_SAVER_H

#include "universe.h"
#include <string.h>

namespace file_saver{
    #include <windows.h>

    class File_Saver{
        private:
        char file_path[4096];
        void save_color(FILE*, const Color&);
        void save_mass(FILE*, const long double);
        void save_name(FILE*, const char*);
        void save_position(FILE*, const Vector3&);
        void save_radius(FILE*, const long double);
        void save_velocity(FILE*, const Vector3&);

        public:
        File_Saver();

        ~File_Saver();

        bool saveFile(Universe* const);

        const char* getFilePath();
    };
};

#endif
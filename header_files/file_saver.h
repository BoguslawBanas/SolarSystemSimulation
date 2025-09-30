#ifndef FILE_SAVER_H
#define FILE_SAVER_H

#include "universe.h"
#include <string.h>

namespace file_saver{
    #include <windows.h>

    class File_Saver{
        private:
        char file_path[4096];
        void create_color_json(FILE*, const Color&);
        void create_mass_json(FILE*, const long double);
        void create_name_json(FILE*, const char*);
        void create_position_json(FILE*, const Vector3&);
        void create_radius_json(FILE*, const long double);
        void create_velocity_json(FILE*, const Vector3&);

        public:
        File_Saver();

        ~File_Saver();

        bool saveFile(Universe* const);

        const char* getFilePath();
    };
};

#endif
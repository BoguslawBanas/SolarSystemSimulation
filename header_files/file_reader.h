#ifndef FILE_READER_H
#define FILE_READER_H

#include <vector>
#include "universe.h"
#include <raylib.h>

namespace file_reader{
    #include <windows.h>

    class File_Reader{
        private:
        char file_path[4096];

        public:
        File_Reader();

        ~File_Reader();

        bool readFile(const Universe*);
    };

};

#endif
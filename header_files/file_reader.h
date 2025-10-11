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
        // Color readColor(FILE*);
        // long double readMass(FILE*);
        // const char *readName(FILE*);
        // Vector3 readPosition(FILE*);
        // long double readRadius(FILE*);
        // Vecotr3 readVelocity(FILE*);

        public:
        File_Reader();

        ~File_Reader();

        Universe* readFile(const Universe*);
    };

};

#endif
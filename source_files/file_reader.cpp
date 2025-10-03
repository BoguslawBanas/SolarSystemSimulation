#include "../header_files/file_reader.h"

file_reader::File_Reader::File_Reader(){

}

file_reader::File_Reader::~File_Reader()=default;

bool file_reader::File_Reader::readFile(const Universe *universe){
    char *str;
    int amount_of_planets=0;
    Planet planet;
    Color color;
    Vector3 v3;
    long double value;
    OPENFILENAMEA file;
    bool return_result=false;
    Universe *new_universe=NULL;

    memset(&file, 0, sizeof(file));
    file.lStructSize = sizeof(file);
    file.hwndOwner = NULL;
    file.lpstrFile = this->file_path;
    file.lpstrFile[0] = '\0';
    file.nMaxFile = sizeof(this->file_path);
    file.lpstrFilter = "All Files\0*.*\0Text Files\0*.TXT\0";
    file.nFilterIndex = 1;
    file.Flags=OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;

    if(GetOpenFileNameA(&file)){
        FILE *f=fopen(this->file_path, "rb");
        if(f){
            return_result=true;
            fscanf(f, "%s\n", str);
            printf("test2\n");
            fscanf(f, "%d", &amount_of_planets);

            new_universe=new Universe();
            printf("test1\n");

            for(int i=0;i<amount_of_planets;++i){
                fscanf(f, "%s");
                fscanf(f, "%s %f %f %f", str, &color.a, &color.b, &color.g, &color.r);
                planet.setColor(color);
                fscanf(f, "%s %Ld", str, &value);
                planet.setMass(value);
                fscanf(f, "%s %s", str, str);
                planet.setName(str);
                fscanf(f, "%s %f %f %f", str, &v3.x, &v3.y, &v3.z);
                planet.setPosition(v3);
                fscanf(f, "%s %Ld", str, &value);
                planet.setRadius(value);
                fscanf(f, "%s %f %f %f", str, &v3.x, &v3.y, &v3.z);
                planet.setVelocity(v3);

                new_universe->addPlanetToUniverse(planet);
                //remove later
                printf("test\n");
            }
        }
    }

    if(return_result){
        delete universe;
        universe=new_universe;
        return true;
    }
    delete new_universe;
    return false;
}
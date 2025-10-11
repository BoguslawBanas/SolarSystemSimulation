#include "../header_files/file_reader.h"

file_reader::File_Reader::File_Reader(){
    this->file_path[0]='\0';
}

file_reader::File_Reader::~File_Reader()=default;

Universe* file_reader::File_Reader::readFile(const Universe *universe){
    char str[260];
    int amount_of_planets=0;
    Planet planet;
    Color color;
    Vector3 v3;
    long double value;
    unsigned char uc;
    OPENFILENAMEA file;
    bool flag=true;
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
        FILE *f=fopen(this->file_path, "r");
        if(f){
            // return_result=true;
            fscanf(f, "%s", str);
            fscanf(f, "%d", &amount_of_planets);
            new_universe=new Universe();

            for(int i=0;i<amount_of_planets;++i){
                fscanf(f, "%259s", str);

                while(strcmp(str, "----")){
                    if(!strcmp(str, "Color:")){
                        fscanf(f, "%d", &uc);
                        color.a=uc;
                        fscanf(f, "%d", &uc);
                        color.b=uc;
                        fscanf(f, "%d", &uc);
                        color.g=uc;
                        fscanf(f, "%d", &uc);
                        color.r=uc;
                        planet.setColor(color);
                    }
                    else if(!strcmp(str, "Mass:")){
                        fscanf(f, "%Lf", &value);
                        planet.setMass(value);
                    }
                    else if(!strcmp(str, "Name:")){
                        fscanf(f, "%259s", str);
                        planet.setName(str);
                    }
                    else if(!strcmp(str, "Position:")){
                        fscanf(f, "%f %f %f", &v3.x, &v3.y, &v3.z);
                        planet.setPosition(v3);
                    }
                    else if(!strcmp(str, "Radius:")){
                        fscanf(f, "%Lf", &value);
                        planet.setRadius(value);
                    }
                    else if(!strcmp(str, "Velocity:")){
                        fscanf(f, "%f %f %f", &v3.x, &v3.y, &v3.z);
                        planet.setVelocity(v3);
                    }
                    fscanf(f, "%259s", str);
                }
                new_universe->addPlanetToUniverse(planet);
            }
        }
        fclose(f);
    }

    if(!flag){
        delete new_universe;
        new_universe=NULL;
    }

    return new_universe;
}
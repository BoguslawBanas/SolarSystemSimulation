#include "File_Reader_Controller.h"

Planet_Model* File_Reader_Controller::getPlanetFromFile(FILE *file){
    Color color;
    double mass, radius;
    char name[256];
    char path_to_texture[512];
    Vector3 position, velocity;
    fscanf(file, "%hhu %hhu %hhu %hhu\n", &color.a, &color.b, &color.g, &color.r);
    fscanf(file, "%lf\n", &mass);
    fscanf(file, "%s\n", name);
    if(!strcmp(name, "/0")){
        name[0]='\0';
    }
    fscanf(file, "%f %f %f\n", &position.x, &position.y, &position.z);
    fscanf(file, "%lf\n", &radius);
    fscanf(file, "%s\n", path_to_texture);
    if(!strcmp(name, "/0")){
        path_to_texture[0]='\0';
    }
    fscanf(file, "%f %f %f\n", &velocity.x, &velocity.y, &velocity.z);

    Planet_Model *planet=new Planet_Model();
    planet->setColor(color);
    planet->setMass(mass);
    planet->setName(name);
    planet->setPosition(position);
    planet->setRadius(radius);
    planet->setTexturePath(path_to_texture);
    planet->setVelocity(velocity);
    return planet;
}

Universe_Model* File_Reader_Controller::read(const char *path_to_file){
    char tmp_s[256];
    int amount_of_planets;
    long long int checksum_from_file;

    Universe_Model *new_universe=new Universe_Model();
    FILE *file=fopen(path_to_file, "rb");
    if(file){
        fscanf(file, "%[^\n]s", tmp_s);
        if(strcmp(tmp_s, "Solar system simulation.")!=0){
            fclose(file);
            delete new_universe;
            return NULL; 
        }
        fscanf(file, "%d", &amount_of_planets);
        for(int i=0;i<amount_of_planets;++i){
            new_universe->addPlanet(this->getPlanetFromFile(file));
        }

        const long long int checksum=new_universe->calculateChecksum();

        fscanf(file, "%lld", &checksum_from_file);
        fclose(file);
        if(checksum_from_file!=checksum){
            //checksum is not correct
            delete new_universe;
            return NULL;
        }
    }
    else{
        delete new_universe;
        return NULL;
    }
    return new_universe;
}

File_Reader_Controller::File_Reader_Controller(){}

File_Reader_Controller::~File_Reader_Controller()=default;

Universe_Model* File_Reader_Controller::readSnapshot(){
    return read(SNAPSHOT_FILE_PATH);
}

Universe_Model* File_Reader_Controller::readUniverse(const char *path_to_file){
    return read(path_to_file);
}
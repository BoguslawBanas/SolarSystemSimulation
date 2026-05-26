#include "File_Reader_Controller.h"

Planet_Model* File_Reader_Controller::getPlanetFromFile(FILE *file, long long int &checksum){
    Color color;
    double mass, radius;
    char name[256];
    char path_to_texture[512];
    Vector3 position, velocity;
    fscanf(file, "%hhu %hhu %hhu %hhu\n", &color.a, &color.b, &color.g, &color.r);
    fscanf(file, "%lf\n", &mass);
    fscanf(file, "%s\n", name);
    fscanf(file, "%f %f %f\n", &position.x, &position.y, &position.z);
    fscanf(file, "%lf\n", &radius);
    fscanf(file, "%s\n", path_to_texture);
    fscanf(file, "%f %f %f\n", &velocity.x, &velocity.y, &velocity.z);

    Planet_Model *planet=new Planet_Model();
    planet->setColor(color);
    planet->setMass(mass);
    planet->setName(name);
    planet->setPosition(position);
    planet->setRadius(radius);
    planet->setTexturePath(path_to_texture);
    planet->setVelocity(velocity);
    checksum+=planet->calculateChecksum();
    return planet;
}

bool File_Reader_Controller::read(Universe_Model* const universe, const char *path_to_file){
    long long int checksum=0;
    char tmp_s[256];
    int amount_of_planets;
    long long int checksum_from_file;
    std::vector<Planet_Model*>planets;
    FILE *file=fopen(path_to_file, "rb");
    if(file){
        fscanf(file, "%[^\n]s", tmp_s);
        if(strcmp(tmp_s, "Solar system simulation.")!=0){
            fclose(file);
            return false; 
        }
        fscanf(file, "%d", &amount_of_planets);
        checksum+=amount_of_planets;
        for(int i=0;i<amount_of_planets;++i){
            planets.push_back(this->getPlanetFromFile(file, checksum));
        }

        fscanf(file, "%lld", &checksum_from_file);
        fclose(file);
        if(checksum_from_file==checksum){
            //checksum is correct
            universe->removeAllPlanets();
            for(Planet_Model *model : planets){
                model->confirmModel();
                printf("Added planet: %s\n", model->getName());
                universe->addPlanet(model);
            }
        }
        else{
            //checksum is not correct
            for(Planet_Model *model : planets){
                delete model;
                model=NULL;
            }
            planets.clear();
            return false;
        }
    }
    else{
        return false;
    }
    return true;
}

File_Reader_Controller::File_Reader_Controller(){}

File_Reader_Controller::~File_Reader_Controller()=default;

bool File_Reader_Controller::readSnapshot(Universe_Model* const universe){
    return read(universe, SNAPSHOT_FILE_PATH);
}

bool File_Reader_Controller::readUniverse(Universe_Model* const universe, const char *path_to_file){
    return read(universe, path_to_file);
}
#include "File_Saver_Controller.h"

void File_Saver_Controller::addPlanetToFile(FILE *file, Planet_Model const * const planet){
    fprintf(file, "%hhu %hhu %hhu %hhu\n", planet->getColor().a, planet->getColor().b, planet->getColor().g, planet->getColor().r);
    fprintf(file, "%lf\n", planet->getMass());
    if(strcmp(planet->getName(), "\0")==0){
        fprintf(file, "/0\n");
    }
    else{
        fprintf(file, "%s\n", planet->getName());
    }
    fprintf(file, "%f %f %f\n", planet->getPosition().x, planet->getPosition().y, planet->getPosition().z);
    fprintf(file, "%lf\n", planet->getRadius());
    if(strcmp(planet->getTexturePath(), "\0")==0){
        fprintf(file, "/0\n");
    }
    else{
        fprintf(file, "%s\n", planet->getTexturePath());
    }
    fprintf(file, "%f %f %f\n", planet->getVelocity().x, planet->getVelocity().y, planet->getVelocity().z);
}

bool File_Saver_Controller::save(Universe_Model const * const universe, const char *path_to_file){
    const long long int checksum=universe->calculateChecksum();
    bool result=false;
    int amount_of_planets;

    FILE *file=fopen(path_to_file, "wb");
    if(file){
        fprintf(file, "Solar system simulation.\n");
        amount_of_planets=universe->getPlanets().size();
        fprintf(file, "%d\n", amount_of_planets);
        for(Planet_Model* const planet : universe->getPlanets()){
            this->addPlanetToFile(file, planet);
        }
        fprintf(file, "%lld\n", checksum);
        fclose(file);
    }
    else{
        return false;
    }
    return true;
}

File_Saver_Controller::File_Saver_Controller(){}

File_Saver_Controller::~File_Saver_Controller()=default;

bool File_Saver_Controller::saveSnapshot(Universe_Model const * const universe){
    return save(universe, SNAPSHOT_FILE_PATH);
}

bool File_Saver_Controller::saveUniverse(Universe_Model const * const universe, const char *path_to_file){
    return save(universe, path_to_file);
}
#include "File_Saver_Controller.h"

void File_Saver_Controller::addPlanetToFile(FILE *file, Planet_Model const * const planet, long long int &checksum){
    fprintf(file, "%d %d %d %d\n", planet->getColor().a, planet->getColor().b, planet->getColor().g, planet->getColor().r);
    checksum+=(planet->getColor().a+planet->getColor().b+planet->getColor().g+planet->getColor().r);
    fprintf(file, "%lf\n", planet->getMass());
    checksum+=(long long int)planet->getMass();
    fprintf(file, "%s\n", planet->getName());
    fprintf(file, "%f %f %f\n", planet->getPosition().x, planet->getPosition().y, planet->getPosition().z);
    checksum+=(long long int)planet->getPosition().x+(long long int)planet->getPosition().y+(long long int)planet->getPosition().z;
    fprintf(file, "%lf\n", planet->getRadius());
    checksum+=(long long int)planet->getRadius();
    fprintf(file, "%s\n", planet->getTexturePath());
    fprintf(file, "%f %f %f\n", planet->getVelocity().x, planet->getVelocity().y, planet->getVelocity().z);
    checksum+=(long long int)planet->getVelocity().x+(long long int)planet->getVelocity().y+(long long int)planet->getVelocity().z;
}

bool File_Saver_Controller::save(Universe_Model const * const universe, const char *path_to_file){
    long long int checksum=0;
    bool result=false;
    int tmp_int;

    FILE *file=fopen(path_to_file, "wb");
    if(file){
        fprintf(file, "Solar system simulation.\n");
        tmp_int=universe->getPlanets().size();
        checksum+=tmp_int;
        fprintf(file, "%d\n", tmp_int);
        for(Planet_Model* const planet : universe->getPlanets()){
            this->addPlanetToFile(file, planet, checksum);
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
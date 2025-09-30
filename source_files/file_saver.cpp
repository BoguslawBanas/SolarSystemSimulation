#include "../header_files/file_saver.h"

void file_saver::File_Saver::create_color_json(FILE *f, const Color &color){
    fprintf(f, "\t\t\t\"Color\": {\n");
    fprintf(f, "\t\t\t\t\"a\": %u,\n", color.a);
    fprintf(f, "\t\t\t\t\"b\": %u,\n", color.b);
    fprintf(f, "\t\t\t\t\"g\": %u,\n", color.g);
    fprintf(f, "\t\t\t\t\"r\": %u\n", color.r);
    fprintf(f, "\t\t\t},\n");
}

void file_saver::File_Saver::create_mass_json(FILE *f, const long double mass){
    fprintf(f, "\t\t\t\"Mass\": %Lf,\n", mass);
}

void file_saver::File_Saver::create_name_json(FILE *f, const char *name){
    fprintf(f, "\t\t\t\"Name\": \"%s\",\n", name);
}

void file_saver::File_Saver::create_position_json(FILE *f, const Vector3 &position){
    fprintf(f, "\t\t\t\"Position\": {\n");
    fprintf(f, "\t\t\t\t\"x\": %f,\n", position.x);
    fprintf(f, "\t\t\t\t\"y\": %f,\n", position.y);
    fprintf(f, "\t\t\t\t\"z\": %f\n", position.z);
    fprintf(f, "\t\t\t},\n");
}

void file_saver::File_Saver::create_radius_json(FILE *f, const long double radius){
    fprintf(f, "\t\t\t\"Radius\": %Lf,\n", radius);
}

void file_saver::File_Saver::create_velocity_json(FILE *f, const Vector3 &velocity){
    fprintf(f, "\t\t\t\"Velocity\": {\n");
    fprintf(f, "\t\t\t\t\"x\": %f,\n", velocity.x);
    fprintf(f, "\t\t\t\t\"y\": %f,\n", velocity.y);
    fprintf(f, "\t\t\t\t\"z\": %f\n", velocity.z);
    fprintf(f, "\t\t\t}\n");
}

file_saver::File_Saver::File_Saver(){
    this->file_path[0]='\0';
}

file_saver::File_Saver::~File_Saver()=default;

bool file_saver::File_Saver::saveFile(Universe* const universe){
    int counter=0;
    bool result=false;
    OPENFILENAMEA file;

    memset(&file, 0, sizeof(file));
    file.lStructSize = sizeof(file);
    file.hwndOwner = NULL;
    file.lpstrFile = this->file_path;
    file.lpstrFile[0] = '\0';
    file.nMaxFile = sizeof(this->file_path);
    file.lpstrFilter = "All Files\0*.*\0Text Files\0*.TXT\0";
    file.nFilterIndex = 1;
    file.Flags=OFN_READONLY;
    if(GetOpenFileNameA(&file)){
        FILE *f=fopen(file.lpstrFile, "wb");
        if(f){
            fprintf(f, "{\n");
            fprintf(f, "\t\"planets\": [\n");
            for(auto &it : universe->getPlanets()){
                fprintf(f, "\t\t{\n");
                this->create_color_json(f, it.getColor());
                this->create_mass_json(f, it.getMass());
                this->create_name_json(f, it.getName());
                this->create_position_json(f, it.getPosition());
                this->create_radius_json(f, it.getRadius());
                this->create_velocity_json(f, it.getVelocity());
                // fprintf(f, "Color: %u %u %u %u\n", universe->getPlanets()[i].getColor().a, universe->getPlanets()[i].getColor().b, universe->getPlanets()[i].getColor().g, universe->getPlanets()[i].getColor().r);
                // fprintf(f, "Mass: %Lf\n", universe->getPlanets()[i].getMass());
                // fprintf(f, "Name: %s\n", universe->getPlanets()[i].getName());
                // fprintf(f, "Position: %f %f %f\n", universe->getPlanets()[i].getPosition().x, universe->getPlanets()[i].getPosition().y, universe->getPlanets()[i].getPosition().z);
                // fprintf(f, "Radius: %Lf\n", universe->getPlanets()[i].getRadius());
                // fprintf(f, "Velocity: %f %f %f\n", universe->getPlanets()[i].getVelocity().x, universe->getPlanets()[i].getVelocity().y, universe->getPlanets()[i].getVelocity().z);
                // fprintf(f, "\n\n\n");
                ++counter;
                if(counter==universe->getPlanets().size()){
                    fprintf(f, "\t\t}\n");
                }
                else{
                    fprintf(f, "\t\t},\n");
                }
            }
            fprintf(f, "\t]\n");
            fprintf(f, "}");
            result=true;
        }
        fclose(f);
    }

    return result;
}

const char* file_saver::File_Saver::getFilePath(){
    return this->file_path;
}
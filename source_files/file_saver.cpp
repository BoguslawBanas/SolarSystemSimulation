#include "../header_files/file_saver.h"

void file_saver::File_Saver::save_color(FILE *f, const Color &color){
    // fprintf(f, "\t\t\t\"Color\": {\n");
    // fprintf(f, "\t\t\t\t\"a\": %u,\n", color.a);
    // fprintf(f, "\t\t\t\t\"b\": %u,\n", color.b);
    // fprintf(f, "\t\t\t\t\"g\": %u,\n", color.g);
    // fprintf(f, "\t\t\t\t\"r\": %u\n", color.r);
    // fprintf(f, "\t\t\t},\n");
    fprintf(f, "Color: %u %u %u %u\n", color.a, color.b, color.g, color.r);
}

void file_saver::File_Saver::save_mass(FILE *f, const long double mass){
    // fprintf(f, "\t\t\t\"Mass\": %Lf,\n", mass);
    fprintf(f, "Mass: %Lf\n", mass);
}

void file_saver::File_Saver::save_name(FILE *f, const char *name){
    // fprintf(f, "\t\t\t\"Name\": \"%s\",\n", name);
    fprintf(f, "Name: %s\n", name);
}

void file_saver::File_Saver::save_position(FILE *f, const Vector3 &position){
    // fprintf(f, "\t\t\t\"Position\": {\n");
    // fprintf(f, "\t\t\t\t\"x\": %f,\n", position.x);
    // fprintf(f, "\t\t\t\t\"y\": %f,\n", position.y);
    // fprintf(f, "\t\t\t\t\"z\": %f\n", position.z);
    // fprintf(f, "\t\t\t},\n");
    fprintf(f, "Position: %f %f %f\n", position.x, position.y, position.z);
}

void file_saver::File_Saver::save_radius(FILE *f, const long double radius){
    // fprintf(f, "\t\t\t\"Radius\": %Lf,\n", radius);
    fprintf(f, "Radius: %Lf\n", radius);
}

void file_saver::File_Saver::save_velocity(FILE *f, const Vector3 &velocity){
    // fprintf(f, "\t\t\t\"Velocity\": {\n");
    // fprintf(f, "\t\t\t\t\"x\": %f,\n", velocity.x);
    // fprintf(f, "\t\t\t\t\"y\": %f,\n", velocity.y);
    // fprintf(f, "\t\t\t\t\"z\": %f\n", velocity.z);
    // fprintf(f, "\t\t\t}\n");
    fprintf(f, "Velocity: %f %f %f\n", velocity.x, velocity.y, velocity.z);
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
            fprintf(f, "Solar_system_simulation_file_save.\n");
            for(auto &it : universe->getPlanets()){
                fprintf(f, "\n----\n");
                this->save_color(f, it.getColor());
                this->save_mass(f, it.getMass());
                this->save_name(f, it.getName());
                this->save_position(f, it.getPosition());
                this->save_radius(f, it.getRadius());
                this->save_velocity(f, it.getVelocity());
            }
            result=true;
        }
        fclose(f);
    }

    return result;
}

const char* file_saver::File_Saver::getFilePath(){
    return this->file_path;
}
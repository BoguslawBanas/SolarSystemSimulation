#include "Gravitational_Grid_2D_Model.h"

Calc_Grid_Str::Calc_Grid_Str(){
    this->pos=Vector3{};
    this->mass=0.1;
    this->amount_of_nodes=1;
    this->grid_delta=1.0;
    this->grid=NULL;
}

void* calcLogicSingleThread(void *arg){
    Calc_Grid_Str str=*(Calc_Grid_Str*)(arg);
    double distance;
    double f;
    double threshold=0.01;
    double distance_after_gravity_is_smaller_than_threshold;

    int min_x, max_x, min_y, max_y;

    distance_after_gravity_is_smaller_than_threshold=sqrt(G*str.mass*0.001/threshold);
    min_x=int(ceilf((str.pos.x-distance_after_gravity_is_smaller_than_threshold-str.start_pos)/str.grid_delta));
    max_x=int(floorf((str.pos.x+distance_after_gravity_is_smaller_than_threshold-str.start_pos)/str.grid_delta));
    min_y=int(ceilf((str.pos.z-distance_after_gravity_is_smaller_than_threshold-str.start_pos)/str.grid_delta));
    max_y=int(floorf((str.pos.z+distance_after_gravity_is_smaller_than_threshold-str.start_pos)/str.grid_delta));

    for(int i=min_x;i<=max_x;++i){
        if(i>=0 && i<str.amount_of_nodes){
            for(int j=min_y;j<=max_y;++j){
                if(j>=0 && j<str.amount_of_nodes){
                    distance=((str.pos.x-(i*str.grid_delta+str.start_pos))*(str.pos.x-(i*str.grid_delta+str.start_pos)))
                    +((str.pos.z-(j*str.grid_delta+str.start_pos))*(str.pos.z-(j*str.grid_delta+str.start_pos)));
                    if(distance<1e4l){
                        distance=1e4l;
                    }
                    f=G*(str.mass*0.001)/distance;
                    str.grid[i][j]-=f;
                }
            }
        }
    }

    return NULL;
}

double Gravitational_Grid_2D_Model::calcGridDelta(){
    return 2*fabs(this->start_pos)/this->amount_of_nodes;
}

Gravitational_Grid_2D_Model::Gravitational_Grid_2D_Model(const double start_pos, const unsigned amount_of_nodes, const double default_grid_height){
    this->start_pos=start_pos;
    this->amount_of_nodes=amount_of_nodes;
    this->default_height_of_the_grid=default_grid_height;
    this->grid=new float*[amount_of_nodes];
    for(int i=0;i<this->amount_of_nodes;++i){
        this->grid[i]=new float[amount_of_nodes];
        for(int j=0;j<this->amount_of_nodes;++j){
            this->grid[i][j]=this->default_height_of_the_grid;
        }
    }
    this->grid_delta=calcGridDelta();
}

Gravitational_Grid_2D_Model::~Gravitational_Grid_2D_Model(){
    for(int i=0;i<this->amount_of_nodes;++i){
        delete[] this->grid[i];
    }
    delete[] this->grid;
}

double Gravitational_Grid_2D_Model::getStartPosition() const{
    return this->start_pos;
}

unsigned Gravitational_Grid_2D_Model::getAmountOfNodes() const{
    return this->amount_of_nodes;
}

double Gravitational_Grid_2D_Model::getDefaultHeightOfTheGrid() const{
    return this->default_height_of_the_grid;
}

double Gravitational_Grid_2D_Model::getGridDelta() const{
    return this->grid_delta;
}

float** const Gravitational_Grid_2D_Model::getGrid() const{
    return this->grid;
}

void Gravitational_Grid_2D_Model::calcLogic(const std::vector<Planet_Model*>&planets){
    for(int i=0;i<this->amount_of_nodes;++i){
        for(int j=0;j<this->amount_of_nodes;++j){
            this->grid[i][j]=this->default_height_of_the_grid;
        }
    }

    pthread_t *threads=new pthread_t[planets.size()];
    Calc_Grid_Str *str=new Calc_Grid_Str[planets.size()];

    for(int i=0;i<planets.size();++i){
        str[i].pos=planets[i]->getPosition();
        str[i].mass=planets[i]->getMass();
        str[i].start_pos=this->start_pos;
        str[i].amount_of_nodes=this->amount_of_nodes;
        str[i].grid_delta=this->grid_delta;
        str[i].grid=this->grid;

        pthread_create(&threads[i], NULL, calcLogicSingleThread, &str[i]);
    }

    for(int i=0;i<planets.size();++i){
        pthread_join(threads[i], NULL);
    }

    delete[] str;
    delete[] threads;

    // double distance;
    // double f;
    // double threshold=0.01;
    // double distance_after_gravity_is_smaller_than_threshold;

    // int min_x, max_x, min_y, max_y;

    // for(auto it : planets){
    //     distance_after_gravity_is_smaller_than_threshold=sqrt(G*it->getMass()*0.001/threshold);
    //     min_x=int(ceilf((it->getPosition().x-distance_after_gravity_is_smaller_than_threshold-this->start_pos)/this->grid_delta));
    //     max_x=int(floorf((it->getPosition().x+distance_after_gravity_is_smaller_than_threshold-this->start_pos)/this->grid_delta));
    //     min_y=int(ceilf((it->getPosition().z-distance_after_gravity_is_smaller_than_threshold-this->start_pos)/this->grid_delta));
    //     max_y=int(floorf((it->getPosition().z+distance_after_gravity_is_smaller_than_threshold-this->start_pos)/this->grid_delta));

    //     for(int i=min_x;i<=max_x;++i){
    //         if(i>=0 && i<this->amount_of_nodes){
    //             for(int j=min_y;j<=max_y;++j){
    //                 if(j>=0 && j<this->amount_of_nodes){
    //                     distance=((it->getPosition().x-(i*this->grid_delta+this->start_pos))*(it->getPosition().x-(i*this->grid_delta+this->start_pos)))
    //                     +((it->getPosition().z-(j*this->grid_delta+this->start_pos))*(it->getPosition().z-(j*this->grid_delta+this->start_pos)));
    //                     if(distance<1e4l){
    //                         distance=1e4l;
    //                     }
    //                     f=G*(it->getMass()*0.001)/distance;
    //                     this->grid[i][j]-=f;
    //                 }
    //             }
    //         }
    //     }
    // }


}
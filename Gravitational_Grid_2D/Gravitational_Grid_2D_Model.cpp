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
    const double threshold=0.01;
    double distance;
    double f;
    double distance_after_gravity_is_smaller_than_threshold=sqrt(G*str.mass*0.001/threshold);

    int min_x=int(ceilf((str.pos.x-distance_after_gravity_is_smaller_than_threshold-str.start_pos)/str.grid_delta));
    int max_x=int(floorf((str.pos.x+distance_after_gravity_is_smaller_than_threshold-str.start_pos)/str.grid_delta));
    int min_y=int(ceilf((str.pos.z-distance_after_gravity_is_smaller_than_threshold-str.start_pos)/str.grid_delta));
    int max_y=int(floorf((str.pos.z+distance_after_gravity_is_smaller_than_threshold-str.start_pos)/str.grid_delta));

    for(int i=min_x;i<=max_x;++i){
        if(i>=0 && i<str.amount_of_nodes){
            for(int j=min_y;j<=max_y;++j){
                if(j>=0 && j<str.amount_of_nodes){
                    distance=((str.pos.x-(i*str.grid_delta+str.start_pos))*(str.pos.x-(i*str.grid_delta+str.start_pos)))
                    +((str.pos.z-(j*str.grid_delta+str.start_pos))*(str.pos.z-(j*str.grid_delta+str.start_pos)));
                    if(distance<1e4){
                        distance=1e4;
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
    return 2.0*fabs(this->start_pos)/this->amount_of_nodes;
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

    this->amount_of_threads=0;
    this->threads=new pthread_t[0];
    this->calc_grid_strs=new Calc_Grid_Str[0];
}

Gravitational_Grid_2D_Model::~Gravitational_Grid_2D_Model(){
    for(int i=0;i<this->amount_of_nodes;++i){
        delete[] this->grid[i];
    }
    delete[] this->grid;
    delete[] this->threads;
    delete[] this->calc_grid_strs;
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

    if(planets.size()!=this->amount_of_threads){
        this->amount_of_threads=planets.size();
        this->threads=(pthread_t*)realloc(this->threads, this->amount_of_threads*sizeof(pthread_t));
        this->calc_grid_strs=(Calc_Grid_Str*)realloc(this->calc_grid_strs, this->amount_of_threads*sizeof(Calc_Grid_Str));
    }

    for(int i=0;i<this->amount_of_threads;++i){
        this->calc_grid_strs[i].pos=planets[i]->getPosition();
        this->calc_grid_strs[i].mass=planets[i]->getMass();
        this->calc_grid_strs[i].start_pos=this->start_pos;
        this->calc_grid_strs[i].amount_of_nodes=this->amount_of_nodes;
        this->calc_grid_strs[i].grid_delta=this->grid_delta;
        this->calc_grid_strs[i].grid=this->grid;

        pthread_create(&this->threads[i], NULL, calcLogicSingleThread, &this->calc_grid_strs[i]);
    }

    for(int i=0;i<this->amount_of_threads;++i){
        pthread_join(this->threads[i], NULL);
    }
}
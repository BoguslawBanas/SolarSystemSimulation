#include "../header_files/gravitational_grid_2d.h"

Gravitational_Grid_2D::Gravitational_Grid_2D(const float start_pos, const int amount_of_nodes, const float default_height_of_grid, const float distance_divider){
    this->start_pos=start_pos;
    this->amount_of_nodes=amount_of_nodes|1; //grid needs to have odd number of nodes
    this->default_height_of_grid=default_height_of_grid;
    this->grid_delta=2*fabs(start_pos)/(amount_of_nodes-1);
    this->distance_const_divider=distance_divider;

    this->grid=new float*[amount_of_nodes];
    for(int i=0;i<amount_of_nodes;++i){
        this->grid[i]=new float[amount_of_nodes];
        for(int j=0;j<amount_of_nodes;++j){
            this->grid[i][j]=default_height_of_grid;
        }
    }
}

Gravitational_Grid_2D::~Gravitational_Grid_2D(){
    for(int i=0;i<this->amount_of_nodes;++i){
        delete[] this->grid[i];
    }
    delete[] this->grid;
}

void Gravitational_Grid_2D::calculateGrid(const std::vector<Planet>& planets){
    long double distance;
    long double f;
    long double threshold=0.01l;
    float distance_after_gravity_is_small_enough;
     
    int min_x, max_x, min_y, max_y;

    for(auto &it : planets){
        distance_after_gravity_is_small_enough=sqrtl(G*it.getMass()*0.001l/threshold);
        min_x=int(ceilf((it.getPosition().x-distance_after_gravity_is_small_enough-this->start_pos)/this->grid_delta));
        max_x=int(floorf((it.getPosition().x+distance_after_gravity_is_small_enough-this->start_pos)/this->grid_delta));
        min_y=int(ceilf((it.getPosition().z-distance_after_gravity_is_small_enough-this->start_pos)/this->grid_delta));
        max_y=int(floorf((it.getPosition().z+distance_after_gravity_is_small_enough-this->start_pos)/this->grid_delta));

        for(int i=min_x;i<=max_x;++i){
            if(i>=0 && i<this->amount_of_nodes){
                for(int j=min_y;j<=max_y;++j){
                    if(j>=0 && j<this->amount_of_nodes){
                        distance=((it.getPosition().x-(i*this->grid_delta+this->start_pos))*(it.getPosition().x-(i*this->grid_delta+this->start_pos)))
                        +((it.getPosition().z-(j*this->grid_delta+this->start_pos))*(it.getPosition().z-(j*this->grid_delta+this->start_pos)));
                        if(distance<1e4l){
                            distance=1e4l;
                        }
                        f=G*(it.getMass()*0.001l)/distance;
                        this->grid[i][j]-=f;
                    }
                }
            }

        }
    }
}

void Gravitational_Grid_2D::drawGrid(const double distance_const){
    for(int i=0;i<this->amount_of_nodes-1;++i){
        for(int j=0;j<this->amount_of_nodes-1;++j){
            DrawLine3D((Vector3){(this->start_pos+i*this->grid_delta)/this->distance_const_divider, this->grid[i][j], (this->start_pos+j*this->grid_delta)/this->distance_const_divider}, (Vector3){(this->start_pos+(i+1)*this->grid_delta)/this->distance_const_divider, this->grid[i+1][j], (this->start_pos+j*this->grid_delta)/this->distance_const_divider}, GRAY);
            DrawLine3D((Vector3){(this->start_pos+i*this->grid_delta)/this->distance_const_divider, this->grid[i][j], (this->start_pos+j*this->grid_delta)/this->distance_const_divider}, (Vector3){(this->start_pos+i*this->grid_delta)/this->distance_const_divider, this->grid[i][j+1], (this->start_pos+(j+1)*this->grid_delta)/this->distance_const_divider}, GRAY);
        }
    }

    for(int i=0;i<this->amount_of_nodes;++i){
        for(int j=0;j<this->amount_of_nodes;++j){
            this->grid[i][j]=this->default_height_of_grid;
        }
    }
}
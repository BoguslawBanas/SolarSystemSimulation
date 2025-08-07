#include "../header_files/gravitational_grid_2d.h"

Gravitational_Grid_2D::Gravitational_Grid_2D(const Vector2 &start_pos, const int amount_of_nodes, const double default_height_of_grid){
    this->start_pos=start_pos;
    this->amount_of_nodes=amount_of_nodes;
    this->default_height_of_grid=default_height_of_grid;
    this->grid=new Vector3[amount_of_nodes*amount_of_nodes];
    for(int i=0;i<amount_of_nodes;++i){
        for(int j=0;j<amount_of_nodes;++j){
            grid[i*amount_of_nodes+j]=(Vector3){start_pos.x+(i*fabs(start_pos.x/(amount_of_nodes/2))), default_height_of_grid, start_pos.y+(j*fabs(start_pos.y/(amount_of_nodes/2)))};
        }
    }
}

Gravitational_Grid_2D::~Gravitational_Grid_2D(){
    delete[] grid;
}

void Gravitational_Grid_2D::calculateGrid(const std::vector<Planet>& planets){
    double distance;
    for(auto &it : planets){
        for(int i=0;i<amount_of_nodes;++i){
            for(int j=0;j<amount_of_nodes;++j){
                distance=(it.getPosition().x-grid[i*this->amount_of_nodes+j].x)*(it.getPosition().x-grid[i*this->amount_of_nodes+j].x)
                +(it.getPosition().y-grid[i*this->amount_of_nodes+j].z)*(it.getPosition().y-grid[i*this->amount_of_nodes+j].z);
                if(distance<fabs(start_pos.x*2/amount_of_nodes)){
                    distance=fabs(start_pos.x*2/amount_of_nodes);
                }

                grid[i*this->amount_of_nodes+j].y-=G*(it.getMass()*0.01)/(distance);
            }
        }
    }
}

void Gravitational_Grid_2D::drawGrid(const double distance_const){
    for(int i=0;i<this->amount_of_nodes-1;++i){
        for(int j=0;j<this->amount_of_nodes-1;++j){
            DrawLine3D((Vector3){grid[i*amount_of_nodes+j].x/distance_const, grid[i*amount_of_nodes+j].y, grid[i*amount_of_nodes+j].z/distance_const}, (Vector3){grid[i*amount_of_nodes+j+1].x/distance_const, grid[i*amount_of_nodes+j+1].y, grid[i*amount_of_nodes+j+1].z/distance_const}, GRAY);
            DrawLine3D((Vector3){grid[i*amount_of_nodes+j].x/distance_const, grid[i*amount_of_nodes+j].y, grid[i*amount_of_nodes+j].z/distance_const}, (Vector3){grid[(i+1)*amount_of_nodes+j].x/distance_const, grid[(i+1)*amount_of_nodes+j].y, grid[(i+1)*amount_of_nodes+j].z/distance_const}, GRAY);
        }
    }

    for(int i=0;i<this->amount_of_nodes;++i){
        for(int j=0;j<this->amount_of_nodes;++j){
            this->grid[i*this->amount_of_nodes+j]=(Vector3){this->start_pos.x+(i*fabs(this->start_pos.x/(this->amount_of_nodes/2))), default_height_of_grid, this->start_pos.y+(j*fabs(this->start_pos.y/(this->amount_of_nodes/2)))};
        }
        // this->grid[i].y=this->default_height_of_grid;
    }
}
#include "Gravitational_Grid_2D_View.h"
#include <raylib.h>

Gravitational_Grid_2D_View::Gravitational_Grid_2D_View(const double distance_divider){
    this->distance_divider=distance_divider;
}

Gravitational_Grid_2D_View::~Gravitational_Grid_2D_View()=default;

void Gravitational_Grid_2D_View::draw(const float start_pos, const unsigned amount_of_nodes, const float grid_delta, float** const grid){
    Vector3 v1;
    Vector3 v2;
    Vector3 v3;

    const float threshold=0.001f;
    float tmp_height;
    int j=0;

    v1=Vector3{start_pos/(float)this->distance_divider, grid[0][0], start_pos/(float)this->distance_divider};
    for(int i=1;i<amount_of_nodes-1;++i){
        if(fabs(grid[0][i-1]-grid[0][i])>threshold){
            v2=Vector3{v1.x, grid[0][i], (start_pos+i*grid_delta)/(float)this->distance_divider};
            DrawLine3D(v1, v2, GRAY);
            v1=v2;
        }
    }
    DrawLine3D(v1, Vector3{start_pos/(float)this->distance_divider, grid[0][amount_of_nodes-1], (start_pos+grid_delta*amount_of_nodes)/(float)this->distance_divider}, GRAY);

    v1=Vector3{start_pos/(float)this->distance_divider, grid[0][0], start_pos/(float)this->distance_divider};
    for(int i=1;i<amount_of_nodes-1;++i){
        if(fabs(grid[i-1][0]-grid[i][0])>threshold){
            v2=Vector3{(start_pos+i*grid_delta)/(float)this->distance_divider, grid[i][0], v1.z};
            DrawLine3D(v1, v2, GRAY);
            v1=v2;
        }
    }
    DrawLine3D(v1, Vector3{(start_pos+grid_delta*amount_of_nodes)/(float)this->distance_divider, grid[amount_of_nodes-1][0], start_pos/(float)this->distance_divider}, GRAY);

    for(int i=1;i<amount_of_nodes;++i){
        v1=Vector3{(start_pos+i*grid_delta)/(float)this->distance_divider, grid[i][0], start_pos/(float)this->distance_divider};
        for(int j=1;j<amount_of_nodes;++j){
            if(fabs(grid[i][j-1]-grid[i][j])>threshold){
                v2=Vector3{v1.x, grid[i][j], (start_pos+j*grid_delta)/(float)this->distance_divider};
                DrawLine3D(v1, v2, GRAY);
                v1=v2;
            }
        }
        DrawLine3D(v1, Vector3{v1.x, grid[amount_of_nodes-1][0], (start_pos+amount_of_nodes*grid_delta)/(float)this->distance_divider}, GRAY);
    }

    for(int i=1;i<amount_of_nodes;++i){
        v1=Vector3{start_pos/(float)this->distance_divider, grid[0][i], (start_pos+i*grid_delta)/(float)this->distance_divider};
        for(int j=1;j<amount_of_nodes;++j){
            if(fabs(grid[j-1][i]-grid[j][i])>threshold){
                v2=Vector3{(start_pos+j*grid_delta)/(float)this->distance_divider, grid[j][i], v1.z};
                DrawLine3D(v1, v2, GRAY);
                v1=v2;
            }
        }
        DrawLine3D(Vector3{(start_pos+amount_of_nodes*grid_delta)/(float)this->distance_divider, grid[0][amount_of_nodes-1], v1.z}, v1, GRAY);
    }

    // for(int i=0;i<amount_of_nodes-2;++i){
    //     for(int j=0;j<amount_of_nodes-2;++j){
    //         v1=Vector3{(start_pos+i*grid_delta)/(float)this->distance_divider, grid[i][j], (start_pos+j*grid_delta)/(float)this->distance_divider};
    //         v2=Vector3{(start_pos+i*grid_delta)/(float)this->distance_divider, grid[i][j+1], (start_pos+(j+1)*grid_delta)/(float)this->distance_divider};
    //         v3=Vector3{(start_pos+(i+1)*grid_delta)/(float)this->distance_divider, grid[i+1][j], (start_pos+j*grid_delta)/(float)this->distance_divider};
    //         DrawLine3D(v1, v2, GRAY);
    //         DrawLine3D(v1, v3, GRAY);
    //     }
    // }
}
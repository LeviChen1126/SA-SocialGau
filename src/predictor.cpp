#include "predictor.hpp"
#include <algorithm>

static inline std::pair<double,double> last_step_velocity(const Pedestrian& p, int obs_len){
    if ((int)p.obs_x_traj.size() < obs_len) return {0.0, 0.0};
    int i2 = obs_len-1;
    int i1 = obs_len-2;
    double vx = p.obs_x_traj[i2] - p.obs_x_traj[i1];
    double vy = p.obs_y_traj[i2] - p.obs_y_traj[i1];
    return {vx, vy};
}

void run_step_prediction(StepData& step, const Args& args){
    for(auto& ped : step){
        if ((int)ped.obs_x_traj.size() < args.obs_len) {
            ped.pred_x_traj.clear();
            ped.pred_y_traj.clear();
            continue;
        }
        ped.pred_x_traj.clear();
        ped.pred_y_traj.clear();

        double x0 = ped.obs_x_traj[args.obs_len-1];
        double y0 = ped.obs_y_traj[args.obs_len-1];
        auto [vx, vy] = last_step_velocity(ped, args.obs_len);

        for(int k=0;k<args.pred_len;++k){
            x0 += vx;
            y0 += vy;
            ped.pred_x_traj.push_back(x0);
            ped.pred_y_traj.push_back(y0);
        }
    }
}

#include "metrics.hpp"
#include <cmath>

std::pair<double,double> cal_step_ade_fde(const StepData& pred_step){
    double sum_ade_err = 0.0;
    double sum_fde_err = 0.0;

    for(const auto& ped : pred_step){
        size_t n = std::min(ped.pred_x_traj.size(), ped.gt_x_traj.size());
        if(n==0) continue;
        double acc = 0.0;
        for(size_t i=0;i<n;++i){
            double dx = ped.gt_x_traj[i] - ped.pred_x_traj[i];
            double dy = ped.gt_y_traj[i] - ped.pred_y_traj[i];
            double d  = std::sqrt(dx*dx + dy*dy);
            acc += d;
            if (i==n-1) sum_fde_err += d;
        }
        sum_ade_err += (acc / double(n));
    }
    return {sum_ade_err, sum_fde_err};
}

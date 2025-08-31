#include "sd_utils.hpp"

double cal_amp(std::vector<Pedestrian>& step,
               std::vector<SDData>& sd_mem,
               int p_id,
               bool check_step1,
               double init_amp,
               double learning_rate){
    (void)step; (void)check_step1; (void)learning_rate;
    if ((int)sd_mem.size() > p_id){
        return sd_mem[p_id].amp;
    }
    return init_amp;
}

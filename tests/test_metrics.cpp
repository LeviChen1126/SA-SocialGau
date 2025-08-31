#include "metrics.hpp"
#include <cassert>

int main(){
    StepData step;
    auto res = cal_step_ade_fde(step);
    assert(res.first == 0.0 && res.second == 0.0);
    return 0;
}

#pragma once
#include "types.hpp"
#include <utility>

std::pair<double,double> cal_step_ade_fde(const StepData& pred_step);

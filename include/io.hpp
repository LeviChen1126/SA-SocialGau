#pragma once
#include "types.hpp"
#include <string>
#include <vector>

void loadJson(const std::string& path, std::vector<StepData>& dataset);

std::string get_default_dataset_path();

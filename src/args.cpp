#include "args.hpp"
#include <string>
#include <vector>

std::vector<std::string> Args::getDatasetPaths(int pred_len){
    (void)pred_len;
    return { "datasets/eth.json" };
}

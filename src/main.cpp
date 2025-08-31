#include <iostream>
#include <vector>
#include "args.hpp"
#include "io.hpp"
#include "predictor.hpp"
#include "metrics.hpp"

int main(int argc, char** argv){
    Args args;
    std::string path = (argc>=2)? std::string(argv[1]) : get_default_dataset_path();

    std::vector<StepData> dataset;
    try {
        loadJson(path, dataset);
    } catch(const std::exception& e){
        std::cerr << "Load failed: " << e.what() << "\n";
        return 1;
    }

    double total_ade = 0.0, total_fde = 0.0;
    size_t total_steps = 0, total_peds = 0;

    for(auto& step : dataset){
        run_step_prediction(step, args);
        auto [sade, sfde] = cal_step_ade_fde(step);
        total_ade += sade;
        total_fde += sfde;
        total_steps += 1;
        total_peds += step.size();
    }

    if (total_peds == 0){
        std::cout << "No predictions.\n"; return 0;
    }

    std::cout << "ADE: " << (total_ade / double(total_peds)) << "\n";
    std::cout << "FDE: " << (total_fde / double(total_peds)) << "\n";
    return 0;
}

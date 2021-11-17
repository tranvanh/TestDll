#include "Model.h"

std::pair<int, double> Model::predict(const std::vector<double> &inputData) {
    auto output = mModel(cppflow::tensor(inputData, { 1,this->mTimestep,this->mFeatureSize }));
    auto values = output.get_data<double>();
    
    double glob_max = 0.;
    int res = -1;
    for (int i = 0; i < values.size(); ++i) {
        res = values[i] > glob_max ? i : res;
        glob_max = values[i] > glob_max ? values[i] : glob_max;
    }

    res = glob_max >= mThreshold ? res : -1; // validating threshold
    return std::make_pair(res, glob_max);
}
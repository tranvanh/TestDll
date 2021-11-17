#pragma once
#include <iostream>
#include <vector>
#include "../../includes/cppflow/ops.h"
#include "../../includes/cppflow/model.h"


class Model
{
public:
	Model() : mTimestep(0), mFeatureSize(0), mThreshold(0) {};
	Model(const std::string& modelDir, const std::string& serving, const int& t, const int& f, const double& threshold) : mTimestep(t), mFeatureSize(f), mThreshold(threshold) {
		std::cout << "init inside before Model" << std::endl;
		mModel.loadModel(modelDir, serving);
		std::cout << "init Model" << std::endl;
	};
	/** Preform prediction **/
	std::pair<int, double> predict(const std::vector<double>& inputData);
	int getTimeStep() const { return this->mTimestep; }
	int getFeaturesSize() const { return this->mFeatureSize; }

private:
	cppflow::model mModel;
	int mTimestep;
	int mFeatureSize;
	double mThreshold;
};

#include <iostream>
#include "Model.h"
#include "CTest.h"

void printTest() {
	std::cout << "test" << std::endl;
}


auto modelDir = "./TrainedModel";
auto serve_command = "serving_default_bidirectional_4_input";
int timestep = 60;
int featureSize = 31;
double threshold = 80;

Model model(
	modelDir,
	serve_command,
	timestep,
	featureSize,
	threshold
);

void predictionTest() {
	std::vector<double> testInput = { 174.764,179.419,180,174.27,174.27,173.202,178.977,179.99,178.23,177.747,-78.7934,330.896,-11.0242,-58.096,344.547,-75.0337,-10.9392,359.526,-84.9223,24.5038,367.454,-68.4322,54.8553,357.718,-38.9895,-9.18619,318.428,13.7324,16.4626,14.2954,22.038 };
	auto [type, probability] = model.predict(testInput);
	std::cout << type << "|" << probability << std::endl;
}
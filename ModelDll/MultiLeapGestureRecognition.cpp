#include <iostream>
#include "Model.h"
#include "ConfigManager.h"
#include "MultiLeapGestureRecognition.h"

void Multileap_printTest() {
	std::cout << "test" << std::endl;
}

static ConfigManager configManager;
static Model model(
	configManager.getConfigValue("model_directory").asCString(),
	configManager.getConfigValue("serve_command").asCString(),
	configManager.getConfigValue("timestep").asInt(),
	configManager.getConfigValue("num_features").asInt(),
	configManager.getConfigValue("threshold").asDouble()
);

std::vector<double> testInput = { 174.764,179.419,180,174.27,174.27,173.202,178.977,179.99,178.23,177.747,-78.7934,330.896,-11.0242,-58.096,344.547,-75.0337,-10.9392,359.526,-84.9223,24.5038,367.454,-68.4322,54.8553,357.718,-38.9895,-9.18619,318.428,13.7324,16.4626,14.2954,22.038 };
void Multileap_PredictionTest() {
	auto [type, probability] = model.predict(testInput);
	std::cout << type << "|" << probability << std::endl;
}
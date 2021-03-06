#include "ConfigManager.h"
ConfigManager::ConfigManager() : path(DEFAULT_CONFIG_PATH) {

    std::ifstream file_input(path.c_str());
    if (file_input.fail())
    {
        std::cout << "default configuration created" << std::endl;
        defaultConfig();
    }
    else
        file_input >> root;

    file_input.close();
    return;
}

void ConfigManager::defaultConfig() {
    float min_scales[] = {
        0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, -693.223, -12.7777,
        -612.731, -680.146, 0, -584.665, -668.353, 0,
        -569.33, -649.613, 0, -597.032, -675.481, 0,
        -590.976, -662.551, 0, -574.437, 0, 0,
        0
    };

    float max_scales[] = {
        180, 180, 180, 179.999, 179.997, 180,
        179.988,  180   ,  179.989,  179.96 ,  539.053, 1036.65 ,
        720.07 ,  581.654, 1090.93 ,  709.384,  585.01 , 1068.79 ,
        705.543,  567.779, 1056.79 ,  702.861,  544.45 , 1061.02 ,
        693.173,  499.893, 1008.3  ,  707.228,  145.94 ,  161.082,
        146.668
    };

    root["demo"] = false;
    root["timestep"] = 60;
    root["dynamic_timestep"] = 100;
    root["sliding_rate"] = 10;
    root["model_directory"] = "./TrainedModel";
    root["dataset_directory"] = "./Dataset";
    root["num_features"] = 31;
    root["epoch"] = 200;
    root["serve_command"] = "serving_default_bidirectional_4_input";
    root["gpu"] = false;

    for (int i = 0; i < 31; ++i) {
        root["min_scales"].append(Json::Value(min_scales[i]));
        root["max_scales"].append(Json::Value(max_scales[i]));
    }

    std::ofstream file_output(path.c_str(), std::ios::trunc);

    Json::StreamWriterBuilder builder;
    builder["commentStyle"] = "None";
    builder["indentation"] = "   ";

    std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());

    writer->write(root, &file_output);
    file_output.close();

    return;
}

std::vector<double> ConfigManager::getVectorDouble(const Json::Value &val) const
{
    std::vector<double> result(val.size());
    
    for (int i = 0; i < val.size(); ++i)
        result[i] = val[i].asDouble();
 
    return result;
}

std::vector<std::string> ConfigManager::getVectorString(const Json::Value& val) const
{
    std::vector<std::string> result(val.size());

    for (int i = 0; i < val.size(); ++i)
        result[i] = val[i].asCString();

    return result;
}

std::vector<std::pair<std::string, std::string>> ConfigManager::getVectorPairString(const Json::Value& val) const
{
    std::vector<std::pair<std::string, std::string>> result(val.size());

    for (int i = 0; i < val.size(); ++i)
        result[i] = std::make_pair(val[i][0].asCString(), val[i][1].asCString());

    return result;
}
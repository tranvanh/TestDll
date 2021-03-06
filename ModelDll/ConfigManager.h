#pragma once
#include <filesystem>
#include <shlobj.h>
#include <windows.h>
#include <string>
#include <json/value.h>
#include <fstream>
#include <iostream>
#include <json/json.h>
#include <vector>

#define DEFAULT_CONFIG_PATH "./gestureLeapConfig.json"

class ConfigManager
{
public:
	ConfigManager();

	/** Return config value at Key **/
	Json::Value getConfigValue(const char* key) const { return root[key]; }
	/** Return config array at Key **/
	std::vector<double> getVectorDouble(const Json::Value& val) const;
	std::vector<std::string> getVectorString(const Json::Value& val) const;
	std::vector<std::pair<std::string, std::string>> getVectorPairString(const Json::Value& val) const;
private:
	/** Create a config file with default values **/
	void defaultConfig();
	std::string path;
	Json::Value root;
};


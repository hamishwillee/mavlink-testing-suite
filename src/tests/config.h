#pragma once

#include <yaml-cpp/yaml.h>

// use YAML as config backend
using ConfigNode = YAML::Node;

namespace tests
{

/**
 * @class ConfigProvider
 * Stores or retrieves configuration data to/from a ConfigNode (abstracts YAML backend)
 */
class ConfigProvider
{
public:
    ConfigProvider(ConfigNode& config, bool store_config);

    template <typename T>
    void operator()(const std::string& config_name, T& value)
    {
        if (_store_config) {
            _config[config_name] = value;
        } else {
            if (_config[config_name])
                value = _config[config_name].as<T>();
        }
    }

private:
    ConfigNode& _config;
    const bool _store_config;  ///< if true, store config in _config, else load from _config
};

} // namespace tests

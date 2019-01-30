#include "config.h"

namespace tests
{

ConfigProvider::ConfigProvider(ConfigNode& config, bool store_config)
    : _config(config), _store_config(store_config)
{
}

} // namespace tests

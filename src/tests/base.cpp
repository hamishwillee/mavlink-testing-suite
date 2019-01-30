
#include "base.h"

namespace tests {

TestBase::TestBase(const Context& context) : _context(context) {}

void TestBase::loadConfig(ConfigNode& config)
{
    ConfigProvider provider(config, false);
    serialize(provider);
}

void TestBase::storeConfig(ConfigNode& config)
{
    ConfigProvider provider(config, true);
    serialize(provider);
}


}  // namespace tests

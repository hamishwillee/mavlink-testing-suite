#pragma once

#include "config.h"
#include <gtest/gtest.h>
#include <dronecode_sdk/dronecode_sdk.h>

#include <map>
#include <memory>
#include <string>


#define REGISTER_TEST(test_, case_) \
    TEST_F(test_, case_) \
{ \
    auto testcase = std::unique_ptr<case_>(new case_(*_context)); \
    testcase->loadConfig(_test_node); \
    testcase->run(); \
    testcase->storeConfig(_test_node); \
}

#define UNUSED(x) (void)(x)

namespace tests
{
/**
 * @struct Context
 * Data that is supplied to each test
 */
struct Context {
    Context(dronecode_sdk::System& system_) : system(system_) {}

    dronecode_sdk::System& system;
    // TODO: logging, ...
};

/**
 * @class TestBase
 * Base class for all tests
 */
class TestBase
{
public:
    explicit TestBase(const Context& context);
    virtual ~TestBase() = default;

    void loadConfig(ConfigNode& config);
    void storeConfig(ConfigNode& config);
    virtual void run() = 0;


protected:
    virtual void serialize(ConfigProvider& c) = 0;

    Context _context;
};


} // namespace tests

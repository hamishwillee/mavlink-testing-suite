#pragma once

#include "config.h"
#include "base.h"
#include <gtest/gtest.h>
#include <memory>
#include <string>


namespace tests
{

class AutopilotTest : public ::testing::Test {
public:
    static std::string connection_override;

protected:
    virtual void SetUp() override;
    virtual void TearDown() override;

    YAML::Node _test_node;
    std::shared_ptr<Context> _context{};

private:
    YAML::Node _config;
    std::string _test_name;
    dronecode_sdk::DronecodeSDK _dcsdk;
};


}  // namespace tests

#include "autopilot_test.h"
#include <future>

using namespace std;

namespace tests
{

std::string AutopilotTest::connection_override {};

void AutopilotTest::SetUp()
{
    _test_name = ::testing::UnitTest::GetInstance()->current_test_info()->name();
    _config = YAML::LoadFile("../config/autopilot.yaml");
    _test_node = _config["tests"][_test_name];

    std::string connection_uri = _config["connection"]["uri"].as<string>();
    if (!connection_override.empty()) {
        connection_uri = connection_override;
    }

    ASSERT_EQ(_dcsdk.add_any_connection(connection_uri),
              dronecode_sdk::ConnectionResult::SUCCESS);

    std::promise<void> prom;
    std::future<void> fut = prom.get_future();

    _dcsdk.register_on_discover([&prom](uint64_t uuid) {
        UNUSED(uuid);
        prom.set_value();
    });

    future_status stat = fut.wait_for(chrono::seconds(2));
    ASSERT_EQ(stat, future_status::ready);

    _context = unique_ptr<Context>(new Context(_dcsdk.system()));
}

void AutopilotTest::TearDown()
{
}


}  // namespace tests

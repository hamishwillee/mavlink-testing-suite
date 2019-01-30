
#include "tests/autopilot_test.h"
#include <gtest/gtest.h>


using namespace std;


int main(int argc, char** argv)
{
    if (argc == 2) {
        // connection_url format:
        // For TCP : tcp://[server_host][:server_port]
        // For UDP : udp://[bind_host][:bind_port]
        // For Serial : serial:///path/to/serial/dev[:baudrate]
        cout << "Connection overriden to: " << argv[1] << endl;
        tests::AutopilotTest::connection_override = argv[1];
    }

    ::testing::InitGoogleTest(&argc, argv);

    // TODO: we could filter the tests using the YAML config.
    //::testing::GTEST_FLAG(filter) = "AutopilotTest.Mission";


    return RUN_ALL_TESTS();
}

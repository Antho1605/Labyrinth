#define CATCH_CONFIG_RUNNER
#include "tests/catch.hpp"

int main(int argc, char *const argv[])
{
    Catch::Session().run(argc, argv);
}

#include <libFreeAssange/free_assange.hpp>

#include <fmt/core.h>

namespace lib_C {

int fn_c()
{
    free_assange::doIt();
    fmt::print("The answer is {}.", 42);
    return 42;
}

} // namespace lib_C

// Stub implementations for libstdc++ symbols that are referenced by the
// prebuilt WebRTC (built with _GLIBCXX_ASSERTIONS) but not exported by
// the system libstdc++.so (built without assertions). Linux only.

#include <cstdlib>

namespace std {

// Prebuilt WebRTC was built with -D_GLIBCXX_ASSERTIONS and references
// __glibcxx_assert_fail; system libstdc++ does not provide it.
__attribute__((visibility("default"))) void __glibcxx_assert_fail(
    const char* /* file */, int /* line */, const char* /* function */,
    const char* /* condition */) {
  std::abort();
}

// Some builds reference std::__throw_bad_array_new_length(); provide a stub.
__attribute__((visibility("default"))) void __throw_bad_array_new_length() {
  std::abort();
}

}  // namespace std

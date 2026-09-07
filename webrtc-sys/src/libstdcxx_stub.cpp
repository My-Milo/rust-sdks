// Copyright 2026 My-Milo
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

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

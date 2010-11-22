// Copyright 2010, Google Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
// * Redistributions of source code must retain the above copyright
//   notice, this list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above copyright
//   notice, this list of conditions and the following disclaimer in the
//   documentation and/or other materials provided with the distribution.
// * Neither the name of Google Inc. nor the names of its contributors
//   may be used to endorse or promote products derived from this software
//   without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

/// \file engine/suite_config.hpp
/// Test suite configuration parsing and representation.

#if !defined(ENGINE_SUITE_CONFIG_HPP)
#define ENGINE_SUITE_CONFIG_HPP

#include <vector>

#include "utils/cmdline/parser.hpp"
#include "utils/fs/path.hpp"

namespace engine {


/// Representation of the configuration of a test suite.
///
/// Test suites are collections of related test programs.  They are described by
/// a configuration file.
///
/// This class provides the parser for test suite configuration files and
/// methods to access the parsed data.
class suite_config {
    std::vector< utils::fs::path > _test_programs;

public:
    explicit suite_config(const std::vector< utils::fs::path >&);
    static suite_config load(const utils::fs::path&);
    static suite_config from_arguments(const utils::cmdline::args_vector&);

    const std::vector< utils::fs::path >& test_programs(void) const;
};


}  // namespace engine

#endif  // !defined(ENGINE_SUITE_CONFIG_HPP)

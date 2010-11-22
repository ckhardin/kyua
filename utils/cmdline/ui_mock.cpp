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

#include <iostream>

#include "utils/cmdline/ui_mock.hpp"

using utils::cmdline::ui_mock;


/// Writes a line to stderr and records it for further inspection.
///
/// \param message The line to print and record, without the trailing newline
///     character.
void
ui_mock::err(const std::string& message)
{
    std::cerr << message << "\n";
    _err_log.push_back(message);
}


/// Writes a line to stdout and records it for further inspection.
///
/// \param message The line to print and record, without the trailing newline
///     character.
void
ui_mock::out(const std::string& message)
{
    std::cout << message << "\n";
    _out_log.push_back(message);
}


/// Gets all the lines written to stderr.
///
/// \return The printed lines.
const std::vector< std::string >&
ui_mock::err_log(void) const
{
    return _err_log;
}


/// Gets all the lines written to stdout.
///
/// \return The printed lines.
const std::vector< std::string >&
ui_mock::out_log(void) const
{
    return _out_log;
}

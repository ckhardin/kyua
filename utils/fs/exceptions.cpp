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

#include "utils/format/macros.hpp"
#include "utils/fs/exceptions.hpp"

namespace fs = utils::fs;


/// Constructs a new error with a plain-text message.
///
/// \param message The plain-text error message.
fs::error::error(const std::string& message) :
    std::runtime_error(message)
{
}


/// Destructor for the error.
fs::error::~error(void) throw()
{
}


/// Constructs a new invalid_path_error.
///
/// \param textual_path Textual representation of the invalid path.
/// \param reason Description of the error in the path.
fs::invalid_path_error::invalid_path_error(const std::string& textual_path,
                                           const std::string& reason) :
    error(F("Invalid path '%s': %s") % textual_path % reason),
    _textual_path(textual_path)
{
}


/// Destructor for the error.
fs::invalid_path_error::~invalid_path_error(void) throw()
{
}


/// Returns the invalid path related to the exception.
///
/// \return The textual representation of the invalid path.
const std::string&
fs::invalid_path_error::invalid_path(void) const
{
    return _textual_path;
}


/// Constructs a new error based on an errno code.
///
/// \param message_ The message describing what caused the error.
/// \param errno_ The error code.
fs::system_error::system_error(const std::string& message_, const int errno_) :
    error(F("%s: %s") % message_ % strerror(errno_)),
    _original_errno(errno_)
{
}


/// Destructor for the error.
fs::system_error::~system_error(void) throw()
{
}



/// Gets the original errno code.
int
fs::system_error::original_errno(void) const throw()
{
    return _original_errno;
}

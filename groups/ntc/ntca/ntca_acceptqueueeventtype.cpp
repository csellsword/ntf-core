// Copyright 2020-2023 Bloomberg Finance L.P.
// SPDX-License-Identifier: Apache-2.0
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

#include <ntca_acceptqueueeventtype.h>

#include <bsls_ident.h>
BSLS_IDENT_RCSID(ntca_acceptqueueeventtype_cpp, "$Id$ $CSID$")

#include <bdlb_string.h>
#include <bsls_assert.h>
#include <bsl_ostream.h>

namespace BloombergLP {
namespace ntca {

int AcceptQueueEventType::fromInt(AcceptQueueEventType::Value* result,
                                  int                          number)
{
    switch (number) {
    case AcceptQueueEventType::e_FLOW_CONTROL_RELAXED:
    case AcceptQueueEventType::e_FLOW_CONTROL_APPLIED:
    case AcceptQueueEventType::e_LOW_WATERMARK:
    case AcceptQueueEventType::e_HIGH_WATERMARK:
    case AcceptQueueEventType::e_DISCARDED:
        *result = static_cast<AcceptQueueEventType::Value>(number);
        return 0;
    default:
        return -1;
    }
}

int AcceptQueueEventType::fromString(AcceptQueueEventType::Value* result,
                                     const bslstl::StringRef&     string)
{
    if (bdlb::String::areEqualCaseless(string, "FLOW_CONTROL_RELAXED")) {
        *result = e_FLOW_CONTROL_RELAXED;
        return 0;
    }
    if (bdlb::String::areEqualCaseless(string, "FLOW_CONTROL_APPLIED")) {
        *result = e_FLOW_CONTROL_APPLIED;
        return 0;
    }
    if (bdlb::String::areEqualCaseless(string, "LOW_WATERMARK")) {
        *result = e_LOW_WATERMARK;
        return 0;
    }
    if (bdlb::String::areEqualCaseless(string, "HIGH_WATERMARK")) {
        *result = e_HIGH_WATERMARK;
        return 0;
    }
    if (bdlb::String::areEqualCaseless(string, "DISCARDED")) {
        *result = e_DISCARDED;
        return 0;
    }

    return -1;
}

const char* AcceptQueueEventType::toString(AcceptQueueEventType::Value value)
{
    switch (value) {
    case e_FLOW_CONTROL_RELAXED: {
        return "FLOW_CONTROL_RELAXED";
    } break;
    case e_FLOW_CONTROL_APPLIED: {
        return "FLOW_CONTROL_APPLIED";
    } break;
    case e_LOW_WATERMARK: {
        return "LOW_WATERMARK";
    } break;
    case e_HIGH_WATERMARK: {
        return "HIGH_WATERMARK";
    } break;
    case e_DISCARDED: {
        return "DISCARDED";
    } break;
    }

    BSLS_ASSERT(!"invalid enumerator");
    return 0;
}

bsl::ostream& AcceptQueueEventType::print(bsl::ostream&               stream,
                                          AcceptQueueEventType::Value value)
{
    return stream << toString(value);
}

bsl::ostream& operator<<(bsl::ostream& stream, AcceptQueueEventType::Value rhs)
{
    return AcceptQueueEventType::print(stream, rhs);
}

}  // close package namespace
}  // close enterprise namespace

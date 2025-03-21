/*
 * Copyright (c) 2015 Igalia
 * Copyright (c) 2015 Igalia S.L.
 * Copyright (c) 2015 Igalia.
 * Copyright (c) 2015, 2016 Canon Inc. All rights reserved.
 * Copyright (c) 2015, 2016, 2017 Canon Inc.
 * Copyright (c) 2016, 2020 Apple Inc. All rights reserved.
 * Copyright (c) 2022 Codeblog Corp. All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

// DO NOT EDIT THIS FILE. It is automatically generated from JavaScript files for
// builtins by the script: Source/JavaScriptCore/Scripts/generate-js-builtins.py

#include "config.h"
#include "ConsoleObjectBuiltins.h"

#include "WebCoreJSClientData.h"
#include <JavaScriptCore/HeapInlines.h>
#include <JavaScriptCore/IdentifierInlines.h>
#include <JavaScriptCore/ImplementationVisibility.h>
#include <JavaScriptCore/Intrinsic.h>
#include <JavaScriptCore/JSCJSValueInlines.h>
#include <JavaScriptCore/JSCellInlines.h>
#include <JavaScriptCore/StructureInlines.h>
#include <JavaScriptCore/VM.h>

namespace WebCore {

const JSC::ConstructAbility s_consoleObjectAsyncIteratorCodeConstructAbility = JSC::ConstructAbility::CannotConstruct;
const JSC::ConstructorKind s_consoleObjectAsyncIteratorCodeConstructorKind = JSC::ConstructorKind::None;
const JSC::ImplementationVisibility s_consoleObjectAsyncIteratorCodeImplementationVisibility = JSC::ImplementationVisibility::Public;
const int s_consoleObjectAsyncIteratorCodeLength = 2004;
static const JSC::Intrinsic s_consoleObjectAsyncIteratorCodeIntrinsic = JSC::NoIntrinsic;
const char* const s_consoleObjectAsyncIteratorCode =
    "(function () {\n" \
    "    \"use strict\";\n" \
    "\n" \
    "    const Iterator = async function* ConsoleAsyncIterator() {\n" \
    "        \"use strict\";\n" \
    "\n" \
    "        const stream = @Bun.stdin.stream();\n" \
    "        var reader = stream.getReader();\n" \
    "\n" \
    "         //\n" \
    "        var decoder = new globalThis.TextDecoder(\"utf-8\", { fatal: false });\n" \
    "        var deferredError;\n" \
    "        var indexOf = @Bun.indexOfLine;\n" \
    "\n" \
    "        try {\n" \
    "            while (true) {\n" \
    "                var done, value;\n" \
    "                var pendingChunk;\n" \
    "                const firstResult = reader.readMany();\n" \
    "                if (@isPromise(firstResult)) {\n" \
    "                    ({done, value} = await firstResult);\n" \
    "                } else {\n" \
    "                    ({done, value} = firstResult);\n" \
    "                }\n" \
    "\n" \
    "                if (done) {\n" \
    "                    if (pendingChunk) {\n" \
    "                        yield decoder.decode(pendingChunk);\n" \
    "                    }\n" \
    "                    return;\n" \
    "                }\n" \
    "                \n" \
    "                var actualChunk;\n" \
    "                //\n" \
    "                for (const chunk of value) {\n" \
    "                    actualChunk = chunk;\n" \
    "                    if (pendingChunk) {\n" \
    "                        actualChunk = Buffer.concat([pendingChunk, chunk]);\n" \
    "                        pendingChunk = null;\n" \
    "                    }\n" \
    "\n" \
    "                    var last = 0;\n" \
    "                    //\n" \
    "                    var i = indexOf(actualChunk, last);\n" \
    "                    while (i !== -1) {\n" \
    "                        yield decoder.decode(actualChunk.subarray(last, i));\n" \
    "                        last = i + 1;\n" \
    "                        i = indexOf(actualChunk, last);\n" \
    "                    }\n" \
    "\n" \
    "                    pendingChunk = actualChunk.subarray(last);\n" \
    "                }\n" \
    "            }\n" \
    "        } catch(e) {\n" \
    "          deferredError = e;\n" \
    "        } finally {\n" \
    "          reader.releaseLock();\n" \
    "\n" \
    "          if (deferredError) {\n" \
    "            throw deferredError;\n" \
    "          }\n" \
    "        }\n" \
    "    };\n" \
    "\n" \
    "    const symbol = globalThis.Symbol.asyncIterator;\n" \
    "    this[symbol] = Iterator;\n" \
    "    return Iterator();\n" \
    "})\n" \
;

const JSC::ConstructAbility s_consoleObjectWriteCodeConstructAbility = JSC::ConstructAbility::CannotConstruct;
const JSC::ConstructorKind s_consoleObjectWriteCodeConstructorKind = JSC::ConstructorKind::None;
const JSC::ImplementationVisibility s_consoleObjectWriteCodeImplementationVisibility = JSC::ImplementationVisibility::Public;
const int s_consoleObjectWriteCodeLength = 524;
static const JSC::Intrinsic s_consoleObjectWriteCodeIntrinsic = JSC::NoIntrinsic;
const char* const s_consoleObjectWriteCode =
    "(function (input) {\n" \
    "    \"use strict\";\n" \
    "\n" \
    "    var writer = @getByIdDirectPrivate(this, \"writer\");\n" \
    "    if (!writer) {\n" \
    "        var length = @toLength(input?.length ?? 0);\n" \
    "        writer = @Bun.stdout.writer({highWaterMark: length > 65536 ? length : 65536});\n" \
    "        @putByIdDirectPrivate(this, \"writer\", writer);\n" \
    "    }\n" \
    "\n" \
    "    var wrote = writer.write(input);\n" \
    "\n" \
    "    const count = @argumentCount();\n" \
    "    for (var i = 1; i < count; i++) {\n" \
    "        wrote += writer.write(@argument(i));\n" \
    "    }\n" \
    "\n" \
    "    writer.flush(true);\n" \
    "    return wrote;\n" \
    "})\n" \
;


#define DEFINE_BUILTIN_GENERATOR(codeName, functionName, overriddenName, argumentCount) \
JSC::FunctionExecutable* codeName##Generator(JSC::VM& vm) \
{\
    JSVMClientData* clientData = static_cast<JSVMClientData*>(vm.clientData); \
    return clientData->builtinFunctions().consoleObjectBuiltins().codeName##Executable()->link(vm, nullptr, clientData->builtinFunctions().consoleObjectBuiltins().codeName##Source(), std::nullopt, s_##codeName##Intrinsic); \
}
WEBCORE_FOREACH_CONSOLEOBJECT_BUILTIN_CODE(DEFINE_BUILTIN_GENERATOR)
#undef DEFINE_BUILTIN_GENERATOR


} // namespace WebCore

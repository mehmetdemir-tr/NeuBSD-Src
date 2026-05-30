import fs from 'node:fs';
var headers = [
  {
    "name": "assert.h",
    "description": "Conditionally compiled macro that compares its argument to zero"
  },
  {
    "name": "complex.h",
    "description": "Complex number arithmetic"
  },
  {
    "name": "ctype.h",
    "description": "Functions to determine the type contained in character data"
  },
  {
    "name": "errno.h",
    "description": "Macros reporting error conditions"
  },
  {
    "name": "fenv.h",
    "description": "Floating-point environment"
  },
  {
    "name": "float.h",
    "description": "Limits of floating-point types"
  },
  {
    "name": "inttypes.h",
    "description": "Format conversion of integer types"
  },
  {
    "name": "iso646.h",
    "description": "Alternative operator spellings"
  },
  {
    "name": "limits.h",
    "description": "Ranges of integer types"
  },
  {
    "name": "locale.h",
    "description": "Localization utilities"
  },
  {
    "name": "math.h",
    "description": "Common mathematics functions"
  },
  {
    "name": "setjmp.h",
    "description": "Nonlocal jumps"
  },
  {
    "name": "signal.h",
    "description": "Signal handling"
  },
  {
    "name": "stdalign.h",
    "description": "alignas and alignof convenience macros"
  },
  {
    "name": "stdarg.h",
    "description": "Variable arguments"
  },
  {
    "name": "stdatomic.h",
    "description": "Atomic operations"
  },
  {
    "name": "stdbool.h",
    "description": "Macros for boolean type"
  },
  {
    "name": "stddef.h",
    "description": "Common macro definitions"
  },
  {
    "name": "stdint.h",
    "description": "Fixed-width integer types"
  },
  {
    "name": "stdio.h",
    "description": "Input/output"
  },
  {
    "name": "stdlib.h",
    "description": "General utilities: memory management, program utilities, string conversions, random numbers, algorithms"
  },
  {
    "name": "stdnoreturn.h",
    "description": "noreturn convenience macro"
  },
  {
    "name": "string.h",
    "description": "String handling"
  },
  {
    "name": "tgmath.h",
    "description": "Type-generic math (macros wrapping math.h and complex.h)"
  },
  {
    "name": "threads.h",
    "description": "Thread library"
  },
  {
    "name": "time.h",
    "description": "Time/date utilities"
  },
  {
    "name": "uchar.h",
    "description": "UTF-16 and UTF-32 character utilities"
  },
  {
    "name": "wchar.h",
    "description": "Extended multibyte and wide character utilities"
  },
  {
    "name": "wctype.h",
    "description": "Functions to determine the type contained in wide character data"
  }
]
var impl = [];
var notimpl = [];
headers.forEach(element => {
  if (fs.existsSync(`src/libc/include/${element["name"]}`)) {
    impl.push(element);
  } else {
    notimpl.push(element);
  }
});
console.log('\x1b[97;1m%s\x1b[0m', "Implemented Headers");
impl.forEach(element => {
  console.log('\t\x1b[96;1m%s\x1b[0m - \x1b[97;1m%s\x1b[0m', element["name"], element["description"]);
});
console.log('\x1b[97;1m%s\x1b[0m', "Unimplemented Headers");
notimpl.forEach(element => {
  console.log('\t\x1b[91;1m%s\x1b[0m - \x1b[97;1m%s\x1b[0m', element["name"], element["description"]);
});
console.log(`${Math.round(impl.length/headers.length*100)}% complete.`);
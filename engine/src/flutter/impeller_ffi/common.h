#ifndef FLUTTER_IMPELLER_FFI_COMMON_H_
#define FLUTTER_IMPELLER_FFI_COMMON_H_

#ifdef _WIN32
#define IMPELLER_FFI_EXPORT __declspec(dllexport)
#else
#define IMPELLER_FFI_EXPORT __attribute__((visibility("default")))
#endif

#ifdef __clang__
#define IMPELLER_FFI_NULLABLE _Nullable
#define IMPELLER_FFI_NONNULL _Nonnull
#else  // __clang__
#define IMPELLER_FFI_NULLABLE
#define IMPELLER_FFI_NONNULL
#endif  // __clang__

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#endif  // FLUTTER_IMPELLER_FFI_COMMON_H_

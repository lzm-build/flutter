#ifndef FLUTTER_IMPELLER_FFI_RENDERER_CONTEXT_H_
#define FLUTTER_IMPELLER_FFI_RENDERER_CONTEXT_H_

#include "impeller_ffi/common.h"
#include "impeller_ffi/renderer/capabilities.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  void* IMPELLER_FFI_NULLABLE ptr1;
  void* IMPELLER_FFI_NULLABLE ptr2;
} impeller_ContextSharedMut;

typedef struct {
  const void* IMPELLER_FFI_NULLABLE ptr1;
  void* IMPELLER_FFI_NULLABLE ptr2;
} impeller_ContextSharedConst;

typedef struct {
  void* IMPELLER_FFI_NULLABLE ptr1;
  void* IMPELLER_FFI_NULLABLE ptr2;
} impeller_ContextWeakMut;

typedef struct {
  const void* IMPELLER_FFI_NULLABLE ptr1;
  void* IMPELLER_FFI_NULLABLE ptr2;
} impeller_ContextWeakConst;

typedef void* IMPELLER_FFI_NONNULL impeller_ContextMut;

typedef const void* IMPELLER_FFI_NONNULL impeller_ContextConst;

IMPELLER_FFI_EXPORT void impeller_ContextSharedConst_from_ContextSharedMut(
    impeller_ContextSharedConst* IMPELLER_FFI_NONNULL out,
    impeller_ContextSharedMut* IMPELLER_FFI_NONNULL self);

IMPELLER_FFI_EXPORT void impeller_ContextSharedMut_clone(
    impeller_ContextSharedMut* IMPELLER_FFI_NONNULL out,
    impeller_ContextSharedMut* IMPELLER_FFI_NONNULL self);

IMPELLER_FFI_EXPORT void impeller_ContextSharedConst_clone(
    impeller_ContextSharedConst* IMPELLER_FFI_NONNULL out,
    impeller_ContextSharedConst* IMPELLER_FFI_NONNULL self);

IMPELLER_FFI_EXPORT void impeller_ContextSharedMut_drop(
    impeller_ContextSharedMut* IMPELLER_FFI_NONNULL self);

IMPELLER_FFI_EXPORT void impeller_ContextSharedConst_drop(
    impeller_ContextSharedConst* IMPELLER_FFI_NONNULL self);

IMPELLER_FFI_EXPORT void impeller_ContextSharedMut_downgrade(
    impeller_ContextWeakMut* IMPELLER_FFI_NONNULL out,
    impeller_ContextSharedMut* IMPELLER_FFI_NONNULL self);

IMPELLER_FFI_EXPORT void impeller_ContextSharedMut_upgrade(
    impeller_ContextSharedMut* IMPELLER_FFI_NONNULL out,
    impeller_ContextWeakMut* IMPELLER_FFI_NONNULL self);

IMPELLER_FFI_EXPORT int impeller_ContextConst_get_backend_type(
    impeller_ContextConst IMPELLER_FFI_NONNULL self);

IMPELLER_FFI_EXPORT const impeller_CapabilitiesSharedConst*
impeller_ContextConst_get_capabilities(
    impeller_ContextConst IMPELLER_FFI_NONNULL self);

#ifdef __cplusplus
}
#endif

#endif  // FLUTTER_IMPELLER_FFI_RENDERER_CONTEXT_H_

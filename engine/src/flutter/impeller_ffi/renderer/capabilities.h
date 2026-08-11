#ifndef FLUTTER_IMPELLER_FFI_RENDERER_CAPABILITIES_H_
#define FLUTTER_IMPELLER_FFI_RENDERER_CAPABILITIES_H_

#include "impeller_ffi/common.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  void* IMPELLER_FFI_NULLABLE ptr1;
  void* IMPELLER_FFI_NULLABLE ptr2;
} impeller_CapabilitiesSharedConst;

typedef void* IMPELLER_FFI_NONNULL impeller_CapabilitiesConst;

IMPELLER_FFI_EXPORT void impeller_CapabilitiesSharedConst_clone(
    impeller_CapabilitiesSharedConst* IMPELLER_FFI_NONNULL out,
    impeller_CapabilitiesSharedConst* IMPELLER_FFI_NONNULL self);

IMPELLER_FFI_EXPORT void impeller_CapabilitiesSharedConst_drop(
    impeller_CapabilitiesSharedConst* IMPELLER_FFI_NONNULL self);

IMPELLER_FFI_EXPORT IMPELLER_FFI_EXPORT bool
impeller_CapabilitiesConst_supports_offscreen_msaa(
    impeller_CapabilitiesConst IMPELLER_FFI_NONNULL self);

IMPELLER_FFI_EXPORT bool
impeller_CapabilitiesConst_supports_implicit_resolving_mass(
    impeller_CapabilitiesConst IMPELLER_FFI_NONNULL self);

IMPELLER_FFI_EXPORT bool impeller_CapabilitiesConst_supports_ssbo(
    impeller_CapabilitiesConst IMPELLER_FFI_NONNULL self);

IMPELLER_FFI_EXPORT bool impeller_CapabilitiesConst_supports_framebuffer_fetch(
    impeller_CapabilitiesConst IMPELLER_FFI_NONNULL self);

IMPELLER_FFI_EXPORT bool impeller_CapabilitiesConst_supports_compute(
    impeller_CapabilitiesConst IMPELLER_FFI_NONNULL self);

#ifdef __cplusplus
}
#endif

#endif  // FLUTTER_IMPELLER_FFI_RENDERER_CAPABILITIES_H_

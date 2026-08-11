#include <memory>

#include "impeller/renderer/capabilities.h"
#include "impeller_ffi/renderer/capabilities.h"

IMPELLER_FFI_EXPORT void impeller_CapabilitiesSharedConst_clone(
    impeller_CapabilitiesSharedConst* IMPELLER_FFI_NONNULL out,
    impeller_CapabilitiesSharedConst* IMPELLER_FFI_NONNULL self) {
  new (out) std::shared_ptr<const impeller::Capabilities>(
      *reinterpret_cast<std::shared_ptr<const impeller::Capabilities>*>(self));
}

IMPELLER_FFI_EXPORT void impeller_CapabilitiesSharedConst_drop(
    impeller_CapabilitiesSharedConst* IMPELLER_FFI_NONNULL self) {
  reinterpret_cast<std::shared_ptr<const impeller::Capabilities>*>(self)
      ->reset();
}

bool impeller_CapabilitiesConst_supports_offscreen_msaa(
    impeller_CapabilitiesConst self) {
  return reinterpret_cast<const impeller::Capabilities*>(self)
      ->SupportsOffscreenMSAA();
}

bool impeller_CapabilitiesConst_supports_implicit_resolving_mass(
    impeller_CapabilitiesConst IMPELLER_FFI_NONNULL self) {
  return reinterpret_cast<const impeller::Capabilities*>(self)
      ->SupportsImplicitResolvingMSAA();
}

bool impeller_CapabilitiesConst_supports_ssbo(
    impeller_CapabilitiesConst IMPELLER_FFI_NONNULL self) {
  return reinterpret_cast<const impeller::Capabilities*>(self)->SupportsSSBO();
}

bool impeller_CapabilitiesConst_supports_framebuffer_fetch(
    impeller_CapabilitiesConst IMPELLER_FFI_NONNULL self) {
  return reinterpret_cast<const impeller::Capabilities*>(self)
      ->SupportsFramebufferFetch();
}

bool impeller_CapabilitiesConst_supports_compute(
    impeller_CapabilitiesConst IMPELLER_FFI_NONNULL self) {
  return reinterpret_cast<const impeller::Capabilities*>(self)
      ->SupportsCompute();
}

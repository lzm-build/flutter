#include <memory>

#include "impeller/renderer/context.h"
#include "impeller_ffi/renderer/context.h"

void impeller_ContextSharedConst_from_ContextSharedMut(
    impeller_ContextSharedConst* out,
    impeller_ContextSharedMut* self) {
  new (out) std::shared_ptr<const impeller::Context>(
      *reinterpret_cast<std::shared_ptr<impeller::Context>*>(self));
}

void impeller_ContextSharedMut_clone(impeller_ContextSharedMut* out,
                                     impeller_ContextSharedMut* self) {
  new (out) std::shared_ptr<impeller::Context>(
      *reinterpret_cast<std::shared_ptr<impeller::Context>*>(self));
}

void impeller_ContextSharedConst_clone(impeller_ContextSharedConst* out,
                                       impeller_ContextSharedConst* self) {
  new (out) std::shared_ptr<const impeller::Context>(
      *reinterpret_cast<std::shared_ptr<const impeller::Context>*>(self));
}

void impeller_ContextSharedMut_drop(impeller_ContextSharedMut* self) {
  reinterpret_cast<std::shared_ptr<impeller::Context>*>(self)->reset();
}

void impeller_ContextSharedConst_drop(impeller_ContextSharedConst* self) {
  reinterpret_cast<std::shared_ptr<const impeller::Context>*>(self)->reset();
}

void impeller_ContextSharedMut_downgrade(impeller_ContextWeakMut* out,
                                         impeller_ContextSharedMut* self) {
  new (out) std::weak_ptr<impeller::Context>(
      *reinterpret_cast<std::shared_ptr<impeller::Context>*>(self));
}

void impeller_ContextSharedMut_upgrade(impeller_ContextSharedMut* out,
                                       impeller_ContextWeakMut* self) {
  new (out) std::shared_ptr<impeller::Context>(
      reinterpret_cast<std::weak_ptr<impeller::Context>*>(self)->lock());
}

int impeller_ContextConst_get_backend_type(impeller_ContextConst self) {
  return static_cast<int>(
      reinterpret_cast<const impeller::Context*>(self)->GetBackendType());
}
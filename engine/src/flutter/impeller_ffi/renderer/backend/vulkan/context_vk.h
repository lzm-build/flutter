#ifndef FLUTTER_IMPELLER_FFI_RENDERER_BACKEND_VULKAN_CONTEXT_VK_H_
#define FLUTTER_IMPELLER_FFI_RENDERER_BACKEND_VULKAN_CONTEXT_VK_H_

#include "impeller_ffi/common.h"
#include "vulkan/vulkan_core.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  void* IMPELLER_FFI_NULLABLE ptr1;
  void* IMPELLER_FFI_NULLABLE ptr2;
} impeller_vulkan_ContextSharedMut;

typedef struct {
  const void* IMPELLER_FFI_NULLABLE ptr1;
  void* IMPELLER_FFI_NULLABLE ptr2;
} impeller_vulkan_ContextSharedConst;

typedef struct {
  void* IMPELLER_FFI_NULLABLE ptr1;
  void* IMPELLER_FFI_NULLABLE ptr2;
} impeller_vulkan_ContextWeakMut;

typedef struct {
  const void* IMPELLER_FFI_NULLABLE ptr1;
  void* IMPELLER_FFI_NULLABLE ptr2;
} impeller_vulkan_ContextWeakConst;

typedef void* IMPELLER_FFI_NONNULL impeller_vulkan_ContextMut;

typedef const void* IMPELLER_FFI_NONNULL impeller_vulkan_ContextConst;

IMPELLER_FFI_EXPORT void
impeller_vulkan_ContextSharedConst_from_ContextSharedMut(
    impeller_vulkan_ContextSharedConst* IMPELLER_FFI_NONNULL out,
    impeller_vulkan_ContextSharedMut* IMPELLER_FFI_NONNULL self);

IMPELLER_FFI_EXPORT void impeller_vulkan_ContextSharedMut_clone(
    impeller_vulkan_ContextSharedMut* IMPELLER_FFI_NONNULL out,
    impeller_vulkan_ContextSharedMut* IMPELLER_FFI_NONNULL self);

IMPELLER_FFI_EXPORT void impeller_vulkan_ContextSharedConst_clone(
    impeller_vulkan_ContextSharedConst* IMPELLER_FFI_NONNULL out,
    impeller_vulkan_ContextSharedConst* IMPELLER_FFI_NONNULL self);

IMPELLER_FFI_EXPORT void impeller_vulkan_ContextSharedMut_drop(
    impeller_vulkan_ContextSharedMut* IMPELLER_FFI_NONNULL self);

IMPELLER_FFI_EXPORT void impeller_vulkan_ContextSharedConst_drop(
    impeller_vulkan_ContextSharedConst* IMPELLER_FFI_NONNULL self);

IMPELLER_FFI_EXPORT void impeller_vulkan_ContextSharedMut_downgrade(
    impeller_vulkan_ContextWeakMut* IMPELLER_FFI_NONNULL out,
    impeller_vulkan_ContextSharedMut* IMPELLER_FFI_NONNULL self);

IMPELLER_FFI_EXPORT void impeller_vulkan_ContextSharedMut_upgrade(
    impeller_vulkan_ContextSharedMut* IMPELLER_FFI_NONNULL out,
    impeller_vulkan_ContextWeakMut* IMPELLER_FFI_NONNULL self);

IMPELLER_FFI_EXPORT void impeller_vulkan_Context_create(
    impeller_vulkan_ContextSharedMut* IMPELLER_FFI_NONNULL out,
    PFN_vkGetInstanceProcAddr IMPELLER_FFI_NONNULL proc_address_callback,
    const uint8_t** IMPELLER_FFI_NULLABLE shader_libraries_item_data_ptr,
    size_t* IMPELLER_FFI_NULLABLE shader_libraries_item_len_ptr,
    size_t shader_libraries_item_count,
    bool enable_validation,
    bool enable_gpu_tracing,
    bool enable_surface_control,
    bool fatal_missing_validations,
    bool use_sdfs,
    VkInstance IMPELLER_FFI_NULLABLE instance,
    VkPhysicalDevice IMPELLER_FFI_NULLABLE physical_device,
    VkDevice IMPELLER_FFI_NULLABLE device,
    uint32_t queue_family_index,
    VkQueue queue,
    const char** IMPELLER_FFI_NULLABLE instance_extensions_item_data_ptr,
    size_t* IMPELLER_FFI_NULLABLE instance_extensions_item_len_ptr,
    size_t instance_extensions_item_count,
    const char** IMPELLER_FFI_NULLABLE device_extensions_item_data_ptr,
    size_t* IMPELLER_FFI_NULLABLE device_extensions_item_len_ptr,
    size_t device_extensions_item_count);

#ifdef __cplusplus
}
#endif

#endif  // FLUTTER_IMPELLER_FFI_RENDERER_BACKEND_VULKAN_CONTEXT_VK_H_

#include <cstddef>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "fml/mapping.h"
#include "fml/paths.h"
#include "impeller/base/flags.h"
#include "impeller/renderer/backend/vulkan/context_vk.h"
#include "impeller_ffi/renderer/backend/vulkan/context_vk.h"

void impeller_vulkan_ContextSharedConst_from_ContextSharedMut(
    impeller_vulkan_ContextSharedConst* out,
    impeller_vulkan_ContextSharedMut* self) {
  new (out) std::shared_ptr<const impeller::ContextVK>(
      *reinterpret_cast<std::shared_ptr<impeller::ContextVK>*>(self));
}

void impeller_vulkan_ContextSharedMut_clone(
    impeller_vulkan_ContextSharedMut* out,
    impeller_vulkan_ContextSharedMut* self) {
  new (out) std::shared_ptr<impeller::ContextVK>(
      *reinterpret_cast<std::shared_ptr<impeller::ContextVK>*>(self));
}

void impeller_vulkan_ContextSharedConst_clone(
    impeller_vulkan_ContextSharedConst* out,
    impeller_vulkan_ContextSharedConst* self) {
  new (out) std::shared_ptr<const impeller::ContextVK>(
      *reinterpret_cast<std::shared_ptr<const impeller::ContextVK>*>(self));
}

void impeller_vulkan_ContextSharedMut_drop(
    impeller_vulkan_ContextSharedMut* self) {
  reinterpret_cast<std::shared_ptr<impeller::ContextVK>*>(self)->reset();
}

void impeller_vulkan_ContextSharedConst_drop(
    impeller_vulkan_ContextSharedConst* self) {
  reinterpret_cast<std::shared_ptr<const impeller::ContextVK>*>(self)->reset();
}

void impeller_vulkan_ContextSharedMut_downgrade(
    impeller_vulkan_ContextWeakMut* out,
    impeller_vulkan_ContextSharedMut* self) {
  new (out) std::weak_ptr<impeller::ContextVK>(
      *reinterpret_cast<std::shared_ptr<impeller::ContextVK>*>(self));
}

void impeller_vulkan_ContextSharedMut_upgrade(
    impeller_vulkan_ContextSharedMut* out,
    impeller_vulkan_ContextWeakMut* self) {
  new (out) std::shared_ptr<impeller::ContextVK>(
      reinterpret_cast<std::weak_ptr<impeller::ContextVK>*>(self)->lock());
}

void impeller_vulkan_Context_create(
    impeller_vulkan_ContextSharedMut* out,
    PFN_vkGetInstanceProcAddr proc_address_callback,
    const uint8_t** shader_libraries_item_data_ptr,
    size_t* shader_libraries_item_len_ptr,
    size_t shader_libraries_item_count,
    bool enable_validation,
    bool enable_gpu_tracing,
    bool enable_surface_control,
    bool fatal_missing_validations,
    bool use_sdfs,
    VkInstance instance,
    VkPhysicalDevice physical_device,
    VkDevice device,
    uint32_t queue_family_index,
    VkQueue queue,
    const char** instance_extensions_item_data_ptr,
    size_t* instance_extensions_item_len_ptr,
    size_t instance_extensions_item_count,
    const char** device_extensions_item_data_ptr,
    size_t* device_extensions_item_len_ptr,
    size_t device_extensions_item_count) {
  impeller::ContextVK::Settings settings;
  settings.proc_address_callback = proc_address_callback;

  // shader_libraries_data

  std::vector<std::shared_ptr<fml::Mapping>> shader_libraries_data;
  shader_libraries_data.reserve(shader_libraries_item_count);
  for (size_t i = 0; i < shader_libraries_item_count; ++i) {
    shader_libraries_data.emplace_back(std::make_shared<fml::NonOwnedMapping>(
        *(shader_libraries_item_data_ptr + i),
        *(shader_libraries_item_len_ptr + i)));
  }
  settings.shader_libraries_data = std::move(shader_libraries_data);

  // cache_directory
  settings.cache_directory = fml::paths::GetCachesDirectory();

  settings.enable_validation = enable_validation;
  settings.enable_gpu_tracing = enable_gpu_tracing;
  settings.enable_surface_control = enable_surface_control;
  settings.fatal_missing_validations = fatal_missing_validations;

  impeller::Flags flags;
  flags.use_sdfs = use_sdfs;
  settings.flags = flags;

  if (instance != NULL) {
    impeller::ContextVK::EmbedderData embedder_data;
    embedder_data.instance = instance;
    embedder_data.physical_device = physical_device;
    embedder_data.device = device;
    embedder_data.queue_family_index = queue_family_index;
    embedder_data.queue = queue;
    // instance_extensions

    std::vector<std::string> instance_extensions;
    instance_extensions.reserve(instance_extensions_item_count);
    for (size_t i = 0; i < instance_extensions_item_count; ++i) {
      instance_extensions.emplace_back(
          std::string(*(instance_extensions_item_data_ptr + i),
                      *(instance_extensions_item_len_ptr + i)));
    }
    embedder_data.instance_extensions = instance_extensions;

    // device_extensions

    std::vector<std::string> device_extensions;
    device_extensions.reserve(device_extensions_item_count);
    for (size_t i = 0; i < device_extensions_item_count; ++i) {
      device_extensions.emplace_back(
          std::string(*(device_extensions_item_data_ptr + i),
                      *(device_extensions_item_len_ptr + i)));
    }
    embedder_data.device_extensions = device_extensions;
  }

  auto context_vk = impeller::ContextVK::Create(std::move(settings));
  new (out) std::shared_ptr<impeller::ContextVK>(std::move(context_vk));
}

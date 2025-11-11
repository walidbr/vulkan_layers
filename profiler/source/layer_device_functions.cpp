/*
 * SPDX-License-Identifier: MIT
 * ----------------------------------------------------------------------------
 * Copyright (c) 2024 Arm Limited
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 * ----------------------------------------------------------------------------
 */

#include "device.hpp"
#include "framework/device_dispatch_table.hpp"

#include <memory>
#include <mutex>
#include <thread>
#undef CONFIG_TRACE
#define CONFIG_TRACE 1
extern std::mutex g_vulkanLock;

/* See Vulkan API for documentation. */
template<>
VKAPI_ATTR void VKAPI_CALL layer_vkCmdBeginRenderPass<user_tag>(VkCommandBuffer commandBuffer,
                                                                const VkRenderPassBeginInfo* pRenderPassBegin,
                                                                VkSubpassContents contents)
{
#if CONFIG_TRACE == 1
    LAYER_LOG("API Trace: Layer: %s ", __func__);
#endif

    // Hold the lock to access layer-wide global store
    std::unique_lock<std::mutex> lock {g_vulkanLock};
    auto* layer = Device::retrieve(commandBuffer);

    // Release the lock to call into the driver
    lock.unlock();
    layer->driver.vkCmdBeginRenderPass(commandBuffer, pRenderPassBegin, contents);
}

/* See Vulkan API for documentation. */
template<>
VKAPI_ATTR void VKAPI_CALL layer_vkCmdBeginRenderPass2<user_tag>(VkCommandBuffer commandBuffer,
                                                                 const VkRenderPassBeginInfo* pRenderPassBegin,
                                                                 const VkSubpassBeginInfo* pSubpassBeginInfo)
{
#if CONFIG_TRACE == 1
    LAYER_LOG("API Trace: Layer: %s ", __func__);
#endif

    // Hold the lock to access layer-wide global store
    std::unique_lock<std::mutex> lock {g_vulkanLock};
    auto* layer = Device::retrieve(commandBuffer);

    // Release the lock to call into the driver
    lock.unlock();
    layer->driver.vkCmdBeginRenderPass2(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
}

/* See Vulkan API for documentation. */
template<>
VKAPI_ATTR void VKAPI_CALL layer_vkCmdBeginRenderPass2KHR<user_tag>(VkCommandBuffer commandBuffer,
                                                                    const VkRenderPassBeginInfo* pRenderPassBegin,
                                                                    const VkSubpassBeginInfo* pSubpassBeginInfo)
{
#if CONFIG_TRACE == 1
    LAYER_LOG("API Trace: Layer: %s ", __func__);
#endif

    // Hold the lock to access layer-wide global store
    std::unique_lock<std::mutex> lock {g_vulkanLock};
    auto* layer = Device::retrieve(commandBuffer);

    // Release the lock to call into the driver
    lock.unlock();
    layer->driver.vkCmdBeginRenderPass2KHR(commandBuffer, pRenderPassBegin, pSubpassBeginInfo);
}

/* See Vulkan API for documentation. */
template<>
VKAPI_ATTR void VKAPI_CALL layer_vkCmdBeginRendering<user_tag>(VkCommandBuffer commandBuffer,
                                                               const VkRenderingInfo* pRenderingInfo)
{
#if CONFIG_TRACE == 1
    LAYER_LOG("API Trace: Layer: %s ", __func__);
#endif

    // Hold the lock to access layer-wide global store
    std::unique_lock<std::mutex> lock {g_vulkanLock};
    auto* layer = Device::retrieve(commandBuffer);

    // Release the lock to call into the driver
    lock.unlock();
    layer->driver.vkCmdBeginRendering(commandBuffer, pRenderingInfo);
}

/* See Vulkan API for documentation. */
template<>
VKAPI_ATTR void VKAPI_CALL layer_vkCmdBeginRenderingKHR<user_tag>(VkCommandBuffer commandBuffer,
                                                                  const VkRenderingInfo* pRenderingInfo)
{
#if CONFIG_TRACE == 1
    LAYER_LOG("API Trace: Layer: %s ", __func__);
#endif

    // Hold the lock to access layer-wide global store
    std::unique_lock<std::mutex> lock {g_vulkanLock};
    auto* layer = Device::retrieve(commandBuffer);

    // Release the lock to call into the driver
    lock.unlock();
    layer->driver.vkCmdBeginRenderingKHR(commandBuffer, pRenderingInfo);
}

/* See Vulkan API for documentation. */
template<>
VKAPI_ATTR VkResult VKAPI_CALL
    layer_vkQueueSubmit<user_tag>(VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence)
{
#if CONFIG_TRACE == 1
    LAYER_LOG("API Trace: Layer (dispatch): %s ", __func__);
#endif

    // Hold the lock to access layer-wide global store
    std::unique_lock<std::mutex> lock {g_vulkanLock};
    auto* layer = Device::retrieve(queue);

    // Release the lock to call into the driver
    lock.unlock();
    auto res = layer->driver.vkQueueSubmit(queue, submitCount, pSubmits, fence);

    return res;
}

/* See Vulkan API for documentation. */
template<>
VKAPI_ATTR VkResult VKAPI_CALL
    layer_vkQueueSubmit2<user_tag>(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence)
{
#if CONFIG_TRACE == 1
    LAYER_LOG("API Trace: Layer (dispatch2): %s ", __func__);
#endif

    // Hold the lock to access layer-wide global store
    std::unique_lock<std::mutex> lock {g_vulkanLock};
    auto* layer = Device::retrieve(queue);

    // Release the lock to call into the driver
    lock.unlock();
    auto res = layer->driver.vkQueueSubmit2(queue, submitCount, pSubmits, fence);

    return res;
}

/* See Vulkan API for documentation. */
template<>
VKAPI_ATTR VkResult VKAPI_CALL
    layer_vkQueueSubmit2KHR<user_tag>(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence)
{
#if CONFIG_TRACE == 1
    LAYER_LOG("API Trace: Layer (dispatch2KHR): %s ", __func__);
#endif

    // Hold the lock to access layer-wide global store
    std::unique_lock<std::mutex> lock {g_vulkanLock};
    auto* layer = Device::retrieve(queue);

    // Release the lock to call into the driver
    lock.unlock();
    auto res = layer->driver.vkQueueSubmit2KHR(queue, submitCount, pSubmits, fence);

    return res;
}

/* See Vulkan API for documentation. */
template<>
VKAPI_ATTR VkResult VKAPI_CALL
    layer_vkWaitForFences<user_tag>(VkDevice device, uint32_t fenceCount, const VkFence* pFences, VkBool32 waitAll, uint64_t timeout)
{
#if CONFIG_TRACE == 1
    LAYER_LOG("API Trace: Layer (wait): %s ", __func__);
#endif

    // Hold the lock to access layer-wide global store
    std::unique_lock<std::mutex> lock {g_vulkanLock};
    auto* layer = Device::retrieve(device);

    // Release the lock to call into the driver
    lock.unlock();
    return layer->driver.vkWaitForFences(device, fenceCount, pFences, waitAll, timeout);
}

/* See Vulkan API for documentation. */
template<>
VKAPI_ATTR VkResult VKAPI_CALL
    layer_vkGetFenceStatus<user_tag>(VkDevice device, VkFence fence)
{
#if CONFIG_TRACE == 1
    LAYER_LOG("API Trace: Layer (getFenceStatus): %s ", __func__);
#endif

    // Hold the lock to access layer-wide global store
    std::unique_lock<std::mutex> lock {g_vulkanLock};
    auto* layer = Device::retrieve(device);

    // Release the lock to call into the driver
    lock.unlock();
    return layer->driver.vkGetFenceStatus(device, fence);
}

/* See Vulkan API for documentation. */
template<>
VKAPI_ATTR VkResult VKAPI_CALL layer_vkQueueWaitIdle<user_tag>(VkQueue queue)
{
#if CONFIG_TRACE == 1
    LAYER_LOG("API Trace: Layer (queueWaitIdle): %s ", __func__);
#endif

    std::unique_lock<std::mutex> lock {g_vulkanLock};
    auto* layer = Device::retrieve(queue);

    lock.unlock();
    return layer->driver.vkQueueWaitIdle(queue);
}

/* See Vulkan API for documentation. */
template<>
VKAPI_ATTR VkResult VKAPI_CALL layer_vkDeviceWaitIdle<user_tag>(VkDevice device)
{
#if CONFIG_TRACE == 1
    LAYER_LOG("API Trace: Layer (deviceWaitIdle): %s ", __func__);
#endif

    std::unique_lock<std::mutex> lock {g_vulkanLock};
    auto* layer = Device::retrieve(device);

    lock.unlock();
    return layer->driver.vkDeviceWaitIdle(device);
}

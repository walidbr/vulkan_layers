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

#pragma once

#include <vulkan/vulkan.h>

/* See Vulkan API for documentation. */
template<>
VKAPI_ATTR void VKAPI_CALL layer_vkCmdBeginRenderPass<user_tag>(VkCommandBuffer commandBuffer,
                                                                const VkRenderPassBeginInfo* pRenderPassBegin,
                                                                VkSubpassContents contents);

/* See Vulkan API for documentation. */
template<>
VKAPI_ATTR void VKAPI_CALL layer_vkCmdBeginRenderPass2<user_tag>(VkCommandBuffer commandBuffer,
                                                                 const VkRenderPassBeginInfo* pRenderPassBegin,
                                                                 const VkSubpassBeginInfo* pSubpassBeginInfo);

/* See Vulkan API for documentation. */
template<>
VKAPI_ATTR void VKAPI_CALL layer_vkCmdBeginRenderPass2KHR<user_tag>(VkCommandBuffer commandBuffer,
                                                                    const VkRenderPassBeginInfo* pRenderPassBegin,
                                                                    const VkSubpassBeginInfo* pSubpassBeginInfo);

/* See Vulkan API for documentation. */
template<>
VKAPI_ATTR void VKAPI_CALL layer_vkCmdBeginRendering<user_tag>(VkCommandBuffer commandBuffer,
                                                               const VkRenderingInfo* pRenderingInfo);

/* See Vulkan API for documentation. */
template<>
VKAPI_ATTR void VKAPI_CALL layer_vkCmdBeginRenderingKHR<user_tag>(VkCommandBuffer commandBuffer,
                                                                  const VkRenderingInfo* pRenderingInfo);




// Queue submit functions
template<>
VKAPI_ATTR VkResult VKAPI_CALL
    layer_vkQueueSubmit<user_tag>(VkQueue queue, uint32_t submitCount, const VkSubmitInfo* pSubmits, VkFence fence);

template<>
VKAPI_ATTR VkResult VKAPI_CALL
    layer_vkQueueSubmit2<user_tag>(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence);

template<>
VKAPI_ATTR VkResult VKAPI_CALL
    layer_vkQueueSubmit2KHR<user_tag>(VkQueue queue, uint32_t submitCount, const VkSubmitInfo2* pSubmits, VkFence fence);

// Fence / wait functions
template<>
VKAPI_ATTR VkResult VKAPI_CALL
    layer_vkWaitForFences<user_tag>(VkDevice device, uint32_t fenceCount, const VkFence* pFences, VkBool32 waitAll, uint64_t timeout);

template<>
VKAPI_ATTR VkResult VKAPI_CALL
    layer_vkGetFenceStatus<user_tag>(VkDevice device, VkFence fence);

template<>
VKAPI_ATTR VkResult VKAPI_CALL layer_vkQueueWaitIdle<user_tag>(VkQueue queue);

template<>
VKAPI_ATTR VkResult VKAPI_CALL layer_vkDeviceWaitIdle<user_tag>(VkDevice device);
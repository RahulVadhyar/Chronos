/*
Copyright (c) 2024 Rahul Satish Vadhyar

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "object.hpp"
#include <fstream>

/**
    \brief Returns the content of a shader file.

    This reads SPIV-V shader files and returns the contents of the file as a
    vector of chars. This is used to create shader modules.

    @param filename The filename of the shader file.

    @return The contents of the shader file as ```std::vector<char>```.
*/
static inline std::vector<char> readFile(const std::string& filename)
{
    // reads file. Used to read shaders
    std::ifstream file(filename, std::ios::ate | std::ios::binary);
    if (!file.is_open()) {
	throw std::runtime_error("Failed to open file: " + filename);
    }
    size_t fileSize = (size_t)file.tellg();
    std::vector<char> buffer(fileSize);
    file.seekg(0);
    file.read(buffer.data(), fileSize);
    file.close();
    return buffer;
}

/**
    \brief Creates a shader module from given shader(SPIV) code.

    In order to get ``std::vector<char>& code`` from a shader file, ``use
    readFile`` function.

    @param code The SPIV code to create the shader module from.
    @param device The device to create the shader module on.

    @return The created shader module.
*/
static inline VkShaderModule createShaderModule(
    const std::vector<char>& code, VkDevice device)
{
    VkShaderModuleCreateInfo createInfo {};
    createInfo.sType = VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO;
    createInfo.codeSize = code.size();
    createInfo.pCode = reinterpret_cast<const uint32_t*>(code.data());
    VkShaderModule shaderModule;
    if (vkCreateShaderModule(device, &createInfo, nullptr, &shaderModule)
	!= VK_SUCCESS) {
	throw std::runtime_error("Failed to create shader module");
    }
    return shaderModule;
}

void Chronos::Engine::Object::init(Chronos::Engine::Device* device,
    VkCommandPool commandPool, SwapChain* swapChain, VkSampler textureSampler,
    VkRenderPass* renderPass, ObjectType objectType)
{
    this->device = device;
    this->swapChain = swapChain;
    this->commandPool = commandPool;
    this->textureSampler = textureSampler;
    this->renderPass = renderPass;
    this->objectType = objectType;

    uniformBuffers.resize(MAX_FRAMES_IN_FLIGHT);
    for (size_t i = 0; i < MAX_FRAMES_IN_FLIGHT; i++) {
	uniformBuffers[i].create(*device);
    }

    createDescriptorPool();
    createDescriptorSetLayout();
    createDescriptorSets();
    createGraphicsPipeline();
}

void Chronos::Engine::Object::createGraphicsPipeline()
{
    Chronos::Engine::PipelineAttributes pipelineAttributes
	= getPipelineAttributes();

    auto vertShaderCode = readFile(vertexShaderPath.c_str());
    auto fragShaderCode = readFile(fragmentShaderPath.c_str());

    VkShaderModule vertShaderModule
	= createShaderModule(vertShaderCode, device->device);
    VkShaderModule fragShaderModule
	= createShaderModule(fragShaderCode, device->device);

    VkPipelineShaderStageCreateInfo vertShaderStageInfo {};
    vertShaderStageInfo.sType
	= VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
    vertShaderStageInfo.stage = VK_SHADER_STAGE_VERTEX_BIT;
    vertShaderStageInfo.module = vertShaderModule;
    vertShaderStageInfo.pName
	= "main"; // start from main(vulkan can start from elsewhere also)

    VkPipelineShaderStageCreateInfo fragShaderStageInfo {};
    fragShaderStageInfo.sType
	= VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
    fragShaderStageInfo.stage = VK_SHADER_STAGE_FRAGMENT_BIT;
    fragShaderStageInfo.module = fragShaderModule;
    fragShaderStageInfo.pName = "main";

    VkPipelineShaderStageCreateInfo shaderStages[]
	= { vertShaderStageInfo, fragShaderStageInfo };

    auto bindingDescription = pipelineAttributes.bindingDescriptions;
    auto attributeDescriptions = pipelineAttributes.attributeDescriptions;

    VkPipelineVertexInputStateCreateInfo vertexInputInfo {};
    vertexInputInfo.sType
	= VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;
    vertexInputInfo.vertexBindingDescriptionCount
	= static_cast<uint32_t>(bindingDescription.size());
    vertexInputInfo.vertexAttributeDescriptionCount
	= static_cast<uint32_t>(attributeDescriptions.size());
    vertexInputInfo.pVertexBindingDescriptions = bindingDescription.data();
    vertexInputInfo.pVertexAttributeDescriptions = attributeDescriptions.data();

    VkPipelineInputAssemblyStateCreateInfo inputAssembly {};
    inputAssembly.sType
	= VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
    inputAssembly.topology
	= pipelineAttributes.topology; // we are using indexed rendering so
				       // we need to use triangle list
    inputAssembly.primitiveRestartEnable = VK_FALSE;

    VkViewport viewport {};
    viewport.x = 0.0f;
    viewport.y = 0.0f;
    viewport.width = (float)(*swapChain).swapChainExtent.width;
    viewport.height = (float)(*swapChain).swapChainExtent.height;
    viewport.minDepth = 0.0f;
    viewport.maxDepth = 1.0f;

    VkRect2D scissor {};
    scissor.offset = { 0, 0 };
    scissor.extent = (*swapChain).swapChainExtent;

    VkPipelineViewportStateCreateInfo viewportState {};
    viewportState.sType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO;
    viewportState.viewportCount = 1;
    viewportState.pViewports = &viewport;
    viewportState.scissorCount = 1;
    viewportState.pScissors = &scissor;

    VkPipelineRasterizationStateCreateInfo rasterizer {};
    rasterizer.sType
	= VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO;
    rasterizer.depthClampEnable = VK_FALSE;
    rasterizer.rasterizerDiscardEnable = VK_FALSE;
    rasterizer.polygonMode = VK_POLYGON_MODE_FILL;
    rasterizer.lineWidth = 1.0f;
    rasterizer.cullMode = VK_CULL_MODE_BACK_BIT;
    rasterizer.frontFace = pipelineAttributes.frontFace; // counter clockwuise
    rasterizer.depthBiasEnable = VK_FALSE;
    rasterizer.depthBiasConstantFactor = 0.0f;
    rasterizer.depthBiasClamp = 0.0f;
    rasterizer.depthBiasSlopeFactor = 0.0f;

    VkPipelineMultisampleStateCreateInfo multisampling {};
    multisampling.sType
	= VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO;
    multisampling.sampleShadingEnable = VK_FALSE;
    multisampling.rasterizationSamples = device->msaaSamples;
    multisampling.minSampleShading = 1.0f; // Optional
    multisampling.pSampleMask = nullptr; // Optional
    multisampling.alphaToCoverageEnable = VK_FALSE; // Optional
    multisampling.alphaToOneEnable = VK_FALSE;
    multisampling.sampleShadingEnable = VK_TRUE;

    VkPipelineColorBlendStateCreateInfo colorBlending {};
    colorBlending.sType
	= VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;
    colorBlending.logicOpEnable = VK_FALSE;
    colorBlending.logicOp = VK_LOGIC_OP_COPY;
    colorBlending.attachmentCount = 1;
    colorBlending.pAttachments = &pipelineAttributes.colorBlendAttachment;
    colorBlending.blendConstants[0] = 0.0f;
    colorBlending.blendConstants[1] = 0.0f;
    colorBlending.blendConstants[2] = 0.0f;
    colorBlending.blendConstants[3] = 0.0f;

    std::vector<VkDynamicState> dynamicStates
	= { VK_DYNAMIC_STATE_VIEWPORT, VK_DYNAMIC_STATE_SCISSOR };
    VkPipelineDynamicStateCreateInfo dynamicState {};
    dynamicState.sType = VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO;
    dynamicState.dynamicStateCount
	= static_cast<uint32_t>(dynamicStates.size());
    dynamicState.pDynamicStates = dynamicStates.data();

    VkPipelineLayoutCreateInfo pipelineLayoutInfo {};
    pipelineLayoutInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
    pipelineLayoutInfo.setLayoutCount = 1; // Optional
    pipelineLayoutInfo.pSetLayouts = &descriptorSetLayout; // Optional
    pipelineLayoutInfo.pushConstantRangeCount = 0; // Optional
    pipelineLayoutInfo.pPushConstantRanges = nullptr; // Optional

    if (vkCreatePipelineLayout(
	    device->device, &pipelineLayoutInfo, nullptr, &pipelineLayout)
	!= VK_SUCCESS) {
	throw std::runtime_error("failed to create pipeline layout!");
    }

    VkGraphicsPipelineCreateInfo pipelineInfo {};
    pipelineInfo.sType = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;
    pipelineInfo.stageCount = 2;
    pipelineInfo.pStages = shaderStages;
    pipelineInfo.pVertexInputState = &vertexInputInfo;
    pipelineInfo.pInputAssemblyState = &inputAssembly;
    pipelineInfo.pViewportState = &viewportState;
    pipelineInfo.pRasterizationState = &rasterizer;
    pipelineInfo.pMultisampleState = &multisampling;
    pipelineInfo.pDepthStencilState = nullptr; // Optional
    pipelineInfo.pColorBlendState = &colorBlending;
    pipelineInfo.pDynamicState = &dynamicState;
    pipelineInfo.layout = pipelineLayout;
    pipelineInfo.renderPass = *renderPass;
    pipelineInfo.subpass = 0;
    pipelineInfo.basePipelineHandle = VK_NULL_HANDLE; // Optional
    pipelineInfo.basePipelineIndex = -1;

    if (vkCreateGraphicsPipelines(device->device, VK_NULL_HANDLE, 1,
	    &pipelineInfo, nullptr, &graphicsPipeline)
	!= VK_SUCCESS) {
	throw std::runtime_error("failed to create graphics pipeline!");
    }

    // destory the shader modules
    vkDestroyShaderModule(device->device, fragShaderModule, nullptr);
    vkDestroyShaderModule(device->device, vertShaderModule, nullptr);
}

void Chronos::Engine::Object::destroy()
{
    for (size_t i = 0; i < MAX_FRAMES_IN_FLIGHT; i++) {
	uniformBuffers[i].destroy();
    }
    vkDestroyDescriptorPool(device->device, descriptorPool, nullptr);
    vkDestroyDescriptorSetLayout(device->device, descriptorSetLayout, nullptr);
    vkDestroyPipeline(device->device, graphicsPipeline, nullptr);
    vkDestroyPipelineLayout(device->device, pipelineLayout, nullptr);
}

void Chronos::Engine::Object::createDescriptorPool()
{
    std::vector<VkDescriptorType> descriptorTypes = getDescriptorTypes();

    std::vector<VkDescriptorPoolSize> poolSizes { descriptorTypes.size() };

    for (size_t i = 0; i < descriptorTypes.size(); i++) {
	poolSizes[i].type = descriptorTypes[i];
	poolSizes[i].descriptorCount
	    = static_cast<uint32_t>(MAX_FRAMES_IN_FLIGHT);
    }
    VkDescriptorPoolCreateInfo poolInfo {};
    poolInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
    poolInfo.poolSizeCount = static_cast<uint32_t>(poolSizes.size());
    poolInfo.pPoolSizes = poolSizes.data();
    poolInfo.maxSets = static_cast<uint32_t>(MAX_FRAMES_IN_FLIGHT);
    if (vkCreateDescriptorPool(
	    device->device, &poolInfo, nullptr, &descriptorPool)
	!= VK_SUCCESS) {
	throw std::runtime_error("failed to create descriptor pool!");
    }
}

void Chronos::Engine::Object::createDescriptorSetLayout()
{
    std::vector<VkDescriptorType> descriptorTypes = getDescriptorTypes();
    std::vector<VkShaderStageFlagBits> descriptorStages = getDescriptorStages();

    if (descriptorTypes.size() != descriptorStages.size()) {
	throw std::runtime_error(
	    "descriptorTypes and descriptorStages must be the same size");
    }

    std::vector<VkDescriptorSetLayoutBinding> bindings {
	descriptorTypes.size()
    };

    for (size_t i = 0; i < descriptorTypes.size(); i++) {
	bindings[i].binding = i;
	bindings[i].descriptorType = descriptorTypes[i];
	bindings[i].descriptorCount = 1;
	bindings[i].stageFlags = descriptorStages[i];
	bindings[i].pImmutableSamplers = nullptr;
    }

    VkDescriptorSetLayoutCreateInfo layoutInfo {};
    layoutInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
    layoutInfo.bindingCount = static_cast<uint32_t>(bindings.size());
    layoutInfo.pBindings = bindings.data();
    if (vkCreateDescriptorSetLayout(
	    device->device, &layoutInfo, nullptr, &descriptorSetLayout)
	!= VK_SUCCESS) {
	throw std::runtime_error("failed to create descriptor set layout!");
    }
}

void Chronos::Engine::Object::recreateGraphicsPipeline()
{
    vkDestroyPipeline(device->device, graphicsPipeline, nullptr);
    vkDestroyPipelineLayout(device->device, pipelineLayout, nullptr);
    createGraphicsPipeline();
}

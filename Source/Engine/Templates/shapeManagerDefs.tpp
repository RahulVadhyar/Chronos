#pragma once
template <Chronos::Engine::VertexLike VertexStruct>
void Chronos::Engine::ShapeManager<VertexStruct>::render(uint32_t currentFrame, uint32_t imageIndex,
    float bgColor[3])
{
    Chronos::Engine::ObjectManager<Chronos::Engine::Shape<VertexStruct>>::render(currentFrame, imageIndex, bgColor);

    VkViewport viewport {};
    viewport.x = 0.0f;
    viewport.y = 0.0f;
    viewport.width = static_cast<float>(Chronos::Engine::ShapeManager<VertexStruct>::swapChain->swapChainExtent.width);
    viewport.height = static_cast<float>(Chronos::Engine::ShapeManager<VertexStruct>::swapChain->swapChainExtent.height);
    viewport.minDepth = 0.0f;
    viewport.maxDepth = 1.0f;

    VkRect2D scissor {};
    scissor.offset = { 0, 0 };
    scissor.extent = Chronos::Engine::ShapeManager<VertexStruct>::swapChain->swapChainExtent;

    // render the shapes
    for (auto& shape : Chronos::Engine::ShapeManager<VertexStruct>::objects) {
        vkCmdBindPipeline(Chronos::Engine::ShapeManager<VertexStruct>::commandBuffers[currentFrame],
            VK_PIPELINE_BIND_POINT_GRAPHICS, shape.second.graphicsPipeline);
        vkCmdSetViewport(Chronos::Engine::ShapeManager<VertexStruct>::commandBuffers[currentFrame], 0, 1, &viewport);
        vkCmdSetScissor(Chronos::Engine::ShapeManager<VertexStruct>::commandBuffers[currentFrame], 0, 1, &scissor);
        VkBuffer vertexBuffers[] = { shape.second.vertexBuffer.buffer };
        VkDeviceSize offsets[] = { 0 };
        vkCmdBindVertexBuffers(Chronos::Engine::ShapeManager<VertexStruct>::commandBuffers[currentFrame], 0, 1, vertexBuffers,
            offsets);
        vkCmdBindIndexBuffer(Chronos::Engine::ShapeManager<VertexStruct>::commandBuffers[currentFrame], shape.second.indexBuffer.buffer,
            0, VK_INDEX_TYPE_UINT16);
        vkCmdBindDescriptorSets(Chronos::Engine::ShapeManager<VertexStruct>::commandBuffers[currentFrame],
            VK_PIPELINE_BIND_POINT_GRAPHICS,
            shape.second.pipelineLayout, 0, 1,
            &shape.second.descriptorSets[currentFrame], 0, nullptr);
        vkCmdDrawIndexed(Chronos::Engine::ShapeManager<VertexStruct>::commandBuffers[currentFrame],
            static_cast<uint32_t>(shape.second.indices.size()), 1, 0, 0, 0);
    }
    Chronos::Engine::ShapeManager<VertexStruct>::endRender(currentFrame);
}

template <Chronos::Engine::VertexLike VertexStruct>
int Chronos::Engine::ShapeManager<VertexStruct>::addRectangle(Chronos::Manager::ShapeParams shapeParams,
    std::string texturePath) requires(std::is_same<Chronos::Engine::TexturedVertex, VertexStruct>::value)
{
    int shapeNo = Chronos::Engine::ObjectManager<Chronos::Engine::Shape<VertexStruct>>::addObject(Rectangle<Chronos::Engine::TexturedVertex>());
    Chronos::Engine::ShapeManager<VertexStruct>::objects[shapeNo].init(Chronos::Engine::ShapeManager<VertexStruct>::device, Chronos::Engine::ShapeManager<VertexStruct>::commandPool, Chronos::Engine::ShapeManager<VertexStruct>::swapChain, Chronos::Engine::ShapeManager<VertexStruct>::textureSampler,
        texturePath, &(Chronos::Engine::ShapeManager<VertexStruct>::renderPass));
    Chronos::Engine::ShapeManager<VertexStruct>::objects[shapeNo].params = shapeParams;
    return shapeNo;
}

template <Chronos::Engine::VertexLike VertexStruct>
int Chronos::Engine::ShapeManager<VertexStruct>::addRectangle(Chronos::Manager::ShapeParams shapeParams,
    std::array<float, 3> color) requires(std::is_same<Chronos::Engine::ColorVertex, VertexStruct>::value)
{
    int shapeNo = Chronos::Engine::ObjectManager<Chronos::Engine::Shape<VertexStruct>>::addObject(Rectangle<Chronos::Engine::ColorVertex>());
    Chronos::Engine::ShapeManager<VertexStruct>::objects[shapeNo].init(Chronos::Engine::ShapeManager<VertexStruct>::device, Chronos::Engine::ShapeManager<VertexStruct>::commandPool, Chronos::Engine::ShapeManager<VertexStruct>::swapChain, Chronos::Engine::ShapeManager<VertexStruct>::textureSampler, color,
        &(Chronos::Engine::ShapeManager<VertexStruct>::renderPass));
    Chronos::Engine::ShapeManager<VertexStruct>::objects[shapeNo].params = shapeParams;
    return shapeNo;
}

template <Chronos::Engine::VertexLike VertexStruct>
int Chronos::Engine::ShapeManager<VertexStruct>::addTriangle(Chronos::Manager::ShapeParams shapeParams,
    std::string texturePath) requires(std::is_same<Chronos::Engine::TexturedVertex, VertexStruct>::value)
{
    int shapeNo = Chronos::Engine::ObjectManager<Chronos::Engine::Shape<VertexStruct>>::addObject(Triangle<Chronos::Engine::TexturedVertex>());
    Chronos::Engine::ShapeManager<VertexStruct>::objects[shapeNo].init(Chronos::Engine::ShapeManager<VertexStruct>::device, Chronos::Engine::ShapeManager<VertexStruct>::commandPool, Chronos::Engine::ShapeManager<VertexStruct>::swapChain, Chronos::Engine::ShapeManager<VertexStruct>::textureSampler,
        texturePath, &(Chronos::Engine::ShapeManager<VertexStruct>::renderPass));
    Chronos::Engine::ShapeManager<VertexStruct>::objects[shapeNo].params = shapeParams;
    return shapeNo;
}

template <Chronos::Engine::VertexLike VertexStruct>
int Chronos::Engine::ShapeManager<VertexStruct>::addTriangle(Chronos::Manager::ShapeParams shapeParams,
    std::array<float, 3> color) requires(std::is_same<Chronos::Engine::ColorVertex, VertexStruct>::value)
{
    int shapeNo = Chronos::Engine::ObjectManager<Chronos::Engine::Shape<VertexStruct>>::addObject(Triangle<Chronos::Engine::ColorVertex>());
    Chronos::Engine::ShapeManager<VertexStruct>::objects[shapeNo].init(Chronos::Engine::ShapeManager<VertexStruct>::device, Chronos::Engine::ShapeManager<VertexStruct>::commandPool, Chronos::Engine::ShapeManager<VertexStruct>::swapChain, Chronos::Engine::ShapeManager<VertexStruct>::textureSampler, color,
        &(Chronos::Engine::ShapeManager<VertexStruct>::renderPass));
    Chronos::Engine::ShapeManager<VertexStruct>::objects[shapeNo].params = shapeParams;
    return shapeNo;
}

template <Chronos::Engine::VertexLike VertexStruct>
void Chronos::Engine::ShapeManager<VertexStruct>::createRenderPass()
{
    /*
   For the render pass the formats are as follows:
           initial - undefined; this is due to the fact that image is cleared
           final(color and msaa) - color attachment optimal; this is due to the
   fact that the image going to next renderpass(Text) Also we are clearing the
   framebuffer
   */
    VkImageLayout initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
    if (std::is_same<Chronos::Engine::ColorVertex, VertexStruct>::value){
        initialLayout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;
    }
    Chronos::Engine::ShapeManager<VertexStruct>::renderPass = Chronos::Engine::createRenderPass(*Chronos::Engine::ShapeManager<VertexStruct>::device, *Chronos::Engine::ShapeManager<VertexStruct>::swapChain, 
        initialLayout,
        VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL,
        VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL, true,
        std::is_same<Chronos::Engine::TexturedVertex, VertexStruct>::value, false);
}


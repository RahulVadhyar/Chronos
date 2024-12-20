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

#include "editorHeaders.hpp"
#include "editorManager.hpp"
#include "editorTheme.hpp"
#include "logging.hpp"
#include "editorCodeGenerator.hpp"

void Chronos::Editor::EditorManager::addElements()
{
    Chronos::Editor::setImGuiStyle();
    this->MenuBar();
    this->ShapeWindow();
    this->TextureWindow();
    this->TextWindow();
    this->AnimationWindow();
    this->SettingsWindow();
    this->TotalCodeGenerationWindow();
    this->ShapeDetailsWindow();
    this->TextureDetailsWindow();
    this->TextDetailsWindow();
    this->KeyframeDetailsWindow();
    this->DebugMetricsWindow();
    this->DebugLogWindow();
#ifdef CHRONOS_PROFILING
    this->ProfilingWindow();
#endif
    this->updateKeyframes();

    LOG(4, "Elements added to the editor.")
}

void Chronos::Editor::EditorManager::MenuBar()
{
    if (this->pinMenuBar) {
	if (ImGui::BeginMainMenuBar()) {
	    ImGui::MenuItem("Shape", NULL, &this->showShapeWindow);
	    ImGui::MenuItem("Texture", NULL, &this->showTextureWindow);
	    ImGui::MenuItem("Text", NULL, &this->showTextWindow);
	    ImGui::MenuItem("Animation", NULL, &this->showAnimationWindow);
	    ImGui::MenuItem("Settings", NULL, &this->showSettingsWindow);
	    ImGui::MenuItem(
		"Generated Code", NULL, &this->showGeneratedCodeWindow);
#ifdef CHRONOS_PROFILING
	    ImGui::MenuItem("Profiling", NULL, &this->showProfilingWindow);
#endif
	    ImGui::EndMainMenuBar();
	}
    } else {
	ImGui::Begin("Editor", nullptr, ImGuiWindowFlags_MenuBar);
	if (ImGui::BeginMenuBar()) {
	    ImGui::MenuItem("Shape", NULL, &this->showShapeWindow);
	    ImGui::MenuItem("Texture", NULL, &this->showTextureWindow);
	    ImGui::MenuItem("Text", NULL, &this->showTextWindow);
	    ImGui::MenuItem("Animation", NULL, &this->showAnimationWindow);
	    ImGui::MenuItem("Settings", NULL, &this->showSettingsWindow);
	    ImGui::MenuItem(
		"Generated Code", NULL, &this->showGeneratedCodeWindow);
	    ImGui::EndMenuBar();
	}
	ImGui::End();
    }
}

void Chronos::Editor::EditorManager::ShapeWindow()
{
    if (this->showShapeWindow) {
	ImGui::Begin("Shape", &this->showShapeWindow);
	bool doesNameExist = false;
	ImGui::SeparatorText("Shape Name");
	ImGui::InputText("Shape Name", this->newShapeParams.shapeName, 200);
	std::vector<std::pair<int, Chronos::Manager::ShapeParams>>
	    nameShapeDetails = this->manager->getShapeDetails();
	for (std::pair<int, Chronos::Manager::ShapeParams> shapeDetail :
	    nameShapeDetails) {
	    if (!strcmp(this->newShapeParams.shapeName,
		    shapeDetail.second.shapeName)) {
		ImGui::Text("Name Already Exists");
		doesNameExist = true;
		break;
	    }
	}
	ImGui::SeparatorText("Fill");
	ImGui::RadioButton("Color", &this->newShapeFill, 0);
	ImGui::RadioButton("Texture", &this->newShapeFill, 1);
	ImGui::SeparatorText("Properties");
	ImGui::DragFloat(
	    "X(-1 to 1)", &this->newShapeParams.x, 0.01f, -1.0f, 1.0f);
	ImGui::DragFloat(
	    "Y(-1 to 1)", &this->newShapeParams.y, 0.01f, -1.0f, 1.0f);
	ImGui::DragFloat(
	    "X Size", &this->newShapeParams.xSize, 0.01f, 0.0f, FLT_MAX);
	ImGui::DragFloat(
	    "Y Size", &this->newShapeParams.ySize, 0.01f, 0.0f, FLT_MAX);
	ImGui::DragFloat(
	    "Rotation", &this->newShapeParams.rotation, 0.01f, 0.0f, FLT_MAX);
	switch (this->newShapeFill) {
	case 0:
	    ImGui::ColorEdit3("Color", this->newShapeParams.color.data());
	    break;
	case 1:
	    if (ImGui::BeginCombo("Select Texture", currentShapeTextureName)) {
		std::vector<Chronos::Manager::TextureDetails> details
		    = this->manager->getTextureDetails();
		if (details.size() == 0) {
		    ImGui::Selectable("No Textures");
		} else {
		    for (Chronos::Manager::TextureDetails textureDetail :
			details) {
			bool isSelected = currentShapeTextureSelection
			    == textureDetail.textureNo;
			if (ImGui::Selectable(textureDetail.textureName.c_str(),
				isSelected)) {
			    currentShapeTextureSelection
				= textureDetail.textureNo;
			    strcpy(currentShapeTextureName,
				textureDetail.textureName.c_str());
			    LOG(1,
				"Texture selected for shapeNo ["
				    + std::to_string(
					currentShapeTextureSelection)
				    + "], textureName ["
				    + currentShapeTextureName + "]")
			}
			if (isSelected) {
			    ImGui::SetItemDefaultFocus();
			}
		    }
		}
		ImGui::EndCombo();
	    }
	}
	if (!doesNameExist) {
	    if (ImGui::Button("Add Shape")) {
		switch (this->newShapeFill) {
		case 0:
		    this->manager->addShape(this->newShapeParams);
		    LOG(1,
			"Colored shape added with shapeName ["
			    + std::string(this->newShapeParams.shapeName) + "]")
		    break;
		case 1:
		    this->manager->addShape(this->newShapeParams,
			this->currentShapeTextureSelection);
		    LOG(1,
			"Textured shape added with shapeName ["
			    + std::string(this->newShapeParams.shapeName) + "]")
		    break;
		}
	    }
	}
	ImGui::SeparatorText("Current Shapes");
	if (ImGui::BeginListBox("Shapes")) {
	    std::vector<std::pair<int, Chronos::Manager::ShapeParams>>
		shapeDetails = this->manager->getShapeDetails();
	    if (shapeDetails.size() == 0) {
		ImGui::Selectable("No Shapes");
	    } else {
		for (int i = 0; i < static_cast<int>(shapeDetails.size());
		    i++) {
		    if (ImGui::Selectable(shapeDetails[i].second.shapeName,
			    this->currentShapeSelection == i)) {
			this->currentShapeSelection = i;
		    }
		}
	    }
	    ImGui::EndListBox();
	    if (shapeDetails.size() > 0) {
		ImGui::Text("Selected Shape: %d",
		    shapeDetails[currentShapeSelection].first);
		if (ImGui::Button("Edit Shape")) {
		    this->showShapeDetailsWindow = true;
		    this->shapeDetailsShapeNo
			= shapeDetails[currentShapeSelection].first;
		    this->shapeDetailsShapeParams
			= shapeDetails[currentShapeSelection].second;
		}
		ImGui::SameLine();
		if (ImGui::Button("Remove Shape")) {
		    this->manager->removeObject(
			shapeDetails[currentShapeSelection].first);
		}
	    }
	}

	ImGui::End();
    }
}

void Chronos::Editor::EditorManager::TextureWindow()
{
    if (this->showTextureWindow) {
	ImGui::Begin("Texture", &this->showTextureWindow);
	bool doesTextureExist = false;
	ImGui::SeparatorText("Add Textures");
	ImGui::InputText("Texture Path", this->newTexturePath, 200);
	ImGui::InputText("Texture Name", this->newTextureName, 200);
	std::vector<Chronos::Manager::TextureDetails> nameTextureDetails
	    = this->manager->getTextureDetails();
	for (Chronos::Manager::TextureDetails textureDetail :
	    nameTextureDetails) {
	    if (!strcmp(
		    this->newTextureName, textureDetail.textureName.c_str())) {
		ImGui::Text("Name Already Exists");
		doesTextureExist = true;
		break;
	    }
	    if (std::string(this->newTextureName).size() == '\0') {
		ImGui::Text("Name Cannot be empty");
		doesTextureExist = true;
		break;
	    }
	    if (!std::string(this->newTexturePath).ends_with(".jpg")
		&& !std::string(this->newTexturePath).ends_with(".png")) {
		ImGui::Text("Only jpg and png files are supported");
		doesTextureExist = true;
		break;
	    }
	}

	if (!doesTextureExist) {
	    if (ImGui::Button("Add Texture")) {
		this->manager->addTexture(
		    this->newTexturePath, this->newTextureName);
		this->newTexturePath[0] = '\0';
		LOG(1,
		    "Texture added with textureName ["
			+ std::string(this->newTextureName)
			+ "] and texturePath [" + this->newTexturePath + "]")
	    }
	}
	ImGui::SeparatorText("Current Textures");
	std::vector<Chronos::Manager::TextureDetails> details
	    = this->manager->getTextureDetails();
	if (ImGui::BeginListBox("Textures")) {
	    if (details.size() == 0) {
		ImGui::Selectable("No Textures");
	    } else {
		for (int i = 0; i < static_cast<int>(details.size()); i++) {
		    if (ImGui::Selectable(details[i].textureName.c_str(),
			    currentTextureSelection == i)) {
			currentTextureSelection = i;
		    }
		}
	    }
	    ImGui::EndListBox();
	}
	if (details.size() > 0) {
	    if (ImGui::Button("Remove Texture")) {
		this->manager->removeTexture(
		    details[currentTextureSelection].textureNo);
		LOG(1,
		    "Texture removed with textureNo ["
			+ std::to_string(
			    details[currentTextureSelection].textureNo)
			+ "]")
	    }
	    ImGui::SameLine();
	    if (ImGui::Button("View Texture Details")) {
		this->showTextureDetailsWindow = true;
		LOG(1,
		    "Texture selected for editing with textureNo ["
			+ std::to_string(this->textureDetailsCurrentSelection)
			+ "]")
	    }
	}
	ImGui::End();
    }
}

void Chronos::Editor::EditorManager::TextWindow()
{
    if (this->showTextWindow) {
	ImGui::Begin("Text", &this->showTextWindow);
	ImGui::SeparatorText("Add Text");
	char inputText[2048];
	strcpy(inputText, this->newTextParams.text.c_str());
	ImGui::InputText("Text", inputText, 2048);
	this->newTextParams.text = inputText;
	ImGui::DragFloat(
	    "X(-1 to 1)", &this->newTextParams.x, 0.01f, -1.0f, 1.0f);
	ImGui::DragFloat(
	    "Y(-1 to 1)", &this->newTextParams.y, 0.01f, -1.0f, 1.0f);
	ImGui::DragFloat(
	    "Rotation", &this->newTextParams.rotation, 0.01f, 0.0f, FLT_MAX);
	ImGui::DragFloat(
	    "Scale", &this->newTextParams.scale, 0.01f, 0.0f, FLT_MAX);
	ImGui::ColorEdit3("Color", this->newTextParams.color.data());
	if (ImGui::BeginCombo(
		"Select Font", this->currentFontSelection.c_str())) {
	    if (ImGui::Selectable(
		    "consolas", this->currentFontSelection == "consolas")) {
		this->currentFontSelection = "consolas";
		LOG(1,
		    "Font selected [" + this->currentFontSelection + "]")
	    }
	    if (ImGui::Selectable("consolas_bold",
		    this->currentFontSelection == "consolas_bold")) {
		this->currentFontSelection = "consolas_bold";
		LOG(1,
		    "Font selected [" + this->currentFontSelection + "]")
	    }
	    if (ImGui::Selectable(
		    "arial", this->currentFontSelection == "arial")) {
		this->currentFontSelection = "arial";
		LOG(1,
		    "Font selected [" + this->currentFontSelection + "]")
	    }
	    if (ImGui::Selectable(
		    "arial_bold", this->currentFontSelection == "arial_bold")) {
		this->currentFontSelection = "arial_bold";
		LOG(1,
		    "Font selected [" + this->currentFontSelection + "]")
	    }
	    if (ImGui::Selectable(
		    "times", this->currentFontSelection == "times")) {
		this->currentFontSelection = "times";
		LOG(1,
		    "Font selected [" + this->currentFontSelection + "]")
	    }
	    if (ImGui::Selectable(
		    "times_bold", this->currentFontSelection == "times_bold")) {
		this->currentFontSelection = "times_bold";
		LOG(1,
		    "Font selected [" + this->currentFontSelection + "]")
	    }
	    ImGui::EndCombo();
	}
	ImGui::DragInt("Font Size", &this->currentFontSizeSelection, 1, 6, 50);
	if (this->newTextParams.text.size() == 0) {
	    ImGui::Text("Text Cannot be empty");
	} else {
	    if (ImGui::Button("Add Text")) {
		this->manager->addText(this->newTextParams,
		    this->currentFontSelection, this->currentFontSizeSelection);
		LOG(1,
		    "Text added with text [" + this->newTextParams.text + "]")
	    }
	}
	ImGui::SeparatorText("Current Text");
	if (ImGui::BeginListBox("Text")) {
	    std::vector<std::pair<int, Chronos::Engine::TextParams>> textDetails
		= this->manager->getTextDetails();
	    if (textDetails.size() == 0) {
		ImGui::Selectable("No Text");
	    } else {
		for (int i = 0; i < static_cast<int>(textDetails.size()); i++) {
		    if (ImGui::Selectable(textDetails[i].second.text.c_str(),
			    this->currentTextSelection == i)) {
			this->currentTextSelection = i;
		    }
		}
	    }
	    ImGui::EndListBox();
	    if (textDetails.size() > 0) {
		if (ImGui::Button("Edit Text")) {
		    this->showTextDetailsWindow = true;
		    this->textDetailsTextNo
			= textDetails[currentTextSelection].first;
		    this->textDetailsTextParams
			= textDetails[currentTextSelection].second;
		    LOG(1,
			"Text selected for editing with textNo ["
			    + std::to_string(this->textDetailsTextNo) + "]")
		}
		ImGui::SameLine();
		if (ImGui::Button("Remove Text")) {
		    this->manager->removeObject(
			textDetails[currentTextSelection].first);
		    LOG(1, 
			"Text removed with textNo ["
			    + std::to_string(
				textDetails[currentTextSelection].first)
			    + "]")
		}
	    }
	}
	ImGui::End();
    }
}

void Chronos::Editor::EditorManager::SettingsWindow()
{
    if (this->showSettingsWindow) {
	ImGui::Begin("Settings", &this->showSettingsWindow);
	ImGui::SeparatorText("Build Information");
	ImGui::Text("Engine name: %s", "Chronos");
	ImGui::Text("Build Version: %d.%d.%d", CHRONOS_VERSION_MAJOR,
	    CHRONOS_VERSION_MINOR, CHRONOS_VERSION_PATCH);
	ImGui::Text("Build Date: %s", __DATE__);
	ImGui::Text("Build Time: %s", __TIME__);

	ImGui::SeparatorText("Window Settings");
	ImGui::InputText("Window Title", this->windowTitle, 200);
	if (ImGui::Button("Update Window Title")) {
	    glfwSetWindowTitle(this->manager->getWindow(), this->windowTitle);
	    LOG(1,
		"Window title updated to [" + std::string(this->windowTitle)
		    + "]")
	}
	ImGui::Checkbox("Make Window Fullscreen", &this->fullScreen);
	if (this->fullScreen && !this->isWindowFullscreen) {
	    GLFWwindow* window = this->manager->getWindow();
	    const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	    glfwSetWindowMonitor(window, glfwGetPrimaryMonitor(), 0, 0,
		mode->width, mode->height, mode->refreshRate);
	    this->isWindowFullscreen = true;
	    LOG(1,"Window set to fullscreen")
	} else if (!this->fullScreen && this->isWindowFullscreen) {
	    GLFWwindow* window = this->manager->getWindow();
	    glfwSetWindowMonitor(window, nullptr, 0, 0, 800, 600, 0);
	    this->isWindowFullscreen = false;
	    LOG(1, "Window set to windowed mode")
	}

	ImGui::SeparatorText("Present Mode");
	if (ImGui::BeginCombo("Present Mode", this->presentMode.c_str())) {
	    if (ImGui::Selectable("mailbox", this->presentMode == "mailbox")) {
		this->presentMode = "mailbox";
	    }
	    if (ImGui::Selectable(
		    "immediate", this->presentMode == "immediate")) {
		this->presentMode = "immediate";
	    }
	    if (ImGui::Selectable("fifo", this->presentMode == "fifo")) {
		this->presentMode = "fifo";
	    }
	    if (ImGui::Selectable(
		    "fifo_relaxed", this->presentMode == "fifo_relaxed")) {
		this->presentMode = "fifo_relaxed";
	    }
	    ImGui::EndCombo();
	}
	if (ImGui::Button("Update Present Mode")) {
	    this->manager->changePresentMode(this->presentMode);
	    LOG(1, 
		"Present mode updated to [" + this->presentMode + "]")
	}

	ImGui::SeparatorText("MSAA Samples");
	std::vector<std::string> msaaSamples = this->manager->getMSAAModes();
	for (std::string sample : msaaSamples) {
	    if (ImGui::Selectable(
		    sample.c_str(), this->msaaSamples == sample)) {
		this->msaaSamples = sample;
	    }
	}
	if (ImGui::Button("Update MSAA Samples")) {
	    this->manager->changeMSAA(this->msaaSamples);
	    LOG(1,
		"MSAA Samples updated to [" + this->msaaSamples + "]")
	}

	ImGui::SeparatorText("Background Color");
	ImGui::ColorEdit3("Background Color", this->bgColor);
	if (ImGui::Button("Update Background Color")) {
	    this->manager->changeBackgroundColor(
		this->bgColor[0], this->bgColor[1], this->bgColor[2]);
	    LOG(1,
		"Background color updated to ["
		    + std::to_string(this->bgColor[0]) + ", "
		    + std::to_string(this->bgColor[1]) + ", "
		    + std::to_string(this->bgColor[2]) + "]")
	}

	ImGui::SeparatorText("ImGui Debug Settings");
	ImGui::Checkbox("Show Metrics", &this->showDebugMetricsWindow);
	ImGui::Checkbox("Show Log", &this->showDebugLogWindow);
	ImGui::Checkbox("Pin Menu Bar", &this->pinMenuBar);

	ImGui::End();
    }
}

void Chronos::Editor::EditorManager::ShapeDetailsWindow()
{
    if (this->showShapeDetailsWindow) {
	ImGui::Begin("Shape Details", &this->showShapeDetailsWindow);
	ImGui::SeparatorText("Shape Details");
	if (this->manager->getShapeDetails().size() == 0) {
	    ImGui::Text("No Shapes");
	} else {
	    ImGui::InputText(
		"Shape Name", this->shapeDetailsShapeParams.shapeName, 200);
	    ImGui::DragFloat("X(-1 to 1)", &this->shapeDetailsShapeParams.x,
		0.01f, -1.0f, 1.0f);
	    ImGui::SameLine();
	    this->keyframeCheckbox(&this->shapeDetailsShapeParams.x, "X");
	    ImGui::DragFloat("Y(-1 to 1)", &this->shapeDetailsShapeParams.y,
		0.01f, -1.0f, 1.0f);
	    ImGui::SameLine();
	    this->keyframeCheckbox(&this->shapeDetailsShapeParams.y, "Y");
	    ImGui::DragFloat("X Size", &this->shapeDetailsShapeParams.xSize,
		0.01f, 0.0f, FLT_MAX);
	    ImGui::SameLine();
	    this->keyframeCheckbox(
		&this->shapeDetailsShapeParams.xSize, "X size");
	    ImGui::DragFloat("Y Size", &this->shapeDetailsShapeParams.ySize,
		0.01f, 0.0f, FLT_MAX);
	    ImGui::SameLine();
	    this->keyframeCheckbox(
		&this->shapeDetailsShapeParams.ySize, "Y size");
	    ImGui::DragFloat("Rotation",
		&this->shapeDetailsShapeParams.rotation, 0.01f, 0.0f, FLT_MAX);
	    ImGui::SameLine();
	    this->keyframeCheckbox(
		&this->shapeDetailsShapeParams.rotation, "Rotation(degrees)");
	    ImGui::ColorEdit3(
		"Color", this->shapeDetailsShapeParams.color.data());
	    this->manager->updateShape(
		this->shapeDetailsShapeNo, this->shapeDetailsShapeParams);
	}
	ImGui::End();
    }
}

void Chronos::Editor::EditorManager::TextureDetailsWindow()
{
    if (this->showTextureDetailsWindow) {
	ImGui::Begin("Texture Details", &this->showTextureDetailsWindow);
	ImGui::SeparatorText("Texture Details");
	std::vector<Chronos::Manager::TextureDetails> textureDetails
	    = this->manager->getTextureDetails();
	if (textureDetails.size() == 0) {
	    ImGui::Text("No Textures");
	} else {
	    ImGui::Text("Texture Name: %s",
		textureDetails[this->textureDetailsCurrentSelection]
		    .textureName.data());
	    ImGui::Text("Texture Path: %s",
		textureDetails[this->textureDetailsCurrentSelection]
		    .texturePath.data());
	    ImGui::Text("Width: %d",
		textureDetails[this->textureDetailsCurrentSelection].width);
	    ImGui::Text("Height: %d",
		textureDetails[this->textureDetailsCurrentSelection].height);
	    ImGui::SeparatorText("Texture Preview");
	    ImGui::Image(
		(ImTextureID)
		    textureDetails[this->textureDetailsCurrentSelection]
			.descriptorSet,
		ImVec2(
		    textureDetails[this->textureDetailsCurrentSelection].width,
		    textureDetails[this->textureDetailsCurrentSelection]
			.height));
	}
	ImGui::End();
    }
}

void Chronos::Editor::EditorManager::TextDetailsWindow()
{
    if (this->showTextDetailsWindow) {
	ImGui::Begin("Text Details", &this->showTextDetailsWindow);
	ImGui::SeparatorText("Text Details");
	std::vector<std::pair<int, Chronos::Engine::TextParams>> textDetails
	    = this->manager->getTextDetails();
	if (textDetails.size() == 0) {
	    ImGui::Text("No Text");
	} else {
	    char inputText[2048];
	    strcpy(inputText, this->textDetailsTextParams.text.c_str());
	    ImGui::InputText("Text", inputText, 2048);
	    if (inputText[0] != '\0') {
		this->textDetailsTextParams.text = inputText;
		ImGui::Text("Text Field cannot be empty");
	    }

	    ImGui::DragFloat("X(-1 to 1)", &this->textDetailsTextParams.x,
		0.01f, -1.0f, 1.0f);
	    ImGui::DragFloat("Y(-1 to 1)", &this->textDetailsTextParams.y,
		0.01f, -1.0f, 1.0f);
	    ImGui::DragFloat("Rotation", &this->textDetailsTextParams.rotation,
		0.01f, 0.0f, FLT_MAX);
	    ImGui::DragFloat("Scale", &this->textDetailsTextParams.scale, 0.01f,
		0.0f, FLT_MAX);
	    ImGui::ColorEdit3(
		"Color", this->textDetailsTextParams.color.data());
	    this->manager->updateText(
		this->textDetailsTextNo, this->textDetailsTextParams);
	}
	ImGui::End();
    }
}
void Chronos::Editor::EditorManager::DebugMetricsWindow()
{
    if (this->showDebugMetricsWindow) {
	ImGui::ShowMetricsWindow(&this->showDebugMetricsWindow);
    }
}

void Chronos::Editor::EditorManager::DebugLogWindow()
{
    if (this->showDebugLogWindow) {
	ImGui::ShowDebugLogWindow(&this->showDebugLogWindow);
    }
}

#ifdef CHRONOS_PROFILING
void Chronos::Editor::EditorManager::ProfilingWindow()
{
    if (this->showProfilingWindow) {
	ImGui::Begin("Profiling", &this->showProfilingWindow);
	ImGui::Text("FPS %f ms", 1000 / this->manager->getTotalTime());
	ImGui::Text("Frame Time %f ms", this->manager->getTotalTime());
	ImGui::Text("Update Time %f ms", this->manager->getUpdateTime());
	ImGui::Text("CPU Time %f ms", this->manager->getCpuTime());
	ImGui::Text("GPU Time %f ms",
	    this->manager->getTotalTime() - this->manager->getCpuTime());
	ImGui::Text("Present Time %f ms", this->manager->getPresentTime());
	ImGui::End();
    }
}
#endif

void Chronos::Editor::EditorManager::TotalCodeGenerationWindow()
{
    if (this->showGeneratedCodeWindow) {
	ImGui::Begin("Generated Code", &this->showGeneratedCodeWindow);
	ImGui::SeparatorText("Generated Code");
	std::string code = Chronos::Editor::generateCode(this->manager);
	ImGui::InputTextMultiline("Code", code.data(), code.size(),
	    ImVec2(800, 600), ImGuiInputTextFlags_ReadOnly);
	ImGui::End();
    }
}

void Chronos::Editor::EditorManager::AnimationWindow()
{
    if (this->showAnimationWindow) {
	ImGui::Begin("Animation", &this->showAnimationWindow);
	ImGui::SeparatorText("Animation");
	ImGui::End();
    }
}

void Chronos::Editor::EditorManager::KeyframeDetailsWindow()
{
    if (this->showKeyframeDetailsWindow) {
	ImGui::Begin("Keyframe Details", &this->showKeyframeDetailsWindow);
	ImGui::SeparatorText("Keyframe Details");
	ImGui::Text("Current Value pointer: %p",
	    (void*)this->currentKeyframeValuePointer);
	int keyframeNo = this->getKeyframeNo(this->currentKeyframeValuePointer);
	ImGui::Text("Keyframe Number: %d", keyframeNo);
	ImGui::End();
    }
}

int Chronos::Editor::EditorManager::getKeyframeNo(float* valuePointer)
{
    if (!valuePointer) {
	throw std::runtime_error("Value Pointer is null");
    }
    if (this->floatPointerToKeyframeNo.find(valuePointer)
	== this->floatPointerToKeyframeNo.end()) {
	return -1;
    } else {
	return this->floatPointerToKeyframeNo[valuePointer];
    }
}

bool Chronos::Editor::EditorManager::doesKeyframeExist(float* valuePointer)
{
    if (this->getKeyframeNo(valuePointer) == -1)
	return false;
    return true;
}

void Chronos::Editor::EditorManager::keyframeCheckbox(
    float* valuePointer, std::string name)
{
    bool isAnimated = this->doesKeyframeExist(valuePointer);
    bool currentChange = isAnimated;
    ImGui::Checkbox(name.c_str(), &currentChange);
    if (currentChange != isAnimated) {
	LOG(3,
	    "Animate checkbox changed for valuePointer ["
		+ std::to_string((long long)valuePointer) + "]");
	if (currentChange) {
	    int keyframeNo = this->manager->addKeyframeVariable(
		{ { 0, *valuePointer }, { 100, *valuePointer } });
	    this->floatPointerToKeyframeNo[valuePointer] = keyframeNo;
	    LOG(3,
		"Added keyframe for valuePointer ["
		    + std::to_string((long long)valuePointer)
		    + "] with keyframeNo [" + std::to_string(keyframeNo) + "]")
	} else {
	    int keyframeNo = this->getKeyframeNo(valuePointer);
	    if (keyframeNo == -1) {
		throw std::runtime_error("Could not find keyframe number!!!");
	    }
	    this->manager->removeKeyframeVariable(keyframeNo);
	    this->floatPointerToKeyframeNo.erase(valuePointer);
	    LOG(3, 
		"Removed keyframe for valuePointer ["
		    + std::to_string((long long)valuePointer)
		    + "] with keyframeNo [" + std::to_string(keyframeNo) + "]")
	}
    }
    if (currentChange) {
	ImGui::SameLine();
	if (ImGui::Button("Keyframe Details")) {
	    this->showKeyframeDetailsWindow = true;
	    this->currentKeyframeValuePointer = valuePointer;
	}
    }
}

void Chronos::Editor::EditorManager::updateKeyframes()
{
    for (auto& [key, value] : this->floatPointerToKeyframeNo) {
	*key = this->manager->keyframeGetVariable(value);
	LOG(4,
	    "Updated keyframe value for keyframeNo [" + std::to_string(value)
		+ "] to [" + std::to_string(*key) + "]")
    }
}
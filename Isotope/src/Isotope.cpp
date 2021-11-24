#include "isotope.h"



void isotope::Init()
{
	ImGui::CreateContext();

	ImGui_ImplGlfw_InitForOpenGL(wind, true);
	ImGui_ImplOpenGL3_Init("#version 330");
}

void isotope::Render()
{
	
	UIrender();
}

void isotope::Delete()
{

}

void isotope::UIrender()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();



	ImGui::Begin("hi");
	ImGui::End();




	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}


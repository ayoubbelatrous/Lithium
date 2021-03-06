#include "isotope.h"
#include "imguizmo/ImGuizmo.h"


static double offset;
void ScrollCalback(GLFWwindow* window, double xoffset, double yoffset)
{
	offset = yoffset;
}

void isotope::Init()
{

	scene = CreateRef<Scene>();
	scenePyramid.Init(scene);
	inspector.Init(scene);
	entity = scene->CreateEntity();
	entity2 = scene->CreateEntity();
	
	scenePyramid.selection = entity;
	entity.AddComponent<TransformComponent>();
	entity.AddComponent<SpriteRendererComponent>(glm::vec4(1.0));

	entity2.AddComponent<TransformComponent>();
	entity2.AddComponent<TagComponent>("hello");
	entity2.AddComponent<SpriteRendererComponent>(glm::vec4(1.0));
	entity.AddComponent<TagComponent>("lolo");
	ImGui::CreateContext();
	glfwSwapInterval(0);
	glfwSetScrollCallback(wind, ScrollCalback);
	ImGuiIO& io = ImGui::GetIO();

	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
//io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
	io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable Multi-Viewport / Platform Windows
	//io.ConfigViewportsNoAutoMerge = true;
	//io.ConfigViewportsNoTaskBarIcon = true;

	ImGui_ImplGlfw_InitForOpenGL(wind, true);
	ImGui_ImplOpenGL3_Init("#version 330");
	ImGuiStyle* style = &ImGui::GetStyle();

	
	style->WindowPadding = ImVec2(15, 15);
	style->WindowRounding = 5.0f;
	style->FramePadding = ImVec2(5, 5);
	style->FrameRounding = 4.0f;
	style->ItemSpacing = ImVec2(12, 8);
	style->ItemInnerSpacing = ImVec2(8, 6);
	style->IndentSpacing = 25.0f;
	style->ScrollbarSize = 20.0f;
	style->ScrollbarRounding = 9.0f;
	style->GrabMinSize = 5.0f;
	style->GrabRounding = 3.0f;
	style->TabRounding = 3.0f;
	
	style->Colors[ImGuiCol_Text] = ImVec4(1.0f, 1.0f, 1.0f, 1.00f);
	style->Colors[ImGuiCol_TextDisabled] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
	style->Colors[ImGuiCol_WindowBg] = ImVec4(0.05f, 0.05, 0.05, 1.0f);
	style->Colors[ImGuiCol_PopupBg] = ImVec4(0.07f, 0.07f, 0.09f, 1.00f);
	style->Colors[ImGuiCol_Border] = ImVec4(0.80f, 0.80f, 0.83f, 0.88f);
	style->Colors[ImGuiCol_BorderShadow] = ImVec4(0.92f, 0.91f, 0.88f, 0.00f);
	style->Colors[ImGuiCol_FrameBg] = ImVec4(0.12f, 0.12f, 0.12f, 1.00f);
	style->Colors[ImGuiCol_FrameBgHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
	style->Colors[ImGuiCol_FrameBgActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style->Colors[ImGuiCol_TitleBg] = ImVec4(0.09f, 0.09f, 0.12f, 1.00f);
	style->Colors[ImGuiCol_TitleBgCollapsed] = ImVec4(1.00f, 0.98f, 0.95f, 0.75f);
	style->Colors[ImGuiCol_TitleBgActive] = ImVec4(0.25f, 0.25f, 0.25f,1.0f);
	style->Colors[ImGuiCol_MenuBarBg] = ImVec4(0.15f, 0.15f, 0.15f, 1.00f);
	style->Colors[ImGuiCol_ScrollbarBg] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style->Colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
	style->Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style->Colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);

	style->Colors[ImGuiCol_CheckMark] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
	style->Colors[ImGuiCol_SliderGrab] = ImVec4(0.80f, 0.80f, 0.83f, 0.31f);
	style->Colors[ImGuiCol_SliderGrabActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	style->Colors[ImGuiCol_Button] = ImVec4(0.10f, 0.09f, 0.12f, 1.00f);
	style->Colors[ImGuiCol_ButtonHovered] = ImVec4(0.24f, 0.23f, 0.29f, 1.00f);
	style->Colors[ImGuiCol_ButtonActive] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style->Colors[ImGuiCol_Header] = ImVec4(0.1f, 0.1f, 0.1f, 1.00f);
	style->Colors[ImGuiCol_HeaderHovered] = ImVec4(0.30f, 0.30f, 0.30f, 1.00f);
	style->Colors[ImGuiCol_HeaderActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);
	style->Colors[ImGuiCol_ResizeGrip] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
	style->Colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.56f, 0.56f, 0.58f, 1.00f);
	style->Colors[ImGuiCol_ResizeGripActive] = ImVec4(0.06f, 0.05f, 0.07f, 1.00f);

	style->Colors[ImGuiCol_PlotLines] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
	style->Colors[ImGuiCol_PlotLinesHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
	style->Colors[ImGuiCol_PlotHistogram] = ImVec4(0.40f, 0.39f, 0.38f, 0.63f);
	style->Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(0.25f, 1.00f, 0.00f, 1.00f);
	style->Colors[ImGuiCol_TextSelectedBg] = ImVec4(0.45f, 0.45f, 0.45f, 0.43f);


	io.Fonts->AddFontFromFileTTF("src/Fonts/OpenSans-Regular.ttf", 18);
	io.Fonts->AddFontFromFileTTF("src/Fonts/OpenSans-Bold.ttf", 18);
	static ImGuiID dockspaceID = 0;


	/*float positions[] =
	{ -0.5f ,-0.5f ,0.0f, 0.0f,
		0.5f,-0.5f ,1.0f, 0.0f,
		0.5f ,0.5f ,1.0f, 1.0f,
		-0.5f,0.5f ,0.0f, 1.0f,
	};*/
	/*
	float positions[] = {
	  -0.5f, -0.5f, 0.0f, 0.0f, // 0
	   0.5f, -0.5f, 1.0f, 0.0f, // 1
	   0.5f,  0.5f, 1.0f, 1.0f, // 2
	  -0.5f,  0.5f, 0.0f, 1.0f
	};
	unsigned int index[] = {
		0, 1, 2,
		2, 3, 0
	};

	va = CreateRef<VertexArray>();
	lay = CreateRef<VertexBufferLayout>();

	lay->Push<float>(2);
	lay->Push<float>(2);

	buf = CreateRef<VertexBuffer>(positions, sizeof(positions));
	ibuf = CreateRef<IndexBuffer>(index,sizeof(index) / 4);
	tex = CreateRef<Texture>(1,1);
	unsigned int white = 0xffffffff;

	tex->SetData(&white);
	va->Bind();
	
	
	buf->Bind();
	va->AddBuffer(*buf, *lay);
	
	fb = Lithium::CreateRef<FrameBuffer>();
	fb->Bind();
	shader = Lithium::CreateRef<Shader>("src/shaders/main.shader");

	shader->Bind();

	
	
	shader->SetUniform1i("u_texture", 0);*/
	view = glm::translate(glm::mat4(1), glm::vec3(0));
	Renderer2D::Init();
	fb = Lithium::CreateRef<FrameBuffer>();
	fb->Bind();
	zoomStep = 0.25f;
}

void isotope::Render()
{	

	
	float aspect = width / height;
	
	size += offset * zoomStep * -1;
	offset = 0;
	float orthoLeft = -size * aspect * 0.5f;
	float orthoRight = size * aspect * 0.5f;
	float orthoBottom = -size * 0.5f;
	float orthoTop = size * 0.5f;


	if (prevsize.x != width || prevsize.y != height)
	{
		fb->resize(width, height);
		prevsize = ImVec2(width, height);
	}
	
	proj = glm::ortho(orthoLeft, orthoRight, orthoBottom, orthoTop);
	MVP = proj * view * entity.GetComponent<TransformComponent>().GetMatrix();

	fb->Bind();
	Renderer::ClearColor(glm::vec4(0.2, 0.2, 0.5, 1.0));
	Renderer::Clear();
	Renderer2D::BeginScene(proj, view);



	Renderer2D::DrawQuad(entity.GetComponent<TransformComponent>().GetMatrix(), (entity.GetComponent<SpriteRendererComponent>().GetColor()));
	Renderer2D::DrawQuad(entity2.GetComponent<TransformComponent>().GetMatrix(), (entity2.GetComponent<SpriteRendererComponent>().GetColor()));

    Renderer2D::EndScene();
	fb->UnBind();
}

void isotope::Delete()
{
	
}

void isotope::UIrender()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
	

	static bool opt_fullscreen = true;
	static bool opt_padding = false;
	static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;
	// We are using the ImGuiWindowFlags_NoDocking flag to make the parent window not dockable into,
	// because it would be confusing to have two docking targets within each others.
	ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
	if (opt_fullscreen)
	{
		const ImGuiViewport* viewport = ImGui::GetMainViewport();
		ImGui::SetNextWindowPos(viewport->WorkPos);
		ImGui::SetNextWindowSize(viewport->WorkSize);
		ImGui::SetNextWindowViewport(viewport->ID);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
		window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
		window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
	}
	else
	{
		dockspace_flags &= ~ImGuiDockNodeFlags_PassthruCentralNode;
	}
	// When using ImGuiDockNodeFlags_PassthruCentralNode, DockSpace() will render our background
	// and handle the pass-thru hole, so we ask Begin() to not render a background.
	if (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode)
		window_flags |= ImGuiWindowFlags_NoBackground;
	// Important: note that we proceed even if Begin() returns false (aka window is collapsed).
	// This is because we want to keep our DockSpace() active. If a DockSpace() is inactive,
	// all active windows docked into it will lose their parent and become undocked.
	// We cannot preserve the docking relationship between an active window and an inactive docking, otherwise
	// any change of dockspace/settings would lead to windows being stuck in limbo and never being visible.
	if (!opt_padding)
		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
	ImGui::Begin("DockSpace Demo", (bool*)true, window_flags);
	if (!opt_padding)
		ImGui::PopStyleVar();
	if (opt_fullscreen)
		ImGui::PopStyleVar(2);
	// Submit the DockSpace
	ImGuiIO& io = ImGui::GetIO();
	if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
	{
		ImGuiID dockspace_id = ImGui::GetID("DockSpace");
		ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
	}
	ImGui::End();


	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, { 0,0 });
	ImGui::Begin("Scene");
	ImVec2 vec = ImGui::GetContentRegionAvail();
	width = vec.x;
	height = vec.y;




	viewportSize = glm::vec2(ImGui::GetContentRegionAvail().x, ImGui::GetContentRegionAvail().y);


	ImGui::Image((void*)(intptr_t)fb->GetColorAttachmentID(), ImVec2(viewportSize.x, viewportSize.y), ImVec2{ 0, 1 }, ImVec2{ 1, 0 });

	ImVec2 viewportMinRegion = ImGui::GetWindowContentRegionMin();
	ImVec2 viewportMaxRegion = ImGui::GetWindowContentRegionMax();
	ImVec2 viewportOffset = ImGui::GetWindowPos();
	m_ViewportBounds[0] = { viewportMinRegion.x + viewportOffset.x, viewportMinRegion.y + viewportOffset.y };
	m_ViewportBounds[1] = { viewportMaxRegion.x + viewportOffset.x, viewportMaxRegion.y + viewportOffset.y };



	glm::mat4 _view = view;
	glm::mat4 _proj = proj;
	
	glm::mat4 matri = scenePyramid.selection.GetComponent<TransformComponent>().GetMatrix();

	ImGuizmo::SetGizmoSizeClipSpace(0.2f);
	ImGuizmo::SetOrthographic(true);
	ImGuizmo::SetDrawlist();

	ImGuizmo::SetRect(m_ViewportBounds[0].x, m_ViewportBounds[0].y, m_ViewportBounds[1].x - m_ViewportBounds[0].x, m_ViewportBounds[1].y - m_ViewportBounds[0].y);
	ImGuizmo::Manipulate(glm::value_ptr(_view), glm::value_ptr(_proj),
		(ImGuizmo::OPERATION)ImGuizmo::OPERATION::TRANSLATE, ImGuizmo::WORLD, glm::value_ptr(matri));

	if (ImGuizmo::IsUsing())
	{
		
		scenePyramid.selection.GetComponent<TransformComponent>().Position = matri[3];
		
	}


	ImGui::End();


	ImGui::Begin("Stats");
	ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);

	ImGui::DragFloat3("Position", glm::value_ptr(entity.GetComponent<TransformComponent>().Position),0.01f);
	ImGui::DragFloat3("Rotation", glm::value_ptr(entity.GetComponent<TransformComponent>().Rotation), 0.01f);
	ImGui::DragFloat3("Scale", glm::value_ptr(entity.GetComponent<TransformComponent>().Scale), 0.01f);


	ImGui::End();
	ImGui::PopStyleVar();

	scenePyramid.RenderUI();
	inspector.SetSelection(scenePyramid.selection);
	inspector.RenderUI();
	


	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	

	if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
	{
		GLFWwindow* backup_current_context = glfwGetCurrentContext();
		ImGui::UpdatePlatformWindows();
		ImGui::RenderPlatformWindowsDefault();
		glfwMakeContextCurrent(backup_current_context);
	}

}
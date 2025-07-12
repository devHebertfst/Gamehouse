#include <stdio.h>
#include <vector>
#include <string>
#include <cstdarg>

// --- Includes do Dear ImGui ---
#include "imgui.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"

// --- Includes de Gráficos ---
#include <GLFW/glfw3.h> 

extern "C" {
    #include "GameHouse.h"
}

std::vector<std::string> event_log;

void Log(const char* fmt, ...) {
    char buf[1024];
    va_list args;
    va_start(args, fmt);
    vsnprintf(buf, IM_ARRAYSIZE(buf), fmt, args);
    va_end(args);
    event_log.push_back(buf);
}

const char* get_status_cliente_str(GameHouse__STATUS_CLIENTE s) {
    switch (s) {
        case GameHouse__ativo: return "Ativo";
        case GameHouse__inativo: return "Inativo";
        case GameHouse__em_espera: return "Em Espera";
        default: return "Desconhecido";
    }
}
const char* get_status_dispositivo_str(GameHouse__STATUS_DISPOSITIVO s) {
    switch (s) {
        case GameHouse__disponivel: return "Disponível";
        case GameHouse__em_uso: return "Em Uso";
        case GameHouse__manutencao: return "Manutenção";
        default: return "Desconhecido";
    }
}

void DrawAdminPanel() {
    ImGui::Begin("Painel de Administração");

    ImGui::Text("Adicionar Entidades");
    ImGui::Separator();
    static int tipo_id = 1, jogo_id = 1, disp_id = 1, cli_id = 1;
    static int tipo_id_para_jogo = 1, tipo_id_para_disp = 1;
    bool ok;

    ImGui::InputInt("ID do Tipo", &tipo_id);
    if (ImGui::Button("Adicionar Tipo")) {
        GameHouse__pre_add_tipo_dispositivo(tipo_id, &ok);
        if (ok) { GameHouse__add_tipo_dispositivo(tipo_id); Log("SUCESSO: Tipo %d adicionado.", tipo_id); tipo_id++; }
        else { Log("FALHA: Tipo %d já existe.", tipo_id); }
    }
    ImGui::SameLine();
    if (ImGui::Button("Remover Tipo")) {
        GameHouse__pre_remove_tipo_dispositivo(tipo_id, &ok);
        if(ok) { GameHouse__remove_tipo_dispositivo(tipo_id); Log("SUCESSO: Tipo %d removido.", tipo_id); }
        else { Log("FALHA: Tipo %d não pode ser removido (em uso?).", tipo_id); }
    }
    ImGui::Separator();

    ImGui::InputInt("ID do Jogo", &jogo_id);
    ImGui::InputInt("Tipo para Jogo", &tipo_id_para_jogo);
    if (ImGui::Button("Adicionar Jogo")) {
        GameHouse__pre_add_jogo(jogo_id, tipo_id_para_jogo, &ok);
        if (ok) { GameHouse__add_jogo(jogo_id, tipo_id_para_jogo); Log("SUCESSO: Jogo %d (tipo %d) adicionado.", jogo_id, tipo_id_para_jogo); jogo_id++; }
        else { Log("FALHA: Jogo %d já existe ou tipo é inválido.", jogo_id); }
    }
    ImGui::SameLine();
    if (ImGui::Button("Remover Jogo")) {
        GameHouse__pre_remover_jogo(jogo_id, &ok);
        if(ok) { GameHouse__remove_jogo(jogo_id); Log("SUCESSO: Jogo %d removido.", jogo_id); }
        else { Log("FALHA: Jogo %d não pode ser removido (em uso?).", jogo_id); }
    }
    ImGui::Separator();

    ImGui::InputInt("ID do Dispositivo", &disp_id);
    ImGui::InputInt("Tipo para Dispositivo", &tipo_id_para_disp);
    if (ImGui::Button("Adicionar Dispositivo")) {
        GameHouse__pre_add_dispositivo(disp_id, tipo_id_para_disp, &ok);
        if(ok) { GameHouse__add_dispositivo(disp_id, tipo_id_para_disp); Log("SUCESSO: Dispositivo %d (tipo %d) adicionado.", disp_id, tipo_id_para_disp); disp_id++; }
        else { Log("FALHA: Dispositivo %d já existe ou tipo é inválido.", disp_id); }
    }
    ImGui::SameLine();
    if (ImGui::Button("Remover Dispositivo")) {
        GameHouse__pre_remove_dispositivo(disp_id, &ok);
        if(ok) { GameHouse__remove_dispositivo(disp_id); Log("SUCESSO: Dispositivo %d removido.", disp_id); }
        else { Log("FALHA: Dispositivo %d não pode ser removido (em uso?).", disp_id); }
    }
    ImGui::Separator();

    ImGui::InputInt("ID do Cliente", &cli_id);
    if (ImGui::Button("Adicionar Cliente")) {
        GameHouse__pre_add_cliente(cli_id, &ok);
        if (ok) { GameHouse__add_cliente(cli_id); Log("SUCESSO: Cliente %d adicionado.", cli_id); cli_id++; }
        else { Log("FALHA: Cliente %d já existe ou limite atingido.", cli_id); }
    }

    ImGui::End();
}

void DrawClientsPanel() {
    ImGui::Begin("Painel de Clientes");
    if (ImGui::BeginTable("tabela_clientes", 4, ImGuiTableFlags_Borders | ImGuiTableFlags_RowBg | ImGuiTableFlags_SizingFixedFit)) {
        ImGui::TableSetupColumn("ID"); ImGui::TableSetupColumn("Créditos"); ImGui::TableSetupColumn("Status"); ImGui::TableSetupColumn("Ações");
        ImGui::TableHeadersRow();
        bool more;
        GameHouse__init_clientes_info();
        GameHouse__has_more_clientes_info(&more);
        while(more) {
            GameHouse__CLIENTES cc; GameHouse__STATUS_CLIENTE ss; int32_t cr;
            GameHouse__get_next_cliente_info(&cc, &ss, &cr);
            ImGui::TableNextRow(); ImGui::PushID(cc);
            ImGui::TableSetColumnIndex(0); ImGui::Text("%d", cc);
            ImGui::TableSetColumnIndex(1); ImGui::Text("%d", cr);
            ImGui::TableSetColumnIndex(2); ImGui::Text("%s", get_status_cliente_str(ss));
            ImGui::TableSetColumnIndex(3);
            static int creditos_a_comprar = 10;
            ImGui::SetNextItemWidth(80); ImGui::InputInt("##cred", &creditos_a_comprar, 0); ImGui::SameLine();
            if (ImGui::Button("Comprar")) {
                bool ok; GameHouse__pre_comprar_creditos(cc, creditos_a_comprar, &ok);
                if(ok) { GameHouse__comprar_creditos(cc, creditos_a_comprar); Log("Cliente %d comprou %d créditos.", cc, creditos_a_comprar); }
                else { Log("FALHA: Cliente %d não pôde comprar.", cc); }
            } ImGui::SameLine();
            if (ImGui::Button("Banir")) {
                bool ok; GameHouse__pre_banir_cliente(cc, &ok);
                if(ok) { GameHouse__banir_cliente(cc); Log("SUCESSO: Cliente %d banido.", cc); }
                else { Log("FALHA: Cliente %d não pôde ser banido (em sessão?).", cc); }
            } ImGui::PopID();
            GameHouse__has_more_clientes_info(&more);
        } ImGui::EndTable();
    } ImGui::End();
}

void DrawDevicesPanel() {
    ImGui::Begin("Painel de Dispositivos");
    bool more_dev;
    GameHouse__init_devices_info();
    GameHouse__has_more_devices_info(&more_dev);
    while(more_dev) {
        GameHouse__DISPOSITIVOS dd; GameHouse__TIPOS_DISPOSITIVO td; GameHouse__STATUS_DISPOSITIVO ss;
        GameHouse__get_next_device_info(&dd, &td, &ss);
        
        if (ImGui::CollapsingHeader(("Dispositivo " + std::to_string(dd)).c_str())) {
            ImGui::PushID(dd);
            ImGui::Text("Tipo: %d", td);
            
            // Mudar Status do Dispositivo
            const char* items[] = { "Disponível", "Em Uso", "Manutenção" };
            int current_status_idx = (int)ss;
            if (ImGui::Combo("Status", &current_status_idx, items, IM_ARRAYSIZE(items))) {
                bool ok;
                GameHouse__STATUS_DISPOSITIVO novo_status = (GameHouse__STATUS_DISPOSITIVO)current_status_idx;
                GameHouse__pre_set_status_dispositivo(dd, novo_status, &ok);
                if(ok) {
                    GameHouse__set_status_dispositivo(dd, novo_status);
                    Log("Status do disp %d alterado para %s.", dd, items[current_status_idx]);
                } else {
                    Log("FALHA: Não foi possível alterar o status do disp %d.", dd);
                }
            }
            
            ImGui::Separator();
            ImGui::Text("Jogos Instalados:");
            bool more_games; GameHouse__init_jogos_dispositivo(); GameHouse__has_more_jogos_dispositivo(dd, &more_games);
            if (!more_games) { ImGui::Text("  (Nenhum)");}
            while(more_games) {
                GameHouse__JOGOS jj; GameHouse__get_next_jogo_dispositivo(dd, &jj);
                ImGui::Text("  - Jogo %d", jj);
                ImGui::SameLine();
                ImGui::PushID(jj);
                if (ImGui::Button("Desinstalar")) {
                    bool ok;
                    GameHouse__pre_desinstalar_jogo(dd, jj, &ok);
                    if(ok) { GameHouse__desinstalar_jogo(dd, jj); Log("Jogo %d desinstalado do disp %d.", jj, dd); }
                    else { Log("FALHA: Jogo %d não pôde ser desinstalado.", jj); }
                }
                ImGui::PopID();
                GameHouse__has_more_jogos_dispositivo(dd, &more_games);
            }

            ImGui::Separator();
            ImGui::Text("Ações do Dispositivo:");
            static int jogo_a_instalar = 1;
            ImGui::SetNextItemWidth(100); ImGui::InputInt("ID Jogo", &jogo_a_instalar, 0); ImGui::SameLine();
            if (ImGui::Button("Instalar Jogo")) {
                 bool ok; GameHouse__pre_instalar_jogo(dd, jogo_a_instalar, &ok);
                 if(ok) { GameHouse__instalar_jogo(dd, jogo_a_instalar); Log("Jogo %d inst. no disp %d.", jogo_a_instalar, dd); }
                 else { Log("FALHA: Jogo %d incompatível/instalado no disp %d.", jogo_a_instalar, dd); }
            } ImGui::SameLine();
            if(ss == GameHouse__disponivel && ImGui::Button("Iniciar Sessão da Fila")) {
                bool ok; GameHouse__pre_iniciar_sessao(dd, &ok);
                if(ok) { GameHouse__iniciar_sessao_fila(dd); Log("Sessão iniciada no disp %d.", dd); }
                else { Log("FALHA: Ninguém na fila para o disp %d.", dd); }
            }
            ImGui::PopID();
        }
        GameHouse__has_more_devices_info(&more_dev);
    }
    ImGui::End();
}

void DrawPlayerActionsPanel() {
    ImGui::Begin("Ações do Jogador");
    static int cliente_id_acao = 1, dispositivo_id_acao = 1, jogo_id_acao = 1;
    ImGui::InputInt("Meu ID Cliente", &cliente_id_acao);
    ImGui::Separator();
    
    ImGui::Text("Ações de Fila");
    ImGui::InputInt("ID Dispositivo", &dispositivo_id_acao);
    ImGui::InputInt("ID Jogo", &jogo_id_acao);
    if (ImGui::Button("Entrar na Fila")) {
        bool ok; GameHouse__pre_entrar_fila_dispositivo(cliente_id_acao, dispositivo_id_acao, jogo_id_acao, &ok);
        if(ok) { GameHouse__entrar_fila_dispositivo(cliente_id_acao, dispositivo_id_acao, jogo_id_acao); Log("Cliente %d entrou na fila do disp %d.", cliente_id_acao, dispositivo_id_acao); }
        else { Log("FALHA: Cliente %d não pôde entrar na fila.", cliente_id_acao); }
    } ImGui::SameLine();
    if (ImGui::Button("Sair da Fila")) {
        bool ok; GameHouse__pre_sair_fila_dispositivo(cliente_id_acao, dispositivo_id_acao, &ok);
        if(ok) { GameHouse__sair_fila_dispositivo(cliente_id_acao, dispositivo_id_acao); Log("Cliente %d saiu da fila do disp %d.", cliente_id_acao, dispositivo_id_acao); }
        else { Log("FALHA: Cliente %d não está na fila do disp %d.", cliente_id_acao, dispositivo_id_acao); }
    }
    ImGui::Separator();

    ImGui::Text("Ações de Sessão");
    if (ImGui::Button("Encerrar Minha Sessão")) {
        bool ok; GameHouse__pre_encerrar_sessao(cliente_id_acao, &ok);
        if(ok) { GameHouse__encerrar_sessao(cliente_id_acao); Log("Cliente %d encerrou sua sessão.", cliente_id_acao); }
        else { Log("FALHA: Cliente %d não está em sessão.", cliente_id_acao); }
    }
    ImGui::End();
}

void DrawLogPanel() {
    ImGui::Begin("Log de Eventos");
    if (ImGui::Button("Limpar Log")) { event_log.clear(); }
    ImGui::SameLine();
    ImGui::Text("Total de eventos: %zu", event_log.size());
    ImGui::Separator();
    ImGui::BeginChild("scrolling", ImVec2(0, 0), false, ImGuiWindowFlags_HorizontalScrollbar);
    for (const auto& item : event_log) { ImGui::TextUnformatted(item.c_str()); }
    if (ImGui::GetScrollY() >= ImGui::GetScrollMaxY()) ImGui::SetScrollHereY(1.0f);
    ImGui::EndChild();
    ImGui::End();
}

int main(int, char**) {
    if (!glfwInit()) return 1;
    const char* glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    GLFWwindow* window = glfwCreateWindow(1280, 720, "Painel de Testes GameHouse", NULL, NULL);
    if (window == NULL) {
        const char* description;
        glfwGetError(&description);
        fprintf(stderr, "Falha ao criar janela GLFW: %s\n", description);
        return 1;
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);
    
    GameHouse__INITIALISATION();
    Log("Sistema GameHouse Inicializado.");

    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        
        ImGuiViewport* viewport = ImGui::GetMainViewport();
        ImGui::SetNextWindowPos(viewport->Pos);
        ImGui::SetNextWindowSize(viewport->Size);
        ImGui::SetNextWindowViewport(viewport->ID);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
        ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
        ImGuiWindowFlags window_flags = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize;
        window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;
        ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
        ImGui::Begin("DockSpace Principal", NULL, window_flags);
        ImGui::PopStyleVar(3);
        ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
        ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), ImGuiDockNodeFlags_None);
        ImGui::End();

        DrawAdminPanel();
        DrawClientsPanel();
        DrawDevicesPanel();
        DrawPlayerActionsPanel();
        DrawLogPanel();

        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.1f, 0.1f, 0.12f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(window);
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
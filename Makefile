# Makefile Definitivo e Corrigido para GameHouse GUI em Arch Linux

# Compiladores
CXX := g++
CC := gcc

# Nome do executável final
EXE := gamehouse_gui

# ==============================================================================
# Flags de Compilação e Linkagem
# ==============================================================================

# Flags para o compilador: onde procurar headers (.h)
# -I. (raiz), -Iimgui (para imgui.h), e -Iimgui/backends (para os headers de implementação)
# Removido -Isrc que não existe.
CPPFLAGS := -I. -Iimgui -std=c++11 `pkg-config --cflags glfw3`

# Flags para o linker: quais bibliotecas usar
LDFLAGS := `pkg-config --libs glfw3` -lGL

# ==============================================================================
# Lista de Arquivos-Objeto com os Caminhos Corretos
# ==============================================================================

# Listamos explicitamente todos os arquivos .o com seus caminhos corretos.
OBJS := \
    main.o \
    GameHouse.o \
    imgui/imgui.o \
    imgui/imgui_draw.o \
    imgui/imgui_tables.o \
    imgui/imgui_widgets.o \
    imgui/backends/imgui_impl_glfw.o \
    imgui/backends/imgui_impl_opengl3.o

# ==============================================================================
# REGRAS DE COMPILAÇÃO
# ==============================================================================

# Regra principal: o que fazer quando você digita "make"
all: $(EXE)

# Regra para linkar: como criar o executável a partir dos arquivos-objeto
$(EXE): $(OBJS)
	$(CXX) $(OBJS) -o $(EXE) $(LDFLAGS)
	@echo "Compilação finalizada com sucesso! Execute com ./${EXE}"

# --- Regras Explícitas para cada arquivo-objeto ---

# Para arquivos na raiz do projeto
main.o: main.cpp imgui/imgui.h GameHouse.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

GameHouse.o: GameHouse.c GameHouse.h GameHouse_ctx.h
	$(CC) $(CPPFLAGS) -c $< -o $@

# Para arquivos na pasta imgui/
imgui/imgui.o: imgui/imgui.cpp imgui/imgui.h imgui/imconfig.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

imgui/imgui_draw.o: imgui/imgui_draw.cpp imgui/imgui.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

imgui/imgui_tables.o: imgui/imgui_tables.cpp imgui/imgui.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

imgui/imgui_widgets.o: imgui/imgui_widgets.cpp imgui/imgui.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

# CORREÇÃO PRINCIPAL AQUI: As regras para os backends agora usam o caminho correto
imgui/backends/imgui_impl_glfw.o: imgui/backends/imgui_impl_glfw.cpp imgui/backends/imgui_impl_glfw.h
	$(CXX) $(CPPFLAGS) -c $< -o $@

imgui/backends/imgui_impl_opengl3.o: imgui/backends/imgui_impl_opengl3.cpp imgui/backends/imgui_impl_opengl3.h
	$(CXX) $(CPPFLAGS) -c $< -o $@


# Regra para limpar os arquivos gerados
clean:
	rm -f $(OBJS) $(EXE)

# Diz ao make que 'all' e 'clean' não são nomes de arquivos reais
.PHONY: all clean
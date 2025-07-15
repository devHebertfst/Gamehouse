Para compilar e executar o projeto, é necessário ter o CMake instalado e, no caso do Windows, utilizar o WSL
sudo apt update && sudo apt install build-essential cmake git libglfw3-dev libglfw3 libgl1-mesa-dev libx11-dev pkg-config
sudo apt install build-essential
git clone --branch docking --single-branch https://github.com/ocornut/imgui.git
make
./gamehouse_gui
/* WARNING if type checker is not performed, translation could contain errors ! */

#include "GameHouse.h"

/* Clause CONCRETE_CONSTANTS */
/* Basic constants */

#define GameHouse__TIPOS_DISPOSITIVO_UB 4
#define GameHouse__DISPOSITIVOS_UB 11
#define GameHouse__JOGOS_UB 34
#define GameHouse__JOGOS_POR_DISPOSITIVO_UB 4
#define GameHouse__CLIENTES_UB 29
#define GameHouse__SESSOES_UB 11
#define GameHouse__ENTRADAS_FILA_UB 6
/* Array and record constants */
/* Clause CONCRETE_VARIABLES */

static int32_t GameHouse__tiposDispositivos_arr[GameHouse__TIPOS_DISPOSITIVO_UB+1];
static int32_t GameHouse__tiposDispositivos_hwm;
static int32_t GameHouse__dispositivos_arr[GameHouse__DISPOSITIVOS_UB+1];
static int32_t GameHouse__tipoDispositivo_arr[GameHouse__DISPOSITIVOS_UB+1];
static GameHouse__STATUS_DISPOSITIVO GameHouse__statusDispositivo_arr[GameHouse__DISPOSITIVOS_UB+1];
static int32_t GameHouse__dispositivos_hwm;
static int32_t GameHouse__jogos_arr[GameHouse__JOGOS_UB+1];
static int32_t GameHouse__tipoJogo_arr[GameHouse__JOGOS_UB+1];
static int32_t GameHouse__jogos_hwm;
static int32_t GameHouse__jogosDispositivo_d_arr[GameHouse__JOGOS_POR_DISPOSITIVO_UB+1];
static int32_t GameHouse__jogosDispositivo_j_arr[GameHouse__JOGOS_POR_DISPOSITIVO_UB+1];
static int32_t GameHouse__jogosDispositivo_hwm;
static int32_t GameHouse__clientes_arr[GameHouse__CLIENTES_UB+1];
static GameHouse__STATUS_CLIENTE GameHouse__statusCliente_arr[GameHouse__CLIENTES_UB+1];
static int32_t GameHouse__creditosCliente_arr[GameHouse__CLIENTES_UB+1];
static int32_t GameHouse__clientes_hwm;
static int32_t GameHouse__sessao_c_arr[GameHouse__SESSOES_UB+1];
static int32_t GameHouse__sessao_d_arr[GameHouse__SESSOES_UB+1];
static int32_t GameHouse__sessao_j_arr[GameHouse__SESSOES_UB+1];
static int32_t GameHouse__sessao_hwm;
static int32_t GameHouse__fila_d_arr[GameHouse__ENTRADAS_FILA_UB+1];
static int32_t GameHouse__fila_c_arr[GameHouse__ENTRADAS_FILA_UB+1];
static int32_t GameHouse__fila_j_arr[GameHouse__ENTRADAS_FILA_UB+1];
static int32_t GameHouse__fila_hwm;
static int32_t GameHouse__disp_disponiveis_iterator;
static int32_t GameHouse__jogos_por_tipo_iterator;
static int32_t GameHouse__jogos_dispositivo_iterator;
static int32_t GameHouse__clientes_info_iterator;
static int32_t GameHouse__tipos_disponiveis_iterator;
static int32_t GameHouse__devices_info_iterator;
/* Clause INITIALISATION */
void GameHouse__INITIALISATION(void)
{
    
    unsigned int i = 0;
    GameHouse__tiposDispositivos_hwm = 0;
    GameHouse__dispositivos_hwm = 0;
    GameHouse__jogos_hwm = 0;
    GameHouse__jogosDispositivo_hwm = 0;
    GameHouse__clientes_hwm = 0;
    GameHouse__sessao_hwm = 0;
    GameHouse__fila_hwm = 0;
    for(i = 0; i <= GameHouse__TIPOS_DISPOSITIVO_UB;i++)
    {
        GameHouse__tiposDispositivos_arr[i] = 1;
    }
    for(i = 0; i <= GameHouse__DISPOSITIVOS_UB;i++)
    {
        GameHouse__dispositivos_arr[i] = 1;
    }
    for(i = 0; i <= GameHouse__DISPOSITIVOS_UB;i++)
    {
        GameHouse__tipoDispositivo_arr[i] = 1;
    }
    for(i = 0; i <= GameHouse__DISPOSITIVOS_UB;i++)
    {
        GameHouse__statusDispositivo_arr[i] = GameHouse__disponivel;
    }
    for(i = 0; i <= GameHouse__JOGOS_UB;i++)
    {
        GameHouse__jogos_arr[i] = 1;
    }
    for(i = 0; i <= GameHouse__JOGOS_UB;i++)
    {
        GameHouse__tipoJogo_arr[i] = 1;
    }
    for(i = 0; i <= GameHouse__JOGOS_POR_DISPOSITIVO_UB;i++)
    {
        GameHouse__jogosDispositivo_d_arr[i] = 1;
    }
    for(i = 0; i <= GameHouse__JOGOS_POR_DISPOSITIVO_UB;i++)
    {
        GameHouse__jogosDispositivo_j_arr[i] = 1;
    }
    for(i = 0; i <= GameHouse__CLIENTES_UB;i++)
    {
        GameHouse__clientes_arr[i] = 1;
    }
    for(i = 0; i <= GameHouse__CLIENTES_UB;i++)
    {
        GameHouse__statusCliente_arr[i] = GameHouse__inativo;
    }
    for(i = 0; i <= GameHouse__CLIENTES_UB;i++)
    {
        GameHouse__creditosCliente_arr[i] = 0;
    }
    for(i = 0; i <= GameHouse__SESSOES_UB;i++)
    {
        GameHouse__sessao_c_arr[i] = 1;
    }
    for(i = 0; i <= GameHouse__SESSOES_UB;i++)
    {
        GameHouse__sessao_d_arr[i] = 1;
    }
    for(i = 0; i <= GameHouse__SESSOES_UB;i++)
    {
        GameHouse__sessao_j_arr[i] = 1;
    }
    for(i = 0; i <= GameHouse__ENTRADAS_FILA_UB;i++)
    {
        GameHouse__fila_d_arr[i] = 1;
    }
    for(i = 0; i <= GameHouse__ENTRADAS_FILA_UB;i++)
    {
        GameHouse__fila_c_arr[i] = 1;
    }
    for(i = 0; i <= GameHouse__ENTRADAS_FILA_UB;i++)
    {
        GameHouse__fila_j_arr[i] = 1;
    }
    GameHouse__disp_disponiveis_iterator = 0;
    GameHouse__jogos_por_tipo_iterator = 0;
    GameHouse__jogos_dispositivo_iterator = 0;
    GameHouse__clientes_info_iterator = 0;
    GameHouse__clientes_info_iterator = 0;
    GameHouse__tipos_disponiveis_iterator = 0;
    GameHouse__tipos_disponiveis_iterator = 0;
    GameHouse__devices_info_iterator = 0;
}

/* Clause OPERATIONS */

void GameHouse__add_tipo_dispositivo(GameHouse__TIPOS_DISPOSITIVO td)
{
    GameHouse__tiposDispositivos_arr[GameHouse__tiposDispositivos_hwm] = td;
    GameHouse__tiposDispositivos_hwm = GameHouse__tiposDispositivos_hwm+1;
}

void GameHouse__remove_tipo_dispositivo(GameHouse__TIPOS_DISPOSITIVO td)
{
    {
        int32_t idx;
        int32_t ii;
        int32_t current_td;
        
        idx = -1;
        ii = 0;
        while(((ii) < (GameHouse__tiposDispositivos_hwm)) &&
        (idx == -1))
        {
            current_td = GameHouse__tiposDispositivos_arr[ii];
            if(current_td == td)
            {
                idx = ii;
            }
            ii = ii+1;
        }
        if((idx) != (-1))
        {
            GameHouse__tiposDispositivos_arr[idx] = GameHouse__tiposDispositivos_arr[GameHouse__tiposDispositivos_hwm-1];
            GameHouse__tiposDispositivos_hwm = GameHouse__tiposDispositivos_hwm-1;
        }
    }
}

void GameHouse__add_dispositivo(GameHouse__DISPOSITIVOS dd, GameHouse__TIPOS_DISPOSITIVO td)
{
    GameHouse__dispositivos_arr[GameHouse__dispositivos_hwm] = dd;
    GameHouse__tipoDispositivo_arr[GameHouse__dispositivos_hwm] = td;
    GameHouse__statusDispositivo_arr[GameHouse__dispositivos_hwm] = GameHouse__disponivel;
    GameHouse__dispositivos_hwm = GameHouse__dispositivos_hwm+1;
}

void GameHouse__remove_dispositivo(GameHouse__DISPOSITIVOS dd)
{
    int32_t idx;
    int32_t ii;
    int32_t jj;
    int32_t current_dd;
    int32_t current_jd_d;
    
    idx = -1;
    ii = 0;
    while(((ii) < (GameHouse__dispositivos_hwm)) &&
    (idx == -1))
    {
        current_dd = GameHouse__dispositivos_arr[ii];
        if(current_dd == dd)
        {
            idx = ii;
        }
        ii = ii+1;
    }
    if((idx) != (-1))
    {
        GameHouse__dispositivos_hwm = GameHouse__dispositivos_hwm-1;
        GameHouse__dispositivos_arr[idx] = GameHouse__dispositivos_arr[GameHouse__dispositivos_hwm];
        GameHouse__tipoDispositivo_arr[idx] = GameHouse__tipoDispositivo_arr[GameHouse__dispositivos_hwm];
        GameHouse__statusDispositivo_arr[idx] = GameHouse__statusDispositivo_arr[GameHouse__dispositivos_hwm];
    }
    jj = 0;
    while((jj) < (GameHouse__jogosDispositivo_hwm))
    {
        current_jd_d = GameHouse__jogosDispositivo_d_arr[jj];
        if(current_jd_d == dd)
        {
            GameHouse__jogosDispositivo_hwm = GameHouse__jogosDispositivo_hwm-1;
            GameHouse__jogosDispositivo_d_arr[jj] = GameHouse__jogosDispositivo_d_arr[GameHouse__jogosDispositivo_hwm];
            GameHouse__jogosDispositivo_j_arr[jj] = GameHouse__jogosDispositivo_j_arr[GameHouse__jogosDispositivo_hwm];
        }
        else
        {
            jj = jj+1;
        }
    }
}

void GameHouse__add_jogo(GameHouse__JOGOS jj, GameHouse__TIPOS_DISPOSITIVO td)
{
    GameHouse__jogos_arr[GameHouse__jogos_hwm] = jj;
    GameHouse__tipoJogo_arr[GameHouse__jogos_hwm] = td;
    GameHouse__jogos_hwm = GameHouse__jogos_hwm+1;
}

void GameHouse__remove_jogo(GameHouse__JOGOS jj)
{
    int32_t idx;
    int32_t ii;
    int32_t kk;
    int32_t current_j;
    int32_t current_jd_j;
    
    idx = -1;
    ii = 0;
    while(((ii) < (GameHouse__jogos_hwm)) &&
    (idx == -1))
    {
        current_j = GameHouse__jogos_arr[ii];
        if(current_j == jj)
        {
            idx = ii;
        }
        ii = ii+1;
    }
    if((idx) != (-1))
    {
        GameHouse__jogos_hwm = GameHouse__jogos_hwm-1;
        GameHouse__jogos_arr[idx] = GameHouse__jogos_arr[GameHouse__jogos_hwm];
        GameHouse__tipoJogo_arr[idx] = GameHouse__tipoJogo_arr[GameHouse__jogos_hwm];
    }
    kk = 0;
    while((kk) < (GameHouse__jogosDispositivo_hwm))
    {
        current_jd_j = GameHouse__jogosDispositivo_j_arr[kk];
        if(current_jd_j == jj)
        {
            GameHouse__jogosDispositivo_hwm = GameHouse__jogosDispositivo_hwm-1;
            GameHouse__jogosDispositivo_d_arr[kk] = GameHouse__jogosDispositivo_d_arr[GameHouse__jogosDispositivo_hwm];
            GameHouse__jogosDispositivo_j_arr[kk] = GameHouse__jogosDispositivo_j_arr[GameHouse__jogosDispositivo_hwm];
        }
        else
        {
            kk = kk+1;
        }
    }
}

void GameHouse__instalar_jogo(GameHouse__DISPOSITIVOS dd, GameHouse__JOGOS jj)
{
    GameHouse__jogosDispositivo_d_arr[GameHouse__jogosDispositivo_hwm] = dd;
    GameHouse__jogosDispositivo_j_arr[GameHouse__jogosDispositivo_hwm] = jj;
    GameHouse__jogosDispositivo_hwm = GameHouse__jogosDispositivo_hwm+1;
}

void GameHouse__desinstalar_jogo(GameHouse__DISPOSITIVOS dd, GameHouse__JOGOS jj)
{
    int32_t idx;
    int32_t ii;
    int32_t current_d;
    int32_t current_j;
    
    idx = -1;
    ii = 0;
    while(((ii) < (GameHouse__jogosDispositivo_hwm)) &&
    (idx == -1))
    {
        current_d = GameHouse__jogosDispositivo_d_arr[ii];
        current_j = GameHouse__jogosDispositivo_j_arr[ii];
        if((current_d == dd) &&
        (current_j == jj))
        {
            idx = ii;
        }
        ii = ii+1;
    }
    if((idx) != (-1))
    {
        GameHouse__jogosDispositivo_hwm = GameHouse__jogosDispositivo_hwm-1;
        GameHouse__jogosDispositivo_d_arr[idx] = GameHouse__jogosDispositivo_d_arr[GameHouse__jogosDispositivo_hwm];
        GameHouse__jogosDispositivo_j_arr[idx] = GameHouse__jogosDispositivo_j_arr[GameHouse__jogosDispositivo_hwm];
    }
}

void GameHouse__set_status_dispositivo(GameHouse__DISPOSITIVOS dd, GameHouse__STATUS_DISPOSITIVO ss)
{
    int32_t idx;
    int32_t ii;
    int32_t current_d;
    
    idx = -1;
    ii = 0;
    while(((ii) < (GameHouse__dispositivos_hwm)) &&
    (idx == -1))
    {
        current_d = GameHouse__dispositivos_arr[ii];
        if(current_d == dd)
        {
            idx = ii;
        }
        ii = ii+1;
    }
    if((idx) != (-1))
    {
        GameHouse__statusDispositivo_arr[idx] = ss;
    }
}

void GameHouse__add_cliente(GameHouse__CLIENTES cc)
{
    GameHouse__clientes_arr[GameHouse__clientes_hwm] = cc;
    GameHouse__statusCliente_arr[GameHouse__clientes_hwm] = GameHouse__inativo;
    GameHouse__creditosCliente_arr[GameHouse__clientes_hwm] = 0;
    GameHouse__clientes_hwm = GameHouse__clientes_hwm+1;
}

void GameHouse__banir_cliente(GameHouse__CLIENTES cc)
{
    int32_t idx;
    int32_t ii;
    int32_t current_c;
    
    idx = -1;
    ii = 0;
    while(((ii) < (GameHouse__clientes_hwm)) &&
    (idx == -1))
    {
        current_c = GameHouse__clientes_arr[ii];
        if(current_c == cc)
        {
            idx = ii;
        }
        ii = ii+1;
    }
    if((idx) != (-1))
    {
        GameHouse__clientes_hwm = GameHouse__clientes_hwm-1;
        GameHouse__clientes_arr[idx] = GameHouse__clientes_arr[GameHouse__clientes_hwm];
        GameHouse__statusCliente_arr[idx] = GameHouse__statusCliente_arr[GameHouse__clientes_hwm];
        GameHouse__creditosCliente_arr[idx] = GameHouse__creditosCliente_arr[GameHouse__clientes_hwm];
    }
}

void GameHouse__comprar_creditos(GameHouse__CLIENTES cc, int32_t qtd)
{
    int32_t idx;
    int32_t ii;
    int32_t current_c;
    int32_t current_creditos;
    
    idx = -1;
    ii = 0;
    while(((ii) < (GameHouse__clientes_hwm)) &&
    (idx == -1))
    {
        current_c = GameHouse__clientes_arr[ii];
        if(current_c == cc)
        {
            idx = ii;
        }
        ii = ii+1;
    }
    if((idx) != (-1))
    {
        current_creditos = GameHouse__creditosCliente_arr[idx];
        GameHouse__creditosCliente_arr[idx] = current_creditos+qtd;
    }
}

void GameHouse__init_disp_disponiveis(void)
{
    GameHouse__disp_disponiveis_iterator = 0;
}

void GameHouse__has_more_disp_disponiveis(bool *more)
{
    int32_t ii;
    bool found;
    GameHouse__STATUS_DISPOSITIVO current_status;
    
    ii = GameHouse__disp_disponiveis_iterator;
    found = false;
    while(((ii) < (GameHouse__dispositivos_hwm)) &&
    (found == false))
    {
        current_status = GameHouse__statusDispositivo_arr[ii];
        if(current_status == GameHouse__disponivel)
        {
            found = true;
        }
        ii = ii+1;
    }
    (*more) = found;
}

void GameHouse__get_next_disp_disponivel(GameHouse__DISPOSITIVOS *dd)
{
    int32_t ii;
    int32_t idx;
    bool found;
    GameHouse__STATUS_DISPOSITIVO current_status;
    
    ii = GameHouse__disp_disponiveis_iterator;
    idx = -1;
    found = false;
    while(((ii) < (GameHouse__dispositivos_hwm)) &&
    (found == false))
    {
        current_status = GameHouse__statusDispositivo_arr[ii];
        if(current_status == GameHouse__disponivel)
        {
            idx = ii;
            found = true;
        }
        ii = ii+1;
    }
    (*dd) = GameHouse__dispositivos_arr[idx];
    GameHouse__disp_disponiveis_iterator = idx+1;
}

void GameHouse__init_jogos_por_tipo(void)
{
    GameHouse__jogos_por_tipo_iterator = 0;
}

void GameHouse__has_more_jogos_por_tipo(GameHouse__TIPOS_DISPOSITIVO td, bool *more)
{
    int32_t ii;
    bool found;
    int32_t current_tipo;
    
    ii = GameHouse__jogos_por_tipo_iterator;
    found = false;
    while(((ii) < (GameHouse__jogos_hwm)) &&
    (found == false))
    {
        current_tipo = GameHouse__tipoJogo_arr[ii];
        if(current_tipo == td)
        {
            found = true;
        }
        ii = ii+1;
    }
    (*more) = found;
}

void GameHouse__init_jogos_dispositivo(void)
{
    GameHouse__jogos_dispositivo_iterator = 0;
}

void GameHouse__has_more_jogos_dispositivo(GameHouse__DISPOSITIVOS dd, bool *more)
{
    int32_t ii;
    bool found;
    int32_t current_disp;
    
    ii = GameHouse__jogos_dispositivo_iterator;
    found = false;
    while(((ii) < (GameHouse__jogosDispositivo_hwm)) &&
    (found == false))
    {
        current_disp = GameHouse__jogosDispositivo_d_arr[ii];
        if(current_disp == dd)
        {
            found = true;
        }
        ii = ii+1;
    }
    (*more) = found;
}

void GameHouse__get_next_jogo_dispositivo(GameHouse__DISPOSITIVOS dd, GameHouse__JOGOS *jj)
{
    int32_t ii;
    int32_t idx;
    bool found;
    int32_t current_disp;
    
    ii = GameHouse__jogos_dispositivo_iterator;
    idx = -1;
    found = false;
    while(((ii) < (GameHouse__jogosDispositivo_hwm)) &&
    (found == false))
    {
        current_disp = GameHouse__jogosDispositivo_d_arr[ii];
        if(current_disp == dd)
        {
            idx = ii;
            found = true;
        }
        ii = ii+1;
    }
    (*jj) = GameHouse__jogosDispositivo_j_arr[idx];
    GameHouse__jogos_dispositivo_iterator = idx+1;
}

void GameHouse__init_clientes_info(void)
{
    GameHouse__clientes_info_iterator = 0;
}

void GameHouse__has_more_clientes_info(bool *more)
{
    (*more) = (((GameHouse__clientes_info_iterator) < (GameHouse__clientes_hwm)) ? true : false);
}

void GameHouse__get_next_cliente_info(GameHouse__CLIENTES *cc, GameHouse__STATUS_CLIENTE *ss, int32_t *cr)
{
    int32_t idx;
    
    idx = GameHouse__clientes_info_iterator;
    (*cc) = GameHouse__clientes_arr[idx];
    (*ss) = GameHouse__statusCliente_arr[idx];
    (*cr) = GameHouse__creditosCliente_arr[idx];
    GameHouse__clientes_info_iterator = idx+1;
}

void GameHouse__get_next_jogo_por_tipo(GameHouse__TIPOS_DISPOSITIVO td, GameHouse__JOGOS *jj)
{
    int32_t ii;
    int32_t idx;
    bool found;
    int32_t current_tipo;
    
    ii = GameHouse__jogos_por_tipo_iterator;
    idx = -1;
    found = false;
    while(((ii) < (GameHouse__jogos_hwm)) &&
    (found == false))
    {
        current_tipo = GameHouse__tipoJogo_arr[ii];
        if(current_tipo == td)
        {
            idx = ii;
            found = true;
        }
        ii = ii+1;
    }
    (*jj) = GameHouse__jogos_arr[idx];
    GameHouse__jogos_por_tipo_iterator = idx+1;
}

void GameHouse__posicao_fila(GameHouse__CLIENTES cc, GameHouse__DISPOSITIVOS dd, int32_t *pp)
{
    int32_t ii;
    int32_t pos;
    bool achou;
    int32_t current_d;
    int32_t current_c;
    
    ii = 0;
    pos = 0;
    achou = false;
    while(((ii) < (GameHouse__fila_hwm)) &&
    (achou == false))
    {
        current_d = GameHouse__fila_d_arr[ii];
        current_c = GameHouse__fila_c_arr[ii];
        if(current_d == dd)
        {
            pos = pos+1;
            if(current_c == cc)
            {
                achou = true;
            }
        }
        ii = ii+1;
    }
    (*pp) = pos;
}

void GameHouse__entrar_fila_dispositivo(GameHouse__CLIENTES cc, GameHouse__DISPOSITIVOS dd, GameHouse__JOGOS jj)
{
    int32_t idx;
    int32_t ii;
    int32_t current_c;
    
    idx = -1;
    ii = 0;
    while(((ii) < (GameHouse__clientes_hwm)) &&
    (idx == -1))
    {
        current_c = GameHouse__clientes_arr[ii];
        if(current_c == cc)
        {
            idx = ii;
        }
        ii = ii+1;
    }
    if((idx) != (-1))
    {
        GameHouse__fila_d_arr[GameHouse__fila_hwm] = dd;
        GameHouse__fila_c_arr[GameHouse__fila_hwm] = cc;
        GameHouse__fila_j_arr[GameHouse__fila_hwm] = jj;
        GameHouse__statusCliente_arr[idx] = GameHouse__em_espera;
        GameHouse__fila_hwm = GameHouse__fila_hwm+1;
    }
}

void GameHouse__sair_fila_dispositivo(GameHouse__CLIENTES cc, GameHouse__DISPOSITIVOS dd)
{
    int32_t idx_fila;
    int32_t idx_cliente;
    int32_t ii;
    int32_t current_c;
    int32_t current_d;
    
    idx_fila = -1;
    ii = 0;
    while(((ii) < (GameHouse__fila_hwm)) &&
    (idx_fila == -1))
    {
        current_c = GameHouse__fila_c_arr[ii];
        current_d = GameHouse__fila_d_arr[ii];
        if((current_c == cc) &&
        (current_d == dd))
        {
            idx_fila = ii;
        }
        ii = ii+1;
    }
    if((idx_fila) != (-1))
    {
        GameHouse__fila_hwm = GameHouse__fila_hwm-1;
        GameHouse__fila_d_arr[idx_fila] = GameHouse__fila_d_arr[GameHouse__fila_hwm];
        GameHouse__fila_c_arr[idx_fila] = GameHouse__fila_c_arr[GameHouse__fila_hwm];
        GameHouse__fila_j_arr[idx_fila] = GameHouse__fila_j_arr[GameHouse__fila_hwm];
    }
    idx_cliente = -1;
    ii = 0;
    while(((ii) < (GameHouse__clientes_hwm)) &&
    (idx_cliente == -1))
    {
        current_c = GameHouse__clientes_arr[ii];
        if(current_c == cc)
        {
            idx_cliente = ii;
        }
        ii = ii+1;
    }
    if((idx_cliente) != (-1))
    {
        GameHouse__statusCliente_arr[idx_cliente] = GameHouse__inativo;
    }
}

void GameHouse__iniciar_sessao_fila(GameHouse__DISPOSITIVOS dd)
{
    int32_t idx_fila;
    int32_t idx_cliente;
    int32_t idx_dispositivo;
    int32_t ii;
    int32_t primeiro_cliente;
    int32_t jogo_solicitado;
    int32_t current_d;
    int32_t current_c;
    int32_t creditos_atuais;
    
    idx_fila = -1;
    ii = 0;
    while(((ii) < (GameHouse__fila_hwm)) &&
    (idx_fila == -1))
    {
        current_d = GameHouse__fila_d_arr[ii];
        if(current_d == dd)
        {
            idx_fila = ii;
        }
        ii = ii+1;
    }
    if((idx_fila) != (-1))
    {
        primeiro_cliente = GameHouse__fila_c_arr[idx_fila];
        jogo_solicitado = GameHouse__fila_j_arr[idx_fila];
        idx_cliente = -1;
        ii = 0;
        while(((ii) < (GameHouse__clientes_hwm)) &&
        (idx_cliente == -1))
        {
            current_c = GameHouse__clientes_arr[ii];
            if(current_c == primeiro_cliente)
            {
                idx_cliente = ii;
            }
            ii = ii+1;
        }
        idx_dispositivo = -1;
        ii = 0;
        while(((ii) < (GameHouse__dispositivos_hwm)) &&
        (idx_dispositivo == -1))
        {
            current_d = GameHouse__dispositivos_arr[ii];
            if(current_d == dd)
            {
                idx_dispositivo = ii;
            }
            ii = ii+1;
        }
        if(((idx_cliente) != (-1)) &&
        ((idx_dispositivo) != (-1)))
        {
            GameHouse__sessao_c_arr[GameHouse__sessao_hwm] = primeiro_cliente;
            GameHouse__sessao_d_arr[GameHouse__sessao_hwm] = dd;
            GameHouse__sessao_j_arr[GameHouse__sessao_hwm] = jogo_solicitado;
            GameHouse__sessao_hwm = GameHouse__sessao_hwm+1;
            GameHouse__statusDispositivo_arr[idx_dispositivo] = GameHouse__em_uso;
            GameHouse__statusCliente_arr[idx_cliente] = GameHouse__ativo;
            creditos_atuais = GameHouse__creditosCliente_arr[idx_cliente];
            GameHouse__creditosCliente_arr[idx_cliente] = creditos_atuais-1;
            GameHouse__fila_hwm = GameHouse__fila_hwm-1;
            GameHouse__fila_d_arr[idx_fila] = GameHouse__fila_d_arr[GameHouse__fila_hwm];
            GameHouse__fila_c_arr[idx_fila] = GameHouse__fila_c_arr[GameHouse__fila_hwm];
            GameHouse__fila_j_arr[idx_fila] = GameHouse__fila_j_arr[GameHouse__fila_hwm];
        }
    }
}

void GameHouse__encerrar_sessao(GameHouse__CLIENTES cc)
{
    int32_t idx_sessao;
    int32_t idx_cliente;
    int32_t idx_dispositivo;
    int32_t ii;
    int32_t dispositivo_da_sessao;
    int32_t current_sc;
    int32_t current_cc;
    int32_t current_d;
    
    idx_sessao = -1;
    ii = 0;
    while(((ii) < (GameHouse__sessao_hwm)) &&
    (idx_sessao == -1))
    {
        current_sc = GameHouse__sessao_c_arr[ii];
        if(current_sc == cc)
        {
            idx_sessao = ii;
        }
        ii = ii+1;
    }
    if((idx_sessao) != (-1))
    {
        dispositivo_da_sessao = GameHouse__sessao_d_arr[idx_sessao];
        idx_cliente = -1;
        ii = 0;
        while(((ii) < (GameHouse__clientes_hwm)) &&
        (idx_cliente == -1))
        {
            current_cc = GameHouse__clientes_arr[ii];
            if(current_cc == cc)
            {
                idx_cliente = ii;
            }
            ii = ii+1;
        }
        idx_dispositivo = -1;
        ii = 0;
        while(((ii) < (GameHouse__dispositivos_hwm)) &&
        (idx_dispositivo == -1))
        {
            current_d = GameHouse__dispositivos_arr[ii];
            if(current_d == dispositivo_da_sessao)
            {
                idx_dispositivo = ii;
            }
            ii = ii+1;
        }
        if(((idx_cliente) != (-1)) &&
        ((idx_dispositivo) != (-1)))
        {
            GameHouse__statusCliente_arr[idx_cliente] = GameHouse__inativo;
            GameHouse__statusDispositivo_arr[idx_dispositivo] = GameHouse__disponivel;
            GameHouse__sessao_hwm = GameHouse__sessao_hwm-1;
            GameHouse__sessao_c_arr[idx_sessao] = GameHouse__sessao_c_arr[GameHouse__sessao_hwm];
            GameHouse__sessao_d_arr[idx_sessao] = GameHouse__sessao_d_arr[GameHouse__sessao_hwm];
            GameHouse__sessao_j_arr[idx_sessao] = GameHouse__sessao_j_arr[GameHouse__sessao_hwm];
        }
    }
}

void GameHouse__pre_add_tipo_dispositivo(GameHouse__TIPOS_DISPOSITIVO td, bool *ok)
{
    bool tipo_encontrado;
    int32_t current_tipo;
    int32_t ii;
    
    tipo_encontrado = false;
    ii = 0;
    while(((ii) < (GameHouse__tiposDispositivos_hwm)) &&
    (tipo_encontrado == false))
    {
        current_tipo = GameHouse__tiposDispositivos_arr[ii];
        if(current_tipo == td)
        {
            tipo_encontrado = true;
        }
        ii = ii+1;
    }
    if(tipo_encontrado == false)
    {
        (*ok) = true;
    }
    else
    {
        (*ok) = false;
    }
}

void GameHouse__pre_remove_tipo_dispositivo(GameHouse__TIPOS_DISPOSITIVO td, bool *ok)
{
    bool tipo_existe;
    bool tipo_em_uso_por_disp;
    bool tipo_em_uso_por_jogo;
    int32_t current_tipo;
    int32_t ii;
    
    tipo_existe = false;
    tipo_em_uso_por_disp = false;
    tipo_em_uso_por_jogo = false;
    ii = 0;
    while(((ii) < (GameHouse__tiposDispositivos_hwm)) &&
    (tipo_existe == false))
    {
        current_tipo = GameHouse__tiposDispositivos_arr[ii];
        if(current_tipo == td)
        {
            tipo_existe = true;
        }
        ii = ii+1;
    }
    ii = 0;
    while(((ii) < (GameHouse__dispositivos_hwm)) &&
    (tipo_em_uso_por_disp == false))
    {
        current_tipo = GameHouse__tipoDispositivo_arr[ii];
        if(current_tipo == td)
        {
            tipo_em_uso_por_disp = true;
        }
        ii = ii+1;
    }
    ii = 0;
    while(((ii) < (GameHouse__jogos_hwm)) &&
    (tipo_em_uso_por_jogo == false))
    {
        current_tipo = GameHouse__tipoJogo_arr[ii];
        if(current_tipo == td)
        {
            tipo_em_uso_por_jogo = true;
        }
        ii = ii+1;
    }
    if(((tipo_existe == true) &&
        (tipo_em_uso_por_disp == false)) &&
    (tipo_em_uso_por_jogo == false))
    {
        (*ok) = true;
    }
    else
    {
        (*ok) = false;
    }
}

void GameHouse__pre_add_dispositivo(GameHouse__DISPOSITIVOS dd, GameHouse__TIPOS_DISPOSITIVO td, bool *ok)
{
    bool disp_encontrado;
    bool tipo_existe;
    int32_t current_disp;
    int32_t current_tipo;
    int32_t ii;
    
    disp_encontrado = false;
    tipo_existe = false;
    ii = 0;
    while(((ii) < (GameHouse__dispositivos_hwm)) &&
    (disp_encontrado == false))
    {
        current_disp = GameHouse__dispositivos_arr[ii];
        if(current_disp == dd)
        {
            disp_encontrado = true;
        }
        ii = ii+1;
    }
    ii = 0;
    while(((ii) < (GameHouse__tiposDispositivos_hwm)) &&
    (tipo_existe == false))
    {
        current_tipo = GameHouse__tiposDispositivos_arr[ii];
        if(current_tipo == td)
        {
            tipo_existe = true;
        }
        ii = ii+1;
    }
    if(((disp_encontrado == false) &&
        (tipo_existe == true)) &&
    ((GameHouse__dispositivos_hwm) < (GameHouse__MAX_DISPOSITIVOS)))
    {
        (*ok) = true;
    }
    else
    {
        (*ok) = false;
    }
}

void GameHouse__pre_remove_dispositivo(GameHouse__DISPOSITIVOS dd, bool *ok)
{
    int32_t idx;
    int32_t ii;
    int32_t current_disp;
    bool disp_existe;
    bool status_ok;
    bool fila_esta_vazia;
    
    idx = -1;
    ii = 0;
    disp_existe = false;
    while((ii) < (GameHouse__dispositivos_hwm))
    {
        current_disp = GameHouse__dispositivos_arr[ii];
        if(current_disp == dd)
        {
            disp_existe = true;
            idx = ii;
        }
        ii = ii+1;
    }
    if(disp_existe == false)
    {
        (*ok) = false;
    }
    else
    {
        {
            GameHouse__STATUS_DISPOSITIVO current_status;
            
            current_status = GameHouse__statusDispositivo_arr[idx];
            status_ok = (((current_status) != (GameHouse__em_uso)) ? true : false);
            fila_esta_vazia = true;
            ii = 0;
            while(((ii) < (GameHouse__fila_hwm)) &&
            (fila_esta_vazia == true))
            {
                current_disp = GameHouse__fila_d_arr[ii];
                if(current_disp == dd)
                {
                    fila_esta_vazia = false;
                }
                ii = ii+1;
            }
            if((status_ok == true) &&
            (fila_esta_vazia == true))
            {
                (*ok) = true;
            }
            else
            {
                (*ok) = false;
            }
        }
    }
}

void GameHouse__pre_add_jogo(GameHouse__JOGOS jj, GameHouse__TIPOS_DISPOSITIVO td, bool *ok)
{
    bool jogo_encontrado;
    bool tipo_existe;
    int32_t current_jogo;
    int32_t current_tipo;
    
    jogo_encontrado = false;
    tipo_existe = false;
    {
        int32_t ii;
        
        ii = 0;
        while((ii) < (GameHouse__jogos_hwm))
        {
            current_jogo = GameHouse__jogos_arr[ii];
            if(current_jogo == jj)
            {
                jogo_encontrado = true;
            }
            ii = ii+1;
        }
        ii = 0;
        while((ii) < (GameHouse__tiposDispositivos_hwm))
        {
            current_tipo = GameHouse__tiposDispositivos_arr[ii];
            if(current_tipo == td)
            {
                tipo_existe = true;
            }
            ii = ii+1;
        }
    }
    if((jogo_encontrado == false) &&
    (tipo_existe == true))
    {
        (*ok) = true;
    }
    else
    {
        (*ok) = false;
    }
}

void GameHouse__pre_remover_jogo(GameHouse__JOGOS jj, bool *ok)
{
    {
        bool jogo_encontrado;
        bool em_sessao;
        bool em_fila;
        int32_t ii;
        int32_t current_j_main;
        int32_t current_j_sessao;
        int32_t current_j_fila;
        
        jogo_encontrado = false;
        em_sessao = false;
        em_fila = false;
        ii = 0;
        while(((ii) < (GameHouse__jogos_hwm)) &&
        (jogo_encontrado == false))
        {
            current_j_main = GameHouse__jogos_arr[ii];
            if(current_j_main == jj)
            {
                jogo_encontrado = true;
            }
            ii = ii+1;
        }
        ii = 0;
        while(((ii) < (GameHouse__sessao_hwm)) &&
        (em_sessao == false))
        {
            current_j_sessao = GameHouse__sessao_j_arr[ii];
            if(current_j_sessao == jj)
            {
                em_sessao = true;
            }
            ii = ii+1;
        }
        ii = 0;
        while(((ii) < (GameHouse__fila_hwm)) &&
        (em_fila == false))
        {
            current_j_fila = GameHouse__fila_j_arr[ii];
            if(current_j_fila == jj)
            {
                em_fila = true;
            }
            ii = ii+1;
        }
        if(((jogo_encontrado == true) &&
            (em_sessao == false)) &&
        (em_fila == false))
        {
            (*ok) = true;
        }
        else
        {
            (*ok) = false;
        }
    }
}

void GameHouse__pre_instalar_jogo(GameHouse__DISPOSITIVOS dd, GameHouse__JOGOS jj, bool *ok)
{
    int32_t idx_d;
    int32_t idx_j;
    int32_t ii;
    bool disp_existe;
    bool jogo_existe;
    int32_t current_d;
    int32_t current_j;
    
    disp_existe = false;
    idx_d = -1;
    ii = 0;
    while(((ii) < (GameHouse__dispositivos_hwm)) &&
    (disp_existe == false))
    {
        current_d = GameHouse__dispositivos_arr[ii];
        if(current_d == dd)
        {
            disp_existe = true;
            idx_d = ii;
        }
        ii = ii+1;
    }
    if(disp_existe == false)
    {
        (*ok) = false;
    }
    else
    {
        jogo_existe = false;
        idx_j = -1;
        ii = 0;
        while(((ii) < (GameHouse__jogos_hwm)) &&
        (jogo_existe == false))
        {
            current_j = GameHouse__jogos_arr[ii];
            if(current_j == jj)
            {
                jogo_existe = true;
                idx_j = ii;
            }
            ii = ii+1;
        }
        if(jogo_existe == false)
        {
            (*ok) = false;
        }
        else
        {
            {
                int32_t tipo_disp;
                int32_t tipo_jogo;
                bool jogo_ja_instalado;
                
                tipo_disp = GameHouse__tipoDispositivo_arr[idx_d];
                tipo_jogo = GameHouse__tipoJogo_arr[idx_j];
                if(tipo_disp == tipo_jogo)
                {
                    jogo_ja_instalado = false;
                    ii = 0;
                    while(((ii) < (GameHouse__jogosDispositivo_hwm)) &&
                    (jogo_ja_instalado == false))
                    {
                        current_d = GameHouse__jogosDispositivo_d_arr[ii];
                        current_j = GameHouse__jogosDispositivo_j_arr[ii];
                        if((current_d == dd) &&
                        (current_j == jj))
                        {
                            jogo_ja_instalado = true;
                        }
                        ii = ii+1;
                    }
                    if(jogo_ja_instalado == false)
                    {
                        (*ok) = true;
                    }
                    else
                    {
                        (*ok) = false;
                    }
                }
                else
                {
                    (*ok) = false;
                }
            }
        }
    }
}

void GameHouse__pre_desinstalar_jogo(GameHouse__DISPOSITIVOS dd, GameHouse__JOGOS jj, bool *ok)
{
    int32_t ii;
    bool jogo_instalado;
    bool em_sessao;
    bool solicitado_na_fila;
    int32_t current_d;
    int32_t current_j;
    
    jogo_instalado = false;
    ii = 0;
    while(((ii) < (GameHouse__jogosDispositivo_hwm)) &&
    (jogo_instalado == false))
    {
        current_d = GameHouse__jogosDispositivo_d_arr[ii];
        current_j = GameHouse__jogosDispositivo_j_arr[ii];
        if((current_d == dd) &&
        (current_j == jj))
        {
            jogo_instalado = true;
        }
        ii = ii+1;
    }
    if(jogo_instalado == true)
    {
        em_sessao = false;
        ii = 0;
        while(((ii) < (GameHouse__sessao_hwm)) &&
        (em_sessao == false))
        {
            current_j = GameHouse__sessao_j_arr[ii];
            if(current_j == jj)
            {
                em_sessao = true;
            }
            ii = ii+1;
        }
        if(em_sessao == false)
        {
            solicitado_na_fila = false;
            ii = 0;
            while(((ii) < (GameHouse__fila_hwm)) &&
            (solicitado_na_fila == false))
            {
                current_j = GameHouse__fila_j_arr[ii];
                if(current_j == jj)
                {
                    solicitado_na_fila = true;
                }
                ii = ii+1;
            }
            if(solicitado_na_fila == false)
            {
                (*ok) = true;
            }
            else
            {
                (*ok) = false;
            }
        }
        else
        {
            (*ok) = false;
        }
    }
    else
    {
        (*ok) = false;
    }
}

void GameHouse__pre_banir_cliente(GameHouse__CLIENTES cc, bool *ok)
{
    int32_t ii;
    bool cliente_existe;
    bool em_sessao;
    bool na_fila;
    int32_t current_c;
    
    cliente_existe = false;
    ii = 0;
    while(((ii) < (GameHouse__clientes_hwm)) &&
    (cliente_existe == false))
    {
        current_c = GameHouse__clientes_arr[ii];
        if(current_c == cc)
        {
            cliente_existe = true;
        }
        ii = ii+1;
    }
    if(cliente_existe == true)
    {
        em_sessao = false;
        ii = 0;
        while(((ii) < (GameHouse__sessao_hwm)) &&
        (em_sessao == false))
        {
            current_c = GameHouse__sessao_c_arr[ii];
            if(current_c == cc)
            {
                em_sessao = true;
            }
            ii = ii+1;
        }
        if(em_sessao == false)
        {
            na_fila = false;
            ii = 0;
            while(((ii) < (GameHouse__fila_hwm)) &&
            (na_fila == false))
            {
                current_c = GameHouse__fila_c_arr[ii];
                if(current_c == cc)
                {
                    na_fila = true;
                }
                ii = ii+1;
            }
            if(na_fila == false)
            {
                (*ok) = true;
            }
            else
            {
                (*ok) = false;
            }
        }
        else
        {
            (*ok) = false;
        }
    }
    else
    {
        (*ok) = false;
    }
}

void GameHouse__pre_comprar_creditos(GameHouse__CLIENTES cc, int32_t qtd, bool *ok)
{
    int32_t idx;
    int32_t ii;
    int32_t current_cliente;
    
    idx = -1;
    ii = 0;
    while(((ii) < (GameHouse__clientes_hwm)) &&
    (idx == -1))
    {
        current_cliente = GameHouse__clientes_arr[ii];
        if(current_cliente == cc)
        {
            idx = ii;
        }
        ii = ii+1;
    }
    if((idx) != (-1))
    {
        {
            int32_t current_creditos;
            
            current_creditos = GameHouse__creditosCliente_arr[idx];
            if((qtd) <= (GameHouse__MAX_CREDITOS))
            {
                {
                    int32_t creditos_finais;
                    
                    creditos_finais = current_creditos+qtd;
                    if((creditos_finais) <= (GameHouse__MAX_CREDITOS))
                    {
                        (*ok) = true;
                    }
                    else
                    {
                        (*ok) = false;
                    }
                }
            }
            else
            {
                (*ok) = false;
            }
        }
    }
    else
    {
        (*ok) = false;
    }
}

void GameHouse__pre_set_status_dispositivo(GameHouse__DISPOSITIVOS dd, GameHouse__STATUS_DISPOSITIVO ss, bool *ok)
{
    int32_t ii;
    bool disp_existe;
    bool em_sessao;
    int32_t current_d;
    
    disp_existe = false;
    ii = 0;
    while(((ii) < (GameHouse__dispositivos_hwm)) &&
    (disp_existe == false))
    {
        current_d = GameHouse__dispositivos_arr[ii];
        if(current_d == dd)
        {
            disp_existe = true;
        }
        ii = ii+1;
    }
    if(disp_existe == true)
    {
        em_sessao = false;
        ii = 0;
        while(((ii) < (GameHouse__sessao_hwm)) &&
        (em_sessao == false))
        {
            current_d = GameHouse__sessao_d_arr[ii];
            if(current_d == dd)
            {
                em_sessao = true;
            }
            ii = ii+1;
        }
        {
            bool status_eh_em_uso;
            
            status_eh_em_uso = ((ss == GameHouse__em_uso) ? true : false);
            if(status_eh_em_uso == true)
            {
                (*ok) = em_sessao;
            }
            else
            {
                (*ok) = ((em_sessao == false) ? true : false);
            }
        }
    }
    else
    {
        (*ok) = false;
    }
}

void GameHouse__pre_add_cliente(GameHouse__CLIENTES cc, bool *ok)
{
    bool cliente_encontrado;
    int32_t current_cliente;
    int32_t ii;
    
    cliente_encontrado = false;
    ii = 0;
    while(((ii) < (GameHouse__clientes_hwm)) &&
    (cliente_encontrado == false))
    {
        current_cliente = GameHouse__clientes_arr[ii];
        if(current_cliente == cc)
        {
            cliente_encontrado = true;
        }
        ii = ii+1;
    }
    if((cliente_encontrado == false) &&
    ((GameHouse__clientes_hwm) < (GameHouse__MAX_CLIENTES)))
    {
        (*ok) = true;
    }
    else
    {
        (*ok) = false;
    }
}

void GameHouse__pre_entrar_fila_dispositivo(GameHouse__CLIENTES cc, GameHouse__DISPOSITIVOS dd, GameHouse__JOGOS jj, bool *ok)
{
    int32_t idx_c;
    bool creditos_suficientes;
    bool cliente_status_ok;
    bool cliente_nao_em_fila;
    bool jogo_instalado;
    int32_t ii;
    int32_t current_c;
    int32_t current_d;
    int32_t current_j;
    
    idx_c = -1;
    ii = 0;
    while(((ii) < (GameHouse__clientes_hwm)) &&
    (idx_c == -1))
    {
        current_c = GameHouse__clientes_arr[ii];
        if(current_c == cc)
        {
            idx_c = ii;
        }
        ii = ii+1;
    }
    if(idx_c == -1)
    {
        (*ok) = false;
    }
    else
    {
        {
            int32_t current_creditos;
            GameHouse__STATUS_CLIENTE current_status;
            
            current_creditos = GameHouse__creditosCliente_arr[idx_c];
            creditos_suficientes = (((current_creditos) > (0)) ? true : false);
            current_status = GameHouse__statusCliente_arr[idx_c];
            cliente_status_ok = ((current_status == GameHouse__inativo) ? true : false);
        }
        if(creditos_suficientes == true)
        {
            if(cliente_status_ok == true)
            {
                cliente_nao_em_fila = true;
                ii = 0;
                while(((ii) < (GameHouse__fila_hwm)) &&
                (cliente_nao_em_fila == true))
                {
                    current_c = GameHouse__fila_c_arr[ii];
                    if(current_c == cc)
                    {
                        cliente_nao_em_fila = false;
                    }
                    ii = ii+1;
                }
                if(cliente_nao_em_fila == false)
                {
                    (*ok) = false;
                }
                else
                {
                    jogo_instalado = false;
                    ii = 0;
                    while(((ii) < (GameHouse__jogosDispositivo_hwm)) &&
                    (jogo_instalado == false))
                    {
                        current_d = GameHouse__jogosDispositivo_d_arr[ii];
                        current_j = GameHouse__jogosDispositivo_j_arr[ii];
                        if((current_d == dd) &&
                        (current_j == jj))
                        {
                            jogo_instalado = true;
                        }
                        ii = ii+1;
                    }
                    (*ok) = jogo_instalado;
                }
            }
            else
            {
                (*ok) = false;
            }
        }
        else
        {
            (*ok) = false;
        }
    }
}

void GameHouse__pre_sair_fila_dispositivo(GameHouse__CLIENTES cc, GameHouse__DISPOSITIVOS dd, bool *ok)
{
    int32_t ii;
    bool cliente_na_fila;
    int32_t current_c;
    int32_t current_d;
    
    cliente_na_fila = false;
    ii = 0;
    while(((ii) < (GameHouse__fila_hwm)) &&
    (cliente_na_fila == false))
    {
        current_c = GameHouse__fila_c_arr[ii];
        current_d = GameHouse__fila_d_arr[ii];
        if((current_c == cc) &&
        (current_d == dd))
        {
            cliente_na_fila = true;
        }
        ii = ii+1;
    }
    (*ok) = cliente_na_fila;
}

void GameHouse__pre_iniciar_sessao(GameHouse__DISPOSITIVOS dd, bool *ok)
{
    int32_t ii;
    int32_t idx_d;
    bool fila_nao_vazia;
    int32_t current_d;
    
    idx_d = -1;
    ii = 0;
    while(((ii) < (GameHouse__dispositivos_hwm)) &&
    (idx_d == -1))
    {
        current_d = GameHouse__dispositivos_arr[ii];
        if(current_d == dd)
        {
            idx_d = ii;
        }
        ii = ii+1;
    }
    if(idx_d == -1)
    {
        (*ok) = false;
    }
    else
    {
        {
            GameHouse__STATUS_DISPOSITIVO current_status;
            
            current_status = GameHouse__statusDispositivo_arr[idx_d];
            if((current_status) != (GameHouse__disponivel))
            {
                (*ok) = false;
            }
            else
            {
                fila_nao_vazia = false;
                ii = 0;
                while(((ii) < (GameHouse__fila_hwm)) &&
                (fila_nao_vazia == false))
                {
                    current_d = GameHouse__fila_d_arr[ii];
                    if(current_d == dd)
                    {
                        fila_nao_vazia = true;
                    }
                    ii = ii+1;
                }
                (*ok) = fila_nao_vazia;
            }
        }
    }
}

void GameHouse__pre_encerrar_sessao(GameHouse__CLIENTES cc, bool *ok)
{
    int32_t ii;
    bool cliente_em_sessao;
    int32_t current_c;
    
    cliente_em_sessao = false;
    ii = 0;
    while(((ii) < (GameHouse__sessao_hwm)) &&
    (cliente_em_sessao == false))
    {
        current_c = GameHouse__sessao_c_arr[ii];
        if(current_c == cc)
        {
            cliente_em_sessao = true;
        }
        ii = ii+1;
    }
    (*ok) = cliente_em_sessao;
}

void GameHouse__init_tipos_disponiveis(void)
{
    GameHouse__tipos_disponiveis_iterator = 0;
}

void GameHouse__has_more_tipos_disponiveis(bool *more)
{
    (*more) = (((GameHouse__tipos_disponiveis_iterator) < (GameHouse__tiposDispositivos_hwm)) ? true : false);
}

void GameHouse__get_next_tipo_dispositivo(GameHouse__TIPOS_DISPOSITIVO *td)
{
    (*td) = GameHouse__tiposDispositivos_arr[GameHouse__tipos_disponiveis_iterator];
    GameHouse__tipos_disponiveis_iterator = GameHouse__tipos_disponiveis_iterator+1;
}

void GameHouse__init_devices_info(void)
{
    GameHouse__devices_info_iterator = 0;
}

void GameHouse__has_more_devices_info(bool *more)
{
    (*more) = (((GameHouse__devices_info_iterator) < (GameHouse__dispositivos_hwm)) ? true : false);
}

void GameHouse__get_next_device_info(GameHouse__DISPOSITIVOS *dd, GameHouse__TIPOS_DISPOSITIVO *td, GameHouse__STATUS_DISPOSITIVO *ss)
{
    (*dd) = GameHouse__dispositivos_arr[GameHouse__devices_info_iterator];
    (*td) = GameHouse__tipoDispositivo_arr[GameHouse__devices_info_iterator];
    (*ss) = GameHouse__statusDispositivo_arr[GameHouse__devices_info_iterator];
    GameHouse__devices_info_iterator = GameHouse__devices_info_iterator+1;
}


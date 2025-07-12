#ifndef _GameHouse_h
#define _GameHouse_h

#include <stdint.h>
#include <stdbool.h>
/* Clause INCLUDES */
#include "GameHouse_ctx.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


#define GameHouse__DISPOSITIVOS__max GameHouse__MAX_DISPOSITIVOS
#define GameHouse__CLIENTES__max GameHouse__MAX_CLIENTES
#define GameHouse__TIPOS_DISPOSITIVO__max GameHouse__MAX_TIPOS_DISPOSITIVO
#define GameHouse__JOGOS__max GameHouse__MAX_JOGOS
/* Clause SETS */
typedef int GameHouse__DISPOSITIVOS;
typedef int GameHouse__CLIENTES;
typedef int GameHouse__TIPOS_DISPOSITIVO;
typedef int GameHouse__JOGOS;
typedef enum
{
    GameHouse__ativo,
    GameHouse__inativo,
    GameHouse__em_espera
    
} GameHouse__STATUS_CLIENTE;
#define GameHouse__STATUS_CLIENTE__max 3
typedef enum
{
    GameHouse__disponivel,
    GameHouse__em_uso,
    GameHouse__manutencao
    
} GameHouse__STATUS_DISPOSITIVO;
#define GameHouse__STATUS_DISPOSITIVO__max 3

/* Clause CONCRETE_CONSTANTS */
/* Basic constants */
/* Array and record constants */

/* Clause CONCRETE_VARIABLES */

extern void GameHouse__INITIALISATION(void);

/* Clause OPERATIONS */

extern void GameHouse__add_tipo_dispositivo(GameHouse__TIPOS_DISPOSITIVO td);
extern void GameHouse__remove_tipo_dispositivo(GameHouse__TIPOS_DISPOSITIVO td);
extern void GameHouse__add_dispositivo(GameHouse__DISPOSITIVOS dd, GameHouse__TIPOS_DISPOSITIVO td);
extern void GameHouse__remove_dispositivo(GameHouse__DISPOSITIVOS dd);
extern void GameHouse__add_jogo(GameHouse__JOGOS jj, GameHouse__TIPOS_DISPOSITIVO td);
extern void GameHouse__remove_jogo(GameHouse__JOGOS jj);
extern void GameHouse__instalar_jogo(GameHouse__DISPOSITIVOS dd, GameHouse__JOGOS jj);
extern void GameHouse__desinstalar_jogo(GameHouse__DISPOSITIVOS dd, GameHouse__JOGOS jj);
extern void GameHouse__set_status_dispositivo(GameHouse__DISPOSITIVOS dd, GameHouse__STATUS_DISPOSITIVO ss);
extern void GameHouse__add_cliente(GameHouse__CLIENTES cc);
extern void GameHouse__banir_cliente(GameHouse__CLIENTES cc);
extern void GameHouse__comprar_creditos(GameHouse__CLIENTES cc, int32_t qtd);
extern void GameHouse__posicao_fila(GameHouse__CLIENTES cc, GameHouse__DISPOSITIVOS dd, int32_t *pp);
extern void GameHouse__entrar_fila_dispositivo(GameHouse__CLIENTES cc, GameHouse__DISPOSITIVOS dd, GameHouse__JOGOS jj);
extern void GameHouse__sair_fila_dispositivo(GameHouse__CLIENTES cc, GameHouse__DISPOSITIVOS dd);
extern void GameHouse__iniciar_sessao_fila(GameHouse__DISPOSITIVOS dd);
extern void GameHouse__encerrar_sessao(GameHouse__CLIENTES cc);
extern void GameHouse__pre_add_tipo_dispositivo(GameHouse__TIPOS_DISPOSITIVO td, bool *ok);
extern void GameHouse__pre_remove_tipo_dispositivo(GameHouse__TIPOS_DISPOSITIVO td, bool *ok);
extern void GameHouse__pre_add_dispositivo(GameHouse__DISPOSITIVOS dd, GameHouse__TIPOS_DISPOSITIVO td, bool *ok);
extern void GameHouse__pre_remove_dispositivo(GameHouse__DISPOSITIVOS dd, bool *ok);
extern void GameHouse__pre_add_jogo(GameHouse__JOGOS jj, GameHouse__TIPOS_DISPOSITIVO td, bool *ok);
extern void GameHouse__pre_remover_jogo(GameHouse__JOGOS jj, bool *ok);
extern void GameHouse__pre_instalar_jogo(GameHouse__DISPOSITIVOS dd, GameHouse__JOGOS jj, bool *ok);
extern void GameHouse__pre_desinstalar_jogo(GameHouse__DISPOSITIVOS dd, GameHouse__JOGOS jj, bool *ok);
extern void GameHouse__pre_banir_cliente(GameHouse__CLIENTES cc, bool *ok);
extern void GameHouse__pre_comprar_creditos(GameHouse__CLIENTES cc, int32_t qtd, bool *ok);
extern void GameHouse__pre_set_status_dispositivo(GameHouse__DISPOSITIVOS dd, GameHouse__STATUS_DISPOSITIVO ss, bool *ok);
extern void GameHouse__pre_add_cliente(GameHouse__CLIENTES cc, bool *ok);
extern void GameHouse__pre_entrar_fila_dispositivo(GameHouse__CLIENTES cc, GameHouse__DISPOSITIVOS dd, GameHouse__JOGOS jj, bool *ok);
extern void GameHouse__pre_sair_fila_dispositivo(GameHouse__CLIENTES cc, GameHouse__DISPOSITIVOS dd, bool *ok);
extern void GameHouse__pre_iniciar_sessao(GameHouse__DISPOSITIVOS dd, bool *ok);
extern void GameHouse__pre_encerrar_sessao(GameHouse__CLIENTES cc, bool *ok);
extern void GameHouse__init_disp_disponiveis(void);
extern void GameHouse__has_more_disp_disponiveis(bool *more);
extern void GameHouse__get_next_disp_disponivel(GameHouse__DISPOSITIVOS *dd);
extern void GameHouse__init_jogos_por_tipo(void);
extern void GameHouse__has_more_jogos_por_tipo(GameHouse__TIPOS_DISPOSITIVO td, bool *more);
extern void GameHouse__get_next_jogo_por_tipo(GameHouse__TIPOS_DISPOSITIVO td, GameHouse__JOGOS *jj);
extern void GameHouse__init_jogos_dispositivo(void);
extern void GameHouse__has_more_jogos_dispositivo(GameHouse__DISPOSITIVOS dd, bool *more);
extern void GameHouse__get_next_jogo_dispositivo(GameHouse__DISPOSITIVOS dd, GameHouse__JOGOS *jj);
extern void GameHouse__init_clientes_info(void);
extern void GameHouse__has_more_clientes_info(bool *more);
extern void GameHouse__get_next_cliente_info(GameHouse__CLIENTES *cc, GameHouse__STATUS_CLIENTE *ss, int32_t *cr);
extern void GameHouse__init_tipos_disponiveis(void);
extern void GameHouse__has_more_tipos_disponiveis(bool *more);
extern void GameHouse__get_next_tipo_dispositivo(GameHouse__TIPOS_DISPOSITIVO *td);
extern void GameHouse__init_devices_info(void);
extern void GameHouse__has_more_devices_info(bool *more);
extern void GameHouse__get_next_device_info(GameHouse__DISPOSITIVOS *dd, GameHouse__TIPOS_DISPOSITIVO *td, GameHouse__STATUS_DISPOSITIVO *ss);

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif /* _GameHouse_h */

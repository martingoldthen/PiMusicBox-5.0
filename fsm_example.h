#ifndef _FSM_EXAMPLE_H_
#define _FSM_EXAMPLE_H_

#include <stdlib.h> // para poder usar NULL
#include <stdio.h> // para poder usar printf
#include <time.h>
#include <signal.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/time.h>
#include <wiringPi.h>
#include "piMusicBox_1.h"
#include "tmr.h"

#include "kbhit.h" // para poder detectar teclas pulsadas sin bloqueo y leer las teclas pulsadas

#include "fsm.h" // para poder crear y ejecutar la máquina de estados

#define CLK_MS 10 // PERIODO DE ACTUALIZACION DE LA MAQUINA ESTADOS

// FLAGS DEL SISTEMA
#define FLAG_PLAYER_START 			0x01
#define FLAG_PLAYER_STOP 			0x02
#define FLAG_PLAYER_END 			0x04
#define FLAG_NOTA_TIMEOUT           0x08
#define FLAG_SYSTEM_START			0x10
#define FLAG_SYSTEM_END			    0x20
#define FLAG_CARD_IN				0x40
#define FLAG_VALID_CARD				0x80

// A 'key' which we can lock and unlock - values are 0 through 3
//	This is interpreted internally as a pthread_mutex by wiringPi
//	which is hiding some of that to make life simple.
#define	FLAGS_KEY	1
#define	STD_IO_BUFFER_KEY	2

//------------------------------------------------------
// FUNCIONES DE ENTRADA O DE TRANSICION DE LA MAQUINA DE ESTADOS
//------------------------------------------------------
// Prototipos de funciones de entrada
int CompruebaPlayerStart (fsm_t* this);
int CompruebaPlayerStop(fsm_t* this);
int CompruebaFinalMelodia (fsm_t* this);
int CompruebaNuevaNota (fsm_t* this);
int CompruebaNotaTimeout(fsm_t* this);
//Nuevas funciones de la version 5
int CompruebaComienzo(fsm_t* this);
int TarjetaNoDisponible(fsm_t* this);
int TarjetaDisponible(fsm_t* this);
int TarjetaNoValida(fsm_t* this);
int TarjetaValida(fsm_t* this);
int CompruebaFinalReproduccion(fsm_t* this);



//------------------------------------------------------
// FUNCIONES DE SALIDA O DE ACCION DE LA MAQUINA DE ESTADOS
//------------------------------------------------------
void InicializaPlayer(fsm_t*);
void ActualizaPlayer(fsm_t*);
void StopPlayer(fsm_t*);
void ComienzaNuevaNota(fsm_t*);
void FinalMelodia(fsm_t*);
void CompruebaTarjeta(void);
//Nuevas funciones de la version 5
void ComienzaSistema(fsm_t*);
void EsperoTarjeta(fsm_t*);
void LeerTarjeta(fsm_t*);
void DescartaTarjeta(fsm_t*);
void ComienzaReproduccion(fsm_t*);
void ComprueboTarjeta(fsm_t*);
void CancelaReproduccion(fsm_t*);
void FinalizaReproduccion(fsm_t*);


//------------------------------------------------------
// SUBRUTINAS DE ATENCION A LAS INTERRUPCIONES
//------------------------------------------------------
void COMPRUEBA_FLANCO(void);

#endif /* _FSM_EXAMPLE_H_ */

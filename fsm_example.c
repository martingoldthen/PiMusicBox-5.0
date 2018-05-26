#include "fsm_example.h"
#include <softTone.h>

//Conjunto de datos de frecuencias y notas de las diferentes melodias
int frecuenciaDespacito[160] = {0,1175,1109,988,740,740,740,740,740,740,988,988,988,988,880,988,784,0,784,784,784,784,784,988,988,988,988,1109,1175,880,0,880,880,880,880,880,1175,1175,1175,1175,1318,1318,1109,0,1175,1109,988,740,740,740,740,740,740,988,988,988,988,880,988,784,0,784,784,784,784,784,988,988,988,988,1109,1175,880,0,880,880,880,880,880,1175,1175,1175,1175,1318,1318,1109,0,1480,1318,1480,1318,1480,1318,1480,1318,1480,1318,1480,1568,1568,1175,0,1175,1568,1568,1568,0,1568,1760,1568,1480,0,1480,1480,1480,1760,1568,1480,1318,659,659,659,659,659,659,659,659,554,587,1480,1318,1480,1318,1480,1318,1480,1318,1480,1318,1480,1568,1568,1175,0,1175,1568,1568,1568,1568,1760,1568,1480,0,1480,1480,1480,1760,1568,1480,1318};
int tiempoDespacito[160] = {1200,600,600,300,300,150,150,150,150,150,150,150,150,300,150,300,343,112,150,150,150,150,150,150,150,150,300,150,300,300,150,150,150,150,150,150,150,150,150,300,150,300,800,300,600,600,300,300,150,150,150,150,150,150,150,150,300,150,300,343,112,150,150,150,150,150,150,150,150,300,150,300,300,150,150,150,150,150,150,150,150,150,300,150,300,450,1800,150,150,150,150,300,150,300,150,150,150,300,150,300,450,450,300,150,150,225,75,150,150,300,450,800,150,150,300,150,150,300,450,150,150,150,150,150,150,150,150,300,300,150,150,150,150,150,150,450,150,150,150,300,150,300,450,450,300,150,150,150,300,150,300,450,800,150,150,300,150,150,300,450};
int frecuenciaGOT[518] = {1568,0,1046,0,1244,0,1397,0,1568,0,1046,0,1244,0,1397,0,1175,0,1397,0,932,0,1244,0,1175,0,1397,0,932,0,1244,0,1175,0,1046,0,831,0,698,0,523,0,349,0,784,0,523,0,523,0,587,0,622,0,698,0,784,0,523,0,622,0,698,0,784,0,523,0,622,0,698,0,587,0,698,0,466,0,622,0,587,0,698,0,466,0,622,0,587,0,523,0,523,0,587,0,622,0,698,0,784,0,523,0,622,0,698,0,784,0,523,0,622,0,698,0,587,0,698,0,466,0,622,0,587,0,698,0,466,0,622,0,587,0,523,0,0,1568,0,0,1046,0,0,1244,0,0,1397,0,0,1568,0,0,1046,0,0,1244,0,0,1397,0,0,1175,0,587,0,622,0,587,0,523,0,587,0,784,0,880,0,932,0,1046,0,1175,0,0,1397,0,0,932,0,0,1244,0,0,1175,0,0,1397,0,0,932,0,0,1244,0,0,1175,0,0,1046,0,0,1568,0,0,1046,0,0,1244,0,0,1397,0,0,1568,0,0,1046,0,0,1244,0,0,1397,0,0,1175,0,880,0,784,0,932,0,1244,0,0,1397,0,0,932,0,0,1175,0,0,1244,0,0,1175,0,0,932,0,0,1046,0,0,2093,0,622,0,831,0,932,0,1046,0,622,0,831,0,1046,0,0,1865,0,622,0,784,0,831,0,932,0,622,0,784,0,932,0,0,1661,0,523,0,698,0,784,0,831,0,523,0,698,0,831,0,0,1568,0,1046,0,1244,0,1397,0,1568,0,1046,0,1244,0,1397,0,0,0,1661,0,1046,0,1175,0,1244,0,831,0,1175,0,1244,0,0,0,0,2489,0,0,0,0,2794,0,0,0,0,3136,0,0,2093,0,622,0,831,0,932,0,1046,0,622,0,831,0,1046,0,0,1865,0,622,0,784,0,831,0,932,0,622,0,784,0,932,0,0,1661,0,523,0,698,0,784,0,831,0,523,0,698,0,831,0,0,1568,0,1046,0,1244,0,1397,0,1568,0,1046,0,1244,0,1397,0,0,0,1661,0,1046,0,1175,0,1244,0,831,0,1175,0,1244,0,0,0,0,2489,0,1397,0,0,0,2350,0,0,0,2489,0,0,0,2350,0,0,0,0,2093,0,392,0,415,0,466,0,523,0,392,0,415,0,466,0,523,0,392,0,415,0,466,0,2093,0,1568,0,1661,0,1865,0,2093,0,1568,0,1661,0,1865,0,2093,0,1568,0,1661,0,1865};
int tiempoGOT[518] = {900,89,900,89,133,13,133,13,600,59,600,59,133,13,133,13,1400,1400,900,89,900,89,133,13,133,13,600,59,900,89,133,13,133,13,1200,116,267,28,267,28,267,28,900,89,900,89,1400,89,69,7,69,7,69,7,69,7,900,89,900,89,133,13,133,13,600,59,600,59,133,13,133,13,1800,1800,900,89,900,89,133,13,133,13,600,59,900,89,133,13,133,13,1200,2400,69,7,69,7,69,7,69,7,900,89,900,89,133,13,133,13,600,59,600,59,133,13,133,13,1800,1800,900,89,900,89,133,13,133,13,600,59,900,89,133,13,133,13,1200,2400,3600,900,89,900,900,89,900,133,13,150,133,13,150,600,59,600,600,59,600,133,13,150,133,13,150,1200,400,69,7,69,7,69,7,69,7,267,28,400,45,133,13,267,28,267,28,267,28,300,900,89,900,900,89,900,133,13,150,133,13,150,600,59,600,900,89,900,133,13,150,133,13,150,1200,1800,3600,900,89,900,900,89,900,133,13,150,133,13,150,600,59,600,600,59,600,133,13,150,133,13,150,1200,400,267,28,1200,400,133,13,133,13,150,900,89,900,900,89,900,600,59,600,267,28,300,600,59,600,267,28,300,1200,2400,3600,267,28,267,28,133,13,133,13,267,28,267,28,133,13,133,13,150,267,28,267,28,133,13,133,13,133,13,267,28,267,28,133,13,150,267,28,267,28,133,13,133,13,267,28,267,28,133,13,133,13,150,267,28,267,28,133,13,133,13,267,28,267,28,133,13,133,13,150,150,600,59,133,13,133,13,267,28,267,28,133,13,133,13,150,150,150,900,89,900,900,900,900,89,900,900,900,1200,2400,3600,267,28,267,28,133,13,133,13,267,28,267,28,133,13,133,13,150,267,28,267,28,133,13,133,13,267,28,267,28,133,13,133,13,150,267,28,267,28,133,13,133,13,267,28,267,28,133,13,133,13,150,267,28,267,28,133,13,133,13,267,28,267,28,133,13,133,13,150,150,600,59,133,13,133,13,267,28,267,28,133,13,133,13,150,150,150,600,212,133,13,150,150,267,28,300,300,400,45,450,450,133,13,150,150,150,267,28,267,28,133,13,133,13,267,28,267,28,133,13,133,13,267,28,267,28,133,13,2400,116,267,28,267,28,133,13,133,13,267,28,267,28,133,13,133,13,267,28,267,28,133,13,2400};
int frecuenciaTetris[55] = {1319,988,1047,1175,1047,988,880,880,1047,1319,1175,1047,988,988,1047,1175,1319,1047,880,880,0,1175,1397,1760,1568,1397,1319,1047,1319,1175,1047,988,988,1047,1175,1319,1047,880,880,0,659,523,587,494,523,440,415,659,523,587,494,523,659,880,831};
int tiempoTetris[55] = {450,225,225,450,225,225,450,225,225,450,225,225,450,225,225,450,450,450,450,450,675,450,225,450,225,225,675,225,450,225,225,450,225,225,450,450,450,450,450,450,900,900,900,900,900,900,1800,900,900,900,900,450,450,900,1800};
int frecuenciaStarwars[59] = {523,0,523,0,523,0,698,0,1046,0,0,880,0,784,0,1397,0,523,0,1760,0,0,880,0,784,0,1397,0,523,0,1760,0,0,880,0,784,0,1397,0,523,0,1760,0,0,880,0,1760,0,0,784,0,523,0,0,523,0,0,523,0};
int tiempoStarwars[59] = {134,134,134,134,134,134,536,134,536,134,134,134,134,134,134,536,134,402,134,134,429,357,134,134,134,134,536,134,402,134,134,429,357,134,134,134,134,536,134,402,134,134,429,357,134,134,134,429,357,1071,268,67,67,268,67,67,67,67,67};

//IDs de las tarjetas
//La primera es la blanca, la segunda la azul
char uid0[100] = "B017E0A4";
char uid1[100] = "7DD48589";

// Definicion de los estados
//Primera maquina de estados (reproductor simple sin tarjetas)
enum fsm_state {
  WAIT_START = 0,
  WAIT_NEXT = 1,
  WAIT_END = 2,
  };

//Segunda maquina de estados (reproductor con tarjetas)
enum fsm_state2{
	WAIT_START2 = 0,
	WAIT_CARD = 1,
	WAIT_CHECK = 2,
	WAIT_PLAY = 3,
};

//Inicializamos la variable flags a 0, para el inicio del sistema
volatile int flags = 0;

//Espera hasta la proxima activacion del reloj
void delay_until (unsigned int next) {
	unsigned int now = millis();

	if (next > now) {
		delay (next - now);
    }
}

//------------------------------------------------------
// FUNCIONES DE LA MAQUINA DE ESTADOS
//------------------------------------------------------

/**
 * Se encarga de activar FLAG_NOTA_TIMEOUT para avisar al sistema
 * de que ya se ha reproducido la duracion asignada a la nota.
 */
void timer_isr (union sigval value) {
	piLock (FLAGS_KEY);
	flags |= FLAG_NOTA_TIMEOUT;
	piUnlock (FLAGS_KEY);
}

//------------------------------------------------------
// FUNCIONES DE ENTRADA O COMPROBACION DE LA MAQUINA DE ESTADOS
//------------------------------------------------------


/**
 * Comprueba que FLAG_PLAYER_START esta activado para que
 * otra funcion se encargue de dar comienzo a la reproduccion
 * de la melodia (este flag es activado en ComienzaReproduccion)
 *
 * @param this Variable compartida de la maquina de estados
 * @return resultado de la operación lógica (1 si la función vale, 0 si no)
 */
int CompruebaPlayerStart (fsm_t* this){
	int result;
	piLock (FLAGS_KEY);
	result = (flags & FLAG_PLAYER_START);
	piUnlock (FLAGS_KEY);
	return result;
}

/**
 * Comprueba que FLAG_PLAYER_STOP esta activado para que otra funcion
 * se encargue de parar la reproduccion
 *
 * @param this Variable compartida de la maquina de estados
 * @return resultado de la operación lógica (1 si la función vale, 0 si no)
 */
int CompruebaPlayerStop(fsm_t* this){
	int result;
	piLock (FLAGS_KEY);
	result = (flags & FLAG_PLAYER_STOP);
	piUnlock (FLAGS_KEY);
	return result;

}

/**
 * Comprueba que FLAG_PLAYER_END esta activado para que otra funcion
 * se encargue de terminar el reproductor
 *
 * @param this Variable compartida de la maquina de estados
 * @return resultado de la operación lógica (1 si la función vale, 0 si no)
 */
int CompruebaFinalMelodia (fsm_t* this){
	int result;
	piLock (FLAGS_KEY);
	result = (flags & FLAG_PLAYER_END);
	piUnlock (FLAGS_KEY);
	return result;
}

/**
 * Comprueba que FLAG_PLAYER_END esta desactivado para que otra funcion
 * se encargue de reproducir la siguiente nota de la melodía
 *
 * @param this Variable compartida de la maquina de estados
 * @return resultado de la operación lógica (1 si la función vale, 0 si no)
 */
int CompruebaNuevaNota (fsm_t* this){
	int result;
	piLock (FLAGS_KEY);
	result = ~flags & FLAG_PLAYER_END;
	piUnlock (FLAGS_KEY);
	return result;
}

/**
 * Comprueba que FLAG_NOTA_TIMEOUT esta activado, es decir que la ultima nota
 * ha sido reproducida en su totalidad para que otra funcion de paso a la
 * siguiente nota
 *
 * @param this Variable compartida de la maquina de estados
 * @return resultado de la operación lógica (1 si la función vale, 0 si no)

 */
int CompruebaNotaTimeout (fsm_t* this){
	int result;
	piLock (FLAGS_KEY);
	result = (flags & FLAG_NOTA_TIMEOUT);
	piUnlock (FLAGS_KEY);
	return result;
}

//Nuevas funciones de comprobacion de la version 5

/**
 * Comprueba que FLAG_SYSTEM_START esta activado para pasar al siguiente
 * estado (WAIT_CARD) este flag se activa al pulsar s
 *
 * @param this Variable compartida de la maquina de estados
 * @return resultado de la operación lógica (1 si la función vale, 0 si no)
 */
int CompruebaComienzo(fsm_t* this){
	int result;
	piLock (FLAGS_KEY);
	result = (flags & FLAG_SYSTEM_START);
	piUnlock (FLAGS_KEY);
	return result;
}

/**
 *  Comprueba si no hay una tarjeta insertada, viendo si
 *  FLAG_CARD_IN esta desactivado
 *
 * @param this Variable compartida de la maquina de estados
 * @return resultado de la operación lógica (1 si la función vale, 0 si no)
 */
int TarjetaNoDisponible(fsm_t* this){
	int result;
	piLock (FLAGS_KEY);
	result = ~flags & FLAG_CARD_IN;
	piUnlock (FLAGS_KEY);
	return result;
}

/**
 * Comprueba si hay una tarjeta insertada, viendo si
 * FLAG_CARD_IN esta activado
 *
 * @param this Variable compartida de la maquina de estados
 * @return resultado de la operación lógica (1 si la función vale, 0 si no)
 */
int TarjetaDisponible(fsm_t* this){
	int result;
		piLock (FLAGS_KEY);
		result = flags & FLAG_CARD_IN;
		piUnlock (FLAGS_KEY);
		return result;
}

/**
 * Comprueba que FLAG_VALID_CARD esta desactivado para que otra funcion
 * posteriormente descarte esa tarjeta
 *
 * @param this Variable compartida de la maquina de estados
 * @return resultado de la operación lógica (1 si la función vale, 0 si no)
 */
int TarjetaNoValida(fsm_t* this){
	int result;
	piLock (FLAGS_KEY);
	result = ~flags & FLAG_VALID_CARD;
	piUnlock (FLAGS_KEY);
	return result;

}

/**
 * Comprueba que FLAG_VALID_CARD esta activado para que otra funcion
 * posteriormente comience la reproduccion de la melodia asignada a
 * esa tarjeta
 *
 * @param this Variable compartida de la maquina de estados
 * @return resultado de la operación lógica (1 si la función vale, 0 si no)
 */
int TarjetaValida(fsm_t* this){
	int result;
		piLock (FLAGS_KEY);
		result = flags & FLAG_VALID_CARD;
		piUnlock (FLAGS_KEY);
		return result;

}

/**
 * Comprueba que FLAG_SYSTEM_END esta activado (se activa en FinalizaMelodia),
 * indicando que el sistema ha finalizado todo su proceso
 *
 * @param this Variable compartida de la maquina de estados
 * @return resultado de la operación lógica (1 si la función vale, 0 si no)
 */
int CompruebaFinalReproduccion(fsm_t* this){
	int result;
	piLock (FLAGS_KEY);
	result = (flags & FLAG_SYSTEM_END);
	piUnlock (FLAGS_KEY);
	return result;
}



//------------------------------------------------------
// FUNCIONES DE SALIDA O ACCION DE LA MAQUINA DE ESTADOS
//------------------------------------------------------
/**
 * Se encarga de crear un objeto TipoMelodia
 *
 * @return El numero de notas de la melodia
 * @param melodia zona de memoria donde hay un TipoMelodia
 * @param nombre el nombre de de la melodia
 * @param array_frecuencias array con las frecuencias de la melodia
 * @param array_duraciones array con las duraciones de las frecuencias de la melodia
 * @param num_notas numero de notas de las melodia
 */
int InicializaMelodia (TipoMelodia *melodia, char *nombre, int *array_frecuencias, int *array_duraciones, int num_notas) {
	int i;

	strcpy(melodia->nombre,nombre);

	melodia->num_notas=num_notas;

	for(i=0;i<num_notas;i++){
		melodia->frecuencias[i]=array_frecuencias[i];
	}

	for(i=0;i<num_notas;i++){
		melodia->duraciones[i]=array_duraciones[i];
	}

	return melodia->num_notas;
}


/**
 * Se encarga de anunciar el inicio de la reproduccion y reproducir la primera nota
 * (establece la posicion inicial de la nota, trazas por terminal, timer, etc...)
 * Además de apagar FLAG_PLAYER_START, para que cuando se haya reproducido la melodia o esta
 * se pare no se vuelva a iniciar
 *
 * @param this Variable compartida de la maquina de estados
 */
void InicializaPlayer (fsm_t* this){
	piLock (FLAGS_KEY);
	flags &= ~FLAG_PLAYER_START;
	piUnlock (FLAGS_KEY);
	TipoSistema *misistema;
	misistema=(TipoSistema *) this->user_data;
	misistema->player.melodia = &(misistema->tarjetas_activas[misistema->pos_tarjeta_actual].melodia);
	misistema->player.posicion_nota_actual = 0;
	misistema->player.frecuencia_nota_actual =
		misistema->player.melodia -> frecuencias[misistema->player.posicion_nota_actual];
	misistema->player.duracion_nota_actual =
			misistema->player.melodia -> duraciones[misistema->player.posicion_nota_actual];
	misistema->player.tmr = misistema->tmr;
	piLock (STD_IO_BUFFER_KEY);
	printf("\n[PLAYER][InicializaPlayer][NOTA 1][FREC %d][DURA %d]\n", misistema->player.frecuencia_nota_actual,
			misistema->player.duracion_nota_actual);
	softToneCreate(18);
	softToneWrite(18,misistema->player.frecuencia_nota_actual);
	tmr_startms((tmr_t*)misistema->player.tmr,misistema->player.duracion_nota_actual);
	piUnlock (STD_IO_BUFFER_KEY);
}


/**
 * Se encarga de reproducir el resto de notas de la melodia,
 * accediendo al reproductor y reproduciendo la nota siguiente a la actual,
 * ademas si nos encontramos en la ultima nota se encarga de encender FLAG_PLAYER_END para
 * avisar al sistema de que la reproduccion a finalizado
 *
 * @param this Variable compartida de la maquina de estados
 */
void ActualizaPlayer (fsm_t* this){
	piLock (FLAGS_KEY);
	flags &= ~FLAG_NOTA_TIMEOUT;
	piUnlock (FLAGS_KEY);
	TipoSistema *misistema;
	misistema=(TipoSistema *) this->user_data;
	misistema->player.posicion_nota_actual++;
	if(misistema->player.posicion_nota_actual<=(misistema->player.melodia->num_notas)-1){
		misistema->player.frecuencia_nota_actual = misistema->player.melodia->frecuencias[misistema->player.posicion_nota_actual];
		misistema->player.duracion_nota_actual = misistema->player.melodia->duraciones[misistema->player.posicion_nota_actual];
		piLock (STD_IO_BUFFER_KEY);
		printf("\n[PLAYER][ActualizaPlayer][NUEVA NOTA (%d DE %d)]",
			(misistema->player.posicion_nota_actual)+1, misistema->player.melodia->num_notas);
			fflush(stdout);
		piUnlock (STD_IO_BUFFER_KEY);
	}

	if(misistema->player.posicion_nota_actual == (misistema->player.melodia->num_notas)){
		piLock (FLAGS_KEY);
		flags |= FLAG_PLAYER_END;
		piUnlock (FLAGS_KEY);
		piLock (STD_IO_BUFFER_KEY);
		printf("\n[PLAYER][ActualizaPlayer][REPRODUCIDAS TODAS LAS NOTAS]\n");
		piUnlock (STD_IO_BUFFER_KEY);
	}
}


/**
 * Para la reproduccion de la melodia,
 * activa FLAG_SYSTEM_START, para que la segunda maquina de estados
 * pase de WAIT_START2 a WAIT_CARD, ya que si no se quedaria estancada
 *
 * @param this Variable compartida de la maquina de estados
 */
void StopPlayer (fsm_t* this){
	piLock (FLAGS_KEY);
	flags  &= ~FLAG_PLAYER_STOP;
	flags  |= FLAG_SYSTEM_START;
	piUnlock (FLAGS_KEY);
	piLock (STD_IO_BUFFER_KEY);
	printf("\n[PLAYER][StopPlayer][MELODIA PARADA, VUELVE A INSERTAR TARJETA PARA VOLVER A EMPEZAR]\n");
	softToneWrite(18,0);
	piUnlock (STD_IO_BUFFER_KEY);
	TipoSistema *misistema;
	misistema=(TipoSistema *) this->user_data;
	misistema->player.frecuencia_nota_actual = 0;

}

/**
 * Apaga todos los flags referentes a la primera maquina de estados
 * además de encender FLAG_SYSTEM_END para indicar la finalizacion del
 * ciclo del sistema (para volver a WAIT_START2)
 *
 * @param this Variable compartida de la maquina de estados
 */
void FinalMelodia (fsm_t* this){
	piLock (FLAGS_KEY);
	flags &= ~FLAG_PLAYER_START;
	flags &= ~FLAG_PLAYER_STOP;
	flags &= ~FLAG_PLAYER_END;
	flags &= ~FLAG_NOTA_TIMEOUT;
	flags |= FLAG_SYSTEM_END;
	piUnlock (FLAGS_KEY);
	piLock (STD_IO_BUFFER_KEY);
	printf("\n[PLAYER][FinalMelodia][Final de la cancion, inserta una tarjeta de nuevo]\n");
	softToneWrite(18,0);
	piUnlock (STD_IO_BUFFER_KEY);
}

/**
 * Se encarga de imprimir por pantalla datos sobre la nota que se comienza a reproducir,
 * además comienza un timer con la duracion de la nota, para que cuando acabe se compruben
 * las funciones de entrada de la maquina de estados
 *
 * @param this Variable compartida de la maquina de estados
 */
void ComienzaNuevaNota (fsm_t* this){
	piLock (STD_IO_BUFFER_KEY);
	TipoSistema *misistema;
	misistema=(TipoSistema *) this->user_data;
	if(misistema->player.posicion_nota_actual<=(misistema->player.melodia->num_notas)-1){
		misistema->player.frecuencia_nota_actual = misistema->player.melodia->frecuencias[misistema->player.posicion_nota_actual];
		misistema->player.duracion_nota_actual = misistema->player.melodia->duraciones[misistema->player.posicion_nota_actual];
		printf("\n[PLAYER][ComienzaNuevaNota][NOTA %d][FREC %d][DURA %d]\n",
			(misistema->player.posicion_nota_actual)+1, misistema->player.frecuencia_nota_actual,
			misistema->player.duracion_nota_actual);
			fflush(stdout);
			softToneCreate(18);
			softToneWrite(18,misistema->player.frecuencia_nota_actual);
	}
	piUnlock (STD_IO_BUFFER_KEY);
	tmr_startms((tmr_t*)misistema->player.tmr,misistema->player.duracion_nota_actual);
}


//Funciones de salida de la vresion 5

/**
 * Apaga todos los flags, para que FLAG_SYSTEM START esté apagado
 * Informa al usuario del inicio del sistema
 *
 * @param this Variable compartida de la maquina de estados
 */
void ComienzaSistema(fsm_t* this){
	piLock (FLAGS_KEY);
	flags = 0;
	piUnlock (FLAGS_KEY);
	piLock (STD_IO_BUFFER_KEY);
	printf("\n[READER][ComienzaSistema]Se ha iniciado el sistema\n");
	printf("\n[READER][ComienzaSistema]Esperando a detectar tarjeta...\n");
	fflush(stdout);
	piUnlock (STD_IO_BUFFER_KEY);
}

/**
 * Informa al usuario de que no hay ninguna tarjeta insertada
 *
 * @param this Variable compartida de la maquina de estados
 */
void EsperoTarjeta(fsm_t* this){
	piLock (STD_IO_BUFFER_KEY);
	printf("\n[READER][EsperoTarjeta] No se ha podido detectar la tarjeta, vuelve a intentarlo\n");
	fflush(stdout);
	piUnlock (STD_IO_BUFFER_KEY);
}

/**
 * Se encarga de leer la tarjeta en el lector RFID y comprobar
 * que su ID coincide con una de las IDs guardadas en las tarjetas,
 * para ver si es una tarjeta válida, en ese caso, activa FLAG_VALID_CARD,
 * y guarda la melodia correspondiente (previamente creada en main con InicializaMelodia)
 * dentro del reproductor del sistema, para que esa melodia sea la reproducida
 * Finalmente avisa al usuario de la validez de la tarjeta y dice melodia elegida.
 *
 * @param this Variable compartida de la maquina de estados
 */
void LeerTarjeta(fsm_t* this){
	TipoSistema *misistema;
	misistema=(TipoSistema*) this->user_data;

	piLock (STD_IO_BUFFER_KEY);
	printf("\n[READER][LeerTarjeta]Leyendo la tarjeta, espera un segundo...");
	fflush(stdout);
	char card_id[MAX_NUM_CHAR_UID];

	strcpy(card_id, read_id());
	piUnlock (STD_IO_BUFFER_KEY);

	int i =0;
	for(i = 0; i<=1; i++){
		int isValid = strcmp(misistema->tarjetas_activas[i].uid, card_id);
		if(isValid == 0){
			piLock (FLAGS_KEY);
			flags |= FLAG_VALID_CARD;
			piUnlock (FLAGS_KEY);
			misistema->pos_tarjeta_actual = i;
			misistema->player.melodia = &(misistema->tarjetas_activas[i].melodia);

			piLock (STD_IO_BUFFER_KEY);
			printf("\n[READER]Tarjeta Valida\n");
			printf("\n[READER]Has escogido: %s \n", misistema->player.melodia->nombre);
			fflush(stdout);
			piUnlock (STD_IO_BUFFER_KEY);
		}
	}
}

/**
 * Al no haberse activado FLAG_VALID_CARD por tener la tarjeta una ID no valida,
 * esta funcion de salida se encarga de informar de ello
 *
 * @param this Variable compartida de la maquina de estados
 */
void DescartaTarjeta(fsm_t* this){
	piLock (FLAGS_KEY);
	flags &= ~FLAG_CARD_IN;
	piUnlock (FLAGS_KEY);
	piLock (STD_IO_BUFFER_KEY);
	printf("\n[READER]Lo siento, la tarjeta introducida no es valida\n");
	printf("\n[READER]Prueba a volver a intentarlo con otra tarjeta\n");
	fflush(stdout);
	piUnlock (STD_IO_BUFFER_KEY);
}

/**
 * Funcion de salida que, una vez establecida la melodia y preparado
 * el sistema activa FLAG_PLAYER_START para que la primera maquina de estados
 * se inicie y comience la reproduccion de la melodia.
 *
 *  @param this Variable compartida de la maquina de estados
 */
void ComienzaReproduccion(fsm_t* this){
	piLock (FLAGS_KEY);
	flags |= FLAG_PLAYER_START;
	piUnlock (FLAGS_KEY);
	piLock (STD_IO_BUFFER_KEY);
	printf("\n[READER]Comienza la reproduccion\n");
	fflush(stdout);
	piUnlock (STD_IO_BUFFER_KEY);
}

/**
 * Actualiza FLAG_CARD_IN para que otra funcion se encargue
 * de parar la melodia en el caso de extraccion de la tarjeta
 *
 * @param this Variable compartida de la maquina de estados
 */
void ComprueboTarjeta(fsm_t* this){
	if(digitalRead(5)==LOW){
		piLock (FLAGS_KEY);
		flags |= FLAG_CARD_IN;
		piUnlock (FLAGS_KEY);
		}
	if(digitalRead(5)==HIGH){
		piLock (FLAGS_KEY);
		flags &= ~FLAG_CARD_IN;
		piUnlock (FLAGS_KEY);
		}
}

/**
 * En el caso de que la tarjeta haya sido extraida, se encarga de
 * activar FLAG_PLAYER_STOP para que efectivamente, la primera maquina
 * de estados vuelva a su estado inicial y se pare la reproduccion de la melodia
 *
 * @param this Variable compartida de la maquina de estados
 */
void CancelaReproduccion(fsm_t* this){
	TipoSistema *misistema;
	misistema=(TipoSistema *) this->user_data;
	piLock (FLAGS_KEY);
	flags |= FLAG_PLAYER_STOP;
	piUnlock (FLAGS_KEY);
	piLock (STD_IO_BUFFER_KEY);
	printf("\n[READER]La tarjeta ha sido extraida, se ha parado el proceso\n");
	softToneWrite(18,0);
	misistema->player.frecuencia_nota_actual = 0;
	piUnlock (STD_IO_BUFFER_KEY);
}

/**
 * Funcion que se ejecuta tras la activacion de FLAG_SYSTEM_END,
 * pone los flags a cero, para el posterior inicio del sistema e
 *  informa al usuario del final de la canción
 *
 * @param this Variable compartida de la maquina de estados
 */
void FinalizaReproduccion(fsm_t* this){
	piLock (STD_IO_BUFFER_KEY);
	printf("\n[READER]Final de la cancion, introduzca otra tarjeta para volver a empezar\n");
	TipoSistema *misistema;
	misistema=(TipoSistema *) this->user_data;
	misistema->player.frecuencia_nota_actual = 0;
	piUnlock (STD_IO_BUFFER_KEY);
	piLock (FLAGS_KEY);
	flags |= FLAG_SYSTEM_START;
	piUnlock (FLAGS_KEY);

}


//------------------------------------------------------
// FUNCIONES DE INICIALIZACION
//------------------------------------------------------

/**
 * Se encarga se inicializar los componentes esenciales
 *
 * @return 1 si todo ha ido correctamente
 */
int system_setup (void) {
	//Rutina de la RaspberryPi
	piLock(STD_IO_BUFFER_KEY);
	if (wiringPiSetupGpio () < 0) {
		printf ("Unable to setup wiringPi\n");
		piUnlock (STD_IO_BUFFER_KEY);
		return -1;
    }

	//Control de interrrupciones
	pinMode (5, INPUT);
	wiringPiISR (5, INT_EDGE_BOTH, &COMPRUEBA_FLANCO);

	//Rutina del lector de tarjetas
	initialize_rfid();

	//Pin para la salida de audio
	softToneCreate(18);
	piUnlock (STD_IO_BUFFER_KEY);
	return 1;
}

//Atencion a la interrupcion
/**
 * En primer lugar comprueba la señal del optoacoplador
 * (en nuestro caso es activacion a nivel bajo), por ello si la señal
 * es "LOW" activa FLAG_CARD_IN, indicando que, efectivamente hay una tarjeta insertada,
 * en el caso contrario lo mantiene a cero.
 */
void COMPRUEBA_FLANCO(void){
	if(digitalRead(5)==LOW){
		piLock (FLAGS_KEY);
		flags |= FLAG_CARD_IN;
		piUnlock (FLAGS_KEY);
	}else{
		piLock (FLAGS_KEY);
		flags &= ~FLAG_CARD_IN;
		piUnlock (FLAGS_KEY);
		}
}

/**
 * Pone todos los flags a 0
 * Inicia el flag inicial de la segunda maquina de estados,
 * para pasar al siguiente estado, algo asi como un power button
 * (WAIT_START2 -> WAIT_CARD)
 */
void fsm_setup(fsm_t* player_fsm) {
	piLock (FLAGS_KEY);
	flags = 0;
	flags |= FLAG_SYSTEM_START;
	piUnlock (FLAGS_KEY);
}

/**
 * La funcion main se encarga de hacer que funcione el programa, es
 * el codigo que se corre cuando ejecutamos el ejecutable, en ella,
 * inicializamos el timer y las dos melodias correspondientes a las tarjetas
 * Además definimos las tablas de transiciones de las maquinas de estados del
 * programa y creamos dichas maquinas de estados.
 * Finalmente, inicializamos el sistema y las maquinas de estados previamente definidas
 * y las comenzamos dentro de un bucle infinito
 *
 * @return codigo de salida (process finished with exit code XX)
 */
int main () {
	//Variables fundamentales del sistema (temporizadores y sistema)
	tmr_t* tmr = tmr_new (timer_isr);
	unsigned int next;
	TipoSistema sistema;
	sistema.tmr = tmr;

	//Creacion de las melodias y posterior guardado en las tarjetas
	InicializaMelodia (&(sistema.tarjetas_activas[0].melodia), "STARWARS", frecuenciaStarwars, tiempoStarwars, 59);
	InicializaMelodia (&(sistema.tarjetas_activas[1].melodia), "GoT", frecuenciaGOT, tiempoGOT, 518);

	//Asignacion de las IDs de cada tarjeta a su respectiva melodia
	strcpy(sistema.tarjetas_activas[0].uid, uid0);
	strcpy(sistema.tarjetas_activas[1].uid, uid1);
	sistema.num_tarjetas_activas= 2;

	// Maquina de estados: lista de transiciones
	// {EstadoOrigen,FunciónDeEntrada,EstadoDestino,FunciónDeSalida}
	fsm_trans_t reproductor[] = {
		{ WAIT_START,   CompruebaPlayerStart,  WAIT_NEXT, InicializaPlayer },
		{ WAIT_NEXT, CompruebaNotaTimeout, WAIT_END, ActualizaPlayer },
		{ WAIT_NEXT, CompruebaPlayerStop, WAIT_START, StopPlayer },
		{ WAIT_END, CompruebaNuevaNota, WAIT_NEXT, ComienzaNuevaNota },
		{ WAIT_END, CompruebaFinalMelodia, WAIT_START, FinalMelodia },
		{ -1, NULL, -1, NULL },
	};

	fsm_trans_t lector[] = {
		{ WAIT_START2, CompruebaComienzo,  WAIT_CARD, ComienzaSistema },
		{ WAIT_CARD, TarjetaNoDisponible, WAIT_CARD, EsperoTarjeta },
		{ WAIT_CARD, TarjetaDisponible, WAIT_CHECK, LeerTarjeta },
		{ WAIT_CHECK, TarjetaNoValida, WAIT_CARD, DescartaTarjeta },
		{ WAIT_CHECK, TarjetaValida, WAIT_PLAY, ComienzaReproduccion },
		{ WAIT_PLAY, CompruebaFinalReproduccion, WAIT_START2, FinalizaReproduccion },
		{ WAIT_PLAY, TarjetaDisponible, WAIT_PLAY, ComprueboTarjeta },
		{ WAIT_PLAY, TarjetaNoDisponible, WAIT_START2, CancelaReproduccion },
		{ -1, NULL, -1, NULL },
	};

	//Creacion de las maquinas de estados
	fsm_t* player_fsm = fsm_new (WAIT_START, reproductor, &sistema);
	fsm_t* reader_fsm = fsm_new (WAIT_START2, lector, &sistema);

	// Configuracion e inicializacion del sistema
	system_setup();
	fsm_setup (player_fsm);
	next = millis();
	while (1) {
		fsm_fire (player_fsm);
		fsm_fire (reader_fsm);
		next += CLK_MS;
		delay_until (next);
	}

	//En caso de que una excepcion ocurra, y se salga del bucle,
	//para que el programa se pare
	tmr_destroy ((tmr_t*)(player_fsm->user_data));
	fsm_destroy (player_fsm);
	tmr_destroy ((tmr_t*)(reader_fsm->user_data));
	fsm_destroy (reader_fsm);
}

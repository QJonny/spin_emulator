/****a* spinn_api.h/spinn_api_header
*
* SUMMARY
*  SpiNNaker API main header file
*
* AUTHOR
*  Luis Plana - lap@cs.man.ac.uk
*
* DETAILS
*  Created on       : 03 May 2011
*  Version          : $Revision: 1645 $
*  Last modified on : $Date: 2012-01-13 15:09:32 +0000 (Fri, 13 Jan 2012) $
*  Last modified by : $Author: plana $
*  $Id: spin1_api.h 1645 2012-01-13 15:09:32Z plana $
*  $HeadURL: https://solem.cs.man.ac.uk/svn/spin1_api/trunk/src/spin1_api.h $
*
* COPYRIGHT
*  Copyright (c) The University of Manchester, 2011. All rights reserved.
*  SpiNNaker Project
*  Advanced Processor Technologies Group
*  School of Computer Science
*
*******/

#ifndef __SPINN_API_H__
#define __SPINN_API_H__


#include "spinnaker.h"
#include "spinn_sdp.h"


// --------------------------------
/* virtual and physical core IDs */
// --------------------------------
extern uint virt_cpu;
extern uint phys_cpu;

// ------------------------------------------------------------------------
// Useful SpiNNaker parameters
// ------------------------------------------------------------------------
/* shared memory */
/* system RAM address and size */
#define SPINN_SYSRAM_BASE     SYSRAM_BASE
#define SPINN_SYSRAM_SIZE     SYSRAM_SIZE
/* SDRAM address and size */
#define SPINN_SDRAM_BASE      SDRAM_BASE
#define SPINN_SDRAM_SIZE      SDRAM_SIZE

// ------------------------------------------------------------------------
// general parameters and definitions
// ------------------------------------------------------------------------
/* boolean constants */
#define TRUE               (0 == 0)
#define FALSE              (0 != 0)
/* function results   */
#define SUCCESS            (uint) 1
#define FAILURE            (uint) 0
/* Null pointer value */
#define NULL               0

// ------------------------------------------------------------------------
// event definitions
// ------------------------------------------------------------------------
// event-related parameters
#define NUM_EVENTS            5
#define MC_PACKET_RECEIVED    0
#define DMA_TRANSFER_DONE     1
#define TIMER_TICK            2
#define SDP_PACKET_RX         3 // !! ST
#define USER_EVENT            4
// ------------------------------------------------------------------------


// ------------------------------------------------------------------------
// DMA transfer parameters
// ------------------------------------------------------------------------
// DMA transfer direction (from core point of view)
#define DMA_READ           0
#define DMA_WRITE          1


// ------------------------------------------------------------------------
// packet parameters
// ------------------------------------------------------------------------
// payload presence
#define NO_PAYLOAD         0
#define WITH_PAYLOAD       1


// ------------------------------------------------------------------------
// type definitions
// ------------------------------------------------------------------------
// !! ST typedef unsigned char  uchar;
// !! ST typedef unsigned int   uint;
// !! ST typedef unsigned short ushort;

typedef void (*callback_t) (uint, uint);  // callbacks
// ------------------------------------------------------------------------


// ------------------------------------------------------------------------
// simulation control functions
// ------------------------------------------------------------------------
uint spin1_start(void);
void spin1_stop(void);
void spin1_kill(uint error);
void spin1_set_timer_tick(uint time);
void spin1_set_core_map(uint chips, uint * core_map);
uint spin1_get_simulation_time(void);
void spin1_delay_us (uint n);
// ------------------------------------------------------------------------


// ------------------------------------------------------------------------
// callback and task functions
// ------------------------------------------------------------------------
void spin1_callback_on(uint event_id, callback_t cback, int priority);
void spin1_callback_off(uint event_id);
uint spin1_schedule_callback(callback_t cback, uint arg0, uint arg1, uint priority);
uint spin1_trigger_user_event(uint arg0, uint arg1);
// ------------------------------------------------------------------------


// ------------------------------------------------------------------------
//  data transfer functions
// ------------------------------------------------------------------------
uint spin1_dma_transfer(uint tag, void *system_address, void *tcm_address, uint direction, uint length);
void spin1_memcpy(void *dst, void const *src, uint len);
// ------------------------------------------------------------------------


// ------------------------------------------------------------------------
//  communications functions
// ------------------------------------------------------------------------
uint spin1_send_mc_packet(uint key, uint data, uint load);
void spin1_flush_rx_packet_queue(void);
void spin1_flush_tx_packet_queue(void);
// ------------------------------------------------------------------------


// ------------------------------------------------------------------------
// SDP related functions
// ------------------------------------------------------------------------
void spin1_msg_free (sdp_msg_t *msg);
sdp_msg_t* spin1_msg_get (void);
uint spin1_send_sdp_msg (sdp_msg_t *msg, uint timeout);
// ------------------------------------------------------------------------


// ------------------------------------------------------------------------
//  interrupt control functions
// ------------------------------------------------------------------------
uint spin1_irq_disable(void);
uint spin1_fiq_disable(void);
uint spin1_int_disable(void);
void spin1_mode_restore(uint sr);
// ------------------------------------------------------------------------


// ------------------------------------------------------------------------
//  system resources access funtions
// ------------------------------------------------------------------------
uint  spin1_get_id(void);
uint  spin1_get_core_id(void);
uint  spin1_get_chip_id(void);
void  spin1_led_control (uint p);
uint  spin1_set_mc_table_entry(uint entry, uint key, uint mask, uint route);
void* spin1_malloc(uint bytes);
// ------------------------------------------------------------------------


#endif /* __SPINN_API_H__ */

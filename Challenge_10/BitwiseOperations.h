/*
 * BitwiseOperations.h
 *
 * Created: 2/13/2019 11:18:07 AM
 *  Author: AVE-LAP-057
 */ 


#ifndef BITWISEOPERATIONS_H_
#define BITWISEOPERATIONS_H_
#include "types.h"

/************************************************************************/
/* Bitwise Operations                                                   */
/************************************************************************/

#define SET_BIT(REG,BIT)   		((REG) = REG|(1<<BIT))
#define CLEAR_BIT(REG,BIT) 		((REG) = REG &~(1<<BIT))
#define GET_BIT(REG,BIT)		((REG)&((1<<BIT)))
#define TOGGLE_BIT(REG,BIT)		((REG)=((REG)^(1<<BIT))

#endif /* BITWISEOPERATIONS_H_ */
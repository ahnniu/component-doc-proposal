//*****************************************************************************
//
//! \file hd44780.h
//! \brief Prototypes for Character LCD HD44780 Driver.
//! \version 2.1.1.0
//! \date 10/18/2011
//! \author CooCoX
//! \copy
//!
//! Copyright (c)  2011, CooCoX 
//! All rights reserved.
//! 
//! Redistribution and use in source and binary forms, with or without 
//! modification, are permitted provided that the following conditions 
//! are met: 
//! 
//!     * Redistributions of source code must retain the above copyright 
//! notice, this list of conditions and the following disclaimer. 
//!     * Redistributions in binary form must reproduce the above copyright
//! notice, this list of conditions and the following disclaimer in the
//! documentation and/or other materials provided with the distribution. 
//!     * Neither the name of the <ORGANIZATION> nor the names of its 
//! contributors may be used to endorse or promote products derived 
//! from this software without specific prior written permission. 
//! 
//! THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
//! AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
//! IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
//! ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE 
//! LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
//! CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
//! SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
//! INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
//! CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
//! ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF 
//! THE POSSIBILITY OF SUCH DAMAGE.
//
//*****************************************************************************

#ifndef __HD44780_H__
#define __HD44780_H__

//*****************************************************************************
//
// If building with a C++ compiler, make all of the definitions in this header
// have a C binding.
//
//*****************************************************************************
#ifdef __cplusplus
extern "C"
{
#endif  
    
//*****************************************************************************
//
//! \addtogroup HD44780
//! @{
//
//*****************************************************************************


//*****************************************************************************
//
//! \addtogroup HD44780_Enum Enumeration
//!
//! \brief Directions that cursor move to. 
//!    
//! @{
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup HD44780_Entry_Mode Cursor Move Direction
//!
//! \brief Directions that cursor move to. 
//!    
//! @{
//
//*****************************************************************************
//
//! Cursor move dirction is increment
//
#define HD44780_MOVE_DIRECTION_INC                                            \
                                0x02
//
//! Cursor move dirction is decrement
//
#define HD44780_MOVE_DIRECTION_DEC                                            \
                                0x00
//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup HD44780_Character_Font Character Font
//!
//! \brief HD44780 Chracter Font setting. 
//!    
//! @{
//
//*****************************************************************************

//
//! Character font is 5*10
//
#define HD44780_CHARACTER_FONT_5X10                                           \
                                0x04
//
//! Character font is 5*8
//
#define HD44780_CHARACTER_FONT_5X8                                            \
                                0x00

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! \addtogroup HD44780_Config_Interface_DL Interface Data Length 
//!
//! \brief HD44780 Interface Data Length setting. 
//!    
//! @{
//
//*****************************************************************************
//
//! Interface data length is 8 bit, use [D7-D0].
//
#define HD44780_INTERFACE_DATA_LEN_8                                          \
                                0x10
//
//! Interface data length is 4 bit, only use [D7-D4].
//
#define HD44780_INTERFACE_DATA_LEN_4                                          \
                                0x00
//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! @}
//
//*****************************************************************************                                

//*****************************************************************************
//
//! \addtogroup HD44780_Exported_APIs  API Refrence
//! \brief API Refrence of HD44780 Driver.
//! @{
//
//*****************************************************************************
extern void HD44780Init(void);

extern void HD44780EntryModeSet(unsigned char ucCursorMoveDirection, 
                                xtBoolean bDisplayShift);
extern void HD44780DisplayClear(void);

extern void HD44780DisplayOn(void);
extern void HD44780DisplayOff(void);
extern void HD44780CursorOn(xtBoolean bBlink);
extern void HD44780CursorOff(void);

extern void HD44780DisplayString(const char* pcString);
extern void HD44780DisplayN(unsigned long n);

extern void HD44780Home(void);
extern void HD44780LocationSet(unsigned char x, unsigned char y);

extern void HD44780CursorLeftMove(unsigned char n);
extern void HD44780CursorRightMove(unsigned char n);
extern void HD44780DisplayLeftShift(unsigned char n);
extern void HD44780DisplayRightShift(unsigned char n);

//
// If the LCD API can not meet your need, you can use the API below operated 
// on the lowlayer.
//
extern xtBoolean HD44780Busy(void);
extern void HD44780WriteCmd(unsigned char ucCmd);
extern void HD44780WriteData(unsigned char ucData);
extern unsigned long HD44780ReadState(void);
extern unsigned long HD44780ReadData(void);

//*****************************************************************************
//
//! @}
//
//*****************************************************************************

//*****************************************************************************
//
//! @}
//
//*****************************************************************************


//*****************************************************************************
//
// Mark the end of the C bindings section for C++ compilers.
//
//*****************************************************************************
#ifdef __cplusplus
}
#endif

#endif //__HD44780_H__

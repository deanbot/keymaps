#pragma once

#include QMK_KEYBOARD_H

// OUT__L or OUT__R include outer column (additional pinky column)

//              +--------+---------+---------+---------+--------+
#define BASE_L1 ___Q___, ___W___, ___F___, ___P___, ___B___
#define BASE_L2 ___A___, ___R___, ___S___, ___T___, ___G___
#define BASE_L3 ___Z___, ___X___, ___C___, ___D___, ___V___
//              +--------+---------+---------+---------+--------+
#define BASE_R1 ___J___, ___L___, ___U___, ___Y___, _SQUOT_
#define BASE_R2 ___M___, ___N___, ___E___, ___I___, ___O___
#define BASE_R3 ___K___, ___H___, _COMMA_, __DOT__, _SCOLN_
//              +--------+---------+---------+---------+--------+
#define BOUT_L1 _______
#define BOUT_L2 _______
#define BOUT_L3 _______
#define BOUT_R1 _______
#define BOUT_R2 _______
#define BOUT_R3 _______
//              +--------+---------+---------+---------+--------+
#define MIR__L1 _SQUOT_, ___Y___, ___U___, ___L___, ___J___
#define MIR__L2 ___O___, ___I___, ___E___, ___N___, ___M___
#define MIR__L3 _SCOLN_, __DOT__, _COMMA_, ___H___, ___K___
//              +--------+---------+---------+---------+--------+
#define MIR__R1 ___B___, ___P___, ___F___, ___W___, ___Q___
#define MIR__R2 ___G___, ___T___, ___S___, ___R___, ___A___
#define MIR__R3 ___V___, ___D___, ___C___, ___X___, ___Z___
//              +--------+---------+---------+---------+--------+
#define MIOUT_1 _BKSPC_
#define MIOUT_2 _SPACE_
#define MIOUT_3 _O_SFT_
//              +--------+---------+---------+---------+--------+
#define NAV__L1 _ACTIO_, __CUT__, _COPY__, _PASTE_, _HINT__
#define NAV__L2 _O_GUI_, _O_CTL_, _O_ALT_, _O_SFT_, _LEAD__
#define NAV__L3 _DRTAN_, _CAPSW_, _REDO__, _UNDO__, _COLS__
//              +--------+---------+---------+---------+--------+
#define NAV__R1 _PROJ__, _GOTOD_, _PGDWN_, _PG_UP_, _GOTOE_
#define NAV__R2 _SEL_L_, _LEFT__, _DOWN__, __UP___, _RIGHT_
#define NAV__R3 _NEWFL_, _FINDF_, _MATCH_, __DEL__, _GOTOL_
//              +--------+---------+---------+---------+--------+
#define NOUT_L1 _______
#define NOUT_L2 _______
#define NOUT_L3 _______
#define NOUT_R1 _______
#define NOUT_R2 _______
#define NOUT_R3 _______
//              +--------+---------+---------+---------+--------+
#define SYM__L1 _TILDE_, _LCBRC_, _LBRAC_, _LPARN_, _ARROW_
#define SYM__L2 _MINUS_, _PLUS__, _EQUAL_, _UNDRS_, _HASH__
#define SYM__L3 _ASTER_, _PIPE__, __AT___, _SLASH_, _PERCT_
//              +--------+---------+---------+---------+--------+
#define SYM__R1 _CIRCF_, _RPARN_, _RBRAC_, _RCBRC_, _GRAVE_
#define SYM__R2 _DOLLR_, _O_SFT_, _O_ALT_, _O_CTL_, _O_GUI_
#define SYM__R3 _TYPE__, _BSLSH_, _AMPRS_, _EXCLM_, _QUEST_
//              +--------+---------+---------+---------+--------+
#define NUM__L1 ___7___, ___5___, ___3___, ___1___, ___9___
#define NUM__L2 _O_GUI_, _O_CTL_, _O_ALT_, _O_SFT_, __F11__
#define NUM__L3 __F7___, __F5___, __F3___, __F1___, __F9___
//              +--------+---------+---------+---------+--------+
#define NUM__R1 ___8___, ___0___, ___2___, ___4___, ___6___
#define NUM__R2 __F12__, _O_SFT_, _O_ALT_, _O_CTL_, _O_GUI_
#define NUM__R3 __F8___, __F1___, __F2___, __F4___, __F6___
//              +--------+---------+---------+---------+--------+
#define GUI__L1 _MWLFT_, _MWUP__, _MWDWN_, _MWRGT_, __MB3__
#define GUI__L2 _MLFT__, __MUP__, _MDWN__, _MRGT__, __MB2__
#define GUI__L3 _T_LFT_, _T_TOP_, _T_BTM_, _T_RGT_, _ADDRS_
//              +--------+---------+---------+---------+--------+
#define GUI__R1 _QUIT__, _TAB_L_, _TAB_R_, _RETAB_, _CLOSE_
#define GUI__R2 _SWWIN_, _O_SFT_, _O_ALT_, _O_CTL_, _O_GUI_
#define GUI__R3 __HUD__, _BACK__, _JUMP__, __FWD__, _HIDE__
//              +--------+---------+---------+---------+--------+
#define MSE__L1 _MWLFT_, _MWUP__, _MWDWN_, _MWRGT_, __MB3__
#define MSE__L2 _MLFT__, __MUP__, _MDWN__, _MRGT__, __MB2__
#define MSE__L3 _T_LFT_, _T_TOP_, _T_BTM_, _T_RGT_, _ADDRS_
//              +--------+---------+---------+---------+--------+
#define MSE__R1 __MB3__, _MWLFT_, _MWDWN_, _MWUP__, _MWRGT_
#define MSE__R2 __MB2__, _MLFT__, _MDWN__, __MUP__, _MRGT__
#define MSE__R3 _ADDRS_, _T_LFT_, _T_TOP_, _T_BTM_, _T_RGT_
//              +--------+---------+---------+---------+--------+
#define DBG__L1 _______, _______, _______, _______, _______
#define DBG__L2 _______, _DSOUT_, _DS_IN_, _DT_OV_, _RESUM_
#define DBG__L3 _______, _______, _______, _______, _______
//              +--------+----- ----+---------+---------+--------+
#define DBG__R1 _RSTRT_, _______, _______, _______, _______
#define DBG__R2 _RLOAD_, _TOGBR_, _START_, _STOP__, _______
#define DBG__R3 _RESUM_, _DT_OV_, _DS_IN_, _DSOUT_, _______
//              +--------+---------+---------+---------+--------+
#define META_L1 _SLEEP_, _______, _______, CMB_TOG, _______
#define META_L2 _PSCRL_, _BRUP__, _BRDWN_, _TMSMU_, _______
#define META_L3 _______, _______, _______, _______, _RESET_
//              +--------+---------+---------+---------+--------+
#define META_R1 RGB_VAD, __PRV__, _PLYPS_, __NXT__, RGB_VAI
#define META_R2 _TMSMU_, _MUTE__, _VDWN__, __VUP__, RGB_TOG
#define META_R3 RGB_HUD, RGB_MOD, RGB_SPD, RGB_SPI, RGB_HUI
//              +--------+---------+---------+---------+--------+

// Bottom Row
// L or R includes Primary and Secondary
// LT or RT includes Tertiary
// LQ or RQ includes Quaternary

// primary/secondary
#define BASEx_L _MONAV_, _O_SFT_
#define BASEx_R _SPGUI_, _MOSYM_

// tertiary
#define BASExLT __MB1__
#define BASExRT _MODBG_

#define BASExL3 BASEx_L , BASExLT
#define BASExR3 BASExRT , BASEx_R

// quaternary
#define BASExLQ KC_MUTE
#define BASExRQ _TMSMU_

//
#define NAVx__L _______, _______
#define NAVx_LT _______
#define NAVx_RT _SPACE_
#define NAVX_RQ _PSCRL_
#define NAVx_LQ _______
#define NAVx__R _BKSPC_, _______

#define NAV_xL3 NAVx__L , NAVx_LT
#define NAV_xR3 NAVx_RT , NAVx__R

//
#define MIRx__L _______, _______
#define MIRx_LT _______
#define MIRx_RT _______
#define MIRx__R _______, _______
//
#define SYMx__L _______, _SCOLN_
#define SYMx_LT _SQUOT_
#define SYMx_RT _______
#define SYMx__R _______, _______

#define SYM_xL3 SYMx__L , SYMx_LT
#define SYM_xR3 SYMx_RT , SYMx__R

//
#define NUMx__L _______, _______
#define NUMx_LT _______
#define NUMx_RT _______
#define NUMx__R _______, _______
//
#define GUIx__L _MMETA_, __MB1__
#define GUIx_LT __MB2__
#define GUIx_RT _______
#define GUIx_LQ BASExLQ
#define GUIx_RQ TG(_GUI)
#define GUIx__R _______, _______

#define GUI_xL3 GUIx__L , GUIx_LT
#define GUI_xR3 GUIx_RT , GUIx__R

//
#define MSEx__L _______, _______
#define MSEx_LT __MB2__
#define MSEx_RT __MB2__
#define MSEx_LQ _______
#define MSEx_RQ _______
#define MSEx__R _______, _______
//
#define DBGx__L _______, _______
#define DBGx_LT _______
#define DBGx_RT _______
#define DBGx__R _______, _______

#define DBG_xL3 DBGx__L , DBGx_LT
#define DBG_xR3 DBGx_RT , DBGx__R
//
#define METAx_L _______, _______
#define METAxLT _______
#define METAxRT _______
#define METAx_R _______, _______

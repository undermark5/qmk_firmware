/* Copyright 2020 undermark5
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "quantum.h"
#define KNO KC_NO

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
#define LAYOUT( \
    K00,      K01, K02, K03, K04,   K05, K06, K07, K08,   K09, K10, K11, K12,    K13, K14, K15, K16, \
                                                                                                     \
    K35, K34, K33, K32, K31, K30, K29, K28, K27, K26, K25, K24, K23,   K21  ,    K20, K19, K18, K17, \
     K36 , K37, K38, K39, K40, K41, K42, K43, K44, K45, K46, K47, K48,  K49 ,    K50, K51, K52, K53, \
      K69 , K68, K67, K66, K65, K64, K63, K62, K61, K60, K59, K58,    K57   ,    K56, K55, K54,      \
        K70 , K71, K72, K73, K74, K75, K76, K77, K78, K79, K80,      K81    ,    K83, K84, K85, K86, \
     K97, K96 , K95 ,              K94            ,  K93 ,  K92,  K91 , K90 ,    K89, K88, K87       \
) { \
    { K00, K01, K02, K03, K04, K05, K06, K07, K08, K09 }, \
    { K10, K11, K12, K13, K14, K15, K16, K17, K18, K19 }, \
    { K20, K21, KNO, K23, K24, K25, K26, K27, K28, K29 }, \
    { K30, K31, K32, K33, K34, K35, K36, K37, K38, K39 }, \
    { K40, K41, K42, K43, K44, K45, K46, K47, K48, K49 }, \
    { K50, K51, K52, K53, K54, K55, K56, K57, K58, K59 }, \
    { K60, K61, K62, K63, K64, K65, K66, K67, K68, K69 }, \
    { K70, K71, K72, K73, K74, K75, K76, K77, K78, K79 }, \
    { K80, K81, KNO, K83, K84, K85, K86, K87, K88, K89 }, \
    { K90, K91, K92, K93, K94, K95, K96, K97, KNO, KNO }, \
}

/*#define LAYOUT_7U(
 K00,      K10, K20, K30, K40,   K50, K60, K70, K80,   K90, K01, K11, K21,    K31, K41, K51, K61, \
                                                                                                  \
 K53, K43, K33, K23, K13, K03, K92, K82, K72, K62, K52, K42, K32,   K12  ,    K02, K91, K81, K71, \
  K63 , K73, K83, K93, K04, K14, K24, K34, K44, K54, K64, K74, K84,  K94 ,    K05, K15, K25, K35, \
   K96 , K86, K76, K66, K56, K46, K36, K26, K16, K06, K95, K85,    K75   ,    K65, K55, K45,      \
     K07 , K17, K27, K37, K47, K57, K67, K77, K87, K97, K08,      K18    ,    K38, K48, K58, K68, \
  K79, K69 , K59 ,                 K49                ,  K29,  K19 , K09 ,    K98, K88, K78       \
) { \
 { K00, K01, K02, K03, K04, K05, K06, K07, K08, K09 }, \
 { K10, K11, K12, K13, K14, K15, K16, K17, K18, K19 }, \
 { K20, K21, KNO, K23, K24, K25, K26, K27, KNO, K29 }, \
 { K30, K31, K32, K33, K34, K35, K36, K37, K38, KNO }, \
 { K40, K41, K42, K43, K44, K45, K46, K47, K48, K49 }, \
 { K50, K51, K52, K53, K54, K55, K56, K57, K58, K59 }, \
 { K60, K61, K62, K63, K64, K65, K66, K67, K68, K69 }, \
 { K70, K71, K72, K73, K74, K75, K76, K77, K78, K79 }, \
 { K80, K81, K82, K83, K84, K85, K86, K87, K88, KNO }, \
 { K90, K91, K92, K93, K94, K95, K96, K97, K98, KNO }, \
}*/

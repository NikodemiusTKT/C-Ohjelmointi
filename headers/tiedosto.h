/*******************************************************************/
/* CT60A0220 C-ohjelmoinnin ja testauksen perusteet 
 * Otsikkotiedot: C-ohjelmoinnin harjoitustyö
 * Tekijät: Teemu Tanninen 0508505
 *          Joonas Hakkarainen 0438374
 *          Henrik Peteri 0452868
 * Päivämäärä: 12.03.17
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 * C-kieli ohjelmointiopas, Kasurinen & Nikula 2012
 */
/*******************************************************************/

#ifndef TIEDOSTO_H
#define TIEDOSTO_H

/* Tarvittavat kirjastot */
#include <stdio.h>
#include <stdlib.h>


/* Funktioesittelyt */
int lue_tiedosto(tuotetiedot **pAlku_tuotteet, char *tuotetiedosto);
int kirjoita_lokitiedosto(palautustiedot *pAlku_palautukset, tuotetiedot *pAlku_tuotteet, char* l_nimi);
int kirjoita_valiaikainen(tuotetiedot *pAlku_tuotteet, palautustiedot *pAlku_palautukset, char* v_nimi);


#endif

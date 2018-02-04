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

#ifndef TIETORAKENTEET_H
#define TIETORAKENTEET_H

/* Tarvittavat kirjastot */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/* Rakenne linkitetylle tuotelistalle */
struct tuotelista {
    int id;
    char *tyyppi;
    float koko;
    float pantti;
    struct tuotelista *seuraava;
};

/* Rakenne linkitetylle palautelistalle */
struct palautelista {
    int id;
    struct palautelista *seuraava;
};


/* Uudet nimet tietorakenteille */
typedef struct tuotelista tuotetiedot;
typedef struct palautelista palautustiedot;

/* Funktioesittelyt */
int lisaa_tuote(tuotetiedot **pAlku_tuotteet, int id, char* tyyppi, float koko, float pantti);
int tulostus(tuotetiedot *pAlku_tuotteet);
int lisaa_palautus(palautustiedot **pAlku_palautukset, tuotetiedot *pAlku_tuotteet, int id);
int laske_kaikki_palautukset(palautustiedot *pAlku_palautukset);
tuotetiedot* hae_tuotetiedot_listasta(tuotetiedot *pAlku_tuotteet, int id);
int laske_tuotteen_palautukset(palautustiedot *pAlku_palautukset, int id);
int tulosta_kuitti(palautustiedot *pAlku_palautukset, tuotetiedot *pAlku_tuotteet, int luku);
float laske_pantit(palautustiedot *pAlku_palautukset, tuotetiedot *pAlku_tuotteet);
int tyhjenna_palautukset(palautustiedot **pAlku_palautukset);
int tyhjenna_tuotteet(tuotetiedot **Palku_tuotteet);

#endif

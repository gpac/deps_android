/*
 * Copyright (C) 2008 The Android Open Source Project
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */
#ifndef _LOCALE_OSMO_H_
#define _LOCALE_OSMO_H_

#include <sys/cdefs.h>

__BEGIN_DECLS

enum {
    LC_CTYPE     = 0,
    LC_NUMERIC   = 1,
    LC_TIME      = 2,
    LC_COLLATE   = 3,
    LC_MONETARY  = 4,
    LC_MESSAGES  = 5,
    LC_ALL       = 6,
    LC_PAPER     = 7,
    LC_NAME      = 8,
    LC_ADDRESS   = 9,

    LC_TELEPHONE      = 10,
    LC_MEASUREMENT    = 11,
    LC_IDENTIFICATION = 12
};

//BEGIN added by Luyen
/* Structure giving information about numeric and monetary notation.  */
struct lconv
{
  /* Numeric (non-monetary) information.  */

  char *decimal_point;		/* Decimal point character.  */
  char *thousands_sep;		/* Thousands separator.  */
  /* Each element is the number of digits in each group;
     elements with higher indices are farther left.
     An element with value CHAR_MAX means that no further grouping is done.
     An element with value 0 means that the previous element is used
     for all groups farther left.  */
  char *grouping;

  /* Monetary information.  */

  /* First three chars are a currency symbol from ISO 4217.
     Fourth char is the separator.  Fifth char is '\0'.  */
  char *int_curr_symbol;
  char *currency_symbol;	/* Local currency symbol.  */
  char *mon_decimal_point;	/* Decimal point character.  */
  char *mon_thousands_sep;	/* Thousands separator.  */
  char *mon_grouping;		/* Like `grouping' element (above).  */
  char *positive_sign;		/* Sign for positive values.  */
  char *negative_sign;		/* Sign for negative values.  */
  char int_frac_digits;		/* Int'l fractional digits.  */
  char frac_digits;		/* Local fractional digits.  */
  /* 1 if currency_symbol precedes a positive value, 0 if succeeds.  */
  char p_cs_precedes;
  /* 1 iff a space separates currency_symbol from a positive value.  */
  char p_sep_by_space;
  /* 1 if currency_symbol precedes a negative value, 0 if succeeds.  */
  char n_cs_precedes;
  /* 1 iff a space separates currency_symbol from a negative value.  */
  char n_sep_by_space;
  /* Positive and negative sign positions:
     0 Parentheses surround the quantity and currency_symbol.
     1 The sign string precedes the quantity and currency_symbol.
     2 The sign string follows the quantity and currency_symbol.
     3 The sign string immediately precedes the currency_symbol.
     4 The sign string immediately follows the currency_symbol.  */
  char p_sign_posn;
  char n_sign_posn;
#ifdef __USE_ISOC99
  /* 1 if int_curr_symbol precedes a positive value, 0 if succeeds.  */
  char int_p_cs_precedes;
  /* 1 iff a space separates int_curr_symbol from a positive value.  */
  char int_p_sep_by_space;
  /* 1 if int_curr_symbol precedes a negative value, 0 if succeeds.  */
  char int_n_cs_precedes;
  /* 1 iff a space separates int_curr_symbol from a negative value.  */
  char int_n_sep_by_space;
  /* Positive and negative sign positions:
     0 Parentheses surround the quantity and int_curr_symbol.
     1 The sign string precedes the quantity and int_curr_symbol.
     2 The sign string follows the quantity and int_curr_symbol.
     3 The sign string immediately precedes the int_curr_symbol.
     4 The sign string immediately follows the int_curr_symbol.  */
  char int_p_sign_posn;
  char int_n_sign_posn;
#else
  char __int_p_cs_precedes;
  char __int_p_sep_by_space;
  char __int_n_cs_precedes;
  char __int_n_sep_by_space;
  char __int_p_sign_posn;
  char __int_n_sign_posn;
#endif
};
//END added by Luyen

extern char *setlocale(int category, const char *locale);

/* Make libstdc++-v3 happy.  */
//struct lconv { };
//struct lconv *localeconv(void);

struct lconv *localeconv (void)
{
  static struct lconv result;

  result.decimal_point = (char *) ",";
  result.thousands_sep = (char *) ".";
  result.grouping = (char *) "";

  result.int_curr_symbol = (char *) "e";
  result.currency_symbol = (char *) "e";
  result.mon_decimal_point = (char *) ".";
  result.mon_thousands_sep = (char *) "";
  result.mon_grouping = (char *) "";
  result.positive_sign = (char *) "+";
  result.negative_sign = (char *) "-";
  result.int_frac_digits = *(char *) "";
  result.frac_digits = *(char *) "";
  result.p_cs_precedes = *(char *) "";
  result.p_sep_by_space = *(char *) "";
  result.n_cs_precedes = *(char *) "";
  result.n_sep_by_space = *(char *) "";
  result.p_sign_posn = *(char *) "";
  result.n_sign_posn = *(char *) "";
  //result.int_p_cs_precedes = *(char *) "";
  //result.int_p_sep_by_space = *(char *) "";
  //result.int_n_cs_precedes = *(char *) "";
  //result.int_n_sep_by_space = *(char *) "";
  //result.int_p_sign_posn = *(char *) "";
  //result.int_n_sign_posn = *(char *) "";

  return &result;
}

__END_DECLS

#endif /* _LOCALE_H_ */

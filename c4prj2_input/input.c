#include<string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"
#include "cards.h"
#include "future.h"




deck_t * hand_from_string(const char * str, future_cards_t * fc)

  

deck_t ** read_input(FILE * f, size_t * n_hands, future_cards_t * fc){
  assert(f!=NULL);
  size_t num = 0;
  size_t sz = 0;
  char * line = NULL;
  deck_t ** r_deck = NULL;
  while(getline(&line, &sz, f)!=EOF){

    // create a hand from each valid line in file
    r_deck=realloc(r_deck,sizeof(* r_deck)*(num+1));
    deck_t * temp = hand_from_string(line,fc);
    if (temp!=NULL){
      // import "temp" to returned deck
      r_deck[num]=temp;
      num++;
    }else{
      // if line invalid go to next line or end if EOF
      continue;
    }


  }
  * n_hands = num;
  free(line);
  return r_deck;
}



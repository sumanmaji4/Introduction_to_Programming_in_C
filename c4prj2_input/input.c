#include<string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "deck.h"
#include "cards.h"
#include "future.h"




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




deck_t * hand_from_string(const char * str, future_cards_t * fc){
  deck_t* deck=malloc(sizeof(*deck));
  deck->cards = NULL;
  deck->n_cards=0;
  for(int i=0;i<strlen(str);i++){
    if((str[i] == '\n')||(str[i] == ' '))continue;
    else{
      if(str[i] == '?'){
	i++;
	char num[strlen(str)];
	int n=0;
	while(!((str[i] == '\n')||(str[i] == ' '))) {
	  num[n]=str[i];
	  i++;n++;}
	num[n]='\0';
	add_future_card(fc,atoi(num),add_empty_card(deck)) ;

      }
      else{
	card_t x = card_from_letters(str[i],str[i+1]);
	add_card_to(deck,x);
	i++;}
    }
  }
  if (deck->n_cards < 5 ){
    return NULL;
    fprintf(stderr,"asas");}
  return deck;
}





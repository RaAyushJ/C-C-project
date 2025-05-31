#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int getCardValue(char card) {
  if (card == 'A') {
    return 11;
  } else if (card >= '2' && card <= '9') {
    return card - '0';
  } else {
    return 10;
  }
}

int getHandValue(char* hand) {
  int value = 0;
  int hasAce = 0;
  for (int i = 0; hand[i] != '\0'; i++) {
    value += getCardValue(hand[i]);
    if (hand[i] == 'A') {
      hasAce = 1;
    }
  }
  if (hasAce && value > 21) {
    value -= 10;
  }
  return value;
}


char hit(char* hand) {
  char newCard;
  printf("Hitting...\n");
  newCard = rand() % 13 + '2'; // Generate random card between 2 and Ace
  strcat(hand, &(char){newCard}); // Cast newCard to char array before appending
  return newCard;
}

void playBlackjack() {
  char playerHand[10] = "";
  char dealerHand[10] = "";

  srand(time(NULL)); // Seed random number generator

  // Deal initial cards
  playerHand[0] = rand() % 13 + '2';
  playerHand[1] = rand() % 13 + '2';
  playerHand[2] = '\0';
  dealerHand[0] = rand() % 13 + '2';
  dealerHand[1] = rand() % 13 + '2';
  dealerHand[2] = '\0';

  printf("Your hand: %s\n", playerHand);
  printf("Dealer's hand: [X] %c\n", dealerHand[1]); // Show only one dealer card

  int playerValue = getHandValue(playerHand);
  int dealerValue;

  // Player turn
  while (1) {
    char choice;
    printf("Hit (h) or Stand (s)? ");
    scanf(" %c", &choice);

    if (choice == 'h') {
      hit(playerHand);
      playerValue = getHandValue(playerHand);
      printf("Your hand: %s (%d)\n", playerHand, playerValue);
      if (playerValue > 21) {
        printf("Busted!\n");
        break;
      }
    } else if (choice == 's') {
      break;
    } else {
      printf("Invalid choice. Please enter 'h' or 's'.\n");
    }
  }

  // Dealer turn (simple strategy - hits until 17 or busts)
  dealerValue = getHandValue(dealerHand);
  printf("Dealer's hand: %s (%d)\n", dealerHand, dealerValue);
  while (dealerValue < 17) {
    hit(dealerHand);
    dealerValue = getHandValue(dealerHand);
    printf("Dealer hits. Dealer's hand: %s (%d)\n", dealerHand, dealerValue);
  }

  // Determine winner
  if (playerValue > 21) {
    printf("You lose.\n");
  } else if (dealerValue > 21) {
    printf("You win!\n");
  } else if (playerValue > dealerValue) {
    printf("You win!\n");
  } else if (playerValue == dealerValue) {
    printf("Push (tie).\n");
  } else {
    printf("You lose.\n");
  }
}

int main() {
  printf("Welcome to Blackjack!\n");
  playBlackjack();
  return 0;
}

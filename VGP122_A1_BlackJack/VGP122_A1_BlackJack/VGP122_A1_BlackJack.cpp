// VGP122_A1_BlackJack.cpp
//

#include <iostream>
#include <algorithm>
#include <random>
#include <vector>

//Suits
enum class Suits
{
    Clubs,Diamonds,Hearts,Spades,
};
//Value
enum class CardNames
{
    Ace = 1,Two,Three,Four,Five,Six,Seven,Eight,Nine,Ten,Jack,Queen,King,
};

struct Card
{
    CardNames name;
    Suits suit;
    int value;
    
    void PrintCard()
    {
        PrintValue();
        std::cout << " of ";
        PrintSuit();
        std::cout << std::endl;
    }
    //the the proper names of each card Ace, 2, ... Jack, Queen, King 
    void PrintValue()
    {
        switch (name)
        {
        case CardNames::Ace: std::cout << "Ace"; break;
        case CardNames::Jack: std::cout << "Jack"; break;
        case CardNames::Queen: std::cout << "Queen"; break;
        case CardNames::King: std::cout << "King"; break;
        default: std::cout << value; break;
        }
    }
    // get the Suit of the card Clubs, Diamonds, Hearts, Spades.
    void PrintSuit()
    {
        switch (suit)
        {
        case Suits::Clubs: std::cout << "clubs"; break;
        case Suits::Diamonds: std::cout << "diamonds"; break;
        case Suits::Hearts: std::cout << "hearts"; break;
        case Suits::Spades: std::cout << "spades"; break;
        }
    }
};
//get the whole deck 
struct Deck
{
    int currentCard = 0;
    Card arrayCards[52];
    
    void PrintAll()
    {
        for (int suit = (int)Suits::Clubs; suit <= (int)Suits::Spades; suit++)
        {
            for (int name = (int)CardNames::Ace; name <= (int)CardNames::King; name++)
            {
                int index = (13 * suit) + name-1;

                arrayCards[index].PrintCard();
            }
        }
    }
    void SetUpCards()
    {
        for (int suit = (int)Suits::Clubs; suit <= (int)Suits::Spades; suit++)
        {
            for (int name = (int)CardNames::Ace; name <= (int)CardNames::King; name++)
            {
                Card c;
                c.suit = (Suits)suit;
                c.name = (CardNames)name;

                if (c.name == CardNames::Jack || c.name == CardNames::Queen || c.name == CardNames::King)
                {
                    c.value = 10;
                }
                else if (c.name == CardNames::Ace)
                {
                    c.value = 11;
                }
                else
                {
                    c.value = (int)c.name;
                }

                int index = (suit * 13) + (name - 1);

                arrayCards[index] = c;
            }
        }
    }
    //shuffle
    void Shuffle()
    {
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(std::begin(arrayCards), std::end(arrayCards), g);
        currentCard = 0;
    }
    Card DealCard()
    {
        if (currentCard < 52)
        {
            return arrayCards[currentCard++];

        }

    }
};
// Calculate the total value of the hand
int HandValue(const std::vector<Card>& hand)
{
    int total = 0;
    int aceCount = 0;

    for (const auto& card : hand)
    {
        total += card.value;
        if (card.name == CardNames::Ace)
        {
            aceCount++;
        }
    }

    // Adjust for Aces
    while (total > 21 && aceCount > 0)
    {
        total -= 10; // Convert an Ace from 11 to 1
        aceCount--;
    }

    return total;
}



int main()
{
    int credit = 1000;
    int bet;
    Deck deck;
    deck.SetUpCards();
    deck.Shuffle();

    while (credit > 0)
    {
        std::cout << "Current Credit: " << credit << std::endl;
        std::cout << "Enter your bet: ";
        std::cin >> bet;
        std::cout << std::endl;

        // Validate bet
        if (bet > credit)
        {
            std::cout << "Not enough credits. Please lower your bet!" << std::endl;
            continue;
        }

        // Deduct initial bet
        credit -= bet;
        std::vector<Card> PlayerHand;
        std::vector<Card> DealerHand;

        // Deal two cards to both player and dealer
        PlayerHand.push_back(deck.DealCard());
        PlayerHand.push_back(deck.DealCard());
        DealerHand.push_back(deck.DealCard());
        DealerHand.push_back(deck.DealCard());

        int playerTotal = HandValue(PlayerHand);
        int dealerTotal = HandValue(DealerHand);

        // Print initial hands
        std::cout << "-- Dealer's Card --" << std::endl;
        DealerHand[0].PrintCard(); // Only show one dealer card initially

        std::cout << "-- Player's Cards --" << std::endl;
        PlayerHand[0].PrintCard();
        PlayerHand[1].PrintCard();
        std::cout << "Player Total: " << playerTotal << std::endl;

        // Player's turn
        bool playerTurn = true;
        bool doubleDown = false;

        while (playerTurn)
        {
            if (playerTotal < 21)
            {
                char move;
                std::cout << "Choose: Hit (h), Stand (s), Double Down (d)" << std::endl;
                std::cin >> move;

                if (move == 'h' || move == 'H')
                {
                    // Hit: Deal a new card to the player
                    PlayerHand.push_back(deck.DealCard());
                    PlayerHand.back().PrintCard();

                    playerTotal = HandValue(PlayerHand);
                    std::cout << "Player Total: " << playerTotal << std::endl;
                }
                else if (move == 's' || move == 'S')
                {
                    // Stand: End player's turn
                    std::cout << "Player stands." << std::endl;
                    playerTurn = false;
                }
                else if (move == 'd' || move == 'D')
                {
                    // Double Down: Double bet, deal one more card, and end turn
                    if (bet * 2 <= credit)
                    {
                        bet *= 2;
                        std::cout << "Bet doubled to: " << bet << std::endl;

                        PlayerHand.push_back(deck.DealCard());
                        PlayerHand.back().PrintCard();

                        playerTotal = HandValue(PlayerHand);
                        std::cout << "Player Total: " << playerTotal << std::endl;
                        playerTurn = false;
                        doubleDown = true;
                    }
                    else
                    {
                        std::cout << "Not enough credits to double down!" << std::endl;
                    }
                }
            }

            // Check if player busts
            if (playerTotal > 21)
            {
                std::cout << "Player busts!" << std::endl;
                playerTurn = false;
            }
        }

        // Dealer's turn
        std::cout << "-- Dealer's Turn --" << std::endl;
        DealerHand[0].PrintCard(); // Print dealer's first card again
        DealerHand[1].PrintCard(); // Print dealer's second card
        std::cout << "Dealer Total: " << dealerTotal << std::endl;

        while (dealerTotal < 17 && dealerTotal>=21)
        {
            DealerHand.push_back(deck.DealCard());
            DealerHand.back().PrintCard();

            dealerTotal = HandValue(DealerHand);
            std::cout << "Dealer Total: " << dealerTotal << std::endl;
        }

        // Final Results
        std::cout << "___________ Final Score ___________" << std::endl;
        std::cout << "Player Total: " << playerTotal << std::endl;
        std::cout << "Dealer Total: " << dealerTotal << std::endl;

        // Determine the outcome
        //bust
        if (playerTotal > 21)
        {
            std::cout << "Player loses this round." << std::endl;
        }
        //win
        else if (dealerTotal > 21 || playerTotal > dealerTotal)
        {
            int winnings = bet * 2;
            std::cout << "Player wins! You receive: " << winnings << " credits." << std::endl;
            credit += winnings;
        }
        //lose
        else if (playerTotal < dealerTotal)
        {
            std::cout << "Dealer wins this round." << std::endl;
        }
        //tie
        else
        {
            std::cout << "It's a tie. You receive your bet back: " << bet << " credits." << std::endl;
            credit += bet;
        }

        // Reset player and dealer hand totals for next round
        PlayerHand.clear();
        DealerHand.clear();
        std::cout << "----------------------------------" << std::endl;
    }

    std::cout << "Game over! You have run out of credits." << std::endl;
    return 0;
}
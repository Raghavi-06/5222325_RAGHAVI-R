#include <stdio.h>

int towerBreakers(int n, int m) 
{
    //if the tower height is 1, no moves can be made.
    //player 1 loses.
    if (m == 1)
 {
        return 2;
    }
    
    //if the number of towers is even, Player 2 can mirror
    //player 1's moves, ensuring Player 2 always has a move.
    //the game ends with Player 1 having no moves.
    if (n % 2 == 0) 
{
        return 2;
    }
    
    //if the number of towers is odd and m > 1, Player 1 can
    //reduce one tower to 1. This leaves an even number of
    // towers for Player 2 to play on. Player 1 can then mirror
    // player 2's moves, eventually leaving Player 2 with no moves.
    return 1;
}

int main()
 {
    int t;
    scanf("%d", &t);
    while (t--)
 {
        int n, m;
        scanf("%d %d", &n, &m);
        printf("%d\n", towerBreakers(n, m));
    }
    return 0;
}

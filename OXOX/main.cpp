#include <iostream>
using namespace std;

int main()
{
    int player = 0;
    int winner = 0;
    int choice = 0;
    unsigned int row = 0;
    unsigned int column = 0;
    char board[3][3] =
    {
        {'1','2','3'},
        {'4','5','6'},
        {'7','8','9'},
    };

    for(unsigned int i = 0;i < 9 && winner == 0; i++)
    {
        for( int j = 0; j<3; j++)
        {
            for(int k = 0;k<3; k++)
            {
                cout  << " |"<< board[j][k] << "| ";
            }
            cout << endl;

        }
        cout << "----+----+----" << endl;
        player = i%2 + 1;

        do
        {
            cout << "Player " << player << " please enter a valid square number for where you want to place your: "
                 << (player == 1)?'X':'O';
            cin >> choice;
            row = --choice /3;
            column = choice %3;
        }while(choice < 0 || choice > 8 || board[row][column] > '9');
        board[row][column] = (player == 1)?'X':'O';

        if((board[0][0] == board[1][1] && board[0][0] == board[2][2]) ||
                (board[0][2] == board[1][1] && board[0][2] == board[2][0]))
            winner = player;
        else
        {
            for(unsigned int line = 0; line <= 2; ++line)
            {
                if((board[line][0] == board[line][1] && board[line][0] == board[line][2]) ||
                        board[0][line] == board[1][line] && board[0][line] == board[line][2])
                    winner = player;
            }
        }

    }

    for( int j = 0; j<3; j++)
    {
        for(int k = 0;k<3; k++)
        {
            cout  << " |"<< board[j][k] << "| ";
        }
        cout << endl;
    }
    if(winner)
        cout << "\n Congratulations,Player"<< winner << "you are the WINNER" << endl;
    else
        cout << "\n How boring,it's a draw " << endl;

    return 0;
}

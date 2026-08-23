#include <iostream>
#include <string>

using namespace std;


enum enGameChoice {Stone = 1, Paper = 2, Scissors = 3};

enum enWinner {Player1 = 1, Computer = 2, Draw = 3};

struct stRoundInfo
{
    short RoundNumber = 0;
    enGameChoice Player1Choice;
    enGameChoice ComputerChoice;
    enWinner Winner;
    string WinnerName = "";
};

struct stGameResult
{
    short GameRounds = 0;
    short Player1WinTimes = 0;
    short ComputerWinTimes = 0;
    short DrawTimes = 0;
    enWinner gameWinner;
    string WinnerName = "";
};

enGameChoice ReadPlayer1Choice()
{
    short Player1Choice = 0;
    do
    {
        cout << "What is your choice? Stone = [1], Paper = [2], Sceeser = [3]  :  ";
        cin >> Player1Choice;
    } while (Player1Choice > 3 || Player1Choice < 1);

    return enGameChoice(Player1Choice);
}

enGameChoice GetComputerChoice()
{
    short ComputerChoice = RandomNumber(1, 3);
    return enGameChoice(ComputerChoice);
}

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

enWinner WhoWonTheRound(const stRoundInfo& RoundInfo)
{
    if (RoundInfo.Player1Choice == RoundInfo.ComputerChoice)
        return enWinner::Draw;

    switch (RoundInfo.Player1Choice)
    {
    case enGameChoice::Stone:
        if (RoundInfo.ComputerChoice == Paper)
            return enWinner::Computer;
        break;
    case enGameChoice::Paper:
        if (RoundInfo.ComputerChoice == Scissors)
            return enWinner::Computer;
        break;
    case enGameChoice::Scissors:
        if (RoundInfo.ComputerChoice == Stone)
            return enWinner::Computer;
        break;

        

    }
    // if you get here is mene the Player1 is the winner.
  
        return enWinner::Player1;
}

int ReadPositiveNumber(std::string Message)
{
    int Number = 0;
    do
    {
        std::cout << Message << "\n";
        std::cin >> Number;
    } while (Number <= 0 || Number > 10);

    return Number;
}

string GetWinnerName(enWinner Winner)
{
    string arrWinnerNmae[3] = { "Player1", "Computer", "NO Winner" };
    return arrWinnerNmae[Winner - 1];
}

void SetWinnerScreenColor(enWinner Winner)
{
    switch (Winner)
    {
       case enWinner::Player1:
           system("color 2F");
           break;
       case enWinner::Computer:
           cout << "\a";
            system("color 4F");
           break;
       case enWinner::Draw:
            system("color 60");
           break;
   
    }
}

string ChoiceName(enGameChoice Choice)
{
    string arrGameChoice[3] = { "Stone " , "Paper" , "Scissors" };
    return arrGameChoice[Choice - 1];
}

void PrintRoundResult(const stRoundInfo& RoundInfo)
{
    cout << "\n----------------Round:[" << RoundInfo.RoundNumber << "]-----------------";
    cout << "\nPlayer1 choice        :" << ChoiceName(RoundInfo.Player1Choice);
    cout << "\nComputer choice       :" << ChoiceName(RoundInfo.ComputerChoice);
    cout << "\nRound Winner          :" << RoundInfo.WinnerName;
    cout << "\n--------------------------------------------------\n" << endl;

    SetWinnerScreenColor(RoundInfo.Winner);
}

enWinner WhoWonTheGame(const stGameResult& GameResult)
{
    if (GameResult.Player1WinTimes > GameResult.ComputerWinTimes)
        return enWinner::Player1;
    else if (GameResult.Player1WinTimes < GameResult.ComputerWinTimes)
        return enWinner::Computer;
    else
        return enWinner::Draw;
}

stGameResult FillGameResult(short GameRounds, short Player1WinTimes, short ComputerWinTimes, short DrawTimes)
{
    stGameResult GameResult;
    GameResult.GameRounds = GameRounds;
    GameResult.Player1WinTimes = Player1WinTimes;
    GameResult.ComputerWinTimes = ComputerWinTimes;
    GameResult.DrawTimes = DrawTimes;
    GameResult.gameWinner = WhoWonTheGame(GameResult);
    GameResult.WinnerName = GetWinnerName(GameResult.gameWinner);

    return GameResult;
}

string Tabs(short TabsNumber)
{
    string t = "";
    for (int i = 0; i < TabsNumber; i++) {

        t  = t + "\t";
    }


        return t;
}

void ShowTheFinaGameResult(const stGameResult& GameResult)
{
    cout << Tabs(2) << "-----------------------------------------------------------\n";
    cout << Tabs(2) << "______________________[Game Result]________________________\n";
    cout << Tabs(2) << "Game Rounds        : " << GameResult.GameRounds << endl;
    cout << Tabs(2) << "Player1 Win Times  : " << GameResult.Player1WinTimes << endl;
    cout << Tabs(2) << "Computer Win Times : " <<  GameResult.ComputerWinTimes << endl;
    cout << Tabs(2) << "Draw Times         : " << GameResult.DrawTimes << endl;
    cout << Tabs(2) << "Final Winner       : " << GameResult.WinnerName << endl;
    cout << Tabs(2) << "--------------------------------------------------------\n";

    SetWinnerScreenColor(GameResult.gameWinner);
}

void ScreenReset()
{
    system("cls");
    system("color 0F");
}

void ShowGameOverScreen()
{
    cout << Tabs(2) << "-----------------------------------------------------------------------------\n";
    cout << Tabs(2) << "                             Game Over\n";
    cout << Tabs(2) << "-----------------------------------------------------------------------------\n";
}

stGameResult PlayGame(short HowManyRound)
{
    stRoundInfo RoundInfo;
    short Player1WinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;
    for (int GameRound = 1; GameRound <= HowManyRound; GameRound++)
    {
        RoundInfo.RoundNumber = GameRound;
        RoundInfo.Player1Choice = ReadPlayer1Choice();
        RoundInfo.ComputerChoice = GetComputerChoice();
        RoundInfo.Winner = WhoWonTheRound(RoundInfo);
        RoundInfo.WinnerName = GetWinnerName(RoundInfo.Winner);


        if (RoundInfo.Winner == enWinner::Player1)
            Player1WinTimes++;
        else if (RoundInfo.Winner == enWinner::Computer)
            ComputerWinTimes++;
        else
            DrawTimes++;


        PrintRoundResult(RoundInfo);

    }
    return FillGameResult(HowManyRound, Player1WinTimes, ComputerWinTimes, DrawTimes);
}


void startGame()
{
    char PlayAgine = 'y';
    do 
    {
        ScreenReset();

        stGameResult GameReslut = PlayGame(ReadPositiveNumber("How Many Round you Want To Play? : [1] To [10]!"));

        ShowGameOverScreen();
         
        ShowTheFinaGameResult(GameReslut);

        cout << "\n\nDo you Want to play agine?  N / Y ?  ";
            cin >> PlayAgine;


    } while (PlayAgine == 'Y' || PlayAgine == 'y');
}


int main()
{
    srand((unsigned)time(NULL));  // Seed random number generator.
    startGame();


    return 0;
}

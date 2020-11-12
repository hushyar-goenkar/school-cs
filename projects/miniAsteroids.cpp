// Made By Samarth Nasnodkar.


#include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
using namespace std;
class myGame
{
  bool shot = false;
  int positionOfUser = 8;
  int positionOfEnemy;
  char input;
  int score = 0;
  bool showWinningScreen = false;
  bool won = false;
  // The blueprint of the map is Show below.
  // ====================
  // |    o             | available spaces = 19
  // |                  |
  // |                  |
  // |      You         |
  // |      Won         |
  // |                  |
  // |                  |
  // |                  |
  // |                  |
  // |       (--)       |
  // ====================
  public:
  void createMap(bool won = false)
  {
    // This function generates the map.
    srand(time(0));
    positionOfEnemy = rand()%19 + 1;
    for(int i=0;i<12;i++)
    {
      // The yes boolean is used to generate the shooting animation. cause the shooting animation should not continue beyond the enemy.
      bool yes = false;
      if(i != 0 or i!= 11 or i!= 1 or i!= 10)
      yes = true;
      else
      yes = false;

      for(int j=0;j<20;j++)
      {
        if(i == 0||i==11)
        {
          cout<<"=";
        }
        else
        {
          if(won)
          {
            // The won boolean signifies if the user has successfully hit the enemy or not.
            // If yes, It will create the You won screen.
            // If not, It will continue will the normal screen.
            if(j==0||j==19)
            cout<<"|";
            else if(j == 7 and i == 4)
            {
              cout<<"You";
              j = j + 2;
            }
            else if(j == 7 and i == 5)
            {
              cout<<"Won";
              j = j + 2;
            }
            else if(j == 7 and i == 6)
            {
              cout<<"Score:";
              j = j + 5;
            }
            else if(j == 7 and i == 7)
            {
              // Here when you display the score, The right boundary starts mooving hence, we need to increment j
              // for the amount of digits in the score with a constant.
              cout<<" "<<score;
              int temp = score;
              int count = 0;
              while(temp>0)
              {
                count += 1;
                temp = temp/10;
              }
              j = j + count;
            }
            else
            cout<<" ";
          }
          else
          {
            // Here the enemy is generated.
            if(j==0||j==19)
            cout<<"|";
            else if(i == 1 and j == positionOfEnemy)
            {
              cout<<"o";
            }
            else if(j == positionOfUser+1 and yes and shot)
            {
              // Here the shooting animation is generated.
              cout<<".";
            }
            else if(j == positionOfUser and i == 10)
            {
              // Object generation.
              cout<<"(--)";
              j = j + 3;
            }
            else
            cout<<" ";
          }

        }
      }
      cout<<endl;
    }
    shot = false;
  }
  int takeInput()
  {
    // This function takes the input from the user and returns the displacement of the user from its initial position.
    if(_kbhit())
    {
      char key;
      key = _getch();
      switch(key)
      {
        case 'd':
          return 1;
          break;
        case 'a':
          return -1;
          break;
        case 's':
          shot = true;
          showWinningScreen = true;
          break;
      }
    }
    return 0;
  }
  void udpatePosition()
  {
    // This function will update the user's position with the user input.
    int position = takeInput();
    if(position != 0)
    {
      positionOfUser += position;
      if(positionOfUser > 14)
      positionOfUser = 14;
      else if(positionOfUser < 2)
      positionOfUser = 2;
    }
  }
  bool hit()
  {
    // This function will return true if the enemy has been hit and false if not
    if(showWinningScreen)
    {
      if(positionOfEnemy - positionOfUser < 2 and positionOfEnemy - positionOfUser > -2)
      {
        showWinningScreen = false;
        score = score + 1;
        return true;
      }
      else
      {
        showWinningScreen = false;
        return false;
      }


    }

    return false;

  }

};

main()
{
  myGame g;
  cout<<"Use a , d keys to move to left and right respectively.\nAnd s to shoot.";
  Sleep(5000);
  while(true)
  {
    g.udpatePosition();
    g.createMap();
    Sleep(2);
    system("cls");
    if(g.hit())
    {
      g.createMap(true);
      Sleep(5000);
      system("cls");
    }

  }
}

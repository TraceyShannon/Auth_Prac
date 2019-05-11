#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

/*

  This program is an authentication and authorization system for a small database. I created This
  with the idea of data persistence while the program is running and losing it when it exits.
  Eventually I will come back and add in data persistence when the program closes and saving
  the information to a hidden file on your computer. In all of this I added a rock, paper,
  scissors game to make sure the data was holding up through the program. This program can let
  only one user at a time be logged in but while not logged in a user can check their profile
  as long as they have there identifier, username and password.

*/

struct users {

  char first_name[30];
  char last_name[30];
  int age;

  char user_name[30];
  char password[30];

  int last_score;
  int high_score;

};

// ==== Database Tracker ==== //
int users = 0;
int direct_user = 0;

struct users profiles[10];

void checker();

void print_interface();

void print_instructions();

int home_interactions_out();

int sign_in(struct users *);

void print_user(struct users);

void print_signed_instructions();

int home_interactions_in();

void read_information(struct users *);

void set_up_game(struct users *);

// ==== Begin Main Function ==== //
int main(int argc, char const *argv[]) {

  // ==== Interface Commands ==== //
  char quit[3] = "00";
  char enter_interface[3] = "77";

  char user_input[3];

  while (strcmp(user_input, quit) != 0) {

    printf("\n\t\t\t** Welcome To Honkeys!! **\n");

    printf("\n\t\t\t** Please Type 00 To Quit **\n");
    printf("\t\t\t** Please Type 77 To Enter Interface **\n\n\n\n");
    printf("Enter Code: ");

    scanf("%s", user_input);

    if (strcmp(user_input, quit) == 0) {
      printf("Bye!\n");
      return 0;
    } else if (strcmp(user_input, enter_interface) == 0) {
      home_interactions_out();
    } else {
      continue;
    }

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");


  }

  return 0;
}
// ==== End Main Function ==== //

void read_information(struct users *user) {

  printf("\nHello And Welcome New User!\n");
  printf("\nPlease Fill Out All THe Information Below To Get Started!\n\n");

  printf("Please Enter Your First Name: ");
  scanf("%s", user->first_name);

  printf("Please Enter Your Last Name: ");
  scanf("%s", user->last_name);

  printf("Please Enter Your Age: ");
  scanf("%d", &user->age);

  printf("Please Enter Your Cool New Username: ");
  scanf("%s", user->user_name);

  printf("Please Enter Your Super Secret Password: ");
  scanf("%s", user->password);

  printf("\nGreat We're All Done Here! Your Identifier Is: { %d }\n", users + 1);
  printf("\n** Please Remember That Number!! You'll Need It To Sign In And Check Your Profile **\n");

}

void print_user(struct users profile) {

  printf("||\t First Name: { %s } \t||", profile.first_name);
  printf("\tLast Name: { %s } \t||", profile.last_name);
  printf("\tUsername: { %s } \t||", profile.user_name);
  printf("\tAge: { %d } \t||", profile.age);
  printf("\tLast Score: { %d } \t||", profile.last_score);
  printf("\tHigh Score: { %d } \t||", profile.high_score);
  printf("\n");

}

void print_interface() {

  for (int i = 0; i < 160; i++) {
    printf("=");
  }
  printf("\n");

}

void print_instructions() {

  printf("\n** Please Type 00 To Quit **\n");
  printf("** Please Type 11 To Sign In **\n");
  printf("** Please Type 22 To Check Profile **\n");
  printf("** Please Type 33 To Create A New Profile **\n\n");

}

void print_signed_instructions() {

  // printf("\n** Please Type 00 To Quit **\n");
  printf("\n** Please Type 44 To Log Out **\n");
  printf("** Please Type 55 To Check Profile **\n");
  printf("** Please Type 66 To Play Rock, Paper, Scissors **\n\n");

}

int sign_in(struct users *profile) {

  char user_input_username[30];
  char user_input_password[30];

  for (int i = 0; i < users; i++) {

    while (strcmp(user_input_password, profile[i].password) != 0) {

      printf("Please Enter Your Username: ");
      scanf("%s", user_input_username);

      if (strcmp(user_input_username, profile[i].user_name) == 0) {
        printf("Please Enter Your Password: ");
        scanf("%s", user_input_password);

        if (strcmp(user_input_password, profile[i].password) == 0) {
          printf("\nCongragulations! Your Are Now Logged In!\n");
          printf("\n%s, Your Are Signed In!\n", profile->user_name);
          return 1;
        } else {
          printf("** Incorrect Information, Please Try Again **\n");
          // direct_user = 0;
          continue;
        }

      } else {
        continue;
      }

    }
  }

  return 0;
}

int home_interactions_out() {

  // ==== Interface Commands ==== //
  char quit[3] = "00";
  char log_in[3] = "11";
  char check_user[3] = "22";
  char create_user[3] = "33";

  char user_input[3];
  direct_user = 0;
  int signed_in = 0;

  while (strcmp(user_input, quit) != 0 || strcmp(user_input, log_in) != 0) {

    print_instructions();
    printf("Enter Code: ");

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n - - > ");

    scanf("%s", user_input);

    if (strcmp(user_input, quit) == 0) {
      printf("Bye!\n");
      return 0;
    } else if (strcmp(user_input, create_user) == 0) {
      read_information(&profiles[users]);
      users++;
    } else if (strcmp(user_input, check_user) == 0) {
      checker();
      direct_user = 0;
    } else if (strcmp(user_input, log_in) == 0) {

      if (users < 1) {
        printf("Sorry There Are No Profiles Here...\n");
        continue;
      }

      while (direct_user < 1 || direct_user > users) {
        printf("Please Enter User Identifier: ");
        scanf("%d", &direct_user);
      }

      signed_in = sign_in(&profiles[direct_user - 1]);

      if (signed_in == 1) {
        home_interactions_in();
        signed_in = 0;
        // direct_user = 0;
      }
    } else {
      continue;
    }

  }

  return 1;
}

int home_interactions_in() {

  // ==== Interface Commands ==== //
  char log_out[3] = "44";
  char check_user[3] = "55";
  char game[3] = "66";

  char user_input[3];

  while (strcmp(user_input, log_out) != 0) {

    print_signed_instructions();
    printf("Enter Code: ");

    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n - - > ");

    scanf("%s", user_input);

    if (strcmp(user_input, log_out) == 0) {
      direct_user = 0;
      printf("Now Logging You Out!\n");
      break;
    } else if (strcmp(user_input, check_user) == 0) {
      checker();
    } else if (strcmp(user_input, game) == 0) {
      set_up_game(&profiles[direct_user - 1]);
    } else {
      continue;
    }

  }

  return 0;
}

void checker() {

  int signed_in;

  if (users < 1) {
    printf("Sorry There Are No Profiles Here...\n");
  } else {
    while (direct_user < 1 || direct_user > users) {
      printf("Please Enter User Identifier: ");
      scanf("%d", &direct_user);
    }
    signed_in = sign_in(&profiles[direct_user - 1]);
    if (signed_in == 1) {
      print_interface();
      print_user(profiles[direct_user - 1]);
      print_interface();
    } else {
      direct_user = 0;
      return;
    }
  }

}

void set_up_game(struct users *profile) {

  // ==== Game Commands ==== //
  int rock = 1;
  int paper = 2;
  int scissors = 3;

  int user_input;
  int computer;

  int usr_score = 0;
  int com_score = 0;
  int rounds = 0;
  int counter = 0;

  srand(time(0));

  while (rounds <= 0 || rounds > 10) {
    printf("\n\nHow Many Rounds Would You Like To Play? **(No Less Than 1 And No Greater than 10)** - - >");
    scanf("%d", &rounds);
  }

  while (counter < rounds) {

    printf("Your Current Score: { %d }   ||   Computer Current Score: { %d } \n", usr_score, com_score);

    printf("\n\n** To Play Type { 1 } -> Rock, { 2 } -> Paper, { 3 } -> Scissors **\n");

    printf("Enter Your Play: ");

    computer = rand() % 3 + 1;
    scanf("%d", &user_input);

    if (user_input == computer) {
      printf("\n\nIts A Tie Baby! No Points Are Added During A Tie!\n\n");
    }

    if (user_input == 1) {
      if (computer == 2) {
        printf("\nComputer Wins This Round!! Congragulations Computer!!\n");
        printf("Computer: 'I'm So Happy To Have Won Using Paper!'\n");
        com_score += 100;
      } else if (computer == 3) {
        printf("\n%s Wins This Round!! Congragulations %s!\n", profile->user_name, profile->user_name);
        printf("The Computer Decided To Pick Scissors...\n");
        usr_score += 100;
      }
    } else if (user_input == 2) {
      if (computer == 3) {
        printf("\nComputer Wins This Round!! Congragulations Computer!!\n");
        printf("Computer: 'I'm So Happy To Have Won Using Scissors!'\n");
        com_score += 100;
      } else if (computer == 1) {
        printf("\n%s Wins This Round!! Congragulations %s!\n", profile->user_name, profile->user_name);
        printf("The Computer Decided To Pick Rock...\n");
        usr_score += 100;
      }
    } else if (user_input == 3) {
      if (computer == 1) {
        printf("\nComputer Wins This Round!! Congragulations Computer!!\n");
        printf("Computer: 'I'm So Happy To Have Won Using Rock!'\n");
        com_score += 100;
      } else if (computer == 2) {
        printf("\n%s Wins This Round!! Congragulations %s!\n", profile->user_name, profile->user_name);
        printf("The Computer Decided To Pick Paper...\n");
        usr_score += 100;
      }
    } else {
      printf("What Happened???? Maybe A Mis-type...\n");
      break;
    }

    counter++;

  }

  profile->last_score = usr_score;

  if (usr_score == com_score) {
    printf("\n\n** It's A Full Tie, A Draw, No One Wins, And You're Both Losers!! Congragulations!!! **\n");
  } else if (usr_score > com_score) {
    printf("\n\n** %s Wins! Your Score: { %d } || Computer Score: { %d } **\n", profile->user_name, usr_score, com_score);
  } else {
    printf("\n\n** Wow Congragulations Computer Look At Your Amazing Score: { %d }, And If You Want To You Can Look At %s's Wimpy Score: { %d } **\n", com_score, profile->user_name, usr_score);
  }

  if (profile->last_score > profile->high_score) {
    profile->high_score = profile->last_score;
  }

}

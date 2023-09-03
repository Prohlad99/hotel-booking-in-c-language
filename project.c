#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#include<stdbool.h>

#include<conio.h>

#define MAX 256

typedef struct account {
  char fname[15];
  char lname[15];
  char phone[14];
  char address[100];
  char pass[10];

}
account;

typedef struct booking {
  char name[10];
  char phone[14];
  char roomQ1[10];
  char roomQ2[10];
  char meal[10];
  char adate[15];
  char rdate[15];

}
booking;

void create_admin_account();
void create_user_account();
int search(char filename[1000]);
void booking_room();
void view_available_room();
void view_facalities();
void view_account_data();
void view_booking_data();
void admin_login();
void user_login();
void admin();
void user();
void hotel_management();
int count_line();
void delLine();

int main() {

  hotel_management();

  return 0;
}

void create_admin_account() {
  char ch;
  char adminPanel[10] = "admin";
  char adminPanel2[10];

  printf("\n\t\tEnter Admin Panel Password:");
  scanf("%s", adminPanel2);

  printf("\n\n");

  if (strcmp(adminPanel, adminPanel2) == 0) {
    int i;
    account a;
    FILE * fp;
    fp = fopen("adminAccount.txt", "a+");

    if (fp == NULL) {
      printf("\t\tFile Is Not Found!!!\n");
    } else {
      printf("\t\tEnter your first name: ");
      scanf("%s", a.fname);

      printf("\t\tEnter your last name: ");
      scanf("%s", a.lname);

      printf("\t\tEnter your phone: ");
      scanf("%s", a.phone);

      printf("\t\tEnter your address: ");
      scanf("%s", a.address);

      printf("\t\tCreate Password: ");
      for (i = 0; i < 10; i++) {
        ch = getch();
        a.pass[i] = ch;
        if (ch != 13) {
          printf("*");

        }
        if (ch == 13) {
          break;
        }

      }

      fprintf(fp, "%s\t%s\t%s\t%s\t\t%s\t\n", a.fname, a.lname, a.phone, a.address, a.pass);
      printf("\t\tYour Account Create Successfully\n\n");

    }

    fclose(fp);

  } else {
    printf("\t\tInvalid Password!!!\n\n");
  }

}

void create_user_account() {
  char ch;
  int i;
  account a;
  FILE * fp;
  fp = fopen("userAccount.txt", "a+");

  if (fp == NULL) {
    printf("\t\tFile Is Not Found!!!\n");
  } else {
    printf("\t\tEnter your first name: ");
    scanf("%s", a.fname);

    printf("\t\tEnter your last name: ");
    scanf("%s", a.lname);

    printf("\t\tEnter your phone: ");
    scanf("%s", a.phone);

    printf("\t\tEnter your address: ");
    scanf("%s", a.address);

    printf("\t\tCreate Password: ");
    for (i = 0; i < 10; i++) {
      ch = getch();
      a.pass[i] = ch;
      if (ch != 13) {
        printf("*");

      }
      if (ch == 13) {
        break;
      }

    }

    fprintf(fp, "%s\t%s\t%s\t%s\t\t%s\t\n", a.fname, a.lname, a.phone, a.address, a.pass);
    printf("\t\tYour Account Create Successfully\n\n");

  }

  fclose(fp);

}

void booking_room() {

  char c;
  int n;
  FILE * fp2;

  fp2 = fopen("avilable.txt", "r+");
  c = fgetc(fp2);
  n = c - '0';

  if (n > 0) {
    booking b;
    FILE * fp;
    fp = fopen("booking.txt", "a+");

    if (fp == NULL) {
      printf("\t\tFile Not Found!!!\n\n");
    } else {
      printf("\n\t\t-------Available Room-------:%d", n);
      printf("\t\nPlease Give Us Your Details: \n");
      printf("\t\tYour Name: ");
      scanf("%s", b.name);

      printf("\t\tPhone Number: ");
      scanf("%s", b.phone);

      printf("\t\tRoom Quality [AC/NON AC]: ");
      scanf("%s", b.roomQ1);

      printf("\t\tRoom Quality [Single/Double]: ");
      scanf("%s", b.roomQ2);

      printf("\t\tMeal [ON/OFF]: ");
      scanf("%s", b.meal);

      printf("\t\tArrival Date [dd/mm/yy]: ");
      scanf("%s", b.adate);

      printf("\t\tRelease Date [dd/mm/yy]: ");
      scanf("%s", b.rdate);

      printf("\t\t\nThanks For Giving Your Information\n\n");
      printf("Dear, %s If You Want To Confirm The Room You Have To Pay Advance 5%% From Total Bill\n\n", b.name);

      printf("\n\n\t\t1. Yes. I Want\n");
      printf("\t\t2. Don't Now\n");
      printf("\t\tChoice Your Option: ");
      int num;
      scanf("%d", & num);

      if (num == 1) {
        fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%s\n", b.phone, b.roomQ1, b.roomQ2, b.meal, b.adate, b.rdate);
        printf("\n\t\tYour Request Has Been Successful!!!\n");
        printf("\t\tThank You For Choice Us...\n\n");
        fprintf(fp2, "%d", n - 1);
        fclose(fp2);

      }

      if (num == 2) {
        printf("\t\t\nYour Request For Booking A Room Does Not Success!!!\n");
        printf("\t\tThank You\n\n");

      }

    }

    fclose(fp);
    // n=n-1;

  } else {
    printf("\t\tSorry!!! No Empty Room Is Available Current Now.\n\n");
  }

}

void view_available_room() {
  char c;
  int n;
  FILE * fp;

  fp = fopen("avilable.txt", "r+");
  c = fgetc(fp);
  n = c - '0';
  printf("%d", n + 1);
  fclose(fp);

}

int search(char filename[1000]) {
  int num = 0;
  int num2 = 0;
  char word[2000];
  char string[50];
  char phone[100] = {
    0
  };
  char password[100] = {
    0
  };
  int line = 0;

  while (phone[0] != '0') {
    FILE * in_file = fopen(filename, "r");
    if (in_file == NULL) {
      printf("\t\tError file missing\n");
      exit(-1);
    }

    printf("\t\tEnter You Phone Number: ");
    scanf("%s", phone);

    printf("\t\tEnter You Password: ");
    scanf("%s", password);
    while (fscanf(in_file, "%s", string) == 1) {
      if (strstr(string, phone) != 0) {
        num++;

      }
      if (strstr(string, password) != 0) {
        num2++;

      }
      if (string == 13) {
        line++;
      }
    }

    if (num == 0) {
      printf("\t\tInvalid User name or Password!!!\n\n");
    }

    fclose(in_file);
    break;
  }

  if (num > 0 && num2 > 0) {
    return 1;
  }

}

void view_facalities() {
  FILE * fp;

  fp = fopen("facilities.txt", "r");

  int c;
  while (1) {
    c = fgetc(fp);

    if (c == EOF) {
      break;
    }

    printf("%c", c);

  }

  fclose(fp);

}

void view_account_data() {
  FILE * fp;
  fp = fopen("userAccount.txt", "r");

  int c;

  while (1) {
    c = fgetc(fp);
    if (c == EOF) {
      break;
    }

    printf("%c", c);
  }

  fclose(fp);

}

auto void view_booking_data() {
  FILE * fp;

  fp = fopen("booking.txt", "r");

  int c;
  while (1) {

    c = fgetc(fp);
    if (c == EOF) {
      break;
    }
    printf("%c", c);

  }

  fclose(fp);

}

auto void admin_login() {

  int ch;

  int search_result = 0;
  search_result = search("adminAccount.txt");

  if (search_result) {

    do {
      printf("\n\n\t\t1. View User Account Data\n");
      printf("\t\t2. View Room Booking Data\n");
      printf("\t\t3. Remove Records From Booking\n");
      printf("\t\t0. Go Back\n");
      printf("\t\tEnter Your Choice: ");
      scanf("%d", & ch);

      switch (ch) {
      case 1: {
        view_account_data();
        break;
      }
      case 2: {
        view_booking_data();
        break;
      }

      case 3: {
        int n = count_line();
        printf("\n\t\tYour Data Stay In %d Number Line\n", n);
        delLine();

      }

      case 0:
        return 0;

      default:
        printf("\t\tInvalid Input!!!\n\n");

      }

    } while (ch != 0);
  }

}

auto void user_login() {

  int ch;

  int search_result = 0;
  search_result = search("userAccount.txt");

  if (search_result) {

    view_available_room();

    do {
      printf("\n\n\t\t1. View Hotel Facilities\n");
      printf("\t\t2. Booking A Room\n");
      printf("\t\t0. Go Back\n");
      printf("\t\tEnter Your Choice: ");
      scanf("%d", & ch);

      switch (ch) {
      case 1: {
        view_facalities();
        break;
      }
      case 2: {
        booking_room();
        break;
      }

      case 0:
        return 0;

      default:
        printf("\t\tInvalid Input!!!\n");

      }

    } while (ch != 0);
  }

}

auto void admin() {
  int ch;

  do {
    printf("\n\n\t\t1. Login\n");
    printf("\t\t2. Create An Account\n");
    printf("\t\t0. Go Back\n");
    printf("\t\tEnter Your Choice: ");
    scanf("%d", & ch);

    switch (ch) {
    case 1: {
      admin_login();
      break;

    }

    case 2: {
      create_admin_account();
      break;

    }

    case 0:
      return 0;

    default:
      printf("\n\t\tInvalid Input");

    }
  } while (ch != 0);

}

auto void user() {
  int ch;

  do {
    printf("\n\n\t\t1. Login\n");
    printf("\t\t2. Create An Account\n");
    printf("\t\t0. Go Back\n");
    printf("\t\tEnter Your Choice: ");
    scanf("%d", & ch);

    switch (ch) {
    case 1: {
      user_login();
      break;
    }

    case 2: {
      create_user_account();
      break;
    }

    case 0:
      return 0;

    default:
      printf("\t\t\nInvalid Input\n");

    }
  } while (ch != 0);

}

void hotel_management() {
  int ch;

  do {
    printf("\n\t\t1. User\n");
    printf("\t\t2. Admin\n");
    printf("\t\t0. Exit\n");
    printf("\t\tEnter Your Choice: ");
    scanf("%d", & ch);

    switch (ch) {
    case 1: {
      user();
      break;
    }

    case 2: {
      admin();
      break;
    }
    case 0:
      return 0;

    default:
      printf("\t\tInvalid Input\n");

    }

  } while (ch != 0);

}

int count_line() {
  char wrd[256], buffer[256];
  int n, m, i, j, line;

  FILE * fp;
  fp = fopen("booking.txt", "r");

  printf("\t\tEnter Email/Phone: ");
  scanf("%s", wrd);

  m = strlen(wrd);

  line = 0;
  while (fgets(buffer, 256, fp) != NULL) {

    i = 0;
    n = strlen(buffer);

    while (i < n) {

      j = 0;
      while (i < n && j < m && buffer[i] == wrd[j]) {
        ++i, ++j;
      }

      if ((i == n || buffer[i] == ' ' || buffer[i] == '\n') && j == m) {
        return line;
      }

      while (i < n && buffer[i] != ' ') {
        ++i;
      }
      ++i;

    }

    ++line;

  }

  fclose(fp);

}

void delLine() {
  int lno, ctr = 0;
  char ch;
  FILE * fptr1, * fptr2;
  char fname[MAX] = "booking.txt";
  char str[MAX], temp[] = "temp.txt";

  fptr1 = fopen(fname, "r");
  if (!fptr1) {
    printf("\t\tFile not found or unable to open the input file!!\n");
    return 0;
  }
  fptr2 = fopen(temp, "w");
  if (!fptr2) {
    printf("\t\tUnable to open a temporary file to write!!\n");
    fclose(fptr1);
    return 0;
  }
  printf("\t\tEnter The Line Number That You See Above: ");
  scanf("%d", & lno);
  lno++;

  while (!feof(fptr1)) {
    strcpy(str, "\0");
    fgets(str, MAX, fptr1);
    if (!feof(fptr1)) {
      ctr++;
      if (ctr != lno) {
        fprintf(fptr2, "%s", str);
      }
    }
  }
  fclose(fptr1);
  fclose(fptr2);
  remove(fname);
  rename(temp, fname);

  fptr1 = fopen(fname, "r");
  ch = fgetc(fptr1);
  printf("\t\t\nAfter Removing The Data The New Data Are: %s is : \n", fname);
  while (ch != EOF) {
    printf("%c", ch);
    ch = fgetc(fptr1);
  }
  fclose(fptr1);

}
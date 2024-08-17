#include <stdio.h>

#include <stdlib.h>

#include <string.h>

struct student {
  char name[20];
  int roll;
  float marks[3];
  float percentage;
  struct student * next;
};

struct student * head = NULL;

void Append();
void Insert();
void Display_All();
void Edit();
void Search();
void Delete_All();
void Delete();
void Mid_Point();
void Display_Reverse();
void Sort();

int main() {
  printf("\nSTUDENTS DATABASE\n");

  int choice;

  while (1) {
    printf("\n1. Append Record");
    printf("\n2. Insert Record");
    printf("\n3. Display All");
    printf("\n4. Edit Record");
    printf("\n5. Search Record");
    printf("\n6. Delete All");
    printf("\n7. Delete Record");
    printf("\n8. Find Mid Point");
    printf("\n9. Display All in Reverse");
    printf("\n10. Sort Linked List");
    printf("\n11. Exit");
    printf("\n\nEnter your choice: ");
    scanf("%d", & choice);

    switch (choice) {
    case 1:
      Append();
      break;
    case 2:
      Insert();
      break;
    case 3:
      Display_All();
      break;
    case 4:
      Edit();
      break;
    case 5:
      Search();
      break;
    case 6:
      Delete_All();
      break;
    case 7:
      Delete();
      break;
    case 8:
      Mid_Point();
      break;
    case 9:
      Display_Reverse();
      break;
    case 10:
      Sort();
      break;
    case 11:
      exit(0);
    default:
      printf("Invalid choice");
    }
  }

  return 0;
}

void Append() {
  struct student * p = (struct student * ) malloc(sizeof(struct student));
  struct student * t;

  if (p == NULL) {
    printf("No Memory Available");
    return;
  }

  printf("\nEnter Name: ");
  scanf("%s", p -> name);
  printf("Enter Roll: ");
  scanf("%d", & p -> roll);
  printf("Enter Marks (3 subjects): ");
  p -> percentage = 0;
  for (int i = 0; i < 3; i++) {
    scanf("%f", & p -> marks[i]);
    p -> percentage += p -> marks[i];
  }
  p -> percentage /= 3;
  p -> next = NULL;

  if (head == NULL) {
    head = p;
  } else {
    for (t = head; t -> next != NULL; t = t -> next);
    t -> next = p;
  }
}

void Insert() {
  struct student * p = (struct student * ) malloc(sizeof(struct student));
  struct student * t;
  char name2[20];
  int roll2, n;
  int found = 0;

  if (p == NULL) {
    printf("No Memory Available");
    return;
  }

  printf("\nSelect 1.Name 2.Roll: ");
  scanf("%d", & n);

  if (n == 1) {
    printf("\nSearch Name: ");
    scanf("%s", name2);

    for (t = head; t != NULL; t = t -> next) {
      if (strcmp(t -> name, name2) == 0) {
        found = 1;
        break;
      }
    }

    if (found) {
      printf("\nEnter Name: ");
      scanf("%s", p -> name);
      printf("Enter Roll: ");
      scanf("%d", & p -> roll);
      printf("Enter Marks (3 subjects): ");
      p -> percentage = 0;
      for (int i = 0; i < 3; i++) {
        scanf("%f", & p -> marks[i]);
        p -> percentage += p -> marks[i];
      }
      p -> percentage /= 3;

      p -> next = t -> next;
      t -> next = p;
    } else {
      printf("\nNot Exist\n");
    }
  } else {
    printf("\nSearch Roll: ");
    scanf("%d", & roll2);

    for (t = head; t -> next != NULL && t -> roll != roll2; t = t -> next);

    if (t -> roll == roll2) {
      printf("\nEnter Name: ");
      scanf("%s", p -> name);
      printf("Enter Roll: ");
      scanf("%d", & p -> roll);
      printf("Enter Marks (3 subjects): ");
      p -> percentage = 0;
      for (int i = 0; i < 3; i++) {
        scanf("%f", & p -> marks[i]);
        p -> percentage += p -> marks[i];
      }
      p -> percentage /= 3;

      p -> next = t -> next;
      t -> next = p;
    } else {
      printf("\nNot Exist\n");
    }
  }
}

void Display_All() {
  struct student * t = head;

  if (t == NULL) {
    printf("\nNo Data\n");
    return;
  }

  while (t != NULL) {
    printf("\nName = %s", t -> name);
    printf("\nRoll = %d", t -> roll);
    printf("\nMarks = ");
    for (int i = 0; i < 3; i++) {
      printf("%f ", t -> marks[i]);
    }
    printf("\nPercentage = %f\n", t -> percentage);
    t = t -> next;
  }
}

void Edit() {
  struct student * t;
  char name2[20];
  int roll2, n;
  int found = 0;

  if (head == NULL) {
    printf("No Data");
    return;
  }

  printf("\nSelect 1.Name 2.Roll: ");
  scanf("%d", & n);

  if (n == 1) {
    printf("\nSearch Name: ");
    scanf("%s", name2);

    for (t = head; t != NULL; t = t -> next) {
      if (strcmp(t -> name, name2) == 0) {
        found = 1;
        break;
      }
    }

    if (found) {
      printf("\nEnter New Name: ");
      scanf("%s", t -> name);
      printf("Enter New Roll: ");
      scanf("%d", & t -> roll);
      printf("Enter New Marks (3 subjects): ");
      t -> percentage = 0;
      for (int i = 0; i < 3; i++) {
        scanf("%f", & t -> marks[i]);
        t -> percentage += t -> marks[i];
      }
      t -> percentage /= 3;
    } else {
      printf("\nNot Exist\n");
    }
  } else {
    printf("\nSearch Roll: ");
    scanf("%d", & roll2);

    for (t = head; t != NULL; t = t -> next) {
      if (t -> roll == roll2) {
        found = 1;
        break;
      }
    }

    if (found) {
      printf("\nEnter New Name: ");
      scanf("%s", t -> name);
      printf("Enter New Roll: ");
      scanf("%d", & t -> roll);
      printf("Enter New Marks (3 subjects): ");
      t -> percentage = 0;
      for (int i = 0; i < 3; i++) {
        scanf("%f", & t -> marks[i]);
        t -> percentage += t -> marks[i];
      }
      t -> percentage /= 3;
    } else {
      printf("\nNot Exist\n");
    }
  }
}

void Search() {
  struct student * t;
  char name2[20];
  int roll2, n;
  int found = 0;

  if (head == NULL) {
    printf("No Data");
    return;
  }

  printf("\nSelect 1.Name 2.Roll: ");
  scanf("%d", & n);

  if (n == 1) {
    printf("\nSearch Name: ");
    scanf("%s", name2);

    for (t = head; t != NULL; t = t -> next) {
      if (strcmp(t -> name, name2) == 0) {
        found = 1;
        break;
      }
    }

    if (found) {
      printf("\nName = %s", t -> name);
      printf("\nRoll = %d", t -> roll);
      printf("\nMarks = ");
      for (int i = 0; i < 3; i++) {
        printf("%f ", t -> marks[i]);
      }
      printf("\nPercentage = %f\n", t -> percentage);
    } else {
      printf("\nNot Exist\n");
    }
  } else {
    printf("\nSearch Roll: ");
    scanf("%d", & roll2);

    for (t = head; t != NULL; t = t -> next) {
      if (t -> roll == roll2) {
        found = 1;
        break;
      }
    }

    if (found) {
      printf("\nName = %s", t -> name);
      printf("\nRoll = %d", t -> roll);
      printf("\nMarks = ");
      for (int i = 0; i < 3; i++) {
        printf("%f ", t -> marks[i]);
      }
      printf("\nPercentage = %f\n", t -> percentage);
    } else {
      printf("\nNot Exist\n");
    }
  }
}

void Delete_All() {
  struct student * t;

  while (head != NULL) {
    t = head;
    head = head -> next;
    free(t);
  }

  printf("All records deleted.\n");
}

void Delete() {
  struct student * t = head, * prev = NULL;
  char name2[20];
  int roll2, n;
  int found = 0;

  if (head == NULL) {
    printf("No Data");
    return;
  }

  printf("\nSelect 1.Name 2.Roll: ");
  scanf("%d", & n);

  if (n == 1) {
    printf("\nSearch Name: ");
    scanf("%s", name2);

    while (t != NULL) {
      if (strcmp(t -> name, name2) == 0) {
        found = 1;
        break;
      }
      prev = t;
      t = t -> next;
    }

    if (found) {
      if (prev == NULL) {
        head = t -> next;
      } else {
        prev -> next = t -> next;
      }
      free(t);
      printf("Record deleted.\n");
    } else {
      printf("Not Exist\n");
    }
  } else {
    printf("\nSearch Roll: ");
    scanf("%d", & roll2);

    while (t != NULL) {
      if (t -> roll == roll2) {
        found = 1;
        break;
      }
      prev = t;
      t = t -> next;
    }

    if (found) {
      if (prev == NULL) {
        head = t -> next;
      } else {
        prev -> next = t -> next;
      }
      free(t);
      printf("Record deleted.\n");
    } else {
      printf("Not Exist\n");
    }
  }
}

void Mid_Point() {
  struct student * slow = head, * fast = head;

  if (head == NULL) {
    printf("No Data");
    return;
  }

  while (fast != NULL && fast -> next != NULL) {
    slow = slow -> next;
    fast = fast -> next -> next;
  }

  printf("\nMid Point:\n");
  printf("Name = %s", slow -> name);
  printf("\nRoll = %d", slow -> roll);
  printf("\nMarks = ");
  for (int i = 0; i < 3; i++) {
    printf("%f ", slow -> marks[i]);
  }
  printf("\nPercentage = %f\n", slow -> percentage);
}

void Display_Reverse() {
  void printReverse(struct student * t) {
    if (t == NULL) return;
    printReverse(t -> next);
    printf("\nName = %s", t -> name);
    printf("\nRoll = %d", t -> roll);
    printf("\nMarks = ");
    for (int i = 0; i < 3; i++) {
      printf("%f ", t -> marks[i]);
    }
    printf("\nPercentage = %f\n", t -> percentage);
  }

  if (head == NULL) {
    printf("No Data");
    return;
  }

  printReverse(head);
}

void Sort() {
  struct student * t = NULL, * p = NULL;

  char temp_name[20], name2;
  int temp_roll, n, i;
  float temp_marks[3];
  float temp_percentage;

  if (!head) {
    printf("\nNo Data\n");
  } else {
    printf("\nSelect 1.Name 2.Roll\n");
    scanf("%d", & n);
    if (n == 1) {

      for (t = head; t != NULL; t = t -> next) {

        for (p = t -> next; p != NULL; p = p -> next) {

          if (p -> name[i] < t -> name[i]) {

            temp_roll = t -> roll;
            t -> roll = p -> roll;
            p -> roll = temp_roll;

            temp_percentage = t -> percentage;
            t -> percentage = p -> percentage;
            p -> percentage = temp_percentage;

            for (int i = 0; t -> name[i] != 0 || p -> name[i] != 0; i++) {
              temp_name[i] = t -> name[i];
            }
            for (int i = 0; t -> name[i] != 0 || p -> name[i] != 0; i++) {
              t -> name[i] = p -> name[i];
            }
            for (int i = 0; t -> name[i] != 0 || p -> name[i] != 0; i++) {
              p -> name[i] = temp_name[i];
            }

            for (int i = 0; i < 3; i++) {
              temp_marks[i] = t -> marks[i];
            }
            for (int i = 0; i < 3; i++) {
              t -> marks[i] = p -> marks[i];
            }
            for (int i = 0; i < 3; i++) {
              p -> marks[i] = temp_marks[i];
            }

          }
        }
      }

      for (t = head; t != NULL; t = t -> next) {
        printf("\nName = %s, Roll = %d\n", t -> name, t -> roll);
        printf("Marks = ");
        for (int i = 0; i < 3; i++) {
          printf("%f ", t -> marks[i]);
        }
        printf("\nPercentage = %f\n", t -> percentage);
      }

    } else {

      for (t = head; t != NULL; t = t -> next) {

        for (p = t -> next; p != NULL; p = p -> next) {

          if (p -> roll < t -> roll) {

            temp_roll = t -> roll;
            t -> roll = p -> roll;
            p -> roll = temp_roll;

            temp_percentage = t -> percentage;
            t -> percentage = p -> percentage;
            p -> percentage = temp_percentage;

            for (int i = 0; t -> name[i] != 0 || p -> name[i] != 0; i++) {
              temp_name[i] = t -> name[i];
            }
            for (int i = 0; t -> name[i] != 0 || p -> name[i] != 0; i++) {
              t -> name[i] = p -> name[i];
            }
            for (int i = 0; t -> name[i] != 0 || p -> name[i] != 0; i++) {
              p -> name[i] = temp_name[i];
            }

            for (int i = 0; i < 3; i++) {
              temp_marks[i] = t -> marks[i];
            }
            for (int i = 0; i < 3; i++) {
              t -> marks[i] = p -> marks[i];
            }
            for (int i = 0; i < 3; i++) {
              p -> marks[i] = temp_marks[i];
            }
          }
        }
      }
      for (t = head; t != NULL; t = t -> next) {
        printf("\nName = %s, Roll = %d\n", t -> name, t -> roll);
        printf("Marks = ");
        for (int i = 0; i < 3; i++) {
          printf("%f ", t -> marks[i]);
        }
        printf("\nPercentage = %f\n", t -> percentage);
      }
    }
  }
}

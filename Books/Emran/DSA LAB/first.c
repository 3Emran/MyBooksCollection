#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SYMBOLS 100
#define MAX_RULES 50

// Function to check if a character is a non-terminal (uppercase letters)
int is_non_terminal(char symbol) {
    return isupper(symbol);  // Non-terminals are typically uppercase
}

// Function to check if a character is a terminal (lowercase letters or special symbols like 'ε')
int is_terminal(char symbol) {
    return !isupper(symbol) && symbol != '\0' && symbol != '→';  // Terminals are lowercase or special symbols
}

// Function to compute the First set of a non-terminal based on the production rules
void compute_first_set(char grammar[MAX_RULES][MAX_SYMBOLS], int num_rules, char non_terminal, char *first_set) {
    // Check if the first_set already contains the non-terminal's First set
    for (int i = 0; i < num_rules; i++) {
        char *rule = grammar[i];

        // If the rule starts with the given non-terminal
        if (rule[0] == non_terminal) {
            // The first symbol in the production (after the non-terminal)
            int j = 2;  // Skip the non-terminal (i.e., rule[0] which is non_terminal and rule[1] which is '→')

            // Loop through each symbol in the production after the non-terminal
            while (rule[j] != '\0') {
                char symbol = rule[j];

                if (is_terminal(symbol)) {
                    // If the first symbol is a terminal, add it to the First set
                    if (!strchr(first_set, symbol)) {
                        strncat(first_set, &symbol, 1); // Append terminal symbol
                    }
                    break;  // After finding a terminal, we stop looking further in this production
                } else if (is_non_terminal(symbol)) {
                    // If it's a non-terminal, we need to add the First set of the non-terminal
                    char temp_first[MAX_SYMBOLS] = {0};  // Temporary array to store First set of the next non-terminal
                    compute_first_set(grammar, num_rules, symbol, temp_first);

                    // Add First set of the non-terminal to the current First set
                    for (int k = 0; temp_first[k] != '\0'; k++) {
                        if (!strchr(first_set, temp_first[k])) {
                            strncat(first_set, &temp_first[k], 1);
                        }
                    }

                    // If the non-terminal can derive epsilon (ε), continue to the next symbol
                    if (strchr(temp_first, 'ε')) {
                        j++;  // Skip to the next symbol in the production
                    } else {
                        break;  // If no epsilon, we stop after the first non-terminal's First set
                    }
                } else if (symbol == 'ε') {
                    // If epsilon (ε) is in the rule, add it to the First set
                    if (!strchr(first_set, 'ε')) {
                        strncat(first_set, "ε", 1);
                    }
                    break;
                }
                j++;
            }
        }
    }
}

// Function to extract terminals and non-terminals from a single production rule
void identify_terminals_non_terminals(char grammar[MAX_RULES][MAX_SYMBOLS], int num_rules) {
    char terminals[MAX_SYMBOLS];
    char non_terminals[MAX_SYMBOLS];
    int terminal_count = 0, non_terminal_count = 0;

    // Loop through each production rule
    for (int i = 0; i < num_rules; i++) {
        char *rule = grammar[i];

        // Loop through each character in the rule
        for (int j = 0; rule[j] != '\0'; j++) {
            char symbol = rule[j];

            // Check for non-terminal symbol
            if (is_non_terminal(symbol)) {
                if (!strchr(non_terminals, symbol)) {
                    non_terminals[non_terminal_count++] = symbol;
                }
            }

            // Check for terminal symbol
            else if (is_terminal(symbol)) {
                if (!strchr(terminals, symbol)) {
                    terminals[terminal_count++] = symbol;
                }
            }
        }
    }

    // Print the results
    printf("Terminals: ");
    for (int i = 0; i < terminal_count; i++) {
        printf("%c ", terminals[i]);
    }
    printf("\n");

    printf("Non-terminals: ");
    for (int i = 0; i < non_terminal_count; i++) {
        printf("%c ", non_terminals[i]);
    }
    printf("\n");

    // Compute and print First sets
    for (int i = 0; i < non_terminal_count; i++) {
        char first_set[MAX_SYMBOLS] = {0};  // Temporary array to store the First set
        compute_first_set(grammar, num_rules, non_terminals[i], first_set);
        printf("First(%c): %s\n", non_terminals[i], first_set);
    }
}

int main() {
    // Sample grammar rule input
    char grammar[MAX_RULES][MAX_SYMBOLS] = {
        "S→aSb",
        "S→ε",
        "A→aS",
        "A→bB",
        "B→bS",
        "B→ε"
    };

    int num_rules = 6;  // Total number of grammar rules

    // Identify and print terminals and non-terminals, and compute the First sets
    identify_terminals_non_terminals(grammar, num_rules);

    return 0;
}


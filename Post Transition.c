#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 6

struct package {
    char* id;
    int weight;
};

typedef struct package package;

struct post_office {
    int min_weight;
    int max_weight;
    package* packages;
    int packages_count;
};

typedef struct post_office post_office;

struct town {
    char* name;
    post_office* offices;
    int offices_count;
};

typedef struct town town;

// Function to print all packages in a given town
void print_all_packages(town t) {
    printf("%s:\n", t.name);
    for (int i = 0; i < t.offices_count; i++) {
        printf("\t%d:\n", i);
        for (int j = 0; j < t.offices[i].packages_count; j++) {
            printf("\t\t%s\n", t.offices[i].packages[j].id);
        }
    }
}

// Function to process package transfers between two specific offices
void send_all_acceptable_packages(town* source, int source_office_index, town* target, int target_office_index) {
    post_office* src_office = &(source->offices[source_office_index]);
    post_office* tgt_office = &(target->offices[target_office_index]);
    
    // Arrays to temporarily segregate accepted and rejected packages
    package* accepted = malloc(src_office->packages_count * sizeof(package));
    package* rejected = malloc(src_office->packages_count * sizeof(package));
    
    int accepted_count = 0;
    int rejected_count = 0;
    
    for (int i = 0; i < src_office->packages_count; i++) {
        int w = src_office->packages[i].weight;
        if (w >= tgt_office->min_weight && w <= tgt_office->max_weight) {
            accepted[accepted_count++] = src_office->packages[i];
        } else {
            rejected[rejected_count++] = src_office->packages[i];
        }
    }
    
    // Update the target office with newly transferred packages
    if (accepted_count > 0) {
        tgt_office->packages = realloc(tgt_office->packages, (tgt_office->packages_count + accepted_count) * sizeof(package));
        for (int i = 0; i < accepted_count; i++) {
            tgt_office->packages[tgt_office->packages_count + i] = accepted[i];
        }
        tgt_office->packages_count += accepted_count;
    }
    
    // Update the source office to only contain the remaining (rejected) packages
    free(src_office->packages);
    if (rejected_count > 0) {
        src_office->packages = malloc(rejected_count * sizeof(package));
        for (int i = 0; i < rejected_count; i++) {
            src_office->packages[i] = rejected[i];
        }
        src_office->packages_count = rejected_count;
    } else {
        src_office->packages = NULL;
        src_office->packages_count = 0;
    }
    
    free(accepted);
    free(rejected);
}

// Function to compute total packages in a town
int get_total_packages(town t) {
    int total = 0;
    for (int i = 0; i < t.offices_count; i++) {
        total += t.offices[i].packages_count;
    }
    return total;
}

// Function to find the town with the maximum number of packages
town town_with_most_packages(town* towns, int towns_count) {
    int max_packages = -1;
    int max_index = 0;
    for (int i = 0; i < towns_count; i++) {
        int current_packages = get_total_packages(towns[i]);
        if (current_packages > max_packages) {
            max_packages = current_packages;
            max_index = i;
        }
    }
    return towns[max_index];
}

// Utility function to find a town struct by its unique string name
town* find_town(town* towns, int towns_count, char* name) {
    for (int i = 0; i < towns_count; i++) {
        if (strcmp(towns[i].name, name) == 0) {
            return &towns[i];
        }
    }
    return NULL;
}

int main() {
    int towns_count;
    if (scanf("%d", &towns_count) != 1) return 0;
    town* towns = malloc(towns_count * sizeof(town));
    
    for (int i = 0; i < towns_count; i++) {
        towns[i].name = malloc(MAX_STRING_LENGTH * sizeof(char));
        scanf("%s", towns[i].name);
        scanf("%d", &towns[i].offices_count);
        towns[i].offices = malloc(towns[i].offices_count * sizeof(post_office));
        
        for (int j = 0; j < towns[i].offices_count; j++) {
            scanf("%d %d %d", &towns[i].offices[j].packages_count, &towns[i].offices[j].min_weight, &towns[i].offices[j].max_weight);
            towns[i].offices[j].packages = malloc(towns[i].offices[j].packages_count * sizeof(package));
            
            for (int k = 0; k < towns[i].offices[j].packages_count; k++) {
                towns[i].offices[j].packages[k].id = malloc(MAX_STRING_LENGTH * sizeof(char));
                scanf("%s", towns[i].offices[j].packages[k].id);
                scanf("%d", &towns[i].offices[j].packages[k].weight);
            }
        }
    }
    
    int queries;
    if (scanf("%d", &queries) != 1) return 0;
    
    while (queries--) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            char name[MAX_STRING_LENGTH];
            scanf("%s", name);
            town* t = find_town(towns, towns_count, name);
            if (t != NULL) {
                print_all_packages(*t);
            }
        } else if (type == 2) {
            char source_name[MAX_STRING_LENGTH];
            char target_name[MAX_STRING_LENGTH];
            int source_office_index, target_office_index;
            scanf("%s %d %s %d", source_name, &source_office_index, target_name, &target_office_index);
            town* source = find_town(towns, towns_count, source_name);
            town* target = find_town(towns, towns_count, target_name);
            send_all_acceptable_packages(source, source_office_index, target, target_office_index);
        } else if (type == 3) {
            town t = town_with_most_packages(towns, towns_count);
            printf("Town with the most number of packages is %s\n", t.name);
        }
    }
    
    // Memory cleanup
    for (int i = 0; i < towns_count; i++) {
        for (int j = 0; j < towns[i].offices_count; j++) {
            for (int k = 0; k < towns[i].offices[j].packages_count; k++) {
                free(towns[i].offices[j].packages[k].id);
            }
            free(towns[i].offices[j].packages);
        }
        free(towns[i].offices);
        free(towns[i].name);
    }
    free(towns);
    
    return 0;
}

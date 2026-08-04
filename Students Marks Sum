int marks_summation(int* marks, int number_of_students, char gender) {
    int sum = 0;
    
    // In HackerRank-style problems, boys' marks are typically stored 
    // at even indices (0, 2, 4...) and girls' at odd indices (1, 3, 5...)
    int start_index = (gender == 'b') ? 0 : 1;
    
    for (int i = start_index; i < number_of_students; i += 2) {
        sum += marks[i];
    }
    
    return sum;
}

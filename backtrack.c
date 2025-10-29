void backtrack(char **result, char *current, int pos, int open, int close, int n, int *returnSize) {
    if (pos == 2 * n) {
        current[pos] = '\0';
        result[*returnSize] = (char *)malloc((2 * n + 1) * sizeof(char));
        strcpy(result[*returnSize], current);
        (*returnSize)++;
        return;
    }

    if (open < n) {
        current[pos] = '(';
        backtrack(result, current, pos + 1, open + 1, close, n, returnSize);
    }
    if (close < open) {
        current[pos] = ')';
        backtrack(result, current, pos + 1, open, close + 1, n, returnSize);
    }
}

char** generateParenthesis(int n, int* returnSize) {
    int maxComb = 1430;  
    char **result = (char **)malloc(maxComb * sizeof(char *));
    char *current = (char *)malloc((2 * n + 1) * sizeof(char));
    *returnSize = 0;
    
    backtrack(result, current, 0, 0, 0, n, returnSize);
    
    free(current);
    return result;
}

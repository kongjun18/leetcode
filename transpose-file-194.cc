# Read from the file file.txt and print its transposed content to stdout.
awk '
{
    line = line + 1
    column = NF
    for (i = 1; i <= NF; ++i) {
        matrix[line][i] = $i
    }
}
END {
    for (i = 1; i <= column; ++i) {
        for (j = 1; j <= line; ++j) {
            printf("%s", matrix[j][i])
            if (j != line) {
                printf(" ")
            }
            
        }
        printf("\n")
    }
}' file.txt

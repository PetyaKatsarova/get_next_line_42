
/*
	Make sure that your function works as expected both when reading a file and when
reading from the standard input.
Error in test 3: get_next_line(5: "read_error.txt"): expected: <NULL>, got: "cccccccc"
Probable reason: You should clear the static buffer when a call to read returns -1
To see the tests open: /Users/pkatsaro/francinette/tests/get_next_line/fsoares/tester.c
*/
// read, malloc, free, ret NULL if there is nth else to read
//read() r nbytes of data from the obj of reference by the fildes into
// the buffer pointed to by buf:re num of bites read adn place in the buf

// -D BUFFER_SIZE=n
// cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c && ./a.out
// int	main(void)
// {
// 	char *line;
//     int fd = open("tests/test.txt", O_RDONLY);
//     if (fd < 0) {
//         printf("Error opening file\n");
//         return (-1);
//     }
//     while ((line = get_next_line(fd)) != NULL) {
//         printf("Line: %s", line);
//         free(line);
//     }
//     if (close(fd) != 0) {
//         printf("Error closing file\n");
//         return (-1);
//     }
// 	return (0);
// }
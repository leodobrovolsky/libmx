void mx_printstr(const char *s);

void mx_print_strarr(char **arr, const char *delim) {
 	int i = 0;
    if (!delim)
    	return;
    while(arr[i]) {
    	if (i != 0)
    	    mx_printstr(delim);
    	mx_printstr(arr[i]);
    	i++;
    }
    mx_printstr("\n");
}

#include <kernel/tty.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>

int printf(const char* format, ...){
    va_list ap;
    char *p, *string_val;
    int int_val, hex_val;
    double double_val;

	char buffer[512];

    va_start(ap, format);
    for(p = format; *p; p++) {
        if(*p != '%') {
            tty_put_char(*p);
            continue;
        }
		if(*++p == 'l'){
			if(*++p == 'l'){
			switch(*++p){
	            case 'd':
    	        case 'i':
            	    i64toa(va_arg(ap, int64_t), buffer, 10);
				break;

    	        case 'f':
            	    dtoa(va_arg(ap, double), buffer, 2);
				break;

    	        case 'x':
            	    i64toa(va_arg(ap, int64_t), buffer, 16);
	            break;

    	        case 's':
            	    tty_write_string(va_arg(ap, char *));
					//!! It's continue for cycle !!!
                	continue;
	            default:
					tty_put_char(*p);
                break;
			}
			}
		}else{
			switch(*p){
	            case 'd':
    	        case 'i':
	                itoa(va_arg(ap, int), buffer, 10);
    	        break;

        	    case 'f':
                	dtoa(va_arg(ap, double), buffer, 2);
				break;

    	        case 'x':
            	    i64toa(va_arg(ap, int), buffer, 16);
	            break;

    	        case 's':
					tty_write_string(va_arg(ap, char *));
					//!! It's continue for cycle !!!
            	    continue;
            	default:
                	tty_put_char(*p);
                break;
			}
        }
		tty_write_string(buffer);
		memset(buffer, 0, 512);
    }
    va_end(ap);
	return 1;
}

#ifndef STRTOK_ADEQUATE_H_
#define STRTOK_ADEQUATE_H_

#include <string.h>
#include <assert.h>

static inline int strtok_adequate(
	const char *restrict str,
	unsigned long len,
	unsigned long *restrict token_off_ptr,
	unsigned long *restrict token_len_ptr,
	/* null-terminator is not included */
	const char *restrict delim
)
{
	assert(len == 0 || str != NULL);
	assert(len == 0 || token_len_ptr != NULL);
	assert(len == 0 || token_off_ptr != NULL);
	assert(delim != NULL);

	assert(len == 0 || *token_off_ptr <= len);
	assert(len == 0 || *token_len_ptr <= len);
	assert(len == 0 || *token_off_ptr <= len - *token_len_ptr);

	const size_t delim_len = strlen(delim);

	/* adjust position */
	*token_off_ptr += *token_len_ptr;
	*token_len_ptr = 0;

	assert(*token_off_ptr <= len);
	if(*token_off_ptr == len) {
		return 0;
	}

	/* find first non-delimiter, start of the next token */
	for(;; ++*token_off_ptr) {
		assert(*token_off_ptr <= len);

		if(*token_off_ptr == len) {
			/* no more tokens */
			return 0;
		}

		if(!memchr(delim, str[*token_off_ptr], delim_len)) {
			break;
		}
	}

	/* find first delimiter, end of the token */
	*token_len_ptr = 0;
	for(;; ++*token_len_ptr) {
		assert(*token_off_ptr + *token_len_ptr <= len);

		if(*token_off_ptr + *token_len_ptr == len) {
			break;
		}

		if(memchr(delim, str[*token_off_ptr + *token_len_ptr], delim_len)) {
			break;
		}
	}

	return 1;
}

#endif /* STRTOK_ADEQUATE_H_ */

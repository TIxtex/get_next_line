# get_next_line

[![built with C](https://img.shields.io/badge/built%20with-C-blue.svg)](https://docs.microsoft.com/es-es/cpp/c-language/?view=msvc-170)

```Makefile
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    get_next_line                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uliherre <uliherre@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/08 19:37:36 by uherrero          #+#    #+#              #
#    Updated: 2022/06/27 16:46:53 by ulherrer         ##   ######.es           #
#                                                                              #
# **************************************************************************** #
```

# table of contents

- [get_next_line](#get_next_line)
- [table of contents](#table-of-contents)
  - [subject](#subject)
  - [get_next_line_c](#get_next_line_c)
  - [get_next_line_utils_c](#get_next_line_utils_c)

## subject

[link_to_subject](./es.subject.pdf)

## get_next_line_c

```C
char    *get_next_line(int fd);
```

## get_next_line_utils_c

```C
size_t  ft_strlen(const char *s);
void    *gnl_scalloc(size_t num_items, size_t size_item);
char    *gnl_substr(char const *s, unsigned int start, size_t len, int flag);
char    *ft_strjoin_f1(char *s1, char *s2);
int     gnl_isnl(char *str);
```

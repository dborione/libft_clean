#### isalpha

* works on letters only
if between 101- 127 or 130-132 or 141-147 or 150-157 or 160-167 or 170-172 == tr
* value of EOF= End Of File= -1= non representable

#### memset

The memset function copies the value of c (converted to an unsigned char) into each of the first n characters of the object pointed to by s.

// ptr ==> Starting address of memory to be filled
// x   ==> Value to be filled
// n   ==> Number of bytes to be filled starting 
//         from ptr

``
void *memset(void *ptr, int x, size_t n);
``

-> while str[i]!= \n && n != 0
	 if str[ptr] == str[i]
		 fill by x : n*sizeof(x)
		 n--

* qund ptr = str[i]
	str[i] = c for n bytes

return void pointer = pas d'arithmetique 


##### strnstr

##### strl cat/cpy

https://c-for-dummies.com/blog/?p=3896

```
	char *src = "this is";
	char *dst = "an exemple";
	int	ex[3] = {1, 2, 3};

	printf("%lu\n", sizeof(dst));
	printf("%lu\n", sizeof(src));
	printf("%lu\n", sizeof(ex));
```
output->	sizeof(dst) = 8 bytes = donne la taille du pointer src = 8 bytes pour un pointer
			sizeof(*dst) = 1 byte = taille de 1 char
			strlen(dst) = 10 bytes (ne compte pas le \0)

strlcat() appends string src to the end of dst.  It will append at most **dstsize - strlen(dst) - 1 characters**. = 
	- dstsize = sizeof(dst) = 8
	- strlen(dst) = 10
	- 8 - 10 - 1 = -3
	
	-> `printf("%lu", strlcat(dst, src, strlen(dst))) = 17 = "an_exemplethis_is" + \0`

	 It will then NUL-terminate, unless dstsize is 0 or the 
	 original dst string was longer than dstsize (in practice this should not happen as it
     means that either dstsize is incorrect or that dst is not a proper string).

**dstsize = full size of the destination buffer** = strlen(dst)

```
First and foremost, both strlcpy() and strlcat() guarantee to NUL-terminate the
destination string for all strings where the given size is
non-zero. Secondly, both functions take the full size of
the destination string as a size parameter. In most cases
this value is easily computed at compile time using the
sizeof operator. Finally, neither strlcpy() nor strlcat() zero-fill their destination strings (other than the compulsatory NUL to terminate the string).
```

Tu te trompes sur le param??tre de taille. Il ne s'agit pas de la taille de la chaine finale, mais de la taille du tableau pr??vu pour enregistrer la chaine finale. L'int??r??t de ce param??tre est d'emp??cher strlcat de sortir du tableau (et ??craser n'importe quoi en m??moire).


18 septembre 2017 ?? 18:29:08
Le man dit :

"The strlcat() function appends the NUL-terminated string src to the end of dst. It will append at most size - strlen(dst) - 1 bytes, NUL-termi- nating the result."

Pour utiliser correctement la fonction, il faut que le troisi??me param??tre soit la taille en octets de la zone m??moire de destination. Relisons-donc doucement la citation du manuel : strlcat() ajoute au plus [le 3??me param??tre] MOINS [la taille de la cha??ne d??j?? contenue dans dst (cha??ne termin??e par 0 of course)] MOINS [1].

La valeur de retour: strlcat retourne la taille totale de la chaine qui aurait du ??tre cr????e, m??me si la chaine a ??t?? tronqu??e (strlen(dst) + strlen(src)).
Ensuite les indices de tableau doivent ??tre de type size_t.
Ah et ??a: (size - length - 1) casse tout quand size = length

Pour les v??rifications des valeurs de retour, ce n'est pas compliqu??, si la valeur de retour de strlcat est diff??rente de strlen(dst) + strlen(src), alors ce n'est pas la bonne

La fonction a plusieurs probl??me : ligne 10, ton probl??me se situe au niveau de la variable size : en effet tu compte recopier size caract??re DEPUIS source, ce que tu veux c'est que size soit au maximum a la taille de source : du coup ligne 10, c'est if (size > len_src) size = len_src

###### terminal timer

`while true; do echo -ne "`date`\r"; done`

##### split

			[0][1] [1][1] [2][1]  [3][3] [4][1] [5][0]
`**tab =	[ e\0] [x\0 ] [e\0]  [mpl\0] [ e\0] [ \0 ]

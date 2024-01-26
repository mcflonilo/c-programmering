# c-programmering
bengt regler:
ikke bruk global variabel(da blir bengt sinna)
han liker hungarian notation (stor bokstav i starten av hvert ord bortsett fra første)

for å kompilere:
gcc –O2 –Wall –Werror –std=c11 NavnPåInnFil.c –o NavnPåUtFil

bruk -wextra i gcc for å se extra warnings. fiks alle warnings

erklær funksjon først, så main, så funksjonskropp

input metoder:
getchar() henter en karakter fra tastatur
scanf() bruk med regex for å hente text/tall i input. sårbar til bufferoverflow.

output:
printF()
put  ()

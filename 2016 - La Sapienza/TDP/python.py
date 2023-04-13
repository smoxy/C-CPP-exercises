#Esercizio con l'operatore di formato di stringhe

# NUMERI INTERI
# %d
# %5d
# %05d
x=365
print("In un anno sono %d giorni" %x)
print("In un anno sono %5d giorni" %x)
print("In un anno sono %-5d giorni" %x)
print("In un anno sono %05d giorni\n" %x)

# NUMERI IN VIRGOLA MOBILE
# %f
# %.2f
# %7.2f
money=1.0755  #1 euro in dollari 18:55 06/01/2016
money2=0.9298 #1 dollaro in euro 18:55 06/01/2016
print("1€ = %f$\t\t1$ = %f€" %(money,money2))
print("1€ = %.2f$\t\t1$ = %.2f€" %(money,money2))
print("1€ = %10.2f$\t1$ = %10.2f€" %(money,money2))
print("1€ = %-10.2f$\t1$ = %-10.2f€" %(money,money2))
print("1€ = %010.2f$\t1$ = %010.2f€\n" %(money,money2))

# STRINGHE
# LE STRINGHE NON POSSONO ESSERE RIEMPITE CON ZERI
# %s
# %10s
name1 = input("Inserisci il 1° nome:").capitalize()
name2 = input("inserisci il 2° nome:").capitalize()
n1 = name1[0]
n2 = name2[0]
print("%s + %s = %s&%s" %(name1,name2,n1,n2))
print("%10s + %-10s = %s&%s" %(name1,name2,n1,n2))

# PER ALLINEARE A SINISTRA
# SE SI AGGIUNGONO GLI ZERI AL POSTO DEGLI SPAZI, NON SI PUÒ ALLINEARE A SINISTRA
# %-10s
print("%-10s + %10s = %s&%s\n" %(name1,name2,n1,n2))

# PER VISUALIZZARE IL SEGNO %
# %d%%   ----->   24%
finish=100
print("Ho completato il %d%% degli esempi"%finish)


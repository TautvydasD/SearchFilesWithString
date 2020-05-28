# Teltonikos Embedded Linux užduotis

## Užduotis

***

* Reikia susikurti aplankalą, kuriame gali būti failų arba kitų aplankalų, kuriuose kiti failai arba aplankalai,
* Kiekvienas failas savyje turi tekstą.
* Programos tikslas yra atrasti failus, kuriuose yra tam tikras paduotas tekstas.
  1. Programa turi būti paleidžiama taip ./programa -f [APLANKALAS] -t [tekstas]
  2. programa turi atspausdinti visus failus, kuriuose yra pasirinktas tekstas, bei atspausdinti kurioje failo eilutėje yra pasirinktas tekstas

Paruošti dynamic library (.so), kuriame būtų įgyvendintas Linked List principu veikiantis sąrašas.

***

## Pastabos

***

Apgalvoti galimus variantus dėl ne konkretaus tipo elemento pridėjimo (void *) ir apie galimybę paruošti šią biblioteką Thread Safe. Reikėtų padaryti iškeliamą header (*.h) failą, kuriame būtų deklaruotos funkcijos, tik kurias gali pasiekti vartotojas (funkcijų deklaracijos privalo būti dokumentuotos DoxyGen principu).

Ši biblioteka turi turėti savo struktūrą, kuri būtu tik deklaruota išorei, be papildomų parametrų (typedef struct linked_list;), kad darbas būtų atliekamas tik su deklaruotomis funkcijomis iš šios bibliotekos, paduodant sąrašo kintamajį (pop(manoKintamasis);).

***
abc
**PS.** sąrašo viduje atmintis privalo būti tvarkoma dinamiškai, be jokių memory leak.

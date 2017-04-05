
1.  !!!  Vi har ikke inkludert/implementert Ant.sifre og Ant.desimaler som en del av datastrukturen og funksjonalitet, 
     da vi oppdaget dette kravet ganske sent i prosessen. Det førte til at det ble såpass omfattende å gjøre dette om, 
     at vi heller lot være. !!! KANSKJE om vi ikke rekker dette !!!

2. Vi har valgt å bruke numeriske kommandoer i menyene, i stedet for bokstavkommandoer.
      Dette ble gjort delvis for å øke utfordringen på oppgaven, og samtidig gi brukeren av systemet en bedre opplevelse.
      Ved å bruke numeriske kommandoer, vil menyer kunne genereres dynamisk etter hvor my data som ligger.
      Tall kan mappes til objekter, som gjør det enklere for brukeren å velge et bestemt objekt.

3. Vi auto-lager IKKE ID-en for øvelser. Denne ID-en ville vert redundant, 
     siden navnet på grenen + navnen på øvelsen er nok til å skape en Primernøkkel. 
     Det har viktig for oss å ikke lagre redundant data i datastrukturen.
     Derfor bruker vi sportnavn + øvelsenavn som PK for Øvelser.

4. !!! Vi har ikke implementert endring av startliste. Dersom bruker ønsker å endre startlisten,
    må han slette den aktive startlisten, og lage en helt ny. !!! KANSKJE om vi ikke rekker dette !!!


5. Vi Har ingen fil med globale hjelpefunksjoner, men har splittet alle disse 
    hjelpefunksjoner 
    + hjelpestructs 
    + hjelpeklasses
    + hjelpetypedefs 
   i en egen modul  - 'tool' - med mange filer.

6. Vi har ingen globale database-objekter, men har samlet alle database-objektene 
     som private medlemmer i klassen API. Resten av programmet bruker API, for å snakke med databasen.

7. Vi bruker altså ikke 'extern' en eneste plass, men bruker heller et API-objekt for å 'interface' med databasen.

8. Desverre fant vi ingen måte å feilskjekke UTF-8 - unicode letters. Derfor vil ikke systemet vårt takle nasjonsspesifikke bokstaver.
     Tar gjerne i mot lærdom og visdom på dette området.

9. Testdata vi fikk tildelt hadde navn med tall i seg. Vi kjører en ganske streng skjekk på at navn er på riktig format når de leses inn. Det
    gir ingen mening å tillate navn med tall i seg. Derfor måtte vi endre på testdata.
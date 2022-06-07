# Metro simulation

# Diagram klas
![diagram](diagram.png)


# Hierarchia klas:

- klasa Coordinator
Zajmuje się połączeniem poszczególnych klas metra.
Przy starcie metra jego zadaniem jest wypełnenie planu odjazdów dla każdej stacji.
Oprócz tego, w nim znajduje się główna logika programu - funkcja "HandleStations" która w każdej swojej iteracji
"rusza" czas lokalny o 1, i wykonuje wszelkie obliczenia związane z działaniem symulacji.
- klasa App
Nie jest ściśle związana z logiką programu, jej zadaniem jest przeczytanie i obróbka danych dostarczonych z plików.
Następnie, koordynuje ona wyświetlanie tekstu przez display, oraz zajmuje się pętlą w której koordynator wykonuje swoje zadania.
- klasa Display_text
Zajmuje się wyświetlaniem podstawowych informacji w konsoli
Pozwala wyświetlić stacje i pociągi wraz z ich zapełnieniem oraz mapę metra.
- klasa Display
Zajmuje się tworzeniem pliku html który przedstawia aktualny stan metra
Główna metoda create_map na początku tworzy nagłówek pliku svg a następnie generuje linie pomiędzy stacjami i punkty w miejscach stacji.
Potem dodawane są pociągi i na samym końcu skrypt umożliwiający wyświetlanie informacji o stacjach i pociągach po najechaniu na nie myszką.

# Mapa
![mapa](mapa.png)
#pragma once
(sama logika)

aplikacja:
stworzona klasa App -
początek:
tworzymy wektor osób (wydaje mi się że osoby będą musiały być dynamicznie alokowane)
koordynator dostaje wektor stacji
koordynator dostaje wektor osób które są na stacjach, znajduje dla nich trasę - wektor stacji przez które mają przejechać
koordynator daje osobom pociągi bądź dodaje do wektora czekających (ma go stacja) 
(wektor czekajacych może zrobić jak dwustronny, bo będzie on działał jak kolejka chyba że dla danej osoby żaden pociąg nie pasuje)

app wywołuje pętlę w czasie (z częstotliwością określoną)
while true:
	wywołaj w koordynatorze funckję - przejdź przez wszystkie stacje metra, i sprawdź czy na jakiejś stacji jest pociąg (patrząc na rozkład) - dostaje wektor referencji na pociąg
	będąc na stacji A:
		poproś o wektor osób w pociągu, sprawdź która z nich wychodzi.
		dodaj do pociągów osoby które czekały już wcześniej na stacji.
		dodaj do pociągów osoby które wyszły z innego pociągu
		dodaj do dwustronnego wektora osoby które są teraz na stacji.
		usuń osoby które są na stacji końcowej	
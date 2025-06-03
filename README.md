# Symulacja operacji specjalnej – misja ratunkowa

## Opis projektu

Symulacja operacji specjalnej, której celem jest uwolnienie zakładników bez wykrycia aż do wyjścia z budynku. Na podstawie tekstowej mapy generowane są trasy strażników, a komandos musi taktycznie eliminować przeciwników i wykorzystać dostępne przedmioty, by wykonać misję pomyślnie.

---

## Parametry wejściowe

- Liczba komandosów  
- Liczba strażników (maksymalnie 10)  
- Przedmioty, które może użyć komandos:  
  - Tłumik (zwiększa obszar cichego zabójstwa)  
  - Granat dymny (zmniejsza widoczność strażnika)  
  - Granat ogłuszający (ogłusza strażnika na 1s)

---

## Parametry wyjściowe

- Status misji: sukces lub niepowodzenie  
- Czas trwania misji  
- Ilość zabitych strażników

---

## Zachowanie komandosów

- Skradanie się — wolniejsze, ale niesłyszalne dla strażników  
- Możliwość wykorzystania przedmiotów  
- Ciche zabójstwa — jeśli komandos zakradnie się blisko strażnika, może go wyeliminować po cichu

---

## Zachowanie strażników

- Zauważenie komandosa — włączenie alarmu, co skutkuje niepowodzeniem misji

---

## Limity

- Maksymalnie 10 strażników  
- 1 komandos

---

## Przebieg symulacji

Komandos wchodzi do budynku i rozpoczyna misję. Po drodze napotyka strażników, których musi cicho eliminować, unikając wywołania alarmu. Do dyspozycji ma różne przedmioty, które pomagają mu w przejściu do zakładników. Wszystkie zdarzenia są logowane do pliku CSV.

---

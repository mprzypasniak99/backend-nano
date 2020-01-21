# backend-nano
## Klasa Nano
### Metody
- `void bind(std::string str, std::function<void()> func, std::string help)` - tworzy BindingString na podstawie podanych parametrów. Format str: `#nano\<KEY\>Litera%opis funkcji!Komunikat do wyświetlenia w okienku${Nazwa pola(entry) do którego ma zostać wczytana wartość}`. Obsługiwane klawisze (KEY):
    - Ctrl
    - Shift
    - F1-F12 - wszystkie kolejne klawisze nie łączą się z literami
    - Delete(DEL)
    - Backspace(BS)
    - Strzałki(LARROW, RARROW, UARROW, DARROW)
    - EDITION - jest to implementacja odpowiedzi toola na wciśnięcie dowolnego przycisku nie objętego bindem. Wartość wciśniętego przycisku przekazywana jest toolowi poprzez funkcję `setEntry("KEY", a)`, gdzie `a` to wciśnięty przycisk. Klawisze specjalne, np Delete, Backspace, są przekazywane w nawiasach ostrych, np `<DEL>` i `<BS>`.\
W nawiasach podane są nazwy, których trzeba użyć przy wpisywaniu do funkcji bind(w nawiasach ostrych <>).\
Nie można używać skrótów łączonych, np. `<CTRL><SHIFT>N`, `<SHIFT><DEL>`
- `void start()` - funkcja obsługująca całą komunikację między toolem a sprzętem
- `std::vector<char> GetBindTab` - pomocnicza funkcja zwracająca tablicę z skrótami klawiszowymi

## Skróty zaimplementowane
- CTRL+Q - wyłącza program, póki co wyświetla tylko okienko z wiadomością o niezapisanym pliku (program można zamknąć naciskając klawisz 'F')
- CTRL+H - wyświetla okienko z wszystkimi skrótami i pomocą do każdego z nich

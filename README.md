# backend-nano
## Klasa Nano
### Metody
- `void bind(std::string str, std::function<void()> func, std::string help)` - tworzy BindingString na podstawie podanych parametrów. Format str: "#nano\<KEY\>Litera%opis funkcji". Obsługiwane klawisze (KEY):
    - Ctrl
    - Shift
- `void start()` - funkcja obsługująca całą komunikację między toolem a sprzętem
- std::vector<char> GetBindTab - pomocnicza funkcja zwracająca tablicę z skrótami klawiszowymi


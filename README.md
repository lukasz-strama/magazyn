# 📦 PBL MAGAZYN

1. [Rozpoczęcie](#-rozpoczęcie)
   - [Wymagania](#wymagania)
   - [Kompilacja](#kompilacja)
2. [Dokumentacja](#-dokumentacja)
   - [Diagram UML](#diagram-uml-klas)
   - [Dokumentacja HTML w doxygen](#generowanie-dokumentacji-html-w-doxygen)
3. [Autorzy](#-autorzy)

## 🚀 Rozpoczęcie

### Wymagania

Aby zbudować i uruchomić ten projekt, będziesz potrzebować:

- Kompilator C++ (GCC, Clang, MSVC itp.)
- Make
- Git

### Kompilacja
1. **Sklonuj repozytorium:**

   ```sh
   git clone https://github.com/lukasz-strama/magazyn.git
   cd magazyn
   ```

2. **Skompiluj projekt:**

   ```sh
   make
   ```

   Jeśli nie masz zainstalowanego Make, możesz zainstalować go za pomocą Homebrew (dla systemów UNIX)

   ```sh
   brew install make
   ```

3. **Uruchom projekt:**

   ```sh
   ./Magazyn
   ```

4. **(Opcjonalnie) Wyczyść pliki budowania:**

   ```sh
   make clean
   ```

5. **Dla użytkowników VS Code:**

   Umożliwienie kompilacji poprzez skrót klawiszowy **Ctrl+Shift+B**

   .vscode/tasks.json

   ```json
   {
     "version": "2.0.0",
     "tasks": [
       {
         "label": "Make",
         "type": "shell",
         "command": "make",
         "group": {
           "kind": "build",
           "isDefault": true
         },
         "problemMatcher": []
       }
     ]
   }
   ```

## 📃 Dokumentacja

### Diagram UML klas:

![Diagram](doc/diagram_klas.png)

### Generowanie dokumentacji HTML w doxygen:

Automatycznie wygenerowana dokumentacja na podstawie gałęzi `main` znajduje się [tutaj](https://lukasz-strama.github.io/pbl-magazyn/index.html). Aktualizowana jest z każdym `push`.

1. Wymagana wersja >= 1.9.5

2. Przejdz do głównego katalogu projektu:

   ```sh
   cd magazyn
   ```

3. Wygeneruj dokumentacje na podstawie pliku Doxyfile:

   ```sh
   doxygen Doxyfile
   ```

4. Lokalizacja index.html:

   ```sh
   doc/html/index.html
   ```

Wygenerowana dokumentacja korzysta z dodatkowego arkusza stylów, arkusz powinen już znajdować się w folderze z dokumentacją:
[Doxygen Awesome](https://jothepro.github.io/doxygen-awesome-css)

## ✨ Autorzy

| Zarządzanie i prezentacja 👨🏻‍🏫 | Programowanie 🧑🏻‍💻 | Dokumentacja 📄 |
| ---------------------------- | ---------------- | --------------- |
| Michał Kucharski             | Daniel Śledź     | Wiktoria Pyka   |
|                              | Łukasz Strama    | Antoni Białecki |
|                              |                  | Antoni Grycmann |

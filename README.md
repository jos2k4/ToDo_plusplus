## ToDo_plusplus 📝

Eine performante und leichtgewichtige Aufgabenverwaltung, die in C geschrieben wurde. Das Tool nutzt eine dateibasierte Speicherung und bietet eine robuste Logik für das Erstellen, Auflisten und Löschen von Aufgaben direkt über die Konsole.

# ✨ Kern-Features
Persistente Speicherung: Aufgaben werden dauerhaft in der Datei saves.txt gespeichert.

Dynamische Speicherverwaltung: Nutzt malloc zur effizienten Handhabung von Zeichenketten (Header und Beschreibungen).

String-Handling: Automatische Umwandlung von Leerzeichen in Bindestriche beim Speichern, um die Integrität der Datenstruktur in der Datei zu gewährleisten.

ID-basiertes Löschen: Aufgaben können gezielt über ihre eindeutige ID aus der Liste und der Datei entfernt werden.

Tabellarische Ansicht: Übersichtliche Formatierung der Aufgabenliste im Terminal.

# 🛠️ Technische Einblicke
Dein Projekt implementiert wichtige Low-Level-Konzepte:

Strukturen: Die Logik basiert auf einem struct-Array (todos), das in struct.h definiert ist.

Dateizugriff: * readTODOS(): Parst die Datei mit fscanf und lädt Daten in den Arbeitsspeicher.

pushTODOS(): Hängt neue Aufgaben an die Datei an ("a" mode).

deleteTODOS(): Organisiert das Array neu und schreibt die Datei sauber neu ("w" mode).

Speicher-Sicherheit: Verwendung von strlen und Puffer-Kopien, um Überläufe zu vermeiden.
---

https://github.com/user-attachments/assets/ab35b56a-b56a-4c24-8fba-94b5e6b7ad3b

---

# 📂 Projektstruktur
main.c: Die Benutzeroberfläche und Menüführung.

struct.c: Die Logik-Funktionen (read, list, push, delete).

struct.h: Definition der Todo-Struktur und Funktionsprototypen.

saves.txt: Der lokale Datenspeicher.

# ⚠️ Entwickler-Hinweis
Das Programm verfügt über integriertes Error-Handling (perror), falls Probleme beim Zugriff auf die saves.txt auftreten. Bei Fehlern bitte die Dateiberechtigungen oder den Pfad prüfen.
---

# 💡 Feedback and suggestions for improvements are always welcome!

contact us: todo.plusplus.feedback@gmail.com

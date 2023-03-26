# Informatik-Projekt: Rosenblatt Perzeptron
von Raphael Enßlin

[Github Repo](https://github.com/Rajakenhd/rosenblatt-perceptron)

---
---

## System-Anforderungen
- Windows 10+ (für Linux / Mac oder ältere Versionen bitte Konfiguration anpassen)
- Visual C++ Redistributable 2015 oder neuer ([VCRedist2015-2022:](https://learn.microsoft.com/en-us/cpp/windows/latest-supported-vc-redist?view=msvc-170))
- ein Installer für VCRedist64 ist im Hauptverzeichnis vorhanden
- oder Visual Studio C++ Komponenten

## Übersicht
### Grundlegendes
Dieses Programm stellt die Funktionsweise eines Einlagigen Perzeptrons mit n binären Eingaben und einer binären Ausgabe.
Das Perzeptron in diesem Projekt symbolisiert je nach Auswahl AND / OR Logikgatter mit n Eingabewerten. Da Logikgatter die einzelnen Eingänge nicht spezifizieren, sind alle Eingänge gleich gewichtet, wobei die einzelnen Gewichte durch den Lernprozess bestimmt werden.

### Minimalbedingung
Die Minimalbedingung eines Logikgatters ist die Bedingung mit der geringsten Eingabe, bei welcher das Logikgatter umschlägt.

### Programmnutzung - Grundlegend
**Hinweis: Die .ini Datei speichert das Layout und sollte nicht gelöscht werden.**

Im Anfangszustand können zwei Eingaben, sowie die Ausgabe festgelegt werden. Dabei werden Eingabe und Ausgabezustände grafisch unter der Wertetabelle dargestellt. Dann kann das Perzeptron Lernen, wobei mit jeder Aktivierung des Train-Buttons eine Lerniteration ausgeführt wird. Dies sollte solange widerholt werden, bis die Gewichtungstabelle sich nicht mehr verändert. In der Wertetabelle werden alle möglichen Kombinationen für das jeweilige Logikgatter gezeigt. Da die Gewichtung für alle Eingabewerte gleich ist, sind die Positionen der einzelnen Werte austauschbar sind.

### Programmnutzung - Fortgeschritten
Insofern "Erweiterte Optionen" aktiviert sind, können dort die Anzahl der Eingabe-Werte, sowie die Lernrate verändert werden. Jedoch rate ich davon ab die Lernrate zu verändern, da diese sich normalerweise von allein an die Anzahl der Eingabewerte anpasst und somit eine Überspezifikation des Neurons verhindert.
Bei mehr als 2 Input-Nodes wird die grafische Darstellung auf 2 Nodes abstrahiert.

## Logikgatter Klassifizierung
Bei den möglichen Logikgattern / Perzeptrons sind solche für welche die Minimalbedingung die einzige ist, welche den Schwellenwert übersteigt UND-Gatter und alle anderen Modifikationen von ODER-Gattern.

## Build-Anleitung
**Hinweis: JetBrains Rider empfohlen (Visual Studio ist auch möglich)**

- app/InformatikPerzeptron.vcxproj öffnen
- optional: Konfiguration anpassen
- Build ausführen
- Build findet sich unter app/Debug

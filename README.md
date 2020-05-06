#Klasická hra Šachy
Autor: Šimon Vávra

##Zadání

Implementujte následující varianty:

pro 2 hráče na jednom počítači
pro hru proti počítači
Hra musí splňovat následující funkcionality:

Dodržování všech pravidel dané varianty (u klasické varianty tedy i rošáda, braní mimochodem, proměna pěšce na dámu).
Ukládání (resp. načítání) rozehrané hry do (resp. ze) souboru (vytvořte vhodný formát a uživatelské rozhraní)
Oznamovat konec hry (šach, mat, pat) a její výsledek.
umělá inteligence (škálovatelná nebo alespoň 3 různé druhy, jeden druh můžou být náhodné tahy, ale nestačí implementovat pouze náhodné tahy)

Kde lze využít polymorfismus? (doporučené)

Ovládání hráčů: lokální hráč, umělá inteligence (různé druhy), síťový hráč
Pohyby figurek: král, dáma, věž, kůň,...
Uživatelské rozhraní: konzolové, ncurses, SDL, OpenGL (různé druhy),...
Pravidla různých variant: klasické šachy, žravé šachy, asijské šachy
Jednotlivá pravidla: tahy, rošáda, braní mimochodem, proměna (jejich výběr pak může být konfigurovatelný)


##Vlastní implementace

Implementace tradiční verze hry Šachy, využívající konzolové rozhraní pro hru. Hráč bude mít možnost hrát proti hráči, proti počítači, nebo pustit dvě umělé inteligence proti sobě. Počítač bude mít 3 různé inteligenční úrovně. A to náhodné tahy, upravený náhodný algoritmus, který nebude zbytečně vystavovat figurky nebezpečí a bude brát, když to bude možné a minimax. Hru bude možné uložit a načíst z textových souborů s příponou chs. kde bude zápasy uložené jako seznam tahů, které hráči udělali zapsané ve standartním zápisu (https://en.wikipedia.org/wiki/Algebraic_notation_(chess)), bude v nich také specifikováno, jaká strana je jak ovládána a uběhnutý čas hry. Samotná hra se pak bude také ovládat zapisováním standartního zápisu do konzole. //todo technická implementace

##Využití polymorfismu

//todo
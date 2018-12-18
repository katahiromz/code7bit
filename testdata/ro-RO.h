/* �tefan Fulea (stefan dot fulea at mail dot com) */
#pragma once

static MUI_ENTRY roROLanguagePageEntries[] =
{
    {
        4,
        3,
        " Instalare ReactOS " KERNEL_VERSION_STR,
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "Selec�ie limb�",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        10,
        "\x07  Selecta�i limba pentru procesul de instalare.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        11,
        "   Apoi ap�sa�i ENTER.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        13,
        "\x07  Aceasta va fi �n final limba implicit� pentru tot sistemul.",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "ENTER = Continuare  F3 = Ie�ire",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY roROWelcomePageEntries[] =
{
    {
        4,
        3,
        " Instalare ReactOS " KERNEL_VERSION_STR " ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "Bun venit la instalarea ReactOS",
        TEXT_STYLE_HIGHLIGHT
    },
    {
        6,
        11,
        "Aceast� prim� etap� din instalarea ReactOS va copia fi�ierele",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        12,
        "necesare �n calculatorul dumneavoastr� �i-l va preg�ti pentru",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        13,
        "cea de-a doua etap� a instal�rii.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        16,
        "\x07  Press ENTER to install or upgrade ReactOS.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        18,
        "\x07  Tasta�i R pentru a reface un sistem deteriorat.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        21,
        "\x07  Tasta�i L pentru Termenii �i Condi�iile de Licen�iere.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        23,
        "\x07  Ap�sa�i F3 pentru a ie�i f�r� a instala ReactOS.",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        26,
        "Pentru mai multe informa�ii despre ReactOS, vizita�i:",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        27,
        "http://www.reactos.org",
        TEXT_STYLE_HIGHLIGHT
    },
    {
        0,
        0,
        "ENTER = Continuare  R = Refacere  L = Licen��  F3 = Ie�ire",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY roROIntroPageEntries[] =
{
    {
        4,
        3,
        " Instalare ReactOS " KERNEL_VERSION_STR " ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "Starea versiunii curente a ReactOS",
        TEXT_STYLE_HIGHLIGHT
    },
    {
        6,
        11,
        "ReactOS este �n stadiu alfa de dezvoltare, adic� nu are prezint�",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        12,
        "func�ionalit��i complete �i �nc� nu este recomandat� utilizarea sa",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        13,
        "ca sistem de operare de zi cu zi. Asigura�i-v� copii ale datelor",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        15,
        "�n cazul �n care �ncerca�i ReactOS �n mod neemulat.",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        16,
        "",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        19,
        "\x07  Ap�sa�i ENTER pentru a instala ReactOS.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        21,
        "\x07  Ap�sa�i F3 pentru a ie�i f�r� a instala ReactOS.",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "ENTER = Continuare   F3 = Ie�ire",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY roROLicensePageEntries[] =
{
    {
        4,
        3,
        " Instalare ReactOS " KERNEL_VERSION_STR " ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        6,
        "Licen�iere:",
        TEXT_STYLE_HIGHLIGHT
    },
    {
        8,
        8,
        "Sistemul de operare ReactOS este oferit �n termenii Licen�ei",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        9,
        "Publice Generale GNU, referit� �n continuare ca GPL, cu p�r�i",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        10,
        "de cod din alte licen�e compatibile (ca X11, BSD, �i LGPL).",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        12,
        "Toate componentele care fac parte din sistemul ReactOS sunt",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        13,
        "prin urmare oferite sub licen�a GPL, men�in�ndu-�i astfel �i",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        14,
        "licen�ierea original� �n acela�i timp.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        16,
        "Acest sistem vine f�r� vreo restric�ie de utilizare, aceasta",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        17,
        "fiind o condi�ie legislativ� aplicabil� at�t la nivel local",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        18,
        "c�t �i interna�ional. Licen�ierea se refer� doar la distri-",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        19,
        "buirea sistemului ReactOS c�tre p�r�i ter�e.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        21,
        "Dac� din vreun careva motiv nu de�ine�i o copie a licen�ei",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        22,
        "GPL �mpreun� cu ReactOS, o pute�i consulta (�n englez�)",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        23,
        "acces�nd pagina:",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        24,
        "http://www.gnu.org/licenses/licenses.html",
        TEXT_STYLE_HIGHLIGHT
    },
    {
        6,
        27,
        "Garan�ie:",
        TEXT_STYLE_HIGHLIGHT
    },
    {
        8,
        29,
        "Acest sistem de operare este distribuit doar �n speran�a c�",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        30,
        "va fi util, neav�nd �ns� ata�at� NICI O GARAN�IE; nici m�car",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        31,
        "garan�ia implicit� a VANDABILIT��II sau a UTILIT��II �NTR-UN",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        32,
        "SCOP ANUME.",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "ENTER = Revenire",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY roRODevicePageEntries[] =
{
    {
        4,
        3,
        " Instalare ReactOS " KERNEL_VERSION_STR " ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "Configurare dispozitive de baz�",
        TEXT_STYLE_NORMAL
    },
    {
        24,
        11,
        "Arh. de calcul:",
        TEXT_STYLE_NORMAL | TEXT_ALIGN_RIGHT
    },
    {
        24,
        12,
        "Parametri grafici:",
        TEXT_STYLE_NORMAL | TEXT_ALIGN_RIGHT
    },
    {
        24,
        13,
        "Model tastatur�:",
        TEXT_STYLE_NORMAL | TEXT_ALIGN_RIGHT
    },
    {
        24,
        14,
        "Aranj. tastatur�:",
        TEXT_STYLE_NORMAL | TEXT_ALIGN_RIGHT
    },
    {
        24,
        16,
        "Accept�:",
        TEXT_STYLE_NORMAL | TEXT_ALIGN_RIGHT
    },
    {
        25,
        16,
        "Accept configura�ia dispozitivelor",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        19,
        "Pute�i modifica starea curent�. Utiliza�i tastele SUS/JOS pentru",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        20,
        "alegerea unui dispozitiv, apoi ap�sa�i ENTER pentru a-i modifica",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        21,
        "configura�ia ata�at�.",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        23,
        "C�nd configura�ia dispozitivele enumerate este cea corect�,",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        24,
        "selecta�i \"Accept configura�ia dispozitivelor\", apoi confirma�i",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        25,
        "ap�s�nd ENTER.",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "ENTER = Continuare   F3 = Ie�ire",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY roRORepairPageEntries[] =
{
    {
        4,
        3,
        " Instalare ReactOS " KERNEL_VERSION_STR " ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "Programul de instalare ReactOS este �nc� �ntr-o faz� incipient� de",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        9,
        "dezvoltare �i nu posed� o func�ionalitate complet�.",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        12,
        "Func�ionalitatea de refacere �nc� nu este implementat�.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        15,
        "\x07  Tasta�i U pentru actualizarea sistemului.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        17,
        "\x07  Tasta�i R pentru consola de Recuperare.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        19,
        "\x07  Ap�sa�i ESC pentru a reveni la pagina principal�.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        21,
        "\x07  Ap�sa�i ENTER pentru a reporni calculatorul.",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "ESC = Revenire  U = Actualizare  R = Recuperare  ENTER = Repornire",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY roROUpgradePageEntries[] =
{
    {
        4,
        3,
        " ReactOS " KERNEL_VERSION_STR " Setup ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "The ReactOS Setup can upgrade one of the available ReactOS installations",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        9,
        "listed below, or, if a ReactOS installation is damaged, the Setup program",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        10,
        "can attempt to repair it.",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        12,
        "The repair functions are not all implemented yet.",
        TEXT_STYLE_HIGHLIGHT
    },
    {
        8,
        15,
        "\x07  Press UP or DOWN to select an OS installation.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        17,
        "\x07  Press U for upgrading the selected OS installation.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        19,
        "\x07  Press ESC to continue with a new installation.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        21,
        "\x07  Press F3 to quit without installing ReactOS.",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "U = Upgrade   ESC = Do not upgrade   F3 = Quit",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY roROComputerPageEntries[] =
{
    {
        4,
        3,
        " Instalare ReactOS " KERNEL_VERSION_STR " ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "Dori�i specificarea unei alte arhitecturi de calcul?",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        10,
        "\x07  Utiliza�i tastele SUS/JOS pentru a selecta o",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        11,
        "   arhitectur� de calcul, apoi ap�sa�i ENTER.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        13,
        "\x07  Ap�sa�i ESC pentru a reveni la pagina precedent�",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        14,
        "   f�r� a specifica o alt� arhitectur� de calcul.",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "ENTER = Continuare   ESC = Anulare   F3 = Ie�ire",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY roROFlushPageEntries[] =
{
    {
        4,
        3,
        " Instalare ReactOS " KERNEL_VERSION_STR " ",
        TEXT_STYLE_UNDERLINE
    },
    {
        10,
        6,
        "Sistemul verific� integritatea datelor scrise pe disc.",
        TEXT_STYLE_NORMAL
    },
    {
        10,
        8,
        "Aceasta poate dura c�teva momente.",
        TEXT_STYLE_NORMAL
    },
    {
        10,
        9,
        "La final, calculatorul va fi repornit automat.",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "Eliberare memorie...",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY roROQuitPageEntries[] =
{
    {
        4,
        3,
        " Instalare ReactOS " KERNEL_VERSION_STR " ",
        TEXT_STYLE_UNDERLINE
    },
    {
        10,
        6,
        "ReactOS nu a fost instalat �n �ntregime.",
        TEXT_STYLE_NORMAL
    },
    {
        10,
        8,
        "Scoate�i discul flexibil din unitatea A:",
        TEXT_STYLE_NORMAL
    },
    {
        10,
        9,
        "�i toate mediile CD-ROM din unit��ile CD.",
        TEXT_STYLE_NORMAL
    },
    {
        10,
        11,
        "Ap�sa�i ENTER pentru a reporni calculatorul.",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "A�tepta�i...",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG,
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY roRODisplayPageEntries[] =
{
    {
        4,
        3,
        " Instalare ReactOS " KERNEL_VERSION_STR " ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "Dori�i modificarea parametrilor grafici de afi�are?",
        TEXT_STYLE_NORMAL
    },
    {   8,
        10,
        "\x07  Utiliza�i tastele SUS/JOS pentru a selecta",
         TEXT_STYLE_NORMAL
    },
    {
        8,
        11,
        "   un grup de parametri, apoi ap�sa�i ENTER.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        13,
        "\x07  Ap�sa�i ESC pentru a reveni la pagina precedent�",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        14,
        "   fara a modifica parametrii grafici actuali.",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "ENTER = Continuare   ESC = Anulare   F3 = Ie�ire",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY roROSuccessPageEntries[] =
{
    {
        4,
        3,
        " Instalare ReactOS " KERNEL_VERSION_STR " ",
        TEXT_STYLE_UNDERLINE
    },
    {
        10,
        6,
        "Componentele de baz� ale ReactOS au fost instalate cu succes.",
        TEXT_STYLE_NORMAL
    },
    {
        10,
        8,
        "Scoate�i discul flexibil din unitatea A: �i toate mediile",
        TEXT_STYLE_NORMAL
    },
    {
        10,
        9,
        "CD-ROM din unit��ile CD.",
        TEXT_STYLE_NORMAL
    },
    {
        10,
        11,
        "Ap�sa�i ENTER pentru a reporni calculatorul.",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "ENTER = Repornire calculator",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY roROBootPageEntries[] =
{
    {
        4,
        3,
        " Instalare ReactOS " KERNEL_VERSION_STR " ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "Programul de instalare nu poate instala modulul de",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        9,
        "ini�ializare a calculatorului pe discul local.",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        13,
        "Introduce�i un disc flexibil formatat �n",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        14,
        "unitatea A: apoi s� ap�sa�i ENTER.",
        TEXT_STYLE_NORMAL,
    },
    {
        0,
        0,
        "ENTER = Continuare   F3 = Ie�ire",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }

};

static MUI_ENTRY roROSelectPartitionEntries[] =
{
    {
        4,
        3,
        " Instalare ReactOS " KERNEL_VERSION_STR " ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "Urm�toarea list� cuprinde parti�iile existente, precum �i",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        9,
        "spa�iul liber disponibil pentru crearea de noi parti�ii.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        11,
        "\x07  Utiliza�i tastele SUS/JOS pentru a selecta o op�iune.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        13,
        "\x07  Ap�sa�i ENTER pentru a instala pe parti�ia selectat�.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        15,
        "\x07  Tasta�i P pentru a crea o parti�ie primar�.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        17,
        "\x07  Tasta�i E pentru a crea o parti�ie extins�.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        19,
        "\x07  Tasta�i L pentru a crea o parti�ie logic�.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        21,
        "\x07  Tasta�i D pentru a �terge o parti�ie existent�.",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "A�tepta�i...",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY roROConfirmDeleteSystemPartitionEntries[] =
{
    {
        4,
        3,
        " Instalare ReactOS " KERNEL_VERSION_STR,
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "A�i solicitat �tergerea parti�iei de sistem.",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        10,
        "Parti�iile de sistem pot con�ine programe de diagnoz�, programe de con-",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        11,
        "figurare a echipamentelor, programe de lansare a unui sistem de operare",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        12,
        "(ca ReactOS) �i alte programe furnizate de produc�torii calculorului.",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        14,
        "�terge�i o parti�ie de sistem doar c�nd sunte�i siguri c� nu exist� a�a",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        15,
        "programe pe parti�ie, sau c�nd sunte�i siguri c� dori�i s� le �terge�i.",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        16,
        "�terg�nd parti�ia apare riscul de a nu mai putea porni calculatorul de",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        17,
        "pe discul local dec�t dup� finalizarea instal�rii ReactOS.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        20,
        "\x07  Ap�sa�i ENTER pentru a �terge parti�ia de sistem. Vi se va",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        21,
        "   cere s� confirma�i din nou aceast� �tergere a parti�iei.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        24,
        "\x07  Ap�sa�i ESC pentru a reveni la pagina precedent�. Parti�ia",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        25,
        "   nu va fi �tears�.",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "ENTER = Continuare   ESC = Anulare",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY roROFormatPartitionEntries[] =
{
    {
        4,
        3,
        " Instalare ReactOS " KERNEL_VERSION_STR " ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "Urmeaz� formatarea parti�iei.",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        10,
        "Ap�sa�i ENTER pentru a continua.",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "ENTER = Continuare   F3 = Ie�ire",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        TEXT_STYLE_NORMAL
    }
};

static MUI_ENTRY roROInstallDirectoryEntries[] =
{
    {
        4,
        3,
        " Instalare ReactOS " KERNEL_VERSION_STR " ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "Alege�i un director de instalare pe parti�ia aleas�.",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        9,
        "Aici vor fi amplasate fi�ierele sistemului ReactOS:",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        14,
        "Pute�i indica un alt director, ap�s�nd BACKSPACE pentru",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        15,
        "a �terge caractere, apoi scriind calea directorului unde",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        16,
        "dori�i s� instala�i ReactOS.",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "ENTER = Continuare   F3 = Ie�ire",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY roROFileCopyEntries[] =
{
    {
        4,
        3,
        " Instalare ReactOS " KERNEL_VERSION_STR " ",
        TEXT_STYLE_UNDERLINE
    },
    {
        0,
        12,
        "Are loc copierea de fi�iere �n directorul ReactOS specificat.",
        TEXT_STYLE_NORMAL | TEXT_ALIGN_CENTER
    },
    {
        0,
        14,
        "(aceasta poate dura c�teva momente)",
        TEXT_STYLE_NORMAL | TEXT_ALIGN_CENTER
    },
    {
        50,
        0,
        "\xB3 A�tepta�i...",
        TEXT_TYPE_STATUS
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY roROBootLoaderEntries[] =
{
    {
        4,
        3,
        " Instalare ReactOS " KERNEL_VERSION_STR " ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "Instalare modul de ini�ializare al calculatorului",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        12,
        "Instaleaz� ini�ializatorul pe discul intern (MBR �i VBR).",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        13,
        "Instaleaz� ini�ializatorul pe discul intern (doar VBR).",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        14,
        "Instaleaz� ini�ializatorul pe un disc flexibil.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        15,
        "Omite instalarea modulului de ini�ializare.",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "ENTER = Continuare   F3 = Ie�ire",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY roROKeyboardSettingsEntries[] =
{
    {
        4,
        3,
        " Instalare ReactOS " KERNEL_VERSION_STR " ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "Dori�i specificarea modelului tastaturii instalate?",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        10,
        "\x07  Utiliza�i tastele SUS/JOS pentru a selecta un model",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        11,
        "   de tastatur�, apoi ap�sa�i ENTER.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        13,
        "\x07  Ap�sa�i ESC pentru a reveni la pagina precedent� f�r�",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        14,
        "   a schimba modelul tastaturii curente.",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "ENTER = Continuare   ESC = Anulare   F3 = Ie�ire",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY roROLayoutSettingsEntries[] =
{
    {
        4,
        3,
        " Instalare ReactOS " KERNEL_VERSION_STR " ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "Dori�i specificarea unui aranjament implicit de tastatur�?",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        10,
        "\x07  Utiliza�i tastele SUS/JOS pentru a selecta un aranjament",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        11,
        "    dorit de tastatur�, apoi ap�sa�i ENTER.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        13,
        "\x07  Ap�sa�i ESC pentru a reveni la pagina precedent� f�r�",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        14,
        "   a schimba aranjamentul curent al tastaturii.",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "ENTER = Continuare   ESC = Anulare   F3 = Ie�ire",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    },

};

static MUI_ENTRY roROPrepareCopyEntries[] =
{
    {
        4,
        3,
        " Instalare ReactOS " KERNEL_VERSION_STR " ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "Au loc preg�tirile necesare pentru copierea de fi�iere.",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "List� de fi�iere �n curs de creare...",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    },

};

static MUI_ENTRY roROSelectFSEntries[] =
{
    {
        4,
        3,
        " Instalare ReactOS " KERNEL_VERSION_STR " ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        14,
        "Alege�i un sistem de fi�iere din lista de mai jos.",
        0
    },
    {
        8,
        16,
        "\x07  Utiliza�i tastele SUS/JOS pentru a selecta",
        0
    },
    {
        8,
        17,
        "   un sistem de fi�iere.",
        0
    },
    {
        8,
        19,
        "\x07  Ap�sa�i ENTER pentru a formata parti�ia.",
        0
    },
    {
        8,
        21,
        "\x07  Ap�sa�i ESC pentru a alege o alt� parti�ie.",
        0
    },
    {
        0,
        0,
        "ENTER = Continuare   ESC = Anulare   F3 = Ie�ire",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },

    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY roRODeletePartitionEntries[] =
{
    {
        4,
        3,
        " Instalare ReactOS " KERNEL_VERSION_STR " ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "A�i ales s� �terge�i parti�ia",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        18,
        "\x07  Tasta�i D pentru a �terge parti�ia.",
        TEXT_STYLE_NORMAL
    },
    {
        11,
        19,
        "ATEN�IE: Toate datele de pe aceast� parti�ie vor fi pierdute!",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        21,
        "\x07  Ap�sa�i ESC pentru a anula.",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "D = �tergere parti�ie   ESC = Anulare   F3 = Ie�ire",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY roRORegistryEntries[] =
{
    {
        4,
        3,
        " Instalare ReactOS " KERNEL_VERSION_STR " ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "Are loc actualizarea configura�iei sistemului.",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "Registru �n curs de creare...",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    },

};

MUI_ERROR roROErrorEntries[] =
{
    {
        // NOT_AN_ERROR
        "Succes\n"
    },
    {
        // ERROR_NOT_INSTALLED
        "ReactOS nu a fost instalat �n totalitate �n calculator.\n"
        "Dac� abandona�i instalarea acum, alt� dat�, pentru a\n"
        "instala ReactOS, va fi nevoie s� repeta�i to�i pa�ii.\n"
        "\n"
        "  \x07  Ap�sa�i ENTER pentru a continua instalarea.\n"
        "  \x07  Ap�sa�i F3 pentru a abandona instalarea.",
        "F3 = Ie�ire  ENTER = Continuare"
    },
    {
        // ERROR_NO_HDD
        "E�ec la identificarea unit��ilor interne de stocare.",
        "ENTER = Repornire calculator"
    },
    {
        // ERROR_NO_SOURCE_DRIVE
        "E�ec la accesarea unitat��ii de instalare.",
        "ENTER = Repornire calculator"
    },
    {
        // ERROR_LOAD_TXTSETUPSIF
        "E�ec la �nc�rcarea fi�ierul TXTSETUP.SIF.",
        "ENTER = Repornire calculator"
    },
    {
        // ERROR_CORRUPT_TXTSETUPSIF
        "Fi�ieul TXTSETUP.SIF a fos g�sit deteriorat.",
        "ENTER = Repornire calculator"
    },
    {
        // ERROR_SIGNATURE_TXTSETUPSIF,
        "Fi�ierul TXTSETUP.SIF con�ine o semn�tur� nevalid�.",
        "ENTER = Repornire calculator"
    },
    {
        // ERROR_DRIVE_INFORMATION
        "E�ec la ob�inerea de informa�ii despre\n"
        "dispozitivele din calculator.\n",
        "ENTER = Repornire calculator"
    },
    {
        // ERROR_WRITE_BOOT,
        "E�ec la instalarea codului %S de ini�ializare\n"
        "pe parti�ia de sistem.",
        "ENTER = Repornire calculator"
    },
    {
        // ERROR_LOAD_COMPUTER,
        "E�ec la �nc�rcarea listei cu arhitecturi de\n"
        "calcul disponibile.",
        "ENTER = Repornire calculator"
    },
    {
        // ERROR_LOAD_DISPLAY,
        "E�ec la �nc�rcarea listei cu parametri de\n"
        "afi�are pentru ecran.",
        "ENTER = Repornire calculator"
    },
    {
        // ERROR_LOAD_KEYBOARD,
        "E�ec la �nc�rcarea listei cu tipuri\n"
        "disponibile de tastatur�.",
        "ENTER = Repornire calculator"
    },
    {
        // ERROR_LOAD_KBLAYOUT,
        "E�ec la �nc�rcarea listei de configura�ii\n"
        "ale tastaturii.",
        "ENTER = Repornire calculator"
    },
    {
        // ERROR_WARN_PARTITION,
        "A fost g�sit� cel pu�in un disc cu tabel� nerecunoscut�\n"
        "de parti�ii, care nu poate fi gestionat� corespunz�tor!\n"
        "\n"
        "Crearea sau �tergerea de parti�ii poate astfel cauza\n"
        "distrugerea tabelei de parti�ii."
        "\n"
        "  \x07  Ap�sa�i F3 pentru a abandona instalarea.\n"
        "  \x07  Ap�sa�i ENTER pentru a continua.",
        "F3 = Ie�ire  ENTER = Continuare"
    },
    {
        // ERROR_NEW_PARTITION,
        "O parti�ie nou� nu poate fi creat� �n interiorul\n"
        "unei parti�ii existente!\n"
        "\n"
        "  * Tasta�i pentru a continua.",
        NULL
    },
    {
        // ERROR_DELETE_SPACE,
        "A�i �ncercat �tergerea de spa�iu neparti�ionat,\n"
        "�ns� doar spa�iul parti�ionat poate fi �ters!\n"
        "\n"
        "  * Tasta�i pentru a continua.",
        NULL
    },
    {
        // ERROR_INSTALL_BOOTCODE,
        "E�ec la instalarea codului %S de ini�ializare\n"
        "pe parti�ia de sistem.",
        "ENTER = Repornire calculator"
    },
    {
        // ERROR_NO_FLOPPY,
        "Nu exist� discuri flexibile �n unitatea A:",
        "ENTER = Continuare"
    },
    {
        // ERROR_UPDATE_KBSETTINGS,
        "E�ec la actualizarea configura�iei de tastatur�.",
        "ENTER = Repornire calculator"
    },
    {
        // ERROR_UPDATE_DISPLAY_SETTINGS,
        "E�ec la actualizarea registrului cu\n"
        "parametrii grafici ai ecranului!",
        "ENTER = Repornire calculator"
    },
    {
        // ERROR_IMPORT_HIVE,
        "E�ec la importarea registrului.",
        "ENTER = Repornire calculator"
    },
    {
        // ERROR_FIND_REGISTRY
        "E�ec la localizarea fi�ierelor\n"
        "cu datele registrului.",
        "ENTER = Repornire calculator"
    },
    {
        // ERROR_CREATE_HIVE,
        "E�ec la crearea registrului.",
        "ENTER = Repornire calculator"
    },
    {
        // ERROR_INITIALIZE_REGISTRY,
        "E�ec la ini�ializarea registrului.",
        "ENTER = Repornire calculator"
    },
    {
        // ERROR_INVALID_CABINET_INF,
        "Fi�ierul cabinet nu con�ine nici\n"
        "un fi�ier valid de tip inf.",
        "ENTER = Repornire calculator"
    },
    {
        // ERROR_CABINET_MISSING,
        "E�ec la localizarea fi�ierului cabinet.\n",
        "ENTER = Repornire calculator"
    },
    {
        // ERROR_CABINET_SCRIPT,
        "Fi�ierul cabinet nu con�ine nici\n"
        "un script de instalare.",
        "ENTER = Repornire calculator"
    },
    {
        // ERROR_COPY_QUEUE,
        "E�ec la accesarea listei cu\n"
        "fi�iere pentru copiere.",
        "ENTER = Repornire calculator"
    },
    {
        // ERROR_CREATE_DIR,
        "E�ec la crearea directoarelor de instalare.",
        "ENTER = Repornire calculator"
    },
    {
        // ERROR_TXTSETUP_SECTION,
        "E�ec la identificarea sec�iunii\n"
        "'%S' �n fi�ierul TXTSETUP.SIF.",
        "ENTER = Repornire calculator"
    },
    {
        // ERROR_CABINET_SECTION,
        "E�ec la identificarea sec�iunii\n"
        "'%S' �n fi�ierul cabinet.",
        "ENTER = Repornire calculator"
    },
    {
        // ERROR_CREATE_INSTALL_DIR
        "E�ec la crearea directorului de instalare.",
        "ENTER = Repornire calculator"
    },
    {
        // ERROR_WRITE_PTABLE,
        "E�ec la scrierea tabelelor de parti�ii.\n",
        "ENTER = Repornire calculator"
    },
    {
        // ERROR_ADDING_CODEPAGE,
        "E�ec la includerea pagin�rii �n registru.\n",
        "ENTER = Repornire calculator"
    },
    {
        // ERROR_UPDATE_LOCALESETTINGS,
        "E�ec la instituirea sistemului de localizare.\n",
        "ENTER = Repornire calculator"
    },
    {
        // ERROR_ADDING_KBLAYOUTS,
        "E�ec la includerea �n registru a configura�iei\n"
        "de tastatur�.",
        "ENTER = Repornire calculator"
    },
    {
        // ERROR_UPDATE_GEOID,
        "E�ec la instituirea de geo id.",
        "ENTER = Repornire calculator"
    },
    {
        // ERROR_DIRECTORY_NAME,
        "Numele de director este nevalid.\n"
        "\n"
        "  * Tasta�i pentru a continua."
    },
    {
        // ERROR_INSUFFICIENT_PARTITION_SIZE,
        "Parti�ia selectat� este prea mic� pentru a instala ReactOS.\n"
        "Parti�ia de instalare trebuie s� aib� cel pu�in %lu Mocte�i.\n"
        "\n"
        "  * Tasta�i pentru a continua.",
        NULL
    },
    {
        // ERROR_PARTITION_TABLE_FULL,
        "Nu poate fi creat� o nou� parti�ie primar� sau extins� �n tabela\n"
        "de parti�ii a acestui disc deoarece tabela de parti�ii e plin�.\n"
        "\n"
        "  * Tasta�i pentru a continua."
    },
    {
        // ERROR_ONLY_ONE_EXTENDED,
        "Nu poate fi creat� mai mult de o parti�ie extins� pe un disc.\n"
        "\n"
        "  * Tasta�i pentru a continua."
    },
    {
        // ERROR_FORMATTING_PARTITION,
        "E�ec la formatarea parti�iei:\n"
        " %S\n"
        "\n"
        "ENTER = Repornire calculator"
    },
    {
        NULL,
        NULL
    }
};

MUI_PAGE roROPages[] =
{
    {
        LANGUAGE_PAGE,
        roROLanguagePageEntries
    },
    {
        WELCOME_PAGE,
        roROWelcomePageEntries
    },
    {
        INSTALL_INTRO_PAGE,
        roROIntroPageEntries
    },
    {
        LICENSE_PAGE,
        roROLicensePageEntries
    },
    {
        DEVICE_SETTINGS_PAGE,
        roRODevicePageEntries
    },
    {
        REPAIR_INTRO_PAGE,
        roRORepairPageEntries
    },
    {
        UPGRADE_REPAIR_PAGE,
        roROUpgradePageEntries
    },
    {
        COMPUTER_SETTINGS_PAGE,
        roROComputerPageEntries
    },
    {
        DISPLAY_SETTINGS_PAGE,
        roRODisplayPageEntries
    },
    {
        FLUSH_PAGE,
        roROFlushPageEntries
    },
    {
        SELECT_PARTITION_PAGE,
        roROSelectPartitionEntries
    },
    {
        CONFIRM_DELETE_SYSTEM_PARTITION_PAGE,
        roROConfirmDeleteSystemPartitionEntries
    },
    {
        SELECT_FILE_SYSTEM_PAGE,
        roROSelectFSEntries
    },
    {
        FORMAT_PARTITION_PAGE,
        roROFormatPartitionEntries
    },
    {
        DELETE_PARTITION_PAGE,
        roRODeletePartitionEntries
    },
    {
        INSTALL_DIRECTORY_PAGE,
        roROInstallDirectoryEntries
    },
    {
        PREPARE_COPY_PAGE,
        roROPrepareCopyEntries
    },
    {
        FILE_COPY_PAGE,
        roROFileCopyEntries
    },
    {
        KEYBOARD_SETTINGS_PAGE,
        roROKeyboardSettingsEntries
    },
    {
        BOOT_LOADER_PAGE,
        roROBootLoaderEntries
    },
    {
        LAYOUT_SETTINGS_PAGE,
        roROLayoutSettingsEntries
    },
    {
        QUIT_PAGE,
        roROQuitPageEntries
    },
    {
        SUCCESS_PAGE,
        roROSuccessPageEntries
    },
    {
        BOOT_LOADER_FLOPPY_PAGE,
        roROBootPageEntries
    },
    {
        REGISTRY_PAGE,
        roRORegistryEntries
    },
    {
        -1,
        NULL
    }
};

MUI_STRING roROStrings[] =
{
    {STRING_PLEASEWAIT,
     "   A�tepta�i..."},
    {STRING_INSTALLCREATEPARTITION,
     "   ENTER = Instalare   P/E = Creare parti�ie Primar�/Extins�   F3 = Ie�ire"},
    {STRING_INSTALLCREATELOGICAL,
     "   ENTER = Instalare   L = Creare parti�ie Logic�   F3 = Ie�ire"},
    {STRING_INSTALLDELETEPARTITION,
     "   ENTER = Instalare   D = �tergere parti�ie   F3 = Ie�ire"},
    {STRING_DELETEPARTITION,
     "   D = �tergere parti�ie   F3 = Ie�ire"},
    {STRING_PARTITIONSIZE,
     "M�rimea noii parti�ii:"},
    {STRING_CHOOSENEWPARTITION,
     "A�i ales crearea unei parti�ii primare pe"},
    {STRING_CHOOSE_NEW_EXTENDED_PARTITION,
     "A�i ales crearea unei parti�ii extinse pe"},
    {STRING_CHOOSE_NEW_LOGICAL_PARTITION,
     "A�i ales crearea unei parti�ii logice pe"},
    {STRING_HDDSIZE,
    "Introduce�i m�rimea noii parti�ii �n megaocte�i."},
    {STRING_CREATEPARTITION,
     "   ENTER = Creare parti�ie   ESC = Anulare   F3 = Ie�ire"},
    {STRING_PARTFORMAT,
    "Aceast� parti�ie urmeaz� s� fie formatat�."},
    {STRING_NONFORMATTEDPART,
    "Alege�i s� instala�i ReactOS pe parti�ie nou� sau neformatat�."},
    {STRING_NONFORMATTEDSYSTEMPART,
    "Parti�ia de sistem �nc� nu a fost formatat�."},
    {STRING_NONFORMATTEDOTHERPART,
    "Noua parti�ie �nc� nu a fost formatat�."},
    {STRING_INSTALLONPART,
    "ReactOS va fi instalat pe parti�ia"},
    {STRING_CHECKINGPART,
    "Programul de instalare verific� acum parti�ia aleas�."},
    {STRING_CONTINUE,
    "ENTER = Continuare"},
    {STRING_QUITCONTINUE,
    "F3 = Ie�ire  ENTER = Continuare"},
    {STRING_REBOOTCOMPUTER,
    "ENTER = Repornire calculator"},
    {STRING_DELETING,
     "   Deleting file: %S"},
    {STRING_MOVING,
     "   Moving file: %S to: %S"},
    {STRING_RENAMING,
     "   Renaming file: %S to: %S"},
    {STRING_COPYING,
     "   Fi�ierul curent: %S"},
    {STRING_SETUPCOPYINGFILES,
     "Fi�iere �n curs de copiere..."},
    {STRING_REGHIVEUPDATE,
    "   Registru �n curs de actualizare..."},
    {STRING_IMPORTFILE,
    "   �n curs de importare din %S..."},
    {STRING_DISPLAYSETTINGSUPDATE,
    "   Registru de configura�ie grafic� �n actualizare..."},
    {STRING_LOCALESETTINGSUPDATE,
    "   Particularit��i locale �n actualizare..."},
    {STRING_KEYBOARDSETTINGSUPDATE,
    "   Configura�ie de tastatur� �n actualizare..."},
    {STRING_CODEPAGEINFOUPDATE,
    "   Date de paginare �n curs de adaugare �n registru..."},
    {STRING_DONE,
    "   Terminat!"},
    {STRING_REBOOTCOMPUTER2,
    "   ENTER = Repornire calculator"},
    {STRING_REBOOTPROGRESSBAR,
    " Calculatorul va reporni �n %li secunde... "},
    {STRING_CONSOLEFAIL1,
    "E�ec la deschiderea consolei\r\n\r\n"},
    {STRING_CONSOLEFAIL2,
    "Cea mai frecvent� cauz� pentru asta este utilizarea unei tastaturi USB\r\n"},
    {STRING_CONSOLEFAIL3,
    "Tastaturile USB nu sunt �nc� toate acceptate\r\n"},
    {STRING_FORMATTINGDISK,
    "Disc �n curs de formatare..."},
    {STRING_CHECKINGDISK,
    "Disc �n curs de verificare..."},
    {STRING_FORMATDISK1,
    " Formateaz� parti�ia ca sistem de fi�iere %S (formatare rapid�) "},
    {STRING_FORMATDISK2,
    " Formateaz� parti�ia ca sistem de fi�iere %S "},
    {STRING_KEEPFORMAT,
    " P�streaz� sistemul de fi�iere actual (f�r� schimb�ri) "},
    {STRING_HDINFOPARTCREATE_1,
    "%I64u %s  Discul %lu  (Port=%hu, Magistrala=%hu, Id=%hu) de tip %wZ [%s]."},
    {STRING_HDINFOPARTCREATE_2,
    "%I64u %s  Discul %lu  (Port=%hu, Magistrala=%hu, Id=%hu) [%s]."},
    {STRING_HDDINFOUNK2,
    "   %c%c  Tip 0x%02X    %I64u %s"},
    {STRING_HDINFOPARTDELETE_1,
    "de pe %I64u %s  Discul %lu  (Port=%hu, Magistrala=%hu, Id=%hu) de tip %wZ [%s]."},
    {STRING_HDINFOPARTDELETE_2,
    "de pe %I64u %s  Discul %lu  (Port=%hu, Magistrala=%hu, Id=%hu) [%s]."},
    {STRING_HDINFOPARTZEROED_1,
    "Discul %lu (%I64u %s), Port=%hu, Magistrala=%hu, Id=%hu (%wZ) [%s]."},
    {STRING_HDDINFOUNK4,
    "%c%c  Tip 0x%02X    %I64u %s"},
    {STRING_HDINFOPARTEXISTS_1,
    "de pe Discul %lu (%I64u %s), Port=%hu, Magistrala=%hu, Id=%hu (%wZ) [%s]."},
    {STRING_HDDINFOUNK5,
    "%c%c %c %sTip %-3u%s                      %6lu %s"},
    {STRING_HDINFOPARTSELECT_1,
    "%6lu %s  Discul %lu  (Port=%hu, Magistrala=%hu, Id=%hu) de tip %wZ [%s]"},
    {STRING_HDINFOPARTSELECT_2,
    "%6lu %s  Discul %lu  (Port=%hu, Magistrala=%hu, Id=%hu) [%s]"},
    {STRING_NEWPARTITION,
    "O nou� parti�ie a fost creat� �n"},
    {STRING_UNPSPACE,
    "    %sSpa�iu neparti�ionat%s           %6lu %s"},
    {STRING_MAXSIZE,
    "Mo (max. %lu Mo)"},
    {STRING_EXTENDED_PARTITION,
    "Parti�ie extins�"},
    {STRING_UNFORMATTED,
    "Part. nou� (neformatat�)"},
    {STRING_FORMATUNUSED,
    "Nefolosit"},
    {STRING_FORMATUNKNOWN,
    "Necunoscut"},
    {STRING_KB,
    "ko"},
    {STRING_MB,
    "Mo"},
    {STRING_GB,
    "Go"},
    {STRING_ADDKBLAYOUTS,
    "Ad�ugare configura�ii de tastatur�"},
    {0, 0}
};

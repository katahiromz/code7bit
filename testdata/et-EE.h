#pragma once

static MUI_ENTRY etEELanguagePageEntries[] =
{
    {
        4,
        3,
        " ReactOS " KERNEL_VERSION_STR " paigaldus ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "Keele valik",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        10,
        "\x07  Vali paigaldamisel kasutatav keel.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        11,
        "   Seej�rel vajuta ENTER.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        13,
        "\x07  Seda keelt kasutatakse hiljem s�steemi keelena.",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "ENTER = J�tka  F3 = V�lju",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY etEEWelcomePageEntries[] =
{
    {
        4,
        3,
        " ReactOS " KERNEL_VERSION_STR " paigaldus ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "Tere tulemast ReactOS'i paigaldusse",
        TEXT_STYLE_HIGHLIGHT
    },
    {
        6,
        11,
        "Selles paigaldamise etapis kopeeritakse ReactOSi failid arvutisse ja",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        12,
        "valmistatakse ette paigaldamise teine j�rk.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        15,
        "\x07  Press ENTER to install or upgrade ReactOS.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        17,
        "\x07  Vajuta R, et ReactOS'i parandada.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        19,
        "\x07  Vajuta L, et n�ha ReactOS'i litsentsi ja kasutamise tingimusi",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        21,
        "\x07  Vajuta F3, et v�ljuda ReactOS'i paigaldamata.",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        23,
        "ReactOS'i kohta saab rohkem infot:",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        24,
        "http://www.reactos.org",
        TEXT_STYLE_HIGHLIGHT
    },
    {
        0,
        0,
        "ENTER = J�tka  R = Paranda  L = Litsents  F3 = V�lju",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY etEEIntroPageEntries[] =
{
    {
        4,
        3,
        " ReactOS " KERNEL_VERSION_STR " paigaldus ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "ReactOS'i versiooni seisund",
        TEXT_STYLE_HIGHLIGHT
    },
    {
        6,
        11,
        "ReactOS on alfa etapis, mis t�hendab et see ei ole veel funktsionaalselt",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        12,
        "t�iuslik ja on t�sises arenguses. Seda on soovitatud ainult kasutada",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        13,
        "tutvumise ja proovimise eesm�rkidel, aga mitte igap�evalise os�steemina.",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        15,
        "Varundage enda andmed v�i proovi teisej�rgulisel arvutil kui proovite",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        16,
        "ReactOS'i p�ris riistvara peal'.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        19,
        "\x07  Vajuta ENTER, et siseneda ReactOS'i paigaldusse.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        21,
        "\x07  Vajuta F3, et lahkuda ReactOS'i paigaldamata.",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "ENTER = J�tka   F3 = V�lju",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY etEELicensePageEntries[] =
{
    {
        4,
        3,
        " ReactOS " KERNEL_VERSION_STR " paigaldus ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        6,
        "Litsents:",
        TEXT_STYLE_HIGHLIGHT
    },
    {
        8,
        8,
        "ReactOS kasutab GNU �ldist avalikku litsentsi(GPL),",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        9,
        "m�ned komponendid kasutavad muid �hilduvaid litsentse,",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        10,
        "nagu n�iteks X11, BSD ja GNU LGPL.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        11,
        "Kogu ReactOS'i s�steem on seega kaitstud GPL litsentsiga",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        12,
        "ning samas kehtivad ka algsed litsentsid.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        13,
        "",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        15,
        "K�esoleva tarkvaraga ei anta kaasa garantiid ega m��rata kasutamise",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        16,
        "piiranguid kehtiva seadusega s�testatud piirides. ReactOSi",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        17,
        "litsents m��rab ainult levitamise kolmandatele osapooltele.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        18,
        "Kui mingil p�hjusel ei olnud tarkvaraga kaasas GNU GPL",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        19,
        "�ldist avalikku litsentsi, siis saab seda vaadata lehel",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        20,
        "http://www.gnu.org/licenses/licenses.html",
        TEXT_STYLE_HIGHLIGHT
    },
    {
        8,
        22,
        "Garantii:",
        TEXT_STYLE_HIGHLIGHT
    },
    {
        8,
        24,
        "Tegemist on vaba tarkvaraga; kopeerimise tingimused on kirjas algkoodis.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        25,
        "Garantii puudub; pole isegi turustamiseks v�i mingil",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        26,
        "kindlal eesm�rgil kasutamiseks sobivuse garantiid",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "ENTER = Tagasi",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY etEEDevicePageEntries[] =
{
    {
        4,
        3,
        " ReactOS " KERNEL_VERSION_STR " paigaldus ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "J�rgnev nimekiri n�itab riistvara seadeid.",
        TEXT_STYLE_NORMAL
    },
    {
        24,
        11,
        "Arvuti:",
        TEXT_STYLE_NORMAL | TEXT_ALIGN_RIGHT
    },
    {
        24,
        12,
        "Ekraan:",
        TEXT_STYLE_NORMAL | TEXT_ALIGN_RIGHT
    },
    {
        24,
        13,
        "Klaviatuur:",
        TEXT_STYLE_NORMAL | TEXT_ALIGN_RIGHT
    },
    {
        24,
        14,
        "Klaviatuuri asetus:",
        TEXT_STYLE_NORMAL | TEXT_ALIGN_RIGHT
    },
    {
        24,
        16,
        "Rakenda:",
        TEXT_STYLE_NORMAL | TEXT_ALIGN_RIGHT
    },
    {
        25,
        16, "Rakenda need s�tted",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        19,
        "Riistvara s�tteid saab muuta �les ja alla liikudes.",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        20,
        "Seadistuse muutmiseks vajuta ENTER.",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        21,
        "",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        23,
        "Kui seadistus on paigas, vali \"Rakenda need s�tted\"",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        24,
        "ja vajuta ENTER.",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "ENTER = J�tka   F3 = V�lju",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY etEERepairPageEntries[] =
{
    {
        4,
        3,
        " ReactOS " KERNEL_VERSION_STR " paigaldus ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "ReactOS'i paigaldusprogramm on varajases arendusfaasis. Praegu ei ole",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        9,
        "veel k�ik korraliku paigaldusprogrammi funktsioonid toetatud.",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        12,
        "Parandamine ei ole veel toetatud.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        15,
        "\x07  Vajuta U, et s�steemi uuendada.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        17,
        "\x07  Vajuta R, et kasutada taastuskonsooli.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        19,
        "\x07  Vajuta ESC, et minna tagasi pealehele.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        21,
        "\x07  Vajuta ENTER, et arvuti taask�ivitada.",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "ESC = Pealeht  U = Uuenda  R = Taastamine  ENTER = Taask�ivitus",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY etEEUpgradePageEntries[] =
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

static MUI_ENTRY etEEComputerPageEntries[] =
{
    {
        4,
        3,
        " ReactOS " KERNEL_VERSION_STR " paigaldus ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "Arvuti t��bi muutmine.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        10,
        "\x07  Liigu �les-alla, et valida sobiv arvuti t��p.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        11,
        "   Seej�rel vajuta ENTER.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        13,
        "\x07  Vajuta ESC, et minna tagasi eelmisele lehele",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        14,
        "   ilma arvuti t��pi muutmata.",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "ENTER = J�tka   ESC = Katkesta   F3 = V�lju",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY etEEFlushPageEntries[] =
{
    {
        4,
        3,
        " ReactOS " KERNEL_VERSION_STR " paigaldus ",
        TEXT_STYLE_UNDERLINE
    },
    {
        10,
        6,
        "S�steem kirjutab n��d andmed kettale",
        TEXT_STYLE_NORMAL
    },
    {
        10,
        8,
        "V�ib kuluda veidi aega",
        TEXT_STYLE_NORMAL
    },
    {
        10,
        9,
        "L�petamisel taask�ivitub arvuti automaatselt",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "Vahem�lu t�hjendamine",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY etEEQuitPageEntries[] =
{
    {
        4,
        3,
        " ReactOS " KERNEL_VERSION_STR " paigaldus ",
        TEXT_STYLE_UNDERLINE
    },
    {
        10,
        6,
        "ReactOS ei ole t�ielikult paigaldatud",
        TEXT_STYLE_NORMAL
    },
    {
        10,
        8,
        "Eemalda flopiketas ja CD-ROMid draividest.",
        TEXT_STYLE_NORMAL
    },
    {
        10,
        9,
        "",
        TEXT_STYLE_NORMAL
    },
    {
        10,
        11,
        "Vajuta ENTER, et arvuti taask�ivitada.",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "Palun oota...",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG,
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY etEEDisplayPageEntries[] =
{
    {
        4,
        3,
        " ReactOS " KERNEL_VERSION_STR " paigaldus ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "Ekraani t��bi muutmine.",
        TEXT_STYLE_NORMAL
    },
    {   8,
        10,
         "\x07  Liigu �les-alla, et ekraani t��pi muuta.",
         TEXT_STYLE_NORMAL
    },
    {
        8,
        11,
        "   Seej�rel vajuta ENTER.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        13,
        "\x07  Vajuta ESC, et minna tagasi eelmisele lehele",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        14,
        "   ilma ekraani t��pi muutmata.",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "ENTER = J�tka   ESC = Katkesta   F3 = V�lju",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY etEESuccessPageEntries[] =
{
    {
        4,
        3,
        " ReactOS " KERNEL_VERSION_STR " paigaldus ",
        TEXT_STYLE_UNDERLINE
    },
    {
        10,
        6,
        "ReactOS'i p�hilised komponendid on edukalt paigaldatud.",
        TEXT_STYLE_NORMAL
    },
    {
        10,
        8,
        "Eemalda flopiketas ja CD-ROMid draividest.",
        TEXT_STYLE_NORMAL
    },
    {
        10,
        9,
        "",
        TEXT_STYLE_NORMAL
    },
    {
        10,
        11,
        "Vajuta ENTER, et arvuti taask�ivitada.",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "ENTER = Taask�ivita arvuti",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY etEEBootPageEntries[] =
{
    {
        4,
        3,
        " ReactOS " KERNEL_VERSION_STR " paigaldus ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "Alglaadurit ei saanud kettale kirjutada.",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        9,
        "",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        13,
        "Sisesta vormindatud flopiketas draivi A:",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        14,
        "ja vajuta ENTER.",
        TEXT_STYLE_NORMAL,
    },
    {
        0,
        0,
        "ENTER = J�tka   F3 = V�lju",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }

};

static MUI_ENTRY etEESelectPartitionEntries[] =
{
    {
        4,
        3,
        " ReactOS " KERNEL_VERSION_STR " paigaldus ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "See nimekiri n�itab partitsioone ja vaba ruumi",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        9,
        "uute partitsioonide jaoks.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        11,
        "\x07  Liigu �les-alla, et valida kirje.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        13,
        "\x07  Vajuta ENTER, et paigaldada ReactOS valitud partitsioonile.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        15,
        "\x07  Vajuta P uue primaarse partitsiooni loomiseks.",
//        "\x07  Vajuta C, et teha uus partitsioon.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        17,
        "\x07  Vajuta E uue laiendatud partitsiooni loomiseks.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        19,
        "\x07  Vajuta L uue loogilise partitsiooni loomiiseks.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        21,
        "\x07  Vajuta D olemasoleva partitsiooni kustutamiseks.",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "Palun oota...",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY etEEConfirmDeleteSystemPartitionEntries[] =
{
    {
        4,
        3,
        " ReactOS " KERNEL_VERSION_STR " paigaldus ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "Olete valinud s�steemi partitsiooni kustutamise.",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        10,
        "S�steemi partitsioon v�ib sisaldada diagnostika programme, riistvara konfiguratsiooni",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        11,
        "programme, programme millega alustada ops�steeme (nagu ReactOS) v�i muid",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        12,
        "programme riistvara tootja poolt esitatud.",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        14,
        "Kustuta s�steemi partitsioon ainult siis kui olete kindel, et seal ei ole �htegi",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        15,
        "sellist programmi partitsioonil v�i kui olete kindel, et tahate neid kustutada.",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        16,
        "Kui kustutad partitsiooni, v�ib juhtuda, et Te ei saa k�ivitada",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        17,
        "arvutit k�vakettalt kuni l�petate ReactOS'i paigalduse.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        20,
        "\x07  Vajuta ENTER s�steemi partitsiooni kustutamiseks. Teilt k�sitakse",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        21,
        "   hiljem uuesti kinnitust partitsiooni kustutamiseks.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        24,
        "\x07  Vajuta ESC eelmise lehele tagasip��rdumiseks. Partitsiooni",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        25,
        "   ei kustutata.",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "ENTER=J�tka  ESC=Loobu",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY etEEFormatPartitionEntries[] =
{
    {
        4,
        3,
        " ReactOS " KERNEL_VERSION_STR " paigaldus ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "Partitsiooni vormindamine",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        10,
        "N��d vormindatakse partitsioon. Vajuta ENTER j�tkamiseks.",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "ENTER = J�tka   F3 = V�lju",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        TEXT_STYLE_NORMAL
    }
};

static MUI_ENTRY etEEInstallDirectoryEntries[] =
{
    {
        4,
        3,
        " ReactOS " KERNEL_VERSION_STR " paigaldus ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "ReactOS paigaldatakse valitud partitsioonile.",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        9,
        "Vali kaust, kuhu ReactOS paigaldada:",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        14,
        "Kausta muutmiseks kustuta kirje BACKSPACE klahviga ja",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        15,
        "tr�ki asemele kaust, kuhu ReactOS installeerida.",
        TEXT_STYLE_NORMAL
    },
    {
        6,
        16,
        "",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "ENTER = J�tka   F3 = V�lju",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY etEEFileCopyEntries[] =
{
    {
        4,
        3,
        " ReactOS " KERNEL_VERSION_STR " paigaldus ",
        TEXT_STYLE_UNDERLINE
    },
    {
        0,
        12,
        "Palun oota, kuni ReactOS paigaldatakse sihtkausta.",
        TEXT_STYLE_NORMAL | TEXT_ALIGN_CENTER
    },
    {
        0,
        13,
        "",
        TEXT_STYLE_NORMAL | TEXT_ALIGN_CENTER
    },
    {
        0,
        14,
        "V�ib kuluda mitu minutit.",
        TEXT_STYLE_NORMAL | TEXT_ALIGN_CENTER
    },
    {
        50,
        0,
        "\xB3 Palun oota...    ",
        TEXT_TYPE_STATUS
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY etEEBootLoaderEntries[] =
{
    {
        4,
        3,
        " ReactOS " KERNEL_VERSION_STR " paigaldus ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "Alglaaduri paigaldamine",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        12,
        "Paigalda alglaadur k�vakettale (MBR ja VBR).",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        13,
        "Paigalda alglaadur k�vakettale (ainult VBR).",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        14,
        "Paigalda alglaadur flopikettale.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        15,
        "�ra paigalda alglaadurit.",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "ENTER = J�tka   F3 = V�lju",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY etEEKeyboardSettingsEntries[] =
{
    {
        4,
        3,
        " ReactOS " KERNEL_VERSION_STR " paigaldus ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "Klaviatuuri t��bi muutmine.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        10,
        "\x07  Vajuta �les-alla, et valida klaviatuuri t��p.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        11,
        "   Seej�rel vajuta ENTER.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        13,
        "\x07  Vajuta ESC eelmisele lehele tagasi p��rdumiseks",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        14,
        "   klaviatuuri t��pi muutmata.",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "ENTER = J�tka   ESC = Katkesta   F3 = V�lju",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY etEELayoutSettingsEntries[] =
{
    {
        4,
        3,
        " ReactOS " KERNEL_VERSION_STR " paigaldus ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "Vali vaikimisi klaviatuuriasetus.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        10,
        "\x07  Liigu �les-alla, et valida klaviatuuriasetus.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        11,
        "    Seej�rel vajuta ENTER.",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        13,
        "\x07  Vajuta ESC eelmisele lehele tagasi p��rdumiseks",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        14,
        "   klaviatuuriasetust muutmata.",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "ENTER = J�tka   ESC = Katkesta   F3 = V�lju",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    },

};

static MUI_ENTRY etEEPrepareCopyEntries[] =
{
    {
        4,
        3,
        " ReactOS " KERNEL_VERSION_STR " paigaldus ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "Arvutit valmistatakse ette ReactOSi failide kopeerimiseks.",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "Failide nimekirja loomine...",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    },

};

static MUI_ENTRY etEESelectFSEntries[] =
{
    {
        4,
        3,
        " ReactOS " KERNEL_VERSION_STR " paigaldus ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        17,
        "Vali nimekirjast failis�steem.",
        0
    },
    {
        8,
        19,
        "\x07  Liigu �les-alla, et valida failis�steem.",
        0
    },
    {
        8,
        21,
        "\x07  Vajuta ENTER partitsiooni vormindamiseks.",
        0
    },
    {
        8,
        23,
        "\x07  Vajuta ESC muu partitsiooni valimiseks.",
        0
    },
    {
        0,
        0,
        "ENTER = J�tka   ESC = Katkesta   F3 = V�lju",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },

    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY etEEDeletePartitionEntries[] =
{
    {
        4,
        3,
        " ReactOS " KERNEL_VERSION_STR " paigaldus ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "Oled valinud partitsiooni kustutamise",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        18,
        "\x07  Vajuta D partitsiooni kustutamiseks.",
        TEXT_STYLE_NORMAL
    },
    {
        11,
        19,
        "HOIATUS: K�ik andmed partitsioonil kustutatakse!",
        TEXT_STYLE_NORMAL
    },
    {
        8,
        21,
        "\x07  Vajuta ESC katkestamiseks.",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "D = Kustuta partitsioon   ESC = Katkesta   F3 = V�lju",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY etEERegistryEntries[] =
{
    {
        4,
        3,
        " ReactOS " KERNEL_VERSION_STR " paigaldus ",
        TEXT_STYLE_UNDERLINE
    },
    {
        6,
        8,
        "Uuendatakse s�steemi seadistust.",
        TEXT_STYLE_NORMAL
    },
    {
        0,
        0,
        "Registri v�tmete loomine...",
        TEXT_TYPE_STATUS | TEXT_PADDING_BIG
    },
    {
        0,
        0,
        NULL,
        0
    },

};

MUI_ERROR etEEErrorEntries[] =
{
    {
        // NOT_AN_ERROR
        "�nnestus\n"
    },
    {
        // ERROR_NOT_INSTALLED
        "ReactOS ei ole t�ielikult paigaldatud.\n"
        "Kui paigaldamine praegu katkestada, siis tuleb\n"
        "ReactOS'i paigaldamiseks paigaldusprogramm uuesti k�ivitada.\n"
        "\n"
        "  \x07  Vajuta ENTER paigalduse j�tmaiseks.\n"
        "  \x07  Vajuta F3 paigalduse seiskamiseks.",
        "F3 = V�lju  ENTER = J�tka"
    },
    {
        // ERROR_NO_HDD
        "K�vaketast ei leitud.\n",
        "ENTER = Taask�ivita arvuti"
    },
    {
        // ERROR_NO_SOURCE_DRIVE
        "Paigaldusprogramm ei leidnud ketast, millelt see k�ivitati.\n",
        "ENTER = Taask�ivita arvuti"
    },
    {
        // ERROR_LOAD_TXTSETUPSIF
        "TXTSETUP.SIF faili ei �nnestunud laadida.\n",
        "ENTER = Taask�ivita arvuti"
    },
    {
        // ERROR_CORRUPT_TXTSETUPSIF
        "TXTSETUP.SIF on vigane.\n",
        "ENTER = Taask�ivita arvuti"
    },
    {
        // ERROR_SIGNATURE_TXTSETUPSIF,
        "TXTSETUP.SIF faili signatuur on vigane.\n",
        "ENTER = Taask�ivita arvuti"
    },
    {
        // ERROR_DRIVE_INFORMATION
        "S�steemiketta parameetreid ei �nnestunud lugeda.\n",
        "ENTER = Taask�ivita arvuti"
    },
    {
        // ERROR_WRITE_BOOT,
        "S�steemikettale ei �nnestunud kirjutada %S alglaadimiskoodi.",
        "ENTER = Taask�ivita arvuti"
    },
    {
        // ERROR_LOAD_COMPUTER,
        "Arvutit��pide nimekirja ei �nnestunud laadida.\n",
        "ENTER = Taask�ivita arvuti"
    },
    {
        //ERROR_LOAD_DISPLAY,
        "Ekraanide nimekirja ei �nnestunud laadida.\n",
        "ENTER = Taask�ivita arvuti"
    },
    {
        // ERROR_LOAD_KEYBOARD,
        "Klaviatuuri t��pide nimekirja ei �nnestunud laadida.\n",
         "ENTER = Taask�ivita arvuti"
    },
    {
        // ERROR_LOAD_KBLAYOUT,
        "Klaviatuuriasetuste nimekirja ei �nnestunud laadida.\n",
        "ENTER = Taask�ivita arvuti"
    },
    {
        // ERROR_WARN_PARTITION,
          "Leiti v�hemalt �ks k�vaketas, millel on �hildamatu partitsioonitabel,\n"
          "millega ei saanud korralikult �mber k�ia!\n"
          "\n"
          "Partitsioonide loomine v�i kustutamine v�ib vigastada partitsioonitabelit.\n"
          "\n"
          "  \x07  Vajuta F3 paigaldusest v�ljumiseks..\n"
          "  \x07  Vajuta ENTER j�tkamiseks.",
          "F3 = V�lju  ENTER = J�tka"
    },
    {
        // ERROR_NEW_PARTITION,
        "Uut partitsioonitabelit ei saa juba olemasoleva\n"
        "partitsiooni sisse tekitada!\n"
        "\n"
        "  * Vajuta mis tahes klahvi, et j�tkata.",
        NULL
    },
    {
        // ERROR_DELETE_SPACE,
        "Partitsioneerimata kettaruumi ei saa kustutada!\n"
        "\n"
        "  * Vajuta mis tahes klahvi, et j�tkata.",
        NULL
    },
    {
        // ERROR_INSTALL_BOOTCODE,
        "S�steemikettale ei �nnestunud paigaldada %S alglaadimiskoodi.",
        "ENTER = Taask�ivita arvuti"
    },
    {
        // ERROR_NO_FLOPPY,
        "Draivis A: ei ole flopiketast.",
        "ENTER = J�tka"
    },
    {
        // ERROR_UPDATE_KBSETTINGS,
        "Klaviatuuriasetuse seadistust ei �nnestunud uuendada.",
        "ENTER = Taask�ivita arvuti"
    },
    {
        //ERROR_UPDATE_DISPLAY_SETTINGS,
        "Ekraani seadistust registris ei �nnestunud uuendada.",
        "ENTER = Taask�ivita arvuti"
    },
    {
        // ERROR_IMPORT_HIVE,
        "Tarufaili ei �nnestunud importida.",
        "ENTER = Taask�ivita arvuti"
    },
    {
        // ERROR_FIND_REGISTRY
        "Registri andmete faile ei leitud.",
        "ENTER = Taask�ivita arvuti"
    },
    {
        // ERROR_CREATE_HIVE,
        "Registri tarusid ei �nnestunud luua.",
        "ENTER = Taask�ivita arvuti"
    },
    {
        // ERROR_INITIALIZE_REGISTRY,
        "Registrit ei �nnestunud luua.",
        "ENTER = Taask�ivita arvuti"
    },
    {
        // ERROR_INVALID_CABINET_INF,
        "Kapifailis ei olnud p�devaid inf faile.\n",
        "ENTER = Taask�ivita arvuti"
    },
    {
        // ERROR_CABINET_MISSING,
        "Kapifaili ei leitud.\n",
        "ENTER = Taask�ivita arvuti"
    },
    {
        // ERROR_CABINET_SCRIPT,
        "Kapifailis puudub paigaldusskript.\n",
        "ENTER = Taask�ivita arvuti"
    },
    {
        // ERROR_COPY_QUEUE,
        "Kopeeritavate failide nimekirja ei �nnestunud avada.\n",
        "ENTER = Taask�ivita arvuti"
    },
    {
        // ERROR_CREATE_DIR,
        "Paigalduskaustu ei �nnestunud luua.",
        "ENTER = Taask�ivita arvuti"
    },
    {
        // ERROR_TXTSETUP_SECTION,
        "TXTSETUP.SIF failist ei leitud '%S' sektsiooni.",
        "ENTER = Taask�ivita arvuti"
    },
    {
        // ERROR_CABINET_SECTION,
        "Kapifailist ei leitud '%S' sektsiooni.",
        "ENTER = Taask�ivita arvuti"
    },
    {
        // ERROR_CREATE_INSTALL_DIR
        "Paigalduskausta ei �nnestunud luua.",
        "ENTER = Taask�ivita arvuti"
    },
    {
        // ERROR_WRITE_PTABLE,
        "Partitsioonitabeleid ei �nnestunud kirjutada.\n"
        "ENTER = Taask�ivita arvuti"
    },
    {
        // ERROR_ADDING_CODEPAGE,
        "Kooditabelit ei �nnestunud registrisse lisada.\n"
        "ENTER = Taask�ivita arvuti"
    },
    {
        // ERROR_UPDATE_LOCALESETTINGS,
        "S�steemilokaati ei �nnestunud sedistada.\n"
        "ENTER = Taask�ivita arvuti"
    },
    {
        // ERROR_ADDING_KBLAYOUTS,
        "Klaviatuuriasetusi ei �nnestunud registrisse lisada.\n"
        "ENTER = Taask�ivita arvuti"
    },
    {
        // ERROR_UPDATE_GEOID,
        "Geograafilist asukohta ei �nnestunud seadistada.\n"
        "ENTER = Taask�ivita arvuti"
    },
    {
        //ERROR_DIRECTORY_NAME,
        "Sobimatu kausta nimi.\n"
        "\n"
        "  * Vajuta mis tahes klahvi, et j�tkata."
    },
    {
        //ERROR_INSUFFICIENT_PARTITION_SIZE,
        "Valitud partitsioon ei ole piisavalt suur ReactOS'i paigaldamiseks.\n"
        "Paigalduse partitsioon peab v�heamlt %lu MB suur olema.\n"
        "\n"
        "  * Vajuta mis tahes klahvi, et j�tkata.",
        NULL
    },
    {
        // ERROR_PARTITION_TABLE_FULL,
        "You can not create a new primary or extended partition in the\n"
        "partition table of this disk because the partition table is full.\n"
        "\n"
        "  * Vajuta mis tahes klahvi, et j�tkata."
    },
    {
        //ERROR_ONLY_ONE_EXTENDED,
        "Te ei saa luua rohkem kui �he laiendatud partitsiooni ketta kohta.\n"
        "\n"
        "  * Vajuta mis tahes klahvi, et j�tkata."
    },
    {
        //ERROR_FORMATTING_PARTITION,
        "Viisard ei saanud vormindada partitsiooni:\n"
        " %S\n"
        "\n"
        "ENTER = Taask�ivita arvuti"
    },
    {
        NULL,
        NULL
    }
};

MUI_PAGE etEEPages[] =
{
    {
        LANGUAGE_PAGE,
        etEELanguagePageEntries
    },
    {
        WELCOME_PAGE,
        etEEWelcomePageEntries
    },
    {
        INSTALL_INTRO_PAGE,
        etEEIntroPageEntries
    },
    {
        LICENSE_PAGE,
        etEELicensePageEntries
    },
    {
        DEVICE_SETTINGS_PAGE,
        etEEDevicePageEntries
    },
    {
        REPAIR_INTRO_PAGE,
        etEERepairPageEntries
    },
    {
        UPGRADE_REPAIR_PAGE,
        etEEUpgradePageEntries
    },
    {
        COMPUTER_SETTINGS_PAGE,
        etEEComputerPageEntries
    },
    {
        DISPLAY_SETTINGS_PAGE,
        etEEDisplayPageEntries
    },
    {
        FLUSH_PAGE,
        etEEFlushPageEntries
    },
    {
        SELECT_PARTITION_PAGE,
        etEESelectPartitionEntries
    },
    {
        CONFIRM_DELETE_SYSTEM_PARTITION_PAGE,
        etEEConfirmDeleteSystemPartitionEntries
    },
    {
        SELECT_FILE_SYSTEM_PAGE,
        etEESelectFSEntries
    },
    {
        FORMAT_PARTITION_PAGE,
        etEEFormatPartitionEntries
    },
    {
        DELETE_PARTITION_PAGE,
        etEEDeletePartitionEntries
    },
    {
        INSTALL_DIRECTORY_PAGE,
        etEEInstallDirectoryEntries
    },
    {
        PREPARE_COPY_PAGE,
        etEEPrepareCopyEntries
    },
    {
        FILE_COPY_PAGE,
        etEEFileCopyEntries
    },
    {
        KEYBOARD_SETTINGS_PAGE,
        etEEKeyboardSettingsEntries
    },
    {
        BOOT_LOADER_PAGE,
        etEEBootLoaderEntries
    },
    {
        LAYOUT_SETTINGS_PAGE,
        etEELayoutSettingsEntries
    },
    {
        QUIT_PAGE,
        etEEQuitPageEntries
    },
    {
        SUCCESS_PAGE,
        etEESuccessPageEntries
    },
    {
        BOOT_LOADER_FLOPPY_PAGE,
        etEEBootPageEntries
    },
    {
        REGISTRY_PAGE,
        etEERegistryEntries
    },
    {
        -1,
        NULL
    }
};

MUI_STRING etEEStrings[] =
{
    {STRING_PLEASEWAIT,
     "   Palun oota..."},
    {STRING_INSTALLCREATEPARTITION,
     "   ENTER = Paigalda   P = Loo primaarne   E = Loo laiendatud   F3 = V�lju"},
    {STRING_INSTALLCREATELOGICAL,
     "   ENTER = Paigalda   L = Loo loogiline partitsioon   F3 = V�lju"},
    {STRING_INSTALLDELETEPARTITION,
     "   ENTER = Paigalda  D = Kustuta partitsioon  F3 = V�lju"},
    {STRING_DELETEPARTITION,
     "   D = Kustuta partitsioon   F3 = V�lju"},
    {STRING_PARTITIONSIZE,
     "Uue partitsiooni suurus:"},
    {STRING_CHOOSENEWPARTITION,
     "You have chosen to create a primary partition on"},
//     "Oled valinud kettale uue partitsiooni loomise"},
    {STRING_CHOOSE_NEW_EXTENDED_PARTITION,
     "You have chosen to create an extended partition on"},
    {STRING_CHOOSE_NEW_LOGICAL_PARTITION,
     "You have chosen to create a logical partition on"},
    {STRING_HDDSIZE,
    "Sisesta uue partitsiooni suurus megabaitides."},
    {STRING_CREATEPARTITION,
     "   ENTER = Loo partitsioon   ESC = Katkesta   F3 = V�lju"},
    {STRING_PARTFORMAT,
    "J�rgmisena vormindatakse seda partitsiooni."},
    {STRING_NONFORMATTEDPART,
    "Oled valinud ReactOS'i paigaldamise uuele v�i vormindamata partitsioonile."},
    {STRING_NONFORMATTEDSYSTEMPART,
    "S�steemipartitsioon on veel vormindamata."},
    {STRING_NONFORMATTEDOTHERPART,
    "Uus partitsioon on veel vormindamata."},
    {STRING_INSTALLONPART,
    "ReactOS paigaldatakse partitsioonile"},
    {STRING_CHECKINGPART,
    "Valitud partitsiooni kontrollitakse."},
    {STRING_CONTINUE,
    "ENTER = J�tka"},
    {STRING_QUITCONTINUE,
    "F3 = V�lju  ENTER = J�tka"},
    {STRING_REBOOTCOMPUTER,
    "ENTER = Taask�ivita arvuti"},
    {STRING_DELETING,
     "   Faili kustutamine: %S"},
    {STRING_MOVING,
     "   Faili liigutamine: %S asukohta %S"},
    {STRING_RENAMING,
     "   Faili �mbernimetamine: %S %S-ks"},
    {STRING_COPYING,
     "   Faili kopeerimine: %S"},
    {STRING_SETUPCOPYINGFILES,
     "Failide kopeerimine..."},
    {STRING_REGHIVEUPDATE,
    "   Registritarude uuendamine..."},
    {STRING_IMPORTFILE,
    "   %S importimine..."},
    {STRING_DISPLAYSETTINGSUPDATE,
    "   Monitori seadistuse uuendamine registris..."},
    {STRING_LOCALESETTINGSUPDATE,
    "   Lokaadi seadistuse uuendamine..."},
    {STRING_KEYBOARDSETTINGSUPDATE,
    "   Klaviatuuriasetuse seadistuse uuendamine..."},
    {STRING_CODEPAGEINFOUPDATE,
    "   Kooditabeli info lisamine registrisse..."},
    {STRING_DONE,
    "   Valmis..."},
    {STRING_REBOOTCOMPUTER2,
    "   ENTER = Taask�ivita arvuti"},
    {STRING_REBOOTPROGRESSBAR,
    " Teie arvuti taask�ivitub %li sekundi p�rast... "},
    {STRING_CONSOLEFAIL1,
    "Konsooli ei �nnestunud avada\r\n\r\n"},
    {STRING_CONSOLEFAIL2,
    "T�en�oliselt on probleem USB klaviatuuri kasutamises\r\n"},
    {STRING_CONSOLEFAIL3,
    "USB klaviatuurid ei ole veel toetatud\r\n"},
    {STRING_FORMATTINGDISK,
    "K�vaketta vormindamine"},
    {STRING_CHECKINGDISK,
    "K�vaketta kontrollimine"},
    {STRING_FORMATDISK1,
    " Vorminda partitsioon %S failis�steemiga (kiire vormindus) "},
    {STRING_FORMATDISK2,
    " Vorminda partitsioon %S failis�steemiga "},
    {STRING_KEEPFORMAT,
    " �ra muuda praegust failis�steemi "},
    {STRING_HDINFOPARTCREATE_1,
    "%I64u %s  K�vaketas %lu  (Port=%hu, Siin=%hu, Id=%hu) - %wZ [%s]."},
    {STRING_HDINFOPARTCREATE_2,
    "%I64u %s  K�vaketas %lu  (Port=%hu, Siin=%hu, Id=%hu) [%s]."},
    {STRING_HDDINFOUNK2,
    "   %c%c  Type 0x%02X    %I64u %s"},
    {STRING_HDINFOPARTDELETE_1,
    "%I64u %s  K�vaketas %lu  (Port=%hu, Siin=%hu, Id=%hu) - %wZ [%s]."},
    {STRING_HDINFOPARTDELETE_2,
    "%I64u %s  K�vaketas %lu  (Port=%hu, Siin=%hu, Id=%hu) [%s]."},
    {STRING_HDINFOPARTZEROED_1,
    "K�vaketas %lu (%I64u %s), Port=%hu, Siin=%hu, Id=%hu (%wZ) [%s]."},
    {STRING_HDDINFOUNK4,
    "%c%c  Type 0x%02X    %I64u %s"},
    {STRING_HDINFOPARTEXISTS_1,
    "K�vaketas %lu (%I64u %s), Port=%hu, Siin=%hu, Id=%hu (%wZ) [%s]."},
    {STRING_HDDINFOUNK5,
    "%c%c %c %sT��p %-3u%s                      %6lu %s"},
    {STRING_HDINFOPARTSELECT_1,
    "%6lu %s  K�vaketas %lu  (Port=%hu, Siin=%hu, Id=%hu) - %wZ [%s]"},
    {STRING_HDINFOPARTSELECT_2,
    "%6lu %s  K�vaketas %lu  (Port=%hu, Siin=%hu, Id=%hu) [%s]"},
    {STRING_NEWPARTITION,
    "Loodi uus partitsioon"},
    {STRING_UNPSPACE,
    "    %sKasutamata kettaruum%s              %6lu %s"},
    {STRING_MAXSIZE,
    "MB (maks. %lu MB)"},
    {STRING_EXTENDED_PARTITION,
    "Laiendatud partitsioon"},
    {STRING_UNFORMATTED,
    "Uus (Vormindamata)"},
    {STRING_FORMATUNUSED,
    "Kasutamata"},
    {STRING_FORMATUNKNOWN,
    "Tundmatu"},
    {STRING_KB,
    "KB"},
    {STRING_MB,
    "MB"},
    {STRING_GB,
    "GB"},
    {STRING_ADDKBLAYOUTS,
    "Klaviatuuriasetuste lisamine"},
    {0, 0}
};

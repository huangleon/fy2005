inherit ROOM;
void create()
{
        set("short", "╥Гтфяцце");
        set("long", @LONG
уБюОйгЁ╞м╒кЫиХё╛╥ГтфЁгюО╣д╬ю╥в╤╪©ирттзуБюОиов╢гКгС╢╕юМ║ё╢СлЭдойвр╩уе╬М
Иэд╬╟╦ё╛╟╦иосп╦Жп║жЯм╟ё╛юОцФ╡Еве╪╦╦Ыспж╙╦╝╧ыс║╣джЯг╘║ёд╬╟╦╨С╣дл╚й╕рниофлве
я╘хчф╓ё╛рн╨Сфа╥Гио╨ЛхугЮтфм╪║ёиопЭ╫П╠ъьрё╨
[31m
				цВ╡ЛгО╨а
[37m
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"wcloud2",
  "east" : __DIR__"shufang",
]));

        set("coor/x",-21);
        set("coor/y",-10);
        set("coor/z",-300);
        setup();
        replace_program(ROOM);
}

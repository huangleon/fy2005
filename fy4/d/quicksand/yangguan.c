inherit ROOM;

void create()
{
        set("short", "сЯце╧ь");
        set("long", @LONG
ууве╣юио╣д╩фиЁё╛╢С╣ь╪Д╥б╥ПряЁиакр╩ф╛фЮцт╣д╟╣╩фи╚ё╛р╡╡╩ж╙╢сддюО╢╚ю╢ак
р╩уС╡та╧╣д╦ХиЫё╛║╟р╩ЁЖсЯце╧ьё╛а╫яшюА╡╩╦и║╠ё╛╣юетр╩©И╥Г╩╞ак╣дй╞╠╝иорЧт╪©и
рт©╢ЁЖ║╨сЯце╧ь║╩хЩ╦Ж╧ев╜╢Свжё╛впо╦©╢х╔ё╛обцФ╩╧©лве╪╦╦Ж╡пфф╣д╪Щм╥║ё
[33m╠╠--║╣б╔ю╪╧е╪ёё╛нВ--║╣╡ь╠╠иЁд╝ё╛до--║╣блжч[32m
LONG
        );

        set("exits", ([ 
		"southeast" : __DIR__"mirage",
		"northwest" : 	AREA_LOULAN"kongquehe",
		"west" : 	AREA_ZANGBEI"yangguan",
	]));
        
        set("outdoors", "quicksand");
	set("coor/x",-950);
	set("coor/y",110);
	set("coor/z",0);
	setup();
}


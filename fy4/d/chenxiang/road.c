
inherit ROOM;

void create()
{
        set("short", "»ÄÒ°");
        set("long", @LONG
ÕâÊÇÒ»¸öÎŞ±ßµÄ»ÄÒ°µØ£¬É½ÊÆµ½ÁËÕâÀïÍ»È»¼ä±äµÄµşµşÆğÆğ£¬Á¬Ãà²»¶ÏÔÙÍù±±
ĞĞÔòÊÇÈ¥´óÉ³Ä®µÄ»ÄÁ¹Ğ¡Â·£¬ÍùÎ÷±±·½ÏòÔ¶Ô¶Ì÷ÍûÔòÊÇÎåÔÀÖ®Ò»µÄ[33m»ªÉ½[32m½çÄÚ£¬¶¸ÇÍ
µÄÉ½ÂÍÖ±²åÔÆÏö£¬Î¡¶ë×³Àö¡£¼ÌĞøÏò±±±ãÊÇÎŞ±ßÎŞ¼ÊµÄ´ó[33mÉ³Ä®[32m¡£
LONG
        );
    set("exits", ([ 
        "north" : __DIR__"roadp",
		"southup" : __DIR__"chenxiang3",
        "northwest" : AREA_HUASHAN"road1",
	]));
        set("outdoors", "chenxiang");

	set("coor/x",-10);
	set("coor/y",70);
	set("coor/z",-10);
	setup();
        replace_program(ROOM);
}


// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "±®ÁÖ");
        set("long", @LONG
Õâ±®ÁÖ×îÎ÷£¬×îÎª³öÃûµÄµ±Êô¡°[33m´óÌÆÌìºóÓùÖÆÊ«Êé±®[32m¡±£¬ÎäÔòÌì×«ÎÄ£¬ÍõÖª¾´
ÊÖÊé£¬±®ÉíËÄÁúÅÌ¶¥£¬ÔìĞÍ±ğÖÂ£¬±®ÎÄÕıÊé£¬±ÊÁ¦åÙ¾¢£¬¹ÅÀ´ÎÄÎäÏàÍ¨£¬µ½´ËµÄÎä
Ñ§Ãû¼ÒÒà³¢ÔŞ²»¾ø¿Ú¡£
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"bei2",
]));
        set("objects", ([
                BOOKS"skill/puti-steps_50" : 1,
		__DIR__"npc/pupil" :2,
       ]) );
        set("outdoors", "shaolin");
	set("coor/x",-20);
	set("coor/y",-80);
	set("coor/z",-10);
	setup();
        replace_program(ROOM);
}

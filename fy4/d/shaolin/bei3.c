// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "±®ÁÖ");
        set("long", @LONG
Ò»ĞĞ±®¶àÎªÀú´úÊé·¨Ãû¼ÒËùÊé£¬¼ÇÔØÉÙÁÖÇ§Äê²×É££¬ÆäÖĞÒÔÃ×ÜÀµÄ¡°[33mµÚÒ»É½[32m¡±
Îª×î£¬µ±ÊôÏ¡ÊÀÖ®±¦¡£ÆäÓà¡°[33mÈıÊ®Áù·å¸³[32m¡±µÈÒ²¿Ú±®²»¾ø£¬ÊÇÉÙÁÖËÄĞĞ±®ÖĞ×î¾ß¹Û
ÉÍ¼ÛÖµµÄÒ»ĞĞ¡£ÔÙÍù¶«±ãÊÇ±®ÁÖµÄ×îºóÒ»ĞĞ¡£
LONG
        );
        set("exits", ([ 
  		"east" : __DIR__"bei4",
  		"southwest" : __DIR__"yingbi",
	]));
        set("objects", ([
                BOOKS"skill/zen_50" : 1,
                BOOKS"skill/buddhism_50" : 1,
       ]) );
        set("outdoors", "shaolin");
	set("coor/x",10);
	set("coor/y",-80);
	set("coor/z",-10);
	setup();
        replace_program(ROOM);
}

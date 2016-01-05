// TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "ÎŞÎªÂ¥");
        set("long", @LONG
Ò»¼äºìÄ¾Ğ¡Â¥£¬ÃÅÇ°ØÒ¶îÉÏ¡°ÎŞÎª¡±Á½×ÖÓë±±ÃæµÄÇå¾²Â¥Ò£ÏàºôÓ¦£¬Â¥ÄÚÖ»ÓĞ
Ò»ÕÅ²è¼¸£¬Ò»Ö»Ğ¡»ğÂ¯£¬ÏëÀ´Ö÷ÈË±ØÊÇ²èµÀ¸ßÊÖ£¬¶«Ç½ÉÏĞü±¦½£Ò»°Ñ£¬½£ÇÊ¹ÅÉ«¹Å
Ïã£¬Ò»¿´±ãÖª¾ø·Ç·²Æ·£¬Î÷Ç½ÉÏÒ»Ìõºá·ù£º

			[37m¼«ÀÖÊÀ½ç[32m

LONG
        );
        set("exits", ([ 
  			"north" : __DIR__"diyuan",
		]));
        set("objects", ([
                __DIR__"npc/girlfy": 1,
       ]) );
		set("coor/x",-20);
		set("coor/y",110);
		set("coor/z",20);
		setup();
        replace_program(ROOM);
}

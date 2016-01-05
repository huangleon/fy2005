
inherit ROOM;

void create()
{
    set("short", "É½ÃÅ");
    set("long", @LONG
É½ÂÍÒÔ½ü£¬ÑÛÇ°Ò»µÀÊ¯ÃÅËÊÁ¢£¬Ê¯ÃÅÉÏÊé[33m¡º»ªÉ½¡»[32mÁ½¸öÁ¥Êé´ó×Ö£¬Ê¯ÃÅºóÉ½·åĞã
ÀöÍ¦°Î£¬ÑöÍ·¿´ÖØÂÍµşáÖ¸ßËÊÈëÔÆ£¬Ò»ÌõÇàÊ¯Ğ¡Â·´©¹ıÉ½Ê¯ÃÅÏòÄÏÑÓÉìÈ¥¡£Ğ¡Â·ÅÔ
ÊÇÓÃÍë¿ÚµÄÃ«Öñ´îÆğ¸öÁ¹Åï£¬ËÄÃæÒ»Æ¬Çà´ä£¬Á¹·çÕóÕóËÍË¬£¬ÔÚ¿áÈÈµÄÌìÆøÀï£¬¸Ï
Â·¸ÏÀÛÁËÄÜ¹»ÕÒÒ»ÕâÃ´ÑùÒ»¸öµØ·½Ğª½Å£¬ÊµÔÚºÜ²»´í¡£
LONG
        );
    set("exits", ([ 
  		"north" : __DIR__"road4",
  		"south" : __DIR__"xiaojing",
	]));
	set("objects", ([
		__DIR__"npc/fatman" : 1,
		__DIR__"npc/xiaobao" : 1,
	]));
    set("outdoors", "huashan");

	set("coor/x",5);
	set("coor/y",20);
	set("coor/z",-40);
	setup();
        replace_program(ROOM);
}



inherit ROOM;

void create()
{
        set("short", "ÔÆº£¹ÂÖÛ");
        set("long", @LONG
ÔÆ£¬·­ÌÚÔÚ½ÅÏÂ£¬ÏóÅÄ°¶µÄ²¨ÀË£¬ÓÖÏóäıäıµÄÁ÷Ë®£¬´ËÆğ±Ë·ü£¬ÎŞ±ßÎŞ¼Ê¡£Äã
¾ÍÏó³Ë×ÅÒ»Ìõ¹ÂÖÛÔÚÔÆº£ÖĞÆ¯µ´£¬²»ÖªµÀÊÇË®ÔÚÁ÷£¬»¹ÊÇ´¬ÔÚ×ß¡£¶«±±±ß£¬ÄÇÈÕ³ö
Ö®µß£¬¾ÍÊÇ´«ËµÖĞµÄÉñÃØµÄ[33m¡ºµÛÍõ¹È¡»[32m¡£ÄÏÃæÁíÓĞÒ»ÌõĞ¡Â·,ÍäÍäÇúÇúµØÍ¨ÏòÔ¶·½¡£
LONG
        );
        set("exits", ([ 
		   "northeast" : AREA_PALACE"entrance",
		   "southdown" : __DIR__"troad0a",
		   "westdown"  : __DIR__"palace_path4",
	]));
        set("outdoors", "palace");

	set("coor/x",260);
	set("coor/y",0);
	set("coor/z",40);
	setup();
        replace_program(ROOM);
}


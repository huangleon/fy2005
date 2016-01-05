
inherit ROOM;

void create()
{
        set("short", "ÂÌÖŞ");
        set("long", @LONG
½ÅÏÂµÄÁ÷É³Í»È»²»¼û£¬Á¹Ë¬µÄÎ¢·ç·÷Ãæ¶øÀ´£¬Ò»¸öĞ¡Ğ¡µÄºş²´³ÊÏÖÔÚÄãµÄÑÛÇ°¡£
Ë®ËäÈ»Ö»ÓĞ¶şÖ¸ºñ£¬È´ºÜÇå³º£¬ºş±ßÂÌÊ÷³ÉÒñÂÌ²İ·Ò·¼¡£ËäÈ»ÔÚ¿áÈÈµÄÉ³Ä®ÖĞ£¬ºş
Ë®ÈÔÊÇÄÇÃ´µÄÇåÁ¹¡£´ÓÕâ¶ùÒ»Ö±ÏòÎ÷£¬¾Í¿ÉÒÔ×ßµ½¹ØÍâµÄ[33m´óÕÑËÂ[32m£¬Ïò±±Ô½¹ıÉ³Áë±ã
ÊÇÖøÃûµÄ[33mÓñÃÅ¹Ø[32m£¬Ò²¾ÍÊÇÍ¨Ïò[33m²Ø±±Ö®µØ[32mµÄ±Ø¾­Ö®Â·¡£
LONG
        );
        set("exits", ([ 
  		"west" : __DIR__"desert9",
  		"north" : __DIR__"sandlin",
  		"east" : __DIR__"desert7",
	]));
	set("objects", ([
		__DIR__"npc/thinlama" : 1,
	]));
	set("resource/water",1);
        set("liquid", (["container": "ºş"]));
        set("outdoors", "quicksand");

	set("coor/x",-1085);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
}

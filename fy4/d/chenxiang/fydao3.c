inherit ROOM;

void create()
{
	set("short", "·çÔÆµÀ");

	set("long", @LONG
¡°Ò»Èë·çÔÆËêÔÂ´ß¡±£¬Õâ¶ùÊÇÁ¬½Ó[33m³ÁÏãÕò[32mºÍ[33mÄÏº£[32mµÄ·çÔÆµÀ£¬°µºÖÉ«µÄµÀÂ·£¬´Ó
ÕâÀï¿ªÊ¼ÍñÑÑÉìÕ¹£¬´©¹ı´äÂÌµÄÊ÷ÁÖ£¬ÑØ×ÅÕ¿À¶µÄºşË®£¬Ò»Í·ÉìÕ¹ÏòÄÖÊĞ£¬Ò»Í·ÈÆ
¹ıºÚÆáÆáµÄÉ­ÁÖÍ¨ÏòÔ¶·½¡£Ô¶É½ÔÚÒõî¨µÄÌìÉ«ÖĞ¿´À´£¬·Â·ğÔÚÎíÖĞ£¬¸ü¼ÓÃÀÀöÉñÃØ¡£
LONG);

	set("type","road");
	set("exits",([
        "northwest":__DIR__"fydao2",
        "east":		AREA_MANGLIN"plainroad",
		]) );
        set("outdoors", "chenxiang");
	set("coor/x",280);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}

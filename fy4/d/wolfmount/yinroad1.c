inherit ROOM;
void create ()
{
        set ("short", "Òõ°µÐ¡Â·");
        set ("long", @LONG
³ÁÏã³ÇÎ÷ÄÏÒ»ÌõÒõ°µ³±ÊªµÄÐ¡Â·£¬ÖÜÎ§É¢Âä×Å²ÐÔ«¶Ï±Ú£¬Â·±ßÔÓ²Ý´ÔÉú¡£¹Ù¸®
ºÜÉÙ¹ÜÕâÀï£¬ËùÒÔÖÎ°²²¢²»Ê®·ÖºÃ¡£µ½´¦ÊÇ³ÁÃÆµÄ»ÒÉ«£¬²»¼ûÒ»Ë¿Éú»ú¡£Â·±ßÁ¢×Å
Ò»¸öÆÆÄ¾ÅÆ×ÓÉÏÁÊ²ÝµÄÐ´×Å¹Ù¸®¸æÊ¾£º¡º½üÈÕ[33mÎ÷É½[32mÈºÀÇºáÐÐ£¬Õ¼É½ÎªÍõ£¬´ò½Ù¹ýÍù
¿ÍÉÌ£¬¹Ù¸®ÎÞÁ¦¹Ë¼°£¬ÐÐÂÃ°²È«²»µÃ±£ÕÏ£¬¹ÃÖÒ¸æÔÝÍ£Î÷ÐÐ¡£Èô²»ÌýÈ°¸æ£¬Ë½×ÔÉí
ÉæÏÕ¾³£¬ºó¹û×Ô¸º¡£¡»
LONG);
        set("exits", ([ //sizeof() == 4
                "east" : AREA_CHENXIANG"mw",
		"west" : __DIR__"yinroad2",
        ]));
        set("outdoors", "wolfmount");
        set("item_desc", ([
	        "paizi": @TEXT
½üÈÕÎ÷É½ÈºÀÇºáÐÐ£¬Õ¼É½ÎªÍõ£¬×¨ÃÅ´ò½Ù¹ýÍù¿ÍÉÌ£¬¹Ù¸®ÎÞÁ¦¹Ë¼°£¬
¼øÓÚ´ó¼ÒÖ®°²È«ÎÊÌâÈÕÒæÑÏÖØ£¬¹Ù¸®½¨ÒéÔÝÊ±²»ÒªÎ÷ÐÐ¡£ÈçÓÐ²»ÌýÈ°
¸æ£¬Ë½×ÔÉíÉæÏÕ¾³£¬Ò»ÇÐºó¹û×Ô¸º¡£
TEXT
	]) );
        set("type", "road");
	set("coor/x",80);
	set("coor/y",180);
	set("coor/z",-60);
        setup();
	replace_program(ROOM);
}

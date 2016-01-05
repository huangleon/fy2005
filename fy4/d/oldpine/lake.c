// Room: /d/oldpine/lake.c

inherit ROOM;

void create()
{
        set("short", "Ë®Ì¶");
        set("long", @LONG
ÄãÏÖÔÚÕıÕ¾ÔÚÒ»¸öÉî²»¼ûµ×µÄË®Ì¶±ßÉÏ£¬´ÓÌ¶µ×²»Ê±ÓĞÆøÅİÃ°ÉÏÀ´£¬É¢·¢ÖøÒ»
¹É¹îÒìµÄÏãÎ¶£¬Ë®Ì¶±ß³¤ÂúÁË[37m»ÆÉ«Ò¶×Ó[32mµÄ¹Ö²İ£¬ËÄÖÜ¶¸ÇÍµÄÉ½±Ú½üºõÖ±Á¢£¬Ì§Í·Ö»
¼ûÒ»¸ö°ëÔ²ĞÎµÄÌì¿Õ£¬Î¨Ò»µÄ³öÂ·´ó¸ÅÖ»ÓĞÍù±±É½ÈªÁ÷ÈëË®Ì¶µÄÈ±¿Ú¡£
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  			"north" : __DIR__"riverbank1",
		]));
		
        set("item_desc", ([
        	"»ÆÉ«Ò¶×Ó": 	"Ë®Ì¶±ß³¤ÂúÁË»ÆÉ«µÄÒ¶×Ó£¬¹ÊÃû»ÆÒ¶Ì¶¡£\n",
        ]));
               
        set("objects", ([ /* sizeof() == 1 */
  			__DIR__"npc/serpent" : 1,
		]));
        set("resource/water", 1);
        set("liquid/name", "»ÆÒ¶Ì¶Ë®");
		set("coor/x",0);
		set("coor/y",-10);
		set("coor/z",0);
		setup();
        replace_program(ROOM);
}

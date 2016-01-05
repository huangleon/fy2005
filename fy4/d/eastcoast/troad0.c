
inherit ROOM;

void create()
{
        set("short", "É½¹È¿Ú");
        set("long", @LONG
Â·±ßÁ¢×ÅÒ»¿éÊ¯±®£¬ÉÏÃæĞ´×ÅÈı¸ö¹Å×­×Ö£º[33m¡º´óÆì¹È¡»[32m¡£Íù¹ÈÖĞ¿´È¥£¬Ò»ÌõÍä
ÍäÇúÇúµÄĞ¡Â·ÉìÏòÉî´¦£¬ÔÚÒ»Î£ÑÂÇ°Í»È»ÖĞ¶Ï¡£
LONG
        );
        set("exits", ([ 
 		 "west" : __DIR__"troad0a",
  		"eastdown" : __DIR__"troad1",
]));
	set("outdoors","tieflag"); 	
        
	set("coor/x",400);
	set("coor/y",-10);
	set("coor/z",10);
	setup();
}

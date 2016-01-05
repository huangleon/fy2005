
inherit ROOM;

void create()
{
        set("short", "»ÄÒ°");
        set("long", @LONG
ÕâÊÇÒ»¸öÎŞ±ßµÄÉ³ÀùµØ£¬É½ÊÆµ½ÁËÕâÀïÍ»È»¼ä±äµÄÎŞÓ°ÎŞ×Ù¡£µØÆø¼«¸ÉÔï£¬Á¬
·ç¶¼ÊÇÅ¯µÄ¡£µØÉÏµÄÊ¯Àù·¢³öÒ»ÖÖ°µºìµÄÑÕÉ«£¬¾ÍÏóÊÇ±»ÏÊÑªÈ¾ºìµÄÒ»Ñù¡£Ò»Ìõ²¼
Âú³µºÛµÄ¹ÙµÀÏòÎ÷·½ºÍ¶«·½ÉìÕ¹¡£Ò»¿éÅÆ×ÓÖ¸ÏòÂ·²àµÄĞ¡µê£¬ÉÏÃæĞ´×Å[33m¡º½¹¶¼æä¡»[32m
LONG
        );
        set("exits", ([ 
	  "east" : __DIR__"huangyie4",
	  "west" : __DIR__"sandroad",
	  "south" : AREA_DEATH"ghostinn",
	  "southeast" : __DIR__"huangyie3",
	  "northeast" : __DIR__"huangyie2",
	]));
        set("outdoors", "quicksand");
        set("objects", ([
                __DIR__"npc/trader" : 3,
        ]) );

	set("coor/x",-1010);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

int valid_leave(object me, string dir)
{
	object room;
	if(me->is_ghost()){
		room = load_object(AREA_DEATH"ghostinn");
		me->move(room);
		return notify_fail("Äã¸Ğµ½Ò»ÕóÔÎÑ££¬ËÆºõ¿´µ½ºÜ¶àÈËÓ°´ÓÑÛÇ°»Î¹ı¡£\n");
	}
	return 1;

}

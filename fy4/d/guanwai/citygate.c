inherit ROOM;

void create()
{
        set("short", "³ÇÃÅ");
        set("long", @LONG
Ê¯ÆöµÄ³ÇÔ«ºá²¼ÔÚ²¼´ïÀ­¹¬ºÍÇ¡¿Ë²·ÀïÉ½Ö®¼ä£¬³ÇÀï±ãÊÇÖøÃûµÄ[33m´óÕÑËÂ[32mºÍ°Ë½Ç
½Ö£¬³ÇÍâµÄĞ¡Â·Ïò±±Í¨Ïò¸ßËÊµÄ[33mÉ½ÂÍ[32m£¬ÏòÄÏÁ¬×ÅÓôÓô´Ğ´ĞµÄ[33mÃÜÁÖ[32m¡£³ÇÃÅÔÚÒ»×ùÉáÀû
ËşÏÂ£¬ËşÀï²Ø×ÅÀú´ú¸ßÉ®µÄ·ğ¹ÇºÍÎŞÊıÉñÃØÃÀÀöµÄ´«ËµÓëÉñ»°¡£
LONG
        );

        set("exits", ([ 
		"west" : __DIR__"octostreet",
		"east" : __DIR__"grassland4",
		"up"   : __DIR__"topoftower",
	        "northup": "/d/resort/smallroad",
	        "south" : "/d/ghost/lroad1",
	]));
        set("outdoors", "guanwai");
        set("objects", ([
                __DIR__"npc/cityguard" : 2,
        ]) );

	set("coor/x",45);
	set("coor/y",0);
	set("coor/z",0);
	setup();
}

int valid_leave(object me, string dir) {
	object ob;
	ob = present("city guard",this_object());
	
	if (ob)
	if ( dir == "west" && me->is_naked())   {
			if (me->query("age")<=11)
				 tell_object(me,ob->name()+"Öå×ÅÃ¼Í·Ëµ£ºĞ¡º¢×Ó¹â×ÅÆ¨¹ÉÅÜÀ´ÅÜÈ¥£¬ÏñÊ²Ã´Ñù×Ó£¡\n\n");
			else
				return notify_fail(ob->name()+"ÏòÄãºÈµÀ£º³àÉíÂãÌåÕĞÒ¡¹ıÊĞ£¬³ÉºÎÌåÍ³£¡£¡\n");
		}

	return 1;
}
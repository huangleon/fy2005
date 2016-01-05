// annie 07.2003
// dancing_faery@hotmail.com

inherit ROOM;
#include <ansi.h>

void 	setup_room_desc(object room,int length, int width, int x, int y) {
	
	int exit_number;
	
	exit_number= sizeof(room->query("exits"));

	switch (random(6))
	{
	case 0:
		room->set("short",CYN"¾ªºèÌ¤Ñ©"NOR);
		room->set("long",@LONG

[1;36m   ¡¡¡¡¡¡¡¡¡¡       Ì¤¡¡¡¡¡¡Ñ© ¡£  ¡£  ¡£ 

[1;37m¡¡¡¡¡¡°Ë»ÄÎ¨ÓñÐ¼£¬ÍòÀïºÎ±ù½à¡£×ã¾ë¸¡ºÛÇ³£¬¶ÏÇÅÇåÀá¾ø¡£
[2;37;0m
LONG
	);
		break;
	case 1:
		room->set("short",CYN"ËûÏçÁ÷Èª"NOR);
		room->set("long",@LONG

[1;32m   ¡¡¡¡¡¡¡¡¡¡       Ìý¡¡¡¡¡¡Èª ¡£  ¡£  ¡£ 

[1;36m¡¡¡¡¡¡¬b¬bË­ßµÏÒ£¬¾²Ò¹Ëß²øÃà¡£ãùãùË¼ÏçÀá£¬ä¸ä¸²»¾¡Èª¡£
[2;37;0m
LONG
	);
		break;
	case 2:
		room->set("short",CYN"³ßËØÃ÷Öé"NOR);
		room->set("long",@LONG

[1;37m   ¡¡¡¡¡¡¡¡¡¡       ¶Á¡¡¡¡¡¡Ê« ¡£  ¡£  ¡£ 

[1;32m¡¡¡¡¡¡ÇàÔÆÂä³àÜ¯£¬×ÏÑà»½ÏàË¼¡£´²Í·Ô§ÑìÕí£¬Õí±ßÎÞ×ÖÊ«¡£
[2;37;0m
LONG
	);
		break;
	case 3:
		room->set("short",CYN"ÏÉÈËÂä×Ó"NOR);
		room->set("long",@LONG

[1;33m   ¡¡¡¡¡¡¡¡¡¡       ÇÃ¡¡¡¡¡¡Æå ¡£  ¡£  ¡£ 

[1;31m¡¡¡¡¡¡·½Ô²´¦´¦î¿£¬ºÚ°××ÜÏà³Ö¡£Âä×ÓÎÅÓàÔÏ£¬Æñ¹Ø°ëÄ¿Æå¡£
[2;37;0m
LONG
	);
		break;
	case 4:
		room->set("short",CYN"¼ÑÆÚÈçÃÎ"NOR);
		room->set("long",@LONG

[1;34m   ¡¡¡¡¡¡¡¡¡¡       Äé¡¡¡¡¡¡»¨ ¡£  ¡£  ¡£ 

[1;33m¡¡¡¡¡¡´åÐæãåÍíÏ¼£¬ÁÖÛÖËÞÇàÑ»¡£Ç³×í¾õ¸èÔ¶£¬ËØÊÖÇÄÄé»¨¡£
[2;37;0m
LONG
	);
		break;
	case 5:
		room->set("short",CYN"Éî¹¬ººÇú"NOR);
		room->set("long",@LONG

[1;31m   ¡¡¡¡¡¡¡¡¡¡       ¹Ë¡¡¡¡¡¡Çú ¡£  ¡£  ¡£ 

[1;34m¡¡¡¡¡¡¾ÕÑÞ³ÈÐÂÂÌ£¬·çÇá³ØË®äË¡£Î÷´°ºìÀáÖò£¬ÓñÖ¸Ñô¹ØÇú¡£
[2;37;0m
LONG
	);
		break;
	}
	
}



void 	setup_npc_obj(object room,int length, int width, int x, int y)
{
		object icecave;
		int boss_x,boss_y;
		icecave = load_object(__DIR__"enterance");
		icecave->generate_maze1();
		boss_x = icecave->query("maze1/boss_x");
		boss_y = icecave->query("maze1/boss_y");


		room->set("objects",([				
			__DIR__"mazenpc/maze"+(random(2)+2)+"_guard"+(random(8)+1):1,
		]));		

	if (x == boss_x && y == boss_y)
		room->set("objects",([				
			__DIR__"npc/jat":1,
		]));		


		set("x",x);
		set("y",y);
		room->set("exits/up",__DIR__"enterance");
		room->set("perma_exist",1);
		set("perma_exist",1);

		room->setup();
}

/*

¡¡¡¡¡¡¡¡¡¡¡¡¡¡¨X¨Y
¡¡¡¡¡¡¡¡¡¡¡¡¡¡¨U¨t¨r
¡¡¡¡¡¡¡¡¡¡¡¡¡¡¨U©¦¨t¨r
¡¡¡¡¡¡¡¡¡¡¡¡¡¡¨U©¦©¦¨t¨r
¡¡¡¡¡¡¡¡¡¡¡¡¡¡¨U©¦©¦©¦©¦
¡¡¡¡¡¡¡¡¡¡¡¡¡¡¨^¨k¨k¨k¨_

¡¡¡¡¡¡¡¡¡¡¡¡¡¡- FengYun - ¡¡¡¡¡¡
¡¡¡¡¡¡¡¡¡¡¡¡annie 08.2003
¡¡¡¡¡¡dancing_faery@hotmail.com
*/

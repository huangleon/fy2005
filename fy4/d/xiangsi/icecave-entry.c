
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "ÌÒÁÖ");
	set("long", @LONG
Õâ±¾ÊÇÒ»Æ¬Ã¯ÃÜ·±Ê¢µÄÌÒ»¨ÁÖ£¬Ô­±¾·¼²ÝÏÊÃÀ£¬ÂäÓ¢çÍ·×£¬ËäÊ±³£ÁýÕÖ×ÅÒ»²ã 
µ­µ­µÄ±¡Îí£¬µ«Ò²°²Ú×ÏéºÍ£¬È»¶ø½ü¼¸ÔÂÀ´£¬ÁÖÖÐÁýÉÏÁËÒ»²ãºñºñµÄÌÒ»¨ÕÎ£¬²»½ö
Ç°Â·ÄÑ±æ£¬¶øÇÒÈôÊÇ¾Ã´ôÆäÖÐ£¬±ã»áÉíÖÐ»¨¶¾¡£¸½½üµÄÀÏ°ÙÐÕÃÇÔÚÊ÷ÁÖÈë¿ÚÊúÆðÁË 
Ò»¿éÊ¯±®£¬ÏÊºìÈçÑªµÄ×­×Ö¸æËßÀ´ÍùÓÎ¿Í£º[0;1;31mÌÒ»¨ÕÎÖÐÎÞ»îÈË£¬ÎðÈë£¡[0m
LONG
	);

	set("outdoors", "icecave");

	set("exits", ([ 
//		"north" : AREA_icecave"taolin2",
		"south" : __DIR__"icecave-maze/entry",
	]));
	set("NONPC", 1);
	set("coor/x",-60);
	set("coor/y",0);
	set("coor/z",-10);
	setup();

}

//	Õâ¶ùÑÝÊ¾ refresh maze,¿ÉÒÔÓÃflushÀ´ÈË¹¤reset maze

void	init(){
	add_action("flush_maze","flush");
}


int	flush_maze(){
	object maze_room;
	string flush_msg;
	
	if (!wizardp(this_player()))
		return 0;
		
	maze_room=find_object(__DIR__"icecave-maze");
	if (!maze_room) return 1;
	flush_msg=MAG"\nºöÈ»¼äÒ»Õó·ç´µ¹ý£¬ÖÜÎ§µÄÌÒ»¨Ö¦ºöÈ»ÒÆ¶¯ÆðÀ´¡£¡£¡£¡£
Ò»ÕóÌìÒ¡µØ×ª£¬Äã·¢ÏÖ×Ô¼ºÓÖ»Øµ½ÁËÌÒ»¨ÁÖµÄ½ø¿Ú¡£\n\n"NOR,
	maze_room->remove_all_players(maze_room,this_object(),flush_msg);
	maze_room->refresh_maze();
	return 1;
}

int	valid_leave(object who, string dir) {
	if (dir == "south")
	{
		if (!who->query_temp("maze/ÌÒ»¨ÁÖÇýÕÎÉ¢"))
		{
			message("vision",who->name()+"ÉîÉîµØÎüÁËÒ»¿ÚÆø£¬¾Ù²½ÏòÁÖÖÐ×ßÈ¥£¬\n",this_object(),who);
			message("vision",MAG"Ò»¹Éµ­µ­µÄÏãÎí´ÓÌÒ»¨ÁÖÖÐÆ®É¢³öÀ´¡£¡£¡£¡£¡£¡£\n"NOR,this_object(),who);
			tell_object(who,"ÄãÕýÓûÌ¤ÈëÌÒ»¨ÁÖ£¬Í»¾õ¿Ú±ÇÖ®ÖÐÏãÎ¶ËÄÉ¢£¬ÐØÖÐÒ»Õó½ÊÍ´£¬ÆøÑª·­ÌÚ£¬
¡°ÆËÍ¨¡±Ò»Éù£¬Ë¤µ¹ÔÚµØ¡£\n");
			who->unconcious();
			return notify_fail ("");
		}
	}		
	return 1;
}
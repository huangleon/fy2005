#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"ÈıÉúÊ¯"NOR);
	set("long", @LONG

	
[1;37m¡¡¡¡¡¡¡¡¡¡¡¡¨X¨Y
¡¡¡¡¡¡¡¡¡¡¡¡¨U¨t¨r
[1;36m¡¡¡¡¡¡¡¡¡¡¡¡¨U©¦¨t¨r
¡¡¡¡¡¡¡¡¡¡¡¡¨U©¦©¦¨t¨r
[1;34m¡¡¡¡¡¡¡¡¡¡¡¡¨U©¦©¦©¦©¦
¡¡¡¡¡¡¡¡¡¡¡¡¨^¨k¨k¨k¨_
[2;37;0m

¡¡½ñÉúÒÑÖªÇ°ÉúÊÂ£¬ ÈıÉúÊ¯ÉÏÁôĞÕÊÏ£¬ 
¡¡²»ÖªÀ´ÉúËûÊÇË­£¬ ÒûÌÀ±ãÍüÈıÉúÊÂ¡£

LONG
        );
	set("exits",([
		"westup" : __DIR__"74",
	]) );

	set("objects", ([
	__DIR__"npc/ding" : 1,
					]) );

  	set("coor/x",80);
	set("coor/y",40);
	set("coor/z",-20);
	set("outdoors", "potboil");
	setup();
}


/*
¨X[ ¡¡- FengYun -¡¡ ]©¨©¨©¨©¨¨[
©®[dancing_faery@hotmail.com]©À©¤©¤¨[
©®[ ¡¡annie 09.2003¡¡ ]©¨©¨©¨¨a    ©¦
©®[ ÀëÀëÂşÈÇÈıÇïÂ¶£¬ÂöÂöÊ±Äı¾ÅÔÂËª ©¦
¨^¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª¡ª-¨a
*/

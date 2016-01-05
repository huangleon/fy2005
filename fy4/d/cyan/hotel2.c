// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ROOM;
string look_stone();

void create()
{
	set("short", "ËÄº£¿ÍÕ»");
    set("long", @LONG
×ß½ø¿ÍÕ»£¬È´²»¼ûĞ¡¶şÓ­ÉÏÀ´£¬½öÊÇÌüÖĞĞü×ÅÒ»·ù²ÆÉñÏñ£¬Á½ÅÔµÄ¹Ò×ÅµÄ
¶ÔÁªÉÏÌâµÀ£º¡°[1;35mÈıÄê²»¿ªÕÅ£¬¿ªÕÅ³ÔÈıÄê[2;37;0m¡±¡£Äã¿ŞĞ¦²»µÃµØÍû×Å¶ÔÁª£¬¿´¿´Å¿
ÔÚ´óÌüÒ»ÓçµÄ×ÀÃæÉÏºôºô´óË¯µÄÎ¨Ò»Ò»¸ö¿ÍÈË£¬ÓÖÃşÁËÃş¹¾¹¾¿¹ÒéµÄ¶Ç×Ó£¬Ò»
Ê±¼äÊÇÈ¥ÊÇÁô£¬µ¹ÕæÊÇ³ì³ùÄÑ¾ö¡£
LONG
NOR
        );
	set("objects", ([
	__DIR__"obj/statue2":1,
	__DIR__"obj/scroll":1,
	__DIR__"obj/desk2":1,
	__DIR__"npc/man":1,

	]));
	set("item_desc", ([

	]) );
	set("exits",([
  		"out" : __DIR__"hotel",
  		"up" : __DIR__"hotel3",
	]) );


	set("coor/x",0);
	set("coor/y",40);
	set("coor/z",95);
	setup();
}


void init() {
	add_action("do_get","get");
}



int do_get(string arg) {
	
	string arg1,arg2;
	int num,gao;
	object ye;
	
	if (!ye=present("fang shisan",this_object())) return 0;
	if (!arg)
		return 0;
	
	if (sscanf(arg,"%s from %s",arg1,arg2)==2)
	{
		if (arg2 == "×ÀÃæ" || arg2 == "×À" || arg2 == "table")
			gao=2;
	
		if (arg1 == "tasty food" && gao == 2) gao=1;
		if (arg1 == "food" && gao == 2) gao=1;
		if (arg1 == "all" && gao == 2) gao=1;
		if (sscanf(arg1,"%s %d",arg2,num)==2)
			if (arg2 == "food" && gao == 2) gao=1;
		if (sscanf(arg1,"%s %d",arg2,num)==2)
			if (arg2 == "tasty food" && gao == 2) gao=1;
		

	}
	
	if (gao == 1) {
		message_vision("$NÔÚË¯ÃÎÖĞ·­ÁË¸öÉí£¬ÕıºÃ½Ø×¡ÁËÄãÉì³öµÄÊÖÍó¡£\n",ye);
		return 1;
	}
	

	return 0;
	
	
}

void reset()
{
	object river,stone,*inv;
	
	::reset();

	river = present("×ÀÃæ", this_object());
	if (!river)
		return;
	inv = all_inventory(river);
	if (sizeof(inv) < 1)
	{
		stone = new(__DIR__"obj/food");
		if(stone)
			stone->move(river);
	}
	return;
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



inherit ROOM;
#include <ansi.h>

void create()

{
        set("short", "����");
        set("long", @LONG
�������������ӣ�ͥԺ�������续�����ɫ�ĳ�������ɽ�ּ䡢Ȫˮ����
���ֽ���һ�������Ʈ��Ʈɢ��Զ����һ�ô�������Ļһ��չ���������ŵġ����
��֦Ѿ�������Ϸ���һ���ƣ���һ���Ʊ���
LONG
        );
        set("exits", ([ 
		"north":  __DIR__"bridge",
	]));
        set("objects", ([
		__DIR__"npc/yexiang":	1,
		__DIR__"obj/trunk":	1,
	]) );
	set("outdoors", "zangbei");
        set("coor/x",-1670);
        set("coor/y",600);
        set("coor/z",10);
	set("map","zbwest");
	setup();

}


void reset()
{
	object statue,incense;
               
        ::reset();
        statue = present("trunk", this_object());
        if (!statue->is_character())
        if (!present("winepot",statue)) {
        	incense=new(__DIR__"obj/winepot");
        	incense->move(statue);
	}
}


void init() {
	add_action("do_get","get");
}



int do_get(string arg) {
	
	object ye;
	
	object me, container;
	string *ban_location, *ban_item, arg1, arg2,what, where; 
	int num, i, ban;

	if (!ye=present("yexiang",this_object())) return 0;
					
	me=this_player();
	if(!arg) return notify_fail("������ʲô��\n");
	if (sscanf(arg,"%s from %s", what, where)!=2)		return 0;
	if (!objectp(container = present(where, this_object())))	return 0;

	if (base_name(container)!=__DIR__"obj/trunk")
		return 0;
	ban_item = ({ "winepot" });				// well, you got to keep this right.
	
	if (what == "all")							ban = 1;
	if (member_array(what,ban_item)!=-1) 		ban = 1;
	if (present(what, container) && sscanf(what,"%s %d",arg2,num)==2)
		if (member_array(arg2,ban_item)!=-1) 	ban = 1;
		
	if (ban) {
		message_vision("$Nһ���ֵ�ס����,��Ц��˵�����Ҿ���ô��ҵ��ˡ���\n",ye);
		return 1;
	}
	
	return 0;
	
	
}
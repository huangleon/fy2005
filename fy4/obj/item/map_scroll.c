//	Used by /d/fy/npc/mapseller
// 	��Ϥ���������Ĺ���	--- By silencer@fy4. workgroup

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("�հ׵ľ���", ({ "scroll" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long","һ����");
                set("value", 1000);
				set("destination","none");
				set("room_name", "����㳡");
				set("usage", "map");
				set("material", "paper");
        }
        ::init_item();
}


void init()
{
   	add_action("do_record","record");
   	add_action("do_look", "look");
}
    
int do_record(string arg)
{
    	object me;
	string desc;
    	    
    	me = this_player();
	
	if (query("room_desc"))
		return notify_fail("�������Ѿ��������ˡ�\n");

	if ( (file_name(environment(me))+ ".c") != query("destination")) {
		if (environment(me)->query("short") == query("room_name"))
			write("�������������ˣ�����Χתת�ɣ�Ҳ��������ظ���\n");
		else
			write("���������Ҫ����ĵط���\n");
		return 1;
	}
		
	message("vision", me->name() + "̧ͷ���˿����ܣ���ͷ"
                "����ϸϸ�Ļ�����ʲô��\n", environment(me), ({ me }));
        tell_object(me, "�㾫�ĵĻ�����" + query("room_name") + "�����ĵ��Ρ�\n");
        set("name","������ľ���");
        set("value",0);
        if (stringp (desc = environment(me)->query("long")))
        	set("room_desc", desc);
        
    	return 1;
}

int do_look(string arg) {
	string msg;
	
	if (arg == "scroll" || arg == "����") {
		if (query("destination") == "none")
			msg = YEL"һ��հ׵ľ�ᣬ������������������㰲���г̡�\n"NOR;
		else {
			msg = YEL"\nһ���ᣬ̧ͷд�ţ�"NOR + query("area") + "  " + query("room_name") + "\n";
			if (query("room_desc")) {
				msg += "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
				msg += "    "+query("room_desc");
				msg += "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			} else
				msg += YEL"�뵽�����ص��¼��Χ�ķ������飨record����\n"NOR;
		}
		write(msg);
		return 1;
	}
	return 0;
}

// Silencer@fengyun workgroup	June.2005
// hmm, �ҹ����ã�����transferable here :P


#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("ͭԿ��", ({ "key" }) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 0);
		set("material", "copper");
        	set("long", "һ��ͭԿ�ף���Use key����\n");
	}
    ::init_item();
}

void init()
{
        add_action("do_open", "use");
}

int do_open(string arg)
{
	object afei, me, room;
	int i;
	
	me = this_player();
	room = environment(me);
	
	if (arg == "key" || arg == "ͭԿ��" || arg = "Կ��") {
		if (environment(this_object())!=me || !arg)
			return 0;
		if (room->query("short")!= "�������"
			|| !room->query("afei_cage"))
			return notify_fail("��������򲻿�ʲô�š�\n");
		if (me->is_busy())
			return notify_fail("��������æ��\n");
				
		if (room->query("door_open"))
			return notify_fail("�����Ѿ����ˡ�\n");
		
		afei = present("afei", room);
		if (!afei)
			return notify_fail("�����Ѿ����ˡ�\n");
		
		if (present("fuhu monk",room))
			return notify_fail("��������˵�����������գ�ʩ�����Ǿ��������ͷ�ɡ���\n");
		if (present("xianglong monk",room))
			return notify_fail("��������˵�����������գ�ʩ�����Ǿ��������ͷ�ɡ���\n");
				
		message_vision(YEL"$N��Կ�ײ嵽������һת����֨һ��������������\n"NOR, me);
		room->set("open_door",1);
		afei->delete_temp("condition_type");
		afei->kill_him(me);
		destruct(this_object());
		return 1;
	}
	return 0;
}

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("��ͭԿ��", ({ "key" }) );
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 0);
		set("material", "jade");
        set("long", "һ������ͭ�����ͭԿ�ף����������½�����ģ���֪�������ڣ�Use key���������ϣ���\n");
	}
    ::init_item();
}

void init()
{
        add_action("do_open", "use");
}

int do_open(string arg)
{
	object obj, room, room1;
	object *team;
	int i;
	if (arg == "key" || arg == "��ͭԿ��" || arg = "Կ��") {
	if (environment(this_object())!=this_player() || !arg)
		return 0;
	if (!objectp(obj=present("iron door",environment(this_player()))))
		return notify_fail("��������򲻿�ʲô�š�\n");
	message_vision(YEL"$N��Կ�ײ嵽������һת��֨ѽһ��������С�Ŵ��ˣ�ʯ����¶
��һ��ͨ��������Կ��ȴ�۶��������\n"NOR, this_player());
	room1 = find_object(AREA_EREN2"jailroad5");
        if(!objectp(room1)) 
        	room1 = load_object(AREA_EREN2"jailroad5");   
	room1->set("exits/north",AREA_EREN2"mouseroom1");
	destruct(this_object());
	}
	return 1;
}

#include <ansi.h>;
inherit ITEM;

void create()
{
	set_name(HIC"�̺�����"NOR, ({"diamond", "blue stone", "stone"}));
    	set_weight(200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
            set("unit", "��");
			set("long", "
����һ�麱������ɫ��ʯ����������˿�����ʣ�Ȼ������Զ����ɫ�ƺ��� 
�������˼����һ�������ңԶ�����硣\n");
                set("value", 200);
		set("imbue", 1);
		set("lore",1);
        }
	::init_item();
}

/*
void init(){
	add_action("do_lian", "lian");
}

int do_lian(){
	object me;
	int i, j;
	me = this_player();
	if(present("yellow stone", me) && present("green stone", me) && present("red stone", me)
			&& present("purple stone", me)) {
		i = me->query_skill("spells");
		j = me->query("mana");
		if(i >= 200 && j >= 2000) {
			message_vision("$N�������з���������һ���׹�ע����ɫ��ʯ��\n", me);
			me->start_busy(3);
			call_out("make_stone", 3, me); 
		} else {
			return notify_fail("��û���㹻�ķ��������ġ�\n");
		}
	} else {
		tell_object(me, "�㻹ȱ��ʯͷ��\n");
	}
	return 1;	
}

int make_stone(object me){
	object obj, ruby, topaz, amethist, jade;
	me->set("mana",0); 
	ruby = present("red stone", me);
	topaz = present("yellow stone", me);
	jade = present("green stone", me);
	amethist = present("purple stone", me);
	message_vision(HIR"�����൤�������׵ĺ�⡣\n"NOR, me); 
	message_vision(HIY"��¶��ʯ���������Ļ�ɫ��â��\n"NOR, me); 
	message_vision(HIG"������䷢���ĳα̵��̹⡣\n"NOR, me);
	message_vision(HIC"�̺����ķ���ӨӨ����ɫ��â��\n"NOR, me); 
	message_vision(HIM"��ڤ�Ͼ��������ĵ���ɫ��â��\n"NOR, me); 
	destruct(ruby);
	destruct(topaz);
	destruct(amethist);
	destruct(jade);
	message_vision("\n��ɫ��ʯ���ڽ��һ�壡\n", me); 
	if(!me->query("m_success/���ʯ")){
	    me->set("m_success/���ʯ",1);
	    me->add("score",10000);
	}	
	obj = new("/obj/specials/stone/rbstone");
	obj->move(me);
	destruct(this_object());
	return 1;
}*/
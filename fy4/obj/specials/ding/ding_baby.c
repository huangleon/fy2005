inherit ITEM;
#define MAX_CARRY 29
#include <ansi.h>

void create()
{
        set_name(YEL"����С��¯"NOR, ({ "ding" }) );
	set_weight(500);
	set("no_drop",1);
	set("no_give",1);
	set("no_get",1);
	set("small_ding",1);
	set_max_encumbrance(50);	
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("unit", "��");
                set("long", CYN"һֻ�������ߵ�С������ƾ��ɣ��ȿ����������Ʊ���ֿ����������
һЩ���䷨ֽ�����Ҫʱ���Էɿ��ȡ����������⣩��\n\n"NOR);
		set("value", 1);
		set("prep","on");
	}
        ::init_item();
}


int is_container() 
{ 
	return 1; 
}

void init()
{
	if(this_player()==environment())
		 add_action("do_grab","grab");
}


int do_grab(string arg)
{
	object	me, ob,*inv;
        if( !arg )
                return notify_fail("��Ҫ��С��¯����ʲô������\n");
	if (!ob=present(arg,this_object()))
		return notify_fail("С��¯������������ô?\n");
	if (!ob->query("fast_grab"))
		return notify_fail("���������������,û��һ����ץ������\n");
	me = this_player();
	inv = all_inventory(this_player());
	if(sizeof(inv) >= MAX_CARRY) 
		return notify_fail("�������Ѿ�����̫�ණ���ˡ�\n");
	message_vision("$Nһ���֣��ɿ�ش�С��¯��ץ��$n��\n", me, ob);
	ob->move(me);
        return 1;
}


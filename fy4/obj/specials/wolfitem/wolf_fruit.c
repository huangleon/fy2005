inherit ITEM;
inherit F_FOOD;
#include <ansi.h>

void create()
{
	set_name(RED"Ұ��"NOR,({"wild fruit", "fruit"}));
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("long",
     	        "һЩ��Ұ��ɼ��Ĺ�ʵ��ɢ���Ű���ɫ�Ĺ�â��\n");
	    set("unit","��");
	    set("value", 0);
		set("desc_ext", "��ɽ���ӿɼ������ˡ�\n");
		set("food_remaining", 1);
		set("food_supply", 0);
		set("no_drop",1);
		set("no_give",1);
		set("material", "food");
	}
	::init_item();
}

int finish_eat()
{
	int value;
	int diff;
	object me;
	me=this_player();
	if (me->query("food")<220) me->add("food",10);
	if (me->query("water")<220) me->add("water",10);
	if(!me->is_fighting()) 
	{
	  	if(me->query_skill_mapped("force") == "wolf-force") {
			tell_object(me,"�㼮�����ķ�����ҩ�������������˴�������ת��\n");
			me->receive_curing("kee", me->query("max_kee")/20);
		}        
	}
	destruct(this_object());
	return 1;
}



// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void do_eatflower();

void create(){
	set_name(HIG"���ǲ�"NOR, ({"grass" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ����̵Ĳݣ��Ȼ�����������仹�̡���\n");
		set("unit", "��");
		set("value", 0);
		set("food_remaining", 1);
		set("food_supply", 1);
		set("eat_func", (: do_eatflower :) );
	}
    ::init_item();
}

void do_eatflower()
{
	object me;
	me = this_player();
	if(!me->query("marks/3years_force")){
		tell_object(me, HIG"\n�����һ����ѣ��ƮƮȻ�����ƶˣ�����\n"NOR);
		me->add("max_force", 100); 
		me->set("marks/3years_force", 1);
		me->set("Add_force/3years_force",100);
		me->unconcious();
	}
}
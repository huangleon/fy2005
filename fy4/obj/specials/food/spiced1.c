// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void do_eatflower();

void create(){
	set_name(YEL"±ţ��"NOR, ({"spiced beef", "beef" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�����������±ţ�⡣\n");
		set("unit", "��");
		set("value", 500);
		set("finish_msg",CYN"$N����ҧ��һ��"+this_object()->query("name")+"�����������򴽻�ζ�����룬��"+this_object()->query("name")+"�ɿ�ؿи����⡣\n"NOR);
		set("food_remaining", 1);
		set("food_supply", 1);
		set("eat_func", (: do_eatflower :) );
	}
    ::init_item();
}

void do_eatflower()
{
	object ob;
	mapping buff;
	ob = this_player();
	if (!ANNIE_D->check_buff(ob,"strup"))
	{
			buff =
			([
				"caster":ob,
				"who":ob,
				"type":"strup",
				"att":"bless",
				"name":"С��̯��±ţ��",
				"buff1":"apply/strength",
				"buff1_c":1,
				"time":60+random(120),
				"buff_msg":HIR"$N"HIR"ͻȻ���û��������������\n"NOR,
			]);
			ANNIE_D->buffup(buff);
	}
	return;
}


// ���p��dancing_faery@hotmail.com


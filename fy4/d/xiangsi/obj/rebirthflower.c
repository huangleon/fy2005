// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void do_eatflower();

void create(){
	set_name(HIB"������"NOR, ({"rebirth flower", "flower" }) );
	set_weight(80);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "һ�������ڸ�ɽ����֮�ϣ�����ؾ��������"HIB"������"NOR"��\n");
		set("unit", "��");
		set("real_flower",1);
		set("no_drop",1);
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
	if (!random(10))
	{
		// �仨��ˮ��ȥҲ��Rebirth
		tell_object(me,HIB"
������İ��������ŵ����У������׽������Ѿ�����һ�ɱ���
��������ĺ������Ǵ̹ǵĺ��ݣ����㲻�������Ĵ���һ����
ս���������������϶�����������ѩ��֮������һ��һ���
ů���������𣬾ۼ������˺����������һ��ů�����߽�����
�����С�\n"NOR);
		me->set("timer/lifesave",time());
	}
}
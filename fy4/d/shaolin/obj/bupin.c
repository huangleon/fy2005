inherit F_FOOD;
inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("����Ʒ" , ({ "good food", "food" }) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
  set("long", WHT
      "�ø�������ҩ�����ɵĲ�Ʒ\n"NOR);
		set("unit", "��");
		set("value", 2000);
		set("food_remaining", 1);
		set("food_supply", 0);
		set("material", "food");
	}
	::init_item();
}
int finish_eat()
{
	object me;
	int max_gin, max_kee, max_sen, num;
	me = this_player();
	max_gin = (int) me->query("max_gin");
        max_kee = (int) me->query("max_kee");
        max_sen = (int) me->query("max_sen");
	message_vision( HIR "$N��ȫ��ӳ��һ���⣡��\n"NOR, me);
	if (me->query_temp("timer/medicine")<11 &&  !me->query_temp("buffup/buffed_kee")) {
	max_gin = max_gin * 21/20;
	max_kee = max_kee * 21/20;
	max_sen = max_sen * 21/20;
	switch(random(3)){
		case 0:
			me->set("max_gin", max_gin);
			break;
		case 1:
			me->set("max_kee", max_kee);
			break;
		case 2:
			me->set("max_sen", max_sen);
			break;
			}
	num=me->query_temp("timer/medicine");
	me->set_temp("timer/medicine",num+1);
	} else tell_object(me,"������ûʲôЧ��,����ǳԵ�̫���Ե��.\n");
	destruct(this_object());
        return 1;
}

inherit F_FOOD;
inherit ITEM;
#include <ansi.h>
void create()
{
    set_name(HIR"���"NOR , ({ "zhuguo" }) );
	set_weight(5);
	if( clonep() )
		set_default_object(__FILE__);
	else {
  set("long", RED
      "һ�����ɫ��Ұ�����������̣������˱ǡ�\n"
      "��˵��ʳ�Ժ���������ļ��ޣ�\n"NOR);

        set("unit", "��");
        set("lore",1);
        set("value", 0);
		set("food_remaining", 1);
		set("food_supply", 0);
		set("material", "food");
	}
	::init_item();
}
int finish_eat()
{
	object me;
	int max_gin, max_kee, max_sen;
	int n;
	me = this_player();
	if (!me->query_temp("timer/zhuguo") && !me->query_temp("buffup/buffed_kee"))
	{
	max_gin = (int) me->query("max_gin");
        max_kee = (int) me->query("max_kee");
        max_sen = (int) me->query("max_sen");
 	message_vision( HIY "$Nֻ������ů�����ʮ�������ȫ������ɢ����һ�����ŵ�������\n"NOR, me);
    	if (me->query("combat_exp")>3000000) n=22;
    		else if (me->query("combat_exp")>2500000) n=23;
    			else n=24;
    	max_gin = max_gin * n/20;
    	max_kee = max_kee * n/20;
    	max_sen = max_sen * n/20;
			me->set("max_gin", max_gin);
			me->set("max_kee", max_kee);
			me->set("max_sen", max_sen);
			me->set_temp("timer/zhuguo",1);
	destruct(this_object());
        return 1;
	} else 
	message_vision( HIY "$N��Ȼ���ø���ů�����ʮ���������ʲôҲû������\n"NOR, me);
	destruct(this_object());
	return 1;
}

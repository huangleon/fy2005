#include <ansi.h>
#include <ansi.h>

inherit F_FOOD;
inherit ITEM;

void create()
{
        set_name(HIY"��ɩ��"NOR, ({ "song-fish", "fish" }) );
        set_weight(350);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ�������ˣ�������Ʒ���㣬��õĳ�ʦ�����Ȫˮ��������ϲ����ó���
��������ڼ������������ۣ�������˧�ĺ��֪�������������ɩ�������˧�������˵���й��á�\n");
                set("unit", "��");
                set("food_remaining", 5);
                set("food_supply", 0);
                set("material", "food");
        }
        ::init_item();
}


int finish_eat()
{
        object me;
        int max_force;
        int n;
        me = this_player();
        if (!me->query_temp("timer/songfish") ) {
        	max_force = (int) me->query("max_force");
        	message_vision( HIW "$N���̻��ʣ������Ƴ�����ɩ�㣬���㣬ֻ��������ͨ���������뵣�
�·����˾�ţ����֮����\n"NOR, me);
        	if (me->query("combat_exp")>1000000) n=3;
                else if (me->query("combat_exp")>500000) n=4;
                        else n=5;
        	max_force = max_force * n;
            me->set("force", max_force);
            me->set_temp("timer/songfish",1);
        	destruct(this_object());
        	return 1;
        } else 
        	message_vision( HIW "$N�����򴽱ߣ���ζ���\n"NOR, me);
        destruct(this_object());
        return 1;
}

//TIE@FY3
#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name(HIY "���ϵ�" NOR, ({ "wood-wandao" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
        set("long", "һ������ľ����䵶�����ʣ��������߰룬����������˳���ͼ��\n��˵��ѵ����зǷ���ħ������ȴ���˲�͸������ \n");
        set("material", "wood");
        set("wield_msg", "$NĬĬ������$n�������С�\n");
                set("unwield_msg", "$NĬĬ�ط������е�$n��\n");
		set("desc_ext","���ˣ�cure wood-wandao��");
	}
	::init_blade(25);
}
void init()
{
        if(this_player()==environment())
        add_action("do_cure","cure");
}
int do_cure(string arg)
{
        object me;
        me = this_player();
        if (!arg)
                return notify_fail("��Ҫ��ʲô���ˣ�\n");
    	if (arg != "wood-wandao")
                return notify_fail("��Ҫ��ʲô���ˣ�\n");
        if (query("used")) 
                return notify_fail(this_object()->name()+"�����޹⣬��ľ���������ֳ�һ˿Ѫ�ۣ���Ҳ���������ˡ����� \n");
       message_vision(HIR"$NĬĬ�����ϵ���������$N����Ѫ������˿ڴ�������\n"NOR,me);
       me->set("eff_kee",(int)me->query("max_kee"));
       me->set("eff_gin",(int)me->query("max_gin"));
       me->set("eff_sen",(int)me->query("max_sen"));
       message_vision(HIW"\n$NͻȻ�����˿�һ������ͷһ����ԭ��Ѫ���߰ߵ��˿�\n��Ȼ�ѹ⻬���񡣡� \n\n"NOR,me);
        set("used",1);
        return 1;
}

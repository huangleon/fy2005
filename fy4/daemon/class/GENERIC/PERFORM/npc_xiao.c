#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)

{
	object wolf;
	int summonwolf, exp;
	int guard;
        
        if(userp(me))
		return notify_fail("����ѡ�õ��书��û�����ֱ�ɱ������\n");
        if ((string)me->query("class") != "wolfmount")
		return notify_fail("ֻ����ɽ���Ӳſ�����������\n");
        if( !me->is_fighting() )
        	return notify_fail("����û����Ҫɱ�㣡\n");
	
	guard= 2;

	if( me->query_temp("max_guard") > guard )
    	return notify_fail("���󸽽��Ѿ�û�����ˡ�\n");

	summonwolf = (int)me->query_skill("summonwolf",1);
	seteuid(getuid());
	wolf= new("/obj/npc/wolf");
	wolf->move(environment(me));
        wolf->invocation(me, (summonwolf));
        wolf->set("possessed", me);

	if (summonwolf<50)
		wolf->set_name("��ë����",({ "wolf" }));
	else if (summonwolf<75)
		wolf->set_name(WHT"��ë����"NOR,({ "wolf" }));
	else if (summonwolf<100)
    		wolf->set_name(YEL"��ë����"NOR,({ "wolf" }));
	else if (summonwolf<125)
        	wolf->set_name(RED"��ë����"NOR,({ "wolf" }));
	else if (summonwolf<150)
		wolf->set_name(HIW"��ë����"NOR,({ "wolf" }));
        else if (summonwolf<175)
     		wolf->set_name(HIR"��ë����"NOR,({ "wolf" }));
	else 
		wolf->set_name(HIY"��ë����"NOR,({ "wolf" }));

    me->add_temp("max_guard",1);

	message_vision(HIB "\n$N�����Ǻ����ء�໡������ء�໡�����ʱ��ɽ��ҰȺ��������\n" NOR, me);	
    message_vision( "\n\n$N��ݺݵ�����������\n" , wolf);
	return 1;
}


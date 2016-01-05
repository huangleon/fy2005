// TIE@FY3
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	string what, who;
	object ob, victim;
	mapping myfam, vtfam;
	int sp, dp;

	object where = environment(me);
        if(me->query("class") != "swordsman")
                return notify_fail("ֻ��������¾������˾����Ľ��Ͳſ��Բ�����\n");
	if( environment(me)->query("no_preach"))
		return notify_fail("���ﲻ�ʺ��㲼����\n");

	if( me->query_temp("preaching") )
		return notify_fail("�����ڲ�����\n");

	if( !arg || sscanf(arg, "%s about %s", who, what)!=2 ) return
		notify_fail("ָ���ʽ��preach <ĳ��> about <ĳ��>\n");
	if(me->query("sen") < 21)
		return notify_fail("����񲻹���\n");
	victim = present(who, environment(me));

	if( !victim || victim == me) return notify_fail("���벼���Ķ��������\n");

	if( !living(victim) || !objectp(victim))
		return notify_fail("��Ҫ��˭������\n");

	if( !wizardp(me) && wizardp(victim) )
		return notify_fail(victim->name()+"�������㲼���ġ�\n");
	if( me->is_fighting() )
                return notify_fail("������һ�ߴ��һ�߲�����\n");

	if( victim->is_fighting() ) 
                return notify_fail(victim->name() + "���ڴ�ܣ�û�����㣡\n");
        if((int)me->query_skill("daode",1) < 25 )
                return notify_fail(victim->name()+"���󲻻�������Ƶġ�\n");
	if( !ob = present(what, victim) ) {
		object *inv;
		inv = all_inventory(victim);
		if( !sizeof(inv) )
			return notify_fail( victim->name() + "���Ͽ�����û��ʲ������ֵ�ò���������\n");
		ob = inv[random(sizeof(inv))];
	}

	if ( ob->query("equipped") || ob->query("no_drop") || ob->query("owner"))
		return notify_fail(victim->name()+"���󲻻�������Ƶġ�\n");

	sp = (int)me->query_skill("daode",1) * (int)me->query_skill("daode",1) 
	 + (int)me->query_cps() * (int)me->query_cps() * (int)me->query_cps() ;
	if( sp < 5000 ) return notify_fail("�㻹û�е��ﲼ���Ľ׶Ρ�\n");
	dp = (int) victim->query("score")-(int)victim->query("bellicosity") + 
	(int)victim->query_cps() * (int)victim->query_cps() * (int)victim->query_cps() * (int)victim->query_cps() +
	(int)victim->query_int()*(int)victim->query_int()*(int)victim->query_int();
	tell_object(me, "��ׯ�ϵ���" + victim->name() + "��˵��"
			+ ob->query("unit") + ob->name() +"�����ֻ���...\n\n");
	tell_object(victim, me->name() + "����ׯ�ϣ�����������˵������λ" + RANK_D->query_respect(victim) + "���������Σ�����" 
			+ ob->query("unit") + ob->name() + "�� ...��\n\n");
	message("vision", "ֻ��" + me->name() + "����ׯ�ϣ��������࣬\n��" 
		+ victim->name() + "�����䷳�ز����ţ�����",environment(me), ({ me, victim }) );

	me->set_temp("preaching", 1);
	me->receive_damage("sen",20);
	call_out( "compelete_preach",random(3)+1, me, victim, ob, sp, dp);

	return 1;
}

private void compelete_preach(object me, object victim, object ob, int sp, int dp)
{
	int amount;
	object ob1;

	me->delete_temp("preaching");
        if(!victim) {
                tell_object(me, "̫��ϧ�ˣ�������������Ѿ������ˡ�\n");
                return;
        }
	if( environment(victim) != environment(me) ) {
		tell_object(me, "̫��ϧ�ˣ�������������Ѿ����ˡ�\n");
		return;
	}

	if(!victim->query("spi")) {
		tell_object(me,victim->name()+"����Ĳ����޶����ԣ�\n");
		return;
	}
	if( living(victim) && (random(sp+dp) > dp) && ob->move(environment(me))) 
	{
		message_vision("$N����$n�Ĳ��������ид���һ��������һ" 
				+ ob->query("unit") + ob->name() + "���ڵ��¡�\n",victim,me);

//		me->improve_skill("begging", random(me->query("int")));
//		me->add("potential",1);
//		me->add("combat_exp",1);
		me->start_busy(1);
	} 
	else 
	{
		if( random(sp+dp) > dp/2 ) {
                message_vision("$N��һ����ʯ�㣬��$n�Ĳ���������ᡣ\n", victim,me);
                me->start_busy(3);
			return;
		}
		else
		message_vision("$N�ݺݵص���$nһ�ۣ��ȵ��������ᣡȥ���˰ɣ�\n", victim,me);
		if(!environment(victim)->query("no_fight"))	
		victim->fight_ob(me);
		me->start_busy(3);
	}
}

int help(object me)
{
write(@HELP
ָ���ʽ : preach <ĳ��> about <ĳ��>

HELP
    );
    return 1;
}

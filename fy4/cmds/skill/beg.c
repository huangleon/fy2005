// TIE@FY3
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	string what, who;
	object ob, victim;
	mapping myfam, vtfam;
	int sp, dp,lvl;

	object where = environment(me);
    
    
    if (userp(me) && me->query("class")!="beggar" )
       	return notify_fail("ֻ��ؤ����Ӳ������֣�\n");

	if (userp(me))
    	return notify_fail("�Ϲ������ٰ�ͣ���ʱ��׼ؤ����Ӻ��������ˣ�\n");
    
	if( environment(me)->query("no_beg")
	 || environment(me)->query("no_fight"))
	 	return notify_fail("���ﲻ���ʺ�ؤ������ַ��ĵط���\n");

	if( me->query_temp("begging") )
		return notify_fail("���Ѿ�������������ˣ�\n");

	if( !arg || sscanf(arg, "%s from %s", what, who)!=2 ) return
		notify_fail("ָ���ʽ��beg <ĳ��> from <ĳ��>\n");

	if ( userp(me) && ((int)me->query_skill("begging",1) < 25))
		return notify_fail("����������Ҫ����������֮����\n");
	
	victim = present(who, environment(me));
	if( !victim || victim == me) return notify_fail("�������ֵĶ��������\n");

	if( !living(victim) || !objectp(victim))
		return notify_fail("��Ҫ��˭���֣�\n");

        if ( (vtfam = victim->query("family")) && vtfam["family_name"] == "ؤ��" )
                return notify_fail("�㲻���򱾰�������֣�\n");

	if( !wizardp(me) && wizardp(victim) )
		return notify_fail("�����������Ա���֡�\n");

	if (userp(me))
	if (!COMBAT_D->legitimate_kill(me, victim)) {
		if (stringp(victim->query("NO_KILL")))
			return notify_fail(victim->query("NO_KILL"));
		if (stringp(victim->query("NO_PK")))
			return notify_fail(victim->query("NO_PK"));	
		else 
			return notify_fail("���޷���������֡�\n");
	}
	
	if( me->is_fighting() )
                return notify_fail("������һ�ߴ��һ�����֣�\n");

	if( victim->is_fighting() )
                return notify_fail(victim->name() + "���ڴ�ܣ�û�����㣡\n");

	if( !ob = present(what, victim) ) {
		object *inv;
		inv = all_inventory(victim);
		if( !sizeof(inv) )
			return notify_fail( victim->name() + "���Ͽ�����û��ʲ���������Ȥ�Ķ�����\n");
		ob = inv[random(sizeof(inv))];
	}

	if (ob->query("equipped") || ob->query("no_drop") || ob->query("owner"))
		return notify_fail(victim->name()+"���󲻻�ʩ������κζ����Ƶġ�\n");
        
        if(me->query("sen") <= 100 && userp(me))
            	return notify_fail("������Ҫ�ķ�һ��������100����\n");
        if (userp(me))
        	me->add("sen",-100);

	lvl = me->query_skill("begging",1);
	
	// 200 * 200 + 55*55*55/3 = 95450
	// 60*1000 + score + bellicosity
	// The formula doesn't really make sense... 
	// Let's just say, you can improve your chance, but whom you can beg easily is pure chance.
			
	sp = (lvl * lvl + me->query_kar()* me->query_kar()* me->query_kar()/3)/10;
        dp = victim->query_cps()*1000 
        	+ victim->query("score") + victim->query("bellicosity");
        
	tell_object(me, "��һ�������Ͱ͵����ӣ���������" + victim->name() + "�߹�ȥ�����˫�֣���Ҫ"
			+ ob->query("unit") + ob->name() +"����\n\n");
	tell_object(victim, me->name() + "һ�������࣬���������߹���������֣�˵����" + RANK_D->query_respect(victim) + "���кã�����"
			+ ob->query("unit") + ob->name() + "�ɡ�����\n\n");
	message("vision", "ֻ��" + me->name() + "װ�������Ͱ͵����ӣ���������"
		+ victim->name() + "�߹�ȥ��\n���˫�֣�˵����"
		+ RANK_D->query_respect(victim) + "�����кðɡ���\n\n", environment(me), ({ me, victim }) );

	if (wizardp(me))
		tell_object(me, "the begging chance is " + sp + " vs " + dp + "\n");
	me->set_temp("begging", 1);
	call_out( "compelete_beg",random(3)+1, me, victim, ob, sp, dp);

	return 1;
}

private void compelete_beg(object me, object victim, object ob, int sp, int dp)
{
	int amount;
	object ob1;

	if (!me)	return;
		
	me->delete_temp("begging");
	if(!victim) {
                tell_object(me, "̫��ϧ�ˣ���Ҫ���ֵ����Ѿ������ˡ�\n");
                return;
        }
	if( environment(victim) != environment(me) ) {
		tell_object(me, "̫��ϧ�ˣ���Ҫ���ֵ����Ѿ����ˡ�\n");
		return;
	}
// exp limit to stop beggar dummies
	if (userp(me) && victim->query("combat_exp")>me->query("combat_exp")*10) {
		tell_object(me,victim->name()+"��м�ؿ�����һ��˵������ȥ�����ɡ���\n");
		return;
	}

	if (!ob || !present(ob, victim)) {
		tell_object(me, "����Ҫ�Ķ����Ѿ�����"+victim->name()+"�����ˡ�\n");
		return;
	}
	
// not a human being
	if(victim->query("race")!="����") {
		tell_object(me,victim->name()+"�������޶����ԣ�\n");
		return;
	}
	if( living(victim) && (random(sp+dp) > dp) && ob->move(me))
	{
		message_vision("$N����$n�Ŀ�������̾�˿���������$nһ"
			+ ob->query("unit") + ob->name() + "��\n",victim,me);
		me->start_busy(3);
	}
	else
	{
		if( random(sp+dp) > dp/2 ) {
                	message_vision("$NŤ��ͷȥ����$n������\n", victim,me);
                	me->start_busy(3);
			return;
		}
		
		message_vision("$N�ݺݵص���$nһ�ۣ��ȵ�����л��ӣ������ᣡ�������ˣ�\n", victim,me);
		if(!environment(victim)->query("no_fight"))
			victim->fight_ob(me);
		me->start_busy(3);
	}
}

int help(object me)
{
write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	beg <����> from <����>[0m
[0;1;37m����������������������������������������������������������������[0m   

����һ��ؤ��ר�õ�ָ�����������������Ʒ�����ֵĳɹ�����������
������������֮���ĸߵ͡��Լ�˫���Ľ���������ء�
���������Ϲ�����ư���֮λ�����ٰ�ͣ���׼ؤ����Ӻ��������ˡ�

[0;1;37m����������������������������������������������������������������[0m   
HELP
    );
    return 1;
}

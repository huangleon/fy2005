// silencer@fy

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string what, who;
	object ob, victim;
	mapping myfam, vtfam;
	int sp, dp;
	
	object where = environment(me);
	if ( me->query("class")!="shenshui")
	          return notify_fail("ֻ����ˮ���Ӳ���ʹ�ù�������\n");

	if (userp(me))
		return notify_fail("�������˵ķ�ʽ�����������о��С�\n");
		
	if( environment(me)->query("no_fight"))
		return notify_fail("�����Ǻ�����ĳ��ϣ����֪�������г���ľٶ���\n");

	if( me->query_temp("seducing") )
		return notify_fail("���Ѿ���ʩ�������ˣ�\n");
	
	if( !arg || sscanf(arg, "%s from %s", what, who)!=2 ) 
		return notify_fail("ָ���ʽ��seduce <ĳ��> from <ĳ��>\n");

	if ( (int)me->query_skill("nine-moon-spirit",1) < 100)
		return notify_fail("������ÿ��Ů�����ܳ�Ϊ���꾫�ģ��㻹�Ǹ������Ů�񹦲��ǣ���Ҫ100������\n");

	if( me->is_fighting() )
                return notify_fail("��ܵ�ʱ�򻹿����������ۣ�\n");

        if(me->query("sen") <= 200)
            	return notify_fail("�㾫����ίί���ҵ�һ�㲻�����ˡ�\n");
        if(me->query_per() < 20)
            	return notify_fail("����쿴����һ��Ҳ�������ˣ����ǻ�ȥ�úô��һ�������԰ɡ�\n");

	victim = present(who, environment(me));
	if( !victim || victim == me) 
		return notify_fail("���빴���Ķ��������\n");
	
	if( !living(victim) || !objectp(victim) || victim == me)
		return notify_fail("��Ҫ����˭��\n");

	if (userp(me))
	if (!COMBAT_D->legitimate_kill(me, victim)) {
		if (stringp(victim->query("NO_KILL")))
			return notify_fail(victim->query("NO_KILL"));
		if (stringp(victim->query("NO_PK")))
			return notify_fail(victim->query("NO_PK"));	
		else 
			return notify_fail("���޷��������ˡ�\n");
	}
	
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
		return notify_fail(victim->name()+"̫��������������,�����·�Ҳû�á�\n");

        if (userp(me))	me->add("sen",-200);
        
        //	180 * 180 + 40*40*40/3 = 54000
	sp = (int)me->query_skill("nine-moon-spirit",1) * (int)me->query_skill("nine-moon-spirit",1) 
	 + (int)me->query_per()* (int)me->query_per() * me->query_per() /3;
	
	if(me->query("gender")==victim->query("gender"))
		sp = sp/3;
		
	if(victim->query("age")<12 || victim->query("age")>60)
		sp = sp/3; 
	 
	if( sp < 1 ) sp = 1;
	
	//	40* 1000 + 20000 = 60000
	dp = (int)victim->query_cps()*1000+20000;

	tell_object(me, HIG"����Ц����������Сèһ�������Ŀ�����"+victim->name()+HIG"���ŵ�"+ ob->name());
	tell_object(me, NOR MAG"\n��������۵���ɫ������ҧ��ҧ���촽 ���� \n��֪���Լ��Ѿ��㹻�ˣ�����ʲô�˻����������˼������һ���ǰ׳ա�\n\n"NOR);

	tell_object(victim, HIG+ me->name() + HIG"��������Ц����������У���������ȥ��\n"NOR);
	tell_object(victim,MAG"�����۾���˵����������Ц��˵����������Ϲ�ӣ�Ҳ�����ŵõ�������ɢ������\n��һ�������㣬Ҳ�������õ��������굴�ǵ�ǳЦ��\n\n"NOR);
	tell_object(victim,MAG"���ƺ������"+ob->name()+NOR MAG"�ܸ���Ȥ��\n"NOR);
	
	message("vision", HIG"ֻ��"+me->name()+HIG"��Ц����������Сèһ�������Ŀ�����"NOR+victim->name()+"��\n"NOR,environment(me), ({ me, victim }) );
	message("vision", MAG+me->name()+ MAG"���۾���˵����������Ц��˵����������Ϲ�ӣ�Ҳ�����ŵõ�������ɢ������\n��һ�������㣬Ҳ�������õ��������굴�ǵ�ǳЦ��\n"NOR,environment(me), ({ me, victim }) );
	message("vision", YEL + me->name()+ YEL"�ƺ��ܸ���Ȥ"+ victim->name()+"���ϴ���ʲô������\n\n"NOR,environment(me), ({ me, victim }) );
	
	me->set_temp("seducing", 1);
	call_out("compelete_seduce",random(3)+1, me, victim, ob, sp, dp);

	return 1;

}




private void compelete_seduce(object me, object victim, object ob, int sp, int dp)
{
	int amount;
	object ob1;

	me->delete_temp("seducing");
	if(!objectp(victim)) { 
			tell_object(me, "���˷Ѹ����ˣ���Ҫ���������Ѿ������ˡ�\n");
		return;
	}
	
	if( environment(victim) != environment(me) ) {
		tell_object(me, "���˷Ѹ����ˣ���Ҫ���������Ѿ������ˡ�\n");
		return;
	}
// not a human being
	if(!victim->query("spi")) {
		tell_object(me,victim->name()+"�������޶����ԣ�\n");
		return;
	}
	
	if (!present(ob, victim)) {
		tell_object(me, "����Ҫ�Ķ����Ѿ�����"+victim->name()+"�����ˡ�\n");
		return;
	}
	
	// exp limit to stop beggar dummies
	if (victim->query("combat_exp")> me->query("combat_exp")* 5) {
		message_vision(NOR"\n$Nһ���������ӣ��������ں�$n�Ѿ��Ļ����ջ�\n"NOR, victim, me);
		return;
	}
	
	if( living(victim) && (random(sp+dp) > dp) && ob->move(me)) 
	{
		message_vision(YEL"$N�ճյ�����$n����Ȼ���������$n����˼�����ϰ�" 
				+ ob->query("unit") + ob->name() + YEL"����$n���\n
\n$N�����ֳ������Եõ�������������˵������ƽ���˵Ĵ���ʥ��������˭��\n\n"NOR,victim,me);
		me->start_busy(3);
	} 
	else 
	{
		if( random(sp+dp) > dp*3/4 && random (4)>1) {
                	message_vision(YEL"$N����Զ��,�ƺ�������ûע�⵽$n��\n"NOR, victim,me);
                	me->start_busy(3);
			return;
		}
		else
			message_vision(YEL"$N�ݺݵص���$nһ�ۣ��ȵ�������Ů,�����ڴ�����\n"NOR, victim,me);
		if(!environment(victim)->query("no_fight"))	
			victim->fight_ob(me);
		me->start_busy(3);
	}
}



int help(object me)
{
write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	seduce <����> from <����>[0m
[0;1;37m����������������������������������������������������������������[0m   

������ˮ����ר�õ�ָ������Լ��������ñ����ĸ���Ը�ذѶ������㡣
�ɹ�����Է����Ա����䡢����������Լ��Ů�񹦵ļ�����ء�

[0;1;37m����������������������������������������������������������������[0m   
HELP
    );
    return 1;
}

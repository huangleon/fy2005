//mimicat@fy4
// - rewriten by neon 06-09-2002
// - new daojianruomeng

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int team_perform(object target, object me, object you);
int perform(object me, object target)
{
		int mylevel;
		string msg,yourname,myname,targetname;
        int skl_me, skl_you, extra_me, extra_you,j,k, solo = 0;
        object you, ob,*myteam, *mystuff, sword, blade;

		if(me->query("gender")!="����")
			return notify_fail("�̸赶���ġ��������Ρ����������ӷ�����\n");
        
		if(me->query_skill("shortsong-blade",1)<30)
        	return notify_fail("�̸赶���ġ��������Ρ���Ҫ30���Ķ̸赶����\n");
        	
		if (!target) target = offensive_target(me);
	        if( !target
	        ||      !target->is_character()
	        ||      !me->is_fighting(target) )
	                return notify_fail("���������Ρ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

        // �Զ�Ѱ��һ��teammate perform.
        
		myteam = me->query_team();
        k = 0;
        if( !pointerp(myteam)) solo = 1 ;
        else {
        	for (j = 0; j< sizeof(myteam); j++) {
        		if (environment(myteam[j]) == environment(me)) {
        			if( myteam[j] != me ) you = myteam[j];
        			k++;
        		}
        	}
        	if (k == 1) solo = 1;
        	else if (k == 2) solo = 0;
        	else 
        		return notify_fail("���������Ρ���Ҫ����������ӡ�������е��������Աߣ������ͷ��Ӳ�������\n"); 
        }
                
        if (solo) 
			return notify_fail("�̸赶���ġ��������Ρ���Ҫ���˲��ܷ�����\n");
        /*Team perform*/
        else { 
         	return team_perform(target, me, you);
        }
        
}

int team_perform(object target, object me, object you)
{
	object blade, sword;
	int skl_me, skl_you, extra_me, extra_you,j,k, bonus;
	string msg,yourname,myname,targetname;

	if(me->query("gender")!="����"|| you->query("gender")!="Ů��")	
		return notify_fail("����һ��һŮ���ܹ�ʹ�����������\n");

        if(me->query_skill("shortsong-blade",1)<30)
        	return notify_fail("�̸赶���ġ��������Ρ���Ҫ30���Ķ̸赶����\n");
		if(!you->query_skill("diesword",1) || you->query_skill_mapped("sword") != "diesword") 
        	return notify_fail("ͬ��û����ϵ��书��\n");
        if(you->query_skill("diesword",1)<30)
        	return notify_fail("ͬ���书���𲻹���\n");
        if(!objectp(sword=you->query_temp("weapon"))) 
        	return notify_fail("ͬ��û�б�����\n");
        if(sword->query("skill_type") != "sword")
        	return notify_fail("ͬ��������಻�ԡ�\n");
        if(you == target )
        	return notify_fail(MAG"����ô�ݵ�������ģ�\n"NOR);
        if(you->query("class")!="legend" && me->query("class")!="legend")
			return notify_fail("������һ���˱�������ѩ���Ӳ����á��������Ρ�\n");
		if (you->is_busy())
			return notify_fail("ͬ����æ�ţ�û������һ��ʩչ���������Ρ�\n");
         
        if (userp(you) && !you->is_fighting(target))
			return notify_fail("ͬ����Է�������ս���С�\n");
	
		if (userp(me))
		if (!COMBAT_D->legitimate_kill(you, target)) {
			if (stringp(target->query("NO_KILL")))
				return notify_fail(target->query("NO_KILL"));
			if (stringp(target->query("NO_PK")))
				return notify_fail(target->query("NO_PK"));	
			else 
				return notify_fail("������취��ͬ�鳶���������ɣ�\n");
		}
	
	 	if (!me->is_killing(target->get_id())){
 			me->kill_ob(target);
 			target->kill_ob(me);
 		}
 		
 		if (!you->is_killing(target->get_id())){
        	you->kill_ob(target);
        	target->kill_ob(you);
        }         
                             
	if (you->query("marry") == me->query("id") && you->query("id") == me->query("marry"))  {
		message_vision(HIG"\n$N��$n��Ŀ����һ�ۣ���Ȼ���������������ͷ������������������λð�ӳ�������\n\n"NOR,me,you);		
	}
	
        skl_me=(int)me->query_skill("shortsong-blade",1);
        extra_me=(int)me->query_skill("shortsong-blade",1);        
        skl_you=(int)you->query_skill("diesword",1);
        extra_you= (int)you->query_skill("diesword",1);
                
//        message_vision((string)(bonus)+" "+(string)(skl_me)+" "+(string)(extra_me)+".\n",me);
        
        me->add_temp("apply/attack",skl_me);
        me->add_temp("apply/damage",extra_me);
        you->add_temp("apply/attack",skl_me);
        you->add_temp("apply/damage",extra_me);
 
 		if (!me->is_killing(target->get_id())){
 			me->kill_ob(target);
 			target->kill_ob(me);
 		}
 		
 		if (!you->is_killing(target->get_id())){
        	you->kill_ob(target);
        	target->kill_ob(you);
        }
        
        myname=me->name();
        yourname=you->name();
        targetname=target->name();
        blade=me->query_temp("weapon");

		msg=HIY"\n$N��$n�����ϱڣ�ʹ����һʽ���������Ρ���˿˿��ۣ���ˮ��©����"+targetname+HIY"նȥ�� \n\n";
       		msg+=HIC"����ǣţ�ǣ���Ӻ�Ů��\n"NOR;
        	msg+=HIC"$N���е�"+sword->name()+HIC"��תǧ�أ���ò�����"+targetname+HIC"��ǰһ����$n���е�"
                +blade->name()+HIC"����ɱ����ǰ�� "NOR;
		message_vision(msg,you,me);
		COMBAT_D->do_attack(me,target, TYPE_REGULAR," ");

        	msg=CYN"\n\n����ߪ���֣�����Ū���̡�\n";
        	msg+="$N���л�����ǰ�����־���һ���� \n"NOR;
		message_vision(msg,you,me);
        	COMBAT_D->do_attack(you,target,TYPE_REGULAR," ");

        	msg=HIW"\n\n���ղ����£����������ꡣ\n";
        	msg+="$n���е�"+blade->name()+HIW"��ס��Σ�$N�˻�����һƬ��Ӱ����"+targetname+HIW"ȫ���������С�" NOR;
		message_vision(msg,you,me);
        	COMBAT_D->do_attack(you,target,TYPE_REGULAR," ");

        	msg=HIM"\n\n�Ӻ�����ǳ����ȥ������\n";
        	msg+="$n������§$N������������"+blade->name()+HIM"бб�ӳ���ֱȡ"+targetname+HIM"��Ҫ���� "NOR;
		message_vision(msg,you,me);
        	COMBAT_D->do_attack(me,target, TYPE_REGULAR," ");

        	msg=HIG"\n\nӯӯһˮ�䣬���������\n";
        	msg+="$n��$N������ͨ��һ��һ������������е����£����϶�Ϊһ��ֱ��"+targetname+HIG"��ȥ��"NOR;
		message_vision(msg,you,me);
        	COMBAT_D->do_attack(me,target, TYPE_REGULAR," ");
        	COMBAT_D->do_attack(you,target,TYPE_REGULAR," ");

        me->add_temp("apply/attack",-skl_me);
        me->add_temp("apply/damage",-extra_me);
        you->add_temp("apply/attack",-skl_me);
        you->add_temp("apply/damage",-extra_me);
        me->perform_busy(3);
        you->perform_busy(3);
        return 1;
}


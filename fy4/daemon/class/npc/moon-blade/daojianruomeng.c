//mimicat@fy4
// - rewriten by neon 06-09-2002
// - new daojianruomeng
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int single_perform(object target, object me, object blade, object sword);
int team_perform(object target, object me, object you);
int perform(object me, object target)
{
	int mylevel;
	string msg,yourname,myname,targetname;
        int skl_me, skl_you, extra_me, extra_you,j,k, solo = 0;
        object you, ob,*myteam, *mystuff, sword, blade;

		if(me->query("gender")!="Ů��")
			return notify_fail("�����������ġ��������Ρ�������Ů�ӷ�����\n");
			
		if(me->query_skill("diesword",1)<30)
        	return notify_fail("����������Ҫ30���ĵ�����������\n");
				
		if (!target) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("���������Ρ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");

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

	if(me->query("gender")!="Ů��"|| you->query("gender")!="����")	
		return notify_fail("����һ��һŮ���ܹ�ʹ�����������\n");

        if(me->query_skill("diesword",1)<30)
        	return notify_fail("��ĵ������������𲻹���\n");
		if(!you->query_skill("shortsong-blade",1) || you->query_skill_mapped("blade") != "shortsong-blade") 
        	return notify_fail("ͬ��û����ϵ��书��\n");
        if(you->query_skill("shortsong-blade",1)<30)
        	return notify_fail("ͬ���书���𲻹���\n");
        if(!objectp(blade=you->query_temp("weapon"))) 
        	return notify_fail("ͬ��û�б�����\n");
        if(blade->query("skill_type") != "blade")
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
                    
	// Now determine the bonus for same menpai and couple
		if (you->query("marry") == me->query("id") && you->query("id") == me->query("marry"))  {
			message_vision(HIG"\n$N��$n��Ŀ����һ�ۣ���Ȼ���������������ͷ������������������λð�ӳ�������\n\n"NOR,me,you);		
		}
	
	    skl_me=(int)me->query_skill("diesword",1);
        extra_me=(int)me->query_skill("diesword",1);        
        skl_you=(int)you->query_skill("shortsong-blade",1);
        extra_you= (int)you->query_skill("shortsong-blade",1);
        
        me->add_temp("apply/attack",skl_me);
        me->add_temp("apply/damage",extra_me);
        you->add_temp("apply/attack",skl_me);
        you->add_temp("apply/damage",extra_me);
 		        
        myname=me->name();
        yourname=you->name();
        targetname=target->name();
        sword=me->query_temp("weapon");

		msg=HIY"\n$N��$n�����ϱڣ�ʹ����һʽ���������Ρ���˿˿��ۣ���ˮ��©����"+targetname+HIY"նȥ�� \n\n";
       		msg+=HIC"����ǣţ�ǣ���Ӻ�Ů��\n"NOR;
        	msg+=HIY"$N���е�"+sword->name()+HIY"��תǧ�أ���ò�����"+targetname+HIY"��ǰһ����$n���е�"
                +blade->name()+HIY"����ɱ����ǰ�� "NOR;
		message_vision(msg,me,you);
		COMBAT_D->do_attack(you,target, TYPE_REGULAR," ");

        	msg=CYN"\n����ߪ���֣�����Ū���̡�\n";
        	msg+="$N���л�����ǰ�����־���һ���� \n"NOR;
        	COMBAT_D->do_attack(me,target,TYPE_REGULAR,msg);

        	msg=HIW"\n\n���ղ����£����������ꡣ\n";
        	msg+="$n���е�"+blade->name()+HIW"��ס��Σ�$N�˻�����һƬ��Ӱ����"+targetname+HIW"ȫ���������С�" NOR;
		message_vision(msg,me,you);
        	COMBAT_D->do_attack(me,target,TYPE_REGULAR," ");

        	msg=MAG"\n\n�Ӻ�����ǳ����ȥ������\n";
        	msg+="$n������§$N������������"+blade->name()+MAG"бб�ӳ���ֱȡ"+targetname+MAG"��Ҫ���� "NOR;
		message_vision(msg,me,you);
        	COMBAT_D->do_attack(you,target, TYPE_REGULAR," ");

        	msg=HIG"\n\nӯӯһˮ�䣬���������\n";
        	msg+="$n��$N������ͨ��һ��һ������������е����£����϶�Ϊһ��ֱ��"+targetname+HIG"��ȥ��"NOR;
		message_vision(msg,me,you);
        	COMBAT_D->do_attack(you,target, TYPE_REGULAR," ");
        	COMBAT_D->do_attack(me,target,TYPE_REGULAR," ");

        me->add_temp("apply/attack",-skl_me);
        me->add_temp("apply/damage",-extra_me);
        you->add_temp("apply/attack",-skl_me);
        you->add_temp("apply/damage",-extra_me);
        me->perform_busy(3);
        you->perform_busy(3);
        return 1;
}

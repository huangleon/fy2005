// - rewriten by neon 06-09-2002
// - new daojianruomeng
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target, object friend)
{
		string msg,yourname,myname,targetname;
        int skl_me, skl_you, extra_me, extra_you, k;
        object you, ob, sword, blade;		

		if(me->query("gender")!="����")
			return notify_fail("�̸赶���ġ��������Ρ����������ӷ�����\n");
			
		if(me->query_skill("shortsong-blade",1)<30)
        	return notify_fail("����������Ҫ30���Ķ̸赶����\n");
				
		
		if (!friend || friend == me)
			return notify_fail ("���������Ρ���Ҫ��ͬ��һ��ʹ�á�\n");
	
		you = friend;
		if ( you->team_member(me) 
			|| (!userp(me) && you->query("npc_team")==me->query("npc_team")))
		k = 1;
		if (!k)
			return notify_fail("ͬ�������������ͬһ�������С�\n");  
        
		if(you->query("gender")!="Ů��")	
			return notify_fail("���������Ρ�����һ��һŮ���ܹ�ʹ�á�\n");
        	
		if(!you->query_skill("diesword",1) 
			|| you->query_skill_mapped("sword") != "diesword") 
        	return notify_fail("ͬ��û����ϵ��书��\n");
        if(you->query_skill("diesword",1)<30)
        	return notify_fail("ͬ����Ҫ30��������������\n");
        if(!objectp(sword=you->query_temp("weapon"))) 
        	return notify_fail("ͬ������ý���\n");
        if(sword->query("skill_type") != "sword")
        	return notify_fail("ͬ������ý���\n");
        if(you->query("class")!="legend" && me->query("class")!="legend")
			return notify_fail("������һ���˱�������ѩ���Ӳ����á��������Ρ�\n");
		if (you->is_busy())
			return notify_fail("ͬ����æ�ţ�û������һ��ʩչ���������Ρ�\n");
        if (you->query_temp("till_death/lockup") || you->query_temp("is_unconcious")
        	|| you->query("force")< 50)
			return notify_fail("ͬ�������޷�ʹ���ؼ���\n");
		
        if (!target) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("���������Ρ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
        
		if(you == target )
        	return notify_fail(MAG"����ô�ݵ�������ģ�\n"NOR);
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
		if (you->query("marry") == me->query("id") 
			&& you->query("id") == me->query("marry"))  {
			message_vision(HIG"\n$N��$n��Ŀ����һ�ۣ���Ȼ���������������ͷ������������������λð�ӳ�������\n\n"NOR,me,you);		
		}
	
	    if (me->query("class") == "legend") {
	    	skl_me= me->query_skill("shortsong-blade",1);
    	} else
    		skl_me = 0;
    	extra_me = skl_me;
    	
    	if (you->query("class") == "legend") {
    		skl_you= you->query_skill("diesword",1);
    	} else
    		skl_you = 0;
        extra_you= skl_you;
        
        // The enable has to be lower than 3sword/3blade
        
        if (extra_me > 100) 	extra_me = 100;
        if (extra_you > 100) 	extra_you = 100; 
        
        me->add_temp("apply/attack",extra_me);
        me->add_temp("apply/damage",extra_me);     
        you->add_temp("apply/attack",extra_you);
        you->add_temp("apply/damage",extra_you);
 		        
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


        me->add_temp("apply/attack",-extra_me);
        me->add_temp("apply/damage",-extra_me);
        you->add_temp("apply/attack",-extra_you);
        you->add_temp("apply/damage",-extra_you);

        
        me->perform_busy(3);
        you->perform_busy(3);
        return 1;
}

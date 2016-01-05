// sillencer@fy4.com

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	object *ob;
    int i, skill, my_exp,his_exp, bonus,num, enhance, tt, crit;
    string msg, dot_owner, dir, index;

    if(me->query("class")!="knight")
    	return notify_fail("ֻ�п���ֵ��Ӳ��ܹ�ʹ��"+WHT"��������"NOR+"��\n");

	if (me->query_skill("dream-herb",1)<200 || me->query_skill("herb",1)<280)
		return notify_fail("����������Ҫ200���������廨����280���Ļ���ҩ����\n");

//	550 
    skill = me->query_skill("herb");
	bonus = me->query_skill("dream-herb",1);
	
	if(!me->is_fighting() ) 
       	return notify_fail("��������ֻ����ս����ʹ�á�\n");
		
		if( !target ) target = offensive_target(me);
		if( !target
		||	!target->is_character()
		||	!me->is_fighting(target) )
			return notify_fail("��������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
		
		dot_owner = file_name(me);
    	sscanf(dot_owner,"%s#%s",dir,index);
    	dot_owner = me->query("id")+ index;
    	
    	if (target->query_temp("dot/dream-herb/yjl/"+dot_owner))
    		return notify_fail("�����Ѿ��������µ������ˡ�\n");
			
    	if (userp(me)) 
    	{
    		if (me->query("force")<100)
    			return notify_fail("������Ҫ100��������\n");
    		me->add("force", -100);
    	}
    	
    	me->perform_busy(2);
    	
    	msg = HIW "$N������ת����ɫͻȻ��òҰ���ѩ����\n" NOR;
    	msg += HIW "$N"HIW"Ŀ�Ⱪ�����ͺ�һ����һ�������ж������������$n��ǰ��ȥ��\n"NOR;
    	
		message_vision(msg,me,target);
	
		me->add_temp("apply/herb",bonus*3);
		    	
		if (COMBAT_D->do_magic_attack(me, target, "herb", "kee", 0))
		{
			msg = WHT"$N����һ������ȴ�Ȼ���ˣ�������ɫ��ϸ�ۣ�$N�ֱ�һ������������һ����\n"NOR;
			message_vision(msg,target);
				
			msg = WHT"$N���˸���������ɫ�ֻҰ������֡�\n"NOR;
									
			// 275 + random(137)
			// -- 275*8 + random(1000) = 2200 + random(1000)	in 40 sec
			// 50% effect of canyunbi = 1100 + random(500) in 40 sec
				
			num = skill/2 + random(skill/4);
			num = num * (100+ F_ABILITY->check_ability(me,"poison_dmg",2)*2)/100;
			num = num/2;
						
			num = COMBAT_D->magic_modifier(me, target,"kee",num);
											
			target->receive_damage("kee",num, me);
			target->receive_wound("kee",num/2,me);
			me->receive_fulling("kee",num/2,me);
																
//			tt = 8 * (100 + F_ABILITY->check_ability(me,"poison_dur")*5)/100;
//			write("tt = " + tt + "\n");
			tt = 8;
						
			target->set_temp("dot/dream-herb/yjl/"+dot_owner,1);
			call_out("dot",4,me,target,tt,0, num,dot_owner, msg);
    	} else
    		message_vision(YEL"$N���һ����ȴ���ǿ��������$n�İ��㡣\n"NOR, target, me);
    	
    	me->add_temp("apply/herb",-bonus*3);
    	return 1;

}


void dot (object me, object enemy, int total, int count, int amount, string dot_owner, string msg)
{
		if (!me || !enemy || !enemy->is_fighting(me)) {
			if (enemy) {
				message_vision(WHT"$N����ɫ�����ָ�����������\n"NOR,enemy);
				enemy->delete_temp("dot/dream-herb/yjl/"+dot_owner);
			}
			return;
		}
	
		message_vision(msg,enemy);
		
		enemy->receive_damage("kee",amount,me);
		enemy->receive_wound("kee",amount/2,me);
		me->receive_fulling("kee",amount/4,me);
		count = count+1;
		if (count<total) 
			call_out("dot",4,me, enemy,total,count, amount, dot_owner,msg);
		else {
			message_vision(WHT"$N����ɫ�����ָ�����������\n"NOR,enemy);
			if (enemy) 
				enemy->delete_temp("dot/dream-herb/yjl/"+dot_owner);
		}
		return ;
}

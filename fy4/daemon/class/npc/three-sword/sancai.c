// silencer@fy4.com

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int single_perform(object target, object me);
string *style = ({
HIW"��غ���£���"+WHT"$N"+WHT"����һ��Ʋ������Ҳ��������յ�����������ֱָ$n��"NOR,
HIW"���º���������"+WHT"$N"+WHT"�Ųȵؼ�λ�����־�һָһ���������������һ�佣������$n��"NOR,
HIW"��ʱ�����򣭣�"+WHT"$N"+WHT"һ���ӳ�,���ƻ�����ƽƽ���棬�������飬���ƽ�����ʵ��"NOR,
HIG"\n������伪�ף���"+HIM"ɭɭ��Ӱ������裬���ۺ��ְ˷����ߣ�����Ѹ�׿�к���ִ�$n"+HIM"����Ҫ����\n"NOR});


int perform(object me, object target)
{
	string msg;
	int skill,extra,i,j,max_exp;
	object ob,*obs, *env, *myteam;

	if (userp(me))
		return notify_fail("ֻ���䵱���Ӳſ��Է������Ž���\n");	
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�����Ž���ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	
        if (!me->query_team()) { 
		single_perform(target, me);
               	return 1;
        	}
        	
	if (member_array(target,myteam=me->query_team())!=-1) 
		return notify_fail("�㲻�ܹ������ѡ�\n");
	
	obs = ({});
        env=all_inventory(environment(me));
        for (i=0;i<sizeof(env);i++) {
        	if (member_array(env[i],myteam)==-1) continue;
        	if (env[i]->is_busy()) continue;
        	if (env[i]->query_skill("three-sword",1)<50) continue;
        	if (env[i]->query_skill_mapped("sword") != "three-sword") continue;
         	if (!objectp(ob=env[i]->query_temp("weapon")))	continue;
        	if (ob->query("skill_type")!="sword") continue;        	
        	obs += ({ env[i] });
        	if (sizeof(obs)>=3) break;
        }
        
         
        if (sizeof(obs)<2) {
		single_perform(target, me);
               	return 1;
        }
        
        if(sizeof(obs) > 3 )
		return notify_fail("���Ž�����������ˣ���\n");
	
	skill=me->query_skill("three-sword",1);
	if (skill<50 || me->query_skill("changelaw",1)<50)
		return notify_fail("�������Ž���������Ҫ50�������Ž������׾���\n");
	
	
	message_vision(HIR+"\n\n$N"+HIR"���б���ֹ�ŵĳ������������߽�������������һƬ��Ļ����ʱ���������Ž���\n"NOR,me);
	
	for (i=0;i<sizeof(obs);i++) {
		if (obs[i]->query("combat_exp")>max_exp) 
			max_exp=obs[i]->query("combat_exp");
	}
	
	if (random(target->query("combat_exp"))<max_exp) {
		message_vision(BLU"$N"+BLU"��ʧɫ��ֻ��������Ӱ��ɽ����Х��ӿ�������������˷���������ֱ���ڸ���\n",target);
		if (target->query_busy()<1) target->start_busy(1);
	}
	
	for(i=0;i<sizeof(obs);i++)
        {
		msg = style[i];
		extra = obs[i]->query_skill("three-sword",1);
		obs[i]->add_temp("apply/attack", extra);
	        obs[i]->add_temp("apply/damage", extra);
		COMBAT_D->do_attack(obs[i],target, TYPE_PERFORM,msg);
		obs[i]->kill_ob(target);	
		obs[i]->add_temp("apply/attack", -extra);
		obs[i]->add_temp("apply/damage", -extra);
	}
	
	if (sizeof(obs)==3 && me->query_skill("changelaw",1)>=100) {
		msg=style[3];
		message_vision(msg,me,target);
		for (i=0;i<sizeof(obs);i++) { 
			obs[i]->add_temp("apply/attack", extra);
	        	obs[i]->add_temp("apply/damage", extra);
			COMBAT_D->do_attack(obs[i],target,TYPE_REGULAR," ");
			obs[i]->add_temp("apply/attack", -extra);
			obs[i]->add_temp("apply/damage", -extra);
		}
	}
	
	for (i=0;i<sizeof(obs);i++) {
		obs[i]->start_busy(2);
		if (obs[i]->query("class")!="wudang" && target->query_busy()<2)	
			target->stop_busy();
	}
	return 1;
}

int single_perform(object target, object me) {
        int skill,law,max_exp,n,i;
        string msg;
        
        skill=me->query_skill("three-sword",1);
        law=me->query_skill("changelaw",1);
        
        if (law>=215) n=4;
                else if (law>=195) n=3;
	        else if (law>=185) n=2;
	        else {
	        	tell_object(me,"�����������Ž���������Ҫ185�����׾���\n");
	        	return 1;
	        }
        
        if (skill<170) {
        	tell_object(me,"������������������Ҫ170�������Ž�����\n");
        	return 1;
        }
        
        message_vision(HIR"\n\n$N"+HIR"ͻȻ����������Ӱ�����ۺ��ְ˷����ߣ�����һ��֮�����������Ž���\n"NOR,me);
	
	max_exp=me->query("combat_exp");
		
	if (random(target->query("combat_exp"))<max_exp) {
		message_vision(BLU"$N"+BLU"��ʧɫ��ֻ����Ӱɽ����Х���������˷�����ֱ���ڸ���\n"NOR,target);
//		target->start_busy(1);
	} else {
		message_vision(YEL"$N"+YEL"���Ų�æ�����λζ������ǽ���֮���š�\n"NOR,target);
		me->perform_busy(2);
		return 1;
	}
	
	for(i=0;i<n;i++)
        {
		msg = HIR +  style[i] + NOR;
		me->add_temp("apply/attack", skill*2);
		me->add_temp("apply/damage", skill*3);
		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
		me->add_temp("apply/attack", -skill*2);
		me->add_temp("apply/damage", -skill*3);
	}

//	target->stop_busy();
	me->perform_busy(2);

	return 1;		                
}
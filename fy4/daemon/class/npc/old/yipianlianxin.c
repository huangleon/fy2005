// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object friend)
{
	string msg;
	int extra,i,j,k,extra_y;
	string *style = ({
BBLU+HIR "$N"BBLU+HIR"����$w"BBLU+HIR"ͻ����⣬����$n"BBLU+HIR"��$l��" NOR,
BBLU+HIY "$N"BBLU+HIY"����$w"BBLU+HIY"ͻ���ƹ⣬ֱȡ$n"BBLU+HIY"��$l��" NOR,
BBLU+HIW "$N"BBLU+HIW"����$w"BBLU+HIW"ͻ���׹⣬����$n"BBLU+HIW"��$l��" NOR,
BBLU+HIG "$N"BBLU+HIG"����$w"BBLU+HIG"ͻ���̹⣬ƽ��$n"BBLU+HIG"��$l��" NOR,
BBLU+HIB "$A"BBLU+HIB"����$W"BBLU+HIB"��$B"BBLU+HIB"���е�$V"BBLU+HIB"��֯��ϣ�����������������$n��" NOR,
});
	object ob,*obs, target;
	object you, *myteam;
	
	if (!friend)
		return notify_fail ("��Ҫ��˭һ��ʹ�á�һƬ���ġ�\n");	
	if (friend==me)
		return notify_fail ("һƬ������Ҫ��ͬ��һ��ʹ�á�\n");
	
	you = friend;                             
    myteam = me->query_team();
    	
	if ( you->team_member(me) || (!userp(me) && you->query("npc_team")==me->query("npc_team")))
		k = 1;
		
	if (!k)
		return notify_fail("ͬ�������������ͬһ�������С�\n");  
           
	if(!you->query_skill("lianxin-blade",1) || you->query_skill_mapped("blade") != "lianxin-blade") 
        	return notify_fail("ͬ��û����ϵ��书��\n");
     if(!objectp(ob=me->query_temp("weapon"))) 
        	return notify_fail("��û��ִ����\n");
	if(ob->query("skill_type") != "blade")
        	return notify_fail("��û��ִ����\n");
     if(!objectp(ob=you->query_temp("weapon"))) 
        	return notify_fail("ͬ��û��ִ����\n");
	if(ob->query("skill_type") != "blade")
        	return notify_fail("ͬ��û��ִ����\n");
	if (you->is_busy())
		return notify_fail("ͬ����æ���ء�\n");
	if (you->query_temp("is_unconcious"))
		return notify_fail("��ͬ���ѹ�����˵�ɡ�\n");
			
	target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��һƬ���ġ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
		
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
        
	message_vision( BBLU + HIC "\n$N"BBLU+HIC"��$n"BBLU+HIC"������ͻȻ��֯��һ��ԽתԽ�죡\n" NOR,me,you);

	target->set_temp("no_check_pfm_win",1);
	
	msg = style[0];
	
	extra = me->query_skill("lianxin-blade",1);
	extra_y = you->query_skill("lianxin-blade",1);
	
	
    me->add_temp("apply/attack", extra);
    me->add_temp("apply/damage", extra);
		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	target->set_temp("skip_damage_record",1);
		
	msg = style[1];
    
    you->add_temp("apply/attack", extra_y);
    you->add_temp("apply/damage", extra_y);
		COMBAT_D->do_attack(you,target, TYPE_PERFORM,msg);
	you->add_temp("apply/attack", -extra_y);
	you->add_temp("apply/damage", -extra_y);
	
	msg = style[2];
    me->add_temp("apply/attack", extra);
    me->add_temp("apply/damage", extra);
		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
	
	msg = style[3];
	extra = you->query_skill("lianxin-blade",1);
    you->add_temp("apply/attack", extra_y);
    you->add_temp("apply/damage", extra_y);
		COMBAT_D->do_attack(you,target, TYPE_PERFORM,msg);
	you->add_temp("apply/attack", -extra_y);
	you->add_temp("apply/damage", -extra_y);

		style[4] = replace_string(style[4],"$A", me->name());
        style[4] = replace_string(style[4],"$B", you->name());
        style[4] = replace_string(style[4],"$W", (me->query_temp("weapon"))->name());
        style[4] = replace_string(style[4],"$V", (you->query_temp("weapon"))->name());
	
        me->add_temp("apply/attack", extra);
        me->add_temp("apply/damage", extra);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,style[4]);
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);
	
		if (objectp(target))	{
			if (target->query_temp("damaged_during_attack")) 
				 COMBAT_D->win_lose_check(me,target,1);
		}
	
		if (objectp(target))	{
			target ->delete_temp("no_check_pfm_win"); 
			target->delete_temp("skip_damage_record");
		}

	
	me->perform_busy(3);
	you->perform_busy(3);
	return 1;
}

	
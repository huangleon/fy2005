// Silencer@fengyun	June.2005
// ����ʯΪ���������к���öԷ���Ѫ���У�2-SB,CDT = Dot time.
//	�ص㣺short self-busy, Dot bypass ���з���

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        string forceskill,msg, dot_owner,index,dir;
		int extra, tmp;
		object weapon;
		
		if (me->query("class") != "fugui")
			return notify_fail("����ʯΪ�����Ǹ�����ӵľ��С�\n");
		
		weapon=me->query_temp("weapon");
	 	extra = me->query_skill("xuezhan-spear",1);
		tmp = me->query_skill("skyforce",1);
	    	    	
	    if (tmp < 100 || extra < 100 )
	    	return notify_fail("����ʯΪ������Ҫ100����Ѫսǹ����100���ı̿��ķ�!\n");
	    	
		if( !target ) target = offensive_target(me);
		if( !target
		||	!target->is_character()
		||	!me->is_fighting(target) )
	        	return notify_fail("����ʯΪ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
             
    	dot_owner = file_name(me);
    	sscanf(dot_owner,"%s#%s",dir,index);
    	dot_owner = me->query("id")+ index;
    	
    	if (target->query_temp("dot/xuezhan-spear/jswk/"+dot_owner))
    		return notify_fail("�����Ѿ�������ġ���ʯΪ�����ˡ�\n");
    		
        me->add_temp("apply/attack", 100 + extra);    
        me->add_temp("apply/damage", tmp);
        msg = HIG"\n$N"HIG"����"+weapon->name()+HIG"����һ��������Ϊ��������ǹ�������ߣ��Ҵ����ǰɨ�أ������ȣ�
�ϵ�ü����������ٿ����ʱٿ���ģ�Խ��Խ�ݣ�Խ��Խ�죡\n" NOR;
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
        me->add_temp("apply/attack", -100 - extra);
        me->add_temp("apply/damage", -tmp);
        
        if (target->query_temp("damaged_during_attack"))
        {
        	message_vision(WHT"$N"WHT"ǹ��΢΢����������͸��$n�˴���\n"NOR, me, target);
        	target->set_temp("dot/xuezhan-spear/jswk/"+dot_owner,1);
        	call_out("dot",4,me,target,3,0,extra,dot_owner);
        }
                
        me->perform_busy(1); 
        return 1;
}

void dot (object me, object enemy, int total, int count, int skill,string dot_owner)
{
	int num;
	if (!me || !enemy || !enemy->is_fighting(me)|| environment(me)!= environment(enemy)) {
		if (enemy) {
			tell_object(enemy, YEL"����˿�Ѫ��������\n"NOR);
			enemy->delete_temp("dot/xuezhan-spear/jswk/"+dot_owner);
		}
		return;
	}
	message_vision(RED"$N���ϵ��˿ں�Ȼ���ѿ�����Ѫˮ�ɽ���\n"NOR,enemy);
	
	// 3 times, 
	// num = 20 + 250/3 + 90/2 + 48 = 196, 	
	// Ability 196*130% = 254
	
	num = 20 + skill/3 + me->query("force_factor")/2 + me->query("level")/3;		
	num = num * ( 100 + F_ABILITY->check_ability(me,"jswk_add")*3)/100;
	
	num = COMBAT_D->magic_modifier(me, enemy, "kee", num);	
	enemy->receive_damage("kee",num,me);
	count = count+1;
	if (count<total) call_out("dot",4,me, enemy,total,count, skill,dot_owner);
	else {
		tell_object(enemy, YEL"����˿�Ѫ��������\n"NOR);
		enemy->delete_temp("dot/xuezhan-spear/jswk/"+dot_owner);
		return;
	}
	return ;
}

//libie.c
// - neon

/*    
��Ȼ�����ߣ�Ψ������ӣ�
......

���±ڶ����ʣ����������ɹ⡣
������֮��¶�������֮��˪��
Ѳ��麶����ڣ�����Ļ��������
֪����֮�������֮���
...

�ʱ���һ�����������塣
...

���������������������ᣬ�����������Ϳͽ�ȡ�
����������ĳ£��ࡢ�Ը��������ˣ�
����������ĺ�������⽿�ϴ���
������֮��������Ԩ��֮���ۡ�����ֶ����飬�м�į������
...

�������ǧ�ϧ����֮ͽ����
���Ĺ�֮��ɪ���޸�̨֮���ơ�
�����մ���̦ɫ�����ʺ������¹⣬
���������粻ĺ����������ҹ�γ���
֯���������Ѿ�������ʫ��Ӱ���ˡ�

...

���Ա𷽲���������ǧ�����б��Թ����Թ��ӯ��
ʹ������񺧣����۹Ǿ�����Ԩ����֮ī��ϡ���֮�ʾ���
���֮���壬��̨֮ȺӢ����������֮�ƣ����е���֮����
˭��ġ����֮״��д����֮���ź���

...
*/

// ��Ȼ������Ψ�����		self-busy 3, every 5mins it's a dmg: = 2500-3000 potential pfm, and you break a leave hook.

#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int libie_sword(object me,object target,int extra,object weapon);
int perform(object me, object target)
{
	string msg, weather,wname;
	int extra,skill, damage,d;
	object weapon;

	// 2.5x150 = 375
	if (me->query_skill("xiaohun-sword",1)<120)
		return notify_fail("�����Ҫ120������Ȼ���꽣����\n");
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail(MAG"������"NOR"ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	//	475 -- 525 + 150 = 625 
	extra = me->query_skill("sword") + F_LEVEL->get_level(me->query("combat_exp"));
	weapon = me->query_temp("weapon");

	//	I: atk+130  dmg 160
	me->add_temp("apply/attack", extra/5);	
	me->add_temp("apply/damage", extra/4);
	msg = HIC"$N����"+ weapon->name()+ HIC"�������ǰ�Ĺ�â�������ա�����\n"
HIW "��â��̴٣��������Ѿ�û���ǹ��ܱ��������ã��Իͣ�����\n"NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	me->add_temp("apply/attack", -extra/5);
	me->add_temp("apply/damage", -extra/4);
	
	
	if (
		(!REWARD_D->check_m_success(me,"���괫��") || me->query("timer/libie")+300> time()))
	{	
		me->perform_busy(3);
		return 1;
	}
	
	if (userp(me))
	if (weapon->query("id") != "leave hook"){
		me->perform_busy(3);
		return 1;
	}
		
	me->set("timer/libie",time());
	
	target->set_temp("combat_no_report",1);
	
//	attack II, atk = 310,dmg = 625	
	
	msg = WHT"\n\n��â��ȥ֮��$n"NOR+WHT"��ǰ��Ȼ���ֳ�������Ҷ�£���ʼ�Զȥ�Ĺ·���
һʱ���г������������ļ�į����ʹ��";
	msg += YEL"\n\n$N����" + weapon->name() + YEL"����������������������֮����
��ʯ���ɫ�䣬���Ɐ��������\n"NOR;
	message_vision(msg,me,target);	
	
	target->delete_temp("last_damage_from");
		
	me->add_temp("apply/attack",extra/2);
	me->add_temp("apply/damage",extra);

    COMBAT_D->do_attack(me,target,TYPE_PERFORM,"");
	me->add_temp("apply/attack",-extra/2);
	me->add_temp("apply/damage",-extra);

//	attack III, atk=310, dmg = 625

    msg = HIB"\n������һƬ���ţ��紵��ľ��������û�У�Ҳ���Ƿ�����ʹ��������"NOR;
    msg += HIG"\n\n$N����" + weapon->name() + HIG"��Ȼ�����������������Ʈ�� . . . 
˭���������е�����֮״������֮���أ�\n"NOR;	    
	message_vision(msg,me,target);

	target->set_temp("no_check_pfm_win",1);
	me->add_temp("apply/attack",extra/2);
	me->add_temp("apply/damage",extra);
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
	me->add_temp("apply/attack",-extra/2);
	me->add_temp("apply/damage",-extra);
	target->delete_temp("no_check_pfm_win");

//  attack IV  sen damage, need previous hit + leave hook	
	if (!target->query_temp("damaged_during_attack"))
	{
		message_vision(HIR"\n$N��Ȼ�����������Ʈ翣����α���Ľ�Ӱ�м��������� \n"NOR,target);
	}	
	else {
        	message_vision(HIW"\n\n\n     ��  Ȼ  ��  ��  �� �� Ψ  ��  ��  ��  ... ...  \n\n"NOR,me);
        	damage = COMBAT_D->magic_modifier(me, target, "sen", extra*2);
            		
    		target->receive_wound("sen",damage, me);
    		me->receive_damage("kee", damage, me);
    		me->receive_wound("kee", damage, me);
    		
			me->set_temp("last_damage_from","�����ң�����������\n");
       		
       		if (userp(me)) {
	       		msg = HIY "\nֻ������ž����һ����$N���е�" + weapon->name() + HIY"�ھ������Ѿ���Ϊ���أ�\n"NOR;
	
				weapon->set("orig_name", weapon->query("name"));
				wname = replace_string( weapon->name(), "�ϵ���", "");
				weapon->set("name", "�ϵ���" + wname);
				d = weapon->query("weapon_prop/damage") - 1;
				weapon->set("weapon_prop/damage",1);
				me->add_temp("apply/damage",-d); 
				if (weapon->query("owner")) {
					weapon->save();
				}
				else {
					weapon->unequip();
					weapon->set("weapon_prop", 0);
					weapon->set("value", 0);
				}
	
	          	msg += YEL"\n$Nǿ������������Ľ�����Ȼ�ӶϽ��ȳ�... \n";
	          	msg += MAG"\n\n���Ǽ�������ţ�$n"MAG"ͻ������������ζ��һ�����ӿ����ͷ��\n\n"NOR;
	            message_vision(msg,me,target);	    		    	
			}
	}

	COMBAT_D->report_status(target,1);
	target->delete_temp("combat_no_report");
	me->perform_busy(3);
	return 1;
}

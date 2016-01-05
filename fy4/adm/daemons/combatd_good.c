// combatd.c
// Copyright (C) 1995 - 2006, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//
// Last modification:
//		- 10/12/2002 by love
//			* add items' hit_ob,parry_ob,dodge_ob
//		- 10/20/2002 by silencer
//			* fixed double calculation in apply/dodge, move ..
//			* a new modification of armor, now it can absorb some damage!
//			* remove unnessary codes such as NPC exp+1.
//		- 12/2002 by silencer
//			* added various 4.1 function
//			* added one function legitimate_kill() to monitor all PK action.			
//		- 07/02-2003 by annie
//			** added 'buff/no_abs' to ignore victim' iron-cloth
//			** added various 4.1 function ; snicker,point 'extra_action'
//		- 07/03/2003 by annie
//			** change extra_action' func,allow ppl to do multi-strike.
//		- 07/16/2003 by silencer
//			** added magic_modifier() to control all spells/magic damage.
//			** removed lots of unnecessary codes.
//			** add ob_hit()... 
//			** restriction on protector.
//		- 07/25/2003 by annie
//			** added 'evasion' , allow ppl to dodge an attack
//			** modified 'dodge_attack' func,trans attack_type as a param.
//		- 08/24/2003 by annie
//			** new creature type: element(wall)
//			** no more hit_ob@weapon when attack elements.
//		- 08/31/2003 by annie
//			** Change ob_hit@npc.
//		- 10/30/2003 by annie
//			** added multi-target action,attack all enemies in a normal-hit.
/*		- 07/2004 by Silencer
			** added do_magic_attack() and do_busy_attack()
			** removed unarmed/weapon difference in parry attack, 
*/

/*		debug env

set combat0	verbose		Show enemy's atk
set combat1 verbose 	Show self atk
set combat2 verbose		Show damage information
set combat_s verbose	Show magic information
set combat_b(2) verbose	Show busy perform information

*/

#pragma optimize all

#define LOWER_LIMIT 2000
#define UPPER_LIMIT 2047483647
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
#include <dbase.h>

//	COMBATD�������ܣ�
//	��һ���ṩ��heart_beat->attack()->���õ�fight()������
//	�ڶ����ṩ����򶷵ĺ��������á�
//	** ע��: ��ֵ����= 2^31-1 = 2147483647 === 2 x 10E+9

void auto_fight(object me, object obj, string type);	// ��init()���õ������򶷴���
void fight(object me, object victim);			// ��heart_beat���õĴ������� 
varargs int do_attack(object attacker, object victim, int attack_type, mixed att_msg, string damage_type);
							// ��fight()������ֱ�ӵ��õĹ�������
varargs int do_magic_attack(object attacker, object victim, string skill, string attack_type, int enhance);				
int do_busy_attack(object attacker, object victim, string skill, string type, int enhance, int mod);
							// ��perform���õķ�����������
							
string damage_msg(object victim,int damage, string type); 		// ���˶����˺�ֵ��Ӧ��Ϣ
string eff_status_msg(int ratio, int dam_type);				// ��Ч������״̬��Ϣ
string status_msg(int ratio, int dam_type); 				// ������״̬��Ϣ
varargs void report_status(object ob, int i); 				// ����ob��״̬��Ϣ��

string prepare_final_message(object attacker, object victim,string w_name, string vw_name,mapping action, string result);
							// �滻����ս������ʾ��Ϣ	 

int skill_power(object ob, int usage);			// �����ܵȼ�������ֵ������״�������������㹥����move/dodge��

void fight_reward(object winner, object loser);
void fight_penalty(object winner, object loser);	// ս�����������object�п��ܴ��ڵ�ʤ������


int attack_damage(object attacker, mapping action, object victim);	
							// �ӹ����ߵ�����(��������)���������˺����� 
varargs int inflict_damage(object attacker, object victim, int damage, mapping action, string damage_type);
							// �ӷ��ط������ԣ�iron-cloth,armor�������������˺�����

int dodge_attack(object attacker, int ap, mapping action, object victim, int attack_type); 	//��dodgeô��
int parry_attack(object attacker, int ap, mapping action, object victim);			//��parryô��
varargs int counter_attack(object attacker, int ap, mapping action, object victim,int i);	//�ܷ���ô��
int do_protect(object attacker, int ap, mapping action, object victim);				//���˱���ô��
mapping get_action(object me, int attack_type);							//��skill�ļ���ȡһ����������

void win_lose_check(object attacker, object victim, int damage);		//��Ӯ�ж�
void auto_follow(object follower, object leader);				//����
void announce(object ob, string event);						//������Ϣ
void winner_reward(object killer, object victim);				//��Ӯ��Ϣ
void loser_penalty(object killer, object victim);				//��Ӯ��Ϣ
void killer_reward(object killer, object victim);				//ɱ�˽���--Quest�ȶ��ڴ˵���
varargs void victim_penalty(object victim, mixed killer,int flag); 		//�����ͷ�--��/feature/damage/die()����
int legitimate_kill(object attacker, object victim);				//����Ƿ���������У�麯��
int can_busy(object attacker, object victim, string skill);			//������BUSY perform ������������
int critical_strike(object me,object who);					//�� critical strike ���жϡ�	
int magic_modifier(object attacker, object victim, string type, int damage);    // 

string ngstr(string str);		// msg color parser
					
string *guard_msg = ({
	CYN "$N"NOR CYN"ע����$n"NOR CYN"���ж�����ͼѰ�һ���һ���ɹ���\n" NOR,
	CYN "$N"NOR CYN"������$n"NOR CYN"��һ��һ������ʱ׼���������ơ�\n" NOR,
	CYN "$N"NOR CYN"����Ϊ������Ҫ�ҳ�$n"NOR CYN"��������\n" NOR,
	CYN "$N"NOR CYN"�������ƶ��ŽŲ����ȴ�����ѵĳ��з�λ��\n" NOR,
	CYN "$N"NOR CYN"�۾�գҲ��գ�ض���$n"NOR CYN"���Ż����֡�\n" NOR,
});

string *catch_hunt_msg = ({
	HIW "$N"HIW"��$n"HIW"������������ۺ죬���̴���������\n" NOR,
	HIW "$N"HIW"����$n"HIW"��ȣ����ɶ������㣡��\n" NOR,
	HIW "$N"HIW"��$n"HIW"һ���棬������˵�ʹ���������\n" NOR,
	HIW "$N"HIW"һ��Ƴ��$n"HIW"�����һ�����˹�����\n" NOR,
	HIW "$N"HIW"һ����$n"HIW"�����һ㶣���У����������㣡��\n" NOR,
	HIW "$N"HIW"�ȵ�����$n"HIW"�����ǵ��ʻ�û���꣬���У���\n" NOR,
	HIW "$N"HIW"�ȵ�����$n"HIW"�����У���\n" NOR,
});

string *winner_msg = ({
	CYN "\n$N"NOR CYN"������Ц��˵���������ˣ�\n\n" NOR,
	CYN "\n$N"NOR CYN"˫��һ����Ц��˵�������ã�\n\n" NOR,
	CYN "\n$N"NOR CYN"ʤ�����У�����Ծ�����ߣ�Ц�������ã�\n\n" NOR,
	CYN "\n$n"NOR CYN"��ɫ΢�䣬˵��������������\n\n" NOR,
	CYN "\n$n"NOR CYN"�������˼�����˵�����ⳡ�����������ˣ�����������\n\n" NOR,
	CYN "\n$n"NOR CYN"����һ�ݣ�������Ҿ˵�����������ղ�������Ȼ������\n\n" NOR,
});

string *counter_msg = ({
	HIR "$N"HIR"ȫȻ����$n"HIR"�Ĺ������Կ��ƿ졣\n" NOR,
	HIR "$N"HIR"�����Ա��������������ϡ�\n" NOR,
});

string *block_msg = ({
	YEL "$n"NOR YEL"�ּ��ۿ죬����$s"NOR YEL"һ�񣬵�ס��$N"NOR+YEL"�Ĺ��ơ�\n" NOR,
	YEL "$n"NOR YEL"������ף�����$s"NOR YEL"���棬�ܹ���$N"NOR+YEL"�Ĺ��ơ�\n" NOR,
	YEL "$n"NOR YEL"��$s"NOR YEL"��ķ糵Ҳ�ƣ�Ӳ�Ǹ���$N"NOR+YEL"�Ĺ�����\n" NOR,
});


object protector;
int attacker_damage = 0;
int victim_damage = 0;
int protector_damage = 0;
string parry_message = "";
string dodge_message = "";
string protect_message = "";
string counter_message = "";
string damage_message = "";
string inflict_message = "";
string result_message = "";

void create() {
	seteuid(ROOT_UID);
}

string damage_msg(object victim,int damage, string type) {
	string str;

	if(damage <= 0) {
		return "���û������κ��˺���\n";
	}

	if (victim->query("race") == "Ԫ��")
	{
			if(!type) type = "�˺�";
			if(damage < 25) str =  "���ֻ����ǿ���һ����΢";
			else if( damage < 50 ) str = "��������΢��";
			else if( damage < 100 ) str = "������һ��";
			else if( damage < 200 ) str = "������һ������";
			else if( damage < 300 ) str = "��������Ϊ���ص�";
			else if( damage < 400 ) str = "�������൱���ص�";
			else if( damage < 600 ) str = "������ʮ�����ص�";
			else if( damage < 800 ) str = "�����ɼ������ص�";
			else str =  "�����ɷǳ����µ�����";
			return str + type + "��\n";
	}

	switch( type ) {
		case "����":
		case "����":
			if( damage < 100 ) 	return "���ֻ������ػ���$n��Ƥ�⡣\n";
			else if( damage < 200 ) return "�����$n��$l����һ��ϸ����Ѫ�ۡ�\n";
			else if( damage < 400 ) return "������͡���һ������һ���˿ڣ�\n";
			else if( damage < 600 ) return "������͡���һ������һ��Ѫ���ܵ��˿ڣ�\n";
			else if( damage < 1000 )return "������͡���һ������һ���ֳ�������˿ڣ�����$N������Ѫ��\n";
			else return "���ֻ����$nһ���Һ���$w����$n$l����һ������ǵĿ����˿ڣ���\n";
			break;
		case "����":
			if( damage < 100 ) 	return "���ֻ������ش���$n��Ƥ�⡣\n";
			else if( damage < 200 ) return "�����$n$l�̳�һ�����ڡ�\n";
			else if( damage < 400 ) return "������ۡ���һ��������$n$l����\n";
			else if( damage < 800 ) return "������ۡ���һ���̽�$n��$l��ʹ$p�������������˼�����\n";
			else if( damage < 1000 ) return "��������͡���һ����$w����$n$l�̳�һ��Ѫ��ģ����Ѫ������\n";
			else return "���ֻ����$nһ���Һ���$w����$n��$l�Դ���������Ѫ�������أ���\n";
			break;
		case "����":
		case "����":
			if( damage < 50 ) 	return  "���ֻ����������������Ĳ�Ӭ��΢���˵㡣\n";
			else if( damage < 100 ) return "�����$n��$l���һ�����ࡣ\n";
			else if( damage < 200 ) return "���һ�����У�$n��$l��ʱ����һ���ϸߣ�\n";
			else if( damage < 400 ) return "���һ�����У�$n�ƺ���һ����Ȼ���˲�С�Ŀ���\n";
			else if( damage < 600 ) return "������项��һ����$n����������\n";
			else if( damage < 800 ) return "�����һ�¡��项��һ�����$n�����˺ü�������һ��ˤ����\n";
			else if( damage < 1000 ) return "������صػ��У�$n���ۡ���һ���³�һ����Ѫ��\n";
			else return "���ֻ�������项��һ�����죬$n��һ�����ݰ���˳�ȥ����\n";
			break;
		case "����":
			if( damage < 50 ) 	return  "���ֻ��������ߵ������Ĳ�Ӭ��΢���˵㡣\n";
			else if( damage < 100 ) return "�����$n��$l���һ�����ࡣ\n";
			else if( damage < 200 ) return "���һ�����У�$n��$l��ʱ����һ���ϸߣ�\n";
			else if( damage < 400 ) return "���һ�����У�$n�ƺ���һ����Ȼ���˲�С�Ŀ���\n";
			else if( damage < 600 ) return "������项��һ����$n����������\n";
			else if( damage < 800 ) return "�����һ�¡��项��һ���ߵ�$n�����˺ü�������һ��ˤ����\n";
			else if( damage < 1000 ) return "������ص����У�$n���ۡ���һ���³�һ����Ѫ��\n";
			else return "���ֻ�������项��һ�����죬$n��һ�����ݰ���˳�ȥ����\n";
			break;
		case "ץ��":
			if( damage < 50 ) 	return "���ֻ�������ץ������ץ����΢���˵㡣\n";
			else if( damage < 100 ) return "�����$n��$lץ������Ѫ�ۡ�\n";
			else if( damage < 200 ) return "���һץ���У�$n��$l��ץ����Ѫ�ɽ���\n";
			else if( damage < 400 ) return "�����һ��ץ��$n���κü��£���һ��ˤ������\n";
			else if( damage < 600 ) return "���һץ���У�$n��$l��ץ��Ѫ���ɣ�����\n";
			else if( damage < 800 ) return "������͡���һ����$l��ץ����ɼ��ǣ���\n";
			else if( damage < 1000 ) return "���$n����һ����$l��ץ�ý�Ϲ��ۣ���\n";
			else return "���ֻ����$nһ���Һ���$l��ץ�����Ѫ��������Ѫ�������أ���\n";
			break;
		case "����":
	                if (damage < 50)  	return "���ֻ����$n��Ƥ����������������ֻ���Ƶ�Ƥ��\n"; 
	                else if (damage < 100)  return "�����$n$l���һ����΢���Ϻۡ�\n"; 
	                else if (damage < 200)  return "�����ž����һ����$n$l���һ��������Ѫ�ۣ�\n"; 
	                else if (damage < 400)  return "���ֻ����ž����һ����$n���κü��£���һ��ˤ����\n"; 
	                else if (damage < 600)  return "���$p��$l�ϱ�����һ��Ѫ���ܵĴ��ڣ�\n"; 
	                else if (damage < 800) return "���ֻ����ž����һ����$n��$l�����Ƥ��������ʹ��$pҧ���гݣ�\n"; 
	                else if (damage < 1000) return "�����ž����һ�����죡��һ�º�������ֻ���$nƤ��������Ѫ���ɽ���\n"; 
	                else return "���ֻ����$nһ���Һ���$w���صس�����$p��$l��$n��ʱѪ���ɣ�ʮ�����˾�����\n";
	                break;
		case "��Ѩ":
	                if (damage < 50)  	return "���ֻ�����������$n��$l������û�е㵽Ѩ����\n"; 
	                else if (damage < 100)  return "���$nʹ��һ������$p��$l���һ�����ࡣ\n"; 
	                else if (damage < 200) 	return "���һ�����У�$N������$n$l�ϵ�Ѩ����$nֻ��һ����ľ��\n"; 
	                else if (damage < 400) 	return "���$n�ƺ���һ��������һ����һ��ף���ʱ����$l��ľ��\n"; 
	                else if (damage < 800) 	return "���$n��ɫһ�±�òҰף���$N����$l��Ѩ��,һ����ʹ�鲼����$l��\n"; 
	                else if (damage < 1000) return "���$nһ����У�$l��Ѩ��������,��ʹֱ���ķΣ�\n"; 
	                else return "���ֻ����$nһ���ҽУ�һ���ʹ�����������α�ȫ������ֱͦͦ�ص�����ȥ��\n";
	                break;
	        case "����":
	                if (damage < 50)  	return "���ֻ�ǰ�$n������˰벽�����������ˡ�\n"; 
	                else if (damage < 100)  return "���$nʹ��һ������$p��$l���һ�����ˡ�\n"; 
	                else if (damage < 200)  return "���һ�����У���$n���ʹ��������ȥ��\n"; 
	                else if (damage < 400)  return "���$n�ƺ���һ��������һ����һ��ף���Ȼ���˵����ˣ�\n"; 
	                else if (damage < 600)  return "���$n��ɫһ�±�òҰף��������������˺ü�����\n"; 
	                else if (damage < 800) return "������صػ��У�$n���ۡ���һ���³�һ����Ѫ��\n"; 
	                else if (damage < 1000) return "������䡹��һ����$nȫ����Ѫ������������Ѫ���������\n"; 
	                else return "���ֻ���������������죬$nһ���ҽУ���̲�����������ȥ����\n";
	                break;
		case "����":
	                if (damage < 50)  	return "���ֻ����������������Ǹ�$nɦ��һ������\n"; 
	                else if (damage < 100)  return "�����$n��$l�ҳ�һ��С������\n"; 
	                else if (damage < 200) 	return "���$N��һ���Ҹ����ţ�$n��$l��ʱ����һ���ϸߣ�\n"; 
	                else if (damage < 400) 	return "���$N��һ���Ҹ����ţ�$n�ƺ�һ����Ȼ���˲�С�Ŀ���\n"; 
	                else if (damage < 600) 	return "���ֻ�����项��һ����$n�۵�����������������\n"; 
	                else if (damage < 800) return "�����һ�¡��䡹��һ���ҵ�$n��ð���ǣ���һ��ˤ����\n"; 
	                else if (damage < 1000) return "������ص����У�$n��ǰһ�ڣ����ۡ���һ���³�һ����Ѫ��\n"; 
	                else  return "���ֻ�������䡹��һ�����죬$n���ҵ�Ѫ��ģ�����Ҳ��̶ã�\n";
	                break;
		case "������":
			if( damage < 5 ) 	return "$N�ܵ�$n$z�ķ����ƺ�һ����\n";
			else if( damage < 10 ) 	return  "$N��$n��$z�����Ѫ���ڣ���ʧɫ��\n";
			else if( damage < 20 ) 	return "$N��$n��$z���վ�����ȣ�ҡҡ�λΡ�\n";
			else if( damage < 40 ) 	return "$N��$n��$z���𣬡��١���һ������������\n";
			else if( damage < 80 ) return "$N��$n��$z����������������ð����顣\n";
			else if( damage < 120 ) return "$N��$n��$z������һ���ؿ������ܵ�һ���ػ�����������������\n";
			else if( damage < 160 ) return "$N��$n��$zһ����ǰһ�ڣ���������ɳ�������\n";
			else return "$N��$n��$zһ����ǰһ�ڣ�������Ѫ������������ߵķ��������ȥ����\n";
			break;
		default:
			if(!type) type = "�˺�";
			if(damage < 50) str =  "���ֻ����ǿ���һ����΢";
			else if( damage < 100 ) str = "��������΢��";
			else if( damage < 200 ) str = "������һ��";
			else if( damage < 400 ) str = "������һ������";
			else if( damage < 500 ) str = "��������Ϊ���ص�";
			else if( damage < 600 ) str = "�������൱���ص�";
			else if( damage < 800 ) str = "������ʮ�����ص�";
			else if( damage < 1000 ) str = "�����ɼ������ص�";
			else str =  "�����ɷǳ����µ�����";
			return str + type + "��\n";
		}
}

//dam_type, kee:1 sen:2 gin:3, default =1
string eff_status_msg(int ratio, int dam_type) {
	if( ratio==100 ) return HIG "�������ϲ���˿���˺ۡ�" NOR;
	if( ratio > 95 ) return HIG "�ƺ�ֻ���˵����ˣ������˴��塣" NOR;
	if( ratio > 90 ) {
		if (dam_type == 3)
			return HIY "������Щή�ң�����������" NOR;
		else if (dam_type == 2)
			return HIY "�����ƺ�����Щ���ˣ������е㽩Ӳ��" NOR;
		else  	return HIY "�������˼���Ƥ���ˡ�" NOR;
	}
	if( ratio > 80 ) return HIY "���˼������ˣ��ƺ��������¡�" NOR;
	if( ratio > 60 ) {
		if (dam_type == 3)
			return HIY "������飬���ύ����" NOR;
		else if (dam_type == 2)
			return HIY "�����Ȼ�������о�Ȼ����Ѫ������" NOR;
		else  	return HIY "�������˲��ᣬ��������Ѫ��" NOR;
	}
	if( ratio > 40 ) {
		if (dam_type == 3)
			return HIY "�沿�鴤��ֹ���Ѿ������Լ���" NOR;
		else    return HIR "��Ѫ��ֹ������ɢ�ң��Ѿ���������·�ˡ�" NOR;
	}
	if( ratio > 30 ) return HIR "�˺����ۣ���������֧����������ȥ��" NOR;
	if( ratio > 20 ) return HIR "�������ˣ�ֻʣ�����һ�����ˡ�" NOR;
	if( ratio > 10 ) return RED "����ԡѪ����Ҫ���ڵ��ϡ�" NOR;
	if( ratio > 5  ) return RED "ͫ�׷Ŵ��Ѿ�����һϢ�����ڵ�Ϧ�ˡ�" NOR;
	return RED "����в�����ʱ�����ܶ�����" NOR;
}

//dam_type, kee:1 sen:2 gin:3, default =1
string status_msg(int ratio, int dam_type) {
	if( ratio==100 ) return HIG "�������棬�������㣬" NOR;
	if( ratio > 95 ) return HIG "�ƺ���Щƣ����������Ȼʮ���л�����" NOR;
	if( ratio > 90 ) return HIY "������������Щ���ã�" NOR;
	if( ratio > 80 ) {
		if (dam_type == 3)
			return HIY "�����е㲻�㣬���Թ��ش��ݣ�" NOR;
		else if (dam_type == 2)
			return HIY "������Щ��㱣�����Ӧ�����磬" NOR;
		else  	return HIY "�����е㲻̫��⣬�����������ɣ�" NOR;
	}
	if( ratio > 60 ) {
		if (dam_type == 3)
			return HIY "�ж���Ȼ�ް����������Ը������ˣ�" NOR;
		else if (dam_type == 2)
			return HIY "��Ӧ��ʼ�ٻ���˫Ŀ����" NOR;
		else  	return HIY "�������꣬��ɫ�Ұף�" NOR;
	}
	if( ratio > 40 ) {
		if (dam_type == 3)
			return HIR "������ɢ���ƺ���ʹ����ʧȥ֪����" NOR;
		else if (dam_type == 2)
			return HIR "�۹����룬����������" NOR;
		else  	return HIR "�ƺ�ʮ��ƣ����������Ҫ�ú���Ϣ�ˣ�" NOR;
	}
	if( ratio > 30 ) return HIR "ͷ�ؽ��ᣬ��������֧����������ȥ��" NOR;
	if( ratio > 20 ) {
		if (dam_type == 3)
			return HIR "�����Ѿ���ľ�����ˣ�" NOR;
		else if (dam_type == 2)
			return HIR "�������Ѿ��겻�����ˣ�" NOR;
		else  	return HIR "�������Ѿ����������ˣ�" NOR;
	}
	if( ratio > 10 ) return RED "ҡͷ���ԡ�����бб�������ε���" NOR;
	return RED "�Ѿ���������״̬������ȫʧ��" NOR;
}

varargs void report_status(object ob, int i) {
	int eff_ratio = 100;
	int ratio = 100;
	int k_stat, g_stat, s_stat;
	int d_type = 1;
	int e_type = 1;
	string *msg = ({RED,HIR,HIY,HIG,HIG});

	k_stat = (int) ob->query("kee") * 100 / (int)ob->query("max_kee");
	s_stat = (int) ob->query("sen") * 100 / (int)ob->query("max_sen");
	g_stat = (int) ob->query("gin") * 100 / (int)ob->query("max_gin");

	if (ratio > k_stat ) {
		ratio =  k_stat;
	}
	if (ratio > s_stat ) {
		ratio =  s_stat;
		d_type = 2;
	}
	if (ratio > g_stat ) {
		ratio =  g_stat;
		d_type = 3;
	}

	k_stat = (int) ob->query("eff_kee") * 100 / (int)ob->query("max_kee");
	s_stat = (int) ob->query("eff_sen") * 100 / (int)ob->query("max_sen");
	g_stat = (int) ob->query("eff_gin") * 100 / (int)ob->query("max_gin");

	if (eff_ratio > k_stat ) {
		eff_ratio =  k_stat;
	}
	if (eff_ratio > s_stat ) {
		eff_ratio =  s_stat;
		e_type = 2;
	}
	if (eff_ratio > g_stat ) {
		eff_ratio =  g_stat;
		e_type = 3;
	}

	if (ob->query("race") != "Ԫ��")
	{
		message_vision("( $N" + status_msg(ratio, d_type) + eff_status_msg(eff_ratio, e_type) + " )\n", ob);
	}
	else
	{
		ratio = (int) ob->query("kee") * 100 / (int)ob->query("max_kee");
		eff_ratio = (int) ob->query("eff_kee") * 100 / (int)ob->query("max_kee");
		if (ratio < 0)	ratio = 0;
		if (eff_ratio < 0)	eff_ratio = 0;
		// elements immune to gin/sen damage.
		message_vision("( $N" + msg[ratio/25]+"������"+(100-ratio)+"%��"+msg[eff_ratio/25]+"�ѱ���" + (100-eff_ratio)+"%��"NOR" )\n", ob);
	}

}


// This function calculates the combined skill/combat_exp power of a certain
// skill. This value is used for A/(A+B) probability use.
int skill_power(object ob, int usage) {
	int status, level, enc, max_enc, result;
	int bonus, exp;
	string skill, skill_log;
	object weapon;
	string wptype,pski;

	// Check for the total weight a player is carrying.
	// Skill power will descrease as you carry more things.
	// NPC does not have this restrication.
	if(!userp(ob)) {
		enc = 10;
	} else {
		max_enc = (int)ob->query_max_encumbrance();
		max_enc = max_enc > 0 ? max_enc : 1;
		enc = (max_enc  + max_enc/10 - 1 - (int) ob->query_encumbrance() ) * 10 / max_enc;
	}

	level = 1;
	switch(usage) {
		case SKILL_USAGE_ATTACK:
			skill = objectp(weapon = ob->query_temp("weapon")) ? weapon->query("skill_type") : "unarmed";
			level = ob->query_skill_combined(skill);
			level += ob->query_temp("apply/attack");
			bonus= ob->query_temp("bonus/attack"); 	// This bonus is ONE_SHOT_BONUS.
			ob->set_temp("bonus/attack",0);		// after this calculation, release bonus.
			
			skill_log = skill;
			break;
		case SKILL_USAGE_DODGE:
			level = ob->query_skill_combined("dodge");
			level += ob->query_temp("apply/defense");
			bonus= ob->query_temp("bonus/dodge");
			ob->set_temp("bonus/dodge",0);
			skill_log = "dodge";
			break;
		case SKILL_USAGE_PARRY:
			weapon = ob->query_temp("weapon");
			wptype = objectp(weapon)?
					weapon->query("skill_type"): "unarmed";
			if (stringp(pski = ob->query_skill_mapped("parry"))){
				if (SKILL_D(pski)->valid_enable(wptype))
					level = ob->query_skill_combined("parry");
				else if (wptype!= "unarmed")
					level = ob->query_skill("parry",1)/2 + ob->query_skill_modifier("parry");
				else 
				{
					level = ob->query_skill("parry",1)/2 + ob->query_skill_modifier("parry");
					if (ob->query_skill_mapped("unarmed"))
						level += ob->query_skill(ob->query_skill_mapped("unarmed")); 			
				}
					
			} else 
			{
				level = ob->query_skill("parry",1)/2 + ob->query_skill_modifier("parry");
				if (wptype == "unarmed" && ob->query_skill_mapped("unarmed"))
					level += ob->query_skill(ob->query_skill_mapped("unarmed")); 			
			}
						
			level += ob->query_temp("apply/defense");
			bonus= ob->query_temp("bonus/parry");
			ob->set_temp("bonus/parry",0);		
			skill_log = skill;
			break;
		case SKILL_USAGE_MOVE:
			level = ob->query_skill_combined("move");
			bonus= ob->query_temp("bonus/move");
			ob->set_temp("bonus/move",0);
			skill_log = "move";
			break;		
		case SKILL_USAGE_MAGIC:
			level = ob->query_skill_combined("magic");
	//		level += ob->query_temp("apply/magic"); ** BE CAREFUL HERE, redundant cal.
			bonus= ob->query_temp("bonus/magic"); 
			ob->set_temp("bonus/magic",0);		
			skill_log = "magic";
			break;
		case SKILL_USAGE_SPELLS:
			level = ob->query_skill_combined("spells");
			bonus= ob->query_temp("bonus/spells"); 
			ob->set_temp("bonus/spells",0);		
			skill_log = "spells";
			break;
		case SKILL_USAGE_CURSISM:
			level = ob->query_skill_combined("cursism");
			bonus= ob->query_temp("bonus/cursism"); 
			ob->set_temp("bonus/cursism",0);		
			skill_log = "cursism";
			break;
		case SKILL_USAGE_HERB:
			level = ob->query_skill_combined("herb");
			bonus= ob->query_temp("bonus/herb"); 
			ob->set_temp("bonus/herb",0);		
			skill_log = "herb";
			break;
		case SKILL_USAGE_PERCEPTION:
			level = ob->query_skill_combined("perception");
			// We are too lazy to set perception for NPCs.. so play a little tricks here.
			if (!userp(ob) && !level) {
				level = ob->query("level")*8/3;
			}			
			bonus= ob->query_temp("bonus/perception");
			ob->set_temp("bonus/perception",0);
			skill_log = "perception";
			break;	
	}
			
// DEBUG ON			
		if (userp(ob) && level > 900) {
			if (ob->query_temp("timer/high_skill")+ 900 < time()) 
			{	
				log_file("SKILL_POWER_LOG", 
					sprintf("(%s)%s >900 skill: %s, %s, lvl = %d, app_atk = %d, app_def = %d\n",
   					ctime(time()), 
   					ob->name(1)+"("+ ob->query("id")+")", 
   					skill_log,
   					ob->query_skill_mapped(skill_log),
   					ob->query_skill(skill_log,1),
   					ob->query_temp("apply/attack"),
   					ob->query_temp("apply/"+skill_log),
				));	
				if (level>1200)
					tell_object(ob,HIR"ϵͳ��¼����Ĺ���/����״̬�����쳣������ͣ��Ϸ����������ʦ�㱨��
����������ʦ�����˳���Ϸ���µ�½����������BUGĲ���߽����ܷ��ƻ�ӭ��\n"NOR);
				ob->set_temp("timer/high_skill", time());
			}
		}
// DEBUG OFF		
	
	result = level/10*level/10*level/5;
	
	if(bonus>0)
		result+=bonus/10*bonus/10*bonus/5;
	
	if (!ANNIE_D->check_buff(ob,"hurtless")>0)
	if((status = ob->query("kee")) > 0 ) {			// Kee will affect SKILL_power
		if(status<ob->query("max_kee"))
		result = status*100/ob->query("max_kee")*result/100;
	} else {
		result = result /4000;
	}
	
	exp = (int)(ob->query("combat_exp")/25);			// exp �ı���
	
	if (!ANNIE_D->check_buff(ob,"hurtless")>0)
	if(ob->query("sen") > 0 && ob->query("gin") > 0) {	// Sen will affect EXP_power
		status= 3 * ob->query("sen") + ob->query("gin");
		if(status< 3*ob->query("max_sen") + ob->query("max_gin"))
			exp = status*100/ (3*ob->query("max_sen")+ob->query("max_gin"))*exp/100;
	} else {
		exp = exp /4000;
	}
	
	result = result + exp;

	// The effect of encumbrance.. only apply to non-magic skills
	if (usage == SKILL_USAGE_ATTACK || usage == SKILL_USAGE_DODGE
		|| usage == SKILL_USAGE_PARRY || usage == SKILL_USAGE_MOVE )
		result = result * enc / 10;				
	
	return result > 1 ? result : 1;
}

// Reward the winner.
void fight_reward(object winner, object loser) {
	object owner;

	if(objectp(owner = winner->query("possessed"))) {
		winner = owner;
	}
	winner->win_enemy(loser);
}

// Penalize the loser.
void fight_penalty(object winner, object loser) {
	object owner;

	if(objectp(owner = loser->query("possessed"))) {
		loser = owner;
	}
	loser->lose_enemy(winner);
}


string prepare_final_message(object attacker, object victim,string w_name, string vw_name,mapping action, string result) {
	string output, *limbs, limb;

	limbs = victim->query("limbs");
	limb = limbs[random(sizeof(limbs))];
	output = replace_string(result, "$l", limb );
	if(stringp(vw_name)) {
		output = replace_string(output, "$v", vw_name);
	}
	if(victim->query_skill_mapped("iron-cloth")) {
		output = replace_string(output, "$z",  SKILL_D(victim->query_skill_mapped("iron-cloth"))->name());
	}
	if(stringp(w_name)) {
		output = replace_string(output, "$w", w_name);
	} else if(stringp(action["weapon"])) {
		output = replace_string(output, "$w", action["weapon"] );
	}
	return output;
}

// attack_damage
// Return the damage an attack can do
int attack_damage(object attacker, mapping action, object victim) {
	int str, damage, force_factor, bounce, att_combat_exp, weapon_damage;
	int d0,d1,d2,d3,d3x,d4,d5,d6,d7,d_race, d_1, d_2, d_3;		// Debug message.
	string force_skill, attack_skill, martial_skill;
	object attweapon;
	mixed tmp;
	function f;

	damage_message = "";
	attweapon = attacker->query_temp("weapon");
	
	// Strength damage bonus. --- this is the combined effect of str + enforce.
	str = attacker->query_str();
	if (str<= 90)
		d1 = str*str/10;
	else
		d1 = 810 + (str-90)* 9;
	
	d1 = d1 *3/4;	// Weapon or not..damage all reduced by 1/4
		
	// Let race factor take effect. 
	d_race = d1 /10;
		if (attacker->query("national")=="�ɹ���")	d1 += d_race;
		if (attacker->query("national")=="����")	d1 -= d_race;
		if (victim ->query("national") =="����")	d1 += d_race;
		if (victim ->query("national")== "����")	d1 -= d_race;
		
	// Weapon damage consists of weapon_prop/damage + apply_temp/damage.
	d2 = attacker->query_temp("apply/damage") + 2;	
		
	// skill damage -- this is defined in individual skill.
	if(objectp(attweapon)) {
		attack_skill = attweapon->query("skill_type");
	} else {
		attack_skill = "unarmed";
	}
	if(stringp(martial_skill = attacker->query_skill_mapped(attack_skill) )) {
		d3 = SKILL_D(martial_skill)->damage_level(attacker);
		d3 = d3 * (d1 + d2) / 1000;	
	}
	
	// Quest_buff
	if (ANNIE_D->check_buff(attacker,"quest_dmg")>0) {
		d3x = (d1+d2) * attacker->query_temp("apply/quest_dmg")/100;
	}
		
	// Let hit_ob force skill take effect. --- written in individual force skill
	force_factor = attacker->query("force_factor");
	if(force_factor && (force_skill = attacker->query_skill_mapped("force"))) {
		tmp = SKILL_D(force_skill)->hit_ob(attacker, victim, d1+d2+d3, force_factor);
		if(stringp(tmp) ) {
			damage_message += tmp;
		} else if(intp(tmp)) {
			d4 += tmp;
		}
		
	}

	// Attack Skill hit_ob() damage -- written in individual skill.
	if(martial_skill = attacker->query_skill_mapped(attack_skill) ) {
		tmp = SKILL_D(martial_skill)->hit_ob(attacker, victim, d1+d2+d3);
		if(stringp(tmp) ) {
			damage_message += tmp;
		} else if(intp(tmp)) {
			d5 = tmp;
		}
	}

	// Let weapon or monster have their special damage.
	if(objectp(attweapon) && victim->query("race") != "Ԫ��") {
		tmp = attweapon->hit_ob(attacker, victim, d1+d2+d3);
		if(stringp(tmp) ) {
			damage_message += tmp;
		} else if(intp(tmp)) {
			d6 = tmp;
		}
		if(functionp(f = attweapon->query_temp("hit_ob",1))) // shadow bound hit_ob()
		{
			tmp = evaluate(f,attacker, victim, d1+d2+d3);
			if(stringp(tmp) )
			{
				damage_message += tmp;
			}
			else if(intp(tmp))
			{
				d6 = tmp;
			}
		}
	} else {	// unarmed hit from monsters
		tmp = attacker->hit_ob(attacker, victim, d1+d2+d3); 
		if(stringp(tmp) ) {
			damage_message += tmp;
		} else if(intp(tmp)) {
			d6 = tmp;
		}
	}

	// Let combat exp take effect
	d7 = F_LEVEL->get_level(attacker->query("combat_exp"))
			- F_LEVEL->get_level(victim->query("combat_exp"));
	
	// Add damage bonus.
	d_1 = d1 + d2 + d3 + d3x + d4 + d5 + d6 + d7;

	// Critical Strike?
	if (attacker->query_temp("combat/critical") && d_1 > 0) {
		d_2 = d_1/2;
		d_1 += d_2;
	}
		
	if (ANNIE_D->check_buff(attacker,"damagecurse") < 1)
	{
		d_3 = (d_1 + random(d_1)) / 2;	// normally average = 75% 
	}
	else
	{
		if ((attacker->query_temp("buff/"+ANNIE_D->check_buff(attacker,"damagecurse")))["att"] == "curse")
		{
			d_3 = d_1/2;	// curse type curse, 50%,-25%
		}
		else			
		{
			d_3 = d_1; 	// blessing type damage curse, 100%,+25%
		}
	}
	
	if (ANNIE_D->check_buff(attacker,"weaken") >= 1)
		d_3-=d_3*attacker->query_temp("buffup/weakened")/100;
		
	damage = d_3;
	damage += F_ABILITY->check_ability(attacker,"damage")*damage/100;
	
	if(damage < 0) damage = 0;
	
	if (wizardp(attacker) && attacker->query("env/combat2")=="verbose")
	{
		tell_object(attacker,sprintf(WHT"\nStr %d,Wp %d,Act %d,Q %d,f %d,sk %d,wp %d,lvl %d,sum=%d,crit.=%d,"HIR"rdm=%d,(ab)=%d \n"NOR,
		d1,d2,d3,d3x,d4,d5,d6,d7,d_1,d_2,d_3,damage));
	}
	if (wizardp(victim) && victim->query("env/combat2")=="verbose")
	{
		tell_object(victim,sprintf(YEL"\nStr %d,Wp %d,Act %d,Q %d,f %d,sk %d,wp %d,lvl %d,sum=%d,cri.=%d,"HIY"rdm=%d,(ab)=%d \n"NOR,
		d1,d2,d3,d3x,d4,d5,d6,d7,d_1,d_2,d_3,damage));
	}
	return damage;
}


// Inflict damange on the victim. victim �ķ�Ӧ
varargs int inflict_damage(object attacker, object victim, int damage, mapping action, string damage_type) {
	int absorb_vic, bounce, wounded,s_ratio,s_force,eff_ness;
	int a0,a_0, a1,a2,a3,a4,no_abs, no_shield, em, inbusy;
	string absorb_skill,s_msg,s_type, martial_skill, wptype, pski,debug, attack_skill;
	mapping shield;
	object weapon, weapon_v;
	mapping foo = ([]);

	weapon=attacker->query_temp("weapon");
	inflict_message = "";
	a0 = damage;


	//4.1 ����һ��ob_hit�Ĺ��ܡ��������ǹ涨ֻ����һ�������ã�����̫���ˡ�
	if(living(victim)
//			&& !victim->is_busy()	// ��ʹbusy,npc�����ĺ�force��ob_hit��Ȼ��Ч��	
			&& !attacker->query_temp("hit_ob_hit")
			&& !victim->query_temp("no_hit_ob_hit")
			&& damage > 0){
		inbusy=victim->is_busy();
		em = 0;
		// Dodge �����к�ķ�Ӧ
		martial_skill = (string)victim->query_skill_mapped("dodge");
		if( !inbusy && martial_skill = victim->query_skill_mapped("dodge"))
		{
			foo = SKILL_D(martial_skill)->ob_hit(attacker, victim, damage);
			if(foo && stringp(foo["msg"])) {
				inflict_message += foo["msg"];
				if (intp(foo["damage"]))	
					damage += foo["damage"];
				em = 1;
			}
		}
		// Parry �����к�ķ�Ӧ
		if (!em && !inbusy) {
			if(weapon_v = victim->query_temp("weapon")){
				wptype = weapon_v->query("skill_type");
				if (stringp(pski= victim->query_skill_mapped("parry")))
				if(SKILL_D(pski)->valid_enable(wptype))
					martial_skill = pski;
			} else {
				martial_skill = victim->query_skill_mapped("unarmed");
			}
			if (martial_skill && stringp(martial_skill)) {
				foo = SKILL_D(martial_skill)->ob_hit(attacker, victim, damage);
				if(foo && stringp(foo["msg"])) {
					em = 2;
					inflict_message += foo["msg"];
					if (intp (foo["damage"]))	damage += foo["damage"];
				} 
			} 
		}
		// Force �����к�ķ�Ӧ
		if( (!em && martial_skill = victim->query_skill_mapped("force"))) {
			foo = SKILL_D(martial_skill)->ob_hit(attacker, victim, damage);
			if(foo && stringp(foo["msg"])) {
				em = 3;
				inflict_message += foo["msg"];
				if (intp(foo["damage"]))	damage += foo["damage"];
			}
		}
		
		// NPC �����к�ķ�Ӧ
		if (!em && !userp(victim)) {
			foo = victim->ob_hit(attacker, victim, damage);
			if(foo && stringp(foo["msg"])) {
				inflict_message += foo["msg"];
				if (intp(foo["damage"]))	damage += foo["damage"];
			}
		}
		
		if (foo && intp(foo["damage"]))	a_0 = foo["damage"];
	}
	

	// Some attack will pass all iron-cloth.
	if(objectp(weapon))
		attack_skill = attacker->query_skill_mapped(weapon->query("skill_type"));
	else
		attack_skill = attacker->query_skill_mapped("unarmed");
	
	if(attack_skill)
	if(SKILL_D(attack_skill)->bypass_ironcloth())
			no_abs = 1;
	
	if (victim->query_temp("buff/no_abs"))
		no_abs = 1;		// ; annie 7.02.2003,��������perform,��divineforce-baocanshouque.

	if (victim->query_temp("buff/no_shield"))
		no_shield = 1;		// : let some attack to penetrate shield.
		
	// how much absort_vic?
	if(random(100)>5 && !no_abs)		
	{
			
	/* formula
	
	absorb_vic = 
		query_skill("iron-cloth",1)/2			- BASIC SKILL EFFECT
		+ query_skill(query_skill_mapped(iron-cloth))* eff_ness/200 - SPECIAL ENABLE EFFECT
		+ query_temp("apply/iron-cloth");			-- APPLY IRON_CLOTH
	*/		
		
		if(victim->query_skill("iron-cloth")) {
			absorb_skill = victim->query_skill_mapped("iron-cloth");
			if (absorb_skill) {
				if (!(eff_ness = SKILL_D(absorb_skill)->ic_effect()))
					eff_ness = 100;	
				absorb_vic = victim->query_skill("iron-cloth",1) /2
							+ victim->query_skill(absorb_skill) * eff_ness/200
							+ victim->query_temp("apply/iron-cloth");
			}else
				{
					absorb_skill = "iron-cloth";
					absorb_vic = victim->query_skill("iron-cloth",1) /2
							+ victim->query_temp("apply/iron-cloth");
				}
			inflict_message += SKILL_D(absorb_skill)->query_absorb_msg();
		} else
			absorb_vic = victim->query_temp("apply/iron-cloth");
			
		a1 = absorb_vic;
		damage -= absorb_vic;
	}
	if(damage <= 0) {
		absorb_skill = victim->query_skill_mapped("iron-cloth");
		if(absorb_skill) {
			bounce = (SKILL_D(absorb_skill)->bounce_ratio()) * (-damage) / 100;
/*			if (objectp(weapon)) {
				if (weapon->query("skill_type")=="throwing")
					bounce = bounce/100;
				if (weapon->query("skill_type")=="whip")
					bounce = bounce/10;
			}*/
			absorb_skill = attacker ->query_skill_mapped("iron-cloth");
			if(absorb_skill) {
				bounce -= (SKILL_D(absorb_skill)->bounce_ratio()) * attacker->query_skill("iron-cloth") / 100;
			}
//			message_vision(" bounce damage is "+(string)(bounce)+". \n",this_player());
			if(bounce > 0) {
				attacker->receive_damage("kee", bounce, victim);
				inflict_message += damage_msg(attacker,bounce, "������");
				damage = -bounce;	// no more damage calculation needed.
			}
		}
	} else {
		if(shield = victim->query_temp("shield_force"))
		if (!no_shield)
		{
			s_type=shield["type"];
			s_ratio=shield["ratio"];
			s_msg=shield["msg"];
			s_force=victim->query(s_type)*s_ratio/100;

			if(stringp(s_type))
			if(s_force>0)
			if(damage<s_force)
			{
				victim->add(s_type,-damage*100/s_ratio);
				damage=0;
				victim->force_status_msg("all");
				inflict_message+=s_msg;
				return damage; // no more calculation needed.
			}
			else
			{
				damage -= s_force;
				victim->set(s_type,0);
				victim->force_status_msg("all");
			}
		}
				
		if (damage>0) {			
			if (a2 = victim->query_temp("apply/armor")) {
				damage -= a2;	
			}
				
		}
					
//		FINAL DAMAGE INFLICTED !!!! 
		if (damage>0)	victim->receive_damage("kee", damage, attacker);
			else damage = 0;	
			
//		WEAPON damage, it just reduces some eff_kee, it will not affect kee.
//		soft-damage is a generic debuff, hardshell is a buff
		if(weapon && !ANNIE_D->check_buff(attacker,"soft_damage")&& !victim->query_temp("hardshell")) {
			a4 = random(damage) - victim->query_temp("apply/armor"); 	
			if(a4 > 0) {
				victim->receive_wound("kee",a4,attacker);
			}
		}
		
		
	}

//	DEBUG
	if (wizardp(attacker) && attacker->query("env/combat2")=="verbose")
		tell_object(attacker,sprintf(WHT"Inc %d,OB %d,I-C %d,Amr %d,Crit %d,"HIR"Total=%d, Eff %d \n"NOR,
		a0,-a_0,-a1,-a2,attacker->query_temp("combat/critical"),damage,a4));
	
	if (wizardp(victim) && victim->query("env/combat2")=="verbose")
		tell_object(victim,sprintf(YEL"Inc %d, OB: %d, I-C: %d, Amr: %d, Crit: %d, "HIY"Total= %d, Eff: %d \n"NOR,
		a0,-a_0,-a1,-a2,attacker->query_temp("combat/critical"),damage,a4));
//	DEBUG ENDS

	if(bounce<=0 || damage>0) {
		if (damage_type)
			inflict_message += damage_msg(victim,damage, damage_type);
		else 	
			inflict_message += damage_msg(victim,damage, action["damage_type"]);
	}
	return damage;
}


// dodge_attack
// the function that checks if the attack can be dodged.
int dodge_attack(object attacker, int ap, mapping action, object victim,int attack_type) {
	int  dp, flag, num, v_exp, perc,chance,shown;
	int busy_dodge, busy_bonus;
	string dodge_skill,attack_skill, race;
	mixed tmp;
	object att_weapon,boot, m_enemy;
	function f;

	dodge_message = "";

	if (victim->query_temp("is_unconcious"))
		return 0;
	
	att_weapon = attacker->query_temp("weapon");
	
	// Attack skill's special power.
	if(objectp(att_weapon))
	{
		attack_skill = attacker->query_skill_mapped(att_weapon->query("skill_type"));
		if(attack_skill)
		{
			if(SKILL_D(attack_skill)->undodgeable())
				return 0;
			else
				ap += ap/10 * SKILL_D(attack_skill)->accuracy_level(attacker)/100;				
		}
	}
	else
	{
		attack_skill = attacker->query_skill_mapped("unarmed");
		if(attack_skill)
		{
			if(SKILL_D(attack_skill)->undodgeable())
				return 0;
			else
				ap += ap/10 * SKILL_D(attack_skill)->accuracy_level(attacker)/100;				
		}
	}

//	4.1 feat/precision
	if (attacker->query_temp("feat/precision"))
		ap = ap * attacker->query_temp("feat/precision")/100;

//	Quest buff-atk
	if (ANNIE_D->check_buff(attacker,"quest_atk")>0)
		ap = ap * (100 + attacker->query_temp("apply/quest_atk"))/100;

	// Get base dodge power.
	dp = skill_power(victim, SKILL_USAGE_DODGE);

	if (victim->query_skill_mapped("dodge") == "stormdance"
		&& victim->query("class") == "moon")
		 	busy_dodge = 3;	
	else
			busy_dodge = 2;

	// Take into account of victim is busy or not. Animals can't parry, but they have bonus in dodge.
	if(victim->is_busy()) {
		race = victim->query("race");
		if (race == "Ұ��" || race == "����" || race =="����"
			|| race == "����" || race == "����" || race == "����") 
			dp /= 2;
		else 
			dp = dp * busy_dodge / 5;
	}

	if (!victim->is_busy() && ANNIE_D->check_buff(victim,"pseudo-busy")>0)
			dp = dp * busy_dodge / 5;
	
	// Take into account of the numbers of opponents, 
	// Each opponents of comparable exp will lower your dodge 5% chance up to 30%.
	
	if (userp(victim)) {
		m_enemy = victim->query_enemy();
		v_exp = victim->query("combat_exp")*3/5;
		m_enemy = filter_array(m_enemy,(: $1->query("combat_exp")>= $2 :), v_exp);
		num = sizeof(m_enemy);
		if (num >= 2) {
			dp = num > 6 ? dp *7/10 : dp - num* dp /20;
		}
	}

	// ���agi��Ӱ��
	perc = (attacker->query_agi() - victim->query_agi())* 100 / (victim->query_agi()+1);
	perc = (perc > 10) ? 10: perc;
	perc = (perc < -10) ? -10: perc;
	dp = dp  * (100 - perc) /100;
		
	// minimum dp is 1.
	dp = dp > 0 ? dp : 1;

	// Debug message
	if(wizardp(attacker) && (string)attacker->query("env/combat1")=="verbose" ) {
		chance = (ap*100)/(ap+dp);
		tell_object(attacker, sprintf(HIW "\nAP:%d vs DP:%d (%d)\t" NOR, ap,dp,chance));
	}
    if(wizardp(victim) && (string)victim->query("env/combat0")=="verbose" ) {
		chance = (ap*100)/(ap+dp);
		tell_object(victim, sprintf(HIW "\nAP:%d vs DP:%d (%d)\t" NOR, ap,dp,chance));
	}
	// Debug message ends

	flag = random(100) < F_ABILITY->check_ability(victim,"dodge");

	// Did the victim dodge the attack?
	if( random(ap + dp) < dp || victim->query_temp("buffup/evade_amount") > 0 || flag) {
		
		// CANT_DODGE can not hit Evade Feat, but will penetrate all others.
		if (victim->query_temp("cant_dodge")
			&& victim->query_temp("buffup/evade_amount") <= 0
			)	return 0;
		
		// Get dodge messages.
		dodge_skill = victim->query_skill_mapped("dodge");
		if(!dodge_skill) {
			dodge_skill = "dodge";
		}
		if (victim->query_temp("buffup/evade_amount") > 0 && !flag)
		{
			shown = 1;
			if (victim->query_temp("buffup/evade_amount")!= 987654321)	// A feat evade.
				victim->add_temp("buffup/evade_amount",-1);
			if (victim->query_temp("buffup/evade_amount") <= 0)
			{
				ANNIE_D->debuff(victim,"feat");	// ��evade_amount,�ض���feat TYPE��
				victim->set_temp("buffup/evade_amount",0);
			}
		}
		dodge_message = SKILL_D(dodge_skill)->query_dodge_msg(victim);
		
		if (shown)
			dodge_message = BRED HIY + "����"NOR + " " + dodge_message;
		
		// DODGE_OB
		if(stringp(tmp = SKILL_D(dodge_skill)->dodge_ob(attacker, victim, attack_type))) {
			dodge_message += tmp;
		}
		
		//����ȷ����ֻ��Ь�ӿ�����dodge_ob��Ҫ��Ȼ�ͳ������ˡ�
		//love
		//10/12/2002
		if(objectp(boot=victim->query_temp("armor/boots")))
		{
			if(functionp(f=boot->query_temp("dodge_ob",1)))
			{
				tmp=evaluate(f,attacker, victim);
				if(stringp(tmp) )
				{
					parry_message += tmp;
				}
			}
		}
		return dp;
	} else 
		return 0;
	
}

// parry_attack
// the function that checks if the atack can be parried.
int parry_attack(object attacker, int ap, mapping action, object victim) {
	string parry_skill, attack_skill;
	mixed tmp;
	int pp, v_exp, num, perc, chance, flag, shown, perc_a, perc_v;
	object weapon, armor, m_enemy, att_weapon;
	string wptype,pski;
	function f;

	parry_message = "";

	// CANT_PARRY can't penetrate feat/parry, but can penetrate inherent luck/ability
	if (victim->query_temp("is_unconcious")
		|| (victim->query_temp("cant_parry") && !victim->query_temp("feat/parry")))
		return 0;
	
	// Attack skill's power
	att_weapon = attacker->query_temp("weapon");
	if(objectp(att_weapon))
	{
		attack_skill = attacker->query_skill_mapped(att_weapon->query("skill_type"));
		if(attack_skill)
		{
			if(SKILL_D(attack_skill)->unparryable())
				return 0;
			else
				ap += ap/10 * SKILL_D(attack_skill)->accuracy_level(attacker)/100;				
		}
	}
	else
	{
		attack_skill = attacker->query_skill_mapped("unarmed");
		if(attack_skill)
		{
			if(SKILL_D(attack_skill)->unparryable())
				return 0;
			else
				ap += ap/10 * SKILL_D(attack_skill)->accuracy_level(attacker)/100;				
		}
	}
		
	//	4.1 feat/precision
	if (attacker->query_temp("feat/precision"))
		ap = ap * attacker->query_temp("feat/precision")/100;
			
	//	Quest buff-atk
	if (ANNIE_D->check_buff(attacker,"quest_atk")>0)
		ap = ap * (100 + attacker->query_temp("apply/quest_atk"))/100;
	
	// Get parry skill power.
	pp = skill_power(victim, SKILL_USAGE_PARRY);
	
	//	Quest buff-parry
	if (ANNIE_D->check_buff(victim,"quest_parry")>0)
		pp = pp * (100 + victim->query_temp("apply/quest_parry"))/100;
	
	// If victim is busy...
	if(victim->is_busy()||ANNIE_D->check_buff(victim,"pseudo-busy")>0){
		pp = pp * 2 / 5;
	}
	
	// �Ƿ���æ�Ż�������
	if (victim->query_temp("timer/switch_equip") + 4 > time())
	{		
		if (victim->query_skill("monkey-claw",1) >= 200 
			&& victim->query_skill_mapped("theorem") == "monkey-claw")
			pp = pp *3/5;	// 60%
		else if (victim->query_skill("monkey-claw",1) >= 150 
			&& victim->query_skill_mapped("theorem") == "monkey-claw")
			pp = pp /2;		// 50%
		else if (victim->query_skill("monkey-claw",1) >= 100 
			&& victim->query_skill_mapped("theorem") == "monkey-claw")
			pp = pp *2/5;	// 40%
		else if (victim->query_skill("monkey-claw",1) >= 50 
			&& victim->query_skill_mapped("theorem") == "monkey-claw")
			pp = pp *3/10;	// 30%
		else
			pp=pp/5;
	}

	// Take into account of the numbers of opponents, 
	// Each opponents of comparable exp will lower your parry 5% chance up to 30%.
	if (userp(victim)) {
		m_enemy = victim->query_enemy();
		v_exp = victim->query("combat_exp")*3/5;
		m_enemy = filter_array(m_enemy,(: $1->query("combat_exp")>= $2 :), v_exp);
		num = sizeof(m_enemy);
		if (num >= 2) {
			pp = num > 6 ? pp *7/10 : pp - num* pp /20;
		}
	}
	
	// ���cps��Ӱ�죬���Ӱ��10%
	perc_v = victim->query_cps()>1? victim->query_cps(): 1;
	perc_a = attacker->query_cps()> 1? attacker->query_cps() : 1;
	perc = ( perc_a - perc_v )* 100 / perc_v;
	perc = (perc > 10) ? 10: perc;
	perc = (perc < -10) ? -10: perc;
	pp = pp  * (100 - perc) /100;
	
	
	// minimum pp is 1.
	pp = pp > 0 ? pp : 1;

	
	// Debug message
	if(wizardp(attacker) && (string)attacker->query("env/combat1")=="verbose" ) {
		chance = (ap*100)/(ap+pp);
		tell_object(attacker, sprintf(HIW "AP:%d vs PP:%d (%d)\t" NOR, ap,pp,chance));
	}
	if(wizardp(victim) && (string)victim->query("env/combat0")=="verbose" ) {
		chance = (ap*100)/(ap+pp);
		tell_object(victim, sprintf(HIW "AP:%d vs PP:%d (%d)\t" NOR, ap,pp,chance));
	}
	// Debug message ends


	// ABILITY && FEAT
	flag = random(100) < F_ABILITY->check_ability(victim,"parry");
//	flag += victim->query_temp("feat/parry"); anywhere besides old panlongsuoguan?
	
	// Did victim parry the attack?
	if( random(pp+ap)< pp || victim->query_temp("buffup/parry_amount") > 0 || flag ) {
		
		if (victim->query_temp("buffup/parry_amount") > 0 && !flag)
		{
			shown = 1;
			if (victim->query_temp("buffup/parry_amount")!= 987654321)	// A feat parry.
				victim->add_temp("buffup/parry_amount",-1);
			if (victim->query_temp("buffup/parry_amount") <= 0)
			{
				ANNIE_D->debuff(victim,"feat");	// ��parry_amount,�ض���feat TYPE��
				victim->set_temp("buffup/parry_amount",0);
			}
		}
		
		// Get parry messages.
		if(weapon = victim->query_temp("weapon")){
			wptype=weapon->query("skill_type");
			if(pski=victim->query_skill_mapped("parry"))
			if(SKILL_D(pski)->valid_enable(wptype))
				parry_skill = pski;
			if (wptype == "unarmed" && !parry_skill)
				parry_skill = victim->query_skill_mapped("unarmed");
			if( !parry_skill)  
				parry_skill = "parry";
		} else {
			parry_skill = victim->query_skill_mapped("parry");
			if(!parry_skill || !SKILL_D(parry_skill)->valid_enable("unarmed"))
				parry_skill = victim->query_skill_mapped("unarmed");
			if(!parry_skill) 
				parry_skill = "unarmed";
		}

		parry_message = SKILL_D(parry_skill)->query_parry_msg(attacker->query_temp("weapon"));
		if(stringp(tmp = SKILL_D(parry_skill)->parry_ob(attacker,victim))) {
			parry_message += tmp;
		}

		if ( shown)
			parry_message = BRED HIY + "����"NOR + " " + parry_message;
			
		// װ�������parry_ob���Ҹ�����Ϊֻ��1�֡�
		// ok���������������������м���һ�£���ô���ԣ�û����
		// love
		// 10/12/2002
		if(objectp(weapon))
		{
			if(functionp(f=weapon->query_temp("parry_ob",1)))
			{
				tmp=evaluate(f,attacker, victim);
				if(stringp(tmp) )
				{
					parry_message += tmp;
				}
			}
		}
		else
		// �ţ��������û��������������һ��fist����ôҲ����������fist���м�
		if(objectp(weapon=victim->query_temp("left_hand")))
		{
			if(functionp(f=weapon->query_temp("parry_ob",1)))
			{
				tmp=evaluate(f,attacker, victim);
				if(stringp(tmp) )
				{
					parry_message += tmp;
				}
			}
		}
		else
		// �����������ǿ�����һЩװ����parry
		// Ŀǰ�Ҹ�����Ϊ���ܵ�װ���ǣ�shield,bracelet,
		// �Ҹ�����Ϊ��Щ��parry_ob�ǲ�������ģ�
		// so 1.weapon,2.secondary_weapon,3.shield,4.bracelet		
		if(objectp(armor=victim->query_temp("armor/shield")))
		{
			if(functionp(f=armor->query_temp("parry_ob",1)))
			{
				tmp=evaluate(f,attacker, victim);
				if(stringp(tmp) )
				{
					parry_message += tmp;
				}
			}
		}
		else
		if(objectp(armor=victim->query_temp("armor/bracelet")))
		{
			if(functionp(f=armor->query_temp("parry_ob",1)))
			{
				tmp=evaluate(f,attacker, victim);
				if(stringp(tmp) )
				{
					parry_message += tmp;
				}
			}
		}

		return pp;
	} else 
		return 0;
	
}


// counter_attack
// the function checks if we can counter the attack.
varargs int counter_attack(object attacker, int ap, mapping action, object victim,int i) {
	mapping counter_action,w_action;
	int counterp, damage, counterResult;
	string counter_skill, dodge_skill, tmp,w_name,vw_name;
	object victim_weapon = victim->query_temp("weapon");
	object attacker_weapon=attacker->query_temp("weapon");
	string damage_type;
	
	counter_message = "";
	// victim is busy or unconcious, can't counter attack.
	if(victim->is_busy() || victim->query_temp("is_unconcious")) 
		return 0;
	
	// get victim's counter attack action.
	counter_action = get_action(victim, 0);
	if(!mapp(counter_action)) {
		return 0;
	}
	if(i && victim->query_temp("counter_msg"))
		counter_message+=victim->query_temp("counter_msg")+counter_action["action"]+"��\n";
	else
		counter_message += counter_msg[random(sizeof(counter_msg))]
				+ counter_action["action"] + "��\n";

	// Get counter attack power
	counterp = skill_power(victim, SKILL_USAGE_ATTACK);

	// Did victim counter attack? ap vs ap --- ��ǿ��������ʤ, so used ap here instead of dp.
	if(random(ap +  counterp) < counterp) {		// counter �ɹ���attacker takes damage
		damage = attack_damage(victim, counter_action, attacker);
		counter_message += damage_message;
		damage = inflict_damage(victim, attacker, damage, counter_action, damage_type);
		counter_message += inflict_message;
		if(damage > 0) {
			attacker_damage += damage;
		} else {
			victim_damage += -damage;
		}
		counterResult = damage;
	} else {				// counter ʧ�ܣ�attacker ֱ��dodge��
		dodge_skill = attacker->query_skill_mapped("dodge");
		if(!dodge_skill) {
			dodge_skill = "dodge";
		}
		counter_message += SKILL_D(dodge_skill)->query_dodge_msg(victim);
		if(stringp(tmp = SKILL_D(dodge_skill)->dodge_ob(attacker, victim))) {
			counter_message += tmp;
		}
		counterResult = RESULT_DODGE;
	}
	if(objectp(attacker_weapon))
		vw_name=attacker_weapon->name();
	if(objectp(victim_weapon)) {
		w_name=victim_weapon->name();
		w_action=victim_weapon->query_action();
		if(counter_action["post_action"]) {
			counter_message += call_other(victim_weapon, counter_action["post_action"], victim, attacker, counterResult);
		}
		else if(w_action["post_action"]&&!random(5))
			counter_message += call_other(victim_weapon, w_action["post_action"], attacker, victim, counterResult);
		else
			counter_message += victim_weapon->wear_off(victim, attacker, counterResult);
	}

	counter_message = prepare_final_message(victim, attacker,w_name, vw_name,counter_action, counter_message);
	counter_message = replace_string(counter_message, "$N", "$TMP");
	counter_message = replace_string(counter_message, "$n", "$N");
	counter_message = replace_string(counter_message, "$TMP", "$n");
	return counterp;
}

// do_protect()
// a function that checks to see if there is anything/anyone protects our victim
int do_protect(object attacker, int ap, mapping action, object victim) {
	object *pros;
	string output, parry_skill;
	int pp, i, result;

	if (random(100) < F_ABILITY->check_ability(attacker,"protect"))
		return 0;

	pros = victim->query_temp("protectors");
	i = random(sizeof(pros));
	// clean up
	if(!pros[i]) {
		pros -= ({pros[i]});
		if(!sizeof(pros)) {
			victim->delete_temp("protectors");
		}
		result = 0;
	// Protector
	} else if((environment(pros[i])  != environment(victim))
			&& (environment(pros[i]) != victim)) {
		result = 0;
	} else if(pros[i]->is_character()) {
		// Can't protect other people, if you are busy, or you are fighting him. or you are not fighting attacker
		if(pros[i]->is_busy() || pros[i]->is_fighting(victim) || !pros[i]->is_fighting(attacker)){
			result = 0;
		} else 
		{
			// Check if the pros[i] can parry this attack for the victim.
			result = parry_attack(attacker, ap, action, pros[i]);
			if(result) {
				protect_message = BGRN HIG + "����"NOR + " " + parry_message;
				if(objectp(pros[i]->query_temp("weapon"))) {
					protect_message = replace_string(protect_message, "$v", (pros[i]->query_temp("weapon"))->name());
				}
			}
		}
	} else {
		result = pros[i]->protection();
		protect_message = pros[i]->protection_msg();
		if (protect_message=="") result=0;
	}

	if(result) {
		protector = pros[i];
		if (pros[i]->is_character())
			protect_message = replace_string(protect_message, "$n", pros[i]->name());
	}
	return result;
}

// get_action(object me)
// Return an action the object can take.
mapping get_action(object me, int attack_type) {
	mapping action;

	action = me->query("actions");
	if(!mapp(action)) {
		me->reset_action();
		action = me->query("action");
		if(!mapp(action)) {
			CHANNEL_D->do_sys_channel( "sys",
					sprintf("%s(%s): bad action = %O", me->name(1),
					me->query("id"), me->query("actions", 1)));
			return 0;
		}
	}
	return action;
}

// do_attack()
// Perform an attack action. This function is called by fight() or as an
// interface for some special utilize in quests.
varargs int do_attack(object attacker, object victim, int attack_type, mixed att_msg, string damage_type) {
	mapping action,w_action;
	string result,w_name,vw_name,race;
	int i, ap, ranCor, counterpower, actionResult, damage, block, eff_block, force_cost, ratio, perc;
	object attacker_weapon;
	object victim_weapon, shield;
	object *inv,*pet;

	// initial global variables.
	attacker_damage = 0;
	victim_damage = 0;
	result_message = "";

	// (1) first check if we are able to attack.
	if(!objectp(attacker) || !living(attacker) ||attacker->is_busy()
			|| !objectp(victim) || attacker->query_temp("is_unconcious")) 
			return 1;

	// Here we attempt to record damage,
	// However, in multi-pfm, we're only interested in the final cumulative damage. 
	// check /daemon/class/bonze/longxianyuye for an example.
	if (!victim->query_temp("skip_damage_record"))		
		victim->delete_temp("damaged_during_attack");

	// (2) Find out what action the attacker will take.
	action = get_action(attacker, attack_type);
	if(!mapp(action)) {
		return 1;
	}

	attacker_weapon = attacker->query_temp("weapon");
	victim_weapon= victim->query_temp("weapon");

	// (3) Prepare AP for the attacker.
	ap = skill_power(attacker, SKILL_USAGE_ATTACK);
		
	// �Ƿ���æ�Ż�������
//	if (attacker->query_temp("timer/switch_equip") + 2 > time()){
//		ap = ap * 7 /10;
//	}
		
	if (ANNIE_D->check_buff(attacker,"pseudo-busy")>0)
		ap = ap*2/3;
		
	if (ap < 1)	ap = 1;

	attacker->delete_temp("combat/critical");
	if (critical_strike(attacker,victim))
	{
		result_message = HIR "\n�� " NOR + action["action"] + "��" + HIR " �� \n" NOR;
		attacker->set_temp("combat/critical",1);
	}
	else
		result_message = "\n" + action["action"] + "��\n";

	if(stringp(att_msg)) {
		result_message = "\n" + att_msg + "\n";
	}
	
	
	// (4)  if player is enforced, let him/her relase the force even without hit others
	//	only use 1/20 enforce.. we want a long fight :D
	if(userp(attacker)) {
		force_cost = attacker->query("force_factor")/40;
		if(attacker->query("force") > force_cost) {
			attacker->add("force", -force_cost);
		} else {
			attacker->set("force_factor", 0);
		}
	}

	// (5) Let's see what/who can protect our victim, $N, $n,...all applies
	protect_message = "";
	result = "";
	actionResult = RESULT_UNKNOWN;
	counterpower = 0;
	if(sizeof(victim->query_temp("protectors"))) {
		counterpower = do_protect(attacker, ap, action, victim);
		result_message += protect_message;
		actionResult = counterpower > 0 ? RESULT_PROTECT : RESULT_UNKNOWN;
	}

	// (6) Find out what is the reaction from the victim.
	if(actionResult == RESULT_UNKNOWN && attack_type!=TYPE_QUICK)
	{
		// (6.1)  victim first try to dodge
		counterpower = dodge_attack(attacker, ap, action, victim, attack_type);
		result = dodge_message;
		actionResult = counterpower > 0 ? RESULT_DODGE : RESULT_UNKNOWN;
		
		// (6.2)  victim try to block --- 4.1 feature
		if (!counterpower)
		if ( shield = victim->query_temp("left_hand"))
		if ( block = shield->query("block_rate")) {
			// block ��һ��skill��marks/block��һ��.. mark :P
			eff_block= block * (victim->query_skill("block",1) + victim->query("marks/block"))
					/(shield->query("block_level") + 1);
			block = eff_block > block? block: eff_block;
			counterpower = random(block+100) > 100 ? 1 : 0;
			if (counterpower) {
				result = block_msg[random(sizeof(block_msg))];
				result = replace_string(result,"$s",shield->name());
				actionResult = RESULT_BLOCK; 
			} else 	
				actionResult = RESULT_UNKNOWN;
		}
		
		// (6.4) victim try to parry attack
		if(!counterpower){
		//  Here we add one thing: Animals don't parry...Ұ����ǰ�ȵ�������ĳ���..not right.
		//	Therefore we give them a second chance to dodge at this place.	������������parry��	
			race = victim->query("race");
			if (race == "Ұ��" || race == "����" || race =="����"
				|| race == "����" || race == "����" || race == "����") {
					counterpower = dodge_attack(attacker, ap, action, victim,attack_type);
					result = dodge_message;
					actionResult = counterpower > 0 ? RESULT_DODGE : RESULT_UNKNOWN;
			} else {	
					counterpower = parry_attack(attacker, ap, action, victim);
					result = parry_message;
					actionResult = counterpower > 0 ? RESULT_PARRY : RESULT_UNKNOWN;
			}
		}
		// (6.5) victim try to counter attack when parry fails or forced counter.
		if(!counterpower && victim->query_cps() > random(attacker->query_cps() + 100)
				&& attack_type==TYPE_REGULAR )		{
			if(userp(victim)){
				if(victim->query("force") > victim->query("force_factor"))
						victim->add("force", -victim->query("force_factor")/40);
				else   
						victim->set("force_factor", 0);
			}
			counterpower = counter_attack(attacker, ap, action, victim);
			actionResult = counterpower > 0 ? RESULT_COUNTER : RESULT_UNKNOWN;
				result= counter_message;
		} else if(victim->query_temp("counter_action"))	{	//  һ���� counter attack.
			counterpower = counter_attack(attacker, ap, action, victim, 1 );
			result+= counter_message;
			victim->delete_temp("counter_action");
		} else if(victim->query_temp("counter_action_extra")>0)	{	// timed counter attack.
			counterpower = counter_attack(attacker, ap, action, victim, 1 );
			if (result)
				result+= counter_message;
			else
				result= counter_message;
		}

	}
	
	// (7) Attack not blocked, take damage.
	if((actionResult == RESULT_UNKNOWN) || (actionResult == RESULT_COUNTER)) {
		
		// ���karma��Ӱ��
		perc = (victim->query_kar() - attacker->query_kar())* 100 /(victim->query_kar()+1);
		perc = (perc>5)? 5 : perc;
		if ( victim->query_temp("is_unconcious")|| perc<0 || random(100)> perc) {
			damage = attack_damage(attacker, action, victim);
				
			result_message += damage_message;
			damage = inflict_damage(attacker, victim, damage, action, damage_type);
			victim->add_temp("damaged_during_attack", damage); 	// ��¼һ�����˵���ֵ��
		
			result_message += inflict_message;
			if(damage < 0) {
				attacker_damage += -damage;
			} else {
				victim_damage += damage;
				actionResult = victim_damage;
			}
		} else
			result_message += WHT"$n"NOR+WHT"���������������͵�һ�������յرܿ���$N"NOR+WHT"�Ĺ�����\n"NOR;
		
	}


	result_message += result;		
	
	// (8)	weapon vs weapon/armor deteriation.
	
	if(objectp(victim_weapon))
		vw_name=victim_weapon->name();
	
		// It only happens when attacker is using a weapon.	
	if(objectp(attacker_weapon)) {
		w_name = attacker_weapon->name();
		w_action = attacker_weapon->query_action();
		// Post_action : e.g. throwing add_amount(-1), bash_weapon drop weapon.
		if(action["post_action"]) 
			result_message += call_other(attacker_weapon, action["post_action"], attacker, victim, actionResult);
		else if( w_action["post_action"] && !random(5))
			result_message += call_other(attacker_weapon, w_action["post_action"], attacker, victim, actionResult);
		// weapon/armor wore off.
		if (objectp(attacker_weapon)) 
			result_message += attacker_weapon->wear_off(attacker, victim, actionResult);
		else {
			attacker_weapon = 0;
			attacker->delete_temp("weapon");
		}
	}


	// (9) Prepare final result and status message, and show it.
	result_message = prepare_final_message(attacker, victim,w_name,vw_name, action, result_message);
	if (!victim->query_temp("combat_no_report"))
		message_vision(result_message, attacker, victim);
	if(victim_damage) {
		if (!victim->query_temp("combat_no_report"))	
			report_status(victim, 0);
		//�ӵ���������damage���Ż��ж�function busy
		if(victim->is_busy())
			victim->interrupt_me(attacker,"hit");
		
		if(victim->query_temp("damage_shield")) { 	// new pfm: damage_shield
			// Ok, we don't want it to be exploited... on players
			ratio = victim->query("combat_exp") * 10 /attacker->query("combat_exp") * 10; 
			if (ratio > 100) ratio = 100;
			if (ratio < 1 ) ratio = 1;
			if (userp(victim))
			{
				ratio = victim->query_temp("damage_shield/amount") * ratio / 100;		
				ratio = magic_modifier(victim,attacker,"kee/gin/sen", ratio);
			}
			else
			{
				ratio = victim->query_temp("damage_shield/amount");
				ratio = magic_modifier(attacker,victim,"kee/gin/sen", ratio);
			}		
			
			attacker->receive_damage(victim->query_temp("damage_shield/type"),ratio,victim);
			attacker->receive_wound(victim->query_temp("damage_shield/type"),ratio,victim);
			message_vision(victim->query_temp("damage_shield/msg"),victim,attacker);
		}
		
		// attack damage-->heal 
		if ((ratio = attacker->query_temp("damage_to_heal"))){
			ratio = magic_modifier(attacker,victim,"kee",victim_damage*ratio/100);
			attacker->receive_fulling("kee",ratio, attacker);
		}
		
		if (victim->query_temp("heal_shield")) { // New pfm: heal_shield
			// Ok, we don't want it to be exploited... on players
			if (attacker->query(victim->query_temp("heal_shield/type")) < attacker->query("max_"+victim->query_temp("heal_shield/type")))
			{
				ratio = attacker->query("combat_exp") * 10 /(victim->query("combat_exp")+1) * 10; 
				if (ratio > 100) 	ratio = 100;
				if (ratio < 1)		ratio = 1;
				if (userp(victim))
				{
					ratio = victim->query_temp("heal_shield/amount") * ratio / 100;		
					ratio = magic_modifier(victim,attacker,"kee/gin/sen", ratio);
				}
				else
				{
					ratio = victim->query_temp("heal_shield/amount");
					ratio = magic_modifier(attacker,victim,"kee/gin/sen", ratio);
				}		
				attacker->receive_fulling(victim->query_temp("heal_shield/type"),ratio);
				message_vision(victim->query_temp("heal_shield/msg"),attacker,victim);
			}
		}
	}
	

	if(attacker_damage) {
		report_status(attacker, 0);
	}
	
	if((!attacker->is_killing(victim->query("id")))
			&& (!victim->is_killing(attacker->query("id")))
			&& (victim->query("kee")*2 <= victim->query("max_kee")
				|| victim->query("gin")*2 <= victim->query("max_gin")
				|| victim->query("sen")*2 <= victim->query("max_sen"))
			&& damage > 0 
			&& !attacker->query_temp("fight_to_death",1)
			)	{
			
		if (!victim->query_temp("no_check_pfm_win"))
		{
			if (!victim->query_temp("is_unconcious"))
				message_vision(winner_msg[random(sizeof(winner_msg))], attacker, victim);				
			
			attacker->remove_enemy(victim);			
			victim->remove_enemy(attacker);
			fight_reward(attacker, victim);
			fight_penalty(attacker, victim);
		}
	}
}

// since most spell/magic perform don't call combatd fight(), this function needs to
//be called in perform to check winner/loser.

void win_lose_check(object attacker, object victim, int damage) {
	if((!attacker->is_killing(victim->query("id")))
			&& (!victim->is_killing(attacker->query("id")))
			&& (victim->query("kee")*2 <= victim->query("max_kee")
				|| victim->query("gin")*2 <= victim->query("max_gin")
				|| victim->query("sen")*2 <= victim->query("max_sen")
				)
			&& damage > 0 )	{
		attacker->remove_enemy(victim);
		victim->remove_enemy(attacker);
		if(!victim->query_temp("is_unconcious"))
			message_vision(winner_msg[random(sizeof(winner_msg))], attacker, victim);
		fight_reward(attacker, victim);
		fight_penalty(attacker, victim);
	}
}


// fight()
// This is called in the attack() defined in F_ATTACK, which handles fighting
// in the heart_beat() of all livings. Be sure to optimize it carefully.
void fight(object me, object victim) {
	object ob, weapon,*enemy;
	int n_race,n_dual,n_haste;
	int i, num;

	// Check to see if fight can start.
	if(!living(me)
			|| (environment(me) != environment(victim)) || me->query("no_attack")) {
		return;
	}

	// victim fight back.
	victim->fight_ob(me);
	
	//  If I am too clumsy to attack.
	if (random(me->query_temp("apply/slow")+100)>=100) {
		message_vision(YEL"\n$N"YEL"���ֳ��ɣ��������$n"YEL"��ʽ�е�������\n"NOR,me,victim);
		return;
	}

	// If victim is unconcious, always take the chance to makeanattack.
	if( victim->query_temp("is_unconcious")) {
		do_attack(me, victim, TYPE_QUICK, 0);
	// Else, see if we are brave enough to make an aggressive action.
	} else if( me->query("cps")* 2 > random(victim->query("cps"))
			|| victim->is_busy()
			&& !me->query_temp("marks/fight_stop")) {
		// do normal attack,
		do_attack(me, victim, TYPE_REGULAR, 0);
		
		// If I have racial penalty
		if(objectp(me) && objectp(victim))
		if ( living(me) && !me->is_busy() && !me->query_temp("is_unconcious") 
			&& me->is_fighting(victim)) 	
		if (victim->query("national")=="�ɹ���") 
		if (random(100) >= 90) {
			message_vision(CYN"\n$n��æ���ң�����է�֣�$N"CYN"��׼ʱ���ٴι���һ�С�\n"NOR,me,victim);
			do_attack(me, victim, TYPE_REGULAR, 0);
		}
		
		// If I have special skill-rated attack,
		if(objectp(me)) 	
		if (num =me->query_temp("buff/berserk_attack")) {
			weapon = me->query_temp("weapon");			
			for (i=0;i<num;i++){
				if(objectp(me) && objectp(victim))
				if ( living(me) && !me->is_busy() && !me->query_temp("is_unconcious")
				&& me->is_fighting(victim))
				{
					if (weapon 
						&& (me->query_skill_mapped(weapon->query("skill_type"))== me->query_temp("buff/berserk_skill"))) {
						message_vision(me->query_temp("buff/berserk_attack_msg"),me,victim);
						do_attack(me,victim,TYPE_REGULAR,0);
					} else
						return;				
				} else
					return;
			} 			
			return;		// Here we return, fixed n hits is good enough.
		}
			
				
		// If I have dual-attack skill.
		if(objectp(me) && objectp(victim))
		if ( living(me) && !me->is_busy() && !me->query_temp("is_unconcious")
			&& me->is_fighting(victim)) 	 	
		if (n_dual= me->query_skill("dual-attack"))
		if (random(n_dual) >= 100) {
			message_vision(CYN"\n$N�������಻�ϣ�ǰ��δ�ϣ��������ѻ�����\n"NOR,me);
			do_attack(me, victim, TYPE_REGULAR, 0);
		}
		// If I am really fast so i can attack again.
		if(objectp(me) && objectp(victim))
		if ( living(me) && !me->is_busy() && !me->query_temp("is_unconcious")
			&& me->is_fighting(victim)) 	 	
		if (n_haste = me->query_temp("apply/haste"))
		if (random(n_haste + 100)>= 100) {
			message_vision(WHT"\n$N����������ƥ��˲�����ѹ���һ�С�\n"NOR,me);
			do_attack(me, victim, TYPE_REGULAR, 0);
		}
	
		// skill' extra action.
		if(objectp(me) && objectp(victim))
		if ( living(me) && !me->is_busy() && !me->query_temp("is_unconcious")
			&& me->is_fighting(victim)) 	 	
		if (me->query_temp("extra_action")) {
			for (i=0;i<me->query_temp("extra_action");i++)
			{
				if (me->query_temp("extra_action_msg"))
					message_vision(me->query_temp("extra_action_msg"),me,victim);
				do_attack(me, victim, TYPE_REGULAR, 0);
			}
			me->delete_temp("extra_action");	//annie 7.02.2003
			// an example : kaleidostrike - hit_ob
		}
			
		// skill' multi-target
		if(objectp(me) && objectp(victim))
		if ( living(me) && !me->is_busy() && !me->query_temp("is_unconcious")) 	
		if (me->query_temp("annie/multi-target"))
		{
			enemy=me->query_enemy();
			for (i=0;i<sizeof(enemy);i++)
			{
				if (enemy[i] == me->query_temp("annie/multi-target"))	continue;

				do_attack(me, enemy[i], TYPE_REGULAR, " ");
			}
			me->delete_temp("annie/multi-target");	//annie 10.30.2003
			// an example : starrain - hit_ob
		}
			
	// Else, we just start guarding.
	} else {
		message_vision(guard_msg[random(sizeof(guard_msg))], me, victim);
	}
	return;
}


// auto_fight()
// This function is to start an automatically fight. Currently this is
// used in "aggressive", "vendetta", "hatred", "berserk" fight.
void auto_fight(object me, object obj, string type) {
	int bellicosity, fined;
	object silver, gold, cloth, room;

	if(!me || !obj || (!userp(me) && !userp(obj)) || me->is_fighting(obj) || me->query_temp("is_unconcious")
			||!living(me) || environment(me)!=environment(obj)
			|| environment(me)->query("no_fight")) {
		return;
	}

	if(type == "berserk") {
		bellicosity = (int)me->query("bellicosity");
		message_vision("$N��һ������������ɨ����$n��\n", me,obj);
		if(((int)me->query("force") + 300) >
				(random(bellicosity) + bellicosity)/2 ) {
			return;
		}
		if(userp(obj) && (int) obj->query("combat_exp") < LOWER_LIMIT) {
			return;
		}
		if (!legitimate_kill(me, obj))
			return; 
		
		if( bellicosity > (int)me->query("score") && !wizardp(obj) ) {
			message_vision("$N����$n�ȵ���" + RANK_D->query_self_rude(me)
					+ "����ʵ�ںܲ�˳�ۣ�ȥ���ɡ�\n", me, obj);
			me->kill_ob(obj);
			obj->kill_ob(me);
		} else {
			message_vision("$N����$n�ȵ���ι��" + RANK_D->query_rude(obj)
					+ "��" + RANK_D->query_self_rude(me) +
					"�������˴�ܣ����������ְɣ�\n", me, obj);
			me->fight_ob(obj);
			obj->fight_ob(me);
		}
	} else if(type == "naked") {
	 	if(!obj->is_naked()) {
	 		// ���˷绯��
	 		return;
	 	}
	} else   {
		if(type=="hatred")	{
			message_vision(catch_hunt_msg[random(sizeof(catch_hunt_msg))],me,obj);
			me->kill_ob(obj);
			obj->fight_ob(me);
		}
		else if (type=="vendetta")	{
			if(userp(me) && userp(obj))
				return;
			message_vision(catch_hunt_msg[random(sizeof(catch_hunt_msg))],me,obj);
			me->kill_ob(obj);
			obj->kill_ob(me);	
		}
		else	{
			message_vision(catch_hunt_msg[random(sizeof(catch_hunt_msg))],me,obj);
			me->kill_ob(obj);
			obj->fight_ob(me);
		}
	}
}

void auto_follow(object follower, object leader) {
	int fexp, lexp;
	fexp = (follower->query("combat_exp") > 0? follower->query("combat_exp") : 0);
	lexp = (leader->query("combat_exp") > 0 ? leader->query("combat_exp") : 0);
	if( random(lexp) > fexp/10 ) {
		follower->set_leader(leader);
	} else {
		follower->set_leader(0);
	}
}

// This function is to announce the special events of the combat.
// This should be moved to another daemon in the future.
void announce(object ob, string event) {

	if (ob->query("race") == "Ԫ��")	 
		return;

	switch(event) {
		case "dead":
			if (stringp(ob->query("death_msg"))) 
				message_vision(ob->query("death_msg"),ob); //���Լ�һ������ǰ�Ļ���
			message_vision("\n$N���ˡ�\n\n", ob);
			break;
		case "unconcious":
			message_vision("\n$N����һ�����ȣ����ڵ���һ��Ҳ�����ˡ�\n\n", ob);
			break;
		case "revive":
			message_vision("\n$N���������۾��������˹�����\n\n", ob);
			break;
	}
}

void winner_reward(object killer, object victim) {
	object owner;

	if(objectp(owner=killer->query("possessed"))) {
		killer = owner;
	}
	killer->defeated_enemy(victim);
}

void loser_penalty(object killer, object victim) {
	object owner;

	if(objectp(owner=victim->query("possessed"))) {
		victim = owner;
	}
	victim->defeated_by_enemy(killer);
}

void killer_reward(object killer, object victim) {
	int bls, i;
	string vmark;
	object owner;
	object env;
	object *mem;
	object realkiller;
	mapping quest;

	// Call the mudlib killer apply.
	realkiller = killer;
	if(objectp(owner=killer->query("possessed"))) {
		killer = owner;
	}
	killer->killed_enemy(victim);	// The NPC's action after killing.
	if(userp(victim) ) {
		if((int) killer->query("combat_exp") < (int)victim->query("combat_exp")/10 * 9) {
			killer->set("last_good_kill",(int)killer->query("mud_age"));
		}
		env = environment(victim);
		if((objectp(env)) && !(env->query("no_death_penalty")))
			killer->add("PKS", 1);
		bls = 10;
	} else {
		killer->add("MKS", 1);
		bls = 1;
	}

	if (userp(killer))
		killer->add("bellicosity",bls);

	// Now official killing official will also become fei.
	if((!userp(victim)) && stringp(vmark = victim->query("vendetta_mark"))) {
		killer->add("vendetta/" + vmark, 1);
	}

	// Now let's add the quest reward here
	
	mem = pointerp(killer->query_team()) ? killer->query_team() : ({ killer });
	if (!userp(victim))
	for(i=0; i<sizeof(mem); i++) {
		if ((mem[i])) {
			if(mapp(quest = mem[i]->query("quest"))
				&& (string)victim->name() == quest["quest"]
				&& (time() - mem[i]->query("quest_time") <= 900)) {
				QUESTS_D->give_reward(mem[i],killer, quest);
			}
		}
	}

	// let's add the hired killer things here
	if(!userp(realkiller) && realkiller->query("hired_killer")
			&& (string)victim->query("id") == (string)realkiller->query("haunttar")) {
		message_vision("$Nһ���֣��Ҳ���ʹ����������ڣ�\n",realkiller);
		victim->set_temp("last_damage_from","�������˴�ɱ��"+ environment(realkiller)->query("short")+HIY"��");
		destruct(realkiller);
	}
}

varargs void victim_penalty(object victim, mixed killer,int flag) {
	
	object env;
	string msg="Ī����������ˡ�";
	string special_death_place,death_msg;
	mapping actions, combat_level, data;
	
	int combat_exp, combat_pot,combat_exp_old,combat_pot_old;
	int combat_exp_lost,combat_pot_lost, reward, current_apply;
	
	string *attr1= ({ "strength","composure","agility", "intelligence","karma", "constitution" });
	string *attr2= ({ "str", "cps", "agi", "int", "kar", "con" });
	string *attr3= ({ "����", "����", "�ٶ�", "����", "����", "����" });
	
	int 	num;
	
	if( userp(victim)) {
		env = environment(victim);
		if((objectp(env)) && (env->query("no_death_penalty"))) {
			victim->set_temp("no_death_penalty",1);
			victim->clear_all_condition();  //In yaren fight, easilly get posioned.
			return;
		}
		if(objectp(killer))
		{
			msg="��"+killer->query("name");
			actions = killer->query("actions");
			switch(actions["damage_type"])
			{
				case "����":
				case "����":
					msg+=HIY"�����ˡ�";
					break;
				case "����":
					msg+=HIY"�����ˡ�";
					break;
				case "����":
					msg+=HIY"�����ˡ�";
					break;
				case "����":
					msg+=HIY"�����ˡ�";
					break;
				case "����":
					msg+=HIY"�����ˡ�";
					break;
				case "����":
				case "����":
					msg+=HIY"�����ˡ�";
					break;
				case "ץ��":
					msg+=HIY"ץ���ˡ�";
					break;
				case "������":
					msg+=HIY"�����ˡ�";
					break;
				default:
					msg+=HIY"ɱ���ˡ�";
			}
			log_file( "DEATH_LOG", sprintf("(%s) %s(%s) was killed by %s(%s) at %O.\n", 
   				ctime(time()), 
   				victim->name(1), victim->query("id"), 
   				killer->name(1), killer->query("id"),
   				environment(victim)));
		}
		else if(stringp(killer)) {
			msg = killer;//������Ǹ���һ�����Ա仯��������info�Ļ���
			log_file( "DEATH_LOG", sprintf("(%s) %s(%s) was %s at %O.\n", 
   				ctime(time()), 
   				victim->name(1),
   				victim->query("id"), 
   				msg, environment(victim)));
   		} else
   			log_file( "DEATH_LOG", sprintf("(%s) %s(%s) was %s at %O.\n", 
   				ctime(time()), 
   				victim->name(1),
   				victim->query("id"), 
   				msg, environment(victim)));
		
		if(!flag)
		CHANNEL_D->do_sys_channel(
				"info",sprintf("%s(%s)"+msg, victim->name(1),victim->query("id")));
		// Add/Set/Reduce flags.
		victim->add("KILLED",1);
		victim->clear_all_condition();
		victim->set("bellicosity", 0);

		// NO_PK auto reset.
		if (!victim->query("NO_PK")) {
			victim->set("NO_PK",1);
			if (data = PK_D->check_list(victim->query("id"),"HUNTER_LIST")) {
				tell_object(victim,WHT"\n���ڹٸ���Ѳ��������������������洵�ˡ�\n"NOR);
				PK_D->remove_member("HUNTER_LIST",victim->query("id"));
			}	
			else if (data = PK_D->check_list(victim->query("id"),"PK_LIST")) {
				tell_object(victim,WHT"\n�ٸ������ͨ���������������ֹͣ�ˡ�\n"NOR);
				PK_D->remove_member("PK_LIST",victim->query("id"));
				if (killer)
				if (userp(killer)) {
					reward = data["reward"]*9/10;
					killer->add("deposit",reward*10000);
					PK_D->add_reward(killer->query("id"));
					tell_object(killer,WHT"��ɱ��һ��ͨ�����ˣ��õ�����"+reward+"���ƽ�\n"NOR);
				}
			}
		}	
				
		// Add/Set/Reduce flags.
		victim->delete("vendetta");

		// EXP ��ʧ�������ֵȼ������ᡤʹ�㽵����
		// Ǳ�ܼ�������ʧ��������5����͵�������Ҫ��ҽ���ָ�����
		
		combat_exp = victim->query("combat_exp");

		// ����Ϊ������ʧ��		
		if (combat_exp > 12000)	{
			// ��ʧ����20��Quest�ľ���ֵ��������20��Quest����20%�ľ���ֵ
			combat_level = F_LEVEL->exp_to_level(combat_exp);
			if (combat_level["level"]<11)	
				combat_exp_lost = REWARD_D->quest_reward(combat_level["level"]) * 5;
			else
				combat_exp_lost = REWARD_D->quest_reward(combat_level["level"]) * 20;
			victim->add("death/half_quest",-combat_exp_lost);						
			victim->set("death/exp_lost", combat_exp_lost);
						
/*			victim->add("combat_exp", - combat_exp_lost);
			if (((F_LEVEL->exp_to_level(combat_exp-combat_exp_lost))["level"]) < combat_level["level"])
				tell_object(victim,HIR"\n�군�ˣ���ĵȼ������ˡ�\n"NOR);
			else
				tell_object(victim,HIR"\n��ľ���ֵ�����ˡ�\n"NOR);	*/
					
			num = random(6);			
			if (combat_level["level"] >= 10) {
				current_apply = victim->query("attr_apply/"+attr1[num]);
				if (victim->query(attr2[num]) + current_apply>10){
					tell_object (victim, WHT"\n		���" + attr3[num] + "�ܵ����˽����ˡ�\n\n\n"NOR);
					victim->add("attr_apply/"+attr1[num],-5);
				}
			}			
		}			
		victim->set("death/time", time());
		victim->set("death/revived", 0);	// fresh new death, no revive yet
		victim->delete("death/killer");
		if (objectp(killer)) 
			victim->set("death/killer",killer->query("name")+"("+killer->query("id")+")");

	}
}


//	This function is to modify all KILL function. All skills/perform that involving "kill_ob" without "kill"
//	should call this function to check legitimacy. 

int legitimate_kill(object attacker, object victim) {
	object owner;
	mapping buff;
	
	// Yaren fight.
	if (environment(attacker)->query("PK_FREE")
			&& environment(victim)->query("PK_FREE"))
		return 1;
		
	// heihei, pet can't escape the log.
	if (objectp(owner = attacker->query("possessed")))
		attacker = owner;	
		
	if( objectp(owner = victim->query("possessed")))
		victim = owner;
		
	// NPC Ψһ��mark�� NO_KILL,�����趨ĳЩ����ɱ�ġ�
	if (!userp(victim)) {
		if (victim->query("NO_KILL")) return 0;
		else return 1;
	}
	
	// ������ɱ������ʧ��
	if (userp(attacker) && ANNIE_D->check_buff(attacker,"no-pk")>0)
		ANNIE_D->debuff(attacker,"no-pk");

				
	// ����victim����PLAYER
	if (userp(attacker)) {
		if (attacker->query("NO_PK") || victim->query("NO_PK"))	
			return 0;
		if (ANNIE_D->check_buff(victim,"no-pk")>0)
			return 0;
		if (!ANNIE_D->check_buff(attacker,"fugitive")) {
					// 5 mins NO_PK mark
			buff =
			([
				"caster":attacker,
				"who": 	 attacker,
				"type":	"fugitive",
				"att":	"curse",
				"name":	"��Թ����",
				"buff1": "fugitive",
				"buff1_c":1,
				"time":  3600,
				"buff_msg":""NOR,
			]);
			ANNIE_D->buffup(buff);
		}
	}
		
	// ��5���ӵĻ���ʱ�䡣
	if (userp(attacker))
	if (attacker->query("pk_start")+ 300 > time()
		|| victim->query("pk_start")+ 300 > time())
		return 0;
		
	if( userp(attacker) && userp(victim) && !environment(victim)->query("no_death_penalty"))
   	log_file( "KILL_LOG", sprintf("(%s)%s tried to attack %s\n", 
   			ctime(time()), 
   			attacker->query("name")+"("+ attacker->query("id")+")", 
   			victim->query("name")+"("+ victim->query("id")+")"));
	return 1;
}

/* 	This is used to check if I can buff/debuff a target in non-combat skills
	which is not covered by Legitimate_kill()
	
	It is called in all base exert/curse/perform/conjure/cast functions.
	It should also be called in cmds/skills which bypass the above checks.
	Main purpose: A pker can't buff/debuff a non-pker and his pets, vice verse.
	
	However, to NPC targets, 
	Debuff is allowed, buff(including heal) is not allowed.
	But current skills don't have a "good" and "bad" mark.
*/
	
int legitimate_buff(object me, object target) {
	object owner, real_target;
	
	if (!userp(me))	return 1;			// NPCs can do whatever they want
	
	if (objectp(owner = target->query("possessed")))
		real_target = owner;
	else
		real_target = target;
		
	if (!userp(real_target)) return 1;  		// Do things to NPC is allowed
	
	if (real_target == me) return 1;		// My own pet.
		
	if (me->query("NO_PK") == real_target->query("NO_PK"))
		return 1;	// All PCs with same PK mark
	
	return 0;	

}

/* 	This is used in every heal performs
	Current Rule is, you can heal Players (or his pets) with same PK mark, and that's it.
	ע�⣬player֮���Heal�ᱻlegitimate_buff����أ��˺�����ص���Heal NPC
*/

int legitimate_heal(object me, object target) {
	object owner, real_target;
	
	if (objectp(owner = target->query("possessed")))
		real_target = owner;
	else
		real_target = target;
		
	if (userp(me) && userp(real_target))
	if (me->query("NO_PK") == real_target->query("NO_PK"))
		return 1;		
	
	return 0;	

}


//	This function is to create a more complicated busy/anti-busy situation, 
//	We don't want everything be busied.

/*	Busy list

Unarmed : 	bloodystrike, meihua-shou, dabei-strike, eagle-claw, 
Step-busy: 	windy-steps, fall-steps, nine-moon-steps, meng-steps, fengyu-piaoxiang, 
		anxiang-steps, cloud-dance. hawk-steps, 
Weapon-busy: 	fumostaff, qingpingsword, tanzhi-shentong, taiji-sword, taiji.three-sword
Special-busy: 	Hong, alchemy-zhui, mihunshu, gobankiri, hyakki, 
NPC only :	shenji-steps,liuquan-steps,

Rule 0: Modify the higher range non-unarmed busy rate, the rate stays same till NPC's exp >1M + yours.
Rule 1: same menpai, effect /2 ֪��֪��ô. Only apply to player,,, cause NPC doesn't switch skill.
Rule 2: some Boss will be immune to busy.
Rule 3: some NPC will be immune to a special type of busy skill.

NPC feature:
(1) BIG Boss: chiyou, hibernating dragon... etc. 
	the busy chance should be no more than 50% for same exp with normal skill,.
	these guys also can't be zhaixin, ghost-curse, or poisoned.
	MARK: set("big_boss",1);
(2) normal boss: dragon lord, octopus, or special NPCs who carries good item, 
	the busy chance should be reduced
	they can't be zhaixin, ghost-curse. or poisoned.
	MARK set("boss",1);
(3) 5M+ new NPCs in 4.1, some of them will have new ability to dodge a certain type of busy. 
	Thus, a player needs to learn more than one busy skill to ensure his power. 
	(a) usually we can skip the 3 unarmed-busy since they have only one real busy time. 
	(b) we should ensure that a menpai has at least one way to deal with enemy. 
	(c) we can exclude those busy with a timer. 
	(d) if a busy isn't strong or it's a symbol of a menpai (alchemy, hong, mihunshu..), leave it alone.
	MARK set("busy_immune",random(2)+1)

*/



int can_busy(object attacker, object victim, string skill) {
	
	int immune,diff, mod;
	int busy_time, interval, time_mod;
	string *group_1 = ({ "hawk-steps","windy-steps","tanzhi-shentong","qingping-sword" });
	string *group_2 = ({ "fall-steps","fumostaff","cloud-dance"});
	string *unarmed = ({ "meihua-shou", "dabei-strike", "bloodystrike","eagle-claw","taiji" });
		
	mod = 10;		// MOD=10 ��û������,
			
//	Rule 1: Since we are designing 0-10M game, we limit the busy power.
//		Only unarmed busy is designed to fight high exp enemy.
//		Remember, the qlist will never ask you to kill someone > yourexp + 400k
	if (member_array(skill, unarmed) ==-1) {
		diff = victim->query("combat_exp") - attacker->query("combat_exp");
		if (diff > 4000000 )		mod = 20;
		else if (diff > 2000000) 	mod = 15;
		else if (diff > 1000000)	mod = 12;
	}

//	Rule 2: same menpai, effect /2 , should this applies to player attack only ?
	if (userp(attacker) && SKILL_D(skill)->skill_class() == victim->query("class"))
		mod = mod * 2;
	
//	Rule 3: some Boss will be immune to unarmed busy.	
	if (victim->query("boss")|| victim->query("combat_exp")>15000000)	
		mod = 200;
	
	if (victim->query("big_boss")|| victim->query("combat_exp")>20000000)	
		mod = 300;
		
//	Rule 3: some NPC will be immune to a special type of busy skill. --- RARE		
	if (!userp(victim) && immune = victim->query("busy_immune")) {
		if ( (immune == 1 && member_array(skill,group_1)!= -1)
			|| (immune == 2 && member_array(skill,group_2)!= -1)
			|| (immune == 3 && member_array(skill, unarmed)!= -1)
			|| (immune == 4)
			)
		return 0;		//��������BUSY
	}	

//	Rule 4: ��ʹ��ͬһperform����busy�����ƣ�ֻ��������ҡ���NPC��������书��
	time_mod = 100;
	if (userp(attacker) || objectp(attacker->query("possessed")))
	if (busy_time = victim->query_temp("busy_timer/"+skill)) {
		interval = time()-busy_time;
		if 	(interval <= 8 ) 			time_mod = 500;	
		else if  (interval <= 10)		time_mod = 300;
		else if (interval < 18)			time_mod = 200;
	}
	
	mod = mod * time_mod /100;
	
	if(wizardp(attacker) && (string)attacker->query("env/combat_b")=="verbose" ) {
		tell_object(attacker,"skill class is "+SKILL_D(skill)->skill_class()+"\n");
		tell_object(attacker, "time mod = " + time_mod + "; busy modifier is "+mod+".\n");
	}

	return mod; 	// MODIFY BUSY RATE
	
}

/*	Currently this function does nothing.
	However, all damages that don't directly call do_attack() should go through this function.
	Later we could
	1. Modify spells/magic damage globaly
	2. Add spell/magic resist concept.
	3. Add �������� blah blah
*/
	
int magic_modifier(object attacker, object victim, string type, int damage){
	
	if (ANNIE_D->check_buff(attacker,"quest_magic")>0)
		damage = damage * (100 + attacker->query_temp("apply/quest_magic"))/100;
	
	if (wizardp(attacker) && attacker->query("env/combat_s")== "verbose")
		tell_object(attacker, WHT"magic damage is "+ type + "="+ damage +".\n"NOR);
	
	if (wizardp(victim) && victim->query("env/combat_s")== "verbose" && attacker != victim)
		tell_object(victim, WHT"magic damage is "+ type + "="+ damage +".\n"NOR);
	return damage;
}

// Calculate Critical Strike.
// +50% critical stike �Ὣ�����10%��ߵ�15%��������10%��ߵ�60%��
// �� Delta kar>20, apply/critical >= 400 ʱ�� rate >=100, ÿһ����Ϊ 150% critical.
// ��ʹ�� feat ʱ����ÿһ����Ϊ critical.
int critical_strike(object me,object who)
{
	int rate;
	
	if (who->query_temp("feat/critical"))	return 1;
	rate = me->query_kar() - who->query_kar();
	if (rate < 1)	return 0;
	if (rate > 20)	rate = 20;
	rate += rate * me->query_temp("apply/critical_strike") / 100;	
//	message_vision("rate is "+rate,me);
	if (random(100) < rate)
		return 1;
	else
		return 0;
}


/*
	
	���������ʹ�������������Ƶķ���������ħ�������ĳɹ��ʡ�
	
	attacker, victim,
	attack_type == "gin", "kee", "sen", "special", ("fire", "ice", "poison" etc )
	skill == "spells", "cursism" "magic" "herb",
	
	����perform����apply/attack��������ڵ��ô˺���ǰʹ��
		apply/spells, apply/magic, apply/cursism, apply/herb
		
	attack_power ==  exp_power + skill_power (basic + apply);
		--	Here, skill can be magic, spells, cursism, herb
		
	defense_power == exp_power + skill_power 
		-- 	Here, skill is "perception"
	
	����ͬʱ����һ��enhance�Ĳ���������Ϊ�����������ɹ��ʣ�	
	
				
*/


varargs int do_magic_attack(object attacker, object victim, string skill, string attack_type, int enhance)
{
	int at_result, df_result, perc, result, chance, c_skill;
	string msg;

	result = 1;
		
	if (enhance > 2000 || attacker->query("combat_exp")> 100000000)
	{							
		tell_object(attacker, " sure hit for this pfm.\n");	// DEBUG
		return 1;
	}	
	
	if (victim->query("combat_exp") > 100000000)
	{
		tell_object(attacker, " sure miss for this pfm.\n");	// DEBUG
		return 0;
	}	
	
	switch (skill){
		case "magic": 	c_skill = SKILL_USAGE_MAGIC; break;
		case "spells": 	c_skill = SKILL_USAGE_SPELLS; break;
		case "cursism": c_skill = SKILL_USAGE_CURSISM; break;
		case "herb":	c_skill = SKILL_USAGE_HERB; 	break;
		default:	tell_object(attacker,"��֪ͨ��ʦ�޸ġ�\n");
	}
	
	at_result = skill_power(attacker, c_skill);
	
	// First Check Perception Defense
	df_result = skill_power(victim, SKILL_USAGE_PERCEPTION);
	if (victim->query_temp("cant_percept"))
		df_result = 1;
	
	msg = "at_result = " + at_result + "  df_result = " + df_result + "\n";
	
	// ��� int ��Ӱ�졣
	perc = (attacker->query_int() - victim->query_int())* 100 / (victim->query_int()+1);
	perc = (perc > 10) ? 10: perc;
	perc = (perc < -10) ? -10: perc;
	at_result = at_result/10 * (100 + perc) /10;
	
	// ���������һ����������ĳЩ�����magic performʹ�á�
	at_result = at_result /100 * (100 + enhance);
	
	chance = at_result * 100 / (at_result + df_result) ;
				
// DEBUG
	if (wizardp(attacker) && attacker->query("env/combat_s") == "verbose") 
	{		
		msg += " INT modifier = attacker" + attacker->query_int() + " vs defender " + victim->query_int() 
			+ " = " + perc + "\n";
		msg += " Modified at_result = " + at_result + "\n";
		msg += " Chance to Win in Perp is ===== " + chance + "\n";
		tell_object(attacker,msg);		
	}
// END DEBUG			 
		
	if (random (at_result + df_result ) <= df_result)
	{
//		result -=1;
//		tell_object(attacker,"1st attack missed");		
		return 0;
	}

	// Then check DODGE DEFENCE

	df_result = skill_power(victim, SKILL_USAGE_DODGE);	
	if (victim->query_temp("cant_dodge"))
		df_result = 1;
		
	msg = "at_result = " + at_result + "  df_result = " + df_result + "\n";
	
	chance = at_result * 100 / (at_result + df_result) ;
				
// DEBUG
	if (wizardp(attacker) && attacker->query("env/combat_s") == "verbose") 
	{		
		msg += " Modified at_result = " + at_result + "\n";
		msg += " Chance to Win in Dodge is ===== " + chance + "\n\n\n";
		tell_object(attacker,msg);		
	}
// END DEBUG			 
		
	if (random (at_result + df_result ) <= df_result)
	{
//		result -=1;
//		tell_object(attacker,"2nd attack missed");		
		return 0;
	}

	return 1;
	
}


/*	BUSY ��һ�������ħ������
	attacker, victim,
	type == "unarmed", "step", "weapon","other"
	skill == "fall-steps/luoyeqiufeng", "shenji-steps/shenjimiaosuan" etc.
	enhance ����һ�����������ʵ�����ֵ��--> �� perform �������
	mod 	����һ����˫��ս��������������--����can_busy()����
	
		my_exp = my_exp * enhance/100 * ������������;
		your_exp = your_exp * mod;
			
	step/weapon busy: 	random (my_exp) + my_exp/2 > your_exp;
	unarmed busy:		random (my_exp+your_exp) > your_exp	
	rev-unarmed busy	my_exp >��random (your_exp)			 		
*/


int do_busy_attack(object attacker, object victim, string skill, string type, int enhance, int mod)
{
	int at_result, df_result, perc, result;
	int chance;
	string msg;
		
	if (type != "unarmed" && type!= "step" && type!="weapon" && type!= "rev-unarmed"
		&& type != "rev-step")
	{
		tell_object(attacker, " wrong skill type, check your coding.\n");	
		return 0;
	}
	
	if (victim->query_temp("is_unconcious"))
		return 1;
	
	if (enhance > 2000 || attacker->query("combat_exp")> 100000000)
	{							
		tell_object(attacker, " sure busy for this pfm.\n");	// DEBUG
		return 1;
	}	
	
	if (enhance < 10 || victim->query("combat_exp") > 100000000)
	{
		tell_object(attacker, " sure fail for this pfm.\n");	// DEBUG
		return 0;
	}
	
	if (mod > 1000)	mod = 1000;	// we don't want overflow :D
	
	at_result = attacker->query("combat_exp") / 10;
	df_result = victim->query("combat_exp") / 100 * mod;
		
	at_result = (at_result <= 100 )? 100: at_result;
	df_result = (df_result <= 100 )? 100: df_result;
	
	// ��Զ�����Ӱ��
	perc = (attacker->query_cps() - victim->query_cps())* 100 /( victim->query_cps()+1);
	perc = (perc > 10) ? 10: perc;
	perc = (perc < -10) ? -10: perc;
		
	at_result = at_result /100 * (100 + perc) /100 * enhance;
	
// DEBUG
	if (wizardp(attacker) && attacker->query("env/combat_b2")== "verbose"){
		msg =  " Attacker :  EXP = " + attacker->query("combat_exp")+ " \n";
		msg += " Defender :  EXP = " + victim ->query("combat_exp")+ " \n";
		msg += " CPS modifier = attacker" + attacker->query_cps() + " vs defender " + victim->query_cps() 
			+ " = " + perc + "\n";
		msg += " Perform EnHance = " + enhance + " mob= " + mod + "\n";
		msg += " Modified at_result = " + at_result + " vs  df_result=" + df_result + "\n";
	}			
// END DEBUG			 
	
	
	if (type == "step" || type == "weapon")
	{
		if (df_result - attacker->query("combat_exp")/2 >= at_result)
			chance = 0;
		else
			chance = (at_result - df_result + attacker->query("combat_exp")/20) * 100 / at_result;
				
		at_result = random(at_result) + attacker->query("combat_exp")/2/10; 
		
	} else if (type == "unarmed")
	{
		chance = at_result * 20 / (at_result + df_result) *5 ;
		at_result = random(at_result + df_result);
	} 
	  else if (type == "rev-unarmed")	// Random enemy exp...wudang taiji-jian.etc
	{
		chance = ( at_result > df_result ) ? 100
				: (at_result * 100 / df_result);				
		df_result = random (df_result);	
	} 	
	
	if (at_result > df_result)
		result = 1;
	else 
		result = 0;
				
// DEBUG
	if (wizardp(attacker) && attacker->query("env/combat_b2")== "verbose"){
		msg += " Chance to Win is ===== " + chance + "\n\n\n";
		tell_object(attacker,msg);		
	}			
// END DEBUG			 
	if (!userp(victim))
		victim->add_hate(attacker, F_LEVEL->get_level(attacker->query("combat_exp"))*4);
	
	return result;
}
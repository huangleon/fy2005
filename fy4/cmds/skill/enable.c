// enable.c
//	07/20/2003-- added all kinds of temp parameters
//			-- Silencer@fengyun.com

#include <ansi.h>
inherit F_CLEAN_UP;

mapping valid_types = ([
//		"array":        "��",
		"animal-training":  "ѵ����",
		"axe":     	"����",
		"blade":        "����",
		"dagger":       "�̱���",
		"dodge":        "������",
		"force":        "�ڹ�",
		"fork":         "�淨",
		"hammer":       "����",
		"iron-cloth": 	"Ӳ��",
		"literate": 	"��д",
		"magic":        "����",
		"move":         "�Ṧ",
		"parry":        "�м�",
	//	"perception":   "������",
		"scratching":   "��֮��",
		"cursism" :	"��ͷ��",
		"spells":       "����",
		"staff":        "�ȷ�",
		"stealing":     "������",
		"sword":        "����",
		"throwing":     "����",
		"unarmed":      "ȭ��",
		"whip":     	"�޷�",
		"herb":		"ҩ��",
		"spear":        "ǹ��",
		"musket":				"��ǹ",

		"theorem":        "����֮��",

]);

int main(object me, string arg) {
	mapping skill_map;
	string *types, *skill_o, *skill, *usr_skill, ski, map_to;
	int i, j, modify, skill_level;
	string s, skill_name,enable_skill, attack_skill;
	object weapon;
	
	seteuid(getuid());
	
	if(!arg) {
		skill_map = me->query_skill_map();
		if(!mapp(skill_map) || sizeof(skill_map)==0 ) {
			return notify_fail("������û��ʹ���κ����⼼�ܡ�\n");
		}
		skill_o = keys(valid_types);
		skill  = sort_array( skill_o, (: strcmp :) );
		
		if (me->query_temp("apply/attack")) {
			if (weapon = me->query_temp("weapon")) 
				attack_skill = weapon->query("skill_type");
			else
				attack_skill = "unarmed";
		}
				
		write("��������Ŀǰʹ���е����⼼�ܡ�\n");
		write("��������������������������������������������������������������������\n");
		for(i=0; i<sizeof(skill); i++) {
			if(undefinedp(valid_types[skill[i]])) {
			    	map_delete(skill_map, skill[i]);
			    	continue;
			}
			if(!me->query_skill(skill[i])) {
				continue;
			}
			modify = me->query_skill_modifier(skill[i]);
			if (skill[i] == attack_skill)
				modify += me->query_temp("apply/attack");
			
			printf("  %-24s�� %-15s  ��Ч�ȼ���%3d%5s\n" NOR, 
		    		valid_types[skill[i]] + " (" + skill[i] + ")",
		    		undefinedp(skill_map[skill[i]]) ? "��" : 
					SKILL_D(skill_map[skill[i]])->name(),
				me->query_skill(skill[i]),
		    		modify==0? "": (modify>0? HIG"+"+(string)(modify): HIR""+(string)(modify))
		    	);
		}
		write("\n��Ч�ȼ� = ��������/2 + ���⼼��*�书ϵ��\n");
		write("����ɫ���ɫ�����ֱ�ʾ������������Perform����Advanced-skill������ֵ��\n\n");
		write("��������������������������������������������������������������������\n");
		return 1;
	}
	
	if(arg=="?") {
		write("�����ǿ���ʹ�����⼼�ܵ�������������⼼�ܣ�\n");
		skill = sort_array(keys(valid_types), (: strcmp :) );
		if (me->query_skills())
			usr_skill = keys(me->query_skills());
		for(i=0; i<sizeof(skill); i++) {
			s = sprintf("%6s (%s)", valid_types[skill[i]], skill[i]);
			if (me->query_skills())
				usr_skill = filter_array(keys(me->query_skills()), (: SKILL_D($1)->valid_enable($2) :), skill[i]);
			if(sizeof(usr_skill)) {
				for(j=0; j<sizeof(usr_skill); j++) {
					printf("  %-20s : %s (%s)\n", s, SKILL_D(usr_skill[j])->name(), usr_skill[j]);
					s = " ";
				}  
			} else {
				printf("  %-20s\n", s);	
			}
		}
		return 1;
	}

	if (arg)
	if (sscanf(arg, "%s %s", ski, map_to)!=2)
	if (sscanf(arg,"%s",skill_name)==1 && skill_name!="none") {
		if(!find_object(SKILL_D(skill_name)) && file_size(SKILL_D(skill_name)+".c")<0) 
			return notify_fail("��" + skill_name + "���������ּ�����\n");	
		if( !(skill_level=me->query_skill(skill_name,1)))
			return notify_fail("�㲢û��ѧ������ܻ��Ǽ��ܵȼ�Ϊ�㡣\n");
		
		if(undefinedp(valid_types[skill_name])) 
			return notify_fail("����ܲ��ǻ����������࣬�� enable ? ���Բ鿴����Щ���ࡣ\n");
		enable_skill=me->query_skill_mapped(skill_name);
					
		write("���������ѯ�����⼼��״����\n\n");
		modify = me->query_skill_modifier(skill_name);
		
		if (me->query_temp("apply/attack")) {
			if (weapon = me->query_temp("weapon")) 
				attack_skill = weapon->query("skill_type");
			else
				attack_skill = "unarmed";
			if ( skill_name == attack_skill)
				modify += me->query_temp("apply/attack");
		}
		
		printf("  %-24s�� %-15s  ��Ч�ȼ���%3d%5s\n\n" NOR, 
		    		valid_types[skill_name] + " (" + skill_name + ")",
		    		(!me->query_skill_mapped(skill_name)) ? "��" : 
					SKILL_D(enable_skill)->name(),
				me->query_skill(skill_name),
				modify==0? "": (modify>0? HIG"+"+(string)(modify): HIR""+(string)(modify))
		    	);
		return 1;
	}

	
	if(sscanf(arg, "%s %s", ski, map_to)!=2) {
		return notify_fail("ָ���ʽ��enable <��������> <��������>|none\n");
	}
	
	if(undefinedp(valid_types[ski])) {
		return notify_fail("û������������࣬�� enable ? ���Բ鿴����Щ���ࡣ\n");
	}
	
	if(map_to=="none") {
		me->map_skill(ski);
		me->reset_action();
		write("ֹͣʹ�á�" + valid_types[ski] + "�������⼼�ܡ�\n");
		return 1;
	} else if(map_to==ski) {
		write("��" + SKILL_D(ski)->name() + "��������" + valid_types[ski] + "�Ļ���������Ҫ enable��\n");
		return 1;
	}
	
	if(!find_object(SKILL_D(map_to)) && !load_object(SKILL_D(map_to))) {
		return notify_fail("��" + map_to + "���������ּ�����\n");	
	}

	if(!me->query_skill(map_to, 1)) {
		return notify_fail("�㲻�����⼼�ܡ�" + SKILL_D(map_to)->name() + "����\n");
	}

	if(!me->query_skill(ski, 1)) {
		return notify_fail("������" + SKILL_D(ski)->name() + "����ûѧ�ᣬ���ʹ�����⼼�ܡ�" + SKILL_D(map_to)->name() + "����\n");
	}
/*	if (map_to == "tanzhi-shentong" && ski=="parry" && !me->query("fy41/hs_tz_parry") ) {
		return notify_fail("�����ڻ�δ������ѵ�ָ��ͨ�������м��ϵĿھ���\n");
	}*/
	if(!SKILL_D(map_to)->valid_enable(ski)) {
		return notify_fail("���⼼�ܡ�" + SKILL_D(map_to)->name() + "���������ڡ�" + valid_types[ski] + "���ϡ�\n");
	}
		
	if(ski=="dodge" && ANNIE_D->check_buff(me,"dodgeup"))
		return notify_fail("������ʹ�������������⼼�ܣ��������Ч����ʧ�����ת�����书��\n");
	
	if(ski=="parry" && ANNIE_D->check_buff(me,"parryup"))
		return notify_fail("������ʹ���мܵ����⼼�ܣ��������Ч����ʧ�����ת�����书��\n");
	
	if(ski=="iron-cloth" && ANNIE_D->check_buff(me,"ironup"))
		return notify_fail("������ʹ��Ӳ�������⼼�ܣ��������Ч����ʧ�����ת�����书��\n");
	
	if(ski=="force" && (ANNIE_D->check_buff(me,"gks") || ANNIE_D->check_buff(me,"powerup")))
		return notify_fail("������ʹ���ڹ������⼼�ܣ��������Ч����ʧ�����ת�����书��\n");

	if (ski == "theorem")
	{
		if(me->query("timer/last_theorem") + 1800 > time())
			return notify_fail(CYN"����֮��ÿ��ʮ����ֻ���л�һ�Ρ�\n"NOR);
		me->set("timer/last_theorem",time());
	}
		
	me->map_skill(ski, map_to);
	me->reset_action();
	write("��ʼʹ�á�" + valid_types[ski] + "�������⼼�ܡ�" + SKILL_D(map_to)->name() + "����\n");
	
	if( ski=="magic" ) {
		write("�������һ��ħ��ϵ�������������¶�����\n");
		me->set("atman", 0);
		me->force_status_msg("atman");
	} else if( ski=="force" ) {
		write("�������һ���ڹ��������������¶�����\n");
		me->set("force_factor",0);
		me->set("force", 0);
		me->force_status_msg("force");
	} else if( ski=="spells" ) {
		write("�������һ������ϵ��������������������\n");
		me->set("mana", 0);
		me->force_status_msg("mana");
	}
	
	return 1;
}



int help(object me) {
	write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36mָ���ʽ : 	enable
		enable ?
		enable <��������>
		enable <��������> <��������> | none[0m
[0;1;37m����������������������������������������������������������������[0m   

���ָ������ָ����Ҫ�õļ��ܣ���ָ����������ͼ������ơ�
������Ӳ��������ʾ���������༰��Ŀǰ��ʹ�õļ������� ��
�����һ�� ? ���г�������ʹ�����⼼�ܵļ������࣬
���ֱ�Ӹ�����������г�Ŀǰ�ü��ܵģ������״̬��
 
[0;1;37m����������������������������������������������������������������[0m   
 
HELP
        );
        return 1;
}
 

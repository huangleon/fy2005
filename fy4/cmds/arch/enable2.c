// enable.c
//      07/20/2003-- added all kinds of temp parameters
//                      -- Silencer@fengyun.com

#include <ansi.h>
inherit F_CLEAN_UP;

mapping valid_types = ([
//              "array":        "��",
                "animal-training":  "ѵ����",
                "axe":          "����",
                "blade":        "����",
                "dagger":       "�̱���",
                "dodge":        "������",
                "force":        "�ڹ�",
                "fork":         "�淨",
                "hammer":       "����",
                "iron-cloth":   "Ӳ��",
                "literate":     "��д",
                "magic":        "����",
                "move":         "�Ṧ",
                "parry":        "�м�",
        //      "perception":   "������",
                "scratching":   "��֮��",
                "cursism" :     "��ͷ��",
                "spells":       "����",
                "staff":        "�ȷ�",
                "stealing":     "������",
                "sword":        "����",
                "throwing":     "����",
                "unarmed":      "ȭ��",
                "whip":         "�޷�",
                "herb":         "ҩ��",
                "spear":        "ǹ��",
                "musket":				"��ǹ",
]);

int main(object me, string arg) {
        mapping skill_map;
        string *types, *skill_o, *skill, *usr_skill, ski, map_to;
        int i, j, modify, skill_level;
        string s, skill_name,enable_skill, attack_skill;
        object weapon;
        object who;
        
        if (!arg)
			return notify_fail("��ʽ��enable ����\n");

        seteuid(getuid());
        who = find_player(arg);
        if (!who)
        	who = find_living(arg);
        if (!who)
            return notify_fail("�Ҳ���Ү����\n");
        
                skill_map = who->query_skill_map();
                if(!mapp(skill_map) || sizeof(skill_map)==0 ) {
                        return notify_fail("������û��ʹ���κ����⼼�ܡ�\n");
                }
                skill_o = keys(valid_types);
                skill  = sort_array( skill_o, (: strcmp :) );
                
                if (who->query_temp("apply/attack")) {
                        if (weapon = who->query_temp("weapon")) 
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
                        if(!who->query_skill(skill[i])) {
                                continue;
                        }
                        modify = who->query_skill_modifier(skill[i]);
                        if (skill[i] == attack_skill)
                                modify += who->query_temp("apply/attack");
                        
                        printf("  %-24s�� %-15s  ��Ч�ȼ���%3d%5s\n" NOR, 
                                valid_types[skill[i]] + " (" + skill[i] + ")",
                                undefinedp(skill_map[skill[i]]) ? "��" : 
                                        SKILL_D(skill_map[skill[i]])->name(),
                                who->query_skill(skill[i]),
                                modify==0? "": (modify>0? HIG"+"+(string)(modify): HIR""+(string)(modify))
                        );
                }
                write("\n��Ч�ȼ� = ��������/2 + ���⼼��*�书ϵ��\n");
                write("����ɫ���ɫ�����ֱ�ʾ������������Perform����Advanced-skill������ֵ��\n\n");
                write("��������������������������������������������������������������������\n");
                return 1;
        
        
        return 1;
}



int help(object me)
{
write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36m��ʦָ���ʽ : 	enable2 ����[0m
[0;1;37m����������������������������������������������������������������[0m   
 
������������NPC��Enable����������ڲ��ԡ�

[0;1;37m����������������������������������������������������������������[0m 
HELP	);
	return 1;
}
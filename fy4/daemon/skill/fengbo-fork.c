// �����硤���μǡ��汾��������
// �粨ʮ���� fengbo-cha.c
// 9-17-97 pickle
//	--- modified by Silencer@fy4 for fy skills.

inherit SKILL;
#include <ansi.h>

void setup() {
	set("name","�粨ʮ����");
	set("type","fork");
	set("usage/fork",1);
	set("usage/parry",1);
	set("effective_level",200);
	set("difficulty",200);
	set("skill_class","npc");
	set("unarmed_parry_msg",({
		"$n������$W���˸�Բ���������������������ˡ�\n",
		"$n���ܲ��ã�ͦ$W����ǰ�մ��������档���п���ƽƽ���棬ȴ��ƽ���н�$N�Ĺ��Ʒ����ˡ�\n",
		"$n�Ӷ�$W������ǰ���˸���Բ�����õ���$N�Ĺ��ơ�\n",
		"$n˿����Ϊ���������赭д�ػӲ�һ�̣��Ƶ�$N�����Է���\n",
		"$n��������$W��ֻ����������һ�����죬���ڽ�$N���˻�ȥ��\n",
		"$n������������$W��������$N����Χκ����֮�ƹ�Ȼ��Ч����$N���˻�ȥ��\n",
	})
	);
		
	action = ({
			([      "action" : "$N����$w����ǰ��̽�����棬�����ָ֮��������$n��$l",
			        "dodge" : 200,
			        "parry" : 100,
			        "damage" : 90,
			        "damage_type" : "����",
			]),
			([      "action" : "$N���β���������$w����$n��$l����������Ӳ�������������ˮ��������������",
			        "dodge" : 150,
			        "parry" : 150,
			        "damage" : 250,
			        "damage_type" : "����",
			]),
			([      "action" : "$Nһ����Х�����������Ӱ�����������ƣ��ŵ�$n�ۻ�����",
			        "dodge" : 120,
			        "parry" : 120,
			        "damage" :220,
			        "damage_type" : "����",
			]),
			([      "action" : "$N����$wһ����Ѹ���ޱȵ���$n�������Ҹ���һ��",
			        "dodge" : 80,
			        "parry" : 80,
			        "damage" : 110,
			        "damage_type" : "����",
			]),
			([      "action" : "$N��Цһ��������$w�������ذ�Ӱ������һ����Ũ������$n\n",
			        "dodge" : 70,
			        "parry" : 70,
			        "damage" : 90,
			        "damage_type" : "����",
			]),
			([      "action" : "$Nŭ߳һ��������$w����ޱȵ���$n��ǰ�����ػ������߻�",
			        "dodge" : 120,
			        "parry" : 120,
			        "damage" : 220,
			        "damage_type" : "����",
			]),
			([      "action" : "$NͻȻ��������һ�ԣ���������֮�����������������������",
			        "dodge" : 120,
			        "parry" : 120,
			        "damage" : 220,
			        "damage_type" : "����",
			]),
	});
}

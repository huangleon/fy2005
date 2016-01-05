//mimicat@fy4

#include <ansi.h>
inherit SKILL;

void setup() {
	set("name","�׽");
	set("type","force");
	set("skill_class","shaolin");
	set("effective_level",150);
	set("usage/parry",1);
	set("usage/force",1);
	set("usage/iron-cloth",1);
	set("usage/unarmed",1);
	set("difficulty",250);
	set("damage_level",200);
	set("ic_effect",75);
	set("bounce_ratio",25);
		
	set("absorb_msg",			({
			"�ۿ�$N��ʽѸ����$n������ǰӭ��һ����һȦ��ǽӦ�������$N������\n",
			"$n˫�ֺ�ʮ���Ŀ������һ���ھ�͸�������$N���˻�ȥ��\n",
			})
	);
	set("unarmed_parry_msg",	({
			"�ۿ�$N��ʽѸ����$n������ǰӭ��һ����һȦ��ǽӦ�������$N������\n",
			"$n˫�ֺ�ʮ���Ŀ������һ���ھ�͸�������$N���˻�ȥ��\n",
			})
	);

	action = ({
			([      "action":
					"$N����һ����ƽ�͵������紺�����̣�����$n$l",
			        "parry":                300,
			        "force":		100,
			        "damage_type":  "����"
			]),
			([      "action":
					"$Nչ��һ�ӣ�������һ����������һ�����θ�ǽѹ��$n",
			        "parry":                200,
			        "force":		140,
			        "damage_type":  "����"
			]),
			([ 	"action":
					"$Nһ���������䣬����Ѱ����ȴ��֪Ϊ�ε��޿ɵ������޿ɱ�",
			        "parry":                300,
			        "dodge":		400,
			        "force":		160,
			        "damage_type":  "����"
			]),
	});
}


int valid_learn(object me) {
	if((string)me->query("class") != "shaolin" ) 
		return notify_fail("�׽��ֻ�����ָ�ɮ���������书��\n");
	if( (int)me->query_skill("zen",1) < (int)me->query_skill("yijinjing",1))
		return notify_fail("���������Ϊ�������޷������������׽��\n");
	return ::valid_learn(me);
}

int effective_level(object me)
{
	if (me)
	if (userp(me) && me->query("class") != "shaolin")
		return 75;
		
	return 150;
}

int help(object me)
{
	write(@HELP   
�׽Ϊ�����书���ѳ�����Чϵ�����½�һ��
�׽��Ҫ��ͬ�ȼ�������Ϊ����

L100������Ʒ�����shield/shieldoff��
�����������壬���˵��˺���������������������ħ���������⣩�Ķ�
�����������������������˺��ı�����1:1.5��1:1.8��1:2.0��
ע�⣬��ʹ�ý���Ʒ��ڼ�ʹ�������ؼ�ÿ����������300��������

L150��������ա���foguang��
20����ʹ��һ�Σ���Χ�������к�10�غ����޷�����

L200�����ؾ�����sanzang��
15����ʹ��һ�Σ�˲��ָ��������ֵ��75%
HELP
    );
    return 1;
}


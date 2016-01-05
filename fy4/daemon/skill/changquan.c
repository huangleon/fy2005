// changquan.c
inherit SKILL;

void setup() {
	set("name","���ֳ�ȭ");
	set("type","unarmed");
	set("effective_level",100);
	set("practice_limit",100);
	set("usage/parry",1);
	set("usage/unarmed",1);
	set("difficulty",100);
	set("skill_class","official");
	set("parry_msg",			({
			"$n����Ϊ����һ�С�����Ϊ�������ͻ�$N��$w������\n",
			"$n��ȭ���£���ȭ�Ա���һ�С����ų�塹����$N���ڳ��⡣\n",
			})
	);
	set("unarmed_parry_msg", 	({
			"$n��ȭ���£���ȭ�Ա���һ�С����ų�塹����$N���ڳ��⡣\n",
			"$n����Ϊ����һ�С�����Ϊ�������ͻ�$N������\n",
			})
	);
	action = ({
			([	"action":		"$Nʹһ�С��ڻ����ġ�����׼$n��$l��������һȭ",
				"force":		80,
				"parry":		60,
				"damage_type":	"����"
			]),
			([	"action":		"$N����ȭͷ��һ�С�̩ɽѹ��������$n��$l�к���ȥ",
				"force":		60,
				"parry":		30,
				"damage_type":	"����"
			]),
			([	"action":		"$N������Σ���ȭ���й�ֱ��������$n��$l����",
				"force":		60,
				"parry":		30,
				"damage_type":	"����"
			]),
			([	"action":		"$N����һ������ȭ��������ȭʹ�����Ϻ��Ƴ�������$n$l",
				"force":		60,
				"parry":		80,
				"damage_type":	"����"
			]),
	});
}


int help(object me)
{
	write(@HELP   
����ԧ��ȭ����yuhuan��
220����Чȭ�ţ�������ȭ������æ��5�غϣ�
250�����ֳ�ȭ��������ȭ������æ��4�غϣ�
���⹥��������Чȭ�ţ�����
�������(enforce)����Чȭ�ţ���
������Ҫ120��������
HELP
    );
    return 1;
}

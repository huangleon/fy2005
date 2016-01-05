// cloudstaff.c

inherit SKILL;

void setup() {
	set("name","�����ȷ�");
	set("type","staff");
	set("effective_level",200);
	set("usage/staff",1);
	set("usage/parry",1);
	set("difficulty",200);
	set("practice_limit",100);
	set("skill_class","bonze");
	set("parry_msg",		({
			"$n���$v��һ�С����Ƴ�ᶡ����ȶ˻���������ԲȦ�����ͳ��أ���$N������Χ��\n",
			"$n˫�ֺ�ʮ������һ�С��������š���$v������ɳ�����$N��$w������\n",
			"$nȫ�������$v�̵غ�ɣ�ͻ��һ�С����ƾ㿪�����ȷ��������õ�ˮ��͸��\n",
			})
	);

	set("unarmed_parry_msg",	({
			"$n���$v��һ�С����Ƴ�ᶡ����ȶ˻���������ԲȦ�����ͳ��أ���$N������Χ��\n",
			"$nȫ�������$v�̵غ�ɣ�ͻ��һ�С����ƾ㿪�����ȷ��������õ�ˮ��͸��\n",
			})
	);
	
	action = ({
			([      "action":               
		"$Nʹһ�С����է�֡�������$w��һ������һɨ��������Ư�������ƣ����赭д�ػ���$n",
			        "damage":               40,
			        "dodge":                40,
			        "parry":                40,
			        "post_action":  "bash_weapon",
			        "damage_type":  "����"
			]),
			([      "action":               
		"$N�Ӷ�$w�������𵴣��·�˺���˵��ƿ飬�����ţ������ţ����಻���ع���$n",
			        "damage":               40,
			        "dodge":                20,
			        "parry":                60,
			        "post_action":  "bash_weapon",
			        "damage_type":  "����"
			]),
			([      "action":           
		"$Nһ������$w���类�������촵�͵�һ�ư��ƣ���ɴһ������$n$l",
			        "damage":               40,
			        "dodge":                10,
			        "parry":                40,
			        "post_action":  "bash_weapon",
			        "damage_type":  "����"
			]),
			([      "action":               
		"$N�趯$w�����з���֮����������Ӱ����һ���Ƶĸ�ǽ�������أ��޿��赲��ײ��$n",
			        "damage":               40,
			        "dodge":                10,
			        "parry":                40,
			        "post_action":  "bash_weapon",
			        "damage_type":  "����"
			]),
	});
}


int help(object me)
{
	write(@HELP   
��������Ұ����longxianyuye��
L0��	һ��������æ��2��
��120��	����������æ��3��
��160��	������������æ��3��
���⹥����=�����ȷ��ȼ�
�����˺���=�����ȷ��ȼ�

HELP
    );
    return 1;
}

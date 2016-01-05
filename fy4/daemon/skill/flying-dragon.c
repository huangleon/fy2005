// flying-dragon.c

inherit SKILL;
void setup() {
	set("name","����̽����");
	set("type","unarmed");
	set("usage/unarmed",1);
	set("effective_level",140);
	set("practice_limit",100);
	set("difficulty",150);
	set("skill_class","yinshi");
	set("parry_msg", ({
        	"$n˫�ּ�ץ$N������$N���е�$w�������ֶ�����\n",
	}) );

	set("unarmed_parry_msg", ({
        	"$n�����ָ�������㣬ָ��ֱ��$N�������Ѩ��\n",
	}) );
	
	action = ({
        ([      "action":               
"$N˫��һ�ӣ�һ�С��������졹���ֻ���$n$l",
                "dodge":                30,
                "parry":                30,
                "damage":                80,
                "damage_type":  "����",
        ]),
        ([      "action":               
"$N��Ӱ���죬ʹһ�С�����ͻ�֡���ת��������$n��$l��ȥ",
                "dodge":                30,
                "parry":                30,
                "damage":                90,
                "damage_type":  "����",
        ]),
        ([      "action":               
"$N���κ�Ȼƽ�ذ���˫��ɢ��������Ӱ��һ�С�������β����$n��$l��ȥ",
                "dodge":                30,
                "parry":                30,
                "damage":                140,
                "damage_type":  "����",
        ]),
        ([      "action":               
"ֻ��$N˫��һ�ڣ�˳������һ�С������㾦����$n��$l��ȥ",
                "dodge":                30,
                "parry":                30,
                "damage":                90,
                "damage_type":  "����",
                "weapon":               "����ʳָ",
        ]),
	});
}


int help(object me)
{
	write(@HELP   
100�����ϣ�ÿ10������1%���ʵ������书���������֡�Ѫ��������һ����
ʹ�ú�û������æ�ң���NOBUSY���ֻ����������3�Ρ�

L10	��������졻��longwujiutian��
������������æ�ң��غ�
���⹥������̽���ֵȼ�
�����˺�����������̽���ֵȼ���������

HELP
    );
    return 1;
}

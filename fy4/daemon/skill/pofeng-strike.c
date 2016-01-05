// pofeng-strike.c
inherit SKILL;

void setup() {
	set("name","�÷���");
	set("practice_limit",100);
	set("usage/parry",1);
	set("damage_level",200);
	set("type","unarmed");
	set("usage/unarmed",1);
	set("effective_level",170);
	set("difficulty",150);
	
	set("skill_class","yinshi");
	
	set("parry_msg", ({
        	"$n����Ϊ����һ�С�������¡�����$N����$w���֡�\n",
        	"$n��һת��һ�С��綯���ҡ�����$N����$w���֡�\n",
        	"$nʹ����ճ���־���˫��һ������ƫ��$N��$w��\n",
	}) );

	set("unarmed_parry_msg", ({
        	"$n����Ϊָ��һ�С����ŭХ������$N������ҪѨ��\n",
        	"$nʩչ�������ŭ�𡹣����赭д�Ļ�����$N�Ĺ��ơ�\n",
	}) );
	
	action = ({
        ([      "action":               
"$Nʹ��һ�С����ÿ�硹�����ƴ����´�������$n��$l",
                "dodge":                30,
                "parry":                10,
                "force":                200,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ��һ�С����ͻϮ�������ƻ���Ϊʵ����$n��$l",
                "dodge":                10,
                "parry":                30,
                "force":                170,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ���÷��Ʒ����綯��ͥ�����εض���$n��ǰ��һ������$n��$l",
                "dodge":                30,
                "parry":                10,
                "force":                150,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N˫��һ��ʹ�������꽻�ӡ�����׼$n��$l�ĳ�һ����Ӱ",
                "dodge":                10,
                "parry":                30,
                "force":                100,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N���ƻ��˸�ȦȦ�������Ƴ���һ�С����ɨҶ������$n$l",
                "dodge":                20,
                "parry":                30,
                "force":                140,
                "damage_type":  "����"
        ]),
	});
}

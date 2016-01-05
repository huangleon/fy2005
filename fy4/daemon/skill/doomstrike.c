// doomstrike.c
inherit SKILL;
void setup() {
	set("name","��������");
	set("damage_level",200);
	set("usage/parry",1);
	set("usage/unarmed",1);
	set("effective_level",160);
	set("type","unarmed");
	set("difficulty",200);
	set("skill_class","fighter");
	
	set("parry_msg", ({
	 	"$n����Ϊ����һ�С���Ѫ��ָ��������$N����$w���֡�\n",
	        "$n˫�ƽ���ʹ��һ�С�ͯ�Ӱ��١�����ž����һ����$N��$w����˫��֮�䡣\n",
	        "$n��һת��һ�С���������������$N����$w���֡�\n",
	        "$nʹ����ճ���־���˫��һ������ƫ��$N��$w��\n",
	}) );

	set("unarmed_parry_msg", ({
	         "$n�������ǣ�һ�С�����Ϊ��������ĳ�ʮ���ƣ��Ƶ�$N�����Ա���\n",
	        "$n����Ϊָ��һ�С���ָ˫�ɡ�����$N������ҪѨ��\n",
	        "$nʩչ������ָ˫�ɡ������赭д�Ļ�����$N�Ĺ��ơ�\n",
	}) );	
	
	

	action = ({
        ([      "action":               
"$Nʹ��һ�С�������ʽ�������ƴ�������$n��$l",
                "dodge":                30,
                "parry":                10,
                "force":                100,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ��һ�С�������ʽ�������ƻ���Ϊʵ����$n��$l",
                "dodge":                10,
                "parry":                30,
                "force":                100,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ�������Ʒ���С����ʽ��������Ȱ�����$n��ǰ��һ������$n��$l",
                "dodge":                30,
                "parry":                10,
                "force":                50,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N˫��һ��ʹ����ѩ����ʽ������׼$n��$l�����ĳ�����",
                "dodge":                10,
                "parry":                30,
                "force":                60,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N���ƻ��˸�ȦȦ�������Ƴ���һ�С��������ķ�������$n$l",
                "dodge":                20,
                "parry":                30,
                "force":                140,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ�����������Ƕϡ�������ɢ���ߴ�ͬʱ��$n��$l���ƹ���",
                "dodge":                70,
                "parry":                10,
                "force":                180,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����������һ�С����������졹˫�Ʋ����Ƴ�",
                "dodge":                270,
                "parry":                340,
                "force":                420,
                "damage_type":  "����"
        ]),
	});
}


inherit SKILL;
void setup(){
	set("name","��ˤ����");
	set("usage/parry",1);
	set("usage/unarmed",1);
	set("effective_level",180);
	set("type","unarmed");
	set("difficulty",200);
	set("practice_limit",100);
	set("skill_class","npc");
	set("parry_msg", ({
      		"$n�ֽ�һ������Ӳ��Ӳ��$N���岽��\n",
	}) );

	set("unarmed_parry_msg", ({
        	"$n������Σ��������$N��Ҫ�������������С�\n",
	}) );	
	action = ({
		([	"action":		"$N���ƻ�һ��Բ��һʽ��������ա�������б������������$n����ǰ��Ѩ",
			"force":		300,
			"parry":		100,
			"damage_type":	"����"
		]),
		([	"action":		"$Nʹһʽ���ƶ����롹�����������������ɺ����һ��˦����ն��$n��$l",
			"force":		300,
			"parry":		200,
			"damage_type":	"����"
		]),
		([	"action":		"$N���ƻ��أ���ȭ�����󷢣�һʽ����������������������$n��$l",
			"force":		300,
			"parry":		200,
			"damage_type":	"����"
		]),
		([	"action":		"$N���Ʊ�������һ������һʽ�����б��¡���˫�Ƽ�����$n�ļ�ͷ",
			"force":		300,
			"parry":		500,
			"damage_type":	"����"
		]),
	});
}


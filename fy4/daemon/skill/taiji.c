// taiji.c by Silencer@fy4 workgroup

#include <ansi.h>
inherit SKILL;

void setup(){
	set("name","̫��ȭ");
	set("type","unarmed");
	set("practice_limit",100);
	set("usage/parry",1);
	set("usage/unarmed",1);
	set("effective_level",200);
	set("damage_level",200);
	set("difficulty",200);
	
	set("skill_class","wudang");
	set("parry_msg", ({
	    "$nһ�С��������ơ���Բ���λ�$N�����ţ��Ƶ�$N��;�������е�$w��\n",
	    "$n����̫����һ�С�§ϥ���������Ƶ�$N����������\n",
	    "$n����Ϊ����һ�С����������������ͻ�$N��$w������\n",
	    "$nһ�С�����Ʊա���˫�Ʋ���Բת������$N����������ת��һȦ��\n",
	}) );

	set("unarmed_parry_msg", ({
	    "$nһ�С�ʮ���֡����Ƶ�$N��;���С�\n",
	    "$n�����������Ծ��ƶ���һ�С�������ɽ������$N������Զ��\n",
	    "$n����������������ʹ��̫��ȭ�ġ�����ʽ��������׾ٵؽ�$N���ڳ��⡣\n",
	    "$n˫�������ʹ��̫��ȭ���һʽ�����޺�̫������$N�Ĺ�������ţ�뺣����ʧ����Ӱ���١�\n",
	}) );	
	action = ({
	    ([ "action":
	    		"$N˫��Բת��ʹ��һ�С�����β������׼$n��$l����",
	     	"dodge":30,
	     	"parry":150,
	     	"damage":300,
	     	"damage_type":"����"
		]),
	    ([ "action":
	    		"$N������Σ����ƻ���һ��Բ����һ�С����ޡ�����$n��$l�к���ȥ",
	     	"dodge":20,
	     	"parry":120,
	     	"damage":300,
	     	"damage_type":"����"
		]),
	    ([	"action":	
	    		"$Nһ�С��׺����᡻��˫�Ƴ�Բ��������Բת����$n��$l����",
	     	"dodge":20,
	     	"parry":120,
	     	"damage":300,
	     	"damage_type":"����"
		]),
	    ([ 	"action":
	    		"$N����������������ʹ��һ�С��ֻ����á���˫��������$n��$l��£",
	     	"dodge":20,
	     	"parry":120,
	     	"damage":300,
	     	"damage_type":"����"
		]),
	    ([  "action":
	    		"$N�����������£��ұ�΢����һ�С�������ɽ������$n��$l��ȥ",
	     	"dodge":20,
	     	"parry":120,
	     	"damage":300,
	     	"damage_type":"����"
		]),
	    ([ 	"action":
	    		"$N˫�־��¸�����������ǰ����ʮ��״��һʽ��ʮ���֡���$n��$l��ȥ",
	     	"dodge":20,
	     	"parry":120,
	     	"damage":300,
	     	"damage_type":"����"
		]),
	    ([ 	"action":
	    		"$N���̤һ���鲽��˫�ֽ����ʮ��ȭ��һ�С��������ǡ�����$n��$l��ȥ",
	     	"dodge":20,
	     	"parry":120,
	     	"damage":300,
	     	"damage_type":"����"
		]),
	    ([ 	"action":
	    		"$N��������ڳ���ʹһ�С���������$n��$l�����Ŵ�ȥ",
	     	"dodge":20,
	     	"parry":120,
	     	"damage":300,
	     	"damage_type":"����"
		]),
	    ([ 	"action":
	    		"$N˫����ȭ�����ֻ����������ʣ����ֻ�����ǰ�Ƴ���һ�С��乭�仢��ֱ��$n���Ѷ�ȥ",
	     	"dodge":20,
	     	"parry":120,
	     	"damage":300,
	     	"damage_type":"����"
		]),
	});
}


int valid_learn(object me)
{
    	object ob;
    	if( (int)me->query_skill("changelaw",1) < (int)(me->query_skill("taiji",1))){
        	return notify_fail("ѧϰ̫��ȭ��Ҫ��ͬ�ȼ����׾���������\n");
		}
	return ::valid_learn(me);
}


//	������ǧ��

mapping ob_hit(object ob, object me, int damage) {
	
	string msg;
	int myexp, yourexp, skill, bonus;
	object weapon;
	mapping data = ([]);
	
	skill = me->query_skill("taiji",1);
	bonus = (me->query_skill("incarnation",1) -300)/10;
	if (bonus > 5 ) bonus = 5;
	else if (bonus <0 ) bonus =0;
	
	if (userp(me)) {	// For Players
		if (!me->query_temp("pfm/taiji_siliang") && 
				(skill < 180	
				||	me->query("class")!="wudang"
				|| me->query_skill_mapped("iron-cloth")!= "incarnation"
				|| me->query_skill("incarnation",1) <= 250
				|| random(20)< 15 - bonus ))
			return 0;
	} else {			// For NPCs
		if (!me->query_temp("pfm/taiji_siliang") && 
				(skill < 100	
				|| me->query("class")!="wudang"
				|| me->query_skill_mapped("iron-cloth")!= "incarnation"
				|| me->query_skill("incarnation",1) <= 250
				|| random(20)< 15 - bonus ))
			return 0;
	}

	switch (random(6))	{			
		case 0:		msg = HIY"$n˫�ְ�һ�С�Ұ����ס�����Ȧ��Χ����$N�ľ���Ϥ��жȥ��\n"NOR,
				damage = - damage;
				break;
		case 1:
		case 2:		msg = CYN"$n����������������˫��������£����$N�ľ�����ȥ��һ��롣\n"NOR;
				damage = - damage*3/4;
				break;
		default:		if (weapon = ob->query_temp("weapon"))
					msg = YEL"$n����ת��һ�С�ת�����������"+ weapon->name()+YEL"�ϣ���$N������ж��һ��!\n"NOR;
				else
					msg = YEL"$n����ת��һ�С�ת�����������$N������ж��һ��!\n"NOR;
				damage = - damage/2;
	}
	if (msg && stringp(msg)) {
		data["damage"] = damage;
		data["msg"] = msg;
		return data;	
	} else
		return 0;
}

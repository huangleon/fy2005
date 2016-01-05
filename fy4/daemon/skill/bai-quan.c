// bai-quan.c
#include <ansi.h>
inherit SKILL;

void setup() {
	set("name","�׼�ȭ��");
	
	set("type","unarmed");
	set("effective_level",150);
	set("usage/unarmed",1);
	set("usage/parry",1);
	set("skill_class","shenshui");
	set("difficulty",150);
	set("practice_limit",1);
 	set("parry_msg", 		({
	        "$nһ�С�������������ͻ�$N�����ţ��Ƶ�$N��;�������е�$w��\n",
	        "$n��ȭ��ϣ���ȭһ�С����ɳ²֡����Ƶ�$N����������\n",
	        "$n����Ϊ����һ�С�����Ϊ�������ͻ�$N��$w������\n",
	        "$nһ�С�����ѿǡ�������һ��$N��$w���֣���ƫ��$N��$w��\n",
							})
	);
	set("unarmed_parry_msg",({
	        "$nһ�С�������������Ƶ�$N��;���С�\n",
	        "$n����������һ�С����׳�н������$N֮�ؾȡ�\n",
	        "$n��ȭ���£���ȭ�Ա���һ�С����ų�塹����$N���ڳ��⡣\n",
	        "$n˫ȭ�����ʹ��һ�С�һ��˫�񡹣�$N�Ĺ�������ţ�뺣����ʧ����Ӱ���١�\n",
							})
	);
					   
 	action = ({
			([	"action":		"$Nʹһ�С����ɹ��¡�����׼$n��$l��������һȭ",
				"dodge":		40,
				"parry":		40,
				"damage_type":	"����"
			]),
			([	"action":		"$N����ȭͷ��һ�С���ѩ��÷������$n��$l�к���ȥ",
				"dodge":		30,
				"parry":		30,
				"damage_type":	"����"
			]),
			([	"action":		"$N������Σ���ȭ���������Ρ���$n��$l����",
				"dodge":		30,
				"parry":		30,
				"damage_type":	"����"
			]),
			([	"action":		"$N����һ������ȭ��������ȭʹ������ɽ����������$n$l",
				"dodge":		30,
				"parry":		30,
				"damage_type":	"����"
			]),
	});
}


int valid_learn(object me)
{
	return notify_fail("������˵������ȭ��̫����ǳ���㲻ѧҲ�ա�\n");
	
	if( me->query_skill("nine-moon-spirit",1)<70)
		return notify_fail("�������������ӿ��˿��㣬˵�����Ů������һЩ�������Ұգ���70������\n");

	if (me->query_skill("nine-moon-claw",1) < 200 && me->query_skill("bai-quan",1) >= 198 )
		return notify_fail("�������������ӿ��˿��㣬˵�������ȰѾ�����ץ���ã����ٴ���׼�ȭ���С�\n");
	
	return ::valid_learn(me);
}


void skill_improved(object me)
{
    	int s;
    	s = me->query_skill("bai-quan", 1);
		if (me->query("class") == "shenshui") {
	    	if (s == 100 ) {
	    		tell_object(me,WHT"������˰׼�ȭ�ľ��ľ���jingxin����\n"NOR);
	    		me->set("pfm/baiquan-jingxin",1); 
	    	} 
	    	
	    	if (s == 200) {
	    		tell_object(me,WHT"��㡢���������򡢾���Ͷ�㣬��ƽ����ȭ��������ζ���\n"
	    				"��ľ�����ץ�Ĺ����ٳ߸�ͷ������һ����\n"NOR);
	    		me->set("pfm/baiquan-9moon",1); 
	    	}
    	}
    	return;
}


int help(object me)
{
	write(@HELP   
��ϰ�׼�ȭ��Ҫ70�����Ů�񹦣�L198��������ҪL200��������ץ��
200����߾����׹�ץ��ϵ����210

�����ľ�����jingxin��
��100���׼�ȭ���ķ�����������ˣ�ÿ�κķ�300������
�ظ���ĿΪ�׼�ȭ����ƽ�ڹ��ȼ�֮�͡�
HELP
    );
    return 1;
}

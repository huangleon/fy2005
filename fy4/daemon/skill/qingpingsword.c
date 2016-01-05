// qingpingsword.c
#include <ansi.h>
inherit SKILL;
void setup(){
	set("name","��ƽ����");
	set("type","sword");
	set("usage/sword",1);
	set("usage/parry",1);
	set("skill_class","shenshui");
	set("effective_level",175);
	set("practice_limit",1);
	set("difficulty",150);

	set("parry_msg", ({
	        "$nʹ��һ�С�������졹�����е�$v����һ�����磬�Ŀ���$N��$w��\n",
	        "$nʹ�����⡹�־�����$N��$w�������⡣\n",
	        "$nʹ��һ�С�������ѩ�������е�$v��������ѩӰ��������$N��$w��\n",
	        "$n���е�$vһ����һ�С����ش��ס�����$N��$w��������ȥ��\n",
	}) );

	set("unarmed_parry_msg", ({
	        "$n�����е�$v����ܲ�͸�磬��ס��$N�Ĺ��ơ�\n",
	        "$n����һ�С��������ա�����������ʧ��һ�Ž���֮�С�\n",
	        "$nʹ��һ�С�������졹��$vֱ��$N��˫�֡�\n",
	        "$n�����е�$v���������������ȵ�$N�������ˡ�\n",
	}) );
	action = ({
        ([      "action":               
"$Nʹһ�С����·ת��������$w��һ�����߰����$n��$l",
                "dodge":                20,
                "damage":               80,
                "force":                200,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nʹ����ƽ�����еġ���ɽ������������ն��$n��$l",
                "dodge":                20,
                "damage":               120,
                "force":                100,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$Nһ�С�������С������ζ�Ȼ�������ߣ�����$wն��$n��$l",
                "dodge":                30,
                "damage":               80,
                "force":                100,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w�й�ֱ����һʽ�����ն�������׼$n��$l�̳�һ��",
                "dodge":                40,
                "damage":               70,
                "force":                60,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����һԾ������$wһ�С����к�ء���׼$n��$lбб�̳�һ��",
                "dodge":                40,
                "damage":               100,
                "force":                60,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N��$wƾ��һָ��һ�С�ͯ����·������$n��$l",
                "dodge":                20,
                "damage":               150,
                "force":                120,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N����$w����һ�֣�ʹһ�С��������������ֶ�׼$n$lһ����ȥ",
                "dodge":                20,
                "damage":               110,
                "force":                180,
                "damage_type":  "����"
        ]),
        ([      "action":               
"$N�ὣ��ǰ������һת����$wʹһ�С��չ���硹����һ���⻡ն��$n��$l",
                "dodge":                30,
                "damage":               80,
                "force":                110,
                "damage_type":  "����"
        ]),
	});
}


int valid_learn(object me)
{
	if(me->query_skill("nine-moon-spirit",1)<115)
		return notify_fail("�������������ӿ��˿��㣬˵�����Ů������һЩ�������Ұգ���115����\n");

	return ::valid_learn(me);
}

void skill_improved(object me)
{
    	int s;
    	s = me->query_skill("qingpingsword", 1);
		if (me->query("class") == "shenshui") {
	    	if (s > 100  && s<= 200 && s%10 ==0 ) {
	    		tell_object(me,WHT"��������ȥ���̡��ġ���������������ֻ����ѧ֮����һ·ͨ����·ͨ��\n"
	    				  "����ƽ����֮Ʈ�ݣ����������֮��������һ·��\n"
	    				  "��ľ������������һ������\n"NOR);
	    		if (s == 200)
	    			tell_object(me,WHT"���Ѿ����׽���ƽ��������������ڻ��ͨ�ˣ�\n"NOR);
	    		me->set("pfm/qingpingsword-9moon",(s-100)); 
	    	} 
	    	
/*	    	if (s == 100) {
	    		tell_object(me,WHT"��ֻ����ѧ֮����������ͨ������ƽ�����ġ����־�����������ھ��������С�\n"
	    				"��ѧ���˾��������ġ���ɺ�̶����\n"NOR);
	    		me->set("pfm/9moon-yanduhantan",1); 
	    	}	    	if (s == 140) {
	    		tell_object(me,WHT"���������ͻ��������ƽ�����ġ����־��������ɲ��롺˪���ϼ��������֮�С�\n"
	    				"��ѧ���˾��������ġ���Ⱦ���ơ���\n"NOR);
	    		me->set("pfm/9moon-yirancangyun",1); 
	    	}*/
    	}
    	return;
}

int skill_difficulty()
{
	object me = this_player();
	int skill,n;
	if (me && userp(me))
	{
		skill = me ->query_skill("qingpingsword",1);
		if (skill < 150)
			return 150;
		else
			return 200;
	}
	return 200;
}


int help(object me)
{
	write(@HELP   	
��ƽ�����ɴӰ����մ�ѧ�ã�����Ϊ115���Ů��
L100-L150���𲽣�ÿʮ����������������ϵ����100��ߵ�150
L155-L200���𲽣�ÿʮ����������������ϵ����150��ߵ�175
��L150����ѧϰϵ������Ϊ200��
HELP
    );
    return 1;
}

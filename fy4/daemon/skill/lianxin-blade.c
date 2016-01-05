//TIE@FY3
//lianxin-blade.c
inherit SKILL;
#include <ansi.h>

void setup() {
	set("name","����Ӱ�ֵ���");
	set("skill_class","shaolin");
	set("type","blade");
	set("effective_level",150);
	set("usage/blade",1);
	set("usage/parry",1);
	
	set("practice_limit",100);
	set("damage_level",200);
	set("difficulty",200);
		
	set("parry_msg", ({
        	"$nʹ��һ�С�����������������е�$v������������$N��$w��\n",
		"$n����$v�����������⣬����ɭɭ��һ�С������¹�����������Ӳ��滮��$N֮�ؾȡ�\n",
		"$n����ת�������е�$v�⻪������һ�С��������ɰ���ơ�������$N��$w��\n",
	}) );

	set("unarmed_parry_msg", ({
		"$nʹ��һ�С���ţ�뺣�沨ɢ�������е�$v��Ȼ������$N�Ĺ����沨��ɢ��\n",
		"$nվ�����Σ�����$v���Ⱪ����һ�С���ұ����ɫ���⡹����ס$N����ʽ��\n",
		"$n���е�$v���л�ʽ���������ࡣ\n",
	}) );
	
	action = ({
		([	"action":		
		"$Nʹһ�С������ˮ�����ס�������$w��������б������ɳ��ʯ����ס$n�Ķ�Ŀ������һ������$n��$l��",
			"dodge":		180,
			"parry":		170,
			"damage_type":	"����"
		]),
		([	"action":		
		"$N���μ�ת�������˶���$w����һ�С�������ɼ��ѡ������������$n��$l��ȥ��",
	                "dodge":                160,
	                "parry":                260,
			"damage_type":	"����"
		]),
		([	"action":		
		"$N����Ծ���ն�����$w��һ�С������˺������ڡ����������$n��$l",
	                "dodge":                170,
	                "parry":                250,
			"damage_type":	"����"
		]),
		([	"action":		
		"$N����$w�趯���������ƣ�һ�С����ƴ��������Ρ���������˷�������$nɱȥ��",
	                "dodge":                170,
	                "parry":                240,
			"damage_type":	"����"
		]),
		([	"action":		
		"$N����$w����ƬƬ���⣬һ�С��ĵس�Ʈ����ѩ����ƮƮ������$n��ȥ",
	                "dodge":                170,
	                "parry":                220,
			"damage_type":	"����"
		]),
		([	"action":		
		"$N�����ĳ����Ʒ����ң�����Ϯ�ˣ�����$w������ʹ⻪��һ�С����ڷ�����ɫ����ֱ��$n$l",
	                "dodge":                170,
	                "parry":                210,
			"damage_type":	"����"
		]),
		([	"action":		
		"$Nʹһ�С�������������ɡ�������$w��ת�������������ն��$n��$l",
	                "dodge":                270,
			"damage_type":	"����"
		]),
	});
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
    	object ob;
    	if( random(damage_bonus) < 250 ) return 0;
    	if(ob=victim->query_temp("weapon"))
    	if(ob->query("skill_type") == "axe")
    	if(victim->query_skill_mapped("axe") == "xuanyuan-axe"  )
    	if(me->query_skill("lianxin-blade",1)+50 > victim->query_skill("xuanyuan-axe",1)) {
    	switch(random(3)) {
            	case 0:
                    message_vision(HIR "\n$N�ϵл��ȣ�����ռ���Ϸ磡" NOR,me,victim);
                    break;
            	case 1:
                    message_vision(HIR "\n$N����׾ٵ�����$n�Ŀ�϶֮�䣡" NOR,me,victim);
                    break;
            	case 2:
                    message_vision(HIR "\n$N����ƫ�棬$n��ʩչ�����ˣ�" NOR,me,victim);
                    break;
                    }
    		return random(me->query_skill("blade")) * 2;
    	}
    	return 0;
}

int help(object me)
{
	write(@HELP  
��һƬ���ġ���yipianlianxin���Ͷ����е�ͬ��һ�𹥻�����
ʹ�÷�����perform yipianlianxin ������ with ͬ����
һ��5�С��������˺���lianxin-blade�ӳ�
HELP
    );
    return 1;
}
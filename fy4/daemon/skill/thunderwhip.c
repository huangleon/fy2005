// thunderwhip.c

#include <ansi.h>

inherit SKILL;
void setup(){
	set("name","������");
	set("practice_limit",100);
	set("type","whip");
	set("usage/whip",1);
	set("usage/parry",1);
	set("effective_level",160);
	set("difficulty",200);
	set("skill_class","yinshi");
	
	set("parry_msg", ({
        	"$nһ��ת�գ����μ�ʽ�������ߣ������������ޡ�̫����������β��������һ�����棬��סȫ��\n",
		"$nһ�С���������������������ֱ��$N���е�$w\n",
		"$n�ұ����һ�ڣ����е�$v��ǰ�������Ӱ��ѩ������ס��$N��\n",
		"$n��̤�����λ�λ���ÿ���һ�С�\n",
	}) );

	set("unarmed_parry_msg", ({
	        "$nһ��ת�գ����μ�ʽ�������ߣ������������ޡ�̫����������β��������һ�����棬��סȫ��\n",
	        "$n�ұ����һ�ڣ����е�$v��ǰ�������Ӱ��ѩ������ס��$N��\n",
	        "$n��̤�����λ�λ���ÿ���һ�С�\n",
	}) );
	
	action = ({
		([
			"action":		
			"$N��߳һ����˫�ֲ��٣����ⶸ�ɣ���ʱ�˱޺�һ�����ֱ��$n��ȥ",
			"dodge":		100,
			"damage":		60,
			"damage_type":	"����"
		]),
		([
			"action":		
			"$N���б�Ӱէ�ţ��������ص�⣬��̫�ſ��졻��Ȼ��ɨ",
			"dodge":		500,
			"damage":		40,
			"damage_type":	"����"
		]),
		([
			"action":		
			"$N��ʽһ�䣬ɱ���Ĳ���չ������������ȥ�޻ص�ɱ�С�̫�ŷ���˵���ԡ�",
			"dodge":		400,
			"damage":		150,
			"damage_type":	"����"
		]),
		([
			"action":	        
			"$NԾ�����ɣ����ڰ�գ���ʽ���䣬��̫���������羪�κ��ˣ���ת�������",
			"dodge":		400,
			"damage":		60,
			"damage_type":	"����"
		]),
	});
}


mixed hit_ob(object me, object victim, int damage_bonus)
{
    	object ob,weapon;
    	int cele;
    
    	if( random(damage_bonus) < 250 ) return 0;
    	if(ob=victim->query_temp("weapon"))
    	if(ob->query("skill_type") == "hammer")
    	if(victim->query_skill_mapped("hammer") == "pangu-hammer"
     		||victim->query_skill_mapped("hammer") == "assassin-hammer"
     		||victim->query_skill_mapped("hammer") == "liuxing-hammer")
    
    	if(me->query_skill("whip")+100 > victim->query_skill("hammer")) {
    	switch(random(3)) {
            case 0:
                    message_vision(HIR "\n���书·����ˣ�$Nռ�����Ϸ磡" NOR,me,victim);
                    break;
            case 1:
                    message_vision(HIR "\n$N����׾ٵ�����$n�Ŀ�϶֮�䣡" NOR,me,victim);
                    break;
            case 2:
                    message_vision(HIR "\n��޴�����ˣ�$n��ʩչ�����ˣ�" NOR,me,victim);
                    break;
                    }
    	return random(me->query_skill("whip")) * 2;
    	}
    	return 0;
}

int damage_level(object me)
{
	int add, n;
	if (me) {
		//	thunder_add 1-10 -> 2%-20% add
		add = F_ABILITY->check_ability(me,"thunderwhip_add",2) *20;
		return add;
	}
	return 0;
}

int help(object me)
{
	write(@HELP   
����Ч�����Ƶȼ������̹ž�ʽ�����Ǵ��������˴�����ʱ�п���ЧӦ��

������һ����(Tianleiyiji)
�Ե��������Ѫ�˺�������æ������
L50������
L200������
���⹥����=�����Ƶȼ�
�����˺���=�����Ƶȼ�

����������yunlongjiuxian��
��Ҫ110�������ױ޷�����ͨ�콵����������޷��й������˵ľ�����
�������ʺ�ɱ��������Ч��ͷ���ĵȼ����
���ؼ���ħ������������������
���������֡�����110��ͨ�콵������æ��3��
���������֡�����160��ͨ�콵������æ��4��
���������֡�����200��ͨ�콵��200��Ǭ�����Σ�����æ��4��

HELP
    );
    return 1;
}

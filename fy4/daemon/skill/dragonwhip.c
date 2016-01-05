// dragonwhip.c
// ; annie 7.1

#include <ansi.h>

inherit SKILL;
void setup(){
	set("name","��������޷�");
	set("type","whip");
	set("usage/whip",1);
	set("effective_level",210);
	set("practice_limit",100);
	set("practice_force",10);
	set("difficulty",200);
	set("skill_class","demon");
	action = ({
		([
			"action":		
			"$N��һ�С��������ơ�������Χ$n���ܼ�ת��������ֻ������˷����Ǳ�Ӱ����\n���ѽ�$n������·",
			"dodge":		100,
			"damage":		60,
			"damage_type":	"����"
		]),
		([
			"action":		
			"$N����һת��һ�С����ս�����������$w��������ڿ�һ���͵���$n��ͷ����",
			"dodge":		500,
			"damage":		40,
			"damage_type":	"����"
		]),
		([
			"action":		
			"$N�����Ṧ��$n��Χ��ת��Ȧ����$n�ۻ�����֮�ʣ�һʽ���������桻����$n",
			"dodge":		400,
			"damage":		150,
			"damage_type":	"����"
		]),
		([
			"action":	        
			"$Nʹ����������Ұ�����ߵ���âһ������������ӥ�������������֮�ƣ�����Ʈ��Ĵ���$n",
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

int help(object me)
{
	write(@HELP   
��������޷��������д���

L50������ǧ�𡻣�thousandfeather��
�趯���޻���ǧ���������������ж��֣�������һ������ʹ����æ�ҡ�
�����˺����ܲ��ȶ�������æ��2-3�֡�

		
L165��������ҡ���firestorm��
�Գ��޴������湥�����ܶ��֣�����æ������
���⹥����=��������޷��ȼ�
�����˺���=��������޷�*2
������������ʮ�ֳ����˺���ÿ���ּ��2-3�غ�
�˺���ԼΪrandom(��������޷��ȼ�*5)

HELP
    );
    return 1;
}

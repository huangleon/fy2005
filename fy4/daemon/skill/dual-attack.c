//	by silencer@fy@, 9/10/02

inherit SKILL;

void setup() {
	set("name","����֮��");
	set("type","martial");
	set("skill_class","basic");
	set("difficulty",200);
	set("effective_level",200);
}


int valid_learn(object me)
{
	if( me->query_skill("combat_exp") <= 5000000 )
		return notify_fail("����书��Ϊ����������޷�ѧϰ����֮����\n");
	return 1;
}

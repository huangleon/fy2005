inherit SKILL;

void setup() {
	set("name","�߼���Ծ����֮��");
	set("practice_limit",100);
	set("skill_class","basic");
	set("difficulty",400);
	set("effective_level",200);
	set("type","martial");
}


int valid_learn(object me)
{
	if( me->query("combat_exp") <= 5000000 )
		return notify_fail("����书��Ϊ����������޷�ѧϰ�߼���Ծ����֮����\n");
	return 1;
}

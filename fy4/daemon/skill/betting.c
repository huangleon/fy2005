// betting.c
inherit SKILL;

void setup() {
	set("name","�Ĳ�֮��");
	set("skill_class","basic");
	set("effective_level",100);
	set("difficulty",100);
	set("type","knowledge");
	set("usage/stealing",1);
	
}



int valid_learn(object me) {
	if( (int)me->query_skill("betting") >=  10  && me->query("class")!="beggar") {
		return notify_fail("�Ĳ�֮����������̶�ֻ�ܴ�ʵ������ߡ�\n");
	}

	return 1;
}


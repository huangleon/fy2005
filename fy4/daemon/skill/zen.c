// buddhism.c
inherit SKILL;

void setup() {
	set("name","����");
	set("skill_class","shaolin");
	set("difficulty",200);
	set("type","knowledge");
	set("effective_level",200);
	set("usage/literate",1);
	set("no_refund",({"yijinjing"}));
}

int valid_learn(object me) {
	if(!::valid_learn(me)) {
		return 0;
	}
	if( (int)me->query("bellicosity") > 100 )
		return notify_fail("���ɱ��̫�أ��޷�����������\n");
	return 1;
}

/*
int learn_bonus() {
	
	if(this_player()->query_skill("zen",1)<=165)
		return -50;
	return -400;
}

	Don't forget about difficulty changes.
*/


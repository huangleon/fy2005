// xiaochengforce.c

inherit SKILL;

void setup(){
	set("name","С���ľ�");
	set("type","force");
	set("usage/force",1);
	set("effective_level",140);
	set("difficulty",150);
	set("skill_class","shaolin");
}


int valid_learn(object me){
	if((int)me->query("bellicosity") > (int)me->query_skill("xiaochengforce",1)* 50 ) {
        	return notify_fail("���ɱ��̫�ߣ��޷�����������С���ľ���\n");
	}
	return 1;
}

int help(object me)
{
	write(@HELP   
����������mingjing��������
HELP
    );
    return 1;
}

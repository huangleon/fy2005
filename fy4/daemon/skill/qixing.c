// TIE@FY3

inherit SKILL;
void setup(){
	set("name","���Ƿ�");
	set("type","spells");
	set("usage/spells",1);
	set("effective_level",100);
	set("skill_class","wudang");
	set("difficulty",200);
}	


int valid_learn(object me)
{
    	object ob;
    	if( (int)me->query_skill("changelaw",1) < (int)(me->query_skill("qixing",1))){
        	return notify_fail("ѧϰ���Ƿ���Ҫ��ͬ�ȼ����׾���������\n");
		}
	return ::valid_learn(me);
}


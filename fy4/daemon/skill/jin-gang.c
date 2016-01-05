// jin-gang.c
inherit SKILL;
void setup() {
	set("name","��ղ�����");
	set("type","iron-cloth");
	set("usage/iron-cloth",1);
	set("effective_level",150);
	set("ic_effect",100);
	set("bounce_ratio",10);
	set("difficulty",250);
	set("skill_class","lama");
	set("absorb_msg", ({
	        "$n˫��һ�𣬽�ղ������������Ƶ����ȶ�����\n",
	        "$nʩչ����ղ������еġ������־���һ�ɵ�������$N�����ڡ�\n",
	        "$nʹ��һ�С��ຣ���ġ�������Ϊʵ������Ӳ���ա�\n",
	        "$nʩչ����ղ��������Կ�$N��һ��֮����\n",
	}) );
}


int valid_learn(object me)
{
	if( (int)me->query_skill("lamaism",1) <= (int)me->query_skill("jin-gang",1)) {
		return notify_fail("������ڷ���Ϊ�������޷����������Ľ�ղ�������\n");
	}
	return 1;
}

int effective_level(object me)
{
	if (me)
	if (userp(me) && me->query("class") != "lama")
		return 75;
		
	return 150;
}


int help(object me)
{
	write(@HELP   
L150����ǹ���롻��daoqiangburu��
��ȥ���˶�������Ѫ�˺��Ĳ������ַ�������

HELP
    );
    return 1;
}

// liuquan-steps.c
inherit SKILL;
void setup() {
	set("name","��Ȫ����");
	set("practice_limit",100);
	set("type","step");
	set("difficulty",200);
	set("usage/dodge",1);
	set("usage/move",1);
	set("effective_level",150);
	set("skill_class","huangshan");
	set("dodge_msg", ({
		"$nһ�С�����ֱ�¡�����һƮ��������٣�ֱ�˳�����֮�⡣\n",
		"$n�������棬��Ӱ�����������һʽ�������̻����ܿ�$N�ķ�â��\n",
		"$n�ڿն��������ڿ���������������һʽ��һ�����ۡ����������ɵ�������\n",
		"$n�������࣬���������ζ���һ�С�Ϫˮ�������ڿն��𣬱��˿�ȥ��\n",
		"$n������ˮ������Ծ�����ߣ�һ�С�ϸˮ����������������Ʈ�˿�ȥ��\n",
		"$n����һ����ȴͻȻ�ڿ�Ծ�𣬡������Ȫ������������\n",
		"����$nһ�С�ˮ��ɽ�ʹ���������Ƶ�$N���ᣡ\n",
   		 "����$n����Ʈ��������һ�ݣ�һ�С������΢�����ܿ���һ����\n",
        	"$n��������һ�Σ�һ�С���ˮ���ա���һ��ת����������֮�⡣\n",
	}) );
}

int valid_learn(object me)
{
	object ob;
	
	if(!::valid_learn(me)) {
		return 0;
	}
	if (me->query("class")!="huangshan")
		return notify_fail("�㻹����ѧ�����书��\n");
	if( (int)me->query("max_force") < 500 ) {
	        return notify_fail("�������������û�а취����Ȫ������\n");
	}
	 return 1;
}

int practice_skill(object me)
{
        return notify_fail("��Ȫ����ֻ��ѧ�ġ�\n");
}

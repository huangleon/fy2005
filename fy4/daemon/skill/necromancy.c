// necromancy.c

inherit SKILL;
void setup(){
	set("name","�������");
	set("type","spells");
	set("usage/spells",1);
	set("skill_class","taoist");
	set("practice_limit",100);
	set("effective_level",220);
	set("difficulty",250);

}	

int valid_learn(object me)
{
	if( (int)me->query_skill("taoism",1) < (int)me->query_skill("necromancy",1))
		return notify_fail("�����ʦ������Ϊ�������޷��������������������\n");
	return 1;
}

int practice_skill(object me)
{	
	object bug;
			
	if( bug = me->query_temp("mind_bug") )
		return notify_fail("��Ļ��ǻ�û��ȫ���ջأ��Ͽ�ɱ�����"
			+ bug->name() + "�ɣ�\n");

	if( (int)me->query("mana") < 10 )
		return notify_fail("��ķ���������\n");

	if( (int)me->query("sen") < 30 )
		return notify_fail("��ľ����޷����С�\n");

	me->add("mana", -10);
	me->receive_damage("sen", 30);

	write("���Ŀ�����������⣬��ʼ��ϰ��������еķ���....\n");
	if( random((int)me->query("sen")) < 5 ) {
		int rnd;

		rnd = random(me->query_skill("spells", 1));
		if( rnd < 10 )	bug = new("/obj/npc/mind_bug");
		else			bug = new("/obj/npc/mind_beast");

		write("��������˼һ�ң������һֻ��Ŀ������" + bug->name() + "��\n");
		bug->move(environment(me));
		bug->set("combat_exp", (int)me->query("combat_exp")+100);
		bug->kill_ob(me);
		me->fight(bug);
		me->set_temp("mind_bug", bug);
		bug->set("owner", me->query("id"));
		return notify_fail("��Ļ�������" + bug->name() + "��ס������������ɣ�\n");
	}	
	else return 1;
}

int help(object me)
{
	write(@HELP   
L10 �����ۣ�vision����
���Լ�/���ѿ��������

L20 ��ڤ֮����netherbolt��
�������˵���Ѫ�������е�50%ת�����������徫�������������н�����һ��

L40 ����֮����drainerbolt��
�������˵ľ����������е�50%ת������

L60 ����֮����feeblebolt��
�������˵����񣬽����е�50%ת������

L80 ����֮����healbolt��
��������Ѫת�Ƹ�ÿ�����ѣ��������120�����£�������Ѫ�������*5��
120�����ϣ�������Ѫ�������*10���ķѷ���300�㡣                    
      
L100 ���ħ��thunderbolt��
�������е��˵����񣬶Թ���ɱ�����ӱ���

L135 ȼ����棨demonicbolt��
�˺�����������һ��Bolt���������ɱ�������󣬵���ʹ��ǰ��3��׼������
���ڼ�����ܵ��˺������������

L170 ���ײԻ���thunderstorm��
�������е��˵����񣬶Թ���ɱ�����ӱ�����ȼ��������ƣ���ʹ��ǰ������
׼��������ܵ��˺������������

HELP
    );
    return 1;
}

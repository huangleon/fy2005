// scratmancy.c
inherit SKILL;

void setup() {
	set("name","�������");
	set("type","scratching");
	set("difficulty",250);
	set("effective_level",200);
	set("practice_limit",100);
	set("usage/scratching",1);
	set("skill_class","taoist");
}

int valid_learn(object me) {
	if((int)me->query_skill("taoism",1) < (int)me->query_skill("scratmancy",1)) {
		return notify_fail("�����ʦ������Ϊ�������޷��������������������\n");
	}
	
	return 1;
}

int practice_skill(object me)
{	
	object bug;
	
	if( bug = me->query_temp("mind_bug") )
		return notify_fail("��Ļ��ǻ�û��ȫ���ջأ��Ͽ�ɱ�����"+ bug->name() + "�ɣ�\n");

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
		else		bug = new("/obj/npc/mind_beast");

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
���к�ң���ࣺ
L20 ��������earth-warp���ظ�����
L35 ���۷���far-vision��ң�е���
L50 �Ŷݷ���drift-warp�����е��ж�֮�����ο����ɰ�����
		�����ȼ�Խ�ߣ��ܸ�Ӧ���Ķ���Խ��

�й��ֻࣨ��ͬʱ�г�һ����,�ٻ��޵ľ���ȼ�ȡ���������Ч������
����ȡ������ļ��ܣ�ѩӰ������̤ѩ�޺۵ȵȣ���
L30 �ٹ����zhaogui��
�ٻ����䣬������Ѫ�������Եͣ���ʹ�ð�ѩ����
L100 �쎟����tianshi��
�ٻ�����������Ѫ�����˸ߣ���ʹ�������ѩ����������ע��
L160 �Ͼ�����shangjun��
�ٻ��������Ѫ�ܵͣ�����ʹ�÷�����������
L195 ��������jisi�� 
�ٻ��޳�����Ѫ�������Եͣ���������ȡ������Ѫ����ʹ�÷�����һ��
ʱ���ڽ��ɵ���ʹ���ؼ�
*����ٻ�����ս������ȥ��������������޽�ת������
*�ٻ��޲���ս����ʱ���˿���������������dismiss xxx���ķ�300����

�ָ��ࣺ
L55 ������/ L110 ��Ѫ��/ L160 ��������qi��
L60 ������/ L120 ��Ԫ��/ L170 ���Ƿ���jing��
L65 ���ķ�/ L130 �����/ L180 �������shen��
L70 ������/ L140 �����/ L200 ��������fa��
*ʹ�ûָ���������������裬д����ȼ����ս���У������������һ
�ſ��������ָ���Ӧ������ķ��ˡ�
HELP
    );
    return 1;
}

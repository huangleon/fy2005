// ninjitsu.c

inherit SKILL;

void setup(){
	set("name","����");
	set("type","magic");
	set("difficulty",200);
	set("usage/magic",1);
	set("skill_class","ninja");
	set("effective_level",180);
}

/*
int valid_learn(object me)
{
	object ob;
	
	if(!::valid_learn(me)) {
		return 0;
	}
	if (REWARD_D->check_m_success( me, "���˵ı���" )!= 1) 
		return notify_fail("���ʮ����δ��Ӧת���������书��\n");
	if ((int)me->query("tianfeng/ninjitsu")!=1){
		return notify_fail("���ʮ����δ��Ӧ���������书��\n");
	}
	return 1;
}*/


int help(object me)
{
	write(@HELP   
��׷������conjure zhuiya��
��100���������ķ�300��������ȥ����Χ�����˵�������ʹ��æ�����֡�
��Ӱ������10�������޷���ʹ������
ע�⣬���ؼ�ֻ��Ӱ��������������ܹ���ɱ�Ķ��֡�

����¶����conjure dart��
��150�������������������루�����ڲ�ͬ�ص㣩�������֣����ֲ������
�������ɱ���������ĵ������Ժ��������ھ����������ߣ��޷���ʹ
�ô��������ؼ��������ھ���ֵС������10�����µĶ��֡�
�˺���Ѫ=����Ч����+������ȼ���+ random����Ч����+������ȼ���

����������conjure wuyin��
��200��������ɽ��ˮ��ʱʹ�õ�һ�У����������ڽ���״̬����50%����
ƭ���������������ʧ�ܡ�����������������ܴ���ܾ������������ˡ�
HELP
    );
    return 1;
}

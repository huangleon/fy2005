// essencemagic.c

inherit SKILL;

void setup() {
	set("name","��ʶ��ͨ");
	set("type","magic");
	set("effective_level",150);
	set("difficulty",300);
	set("usage/magic",1);
	set("skill_class","bonze");
}

int valid_learn(object me)
{
	if( (int)me->query_skill("buddhism",1) < 10
	||	(int)me->query_skill("buddhism",1) <= (int)me->query_skill("essencemagic",1) )
		return notify_fail("��ķ���Ϊ����������޷�ѧϰ��ʶ��ͨ��\n");
	return 1;
}


int help(object me)
{
	write(@HELP   
��ʶ��ͨ��ѧϰ��Ҫ��ͬ�ȼ��Ĵ�˷�Ϊ������

L20����ʶ��(soul_sense)  
�ɿ������������ʩ�����������ѡ�

L30����ʶ��(silent_sense)
�ɶ���ظ���������ս����ʹ�á�

L40����ʶ��(mind_sense)
�Է����������ֵ���Ѫ��ÿ�����ٺķ�50���������˺�������Ч��
����ء�200��ʱ���ɽ��Ե����˺���10%ת��Ϊ�����������
  
L60����ʶ��(shade_sense) 
����Χ�����޷�����������٣���ս���м�ս��ֹͣ���2���ڻ���ʱ
ʧЧ��ע�⣬���������е�NPC���ᱻ��ʶ�Ի�
���������ֹͣ��ʶ����ʹ��conjure shade_sense_off��������ÿ
����ֻ��ʹ��һ��.
����ʶ��ʧʱ������������æ�ң����ܵ���ǰ�ص���˵�����������

L60����ʶ��(void_sense)  
���͵��˵Ĺ�������������������ʱ��30�룬��ʧ������æ�����֡�

L90����ʶ��(drift_sense)
�����ڸ��أ�ʹ��ʱconjure drift_sense��Ȼ������Ŀ��NPC��Ӣ��
�������Ƹ��ض���һЩ�ض���NPC����Ϊ��ʶ��Ŀ�꣬�����Լ������ˡ�

L100����ʶ��(heart_sense)
�ظ�������ҵľ�����ʧ��Ψ�����߻���ǰ����ʹ�ã��ķ�����8������
�����ʬ����ʹ�ã�conjure heart_sense on corpse��
��L100:60%;L140:70%;L180:80%;L200:90%��

L120����ʶ��(light_sense)
�������е��ֵ����񣬶Թ��ɱ�����ӱ����ķ�200��������
����æ��2��

L170����ʶ��(team_drift)
Я�����������ڸ��أ����Ķ��йؾ�����ܼ���

HELP
    );
    return 1;
}

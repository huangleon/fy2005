// heart-listening.c
// annie 07.2003
// ��������sen������һ��СС�ô�cast telepathy

inherit SKILL;
void setup(){
	set("name","��������");
	set("difficulty",200);
	set("usage/spells",1);
	set("type","spells");
	set("effective_level",200);
	set("skill_class","moon");
}

int practice_skill(object me)
{	
	return notify_fail("���������޷���ϰ��\n");
}

int help(object me)
{
	write(@HELP   
L40 �����������telepathy��
����֮���໥�������

L80 ���������ޡ���yixinwanghen��
�����˵�����ȫ�����㣬ע���Ⲣ����ֹͣս����
��ֻ������˿�ʼ���ѡ��Ŀ��
ÿ2����ʹ��һ�Ρ�

L120���޷���á���wufangbianhuan��
�ڣ�������������ת�Լ��ٶ�����ɵ�æ�ң�
ÿ������ʹ��һ�Ρ�

L200���������硻��zhaoyuwanqing��
���Ķ��йؾ�������ʹ�á�ÿ30����һ��
����150��������衣�����ؼ���������60�롣
��һ�᣺����6�ι���
�ڶ��᣺����9�ι���
�����᣺����12�ι���
HELP
    );
    return 1;
}


inherit SKILL;
#include <ansi.h>
void setup(){
	set("name","��·����");
	set("type","knowledge");
	set("skill_class","theorem");
	set("usage/theorem",1);
	set("effective_level",100);
	set("difficulty", 30);	
}

/*
int valid_learn(object me)
{

	if (me->query_skill("pathfinding",1) >= me->query_skill("theorem",1))
		return notify_fail("�������֮����򲻹���\n");

	return ::valid_learn(me);
}*/

int help(object me)
{
	write(@HELP   
������������Թ�����Щ�Թ���ϵͳ������ʱ�Զ����ɡ�
������˵�������񣬻��漰���Թ��е�NPC��
�׻�˵����ȥ���׳����ѣ�������ָ��ֽ����Թ������Ҳû�г�������

���ǣ�������ȴ��һ���������ܹ�������ɽ��ˮ��֮ʱ����������	
	
L10���һ��ˡ���taohua�����һ����Թ��жݳ�
L30�������ˡ���xuanwu���ӽ�Ǯ�������жݳ�
L50�������ˡ���xuanbing�� ����˼����������һ��ݳ�
L70������ˡ���guiku�� ���������жݳ�
L90�������ˡ���dilao�� �ӽ�Ǯ�����жݳ�
L110�������ˡ���xuanbinga�� ����˼���������ڶ���ݳ�
L130���޺��ˡ���luohan�� �������޺����жݳ�
L150�������ˡ���jitian������ϼɽɽ���������ݳ�

ʹ�÷�����perform theorem.taohua ....�Դ�����
HELP
    );
    return 1;
}


/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/



inherit SKILL;

void setup(){
	set("name","�������");
	set("type","force");
	set("usage/force",1);
	set("skill_class","berserker");
	set("effective_level",150);
	set("difficulty",200);
}

int help(object me)
{
	write(@HELP   
L0���������ƾ�����damageup��
��ħ��������ɱ��������ȡ������ֵ

l0 ����������������powerup��
��߶��⹥��������߶����˺���
��ֵ=������ȼ�

L200 ������Ͽ��Ҿ���(forceup) 
������enforce�����50%

HELP
    );
    return 1;
}


/*
�X[ ��- FengYun -�� ]���������[
��[dancing_faery@hotmail.com]�������[
��[ ��annie 09.2003�� ]�������a    ��
��[ ������������¶������ʱ������˪ ��
�^��������������������������������-�a
*/

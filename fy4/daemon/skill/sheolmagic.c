// sheolmagic.c

inherit SKILL;
void setup(){
	set("name","ҹ��ͨ�鷨");
	set("type","magic");
	set("difficulty",200);
	set("usage/magic",1);
	set("skill_class","demon");
	set("effective_level",200);
}       

int valid_learn(object me)
{
        return 1;
}


int help(object me)
{
	write(@HELP   
L35��Թ���ٻ�����summon1��
L80�������ٻ�����summon2��
L125��ҹ���ٻ�����summon3��
L170�������ٻ�����summon4��
L215��ħ���ٻ�����summon3��

���������ٻ�ħ�������ޱȣ�ÿһСʱ����ʹ��һ�Σ�
ÿ���ٻ���ֻ����15���ӣ����ã�
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


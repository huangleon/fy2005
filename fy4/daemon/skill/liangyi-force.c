// taijiforce.c

inherit SKILL;

void setup(){
	set("name","�����ķ�");
	set("type","force");
	set("difficulty",250);
	set("usage/force",1);
	set("effective_level",100);
	set("skill_class","task");
}

int help(object me)
{
	write(@HELP   
L100 ������Ʊա���rufengsibi��
��ͼ�����æ�ң�����æ��һ�֣����ɹ�����æ������
ÿ����������= 250 - �����ķ��ȼ�
���ؼ�ʹ��ʱ����enable��ֻ��Ҫʹ������
perform rufengsibi
HELP
    );
    return 1;
}

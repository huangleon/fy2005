
inherit SKILL;

void setup(){
	set("name","ǧ��");
	set("type","knowledge");
	set("skill_class","theorem");
	set("usage/theorem",1);
	set("effective_level",100);
	set("difficulty", 50);	
}


int help(object me)
{
	write(@HELP   
������/2�ȼ�������֮����ѧ�ɺ����߸���ҩ�������Ч�ʣ�
�������������������η��ӡ���С����ҩƷ��
ͬʱҲ����߸����ɻ��������ķ����˹�����ɽ�ȳ��⣩��Ч�ʡ�
��������ѧ�á�

ҩ������Ч��=ҩ�ﱾ����Ч*��100+ǧ�𷽵ȼ�/2��/100
�ķ�����Ч�ʣ��ķ�������Ч*��100+ǧ�𷽵ȼ�/4��/100
HELP
);
    return 1;
}

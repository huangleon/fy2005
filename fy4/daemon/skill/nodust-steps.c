inherit SKILL;

void setup(){
	set("name","�޳�����");
	set("type","step");
	set("usage/dodge",1);
	set("usage/move",1);
	set("effective_level",170);
	set("difficulty",200);
	set("practice_limit",100);
	set("skill_class","bonze");
	set("dodge_msg", ({
	        "$nһ�С�������翡��������ɵر��˿�ȥ��\n",
	        "ֻ��$n��Ӱһ�Σ�һʽ������ֱ�ϡ����ѱ����߳�֮�⡣\n",
	        "$nʹ������շɶɡ����������ɵ�������\n",
	}) );
}


int help(object me)
{
	write(@HELP   
L100	�����须(dodge.kongling) 
���������ɱ��

L150	��������(dodge.juechen) 
���������ٶ�(+�޳�����/20)

HELP
    );
    return 1;
}

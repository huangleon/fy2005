// begging.c

inherit SKILL;

void setup() {
	set("name","����֮��");
	set("type","knowledge");
	set("skill_class","beggar");
	set("difficulty",250);
	set("effective_level",200);
	set("no_refund",({"dragonstrike"}));
}


int help(object me)
{
	write(@HELP   
����֮��Ϊؤ���书�Ļ�����
L50	����ѯ����inquire��
�������˵���Ϣ����ϸ��ο�help inquire

L90	���ѻ�����juji��
��ս����ʼǰ͵Ϯ���֣���ϸ��ο�help juji

L185	���ɸ봫�须��inform��
����ؤ����ʹ���ʹ�ã��л����ѣ���ϸ��ο�help inform

HELP
    );
    return 1;
}

inherit SKILL;
#include <ansi.h>

void setup(){
	set("name","�����ɱ��");
	set("type","dagger");
	set("usage/dagger",1);
	set("effective_level",250);
	set("difficulty",200);
	set("skill_class","berserker");
	
	action = ({
        ([  "action":       "$N����һ����������$n��ߣ�������",
			"dodge":		100,
			"damage":		200,
			"damage_type":	"����"
		]),
        ([  "action":       "$Nһ�μ�����$w��Ȼ������$n��ǰ",
			"dodge":		150,
			"damage":		180,
			"damage_type":	"����"
		]),
        ([  "action":       "$n��ǰʧȥ$N��Ӱ��һ��֮�£�$w����$n�������",
			"dodge":		200,
			"damage":		220,
			"damage_type":	"����"
		]),
        ([  "action":       "$Nһ���֣�$w�ɵ��Ƶ�����$n���ַ�������",
			"dodge":		220,
			"damage":		300,
			"damage_type":	"����"
		]),
	});
}

int help(object me)
{
	write(@HELP   
����ڤ��֮������deathtouch��
��Ҫ200���̱��У�a����200���ļ����ɱ����b��
������Ҫ120�������
��������������æ������
���⹥����= a + b + random(b)
�����˺���= (a+b)*2 + random(a*3)

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

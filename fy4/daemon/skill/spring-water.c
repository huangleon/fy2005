//spring-water.c
#include <ansi.h>
inherit SKILL;
void setup(){
	set("name","��ˮ����");
	set("type","iron-cloth");
	set("effective_level",120);
	set("usage/iron-cloth",1);
	set("ic_effect",50);
	set("bounce_ratio",10);
	set("difficulty",300);
	set("skill_class","huashan");
	set("absorb_msg", ({
	        "$n��ü΢����ʩչ�������������¡�����������Ʈ�裬��Ȼ�ƺ��е��΢�⸡����\n",
	        "$nʩչ��ˮ�����ġ��κ�¥̨���������������ܣ����ƺ�������$N�����ڡ�\n",
	        "$n΢΢����һʽ���仨�˶���������$N�Ĺ����£��´�ƮƮ����紵���衣\n",
	        "$nʩչ����΢����˫�ɡ���˫���չ������$N��һ����\n",
	}) );
}

int valid_learn(object me){
    	if( (string)me->query("gender") != "Ů��" ) {
        	return notify_fail("��ˮ������ֻ��Ů�Ӳ��������书��\n");
	}
	if(!::valid_learn(me)){
		return 0;
	}
	return 1;
}

int help(object me)
{
	write(@HELP   
L50	���������ϡ���bingwantianzhang��
�����Ч�������Ĺ�Ч���������Ϊ��ˮ�����ȼ���50%
����ս����ʹ�û�����������æ�ҡ�

L120��ӳ�����ԡ���yingyueliuhui��
����200���ĺ�÷�ķ���Ψ����Ϻ�÷�ķ�����Ч��������ս���з���
Ҳ�������������ͬʱʹ�ã�����3���ӡ�������������Χ����3-5����
Ӱ�����˵�ÿ�ι�����25%�ļ��ʻ��л�Ӱ��������˺���ħ��������
�ܴ����ƣ���ÿ����Ӱ�����к����ʧ�����Թ���3-5�λ���ȫ������
���˵��˺���
HELP
    );
    return 1;
}

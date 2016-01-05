// bolomiduo.c
inherit SKILL;
#include <ansi.h>

void setup() {
	set("name","�����۶��ľ�");
	set("type","force");
	set("effective_level",120);
	set("usage/force",1);
	set("difficulty",200);
	set("skill_class","lama");
}


//	������

mapping ob_hit(object ob, object me, int damage) {
	
	mapping data = ([]);
	
	if(!me->query_temp("pfm/dz_roar") || me->query("class")!= "lama"
		|| me->query_skill_mapped("iron-cloth")!= "jin-gang")
		return 0;
	
	data["msg"] = BRED + HIY"$n����ϼ�޻��ƣ��⻪��Ŀ��$N�Ĺ��ƾ������ţ�\n"NOR,
	data["damage"] = -damage;	// In Roar, we set resistance/kee = 100, so damage here is irrelevant.
	return data;	
}

int help(object me)
{
	write(@HELP   
L0 �������۶ࡻ��bolo�������ķ�

L100��������sheshen��
����100�����ڷ𷨣���������Ѫ��15%ת��Ϊ�������80%��
ÿ20���ʹ��һ��

L150����������leiting��
����150����ղ����������˻��к��Զ������˺����˵�����
���10%�������˺��ĵֿ���������Ϊ������������ͬ�顣

L160����������pili��
����180����ղ����������˻��к��Զ������˺����˵ľ�����
���10%�Ծ����˺��ĵֿ���������Ϊ������������ͬ�顣

L160�����ת������huofo��
����170�����ڷ𷨣�����2word��3word��mana����
�޷��롺�������͡����������ã�����������
Ч������10���ӡ�

HELP
    );
    return 1;
}

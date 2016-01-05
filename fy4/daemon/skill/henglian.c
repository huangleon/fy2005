// jin-gang.c
inherit SKILL;
void setup() {
	set("name","ʮ��̫������");
	set("type","iron-cloth");
	set("effective_level",100);
	
	set("usage/iron-cloth",1);
	set("ic_effect",50);
	set("bounce_ratio",10);
	set("difficulty",400);
	set("skill_class","fugui");
        set("absorb_msg", ({
	        "$n�������ܣ���Ӳ����$N��һ�С�\n",
	        "$n������ͨ���ھ�����ȫ�����£��Կ�$N����һ�С�\n",
	        "$n��ȻһЦ������һ���ѽ�$N�ĳ����𿪡�\n",
        }) );
}


int valid_learn(object me){
	
	if( (string)me->query("gender") != "����" ) {
        	return notify_fail("ʮ��̫��������ֻ�����Ӳ��������书��\n");
	}
	
	if( (int)me->query_skill("skyforce",1)+20 < (int)me->query_skill("henglian",1)) {
        	return notify_fail("��ı̿��ķ���Ϊ�������޷�����������ʮ��̫��������\n");
	}
	return ::valid_learn(me);
}


int help(object me)
{
	write(@HELP   
L100��һ���ޡ���yichuan��
��ߺ����Ĺ�Ч������50����ЧӲ��
 
L180�������ڡ���erchuan��
��ȥ���ж��ֵĹ�����������ʱ��30�����ʧ��ÿʮ����
ʹ��һ�Σ�Ψ��ʹ�ñ̿��ķ�����Ч��

HELP
    );
    return 1;
}

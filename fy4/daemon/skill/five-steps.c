// five-steps.c
#include <ansi.h>

inherit SKILL;
void setup() {
	set("name","������");
	set("type","step");
	set("usage/dodge",1);
	set("usage/move",1);
	set("effective_level",200);
	set("practice_limit",100);
	set("difficulty",200);
	set("skill_class","wudang");
	set("dodge_msg", ({
	        "����$n����������ˮ��һʽ��ˮ�־����г鵶��ˮ����������ıܿ���һ����\n",
	        "$n������ת���Ų����У�һʽ��ľ�־�����ٿ�ش�ľ��Ų�������ߣ��ܹ�����һ�С�\n",
	        "����$n����һ�ã�ʹ���������еġ����־�����$N��һ�����˸��ա�\n",
	        "ȴ��$n�㲻��أ��ó������Ӱ���ӻ������Դܿ����ߣ����˿�ȥ��\n",
	        "$n����΢�Σ�ʹ�����С����־��������ݵ���$N�����\n",
	}) );
}

int valid_learn(object me)
{
	if((int)me->query_skill("changelaw", 1) < (int)(me->query_skill("five-steps", 1)/2)) {
		return notify_fail("����׾����˽⻹��������޷�ѧϰ��������\n");
	}
	return 1;
}


int practice_skill(object me)
{
	string msg;
		
	msg = MAG"������չ������ͼ��"HIY" �� "HIG"ľ "HIC" ˮ "HIR" �� "NOR YEL" �� "MAG"���в������������󷨡�����ͼ���С�\n" NOR;
	tell_object(me,msg);
	return :: practice_skill(me);	
}


//	մ��ʮ�˵�

mapping ob_hit(object ob, object me, int damage) {
	mapping data;
	int skill;
		
	skill = me->query_skill("five-steps",1);
		
	if (me->query_temp("pfm/five-steps_zhanyi")|| 
		(	skill >= 200 
			&& me->query("class")=="wudang"
			&& me->query_skill_mapped("iron-cloth")== "incarnation")
			&& me->query_skill("incarnation",1)>= 300
			&& !random(10)) {
		ob->perform_busy(1);
		data = ([
			"msg":	WHT"$N��һ����$n��������ƽƽ�ĺ�ɳ�ȥ�����һ��������ʵʵ��ˤ������֮�⡣\n"NOR,
			"damage": -damage,
		]);
		return data;
	}
	return 0;
}



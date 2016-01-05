// incarnation.c

inherit SKILL;
#include <ansi.h>
void setup(){
	set("name","������");
	set("type","knowledge");
	set("skill_class","basic");
	set("difficulty",100);
	set("usage/literate",1);
	set("bounce_ratio",10);
	set("effective_level",50);
	set("difficutly", 200);	
		set("absorb_msg", ({
	        "$n�������������������̬����Ȼ������һ����Լ�ĵ���ɫ�Ĺ�ԡ�\n",
	        "$n���ܲ����������Ƴ�һ����쭣��ȴ����ᣬ�����䵱�ɡ����������������\n",
	}) );

}


void skill_improved(object me)
{
    	int s;

    	s = me->query_skill("incarnation", 1);
	if ( s == 220 && me->query("class") == "wudang")
		tell_object(HIY"�������������֮�������������������ѳ����ž���\n");
			
/*    	if( s%10==9 && (int)me->query("spi") < s/5) {
        	tell_object(me, HIW "����������������������������ˡ�\n" NOR);
        	me->set("spi",(s+1)/5);
    	}*/
}

int skill_difficulty() {
	
	int skill;
	if (this_player()) {
		skill = this_player()->query_skill("incarnation",1);
		if (skill<=200) return 200;
	}
	return skill*3;	
}


int valid_enable(string usage) 
{ 
	object me;
	if (me=this_player())
		if(me->query_skill("incarnation",1)>=220){
			return usage=="literate"||usage=="iron-cloth"; 
	}
	else
		return usage=="literate";
}

int help(object me)
{
	write(@HELP   
�������ң�Ρ�
��Ҫ160��������������һ���ط��趨���꣨setmark����
������һ��ʱ���ڿ��ٷ��أ�usermark��
ÿ�κķ�200��������

�����е����������Դ��鼮��NPC�ȴ������׵�ѧ��150����
�����ϵ�ʮ��150-160����Ҫ�Լ��о��ˣ�research��
�о�����Ҫ��Ǳ����������ѧϰ����Ҫ��10����

220�����ϵ�������������������
HELP
    );
    return 1;
}

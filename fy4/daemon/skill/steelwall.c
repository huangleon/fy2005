// ���skill�Ǹ�wall�õģ���Ҫ��һ��npc

inherit SKILL;
#include <ansi.h>
void setup(){
	set("name","ͭǽ����");
	set("type","iron-cloth");
	set("skill_class","npc");
	set("difficulty",200);
	set("ic_effect",100);
	set("usage/iron-cloth",1);
	set("bounce_ratio",10);
	set("effective_level",100);
        set("difficutly", 100); 
                set("absorb_msg", ({
                "$n���·���һ����Լ�ĵ���ɫ�Ĺ�ԣ�����̩ɽ��������ʯ��\n",
                "$Nֻ����$n���ͭ������Ӳ�ޱȣ���ǹ���ˡ�\n",
        }) );

}


/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/



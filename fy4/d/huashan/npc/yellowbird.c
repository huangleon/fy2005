#include <ansi.h>
inherit NPC;
void create()
{
    	set_name("С��ȸ", ({ "yellow bird", "bird" }) );
    	set("race", "����");
    	set("age", 1);
    	set("gender", "����");
    	set("long", "����һֻС��ȸ����������ë��ҫ�Ż�ɫ�Ĺ���\n");
    	set("attitude","peaceful");
    	
	set("chat_chance", 1);
	set("chat_msg", ({
		    (: random_move :),
	    	"С��ȸ��ͷ�ڵ������˼��¡�\n",
	}));
	set_temp("apply/dodge", random(200));
	set_temp("apply/attack", 10);
	set_temp("apply/armor", 5);
	set("weight", 200);
    	setup();
}




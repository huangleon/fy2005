inherit NPC;
#include <ansi.h>
inherit INQUIRY_MSG;
int give_mission();

void create()
{
        set_name("������С��", ({ "kid"}) );
        set("gender", "����");
        set("age", 12);
        set("long",	"һ��ʮ�������С����������վ���ƺ��Ŵ��ˡ�\n"	);
		set("chat_chance", 1);
        set("chat_msg", ({
        }) );
		set("inquiry", ([
	        	"С��" : (: give_mission :),
	        	"xiaoyan" : (: give_mission :),
	   	]));

		set("combat_exp",10000);
        setup();
		carry_object("/obj/armor/cloth")->wear();
}

int give_mission()	{
	message_vision("$N�ƺ���˵ʲô�����˿����ܣ��ֲ������ˡ�\n",this_object());
	return 1;
	
}	
			
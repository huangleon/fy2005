#include <ansi.h>
inherit NPC;

void create()
{
        set_name("��ţ��", ({ "little farmer", "farmer" }) );
        set("gender", "����");
        set("age", 12);
        set("combat_exp",2000);
        set("long", "һ��ʮ����ķ�ţ�ޣ����������ţ��\n");
	
	set("inquiry", ([
        	"bull": "�úõ�һͷţ���ڵ�������һȦͻȻ�Ͳ����ˣ������ô�죿\n",
        	"��ˮţ": "�úõ�һͷţ���ڵ�������һȦͻȻ�Ͳ����ˣ������ô�죿\n",
        	"����":	"�úõ�һͷţ���ڵ�������һȦͻȻ�Ͳ����ˣ������ô�죿\n",
         ]) );
	
	set_skill("blade", 10+random(50));
        setup();
	carry_object(__DIR__"obj/liandao")->wield();
	carry_object("/obj/armor/cloth")->wear();
}


int accept_object(object who, object item){
	
	if (item->query("name") == "�߲�Ы�ӵ�ʬ��") {
		ccommand("ack");
		message_vision(CYN"��ţ��˵��ԭ��������һ��ڵ���ѽ��̫��л���ˣ�\n"NOR, who);
		message_vision(CYN"��ţ�޴�����������ĵ�˵��������������ܣ���������ﳣ��Щ��ֵ���������\n"NOR,who);
		
		if (QUESTS_D->verify_quest(who, "�䵱��ˮţ"))
			QUESTS_D->special_reward(who, "�䵱��ˮţ");
		return 1;
	}
	return 0;
}
			
// fatman.c
#include <ansi.h>

inherit NPC;
int tell_him();

void create()
{
        set_name("���", ({ "big cook","cook" }) );
        set("gender", "����" );
        set("age", 42);
        set("long", "����һ�����վ�տ�Ĵ����\n");
	set("attitude", "heroism");
        set("combat_exp", 20000);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "����ڳ�����æǰæ����ͷ�󺹡�\n",
        }) );

    	set("inquiry", ([
	        "��æ" : (: tell_him :),
	        "����" : (: tell_him:),
	        "work" : (: tell_him :),
	        "help" : (: tell_him:),
	        "����":	 "���������󵽴����ܣ�����ϸ����˵�����ܷ������ǵ��ϳ���\n",
        	"rat":	 "���������󵽴����ܣ�����ϸ����˵�����ܷ������ǵ��ϳ���\n",
        	"mouse":	 "���������󵽴����ܣ�����ϸ����˵�����ܷ������ǵ��ϳ���\n",
        ]));
        
        set_skill("unarmed", 130);
        set_skill("parry", 30);
	set_skill("dodge", 30);
	
	setup();
    
        carry_object(__DIR__"obj/jinzhuang")->wear();
	carry_object(__DIR__"obj/luwei");
        
}


int tell_him(){
	object ob, me = this_player();
	ob = this_object();
	
	if (!QUESTS_D->verify_quest(me,"��ʨ���")) {
		command("say ��æ������ղ�ô����������������ȥ�ַ��˻��ɡ�");
		return 1;
	}
	if (me->query_temp("marks/js_cook_mice")) {
		tell_object(me, "���˵���ҽ���ȥ����¶�������ô��\n");
		return 1;
	}
	
	if (me->query_temp("marks/ask_js_cook")<3) {
		me->add_temp("marks/ask_js_cook",1);
		if (random(2))
			message_vision("��������æ������ת���ƺ�û����$N�Ļ�����\n",me);
		else
			message_vision("���̧��ͷ������$Nһ�ۣ��ֵ���ͷȥæ���ˡ�\n",me);
		return 1;
	}
	
		
	tell_object(me, "�������˵���Χȹ�ϲ��˲�˵�����æ�����У���Щ��"YEL"����"NOR"���ڵ��������㿴����ʲô���ӣ�\n");
	me->delete_temp("marks/ask_js_cook");
	me ->set_temp("marks/js_cook_mice",1);
	return 1;
}
		
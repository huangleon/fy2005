#include <ansi.h>
inherit NPC;

void create()
{
        set_name("�γ���", ({ "song" }) );
        set("gender", "����");
        set("age", 30);
        set("long",
		"�γ������䵱�𹤵��ˣ����Ż�ɫ���ۡ�\n"
	);
        set("combat_exp", 10000);
        set("class", "taoist");
        create_family("�䵱��", 58, "����");

        set_skill("move", 10+random(40));
        set_skill("force", 10+random(40));
        set_skill("unarmed", 10+random(40));
        set_skill("sword", 10+random(40));
        set_skill("parry", 10+random(40));
        set_skill("dodge", 10+random(40));
        set_skill("taijiforce", 10+random(30));
        set_skill("taiji", 10+random(30));
        set_skill("three-sword", 10+random(30));
        set_skill("five-steps", 10+random(30));

        map_skill("force", "taijiforce");
        map_skill("sword", "three-sword");
        map_skill("parry", "three-sword");
        map_skill("unarmed", "taiji");
        map_skill("dodge", "five-steps");
        map_skill("move", "five-steps");
        
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "sword.nianzijue" :),
        }) );

        set_skill("changelaw", 10);
        setup();

        carry_object(__DIR__"obj/sword")->wield();
        carry_object(__DIR__"obj/cloth")->wear();

}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

int accept_fight(object me)
{
        if( (string)me->query("family/family_name")=="�䵱��" ) {
                command("nod");
                command("say ���аɡ�");
                return 1;
        }
        command("say �䵱�ɲ��ͱ��ɵ��˹��С�");
        return 0;
}

void greeting(object me)
{
    if( !me || environment(me) != environment() ) return;
	if( (string)me->query("family/family_name")!="�䵱��" ) {
		if( (string)me->name()!="����" ) {
			say( YEL "�γ���˵������λ" + RANK_D->query_respect(me)
				+ "����������Ժ���䵱�صأ����������롣\n"NOR);
			} 
		else {
			message_vision( YEL "$N�������´�����$n����˵������ʦ�絽����ȥ�ˣ�\n"NOR, this_object(), me);
			message_vision( YEL "Ϊʲô��ɫ���ã��������岻������쵽��Ժ��Ϣ��\n"NOR, this_object(), me);
		}
	}
	else {
		say( YEL "�γ���˵������λ" + RANK_D->query_respect(me)
			+ "���Ժ��Ϣ���跹�����͵���\n"NOR);
	}
}

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("�����ϴ�", ({ "bandit chief", "chief" }) );
        set("gender", "����");
        set("age", 39);
        set("long",
                "��һ������׶�һ˫���������������������Ĳ��ӡ�\n");
        set("combat_exp", 650000);
        set("attitude", "aggressive");
        set("chat_chance", 10);
        set("chat_msg_combat", ({
                "\n�����ϴ���������˵�����ԹԵ����°ɣ�\n",
                "\n�����ϴ󻢺�һ����������ǰ��\n"
        }) );
        
        set_skill("blade", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("shenji-blade",90);
        set_skill("shenji-steps",100);
        set_skill("unarmed",150);
        set_skill("yiyangzhi",80);
        
        map_skill("unarmed","yiyangzhi");
        map_skill("blade","shenji-blade");
        map_skill("parry","shenji-blade");
        map_skill("dodge","shenji-steps");
        

        setup();
        carry_object("obj/weapon/blade")->wield();
        carry_object(__DIR__"obj/leather")->wear();
}

void start_help()
{
        message_vision(CYN"һ����Ӱ�����ּ�Ծ�������ֽý��������书������\n"NOR,this_object());
        command("say ������... ���⼸��С��ɫҲ�򷢲��ˣ�վ��һ�㣡\n");
}

int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}

void leave()
{
	object ob;
	message("vision",name() + "Ц�����ú����ţ���ү��ȥ˯���ˣ�\n", environment(),this_object() );
	command("escape");
	if (ob=present("bandit",environment()))
		ob->set("called_help",0);
	destruct(this_object());
}

#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�����", ({ "dazui" }) );
        set("gender", "����");
        set("combat_exp", 500000);
        set("title", HIW "����"NOR);
        set("long",	"���˹��е�һԱ���ó����⣬а������\n");
        
        
        set("inquiry", ([
        	"��Ƽ��":	"��Ƽ�����ҵĹԹ�Ů����\n",
        	"�ؼ�":		"���ɣ����ӹ������Ƕ������ӡ�\n",
        ]));
        
        set_skill("move", 50);
        set_skill("dodge", 200);
		set_skill("unarmed",250);
		set("str",55);
        set("chat_chance", 1);
        set("chat_msg", ({
                (: random_move :)
        }) );
        setup();
	carry_object("/obj/armor/cloth")->wear();
}

void init()
{
	object		me;

        ::init();
        if( interactive(me = this_player()) && !is_fighting() && !random(5)) {
		add_action("do_accept", "accept");
                call_out("greeting", 1, me);
        }
}

int greeting(object me)
{
		if (!me || environment(me)!= environment()) return 1;
			
		message_vision(HIY "\n$N��$n˵�����ҿ��Խ���ʦ��������ȫ��
���������㣬��ô������accept yes/no��\n"NOR, this_object(), me);
	return 1;
}

int do_accept(string arg)
{
	if( arg != "yes" &&  arg != "no") 
                return notify_fail("��Ҫ����ʲô��\n");
	if( arg == "yes") {
		message_vision( HIY "$N˵�����ã���ҹ��ʱ����\n"NOR, this_object());
	}
	else {
        message_vision( HIY "$N˵�������ǲ�ʶ̧�٣���������\n"NOR, this_object());
		kill_ob(this_player());
        }
	return 1;
}


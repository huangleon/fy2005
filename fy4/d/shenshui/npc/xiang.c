// thousand_hand.c

#include <ansi.h>

inherit NPC;
void create()
{
	set_name("����" , ({ "xiang xiang", "girl", "qing yi" }) );
	set("long", "һλ����ԲԲ�Ĵ��۾���Ů����\n");
	set("attitude", "friendly");
	set("class","shenshui");
	set("age", 15);
        set("gender", "Ů��" );
        set("title", "��ˮ������");
	set("combat_exp", 500000);
        set_skill("unarmed", 50);
        set_skill("throwing", 85);
        set_skill("force", 90);
        set_skill("parry", 67);
        set_skill("dodge", 89);
        set_skill("literate", 50);
        set_skill("perception", 68);

        set_skill("nine-moon-steps", 68);
        set_skill("nine-moon-claw", 55);
        set_skill("nine-moon-force", 60);
        set_skill("nine-moon-sword", 70);

        map_skill("dodge", "nine-moon-steps");
        map_skill("unarmed", "nine-moon-claw");
        map_skill("force", "nine-moon-force");
        map_skill("sword", "nine-moon-sword");
        map_skill("move", "nine-moon-steps");
        
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.lianhuanbu" :),
                (: perform_action, "dodge.lianhuanbu" :),
                (: perform_action, "dodge.lianhuanbu" :),
                
        }) );

	setup();
	carry_object(__DIR__"obj/cloth")->wear();
        add_money("coin", 3);
}

void init()
{
        object me;
        me = this_player();
        if(interactive(me) && me->query("gender") == "����" && !me->query_temp("marks/guest") && !me->query("marks/�׼���"))
        call_out("chase_him", 1,me );


}

int chase_him(object me)
{
        message_vision("$N��$n�ȵ����󵨿�ͽ�������ô���ˮ����\n",this_object(),me);
        set_leader(me);
        kill_ob(me);
        me->kill_ob(this_object());
        return 1;
}


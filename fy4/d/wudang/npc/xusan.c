#include <ansi.h>

inherit NPC;

void create()
{
        set_name("����ү", ({ "san ye","sanye"}) );
        set("long","һ��������ͷ����ȧӥ�ǡ������ܽ��������ɺܴ�������ˡ�\n");
        set("cor", 26);
        set("cps", 25);
        set("combat_exp", 400000);
        set("chat_chance", 1);
        set("chat_msg", ({
                "����ү��˿ھƣ�����¶������ֵ�Ц�ݣ�ˣǹ���ˣ����������ڰ�\n��ǹ�£���Ҳ������һ�����¡�\n",
        }) );
        
        set_skill("unarmed", 70);
        set_skill("spear", 70);
        set_skill("parry", 70);
        set_skill("dodge", 70);
        set_skill("move", 100);
        set_skill("xuezhan-spear",80);
        set_skill("hawk-steps", 50);
        
        map_skill("spear","xuezhan-spear");
        map_skill("dodge","hawk-steps");
        map_skill("parry","xuezhan-spear");
        map_skill("move","hawk-steps");
        
        set_temp("apply/damage", 50+random(50));
                
        setup();
        carry_object(__DIR__"obj/spear")->wield();
        carry_object(__DIR__"obj/m_cloth1")->wear();
}


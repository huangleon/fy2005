#include <ansi.h>
#include <combat.h>
inherit NPC;
inherit F_MASTER;
int direct();
void consider();

void create()
{
    set_name("��������", ({"nakedman chu" }));
    set("title", HIY "�������"NOR );
    set("gender", "����");
    set("age", 32);
    set("long",
        "
��˫ü���泤�������������������������˫�峺�����磬ȴ�����������ݡ�������
ֱͦ��������ǿ�����ϵ���ʯ�ĳ������Ǳ����ģ�������̵��죬����Ҳ��Щ��ᣬ��
ֻҪ��һЦ��������ǿ�ͱ������ᣬ���Ҳ����ͬ�飬��������ů�Ĵ��紵���˴�ء�
");
    set("attitude","friendly");
    set("per", 40);
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
        (: perform_action, "unarmed.luori" :),
            }) );

    set("combat_exp", 10000000);
    set("score", 50000);

    set_skill("force", 150);
    set_skill("bibo-force", 150);
    set_skill("unarmed", 120);
    set_skill("dodge", 320);
    set_skill("luoriquan", 200);
    set_skill("move", 320);
    set_skill("fengyu-piaoxiang", 320);
    set_skill("parry", 150);
    set_skill("literate",150);
    set_skill("stealing",320);
    map_skill("force"  , "bibo-force");
    map_skill("unarmed", "luoriquan");
    map_skill("dodge"  , "fengyu-piaoxiang");
    map_skill("move"  , "fengyu-piaoxiang");
    setup();
}

void init()
{
	::init();
	add_action("do_look","look");
}
int do_look(string arg)
{
    object me;
    me = this_player();
    
    if( (string)me->query("gender") == "Ů��" && 
        (arg == "nakedman chu"))
    {
        message_vision("$Nһ�ŷ�����������ķɿ죮������\n"NOR, me);
        me->unconcious();
        return 1;
    }
    else return 0;
}


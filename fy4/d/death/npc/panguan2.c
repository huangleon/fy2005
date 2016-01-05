inherit NPC;
#include <ansi.h>
void create()
{
        set_name("�����й�", ({ "death-judge" }) );
        set("long",
                "������ߵ������й٣��ƹ��������ᡣ\n");
        set("age", 3100);
        set("cor", 37);
	set("str",100);
        set("combat_exp", 2000000);
	set_skill("move",200);
        set("attitude", "peaceful");
        set_temp("apply/attack", 80);
        set_temp("apply/parry", 80);
        set("chat_chance", 1);
        set("chat_msg", ({
		"�����йٿ�����һ�ۣ������������Ϲ���һ�¡�\n",
		"�����й�˵����������ү�������ǰ�����Ƥ���ǳ����Ľ��\n",
		"�����й�˵����������ү����������ǰ�����޵�����������Ͷ̥����Ů�ɣ�\n",
		"�����й�˵����������ү������Ͷ̥��̫��ɣ�\n",
		"�����й����㣺��Ϊʲô��������ү�����¹򣿣�\n",
		"�����й������ǿն����۾�������������\n",
		"�����йٺ���������������һ������\n",

        }) );
        set_temp("apply/armor", 70);
        set_temp("apply/damage", 130);
        set_temp("apply/dodge", 70);
        set("inquiry", ([
		"Ͷ̥" : "�źöӣ���������\n",
                "*" : "��ķϻ��湻��ģ��˶����ˣ��컹���ϱ��ϡ�\n",
        ]) );
        setup();
        carry_object("/obj/armor/ghost_cloth")->wear();
}

void unconcious()
{
return;
}
void die()
{
return;
}

void init()
{
	::init();
        if( !previous_object()
        ||      !userp(previous_object()) )
                return;
        call_out( "death_stage", 1, previous_object() );
}


void death_stage(object ob)
{
        if( !ob || !present(ob) ) return;

        if( !ob->is_ghost() ) {
                command("say Ŷ�����ˣ�����Ҳ�ñ����ˣ�");
                kill_ob(ob);
                ob->fight_ob(this_object());
                return;
}
}

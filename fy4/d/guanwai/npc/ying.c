#include <ansi.h>

inherit NPC;

void create()
{
        set_name("��ӥ", ({ "ying" }) );
        set("gender", "����" );
        set("long",
                "أӥ������ۣ������İ��£���������ᣬɽ������򶨡�\n" );
        set("title", GRN"��ԭ֮ӥ"NOR);
        set("attitude", "peaceful");
	set("age", 44);
        set("per", 20);
        set("combat_exp", 10000000);
        set_temp("apply/damage",50);
        set("chat_chance", 1);
        set("chat_msg", ({
                "��ӥ��һ�ּ�ڽ��Ŀ������ض����㡣\n",
                }) );
        set_skill("unarmed", 200);
        set_skill("parry", 200);
        set_skill("dodge", 300);
        set_skill("blade", 200);
        set_skill("shortsong-blade", 100);
        set_skill("fall-steps", 100);
        set_skill("bolomiduo", 100);
	set_skill("blade", 200);
        map_skill("force", "bolomiduo");
        map_skill("dodge", "fall-steps");
	map_skill("parry", "shortsong-blade");
        map_skill("blade", "shortsong-blade");

	setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/guskin");
	carry_object(__DIR__"obj/roundblade1")->wield();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_continue","continue");
}

void greeting(object ob)
{
        object npc;
        npc = this_object();
        if( !ob || environment(ob) != environment() ) return;
        if( ob->query("score") > 1500 && ob->query_temp("marks/guanwai_knowsecret") )
        {
        	message_vision("$N���˿ڹų��գ��������ֳ�һ˿Ц�⣬�������裺\n�����������������������������\n",npc);
        	message_vision("$Nת��ͷ�����˿�$nЦ��������ȥ����continue .....�� \n",npc,ob);
        	set("enable_continue",1);
        }
        else
        {
        	message_vision("$N���˿ڹų��գ���һ�ּ�ڽ��Ŀ������ض���$n��\n",npc,ob);
        }
}

int do_continue(string arg)
{
	object npc,player;
	npc = this_object();
	player = this_player();

	if(!query("enable_continue")) return 0;
	if ( !arg )
		return notify_fail("��Ҫ������ʲô��\n");
	if (arg == "���̸���������ԡ�����" || arg == "���̸������" || arg == "���̸�����ԡ�" )
        {
        	delete("enable_continue");
        	message_vision("$N����Ӧ���ͳ������̸���������ԡ�������\n",player);
        	call_out("ask_help",3,npc,player);
	}
	else
		message_vision("$N����ɤ�Ӻ��ҳ�����"+arg+"��\n",player);
	return 1;
}

void ask_help(object npc,object player)
{
	object sword;
	message_vision("$N������Ц�����úã���һ�������ԣ����������Ҹ�æ���ҵ�С����\n�����ħ�۽�����������������Ϲ�����ˡ�\n",npc);
	sword = new(__DIR__"obj/magicsword");
	sword->set("owner_id",player->query("id"));
	sword->move(player);
	message_vision("$N�ó�һ��ħ�۽�����$n��\n",npc,player);
	player->delete_temp("marks/guanwai_knowsecret");
	player->set_temp("marks/guanwai_help_ying",1);
	return;
}

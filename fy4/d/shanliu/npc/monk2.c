// yangfan.c

inherit NPC;

#include <ansi.h>
void answer_shanliu();
void create()
{
	set_name("��ɫ", ({ "old monk","monk" }) );
	set("gender", "����" );
	set("age", 78);
	create_family("������",17,"��ʦ");
	set("long",
"���Ǹ�����ȥ���ϵĺ��У��������ֵģ�Ц������ֱ�ͻ�����һ�����շ���ǰ��
���˸�ľ�㡣\n");
        set("chat_chance", 1);
        set("chat_msg", ({
            "��ɫ����ľ�㣬�૵����Ҳ��������˭����������в���Ϳ��˭��Ϳ��\n",
            "��ɫ¶��һ˿Ц�ݣ�����Ц����ɽ���޴����ڣ���Ϊ��ԭ������ÿ������֮ʿ�����С�\n",
    }) );
	set("combat_exp", 2000000);
	set("attitude", "friendly");
	set("per",10);
	set("str", 30);
	set("force",1000);
	set("max_force",1000);
	set("force_factor",50);
	set_skill("dodge",100);
        set_skill("unarmed",100);
        set_skill("parry", 100);
        
 	setup();
    carry_object("obj/armor/cloth")->wear();

}


void init()
{
	object ob;
	::init();
	if( interactive(ob = this_player()))
	if(ob->query_temp("ɽ��/�߸���"))
	{
		remove_call_out("greeting");
                call_out("greeting", 3, ob);
        }
	add_action("do_kill","kill");
}

void greeting(object me)
{

	if(environment(me)!=environment())
		return ;
	me->delete_temp("ɽ��/�߸���");
	if(me->query("ɽ��/ʧ��")&&me->query("ɽ��/ʧ��")+86400>time())
	{
		message_vision("$N����Ķ�$n˵����������ɽ����Ե��������ذɡ���\n",this_object(),me);
		return ;
	}
	message_vision(HIY"$N΢Ц�Ŷ�$n˵���������¾��ڷ����棬��ȥ�ɡ���\n"NOR,this_object(),me);
	me->set_temp("ɽ��/������",1);
	me->move("/d/shanliu/sheshenya");
	return ;
}

int do_kill(string arg)
{
	object me;

	me=this_player();
	if(!arg) return 0;
	if(this_object()==present(arg,environment()))
		me->set("ɽ��/ʧ��",time());
	return 0;
}

#include <ansi.h>
inherit QUESTNPC;
#include <ansi.h>
void crazy();
void create()
{
        set_name("����ѩ", ({ "fu hongxue","fu" }) );
        set("gender", "����");
        set("age",26);
        set("nickname", HIC"���ġ����¡���"NOR);
        set("title", "�߳�        ����");
        set("quality","good");
        set("combat_exp", 9000000);
        set("long",
                "�����ϵ�����Ӣ����ͻ������ȴ����Զɽ�ϵı�ѩ�ܳɵġ�\n",
        );
	set("cor",40);
	set("str",50);
	set("cps",31);
        set("max_force",4000);
        set("force",4000);
        set("force_factor",80);
	set_skill("force",150);
	set_skill("demon-force",120);
        set_skill("parry", 200);
        set_skill("blade",200);
        set_skill("dodge",180);
	set_skill("demon-steps",150);
	set_skill("demon-blade",150);
        map_skill("dodge","demon-steps");
        map_skill("blade","demon-blade");
        map_skill("parry","demon-blade");
	map_skill("force","demon-force");
        set("chat_chance", 90);
        set("arrive_msg","���˹��������������һ�����ҽŲ�����������ȥ");
        set("leave_msg","��ȥ�����������һ�����ҽŲ�����������ȥ");
        set("chat_msg", ({
        (: random_move :),
        (: random_move :),
        (: random_move :),
        (: crazy :),
	 "����ѩ����¶���˼���ʹ��ı��飬������������𣬱��𣡣���\n",
        }) );




        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action,"dodge.lianhuanbabu"  :),
					(:perform_action,"blade.tiandirenmo" :),
        }) );
        setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/blackblade")->wield();
}
void remove_effect(int exp);
void crazy()
{	int exp;
	if (!random(10))
	{
		message_vision(
RED"����ѩ������ȻŤ�����Σ������³���ĭ���������¶���ʼ���Ρ�������¶
�����ޱ�ʹ��ı��飬���ƺ���˵ʲô��ȴһ����Ҳ˵������������������\n"NOR,this_object());
		exp=this_object()->query("combat_exp");
                this_object()->start_busy(10);
		this_object()->set("combat_exp",2000000);
		call_out("remove_effect",30,exp);
		return;
	}
	return;
}

void remove_effect(int exp)
{
	message_vision("����ѩ��������ڷ������ˡ�\n",this_object());
	this_object()->stop_busy();
	this_object()->set("combat_exp",exp);
}

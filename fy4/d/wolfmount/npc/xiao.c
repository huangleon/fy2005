
inherit NPC;
#include <ansi.h>
void create()
{
        set_name("��ʮһ��", ({ "xiao11","xiao" }) );
        set("gender", "����" );
        set("age", 25);
        set("per", 27);
        set("attitude", "peaceful");

        set("long",     "��ȫ���ָɾ������࣬����һ���ոհ��˿ǵļ�����\n");
        set("combat_exp", 9999999);
    set("title", "���");
        set_skill("blade", 120);
	set_skill("unarmed",50);
	set_skill("dodge", 100);
        set_skill("force", 130);
        set_skill("literate", 70);
        setup();
        carry_object(__DIR__"obj/gelu")->wield();
        carry_object("/obj/armor/cloth")->wear();
}
void init()
{
	object me;
	::init();
	add_action("do_answer","answer");
	me = this_player();
	if(interactive(me) 
	) call_out("ask_him", 1,me );


} 
int ask_him(object me)
{
	if(environment(me) == environment())
	tell_object(me,name()+"�ʵ�������˭�����ڵ������ˣ���answer��\n");
	return 1;
}
int do_answer(string arg)
{
	object me;
	me =this_player();
	if(!arg )
		return notify_fail(name()+"����������Ҳ�ﲻ���ң�\n");
	if( arg == "lian" || arg == "lian cheng bi" || arg == "���Ǳ�")
	{
		if(me->query_temp("in_doubt") && me->query_temp("listened"))
		{
        	REWARD_D->riddle_done("ʶ������", me, 20, 1);
        	
			command("unwield gelu");
			command("give gelu to " + me->get_id());
			tell_object(me,name()+"����������һ����������ˣ��ã�\n");
			return 1;
		}
			else
			return notify_fail(name()+"���������û��֤��ѽ��\n");

	}
	else
		return notify_fail(name()+"�����Ҿ��ò���\n");
}
